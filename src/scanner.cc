#include <tree_sitter/parser.h>
#include <string>	//string, to_string
#include <stack>	//stack
#include <map>		//map
#include <utility>	//pair
#include <regex>	//regex, regex_match
#include <iostream>	//cout

namespace {

using namespace std;

const bool doLog = true;

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
	
	
	_INVALID,
};

enum QueryType {
	QT_INVALID_EMPTY = 1,
	QT_INVALID_UNCLOSED = 2,
	QT_PROMPT_ONLY = 4,
	QT_TEXTBOX = 8,
	QT_OPTIONS = 16,
};

enum ANSI_Color {
	//https://stackoverflow.com/a/45300654/15788
	default=39,
	black=30,darkGray=97,gray=37,white=97,
	red=31,yellow=33,green=32,cyan=36,blue=34,magenta=35,
};
string dim(int color, bool background = false) {
	return "\033["+to_string(
		(
			color==default?default:
			color==gray?darkGray:
			color
		)
		+(background?10:0)
	)+"m";
}
string bright(int color, bool background = false) {
	return "\033["+to_string(
		(
			color==default?default:
			color==white?white:
			color==gray?gray:
			color==black?black:
			color+60
		)
		+(background?10:0)
	)+"m";
}

void log(string str) {
	if (doLog) cout << "\033[0m" << str << "\033[0m" << endl;
}
void logLookahead(TSLexer *lexer) {
	char c = lexer->lookahead;
	log(dim(green)+"  Lookahead '"+bright(green)+""+string({c})+dim(green)+"'");
}

char advance(TSLexer *lexer) {
	lexer->advance(lexer, false);
	logLookahead(lexer);
	return lexer->lookahead;
}
void mark_end(TSLexer *lexer) {
	lexer->mark_end(lexer);
	char c = lexer->lookahead;
	log(dim(cyan)+"  Mark end before '"+bright(cyan)+string({c})+dim(cyan)+"'");
}


bool check_for_closure(TSLexer *lexer, char start_char, char end_char) {
	log(dim(magenta)+"  check_for_closure");
	char c = lexer->lookahead;
	if (c == start_char) {
		c = advance(lexer);
		while (c != 0 && c != '\n' && c != end_char) {
			c = advance(lexer);
		}
		if (c == end_char) {
			advance(lexer);
			return true;
		}
	}
	return false;
}

bool scan_macro_start(TSLexer *lexer, unsigned depth) {
	log(dim(magenta)+"  scan_macro_start");
	char c = lexer->lookahead;
	
	if (c == 0 || c == ' ' || c == '\n') return false;
	if (depth > 0 && (c == '|' || c == '}')) return false;
	
	while (c != 0 && c != ' ' && c != '\n') {
		if (depth > 0 && (c == '|' || c == '}')) break;
		if (c == '@' || c == '%') {
			c = advance(lexer);
			if (c == '{' && !check_for_closure(lexer, '{', '}')) return false;
		}
		else {
			c = advance(lexer);
		}
	}
	
	if (c == 0 || c == ' ' || c == '\n') return true;
	
	return false;
}

bool scan_diceRoll_start(TSLexer *lexer) {
	log(dim(magenta)+"  scan_diceRoll_start");
	char c = lexer->lookahead;
	
	if (c == 'f' || c == 'F') {
		return true;
	}
	else if (regex_match(string({c}), regex("\\d"))) {	//c is a digit
		return true;
	}
	else if (c == '@' || c == '%') {
		advance(lexer);
		if (check_for_closure(lexer, '{', '}')) return true;
	}
	return false;
}

