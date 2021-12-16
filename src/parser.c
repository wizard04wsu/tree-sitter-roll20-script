#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 126
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 50
#define ALIAS_COUNT 1
#define TOKEN_COUNT 22
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 16

enum {
  aux_sym_script_token1 = 1,
  anon_sym_AMP = 2,
  sym_html_entity = 3,
  aux_sym__placeholder_or_text_token1 = 4,
  anon_sym_target = 5,
  anon_sym_selected = 6,
  anon_sym_AT_LBRACE = 7,
  anon_sym_RBRACE = 8,
  anon_sym_PIPE = 9,
  anon_sym_PIPEmax_RBRACE = 10,
  aux_sym_attribute_identifier_token1 = 11,
  anon_sym_PERCENT_LBRACE = 12,
  aux_sym_ability_identifier_token1 = 13,
  anon_sym_POUND = 14,
  anon_sym_ = 15,
  aux_sym__macro_inProperty_name_recurse_token1 = 16,
  aux_sym__macro_inProperty_name_recurse_token2 = 17,
  aux_sym__macro_inProperty_name_recurse_token3 = 18,
  aux_sym__macro_inRoot_and_wsp_token1 = 19,
  aux_sym__macro_inRoot_name_recurse_token1 = 20,
  sym___EOF = 21,
  sym_script = 22,
  sym__html_entity_or_text = 23,
  sym__placeholder_or_text = 24,
  sym__placeholder = 25,
  sym_character_token_identifier = 26,
  sym__attribute = 27,
  sym_attribute = 28,
  sym__attribute_of_character = 29,
  sym__attribute_of_character_maximum = 30,
  sym_attribute_identifier = 31,
  sym_ability = 32,
  sym_ability_identifier = 33,
  sym__macro_inProperty_and_wsp_or_text = 34,
  sym__macro_inProperty_and_wsp = 35,
  sym__macro_inProperty = 36,
  sym__macro_inProperty_name = 37,
  sym__macro_inProperty_name_recurse = 38,
  sym__macro_inRoot_and_wsp_or_text = 39,
  sym__macro_inRoot_and_wsp = 40,
  sym__macro_inRoot = 41,
  sym__macro_inRoot_name = 42,
  sym__macro_inRoot_name_recurse = 43,
  aux_sym_script_repeat1 = 44,
  aux_sym_attribute_identifier_repeat1 = 45,
  aux_sym_ability_identifier_repeat1 = 46,
  aux_sym__macro_inProperty_name_repeat1 = 47,
  aux_sym__macro_inProperty_name_recurse_repeat1 = 48,
  aux_sym__macro_inRoot_name_recurse_repeat1 = 49,
  alias_sym_character_identifier = 50,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_script_token1] = "script_token1",
  [anon_sym_AMP] = "ambiguous",
  [sym_html_entity] = "html_entity",
  [aux_sym__placeholder_or_text_token1] = "ambiguous",
  [anon_sym_target] = "target",
  [anon_sym_selected] = "selected",
  [anon_sym_AT_LBRACE] = "@{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_PIPE] = "|",
  [anon_sym_PIPEmax_RBRACE] = "|max}",
  [aux_sym_attribute_identifier_token1] = "attribute_identifier_token1",
  [anon_sym_PERCENT_LBRACE] = "%{",
  [aux_sym_ability_identifier_token1] = "ability_identifier_token1",
  [anon_sym_POUND] = "ambiguous",
  [anon_sym_] = " ",
  [aux_sym__macro_inProperty_name_recurse_token1] = "_macro_inProperty_name_recurse_token1",
  [aux_sym__macro_inProperty_name_recurse_token2] = "_macro_inProperty_name_recurse_token2",
  [aux_sym__macro_inProperty_name_recurse_token3] = "_macro_inProperty_name_recurse_token3",
  [aux_sym__macro_inRoot_and_wsp_token1] = "_macro_inRoot_and_wsp_token1",
  [aux_sym__macro_inRoot_name_recurse_token1] = "_macro_inRoot_name_recurse_token1",
  [sym___EOF] = "__EOF",
  [sym_script] = "script",
  [sym__html_entity_or_text] = "_html_entity_or_text",
  [sym__placeholder_or_text] = "_placeholder_or_text",
  [sym__placeholder] = "_placeholder",
  [sym_character_token_identifier] = "character_token_identifier",
  [sym__attribute] = "_attribute",
  [sym_attribute] = "attribute",
  [sym__attribute_of_character] = "attribute",
  [sym__attribute_of_character_maximum] = "attribute_maximum",
  [sym_attribute_identifier] = "attribute_identifier",
  [sym_ability] = "ability",
  [sym_ability_identifier] = "ability_identifier",
  [sym__macro_inProperty_and_wsp_or_text] = "_macro_inProperty_and_wsp_or_text",
  [sym__macro_inProperty_and_wsp] = "_macro_inProperty_and_wsp",
  [sym__macro_inProperty] = "macro",
  [sym__macro_inProperty_name] = "name",
  [sym__macro_inProperty_name_recurse] = "_macro_inProperty_name_recurse",
  [sym__macro_inRoot_and_wsp_or_text] = "_macro_inRoot_and_wsp_or_text",
  [sym__macro_inRoot_and_wsp] = "_macro_inRoot_and_wsp",
  [sym__macro_inRoot] = "macro",
  [sym__macro_inRoot_name] = "name",
  [sym__macro_inRoot_name_recurse] = "_macro_inRoot_name_recurse",
  [aux_sym_script_repeat1] = "script_repeat1",
  [aux_sym_attribute_identifier_repeat1] = "attribute_identifier_repeat1",
  [aux_sym_ability_identifier_repeat1] = "ability_identifier_repeat1",
  [aux_sym__macro_inProperty_name_repeat1] = "_macro_inProperty_name_repeat1",
  [aux_sym__macro_inProperty_name_recurse_repeat1] = "_macro_inProperty_name_recurse_repeat1",
  [aux_sym__macro_inRoot_name_recurse_repeat1] = "_macro_inRoot_name_recurse_repeat1",
  [alias_sym_character_identifier] = "character_identifier",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_script_token1] = aux_sym_script_token1,
  [anon_sym_AMP] = anon_sym_AMP,
  [sym_html_entity] = sym_html_entity,
  [aux_sym__placeholder_or_text_token1] = anon_sym_AMP,
  [anon_sym_target] = anon_sym_target,
  [anon_sym_selected] = anon_sym_selected,
  [anon_sym_AT_LBRACE] = anon_sym_AT_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_PIPEmax_RBRACE] = anon_sym_PIPEmax_RBRACE,
  [aux_sym_attribute_identifier_token1] = aux_sym_attribute_identifier_token1,
  [anon_sym_PERCENT_LBRACE] = anon_sym_PERCENT_LBRACE,
  [aux_sym_ability_identifier_token1] = aux_sym_ability_identifier_token1,
  [anon_sym_POUND] = anon_sym_AMP,
  [anon_sym_] = anon_sym_,
  [aux_sym__macro_inProperty_name_recurse_token1] = aux_sym__macro_inProperty_name_recurse_token1,
  [aux_sym__macro_inProperty_name_recurse_token2] = aux_sym__macro_inProperty_name_recurse_token2,
  [aux_sym__macro_inProperty_name_recurse_token3] = aux_sym__macro_inProperty_name_recurse_token3,
  [aux_sym__macro_inRoot_and_wsp_token1] = aux_sym__macro_inRoot_and_wsp_token1,
  [aux_sym__macro_inRoot_name_recurse_token1] = aux_sym__macro_inRoot_name_recurse_token1,
  [sym___EOF] = sym___EOF,
  [sym_script] = sym_script,
  [sym__html_entity_or_text] = sym__html_entity_or_text,
  [sym__placeholder_or_text] = sym__placeholder_or_text,
  [sym__placeholder] = sym__placeholder,
  [sym_character_token_identifier] = sym_character_token_identifier,
  [sym__attribute] = sym__attribute,
  [sym_attribute] = sym_attribute,
  [sym__attribute_of_character] = sym_attribute,
  [sym__attribute_of_character_maximum] = sym__attribute_of_character_maximum,
  [sym_attribute_identifier] = sym_attribute_identifier,
  [sym_ability] = sym_ability,
  [sym_ability_identifier] = sym_ability_identifier,
  [sym__macro_inProperty_and_wsp_or_text] = sym__macro_inProperty_and_wsp_or_text,
  [sym__macro_inProperty_and_wsp] = sym__macro_inProperty_and_wsp,
  [sym__macro_inProperty] = sym__macro_inProperty,
  [sym__macro_inProperty_name] = sym__macro_inProperty_name,
  [sym__macro_inProperty_name_recurse] = sym__macro_inProperty_name_recurse,
  [sym__macro_inRoot_and_wsp_or_text] = sym__macro_inRoot_and_wsp_or_text,
  [sym__macro_inRoot_and_wsp] = sym__macro_inRoot_and_wsp,
  [sym__macro_inRoot] = sym__macro_inProperty,
  [sym__macro_inRoot_name] = sym__macro_inProperty_name,
  [sym__macro_inRoot_name_recurse] = sym__macro_inRoot_name_recurse,
  [aux_sym_script_repeat1] = aux_sym_script_repeat1,
  [aux_sym_attribute_identifier_repeat1] = aux_sym_attribute_identifier_repeat1,
  [aux_sym_ability_identifier_repeat1] = aux_sym_ability_identifier_repeat1,
  [aux_sym__macro_inProperty_name_repeat1] = aux_sym__macro_inProperty_name_repeat1,
  [aux_sym__macro_inProperty_name_recurse_repeat1] = aux_sym__macro_inProperty_name_recurse_repeat1,
  [aux_sym__macro_inRoot_name_recurse_repeat1] = aux_sym__macro_inRoot_name_recurse_repeat1,
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
  [anon_sym_AMP] = {
    .visible = true,
    .named = true,
  },
  [sym_html_entity] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__placeholder_or_text_token1] = {
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
  [anon_sym_POUND] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__macro_inProperty_name_recurse_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__macro_inProperty_name_recurse_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__macro_inProperty_name_recurse_token3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__macro_inRoot_and_wsp_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__macro_inRoot_name_recurse_token1] = {
    .visible = false,
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
  [sym__html_entity_or_text] = {
    .visible = false,
    .named = true,
  },
  [sym__placeholder_or_text] = {
    .visible = false,
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
  [sym__macro_inProperty_and_wsp_or_text] = {
    .visible = false,
    .named = true,
  },
  [sym__macro_inProperty_and_wsp] = {
    .visible = false,
    .named = true,
  },
  [sym__macro_inProperty] = {
    .visible = true,
    .named = true,
  },
  [sym__macro_inProperty_name] = {
    .visible = true,
    .named = true,
  },
  [sym__macro_inProperty_name_recurse] = {
    .visible = false,
    .named = true,
  },
  [sym__macro_inRoot_and_wsp_or_text] = {
    .visible = false,
    .named = true,
  },
  [sym__macro_inRoot_and_wsp] = {
    .visible = false,
    .named = true,
  },
  [sym__macro_inRoot] = {
    .visible = true,
    .named = true,
  },
  [sym__macro_inRoot_name] = {
    .visible = true,
    .named = true,
  },
  [sym__macro_inRoot_name_recurse] = {
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
  [aux_sym__macro_inProperty_name_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__macro_inProperty_name_recurse_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__macro_inRoot_name_recurse_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_character_identifier] = {
    .visible = true,
    .named = true,
  },
};

enum {
  field_a = 1,
  field_b = 2,
  field_c = 3,
  field_selected = 4,
  field_target = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_a] = "a",
  [field_b] = "b",
  [field_c] = "c",
  [field_selected] = "selected",
  [field_target] = "target",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 2},
  [6] = {.index = 6, .length = 1},
  [7] = {.index = 7, .length = 1},
  [8] = {.index = 8, .length = 2},
  [9] = {.index = 10, .length = 1},
  [10] = {.index = 11, .length = 1},
  [11] = {.index = 12, .length = 2},
  [12] = {.index = 14, .length = 1},
  [14] = {.index = 15, .length = 1},
  [15] = {.index = 16, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_a, 0},
  [1] =
    {field_a, 0, .inherited = true},
  [2] =
    {field_target, 0},
  [3] =
    {field_selected, 0},
  [4] =
    {field_b, 0},
    {field_c, 1, .inherited = true},
  [6] =
    {field_c, 0, .inherited = true},
  [7] =
    {field_b, 0, .inherited = true},
  [8] =
    {field_a, 0, .inherited = true},
    {field_a, 1, .inherited = true},
  [10] =
    {field_c, 1},
  [11] =
    {field_c, 1, .inherited = true},
  [12] =
    {field_c, 0, .inherited = true},
    {field_c, 1, .inherited = true},
  [14] =
    {field_c, 2, .inherited = true},
  [15] =
    {field_c, 3, .inherited = true},
  [16] =
    {field_c, 0, .inherited = true},
    {field_c, 3, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [13] = {
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
      if (lookahead == '\n') ADVANCE(107);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ' ') ADVANCE(85);
      if (lookahead == '#') ADVANCE(84);
      if (lookahead == '%') ADVANCE(33);
      if (lookahead == '&') ADVANCE(26);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == 's') ADVANCE(94);
      if (lookahead == 't') ADVANCE(91);
      if (lookahead == '{') ADVANCE(86);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '}') ADVANCE(43);
      if (lookahead != 0) ADVANCE(103);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(107);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(85);
      if (lookahead == '#') ADVANCE(84);
      if (lookahead == '%') ADVANCE(87);
      if (lookahead == '@') ADVANCE(88);
      if (lookahead == '{') ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(103);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(62);
      if (lookahead == '#') ADVANCE(84);
      if (lookahead == '%') ADVANCE(59);
      if (lookahead == '&') ADVANCE(26);
      if (lookahead == '@') ADVANCE(60);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '}') ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(46);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(62);
      if (lookahead == '#') ADVANCE(84);
      if (lookahead == '%') ADVANCE(59);
      if (lookahead == '&') ADVANCE(26);
      if (lookahead == '@') ADVANCE(60);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(46);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(84);
      if (lookahead == '&') ADVANCE(27);
      if (lookahead == 's') ADVANCE(50);
      if (lookahead == 't') ADVANCE(47);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(84);
      if (lookahead == '&') ADVANCE(27);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '}') ADVANCE(43);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(62);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(84);
      if (lookahead == '&') ADVANCE(27);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(43);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(62);
      END_STATE();
    case 8:
      if (lookahead == '&') ADVANCE(27);
      if (lookahead == 's') ADVANCE(70);
      if (lookahead == 't') ADVANCE(67);
      if (lookahead == '{') ADVANCE(79);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 9:
      if (lookahead == '&') ADVANCE(27);
      if (lookahead == '{') ADVANCE(79);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '}') ADVANCE(43);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(81);
      END_STATE();
    case 10:
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(15);
      END_STATE();
    case 14:
      if (lookahead == 'm') ADVANCE(13);
      END_STATE();
    case 15:
      if (lookahead == 'x') ADVANCE(16);
      END_STATE();
    case 16:
      if (lookahead == '}') ADVANCE(45);
      END_STATE();
    case 17:
      if (lookahead == '\n' ||
          lookahead == ' ') ADVANCE(107);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '#') ADVANCE(84);
      if (lookahead == '%') ADVANCE(87);
      if (lookahead == '@') ADVANCE(88);
      if (lookahead == '{') ADVANCE(86);
      if (lookahead != 0) ADVANCE(109);
      END_STATE();
    case 18:
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(19);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 19:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 20:
      if (eof) ADVANCE(22);
      if (lookahead == '\n' ||
          lookahead == ' ') ADVANCE(25);
      if (lookahead == '\r') ADVANCE(25);
      if (lookahead == '#') ADVANCE(84);
      if (lookahead == '%') ADVANCE(33);
      if (lookahead == '&') ADVANCE(28);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '{') ADVANCE(24);
      if (lookahead != 0) ADVANCE(23);
      END_STATE();
    case 21:
      if (eof) ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '@') ADVANCE(25);
      if (lookahead == '\r') ADVANCE(25);
      if (lookahead == '#') ADVANCE(84);
      if (lookahead == '%') ADVANCE(32);
      if (lookahead == '&') ADVANCE(27);
      if (lookahead == '@') ADVANCE(34);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '\n' ||
          lookahead == ' ' ||
          lookahead == '{') ADVANCE(25);
      if (lookahead == '\r') ADVANCE(25);
      if (lookahead == '&') ADVANCE(109);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@') ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead != 0 &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(25);
      if (lookahead == '\r') ADVANCE(25);
      if (lookahead == '{') ADVANCE(24);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(89);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead != 0 &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '@') ADVANCE(25);
      if (lookahead == '\r') ADVANCE(25);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '#') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(90);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '#') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '#') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(108);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(109);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_html_entity);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_html_entity);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_html_entity);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(109);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym__placeholder_or_text_token1);
      if (lookahead == '{') ADVANCE(66);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym__placeholder_or_text_token1);
      if (lookahead == '{') ADVANCE(66);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(89);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym__placeholder_or_text_token1);
      if (lookahead == '{') ADVANCE(42);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym__placeholder_or_text_token1);
      if (lookahead == '{') ADVANCE(42);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(89);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_PIPEmax_RBRACE);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == ' ') ADVANCE(62);
      if (lookahead == '&') ADVANCE(103);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'a') ADVANCE(56);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'c') ADVANCE(58);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'd') ADVANCE(39);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(55);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(48);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(49);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(57);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'g') ADVANCE(53);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'l') ADVANCE(51);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'r') ADVANCE(54);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 't') ADVANCE(36);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 't') ADVANCE(52);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(66);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(63);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(42);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(63);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(63);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(63);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_PERCENT_LBRACE);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'a') ADVANCE(76);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'c') ADVANCE(78);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'd') ADVANCE(40);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(75);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(69);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(77);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'g') ADVANCE(73);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'l') ADVANCE(71);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'r') ADVANCE(74);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 't') ADVANCE(37);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 't') ADVANCE(72);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(79);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(79);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(80);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(81);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(79);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token1);
      if (lookahead == '{') ADVANCE(86);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(89);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token1);
      if (lookahead == '{') ADVANCE(66);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(89);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token1);
      if (lookahead == '{') ADVANCE(42);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(89);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(89);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == ';') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(90);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 'a') ADVANCE(100);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 'c') ADVANCE(102);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 'd') ADVANCE(41);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 'e') ADVANCE(99);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 'e') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 'e') ADVANCE(93);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 'e') ADVANCE(101);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 'g') ADVANCE(97);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 'l') ADVANCE(95);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 'r') ADVANCE(98);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 't') ADVANCE(38);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == 't') ADVANCE(96);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(103);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == '{') ADVANCE(86);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(89);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == '{') ADVANCE(105);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(106);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(106);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym__macro_inRoot_and_wsp_token1);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym__macro_inRoot_name_recurse_token1);
      if (lookahead == ';') ADVANCE(31);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(108);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(109);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym__macro_inRoot_name_recurse_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(109);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 21},
  [2] = {.lex_state = 3},
  [3] = {.lex_state = 21},
  [4] = {.lex_state = 20},
  [5] = {.lex_state = 21},
  [6] = {.lex_state = 4},
  [7] = {.lex_state = 17, .external_lex_state = 1},
  [8] = {.lex_state = 17, .external_lex_state = 1},
  [9] = {.lex_state = 17, .external_lex_state = 1},
  [10] = {.lex_state = 17, .external_lex_state = 1},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 17, .external_lex_state = 1},
  [15] = {.lex_state = 5},
  [16] = {.lex_state = 5},
  [17] = {.lex_state = 17, .external_lex_state = 1},
  [18] = {.lex_state = 5},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 6},
  [22] = {.lex_state = 17, .external_lex_state = 1},
  [23] = {.lex_state = 17, .external_lex_state = 1},
  [24] = {.lex_state = 6},
  [25] = {.lex_state = 7},
  [26] = {.lex_state = 7},
  [27] = {.lex_state = 6},
  [28] = {.lex_state = 6},
  [29] = {.lex_state = 6},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 6},
  [32] = {.lex_state = 6},
  [33] = {.lex_state = 6},
  [34] = {.lex_state = 8},
  [35] = {.lex_state = 8},
  [36] = {.lex_state = 8},
  [37] = {.lex_state = 21},
  [38] = {.lex_state = 21},
  [39] = {.lex_state = 21},
  [40] = {.lex_state = 21},
  [41] = {.lex_state = 21},
  [42] = {.lex_state = 21},
  [43] = {.lex_state = 21},
  [44] = {.lex_state = 21},
  [45] = {.lex_state = 21},
  [46] = {.lex_state = 21},
  [47] = {.lex_state = 21},
  [48] = {.lex_state = 9},
  [49] = {.lex_state = 9},
  [50] = {.lex_state = 6},
  [51] = {.lex_state = 9},
  [52] = {.lex_state = 17, .external_lex_state = 1},
  [53] = {.lex_state = 9},
  [54] = {.lex_state = 7},
  [55] = {.lex_state = 17, .external_lex_state = 1},
  [56] = {.lex_state = 17, .external_lex_state = 1},
  [57] = {.lex_state = 17, .external_lex_state = 1},
  [58] = {.lex_state = 17, .external_lex_state = 1},
  [59] = {.lex_state = 17, .external_lex_state = 1},
  [60] = {.lex_state = 17, .external_lex_state = 1},
  [61] = {.lex_state = 17, .external_lex_state = 1},
  [62] = {.lex_state = 9},
  [63] = {.lex_state = 9},
  [64] = {.lex_state = 9},
  [65] = {.lex_state = 9},
  [66] = {.lex_state = 2},
  [67] = {.lex_state = 2},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 2},
  [72] = {.lex_state = 2},
  [73] = {.lex_state = 2},
  [74] = {.lex_state = 104},
  [75] = {.lex_state = 104},
  [76] = {.lex_state = 104},
  [77] = {.lex_state = 104},
  [78] = {.lex_state = 17, .external_lex_state = 1},
  [79] = {.lex_state = 4},
  [80] = {.lex_state = 17, .external_lex_state = 1},
  [81] = {.lex_state = 17, .external_lex_state = 1},
  [82] = {.lex_state = 17, .external_lex_state = 1},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 17, .external_lex_state = 1},
  [86] = {.lex_state = 4},
  [87] = {.lex_state = 4},
  [88] = {.lex_state = 2},
  [89] = {.lex_state = 17, .external_lex_state = 1},
  [90] = {.lex_state = 104},
  [91] = {.lex_state = 17},
  [92] = {.lex_state = 17, .external_lex_state = 1},
  [93] = {.lex_state = 104},
  [94] = {.lex_state = 104},
  [95] = {.lex_state = 4},
  [96] = {.lex_state = 4},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 4},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 2},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 105},
  [111] = {.lex_state = 2},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 105},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 2},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
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
    [anon_sym_AMP] = ACTIONS(1),
    [sym_html_entity] = ACTIONS(1),
    [aux_sym__placeholder_or_text_token1] = ACTIONS(1),
    [anon_sym_target] = ACTIONS(1),
    [anon_sym_selected] = ACTIONS(1),
    [anon_sym_AT_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [aux_sym__macro_inProperty_name_recurse_token1] = ACTIONS(1),
    [aux_sym__macro_inProperty_name_recurse_token2] = ACTIONS(1),
    [aux_sym__macro_inRoot_and_wsp_token1] = ACTIONS(1),
    [sym___EOF] = ACTIONS(1),
  },
  [1] = {
    [sym_script] = STATE(117),
    [sym__html_entity_or_text] = STATE(5),
    [sym__placeholder_or_text] = STATE(5),
    [sym__placeholder] = STATE(5),
    [sym__attribute] = STATE(5),
    [sym_attribute] = STATE(5),
    [sym__attribute_of_character] = STATE(5),
    [sym__attribute_of_character_maximum] = STATE(5),
    [sym_ability] = STATE(5),
    [sym__macro_inRoot_and_wsp_or_text] = STATE(47),
    [sym__macro_inRoot_and_wsp] = STATE(47),
    [sym__macro_inRoot] = STATE(80),
    [aux_sym_script_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_script_token1] = ACTIONS(5),
    [anon_sym_AMP] = ACTIONS(7),
    [sym_html_entity] = ACTIONS(5),
    [aux_sym__placeholder_or_text_token1] = ACTIONS(7),
    [anon_sym_AT_LBRACE] = ACTIONS(9),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(11),
    [anon_sym_POUND] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(25), 1,
      aux_sym__macro_inProperty_name_recurse_token2,
    STATE(74), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(106), 1,
      sym__macro_inProperty_name,
    STATE(107), 1,
      sym__macro_inProperty_name_recurse,
    ACTIONS(15), 3,
      anon_sym_AMP,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(19), 3,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      anon_sym_POUND,
    STATE(13), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [41] = 9,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(38), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(41), 1,
      anon_sym_POUND,
    STATE(80), 1,
      sym__macro_inRoot,
    ACTIONS(29), 2,
      aux_sym_script_token1,
      sym_html_entity,
    ACTIONS(32), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    STATE(47), 2,
      sym__macro_inRoot_and_wsp_or_text,
      sym__macro_inRoot_and_wsp,
    STATE(3), 9,
      sym__html_entity_or_text,
      sym__placeholder_or_text,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_script_repeat1,
  [80] = 10,
    ACTIONS(48), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(50), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(52), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(54), 1,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(76), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(85), 1,
      sym__macro_inRoot_name,
    STATE(89), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(44), 2,
      ts_builtin_sym_end,
      anon_sym_POUND,
    ACTIONS(46), 4,
      aux_sym_script_token1,
      anon_sym_AMP,
      sym_html_entity,
      aux_sym__placeholder_or_text_token1,
    STATE(9), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [121] = 9,
    ACTIONS(9), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(11), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(13), 1,
      anon_sym_POUND,
    ACTIONS(56), 1,
      ts_builtin_sym_end,
    STATE(80), 1,
      sym__macro_inRoot,
    ACTIONS(58), 2,
      aux_sym_script_token1,
      sym_html_entity,
    ACTIONS(60), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    STATE(47), 2,
      sym__macro_inRoot_and_wsp_or_text,
      sym__macro_inRoot_and_wsp,
    STATE(3), 9,
      sym__html_entity_or_text,
      sym__placeholder_or_text,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym_script_repeat1,
  [160] = 10,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(25), 1,
      aux_sym__macro_inProperty_name_recurse_token2,
    STATE(74), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(106), 1,
      sym__macro_inProperty_name,
    STATE(107), 1,
      sym__macro_inProperty_name_recurse,
    ACTIONS(15), 3,
      anon_sym_AMP,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(19), 3,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
      anon_sym_POUND,
    STATE(13), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [201] = 8,
    ACTIONS(48), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(50), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(52), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(64), 1,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(76), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(81), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(62), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    STATE(14), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [233] = 8,
    ACTIONS(48), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(50), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(52), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(64), 1,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(76), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(82), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(66), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    STATE(14), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [265] = 8,
    ACTIONS(48), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(50), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(52), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(64), 1,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(76), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(92), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(68), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    STATE(14), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [297] = 8,
    ACTIONS(48), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(50), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(52), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(64), 1,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(76), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(78), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(70), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    STATE(14), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [329] = 8,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(72), 1,
      anon_sym_,
    ACTIONS(74), 1,
      aux_sym__macro_inProperty_name_recurse_token2,
    STATE(74), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(104), 1,
      sym__macro_inProperty_name_recurse,
    STATE(20), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [360] = 8,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(74), 1,
      aux_sym__macro_inProperty_name_recurse_token2,
    ACTIONS(76), 1,
      anon_sym_,
    STATE(74), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(121), 1,
      sym__macro_inProperty_name_recurse,
    STATE(20), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [391] = 8,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(23), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(74), 1,
      aux_sym__macro_inProperty_name_recurse_token2,
    ACTIONS(78), 1,
      anon_sym_,
    STATE(74), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(111), 1,
      sym__macro_inProperty_name_recurse,
    STATE(20), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [422] = 5,
    ACTIONS(80), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(83), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(86), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(88), 3,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(14), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [446] = 9,
    ACTIONS(92), 1,
      sym_html_entity,
    ACTIONS(94), 1,
      anon_sym_target,
    ACTIONS(96), 1,
      anon_sym_selected,
    ACTIONS(98), 1,
      anon_sym_POUND,
    STATE(101), 1,
      sym_attribute_identifier,
    STATE(116), 1,
      sym__macro_inProperty,
    STATE(124), 1,
      sym_character_token_identifier,
    ACTIONS(90), 2,
      anon_sym_AMP,
      aux_sym_attribute_identifier_token1,
    STATE(21), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [478] = 9,
    ACTIONS(92), 1,
      sym_html_entity,
    ACTIONS(94), 1,
      anon_sym_target,
    ACTIONS(96), 1,
      anon_sym_selected,
    ACTIONS(98), 1,
      anon_sym_POUND,
    STATE(83), 1,
      sym_attribute_identifier,
    STATE(116), 1,
      sym__macro_inProperty,
    STATE(118), 1,
      sym_character_token_identifier,
    ACTIONS(90), 2,
      anon_sym_AMP,
      aux_sym_attribute_identifier_token1,
    STATE(21), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [510] = 6,
    ACTIONS(48), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(50), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(100), 1,
      anon_sym_POUND,
    ACTIONS(104), 1,
      aux_sym__macro_inRoot_name_recurse_token1,
    ACTIONS(102), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    STATE(10), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [536] = 9,
    ACTIONS(92), 1,
      sym_html_entity,
    ACTIONS(94), 1,
      anon_sym_target,
    ACTIONS(96), 1,
      anon_sym_selected,
    ACTIONS(98), 1,
      anon_sym_POUND,
    STATE(97), 1,
      sym_attribute_identifier,
    STATE(116), 1,
      sym__macro_inProperty,
    STATE(122), 1,
      sym_character_token_identifier,
    ACTIONS(90), 2,
      anon_sym_AMP,
      aux_sym_attribute_identifier_token1,
    STATE(21), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [568] = 5,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(108), 1,
      anon_sym_,
    ACTIONS(106), 2,
      anon_sym_POUND,
      aux_sym__macro_inProperty_name_recurse_token2,
    STATE(12), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [591] = 5,
    ACTIONS(86), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(110), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(113), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(88), 2,
      anon_sym_,
      aux_sym__macro_inProperty_name_recurse_token2,
    STATE(20), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [614] = 6,
    ACTIONS(98), 1,
      anon_sym_POUND,
    ACTIONS(116), 1,
      anon_sym_AMP,
    STATE(116), 1,
      sym__macro_inProperty,
    ACTIONS(118), 2,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(120), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    STATE(24), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [638] = 4,
    ACTIONS(48), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(50), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(70), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    STATE(7), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [658] = 4,
    ACTIONS(48), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(50), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(122), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    STATE(8), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [678] = 6,
    ACTIONS(124), 1,
      anon_sym_AMP,
    ACTIONS(132), 1,
      anon_sym_POUND,
    STATE(116), 1,
      sym__macro_inProperty,
    ACTIONS(127), 2,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(130), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    STATE(24), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [702] = 6,
    ACTIONS(135), 1,
      anon_sym_AMP,
    ACTIONS(139), 1,
      anon_sym_POUND,
    STATE(105), 1,
      sym__macro_inProperty,
    ACTIONS(120), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(137), 2,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    STATE(26), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [726] = 6,
    ACTIONS(141), 1,
      anon_sym_AMP,
    ACTIONS(147), 1,
      anon_sym_POUND,
    STATE(105), 1,
      sym__macro_inProperty,
    ACTIONS(130), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(144), 2,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    STATE(26), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [750] = 6,
    ACTIONS(139), 1,
      anon_sym_POUND,
    ACTIONS(150), 1,
      anon_sym_AMP,
    STATE(86), 1,
      sym_attribute_identifier,
    STATE(105), 1,
      sym__macro_inProperty,
    ACTIONS(152), 2,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    STATE(25), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [773] = 6,
    ACTIONS(139), 1,
      anon_sym_POUND,
    ACTIONS(150), 1,
      anon_sym_AMP,
    STATE(87), 1,
      sym_attribute_identifier,
    STATE(105), 1,
      sym__macro_inProperty,
    ACTIONS(152), 2,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    STATE(25), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [796] = 6,
    ACTIONS(139), 1,
      anon_sym_POUND,
    ACTIONS(150), 1,
      anon_sym_AMP,
    STATE(95), 1,
      sym_attribute_identifier,
    STATE(105), 1,
      sym__macro_inProperty,
    ACTIONS(152), 2,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    STATE(25), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [819] = 4,
    ACTIONS(17), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(21), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(76), 1,
      anon_sym_,
    STATE(11), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [838] = 6,
    ACTIONS(139), 1,
      anon_sym_POUND,
    ACTIONS(150), 1,
      anon_sym_AMP,
    STATE(96), 1,
      sym_attribute_identifier,
    STATE(105), 1,
      sym__macro_inProperty,
    ACTIONS(152), 2,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    STATE(25), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [861] = 6,
    ACTIONS(139), 1,
      anon_sym_POUND,
    ACTIONS(150), 1,
      anon_sym_AMP,
    STATE(79), 1,
      sym_attribute_identifier,
    STATE(105), 1,
      sym__macro_inProperty,
    ACTIONS(152), 2,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    STATE(25), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [884] = 6,
    ACTIONS(139), 1,
      anon_sym_POUND,
    ACTIONS(150), 1,
      anon_sym_AMP,
    STATE(100), 1,
      sym_attribute_identifier,
    STATE(105), 1,
      sym__macro_inProperty,
    ACTIONS(152), 2,
      sym_html_entity,
      aux_sym_attribute_identifier_token1,
    STATE(25), 4,
      sym__html_entity_or_text,
      sym__macro_inProperty_and_wsp_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [907] = 7,
    ACTIONS(94), 1,
      anon_sym_target,
    ACTIONS(96), 1,
      anon_sym_selected,
    ACTIONS(156), 1,
      sym_html_entity,
    STATE(99), 1,
      sym_ability_identifier,
    STATE(123), 1,
      sym_character_token_identifier,
    ACTIONS(154), 2,
      anon_sym_AMP,
      aux_sym_ability_identifier_token1,
    STATE(49), 2,
      sym__html_entity_or_text,
      aux_sym_ability_identifier_repeat1,
  [931] = 7,
    ACTIONS(94), 1,
      anon_sym_target,
    ACTIONS(96), 1,
      anon_sym_selected,
    ACTIONS(156), 1,
      sym_html_entity,
    STATE(98), 1,
      sym_ability_identifier,
    STATE(125), 1,
      sym_character_token_identifier,
    ACTIONS(154), 2,
      anon_sym_AMP,
      aux_sym_ability_identifier_token1,
    STATE(49), 2,
      sym__html_entity_or_text,
      aux_sym_ability_identifier_repeat1,
  [955] = 7,
    ACTIONS(94), 1,
      anon_sym_target,
    ACTIONS(96), 1,
      anon_sym_selected,
    ACTIONS(156), 1,
      sym_html_entity,
    STATE(84), 1,
      sym_ability_identifier,
    STATE(115), 1,
      sym_character_token_identifier,
    ACTIONS(154), 2,
      anon_sym_AMP,
      aux_sym_ability_identifier_token1,
    STATE(49), 2,
      sym__html_entity_or_text,
      aux_sym_ability_identifier_repeat1,
  [979] = 2,
    ACTIONS(160), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(158), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_html_entity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND,
  [992] = 2,
    ACTIONS(164), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(162), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_html_entity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND,
  [1005] = 2,
    ACTIONS(168), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(166), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_html_entity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND,
  [1018] = 2,
    ACTIONS(164), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(162), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_html_entity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND,
  [1031] = 2,
    ACTIONS(172), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(170), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_html_entity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND,
  [1044] = 2,
    ACTIONS(176), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(174), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_html_entity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND,
  [1057] = 2,
    ACTIONS(180), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(178), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_html_entity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND,
  [1070] = 2,
    ACTIONS(184), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(182), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_html_entity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND,
  [1083] = 2,
    ACTIONS(188), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(186), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_html_entity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND,
  [1096] = 2,
    ACTIONS(192), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(190), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_html_entity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND,
  [1109] = 2,
    ACTIONS(196), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(194), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_html_entity,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND,
  [1122] = 4,
    ACTIONS(198), 1,
      anon_sym_AMP,
    ACTIONS(201), 2,
      sym_html_entity,
      aux_sym_ability_identifier_token1,
    ACTIONS(204), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    STATE(48), 2,
      sym__html_entity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1138] = 4,
    ACTIONS(206), 1,
      anon_sym_AMP,
    ACTIONS(208), 2,
      sym_html_entity,
      aux_sym_ability_identifier_token1,
    ACTIONS(210), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    STATE(48), 2,
      sym__html_entity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1154] = 2,
    ACTIONS(212), 1,
      anon_sym_AMP,
    ACTIONS(214), 5,
      sym_html_entity,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_attribute_identifier_token1,
      anon_sym_POUND,
  [1165] = 4,
    ACTIONS(154), 1,
      anon_sym_AMP,
    STATE(112), 1,
      sym_ability_identifier,
    ACTIONS(156), 2,
      sym_html_entity,
      aux_sym_ability_identifier_token1,
    STATE(49), 2,
      sym__html_entity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1180] = 2,
    ACTIONS(176), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(174), 5,
      sym___EOF,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1191] = 4,
    ACTIONS(154), 1,
      anon_sym_AMP,
    STATE(108), 1,
      sym_ability_identifier,
    ACTIONS(156), 2,
      sym_html_entity,
      aux_sym_ability_identifier_token1,
    STATE(49), 2,
      sym__html_entity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1206] = 2,
    ACTIONS(212), 1,
      anon_sym_AMP,
    ACTIONS(214), 5,
      sym_html_entity,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
      aux_sym_attribute_identifier_token1,
      anon_sym_POUND,
  [1217] = 2,
    ACTIONS(184), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(182), 5,
      sym___EOF,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1228] = 2,
    ACTIONS(168), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(166), 5,
      sym___EOF,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1239] = 2,
    ACTIONS(160), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(158), 5,
      sym___EOF,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1250] = 2,
    ACTIONS(172), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(170), 5,
      sym___EOF,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1261] = 2,
    ACTIONS(192), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(190), 5,
      sym___EOF,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1272] = 2,
    ACTIONS(188), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(186), 5,
      sym___EOF,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1283] = 2,
    ACTIONS(180), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(178), 5,
      sym___EOF,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1294] = 4,
    ACTIONS(154), 1,
      anon_sym_AMP,
    STATE(103), 1,
      sym_ability_identifier,
    ACTIONS(156), 2,
      sym_html_entity,
      aux_sym_ability_identifier_token1,
    STATE(49), 2,
      sym__html_entity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1309] = 4,
    ACTIONS(154), 1,
      anon_sym_AMP,
    STATE(102), 1,
      sym_ability_identifier,
    ACTIONS(156), 2,
      sym_html_entity,
      aux_sym_ability_identifier_token1,
    STATE(49), 2,
      sym__html_entity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1324] = 4,
    ACTIONS(154), 1,
      anon_sym_AMP,
    STATE(114), 1,
      sym_ability_identifier,
    ACTIONS(156), 2,
      sym_html_entity,
      aux_sym_ability_identifier_token1,
    STATE(49), 2,
      sym__html_entity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1339] = 4,
    ACTIONS(154), 1,
      anon_sym_AMP,
    STATE(109), 1,
      sym_ability_identifier,
    ACTIONS(156), 2,
      sym_html_entity,
      aux_sym_ability_identifier_token1,
    STATE(49), 2,
      sym__html_entity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1354] = 2,
    ACTIONS(168), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(166), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_,
      aux_sym__macro_inProperty_name_recurse_token2,
  [1364] = 2,
    ACTIONS(172), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(170), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_,
      aux_sym__macro_inProperty_name_recurse_token2,
  [1374] = 2,
    ACTIONS(184), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(182), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_,
      aux_sym__macro_inProperty_name_recurse_token2,
  [1384] = 2,
    ACTIONS(160), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(158), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_,
      aux_sym__macro_inProperty_name_recurse_token2,
  [1394] = 2,
    ACTIONS(176), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(174), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_,
      aux_sym__macro_inProperty_name_recurse_token2,
  [1404] = 2,
    ACTIONS(188), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(186), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_,
      aux_sym__macro_inProperty_name_recurse_token2,
  [1414] = 2,
    ACTIONS(180), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(178), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_,
      aux_sym__macro_inProperty_name_recurse_token2,
  [1424] = 2,
    ACTIONS(192), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(190), 4,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_,
      aux_sym__macro_inProperty_name_recurse_token2,
  [1434] = 3,
    ACTIONS(216), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(218), 1,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(77), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
  [1444] = 3,
    ACTIONS(220), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(223), 1,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(75), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
  [1454] = 3,
    ACTIONS(225), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(227), 1,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(75), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
  [1464] = 3,
    ACTIONS(229), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(232), 1,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(77), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
  [1474] = 1,
    ACTIONS(234), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1479] = 2,
    ACTIONS(236), 1,
      anon_sym_RBRACE,
    ACTIONS(238), 1,
      anon_sym_PIPEmax_RBRACE,
  [1486] = 2,
    ACTIONS(240), 1,
      aux_sym__macro_inRoot_and_wsp_token1,
    ACTIONS(242), 1,
      sym___EOF,
  [1493] = 1,
    ACTIONS(244), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1498] = 1,
    ACTIONS(246), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1503] = 2,
    ACTIONS(248), 1,
      anon_sym_RBRACE,
    ACTIONS(250), 1,
      anon_sym_PIPE,
  [1510] = 2,
    ACTIONS(252), 1,
      anon_sym_RBRACE,
    ACTIONS(254), 1,
      anon_sym_PIPE,
  [1517] = 1,
    ACTIONS(256), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1522] = 2,
    ACTIONS(258), 1,
      anon_sym_RBRACE,
    ACTIONS(260), 1,
      anon_sym_PIPEmax_RBRACE,
  [1529] = 2,
    ACTIONS(262), 1,
      anon_sym_RBRACE,
    ACTIONS(264), 1,
      anon_sym_PIPEmax_RBRACE,
  [1536] = 1,
    ACTIONS(106), 2,
      anon_sym_POUND,
      aux_sym__macro_inProperty_name_recurse_token2,
  [1541] = 1,
    ACTIONS(266), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1546] = 2,
    ACTIONS(232), 1,
      aux_sym__macro_inProperty_name_recurse_token3,
    ACTIONS(268), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
  [1553] = 2,
    ACTIONS(100), 1,
      anon_sym_POUND,
    ACTIONS(104), 1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1560] = 1,
    ACTIONS(270), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1565] = 2,
    ACTIONS(272), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(274), 1,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1572] = 2,
    ACTIONS(276), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(278), 1,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1579] = 2,
    ACTIONS(280), 1,
      anon_sym_RBRACE,
    ACTIONS(282), 1,
      anon_sym_PIPEmax_RBRACE,
  [1586] = 2,
    ACTIONS(284), 1,
      anon_sym_RBRACE,
    ACTIONS(286), 1,
      anon_sym_PIPEmax_RBRACE,
  [1593] = 2,
    ACTIONS(288), 1,
      anon_sym_RBRACE,
    ACTIONS(290), 1,
      anon_sym_PIPE,
  [1600] = 2,
    ACTIONS(292), 1,
      anon_sym_RBRACE,
    ACTIONS(294), 1,
      anon_sym_PIPE,
  [1607] = 2,
    ACTIONS(296), 1,
      anon_sym_RBRACE,
    ACTIONS(298), 1,
      anon_sym_PIPE,
  [1614] = 2,
    ACTIONS(300), 1,
      anon_sym_RBRACE,
    ACTIONS(302), 1,
      anon_sym_PIPEmax_RBRACE,
  [1621] = 2,
    ACTIONS(304), 1,
      anon_sym_RBRACE,
    ACTIONS(306), 1,
      anon_sym_PIPE,
  [1628] = 1,
    ACTIONS(308), 1,
      anon_sym_RBRACE,
  [1632] = 1,
    ACTIONS(310), 1,
      anon_sym_RBRACE,
  [1636] = 1,
    ACTIONS(312), 1,
      anon_sym_,
  [1640] = 1,
    ACTIONS(314), 1,
      anon_sym_,
  [1644] = 1,
    ACTIONS(316), 1,
      anon_sym_,
  [1648] = 1,
    ACTIONS(78), 1,
      anon_sym_,
  [1652] = 1,
    ACTIONS(318), 1,
      anon_sym_RBRACE,
  [1656] = 1,
    ACTIONS(320), 1,
      anon_sym_RBRACE,
  [1660] = 1,
    ACTIONS(322), 1,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1664] = 1,
    ACTIONS(324), 1,
      anon_sym_,
  [1668] = 1,
    ACTIONS(326), 1,
      anon_sym_RBRACE,
  [1672] = 1,
    ACTIONS(328), 1,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1676] = 1,
    ACTIONS(330), 1,
      anon_sym_RBRACE,
  [1680] = 1,
    ACTIONS(332), 1,
      anon_sym_PIPE,
  [1684] = 1,
    ACTIONS(334), 1,
      anon_sym_,
  [1688] = 1,
    ACTIONS(336), 1,
      ts_builtin_sym_end,
  [1692] = 1,
    ACTIONS(338), 1,
      anon_sym_PIPE,
  [1696] = 1,
    ACTIONS(340), 1,
      anon_sym_PIPE,
  [1700] = 1,
    ACTIONS(342), 1,
      anon_sym_PIPE,
  [1704] = 1,
    ACTIONS(72), 1,
      anon_sym_,
  [1708] = 1,
    ACTIONS(344), 1,
      anon_sym_PIPE,
  [1712] = 1,
    ACTIONS(346), 1,
      anon_sym_PIPE,
  [1716] = 1,
    ACTIONS(348), 1,
      anon_sym_PIPE,
  [1720] = 1,
    ACTIONS(350), 1,
      anon_sym_PIPE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 41,
  [SMALL_STATE(4)] = 80,
  [SMALL_STATE(5)] = 121,
  [SMALL_STATE(6)] = 160,
  [SMALL_STATE(7)] = 201,
  [SMALL_STATE(8)] = 233,
  [SMALL_STATE(9)] = 265,
  [SMALL_STATE(10)] = 297,
  [SMALL_STATE(11)] = 329,
  [SMALL_STATE(12)] = 360,
  [SMALL_STATE(13)] = 391,
  [SMALL_STATE(14)] = 422,
  [SMALL_STATE(15)] = 446,
  [SMALL_STATE(16)] = 478,
  [SMALL_STATE(17)] = 510,
  [SMALL_STATE(18)] = 536,
  [SMALL_STATE(19)] = 568,
  [SMALL_STATE(20)] = 591,
  [SMALL_STATE(21)] = 614,
  [SMALL_STATE(22)] = 638,
  [SMALL_STATE(23)] = 658,
  [SMALL_STATE(24)] = 678,
  [SMALL_STATE(25)] = 702,
  [SMALL_STATE(26)] = 726,
  [SMALL_STATE(27)] = 750,
  [SMALL_STATE(28)] = 773,
  [SMALL_STATE(29)] = 796,
  [SMALL_STATE(30)] = 819,
  [SMALL_STATE(31)] = 838,
  [SMALL_STATE(32)] = 861,
  [SMALL_STATE(33)] = 884,
  [SMALL_STATE(34)] = 907,
  [SMALL_STATE(35)] = 931,
  [SMALL_STATE(36)] = 955,
  [SMALL_STATE(37)] = 979,
  [SMALL_STATE(38)] = 992,
  [SMALL_STATE(39)] = 1005,
  [SMALL_STATE(40)] = 1018,
  [SMALL_STATE(41)] = 1031,
  [SMALL_STATE(42)] = 1044,
  [SMALL_STATE(43)] = 1057,
  [SMALL_STATE(44)] = 1070,
  [SMALL_STATE(45)] = 1083,
  [SMALL_STATE(46)] = 1096,
  [SMALL_STATE(47)] = 1109,
  [SMALL_STATE(48)] = 1122,
  [SMALL_STATE(49)] = 1138,
  [SMALL_STATE(50)] = 1154,
  [SMALL_STATE(51)] = 1165,
  [SMALL_STATE(52)] = 1180,
  [SMALL_STATE(53)] = 1191,
  [SMALL_STATE(54)] = 1206,
  [SMALL_STATE(55)] = 1217,
  [SMALL_STATE(56)] = 1228,
  [SMALL_STATE(57)] = 1239,
  [SMALL_STATE(58)] = 1250,
  [SMALL_STATE(59)] = 1261,
  [SMALL_STATE(60)] = 1272,
  [SMALL_STATE(61)] = 1283,
  [SMALL_STATE(62)] = 1294,
  [SMALL_STATE(63)] = 1309,
  [SMALL_STATE(64)] = 1324,
  [SMALL_STATE(65)] = 1339,
  [SMALL_STATE(66)] = 1354,
  [SMALL_STATE(67)] = 1364,
  [SMALL_STATE(68)] = 1374,
  [SMALL_STATE(69)] = 1384,
  [SMALL_STATE(70)] = 1394,
  [SMALL_STATE(71)] = 1404,
  [SMALL_STATE(72)] = 1414,
  [SMALL_STATE(73)] = 1424,
  [SMALL_STATE(74)] = 1434,
  [SMALL_STATE(75)] = 1444,
  [SMALL_STATE(76)] = 1454,
  [SMALL_STATE(77)] = 1464,
  [SMALL_STATE(78)] = 1474,
  [SMALL_STATE(79)] = 1479,
  [SMALL_STATE(80)] = 1486,
  [SMALL_STATE(81)] = 1493,
  [SMALL_STATE(82)] = 1498,
  [SMALL_STATE(83)] = 1503,
  [SMALL_STATE(84)] = 1510,
  [SMALL_STATE(85)] = 1517,
  [SMALL_STATE(86)] = 1522,
  [SMALL_STATE(87)] = 1529,
  [SMALL_STATE(88)] = 1536,
  [SMALL_STATE(89)] = 1541,
  [SMALL_STATE(90)] = 1546,
  [SMALL_STATE(91)] = 1553,
  [SMALL_STATE(92)] = 1560,
  [SMALL_STATE(93)] = 1565,
  [SMALL_STATE(94)] = 1572,
  [SMALL_STATE(95)] = 1579,
  [SMALL_STATE(96)] = 1586,
  [SMALL_STATE(97)] = 1593,
  [SMALL_STATE(98)] = 1600,
  [SMALL_STATE(99)] = 1607,
  [SMALL_STATE(100)] = 1614,
  [SMALL_STATE(101)] = 1621,
  [SMALL_STATE(102)] = 1628,
  [SMALL_STATE(103)] = 1632,
  [SMALL_STATE(104)] = 1636,
  [SMALL_STATE(105)] = 1640,
  [SMALL_STATE(106)] = 1644,
  [SMALL_STATE(107)] = 1648,
  [SMALL_STATE(108)] = 1652,
  [SMALL_STATE(109)] = 1656,
  [SMALL_STATE(110)] = 1660,
  [SMALL_STATE(111)] = 1664,
  [SMALL_STATE(112)] = 1668,
  [SMALL_STATE(113)] = 1672,
  [SMALL_STATE(114)] = 1676,
  [SMALL_STATE(115)] = 1680,
  [SMALL_STATE(116)] = 1684,
  [SMALL_STATE(117)] = 1688,
  [SMALL_STATE(118)] = 1692,
  [SMALL_STATE(119)] = 1696,
  [SMALL_STATE(120)] = 1700,
  [SMALL_STATE(121)] = 1704,
  [SMALL_STATE(122)] = 1708,
  [SMALL_STATE(123)] = 1712,
  [SMALL_STATE(124)] = 1716,
  [SMALL_STATE(125)] = 1720,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro_inProperty_and_wsp_or_text, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_and_wsp_or_text, 1),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(110),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2, .production_id = 8),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2, .production_id = 8), SHIFT_REPEAT(3),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2, .production_id = 8), SHIFT_REPEAT(3),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2, .production_id = 8), SHIFT_REPEAT(16),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2, .production_id = 8), SHIFT_REPEAT(36),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2, .production_id = 8), SHIFT_REPEAT(4),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_and_wsp_or_text, 1, .production_id = 1),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro_inRoot_and_wsp_or_text, 1, .production_id = 1),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [52] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 1, .production_id = 2),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 3),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 3, .production_id = 6),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name, 1),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 2),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 3),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 2),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name, 1),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(18),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(34),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2),
  [90] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [94] = {.entry = {.count = 1, .reusable = false}}, SHIFT(120),
  [96] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 1),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 1),
  [110] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(15),
  [113] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(35),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_identifier, 1),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 2, .production_id = 6),
  [124] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(24),
  [127] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(24),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2),
  [132] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(2),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [141] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(26),
  [144] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(26),
  [147] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(6),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [154] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_and_wsp, 2, .production_id = 7),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro_inRoot_and_wsp, 2, .production_id = 7),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 13),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 13),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 3),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 3),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5, .production_id = 13),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5, .production_id = 13),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5, .production_id = 13),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5, .production_id = 13),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 1, .production_id = 2),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 1, .production_id = 2),
  [198] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_ability_identifier_repeat1, 2), SHIFT_REPEAT(48),
  [201] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_ability_identifier_repeat1, 2), SHIFT_REPEAT(48),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ability_identifier_repeat1, 2),
  [206] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability_identifier, 1),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro_inProperty_and_wsp, 2),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_and_wsp, 2),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [218] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [220] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2, .production_id = 11), SHIFT_REPEAT(91),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2, .production_id = 11),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [229] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_recurse_repeat1, 2), SHIFT_REPEAT(88),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_inProperty_name_recurse_repeat1, 2),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 3, .production_id = 12),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 4, .production_id = 14),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 4, .production_id = 15),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot, 2, .production_id = 5),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name, 1, .production_id = 6),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_recurse_repeat1, 2),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name, 2, .production_id = 10),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2),
  [274] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2, .production_id = 9),
  [278] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2, .production_id = 9),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 4),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty, 2),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name, 2),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [336] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 4),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 3),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
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
