#include <tree_sitter/parser.h>
#include <string>	//string, to_string
#include <regex>	//regex, regex_match
#include <stack>
#include <unordered_set>
#include <iostream>	//cout

namespace {

using namespace std;


const bool DEBUGGING = false;
const unsigned MAX_ENTITY_NAME_LENGTH = 50;


enum TokenType {
	ANYTHING,
	
	AMP_AT_OR_ABOVE_DEPTH,
	AMP_AT_DEPTH,
		
	HTML_ENTITY,
		
	ROLLQUERY_START,
	ROLLQUERY_PIPE,
	ROLLQUERY_COMMA,
	ROLLQUERY_END,
		
	LABEL_START,
	LABEL_END,
		
	BUTTON_START,
	BUTTON_PIPE,
	BUTTON_END,
		
	GROUPROLL_START,
	GROUPROLL_COMMA,
	GROUPROLL_END,
		
	TABLEROLL_START,
	TABLEROLL_END,
};


//For debugging:
const bool log_valid_symbols = true;
enum ANSI_Color {
	noChange=0,
	
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
string color(ANSI_Color foreground = noChange, ANSI_Color background = noChange) {
	return "\033["
		+(foreground?to_string(foreground):"")
		+((foreground&&background)?";":"")
		+(background?to_string(background+10):"")
		+"m";
}
unsigned log_marked = 0;
string log_consumed = "";
void log(string str) {
	if (DEBUGGING) cout << "\033[0m" << str << "\033[0m" << endl;
}
void logLookahead(TSLexer *lexer) {
	char c = lexer->lookahead;
	log(color(darkCyan)+"  Lookahead '"+color(lightCyan)+string({c})+color(darkCyan)+"'");
	
}
void logEntity(string character) { log(color(cyan)+"  Entity of '"+character+"'"); }
void logFunction(string functionName) { log(color(magenta)+functionName); }
void logValidSymbols(const bool *valid_symbols) {
	if (!DEBUGGING || !log_valid_symbols) return;
	cout << color(darkGray) //<< "Valid symbols:" << "\n"
		 << (valid_symbols[ANYTHING]?"ANYTHING, ":"")
		 
		 << (valid_symbols[AMP_AT_OR_ABOVE_DEPTH]?"AMP_AT_OR_ABOVE_DEPTH, ":"")
		 << (valid_symbols[AMP_AT_DEPTH]?"AMP_AT_DEPTH, ":"")
		
		 << (valid_symbols[HTML_ENTITY]?"HTML_ENTITY, ":"")
		
		 << (valid_symbols[ROLLQUERY_START]?"ROLLQUERY_START, ":"")
		 << (valid_symbols[ROLLQUERY_PIPE]?"ROLLQUERY_PIPE, ":"")
		 << (valid_symbols[ROLLQUERY_COMMA]?"ROLLQUERY_COMMA, ":"")
		 << (valid_symbols[ROLLQUERY_END]?"ROLLQUERY_END, ":"")
		
		 << (valid_symbols[LABEL_START]?"LABEL_START, ":"")
		 << (valid_symbols[LABEL_END]?"LABEL_END, ":"")
		
		 << (valid_symbols[BUTTON_START]?"BUTTON_START, ":"")
		 << (valid_symbols[BUTTON_PIPE]?"BUTTON_PIPE, ":"")
		 << (valid_symbols[BUTTON_END]?"BUTTON_END, ":"")
		
		 << (valid_symbols[GROUPROLL_START]?"GROUPROLL_START, ":"")
		 << (valid_symbols[GROUPROLL_COMMA]?"GROUPROLL_COMMA, ":"")
		 << (valid_symbols[GROUPROLL_END]?"GROUPROLL_END, ":"")
		
		 << (valid_symbols[TABLEROLL_START]?"TABLEROLL_START, ":"")
		 << (valid_symbols[TABLEROLL_END]?"TABLEROLL_END, ":"")
		 << "\n";
}


char advance(TSLexer *lexer) {
	if (DEBUGGING) log_consumed += lexer->lookahead;
	lexer->advance(lexer, false);
	logLookahead(lexer);
	return lexer->lookahead;
}
void mark_end(TSLexer *lexer) {
	lexer->mark_end(lexer);
	char c = lexer->lookahead;
	log(color(yellow)+"Mark end before '"+string({c})+"'");
	if (DEBUGGING) log_marked = log_consumed.length();
}


struct HtmlEntity {
	unsigned depth = 0;
	string amps = "&";
	string entityName = "";
	string remainder = "";
};

// Gets the HTML entity (starting after the '&') at the specified depth (or above).
// If the HTML entity is a level above that specified, it may act as a special character.
HtmlEntity getHtmlEntity(TSLexer *lexer, unsigned depth) {
	
	HtmlEntity obj;
	unsigned ampCount = 0;
	string entityName;
	char c = lexer->lookahead;
	
	if (depth <= 1) {
		
		//-------------------------------------------
		//too shallow; HTML entities will never act as special characters at these depths
		//-------------------------------------------
		
		obj.depth = depth;
		
		//-------------------------------------------
		//get the entity name following the ampersand
		//-------------------------------------------
		
		entityName = "";
		while (c != ';' && c != 0 && entityName.length() < 50) {
			if (!regex_match(string({c}), regex("[#\\da-zA-Z;]"))) break;
			entityName += c;
			c = advance(lexer);
		}
		
		if (c == ';' && regex_match(entityName, regex("([\\da-zA-Z]+|#(\\d+|[xX][\\da-fA-F]+))"))) {
			
			c = advance(lexer);
			
			obj.entityName = entityName;
		}
		else {
			//didn't find a semicolon; it's just an ampersand
			
			log(color(brightGreen)+"!0> "+entityName);
			obj.remainder = entityName;
		}
		
		if (obj.entityName != "") {
			log(color(green)+"at depth "+to_string(obj.depth)+": "+obj.amps+obj.entityName+";");
		}else{
			log(color(green)+"just an ampersand; remainder: "+obj.remainder);
		}
		return obj;
		
	}
	
	//-------------------------------------------
	//collect the "amp;" names as we go down to `depth`
	//-------------------------------------------
	
	while (ampCount+1 < depth) {
		
		entityName = "";
		while (c != ';' && c != 0 && entityName.length() < 50) {
			if (!regex_match(string({c}), regex("[#\\da-zA-Z;]"))) break;
			entityName += c;
			c = advance(lexer);
		}
		
		if (c == ';' && regex_match(entityName, regex("amp|AMP|#38|#[xX](00)?26"))) {
			
			c = advance(lexer);
			mark_end(lexer);
			
			obj.amps += "amp;";
			ampCount++;
		}
		else {
			//ran out of "amp;" names before we got to `depth`
			log(color(brightGreen)+"!> "+entityName);
			
			if (c == ';' && regex_match(entityName, regex("([\\da-zA-Z]+|#(\\d+|[xX][\\da-fA-F]+))"))) {
				//follwed by an entity name
				
				c = advance(lexer);
				mark_end(lexer);
				
				obj.entityName = entityName;
				obj.depth = ampCount+2;
			}
			else if (ampCount > 0) {
				//not followed by an entity name, so use the last "amp;"
				
				ampCount--;
				
				obj.entityName = "amp";
				obj.depth = ampCount+2;
			}
			else {
				//it's just an ampersand
				
				obj.remainder = entityName;
			}
			
			if (obj.entityName != "") {
				log(color(green)+"at depth "+to_string(obj.depth)+": "+obj.amps+obj.entityName+";");
			}else{
				log(color(green)+"just an ampersand; remainder: "+obj.remainder);
			}
			return obj;
		}
		
		
		//-------------------------------------------
		//get the entity name following the ampersand or semicolon
		//-------------------------------------------
		
		entityName = "";
		while (c != ';' && c != 0 && entityName.length() < 50) {
			if (!regex_match(string({c}), regex("[#\\da-zA-Z;]"))) break;
			entityName += c;
			c = advance(lexer);
		}
		
		log(color(brightGreen)+"entityName: "+entityName);
		if (c == ';' && regex_match(entityName, regex("([\\da-zA-Z]+|#(\\d+|[xX][\\da-fA-F]+))"))) {
			//follwed by an entity name
			
			c = advance(lexer);
			mark_end(lexer);
			
			obj.entityName = entityName;
			obj.depth = ampCount+2;
		}
		else if (ampCount > 0) {
			//not followed by an entity name, so use the last "amp;"
			
			ampCount--;
			
			obj.entityName = "amp";
			obj.depth = ampCount+2;
		}
		else {
			//it's just an ampersand
			
			obj.remainder = entityName;
		}
			
	}
	
	if (obj.entityName != "") {
		log(color(green)+"at depth "+to_string(obj.depth)+": "+obj.amps+obj.entityName+";");
	}else{
		log(color(green)+"just an ampersand; remainder: "+obj.remainder);
	}
	return obj;
	
}


class NestedElements {
	
