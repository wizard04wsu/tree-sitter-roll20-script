#include <tree_sitter/parser.h>
#include <string>	//string, to_string
#include <stack>	//stack
#include <map>		//map
#include <utility>	//pair
#include <regex>	//regex, regex_match
#include <iostream>	//cout
#include <algorithm>	//max

namespace {

using namespace std;


enum TokenType {
	INTEGER,
	
	ATTRIBUTE_START,
	
	ABILITY_START,
	
	MACRO_SAFE_START,
	MACRO_UNSAFE_START,
	
	HTML_ENTITY,
	
	QUERY_START,
	QUERY_PIPE_HASDEFAULT,
	QUERY_PIPE_HASOPTIONS,
	QUERY_END,
	
	//LABEL_START,
	//LABEL_END,
	
	INLINE_ROLL_START,
	INLINE_ROLL_END,
	
	//PARENTHESIZED_START,
	//PARENTHESIZED_END,
	
	//GROUP_ROLL_START,
	//GROUP_ROLL_END,
	
	DICE_ROLL_START,
	DICE_ROLL_MODIFIERS,
	
	TABLE_ROLL_START,
	
	JUST_AT,
	JUST_PERCENT,
	JUST_HASH,
	JUST_AMPERSAND,
	JUST_D,
	JUST_T,
	JUST_QUESTIONMARK,
	JUST_LEFTBRACE,
	JUST_PIPE,
	JUST_COMMA,
	JUST_RIGHTBRACE,
	JUST_LEFTBRACKET,
	JUST_RIGHTBRACKET,
	JUST_LEFTPAREN,
	JUST_RIGHTPAREN,
	
	DECIMAL_POINT,
	JUST_PERIOD,
	
	JUST_SLASH,
	JUST_ASTERISK,
	JUST_PLUS,
	JUST_DASH,
	OPERATOR_POSITIVE,
	OPERATOR_NEGATIVE,
	
