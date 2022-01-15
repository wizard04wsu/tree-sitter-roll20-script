#include <tree_sitter/parser.h>
#include <string>	//string, to_string
#include <regex>	//regex, regex_match
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <iostream>	//cout

//for serialization/deserialization using cereal:
//http://uscilab.github.io/cereal/quickstart.html
#include <sstream>
//#include <cereal/archives/json.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/types/stack.hpp>
#include <cereal/types/unordered_set.hpp>

namespace {

using namespace std;


const bool DEBUGGING = false;
const unsigned MAX_ENTITY_NAME_LENGTH = 50;


enum TokenType {
	ROLLQUERY_START,
	ROLLQUERY_END,
		
	INLINEROLL_START,
	INLINEROLL_END,
		
	LABEL_START,
	LABEL_END,
		
	BUTTON_START,
	BUTTON_END,
		
	GROUPROLL_START,
	GROUPROLL_END,
		
	TABLEROLL_START,
	TABLEROLL_END,
	
	PIPE,
	COMMA,
	LEFT_BRACE,
	RIGHT_BRACE,
	LEFT_PAREN,
	RIGHT_PAREN,
	
	HTML_ENTITY,
		
	AMPERSAND,
		
	ANYTHING,
};


//For debugging:
unordered_map<int, string> symbol_strings({
	{ ROLLQUERY_START, "ROLLQUERY_START" },
	{ ROLLQUERY_END, "ROLLQUERY_END" },
		
	{ INLINEROLL_START, "INLINEROLL_START" },
	{ INLINEROLL_END, "INLINEROLL_END" },
		
	{ LABEL_START, "LABEL_START" },
	{ LABEL_END, "LABEL_END" },
		
	{ BUTTON_START, "BUTTON_START" },
	{ BUTTON_END, "BUTTON_END" },
		
	{ GROUPROLL_START, "GROUPROLL_START" },
	{ GROUPROLL_END, "GROUPROLL_END" },
		
	{ TABLEROLL_START, "TABLEROLL_START" },
	{ TABLEROLL_END, "TABLEROLL_END" },
	
	{ PIPE, "PIPE" },
	{ COMMA, "COMMA" },
	{ LEFT_BRACE, "LEFT_BRACE" },
	{ RIGHT_BRACE, "RIGHT_BRACE" },
	{ LEFT_PAREN, "LEFT_PAREN" },
	{ RIGHT_PAREN, "RIGHT_PAREN" },
	
	{ HTML_ENTITY, "HTML_ENTITY" },
		
	{ AMPERSAND, "AMPERSAND" },
		
	{ ANYTHING, "ANYTHING" },
});
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
	string str = color(darkGray);
	for (auto it = symbol_strings.begin(); it != symbol_strings.end(); ++it) {
		str += (valid_symbols[it->first] ? it->second+", " : "");
	}
	cout << str + "\n";
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
	unsigned encodedDepth = 0;	//Depth it would need to be at now if it was a character at depth 1.
								//Like this: starting as a character at depth 1, encode it each time
								// it gets encapsulated in a roll query/group roll/etcetera (i.e., each
								// time its depth is incremented). Add 1 since depths 0 & 1 act the same.
	bool atDepth = false;		//Does the encoded depth equal the current depth?
	string amps = "&";			//First ampersand followed by a possible chain of "amp;"
								// strings before the actual entity name.
	string entityName = "";		//Entity name (not including the following ';').
	string remainder = "";		//Final characters that were consumed but did not end up
								// being part of the entity.
};

string getNextEntityName(TSLexer *lexer, string &remainder){
	
	string entityName = "";
	char c = lexer->lookahead;
	
	while (c != ';' && c != 0 && entityName.length() < MAX_ENTITY_NAME_LENGTH) {
		if (!regex_match(string({c}), regex("[#\\da-zA-Z;]"))) break;
		entityName += c;
		c = advance(lexer);
	}
	
	if (c == ';' && regex_match(entityName, regex("([\\da-zA-Z]+|#(\\d+|[xX][\\da-fA-F]+))"))) {
		c = advance(lexer);
		
		return entityName;
	}
	
	remainder = entityName;
	return "";
	
}

