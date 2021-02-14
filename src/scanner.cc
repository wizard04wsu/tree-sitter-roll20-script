#include <tree_sitter/parser.h>
#include <string>	//string, to_string
#include <stack>	//stack
#include <map>		//map
#include <utility>	//pair
#include <regex>	//regex, regex_match
#include <iostream>	//cout

namespace {

using namespace std;


//For debugging:
const bool debugging = false;
enum ANSI_Color {
	//https://stackoverflow.com/a/45300654/15788
	default=39,
	
	black=30,
	darkGray=90,gray=90,dimGray=90,
	lightGray=37,brightGray=37,
	white=97,
	
	red=31,dimRed=31,darkRed=31,
	yellow=33,dimYellow=33,darkYellow=33,
	green=32,dimGreen=32,darkGreen=32,
	cyan=36,dimCyan=36,darkCyan=36,
	blue=34,dimBlue=34,darkBlue=34,
	magenta=35,dimMagenta=35,darkMagenta=35,
	
	brightRed=91,lightRed=91,
	brightYellow=93,lightYellow=93,
	brightGreen=92,lightGreen=92,
	brightCyan=96,lightCyan=96,
	brightBlue=94,lightBlue=94,
	brightMagenta=95,lightMagenta=95,
};
string color(int foreground = 0, int background = 0) {
	return "\033["
		+(foreground?to_string(foreground):"")
		+((foreground&&background)?";":"")
		+(background?to_string(background+10):"")
		+"m";
}
unsigned log_marked = 0;
string log_consumed = "";
void log(string str) {
	if (debugging) cout << "\033[0m" << str << "\033[0m" << endl;
}
void logLookahead(TSLexer *lexer) {
	char c = lexer->lookahead;
	string str = string({c}) + (c=='\n'?"•":"");
	log(color(darkCyan)+"  Lookahead '"+color(lightCyan)+str+color(darkCyan)+"'");
	
}
void logEntity(string character) { log(color(cyan)+"  Entity of '"+character+"'"); }
void logFunction(string functionName) { log(color(magenta)+functionName); }


struct Query;
struct Scanner;

enum TokenType {
	ATTRIBUTE_START,
	
	ABILITY_START,
	
	MACRO_START,
	
	//HTML_ENTITY,
	
	QUERY_START,
	QUERY_PIPE_HASDEFAULT,
	QUERY_PIPE_HASOPTIONS,
	QUERY_END,
	
	//LABEL_START,
	//LABEL_END,
	
	//INLINE_ROLL_START,
	//INLINE_ROLL_END,
	
	//PARENTHESIZED_START,
	//PARENTHESIZED_END,
	
	//GROUP_ROLL_START,
	//GROUP_ROLL_END,
	
	DICE_ROLL_START,
	
