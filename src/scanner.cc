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
	COLON,
	
	FLAG_START,
	FLAG_END,
	ROLLTEMPLATE_PROPERTY_START,
	ROLLTEMPLATE_PROPERTY_END,
	
	HTML_ENTITY,
		
	AMPERSAND,
};
//for debugging:
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
	{ COLON, "COLON" },
	
	{ FLAG_START, "FLAG_START" },
	{ FLAG_END, "FLAG_END" },
	{ ROLLTEMPLATE_PROPERTY_START, "ROLLTEMPLATE_PROPERTY_START" },
	{ ROLLTEMPLATE_PROPERTY_END, "ROLLTEMPLATE_PROPERTY_END" },
	
	{ HTML_ENTITY, "HTML_ENTITY" },
		
	{ AMPERSAND, "AMPERSAND" },
});


struct HtmlEntity;


/*╔════════════════════════════════════════════════════════════
  ║ For debugging
  ╚════════════════════════════════════════════════════════════*/

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
string color_passFail(bool test) { return color(test ? brightGreen : darkRed); }

struct DebugTools {
	
private:
	string consumed = "";
	unsigned markedEndAt = 0;
	
public:
	void init() {
		consumed = "";
		markedEndAt = 0;
	}
	
	
	void log(string str) {
		if (!DEBUGGING) return;
		cout << "\033[0m" << str << "\033[0m" << endl;
	}
	
	
	void logValidSymbols(const bool *valid_symbols) {
		if (!DEBUGGING) return;
		string str = color(darkGray);
		for (auto it = symbol_strings.begin(); it != symbol_strings.end(); ++it) {
			str += (valid_symbols[it->first] ? it->second+", " : "");
		}
		log(str);
	}
	
	
	void saveLookahead(TSLexer *lexer) {
		if (!DEBUGGING) return;
		consumed += lexer->lookahead;
	}
	void logLookahead(TSLexer *lexer) {
		if (!DEBUGGING) return;
		log(color(darkCyan)+"  Lookahead '"+color(lightCyan)+string({char(lexer->lookahead)})+color(darkCyan)+"'");
	}
	void logMarkEnd(TSLexer *lexer) {
		if (!DEBUGGING) return;
		log(color(yellow)+"Mark end before '"+string({char(lexer->lookahead)})+"'");
		markedEndAt = consumed.length();
	}
	
	
	void logMatchFound(TSLexer *lexer, int symbol) {
		if (!DEBUGGING) return;
		log(color(yellow)+"Result set to "+color(brightYellow)+symbol_strings[symbol]);
		log("  "
			+color(brightYellow)+consumed.substr(0, markedEndAt)
			+color(gray)+consumed.substr(markedEndAt)
			+color(cyan)+string({char(lexer->lookahead)})
		);
	}
	void logNoMatch(TSLexer *lexer) {
		if (!DEBUGGING) return;
		log(color(yellow)+"Result set to "+color(brightYellow)+"(no match)");
		unsigned consumed_length = max(int(markedEndAt), int(consumed.length()-1));
		log("  "
			+color(gray)+consumed.substr(0, consumed_length)
			+color(cyan)+consumed.substr(consumed_length)
			+color(cyan)+string({char(lexer->lookahead)})
		);
	}
	
};
DebugTools Debug;


/*╔════════════════════════════════════════════════════════════
  ║ Nested Elements
  ╚╤═══════════════════════════════════════════════════════════*/
 /*│ Track the state of nested roll queries, group rolls, table rolls, and buttons.
   │ This includes their depth and related special characters.
   └─────────────────────────────*/

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


/*╔════════════════════════════════════════════════════════════
  ║ The Scanner
  ╚════════════════════════════════════════════════════════════*/

struct Scanner {
	Scanner() {}
	
	TSLexer *lexer;
	const bool *valid_symbols;
	
	NestedElements nest;
	bool inRollTemplateProperty = false;
	
	
	/*╔════════════════════════════════════════════════════════════
	  ║ Serialize/deserialize the state of `nest`
	  ╚════════════════════════════════════════════════════════════*/
	
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
	
	
	/*╔════════════════════════════════════════════════════════════
	  ║ Get an HTML entity and determine its purpose
	  ╚════════════════════════════════════════════════════════════*/
	
