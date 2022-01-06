#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 125
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 50
#define ALIAS_COUNT 1
#define TOKEN_COUNT 24
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 4

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
  anon_sym_LBRACK_LBRACK = 14,
  anon_sym_RBRACK_RBRACK = 15,
  aux_sym__number_signable_token1 = 16,
  anon_sym_DOT = 17,
  aux_sym__term_first_token1 = 18,
  anon_sym_LBRACK = 19,
  aux_sym_label_token1 = 20,
  aux_sym_label_token2 = 21,
  anon_sym_RBRACK = 22,
  sym___EOF = 23,
  sym_script = 24,
  sym__placeholder = 25,
  sym_character_token_identifier = 26,
  sym__attribute = 27,
  sym_attribute = 28,
  sym__attribute_of_character = 29,
  sym__attribute_of_character_maximum = 30,
  sym_attribute_identifier = 31,
  sym_ability = 32,
  sym_ability_identifier = 33,
  sym_inlineRoll = 34,
  sym__IrPh = 35,
  sym_number = 36,
  sym__number_signable = 37,
  sym__number_unsignable = 38,
  sym_label = 39,
  sym__labels = 40,
  aux_sym_script_repeat1 = 41,
  aux_sym_attribute_identifier_repeat1 = 42,
  aux_sym_ability_identifier_repeat1 = 43,
  aux_sym_inlineRoll_repeat1 = 44,
  aux_sym__number_signable_repeat1 = 45,
  aux_sym__number_signable_repeat2 = 46,
  aux_sym__number_signable_repeat3 = 47,
  aux_sym_label_repeat1 = 48,
  aux_sym__labels_repeat1 = 49,
  alias_sym_character_identifier = 50,
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
  [anon_sym_LBRACK_LBRACK] = "[[",
  [anon_sym_RBRACK_RBRACK] = "]]",
  [aux_sym__number_signable_token1] = "_number_signable_token1",
  [anon_sym_DOT] = ".",
  [aux_sym__term_first_token1] = "operator",
  [anon_sym_LBRACK] = "[",
  [aux_sym_label_token1] = "label_token1",
  [aux_sym_label_token2] = "label_token2",
  [anon_sym_RBRACK] = "]",
  [sym___EOF] = "__EOF",
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
  [sym_inlineRoll] = "inlineRoll",
  [sym__IrPh] = "_IrPh",
  [sym_number] = "number",
  [sym__number_signable] = "_number_signable",
  [sym__number_unsignable] = "_number_unsignable",
  [sym_label] = "label",
  [sym__labels] = "_labels",
  [aux_sym_script_repeat1] = "script_repeat1",
  [aux_sym_attribute_identifier_repeat1] = "attribute_identifier_repeat1",
  [aux_sym_ability_identifier_repeat1] = "ability_identifier_repeat1",
  [aux_sym_inlineRoll_repeat1] = "inlineRoll_repeat1",
  [aux_sym__number_signable_repeat1] = "_number_signable_repeat1",
  [aux_sym__number_signable_repeat2] = "_number_signable_repeat2",
  [aux_sym__number_signable_repeat3] = "_number_signable_repeat3",
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
  [anon_sym_LBRACK_LBRACK] = anon_sym_LBRACK_LBRACK,
  [anon_sym_RBRACK_RBRACK] = anon_sym_RBRACK_RBRACK,
  [aux_sym__number_signable_token1] = aux_sym__number_signable_token1,
  [anon_sym_DOT] = anon_sym_DOT,
  [aux_sym__term_first_token1] = aux_sym__term_first_token1,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [aux_sym_label_token1] = aux_sym_label_token1,
  [aux_sym_label_token2] = aux_sym_label_token2,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym___EOF] = sym___EOF,
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
  [sym_inlineRoll] = sym_inlineRoll,
  [sym__IrPh] = sym__IrPh,
  [sym_number] = sym_number,
  [sym__number_signable] = sym__number_signable,
  [sym__number_unsignable] = sym__number_unsignable,
  [sym_label] = sym_label,
  [sym__labels] = sym__labels,
  [aux_sym_script_repeat1] = aux_sym_script_repeat1,
  [aux_sym_attribute_identifier_repeat1] = aux_sym_attribute_identifier_repeat1,
  [aux_sym_ability_identifier_repeat1] = aux_sym_ability_identifier_repeat1,
  [aux_sym_inlineRoll_repeat1] = aux_sym_inlineRoll_repeat1,
  [aux_sym__number_signable_repeat1] = aux_sym__number_signable_repeat1,
  [aux_sym__number_signable_repeat2] = aux_sym__number_signable_repeat2,
  [aux_sym__number_signable_repeat3] = aux_sym__number_signable_repeat3,
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
  [sym___EOF] = {
    .visible = false,
    .named = true,
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
  [aux_sym_inlineRoll_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__number_signable_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__number_signable_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__number_signable_repeat3] = {
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
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(22);
      if (lookahead == '\r') ADVANCE(23);
      if (lookahead == '#') ADVANCE(83);
      if (lookahead == '%') ADVANCE(26);
      if (lookahead == '&') ADVANCE(24);
      if (lookahead == '.') ADVANCE(87);
      if (lookahead == '@') ADVANCE(27);
      if (lookahead == '[') ADVANCE(88);
      if (lookahead == ']') ADVANCE(98);
      if (lookahead == '|') ADVANCE(38);
      if (lookahead == '}') ADVANCE(37);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(23);
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(83);
      if (lookahead == '%') ADVANCE(96);
      if (lookahead == '&') ADVANCE(95);
      if (lookahead == '@') ADVANCE(97);
      if (lookahead == ']') ADVANCE(98);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(94);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(83);
      if (lookahead == '%') ADVANCE(92);
      if (lookahead == '&') ADVANCE(91);
      if (lookahead == '@') ADVANCE(93);
      if (lookahead == ']') ADVANCE(98);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '[') ADVANCE(90);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(83);
      if (lookahead == '&') ADVANCE(40);
      if (lookahead == 's') ADVANCE(45);
      if (lookahead == 't') ADVANCE(42);
      if (lookahead == '{') ADVANCE(54);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(37);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(56);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(83);
      if (lookahead == '&') ADVANCE(40);
      if (lookahead == '{') ADVANCE(54);
      if (lookahead == '|') ADVANCE(38);
      if (lookahead == '}') ADVANCE(37);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(56);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(83);
      if (lookahead == '&') ADVANCE(40);
      if (lookahead == '{') ADVANCE(54);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(37);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(56);
      END_STATE();
    case 6:
      if (lookahead == '%') ADVANCE(16);
      if (lookahead == '.') ADVANCE(87);
      if (lookahead == '@') ADVANCE(17);
      if (lookahead == '[') ADVANCE(89);
      if (lookahead == ']') ADVANCE(12);
      if (lookahead == '|') ADVANCE(38);
      if (lookahead == '}') ADVANCE(37);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(86);
      END_STATE();
    case 7:
      if (lookahead == '&') ADVANCE(60);
      if (lookahead == 's') ADVANCE(67);
      if (lookahead == 't') ADVANCE(64);
      if (lookahead == '{') ADVANCE(76);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 8:
      if (lookahead == '&') ADVANCE(60);
      if (lookahead == '{') ADVANCE(76);
      if (lookahead == '|') ADVANCE(38);
      if (lookahead == '}') ADVANCE(37);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(80);
      END_STATE();
    case 9:
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == ']') ADVANCE(85);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(15);
      END_STATE();
    case 14:
      if (lookahead == 'm') ADVANCE(13);
      END_STATE();
    case 15:
      if (lookahead == 'x') ADVANCE(18);
      END_STATE();
    case 16:
      if (lookahead == '{') ADVANCE(59);
      END_STATE();
    case 17:
      if (lookahead == '{') ADVANCE(36);
      END_STATE();
    case 18:
      if (lookahead == '}') ADVANCE(39);
      END_STATE();
    case 19:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      END_STATE();
    case 20:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(10);
      END_STATE();
    case 21:
      if (eof) ADVANCE(22);
      if (lookahead == '#') ADVANCE(83);
      if (lookahead == '%') ADVANCE(26);
      if (lookahead == '&') ADVANCE(24);
      if (lookahead == '@') ADVANCE(27);
      if (lookahead == '[') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(23);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_script_token1);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '#') ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(11);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '[') ADVANCE(84);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '{') ADVANCE(59);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '{') ADVANCE(36);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym__wsp);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_htmlEntity);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_htmlEntity);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_htmlEntity);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_PIPEmax_RBRACE);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '#') ADVANCE(19);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == ';') ADVANCE(30);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(41);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'a') ADVANCE(51);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'c') ADVANCE(53);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'd') ADVANCE(34);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(50);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(43);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(44);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(52);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'g') ADVANCE(48);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'l') ADVANCE(46);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'r') ADVANCE(49);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 't') ADVANCE(32);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 't') ADVANCE(47);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(54);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(56);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(54);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_PERCENT_LBRACE);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '#') ADVANCE(78);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == ';') ADVANCE(31);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(61);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == ';') ADVANCE(31);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == ';') ADVANCE(31);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'a') ADVANCE(73);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'c') ADVANCE(75);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'd') ADVANCE(35);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(72);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(65);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(66);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(74);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'g') ADVANCE(70);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'l') ADVANCE(68);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'r') ADVANCE(71);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 't') ADVANCE(33);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 't') ADVANCE(69);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(76);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(76);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(61);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(77);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(80);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(81);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(76);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_hash);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_LBRACK_LBRACK);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_RBRACK_RBRACK);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym__number_signable_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      if (lookahead == '[') ADVANCE(84);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_label_token1);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_label_token1);
      if (lookahead == '#') ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(11);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym_label_token1);
      if (lookahead == '{') ADVANCE(59);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym_label_token1);
      if (lookahead == '{') ADVANCE(36);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym_label_token2);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym_label_token2);
      if (lookahead == '#') ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(11);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym_label_token2);
      if (lookahead == '{') ADVANCE(59);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym_label_token2);
      if (lookahead == '{') ADVANCE(36);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 21},
  [2] = {.lex_state = 6},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 6},
  [5] = {.lex_state = 6},
  [6] = {.lex_state = 6},
  [7] = {.lex_state = 6},
  [8] = {.lex_state = 6},
  [9] = {.lex_state = 6},
  [10] = {.lex_state = 6},
  [11] = {.lex_state = 6},
  [12] = {.lex_state = 6},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 6},
  [15] = {.lex_state = 6},
  [16] = {.lex_state = 6},
  [17] = {.lex_state = 6},
  [18] = {.lex_state = 21},
  [19] = {.lex_state = 21},
  [20] = {.lex_state = 6},
  [21] = {.lex_state = 6},
  [22] = {.lex_state = 6},
  [23] = {.lex_state = 6},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 6},
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 6},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 6},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 6},
  [32] = {.lex_state = 6},
  [33] = {.lex_state = 6},
  [34] = {.lex_state = 6},
  [35] = {.lex_state = 6},
  [36] = {.lex_state = 6},
  [37] = {.lex_state = 6},
  [38] = {.lex_state = 6},
  [39] = {.lex_state = 6},
  [40] = {.lex_state = 6},
  [41] = {.lex_state = 6},
  [42] = {.lex_state = 3},
  [43] = {.lex_state = 6},
  [44] = {.lex_state = 6},
  [45] = {.lex_state = 6},
  [46] = {.lex_state = 6},
  [47] = {.lex_state = 6},
  [48] = {.lex_state = 6},
  [49] = {.lex_state = 6},
  [50] = {.lex_state = 6},
  [51] = {.lex_state = 3},
  [52] = {.lex_state = 6},
  [53] = {.lex_state = 6},
  [54] = {.lex_state = 6},
  [55] = {.lex_state = 6},
  [56] = {.lex_state = 3},
  [57] = {.lex_state = 6},
  [58] = {.lex_state = 7},
  [59] = {.lex_state = 7},
  [60] = {.lex_state = 21},
  [61] = {.lex_state = 21},
  [62] = {.lex_state = 21},
  [63] = {.lex_state = 21},
  [64] = {.lex_state = 21},
  [65] = {.lex_state = 21},
  [66] = {.lex_state = 7},
  [67] = {.lex_state = 21},
  [68] = {.lex_state = 21},
  [69] = {.lex_state = 21},
  [70] = {.lex_state = 21},
  [71] = {.lex_state = 1},
  [72] = {.lex_state = 4},
  [73] = {.lex_state = 4},
  [74] = {.lex_state = 1},
  [75] = {.lex_state = 5},
  [76] = {.lex_state = 1},
  [77] = {.lex_state = 1},
  [78] = {.lex_state = 5},
  [79] = {.lex_state = 1},
  [80] = {.lex_state = 1},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 4},
  [84] = {.lex_state = 4},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 8},
  [87] = {.lex_state = 8},
  [88] = {.lex_state = 4},
  [89] = {.lex_state = 4},
  [90] = {.lex_state = 4},
  [91] = {.lex_state = 8},
  [92] = {.lex_state = 8},
  [93] = {.lex_state = 8},
  [94] = {.lex_state = 8},
  [95] = {.lex_state = 8},
  [96] = {.lex_state = 8},
  [97] = {.lex_state = 6},
  [98] = {.lex_state = 6},
  [99] = {.lex_state = 3},
  [100] = {.lex_state = 3},
  [101] = {.lex_state = 3},
  [102] = {.lex_state = 3},
  [103] = {.lex_state = 6},
  [104] = {.lex_state = 6},
  [105] = {.lex_state = 3},
  [106] = {.lex_state = 3},
  [107] = {.lex_state = 6},
  [108] = {.lex_state = 6},
  [109] = {.lex_state = 6},
  [110] = {.lex_state = 6},
  [111] = {.lex_state = 6},
  [112] = {.lex_state = 6},
  [113] = {.lex_state = 6},
  [114] = {.lex_state = 6},
  [115] = {.lex_state = 6},
  [116] = {.lex_state = 6},
  [117] = {.lex_state = 6},
  [118] = {.lex_state = 6},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 6},
  [121] = {.lex_state = 6},
  [122] = {.lex_state = 6},
  [123] = {.lex_state = 6},
  [124] = {.lex_state = 6},
};

