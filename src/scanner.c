#include <tree_sitter/parser.h>
#include <string.h>

enum TokenType {
	EOF,
	ATTRIBUTE_START,
	JUST_AT,
	ABILITY_START,
	JUST_PERCENT,
	DICE_ROLL_START,
	JUST_D,
	//UNSIGNED_INTEGER,
	NOT_ROLL_COUNT,
	TABLE_ROLL_COUNT,
};

void * tree_sitter_roll20_script_external_scanner_create() { return NULL; }
void tree_sitter_roll20_script_external_scanner_destroy(void *payload) {}
unsigned tree_sitter_roll20_script_external_scanner_serialize(void *payload, char *buffer) { return 0; }
void tree_sitter_roll20_script_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {}

char advance(TSLexer *lexer) {
	lexer->advance(lexer, false);
	return lexer->lookahead;
}
/*bool check_for_braces(
	TSLexer *lexer,
	const bool *valid_symbols,
	int symbol,
	char start_char
) {
	char c = lexer->lookahead;
	if (c == start_char && valid_symbols[symbol]) {
		c = advance(lexer);
		if (c == '{') {
			c = advance(lexer);
			lexer->mark_end(lexer);	//"@{"
			
			while (c != 0 && c != '\n' && c != '}') {
				c = advance(lexer);
			}
			if (c == '}') {
				lexer->result_symbol = symbol;
				return true;
			}
		}
	}
	return false;
}*/
bool check_for_closure(
	TSLexer *lexer,
	char start_char,
	char end_char,
	bool mark_at_entrance
) {
	char c = lexer->lookahead;
	if (c == start_char) {
		c = advance(lexer);
		if (mark_at_entrance) lexer->mark_end(lexer);
		while (c != 0 && c != '\n' && c != end_char) {
			c = advance(lexer);
		}
		if (c == end_char) return true;
	}
	return false;
}

bool check_for_dice_roll_start(
	TSLexer *lexer,
	const bool *valid_symbols
) {
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
		if (check_for_closure(lexer, '{', '}', false)) return true;
	}
	else if (c == '%') {
		advance(lexer);
		if (check_for_closure(lexer, '{', '}', false)) return true;
	}
	return false;
}

bool tree_sitter_roll20_script_external_scanner_scan(
	void *payload,
	TSLexer *lexer,
	//const bool *valid_symbols
	const bool *vs
) {
	lexer->mark_end(lexer);
	char c = lexer->lookahead;
	
	if (c == 0) {
		lexer->result_symbol = EOF;
		return vs[EOF];
	}
	
	//char digit[] = "0123456789";
	
	/*if (check_for_braces(lexer, vs, ATTRIBUTE_START, '@') ||
		check_for_braces(lexer, vs, ABILITY_START, '%')
	) {
		return true;
	}*/
	
	if (c == '@') {
		if (vs[ATTRIBUTE_START] || vs[JUST_AT]) {
			advance(lexer);
			if (check_for_closure(lexer, '{', '}', true)) {
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
			if (check_for_closure(lexer, '{', '}', true)) {
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
	else if (c == 'd' || c == 'D') {
		if (vs[DICE_ROLL_START] || vs[JUST_D] || vs[NOT_ROLL_COUNT]) {
			c = advance(lexer);
			if (vs[DICE_ROLL_START] || vs[JUST_D]) {
				lexer->mark_end(lexer);
			}
			
			if (check_for_dice_roll_start(lexer, vs)) {
				if (vs[DICE_ROLL_START]) {
					lexer->result_symbol = DICE_ROLL_START;
					return true;
				}
			}
			else if (vs[JUST_D]) {
				lexer->result_symbol = JUST_D;
				return true;
			}
			else if (vs[NOT_ROLL_COUNT]) {
				lexer->result_symbol = NOT_ROLL_COUNT;
				return true;
			}
		}
	}
	else if (c == 't' || c == 'T') {
		if (vs[TABLE_ROLL_COUNT]) {
			lexer->result_symbol = TABLE_ROLL_COUNT;
			return true;
		}
	}
	else if (vs[NOT_ROLL_COUNT]) {
		lexer->result_symbol = NOT_ROLL_COUNT;
		return true;
	}
	
	/*else if (strchr(digit, lexer->lookahead) != NULL
		&& vs[UNSIGNED_INTEGER]
	) {
		advance(lexer);
		while (lexer->lookahead != 0 && strchr(digit, lexer->lookahead) != NULL) {
			 advance(lexer);
		}
		
		if (strchr("dDtT", lexer->lookahead) == NULL) {
			lexer->mark_end(lexer);
			lexer->result_symbol = UNSIGNED_INTEGER;
			return true;
		}
	}*/
	
	
	return false;
}