//(when called, lexer->lookahead should be the character after '&')
HtmlEntity getHtmlEntity(TSLexer *lexer, unsigned depth) {
	
	HtmlEntity obj;
	unsigned ampCount = 0;
	unsigned offset = 2;
	string prevEntityName = "";
	string entityName = "";
	string remainder = "";
	regex rxp_amp = regex("amp|AMP|#38|#[xX](00)?26");
	char c = lexer->lookahead;
	
	if (depth < 2) offset = depth;
	
	while (ampCount+offset <= depth) {
		
		prevEntityName = entityName;
		entityName = getNextEntityName(lexer, remainder);
		
		if (regex_match(entityName, rxp_amp)) {
			mark_end(lexer);
			obj.amps += entityName+";";
			ampCount++;
		}
		else {
			if (entityName != "") {
				mark_end(lexer);
				obj.entityName = entityName;
			}
			else if (ampCount > 0) {
				//not followed by an entity name, so use the last "amp;"
				
				ampCount--;
				obj.entityName = prevEntityName;
				obj.remainder = remainder;
			}
			else {
				obj.remainder = remainder;
			}
			
			obj.encodedDepth = depth - (ampCount+1) + (depth > 0 ? 1 : 0);
			if (obj.encodedDepth == depth) obj.atDepth = true;
			
			break;
		}
	}
	
	return obj;
	
}


struct NestedElements {
	
	stack<unordered_set<char>> unsafeChars;
	
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
		if (unsafeChars.size() > 0) unsafeChars.pop();
		return this->depth();
	}
	
	bool isUnsafe(const char c){
		if (unsafeChars.size() <= 1) return false;
		return unsafeChars.top().count(c) > 0;
	}
	
	bool isSafe(const char c){ return !isUnsafe(c); }
	
	
	
	template<class Archive>
	void serialize(Archive & archive) {
		archive(unsafeChars);
	}
	
};

struct Scanner {
	Scanner() {}
	
	TSLexer *lexer;
	const bool *valid_symbols;
	
	NestedElements nest;
	
	
	
	unsigned serialize(char * buffer) {
		stringstream stream_out;
		{
			//cereal::JSONOutputArchive archive_out(stream_out);
			cereal::BinaryOutputArchive archive_out(stream_out);
			archive_out(nest);
		}
		string state2save = stream_out.str();
		state2save.copy(&buffer[0], state2save.size());
		return state2save.size()+1;
	}
	void deserialize(const char * buffer, unsigned length) {
		if (length > 0) {
			string state2load;
			state2load.assign(&buffer[0], length);
			stringstream stream_in;
			stream_in.str(state2load);
			{
				//cereal::JSONInputArchive archive_in(stream_in);
				cereal::BinaryInputArchive archive_in(stream_in);
				archive_in(nest);
			}
		}
	}
	
	
	
	bool match_found(int symbol) {
		log(color(yellow)+"Result set to "+color(brightYellow)+symbol_strings[symbol]);
		
		log("  "
			+color(brightYellow)+log_consumed.substr(0, log_marked)
			+color(gray)+log_consumed.substr(log_marked)
			+color(cyan)+string({char(lexer->lookahead)})
		);
		
		lexer->result_symbol = symbol;
		return true;
	}
	
	bool no_match() {
		log(color(yellow)+"Result set to "+color(brightYellow)+"(no match)");
		
		//consume an extra character
		log_consumed += lexer->lookahead;
		lexer->advance(lexer, false);
		
		unsigned consumed_length = max(int(log_marked), int(log_consumed.length()-1));
		log("  "
			+color(gray)+log_consumed.substr(0, consumed_length)
			+color(cyan)+log_consumed.substr(consumed_length)
			+color(cyan)+string({char(lexer->lookahead)})
		);
		
		return false;
	}
	
	
	bool match_at_depth(HtmlEntity entity, int symbol, char encodedChar, string rxp) {
		log(color(green)+entity.amps+entity.entityName+"; [ "+color(brightGreen)+symbol_strings[symbol]+color(green)+" ] @ depth "+to_string(nest.depth())+" / encoded depth "+to_string(entity.encodedDepth));
		
		log(color(green)+"    symbol "+
			(valid_symbols[symbol]?"":"not ")+"accepted, '"+
			string({encodedChar})+"' is "+(nest.isSafe(encodedChar)?"safe to use here":"reserved")+", will"+
			(entity.encodedDepth <= nest.depth()?"":" not")+" be fully decoded when evaluated, "+
			(regex_match(entity.entityName, regex(rxp))?"matches":"doesn't match")+" the regexp");
		
		return (
			valid_symbols[symbol]
			&& (
				(
					entity.atDepth
					&& nest.depth() > 1
				)
				|| (
					entity.encodedDepth < nest.depth()
					&& nest.isSafe(encodedChar)
				)
			)
			&& regex_match(entity.entityName, regex(rxp))
		);
	}
	template <int N>
	bool match_at_depth(HtmlEntity entity, const int (&symbols)[N], char encodedChar, string rxp) {
		for (int i=0; i<N; i++) {
			string logstr = color(green)+entity.amps+entity.entityName+"; [ ";
			for (int j=0; j<N; j++) {
				logstr += (i==j?color(brightGreen):"")+
					symbol_strings[symbols[j]]+
					(i==j?color(green):"")+", ";
			}
			log(logstr+"] @ depth "+to_string(nest.depth())+" / encoded depth "+to_string(entity.encodedDepth));
			log(color(green)+"    symbol "+
				(valid_symbols[symbols[i]]?"":"not ")+"accepted, '"+
				string({encodedChar})+"' is "+(nest.isSafe(encodedChar)?"safe to use here":"reserved")+", will"+
				(entity.encodedDepth <= nest.depth()?"":" not")+" be fully decoded when evaluated, "+
				(regex_match(entity.entityName, regex(rxp))?"matches":"doesn't match")+" the regexp");
			
			if (valid_symbols[symbols[i]]) {
				return (
					(
						(
							entity.atDepth
							&& nest.depth() > 1
						)
						|| (
							entity.encodedDepth < nest.depth()
							&& nest.isSafe(encodedChar)
						)
					)
					&& regex_match(entity.entityName, regex(rxp))
				);
			}
		}
		
		return false;
	}
	
	
	