	TABLE_ROLL_START,
	//TABLE_ROLL_END,
	
	
	JUST_AT,
	JUST_PERCENT,
	JUST_HASH,
	JUST_AMPERSAND,
	JUST_D,
	JUST_T,
	JUST_QUESTIONMARK,
	JUST_PIPE,
	//JUST_COMMA,
	//JUST_LEFTBRACE,
	//JUST_RIGHTBRACE,
	//JUST_LEFTBRACKET,
	//JUST_RIGHTBRACKET,
};

enum QueryType {
	QT_INVALID_EMPTY = 1,
	QT_INVALID_UNCLOSED = 2,
	QT_PROMPT_ONLY = 4,
	QT_TEXTBOX = 8,
	QT_OPTIONS = 16,
};


char advance(TSLexer *lexer) {
	if (debugging) log_consumed += lexer->lookahead;
	lexer->advance(lexer, false);
	logLookahead(lexer);
	return lexer->lookahead;
}
void mark_end(TSLexer *lexer) {
	lexer->mark_end(lexer);
	char c = lexer->lookahead;
	log(color(yellow)+"Mark end before '"+string({c})+"'");
	if (debugging) log_marked = log_consumed.length();
}

//scan does not include the starting '@' or '%'
bool scan_placeholder(TSLexer *lexer) {
	logFunction("scan_placeholder");
	char c = lexer->lookahead;
	if (c == '{') {
		while (c != '}' && c != 0 && c != '\n') {
			c = advance(lexer);
			if (c == '@' || c == '%') {
				c = advance(lexer);
				if (c == '{') break;
			}
		}
		if (c == '}') {
			advance(lexer);
			return true;
		}
	}
	return false;
}

//scan does not include the starting hash character
bool scan_macro_start(TSLexer *lexer, unsigned depth) {
	logFunction("scan_macro_start");
	char c = lexer->lookahead;
	
	while (c == '\r') { c = advance(lexer); }
	if (c == 0 || c == ' ' || c == '\n') return false;
	
	while (c != 0 && c != ' ' && c != '\n') {
		if (depth > 0 && (c == '|' || c == '}')) break;
		if (c == '@' || c == '%') {
			c = advance(lexer);
			if (c == '{' && !scan_placeholder(lexer)) return false;
		}
		else {
			c = advance(lexer);
		}
	}
	
	if (c == 0 || c == ' ' || c == '\n') return true;
	
	return false;
}

//scan does not include the dice count or the 'd' or 'D'
bool scan_diceRoll_start(TSLexer *lexer) {
	logFunction("scan_diceRoll_start");
	char c = lexer->lookahead;
	
	if (c == 'f' || c == 'F') {
		return true;
	}
	else if (regex_match(string({c}), regex("\\d"))) {	//c is a digit
		return true;
	}
	else if (c == '@' || c == '%') {
		c = advance(lexer);
		if (scan_placeholder(lexer)) return true;
	}
	return false;
}

//scan does not include the 't' or 'T'
bool scan_tableRoll_start(TSLexer *lexer) {
	logFunction("scan_tableRoll_start");
	char c = lexer->lookahead;
	
	bool rightBracketFound = false;
	if (c == '[') {
		c = advance(lexer);
		while (c != ']' && c != 0 && c != '\n') {
			if (c == '@' || c == '%') {
				c = advance(lexer);
				if (c = '{') {
					while (c != '}' && c != 0 && c != '\n') {
						c = advance(lexer);
						if (c == '@' || c == '%') {
							c = advance(lexer);
							if (c == '{') break;
						}
						else if (c == ']') {
							rightBracketFound = true;
						}
					}
					if (c == '}') {
						rightBracketFound = false;	//reset this; if it was found, it was just part of the attribute/ability name
						c = advance(lexer);
						continue;
					}
					else {	//end of input
						//if rightBracketFound == true, the "@{" or "%{" is interpreted as being part of the table name
						return rightBracketFound;
					}
				}
				else {
					continue;
				}
			}
			c = advance(lexer);
		}
		if (c == ']') return true;
	}
	return false;
}


map<string, string> entitiesMap = {
	{"@", "#64|#[xX](00)?40|commat"},
	{"%", "#37|#[xX](00)?25|percnt"},
	{"#", "#35|#[xX](00)?23|num"},
	{"&", "#38|#[xX](00)?26|amp|AMP"},
	{"[", "#91|#[xX](00)?5[bB]|lsqb|lbrack"},
	{"(", "#40|#[xX](00)?28|lpar"},
	{"{", "#123|#[xX](00)?7[bB]|lcub|lbrace"},
	{"+", "#43|#[xX](00)?2[bB]|plus"},
	{"-", "#45|#[xX](00)?2[dD]|dash|hyphen"},
	{"}", "#125|#[xX](00)?7[dD]|rcub|rbrace"},
	{")", "#41|#[xX](00)?29|rpar"},
	{"]", "#93|#[xX](00)?5[dD]|rsqb|rbrack"},
	{"|", "#124|#[xX](00)?7[cC]|vert|verbar|VerticalLine"},
	{"?", "#63|#[xX](00)?3[fF]|quest"},
	{",", "#44|#[xX](00)?2[cC]|comma"},
	{"=", "#61|#[xX](00)?3[dD]|equals"},
	{"~", "#126|#[xX](00)?7[eE]"},
	{"d", "#100|#[xX](00)?64"},
	{"D", "#68|#[xX](00)?44"},
	{"t", "#116|#[xX](00)?74"},
	{"T", "#84|#[xX](00)?54"},
};

//returns a string with the delimiter represented by the passed entity string, or an empty string if no match is found
string matchDelimiters(string entity, string delimiters, unsigned depth, bool shallowerIsOkay = false) {
	logFunction("matchDelimiters");
	
	//if no delimiters were passed, check this list by default
	if (delimiters == "") delimiters = "@%#&[({+-})]|?,=~dDtT";
	
	for (unsigned i=0; i<delimiters.length(); i++) {
		string delimiter = string({delimiters[i]});
		
		if (depth == 0) {
			if (entity.compare(delimiter) == 0) return delimiter;
			continue;
		}
		
		if (shallowerIsOkay && entity.compare(delimiter) == 0) return delimiter;
		
		string rxpStr = "&(amp;){";
		rxpStr.append(shallowerIsOkay?"0,":"");
		rxpStr.append(to_string(depth-1));
		rxpStr.append("}(");
		rxpStr.append(entitiesMap[delimiter]);
		rxpStr.append(");");
		if (regex_match(entity, regex(rxpStr))) return delimiter;
	}
	return "";
}

//scan does not include the '&'
//however, the '&' is included in the result if a match is found
string get_entity(TSLexer *lexer, unsigned depth, bool shallowerIsOkay = false) {
	logFunction("get_entity");
	regex charsRxp = regex("[a-zA-Z0-9]");
	string code = "", prevCode = "";
	string entity = "&";
	unsigned amps = 0;
	
	char c = lexer->lookahead;
	
	do {
		if (c == '#') {
			code = "#";
			c = advance(lexer);
			if (c == 'x' || c == 'X') {
				code += string({c});
				charsRxp = regex("[a-fA-F0-9]");	//hex code
				c = advance(lexer);
			}
			else {
				charsRxp = regex("\\d");	//decimal code
			}
		}
		else {
			charsRxp = regex("[a-zA-Z0-9]");	//named
		}
		
		while (c != 0) {
			if (c == ';') {
				c = advance(lexer);
				if (code == "") {	//TODO: if (not_a_valid_HTML_entity_code) {
				//just found a semicolon at this depth (no entity name)
					if (amps == 0){
					//at depth 0; nothing found but the semicolon
						return "";
					}
					
					//use the entity name at the previous depth
					log(color(green)+"Found \"&amp;\" at depth "+to_string(depth+amps-1)+" (current depth: "+to_string(depth)+")");
					return entity;
				}
				else if (amps < depth && regex_match(code, regex(entitiesMap["&"]))) {
					amps++;
					entity += code + ";";
					prevCode = code;
					code = "";
					break;
				}
				else if (amps == depth || shallowerIsOkay) {
				//found an entity
					log(color(green)+"Found \"&"+code+";\" at depth "+to_string(depth+amps)+" (current depth: "+to_string(depth)+")");
					return entity+code+";";
				}
				else {
				//found an entity, but it's too shallow
					log(color(red)+"Found \"&"+code+";\" at depth "+to_string(depth+amps)+" (too shallow; current depth: "+to_string(depth)+")");
					return "";
				}
			}
			else if (!regex_match(string({c}), charsRxp)){
			//it's not a valid character
				log(color(red)+"Invalid character for an HTML entity: '"+color(brightRed)+string({c})+color(red)+"'");
				return "";
			}
			else {
				code += c;
				c = advance(lexer);
			}
		}
	} while (c != 0);
	log(color(red)+"No closing semicolon");
	return "";
}


struct Query {
	Scanner *scanner;
	unsigned depth = 0;
	int type = 0;
	