enum {
  ts_external_token___EOF = 0,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token___EOF] = sym___EOF,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token___EOF] = true,
  },
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
    [anon_sym_DOT] = ACTIONS(1),
    [aux_sym__term_first_token1] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [aux_sym_label_token1] = ACTIONS(1),
    [aux_sym_label_token2] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym___EOF] = ACTIONS(1),
  },
  [1] = {
    [sym_script] = STATE(119),
    [sym__placeholder] = STATE(18),
    [sym__attribute] = STATE(18),
    [sym_attribute] = STATE(18),
    [sym__attribute_of_character] = STATE(18),
    [sym__attribute_of_character_maximum] = STATE(18),
    [sym_ability] = STATE(18),
    [sym_inlineRoll] = STATE(18),
    [sym__IrPh] = STATE(18),
    [aux_sym_script_repeat1] = STATE(18),
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
  [0] = 13,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(23), 1,
      anon_sym_RBRACK_RBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    STATE(31), 1,
      aux_sym__labels_repeat1,
    STATE(53), 1,
      sym_label,
    STATE(47), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(3), 3,
      sym_number,
      sym__labels,
      aux_sym_inlineRoll_repeat1,
    STATE(21), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [51] = 13,
    ACTIONS(31), 1,
      sym__wsp,
    ACTIONS(34), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(37), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(40), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(43), 1,
      anon_sym_RBRACK_RBRACK,
    ACTIONS(45), 1,
      aux_sym__number_signable_token1,
    ACTIONS(48), 1,
      anon_sym_DOT,
    ACTIONS(51), 1,
      anon_sym_LBRACK,
    STATE(31), 1,
      aux_sym__labels_repeat1,
    STATE(53), 1,
      sym_label,
    STATE(47), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(3), 3,
      sym_number,
      sym__labels,
      aux_sym_inlineRoll_repeat1,
    STATE(21), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [102] = 13,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(54), 1,
      anon_sym_RBRACK_RBRACK,
    STATE(31), 1,
      aux_sym__labels_repeat1,
    STATE(53), 1,
      sym_label,
    STATE(47), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(5), 3,
      sym_number,
      sym__labels,
      aux_sym_inlineRoll_repeat1,
    STATE(21), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [153] = 13,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(56), 1,
      anon_sym_RBRACK_RBRACK,
    STATE(31), 1,
      aux_sym__labels_repeat1,
    STATE(53), 1,
      sym_label,
    STATE(47), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(3), 3,
      sym_number,
      sym__labels,
      aux_sym_inlineRoll_repeat1,
    STATE(21), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [204] = 13,
    ACTIONS(15), 1,
      sym__wsp,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(25), 1,
      aux_sym__number_signable_token1,
    ACTIONS(27), 1,
      anon_sym_DOT,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    ACTIONS(58), 1,
      anon_sym_RBRACK_RBRACK,
    STATE(31), 1,
      aux_sym__labels_repeat1,
    STATE(53), 1,
      sym_label,
    STATE(47), 2,
      sym__number_signable,
      sym__number_unsignable,
    STATE(2), 3,
      sym_number,
      sym__labels,
      aux_sym_inlineRoll_repeat1,
    STATE(21), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [255] = 7,
    ACTIONS(62), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(65), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(68), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(71), 1,
      aux_sym__number_signable_token1,
    ACTIONS(74), 1,
      anon_sym_LBRACK,
    ACTIONS(60), 3,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_DOT,
    STATE(7), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat3,
  [287] = 7,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(78), 1,
      aux_sym__number_signable_token1,
    ACTIONS(80), 1,
      anon_sym_LBRACK,
    ACTIONS(76), 3,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_DOT,
    STATE(7), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat3,
  [319] = 7,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(78), 1,
      aux_sym__number_signable_token1,
    ACTIONS(84), 1,
      anon_sym_LBRACK,
    ACTIONS(82), 3,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_DOT,
    STATE(7), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat3,
  [351] = 7,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(78), 1,
      aux_sym__number_signable_token1,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(86), 3,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_DOT,
    STATE(7), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat3,
  [383] = 7,
    ACTIONS(92), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(95), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(98), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    STATE(11), 1,
      aux_sym__number_signable_repeat2,
    ACTIONS(90), 4,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
    STATE(112), 8,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
  [415] = 7,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(78), 1,
      aux_sym__number_signable_token1,
    ACTIONS(105), 1,
      anon_sym_LBRACK,
    ACTIONS(103), 3,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_DOT,
    STATE(7), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat3,
  [447] = 8,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(109), 1,
      anon_sym_DOT,
    ACTIONS(111), 1,
      anon_sym_LBRACK,
    STATE(14), 1,
      aux_sym__number_signable_repeat2,
    ACTIONS(107), 3,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
    STATE(54), 8,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
  [481] = 8,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(80), 1,
      anon_sym_LBRACK,
    ACTIONS(113), 1,
      anon_sym_DOT,
    STATE(11), 1,
      aux_sym__number_signable_repeat2,
    ACTIONS(76), 3,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
    STATE(38), 8,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
  [515] = 8,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(117), 1,
      anon_sym_DOT,
    ACTIONS(119), 1,
      anon_sym_LBRACK,
    STATE(17), 1,
      aux_sym__number_signable_repeat2,
    ACTIONS(115), 3,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
    STATE(41), 8,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
  [549] = 7,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(78), 1,
      aux_sym__number_signable_token1,
    ACTIONS(123), 1,
      anon_sym_LBRACK,
    ACTIONS(121), 3,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      anon_sym_DOT,
    STATE(7), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat3,
  [581] = 8,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(109), 1,
      anon_sym_DOT,
    ACTIONS(111), 1,
      anon_sym_LBRACK,
    STATE(11), 1,
      aux_sym__number_signable_repeat2,
    ACTIONS(107), 3,
      sym__wsp,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
    STATE(54), 8,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
  [615] = 7,
    ACTIONS(9), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(11), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(13), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(125), 1,
      ts_builtin_sym_end,
    ACTIONS(127), 1,
      aux_sym_script_token1,
    ACTIONS(129), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(19), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym_script_repeat1,
  [646] = 7,
    ACTIONS(131), 1,
      ts_builtin_sym_end,
    ACTIONS(133), 1,
      aux_sym_script_token1,
    ACTIONS(139), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(142), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(145), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(136), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(19), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym_script_repeat1,
  [677] = 5,
    ACTIONS(148), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(151), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(154), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(157), 2,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
    STATE(20), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [702] = 6,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(117), 1,
      anon_sym_DOT,
    ACTIONS(159), 1,
      aux_sym__number_signable_token1,
    STATE(20), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat1,
  [729] = 5,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(161), 1,
      aux_sym__number_signable_token1,
    STATE(12), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat3,
  [753] = 5,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(163), 1,
      aux_sym__number_signable_token1,
    STATE(8), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat3,
  [777] = 6,
    ACTIONS(168), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(171), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(174), 1,
      aux_sym_label_token2,
    ACTIONS(177), 1,
      anon_sym_RBRACK,
    ACTIONS(165), 2,
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
  [803] = 5,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(179), 1,
      aux_sym__number_signable_token1,
    STATE(9), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat3,
  [827] = 6,
    ACTIONS(183), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(185), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(187), 1,
      aux_sym_label_token2,
    ACTIONS(189), 1,
      anon_sym_RBRACK,
    ACTIONS(181), 2,
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
  [853] = 5,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(191), 1,
      aux_sym__number_signable_token1,
    STATE(10), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat3,
  [877] = 6,
    ACTIONS(183), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(185), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(195), 1,
      aux_sym_label_token2,
    ACTIONS(197), 1,
      anon_sym_RBRACK,
    ACTIONS(193), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(26), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_label_repeat1,
  [903] = 5,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(19), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACK_LBRACK,
    ACTIONS(199), 1,
      aux_sym__number_signable_token1,
    STATE(16), 9,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym_inlineRoll,
      sym__IrPh,
      aux_sym__number_signable_repeat3,
  [927] = 6,
    ACTIONS(183), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(185), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(203), 1,
      aux_sym_label_token1,
    ACTIONS(205), 1,
      anon_sym_RBRACK,
    ACTIONS(201), 2,
      sym_htmlEntity,
      sym_hash,
    STATE(28), 6,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
  [952] = 4,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    STATE(32), 1,
      aux_sym__labels_repeat1,
    STATE(53), 1,
      sym_label,
    ACTIONS(207), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [971] = 4,
    ACTIONS(211), 1,
      anon_sym_LBRACK,
    STATE(32), 1,
      aux_sym__labels_repeat1,
    STATE(53), 1,
      sym_label,
    ACTIONS(209), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [990] = 4,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    STATE(34), 1,
      aux_sym__labels_repeat1,
    STATE(53), 1,
      sym_label,
    ACTIONS(207), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1009] = 4,
    ACTIONS(29), 1,
      anon_sym_LBRACK,
    STATE(32), 1,
      aux_sym__labels_repeat1,
    STATE(53), 1,
      sym_label,
    ACTIONS(214), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1028] = 2,
    ACTIONS(218), 1,
      anon_sym_LBRACK,
    ACTIONS(216), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1041] = 2,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(90), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1054] = 2,
    ACTIONS(222), 1,
      anon_sym_LBRACK,
    ACTIONS(220), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1067] = 4,
    ACTIONS(88), 1,
      anon_sym_LBRACK,
    ACTIONS(224), 1,
      aux_sym__number_signable_token1,
    ACTIONS(226), 1,
      anon_sym_DOT,
    ACTIONS(86), 5,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
  [1084] = 2,
    ACTIONS(230), 1,
      anon_sym_LBRACK,
    ACTIONS(228), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1097] = 2,
    ACTIONS(234), 1,
      anon_sym_LBRACK,
    ACTIONS(232), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1110] = 4,
    ACTIONS(109), 1,
      anon_sym_DOT,
    ACTIONS(111), 1,
      anon_sym_LBRACK,
    ACTIONS(224), 1,
      aux_sym__number_signable_token1,
    ACTIONS(107), 5,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
  [1127] = 7,
    ACTIONS(238), 1,
      anon_sym_target,
    ACTIONS(240), 1,
      anon_sym_selected,
    ACTIONS(242), 1,
      sym_hash,
    STATE(73), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(98), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym_character_token_identifier,
    ACTIONS(236), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1150] = 2,
    ACTIONS(246), 1,
      anon_sym_LBRACK,
    ACTIONS(244), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1163] = 2,
    ACTIONS(248), 1,
      anon_sym_LBRACK,
    ACTIONS(209), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1176] = 2,
    ACTIONS(252), 1,
      anon_sym_LBRACK,
    ACTIONS(250), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1189] = 2,
    ACTIONS(256), 1,
      anon_sym_LBRACK,
    ACTIONS(254), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1202] = 2,
    ACTIONS(260), 1,
      anon_sym_LBRACK,
    ACTIONS(258), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1215] = 2,
    ACTIONS(264), 1,
      anon_sym_LBRACK,
    ACTIONS(262), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1228] = 2,
    ACTIONS(268), 1,
      anon_sym_LBRACK,
    ACTIONS(266), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1241] = 2,
    ACTIONS(272), 1,
      anon_sym_LBRACK,
    ACTIONS(270), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1254] = 7,
    ACTIONS(238), 1,
      anon_sym_target,
    ACTIONS(240), 1,
      anon_sym_selected,
    ACTIONS(242), 1,
      sym_hash,
    STATE(73), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(107), 1,
      sym_attribute_identifier,
    STATE(121), 1,
      sym_character_token_identifier,
    ACTIONS(236), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1277] = 2,
    ACTIONS(276), 1,
      anon_sym_LBRACK,
    ACTIONS(274), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1290] = 3,
    ACTIONS(278), 1,
      sym__wsp,
    ACTIONS(283), 1,
      anon_sym_LBRACK,
    ACTIONS(281), 6,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1305] = 4,
    ACTIONS(80), 1,
      anon_sym_LBRACK,
    ACTIONS(113), 1,
      anon_sym_DOT,
    ACTIONS(224), 1,
      aux_sym__number_signable_token1,
    ACTIONS(76), 5,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
  [1322] = 2,
    ACTIONS(287), 1,
      anon_sym_LBRACK,
    ACTIONS(285), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1335] = 7,
    ACTIONS(238), 1,
      anon_sym_target,
    ACTIONS(240), 1,
      anon_sym_selected,
    ACTIONS(242), 1,
      sym_hash,
    STATE(73), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(103), 1,
      sym_attribute_identifier,
    STATE(123), 1,
      sym_character_token_identifier,
    ACTIONS(236), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1358] = 2,
    ACTIONS(291), 1,
      anon_sym_LBRACK,
    ACTIONS(289), 7,
      sym__wsp,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_LBRACK_LBRACK,
      anon_sym_RBRACK_RBRACK,
      aux_sym__number_signable_token1,
      anon_sym_DOT,
  [1371] = 6,
    ACTIONS(238), 1,
      anon_sym_target,
    ACTIONS(240), 1,
      anon_sym_selected,
    STATE(86), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(108), 1,
      sym_ability_identifier,
    STATE(122), 1,
      sym_character_token_identifier,
    ACTIONS(293), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [1391] = 6,
    ACTIONS(238), 1,
      anon_sym_target,
    ACTIONS(240), 1,
      anon_sym_selected,
    STATE(86), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(97), 1,
      sym_ability_identifier,
    STATE(124), 1,
      sym_character_token_identifier,
    ACTIONS(293), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [1411] = 2,
    ACTIONS(222), 1,
      aux_sym_script_token1,
    ACTIONS(220), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [1423] = 2,
    ACTIONS(276), 1,
      aux_sym_script_token1,
    ACTIONS(274), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [1435] = 2,
    ACTIONS(287), 1,
      aux_sym_script_token1,
    ACTIONS(285), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [1447] = 2,
    ACTIONS(252), 1,
      aux_sym_script_token1,
    ACTIONS(250), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [1459] = 2,
    ACTIONS(268), 1,
      aux_sym_script_token1,
    ACTIONS(266), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [1471] = 2,
    ACTIONS(272), 1,
      aux_sym_script_token1,
    ACTIONS(270), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [1483] = 6,
    ACTIONS(238), 1,
      anon_sym_target,
    ACTIONS(240), 1,
      anon_sym_selected,
    STATE(86), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(104), 1,
      sym_ability_identifier,
    STATE(114), 1,
      sym_character_token_identifier,
    ACTIONS(293), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [1503] = 2,
    ACTIONS(218), 1,
      aux_sym_script_token1,
    ACTIONS(216), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [1515] = 2,
    ACTIONS(264), 1,
      aux_sym_script_token1,
    ACTIONS(262), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [1527] = 2,
    ACTIONS(230), 1,
      aux_sym_script_token1,
    ACTIONS(228), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [1539] = 2,
    ACTIONS(234), 1,
      aux_sym_script_token1,
    ACTIONS(232), 6,
      ts_builtin_sym_end,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_LBRACK_LBRACK,
  [1551] = 2,
    ACTIONS(268), 1,
      aux_sym_label_token2,
    ACTIONS(266), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [1562] = 4,
    ACTIONS(300), 1,
      sym_hash,
    STATE(72), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(295), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(298), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [1577] = 4,
    ACTIONS(307), 1,
      sym_hash,
    STATE(72), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(303), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(305), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [1592] = 2,
    ACTIONS(272), 1,
      aux_sym_label_token2,
    ACTIONS(270), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [1603] = 4,
    ACTIONS(311), 1,
      sym_hash,
    STATE(78), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(305), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(309), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1618] = 2,
    ACTIONS(252), 1,
      aux_sym_label_token2,
    ACTIONS(250), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [1629] = 2,
    ACTIONS(287), 1,
      aux_sym_label_token2,
    ACTIONS(285), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [1640] = 4,
    ACTIONS(316), 1,
      sym_hash,
    STATE(78), 1,
      aux_sym_attribute_identifier_repeat1,
    ACTIONS(298), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(313), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1655] = 2,
    ACTIONS(276), 1,
      aux_sym_label_token2,
    ACTIONS(274), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [1666] = 2,
    ACTIONS(222), 1,
      aux_sym_label_token2,
    ACTIONS(220), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [1677] = 2,
    ACTIONS(234), 1,
      aux_sym_label_token2,
    ACTIONS(232), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [1688] = 2,
    ACTIONS(218), 1,
      aux_sym_label_token2,
    ACTIONS(216), 5,
      sym_htmlEntity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      sym_hash,
      anon_sym_RBRACK,
  [1699] = 4,
    ACTIONS(321), 1,
      sym_hash,
    STATE(75), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(100), 1,
      sym_attribute_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1713] = 4,
    ACTIONS(321), 1,
      sym_hash,
    STATE(75), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(102), 1,
      sym_attribute_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1727] = 4,
    ACTIONS(321), 1,
      sym_hash,
    STATE(75), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(101), 1,
      sym_attribute_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1741] = 3,
    STATE(87), 1,
      aux_sym_ability_identifier_repeat1,
    ACTIONS(323), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    ACTIONS(325), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [1753] = 3,
    STATE(87), 1,
      aux_sym_ability_identifier_repeat1,
    ACTIONS(327), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    ACTIONS(330), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [1765] = 4,
    ACTIONS(321), 1,
      sym_hash,
    STATE(75), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(106), 1,
      sym_attribute_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1779] = 4,
    ACTIONS(321), 1,
      sym_hash,
    STATE(75), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(105), 1,
      sym_attribute_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1793] = 4,
    ACTIONS(321), 1,
      sym_hash,
    STATE(75), 1,
      aux_sym_attribute_identifier_repeat1,
    STATE(99), 1,
      sym_attribute_identifier,
    ACTIONS(319), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
  [1807] = 3,
    STATE(86), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(113), 1,
      sym_ability_identifier,
    ACTIONS(293), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [1818] = 3,
    STATE(86), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(117), 1,
      sym_ability_identifier,
    ACTIONS(293), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [1829] = 3,
    STATE(86), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(110), 1,
      sym_ability_identifier,
    ACTIONS(293), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [1840] = 3,
    STATE(86), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(118), 1,
      sym_ability_identifier,
    ACTIONS(293), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [1851] = 3,
    STATE(86), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(120), 1,
      sym_ability_identifier,
    ACTIONS(293), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [1862] = 3,
    STATE(86), 1,
      aux_sym_ability_identifier_repeat1,
    STATE(111), 1,
      sym_ability_identifier,
    ACTIONS(293), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
  [1873] = 2,
    ACTIONS(332), 1,
      anon_sym_RBRACE,
    ACTIONS(334), 1,
      anon_sym_PIPE,
  [1880] = 2,
    ACTIONS(336), 1,
      anon_sym_RBRACE,
    ACTIONS(338), 1,
      anon_sym_PIPE,
  [1887] = 2,
    ACTIONS(340), 1,
      anon_sym_RBRACE,
    ACTIONS(342), 1,
      anon_sym_PIPEmax_RBRACE,
  [1894] = 2,
    ACTIONS(344), 1,
      anon_sym_RBRACE,
    ACTIONS(346), 1,
      anon_sym_PIPEmax_RBRACE,
  [1901] = 2,
    ACTIONS(348), 1,
      anon_sym_RBRACE,
    ACTIONS(350), 1,
      anon_sym_PIPEmax_RBRACE,
  [1908] = 2,
    ACTIONS(352), 1,
      anon_sym_RBRACE,
    ACTIONS(354), 1,
      anon_sym_PIPEmax_RBRACE,
  [1915] = 2,
    ACTIONS(356), 1,
      anon_sym_RBRACE,
    ACTIONS(358), 1,
      anon_sym_PIPE,
  [1922] = 2,
    ACTIONS(360), 1,
      anon_sym_RBRACE,
    ACTIONS(362), 1,
      anon_sym_PIPE,
  [1929] = 2,
    ACTIONS(364), 1,
      anon_sym_RBRACE,
    ACTIONS(366), 1,
      anon_sym_PIPEmax_RBRACE,
  [1936] = 2,
    ACTIONS(368), 1,
      anon_sym_RBRACE,
    ACTIONS(370), 1,
      anon_sym_PIPEmax_RBRACE,
  [1943] = 2,
    ACTIONS(372), 1,
      anon_sym_RBRACE,
    ACTIONS(374), 1,
      anon_sym_PIPE,
  [1950] = 2,
    ACTIONS(376), 1,
      anon_sym_RBRACE,
    ACTIONS(378), 1,
      anon_sym_PIPE,
  [1957] = 1,
    ACTIONS(380), 1,
      anon_sym_PIPE,
  [1961] = 1,
    ACTIONS(382), 1,
      anon_sym_RBRACE,
  [1965] = 1,
    ACTIONS(384), 1,
      anon_sym_RBRACE,
  [1969] = 1,
    ACTIONS(224), 1,
      aux_sym__number_signable_token1,
  [1973] = 1,
    ACTIONS(386), 1,
      anon_sym_RBRACE,
  [1977] = 1,
    ACTIONS(388), 1,
      anon_sym_PIPE,
  [1981] = 1,
    ACTIONS(390), 1,
      anon_sym_PIPE,
  [1985] = 1,
    ACTIONS(392), 1,
      anon_sym_PIPE,
  [1989] = 1,
    ACTIONS(394), 1,
      anon_sym_RBRACE,
  [1993] = 1,
    ACTIONS(396), 1,
      anon_sym_RBRACE,
  [1997] = 1,
    ACTIONS(398), 1,
      ts_builtin_sym_end,
  [2001] = 1,
    ACTIONS(400), 1,
      anon_sym_RBRACE,
  [2005] = 1,
    ACTIONS(402), 1,
      anon_sym_PIPE,
  [2009] = 1,
    ACTIONS(404), 1,
      anon_sym_PIPE,
  [2013] = 1,
    ACTIONS(406), 1,
      anon_sym_PIPE,
  [2017] = 1,
    ACTIONS(408), 1,
      anon_sym_PIPE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 51,
  [SMALL_STATE(4)] = 102,
  [SMALL_STATE(5)] = 153,
  [SMALL_STATE(6)] = 204,
  [SMALL_STATE(7)] = 255,
  [SMALL_STATE(8)] = 287,
  [SMALL_STATE(9)] = 319,
  [SMALL_STATE(10)] = 351,
  [SMALL_STATE(11)] = 383,
  [SMALL_STATE(12)] = 415,
  [SMALL_STATE(13)] = 447,
  [SMALL_STATE(14)] = 481,
  [SMALL_STATE(15)] = 515,
  [SMALL_STATE(16)] = 549,
  [SMALL_STATE(17)] = 581,
  [SMALL_STATE(18)] = 615,
  [SMALL_STATE(19)] = 646,
  [SMALL_STATE(20)] = 677,
  [SMALL_STATE(21)] = 702,
  [SMALL_STATE(22)] = 729,
  [SMALL_STATE(23)] = 753,
  [SMALL_STATE(24)] = 777,
  [SMALL_STATE(25)] = 803,
  [SMALL_STATE(26)] = 827,
  [SMALL_STATE(27)] = 853,
  [SMALL_STATE(28)] = 877,
  [SMALL_STATE(29)] = 903,
  [SMALL_STATE(30)] = 927,
  [SMALL_STATE(31)] = 952,
  [SMALL_STATE(32)] = 971,
  [SMALL_STATE(33)] = 990,
  [SMALL_STATE(34)] = 1009,
  [SMALL_STATE(35)] = 1028,
  [SMALL_STATE(36)] = 1041,
  [SMALL_STATE(37)] = 1054,
  [SMALL_STATE(38)] = 1067,
  [SMALL_STATE(39)] = 1084,
  [SMALL_STATE(40)] = 1097,
  [SMALL_STATE(41)] = 1110,
  [SMALL_STATE(42)] = 1127,
  [SMALL_STATE(43)] = 1150,
  [SMALL_STATE(44)] = 1163,
  [SMALL_STATE(45)] = 1176,
  [SMALL_STATE(46)] = 1189,
  [SMALL_STATE(47)] = 1202,
  [SMALL_STATE(48)] = 1215,
  [SMALL_STATE(49)] = 1228,
  [SMALL_STATE(50)] = 1241,
  [SMALL_STATE(51)] = 1254,
  [SMALL_STATE(52)] = 1277,
  [SMALL_STATE(53)] = 1290,
  [SMALL_STATE(54)] = 1305,
  [SMALL_STATE(55)] = 1322,
  [SMALL_STATE(56)] = 1335,
  [SMALL_STATE(57)] = 1358,
  [SMALL_STATE(58)] = 1371,
  [SMALL_STATE(59)] = 1391,
  [SMALL_STATE(60)] = 1411,
  [SMALL_STATE(61)] = 1423,
  [SMALL_STATE(62)] = 1435,
  [SMALL_STATE(63)] = 1447,
  [SMALL_STATE(64)] = 1459,
  [SMALL_STATE(65)] = 1471,
  [SMALL_STATE(66)] = 1483,
  [SMALL_STATE(67)] = 1503,
  [SMALL_STATE(68)] = 1515,
  [SMALL_STATE(69)] = 1527,
  [SMALL_STATE(70)] = 1539,
  [SMALL_STATE(71)] = 1551,
  [SMALL_STATE(72)] = 1562,
  [SMALL_STATE(73)] = 1577,
  [SMALL_STATE(74)] = 1592,
  [SMALL_STATE(75)] = 1603,
  [SMALL_STATE(76)] = 1618,
  [SMALL_STATE(77)] = 1629,
  [SMALL_STATE(78)] = 1640,
  [SMALL_STATE(79)] = 1655,
  [SMALL_STATE(80)] = 1666,
  [SMALL_STATE(81)] = 1677,
  [SMALL_STATE(82)] = 1688,
  [SMALL_STATE(83)] = 1699,
  [SMALL_STATE(84)] = 1713,
  [SMALL_STATE(85)] = 1727,
  [SMALL_STATE(86)] = 1741,
  [SMALL_STATE(87)] = 1753,
  [SMALL_STATE(88)] = 1765,
  [SMALL_STATE(89)] = 1779,
  [SMALL_STATE(90)] = 1793,
  [SMALL_STATE(91)] = 1807,
  [SMALL_STATE(92)] = 1818,
  [SMALL_STATE(93)] = 1829,
  [SMALL_STATE(94)] = 1840,
  [SMALL_STATE(95)] = 1851,
  [SMALL_STATE(96)] = 1862,
  [SMALL_STATE(97)] = 1873,
  [SMALL_STATE(98)] = 1880,
  [SMALL_STATE(99)] = 1887,
  [SMALL_STATE(100)] = 1894,
  [SMALL_STATE(101)] = 1901,
  [SMALL_STATE(102)] = 1908,
  [SMALL_STATE(103)] = 1915,
  [SMALL_STATE(104)] = 1922,
  [SMALL_STATE(105)] = 1929,
  [SMALL_STATE(106)] = 1936,
  [SMALL_STATE(107)] = 1943,
  [SMALL_STATE(108)] = 1950,
  [SMALL_STATE(109)] = 1957,
  [SMALL_STATE(110)] = 1961,
  [SMALL_STATE(111)] = 1965,
  [SMALL_STATE(112)] = 1969,
  [SMALL_STATE(113)] = 1973,
  [SMALL_STATE(114)] = 1977,
  [SMALL_STATE(115)] = 1981,
  [SMALL_STATE(116)] = 1985,
  [SMALL_STATE(117)] = 1989,
  [SMALL_STATE(118)] = 1993,
  [SMALL_STATE(119)] = 1997,
  [SMALL_STATE(120)] = 2001,
  [SMALL_STATE(121)] = 2005,
  [SMALL_STATE(122)] = 2009,
  [SMALL_STATE(123)] = 2013,
  [SMALL_STATE(124)] = 2017,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inlineRoll_repeat1, 2), SHIFT_REPEAT(33),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inlineRoll_repeat1, 2), SHIFT_REPEAT(51),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inlineRoll_repeat1, 2), SHIFT_REPEAT(58),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inlineRoll_repeat1, 2), SHIFT_REPEAT(6),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_inlineRoll_repeat1, 2),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inlineRoll_repeat1, 2), SHIFT_REPEAT(15),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inlineRoll_repeat1, 2), SHIFT_REPEAT(29),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_inlineRoll_repeat1, 2), SHIFT_REPEAT(30),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat3, 2),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat3, 2), SHIFT_REPEAT(51),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat3, 2), SHIFT_REPEAT(58),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat3, 2), SHIFT_REPEAT(6),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat3, 2), SHIFT_REPEAT(7),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__number_signable_repeat3, 2),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_signable, 3),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [80] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_signable, 3),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_signable, 5),
  [84] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_signable, 5),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_signable, 4),
  [88] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_signable, 4),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat2, 2),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat2, 2), SHIFT_REPEAT(51),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat2, 2), SHIFT_REPEAT(58),
  [98] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat2, 2), SHIFT_REPEAT(6),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__number_signable_repeat2, 2),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_signable, 6),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_signable, 6),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_signable, 2),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_signable, 2),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_signable, 1),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_signable, 1),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__number_unsignable, 2),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__number_unsignable, 2),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 1),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2),
  [133] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(19),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(19),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(42),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(66),
  [145] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(4),
  [148] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2), SHIFT_REPEAT(51),
  [151] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2), SHIFT_REPEAT(58),
  [154] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2), SHIFT_REPEAT(6),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__number_signable_repeat1, 2),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [165] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(24),
  [168] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(56),
  [171] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(59),
  [174] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_label_repeat1, 2), SHIFT_REPEAT(24),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_label_repeat1, 2),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [187] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [195] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__labels, 1),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__labels_repeat1, 2),
  [211] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__labels_repeat1, 2), SHIFT_REPEAT(30),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__labels, 2),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inlineRoll, 3),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inlineRoll, 3),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 3),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 3),
  [236] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [238] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [240] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 2),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__labels_repeat1, 2),
  [250] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 3),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 3),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 4),
  [256] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 4),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number, 1),
  [260] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number, 1),
  [262] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inlineRoll, 2),
  [264] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inlineRoll, 2),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5, .production_id = 3),
  [272] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5, .production_id = 3),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [278] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__labels_repeat1, 1), SHIFT_REPEAT(44),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__labels_repeat1, 1),
  [283] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__labels_repeat1, 1),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5, .production_id = 3),
  [287] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5, .production_id = 3),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 3),
  [291] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_label, 3),
  [293] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [295] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(72),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2),
  [300] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(72),
  [303] = {.entry = {.count = 1, .reusable = false}}, SHIFT(72),
  [305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_identifier, 1),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [309] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [313] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(78),
  [316] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(78),
  [319] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [323] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [325] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability_identifier, 1),
  [327] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_ability_identifier_repeat1, 2), SHIFT_REPEAT(87),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ability_identifier_repeat1, 2),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [390] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 2),
  [392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 1),
  [394] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [398] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_roll20_script_external_scanner_create(void);
void tree_sitter_roll20_script_external_scanner_destroy(void *);
bool tree_sitter_roll20_script_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_roll20_script_external_scanner_serialize(void *, char *);
void tree_sitter_roll20_script_external_scanner_deserialize(void *, const char *, unsigned);

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
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_roll20_script_external_scanner_create,
      tree_sitter_roll20_script_external_scanner_destroy,
      tree_sitter_roll20_script_external_scanner_scan,
      tree_sitter_roll20_script_external_scanner_serialize,
      tree_sitter_roll20_script_external_scanner_deserialize,
    },
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