	struct HtmlEntity {
		string str = "&";			//the '&', a possible chain of "amp;" strings, the final
									// entity name/code, and the following ';'
		
		string entityName = "";		//just the final name/code, not including the following ';'
		
		string remainder = "";		//final characters that were traversed but did not end up
									// being part of the entity
		
		unsigned timesEncoded = 0;	//number of times the represented character was encoded
		unsigned foundAtDepth;		//the current depth when this entity was encountered
		
		bool isChar(unsigned depth) { return timesEncoded == depth - 1; }
		bool isEntity(unsigned depth) { return timesEncoded >= depth; }
	};
	enum UseEntityAs {
		AS_CHARACTER,
		AS_ENTITY,
		AS_START,
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
	HtmlEntity getHtmlEntity() {
		
		regex rxp_amp = regex("amp|AMP|#38|#[xX](00)?26");
		
		//if it's not a character after this many decodings, it will always be interpreted as an HTML entity
		unsigned maxDecodings = max(0, int(nest.depth())-1);
		
		HtmlEntity obj;
		obj.foundAtDepth = nest.depth();
		
		
		while (obj.timesEncoded <= maxDecodings) {
			
			obj.entityName = getNextEntityName(lexer, obj.remainder);
			
			if (obj.entityName != "") {
				mark_end(lexer);
				obj.str += obj.entityName+";";
				obj.timesEncoded++;
				
				if (!regex_match(obj.entityName, rxp_amp)) {
					//it's an entity for something besides an ampersand
					break;
				}
			}
			else {
				//it's either an entity for an ampersand, or it's just an ampersand character
				break;
			}
		}
		
		return obj;
	}
	
	template <int N>
	bool checkEntity(HtmlEntity entity, const int (&symbols)[N], char encodedChar, string rxp, int useAs = AS_CHARACTER) {
		bool entityMatches = regex_match(entity.entityName, regex(rxp));
		
		bool validUse = ( useAs == AS_CHARACTER && entity.isChar(nest.depth() + (inRollTemplateProperty?1:0)) )
			|| ( useAs == AS_ENTITY && entity.isEntity(nest.depth()) )
			|| ( useAs == AS_START && entity.isEntity(nest.depth()) );
		
		bool validSymbolFound = false;
		for (int i=0; i<N; i++) {
			if (valid_symbols[symbols[i]]) {
				validSymbolFound = true;
				break;
			}
		}
		
		if (DEBUGGING) {
			string str = "" +
				//HTML entity; does it match?
				color_passFail(entityMatches) + entity.str + "  " +
				//character it represents; is it safe here?
				color_passFail(nest.isSafe(encodedChar)) + string({encodedChar}) + "  " +
				//its intended use; can it be that?
				color_passFail(validUse) +
				(useAs==AS_CHARACTER ? "char  " :
				useAs==AS_START ? "start " :
				useAs==AS_ENTITY ? "entity" :
				"n/a   ") +
				color(green) + "  [ ";
			
			//highlight accepted symbols
			for (int i=0; i<N; i++) {
				if (i > 0) str += color(green)+", ";
				str += color_passFail(valid_symbols[symbols[i]]) + symbol_strings[symbols[i]];
			}
			Debug.log(str + color(green) + " ]");
		}
		
		return ( validSymbolFound && validUse && entityMatches );
	}
	
	
	/*╔════════════════════════════════════════════════════════════
	  ║ Lexer manipulation
	  ╚════════════════════════════════════════════════════════════*/
	
	char advance(TSLexer *lexer) {
		Debug.saveLookahead(lexer);
		lexer->advance(lexer, false);
		Debug.logLookahead(lexer);
		return lexer->lookahead;
	}
	void mark_end(TSLexer *lexer) {
		lexer->mark_end(lexer);
		Debug.logMarkEnd(lexer);
	}
	
	bool match_found(int symbol) {
		Debug.logMatchFound(lexer, symbol);
		lexer->result_symbol = symbol;
		return true;
	}
	bool no_match() {
		//consume an extra character for debug log
		Debug.saveLookahead(lexer);
		lexer->advance(lexer, false);
		Debug.logNoMatch(lexer);
		
		return false;
	}
	
	
	/*╔════════════════════════════════════════════════════════════
	  ║ Scanning
	  ╚════════════════════════════════════════════════════════════*/
	