	Query(Scanner *scanner, unsigned depth) : scanner(scanner), depth(depth) {}
	
	//consumes the part after "?{"
	bool scan_query(TSLexer *lexer, int *type, unsigned depth) {
		logFunction("Query.scan_query");
		logLookahead(lexer);
		
		char c = lexer->lookahead;
		char lastChar;
		int optionCount = -1;
		bool isEmpty = true;
		
		do {
			optionCount++;
			lastChar = scan_query_part(lexer, type, depth, &isEmpty);
		} while (lastChar == '|');
		
		if (lastChar == 0) {
			log(color(red)+"The query at depth "+to_string(depth)+" is missing a closing delimiter");
			*type = this->type |= QT_INVALID_UNCLOSED;
			return false;
		}
		else if (isEmpty) {
			log(color(red)+"The query at depth "+to_string(depth)+" has no content");
			*type = this->type |= QT_INVALID_EMPTY;
			return false;
		}
		
		if (optionCount == 0) {
			log(color(yellow)+"The query at depth "+to_string(depth)+" will prompt for text, no default");
			*type = this->type |= QT_PROMPT_ONLY;
		}
		else if (optionCount == 1) {
			log(color(yellow)+"The query at depth "+to_string(depth)+" will prompt for text");
			*type = this->type |= QT_TEXTBOX;
		}
		else {
			log(color(yellow)+"The query at depth "+to_string(depth)+" will prompt for a selection");
			*type = this->type |= QT_OPTIONS;
		}
		return true;
	}
	
