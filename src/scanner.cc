#include <tree_sitter/parser.h>
#include <string>	//string, to_string
#include <stack>	//stack
#include <map>		//map
#include <utility>	//pair
#include <regex>	//regext, regex_match
//#include <iostream>

namespace {

using std::string;
using std::to_string;
using std::stack;
using std::map;
using std::pair;
using std::regex;
using std::regex_match;

enum TokenType {
	_EOF,
	
	ATTRIBUTE_START,
	JUST_AT,
	
	ABILITY_START,
	JUST_PERCENT,
	
	DICE_ROLL_START,
	JUST_D,
	
	TABLE_ROLL_START,
	JUST_T,
	
	QUERY_START,
	JUST_QUESTIONMARK,
	QUERY_PIPE,
	QUERY_COMMA,
	QUERY_END,
	QUERY_HASDEFAULT,
	QUERY_HASOPTIONS,
};

struct Query;
struct Scanner;

char advance(TSLexer *lexer) {
	lexer->advance(lexer, false);
	return lexer->lookahead;
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
	entitiesMap.insert(pair<string, string>("|", "#123|#[xX](00)?7[cC]|vert|verbar|VerticalLine"));
	entitiesMap.insert(pair<string, string>("?", "#63|#[xX](00)?3[fF]|quest"));
	entitiesMap.insert(pair<string, string>(",", "#44|#[xX](00)?2[cC]|comma"));
	entitiesMap.insert(pair<string, string>("=", "#61|#[xX](00)?3[dD]|equals"));
	entitiesMap.insert(pair<string, string>("~", "#126|#[xX](00)?7[eE]"));
}

bool matchDelimiter(string entity, string delimiter, unsigned depth, bool shallowerIsOkay = false) {
	if (depth == 0) return entity.compare(delimiter) == 0;
	if (shallowerIsOkay && entity.compare(delimiter) == 0) return true;
	string rxpStr = "&(amp;){";
	rxpStr.append(shallowerIsOkay?"0,":"");
	rxpStr.append(to_string(depth-1));
	rxpStr.append("}(");
	rxpStr.append(entitiesMap[delimiter]);
	rxpStr.append(")");
	return regex_match(entity, regex(rxpStr));
}

string get_entity(TSLexer *lexer, unsigned depth) {
	regex charsRxp = regex("[#a-zA-Z0-9]");
	string code = "";
	string entity = "&";
	unsigned amps = 0;
	
	char c = lexer->lookahead;
	
	if (c != '&') return "";
	c = advance(lexer);
	
	for (;;) {
		if (c == 0 || !regex_match(string({c}), charsRxp)) return "";
		if (c == ';') {
			if (amps == depth-1) {
				if (code.length() < 2) return "";
				entity += code + ";";
				advance(lexer);
				return entity;
			}
			else if (code.compare("amp") == 0) {
				amps++;
				entity += "amp;";
				code = "";
			}
			else return "";
		}
		code += c;
		c = advance(lexer);
	}
}

struct Query {
	Scanner *scanner;
	unsigned depth = 0;
	unsigned option_count = 0;
	enum QueryPart : unsigned { qpStart, qpPrompt, qpDefault, qpName, qpValue };
	unsigned at_part = qpStart;
	
	Query(Scanner *scanner, unsigned depth) : scanner(scanner), depth(depth) {}
	
	string serialize() {
		return to_string(depth) + " " + to_string(option_count) + " " + to_string(at_part);
	}
	
	void deserialize(const char *buffer) {
		string data = string(buffer);
		size_t p;
		depth = stoul(data, &p);
		option_count = stoul(data.substr(p+1), &p);
		at_part = stoul(data.substr(p+1), &p);
	}
	