	stack<unordered_set<char>> unsafeChars;
	
public:
	
	unsigned depth(){ return unsafeChars.size(); }
	
	unsigned push(const string specialChars){
		unordered_set<char> uc;
		if (unsafeChars.size() > 0) uc = unsafeChars.top();
		unsigned i;
		for (i=0; i<specialChars.length(); i++) {
			uc.insert(specialChars[i]);
		}
		unsafeChars.push(uc);
		return this->depth();
	}
	
	unsigned pop(){
		unsafeChars.pop();
		return this->depth();
	}
	
	bool isUnsafe(const char c){
		if (unsafeChars.size() <= 1) return false;
		return unsafeChars.top().count(c) > 0;
	}
	
	bool isSafe(const char c){ return !isUnsafe(c); }
	
};

struct Scanner {
	Scanner() {}
	
	NestedElements nest;
	
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
	
	bool no_match(TSLexer *lexer) {
		logTokenType(lexer, "(no match)", true);
		return false;
	}
	
	
	
	bool scan(TSLexer *lexer, const bool *valid_symbols){
		log_marked = 0;
		log_consumed = "";
		log(color(brightMagenta)+"Scanner.scan");
		log(color(magenta)+"Depth: "+to_string(nest.depth()));
		logValidSymbols(valid_symbols);
		logLookahead(lexer);
		
		int ampCount = 0;
		HtmlEntity initialResult;
		HtmlEntity result;
		string entityName = "";
		
		char c = lexer->lookahead;
		mark_end(lexer);
		
		if (c == '&') {
			c = advance(lexer);
			mark_end(lexer);
			
			initialResult = getHtmlEntity(lexer, nest.depth());
			
			if (initialResult.entityName != ""
			 && initialResult.depth == nest.depth()
			 && (
			 valid_symbols[ROLLQUERY_START]
			 || valid_symbols[GROUPROLL_START]
			 || valid_symbols[LABEL_START]
			 || valid_symbols[BUTTON_START]
			 || valid_symbols[TABLEROLL_START]
			 || valid_symbols[ROLLQUERY_END]
			 || valid_symbols[GROUPROLL_END]
			 || valid_symbols[LABEL_END]
			 || valid_symbols[TABLEROLL_END]
			 || valid_symbols[BUTTON_END]
			 || valid_symbols[ROLLQUERY_PIPE]
			 || valid_symbols[ROLLQUERY_COMMA]
			 || valid_symbols[GROUPROLL_COMMA])) {
				
				result = initialResult;
				c = lexer->lookahead;
				
				if (regex_match(result.entityName, regex("#63|#[xX](00)?3[fF]|quest"))
				 && valid_symbols[ROLLQUERY_START]) {
					
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (result.depth == nest.depth() && regex_match(result.entityName, regex("#123|#[xX](00)?7[bB]|lcub|lbrace"))) {
							mark_end(lexer);
							
							nest.push("|,}");
							return match_found(lexer, ROLLQUERY_START, "ROLLQUERY_START");
						}
					}
					else if (c == '{') {
						c = advance(lexer);
						mark_end(lexer);
						
						nest.push("|,}");
						return match_found(lexer, ROLLQUERY_START, "ROLLQUERY_START");
					}
				}
				
				else if (regex_match(result.entityName, regex("#123|#[xX](00)?7[bB]|lcub|lbrace"))
				 && valid_symbols[GROUPROLL_START]) {
					nest.push(",}");
					return match_found(lexer, GROUPROLL_START, "GROUPROLL_START");
				}
				
				else if (regex_match(result.entityName, regex("#91|#[xX](00)?5[bB]|lsqb|lbrack"))
				 && valid_symbols[LABEL_START]) {
					
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (result.depth < nest.depth() || (result.depth == nest.depth() && !regex_match(result.entityName, regex("#91|#[xX](00)?5[bB]|lsqb|lbrack")))) {
							
							nest.push("]");
							return match_found(lexer, LABEL_START, "LABEL_START");
						}
					}
					
					else if (c != '[' && nest.isSafe(c)) {
						nest.push("]");
						return match_found(lexer, LABEL_START, "LABEL_START");
					}
				}
				
				else if (regex_match(result.entityName, regex("#40|#[xX](00)?28|lpar"))
				 && valid_symbols[BUTTON_START]) {
					
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (result.depth == nest.depth() && regex_match(result.entityName, regex("#126|#[xX](00)?7[eE]"))) {
							mark_end(lexer);
							
							nest.push("|)");
							return match_found(lexer, BUTTON_START, "BUTTON_START");
						}
					}
					
					else if (c == '~' && nest.isSafe(c)) {
						c = advance(lexer);
						mark_end(lexer);
						
						nest.push("|)");
						return match_found(lexer, BUTTON_START, "BUTTON_START");
					}
				}
				