	bool scan(TSLexer *theLexer, const bool *theValidSymbols){
		
		lexer = theLexer;
		valid_symbols = theValidSymbols;
		
		log_marked = 0;
		log_consumed = "";
		log(color(brightMagenta)+"Scanning at depth "+to_string(nest.depth()));
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
			
			result = getHtmlEntity(lexer, nest.depth());
			
			if (result.entityName == "") {
				if (valid_symbols[AMPERSAND] && nest.isSafe('&'))
					return match_found(AMPERSAND);
			}
			else {
				c = lexer->lookahead;
				
				if (match_at_depth(result, ROLLQUERY_START, '?', "#63|#[xX](00)?3[fF]|quest")) {
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (match_at_depth(result, ROLLQUERY_START, '{', "#123|#[xX](00)?7[bB]|lcub|lbrace")) {
							mark_end(lexer);
							nest.push("|,}");
							return match_found(ROLLQUERY_START);
						}
					}
					else if (c == '{' && nest.isSafe(c)) {
						c = advance(lexer);
						mark_end(lexer);
						nest.push("|,}");
						return match_found(ROLLQUERY_START);
					}
				}
				
				else if (match_at_depth(result, {INLINEROLL_START, LABEL_START}, '[', "#91|#[xX](00)?5[bB]|lsqb|lbrack")) {
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (match_at_depth(result, INLINEROLL_START, '[', "#91|#[xX](00)?5[bB]|lsqb|lbrack")) {
							mark_end(lexer);
							return match_found(INLINEROLL_START);
						}
						else if (valid_symbols[LABEL_START]) {
							nest.push("]");
							return match_found(LABEL_START);
						}
					}
					else if (c == '[' && valid_symbols[INLINEROLL_START] && nest.isSafe(c)) {
						return match_found(INLINEROLL_START);
					}
					else if (valid_symbols[LABEL_START] && nest.isSafe(c)) {
						nest.push("]");
						return match_found(LABEL_START);
					}
				}
				
