#include <tree_sitter/parser.h>
#include <string.h>

enum TokenType {
	EOF,
	
	ATTRIBUTE_START,
	JUST_AT,
	
	ABILITY_START,
	JUST_PERCENT,
	
	QUERY_START,
	JUST_QUESTIONMARK,
	
	DICE_ROLL_START,
	JUST_D,
	
	TABLE_ROLL_START,
	JUST_T,
};

void * tree_sitter_roll20_script_external_scanner_create() { return NULL; }
void tree_sitter_roll20_script_external_scanner_destroy(void *payload) {}
unsigned tree_sitter_roll20_script_external_scanner_serialize(void *payload, char *buffer) { return 0; }
void tree_sitter_roll20_script_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {}

char advance(TSLexer *lexer) {
	lexer->advance(lexer, false);
	return lexer->lookahead;
}

bool check_for_closure(
	TSLexer *lexer,
	char start_char,
	char end_char
) {
	char c = lexer->lookahead;
	if (c == start_char) {
		c = advance(lexer);
		while (c != 0 && c != '\n' && c != end_char) {
			c = advance(lexer);
		}
		if (c == end_char) return true;
	}
	return false;
}

bool check_for_roll_query_start(TSLexer *lexer) {
	char c = lexer->lookahead;
	if (c == '{') {
		c = advance(lexer);
		while (c != 0 && c != '\n' && c != '}') {
			if (c == '@' || c == '%') {
				c = advance(lexer);
				if (c = '{') {
					while (c != 0 && c != '\n' && c != '}') {
						c = advance(lexer);
					}
					if (c != '}') {	//end of input; no closing tag
						return false;
					}
					continue;
				}
			}
			c = advance(lexer);
		}
		if (c == '}') return true;
	}
	return false;
}

bool check_for_dice_roll_start(TSLexer *lexer) {
	char digit[] = "0123456789";
	char c = lexer->lookahead;
	if (strchr("fF", c) != NULL) {
		return true;
	}
	else if (strchr(digit, c) != NULL) {
		c = advance(lexer);
		while (c != 0 && strchr(digit, c) != NULL) {
			c = advance(lexer);
		}
		return true;
	}
	else if (c == '@') {
		advance(lexer);
		if (check_for_closure(lexer, '{', '}')) return true;
	}
	else if (c == '%') {
		advance(lexer);
		if (check_for_closure(lexer, '{', '}')) return true;
	}
	return false;
}

bool check_for_table_roll_start(TSLexer *lexer) {
	char c = lexer->lookahead;
	bool rightBracketFound = false;
	if (c == '[') {
		c = advance(lexer);
		while (c != 0 && c != '\n' && c != ']') {
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

bool tree_sitter_roll20_script_external_scanner_scan(
	void *payload,
	TSLexer *lexer,
	const bool *vs	//valid_symbols
) {
	lexer->mark_end(lexer);
	char c = lexer->lookahead;
	
	if (c == 0) {
		lexer->result_symbol = EOF;
		return vs[EOF];
	}
	else if (c == '@') {
		if (vs[ATTRIBUTE_START] || vs[JUST_AT]) {
			advance(lexer);
			lexer->mark_end(lexer);
			
			if (check_for_closure(lexer, '{', '}')) {
				if (vs[ATTRIBUTE_START]) {
					lexer->result_symbol = ATTRIBUTE_START;
					return true;
				}
			}
			else if (vs[JUST_AT]) {
				lexer->result_symbol = JUST_AT;
				return true;
			}
		}
	}
	else if (c == '%') {
		if (vs[ABILITY_START] || vs[JUST_PERCENT]) {
			advance(lexer);
			lexer->mark_end(lexer);
			
			if (check_for_closure(lexer, '{', '}')) {
				if (vs[ABILITY_START]) {
					lexer->result_symbol = ABILITY_START;
					return true;
				}
			}
			else if (vs[JUST_PERCENT]) {
				lexer->result_symbol = JUST_PERCENT;
				return true;
			}
		}
	}
	else if (c == '?') {
		if (vs[QUERY_START] || vs[JUST_QUESTIONMARK]) {
			advance(lexer);
			lexer->mark_end(lexer);
			
			if (check_for_closure(lexer, '{', '}')) {
				if (vs[QUERY_START]) {
					lexer->result_symbol = QUERY_START;
					return true;
				}
			}
			else if (vs[JUST_QUESTIONMARK]) {
				lexer->result_symbol = JUST_QUESTIONMARK;
				return true;
			}
		}
	}
	else if (c == 'd' || c == 'D') {
		if (vs[DICE_ROLL_START] || vs[JUST_D]) {
			c = advance(lexer);
			lexer->mark_end(lexer);
			
			if (check_for_dice_roll_start(lexer)) {
				if (vs[DICE_ROLL_START]) {
					lexer->result_symbol = DICE_ROLL_START;
					return true;
				}
			}
			else if (vs[JUST_D]) {
				lexer->result_symbol = JUST_D;
				return true;
			}
		}
	}
	else if (c == 't' || c == 'T') {
		if (vs[TABLE_ROLL_START] || vs[JUST_T]) {
			c = advance(lexer);
			lexer->mark_end(lexer);
			
			if (check_for_table_roll_start(lexer)) {
				if (vs[TABLE_ROLL_START]) {
					lexer->result_symbol = TABLE_ROLL_START;
					return true;
				}
			}
			else if (vs[JUST_T]) {
				lexer->result_symbol = JUST_T;
				return true;
			}
		}
	}
	else if (c == '?') {
		if (vs[QUERY_START] || vs[JUST_QUESTIONMARK]) {
			c = advance(lexer);
			lexer->mark_end(lexer);
			
			if (check_for_roll_query_start(lexer)) {
				if (vs[QUERY_START]) {
					lexer->result_symbol = QUERY_START;
					return true;
				}
			}
			else if (vs[JUST_QUESTIONMARK]) {
				lexer->result_symbol = JUST_QUESTIONMARK;
				return true;
			}
		}
	}
	
	return false;
}