	//consumes the part after "{" or "|", up to and including the next "|" or
	//   closing "}"
	//sets `isEmpty` to false if it finds content
	//returns the last consumed character (or the unescaped HTML entity)
	char scan_query_part(TSLexer *lexer, int *type, unsigned depth, bool *isEmpty) {
		logFunction("Query.scan_query_part");
		logLookahead(lexer);
		
		char c = lexer->lookahead;
		string entity = "", delimiter = "";
		bool prevCharIsForPlaceholder = false;
		bool inPlaceholder = false;
		
		while (c != 0) {
			if (inPlaceholder) {
			//inside an attribute or ability
				if (c == '}') {
				//ends the attribute or ability
					log(color(green)+"End @{} or %{}");
					inPlaceholder = false;
				}
			}
			else if (depth == 0) {
				if (c == '{' && prevCharIsForPlaceholder) {
				//begins an attribute or ability: @{ or %{
					log(color(cyan)+"Begin @{} or %{}");
					inPlaceholder = true;
				}
				prevCharIsForPlaceholder = false;
				
				if (c == '@' || c == '%') {
				//might begin an attribute or ability
					prevCharIsForPlaceholder = true;
				}
				else if (c == '|' || c == '}') {
				//ends the roll query option
					if (c == '|') *isEmpty = false;
					advance(lexer);
					log(color(green)+"Query delimiter found: '"+c+"'");
					return c;
				}
			}
			else {	//depth > 0
				if (c == '&') {
					prevCharIsForPlaceholder = false;
					c = advance(lexer);
					entity = get_entity(lexer, depth, true);
					if (entity != "") {
						delimiter = matchDelimiters(entity, "|}", depth, false);
						if (delimiter != "") {
							if (delimiter == "|") *isEmpty = false;
							log(color(green)+"Query delimiter found: '"+delimiter+"'");
							return char(delimiter[0]);
						}
						delimiter = matchDelimiters(entity, "|}", depth, true);
						if (delimiter != "") {
							//encountered a delimiter of a containing roll query
							return 0;
						}
					}
					
					*isEmpty = false;
					c = lexer->lookahead;
					continue;
				}
				else if (c == '|' || c == '}') {
					//encountered a delimiter of a containing roll query
					return 0;
				}
			}
			
			*isEmpty = false;
			c = advance(lexer);
		}
		
		//EOF; the roll query was never closed
		return 0;
	}
};

struct Scanner {
	stack<Query*> queries;
	
	Scanner() {}
	
	void logPopQuery(){
		log(color(brightCyan)+"Pop "+color(cyan)+"a Query; stack size: "+color(brightCyan)+to_string(queries.size()));
	}
	void logPushQuery(){
		log(color(brightCyan)+"Push "+color(cyan)+"a Query; stack size: "+color(brightCyan)+to_string(queries.size()));
	}
	void logTokenType(TSLexer *lexer, string tokenType) {
		log(color(yellow)+"Result set to "+color(brightYellow)+tokenType);
		log("  "
			+color(brightYellow)+log_consumed.substr(0, log_marked)
			+color(gray)+log_consumed.substr(log_marked)
			+color(cyan)+string({char(lexer->lookahead)})
		);
	}
	
	bool scan(TSLexer *lexer, const bool *valid_symbols){
		log_marked = 0;
		log_consumed = "";
		log(color(brightMagenta)+"Scanner.scan");
		logLookahead(lexer);
		
		char c = lexer->lookahead;
		mark_end(lexer);
		
		int queryType = 0;
		if (queries.size() > 0) queryType = queries.top()->type;
		
		unsigned depth = queries.size()>0 ? queries.size()-1 : 0;
		string entity, delimAtDepth, delimAtOrAbove;
		
		if (c == '@') {
			if (valid_symbols[ATTRIBUTE_START] || valid_symbols[JUST_AT]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ATTRIBUTE_START]) {
					if (scan_placeholder(lexer)) {
						logTokenType(lexer, "ATTRIBUTE_START");
						lexer->result_symbol = ATTRIBUTE_START;
						return true;
					}
				}
				
				if (valid_symbols[JUST_AT]) {
					logTokenType(lexer, "JUST_AT");
					lexer->result_symbol = JUST_AT;
					return true;
				}
			}
		}
		else if (c == '%') {
			if (valid_symbols[ABILITY_START] || valid_symbols[JUST_PERCENT]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ABILITY_START]) {
					if (scan_placeholder(lexer)) {
						logTokenType(lexer, "ABILITY_START");
						lexer->result_symbol = ABILITY_START;
						return true;
					}
				}
				