	bool scan(TSLexer *theLexer, const bool *theValidSymbols){
		
		lexer = theLexer;
		valid_symbols = theValidSymbols;
		
		Debug.init();
		Debug.log(color(brightMagenta)+"Scanning at depth "+to_string(nest.depth()));
		Debug.logValidSymbols(valid_symbols);
		Debug.logLookahead(lexer);
		
		HtmlEntity result;
		string entityName = "";
		
		char c = lexer->lookahead;
		mark_end(lexer);
		
		if (c == '&') {
			c = advance(lexer);
			mark_end(lexer);
			
			result = getHtmlEntity();
			
			if (result.entityName == "") {
				if (nest.isSafe('&')) {
					
					if (c == '{' && nest.isSafe(c)) {
						if (valid_symbols[FLAG_START]) {
							c = advance(lexer);
							mark_end(lexer);
							nest.push(":}");
							return match_found(FLAG_START);
						}
					}
					else {
						if (c == '&' && valid_symbols[FLAG_START]) {
							c = advance(lexer);
							
							result = getHtmlEntity();
							c = lexer->lookahead;
							
							if (checkEntity(result, {FLAG_START}, '{', "#123|#[xX](00)?7[bB]|lcub|lbrace")) {
								mark_end(lexer);
								nest.push(":}");
								return match_found(FLAG_START);
							}
						}
						
						if (valid_symbols[AMPERSAND])
							return match_found(AMPERSAND);
					}
					
				}
			}
			else {
				c = lexer->lookahead;
				
				if (checkEntity(result, {ROLLQUERY_START}, '?', "#63|#[xX](00)?3[fF]|quest", AS_START)) {
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity();
						c = lexer->lookahead;
						
						if (checkEntity(result, {ROLLQUERY_START}, '{', "#123|#[xX](00)?7[bB]|lcub|lbrace")) {
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
				
				else if (checkEntity(result, {INLINEROLL_START, LABEL_START}, '[', "#91|#[xX](00)?5[bB]|lsqb|lbrack")) {
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity();
						c = lexer->lookahead;
						
						if (checkEntity(result, {INLINEROLL_START}, '[', "#91|#[xX](00)?5[bB]|lsqb|lbrack")) {
							mark_end(lexer);
							return match_found(INLINEROLL_START);
						}
						else if (valid_symbols[LABEL_START]) {
							//nest.push("]");
							return match_found(LABEL_START);
						}
					}
					else if (c == '[' && valid_symbols[INLINEROLL_START] && nest.isSafe(c)) {
						return match_found(INLINEROLL_START);
					}
					else if (valid_symbols[LABEL_START] && nest.isSafe(c)) {
						//nest.push("]");
						return match_found(LABEL_START);
					}
				}
				
				else if (checkEntity(result, {BUTTON_START}, '(', "#40|#[xX](00)?28|lpar", AS_START)) {
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity();
						c = lexer->lookahead;
						
						if (checkEntity(result, {BUTTON_START}, '~', "#126|#[xX](00)?7[eE]", AS_START)) {
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
				
				else if (checkEntity(result, {LEFT_PAREN}, '(', "#40|#[xX](00)?28|lpar"))
					return match_found(LEFT_PAREN);
				
				else if (checkEntity(result, {ROLLTEMPLATE_PROPERTY_START}, '{', "#123|#[xX](00)?7[bB]|lcub|lbrace", AS_START)) {
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity();
						c = lexer->lookahead;
						
						if (checkEntity(result, {ROLLTEMPLATE_PROPERTY_START}, '{', "#123|#[xX](00)?7[bB]|lcub|lbrace")) {
							mark_end(lexer);
							//nest.push("}");
							inRollTemplateProperty = true;
							return match_found(ROLLTEMPLATE_PROPERTY_START);
						}
					}
					else if (c == '{' && nest.isSafe(c)) {
						c = advance(lexer);
						mark_end(lexer);
						//nest.push("}");
						inRollTemplateProperty = true;
						return match_found(ROLLTEMPLATE_PROPERTY_START);
					}
				}
				
				else if (checkEntity(result, {GROUPROLL_START}, '{', "#123|#[xX](00)?7[bB]|lcub|lbrace", AS_START)) {
					nest.push(",}");
					return match_found(GROUPROLL_START);
				}
				
				else if (checkEntity(result, {LEFT_BRACE}, '{', "#123|#[xX](00)?7[bB]|lcub|lbrace"))
					return match_found(LEFT_BRACE);
				
				else if (checkEntity(result, {TABLEROLL_START}, 't', "#116|#[xX](00)?74", AS_START)
				 || checkEntity(result, {TABLEROLL_START}, 'T', "#84|#[xX](00)?54", AS_START)) {
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity();
						c = lexer->lookahead;
						
						if (checkEntity(result, {TABLEROLL_START}, '[', "#91|#[xX](00)?5[bB]|lsqb|lbrack", AS_START)) {
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
				
				else if (checkEntity(result, {ROLLQUERY_END, GROUPROLL_END, FLAG_END}, '}', "#125|#[xX](00)?7[dD]|rcub|rbrace")) {
					nest.pop();
					if (valid_symbols[ROLLQUERY_END]) return match_found(ROLLQUERY_END);
					if (valid_symbols[GROUPROLL_END]) return match_found(GROUPROLL_END);
					if (valid_symbols[FLAG_END]) return match_found(FLAG_END);
				}
				
				else if (checkEntity(result, {ROLLTEMPLATE_PROPERTY_END}, '}', "#125|#[xX](00)?7[dD]|rcub|rbrace")) {
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity();
						c = lexer->lookahead;
						
						if (checkEntity(result, {ROLLTEMPLATE_PROPERTY_END}, '}', "#125|#[xX](00)?7[dD]|rcub|rbrace")) {
							mark_end(lexer);
							//nest.pop();
							inRollTemplateProperty = false;
							return match_found(ROLLTEMPLATE_PROPERTY_END);
						}
					}
					else if (c == '}' && nest.isSafe(c)) {
						c = advance(lexer);
						mark_end(lexer);
						//nest.pop();
						inRollTemplateProperty = false;
						return match_found(ROLLTEMPLATE_PROPERTY_END);
					}
				}
				
				else if (checkEntity(result, {RIGHT_BRACE}, '}', "#125|#[xX](00)?7[dD]|rcub|rbrace"))
					return match_found(RIGHT_BRACE);
				
				else if (checkEntity(result, {INLINEROLL_END, LABEL_END, TABLEROLL_END}, ']', "#93|#[xX](00)?5[dD]|rsqb|rbrack")) {
					if (valid_symbols[LABEL_END]) {
						//nest.pop();
						return match_found(LABEL_END);
					}
					else if (valid_symbols[TABLEROLL_END]) {
						nest.pop();
						return match_found(TABLEROLL_END);
					}
					else if (valid_symbols[INLINEROLL_END]) {
						if (c == '&') {
							c = advance(lexer);
							
							result = getHtmlEntity();
							c = lexer->lookahead;
							
							if (checkEntity(result, {INLINEROLL_END}, ']', "#93|#[xX](00)?5[dD]|rsqb|rbrack")) {
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
				
				else if (checkEntity(result, {BUTTON_END}, ')', "#41|#[xX](00)?29|rpar")) {
					nest.pop();
					return match_found(BUTTON_END);
				}
				
				else if (checkEntity(result, {RIGHT_PAREN}, ')', "#41|#[xX](00)?29|rpar"))
					return match_found(RIGHT_PAREN);
				
				else if (checkEntity(result, {PIPE}, '|', "#124|#[xX](00)?7[cC]|vert|verbar|VerticalLine"))
					return match_found(PIPE);
				
				else if (checkEntity(result, {COMMA}, ',', "#44|#[xX](00)?2[cC]|comma"))
					return match_found(COMMA);
				
				else if (checkEntity(result, {COLON}, ':', "#58|#[xX](00)?3[aA]|colon"))
					return match_found(COLON);
				
				
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
					
					result = getHtmlEntity();
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
					
					result = getHtmlEntity();
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
					//nest.push("]");
					return match_found(LABEL_START);
				}
			}
			else if (c == '(' && valid_symbols[BUTTON_START]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (c == '&') {
					c = advance(lexer);
					
					result = getHtmlEntity();
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
			else if (c == '(' && valid_symbols[LEFT_PAREN]) {
				c = advance(lexer);
				mark_end(lexer);
				return match_found(LEFT_PAREN);
			}
			else if (c == '{') {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ROLLTEMPLATE_PROPERTY_START]) {
					if (c == '&') {
						c = advance(lexer);
						
						result = getHtmlEntity();
						c = lexer->lookahead;
						
						if (regex_match(result.entityName, regex("#123|#[xX](00)?7[bB]|lcub|lbrace"))) {
							//nest.push("}");
							inRollTemplateProperty = true;
							return match_found(ROLLTEMPLATE_PROPERTY_START);
						}
					}
					else if (c == '{') {
						c = advance(lexer);
						mark_end(lexer);
						//nest.push("}");
						inRollTemplateProperty = true;
						return match_found(ROLLTEMPLATE_PROPERTY_START);
					}
				}
				else if (valid_symbols[GROUPROLL_START]) {
					nest.push(",}");
					return match_found(GROUPROLL_START);
				}
				else if (valid_symbols[LEFT_BRACE]) {
					return match_found(LEFT_BRACE);
				}
			}
			else if ((c == 't' || c == 'T') && valid_symbols[TABLEROLL_START]) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (c == '&') {
					c = advance(lexer);
					
					result = getHtmlEntity();
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
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[ROLLQUERY_END] || valid_symbols[GROUPROLL_END]
				 || valid_symbols[FLAG_END] || valid_symbols[ROLLTEMPLATE_PROPERTY_END]) {
					if (valid_symbols[ROLLTEMPLATE_PROPERTY_END]) {
						if (c == '&') {
							c = advance(lexer);
							
							result = getHtmlEntity();
							c = lexer->lookahead;
							
							if (regex_match(result.entityName, regex("#125|#[xX](00)?7[dD]|rcub|rbrace"))) {
								//nest.pop();
								inRollTemplateProperty = false;
								return match_found(ROLLTEMPLATE_PROPERTY_END);
							}
						}
						else if (c == '}') {
							c = advance(lexer);
							mark_end(lexer);
							//nest.pop();
							inRollTemplateProperty = false;
							return match_found(ROLLTEMPLATE_PROPERTY_END);
						}
					}
					else if (inRollTemplateProperty) {
						if (c != '}') {
							nest.pop();
							if (valid_symbols[ROLLQUERY_END])
								return match_found(ROLLQUERY_END);
							if (valid_symbols[GROUPROLL_END])
								return match_found(GROUPROLL_END);
							if (valid_symbols[FLAG_END])
								return match_found(FLAG_END);
						}
					}
					else {
						nest.pop();
						if (valid_symbols[ROLLQUERY_END])
							return match_found(ROLLQUERY_END);
						if (valid_symbols[GROUPROLL_END])
							return match_found(GROUPROLL_END);
						if (valid_symbols[FLAG_END])
							return match_found(FLAG_END);
					}
				}
				else if (valid_symbols[RIGHT_BRACE]) {
					return match_found(RIGHT_BRACE);
				}
			}
			else if (c == ']' && (valid_symbols[INLINEROLL_END] || valid_symbols[LABEL_END]
			 || valid_symbols[TABLEROLL_END])) {
				c = advance(lexer);
				mark_end(lexer);
				
				if (valid_symbols[LABEL_END]) {
					//nest.pop();
					return match_found(LABEL_END);
				}
				else if (valid_symbols[TABLEROLL_END]) {
					nest.pop();
					return match_found(TABLEROLL_END);
				}
				else if (c == '&') {
					c = advance(lexer);
					
					result = getHtmlEntity();
					c = lexer->lookahead;
					
					if (checkEntity(result, {INLINEROLL_END}, ']', "#93|#[xX](00)?5[dD]|rsqb|rbrack")) {
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
			else if (c == ')' && valid_symbols[RIGHT_PAREN]) {
				c = advance(lexer);
				mark_end(lexer);
				return match_found(RIGHT_PAREN);
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
			else if (c == ':' && valid_symbols[COLON]) {
				c = advance(lexer);
				mark_end(lexer);
				return match_found(COLON);
			}
		}
		
		return no_match();
	}
	
};



}	//namespace


/*╔════════════════════════════════════════════════════════════
  ║ Tree-sitter external scanner functions
  ╚════════════════════════════════════════════════════════════*/

extern "C" {

void *tree_sitter_roll20_script_external_scanner_create() {
	Debug.log(color(noChange, brightMagenta)+"                                        ");
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

}	//extern "C"
