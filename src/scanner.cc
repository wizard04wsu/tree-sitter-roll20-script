#include <tree_sitter/parser.h>
#include <string>	//string, to_string

namespace {

using namespace std;


enum TokenType {
	_EOF,
};


char advance(TSLexer *lexer) {
	lexer->advance(lexer, false);
	return lexer->lookahead;
}
void mark_end(TSLexer *lexer) {
	lexer->mark_end(lexer);
}


struct Scanner {
	Scanner() {}
	
	bool match_found(TSLexer *lexer, int symbol) {
		lexer->result_symbol = symbol;
		return true;
	}
	
	bool scan(TSLexer *lexer, const bool *valid_symbols){
		
		char c = lexer->lookahead;
		mark_end(lexer);
		
		if (c == 0) {
			if (valid_symbols[_EOF]) {
				return match_found(lexer, _EOF);
			}
		}
		
		return false;
	}
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
	return 0;
}

void tree_sitter_roll20_script_external_scanner_deserialize(void *payload, const char *state, unsigned length) {}

void tree_sitter_roll20_script_external_scanner_destroy(void *payload) {
	Scanner *scanner = static_cast<Scanner *>(payload);
	delete scanner;
}

}
