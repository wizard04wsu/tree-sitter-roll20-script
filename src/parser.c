#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 179
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 59
#define ALIAS_COUNT 1
#define TOKEN_COUNT 28
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 6

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
  aux_sym__operator_multiplication_token1 = 21,
  sym__operator_summation_plus = 22,
  sym__operator_summation_minus = 23,
  anon_sym_LBRACK = 24,
  aux_sym_label_token1 = 25,
  aux_sym_label_token2 = 26,
  anon_sym_RBRACK = 27,
  sym_script = 28,
  sym__placeholder = 29,
  sym_character_token_identifier = 30,
  sym__attribute = 31,
  sym_attribute = 32,
  sym__attribute_of_character = 33,
  sym__attribute_of_character_maximum = 34,
  sym_attribute_identifier = 35,
  sym_ability = 36,
  sym_ability_identifier = 37,
  sym__macro = 38,
  sym_inlineRoll = 39,
  sym__IrPh = 40,
  sym_number = 41,
  sym__number_signable = 42,
  sym__number_unsignable = 43,
  sym_formula = 44,
  sym__term_first = 45,
  sym__term = 46,
  sym__operator_multiplication = 47,
  sym__operator_summation = 48,
  sym_label = 49,
  sym__labels = 50,
  aux_sym_script_repeat1 = 51,
  aux_sym_attribute_identifier_repeat1 = 52,
  aux_sym_ability_identifier_repeat1 = 53,
  aux_sym__macro_repeat1 = 54,
  aux_sym__number_signable_repeat1 = 55,
  aux_sym_formula_repeat1 = 56,
  aux_sym_label_repeat1 = 57,
  aux_sym__labels_repeat1 = 58,
  alias_sym_character_identifier = 59,
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
  [sym__term] = "term",
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
  [sym__term] = sym__term_first,
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
  [sym__term] = {
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
    [1] = alias_sym_character_identifier,
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
      if (eof) ADVANCE(29);
      if (lookahead == '\n') ADVANCE(100);
      if (lookahead == '\r') ADVANCE(31);
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '%') ADVANCE(34);
      if (lookahead == '&') ADVANCE(32);
      if (lookahead == '.') ADVANCE(104);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '[') ADVANCE(113);
      if (lookahead == ']') ADVANCE(123);
      if (lookahead == '|') ADVANCE(48);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(30);
      if (lookahead != 0) ADVANCE(30);
      END_STATE();
    case 1:
      if (lookahead == '\t') ADVANCE(36);
      if (lookahead == '\n') ADVANCE(38);
      if (lookahead == '\r') ADVANCE(37);
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == '%') ADVANCE(108);
      if (lookahead == '*') ADVANCE(98);
      if (lookahead == '+') ADVANCE(94);
      if (lookahead == '-') ADVANCE(95);
      if (lookahead == '/') ADVANCE(99);
      if (lookahead == '@') ADVANCE(24);
      if (lookahead == '[') ADVANCE(113);
      if (lookahead == ']') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '&' &&
          lookahead != '(' &&
          lookahead != ')' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(99);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '%') ADVANCE(108);
      if (lookahead == '*') ADVANCE(107);
      if (lookahead == '+') ADVANCE(110);
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == '.') ADVANCE(104);
      if (lookahead == '/') ADVANCE(106);
      if (lookahead == '@') ADVANCE(24);
      if (lookahead == '[') ADVANCE(114);
      if (lookahead == ']') ADVANCE(19);
      if (lookahead == '|') ADVANCE(21);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(103);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '%') ADVANCE(121);
      if (lookahead == '&') ADVANCE(120);
      if (lookahead == '@') ADVANCE(122);
      if (lookahead == ']') ADVANCE(123);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(119);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '%') ADVANCE(117);
      if (lookahead == '&') ADVANCE(116);
      if (lookahead == '@') ADVANCE(118);
      if (lookahead == ']') ADVANCE(123);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '[') ADVANCE(115);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '%') ADVANCE(23);
      if (lookahead == '.') ADVANCE(104);
      if (lookahead == '@') ADVANCE(24);
      if (lookahead == '[') ADVANCE(114);
      if (lookahead == '|') ADVANCE(48);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(105);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(103);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '&') ADVANCE(50);
      if (lookahead == 's') ADVANCE(55);
      if (lookahead == 't') ADVANCE(52);
      if (lookahead == '{') ADVANCE(64);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(67);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '&') ADVANCE(50);
      if (lookahead == '{') ADVANCE(64);
      if (lookahead == '|') ADVANCE(48);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(67);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(66);
      END_STATE();
    case 8:
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '&') ADVANCE(50);
      if (lookahead == '{') ADVANCE(64);
      if (lookahead == '|') ADVANCE(21);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(67);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(66);
      END_STATE();
    case 9:
      if (lookahead == '%') ADVANCE(23);
      if (lookahead == '@') ADVANCE(24);
      if (!aux_sym__macro_token1_character_set_1(lookahead)) ADVANCE(99);
      END_STATE();
    case 10:
      if (lookahead == '&') ADVANCE(70);
      if (lookahead == 's') ADVANCE(77);
      if (lookahead == 't') ADVANCE(74);
      if (lookahead == '{') ADVANCE(86);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(91);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 11:
      if (lookahead == '&') ADVANCE(70);
      if (lookahead == '{') ADVANCE(86);
      if (lookahead == '|') ADVANCE(48);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(91);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(90);
      END_STATE();
    case 12:
      if (lookahead == '+') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == '+') ADVANCE(112);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      END_STATE();
    case 15:
      if (lookahead == '-') ADVANCE(109);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(15);
      END_STATE();
    case 16:
      if (lookahead == ';') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == ';') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(17);
      END_STATE();
    case 18:
      if (lookahead == ';') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 19:
      if (lookahead == ']') ADVANCE(102);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(22);
      END_STATE();
    case 21:
      if (lookahead == 'm') ADVANCE(20);
      END_STATE();
    case 22:
      if (lookahead == 'x') ADVANCE(25);
      END_STATE();
    case 23:
      if (lookahead == '{') ADVANCE(69);
      END_STATE();
    case 24:
      if (lookahead == '{') ADVANCE(46);
      END_STATE();
    case 25:
      if (lookahead == '}') ADVANCE(49);
      END_STATE();
    case 26:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(16);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(17);
      END_STATE();
    case 28:
      if (eof) ADVANCE(29);
      if (lookahead == '#') ADVANCE(93);
      if (lookahead == '%') ADVANCE(34);
      if (lookahead == '&') ADVANCE(32);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '[') ADVANCE(33);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(30);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_script_token1);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '\n') ADVANCE(100);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '#') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '[') ADVANCE(101);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '{') ADVANCE(69);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '{') ADVANCE(46);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__wsp);
      if (lookahead == '\t') ADVANCE(36);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(38);
      if (lookahead != 0 &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '@' &&
          lookahead != '[' &&
          lookahead != ']' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(99);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym__wsp);
      if (lookahead == '\n') ADVANCE(38);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(38);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym__wsp);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_htmlEntity);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_htmlEntity);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_htmlEntity);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_PIPEmax_RBRACE);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '#') ADVANCE(26);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == ';') ADVANCE(40);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'a') ADVANCE(61);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'c') ADVANCE(63);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'd') ADVANCE(44);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(60);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(53);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(54);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(62);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'g') ADVANCE(58);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'l') ADVANCE(56);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'r') ADVANCE(59);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 't') ADVANCE(42);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 't') ADVANCE(57);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(64);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(67);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(67);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(64);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_PERCENT_LBRACE);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '#') ADVANCE(88);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == ';') ADVANCE(41);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == ';') ADVANCE(41);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == ';') ADVANCE(41);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(73);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'a') ADVANCE(83);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'c') ADVANCE(85);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'd') ADVANCE(45);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(82);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(75);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(76);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(84);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'g') ADVANCE(80);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'l') ADVANCE(78);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'r') ADVANCE(81);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 't') ADVANCE(43);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 't') ADVANCE(79);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(86);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(91);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(90);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(91);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(86);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(92);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_hash);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (lookahead == '\t') ADVANCE(94);
      if (lookahead == '-') ADVANCE(97);
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
          (lookahead < '{' || '}' < lookahead)) ADVANCE(99);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (lookahead == '\t') ADVANCE(95);
      if (lookahead == '+') ADVANCE(96);
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
          (lookahead < '{' || '}' < lookahead)) ADVANCE(99);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (lookahead == '\t') ADVANCE(96);
      if (lookahead == '-') ADVANCE(95);
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
          (lookahead < '{' || '}' < lookahead)) ADVANCE(99);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (lookahead == '\t') ADVANCE(97);
      if (lookahead == '+') ADVANCE(94);
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
          (lookahead < '{' || '}' < lookahead)) ADVANCE(99);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (lookahead == '*') ADVANCE(99);
      if (!aux_sym__macro_token1_character_set_2(lookahead)) ADVANCE(99);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym__macro_token1);
      if (!aux_sym__macro_token1_character_set_2(lookahead)) ADVANCE(99);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym__macro_token2);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym__number_signable_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(103);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym__term_first_token1);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym__operator_multiplication_token1);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym__operator_multiplication_token1);
      if (lookahead == '*') ADVANCE(106);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym__operator_multiplication_token1);
      if (lookahead == '{') ADVANCE(69);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym__operator_summation_plus);
      if (lookahead == '+') ADVANCE(110);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym__operator_summation_plus);
      if (lookahead == '-') ADVANCE(109);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(15);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym__operator_summation_minus);
      if (lookahead == '+') ADVANCE(112);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(13);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym__operator_summation_minus);
      if (lookahead == '-') ADVANCE(111);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead == '[') ADVANCE(101);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(aux_sym_label_token1);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(aux_sym_label_token1);
      if (lookahead == '#') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(aux_sym_label_token1);
      if (lookahead == '{') ADVANCE(69);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(aux_sym_label_token1);
      if (lookahead == '{') ADVANCE(46);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(aux_sym_label_token2);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(aux_sym_label_token2);
      if (lookahead == '#') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(aux_sym_label_token2);
      if (lookahead == '{') ADVANCE(69);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(aux_sym_label_token2);
      if (lookahead == '{') ADVANCE(46);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 28},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 2},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 5},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 28},
  [20] = {.lex_state = 28},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 3},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 3},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 3},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 2},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 2},
  [42] = {.lex_state = 2},
  [43] = {.lex_state = 2},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 4},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 2},
  [51] = {.lex_state = 1},
  [52] = {.lex_state = 9},
  [53] = {.lex_state = 1},
  [54] = {.lex_state = 5},
  [55] = {.lex_state = 1},
  [56] = {.lex_state = 5},
  [57] = {.lex_state = 1},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 1},
  [60] = {.lex_state = 1},
  [61] = {.lex_state = 1},
  [62] = {.lex_state = 5},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 5},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 5},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 5},
  [69] = {.lex_state = 5},
  [70] = {.lex_state = 5},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 2},
  [74] = {.lex_state = 5},
  [75] = {.lex_state = 2},
  [76] = {.lex_state = 6},
  [77] = {.lex_state = 2},
  [78] = {.lex_state = 6},
  [79] = {.lex_state = 6},
  [80] = {.lex_state = 6},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 28},
  [83] = {.lex_state = 28},
  [84] = {.lex_state = 10},
  [85] = {.lex_state = 10},
  [86] = {.lex_state = 10},
  [87] = {.lex_state = 28},
  [88] = {.lex_state = 28},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 10},
  [91] = {.lex_state = 28},
  [92] = {.lex_state = 28},
  [93] = {.lex_state = 28},
  [94] = {.lex_state = 28},
  [95] = {.lex_state = 28},
  [96] = {.lex_state = 2},
  [97] = {.lex_state = 2},
  [98] = {.lex_state = 2},
  [99] = {.lex_state = 2},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 2},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 3},
  [104] = {.lex_state = 8},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 7},
  [109] = {.lex_state = 3},
  [110] = {.lex_state = 8},
  [111] = {.lex_state = 3},
  [112] = {.lex_state = 3},
  [113] = {.lex_state = 3},
  [114] = {.lex_state = 2},
  [115] = {.lex_state = 3},
  [116] = {.lex_state = 7},
  [117] = {.lex_state = 3},
  [118] = {.lex_state = 3},
  [119] = {.lex_state = 2},
  [120] = {.lex_state = 8},
  [121] = {.lex_state = 11},
  [122] = {.lex_state = 8},
  [123] = {.lex_state = 8},
  [124] = {.lex_state = 8},
  [125] = {.lex_state = 8},
  [126] = {.lex_state = 8},
  [127] = {.lex_state = 8},
  [128] = {.lex_state = 11},
  [129] = {.lex_state = 8},
  [130] = {.lex_state = 11},
  [131] = {.lex_state = 11},
  [132] = {.lex_state = 2},
  [133] = {.lex_state = 11},
  [134] = {.lex_state = 11},
  [135] = {.lex_state = 11},
  [136] = {.lex_state = 11},
  [137] = {.lex_state = 2},
  [138] = {.lex_state = 11},
  [139] = {.lex_state = 2},
  [140] = {.lex_state = 11},
  [141] = {.lex_state = 2},
  [142] = {.lex_state = 2},
  [143] = {.lex_state = 5},
  [144] = {.lex_state = 2},
  [145] = {.lex_state = 2},
  [146] = {.lex_state = 2},
  [147] = {.lex_state = 5},
  [148] = {.lex_state = 5},
  [149] = {.lex_state = 5},
  [150] = {.lex_state = 2},
  [151] = {.lex_state = 2},
  [152] = {.lex_state = 5},
  [153] = {.lex_state = 5},
  [154] = {.lex_state = 2},
  [155] = {.lex_state = 2},
  [156] = {.lex_state = 5},
  [157] = {.lex_state = 5},
  [158] = {.lex_state = 5},
  [159] = {.lex_state = 2},
  [160] = {.lex_state = 2},
  [161] = {.lex_state = 2},
  [162] = {.lex_state = 5},
  [163] = {.lex_state = 2},
  [164] = {.lex_state = 2},
  [165] = {.lex_state = 5},
  [166] = {.lex_state = 5},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 2},
  [169] = {.lex_state = 2},
  [170] = {.lex_state = 2},
  [171] = {.lex_state = 2},
  [172] = {.lex_state = 2},
  [173] = {.lex_state = 5},
  [174] = {.lex_state = 5},
  [175] = {.lex_state = 5},
  [176] = {.lex_state = 5},
  [177] = {.lex_state = 5},
  [178] = {.lex_state = 5},
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
    [anon_sym_LBRACK] = ACTIONS(1),
    [aux_sym_label_token1] = ACTIONS(1),
    [aux_sym_label_token2] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
  },
  [1] = {
    [sym_script] = STATE(167),
    [sym__placeholder] = STATE(19),
    [sym__attribute] = STATE(19),
    [sym_attribute] = STATE(19),
    [sym__attribute_of_character] = STATE(19),
    [sym__attribute_of_character_maximum] = STATE(19),
    [sym_ability] = STATE(19),
    [sym_inlineRoll] = STATE(19),
    [sym__IrPh] = STATE(19),
    [aux_sym_script_repeat1] = STATE(19),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_script_token1] = ACTIONS(5),
    [sym_htmlEntity] = ACTIONS(7),
    [anon_sym_AT_LBRACE] = ACTIONS(9),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(11),
    [sym_hash] = ACTIONS(7),
    [anon_sym_LBRACK_LBRACK] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 18,
    ACTIONS(15), 1,
      sym__wsp,
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
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    STATE(5), 1,
      sym__operator_summation,
    STATE(8), 1,
      sym__labels,
    STATE(28), 1,
      aux_sym__labels_repeat1,
    STATE(35), 1,
      sym_label,
    STATE(67), 1,
      sym__term,
    STATE(73), 1,
      sym_number,
    STATE(105), 1,
      sym__macro,
    ACTIONS(29), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(100), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [65] = 17,
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
    ACTIONS(33), 1,
      sym__wsp,
    ACTIONS(35), 1,
      aux_sym__term_first_token1,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    STATE(16), 1,
      sym__labels,
    STATE(41), 1,
      sym__term_first,
    STATE(64), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    STATE(119), 1,
      sym__macro,
    STATE(170), 1,
      sym_formula,
    STATE(77), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [126] = 17,
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
    ACTIONS(33), 1,
      sym__wsp,
    ACTIONS(35), 1,
      aux_sym__term_first_token1,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    STATE(16), 1,
      sym__labels,
    STATE(41), 1,
      sym__term_first,
    STATE(64), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    STATE(119), 1,
      sym__macro,
    STATE(164), 1,
      sym_formula,
    STATE(77), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [187] = 16,
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
    ACTIONS(33), 1,
      sym__wsp,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    STATE(12), 1,
      sym__labels,
    STATE(64), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    STATE(72), 1,
      sym__term,
    STATE(73), 1,
      sym_number,
    STATE(105), 1,
      sym__macro,
    STATE(100), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [245] = 16,
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
    ACTIONS(33), 1,
      sym__wsp,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    STATE(14), 1,
      sym__labels,
    STATE(64), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    STATE(71), 1,
      sym__term,
    STATE(73), 1,
      sym_number,
    STATE(105), 1,
      sym__macro,
    STATE(100), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [303] = 16,
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
    ACTIONS(33), 1,
      sym__wsp,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    STATE(11), 1,
      sym__labels,
    STATE(64), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    STATE(67), 1,
      sym__term,
    STATE(73), 1,
      sym_number,
    STATE(105), 1,
      sym__macro,
    STATE(100), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [361] = 13,
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
    STATE(6), 1,
      sym__operator_summation,
    STATE(72), 1,
      sym__term,
    STATE(73), 1,
      sym_number,
    STATE(105), 1,
      sym__macro,
    ACTIONS(29), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(100), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [411] = 7,
    ACTIONS(41), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(44), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(47), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(50), 1,
      aux_sym__number_signable_token1,
    ACTIONS(53), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(39), 6,
      sym__wsp,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(9), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [447] = 8,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(57), 1,
      aux_sym__number_signable_token1,
    ACTIONS(59), 1,
      anon_sym_DOT,
    ACTIONS(61), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(55), 5,
      sym__wsp,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(9), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [485] = 11,
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
    STATE(72), 1,
      sym__term,
    STATE(73), 1,
      sym_number,
    STATE(105), 1,
      sym__macro,
    STATE(100), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [528] = 11,
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
    STATE(71), 1,
      sym__term,
    STATE(73), 1,
      sym_number,
    STATE(105), 1,
      sym__macro,
    STATE(100), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [571] = 7,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(57), 1,
      aux_sym__number_signable_token1,
    ACTIONS(65), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(63), 5,
      sym__wsp,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(9), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [606] = 11,
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
    STATE(65), 1,
      sym__term,
    STATE(73), 1,
      sym_number,
    STATE(105), 1,
      sym__macro,
    STATE(100), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [649] = 7,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(57), 1,
      aux_sym__number_signable_token1,
    ACTIONS(69), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(67), 5,
      sym__wsp,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(9), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [684] = 11,
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
    ACTIONS(35), 1,
      aux_sym__term_first_token1,
    STATE(33), 1,
      sym__term_first,
    STATE(119), 1,
      sym__macro,
    STATE(77), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [727] = 7,
    ACTIONS(73), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(75), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(77), 1,
      aux_sym__macro_token1,
    ACTIONS(71), 2,
      sym__wsp,
      aux_sym__macro_token2,
    ACTIONS(79), 2,
      anon_sym_RBRACK_RBRACK,
      anon_sym_LBRACK,
    ACTIONS(81), 3,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(18), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_repeat1,
  [759] = 6,
    ACTIONS(85), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(88), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(91), 1,
      aux_sym__macro_token1,
    ACTIONS(94), 2,
      anon_sym_RBRACK_RBRACK,
      anon_sym_LBRACK,
    ACTIONS(83), 5,
      sym__wsp,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
    STATE(18), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_repeat1,
  [789] = 7,
    ACTIONS(9), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(11), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(13), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(96), 1,
      ts_builtin_sym_end,
    ACTIONS(98), 1,
      aux_sym_script_token1,
    ACTIONS(100), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(20), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym_script_repeat1,
  [820] = 7,
    ACTIONS(102), 1,
      ts_builtin_sym_end,
    ACTIONS(104), 1,
      aux_sym_script_token1,
    ACTIONS(110), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(113), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(116), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(107), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(20), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym_script_repeat1,
  [851] = 6,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    STATE(75), 1,
      sym__number_signable,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [878] = 5,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(121), 1,
      aux_sym__operator_multiplication_token1,
    STATE(30), 1,
      aux_sym__labels_repeat1,
    STATE(35), 1,
      sym_label,
    ACTIONS(119), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [902] = 6,
    ACTIONS(125), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(127), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(129), 1,
      aux_sym_label_token2,
    ACTIONS(131), 1,
      anon_sym_RBRACK,
    ACTIONS(123), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(29), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_label_repeat1,
  [928] = 6,
    ACTIONS(136), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(139), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(142), 1,
      aux_sym_label_token2,
    ACTIONS(145), 1,
      anon_sym_RBRACK,
    ACTIONS(133), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(24), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_label_repeat1,
  [954] = 6,
    ACTIONS(125), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(127), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(149), 1,
      aux_sym_label_token2,
    ACTIONS(151), 1,
      anon_sym_RBRACK,
    ACTIONS(147), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(24), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_label_repeat1,
  [980] = 5,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(155), 1,
      aux_sym__operator_multiplication_token1,
    STATE(22), 1,
      aux_sym__labels_repeat1,
    STATE(35), 1,
      sym_label,
    ACTIONS(153), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1004] = 6,
    ACTIONS(125), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(127), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(159), 1,
      aux_sym_label_token2,
    ACTIONS(161), 1,
      anon_sym_RBRACK,
    ACTIONS(157), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(25), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_label_repeat1,
  [1030] = 5,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(155), 1,
      aux_sym__operator_multiplication_token1,
    STATE(30), 1,
      aux_sym__labels_repeat1,
    STATE(35), 1,
      sym_label,
    ACTIONS(153), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1054] = 6,
    ACTIONS(125), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(127), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(149), 1,
      aux_sym_label_token2,
    ACTIONS(163), 1,
      anon_sym_RBRACK,
    ACTIONS(147), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(24), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_label_repeat1,
  [1080] = 5,
    ACTIONS(167), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(169), 1,
      anon_sym_LBRACK,
    STATE(30), 1,
      aux_sym__labels_repeat1,
    STATE(35), 1,
      sym_label,
    ACTIONS(165), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1104] = 5,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(172), 1,
      aux_sym__number_signable_token1,
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
  [1128] = 5,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(174), 1,
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
  [1152] = 11,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(176), 1,
      anon_sym_RBRACK_RBRACK,
    ACTIONS(178), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(180), 1,
      anon_sym_LBRACK,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(28), 1,
      aux_sym__labels_repeat1,
    STATE(35), 1,
      sym_label,
    STATE(97), 1,
      sym__labels,
    STATE(99), 1,
      aux_sym_formula_repeat1,
    ACTIONS(29), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1187] = 6,
    ACTIONS(125), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(127), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(184), 1,
      aux_sym_label_token1,
    ACTIONS(186), 1,
      anon_sym_RBRACK,
    ACTIONS(182), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(27), 6,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
  [1212] = 3,
    ACTIONS(188), 1,
      sym__wsp,
    ACTIONS(192), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(190), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1231] = 2,
    ACTIONS(196), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(194), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1248] = 2,
    ACTIONS(200), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(198), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1265] = 2,
    ACTIONS(204), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(202), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1282] = 2,
    ACTIONS(208), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(206), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1299] = 2,
    ACTIONS(212), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(210), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1316] = 11,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(178), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(180), 1,
      anon_sym_LBRACK,
    ACTIONS(214), 1,
      anon_sym_RBRACK_RBRACK,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(28), 1,
      aux_sym__labels_repeat1,
    STATE(35), 1,
      sym_label,
    STATE(96), 1,
      aux_sym_formula_repeat1,
    STATE(101), 1,
      sym__labels,
    ACTIONS(29), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1351] = 2,
    ACTIONS(218), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(216), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1368] = 2,
    ACTIONS(222), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(220), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1385] = 2,
    ACTIONS(226), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(224), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1402] = 2,
    ACTIONS(230), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(228), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1419] = 2,
    ACTIONS(234), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(232), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1436] = 6,
    ACTIONS(125), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(127), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(238), 1,
      aux_sym_label_token1,
    ACTIONS(240), 1,
      anon_sym_RBRACK,
    ACTIONS(236), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(23), 6,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
  [1461] = 2,
    ACTIONS(244), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(242), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1478] = 2,
    ACTIONS(248), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(246), 10,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1495] = 2,
    ACTIONS(167), 2,
      aux_sym__operator_multiplication_token1,
      anon_sym_LBRACK,
    ACTIONS(165), 9,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1511] = 2,
    ACTIONS(198), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_LBRACK,
    ACTIONS(200), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1526] = 4,
    ACTIONS(73), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(75), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(250), 1,
      aux_sym__macro_token1,
    STATE(17), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_repeat1,
  [1545] = 2,
    ACTIONS(210), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_LBRACK,
    ACTIONS(212), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1560] = 4,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    STATE(62), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    ACTIONS(153), 7,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
  [1579] = 2,
    ACTIONS(206), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_LBRACK,
    ACTIONS(208), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1594] = 4,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    STATE(56), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    ACTIONS(165), 7,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
  [1613] = 2,
    ACTIONS(246), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_LBRACK,
    ACTIONS(248), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1628] = 2,
    ACTIONS(257), 1,
      anon_sym_LBRACK,
    ACTIONS(255), 9,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1643] = 2,
    ACTIONS(224), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_LBRACK,
    ACTIONS(226), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1658] = 2,
    ACTIONS(216), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_LBRACK,
    ACTIONS(218), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1673] = 2,
    ACTIONS(202), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_LBRACK,
    ACTIONS(204), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1688] = 4,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    STATE(56), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    ACTIONS(119), 7,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
  [1707] = 2,
    ACTIONS(220), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_RBRACK_RBRACK,
      anon_sym_LBRACK,
    ACTIONS(222), 6,
      sym__wsp,
      aux_sym__macro_token1,
      aux_sym__macro_token2,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1722] = 4,
    ACTIONS(37), 1,
      anon_sym_LBRACK,
    STATE(56), 1,
      aux_sym__labels_repeat1,
    STATE(66), 1,
      sym_label,
    ACTIONS(153), 7,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
  [1741] = 6,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(180), 1,
      anon_sym_LBRACK,
    STATE(28), 1,
      aux_sym__labels_repeat1,
    STATE(35), 1,
      sym_label,
    STATE(141), 1,
      sym__labels,
    ACTIONS(259), 4,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1763] = 3,
    ACTIONS(192), 1,
      anon_sym_LBRACK,
    ACTIONS(261), 1,
      sym__wsp,
    ACTIONS(190), 7,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
  [1779] = 6,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(180), 1,
      anon_sym_LBRACK,
    STATE(28), 1,
      aux_sym__labels_repeat1,
    STATE(35), 1,
      sym_label,
    STATE(139), 1,
      sym__labels,
    ACTIONS(263), 4,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1801] = 2,
    ACTIONS(244), 1,
      anon_sym_LBRACK,
    ACTIONS(242), 8,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
  [1815] = 2,
    ACTIONS(230), 1,
      anon_sym_LBRACK,
    ACTIONS(228), 8,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
  [1829] = 2,
    ACTIONS(196), 1,
      anon_sym_LBRACK,
    ACTIONS(194), 8,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
  [1843] = 6,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(180), 1,
      anon_sym_LBRACK,
    STATE(28), 1,
      aux_sym__labels_repeat1,
    STATE(35), 1,
      sym_label,
    STATE(132), 1,
      sym__labels,
    ACTIONS(265), 4,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1865] = 6,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(180), 1,
      anon_sym_LBRACK,
    STATE(28), 1,
      aux_sym__labels_repeat1,
    STATE(35), 1,
      sym_label,
    STATE(137), 1,
      sym__labels,
    ACTIONS(267), 4,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [1887] = 3,
    ACTIONS(21), 1,
      sym_hash,
    STATE(114), 1,
      sym__macro,
    ACTIONS(269), 6,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [1902] = 2,
    ACTIONS(167), 1,
      anon_sym_LBRACK,
    ACTIONS(165), 7,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
      aux_sym__term_first_token1,
  [1915] = 3,
    ACTIONS(21), 1,
      sym_hash,
    STATE(106), 1,
      sym__macro,
    ACTIONS(271), 6,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [1930] = 7,
    ACTIONS(275), 1,
      anon_sym_target,
    ACTIONS(277), 1,
      anon_sym_selected,
    ACTIONS(279), 1,
      sym_hash,
    STATE(108), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(143), 1,
      sym_attribute_identifier,
    STATE(166), 1,
      sym_character_token_identifier,
    ACTIONS(273), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1953] = 3,
    ACTIONS(21), 1,
      sym_hash,
    STATE(102), 1,
      sym__macro,
    ACTIONS(281), 6,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [1968] = 7,
    ACTIONS(275), 1,
      anon_sym_target,
    ACTIONS(277), 1,
      anon_sym_selected,
    ACTIONS(279), 1,
      sym_hash,
    STATE(108), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(152), 1,
      sym_attribute_identifier,
    STATE(173), 1,
      sym_character_token_identifier,
    ACTIONS(273), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1991] = 7,
    ACTIONS(275), 1,
      anon_sym_target,
    ACTIONS(277), 1,
      anon_sym_selected,
    ACTIONS(279), 1,
      sym_hash,
    STATE(108), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(157), 1,
      sym_attribute_identifier,
    STATE(175), 1,
      sym_character_token_identifier,
    ACTIONS(273), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2014] = 7,
    ACTIONS(275), 1,
      anon_sym_target,
    ACTIONS(277), 1,
      anon_sym_selected,
    ACTIONS(279), 1,
      sym_hash,
    STATE(108), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(148), 1,
      sym_attribute_identifier,
    STATE(177), 1,
      sym_character_token_identifier,
    ACTIONS(273), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2037] = 2,
    ACTIONS(285), 1,
      anon_sym_LBRACK,
    ACTIONS(283), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [2050] = 2,
    ACTIONS(234), 1,
      aux_sym_script_token1,
    ACTIONS(232), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2062] = 2,
    ACTIONS(200), 1,
      aux_sym_script_token1,
    ACTIONS(198), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2074] = 6,
    ACTIONS(275), 1,
      anon_sym_target,
    ACTIONS(277), 1,
      anon_sym_selected,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(153), 1,
      sym_ability_identifier,
    STATE(174), 1,
      sym_character_token_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2094] = 6,
    ACTIONS(275), 1,
      anon_sym_target,
    ACTIONS(277), 1,
      anon_sym_selected,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(156), 1,
      sym_ability_identifier,
    STATE(176), 1,
      sym_character_token_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2114] = 6,
    ACTIONS(275), 1,
      anon_sym_target,
    ACTIONS(277), 1,
      anon_sym_selected,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(147), 1,
      sym_ability_identifier,
    STATE(165), 1,
      sym_character_token_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2134] = 2,
    ACTIONS(204), 1,
      aux_sym_script_token1,
    ACTIONS(202), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2146] = 2,
    ACTIONS(208), 1,
      aux_sym_script_token1,
    ACTIONS(206), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2158] = 6,
    ACTIONS(178), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(289), 1,
      anon_sym_RBRACK_RBRACK,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(98), 1,
      aux_sym_formula_repeat1,
    ACTIONS(29), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2178] = 6,
    ACTIONS(275), 1,
      anon_sym_target,
    ACTIONS(277), 1,
      anon_sym_selected,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(149), 1,
      sym_ability_identifier,
    STATE(178), 1,
      sym_character_token_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2198] = 2,
    ACTIONS(212), 1,
      aux_sym_script_token1,
    ACTIONS(210), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2210] = 2,
    ACTIONS(226), 1,
      aux_sym_script_token1,
    ACTIONS(224), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2222] = 2,
    ACTIONS(218), 1,
      aux_sym_script_token1,
    ACTIONS(216), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2234] = 2,
    ACTIONS(248), 1,
      aux_sym_script_token1,
    ACTIONS(246), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2246] = 2,
    ACTIONS(222), 1,
      aux_sym_script_token1,
    ACTIONS(220), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [2258] = 6,
    ACTIONS(176), 1,
      anon_sym_RBRACK_RBRACK,
    ACTIONS(178), 1,
      aux_sym__operator_multiplication_token1,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(98), 1,
      aux_sym_formula_repeat1,
    ACTIONS(29), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2278] = 6,
    ACTIONS(178), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(291), 1,
      anon_sym_RBRACK_RBRACK,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(89), 1,
      aux_sym_formula_repeat1,
    ACTIONS(29), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2298] = 6,
    ACTIONS(263), 1,
      anon_sym_RBRACK_RBRACK,
    ACTIONS(293), 1,
      aux_sym__operator_multiplication_token1,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(98), 1,
      aux_sym_formula_repeat1,
    ACTIONS(296), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2318] = 6,
    ACTIONS(178), 1,
      aux_sym__operator_multiplication_token1,
    ACTIONS(291), 1,
      anon_sym_RBRACK_RBRACK,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(98), 1,
      aux_sym_formula_repeat1,
    ACTIONS(29), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2338] = 1,
    ACTIONS(299), 7,
      sym__wsp,
      sym_hash,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2348] = 6,
    ACTIONS(176), 1,
      anon_sym_RBRACK_RBRACK,
    ACTIONS(178), 1,
      aux_sym__operator_multiplication_token1,
    STATE(2), 1,
      sym__operator_multiplication,
    STATE(7), 1,
      sym__operator_summation,
    STATE(99), 1,
      aux_sym_formula_repeat1,
    ACTIONS(29), 2,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2368] = 1,
    ACTIONS(301), 6,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2377] = 2,
    ACTIONS(204), 1,
      aux_sym_label_token2,
    ACTIONS(202), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2388] = 4,
    ACTIONS(308), 1,
      sym_hash,
    STATE(104), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(303), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(306), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
  [2403] = 1,
    ACTIONS(269), 6,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2412] = 1,
    ACTIONS(311), 6,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2421] = 1,
    ACTIONS(313), 6,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2430] = 4,
    ACTIONS(319), 1,
      sym_hash,
    STATE(116), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(315), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(317), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [2445] = 2,
    ACTIONS(200), 1,
      aux_sym_label_token2,
    ACTIONS(198), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2456] = 4,
    ACTIONS(323), 1,
      sym_hash,
    STATE(104), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(317), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(321), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2471] = 2,
    ACTIONS(208), 1,
      aux_sym_label_token2,
    ACTIONS(206), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2482] = 2,
    ACTIONS(212), 1,
      aux_sym_label_token2,
    ACTIONS(210), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2493] = 2,
    ACTIONS(226), 1,
      aux_sym_label_token2,
    ACTIONS(224), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2504] = 1,
    ACTIONS(325), 6,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2513] = 2,
    ACTIONS(248), 1,
      aux_sym_label_token2,
    ACTIONS(246), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2524] = 4,
    ACTIONS(330), 1,
      sym_hash,
    STATE(116), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(306), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(327), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2539] = 2,
    ACTIONS(222), 1,
      aux_sym_label_token2,
    ACTIONS(220), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2550] = 2,
    ACTIONS(218), 1,
      aux_sym_label_token2,
    ACTIONS(216), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [2561] = 1,
    ACTIONS(333), 6,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
      anon_sym_LBRACK,
  [2570] = 4,
    ACTIONS(337), 1,
      sym_hash,
    STATE(110), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(151), 1,
      sym_attribute_identifier,
    ACTIONS(335), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2584] = 3,
    STATE(128), 1,
      aux_sym_ability_identifier_repeat1,
    ACTIONS(339), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    ACTIONS(341), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [2596] = 4,
    ACTIONS(337), 1,
      sym_hash,
    STATE(110), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(150), 1,
      sym_attribute_identifier,
    ACTIONS(335), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2610] = 4,
    ACTIONS(337), 1,
      sym_hash,
    STATE(110), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(155), 1,
      sym_attribute_identifier,
    ACTIONS(335), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2624] = 4,
    ACTIONS(337), 1,
      sym_hash,
    STATE(110), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(144), 1,
      sym_attribute_identifier,
    ACTIONS(335), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2638] = 4,
    ACTIONS(337), 1,
      sym_hash,
    STATE(110), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(145), 1,
      sym_attribute_identifier,
    ACTIONS(335), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2652] = 4,
    ACTIONS(337), 1,
      sym_hash,
    STATE(110), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(142), 1,
      sym_attribute_identifier,
    ACTIONS(335), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2666] = 4,
    ACTIONS(337), 1,
      sym_hash,
    STATE(110), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(154), 1,
      sym_attribute_identifier,
    ACTIONS(335), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2680] = 3,
    STATE(128), 1,
      aux_sym_ability_identifier_repeat1,
    ACTIONS(343), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    ACTIONS(346), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [2692] = 4,
    ACTIONS(337), 1,
      sym_hash,
    STATE(110), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(146), 1,
      sym_attribute_identifier,
    ACTIONS(335), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [2706] = 3,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(172), 1,
      sym_ability_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2717] = 3,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(163), 1,
      sym_ability_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2728] = 1,
    ACTIONS(259), 4,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2735] = 3,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(159), 1,
      sym_ability_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2746] = 3,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(160), 1,
      sym_ability_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2757] = 3,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(169), 1,
      sym_ability_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2768] = 3,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(168), 1,
      sym_ability_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2779] = 1,
    ACTIONS(265), 4,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2786] = 3,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(161), 1,
      sym_ability_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2797] = 1,
    ACTIONS(267), 4,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2804] = 3,
    STATE(121), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(171), 1,
      sym_ability_identifier,
    ACTIONS(287), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [2815] = 1,
    ACTIONS(348), 4,
      anon_sym_RBRACK_RBRACK,
      aux_sym__operator_multiplication_token1,
      sym__operator_summation_plus,
      sym__operator_summation_minus,
  [2822] = 2,
    ACTIONS(350), 1,
      anon_sym_RBRACE,
    ACTIONS(352), 1,
      anon_sym_PIPEmax_RBRACE,
  [2829] = 2,
    ACTIONS(354), 1,
      anon_sym_RBRACE,
    ACTIONS(356), 1,
      anon_sym_PIPE,
  [2836] = 2,
    ACTIONS(358), 1,
      anon_sym_RBRACE,
    ACTIONS(360), 1,
      anon_sym_PIPEmax_RBRACE,
  [2843] = 2,
    ACTIONS(362), 1,
      anon_sym_RBRACE,
    ACTIONS(364), 1,
      anon_sym_PIPEmax_RBRACE,
  [2850] = 2,
    ACTIONS(366), 1,
      anon_sym_RBRACE,
    ACTIONS(368), 1,
      anon_sym_PIPEmax_RBRACE,
  [2857] = 2,
    ACTIONS(370), 1,
      anon_sym_RBRACE,
    ACTIONS(372), 1,
      anon_sym_PIPE,
  [2864] = 2,
    ACTIONS(374), 1,
      anon_sym_RBRACE,
    ACTIONS(376), 1,
      anon_sym_PIPE,
  [2871] = 2,
    ACTIONS(378), 1,
      anon_sym_RBRACE,
    ACTIONS(380), 1,
      anon_sym_PIPE,
  [2878] = 2,
    ACTIONS(382), 1,
      anon_sym_RBRACE,
    ACTIONS(384), 1,
      anon_sym_PIPEmax_RBRACE,
  [2885] = 2,
    ACTIONS(386), 1,
      anon_sym_RBRACE,
    ACTIONS(388), 1,
      anon_sym_PIPEmax_RBRACE,
  [2892] = 2,
    ACTIONS(390), 1,
      anon_sym_RBRACE,
    ACTIONS(392), 1,
      anon_sym_PIPE,
  [2899] = 2,
    ACTIONS(394), 1,
      anon_sym_RBRACE,
    ACTIONS(396), 1,
      anon_sym_PIPE,
  [2906] = 2,
    ACTIONS(398), 1,
      anon_sym_RBRACE,
    ACTIONS(400), 1,
      anon_sym_PIPEmax_RBRACE,
  [2913] = 2,
    ACTIONS(402), 1,
      anon_sym_RBRACE,
    ACTIONS(404), 1,
      anon_sym_PIPEmax_RBRACE,
  [2920] = 2,
    ACTIONS(406), 1,
      anon_sym_RBRACE,
    ACTIONS(408), 1,
      anon_sym_PIPE,
  [2927] = 2,
    ACTIONS(410), 1,
      anon_sym_RBRACE,
    ACTIONS(412), 1,
      anon_sym_PIPE,
  [2934] = 1,
    ACTIONS(414), 1,
      anon_sym_PIPE,
  [2938] = 1,
    ACTIONS(416), 1,
      anon_sym_RBRACE,
  [2942] = 1,
    ACTIONS(418), 1,
      anon_sym_RBRACE,
  [2946] = 1,
    ACTIONS(420), 1,
      anon_sym_RBRACE,
  [2950] = 1,
    ACTIONS(422), 1,
      anon_sym_PIPE,
  [2954] = 1,
    ACTIONS(424), 1,
      anon_sym_RBRACE,
  [2958] = 1,
    ACTIONS(426), 1,
      anon_sym_RBRACK_RBRACK,
  [2962] = 1,
    ACTIONS(428), 1,
      anon_sym_PIPE,
  [2966] = 1,
    ACTIONS(430), 1,
      anon_sym_PIPE,
  [2970] = 1,
    ACTIONS(432), 1,
      ts_builtin_sym_end,
  [2974] = 1,
    ACTIONS(434), 1,
      anon_sym_RBRACE,
  [2978] = 1,
    ACTIONS(436), 1,
      anon_sym_RBRACE,
  [2982] = 1,
    ACTIONS(438), 1,
      anon_sym_RBRACK_RBRACK,
  [2986] = 1,
    ACTIONS(440), 1,
      anon_sym_RBRACE,
  [2990] = 1,
    ACTIONS(442), 1,
      anon_sym_RBRACE,
  [2994] = 1,
    ACTIONS(444), 1,
      anon_sym_PIPE,
  [2998] = 1,
    ACTIONS(446), 1,
      anon_sym_PIPE,
  [3002] = 1,
    ACTIONS(448), 1,
      anon_sym_PIPE,
  [3006] = 1,
    ACTIONS(450), 1,
      anon_sym_PIPE,
  [3010] = 1,
    ACTIONS(452), 1,
      anon_sym_PIPE,
  [3014] = 1,
    ACTIONS(454), 1,
      anon_sym_PIPE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 65,
  [SMALL_STATE(4)] = 126,
  [SMALL_STATE(5)] = 187,
  [SMALL_STATE(6)] = 245,
  [SMALL_STATE(7)] = 303,
  [SMALL_STATE(8)] = 361,
  [SMALL_STATE(9)] = 411,
  [SMALL_STATE(10)] = 447,
  [SMALL_STATE(11)] = 485,
  [SMALL_STATE(12)] = 528,
  [SMALL_STATE(13)] = 571,
  [SMALL_STATE(14)] = 606,
  [SMALL_STATE(15)] = 649,
  [SMALL_STATE(16)] = 684,
  [SMALL_STATE(17)] = 727,
  [SMALL_STATE(18)] = 759,
  [SMALL_STATE(19)] = 789,
  [SMALL_STATE(20)] = 820,
  [SMALL_STATE(21)] = 851,
  [SMALL_STATE(22)] = 878,
  [SMALL_STATE(23)] = 902,
  [SMALL_STATE(24)] = 928,
  [SMALL_STATE(25)] = 954,
  [SMALL_STATE(26)] = 980,
  [SMALL_STATE(27)] = 1004,
  [SMALL_STATE(28)] = 1030,
  [SMALL_STATE(29)] = 1054,
  [SMALL_STATE(30)] = 1080,
  [SMALL_STATE(31)] = 1104,
  [SMALL_STATE(32)] = 1128,
  [SMALL_STATE(33)] = 1152,
  [SMALL_STATE(34)] = 1187,
  [SMALL_STATE(35)] = 1212,
  [SMALL_STATE(36)] = 1231,
  [SMALL_STATE(37)] = 1248,
  [SMALL_STATE(38)] = 1265,
  [SMALL_STATE(39)] = 1282,
  [SMALL_STATE(40)] = 1299,
  [SMALL_STATE(41)] = 1316,
  [SMALL_STATE(42)] = 1351,
  [SMALL_STATE(43)] = 1368,
  [SMALL_STATE(44)] = 1385,
  [SMALL_STATE(45)] = 1402,
  [SMALL_STATE(46)] = 1419,
  [SMALL_STATE(47)] = 1436,
  [SMALL_STATE(48)] = 1461,
  [SMALL_STATE(49)] = 1478,
  [SMALL_STATE(50)] = 1495,
  [SMALL_STATE(51)] = 1511,
  [SMALL_STATE(52)] = 1526,
  [SMALL_STATE(53)] = 1545,
  [SMALL_STATE(54)] = 1560,
  [SMALL_STATE(55)] = 1579,
  [SMALL_STATE(56)] = 1594,
  [SMALL_STATE(57)] = 1613,
  [SMALL_STATE(58)] = 1628,
  [SMALL_STATE(59)] = 1643,
  [SMALL_STATE(60)] = 1658,
  [SMALL_STATE(61)] = 1673,
  [SMALL_STATE(62)] = 1688,
  [SMALL_STATE(63)] = 1707,
  [SMALL_STATE(64)] = 1722,
  [SMALL_STATE(65)] = 1741,
  [SMALL_STATE(66)] = 1763,
  [SMALL_STATE(67)] = 1779,
  [SMALL_STATE(68)] = 1801,
  [SMALL_STATE(69)] = 1815,
  [SMALL_STATE(70)] = 1829,
  [SMALL_STATE(71)] = 1843,
  [SMALL_STATE(72)] = 1865,
  [SMALL_STATE(73)] = 1887,
  [SMALL_STATE(74)] = 1902,
  [SMALL_STATE(75)] = 1915,
  [SMALL_STATE(76)] = 1930,
  [SMALL_STATE(77)] = 1953,
  [SMALL_STATE(78)] = 1968,
  [SMALL_STATE(79)] = 1991,
  [SMALL_STATE(80)] = 2014,
  [SMALL_STATE(81)] = 2037,
  [SMALL_STATE(82)] = 2050,
  [SMALL_STATE(83)] = 2062,
  [SMALL_STATE(84)] = 2074,
  [SMALL_STATE(85)] = 2094,
  [SMALL_STATE(86)] = 2114,
  [SMALL_STATE(87)] = 2134,
  [SMALL_STATE(88)] = 2146,
  [SMALL_STATE(89)] = 2158,
  [SMALL_STATE(90)] = 2178,
  [SMALL_STATE(91)] = 2198,
  [SMALL_STATE(92)] = 2210,
  [SMALL_STATE(93)] = 2222,
  [SMALL_STATE(94)] = 2234,
  [SMALL_STATE(95)] = 2246,
  [SMALL_STATE(96)] = 2258,
  [SMALL_STATE(97)] = 2278,
  [SMALL_STATE(98)] = 2298,
  [SMALL_STATE(99)] = 2318,
  [SMALL_STATE(100)] = 2338,
  [SMALL_STATE(101)] = 2348,
  [SMALL_STATE(102)] = 2368,
  [SMALL_STATE(103)] = 2377,
  [SMALL_STATE(104)] = 2388,
  [SMALL_STATE(105)] = 2403,
  [SMALL_STATE(106)] = 2412,
  [SMALL_STATE(107)] = 2421,
  [SMALL_STATE(108)] = 2430,
  [SMALL_STATE(109)] = 2445,
  [SMALL_STATE(110)] = 2456,
  [SMALL_STATE(111)] = 2471,
  [SMALL_STATE(112)] = 2482,
  [SMALL_STATE(113)] = 2493,
  [SMALL_STATE(114)] = 2504,
  [SMALL_STATE(115)] = 2513,
  [SMALL_STATE(116)] = 2524,
  [SMALL_STATE(117)] = 2539,
  [SMALL_STATE(118)] = 2550,
  [SMALL_STATE(119)] = 2561,
  [SMALL_STATE(120)] = 2570,
  [SMALL_STATE(121)] = 2584,
  [SMALL_STATE(122)] = 2596,
  [SMALL_STATE(123)] = 2610,
  [SMALL_STATE(124)] = 2624,
  [SMALL_STATE(125)] = 2638,
  [SMALL_STATE(126)] = 2652,
  [SMALL_STATE(127)] = 2666,
  [SMALL_STATE(128)] = 2680,
  [SMALL_STATE(129)] = 2692,
  [SMALL_STATE(130)] = 2706,
  [SMALL_STATE(131)] = 2717,
  [SMALL_STATE(132)] = 2728,
  [SMALL_STATE(133)] = 2735,
  [SMALL_STATE(134)] = 2746,
  [SMALL_STATE(135)] = 2757,
  [SMALL_STATE(136)] = 2768,
  [SMALL_STATE(137)] = 2779,
  [SMALL_STATE(138)] = 2786,
  [SMALL_STATE(139)] = 2797,
  [SMALL_STATE(140)] = 2804,
  [SMALL_STATE(141)] = 2815,
  [SMALL_STATE(142)] = 2822,
  [SMALL_STATE(143)] = 2829,
  [SMALL_STATE(144)] = 2836,
  [SMALL_STATE(145)] = 2843,
  [SMALL_STATE(146)] = 2850,
  [SMALL_STATE(147)] = 2857,
  [SMALL_STATE(148)] = 2864,
  [SMALL_STATE(149)] = 2871,
  [SMALL_STATE(150)] = 2878,
  [SMALL_STATE(151)] = 2885,
  [SMALL_STATE(152)] = 2892,
  [SMALL_STATE(153)] = 2899,
  [SMALL_STATE(154)] = 2906,
  [SMALL_STATE(155)] = 2913,
  [SMALL_STATE(156)] = 2920,
  [SMALL_STATE(157)] = 2927,
  [SMALL_STATE(158)] = 2934,
  [SMALL_STATE(159)] = 2938,
  [SMALL_STATE(160)] = 2942,
  [SMALL_STATE(161)] = 2946,
  [SMALL_STATE(162)] = 2950,
  [SMALL_STATE(163)] = 2954,
  [SMALL_STATE(164)] = 2958,
  [SMALL_STATE(165)] = 2962,
  [SMALL_STATE(166)] = 2966,
  [SMALL_STATE(167)] = 2970,
  [SMALL_STATE(168)] = 2974,
  [SMALL_STATE(169)] = 2978,
  [SMALL_STATE(170)] = 2982,
  [SMALL_STATE(171)] = 2986,
  [SMALL_STATE(172)] = 2990,
  [SMALL_STATE(173)] = 2994,
  [SMALL_STATE(174)] = 2998,
  [SMALL_STATE(175)] = 3002,
  [SMALL_STATE(176)] = 3006,
  [SMALL_STATE(177)] = 3010,
  [SMALL_STATE(178)] = 3014,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2), SHIFT_REPEAT(78),
  [44] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2), SHIFT_REPEAT(84),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2), SHIFT_REPEAT(4),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2), SHIFT_REPEAT(9),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__number_signable_repeat1, 2),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_signable, 1),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_signable, 1),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_signable, 3),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_signable, 3),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_unsignable, 2),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_unsignable, 2),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro, 2),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro, 2),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_repeat1, 2),
  [85] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_repeat1, 2), SHIFT_REPEAT(79),
  [88] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_repeat1, 2), SHIFT_REPEAT(85),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__macro_repeat1, 2), SHIFT_REPEAT(18),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_repeat1, 2),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 1),
  [98] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2),
  [104] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(20),
  [107] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(20),
  [110] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(76),
  [113] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(86),
  [116] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(3),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__labels, 2),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__labels, 2),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [129] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [133] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(24),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(80),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(90),
  [142] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(24),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__labels, 1),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__labels, 1),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [159] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__labels_repeat1, 2),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__labels_repeat1, 2),
  [169] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__labels_repeat1, 2), SHIFT_REPEAT(34),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 2),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [184] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__labels_repeat1, 1),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__labels_repeat1, 1),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 4),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 4),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5, .production_id = 5),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5, .production_id = 5),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 5),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 5),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5, .production_id = 5),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5, .production_id = 5),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 1),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 3),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 3),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inlineRoll, 3),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inlineRoll, 3),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [238] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 3),
  [244] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 3),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [252] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__labels_repeat1, 2), SHIFT_REPEAT(47),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__operator_multiplication, 1),
  [257] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__operator_multiplication, 1),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 5),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 2),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 4),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 3),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term, 1),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_first, 2, .production_id = 4),
  [273] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [275] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [277] = {.entry = {.count = 1, .reusable = false}}, SHIFT(162),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_first, 1, .production_id = 3),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__operator_summation, 1),
  [285] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__operator_summation, 1),
  [287] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 4),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formula, 3),
  [293] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 2), SHIFT_REPEAT(58),
  [296] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 2), SHIFT_REPEAT(81),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_first, 2, .production_id = 3),
  [303] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(104),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2),
  [308] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(104),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_first, 3, .production_id = 4),
  [313] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro, 3),
  [315] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_identifier, 1),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [321] = {.entry = {.count = 1, .reusable = false}}, SHIFT(104),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term, 2),
  [327] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(116),
  [330] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(116),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__term_first, 1),
  [335] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [339] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability_identifier, 1),
  [343] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_ability_identifier_repeat1, 2), SHIFT_REPEAT(128),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ability_identifier_repeat1, 2),
  [348] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_formula_repeat1, 6),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [390] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [392] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [398] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [414] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 1),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [420] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [422] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 2),
  [424] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [426] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [428] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [430] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [432] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [434] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [436] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [438] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [440] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [442] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [444] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(131),
  [448] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [450] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [454] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
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