	_EOF,
};


//For debugging:
const bool debugging = true;
const bool log_valid_symbols = true;
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
	log(color(darkCyan)+"  Lookahead '"+color(lightCyan)+string({c})+color(darkCyan)+"'");
	
}
void logEntity(string character) { log(color(cyan)+"  Entity of '"+character+"'"); }
void logFunction(string functionName) { log(color(magenta)+functionName); }
void logValidSymbols(const bool *valid_symbols) {
	if (!debugging || !log_valid_symbols) return;
	cout << color(darkGray) //<< "Valid symbols:" << "\n"
		 << (valid_symbols[INTEGER]?"INTEGER, ":"")
		 << (valid_symbols[ATTRIBUTE_START]?"ATTRIBUTE_START, ":"")
		 << (valid_symbols[ABILITY_START]?"ABILITY_START, ":"")
		 << (valid_symbols[MACRO_SAFE_START]?"MACRO_SAFE_START, ":"")
		 << (valid_symbols[MACRO_UNSAFE_START]?"MACRO_UNSAFE_START, ":"")
		 << (valid_symbols[HTML_ENTITY]?"HTML_ENTITY, ":"")
		 << (valid_symbols[QUERY_START]?"QUERY_START, ":"")
		 << (valid_symbols[QUERY_PIPE_HASDEFAULT]?"QUERY_PIPE_HASDEFAULT, ":"")
		 << (valid_symbols[QUERY_PIPE_HASOPTIONS]?"QUERY_PIPE_HASOPTIONS, ":"")
		 << (valid_symbols[QUERY_END]?"QUERY_END, ":"")
		 << (valid_symbols[INLINE_ROLL_START]?"INLINE_ROLL_START, ":"")
		 << (valid_symbols[INLINE_ROLL_END]?"INLINE_ROLL_END, ":"")
		 << (valid_symbols[DICE_ROLL_START]?"DICE_ROLL_START, ":"")
		 << (valid_symbols[DICE_ROLL_MODIFIERS]?"DICE_ROLL_MODIFIERS, ":"")
		 << (valid_symbols[TABLE_ROLL_START]?"TABLE_ROLL_START, ":"")
		 << (valid_symbols[JUST_AT]?"JUST_AT, ":"")
		 << (valid_symbols[JUST_PERCENT]?"JUST_PERCENT, ":"")
		 << (valid_symbols[JUST_HASH]?"JUST_HASH, ":"")
		 << (valid_symbols[JUST_AMPERSAND]?"JUST_AMPERSAND, ":"")
		 << (valid_symbols[JUST_D]?"JUST_D, ":"")
		 << (valid_symbols[JUST_T]?"JUST_T, ":"")
		 << (valid_symbols[JUST_QUESTIONMARK]?"JUST_QUESTIONMARK, ":"")
		 << (valid_symbols[JUST_LEFTBRACE]?"JUST_LEFTBRACE, ":"")
		 << (valid_symbols[JUST_PIPE]?"JUST_PIPE, ":"")
		 << (valid_symbols[JUST_COMMA]?"JUST_COMMA, ":"")
		 << (valid_symbols[JUST_RIGHTBRACE]?"JUST_RIGHTBRACE, ":"")
		 << (valid_symbols[JUST_LEFTBRACKET]?"JUST_LEFTBRACKET, ":"")
		 << (valid_symbols[JUST_RIGHTBRACKET]?"JUST_RIGHTBRACKET, ":"")
		 << (valid_symbols[JUST_LEFTPAREN]?"JUST_LEFTPAREN, ":"")
		 << (valid_symbols[JUST_RIGHTPAREN]?"JUST_RIGHTPAREN, ":"")
		 << (valid_symbols[DECIMAL_POINT]?"DECIMAL_POINT, ":"")
		 << (valid_symbols[JUST_PERIOD]?"JUST_PERIOD, ":"")
		 << (valid_symbols[JUST_SLASH]?"JUST_SLASH, ":"")
		 << (valid_symbols[JUST_ASTERISK]?"JUST_ASTERISK, ":"")
		 << (valid_symbols[JUST_PLUS]?"JUST_PLUS, ":"")
		 << (valid_symbols[JUST_DASH]?"JUST_DASH, ":"")
		 << (valid_symbols[OPERATOR_POSITIVE]?"OPERATOR_POSITIVE, ":"")
		 << (valid_symbols[OPERATOR_NEGATIVE]?"OPERATOR_NEGATIVE, ":"")
		 << (valid_symbols[_EOF]?"_EOF, ":"")
		 << "\n";
}


struct Query;
struct Scanner;

enum QueryType {
	QT_INVALID_EMPTY = 1,
	QT_INVALID_UNCLOSED = 2,
	QT_PROMPT_ONLY = 4,
	QT_TEXTBOX = 8,
	QT_OPTIONS = 16,
};

map<string, string> entitiesMap = {
	{"@", "#64|#[xX](00)?40|commat"},
	{"%", "#37|#[xX](00)?25|percnt"},
	{"#", "#35|#[xX](00)?23|num"},
	{"&", "#38|#[xX](00)?26|amp|AMP"},
	{"[", "#91|#[xX](00)?5[bB]|lsqb|lbrack"},
	{"(", "#40|#[xX](00)?28|lpar"},
	{"{", "#123|#[xX](00)?7[bB]|lcub|lbrace"},
	{"/", "#47|#[xX](00)?2[fF]|sol"},
	{"*", "#42|#[xX](00)?2[aA]|ast"},
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
	{"0", "#48|#[xX](00)?30"},
	{"1", "#49|#[xX](00)?31"},
	{"2", "#50|#[xX](00)?32"},
	{"3", "#51|#[xX](00)?33"},
	{"4", "#52|#[xX](00)?34"},
	{"5", "#53|#[xX](00)?35"},
	{"6", "#54|#[xX](00)?36"},
	{"7", "#55|#[xX](00)?37"},
	{"8", "#56|#[xX](00)?38"},
	{"9", "#57|#[xX](00)?39"},
	{".", "#46|#[xX](00)?2[eE]|period"},
};
string entityChars = "";


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


