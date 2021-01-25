#include <tree_sitter/parser.h>
#include <string.h>

enum TokenType {
	//END,
	WILL_CLOSE_BRACE,
};

void * tree_sitter_roll20_script_external_scanner_create() { return NULL; }
void tree_sitter_roll20_script_external_scanner_destroy(void *payload) {}
unsigned tree_sitter_roll20_script_external_scanner_serialize(void *payload, char *buffer) { return 0; }
void tree_sitter_roll20_script_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {}

static void advance(TSLexer *lexer) {
	lexer->advance(lexer, false);
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
	char c;
	if (valid_symbols[WILL_CLOSE_BRACE]) {
		c = lexer->lookahead;
		while (c != 0 && c != '\n' && c != '}') {
			advance(lexer),
			c = lexer->lookahead;
		}
		if (c == '}') {
			lexer->result_symbol = WILL_CLOSE_BRACE;
			return true;
		}
	}
	
	
	return false;
}