				else if (regex_match(result.entityName, regex("#116|#[xX](00)?74|#84|#[xX](00)?54"))
				 && valid_symbols[TABLEROLL_START]) {
					
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (result.depth == nest.depth() && regex_match(result.entityName, regex("#91|#[xX](00)?5[bB]|lsqb|lbrack"))) {
							mark_end(lexer);
							
							nest.push("]");
							return match_found(lexer, TABLEROLL_START, "TABLEROLL_START");
						}
					}
					
					else if (c == '[' && nest.isSafe(c)) {
						c = advance(lexer);
						mark_end(lexer);
						
						nest.push("]");
						return match_found(lexer, TABLEROLL_START, "TABLEROLL_START");
					}
				}
				
				else if (regex_match(result.entityName, regex("#125|#[xX](00)?7[dD]|rcub|rbrace"))
				 && (valid_symbols[ROLLQUERY_END] || valid_symbols[GROUPROLL_END])) {
					
					if (valid_symbols[ROLLQUERY_END] && nest.isUnsafe('}') && !valid_symbols[ANYTHING]) {
						mark_end(lexer);
						
						nest.pop();
						return match_found(lexer, ROLLQUERY_END, "ROLLQUERY_END");
					}
					
					else if (valid_symbols[GROUPROLL_END] && nest.isUnsafe('}') && !valid_symbols[ANYTHING]) {
						mark_end(lexer);
						
						nest.pop();
						return match_found(lexer, GROUPROLL_END, "GROUPROLL_END");
					}
				}
				