	bool scan_query_start(TSLexer *lexer) {
		char c = lexer->lookahead;
		
		if (c == '&') {
			string entity = get_entity(lexer, depth);
			if (entity == "") return false;
			if (!matchDelimiter(entity, "?", depth, true)) return false;
		}
		else if (c != '?') return false;
		
		c = advance(lexer);
		if (c == '&') {
			string entity = get_entity(lexer, depth);
			if (entity == "") return false;
			if (!matchDelimiter(entity, "{", depth, true)) return false;
		}
		else if (c != '{') return false;
		
		lexer->mark_end;
		at_part = qpPrompt;
		if (scan_query_prompt(lexer)) {
			return true;
		}
		
		return false;
	}
	
	bool scan_query_prompt(TSLexer *lexer) {
		//TODO
		return false;
	}
	
	bool scan_query_pipe(TSLexer *lexer) {
		//TODO
		return false;
	}
	
	bool scan_query_end(TSLexer *lexer) {
		//TODO
		return false;
	}
	
};

struct Scanner {
	stack<Query> *queries;
	
	Scanner() {
		populateEntitiesMap();
	}
	
	unsigned serialize(char *buffer) {
		string data;
		while(queries->size() > 0) {
			data += queries->top().serialize() + " ";
			queries->pop();
		}
		strcpy(buffer, data.c_str());	//convert from string to char*
		if (strlen(buffer) >= TREE_SITTER_SERIALIZATION_BUFFER_SIZE) return 0;
		return strlen(buffer);
	}

	void deserialize(const char *buffer, unsigned length) {
		if (length == 0) {
			//
		} else {
			string data = string(buffer);
			size_t p;
			do {
				p = data.find(" ");
				p = data.find(" ", p+1);
				p = data.find(" ", p+1);
				if (p == string::npos) break;
				Query *query = new Query(this, queries->size());
				char *temp = "";
				strcpy(temp, data.substr(0, p).c_str());	//convert from string to char*
				query->deserialize(temp);
				queries->push(*query);
				data = data.substr(p+1);
			} while (data.length() > 0);
		}
	}
	
	void nestedQuery() {
		//TODO: push a new Query to the stack and scan for the end of it (just to skip it), then pop it.
	}
	
