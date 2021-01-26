#include <tree_sitter/parser.h>
#include <string.h>

enum TokenType {
	//END,
	ATTRIBUTE_START,
};

void * tree_sitter_roll20_script_external_scanner_create() { return NULL; }
void tree_sitter_roll20_script_external_scanner_destroy(void *payload) {}
unsigned tree_sitter_roll20_script_external_scanner_serialize(void *payload, char *buffer) { return 0; }
void tree_sitter_roll20_script_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {}

char advance(TSLexer *lexer) {
	lexer->advance(lexer, false);
	return lexer->lookahead;
}

bool tree_sitter_roll20_script_external_scanner_scan(
	void *payload,
	TSLexer *lexer,
	const bool *valid_symbols
) {
	lexer->mark_end(lexer);
	
	/*if (lexer->lookahead == 0 && valid_symbols[END]) {
		lexer->result_symbol = END;
		return true;
	}*/
	char c = lexer->lookahead;
	if (c == '@' && valid_symbols[ATTRIBUTE_START]) {
		c = advance(lexer);
		if (c == '{') {
			c = advance(lexer);
			lexer->mark_end(lexer);	//"@{"
			
			while (c != 0 && c != '\n' && c != '}') {
				c = advance(lexer);
			}
			if (c == '}') {
				lexer->result_symbol = ATTRIBUTE_START;
				return true;
			}
		}
	}
	
	
	return false;
}