//Returns a string with the character that was represented by the `entity` argument, or an empty string if no match is found.
//`entity` should not include the starting ampersand.
//`entity` can be a single character; it will be returned if it matches an accepted character at appropriate depth.
string matchCharEntity(string entity, string acceptedCharacters, unsigned depth, bool shallowerIsOkay = false) {
	//logFunction("matchCharEntity");
	
	if (entity == "") return "";
	
	//if no accepted characters were passed, accept any mapped character
	if (acceptedCharacters == "") acceptedCharacters = entityChars;
	
	for (unsigned i=0; i<acceptedCharacters.length(); i++) {
		string testChar = string({acceptedCharacters[i]});
		if (entitiesMap.find(testChar) == entitiesMap.end()) continue;
		
		if ((depth == 0 || shallowerIsOkay) && entity.compare(testChar) == 0) {
			return testChar;
		}
		if (depth == 0) continue;
		
		string rxpStr = "&(amp;){";
		rxpStr.append(shallowerIsOkay?"0,":"");
		rxpStr.append(to_string(depth-1));
		rxpStr.append("}(");
		rxpStr.append(entitiesMap[testChar]);
		rxpStr.append(");");
		if (regex_match(entity, regex(rxpStr))) return testChar;
	}
	return "";
}

string matchNumbers(string entity, unsigned depth) {
	return matchCharEntity(entity, "0123456789", depth, true);
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


//scan does not include the starting '@' or '%'
bool scan_placeholder(TSLexer *lexer) {
	logFunction("scan_placeholder");
	char c = lexer->lookahead;
	if (c == '{') {
		c = advance(lexer);
		if (c == '}') return false;	//empty
		while (c != '}' && c != 0 && c != '\n') {
			if (c == '@' || c == '%') {
				c = advance(lexer);
				if (c == '{') return false;	//start of a nested placeholder
			}
			c = advance(lexer);
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
	if (c == 0 || c == ' ' || c == '\n') {
	//no macro name
		return false;
	}
	
	while (c != 0 && c != ' ' && c != '\n') {
		if (depth > 0 && c == '&') {
			c = advance(lexer);
			string entity = get_entity(lexer, depth, true);
			if (entity != "") {
				if (matchCharEntity(entity, "|,}", depth, false) != "") {
				//found an unsafe character (valid for a macro name, but likely unintented)
					return true;
				}
			}
		}
		
		if (regex_match(string({c}), regex("[\\[({/*+\\-})\\]|]"))) {
		//found an unsafe character (valid for a macro name, but likely unintented)
			return true;
		}
		
		if (c == '@' || c == '%') {
			c = advance(lexer);
			scan_placeholder(lexer);
			c = lexer->lookahead;
		}
		else {
			c = advance(lexer);
		}
	}
	
	return true;
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
	if (c == '[') {	//TODO: do we need to check for an HTML entity?
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
						delimiter = matchCharEntity(entity, "|}", depth, false);
						if (delimiter != "") {
							if (delimiter == "|") *isEmpty = false;
							log(color(green)+"Query delimiter found: '"+delimiter+"'");
							return char(delimiter[0]);
						}
						delimiter = matchCharEntity(entity, "|}", depth, true);
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
	void logTokenType(TSLexer *lexer, string tokenType, bool noMatch = false) {
		log(color(yellow)+"Result set to "+color(brightYellow)+tokenType);
		if (noMatch) {
			//consume an extra character
			log_consumed += lexer->lookahead;
			lexer->advance(lexer, false);
			
			unsigned consumed_length = max(int(log_marked), int(log_consumed.length()-1));
			log("  "
				+color(gray)+log_consumed.substr(0, consumed_length)
				+color(cyan)+log_consumed.substr(consumed_length)
				+color(cyan)+string({char(lexer->lookahead)})
			);
		}
		else {
			log("  "
				+color(brightYellow)+log_consumed.substr(0, log_marked)
				+color(gray)+log_consumed.substr(log_marked)
				+color(cyan)+string({char(lexer->lookahead)})
			);
		}
	}
	
	bool match_found(TSLexer *lexer, int symbol, string tokenType) {
		logTokenType(lexer, tokenType);
		lexer->result_symbol = symbol;
		return true;
	}
	
	bool test_for_sign(TSLexer *lexer, const bool *valid_symbols,
		int symbolOnPass, string typeOnPass, int symbolOnFail, string typeOnFail
	) {
		unsigned depth = queries.size()>0 ? queries.size()-1 : 0;
		string entity, delimAtOrAbove, digitAtOrAbove;
		char c = lexer->lookahead;
		
		if (valid_symbols[symbolOnPass]) {
			if (regex_match(string({c}), regex("\\d"))) {
				return match_found(lexer, symbolOnPass, typeOnPass);
			}
			else if (c == '%' || c == '@') {
				advance(lexer);
				
				if (scan_placeholder(lexer)) {
					return match_found(lexer, symbolOnPass, typeOnPass);
				}
			}
			else {
				delimAtOrAbove = "";
				if (c == '&') {
					advance(lexer);
					entity = get_entity(lexer, depth, true);
					delimAtOrAbove = matchCharEntity(entity, "[", depth, true);
					digitAtOrAbove = matchNumbers(entity, depth);
				}
				
				if (c == '[' || delimAtOrAbove == "[") {
					c = (c == '&' ? lexer->lookahead : advance(lexer));
					
					delimAtOrAbove = "";
					if (c == '&') {
						advance(lexer);
						entity = get_entity(lexer, depth, true);
						delimAtOrAbove = matchCharEntity(entity, "[", depth, true);
					}
					
					if (c == '[' || delimAtOrAbove == "[") {
					//inline roll start "[["
						return match_found(lexer, symbolOnPass, typeOnPass);
					}
				}
				else if (digitAtOrAbove != "") {
					return match_found(lexer, symbolOnPass, typeOnPass);
				}
			}
		}
		
		if (valid_symbols[symbolOnFail]) {
			return match_found(lexer, symbolOnFail, typeOnFail);
		}
	}
	
	bool scan(TSLexer *lexer, const bool *valid_symbols){
		log_marked = 0;
		log_consumed = "";
		log(color(brightMagenta)+"Scanner.scan");
		logValidSymbols(valid_symbols);
		logLookahead(lexer);
		
		char c = lexer->lookahead;
		mark_end(lexer);
		
		int queryType = 0;
		if (queries.size() > 0) queryType = queries.top()->type;
		
		unsigned depth = queries.size()>0 ? queries.size()-1 : 0;
		string entity = "", delimAtDepth = "", delimAtOrAbove = "", digitAtOrAbove = "";
		bool scanningEntity = false;
		string potentiallyValidModifiers = "acdfhklmoprstACDFHKLMOPRST<=>!0123456789.";
		
		if (c == 0) {
			if (valid_symbols[_EOF]) {
				return match_found(lexer, _EOF, "_EOF");
			}
		}
		else if (c == '@') {
			if (valid_symbols[ATTRIBUTE_START] || valid_symbols[JUST_AT]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ATTRIBUTE_START]) {
					if (scan_placeholder(lexer)) {
						return match_found(lexer, ATTRIBUTE_START, "ATTRIBUTE_START");
					}
				}
				
				if (valid_symbols[JUST_AT]) {
					return match_found(lexer, JUST_AT, "JUST_AT");
				}
			}
		}
		else if (c == '%') {
			if (valid_symbols[ABILITY_START] || valid_symbols[JUST_PERCENT]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ABILITY_START]) {
					if (scan_placeholder(lexer)) {
						return match_found(lexer, ABILITY_START, "ABILITY_START");
					}
				}
				
				if (valid_symbols[JUST_PERCENT]) {
					return match_found(lexer, JUST_PERCENT, "JUST_PERCENT");
				}
			}
		}
		else if (c == '#') {
			if (valid_symbols[MACRO_SAFE_START] || valid_symbols[MACRO_UNSAFE_START] || valid_symbols[JUST_HASH]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[MACRO_SAFE_START] || valid_symbols[MACRO_UNSAFE_START]) {
					if (scan_macro_start(lexer, depth)) {
						c = lexer->lookahead;
						if ((c == 0 || c == ' ' || c == '\n') && valid_symbols[MACRO_SAFE_START]) {
							return match_found(lexer, MACRO_SAFE_START, "MACRO_SAFE_START");
						}
						else {
							return match_found(lexer, MACRO_UNSAFE_START, "MACRO_UNSAFE_START");
						}
					}
				}
				
				if (valid_symbols[JUST_HASH]) {
					return match_found(lexer, JUST_HASH, "JUST_HASH");
				}
			}
		}
		else if (valid_symbols[DICE_ROLL_MODIFIERS] && potentiallyValidModifiers.find(c) > -1) {
			c = advance(lexer);
			mark_end(lexer);
			return match_found(lexer, DICE_ROLL_MODIFIERS, "DICE_ROLL_MODIFIERS");
		}
		else {
			entity = string({c});
			
			if (c == '&') {
				scanningEntity = true;
				
				advance(lexer);
				mark_end(lexer);
				
				if (depth > 0) {
					entity = get_entity(lexer, depth, true);
				}
				else {
					if (valid_symbols[HTML_ENTITY]) {
						entity = get_entity(lexer, 0, false);
						if (entity != "") {
							mark_end(lexer);
							return match_found(lexer, HTML_ENTITY, "HTML_ENTITY");
						}
					}
				}
			}
			
			delimAtDepth = matchCharEntity(entity, "", depth, false);
			delimAtOrAbove = matchCharEntity(entity, "", depth, true);
			digitAtOrAbove = matchNumbers(entity, depth);
			log(color(red)+"e="+entity+" @="+delimAtDepth+" ^="+delimAtOrAbove+" #="+digitAtOrAbove);
			
			if (delimAtOrAbove == "d" || delimAtOrAbove == "D") {
				if (valid_symbols[DICE_ROLL_START] || valid_symbols[JUST_D]) {
					if (scanningEntity) logEntity(delimAtOrAbove);
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					if (valid_symbols[DICE_ROLL_START]) {
						if (scan_diceRoll_start(lexer)) {
							return match_found(lexer, DICE_ROLL_START, "DICE_ROLL_START");
						}
					}
					
					if (valid_symbols[JUST_D]) {
						return match_found(lexer, JUST_D, "JUST_D");
					}
				}
			}
			else if (delimAtOrAbove == "t" || delimAtOrAbove == "T") {
				if (valid_symbols[TABLE_ROLL_START] || valid_symbols[JUST_T]) {
					if (scanningEntity) logEntity(delimAtOrAbove);
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					if (valid_symbols[TABLE_ROLL_START]) {
						if (scan_tableRoll_start(lexer)) {
							return match_found(lexer, TABLE_ROLL_START, "TABLE_ROLL_START");
						}
					}
					
					if (valid_symbols[JUST_T]) {
						return match_found(lexer, JUST_T, "JUST_T");
					}
				}
			}
			else if (delimAtOrAbove == "?") {
				if (valid_symbols[QUERY_START] || valid_symbols[JUST_QUESTIONMARK]) {
					if (scanningEntity) logEntity("?");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					if (valid_symbols[QUERY_START]) {
						delimAtOrAbove = "";
						if (c == '&') {
							advance(lexer);
							entity = get_entity(lexer, depth, true);
							delimAtOrAbove = matchCharEntity(entity, "{", depth, true);
						}
						
						if (c == '{' || delimAtOrAbove == "{") {
							if (c == '{') advance(lexer);
							
							Query *query = new Query(this, queries.size());
							queries.push(query);
							queryType = 0;
							logPushQuery();
							
							if (queries.top()->scan_query(lexer, &queryType, queries.size()-1)) {
								mark_end(lexer);
								
								return match_found(lexer, QUERY_START, "QUERY_START");
							}
							
							//else it's unclosed or empty
							queries.pop();
							logPopQuery();
							return false;
						}
					}
					
					if (valid_symbols[JUST_QUESTIONMARK]) {
						return match_found(lexer, JUST_QUESTIONMARK, "JUST_QUESTIONMARK");
					}
				}
			}
			else if (delimAtDepth == "{") {
				if (valid_symbols[JUST_LEFTBRACE]) {
					if (scanningEntity) logEntity("{");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					return match_found(lexer, JUST_LEFTBRACE, "JUST_LEFTBRACE");
				}
			}
			else if (delimAtDepth == "|") {
				if (valid_symbols[QUERY_PIPE_HASDEFAULT] || valid_symbols[QUERY_PIPE_HASOPTIONS] || valid_symbols[JUST_PIPE]) {
					if (scanningEntity) logEntity("|");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					if (queries.size() > 0 && (valid_symbols[QUERY_PIPE_HASDEFAULT] || valid_symbols[QUERY_PIPE_HASOPTIONS])) {
						if (queryType & QT_TEXTBOX) {
							return match_found(lexer, QUERY_PIPE_HASDEFAULT, "QUERY_PIPE_HASDEFAULT");
						}
						else if (queryType & QT_OPTIONS) {
							return match_found(lexer, QUERY_PIPE_HASOPTIONS, "QUERY_PIPE_HASOPTIONS");
						}
					}
					
					if (valid_symbols[JUST_PIPE]) {
						return match_found(lexer, JUST_PIPE, "JUST_PIPE");
					}
				}
			}
			else if (delimAtDepth == ",") {
				if (valid_symbols[JUST_COMMA]) {
					if (scanningEntity) logEntity(",");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					return match_found(lexer, JUST_COMMA, "JUST_COMMA");
				}
			}
			else if (delimAtDepth == "}") {
				if (valid_symbols[QUERY_END] || valid_symbols[JUST_RIGHTBRACE]) {
					if (scanningEntity) logEntity("}");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					if (queries.size() > 0 && valid_symbols[QUERY_END]) {
						logTokenType(lexer, "QUERY_END");
						lexer->result_symbol = QUERY_END;
						queries.pop();
						logPopQuery();
						return true;
					}
					
					if (valid_symbols[JUST_RIGHTBRACE]) {
						return match_found(lexer, JUST_RIGHTBRACE, "JUST_RIGHTBRACE");
					}
				}
			}
			else if (delimAtDepth == "[") {
				if (valid_symbols[INLINE_ROLL_START] || valid_symbols[JUST_LEFTBRACKET]) {
					if (scanningEntity) logEntity("[");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					if (valid_symbols[INLINE_ROLL_START]) {
						delimAtOrAbove = "";
						if (c == '&') {
							advance(lexer);
							entity = get_entity(lexer, depth, true);
							delimAtOrAbove = matchCharEntity(entity, "[", depth, true);
						}
						
						if (c == '[' || delimAtOrAbove == "[") {
							if (c == '[') advance(lexer);
							mark_end(lexer);
							
							return match_found(lexer, INLINE_ROLL_START, "INLINE_ROLL_START");
						}
					}
					
					if (valid_symbols[JUST_LEFTBRACKET]) {
						return match_found(lexer, JUST_LEFTBRACKET, "JUST_LEFTBRACKET");
					}
				}
			}
			else if (delimAtDepth == "]") {
				if (valid_symbols[INLINE_ROLL_END] || valid_symbols[JUST_RIGHTBRACKET]) {
					if (scanningEntity) logEntity("]");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					if (valid_symbols[INLINE_ROLL_END]) {
						delimAtOrAbove = "";
						if (c == '&') {
							advance(lexer);
							entity = get_entity(lexer, depth, true);
							delimAtOrAbove = matchCharEntity(entity, "]", depth, true);
						}
						
						if (c == ']' || delimAtOrAbove == "]") {
							if (c == ']') advance(lexer);
							mark_end(lexer);
							
							return match_found(lexer, INLINE_ROLL_END, "INLINE_ROLL_END");
						}
					}
					
					if (valid_symbols[JUST_RIGHTBRACKET]) {
						return match_found(lexer, JUST_RIGHTBRACKET, "JUST_RIGHTBRACKET");
					}
				}
			}
			else if (delimAtDepth == "(") {
				if (valid_symbols[JUST_LEFTPAREN]) {
					if (scanningEntity) logEntity("(");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					return match_found(lexer, JUST_LEFTPAREN, "JUST_LEFTPAREN");
				}
			}
			else if (delimAtDepth == ")") {
				if (valid_symbols[JUST_RIGHTPAREN]) {
					if (scanningEntity) logEntity(")");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					return match_found(lexer, JUST_RIGHTPAREN, "JUST_RIGHTPAREN");
				}
			}
			else if (delimAtDepth == "/") {
				if (valid_symbols[JUST_SLASH]) {
					if (scanningEntity) logEntity("/");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					return match_found(lexer, JUST_SLASH, "JUST_SLASH");
				}
			}
			else if (delimAtDepth == "*") {
				if (valid_symbols[JUST_ASTERISK]) {
					if (scanningEntity) logEntity("*");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					return match_found(lexer, JUST_ASTERISK, "JUST_ASTERISK");
				}
			}
			else if (delimAtDepth == "+") {
				if (valid_symbols[OPERATOR_POSITIVE] || valid_symbols[JUST_PLUS]) {
					if (scanningEntity) logEntity("+");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					if (test_for_sign(lexer, valid_symbols, OPERATOR_POSITIVE, "OPERATOR_POSITIVE", JUST_PLUS, "JUST_PLUS")) {
						return true;
					}
				}
			}
			else if (delimAtDepth == "-") {
				if (valid_symbols[OPERATOR_NEGATIVE] || valid_symbols[JUST_DASH]) {
					if (scanningEntity) logEntity("-");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					if (test_for_sign(lexer, valid_symbols, OPERATOR_NEGATIVE, "OPERATOR_NEGATIVE", JUST_DASH, "JUST_DASH")) {
						return true;
					}
				}
			}
			else if (delimAtOrAbove == ".") {
				if (valid_symbols[DECIMAL_POINT] || valid_symbols[JUST_PERIOD]) {
					if (scanningEntity) logEntity(".");
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					mark_end(lexer);
					
					if (valid_symbols[DECIMAL_POINT]) {
						if (c == '&') {
							advance(lexer);
							
							entity = get_entity(lexer, depth, true);
							if (matchNumbers(entity, depth) != "") {
								return match_found(lexer, DECIMAL_POINT, "DECIMAL_POINT");
							}
						}
						else if (regex_match(string({c}), regex("\\d"))) {
							return match_found(lexer, DECIMAL_POINT, "DECIMAL_POINT");
						}
					}
					
					if (valid_symbols[JUST_PERIOD]) {
						return match_found(lexer, JUST_PERIOD, "JUST_PERIOD");
					}
				}
			}
			else if (digitAtOrAbove != "") {
				if (valid_symbols[INTEGER]) {
					if (scanningEntity) logEntity(digitAtOrAbove);
					c = (scanningEntity ? lexer->lookahead : advance(lexer));
					
					while (matchNumbers(string({c}), depth) != "") {
						c = advance(lexer);
					}
					mark_end(lexer);
					
					return match_found(lexer, INTEGER, "INTEGER");
				}
			}
			else if (c == '&') {
				if (entity != "" && delimAtDepth == "" && valid_symbols[HTML_ENTITY]) {
					mark_end(lexer);
					
					return match_found(lexer, HTML_ENTITY, "HTML_ENTITY");
				}
				
				if (valid_symbols[JUST_AMPERSAND]) {
					return match_found(lexer, JUST_AMPERSAND, "JUST_AMPERSAND");
				}
			}
		}
		
		logTokenType(lexer, "(no match)", true);
		return false;
	}
};

}

extern "C" {

void *tree_sitter_roll20_script_external_scanner_create() {
	log(color(NULL, brightMagenta)+"                                        ");
	for (const auto& e : entitiesMap) {
		entityChars += e.first;	//map key
	}
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
