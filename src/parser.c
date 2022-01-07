#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 186
#define LARGE_STATE_COUNT 3
#define SYMBOL_COUNT 66
#define ALIAS_COUNT 1
#define TOKEN_COUNT 31
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 8

enum {
  aux_sym_script_token1 = 1,
  sym__wsp = 2,
  sym_htmlEntity = 3,
  anon_sym_target = 4,
  anon_sym_selected = 5,
  anon_sym_AT_LBRACE = 6,
  anon_sym_RBRACE = 7,
  anon_sym_PIPE = 8,
  anon_sym_PIPEmax_RBRACE = 9,
  aux_sym_attribute_identifier_token1 = 10,
  anon_sym_PERCENT_LBRACE = 11,
  aux_sym_ability_identifier_token1 = 12,
  sym_hash = 13,
  aux_sym__macro_token1 = 14,
  aux_sym__macro_token2 = 15,
  anon_sym_LBRACK_LBRACK = 16,
  anon_sym_RBRACK_RBRACK = 17,
  aux_sym__number_signable_token1 = 18,
  anon_sym_DOT = 19,
  aux_sym__term_first_token1 = 20,
  anon_sym_LPAREN = 21,
  anon_sym_RPAREN = 22,
  aux_sym_function_token1 = 23,
  aux_sym__operator_multiplication_token1 = 24,
  sym__operator_summation_plus = 25,
  sym__operator_summation_minus = 26,
  anon_sym_LBRACK = 27,
  aux_sym_label_token1 = 28,
  aux_sym_label_token2 = 29,
  anon_sym_RBRACK = 30,
  sym_script = 31,
  sym__placeholder = 32,
  sym_character_token_identifier = 33,
  sym__attribute = 34,
  sym_attribute = 35,
  sym__attribute_of_character = 36,
  sym__attribute_of_character_maximum = 37,
  sym_attribute_identifier = 38,
  sym_ability = 39,
  sym_ability_identifier = 40,
  sym__macro = 41,
  sym_inlineRoll = 42,
  sym__IrPh = 43,
  sym_number = 44,
  sym__number_signable = 45,
  sym__number_unsignable = 46,
  sym_formula = 47,
  sym__term_first = 48,
  sym__term_unsigned = 49,
  sym__term_signed = 50,
  sym_parenthesized = 51,
  sym__parenthesized = 52,
  sym_function = 53,
  sym__operator_multiplication = 54,
  sym__operator_summation = 55,
  sym_label = 56,
  sym__labels = 57,
  aux_sym_script_repeat1 = 58,
  aux_sym_attribute_identifier_repeat1 = 59,
  aux_sym_ability_identifier_repeat1 = 60,
  aux_sym__macro_repeat1 = 61,
  aux_sym__number_signable_repeat1 = 62,
  aux_sym_formula_repeat1 = 63,
  aux_sym_label_repeat1 = 64,
  aux_sym__labels_repeat1 = 65,
  alias_sym_character_identifier = 66,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_script_token1] = "script_token1",
  [sym__wsp] = "_wsp",
  [sym_htmlEntity] = "htmlEntity",
  [anon_sym_target] = "target",
  [anon_sym_selected] = "selected",
  [anon_sym_AT_LBRACE] = "@{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_PIPE] = "|",
  [anon_sym_PIPEmax_RBRACE] = "|max}",
  [aux_sym_attribute_identifier_token1] = "attribute_identifier_token1",
  [anon_sym_PERCENT_LBRACE] = "%{",
  [aux_sym_ability_identifier_token1] = "ability_identifier_token1",
  [sym_hash] = "hash",
  [aux_sym__macro_token1] = "_macro_token1",
  [aux_sym__macro_token2] = "_macro_token2",
  [anon_sym_LBRACK_LBRACK] = "[[",
  [anon_sym_RBRACK_RBRACK] = "]]",
  [aux_sym__number_signable_token1] = "_number_signable_token1",
  [anon_sym_DOT] = ".",
  [aux_sym__term_first_token1] = "operator",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [aux_sym_function_token1] = "name",
  [aux_sym__operator_multiplication_token1] = "_operator_multiplication_token1",
  [sym__operator_summation_plus] = "_operator_summation_plus",
  [sym__operator_summation_minus] = "_operator_summation_minus",
  [anon_sym_LBRACK] = "[",
  [aux_sym_label_token1] = "label_token1",
  [aux_sym_label_token2] = "label_token2",
  [anon_sym_RBRACK] = "]",
  [sym_script] = "script",
  [sym__placeholder] = "_placeholder",
  [sym_character_token_identifier] = "character_token_identifier",
  [sym__attribute] = "_attribute",
  [sym_attribute] = "attribute",
  [sym__attribute_of_character] = "attribute",
  [sym__attribute_of_character_maximum] = "attribute_maximum",
  [sym_attribute_identifier] = "attribute_identifier",
  [sym_ability] = "ability",
  [sym_ability_identifier] = "ability_identifier",
  [sym__macro] = "_macro",
  [sym_inlineRoll] = "inlineRoll",
  [sym__IrPh] = "_IrPh",
  [sym_number] = "number",
  [sym__number_signable] = "_number_signable",
  [sym__number_unsignable] = "_number_unsignable",
  [sym_formula] = "formula",
  [sym__term_first] = "term",
  [sym__term_unsigned] = "_term_unsigned",
  [sym__term_signed] = "term",
  [sym_parenthesized] = "parenthesized",
  [sym__parenthesized] = "_parenthesized",
  [sym_function] = "function",
  [sym__operator_multiplication] = "operator",
  [sym__operator_summation] = "operator",
  [sym_label] = "label",
  [sym__labels] = "_labels",
  [aux_sym_script_repeat1] = "script_repeat1",
  [aux_sym_attribute_identifier_repeat1] = "attribute_identifier_repeat1",
  [aux_sym_ability_identifier_repeat1] = "ability_identifier_repeat1",
  [aux_sym__macro_repeat1] = "_macro_repeat1",
  [aux_sym__number_signable_repeat1] = "_number_signable_repeat1",
  [aux_sym_formula_repeat1] = "formula_repeat1",
  [aux_sym_label_repeat1] = "label_repeat1",
  [aux_sym__labels_repeat1] = "_labels_repeat1",
  [alias_sym_character_identifier] = "character_identifier",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_script_token1] = aux_sym_script_token1,
  [sym__wsp] = sym__wsp,
  [sym_htmlEntity] = sym_htmlEntity,
  [anon_sym_target] = anon_sym_target,
  [anon_sym_selected] = anon_sym_selected,
  [anon_sym_AT_LBRACE] = anon_sym_AT_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_PIPEmax_RBRACE] = anon_sym_PIPEmax_RBRACE,
  [aux_sym_attribute_identifier_token1] = aux_sym_attribute_identifier_token1,
  [anon_sym_PERCENT_LBRACE] = anon_sym_PERCENT_LBRACE,
  [aux_sym_ability_identifier_token1] = aux_sym_ability_identifier_token1,
  [sym_hash] = sym_hash,
  [aux_sym__macro_token1] = aux_sym__macro_token1,
  [aux_sym__macro_token2] = aux_sym__macro_token2,
  [anon_sym_LBRACK_LBRACK] = anon_sym_LBRACK_LBRACK,
  [anon_sym_RBRACK_RBRACK] = anon_sym_RBRACK_RBRACK,
  [aux_sym__number_signable_token1] = aux_sym__number_signable_token1,
  [anon_sym_DOT] = anon_sym_DOT,
  [aux_sym__term_first_token1] = aux_sym__term_first_token1,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [aux_sym_function_token1] = aux_sym_function_token1,
  [aux_sym__operator_multiplication_token1] = aux_sym__operator_multiplication_token1,
  [sym__operator_summation_plus] = sym__operator_summation_plus,
  [sym__operator_summation_minus] = sym__operator_summation_minus,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [aux_sym_label_token1] = aux_sym_label_token1,
  [aux_sym_label_token2] = aux_sym_label_token2,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_script] = sym_script,
  [sym__placeholder] = sym__placeholder,
  [sym_character_token_identifier] = sym_character_token_identifier,
  [sym__attribute] = sym__attribute,
  [sym_attribute] = sym_attribute,
  [sym__attribute_of_character] = sym_attribute,
  [sym__attribute_of_character_maximum] = sym__attribute_of_character_maximum,
  [sym_attribute_identifier] = sym_attribute_identifier,
  [sym_ability] = sym_ability,
  [sym_ability_identifier] = sym_ability_identifier,
  [sym__macro] = sym__macro,
  [sym_inlineRoll] = sym_inlineRoll,
  [sym__IrPh] = sym__IrPh,
  [sym_number] = sym_number,
  [sym__number_signable] = sym__number_signable,
  [sym__number_unsignable] = sym__number_unsignable,
  [sym_formula] = sym_formula,
  [sym__term_first] = sym__term_first,
  [sym__term_unsigned] = sym__term_unsigned,
  [sym__term_signed] = sym__term_first,
  [sym_parenthesized] = sym_parenthesized,
  [sym__parenthesized] = sym__parenthesized,
  [sym_function] = sym_function,
  [sym__operator_multiplication] = aux_sym__term_first_token1,
  [sym__operator_summation] = aux_sym__term_first_token1,
  [sym_label] = sym_label,
  [sym__labels] = sym__labels,
  [aux_sym_script_repeat1] = aux_sym_script_repeat1,
  [aux_sym_attribute_identifier_repeat1] = aux_sym_attribute_identifier_repeat1,
  [aux_sym_ability_identifier_repeat1] = aux_sym_ability_identifier_repeat1,
  [aux_sym__macro_repeat1] = aux_sym__macro_repeat1,
  [aux_sym__number_signable_repeat1] = aux_sym__number_signable_repeat1,
  [aux_sym_formula_repeat1] = aux_sym_formula_repeat1,
  [aux_sym_label_repeat1] = aux_sym_label_repeat1,
  [aux_sym__labels_repeat1] = aux_sym__labels_repeat1,
  [alias_sym_character_identifier] = alias_sym_character_identifier,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_script_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__wsp] = {
    .visible = false,
    .named = true,
  },
  [sym_htmlEntity] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_target] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_selected] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPEmax_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_attribute_identifier_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_PERCENT_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_ability_identifier_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_hash] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__macro_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__macro_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACK_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__number_signable_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__term_first_token1] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_function_token1] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__operator_multiplication_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__operator_summation_plus] = {
    .visible = false,
    .named = true,
  },
  [sym__operator_summation_minus] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_label_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_label_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_script] = {
    .visible = true,
    .named = true,
  },
  [sym__placeholder] = {
    .visible = false,
    .named = true,
  },
  [sym_character_token_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__attribute] = {
    .visible = false,
    .named = true,
  },
  [sym_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym__attribute_of_character] = {
    .visible = true,
    .named = true,
  },
  [sym__attribute_of_character_maximum] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_ability] = {
    .visible = true,
    .named = true,
  },
  [sym_ability_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__macro] = {
    .visible = false,
    .named = true,
  },
  [sym_inlineRoll] = {
    .visible = true,
    .named = true,
  },
  [sym__IrPh] = {
    .visible = false,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym__number_signable] = {
    .visible = false,
    .named = true,
  },
  [sym__number_unsignable] = {
    .visible = false,
    .named = true,
  },
  [sym_formula] = {
    .visible = true,
    .named = true,
  },
  [sym__term_first] = {
    .visible = true,
    .named = true,
  },
  [sym__term_unsigned] = {
    .visible = false,
    .named = true,
  },
  [sym__term_signed] = {
    .visible = true,
    .named = true,
  },
  [sym_parenthesized] = {
    .visible = true,
    .named = true,
  },
  [sym__parenthesized] = {
    .visible = false,
    .named = true,
  },
  [sym_function] = {
    .visible = true,
    .named = true,
  },
  [sym__operator_multiplication] = {
    .visible = true,
    .named = true,
  },
  [sym__operator_summation] = {
    .visible = true,
    .named = true,
  },
  [sym_label] = {
    .visible = true,
    .named = true,
  },
  [sym__labels] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_script_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_attribute_identifier_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_ability_identifier_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__macro_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__number_signable_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_formula_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_label_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__labels_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_character_identifier] = {
    .visible = true,
    .named = true,
  },
};