				if (valid_symbols[JUST_PERCENT]) {
					logTokenType(lexer, "JUST_PERCENT");
					lexer->result_symbol = JUST_PERCENT;
					return true;
				}
			}
		}
		else if (c == '#') {
			if (valid_symbols[MACRO_START] || valid_symbols[JUST_HASH]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[MACRO_START]) {
					if (scan_macro_start(lexer, depth)) {
						logTokenType(lexer, "MACRO_START");
						lexer->result_symbol = MACRO_START;
						return true;
					}
				}
				
				if (valid_symbols[JUST_HASH]) {
					logTokenType(lexer, "JUST_HASH");
					lexer->result_symbol = JUST_HASH;
					return true;
				}
			}
		}
		else if (c == '&') {
			if (depth > 0) {
				advance(lexer);
				entity = get_entity(lexer, depth, true);
				delimAtDepth = matchDelimiters(entity, "", depth, false);
				delimAtOrAbove = matchDelimiters(entity, "", depth, true);
				
				if (delimAtOrAbove == "?") {
					logEntity("?");
					if (valid_symbols[QUERY_START] || valid_symbols[JUST_QUESTIONMARK]) {
						c = lexer->lookahead;
						
						if (valid_symbols[QUERY_START]) {
							delimAtOrAbove = "";
							if (c == '&') {
								advance(lexer);
								entity = get_entity(lexer, depth, true);
								delimAtOrAbove = matchDelimiters(entity, "{", depth, true);
							}
							
							if (c == '{' || delimAtOrAbove == "{") {
								if (c == '{') advance(lexer);
								
								Query *query = new Query(this, queries.size());
								queries.push(query);
								queryType = 0;
								logPushQuery();
								
								if (queries.top()->scan_query(lexer, &queryType, queries.size()-1)) {
									logTokenType(lexer, "QUERY_START");
									lexer->result_symbol = QUERY_START;
									return true;
								}
								
								//else it's unclosed or empty
								queries.pop();
								logPopQuery();
								return false;
							}
						}
						
						if (valid_symbols[JUST_QUESTIONMARK]) {
							mark_end(lexer);
							logTokenType(lexer, "JUST_QUESTIONMARK");
							lexer->result_symbol = JUST_QUESTIONMARK;
							return true;
						}
					}
				}
				else if (delimAtDepth == "}") {
					logEntity("}");
					if (valid_symbols[QUERY_END] && queries.size() > 0) {
						c = lexer->lookahead;
						mark_end(lexer);
						
						logTokenType(lexer, "QUERY_END");
						lexer->result_symbol = QUERY_END;
						queries.pop();
						logPopQuery();
						return true;
					}
				}
				else if (delimAtDepth == "|") {
					logEntity("|");
					if (valid_symbols[QUERY_PIPE_HASDEFAULT] || valid_symbols[QUERY_PIPE_HASOPTIONS] || valid_symbols[JUST_PIPE]) {
						c = lexer->lookahead;
						
						if (valid_symbols[QUERY_PIPE_HASDEFAULT] || valid_symbols[QUERY_PIPE_HASOPTIONS]) {
							if (queryType & QT_TEXTBOX) {
								mark_end(lexer);
								logTokenType(lexer, "QUERY_PIPE_HASDEFAULT");
								lexer->result_symbol = QUERY_PIPE_HASDEFAULT;
								return true;
							}
							else if (queryType & QT_OPTIONS) {
								mark_end(lexer);
								logTokenType(lexer, "QUERY_PIPE_HASOPTIONS");
								lexer->result_symbol = QUERY_PIPE_HASOPTIONS;
								return true;
							}
						}
						
						if (valid_symbols[JUST_PIPE]) {
							mark_end(lexer);
							logTokenType(lexer, "JUST_PIPE");
							lexer->result_symbol = JUST_PIPE;
							return true;
						}
					}
				}
				
				if (valid_symbols[JUST_AMPERSAND]) {
					logTokenType(lexer, "JUST_AMPERSAND");
					lexer->result_symbol = JUST_AMPERSAND;
					return true;
				}
			}
			else if (valid_symbols[JUST_AMPERSAND]) {
				c = advance(lexer);
				mark_end(lexer);
				
				logTokenType(lexer, "JUST_AMPERSAND");
				lexer->result_symbol = JUST_AMPERSAND;
				return true;
			}
		}
		else if (c == 'd' || c == 'D') {
			if (valid_symbols[DICE_ROLL_START] || valid_symbols[JUST_D]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[DICE_ROLL_START]) {
					if (scan_diceRoll_start(lexer)) {
						logTokenType(lexer, "DICE_ROLL_START");
						lexer->result_symbol = DICE_ROLL_START;
						return true;
					}
				}
				
				if (valid_symbols[JUST_D]) {
					logTokenType(lexer, "JUST_D");
					lexer->result_symbol = JUST_D;
					return true;
				}
			}
		}
		else if (c == 't' || c == 'T') {
			if (valid_symbols[TABLE_ROLL_START] || valid_symbols[JUST_T]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[TABLE_ROLL_START]) {
					if (scan_tableRoll_start(lexer)) {
						logTokenType(lexer, "TABLE_ROLL_START");
						lexer->result_symbol = TABLE_ROLL_START;
						return true;
					}
				}
				
				if (valid_symbols[JUST_T]) {
					logTokenType(lexer, "JUST_T");
					lexer->result_symbol = JUST_T;
					return true;
				}
			}
		}
		else if (c == '?') {
			if (valid_symbols[QUERY_START] || valid_symbols[JUST_QUESTIONMARK]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[QUERY_START]) {
					delimAtOrAbove = "";
					if (c == '&') {
						advance(lexer);
						entity = get_entity(lexer, depth, true);
						delimAtOrAbove = matchDelimiters(entity, "{", depth, true);
					}
					
					if (c == '{' || delimAtOrAbove == "{") {
						if (c == '{') advance(lexer);
						
						Query *query = new Query(this, queries.size());
						queries.push(query);
						queryType = 0;
						logPushQuery();
						
						if (queries.top()->scan_query(lexer, &queryType, queries.size()-1)) {
							logTokenType(lexer, "QUERY_START");
							lexer->result_symbol = QUERY_START;
							return true;
						}
						
						//else it's unclosed or empty
						queries.pop();
						logPopQuery();
						return false;
					}
				}
				
				if (valid_symbols[JUST_QUESTIONMARK]) {
					logTokenType(lexer, "JUST_QUESTIONMARK");
					lexer->result_symbol = JUST_QUESTIONMARK;
					return true;
				}
			}
		}
		else if (c == '|') {
			if (valid_symbols[QUERY_PIPE_HASDEFAULT] || valid_symbols[QUERY_PIPE_HASOPTIONS] || valid_symbols[JUST_PIPE]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if ((valid_symbols[QUERY_PIPE_HASDEFAULT] || valid_symbols[QUERY_PIPE_HASOPTIONS]) && queries.size() == 1) {
					if (queryType & QT_TEXTBOX) {
						logTokenType(lexer, "QUERY_PIPE_HASDEFAULT");
						lexer->result_symbol = QUERY_PIPE_HASDEFAULT;
						return true;
					}
					else if (queryType & QT_OPTIONS) {
						logTokenType(lexer, "QUERY_PIPE_HASOPTIONS");
						lexer->result_symbol = QUERY_PIPE_HASOPTIONS;
						return true;
					}
				}
				
				if (valid_symbols[JUST_PIPE]) {
					logTokenType(lexer, "JUST_PIPE");
					lexer->result_symbol = JUST_PIPE;
					return true;
				}
			}
		}
		else if (c == '}') {
			if (valid_symbols[QUERY_END] && queries.size() == 1) {
				c = advance(lexer);
				mark_end(lexer);
				
				logTokenType(lexer, "QUERY_END");
				lexer->result_symbol = QUERY_END;
				queries.pop();
				logPopQuery();
				return true;
			}
		}
		
		if (debugging) {
			advance(lexer);
			mark_end(lexer);
		}
		logTokenType(lexer, "(no match)");
		return false;
	}
};

}

extern "C" {

void *tree_sitter_roll20_script_external_scanner_create() {
	log(color(NULL, brightMagenta)+"                                        ");
	return new Scanner();
}

bool tree_sitter_roll20_script_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
	Scanner *scanner = static_cast<Scanner *>(payload);
	return scanner->scan(lexer, valid_symbols);
}

unsigned tree_sitter_roll20_script_external_scanner_serialize(void *payload, char *state) {
	return 0;
}

void tree_sitter_roll20_script_external_scanner_deserialize(void *payload, const char *state, unsigned length) {}

void tree_sitter_roll20_script_external_scanner_destroy(void *payload) {
	Scanner *scanner = static_cast<Scanner *>(payload);
	delete scanner;
}

}