				else if (regex_match(result.entityName, regex("#93|#[xX](00)?5[dD]|rsqb|rbrack"))
				 && (valid_symbols[LABEL_END] || valid_symbols[TABLEROLL_END])) {
					
					if (valid_symbols[LABEL_END] && nest.isUnsafe(']')) {
						mark_end(lexer);
						
						nest.pop();
						return match_found(lexer, LABEL_END, "LABEL_END");
					}
					
					else if (valid_symbols[TABLEROLL_END] && nest.isUnsafe(']')) {
						mark_end(lexer);
						
						nest.pop();
						return match_found(lexer, TABLEROLL_END, "TABLEROLL_END");
					}
				}
				
				else if (regex_match(result.entityName, regex("#41|#[xX](00)?29|rpar"))
				 && valid_symbols[BUTTON_END] && nest.isUnsafe(')')) {
					 mark_end(lexer);
					 
					nest.pop();
					return match_found(lexer, BUTTON_END, "BUTTON_END");
				}
				
				else if (regex_match(result.entityName, regex("#124|#[xX](00)?7[cC]|vert|verbar|VerticalLine"))
				 && valid_symbols[ROLLQUERY_PIPE] && nest.isUnsafe('|')) {
					 mark_end(lexer);
					 
					return match_found(lexer, ROLLQUERY_PIPE, "ROLLQUERY_PIPE");
				}
				
				else if (regex_match(result.entityName, regex("#44|#[xX](00)?2[cC]|comma"))
				 && (valid_symbols[ROLLQUERY_COMMA] || valid_symbols[GROUPROLL_COMMA])) {
					
					if (valid_symbols[ROLLQUERY_COMMA] && nest.isUnsafe(',')) {
						mark_end(lexer);
						
						return match_found(lexer, ROLLQUERY_COMMA, "ROLLQUERY_COMMA");
					}
					
					else if (valid_symbols[GROUPROLL_COMMA] && nest.isUnsafe(',')) {
						mark_end(lexer);
						
						return match_found(lexer, GROUPROLL_COMMA, "GROUPROLL_COMMA");
					}
				}
				
				if (valid_symbols[HTML_ENTITY]) {
					mark_end(lexer);
					
					return match_found(lexer, HTML_ENTITY, "HTML_ENTITY");
				}
			}
			
