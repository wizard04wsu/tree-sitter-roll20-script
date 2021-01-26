#include <tree_sitter/parser.h>
#include <string.h>

enum TokenType {
	EOF,
	ATTRIBUTE_START,
	ABILITY_START,
	INLINE_ROLL_START,
};

void * tree_sitter_roll20_script_external_scanner_create() { return NULL; }
void tree_sitter_roll20_script_external_scanner_destroy(void *payload) {}
unsigned tree_sitter_roll20_script_external_scanner_serialize(void *payload, char *buffer) { return 0; }
void tree_sitter_roll20_script_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {}

char advance(TSLexer *lexer) {
	lexer->advance(lexer, false);
	return lexer->lookahead;
}
bool check_for_braces(
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
}
bool check_for_brackets(
	TSLexer *lexer,
	const bool *valid_symbols,
) {
	char c = lexer->lookahead;
	if (c == '[' && valid_symbols[INLINE_ROLL_START]) {
		c = advance(lexer);
		if (c == '[') {
			c = advance(lexer);
			lexer->mark_end(lexer);	//"[["
			
			while (c != 0 && c != '\n') {
				if (c == ']') {
					c = advance(lexer);
					if (c == ']') {
						lexer->result_symbol = INLINE_ROLL_START;
						return true;
					}
					if (c == 0 || c == '\n') {
						break;
					}
				}
				c = advance(lexer);
			}
		}
	}
	return false;
}

bool tree_sitter_roll20_script_external_scanner_scan(
	void *payload,
	TSLexer *lexer,
	const bool *valid_symbols
) {
	lexer->mark_end(lexer);
	
	if (lexer->lookahead == 0 && valid_symbols[EOF]) {
		lexer->result_symbol = EOF;
		return true;
	}
	
	if (check_for_braces(lexer, valid_symbols, ATTRIBUTE_START, '@') ||
		check_for_braces(lexer, valid_symbols, ABILITY_START, '%') ||
		check_for_brackets(lexer, valid_symbols)
	) {
		return true;
	}
	
	return false;
}