				else if (match_at_depth(result, BUTTON_START, '(', "#40|#[xX](00)?28|lpar")) {
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (match_at_depth(result, BUTTON_START, '~', "#126|#[xX](00)?7[eE]")) {
							mark_end(lexer);
							nest.push("|)");
							return match_found(BUTTON_START);
						}
					}
					else if (c == '~' && nest.isSafe(c)) {
						c = advance(lexer);
						mark_end(lexer);
						nest.push("|)");
						return match_found(BUTTON_START);
					}
				}
				
				else if (match_at_depth(result, GROUPROLL_START, '{', "#123|#[xX](00)?7[bB]|lcub|lbrace")) {
					nest.push(",}");
					return match_found(GROUPROLL_START);
				}
				
				else if (match_at_depth(result, TABLEROLL_START, 't', "#116|#[xX](00)?74")
				 || match_at_depth(result, TABLEROLL_START, 'T', "#84|#[xX](00)?54")) {
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity(lexer, nest.depth());
						c = lexer->lookahead;
						
						if (match_at_depth(result, TABLEROLL_START, '[', "#91|#[xX](00)?5[bB]|lsqb|lbrack")) {
							mark_end(lexer);
							nest.push("]");
							return match_found(TABLEROLL_START);
						}
					}
					else if (c == '[' && nest.isSafe(c)) {
						c = advance(lexer);
						mark_end(lexer);
						nest.push("]");
						return match_found(TABLEROLL_START);
					}
				}
				
				else if (match_at_depth(result, {ROLLQUERY_END, GROUPROLL_END}, '}', "#125|#[xX](00)?7[dD]|rcub|rbrace")) {
					if (!valid_symbols[ANYTHING]) {
						nest.pop();
						if (valid_symbols[ROLLQUERY_END]) return match_found(ROLLQUERY_END);
						if (valid_symbols[GROUPROLL_END]) return match_found(GROUPROLL_END);
					}
				}
				
				else if (match_at_depth(result, {INLINEROLL_END, LABEL_END, TABLEROLL_END}, ']', "#93|#[xX](00)?5[dD]|rsqb|rbrack")) {
					if (valid_symbols[LABEL_END]) {
						nest.pop();
						return match_found(LABEL_END);
					}
					else if (valid_symbols[TABLEROLL_END]) {
						nest.pop();
						return match_found(TABLEROLL_END);
					}
					else if (valid_symbols[INLINEROLL_END]) {
						if (c == '&') {
							c = advance(lexer);
							
							result = getHtmlEntity(lexer, nest.depth());
							c = lexer->lookahead;
							
							if (match_at_depth(result, INLINEROLL_END, ']', "#93|#[xX](00)?5[dD]|rsqb|rbrack")) {
								mark_end(lexer);
								nest.pop();
								return match_found(INLINEROLL_END);
							}
						}
						else if (c == ']' && nest.isSafe(c)) {
							nest.pop();
							return match_found(INLINEROLL_END);
						}
					}
				}
				
				else if (match_at_depth(result, BUTTON_END, ')', "#41|#[xX](00)?29|rpar")) {
					nest.pop();
					return match_found(BUTTON_END);
				}
				
				else if (match_at_depth(result, PIPE, '|', "#124|#[xX](00)?7[cC]|vert|verbar|VerticalLine"))
					return match_found(PIPE);
				
				else if (match_at_depth(result, COMMA, ',', "#44|#[xX](00)?2[cC]|comma"))
					return match_found(COMMA);
				
				else if (match_at_depth(result, LEFT_BRACE, '{', "#123|#[xX](00)?7[bB]|lcub|lbrace"))
					return match_found(LEFT_BRACE);
				
				else if (match_at_depth(result, RIGHT_BRACE, '}', "#125|#[xX](00)?7[dD]|rcub|rbrace"))
					return match_found(RIGHT_BRACE);
				
				else if (match_at_depth(result, LEFT_PAREN, '(', "#40|#[xX](00)?28|lpar"))
					return match_found(LEFT_PAREN);
				
				else if (match_at_depth(result, RIGHT_PAREN, ')', "#41|#[xX](00)?29|rpar"))
					return match_found(RIGHT_PAREN);
				
				
				if (valid_symbols[HTML_ENTITY]) {
					return match_found(HTML_ENTITY);
				}
			}
		}
		
		else if (nest.isSafe(c)) {
			if (c == '?' && valid_symbols[ROLLQUERY_START]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (c == '&') {
					c = advance(lexer);
					
					result = getHtmlEntity(lexer, nest.depth());
					c = lexer->lookahead;
					
					if (regex_match(result.entityName, regex("#123|#[xX](00)?7[bB]|lcub|lbrace"))) {
						mark_end(lexer);
						nest.push("|,}");
						return match_found(ROLLQUERY_START);
					}
				}
				else if (c == '{' && nest.isSafe(c)) {
					c = advance(lexer);
					mark_end(lexer);
					nest.push("|,}");
					return match_found(ROLLQUERY_START);
				}
			}
			else if (c == '[' && (valid_symbols[INLINEROLL_START] || valid_symbols[LABEL_START])) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (c == '&') {
					c = advance(lexer);
					
					result = getHtmlEntity(lexer, nest.depth());
					c = lexer->lookahead;
					
					if (regex_match(result.entityName, regex("#91|#[xX](00)?5[bB]|lsqb|lbrack"))) {
						if (valid_symbols[INLINEROLL_START]) {
							return match_found(INLINEROLL_START);
						}
					}
					else if (valid_symbols[LABEL_START]) {
						nest.push("]");
						return match_found(LABEL_START);
					}
				}
				else if (c == '[' && valid_symbols[INLINEROLL_START] && nest.isSafe(c)) {
					c = advance(lexer);
					mark_end(lexer);
					return match_found(INLINEROLL_START);
				}
				else if (c != '[' && valid_symbols[LABEL_START]) {
					nest.push("]");
					return match_found(LABEL_START);
				}
			}
			else if (c == '(' && valid_symbols[BUTTON_START]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (c == '&') {
					c = advance(lexer);
					
					result = getHtmlEntity(lexer, nest.depth());
					c = lexer->lookahead;
					
					if (regex_match(result.entityName, regex("#126|#[xX](00)?7[eE]"))) {
						mark_end(lexer);
						nest.push("|)");
						return match_found(BUTTON_START);
					}
				}
				else if (c == '~' && nest.isSafe(c)) {
					c = advance(lexer);
					mark_end(lexer);
					nest.push("|)");
					return match_found(BUTTON_START);
				}
			}
			else if (c == '{' && valid_symbols[GROUPROLL_START]) {
				c = advance(lexer);
				mark_end(lexer);
				nest.push(",}");
				return match_found(GROUPROLL_START);
			}
			else if ((c == 't' || c == 'T') && valid_symbols[TABLEROLL_START]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (c == '&') {
					c = advance(lexer);
					
					result = getHtmlEntity(lexer, nest.depth());
					c = lexer->lookahead;
					
					if (regex_match(result.entityName, regex("#91|#[xX](00)?5[bB]|lsqb|lbrack"))) {
						mark_end(lexer);
						nest.push("]");
						return match_found(TABLEROLL_START);
					}
				}
				else if (c == '[' && nest.isSafe(c)) {
					c = advance(lexer);
					mark_end(lexer);
					nest.push("]");
					return match_found(TABLEROLL_START);
				}
			}
			
			else if (c == '}') {
				if ((valid_symbols[ROLLQUERY_END] || valid_symbols[GROUPROLL_END])
				 && !valid_symbols[ANYTHING]) {
					c = advance(lexer);
					mark_end(lexer);
					nest.pop();
					if (valid_symbols[ROLLQUERY_END])
						return match_found(ROLLQUERY_END);
					if (valid_symbols[GROUPROLL_END])
						return match_found(GROUPROLL_END);
				}
				else if (valid_symbols[RIGHT_BRACE]) {
					c = advance(lexer);
					mark_end(lexer);
					return match_found(RIGHT_BRACE);
				}
			}
			else if (c == ']' && (valid_symbols[INLINEROLL_END] || valid_symbols[LABEL_END]
			 || valid_symbols[TABLEROLL_END])) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[LABEL_END]) {
					nest.pop();
					return match_found(LABEL_END);
				}
				else if (valid_symbols[TABLEROLL_END]) {
					nest.pop();
					return match_found(TABLEROLL_END);
				}
				else if (c == '&') {
					c = advance(lexer);
					
					result = getHtmlEntity(lexer, nest.depth());
					c = lexer->lookahead;
					
					if (match_at_depth(result, INLINEROLL_END, ']', "#93|#[xX](00)?5[dD]|rsqb|rbrack")) {
						return match_found(INLINEROLL_END);
					}
				}
				else if (c == ']' && valid_symbols[INLINEROLL_END] && nest.isSafe(']')) {
					c = advance(lexer);
					mark_end(lexer);
					return match_found(INLINEROLL_END);
				}
			}
			else if (c == ')' && valid_symbols[BUTTON_END]) {
				c = advance(lexer);
				mark_end(lexer);
				nest.pop();
				return match_found(BUTTON_END);
			}
			
			else if (c == '|' && valid_symbols[PIPE]) {
				c = advance(lexer);
				mark_end(lexer);
				return match_found(PIPE);
			}
			else if (c == ',' && valid_symbols[COMMA]) {
				c = advance(lexer);
				mark_end(lexer);
				return match_found(COMMA);
			}
			else if (c == '{' && valid_symbols[LEFT_BRACE]) {
				c = advance(lexer);
				mark_end(lexer);
				return match_found(LEFT_BRACE);
			}
			else if (c == '(' && valid_symbols[LEFT_PAREN]) {
				c = advance(lexer);
				mark_end(lexer);
				return match_found(LEFT_PAREN);
			}
			else if (c == ')' && valid_symbols[RIGHT_PAREN]) {
				c = advance(lexer);
				mark_end(lexer);
				return match_found(RIGHT_PAREN);
			}
		}
		
		return no_match();
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

unsigned tree_sitter_roll20_script_external_scanner_serialize(void *payload, char *buffer) {
	Scanner *scanner = static_cast<Scanner *>(payload);
	return scanner->serialize(buffer);
}

void tree_sitter_roll20_script_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
	Scanner *scanner = static_cast<Scanner *>(payload);
	scanner->deserialize(buffer, length);
}

void tree_sitter_roll20_script_external_scanner_destroy(void *payload) {
	Scanner *scanner = static_cast<Scanner *>(payload);
	delete scanner;
}

}