			else if (initialResult.entityName != "" && valid_symbols[HTML_ENTITY]) {
				mark_end(lexer);
				
				return match_found(lexer, HTML_ENTITY, "HTML_ENTITY");
			}
			
			
			if (valid_symbols[AMP_AT_OR_ABOVE_DEPTH] || valid_symbols[AMP_AT_DEPTH]) {
				
				result = initialResult;
				
				if (result.depth == nest.depth() && valid_symbols[AMP_AT_DEPTH]) {
					return match_found(lexer, AMP_AT_DEPTH, "AMP_AT_DEPTH");
				}
				
				else if (valid_symbols[AMP_AT_OR_ABOVE_DEPTH]) {
					return match_found(lexer, AMP_AT_OR_ABOVE_DEPTH, "AMP_AT_OR_ABOVE_DEPTH");
				}
			}
		}
		
		else if (nest.isSafe(c)) {
			
			if (c == '?') {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ROLLQUERY_START]) {
					
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (result.depth == nest.depth() && regex_match(result.entityName, regex("#123|#[xX](00)?7[bB]|lcub|lbrace"))) {
							mark_end(lexer);
							
							nest.push("|,}");
							return match_found(lexer, ROLLQUERY_START, "ROLLQUERY_START");
						}
					}
					
					else if (c == '{' && nest.isSafe(c)) {
						c = advance(lexer);
						mark_end(lexer);
						
						nest.push("|,}");
						return match_found(lexer, ROLLQUERY_START, "ROLLQUERY_START");
					}
				}
			}
			
			else if (c == '{') {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[GROUPROLL_START]) {
					nest.push(",}");
					return match_found(lexer, GROUPROLL_START, "GROUPROLL_START");
				}
			}
			
			else if (c == '[') {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[LABEL_START]) {
					
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (result.depth < nest.depth() || (result.depth == nest.depth() && !regex_match(result.entityName, regex("#91|#[xX](00)?5[bB]|lsqb|lbrack")))) {
							nest.push("]");
							return match_found(lexer, LABEL_START, "LABEL_START");
						}
					}
					
					else if (c != '[' && nest.isSafe(c)) {
						nest.push("]");
						return match_found(lexer, LABEL_START, "LABEL_START");
					}
				}
			}
			
			else if (c == '(') {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[BUTTON_START]) {
					
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (result.depth == nest.depth() && regex_match(result.entityName, regex("#126|#[xX](00)?7[eE]"))) {
							mark_end(lexer);
							
							nest.push("|)");
							return match_found(lexer, BUTTON_START, "BUTTON_START");
						}
					}
					
					else if (c == '~' && nest.isSafe(c)) {
						c = advance(lexer);
						mark_end(lexer);
						
						nest.push("|)");
						return match_found(lexer, BUTTON_START, "BUTTON_START");
					}
				}
			}
			
			else if (c == 't' || c == 'T') {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[TABLEROLL_START]) {
					
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (result.depth == nest.depth() && regex_match(result.entityName, regex("#91|#[xX](00)?5[bB]|lsqb|lbrack"))) {
							mark_end(lexer);
							
							nest.push("]");
							return match_found(lexer, TABLEROLL_START, "TABLEROLL_START");
						}
					}
					
					else if (c == '[' && nest.isSafe(c)) {
						c = advance(lexer);
						mark_end(lexer);
						
						nest.push("]");
						return match_found(lexer, TABLEROLL_START, "TABLEROLL_START");
					}
				}
			}
			
			else if (c == '}') {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ROLLQUERY_END] && !valid_symbols[ANYTHING]) {
					nest.pop();
					return match_found(lexer, ROLLQUERY_END, "ROLLQUERY_END");
				}
				
				else if (valid_symbols[GROUPROLL_END] && !valid_symbols[ANYTHING]) {
					nest.pop();
					return match_found(lexer, GROUPROLL_END, "GROUPROLL_END");
				}
			}
			
			else if (c == ']') {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[LABEL_END]) {
					nest.pop();
					return match_found(lexer, LABEL_END, "LABEL_END");
				}
				
				else if (valid_symbols[TABLEROLL_END]) {
					nest.pop();
					return match_found(lexer, TABLEROLL_END, "TABLEROLL_END");
				}
			}
			
			else if (c == ')') {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[BUTTON_END]) {
					nest.pop();
					return match_found(lexer, BUTTON_END, "BUTTON_END");
				}
			}
			
			else if (c == ',') {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ROLLQUERY_COMMA]) {
					return match_found(lexer, ROLLQUERY_COMMA, "ROLLQUERY_COMMA");
				}
				
				else if (valid_symbols[GROUPROLL_COMMA]) {
					return match_found(lexer, GROUPROLL_COMMA, "GROUPROLL_COMMA");
				}
			}
			
			else if (c == '|') {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ROLLQUERY_PIPE]) {
					return match_found(lexer, ROLLQUERY_PIPE, "ROLLQUERY_PIPE");
				}
				
				else if (valid_symbols[BUTTON_PIPE]) {
					return match_found(lexer, BUTTON_PIPE, "BUTTON_PIPE");
				}
			}
			
		}
		
		return no_match(lexer);
	}
};

}

extern "C" {

void *tree_sitter_roll20_script_external_scanner_create() {
	log(color(noChange, brightMagenta)+"                                        ");
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