bool scan_tableRoll_start(TSLexer *lexer) {
	log(dim(magenta)+"  scan_tableRoll_start");
	char c = lexer->lookahead;
	
	bool rightBracketFound = false;
	if (c == '[') {
		c = advance(lexer);
		while (c != 0 && c != '\n' && c != ']') {
			if (c == '\r'){
				c = advance(lexer);
				continue;
			}
			if (c == '@' || c == '%') {
				c = advance(lexer);
				if (c = '{') {
					while (c != 0 && c != '\n' && c != '}' && c != ']') {
						c = advance(lexer);
					}
					if (c == '}') {
						rightBracketFound = false;	//reset this; if it was found, it was just part of the attribute/ability name
						c = advance(lexer);
						continue;
					}
					else if (c == ']') {
						rightBracketFound = true;
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


map<string, string> entitiesMap;

void populateEntitiesMap() {
	if (!entitiesMap.empty()) return;
	entitiesMap.insert(pair<string, string>("@", "#64|#[xX](00)?40|commat"));
	entitiesMap.insert(pair<string, string>("%", "#37|#[xX](00)?25|percnt"));
	entitiesMap.insert(pair<string, string>("#", "#35|#[xX](00)?23|num"));
	entitiesMap.insert(pair<string, string>("&", "#38|#[xX](00)?26|amp|AMP"));
	entitiesMap.insert(pair<string, string>("[", "#91|#[xX](00)?5[bB]|lsqb|lbrack"));
	entitiesMap.insert(pair<string, string>("(", "#40|#[xX](00)?28|lpar"));
	entitiesMap.insert(pair<string, string>("{", "#123|#[xX](00)?7[bB]|lcub|lbrace"));
	entitiesMap.insert(pair<string, string>("+", "#43|#[xX](00)?2[bB]|plus"));
	entitiesMap.insert(pair<string, string>("-", "#45|#[xX](00)?2[dD]|dash|hyphen"));
	entitiesMap.insert(pair<string, string>("}", "#125|#[xX](00)?7[dD]|rcub|rbrace"));
	entitiesMap.insert(pair<string, string>(")", "#41|#[xX](00)?29|rpar"));
	entitiesMap.insert(pair<string, string>("]", "#93|#[xX](00)?5[dD]|rsqb|rbrack"));
	entitiesMap.insert(pair<string, string>("|", "#124|#[xX](00)?7[cC]|vert|verbar|VerticalLine"));
	entitiesMap.insert(pair<string, string>("?", "#63|#[xX](00)?3[fF]|quest"));
	entitiesMap.insert(pair<string, string>(",", "#44|#[xX](00)?2[cC]|comma"));
	entitiesMap.insert(pair<string, string>("=", "#61|#[xX](00)?3[dD]|equals"));
	entitiesMap.insert(pair<string, string>("~", "#126|#[xX](00)?7[eE]"));
	entitiesMap.insert(pair<string, string>("d", "#100|#[xX](00)?64"));
	entitiesMap.insert(pair<string, string>("D", "#68|#[xX](00)?44"));
	entitiesMap.insert(pair<string, string>("t", "#116|#[xX](00)?74"));
	entitiesMap.insert(pair<string, string>("T", "#84|#[xX](00)?54"));
}

string matchDelimiters(string entity, string delimiters, unsigned depth, bool shallowerIsOkay = false) {
	log(dim(magenta)+"  matchDelimiters");
	
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

string get_entity(TSLexer *lexer, unsigned depth, bool shallowerIsOkay = false) {
	log(dim(magenta)+"  get_entity");
	regex charsRxp = regex("[a-zA-Z0-9]");
	string code = "";
	string entity = "&";
	unsigned amps = 0;
	
	char c = lexer->lookahead;
	
	if (c != '&') {
		log(dim(cyan)+"  not an ampersand '"+bright(cyan)+string({c})+dim(cyan)+"'");
		return "";
	}
	c = advance(lexer);
	
	while (c != 0){
		if (c == '#' && code == "") {
			entity += "#";
			c = advance(lexer);
			if (c == 'x' || c == 'X') {
				entity += string({c});
				charsRxp = regex("[a-fA-F0-9]");
				c = advance(lexer);
			}
			else {
				charsRxp = regex("\\d");
			}
		}
		else {
			charsRxp = regex("[a-zA-Z0-9]");
		}
		
		if (c == ';') {
			entity += code + ";";
			if (depth == 0 || amps == depth-1) {
				advance(lexer);
				if (code.length() < 2){
					log(dim(cyan)+"  entity name too short: \""+code+"\"");
					return "";
				}
				log(dim(cyan)+"  found \""+entity+"\" at depth "+to_string(amps+1)+" of "+to_string(depth));
				return entity;
			}
			else if (code.compare("amp") == 0) {
				amps++;
				code = "";
			}
			else if (shallowerIsOkay) {
				advance(lexer);
				log(dim(cyan)+"  found \""+entity+"\" at depth "+to_string(amps+1)+" of "+to_string(depth));
				return entity;
			}
			else{
				advance(lexer);
				log(dim(cyan)+"  depth != "+to_string(depth)+" for \""+entity+"\"");
				return "";
			}
		}
		else if (!regex_match(string({c}), charsRxp)){
			c = advance(lexer);
			log(dim(cyan)+"  invalid character '"+bright(cyan)+string({c})+dim(cyan)+"'");
			return "";
		}
		code += c;
		c = advance(lexer);
	}
	log(dim(cyan)+"  eof");
	return "";
}
string get_entity_delimiter(TSLexer *lexer, string toMatch, unsigned depth, bool shallowerIsOkay = false) {
	log(dim(magenta)+"  get_entity_delimiter");
	string entity = get_entity(lexer, depth, shallowerIsOkay);
	if (entity == "") return "";
	return matchDelimiters(entity, toMatch, depth, shallowerIsOkay);
}


struct Query {
	Scanner *scanner;
	unsigned depth = 0;
	int type = 0;
	
	Query(Scanner *scanner, unsigned depth) : scanner(scanner), depth(depth) {}
	
	//consumes the part after "?{"
	bool scan_query(TSLexer *lexer, int *type, unsigned depth) {
		log(dim(magenta)+"  Query.scan_query");
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
			log(bright(red)+"  Query missing closing delimiter");
			*type = this->type |= QT_INVALID_UNCLOSED;
			return false;
		}
		else if (isEmpty) {
			log(bright(red)+"  Query has no content");
			*type = this->type |= QT_INVALID_EMPTY;
			return false;
		}
		
		if (optionCount == 0) {
			log(dim(green)+"  Query prompts for text, no default");
			*type = this->type |= QT_PROMPT_ONLY;
		}
		else if (optionCount == 1) {
			log(dim(green)+"  Query prompts for text");
			*type = this->type |= QT_TEXTBOX;
		}
		else {
			log(dim(green)+"  Query prompts for selection");
			*type = this->type |= QT_OPTIONS;
		}
		return true;
	}
	
	//consumes the part after "{" or "|", up to and including the next "|" or
	//   closing "}"
	//sets `isEmpty` to false if it finds content
	//returns the last consumed character (or the unescaped HTML entity)
	char scan_query_part(TSLexer *lexer, int *type, unsigned depth, bool *isEmpty) {
		log(dim(magenta)+"  Query.scan_query_part");
		logLookahead(lexer);
		
		char c = lexer->lookahead;
		string delimiter = "";
		bool prevCharIsForPlaceholder = false;
		bool inPlaceholder = false;
		bool skipNextAdvance = false;
		
		while (c != 0) {
			if (inPlaceholder) {
			//inside an attribute or ability
				if (c == '}') {
				//ends the attribute or ability
					log(dim(cyan)+"  End @{} or %{}");
					inPlaceholder = false;
				}
			}
			else {
				if (c == '&' && depth > 0) {
				//unescape the HTML entity
					delimiter = get_entity_delimiter(lexer, "|}", depth, false);
					if (delimiter == "") delimiter = get_entity_delimiter(lexer, "@%{", depth, true);
					if (delimiter != "") {
					//set unescaped delimiter as the character we're processing
						c = delimiter.c_str()[0];
						skipNextAdvance = true;
					}
				}
				
				if (c == '|' || c == '}') {
				//ends the roll query option
					if (!skipNextAdvance) advance(lexer);
					return c;
				}
				
				if (c == '{' && prevCharIsForPlaceholder) {
				//begins an attribute or ability: @{ or %{
					log(dim(cyan)+"  Begin @{} or %{}");
					prevCharIsForPlaceholder = false;
					inPlaceholder = true;
				}
				else if (c == '@' || c == '%') {
				//might begin an attribute or ability
					prevCharIsForPlaceholder = true;
				}
				else {
					prevCharIsForPlaceholder = false;
				}
			}
			
			*isEmpty = false;
			if (skipNextAdvance) {
				skipNextAdvance = false;
				logLookahead(lexer);
				c = lexer->lookahead;
			}
			else {
				c = advance(lexer);
			}
		}
		
		//EOF; the roll query was never closed
		return 0;
	}
};

struct Scanner {
	stack<Query*> queries;
	
	Scanner() {
		populateEntitiesMap();
	}
	
	bool scan(TSLexer *lexer, const bool *valid_symbols){
		log(bright(magenta)+"  Scanner.scan");
		logLookahead(lexer);
		char c = lexer->lookahead;
		while (c == '\r') { c = advance(lexer); }
		mark_end(lexer);
		
		int queryType = 0;
		if (queries.size() > 0) queryType = queries.top()->type;
		
		
		
		
		if (regex_match(string({c}), "[@%#&[({+-})]|?,=~dDtT]") && depth == 0;) {
			
		}
		
		
		
		
		
		if (c == '@') {
			if (valid_symbols[ATTRIBUTE_START] || valid_symbols[JUST_AT] || valid_symbols[_INVALID]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ATTRIBUTE_START] && check_for_closure(lexer, '{', '}')) {
					log(bright(yellow)+"  ATTRIBUTE_START");
					lexer->result_symbol = ATTRIBUTE_START;
					return true;
				}
				else if (valid_symbols[_INVALID] && c == '{') {
					advance(lexer);
					lexer->mark_end(lexer);
					log(bright(yellow)+"  _INVALID");
					lexer->result_symbol = _INVALID;
					return true;
				}
				else if (valid_symbols[JUST_AT]) {
					log(bright(yellow)+"  JUST_AT");
					lexer->result_symbol = JUST_AT;
					return true;
				}
			}
		}
		else if (c == '%') {
			if (valid_symbols[ABILITY_START] || valid_symbols[JUST_PERCENT] || valid_symbols[_INVALID]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ABILITY_START] && check_for_closure(lexer, '{', '}')) {
					log(bright(yellow)+"  ABILITY_START");
					lexer->result_symbol = ABILITY_START;
					return true;
				}
				else if (valid_symbols[_INVALID] && c == '{') {
					advance(lexer);
					lexer->mark_end(lexer);
					log(bright(yellow)+"  _INVALID");
					lexer->result_symbol = _INVALID;
					return true;
				}
				else if (valid_symbols[JUST_PERCENT]) {
					log(bright(yellow)+"  JUST_PERCENT");
					lexer->result_symbol = JUST_PERCENT;
					return true;
				}
			}
		}
		else if (c == '#') {
			if (valid_symbols[MACRO_START] || valid_symbols[JUST_HASH]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[JUST_HASH] && (c == 0 || c == '\r' || c == '\n' || c == ' ')) {
					while (c == '\r') { c = advance(lexer); }
					log(bright(yellow)+"  JUST_HASH");
					lexer->result_symbol = JUST_HASH;
					return true;
				}
				
				if (valid_symbols[MACRO_START] && scan_macro_start(lexer, queries.size())) {
					log(bright(yellow)+"  MACRO_START");
					lexer->result_symbol = MACRO_START;
					return true;
				}
				
				if (valid_symbols[JUST_HASH]) {
					log(bright(yellow)+"  JUST_HASH");
					lexer->result_symbol = JUST_HASH;
					return true;
				}
			}
		}
		else if (c == '&') {
			
			if (valid_symbols[QUERY_START]) {
				if (get_entity_delimiter(lexer, "?", queries.top()->depth, true) != "") {
					log(dim(blue)+"  entity of '?'");
					c = lexer->lookahead;
					mark_end(lexer);
					
					if (c == '{' || get_entity_delimiter(lexer, "{", queries.top()->depth, true) != "") {
						if (c == '{') advance(lexer);
						mark_end(lexer);
						
						Query *query = new Query(this, queries.size());
						queries.push(query);
						queryType = 0;
						log(bright(cyan)+"  push "+dim(cyan)+"a Query: "+bright(cyan)+to_string(queries.size()));
						
						if (queries.top()->scan_query(lexer, &queryType, queries.top()->depth)) {
							//if (queries.top()->scan_query_part(lexer, &queryType, queries.top()->depth)) {
								log(bright(yellow)+"  QUERY_START");
								lexer->result_symbol = QUERY_START;
								return true;
							//}
						}
						
						queries.pop();
						log(bright(cyan)+"  pop "+dim(cyan)+"a Query: "+bright(cyan)+to_string(queries.size()));
						return false;
					}
					
					if (valid_symbols[JUST_QUESTIONMARK]) {
						log(bright(yellow)+"  JUST_QUESTIONMARK");
						lexer->result_symbol = JUST_QUESTIONMARK;
						return true;
					}
				}
			}
			else if ((valid_symbols[QUERY_PIPE_HASDEFAULT] || valid_symbols[QUERY_PIPE_HASOPTIONS]) && queries.size() > 1) {
				if (get_entity_delimiter(lexer, "|", queries.top()->depth, false) != "") {
					log(dim(blue)+"  entity of '|'");
					mark_end(lexer);
					
					//if (queries.top()->scan_query_part(lexer, &queryType, queries.top()->depth)) {
						if (queryType & QT_TEXTBOX) {
							log(bright(yellow)+"  QUERY_PIPE_HASDEFAULT");
							lexer->result_symbol = QUERY_PIPE_HASDEFAULT;
						}
						else if (queryType & QT_OPTIONS) {
							log(bright(yellow)+"  QUERY_PIPE_HASOPTIONS");
							lexer->result_symbol = QUERY_PIPE_HASOPTIONS;
						}
						return true;
					//}
				}
				return false;
			}
			else if (valid_symbols[QUERY_END] && queries.size() > 0) {
				log(bright(green)+"  >>> QUERY_END <<<");
				if (get_entity_delimiter(lexer, "}", queries.top()->depth, false) != "") {
					log(dim(blue)+"  entity of '}'");
					mark_end(lexer);
					
					log(bright(yellow)+"  QUERY_END");
					lexer->result_symbol = QUERY_END;
					queries.pop();
					log(dim(cyan)+"  pop "+dim(cyan)+"a Query: "+bright(cyan)+to_string(queries.size()));
					return true;
				}
			}
			else if (valid_symbols[JUST_PIPE] && queries.size() > 0) {
				if (get_entity_delimiter(lexer, "|", queries.size(), true) != "") {
					log(dim(blue)+"  entity of '|'");
					mark_end(lexer);
					
					log(bright(yellow)+"  JUST_PIPE");
					lexer->result_symbol = JUST_PIPE;
					return true;
				}
			}
			else if (valid_symbols[JUST_QUESTIONMARK] && queries.size() > 0) {
				if (get_entity_delimiter(lexer, "?", queries.size(), true) != "") {
					log(dim(blue)+"  entity of '?'");
					mark_end(lexer);
					
					log(bright(yellow)+"  JUST_QUESTIONMARK");
					lexer->result_symbol = JUST_QUESTIONMARK;
					return true;
				}
			}
			else {
				advance(lexer);
				mark_end(lexer);
				
				log(bright(yellow)+"  JUST_AMPERSAND");
				lexer->result_symbol = JUST_AMPERSAND;
				return true;
			}
		}
		else if (c == 'd' || c == 'D') {
			if (valid_symbols[DICE_ROLL_START] || valid_symbols[JUST_D]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[DICE_ROLL_START] && scan_diceRoll_start(lexer)) {
					log(bright(yellow)+"  DICE_ROLL_START");
					lexer->result_symbol = DICE_ROLL_START;
					return true;
				}
				
				if (valid_symbols[JUST_D]) {
					log(bright(yellow)+"  JUST_D");
					lexer->result_symbol = JUST_D;
					return true;
				}
			}
		}
		else if (c == 't' || c == 'T') {
			if (valid_symbols[TABLE_ROLL_START] || valid_symbols[JUST_T]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[TABLE_ROLL_START] && scan_tableRoll_start(lexer)) {
					log(bright(yellow)+"  TABLE_ROLL_START");
					lexer->result_symbol = TABLE_ROLL_START;
					return true;
				}
				else if (valid_symbols[JUST_T]) {
					log(bright(yellow)+"  JUST_T");
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
					if (c == '{' || get_entity_delimiter(lexer, "{", queries.top()->depth, true) != "") {
						if (c == '{') advance(lexer);
						mark_end(lexer);
						
						Query *query = new Query(this, queries.size());
						queries.push(query);
						queryType = 0;
						log(bright(cyan)+"  push "+dim(cyan)+"a Query: "+bright(cyan)+to_string(queries.size()));
						
						if (queries.top()->scan_query(lexer, &queryType, queries.top()->depth)) {
							//if (queries.top()->scan_query_options(lexer, &queryType, queries.top()->depth)) {
								log(bright(yellow)+"  QUERY_START");
								lexer->result_symbol = QUERY_START;
								return true;
							//}
						}
						else if (valid_symbols[_INVALID] && queries.top()->type & QT_INVALID_UNCLOSED) {
							advance(lexer);
							mark_end(lexer);
							log(bright(red)+"  _INVALID \"?{\"");
							lexer->result_symbol = _INVALID;
							queries.pop();
							log(dim(cyan)+"  pop "+dim(cyan)+"a Query: "+bright(cyan)+to_string(queries.size()));
							return true;
						}
						
						queries.pop();
						log(dim(cyan)+"  pop "+dim(cyan)+"a Query: "+bright(cyan)+to_string(queries.size()));
						return false;
					}
				}
				
				if (valid_symbols[JUST_QUESTIONMARK]) {
					log(bright(yellow)+"  JUST_QUESTIONMARK");
					lexer->result_symbol = JUST_QUESTIONMARK;
					return true;
				}
			}
		}
		else if (c == '|') {
			if ((valid_symbols[QUERY_PIPE_HASDEFAULT] || valid_symbols[QUERY_PIPE_HASOPTIONS]) && queries.size() == 1) {
				advance(lexer);
				mark_end(lexer);
				
				//log(bright(cyan)+"  get first pipe");
				//if (queries.top()->scan_query_options(lexer, &queryType)) {
					if (queryType & QT_TEXTBOX) {
						log("  QUERY_PIPE_HASDEFAULT");
						lexer->result_symbol = QUERY_PIPE_HASDEFAULT;
						return true;
					}
					else if (queryType & QT_OPTIONS) {
						log(bright(yellow)+"  QUERY_PIPE_HASOPTIONS");
						lexer->result_symbol = QUERY_PIPE_HASOPTIONS;
						return true;
					}
				//}
			}
			else if (valid_symbols[JUST_PIPE]) {
				advance(lexer);
				mark_end(lexer);
				
				log(bright(yellow)+"  JUST_PIPE");
				lexer->result_symbol = JUST_PIPE;
				return true;
			}
		}
		else if (c == '}' && queries.top()->depth == 0) {
			if (valid_symbols[QUERY_END] && queries.size() > 0) {
				c = advance(lexer);
				mark_end(lexer);
				
				log(bright(yellow)+"  QUERY_END");
				lexer->result_symbol = QUERY_END;
				queries.pop();
				log(bright(cyan)+"  pop "+dim(cyan)+"a Query: "+bright(cyan)+to_string(queries.size()));
				return true;
			}
		}
		else {
			log(bright(yellow)+"  (no match)");
			return false;
		}
		return false;
	}
};

}

extern "C" {

void *tree_sitter_roll20_script_external_scanner_create() {
	log(bright(magenta, true)+"                                        ");
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
