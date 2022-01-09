#include <tree_sitter/parser.h>
#include <string>	//string, to_string
#include <regex>	//regex, regex_match
#include <iostream>	//cout

namespace {

using namespace std;


const unsigned MAX_ENTITY_NAME_LENGTH = 50;


enum TokenType {
	ROLLQUERY_START,
	ROLLQUERY_PIPE,
	ROLLQUERY_END,
	AMP_AT_OR_ABOVE_DEPTH,
	AMP_AT_DEPTH,
	HTML_ENTITY,
};


//For debugging:
const bool debugging = true;
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
		 << (valid_symbols[ROLLQUERY_START]?"ROLLQUERY_START, ":"")
		 << (valid_symbols[ROLLQUERY_PIPE]?"ROLLQUERY_PIPE, ":"")
		 << (valid_symbols[ROLLQUERY_END]?"ROLLQUERY_END, ":"")
		 << (valid_symbols[AMP_AT_OR_ABOVE_DEPTH]?"AMP_AT_OR_ABOVE_DEPTH, ":"")
		 << (valid_symbols[AMP_AT_DEPTH]?"AMP_AT_DEPTH, ":"")
		 << (valid_symbols[HTML_ENTITY]?"HTML_ENTITY, ":"")
		 << "\n";
}


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


int getAmps(TSLexer *lexer, int depth, string &entityName) {
	entityName = "";
	int ampCount = 0;
	int max = depth == -1 ? 0 : depth;
	char c = lexer->lookahead;
	
	while (ampCount < max) {
		while (c != ';' && c != 0 && entityName.length() < 50) {
			entityName += c;
			c = advance(lexer);
		}
		if (c == ';' && regex_match(entityName, regex("amp|AMP|#38|#[xX](00)?26"))) {
			c = advance(lexer);
			mark_end(lexer);
			ampCount++;
		}
		else {
			break;
		}
	}
	
	return ampCount;
}

struct Scanner {
	Scanner() {}
	
	int depth = -1;

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
		log(color(magenta)+"Depth: "+to_string(depth));
		logValidSymbols(valid_symbols);
		logLookahead(lexer);
		
		char c = lexer->lookahead;
		mark_end(lexer);
		
		int ampCount = 0;
		string entityName = "";
		
		if (c == '&') {
			c = advance(lexer);
			mark_end(lexer);
			
			if (valid_symbols[HTML_ENTITY] || valid_symbols[ROLLQUERY_START] || valid_symbols[ROLLQUERY_PIPE] || valid_symbols[ROLLQUERY_END]) {
				ampCount = getAmps(lexer, depth, entityName);
				c = lexer->lookahead;
				
				while (c != ';' && c != 0 && entityName.length() <= MAX_ENTITY_NAME_LENGTH) {
					entityName += c;
					c = advance(lexer);
				}
				
				if (c == ';' && regex_match(entityName, regex("([\\da-zA-Z]+|#(\\d+|[xX][0-9a-fA-F]+))"))) {
					c = advance(lexer);
					mark_end(lexer);
					
					if (valid_symbols[ROLLQUERY_END] && depth > 0 && regex_match(entityName, regex("#125|#[xX](00)?7[dD]|rcub|rbrace"))) {
						depth--;
						log(color(magenta)+"Depth decremented: "+to_string(depth));
						return match_found(lexer, ROLLQUERY_END, "ROLLQUERY_END");
					}
					
					else if (valid_symbols[ROLLQUERY_PIPE] && depth > 0 && regex_match(entityName, regex("#124|#[xX](00)?7[cC]|vert|verbar|VerticalLine"))) {
						return match_found(lexer, ROLLQUERY_PIPE, "ROLLQUERY_PIPE");
					}
					
					else if (valid_symbols[ROLLQUERY_START] && depth >= 0 && regex_match(entityName, regex("#63|#[xX](00)?3[fF]|quest"))) {
						
						if (c == '&') {
							c = advance(lexer);
							
							ampCount = getAmps(lexer, depth, entityName);
							c = lexer->lookahead;
							
							while (c != ';' && c != 0 && entityName.length() < MAX_ENTITY_NAME_LENGTH) {
								entityName += c;
								c = advance(lexer);
							}
							
							if (c == ';' && regex_match(entityName, regex("#123|#[xX](00)?7[bB]|lcub|lbrace"))) {
								c = advance(lexer);
								mark_end(lexer);
								
								depth++;
								log(color(magenta)+"Depth incremented: "+to_string(depth));
								return match_found(lexer, ROLLQUERY_START, "ROLLQUERY_START");
							}
						}
						else if (c == '{') {
							c = advance(lexer);
							mark_end(lexer);
							
							depth++;
							log(color(magenta)+"Depth incremented: "+to_string(depth));
							return match_found(lexer, ROLLQUERY_START, "ROLLQUERY_START");
						}
					}
					
					if (valid_symbols[HTML_ENTITY]) {
						return match_found(lexer, HTML_ENTITY, "HTML_ENTITY");
					}
				}
			}
			
			if (valid_symbols[AMP_AT_OR_ABOVE_DEPTH] || valid_symbols[AMP_AT_DEPTH]) {
				ampCount = getAmps(lexer, depth, entityName);
				c = lexer->lookahead;
				
				if (ampCount >= depth-1 && valid_symbols[AMP_AT_DEPTH]) {
					return match_found(lexer, AMP_AT_DEPTH, "AMP_AT_DEPTH");
				}
				
				else if (valid_symbols[AMP_AT_OR_ABOVE_DEPTH]) {
					return match_found(lexer, AMP_AT_OR_ABOVE_DEPTH, "AMP_AT_OR_ABOVE_DEPTH");
				}
			}
		}
		
		else if (c == '}') {
			c = advance(lexer);
			mark_end(lexer);
			
			if (valid_symbols[ROLLQUERY_END] && depth == 0) {
				depth--;
				log(color(magenta)+"Depth decremented: "+to_string(depth));
				return match_found(lexer, ROLLQUERY_END, "ROLLQUERY_END");
			}
		}
		
		else if (c == '|') {
			c = advance(lexer);
			mark_end(lexer);
			
			if (valid_symbols[ROLLQUERY_PIPE] && depth == 0) {
				return match_found(lexer, ROLLQUERY_PIPE, "ROLLQUERY_PIPE");
			}
		}
		
		else if (c == '?') {
			c = advance(lexer);
			mark_end(lexer);
			
			if (valid_symbols[ROLLQUERY_START]) {
				
				if (c == '&') {
					c = advance(lexer);
					
					ampCount = getAmps(lexer, depth, entityName);
					c = lexer->lookahead;
					
					while (c != ';' && c != 0 && entityName.length() < MAX_ENTITY_NAME_LENGTH) {
						entityName += c;
						c = advance(lexer);
					}
					
					if (c == ';' && regex_match(entityName, regex("#123|#[xX](00)?7[bB]|lcub|lbrace"))) {
						c = advance(lexer);
						mark_end(lexer);
						
						depth++;
						log(color(magenta)+"Depth incremented: "+to_string(depth));
						return match_found(lexer, ROLLQUERY_START, "ROLLQUERY_START");
					}
				}
				
				else if (c == '{') {
					c = advance(lexer);
					mark_end(lexer);
					
					depth++;
					log(color(magenta)+"Depth incremented: "+to_string(depth));
					return match_found(lexer, ROLLQUERY_START, "ROLLQUERY_START");
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