enum {
  field_selected = 1,
  field_target = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_selected] = "selected",
  [field_target] = "target",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_target, 0},
  [1] =
    {field_selected, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [3] = {
    [0] = sym_number,
  },
  [4] = {
    [1] = sym_number,
  },
  [5] = {
    [1] = sym__term_first,
  },
  [6] = {
    [1] = alias_sym_character_identifier,
  },
  [7] = {
    [2] = sym__term_first,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym_attribute_identifier, 2,
    sym_attribute_identifier,
    alias_sym_character_identifier,
  sym_ability_identifier, 2,
    sym_ability_identifier,
    alias_sym_character_identifier,
  sym__number_signable, 2,
    sym__number_signable,
    sym_number,
  sym__number_unsignable, 2,
    sym__number_unsignable,
    sym_number,
  sym__term_unsigned, 2,
    sym__term_unsigned,
    sym__term_first,
  0,
};

static inline bool aux_sym__macro_token1_character_set_1(int32_t c) {
  return (c < '&'
    ? (c < '\r'
      ? (c < '\n'
        ? c == 0
        : c <= '\n')
      : (c <= '\r' || c == ' '))
    : (c <= '&' || (c < ']'
      ? (c < '['
        ? (c >= '(' && c <= ')')
        : c <= '[')
      : (c <= ']' || (c >= '{' && c <= '}')))));
}

static inline bool aux_sym__macro_token1_character_set_2(int32_t c) {
  return (c < '('
    ? (c < '\r'
      ? (c < '\n'
        ? c == 0
        : c <= '\n')
      : (c <= '\r' || (c < '%'
        ? c == ' '
        : c <= '&')))
    : (c <= ')' || (c < ']'
      ? (c < '['
        ? c == '@'
        : c <= '[')
      : (c <= ']' || (c >= '{' && c <= '}')))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(42);
      if (lookahead == '\n') ADVANCE(113);
      if (lookahead == '\r') ADVANCE(44);
      if (lookahead == '#') ADVANCE(106);
      if (lookahead == '%') ADVANCE(47);
      if (lookahead == '&') ADVANCE(45);
      if (lookahead == '(') ADVANCE(119);
      if (lookahead == ')') ADVANCE(120);
      if (lookahead == '.') ADVANCE(117);
      if (lookahead == '@') ADVANCE(48);
      if (lookahead == '[') ADVANCE(129);
      if (lookahead == ']') ADVANCE(139);
      if (lookahead == '|') ADVANCE(61);
      if (lookahead == '}') ADVANCE(60);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(43);
      if (lookahead != 0) ADVANCE(43);
      END_STATE();
    case 1:
      if (lookahead == '\t') ADVANCE(49);
      if (lookahead == '\n') ADVANCE(51);
      if (lookahead == '\r') ADVANCE(50);
      if (lookahead == ' ') ADVANCE(51);
      if (lookahead == '%') ADVANCE(124);
      if (lookahead == ')') ADVANCE(120);
      if (lookahead == '*') ADVANCE(111);
      if (lookahead == '+') ADVANCE(107);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '/') ADVANCE(112);
      if (lookahead == '@') ADVANCE(37);
      if (lookahead == '[') ADVANCE(129);
      if (lookahead == ']') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '(' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(112);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(106);
      if (lookahead == '%') ADVANCE(124);
      if (lookahead == '(') ADVANCE(119);
      if (lookahead == ')') ADVANCE(120);
      if (lookahead == '*') ADVANCE(123);
      if (lookahead == '+') ADVANCE(126);
      if (lookahead == '-') ADVANCE(127);
      if (lookahead == '.') ADVANCE(117);
      if (lookahead == '/') ADVANCE(122);
      if (lookahead == '@') ADVANCE(37);
      if (lookahead == '[') ADVANCE(130);
      if (lookahead == ']') ADVANCE(19);
      if (lookahead == 'a') ADVANCE(21);
      if (lookahead == 'c') ADVANCE(23);
      if (lookahead == 'f') ADVANCE(26);
      if (lookahead == 'r') ADVANCE(29);
      if (lookahead == '|') ADVANCE(61);
      if (lookahead == '}') ADVANCE(60);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(106);
      if (lookahead == '%') ADVANCE(137);
      if (lookahead == '&') ADVANCE(136);
      if (lookahead == '@') ADVANCE(138);
      if (lookahead == ']') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(135);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(106);
      if (lookahead == '%') ADVANCE(133);
      if (lookahead == '&') ADVANCE(132);
      if (lookahead == '@') ADVANCE(134);
      if (lookahead == ']') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '[') ADVANCE(131);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(106);
      if (lookahead == '%') ADVANCE(36);
      if (lookahead == '(') ADVANCE(119);
      if (lookahead == '.') ADVANCE(117);
      if (lookahead == '@') ADVANCE(37);
      if (lookahead == '[') ADVANCE(130);
      if (lookahead == 'a') ADVANCE(21);
      if (lookahead == 'c') ADVANCE(23);
      if (lookahead == 'f') ADVANCE(26);
      if (lookahead == 'r') ADVANCE(29);
      if (lookahead == '|') ADVANCE(27);
      if (lookahead == '}') ADVANCE(60);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(118);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(106);
      if (lookahead == '&') ADVANCE(63);
      if (lookahead == 's') ADVANCE(68);
      if (lookahead == 't') ADVANCE(65);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(80);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(106);
      if (lookahead == '&') ADVANCE(63);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '|') ADVANCE(61);
      if (lookahead == '}') ADVANCE(60);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(80);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(79);
      END_STATE();
    case 8:
      if (lookahead == '#') ADVANCE(106);
      if (lookahead == '&') ADVANCE(63);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '|') ADVANCE(27);
      if (lookahead == '}') ADVANCE(60);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(80);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(79);
      END_STATE();
    case 9:
      if (lookahead == '%') ADVANCE(36);
      if (lookahead == '@') ADVANCE(37);
      if (!aux_sym__macro_token1_character_set_1(lookahead)) ADVANCE(112);
      END_STATE();
    case 10:
      if (lookahead == '&') ADVANCE(83);
      if (lookahead == 's') ADVANCE(90);
      if (lookahead == 't') ADVANCE(87);
      if (lookahead == '{') ADVANCE(99);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 11:
      if (lookahead == '&') ADVANCE(83);
      if (lookahead == '{') ADVANCE(99);
      if (lookahead == '|') ADVANCE(61);
      if (lookahead == '}') ADVANCE(60);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(103);
      END_STATE();
    case 12:
      if (lookahead == '+') ADVANCE(126);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == '+') ADVANCE(128);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(127);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(125);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == ';') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == ';') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == ';') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 19:
      if (lookahead == ']') ADVANCE(115);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(35);
      END_STATE();
    case 21:
      if (lookahead == 'b') ADVANCE(33);
      END_STATE();
    case 22:
      if (lookahead == 'd') ADVANCE(121);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 24:
      if (lookahead == 'i') ADVANCE(25);
      END_STATE();
    case 25:
      if (lookahead == 'l') ADVANCE(121);
      END_STATE();
    case 26:
      if (lookahead == 'l') ADVANCE(31);
      END_STATE();
    case 27:
      if (lookahead == 'm') ADVANCE(20);
      END_STATE();
    case 28:
      if (lookahead == 'n') ADVANCE(22);
      END_STATE();
    case 29:
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 30:
      if (lookahead == 'o') ADVANCE(32);
      END_STATE();
    case 31:
      if (lookahead == 'o') ADVANCE(30);
      END_STATE();
    case 32:
      if (lookahead == 'r') ADVANCE(121);
      END_STATE();
    case 33:
      if (lookahead == 's') ADVANCE(121);
      END_STATE();
    case 34:
      if (lookahead == 'u') ADVANCE(28);
      END_STATE();
    case 35:
      if (lookahead == 'x') ADVANCE(38);
      END_STATE();
    case 36:
      if (lookahead == '{') ADVANCE(82);
      END_STATE();
    case 37:
      if (lookahead == '{') ADVANCE(59);
      END_STATE();
    case 38:
      if (lookahead == '}') ADVANCE(62);
      END_STATE();
    case 39:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 40:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(17);
      END_STATE();
    case 41:
      if (eof) ADVANCE(42);
      if (lookahead == '#') ADVANCE(106);
      if (lookahead == '%') ADVANCE(47);
      if (lookahead == '&') ADVANCE(45);
      if (lookahead == '@') ADVANCE(48);
      if (lookahead == '[') ADVANCE(46);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(43);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym_script_token1);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '\n') ADVANCE(113);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '#') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '[') ADVANCE(114);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '{') ADVANCE(82);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '{') ADVANCE(59);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym__wsp);
      if (lookahead == '\t') ADVANCE(49);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '@' &&
          lookahead != '[' &&
          lookahead != ']' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(112);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym__wsp);
      if (lookahead == '\n') ADVANCE(51);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(51);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym__wsp);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_htmlEntity);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_htmlEntity);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_htmlEntity);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_PIPEmax_RBRACE);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '#') ADVANCE(39);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == ';') ADVANCE(53);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'a') ADVANCE(74);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'c') ADVANCE(76);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'd') ADVANCE(57);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(73);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(66);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(67);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(75);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'g') ADVANCE(71);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'l') ADVANCE(69);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'r') ADVANCE(72);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 't') ADVANCE(55);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 't') ADVANCE(70);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(80);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(77);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(78);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(80);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(77);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_PERCENT_LBRACE);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '#') ADVANCE(101);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == ';') ADVANCE(54);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == ';') ADVANCE(54);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == ';') ADVANCE(54);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'a') ADVANCE(96);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'c') ADVANCE(98);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'd') ADVANCE(58);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(95);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(88);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(89);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(97);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'g') ADVANCE(93);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'l') ADVANCE(91);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'r') ADVANCE(94);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 't') ADVANCE(56);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 't') ADVANCE(92);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(99);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(100);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(99);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(105);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_hash);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (lookahead == '\t') ADVANCE(107);
      if (lookahead == '-') ADVANCE(110);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '@' &&
          lookahead != '[' &&
          lookahead != ']' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(112);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (lookahead == '\t') ADVANCE(108);
      if (lookahead == '+') ADVANCE(109);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '@' &&
          lookahead != '[' &&
          lookahead != ']' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(112);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (lookahead == '\t') ADVANCE(109);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '@' &&
          lookahead != '[' &&
          lookahead != ']' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(112);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (lookahead == '\t') ADVANCE(110);
      if (lookahead == '+') ADVANCE(107);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '@' &&
          lookahead != '[' &&
          lookahead != ']' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(112);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (lookahead == '*') ADVANCE(112);
      if (!aux_sym__macro_token1_character_set_2(lookahead)) ADVANCE(112);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (!aux_sym__macro_token1_character_set_2(lookahead)) ADVANCE(112);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(aux_sym__macro_token2);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(aux_sym__number_signable_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(aux_sym__term_first_token1);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(aux_sym_function_token1);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(aux_sym__operator_multiplication_token1);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(aux_sym__operator_multiplication_token1);
      if (lookahead == '*') ADVANCE(122);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym__operator_multiplication_token1);
      if (lookahead == '{') ADVANCE(82);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym__operator_summation_plus);
      if (lookahead == '+') ADVANCE(126);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym__operator_summation_plus);
      if (lookahead == '-') ADVANCE(125);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(15);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym__operator_summation_minus);
      if (lookahead == '+') ADVANCE(128);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(13);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym__operator_summation_minus);
      if (lookahead == '-') ADVANCE(127);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead == '[') ADVANCE(114);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_label_token1);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_label_token1);
      if (lookahead == '#') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_label_token1);
      if (lookahead == '{') ADVANCE(82);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_label_token1);
      if (lookahead == '{') ADVANCE(59);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_label_token2);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(aux_sym_label_token2);
      if (lookahead == '#') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(aux_sym_label_token2);
      if (lookahead == '{') ADVANCE(82);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_label_token2);
      if (lookahead == '{') ADVANCE(59);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 41},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 5},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 41},
  [24] = {.lex_state = 41},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 3},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 3},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 3},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 2},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 3},
  [42] = {.lex_state = 2},
  [43] = {.lex_state = 2},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 3},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 5},
  [51] = {.lex_state = 2},
  [52] = {.lex_state = 5},
  [53] = {.lex_state = 4},
  [54] = {.lex_state = 5},
  [55] = {.lex_state = 5},
  [56] = {.lex_state = 1},
  [57] = {.lex_state = 1},
  [58] = {.lex_state = 1},
  [59] = {.lex_state = 1},
  [60] = {.lex_state = 1},
  [61] = {.lex_state = 1},
  [62] = {.lex_state = 1},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 5},
  [65] = {.lex_state = 5},
  [66] = {.lex_state = 5},
  [67] = {.lex_state = 5},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 5},
  [72] = {.lex_state = 9},
  [73] = {.lex_state = 2},
  [74] = {.lex_state = 2},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 2},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 2},
  [79] = {.lex_state = 2},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 6},
  [85] = {.lex_state = 2},
  [86] = {.lex_state = 6},
  [87] = {.lex_state = 2},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 6},
  [90] = {.lex_state = 6},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 10},
  [93] = {.lex_state = 41},
  [94] = {.lex_state = 41},
  [95] = {.lex_state = 41},
  [96] = {.lex_state = 41},
  [97] = {.lex_state = 2},
  [98] = {.lex_state = 2},
  [99] = {.lex_state = 10},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 2},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 10},
  [104] = {.lex_state = 10},
  [105] = {.lex_state = 41},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 2},
  [109] = {.lex_state = 2},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 41},
  [112] = {.lex_state = 41},
  [113] = {.lex_state = 41},
  [114] = {.lex_state = 41},
  [115] = {.lex_state = 7},
  [116] = {.lex_state = 7},
  [117] = {.lex_state = 8},
  [118] = {.lex_state = 3},
  [119] = {.lex_state = 3},
  [120] = {.lex_state = 3},
  [121] = {.lex_state = 3},
  [122] = {.lex_state = 8},
  [123] = {.lex_state = 3},
  [124] = {.lex_state = 3},
  [125] = {.lex_state = 3},
  [126] = {.lex_state = 3},
  [127] = {.lex_state = 7},
  [128] = {.lex_state = 7},
  [129] = {.lex_state = 7},
  [130] = {.lex_state = 11},
  [131] = {.lex_state = 11},
  [132] = {.lex_state = 7},
  [133] = {.lex_state = 2},
  [134] = {.lex_state = 7},
  [135] = {.lex_state = 7},
  [136] = {.lex_state = 2},
  [137] = {.lex_state = 7},
  [138] = {.lex_state = 7},
  [139] = {.lex_state = 11},
  [140] = {.lex_state = 11},
  [141] = {.lex_state = 11},
  [142] = {.lex_state = 11},
  [143] = {.lex_state = 11},
  [144] = {.lex_state = 11},
  [145] = {.lex_state = 11},
  [146] = {.lex_state = 11},
  [147] = {.lex_state = 2},
  [148] = {.lex_state = 2},
  [149] = {.lex_state = 2},
  [150] = {.lex_state = 2},
  [151] = {.lex_state = 5},
  [152] = {.lex_state = 5},
  [153] = {.lex_state = 5},
  [154] = {.lex_state = 2},
  [155] = {.lex_state = 2},
  [156] = {.lex_state = 2},
  [157] = {.lex_state = 5},
  [158] = {.lex_state = 5},
  [159] = {.lex_state = 5},
  [160] = {.lex_state = 5},
  [161] = {.lex_state = 5},
  [162] = {.lex_state = 2},
  [163] = {.lex_state = 2},
  [164] = {.lex_state = 2},
  [165] = {.lex_state = 2},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 2},
  [168] = {.lex_state = 2},
  [169] = {.lex_state = 2},
  [170] = {.lex_state = 2},
  [171] = {.lex_state = 2},
  [172] = {.lex_state = 2},
  [173] = {.lex_state = 2},
  [174] = {.lex_state = 2},
  [175] = {.lex_state = 2},
  [176] = {.lex_state = 2},
  [177] = {.lex_state = 2},
  [178] = {.lex_state = 2},
  [179] = {.lex_state = 2},
  [180] = {.lex_state = 2},
  [181] = {.lex_state = 2},
  [182] = {.lex_state = 2},
  [183] = {.lex_state = 2},
  [184] = {.lex_state = 2},
  [185] = {.lex_state = 2},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym_script_token1] = ACTIONS(1),
    [sym_htmlEntity] = ACTIONS(1),
    [anon_sym_AT_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(1),
    [sym_hash] = ACTIONS(1),
    [aux_sym__macro_token2] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [aux_sym__term_first_token1] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [aux_sym_label_token1] = ACTIONS(1),
    [aux_sym_label_token2] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
  },
  [1] = {
    [sym_script] = STATE(166),
    [sym__placeholder] = STATE(23),
    [sym__attribute] = STATE(23),
    [sym_attribute] = STATE(23),
    [sym__attribute_of_character] = STATE(23),
    [sym__attribute_of_character_maximum] = STATE(23),
    [sym_ability] = STATE(23),
    [sym_inlineRoll] = STATE(23),
    [sym__IrPh] = STATE(23),
    [aux_sym_script_repeat1] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_script_token1] = ACTIONS(5),
    [sym_htmlEntity] = ACTIONS(7),
    [anon_sym_AT_LBRACE] = ACTIONS(9),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(11),
    [sym_hash] = ACTIONS(7),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(13),
  },
  [2] = {
    [sym__placeholder] = STATE(12),
    [sym__attribute] = STATE(12),
    [sym_attribute] = STATE(12),
    [sym__attribute_of_character] = STATE(12),
    [sym__attribute_of_character_maximum] = STATE(12),
    [sym_ability] = STATE(12),
    [sym__macro] = STATE(110),
    [sym_inlineRoll] = STATE(12),
    [sym__IrPh] = STATE(12),
    [sym_number] = STATE(79),
    [sym__number_signable] = STATE(81),
    [sym__number_unsignable] = STATE(81),
    [sym__term_unsigned] = STATE(75),
    [sym__term_signed] = STATE(75),
    [sym_parenthesized] = STATE(18),
    [sym__parenthesized] = STATE(69),
    [sym_function] = STATE(18),
    [sym__operator_summation] = STATE(6),
    [sym_label] = STATE(26),
    [sym__labels] = STATE(8),
    [aux_sym__number_signable_repeat1] = STATE(12),
    [aux_sym__labels_repeat1] = STATE(20),
    [sym__wsp] = ACTIONS(15),
    [anon_sym_AT_LBRACE] = ACTIONS(17),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(19),
    [sym_hash] = ACTIONS(21),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(23),
    [aux_sym__number_signable_token1] = ACTIONS(25),
    [anon_sym_DOT] = ACTIONS(27),
    [anon_sym_LPAREN] = ACTIONS(29),
    [aux_sym_function_token1] = ACTIONS(31),
    [sym__operator_summation_plus] = ACTIONS(33),
    [sym__operator_summation_minus] = ACTIONS(33),
    [anon_sym_LBRACK] = ACTIONS(35),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 21,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      sym_hash,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      aux_sym_function_token1,
    ACTIONS(37), 1,
      sym__wsp,
    ACTIONS(39), 1,
      aux_sym__term_first_token1,
    ACTIONS(41), 1,
      anon_sym_LBRACK,
    STATE(9), 1,
      sym__labels,
    STATE(43), 1,
      sym__term_first,
    STATE(54), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    STATE(69), 1,
      sym__parenthesized,
    STATE(108), 1,
      sym__macro,
    STATE(167), 1,
      sym_formula,
    STATE(77), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(78), 2,
      sym_parenthesized,
      sym_function,
    STATE(12), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [74] = 21,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      sym_hash,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      aux_sym_function_token1,
    ACTIONS(37), 1,
      sym__wsp,
    ACTIONS(39), 1,
      aux_sym__term_first_token1,
    ACTIONS(41), 1,
      anon_sym_LBRACK,
    STATE(9), 1,
      sym__labels,
    STATE(43), 1,
      sym__term_first,
    STATE(54), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    STATE(69), 1,
      sym__parenthesized,
    STATE(108), 1,
      sym__macro,
    STATE(165), 1,
      sym_formula,
    STATE(77), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(78), 2,
      sym_parenthesized,
      sym_function,
    STATE(12), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [148] = 21,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      sym_hash,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      aux_sym_function_token1,
    ACTIONS(37), 1,
      sym__wsp,
    ACTIONS(39), 1,
      aux_sym__term_first_token1,
    ACTIONS(41), 1,
      anon_sym_LBRACK,
    STATE(9), 1,
      sym__labels,
    STATE(43), 1,
      sym__term_first,
    STATE(54), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    STATE(69), 1,
      sym__parenthesized,
    STATE(108), 1,
      sym__macro,
    STATE(176), 1,
      sym_formula,
    STATE(77), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(78), 2,
      sym_parenthesized,
      sym_function,
    STATE(12), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [222] = 20,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      sym_hash,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      aux_sym_function_token1,
    ACTIONS(37), 1,
      sym__wsp,
    ACTIONS(41), 1,
      anon_sym_LBRACK,
    STATE(11), 1,
      sym__labels,
    STATE(54), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    STATE(69), 1,
      sym__parenthesized,
    STATE(79), 1,
      sym_number,
    STATE(100), 1,
      sym__term_unsigned,
    STATE(110), 1,
      sym__macro,
    STATE(18), 2,
      sym_parenthesized,
      sym_function,
    STATE(81), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(12), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [293] = 20,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      sym_hash,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      aux_sym_function_token1,
    ACTIONS(37), 1,
      sym__wsp,
    ACTIONS(41), 1,
      anon_sym_LBRACK,
    STATE(10), 1,
      sym__labels,
    STATE(54), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    STATE(69), 1,
      sym__parenthesized,
    STATE(75), 1,
      sym__term_unsigned,
    STATE(79), 1,
      sym_number,
    STATE(110), 1,
      sym__macro,
    STATE(18), 2,
      sym_parenthesized,
      sym_function,
    STATE(81), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(12), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [364] = 17,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      sym_hash,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      aux_sym_function_token1,
    STATE(6), 1,
      sym__operator_summation,
    STATE(69), 1,
      sym__parenthesized,
    STATE(79), 1,
      sym_number,
    STATE(110), 1,
      sym__macro,
    ACTIONS(33), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(18), 2,
      sym_parenthesized,
      sym_function,
    STATE(73), 2,
      sym__term_unsigned,
      sym__term_signed,
    STATE(81), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(12), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [428] = 15,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      sym_hash,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      aux_sym_function_token1,
    ACTIONS(39), 1,
      aux_sym__term_first_token1,
    STATE(39), 1,
      sym__term_first,
    STATE(69), 1,
      sym__parenthesized,
    STATE(108), 1,
      sym__macro,
    STATE(77), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(78), 2,
      sym_parenthesized,
      sym_function,
    STATE(12), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [484] = 15,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      sym_hash,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      aux_sym_function_token1,
    STATE(69), 1,
      sym__parenthesized,
    STATE(73), 1,
      sym__term_unsigned,
    STATE(79), 1,
      sym_number,
    STATE(110), 1,
      sym__macro,
    STATE(18), 2,
      sym_parenthesized,
      sym_function,
    STATE(81), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(12), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [540] = 15,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      sym_hash,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      aux_sym_function_token1,
    STATE(69), 1,
      sym__parenthesized,
    STATE(79), 1,
      sym_number,
    STATE(102), 1,
      sym__term_unsigned,
    STATE(110), 1,
      sym__macro,
    STATE(18), 2,
      sym_parenthesized,
      sym_function,
    STATE(81), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(12), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [596] = 8,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(45), 1,
      aux_sym__number_signable_token1,
    ACTIONS(47), 1,
      anon_sym_DOT,
    ACTIONS(49), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(43), 6,
      sym__wsp,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(13), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [635] = 7,
    ACTIONS(53), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(56), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(59), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(62), 1,
      aux_sym__number_signable_token1,
    ACTIONS(65), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(51), 7,
      sym__wsp,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      anon_sym_DOT,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(13), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [672] = 7,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(45), 1,
      aux_sym__number_signable_token1,
    ACTIONS(69), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(67), 6,
      sym__wsp,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(13), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [708] = 7,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(45), 1,
      aux_sym__number_signable_token1,
    ACTIONS(73), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(71), 6,
      sym__wsp,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(13), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [744] = 7,
    ACTIONS(77), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(79), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(81), 1,
      aux_sym__macro_token1,
    ACTIONS(75), 2,
      sym__wsp,
      aux_sym__macro_token2,
    ACTIONS(83), 3,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
    ACTIONS(85), 3,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(17), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_repeat1,
  [777] = 6,
    ACTIONS(89), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(92), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(95), 1,
      aux_sym__macro_token1,
    ACTIONS(98), 3,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
    ACTIONS(87), 5,
      sym__wsp,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(17), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_repeat1,
  [808] = 7,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      sym_hash,
    ACTIONS(102), 1,
      aux_sym__operator_multiplication_token1,
    STATE(98), 1,
      sym__macro,
    ACTIONS(100), 6,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
    STATE(76), 6,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
  [840] = 5,
    ACTIONS(35), 1,
      anon_sym_LBRACK,
    ACTIONS(106), 1,
      aux_sym__operator_multiplication_token1,
    STATE(21), 1,
      aux_sym__labels_repeat1,
    STATE(26), 1,
      sym_label,
    ACTIONS(104), 12,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      aux_sym_function_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [867] = 5,
    ACTIONS(35), 1,
      anon_sym_LBRACK,
    ACTIONS(106), 1,
      aux_sym__operator_multiplication_token1,
    STATE(22), 1,
      aux_sym__labels_repeat1,
    STATE(26), 1,
      sym_label,
    ACTIONS(104), 12,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      aux_sym_function_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [894] = 5,
    ACTIONS(35), 1,
      anon_sym_LBRACK,
    ACTIONS(110), 1,
      aux_sym__operator_multiplication_token1,
    STATE(22), 1,
      aux_sym__labels_repeat1,
    STATE(26), 1,
      sym_label,
    ACTIONS(108), 12,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      aux_sym_function_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [921] = 5,
    ACTIONS(114), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(116), 1,
      anon_sym_LBRACK,
    STATE(22), 1,
      aux_sym__labels_repeat1,
    STATE(26), 1,
      sym_label,
    ACTIONS(112), 12,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      aux_sym_function_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [948] = 7,
    ACTIONS(9), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(11), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(13), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(119), 1,
      ts_builtin_sym_end,
    ACTIONS(121), 1,
      aux_sym_script_token1,
    ACTIONS(123), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(24), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym_script_repeat1,
  [979] = 7,
    ACTIONS(125), 1,
      ts_builtin_sym_end,
    ACTIONS(127), 1,
      aux_sym_script_token1,
    ACTIONS(133), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(136), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(139), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(130), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(24), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym_script_repeat1,
  [1010] = 2,
    ACTIONS(144), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(142), 13,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      aux_sym_function_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1030] = 3,
    ACTIONS(146), 1,
      sym__wsp,
    ACTIONS(150), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(148), 12,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      aux_sym_function_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1052] = 2,
    ACTIONS(154), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(152), 13,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      aux_sym_function_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1072] = 2,
    ACTIONS(158), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(156), 13,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      aux_sym_function_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1092] = 2,
    ACTIONS(114), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(112), 12,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      aux_sym_function_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1111] = 6,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    STATE(80), 1,
      sym__number_signable,
    STATE(12), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [1138] = 6,
    ACTIONS(162), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(164), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(166), 1,
      aux_sym_label_token2,
    ACTIONS(168), 1,
      anon_sym_RBRACK,
    ACTIONS(160), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(47), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_label_repeat1,
  [1164] = 2,
    ACTIONS(172), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(170), 11,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1182] = 6,
    ACTIONS(162), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(164), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(176), 1,
      aux_sym_label_token2,
    ACTIONS(178), 1,
      anon_sym_RBRACK,
    ACTIONS(174), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(36), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_label_repeat1,
  [1208] = 5,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(180), 1,
      aux_sym__number_signable_token1,
    STATE(14), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [1232] = 2,
    ACTIONS(184), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(182), 11,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1250] = 6,
    ACTIONS(162), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(164), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(188), 1,
      aux_sym_label_token2,
    ACTIONS(190), 1,
      anon_sym_RBRACK,
    ACTIONS(186), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(41), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_label_repeat1,
  [1276] = 2,
    ACTIONS(194), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(192), 11,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1294] = 2,
    ACTIONS(198), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(196), 11,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1312] = 11,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(202), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(204), 1,
      anon_sym_LBRACK,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(20), 1,
      aux_sym__labels_repeat1,
    STATE(26), 1,
      sym_label,
    STATE(83), 1,
      sym__labels,
    STATE(85), 1,
      aux_sym_formula_repeat1,
    ACTIONS(33), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    ACTIONS(200), 2,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
  [1348] = 2,
    ACTIONS(208), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(206), 11,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1366] = 6,
    ACTIONS(213), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(216), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(219), 1,
      aux_sym_label_token2,
    ACTIONS(222), 1,
      anon_sym_RBRACK,
    ACTIONS(210), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(41), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_label_repeat1,
  [1392] = 2,
    ACTIONS(226), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(224), 11,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1410] = 11,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(202), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(204), 1,
      anon_sym_LBRACK,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(20), 1,
      aux_sym__labels_repeat1,
    STATE(26), 1,
      sym_label,
    STATE(87), 1,
      aux_sym_formula_repeat1,
    STATE(91), 1,
      sym__labels,
    ACTIONS(33), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    ACTIONS(228), 2,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
  [1446] = 2,
    ACTIONS(232), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(230), 11,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1464] = 5,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(234), 1,
      aux_sym__number_signable_token1,
    STATE(15), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [1488] = 2,
    ACTIONS(238), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(236), 11,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1506] = 6,
    ACTIONS(162), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(164), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(188), 1,
      aux_sym_label_token2,
    ACTIONS(240), 1,
      anon_sym_RBRACK,
    ACTIONS(186), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(41), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_label_repeat1,
  [1532] = 2,
    ACTIONS(244), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(242), 11,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1550] = 6,
    ACTIONS(162), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(164), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(248), 1,
      aux_sym_label_token1,
    ACTIONS(250), 1,
      anon_sym_RBRACK,
    ACTIONS(246), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(33), 6,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
  [1575] = 4,
    ACTIONS(41), 1,
      anon_sym_LBRACK,
    STATE(52), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    ACTIONS(104), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
      anon_sym_LPAREN,
      aux_sym_function_token1,
  [1596] = 2,
    ACTIONS(254), 1,
      anon_sym_LBRACK,
    ACTIONS(252), 11,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_LPAREN,
      aux_sym_function_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1613] = 4,
    ACTIONS(41), 1,
      anon_sym_LBRACK,
    STATE(55), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    ACTIONS(108), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
      anon_sym_LPAREN,
      aux_sym_function_token1,
  [1634] = 6,
    ACTIONS(162), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(164), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(258), 1,
      aux_sym_label_token1,
    ACTIONS(260), 1,
      anon_sym_RBRACK,
    ACTIONS(256), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(31), 6,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
  [1659] = 4,
    ACTIONS(41), 1,
      anon_sym_LBRACK,
    STATE(55), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    ACTIONS(104), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
      anon_sym_LPAREN,
      aux_sym_function_token1,
  [1680] = 4,
    ACTIONS(262), 1,
      anon_sym_LBRACK,
    STATE(55), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    ACTIONS(112), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
      anon_sym_LPAREN,
      aux_sym_function_token1,
  [1701] = 2,
    ACTIONS(170), 5,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
    ACTIONS(172), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1717] = 2,
    ACTIONS(224), 5,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
    ACTIONS(226), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1733] = 2,
    ACTIONS(242), 5,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
    ACTIONS(244), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1749] = 2,
    ACTIONS(182), 5,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
    ACTIONS(184), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1765] = 2,
    ACTIONS(230), 5,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
    ACTIONS(232), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1781] = 2,
    ACTIONS(196), 5,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
    ACTIONS(198), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1797] = 2,
    ACTIONS(206), 5,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
    ACTIONS(208), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1813] = 2,
    ACTIONS(236), 5,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
    ACTIONS(238), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1829] = 2,
    ACTIONS(144), 1,
      anon_sym_LBRACK,
    ACTIONS(142), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
      anon_sym_LPAREN,
      aux_sym_function_token1,
  [1845] = 2,
    ACTIONS(154), 1,
      anon_sym_LBRACK,
    ACTIONS(152), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
      anon_sym_LPAREN,
      aux_sym_function_token1,
  [1861] = 3,
    ACTIONS(150), 1,
      anon_sym_LBRACK,
    ACTIONS(265), 1,
      sym__wsp,
    ACTIONS(148), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
      anon_sym_LPAREN,
      aux_sym_function_token1,
  [1879] = 2,
    ACTIONS(158), 1,
      anon_sym_LBRACK,
    ACTIONS(156), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
      anon_sym_LPAREN,
      aux_sym_function_token1,
  [1895] = 2,
    ACTIONS(269), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(267), 9,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [1910] = 2,
    ACTIONS(273), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(271), 9,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [1925] = 2,
    ACTIONS(277), 1,
      anon_sym_LBRACK,
    ACTIONS(275), 9,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      anon_sym_LPAREN,
      aux_sym_function_token1,
  [1940] = 2,
    ACTIONS(114), 1,
      anon_sym_LBRACK,
    ACTIONS(112), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
      anon_sym_LPAREN,
      aux_sym_function_token1,
  [1955] = 4,
    ACTIONS(77), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(79), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(279), 1,
      aux_sym__macro_token1,
    STATE(16), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_repeat1,
  [1974] = 6,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(204), 1,
      anon_sym_LBRACK,
    STATE(20), 1,
      aux_sym__labels_repeat1,
    STATE(26), 1,
      sym_label,
    STATE(133), 1,
      sym__labels,
    ACTIONS(281), 5,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1997] = 2,
    ACTIONS(285), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(283), 9,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2012] = 6,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(204), 1,
      anon_sym_LBRACK,
    STATE(20), 1,
      aux_sym__labels_repeat1,
    STATE(26), 1,
      sym_label,
    STATE(136), 1,
      sym__labels,
    ACTIONS(287), 5,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2035] = 3,
    ACTIONS(21), 1,
      sym_hash,
    STATE(101), 1,
      sym__macro,
    ACTIONS(289), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2051] = 3,
    ACTIONS(21), 1,
      sym_hash,
    STATE(106), 1,
      sym__macro,
    ACTIONS(291), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2067] = 3,
    ACTIONS(21), 1,
      sym_hash,
    STATE(97), 1,
      sym__macro,
    ACTIONS(293), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2083] = 3,
    ACTIONS(21), 1,
      sym_hash,
    STATE(98), 1,
      sym__macro,
    ACTIONS(100), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2099] = 3,
    ACTIONS(21), 1,
      sym_hash,
    STATE(109), 1,
      sym__macro,
    ACTIONS(295), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2115] = 1,
    ACTIONS(297), 8,
      sym__wsp,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2126] = 6,
    ACTIONS(301), 1,
      aux_sym__operator_multiplication_token1,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(82), 1,
      aux_sym_formula_repeat1,
    ACTIONS(299), 2,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
    ACTIONS(304), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2147] = 6,
    ACTIONS(202), 1,
      aux_sym__operator_multiplication_token1,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(88), 1,
      aux_sym_formula_repeat1,
    ACTIONS(33), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    ACTIONS(307), 2,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
  [2168] = 7,
    ACTIONS(311), 1,
      anon_sym_target,
    ACTIONS(313), 1,
      anon_sym_selected,
    ACTIONS(315), 1,
      sym_hash,
    STATE(115), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(163), 1,
      sym_attribute_identifier,
    STATE(170), 1,
      sym_character_token_identifier,
    ACTIONS(309), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2191] = 6,
    ACTIONS(202), 1,
      aux_sym__operator_multiplication_token1,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(82), 1,
      aux_sym_formula_repeat1,
    ACTIONS(33), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    ACTIONS(307), 2,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
  [2212] = 7,
    ACTIONS(311), 1,
      anon_sym_target,
    ACTIONS(313), 1,
      anon_sym_selected,
    ACTIONS(315), 1,
      sym_hash,
    STATE(115), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(149), 1,
      sym_attribute_identifier,
    STATE(182), 1,
      sym_character_token_identifier,
    ACTIONS(309), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2235] = 6,
    ACTIONS(202), 1,
      aux_sym__operator_multiplication_token1,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(82), 1,
      aux_sym_formula_repeat1,
    ACTIONS(33), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    ACTIONS(200), 2,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
  [2256] = 6,
    ACTIONS(202), 1,
      aux_sym__operator_multiplication_token1,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(82), 1,
      aux_sym_formula_repeat1,
    ACTIONS(33), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    ACTIONS(317), 2,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
  [2277] = 7,
    ACTIONS(311), 1,
      anon_sym_target,
    ACTIONS(313), 1,
      anon_sym_selected,
    ACTIONS(315), 1,
      sym_hash,
    STATE(115), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(155), 1,
      sym_attribute_identifier,
    STATE(184), 1,
      sym_character_token_identifier,
    ACTIONS(309), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2300] = 7,
    ACTIONS(311), 1,
      anon_sym_target,
    ACTIONS(313), 1,
      anon_sym_selected,
    ACTIONS(315), 1,
      sym_hash,
    STATE(115), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(148), 1,
      sym_attribute_identifier,
    STATE(180), 1,
      sym_character_token_identifier,
    ACTIONS(309), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2323] = 6,
    ACTIONS(202), 1,
      aux_sym__operator_multiplication_token1,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(85), 1,
      aux_sym_formula_repeat1,
    ACTIONS(33), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    ACTIONS(200), 2,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
  [2344] = 6,
    ACTIONS(311), 1,
      anon_sym_target,
    ACTIONS(313), 1,
      anon_sym_selected,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(156), 1,
      sym_ability_identifier,
    STATE(185), 1,
      sym_character_token_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2364] = 2,
    ACTIONS(184), 1,
      aux_sym_script_token1,
    ACTIONS(182), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2376] = 2,
    ACTIONS(244), 1,
      aux_sym_script_token1,
    ACTIONS(242), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2388] = 2,
    ACTIONS(198), 1,
      aux_sym_script_token1,
    ACTIONS(196), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2400] = 2,
    ACTIONS(238), 1,
      aux_sym_script_token1,
    ACTIONS(236), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2412] = 1,
    ACTIONS(321), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2422] = 1,
    ACTIONS(289), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2432] = 6,
    ACTIONS(311), 1,
      anon_sym_target,
    ACTIONS(313), 1,
      anon_sym_selected,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(150), 1,
      sym_ability_identifier,
    STATE(183), 1,
      sym_character_token_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2452] = 1,
    ACTIONS(323), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2462] = 1,
    ACTIONS(325), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2472] = 1,
    ACTIONS(327), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2482] = 6,
    ACTIONS(311), 1,
      anon_sym_target,
    ACTIONS(313), 1,
      anon_sym_selected,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(147), 1,
      sym_ability_identifier,
    STATE(175), 1,
      sym_character_token_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2502] = 6,
    ACTIONS(311), 1,
      anon_sym_target,
    ACTIONS(313), 1,
      anon_sym_selected,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(162), 1,
      sym_ability_identifier,
    STATE(181), 1,
      sym_character_token_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2522] = 2,
    ACTIONS(194), 1,
      aux_sym_script_token1,
    ACTIONS(192), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2534] = 1,
    ACTIONS(329), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2544] = 1,
    ACTIONS(331), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2554] = 1,
    ACTIONS(293), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2564] = 1,
    ACTIONS(333), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2574] = 1,
    ACTIONS(100), 7,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2584] = 2,
    ACTIONS(226), 1,
      aux_sym_script_token1,
    ACTIONS(224), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2596] = 2,
    ACTIONS(208), 1,
      aux_sym_script_token1,
    ACTIONS(206), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2608] = 2,
    ACTIONS(232), 1,
      aux_sym_script_token1,
    ACTIONS(230), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2620] = 2,
    ACTIONS(172), 1,
      aux_sym_script_token1,
    ACTIONS(170), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2632] = 4,
    ACTIONS(339), 1,
      sym_hash,
    STATE(116), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(335), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(337), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [2647] = 4,
    ACTIONS(346), 1,
      sym_hash,
    STATE(116), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(341), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(344), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [2662] = 4,
    ACTIONS(351), 1,
      sym_hash,
    STATE(122), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(337), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(349), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2677] = 2,
    ACTIONS(238), 1,
      aux_sym_label_token2,
    ACTIONS(236), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2688] = 2,
    ACTIONS(198), 1,
      aux_sym_label_token2,
    ACTIONS(196), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2699] = 2,
    ACTIONS(244), 1,
      aux_sym_label_token2,
    ACTIONS(242), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2710] = 2,
    ACTIONS(226), 1,
      aux_sym_label_token2,
    ACTIONS(224), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2721] = 4,
    ACTIONS(356), 1,
      sym_hash,
    STATE(122), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(344), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(353), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2736] = 2,
    ACTIONS(232), 1,
      aux_sym_label_token2,
    ACTIONS(230), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2747] = 2,
    ACTIONS(184), 1,
      aux_sym_label_token2,
    ACTIONS(182), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2758] = 2,
    ACTIONS(208), 1,
      aux_sym_label_token2,
    ACTIONS(206), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2769] = 2,
    ACTIONS(172), 1,
      aux_sym_label_token2,
    ACTIONS(170), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2780] = 4,
    ACTIONS(361), 1,
      sym_hash,
    STATE(117), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(161), 1,
      sym_attribute_identifier,
    ACTIONS(359), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2794] = 4,
    ACTIONS(361), 1,
      sym_hash,
    STATE(117), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(159), 1,
      sym_attribute_identifier,
    ACTIONS(359), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2808] = 4,
    ACTIONS(361), 1,
      sym_hash,
    STATE(117), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(157), 1,
      sym_attribute_identifier,
    ACTIONS(359), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2822] = 3,
    STATE(131), 1,
      aux_sym_ability_identifier_repeat1,
    ACTIONS(363), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    ACTIONS(365), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [2834] = 3,
    STATE(131), 1,
      aux_sym_ability_identifier_repeat1,
    ACTIONS(367), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    ACTIONS(370), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [2846] = 4,
    ACTIONS(361), 1,
      sym_hash,
    STATE(117), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(158), 1,
      sym_attribute_identifier,
    ACTIONS(359), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2860] = 1,
    ACTIONS(372), 5,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2868] = 4,
    ACTIONS(361), 1,
      sym_hash,
    STATE(117), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(153), 1,
      sym_attribute_identifier,
    ACTIONS(359), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2882] = 4,
    ACTIONS(361), 1,
      sym_hash,
    STATE(117), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(160), 1,
      sym_attribute_identifier,
    ACTIONS(359), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2896] = 1,
    ACTIONS(374), 5,
      anon_sym_RBRACK_RBRACK,
      anon_sym_RPAREN,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2904] = 4,
    ACTIONS(361), 1,
      sym_hash,
    STATE(117), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(151), 1,
      sym_attribute_identifier,
    ACTIONS(359), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2918] = 4,
    ACTIONS(361), 1,
      sym_hash,
    STATE(117), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(152), 1,
      sym_attribute_identifier,
    ACTIONS(359), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2932] = 3,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(169), 1,
      sym_ability_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2943] = 3,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(179), 1,
      sym_ability_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2954] = 3,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(173), 1,
      sym_ability_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2965] = 3,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(177), 1,
      sym_ability_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2976] = 3,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(178), 1,
      sym_ability_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2987] = 3,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(171), 1,
      sym_ability_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2998] = 3,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(172), 1,
      sym_ability_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [3009] = 3,
    STATE(130), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(174), 1,
      sym_ability_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [3020] = 2,
    ACTIONS(376), 1,
      anon_sym_RBRACE,
    ACTIONS(378), 1,
      anon_sym_PIPE,
  [3027] = 2,
    ACTIONS(380), 1,
      anon_sym_RBRACE,
    ACTIONS(382), 1,
      anon_sym_PIPE,
  [3034] = 2,
    ACTIONS(384), 1,
      anon_sym_RBRACE,
    ACTIONS(386), 1,
      anon_sym_PIPE,
  [3041] = 2,
    ACTIONS(388), 1,
      anon_sym_RBRACE,
    ACTIONS(390), 1,
      anon_sym_PIPE,
  [3048] = 2,
    ACTIONS(392), 1,
      anon_sym_RBRACE,
    ACTIONS(394), 1,
      anon_sym_PIPEmax_RBRACE,
  [3055] = 2,
    ACTIONS(396), 1,
      anon_sym_RBRACE,
    ACTIONS(398), 1,
      anon_sym_PIPEmax_RBRACE,
  [3062] = 2,
    ACTIONS(400), 1,
      anon_sym_RBRACE,
    ACTIONS(402), 1,
      anon_sym_PIPEmax_RBRACE,
  [3069] = 2,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    STATE(68), 1,
      sym__parenthesized,
  [3076] = 2,
    ACTIONS(404), 1,
      anon_sym_RBRACE,
    ACTIONS(406), 1,
      anon_sym_PIPE,
  [3083] = 2,
    ACTIONS(408), 1,
      anon_sym_RBRACE,
    ACTIONS(410), 1,
      anon_sym_PIPE,
  [3090] = 2,
    ACTIONS(412), 1,
      anon_sym_RBRACE,
    ACTIONS(414), 1,
      anon_sym_PIPEmax_RBRACE,
  [3097] = 2,
    ACTIONS(416), 1,
      anon_sym_RBRACE,
    ACTIONS(418), 1,
      anon_sym_PIPEmax_RBRACE,
  [3104] = 2,
    ACTIONS(420), 1,
      anon_sym_RBRACE,
    ACTIONS(422), 1,
      anon_sym_PIPEmax_RBRACE,
  [3111] = 2,
    ACTIONS(424), 1,
      anon_sym_RBRACE,
    ACTIONS(426), 1,
      anon_sym_PIPEmax_RBRACE,
  [3118] = 2,
    ACTIONS(428), 1,
      anon_sym_RBRACE,
    ACTIONS(430), 1,
      anon_sym_PIPEmax_RBRACE,
  [3125] = 2,
    ACTIONS(432), 1,
      anon_sym_RBRACE,
    ACTIONS(434), 1,
      anon_sym_PIPE,
  [3132] = 2,
    ACTIONS(436), 1,
      anon_sym_RBRACE,
    ACTIONS(438), 1,
      anon_sym_PIPE,
  [3139] = 1,
    ACTIONS(440), 1,
      anon_sym_PIPE,
  [3143] = 1,
    ACTIONS(442), 1,
      anon_sym_RBRACK_RBRACK,
  [3147] = 1,
    ACTIONS(444), 1,
      ts_builtin_sym_end,
  [3151] = 1,
    ACTIONS(446), 1,
      anon_sym_RBRACK_RBRACK,
  [3155] = 1,
    ACTIONS(448), 1,
      anon_sym_PIPE,
  [3159] = 1,
    ACTIONS(450), 1,
      anon_sym_RBRACE,
  [3163] = 1,
    ACTIONS(452), 1,
      anon_sym_PIPE,
  [3167] = 1,
    ACTIONS(454), 1,
      anon_sym_RBRACE,
  [3171] = 1,
    ACTIONS(456), 1,
      anon_sym_RBRACE,
  [3175] = 1,
    ACTIONS(458), 1,
      anon_sym_RBRACE,
  [3179] = 1,
    ACTIONS(460), 1,
      anon_sym_RBRACE,
  [3183] = 1,
    ACTIONS(462), 1,
      anon_sym_PIPE,
  [3187] = 1,
    ACTIONS(464), 1,
      anon_sym_RPAREN,
  [3191] = 1,
    ACTIONS(466), 1,
      anon_sym_RBRACE,
  [3195] = 1,
    ACTIONS(468), 1,
      anon_sym_RBRACE,
  [3199] = 1,
    ACTIONS(470), 1,
      anon_sym_RBRACE,
  [3203] = 1,
    ACTIONS(472), 1,
      anon_sym_PIPE,
  [3207] = 1,
    ACTIONS(474), 1,
      anon_sym_PIPE,
  [3211] = 1,
    ACTIONS(476), 1,
      anon_sym_PIPE,
  [3215] = 1,
    ACTIONS(478), 1,
      anon_sym_PIPE,
  [3219] = 1,
    ACTIONS(480), 1,
      anon_sym_PIPE,
  [3223] = 1,
    ACTIONS(482), 1,
      anon_sym_PIPE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(3)] = 0,
  [SMALL_STATE(4)] = 74,
  [SMALL_STATE(5)] = 148,
  [SMALL_STATE(6)] = 222,
  [SMALL_STATE(7)] = 293,
  [SMALL_STATE(8)] = 364,
  [SMALL_STATE(9)] = 428,
  [SMALL_STATE(10)] = 484,
  [SMALL_STATE(11)] = 540,
  [SMALL_STATE(12)] = 596,
  [SMALL_STATE(13)] = 635,
  [SMALL_STATE(14)] = 672,
  [SMALL_STATE(15)] = 708,
  [SMALL_STATE(16)] = 744,
  [SMALL_STATE(17)] = 777,
  [SMALL_STATE(18)] = 808,
  [SMALL_STATE(19)] = 840,
  [SMALL_STATE(20)] = 867,
  [SMALL_STATE(21)] = 894,
  [SMALL_STATE(22)] = 921,
  [SMALL_STATE(23)] = 948,
  [SMALL_STATE(24)] = 979,
  [SMALL_STATE(25)] = 1010,
  [SMALL_STATE(26)] = 1030,
  [SMALL_STATE(27)] = 1052,
  [SMALL_STATE(28)] = 1072,
  [SMALL_STATE(29)] = 1092,
  [SMALL_STATE(30)] = 1111,
  [SMALL_STATE(31)] = 1138,
  [SMALL_STATE(32)] = 1164,
  [SMALL_STATE(33)] = 1182,
  [SMALL_STATE(34)] = 1208,
  [SMALL_STATE(35)] = 1232,
  [SMALL_STATE(36)] = 1250,
  [SMALL_STATE(37)] = 1276,
  [SMALL_STATE(38)] = 1294,
  [SMALL_STATE(39)] = 1312,
  [SMALL_STATE(40)] = 1348,
  [SMALL_STATE(41)] = 1366,
  [SMALL_STATE(42)] = 1392,
  [SMALL_STATE(43)] = 1410,
  [SMALL_STATE(44)] = 1446,
  [SMALL_STATE(45)] = 1464,
  [SMALL_STATE(46)] = 1488,
  [SMALL_STATE(47)] = 1506,
  [SMALL_STATE(48)] = 1532,
  [SMALL_STATE(49)] = 1550,
  [SMALL_STATE(50)] = 1575,
  [SMALL_STATE(51)] = 1596,
  [SMALL_STATE(52)] = 1613,
  [SMALL_STATE(53)] = 1634,
  [SMALL_STATE(54)] = 1659,
  [SMALL_STATE(55)] = 1680,
  [SMALL_STATE(56)] = 1701,
  [SMALL_STATE(57)] = 1717,
  [SMALL_STATE(58)] = 1733,
  [SMALL_STATE(59)] = 1749,
  [SMALL_STATE(60)] = 1765,
  [SMALL_STATE(61)] = 1781,
  [SMALL_STATE(62)] = 1797,
  [SMALL_STATE(63)] = 1813,
  [SMALL_STATE(64)] = 1829,
  [SMALL_STATE(65)] = 1845,
  [SMALL_STATE(66)] = 1861,
  [SMALL_STATE(67)] = 1879,
  [SMALL_STATE(68)] = 1895,
  [SMALL_STATE(69)] = 1910,
  [SMALL_STATE(70)] = 1925,
  [SMALL_STATE(71)] = 1940,
  [SMALL_STATE(72)] = 1955,
  [SMALL_STATE(73)] = 1974,
  [SMALL_STATE(74)] = 1997,
  [SMALL_STATE(75)] = 2012,
  [SMALL_STATE(76)] = 2035,
  [SMALL_STATE(77)] = 2051,
  [SMALL_STATE(78)] = 2067,
  [SMALL_STATE(79)] = 2083,
  [SMALL_STATE(80)] = 2099,
  [SMALL_STATE(81)] = 2115,
  [SMALL_STATE(82)] = 2126,
  [SMALL_STATE(83)] = 2147,
  [SMALL_STATE(84)] = 2168,
  [SMALL_STATE(85)] = 2191,
  [SMALL_STATE(86)] = 2212,
  [SMALL_STATE(87)] = 2235,
  [SMALL_STATE(88)] = 2256,
  [SMALL_STATE(89)] = 2277,
  [SMALL_STATE(90)] = 2300,
  [SMALL_STATE(91)] = 2323,
  [SMALL_STATE(92)] = 2344,
  [SMALL_STATE(93)] = 2364,
  [SMALL_STATE(94)] = 2376,
  [SMALL_STATE(95)] = 2388,
  [SMALL_STATE(96)] = 2400,
  [SMALL_STATE(97)] = 2412,
  [SMALL_STATE(98)] = 2422,
  [SMALL_STATE(99)] = 2432,
  [SMALL_STATE(100)] = 2452,
  [SMALL_STATE(101)] = 2462,
  [SMALL_STATE(102)] = 2472,
  [SMALL_STATE(103)] = 2482,
  [SMALL_STATE(104)] = 2502,
  [SMALL_STATE(105)] = 2522,
  [SMALL_STATE(106)] = 2534,
  [SMALL_STATE(107)] = 2544,
  [SMALL_STATE(108)] = 2554,
  [SMALL_STATE(109)] = 2564,
  [SMALL_STATE(110)] = 2574,
  [SMALL_STATE(111)] = 2584,
  [SMALL_STATE(112)] = 2596,
  [SMALL_STATE(113)] = 2608,
  [SMALL_STATE(114)] = 2620,
  [SMALL_STATE(115)] = 2632,
  [SMALL_STATE(116)] = 2647,
  [SMALL_STATE(117)] = 2662,
  [SMALL_STATE(118)] = 2677,
  [SMALL_STATE(119)] = 2688,
  [SMALL_STATE(120)] = 2699,
  [SMALL_STATE(121)] = 2710,
  [SMALL_STATE(122)] = 2721,
  [SMALL_STATE(123)] = 2736,
  [SMALL_STATE(124)] = 2747,
  [SMALL_STATE(125)] = 2758,
  [SMALL_STATE(126)] = 2769,
  [SMALL_STATE(127)] = 2780,
  [SMALL_STATE(128)] = 2794,
  [SMALL_STATE(129)] = 2808,
  [SMALL_STATE(130)] = 2822,
  [SMALL_STATE(131)] = 2834,
  [SMALL_STATE(132)] = 2846,
  [SMALL_STATE(133)] = 2860,
  [SMALL_STATE(134)] = 2868,
  [SMALL_STATE(135)] = 2882,
  [SMALL_STATE(136)] = 2896,
  [SMALL_STATE(137)] = 2904,
  [SMALL_STATE(138)] = 2918,
  [SMALL_STATE(139)] = 2932,
  [SMALL_STATE(140)] = 2943,
  [SMALL_STATE(141)] = 2954,
  [SMALL_STATE(142)] = 2965,
  [SMALL_STATE(143)] = 2976,
  [SMALL_STATE(144)] = 2987,
  [SMALL_STATE(145)] = 2998,
  [SMALL_STATE(146)] = 3009,
  [SMALL_STATE(147)] = 3020,
  [SMALL_STATE(148)] = 3027,
  [SMALL_STATE(149)] = 3034,
  [SMALL_STATE(150)] = 3041,
  [SMALL_STATE(151)] = 3048,
  [SMALL_STATE(152)] = 3055,
  [SMALL_STATE(153)] = 3062,
  [SMALL_STATE(154)] = 3069,
  [SMALL_STATE(155)] = 3076,
  [SMALL_STATE(156)] = 3083,
  [SMALL_STATE(157)] = 3090,
  [SMALL_STATE(158)] = 3097,
  [SMALL_STATE(159)] = 3104,
  [SMALL_STATE(160)] = 3111,
  [SMALL_STATE(161)] = 3118,
  [SMALL_STATE(162)] = 3125,
  [SMALL_STATE(163)] = 3132,
  [SMALL_STATE(164)] = 3139,
  [SMALL_STATE(165)] = 3143,
  [SMALL_STATE(166)] = 3147,
  [SMALL_STATE(167)] = 3151,
  [SMALL_STATE(168)] = 3155,
  [SMALL_STATE(169)] = 3159,
  [SMALL_STATE(170)] = 3163,
  [SMALL_STATE(171)] = 3167,
  [SMALL_STATE(172)] = 3171,
  [SMALL_STATE(173)] = 3175,
  [SMALL_STATE(174)] = 3179,
  [SMALL_STATE(175)] = 3183,
  [SMALL_STATE(176)] = 3187,
  [SMALL_STATE(177)] = 3191,
  [SMALL_STATE(178)] = 3195,
  [SMALL_STATE(179)] = 3199,
  [SMALL_STATE(180)] = 3203,
  [SMALL_STATE(181)] = 3207,
  [SMALL_STATE(182)] = 3211,
  [SMALL_STATE(183)] = 3215,
  [SMALL_STATE(184)] = 3219,
  [SMALL_STATE(185)] = 3223,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_signable, 1),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_signable, 1),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2), SHIFT_REPEAT(90),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2), SHIFT_REPEAT(104),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2), SHIFT_REPEAT(3),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2), SHIFT_REPEAT(13),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__number_signable_repeat1, 2),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_signable, 3),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_signable, 3),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_unsignable, 2),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_unsignable, 2),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro, 2),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro, 2),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_repeat1, 2),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_repeat1, 2), SHIFT_REPEAT(86),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_repeat1, 2), SHIFT_REPEAT(99),
  [95] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__macro_repeat1, 2), SHIFT_REPEAT(17),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_repeat1, 2),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_unsigned, 1),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__term_unsigned, 1),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__labels, 1),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__labels, 1),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__labels, 2),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__labels, 2),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__labels_repeat1, 2),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__labels_repeat1, 2),
  [116] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__labels_repeat1, 2), SHIFT_REPEAT(49),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 1),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2),
  [127] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(24),
  [130] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(24),
  [133] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(84),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(103),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(4),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 3),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 3),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__labels_repeat1, 1),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__labels_repeat1, 1),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 4),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 4),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [162] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [176] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [188] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inlineRoll, 3),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inlineRoll, 3),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 2),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 3),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 3),
  [210] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(41),
  [213] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(89),
  [216] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(92),
  [219] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(41),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5, .production_id = 6),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5, .production_id = 6),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 1),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [236] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5, .production_id = 6),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5, .production_id = 6),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 6),
  [244] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 6),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [248] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__operator_multiplication, 1),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__operator_multiplication, 1),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [258] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [262] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__labels_repeat1, 2), SHIFT_REPEAT(53),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function, 2),
  [269] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function, 2),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized, 1),
  [273] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesized, 1),
  [275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__operator_summation, 1),
  [277] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__operator_summation, 1),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 3, .production_id = 7),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__parenthesized, 3),
  [285] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__parenthesized, 3),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 2, .production_id = 5),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_unsigned, 2),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_first, 1, .production_id = 3),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_first, 1),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_first, 2, .production_id = 4),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 2),
  [301] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 2), SHIFT_REPEAT(51),
  [304] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 2), SHIFT_REPEAT(70),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 3),
  [309] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [311] = {.entry = {.count = 1, .reusable = false}}, SHIFT(168),
  [313] = {.entry = {.count = 1, .reusable = false}}, SHIFT(164),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 4),
  [319] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [321] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_first, 2),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_signed, 2),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_unsigned, 3),
  [327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_signed, 3),
  [329] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_first, 2, .production_id = 3),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro, 3),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_first, 3, .production_id = 4),
  [335] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [337] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_identifier, 1),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [341] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(116),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2),
  [346] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(116),
  [349] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [353] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(122),
  [356] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(122),
  [359] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [363] = {.entry = {.count = 1, .reusable = false}}, SHIFT(131),
  [365] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability_identifier, 1),
  [367] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_ability_identifier_repeat1, 2), SHIFT_REPEAT(131),
  [370] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ability_identifier_repeat1, 2),
  [372] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 4, .production_id = 7),
  [374] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 3, .production_id = 5),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [422] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [440] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 2),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [444] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [448] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 1),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [458] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [460] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [462] = {.entry = {.count = 1, .reusable = true}}, SHIFT(143),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [466] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [468] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [472] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [474] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [476] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [478] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [480] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_roll20_script(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