	bool scan(TSLexer *lexer, const bool *valid_symbols){
		lexer->mark_end(lexer);
		char c = lexer->lookahead;
		
		if (c == 0) {
			lexer->result_symbol = EOF;
			return valid_symbols[EOF];
		}
/*		else if (c == '@') {
			if (valid_symbols[ATTRIBUTE_START] || valid_symbols[JUST_AT]) {
				advance(lexer);
				lexer->mark_end(lexer);
				
				if (check_for_closure(lexer, '{', '}')) {
					if (valid_symbols[ATTRIBUTE_START]) {
						lexer->result_symbol = ATTRIBUTE_START;
						return true;
					}
				}
				else if (valid_symbols[JUST_AT]) {
					lexer->result_symbol = JUST_AT;
					return true;
				}
			}
		}
		else if (c == '%') {
			if (valid_symbols[ABILITY_START] || valid_symbols[JUST_PERCENT]) {
				advance(lexer);
				lexer->mark_end(lexer);
				
				if (check_for_closure(lexer, '{', '}')) {
					if (valid_symbols[ABILITY_START]) {
						lexer->result_symbol = ABILITY_START;
						return true;
					}
				}
				else if (valid_symbols[JUST_PERCENT]) {
					lexer->result_symbol = JUST_PERCENT;
					return true;
				}
			}
		}
		else if (c == 'd' || c == 'D') {
			if (valid_symbols[DICE_ROLL_START] || valid_symbols[JUST_D]) {
				c = advance(lexer);
				lexer->mark_end(lexer);
				
				if (check_for_dice_roll_start(lexer)) {
					if (valid_symbols[DICE_ROLL_START]) {
						lexer->result_symbol = DICE_ROLL_START;
						return true;
					}
				}
				else if (valid_symbols[JUST_D]) {
					lexer->result_symbol = JUST_D;
					return true;
				}
			}
		}
		else if (c == 't' || c == 'T') {
			if (valid_symbols[TABLE_ROLL_START] || valid_symbols[JUST_T]) {
				c = advance(lexer);
				lexer->mark_end(lexer);
				
				if (check_for_table_roll_start(lexer)) {
					if (valid_symbols[TABLE_ROLL_START]) {
						lexer->result_symbol = TABLE_ROLL_START;
						return true;
					}
				}
				else if (valid_symbols[JUST_T]) {
					lexer->result_symbol = JUST_T;
					return true;
				}
			}
		}*/
		else if (c == '?') {
			if (valid_symbols[QUERY_START] || valid_symbols[JUST_QUESTIONMARK]) {
				c = advance(lexer);
				lexer->mark_end(lexer);
				
				if (queries->top().scan_query_start(lexer)) {
					lexer->result_symbol = QUERY_START;
					return true;
				}
				else if (valid_symbols[JUST_QUESTIONMARK]) {
					lexer->result_symbol = JUST_QUESTIONMARK;
					return true;
				}
			}
		}
/*		else if (c == '|') {
			if (valid_symbols[QUERY_HASDEFAULT] || valid_symbols[QUERY_HASOPTIONS]) {
				c = advance(lexer);
				lexer->mark_end(lexer);
				type = check_for_roll_query_options(lexer, 0);
				if (type == 1 && valid_symbols[QUERY_HASDEFAULT]) {
					lexer->result_symbol = QUERY_HASDEFAULT;
					return true;
				}
				else if (type == 2 && valid_symbols[QUERY_HASOPTIONS]) {
					lexer->result_symbol = QUERY_HASOPTIONS;
					return true;
				}
			}
		}*/
		else if (c == '&') {
			if (valid_symbols[QUERY_START]) {
				if (queries->top().scan_query_start(lexer)) {
					lexer->result_symbol = QUERY_START;
					return true;
				}
			}
/*			else if (valid_symbols[QUERY_HASDEFAULT] || valid_symbols[QUERY_HASOPTIONS]) {
				get_character_depth_and_type(lexer, &depth, &type);
				if (type == 3) {	//pipe
					lexer->mark_end(lexer);
					type = check_for_roll_query_options(lexer, depth);
					if (type == 1 && valid_symbols[QUERY_HASDEFAULT]) {
						lexer->result_symbol = QUERY_HASDEFAULT;
						return true;
					}
					else if (type == 2 && valid_symbols[QUERY_HASOPTIONS]) {
						lexer->result_symbol = QUERY_HASOPTIONS;
						return true;
					}
				}
			}*/
		}
		
		return false;
	}

/*	bool scan_heredoc_start(TSLexer *lexer) {
		while (iswspace(lexer->lookahead)) skip(lexer);

		lexer->result_symbol = HEREDOC_START;
		heredoc_is_raw = lexer->lookahead == '\'';
		started_heredoc = false;
		heredoc_delimiter.clear();

		if (lexer->lookahead == '\\') {
			advance(lexer);
		}

		int32_t quote = 0;
		if (heredoc_is_raw || lexer->lookahead == '"') {
			quote = lexer->lookahead;
			advance(lexer);
		}

		while (iswalpha(lexer->lookahead) || (quote != 0 && iswspace(lexer->lookahead))) {
			heredoc_delimiter += lexer->lookahead;
			advance(lexer);
		}

		if (lexer->lookahead == quote) {
			advance(lexer);
		}

		return !heredoc_delimiter.empty();
	}

	bool scan_heredoc_end_identifier(TSLexer *lexer) {
		current_leading_word.clear();
		// Scan the first 'n' characters on this line, to see if they match the heredoc delimiter
		while (
			lexer->lookahead != '\0' &&
			lexer->lookahead != '\n' &&
			current_leading_word.length() < heredoc_delimiter.length()
		) {
			current_leading_word += lexer->lookahead;
			advance(lexer);
		}
		return current_leading_word == heredoc_delimiter;
	}

	bool scan_heredoc_content(TSLexer *lexer, TokenType middle_type, TokenType end_type) {
		bool did_advance = false;

		for (;;) {
			switch (lexer->lookahead) {
				case '\0': {
					if (did_advance) {
						heredoc_is_raw = false;
						started_heredoc = false;
						heredoc_allows_indent = false;
						heredoc_delimiter.clear();
						lexer->result_symbol = end_type;
						return true;
					} else {
						return false;
					}
				}

				case '\\': {
					did_advance = true;
					advance(lexer);
					advance(lexer);
					break;
				}

				case '$': {
					if (heredoc_is_raw) {
						did_advance = true;
						advance(lexer);
						break;
					} else if (did_advance) {
						lexer->result_symbol = middle_type;
						started_heredoc = true;
						return true;
					} else {
						return false;
					}
				}

				case '\n': {
					did_advance = true;
					advance(lexer);
					if (heredoc_allows_indent) {
						while (iswspace(lexer->lookahead)) {
							advance(lexer);
						}
					}
					if (scan_heredoc_end_identifier(lexer)) {
						heredoc_is_raw = false;
						started_heredoc = false;
						heredoc_allows_indent = false;
						heredoc_delimiter.clear();
						lexer->result_symbol = end_type;
						return true;
					}
					break;
				}

				default: {
					did_advance = true;
					advance(lexer);
					break;
				}
			}
		}
	}

	bool scan(TSLexer *lexer, const bool *valid_symbols) {
		if (valid_symbols[CONCAT]) {
			if (!(
				lexer->lookahead == 0 ||
				iswspace(lexer->lookahead) ||
				lexer->lookahead == '>' ||
				lexer->lookahead == '<' ||
				lexer->lookahead == ')' ||
				lexer->lookahead == '(' ||
				lexer->lookahead == ';' ||
				lexer->lookahead == '&' ||
				lexer->lookahead == '|' ||
				lexer->lookahead == '`' ||
				lexer->lookahead == '#' ||
				(lexer->lookahead == '}' && valid_symbols[CLOSING_BRACE]) ||
				(lexer->lookahead == ']' && valid_symbols[CLOSING_BRACKET])
			)) {
				lexer->result_symbol = CONCAT;
				return true;
			}
		}

		if (valid_symbols[EMPTY_VALUE]) {
			if (iswspace(lexer->lookahead)) {
				lexer->result_symbol = EMPTY_VALUE;
				return true;
			}
		}

		if (valid_symbols[HEREDOC_BODY_BEGINNING] && !heredoc_delimiter.empty() && !started_heredoc) {
			return scan_heredoc_content(lexer, HEREDOC_BODY_BEGINNING, SIMPLE_HEREDOC_BODY);
		}

		if (valid_symbols[HEREDOC_BODY_MIDDLE] && !heredoc_delimiter.empty() && started_heredoc) {
			return scan_heredoc_content(lexer, HEREDOC_BODY_MIDDLE, HEREDOC_BODY_END);
		}

		if (valid_symbols[HEREDOC_START]) {
			return scan_heredoc_start(lexer);
		}

		if (valid_symbols[VARIABLE_NAME] || valid_symbols[FILE_DESCRIPTOR] || valid_symbols[HEREDOC_ARROW]) {
			for (;;) {
				if (
					lexer->lookahead == ' ' ||
					lexer->lookahead == '\t' ||
					lexer->lookahead == '\r' ||
					(lexer->lookahead == '\n' && !valid_symbols[NEWLINE])
				) {
					skip(lexer);
				} else if (lexer->lookahead == '\\') {
					skip(lexer);
					if (lexer->lookahead == '\n') {
						skip(lexer);
					} else {
						return false;
					}
				} else {
					break;
				}
			}

			if (valid_symbols[HEREDOC_ARROW] && lexer->lookahead == '<') {
				advance(lexer);
				if (lexer->lookahead == '<') {
					advance(lexer);
					if (lexer->lookahead == '-') {
						advance(lexer);
						heredoc_allows_indent = true;
						lexer->result_symbol = HEREDOC_ARROW_DASH;
					} else if (lexer->lookahead == '<') {
						return false;
					} else {
						heredoc_allows_indent = false;
						lexer->result_symbol = HEREDOC_ARROW;
					}
					return true;
				}
				return false;
			}

			bool is_number = true;
			if (iswdigit(lexer->lookahead)) {
				advance(lexer);
			} else if (iswalpha(lexer->lookahead) || lexer->lookahead == '_') {
				is_number = false;
				advance(lexer);
			} else {
				return false;
			}

			for (;;) {
				if (iswdigit(lexer->lookahead)) {
					advance(lexer);
				} else if (iswalpha(lexer->lookahead) || lexer->lookahead == '_') {
					is_number = false;
					advance(lexer);
				} else {
					break;
				}
			}

			if (is_number &&
					valid_symbols[FILE_DESCRIPTOR] &&
					(lexer->lookahead == '>' || lexer->lookahead == '<')) {
				lexer->result_symbol = FILE_DESCRIPTOR;
				return true;
			}

			if (valid_symbols[VARIABLE_NAME]) {
				if (lexer->lookahead == '+') {
					lexer->mark_end(lexer);
					advance(lexer);
					if (lexer->lookahead == '=') {
						lexer->result_symbol = VARIABLE_NAME;
						return true;
					} else {
						return false;
					}
				} else if (lexer->lookahead == '=' || lexer->lookahead == '[') {
					lexer->result_symbol = VARIABLE_NAME;
					return true;
				}
			}

			return false;
		}

		if (valid_symbols[REGEX]) {
			while (iswspace(lexer->lookahead)) skip(lexer);

			if (
				lexer->lookahead != '"' &&
				lexer->lookahead != '\'' &&
				lexer->lookahead != '$'
			) {
				struct State {
					bool done;
					uint32_t paren_depth;
					uint32_t bracket_depth;
					uint32_t brace_depth;
				};

				lexer->mark_end(lexer);

				State state = {false, 0, 0, 0};
				while (!state.done) {
					switch (lexer->lookahead) {
						case '\0':
							return false;
						case '(':
							state.paren_depth++;
							break;
						case '[':
							state.bracket_depth++;
							break;
						case '{':
							state.brace_depth++;
							break;
						case ')':
							if (state.paren_depth == 0) state.done = true;
							state.paren_depth--;
							break;
						case ']':
							if (state.bracket_depth == 0) state.done = true;
							state.bracket_depth--;
							break;
						case '}':
							if (state.brace_depth == 0) state.done = true;
							state.brace_depth--;
							break;
					}

					if (!state.done) {
						bool was_space = iswspace(lexer->lookahead);
						advance(lexer);
						if (!was_space) lexer->mark_end(lexer);
					}
				}

				lexer->result_symbol = REGEX;
				return true;
			}
		}

		return false;
	}

	string heredoc_delimiter;
	bool heredoc_is_raw;
	bool started_heredoc;
	bool heredoc_allows_indent;
	string current_leading_word;*/
};

}

extern "C" {

void *tree_sitter_roll20_script_external_scanner_create() {
	return new Scanner();
}

bool tree_sitter_roll20_script_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
	Scanner *scanner = static_cast<Scanner *>(payload);
	return scanner->scan(lexer, valid_symbols);
}

unsigned tree_sitter_roll20_script_external_scanner_serialize(void *payload, char *state) {
	Scanner *scanner = static_cast<Scanner *>(payload);
	return scanner->serialize(state);
}

void tree_sitter_roll20_script_external_scanner_deserialize(void *payload, const char *state, unsigned length) {
	Scanner *scanner = static_cast<Scanner *>(payload);
	scanner->deserialize(state, length);
}

void tree_sitter_roll20_script_external_scanner_destroy(void *payload) {
	Scanner *scanner = static_cast<Scanner *>(payload);
	delete scanner;
}

}
