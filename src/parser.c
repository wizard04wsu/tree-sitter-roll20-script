#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 121
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 49
#define ALIAS_COUNT 1
#define TOKEN_COUNT 23
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 5

enum {
  anon_sym_ = 1,
  aux_sym_script_token1 = 2,
  anon_sym_AMP = 3,
  sym_htmlEntity = 4,
  sym__ambiguousHash = 5,
  anon_sym_AT = 6,
  anon_sym_PERCENT = 7,
  anon_sym_target = 8,
  anon_sym_selected = 9,
  anon_sym_AT_LBRACE = 10,
  anon_sym_RBRACE = 11,
  anon_sym_PIPE = 12,
  anon_sym_PIPEmax_RBRACE = 13,
  aux_sym_attribute_identifier_token1 = 14,
  anon_sym_PERCENT_LBRACE = 15,
  aux_sym_ability_identifier_token1 = 16,
  aux_sym__macro_inProperty_name_recurse_token1 = 17,
  aux_sym__macro_inProperty_name_recurse_token2 = 18,
  aux_sym__macro_inProperty_name_recurse_token3 = 19,
  aux_sym__macro_inRoot_and_wsp_token1 = 20,
  aux_sym__macro_inRoot_name_recurse_token1 = 21,
  sym___EOF = 22,
  sym_script = 23,
  sym__htmlEntity_or_text = 24,
  sym__placeholder_or_text = 25,
  sym__placeholder = 26,
  sym_character_token_identifier = 27,
  sym__attribute = 28,
  sym_attribute = 29,
  sym__attribute_of_character = 30,
  sym__attribute_of_character_maximum = 31,
  sym_attribute_identifier = 32,
  sym_ability = 33,
  sym_ability_identifier = 34,
  sym__macro_inProperty_and_wsp = 35,
  sym__macro_inProperty = 36,
  sym__macro_inProperty_name = 37,
  sym__macro_inProperty_name_recurse = 38,
  sym__macro_inRoot_and_wsp = 39,
  sym__macro_inRoot = 40,
  sym__macro_inRoot_name = 41,
  sym__macro_inRoot_name_recurse = 42,
  aux_sym_script_repeat1 = 43,
  aux_sym_attribute_identifier_repeat1 = 44,
  aux_sym_ability_identifier_repeat1 = 45,
  aux_sym__macro_inProperty_name_repeat1 = 46,
  aux_sym__macro_inProperty_name_recurse_repeat1 = 47,
  aux_sym__macro_inRoot_name_recurse_repeat1 = 48,
  alias_sym_character_identifier = 49,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_] = " ",
  [aux_sym_script_token1] = "script_token1",
  [anon_sym_AMP] = "&",
  [sym_htmlEntity] = "htmlEntity",
  [sym__ambiguousHash] = "_ambiguousHash",
  [anon_sym_AT] = "@",
  [anon_sym_PERCENT] = "%",
  [anon_sym_target] = "target",
  [anon_sym_selected] = "selected",
  [anon_sym_AT_LBRACE] = "@{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_PIPE] = "|",
  [anon_sym_PIPEmax_RBRACE] = "|max}",
  [aux_sym_attribute_identifier_token1] = "attribute_identifier_token1",
  [anon_sym_PERCENT_LBRACE] = "%{",
  [aux_sym_ability_identifier_token1] = "ability_identifier_token1",
  [aux_sym__macro_inProperty_name_recurse_token1] = "_macro_inProperty_name_recurse_token1",
  [aux_sym__macro_inProperty_name_recurse_token2] = "_macro_inProperty_name_recurse_token2",
  [aux_sym__macro_inProperty_name_recurse_token3] = "_macro_inProperty_name_recurse_token3",
  [aux_sym__macro_inRoot_and_wsp_token1] = "_macro_inRoot_and_wsp_token1",
  [aux_sym__macro_inRoot_name_recurse_token1] = "_macro_inRoot_name_recurse_token1",
  [sym___EOF] = "__EOF",
  [sym_script] = "script",
  [sym__htmlEntity_or_text] = "_htmlEntity_or_text",
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
  [sym__macro_inProperty_and_wsp] = "_macro_inProperty_and_wsp",
  [sym__macro_inProperty] = "macro",
  [sym__macro_inProperty_name] = "name",
  [sym__macro_inProperty_name_recurse] = "_macro_inProperty_name_recurse",
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

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_] = anon_sym_,
  [aux_sym_script_token1] = aux_sym_script_token1,
  [anon_sym_AMP] = anon_sym_AMP,
  [sym_htmlEntity] = sym_htmlEntity,
  [sym__ambiguousHash] = sym__ambiguousHash,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_target] = anon_sym_target,
  [anon_sym_selected] = anon_sym_selected,
  [anon_sym_AT_LBRACE] = anon_sym_AT_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_PIPEmax_RBRACE] = anon_sym_PIPEmax_RBRACE,
  [aux_sym_attribute_identifier_token1] = aux_sym_attribute_identifier_token1,
  [anon_sym_PERCENT_LBRACE] = anon_sym_PERCENT_LBRACE,
  [aux_sym_ability_identifier_token1] = aux_sym_ability_identifier_token1,
  [aux_sym__macro_inProperty_name_recurse_token1] = aux_sym__macro_inProperty_name_recurse_token1,
  [aux_sym__macro_inProperty_name_recurse_token2] = aux_sym__macro_inProperty_name_recurse_token2,
  [aux_sym__macro_inProperty_name_recurse_token3] = aux_sym__macro_inProperty_name_recurse_token3,
  [aux_sym__macro_inRoot_and_wsp_token1] = aux_sym__macro_inRoot_and_wsp_token1,
  [aux_sym__macro_inRoot_name_recurse_token1] = aux_sym__macro_inRoot_name_recurse_token1,
  [sym___EOF] = sym___EOF,
  [sym_script] = sym_script,
  [sym__htmlEntity_or_text] = sym__htmlEntity_or_text,
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
  [sym__macro_inProperty_and_wsp] = sym__macro_inProperty_and_wsp,
  [sym__macro_inProperty] = sym__macro_inProperty,
  [sym__macro_inProperty_name] = sym__macro_inProperty_name,
  [sym__macro_inProperty_name_recurse] = sym__macro_inProperty_name_recurse,
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
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_script_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [sym_htmlEntity] = {
    .visible = true,
    .named = true,
  },
  [sym__ambiguousHash] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
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
  [sym__htmlEntity_or_text] = {
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
  field_selected = 1,
  field_target = 2,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_selected] = "selected",
  [field_target] = "target",
};

static const TSFieldMapSlice ts_field_map_slices[7] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_target, 0},
  [1] =
    {field_selected, 0},
};

static TSSymbol ts_alias_sequences[7][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [3] = {
    [1] = sym_ability_identifier,
  },
  [4] = {
    [1] = alias_sym_character_identifier,
  },
  [5] = {
    [3] = sym_ability_identifier,
  },
  [6] = {
    [1] = alias_sym_character_identifier,
    [3] = sym_ability_identifier,
  },
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(22);
      if (lookahead == '\n') ADVANCE(106);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ' ') ADVANCE(23);
      if (lookahead == '#') ADVANCE(35);
      if (lookahead == '%') ADVANCE(39);
      if (lookahead == '&') ADVANCE(29);
      if (lookahead == '@') ADVANCE(37);
      if (lookahead == 's') ADVANCE(96);
      if (lookahead == 't') ADVANCE(93);
      if (lookahead == '{') ADVANCE(91);
      if (lookahead == '|') ADVANCE(48);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead != 0) ADVANCE(105);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(106);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(23);
      if (lookahead == '#') ADVANCE(35);
      if (lookahead == '%') ADVANCE(88);
      if (lookahead == '@') ADVANCE(89);
      if (lookahead == '{') ADVANCE(91);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(105);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(24);
      if (lookahead == '#') ADVANCE(35);
      if (lookahead == '%') ADVANCE(63);
      if (lookahead == '&') ADVANCE(29);
      if (lookahead == '@') ADVANCE(64);
      if (lookahead == '{') ADVANCE(67);
      if (lookahead == '|') ADVANCE(48);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(50);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(24);
      if (lookahead == '#') ADVANCE(35);
      if (lookahead == '%') ADVANCE(63);
      if (lookahead == '&') ADVANCE(29);
      if (lookahead == '@') ADVANCE(64);
      if (lookahead == '{') ADVANCE(67);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(50);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(35);
      if (lookahead == '&') ADVANCE(30);
      if (lookahead == 's') ADVANCE(54);
      if (lookahead == 't') ADVANCE(51);
      if (lookahead == '{') ADVANCE(67);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(35);
      if (lookahead == '&') ADVANCE(30);
      if (lookahead == '{') ADVANCE(67);
      if (lookahead == '|') ADVANCE(48);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(66);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(35);
      if (lookahead == '&') ADVANCE(30);
      if (lookahead == '{') ADVANCE(67);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(66);
      END_STATE();
    case 8:
      if (lookahead == '&') ADVANCE(30);
      if (lookahead == 's') ADVANCE(74);
      if (lookahead == 't') ADVANCE(71);
      if (lookahead == '{') ADVANCE(83);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 9:
      if (lookahead == '&') ADVANCE(30);
      if (lookahead == '{') ADVANCE(83);
      if (lookahead == '|') ADVANCE(48);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(85);
      END_STATE();
    case 10:
      if (lookahead == ';') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == ';') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == ';') ADVANCE(32);
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
      if (lookahead == '}') ADVANCE(49);
      END_STATE();
    case 17:
      if (lookahead == '\n' ||
          lookahead == ' ') ADVANCE(106);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '#') ADVANCE(35);
      if (lookahead == '%') ADVANCE(88);
      if (lookahead == '@') ADVANCE(89);
      if (lookahead == '{') ADVANCE(91);
      if (lookahead != 0) ADVANCE(108);
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
      if (lookahead == ' ') ADVANCE(25);
      if (lookahead == '#') ADVANCE(35);
      if (lookahead == '%') ADVANCE(39);
      if (lookahead == '&') ADVANCE(31);
      if (lookahead == '@') ADVANCE(37);
      if (lookahead == '{') ADVANCE(27);
      if (lookahead == '\n' ||
          lookahead == '\r') ADVANCE(28);
      if (lookahead != 0) ADVANCE(26);
      END_STATE();
    case 21:
      if (eof) ADVANCE(22);
      if (lookahead == '#') ADVANCE(35);
      if (lookahead == '%') ADVANCE(38);
      if (lookahead == '&') ADVANCE(30);
      if (lookahead == '@') ADVANCE(36);
      if (lookahead != 0) ADVANCE(28);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '@') ADVANCE(28);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '&') ADVANCE(108);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ' ||
          lookahead == '{') ADVANCE(28);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@') ADVANCE(26);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead == '{') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '@') ADVANCE(28);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_script_token1);
      if (lookahead != 0 &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '&' &&
          lookahead != '@') ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '#') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '#') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '#') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(108);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_htmlEntity);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_htmlEntity);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(108);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_htmlEntity);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym__ambiguousHash);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead == '{') ADVANCE(46);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead == '{') ADVANCE(46);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(90);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '{') ADVANCE(70);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '{') ADVANCE(70);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(90);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
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
      if (lookahead == ' ') ADVANCE(66);
      if (lookahead == '&') ADVANCE(105);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(50);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'a') ADVANCE(60);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'c') ADVANCE(62);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'd') ADVANCE(43);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(59);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(52);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
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
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'e') ADVANCE(61);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'g') ADVANCE(57);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'l') ADVANCE(55);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 'r') ADVANCE(58);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 't') ADVANCE(40);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == 't') ADVANCE(56);
      if (lookahead == '{') ADVANCE(65);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(70);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(67);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(46);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(67);
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
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '{') ADVANCE(67);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(67);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(68);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_attribute_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(69);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '&' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(67);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_PERCENT_LBRACE);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'a') ADVANCE(80);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'c') ADVANCE(82);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'd') ADVANCE(44);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(79);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(72);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(73);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'e') ADVANCE(81);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'g') ADVANCE(77);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'l') ADVANCE(75);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 'r') ADVANCE(78);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 't') ADVANCE(41);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == 't') ADVANCE(76);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(83);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '{') ADVANCE(84);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(85);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(86);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '&' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(83);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_ability_identifier_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(87);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token1);
      if (lookahead == '{') ADVANCE(70);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(90);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token1);
      if (lookahead == '{') ADVANCE(46);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(90);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(90);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == '{') ADVANCE(91);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == ';') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'a') ADVANCE(102);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'c') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'd') ADVANCE(45);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'e') ADVANCE(101);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'e') ADVANCE(94);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'e') ADVANCE(95);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'e') ADVANCE(103);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'g') ADVANCE(99);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'l') ADVANCE(97);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'r') ADVANCE(100);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 't') ADVANCE(42);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 't') ADVANCE(98);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(105);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym__macro_inRoot_and_wsp_token1);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym__macro_inRoot_name_recurse_token1);
      if (lookahead == ';') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(107);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(108);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym__macro_inRoot_name_recurse_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(108);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 21},
  [2] = {.lex_state = 20},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 4},
  [5] = {.lex_state = 21},
  [6] = {.lex_state = 21},
  [7] = {.lex_state = 17, .external_lex_state = 1},
  [8] = {.lex_state = 17, .external_lex_state = 1},
  [9] = {.lex_state = 17, .external_lex_state = 1},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 17, .external_lex_state = 1},
  [14] = {.lex_state = 17, .external_lex_state = 1},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 17, .external_lex_state = 1},
  [18] = {.lex_state = 17, .external_lex_state = 1},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 5},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 5},
  [23] = {.lex_state = 5},
  [24] = {.lex_state = 7},
  [25] = {.lex_state = 6},
  [26] = {.lex_state = 6},
  [27] = {.lex_state = 7},
  [28] = {.lex_state = 21},
  [29] = {.lex_state = 21},
  [30] = {.lex_state = 21},
  [31] = {.lex_state = 21},
  [32] = {.lex_state = 17, .external_lex_state = 1},
  [33] = {.lex_state = 21},
  [34] = {.lex_state = 7},
  [35] = {.lex_state = 21},
  [36] = {.lex_state = 21},
  [37] = {.lex_state = 7},
  [38] = {.lex_state = 7},
  [39] = {.lex_state = 21},
  [40] = {.lex_state = 7},
  [41] = {.lex_state = 8},
  [42] = {.lex_state = 8},
  [43] = {.lex_state = 21},
  [44] = {.lex_state = 21},
  [45] = {.lex_state = 7},
  [46] = {.lex_state = 8},
  [47] = {.lex_state = 7},
  [48] = {.lex_state = 17, .external_lex_state = 1},
  [49] = {.lex_state = 17, .external_lex_state = 1},
  [50] = {.lex_state = 17, .external_lex_state = 1},
  [51] = {.lex_state = 17, .external_lex_state = 1},
  [52] = {.lex_state = 17, .external_lex_state = 1},
  [53] = {.lex_state = 17, .external_lex_state = 1},
  [54] = {.lex_state = 2},
  [55] = {.lex_state = 17, .external_lex_state = 1},
  [56] = {.lex_state = 17, .external_lex_state = 1},
  [57] = {.lex_state = 17, .external_lex_state = 1},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 9},
  [60] = {.lex_state = 2},
  [61] = {.lex_state = 2},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 2},
  [64] = {.lex_state = 2},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 2},
  [67] = {.lex_state = 9},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 9},
  [70] = {.lex_state = 6},
  [71] = {.lex_state = 9},
  [72] = {.lex_state = 9},
  [73] = {.lex_state = 7},
  [74] = {.lex_state = 9},
  [75] = {.lex_state = 7},
  [76] = {.lex_state = 9},
  [77] = {.lex_state = 6},
  [78] = {.lex_state = 9},
  [79] = {.lex_state = 4},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 17, .external_lex_state = 1},
  [82] = {.lex_state = 17, .external_lex_state = 1},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 17, .external_lex_state = 1},
  [85] = {.lex_state = 4},
  [86] = {.lex_state = 4},
  [87] = {.lex_state = 17, .external_lex_state = 1},
  [88] = {.lex_state = 17, .external_lex_state = 1},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 17, .external_lex_state = 1},
  [91] = {.lex_state = 17},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 4},
  [96] = {.lex_state = 4},
  [97] = {.lex_state = 4},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 2},
  [106] = {.lex_state = 2},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 2},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 2},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 2},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
};

enum {
  ts_external_token___EOF = 0,
};

static TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token___EOF] = sym___EOF,
};

static bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token___EOF] = true,
  },
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [sym_htmlEntity] = ACTIONS(1),
    [sym__ambiguousHash] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_target] = ACTIONS(1),
    [anon_sym_selected] = ACTIONS(1),
    [anon_sym_AT_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(1),
    [aux_sym__macro_inProperty_name_recurse_token1] = ACTIONS(1),
    [aux_sym__macro_inProperty_name_recurse_token2] = ACTIONS(1),
    [aux_sym__macro_inProperty_name_recurse_token3] = ACTIONS(1),
    [aux_sym__macro_inRoot_and_wsp_token1] = ACTIONS(1),
    [sym___EOF] = ACTIONS(1),
  },
  [1] = {
    [sym_script] = STATE(112),
    [sym__htmlEntity_or_text] = STATE(5),
    [sym__placeholder_or_text] = STATE(5),
    [sym__placeholder] = STATE(5),
    [sym__attribute] = STATE(5),
    [sym_attribute] = STATE(5),
    [sym__attribute_of_character] = STATE(5),
    [sym__attribute_of_character_maximum] = STATE(5),
    [sym_ability] = STATE(5),
    [sym__macro_inRoot_and_wsp] = STATE(5),
    [sym__macro_inRoot] = STATE(87),
    [aux_sym_script_repeat1] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_script_token1] = ACTIONS(5),
    [anon_sym_AMP] = ACTIONS(7),
    [sym_htmlEntity] = ACTIONS(5),
    [sym__ambiguousHash] = ACTIONS(9),
    [anon_sym_AT] = ACTIONS(7),
    [anon_sym_PERCENT] = ACTIONS(7),
    [anon_sym_AT_LBRACE] = ACTIONS(11),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(13),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 12,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      anon_sym_,
    ACTIONS(21), 1,
      sym__ambiguousHash,
    ACTIONS(23), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(27), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(13), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(88), 1,
      sym__macro_inRoot_name,
    STATE(90), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(29), 2,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_name_recurse_token1,
    ACTIONS(19), 5,
      aux_sym_script_token1,
      anon_sym_AMP,
      sym_htmlEntity,
      anon_sym_AT,
      anon_sym_PERCENT,
    STATE(9), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [48] = 12,
    ACTIONS(31), 1,
      anon_sym_,
    ACTIONS(35), 1,
      sym__ambiguousHash,
    ACTIONS(37), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(41), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(43), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(15), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(100), 1,
      sym__macro_inProperty_name_recurse,
    STATE(113), 1,
      sym__macro_inProperty_name,
    ACTIONS(39), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(45), 2,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
    ACTIONS(33), 3,
      anon_sym_AMP,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(11), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [95] = 12,
    ACTIONS(35), 1,
      sym__ambiguousHash,
    ACTIONS(37), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(41), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(43), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(47), 1,
      anon_sym_,
    STATE(15), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(100), 1,
      sym__macro_inProperty_name_recurse,
    STATE(113), 1,
      sym__macro_inProperty_name,
    ACTIONS(39), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(45), 2,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
    ACTIONS(33), 3,
      anon_sym_AMP,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(11), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [142] = 8,
    ACTIONS(9), 1,
      sym__ambiguousHash,
    ACTIONS(11), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(13), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    STATE(87), 1,
      sym__macro_inRoot,
    ACTIONS(51), 2,
      aux_sym_script_token1,
      sym_htmlEntity,
    ACTIONS(53), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    STATE(6), 10,
      sym__htmlEntity_or_text,
      sym__placeholder_or_text,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym__macro_inRoot_and_wsp,
      aux_sym_script_repeat1,
  [179] = 8,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    ACTIONS(63), 1,
      sym__ambiguousHash,
    ACTIONS(66), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(69), 1,
      anon_sym_PERCENT_LBRACE,
    STATE(87), 1,
      sym__macro_inRoot,
    ACTIONS(57), 2,
      aux_sym_script_token1,
      sym_htmlEntity,
    ACTIONS(60), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    STATE(6), 10,
      sym__htmlEntity_or_text,
      sym__placeholder_or_text,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      sym__macro_inRoot_and_wsp,
      aux_sym_script_repeat1,
  [216] = 8,
    ACTIONS(23), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(27), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(13), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(84), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(72), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    ACTIONS(21), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(14), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [250] = 8,
    ACTIONS(23), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(27), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(13), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(82), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(74), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    ACTIONS(21), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(14), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [284] = 8,
    ACTIONS(23), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(27), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(13), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(81), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(76), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    ACTIONS(21), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(14), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [318] = 8,
    ACTIONS(37), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(41), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(43), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(78), 1,
      anon_sym_,
    STATE(15), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(110), 1,
      sym__macro_inProperty_name_recurse,
    ACTIONS(35), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(16), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [351] = 8,
    ACTIONS(37), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(41), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(43), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(80), 1,
      anon_sym_,
    STATE(15), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(116), 1,
      sym__macro_inProperty_name_recurse,
    ACTIONS(35), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(16), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [384] = 8,
    ACTIONS(37), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(41), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(43), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(82), 1,
      anon_sym_,
    STATE(15), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(106), 1,
      sym__macro_inProperty_name_recurse,
    ACTIONS(35), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(16), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [417] = 7,
    ACTIONS(23), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(86), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(32), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    ACTIONS(88), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    ACTIONS(84), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(8), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [448] = 5,
    ACTIONS(92), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(95), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(98), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(90), 5,
      sym___EOF,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
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
  [474] = 7,
    ACTIONS(37), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(41), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(100), 1,
      anon_sym_,
    ACTIONS(104), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(54), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    ACTIONS(102), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(10), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [504] = 5,
    ACTIONS(98), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(106), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(109), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(90), 4,
      anon_sym_,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(16), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [529] = 5,
    ACTIONS(23), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(88), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    ACTIONS(112), 2,
      sym__ambiguousHash,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(8), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [553] = 5,
    ACTIONS(23), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(74), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    ACTIONS(112), 2,
      sym__ambiguousHash,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(7), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [577] = 5,
    ACTIONS(37), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(41), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(100), 1,
      anon_sym_,
    ACTIONS(114), 2,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(10), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [600] = 9,
    ACTIONS(118), 1,
      sym_htmlEntity,
    ACTIONS(120), 1,
      sym__ambiguousHash,
    ACTIONS(122), 1,
      anon_sym_target,
    ACTIONS(124), 1,
      anon_sym_selected,
    STATE(80), 1,
      sym_attribute_identifier,
    STATE(105), 1,
      sym__macro_inProperty,
    STATE(119), 1,
      sym_character_token_identifier,
    ACTIONS(116), 2,
      anon_sym_AMP,
      aux_sym_attribute_identifier_token1,
    STATE(25), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [631] = 5,
    ACTIONS(37), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(41), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(78), 1,
      anon_sym_,
    ACTIONS(114), 2,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(12), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [654] = 9,
    ACTIONS(118), 1,
      sym_htmlEntity,
    ACTIONS(120), 1,
      sym__ambiguousHash,
    ACTIONS(122), 1,
      anon_sym_target,
    ACTIONS(124), 1,
      anon_sym_selected,
    STATE(92), 1,
      sym_attribute_identifier,
    STATE(105), 1,
      sym__macro_inProperty,
    STATE(117), 1,
      sym_character_token_identifier,
    ACTIONS(116), 2,
      anon_sym_AMP,
      aux_sym_attribute_identifier_token1,
    STATE(25), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [685] = 9,
    ACTIONS(118), 1,
      sym_htmlEntity,
    ACTIONS(120), 1,
      sym__ambiguousHash,
    ACTIONS(122), 1,
      anon_sym_target,
    ACTIONS(124), 1,
      anon_sym_selected,
    STATE(93), 1,
      sym_attribute_identifier,
    STATE(105), 1,
      sym__macro_inProperty,
    STATE(107), 1,
      sym_character_token_identifier,
    ACTIONS(116), 2,
      anon_sym_AMP,
      aux_sym_attribute_identifier_token1,
    STATE(25), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [716] = 6,
    ACTIONS(126), 1,
      anon_sym_AMP,
    ACTIONS(130), 1,
      sym__ambiguousHash,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(128), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(132), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    STATE(27), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [739] = 6,
    ACTIONS(120), 1,
      sym__ambiguousHash,
    ACTIONS(134), 1,
      anon_sym_AMP,
    STATE(105), 1,
      sym__macro_inProperty,
    ACTIONS(132), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(136), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(26), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [762] = 6,
    ACTIONS(138), 1,
      anon_sym_AMP,
    ACTIONS(144), 1,
      sym__ambiguousHash,
    STATE(105), 1,
      sym__macro_inProperty,
    ACTIONS(141), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(147), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    STATE(26), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [785] = 6,
    ACTIONS(149), 1,
      anon_sym_AMP,
    ACTIONS(155), 1,
      sym__ambiguousHash,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(147), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(152), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(27), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [808] = 2,
    ACTIONS(160), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    ACTIONS(158), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [822] = 2,
    ACTIONS(164), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    ACTIONS(162), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [836] = 2,
    ACTIONS(168), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    ACTIONS(166), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [850] = 2,
    ACTIONS(172), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    ACTIONS(170), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [864] = 4,
    ACTIONS(179), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(32), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    ACTIONS(174), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_name_recurse_token1,
    ACTIONS(177), 4,
      sym___EOF,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inRoot_and_wsp_token1,
  [882] = 2,
    ACTIONS(184), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    ACTIONS(182), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [896] = 6,
    ACTIONS(130), 1,
      sym__ambiguousHash,
    ACTIONS(186), 1,
      anon_sym_AMP,
    STATE(79), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(188), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(24), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [918] = 2,
    ACTIONS(192), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    ACTIONS(190), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [932] = 2,
    ACTIONS(194), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    ACTIONS(55), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [946] = 6,
    ACTIONS(130), 1,
      sym__ambiguousHash,
    ACTIONS(186), 1,
      anon_sym_AMP,
    STATE(96), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(188), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(24), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [968] = 6,
    ACTIONS(130), 1,
      sym__ambiguousHash,
    ACTIONS(186), 1,
      anon_sym_AMP,
    STATE(85), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(188), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(24), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [990] = 2,
    ACTIONS(198), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    ACTIONS(196), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1004] = 6,
    ACTIONS(130), 1,
      sym__ambiguousHash,
    ACTIONS(186), 1,
      anon_sym_AMP,
    STATE(86), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(188), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(24), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [1026] = 7,
    ACTIONS(122), 1,
      anon_sym_target,
    ACTIONS(124), 1,
      anon_sym_selected,
    ACTIONS(202), 1,
      sym_htmlEntity,
    STATE(83), 1,
      sym_ability_identifier,
    STATE(99), 1,
      sym_character_token_identifier,
    ACTIONS(200), 2,
      anon_sym_AMP,
      aux_sym_ability_identifier_token1,
    STATE(67), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1050] = 7,
    ACTIONS(122), 1,
      anon_sym_target,
    ACTIONS(124), 1,
      anon_sym_selected,
    ACTIONS(202), 1,
      sym_htmlEntity,
    STATE(98), 1,
      sym_ability_identifier,
    STATE(120), 1,
      sym_character_token_identifier,
    ACTIONS(200), 2,
      anon_sym_AMP,
      aux_sym_ability_identifier_token1,
    STATE(67), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1074] = 2,
    ACTIONS(206), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    ACTIONS(204), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1088] = 2,
    ACTIONS(210), 3,
      anon_sym_AMP,
      anon_sym_AT,
      anon_sym_PERCENT,
    ACTIONS(208), 6,
      ts_builtin_sym_end,
      aux_sym_script_token1,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1102] = 6,
    ACTIONS(130), 1,
      sym__ambiguousHash,
    ACTIONS(186), 1,
      anon_sym_AMP,
    STATE(95), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(188), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(24), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [1124] = 7,
    ACTIONS(122), 1,
      anon_sym_target,
    ACTIONS(124), 1,
      anon_sym_selected,
    ACTIONS(202), 1,
      sym_htmlEntity,
    STATE(94), 1,
      sym_ability_identifier,
    STATE(118), 1,
      sym_character_token_identifier,
    ACTIONS(200), 2,
      anon_sym_AMP,
      aux_sym_ability_identifier_token1,
    STATE(67), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1148] = 6,
    ACTIONS(130), 1,
      sym__ambiguousHash,
    ACTIONS(186), 1,
      anon_sym_AMP,
    STATE(97), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(188), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(24), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [1170] = 2,
    ACTIONS(206), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(204), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1183] = 2,
    ACTIONS(198), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(196), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1196] = 2,
    ACTIONS(164), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(162), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1209] = 2,
    ACTIONS(192), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(190), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1222] = 2,
    ACTIONS(210), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(208), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1235] = 2,
    ACTIONS(168), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(166), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1248] = 4,
    ACTIONS(217), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(54), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    ACTIONS(212), 3,
      anon_sym_,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(214), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1265] = 2,
    ACTIONS(172), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(170), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1278] = 2,
    ACTIONS(184), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(182), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1291] = 2,
    ACTIONS(220), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(177), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1304] = 2,
    ACTIONS(164), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(162), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1316] = 4,
    ACTIONS(222), 1,
      anon_sym_AMP,
    ACTIONS(225), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    ACTIONS(228), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    STATE(59), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1332] = 2,
    ACTIONS(206), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(204), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1344] = 2,
    ACTIONS(192), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(190), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1356] = 2,
    ACTIONS(184), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(182), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1368] = 2,
    ACTIONS(172), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(170), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1380] = 2,
    ACTIONS(168), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(166), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1392] = 2,
    ACTIONS(210), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(208), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1404] = 2,
    ACTIONS(198), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(196), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1416] = 4,
    ACTIONS(230), 1,
      anon_sym_AMP,
    ACTIONS(232), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    ACTIONS(234), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    STATE(59), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1432] = 2,
    ACTIONS(236), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(212), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1444] = 4,
    ACTIONS(200), 1,
      anon_sym_AMP,
    STATE(114), 1,
      sym_ability_identifier,
    ACTIONS(202), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(67), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1459] = 2,
    ACTIONS(238), 1,
      anon_sym_AMP,
    ACTIONS(147), 5,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_attribute_identifier_token1,
  [1470] = 4,
    ACTIONS(200), 1,
      anon_sym_AMP,
    STATE(104), 1,
      sym_ability_identifier,
    ACTIONS(202), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(67), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1485] = 4,
    ACTIONS(200), 1,
      anon_sym_AMP,
    STATE(103), 1,
      sym_ability_identifier,
    ACTIONS(202), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(67), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1500] = 2,
    ACTIONS(238), 1,
      anon_sym_AMP,
    ACTIONS(147), 5,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
      aux_sym_attribute_identifier_token1,
  [1511] = 4,
    ACTIONS(200), 1,
      anon_sym_AMP,
    STATE(101), 1,
      sym_ability_identifier,
    ACTIONS(202), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(67), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1526] = 2,
    ACTIONS(240), 1,
      anon_sym_AMP,
    ACTIONS(242), 5,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
      aux_sym_attribute_identifier_token1,
  [1537] = 4,
    ACTIONS(200), 1,
      anon_sym_AMP,
    STATE(115), 1,
      sym_ability_identifier,
    ACTIONS(202), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(67), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1552] = 2,
    ACTIONS(240), 1,
      anon_sym_AMP,
    ACTIONS(242), 5,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_attribute_identifier_token1,
  [1563] = 4,
    ACTIONS(200), 1,
      anon_sym_AMP,
    STATE(102), 1,
      sym_ability_identifier,
    ACTIONS(202), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(67), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1578] = 2,
    ACTIONS(244), 1,
      anon_sym_RBRACE,
    ACTIONS(246), 1,
      anon_sym_PIPEmax_RBRACE,
  [1585] = 2,
    ACTIONS(248), 1,
      anon_sym_RBRACE,
    ACTIONS(250), 1,
      anon_sym_PIPE,
  [1592] = 1,
    ACTIONS(252), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1597] = 1,
    ACTIONS(72), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1602] = 2,
    ACTIONS(254), 1,
      anon_sym_RBRACE,
    ACTIONS(256), 1,
      anon_sym_PIPE,
  [1609] = 1,
    ACTIONS(258), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1614] = 2,
    ACTIONS(260), 1,
      anon_sym_RBRACE,
    ACTIONS(262), 1,
      anon_sym_PIPEmax_RBRACE,
  [1621] = 2,
    ACTIONS(264), 1,
      anon_sym_RBRACE,
    ACTIONS(266), 1,
      anon_sym_PIPEmax_RBRACE,
  [1628] = 1,
    ACTIONS(268), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1633] = 1,
    ACTIONS(270), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1638] = 1,
    ACTIONS(114), 2,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1643] = 1,
    ACTIONS(76), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1648] = 1,
    ACTIONS(112), 2,
      sym__ambiguousHash,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1653] = 2,
    ACTIONS(272), 1,
      anon_sym_RBRACE,
    ACTIONS(274), 1,
      anon_sym_PIPE,
  [1660] = 2,
    ACTIONS(276), 1,
      anon_sym_RBRACE,
    ACTIONS(278), 1,
      anon_sym_PIPE,
  [1667] = 2,
    ACTIONS(280), 1,
      anon_sym_RBRACE,
    ACTIONS(282), 1,
      anon_sym_PIPE,
  [1674] = 2,
    ACTIONS(284), 1,
      anon_sym_RBRACE,
    ACTIONS(286), 1,
      anon_sym_PIPEmax_RBRACE,
  [1681] = 2,
    ACTIONS(288), 1,
      anon_sym_RBRACE,
    ACTIONS(290), 1,
      anon_sym_PIPEmax_RBRACE,
  [1688] = 2,
    ACTIONS(292), 1,
      anon_sym_RBRACE,
    ACTIONS(294), 1,
      anon_sym_PIPEmax_RBRACE,
  [1695] = 2,
    ACTIONS(296), 1,
      anon_sym_RBRACE,
    ACTIONS(298), 1,
      anon_sym_PIPE,
  [1702] = 1,
    ACTIONS(300), 1,
      anon_sym_PIPE,
  [1706] = 1,
    ACTIONS(80), 1,
      anon_sym_,
  [1710] = 1,
    ACTIONS(302), 1,
      anon_sym_RBRACE,
  [1714] = 1,
    ACTIONS(304), 1,
      anon_sym_RBRACE,
  [1718] = 1,
    ACTIONS(306), 1,
      anon_sym_RBRACE,
  [1722] = 1,
    ACTIONS(308), 1,
      anon_sym_RBRACE,
  [1726] = 1,
    ACTIONS(310), 1,
      anon_sym_,
  [1730] = 1,
    ACTIONS(312), 1,
      anon_sym_,
  [1734] = 1,
    ACTIONS(314), 1,
      anon_sym_PIPE,
  [1738] = 1,
    ACTIONS(316), 1,
      anon_sym_PIPE,
  [1742] = 1,
    ACTIONS(318), 1,
      anon_sym_,
  [1746] = 1,
    ACTIONS(82), 1,
      anon_sym_,
  [1750] = 1,
    ACTIONS(320), 1,
      anon_sym_PIPE,
  [1754] = 1,
    ACTIONS(322), 1,
      ts_builtin_sym_end,
  [1758] = 1,
    ACTIONS(324), 1,
      anon_sym_,
  [1762] = 1,
    ACTIONS(326), 1,
      anon_sym_RBRACE,
  [1766] = 1,
    ACTIONS(328), 1,
      anon_sym_RBRACE,
  [1770] = 1,
    ACTIONS(330), 1,
      anon_sym_,
  [1774] = 1,
    ACTIONS(332), 1,
      anon_sym_PIPE,
  [1778] = 1,
    ACTIONS(334), 1,
      anon_sym_PIPE,
  [1782] = 1,
    ACTIONS(336), 1,
      anon_sym_PIPE,
  [1786] = 1,
    ACTIONS(338), 1,
      anon_sym_PIPE,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 48,
  [SMALL_STATE(4)] = 95,
  [SMALL_STATE(5)] = 142,
  [SMALL_STATE(6)] = 179,
  [SMALL_STATE(7)] = 216,
  [SMALL_STATE(8)] = 250,
  [SMALL_STATE(9)] = 284,
  [SMALL_STATE(10)] = 318,
  [SMALL_STATE(11)] = 351,
  [SMALL_STATE(12)] = 384,
  [SMALL_STATE(13)] = 417,
  [SMALL_STATE(14)] = 448,
  [SMALL_STATE(15)] = 474,
  [SMALL_STATE(16)] = 504,
  [SMALL_STATE(17)] = 529,
  [SMALL_STATE(18)] = 553,
  [SMALL_STATE(19)] = 577,
  [SMALL_STATE(20)] = 600,
  [SMALL_STATE(21)] = 631,
  [SMALL_STATE(22)] = 654,
  [SMALL_STATE(23)] = 685,
  [SMALL_STATE(24)] = 716,
  [SMALL_STATE(25)] = 739,
  [SMALL_STATE(26)] = 762,
  [SMALL_STATE(27)] = 785,
  [SMALL_STATE(28)] = 808,
  [SMALL_STATE(29)] = 822,
  [SMALL_STATE(30)] = 836,
  [SMALL_STATE(31)] = 850,
  [SMALL_STATE(32)] = 864,
  [SMALL_STATE(33)] = 882,
  [SMALL_STATE(34)] = 896,
  [SMALL_STATE(35)] = 918,
  [SMALL_STATE(36)] = 932,
  [SMALL_STATE(37)] = 946,
  [SMALL_STATE(38)] = 968,
  [SMALL_STATE(39)] = 990,
  [SMALL_STATE(40)] = 1004,
  [SMALL_STATE(41)] = 1026,
  [SMALL_STATE(42)] = 1050,
  [SMALL_STATE(43)] = 1074,
  [SMALL_STATE(44)] = 1088,
  [SMALL_STATE(45)] = 1102,
  [SMALL_STATE(46)] = 1124,
  [SMALL_STATE(47)] = 1148,
  [SMALL_STATE(48)] = 1170,
  [SMALL_STATE(49)] = 1183,
  [SMALL_STATE(50)] = 1196,
  [SMALL_STATE(51)] = 1209,
  [SMALL_STATE(52)] = 1222,
  [SMALL_STATE(53)] = 1235,
  [SMALL_STATE(54)] = 1248,
  [SMALL_STATE(55)] = 1265,
  [SMALL_STATE(56)] = 1278,
  [SMALL_STATE(57)] = 1291,
  [SMALL_STATE(58)] = 1304,
  [SMALL_STATE(59)] = 1316,
  [SMALL_STATE(60)] = 1332,
  [SMALL_STATE(61)] = 1344,
  [SMALL_STATE(62)] = 1356,
  [SMALL_STATE(63)] = 1368,
  [SMALL_STATE(64)] = 1380,
  [SMALL_STATE(65)] = 1392,
  [SMALL_STATE(66)] = 1404,
  [SMALL_STATE(67)] = 1416,
  [SMALL_STATE(68)] = 1432,
  [SMALL_STATE(69)] = 1444,
  [SMALL_STATE(70)] = 1459,
  [SMALL_STATE(71)] = 1470,
  [SMALL_STATE(72)] = 1485,
  [SMALL_STATE(73)] = 1500,
  [SMALL_STATE(74)] = 1511,
  [SMALL_STATE(75)] = 1526,
  [SMALL_STATE(76)] = 1537,
  [SMALL_STATE(77)] = 1552,
  [SMALL_STATE(78)] = 1563,
  [SMALL_STATE(79)] = 1578,
  [SMALL_STATE(80)] = 1585,
  [SMALL_STATE(81)] = 1592,
  [SMALL_STATE(82)] = 1597,
  [SMALL_STATE(83)] = 1602,
  [SMALL_STATE(84)] = 1609,
  [SMALL_STATE(85)] = 1614,
  [SMALL_STATE(86)] = 1621,
  [SMALL_STATE(87)] = 1628,
  [SMALL_STATE(88)] = 1633,
  [SMALL_STATE(89)] = 1638,
  [SMALL_STATE(90)] = 1643,
  [SMALL_STATE(91)] = 1648,
  [SMALL_STATE(92)] = 1653,
  [SMALL_STATE(93)] = 1660,
  [SMALL_STATE(94)] = 1667,
  [SMALL_STATE(95)] = 1674,
  [SMALL_STATE(96)] = 1681,
  [SMALL_STATE(97)] = 1688,
  [SMALL_STATE(98)] = 1695,
  [SMALL_STATE(99)] = 1702,
  [SMALL_STATE(100)] = 1706,
  [SMALL_STATE(101)] = 1710,
  [SMALL_STATE(102)] = 1714,
  [SMALL_STATE(103)] = 1718,
  [SMALL_STATE(104)] = 1722,
  [SMALL_STATE(105)] = 1726,
  [SMALL_STATE(106)] = 1730,
  [SMALL_STATE(107)] = 1734,
  [SMALL_STATE(108)] = 1738,
  [SMALL_STATE(109)] = 1742,
  [SMALL_STATE(110)] = 1746,
  [SMALL_STATE(111)] = 1750,
  [SMALL_STATE(112)] = 1754,
  [SMALL_STATE(113)] = 1758,
  [SMALL_STATE(114)] = 1762,
  [SMALL_STATE(115)] = 1766,
  [SMALL_STATE(116)] = 1770,
  [SMALL_STATE(117)] = 1774,
  [SMALL_STATE(118)] = 1778,
  [SMALL_STATE(119)] = 1782,
  [SMALL_STATE(120)] = 1786,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 1),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [19] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 1),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 1),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 1),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 1),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(6),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(6),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(2),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(23),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(41),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 3),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 2),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name, 1),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 2),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name, 1),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 3),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [86] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 1),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(22),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(46),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 1),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(20),
  [109] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(42),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(111),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_identifier, 1),
  [134] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [138] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(26),
  [141] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(26),
  [144] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(3),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2),
  [149] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(27),
  [152] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(27),
  [155] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(4),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_and_wsp, 2),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro_inRoot_and_wsp, 2),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5, .production_id = 5),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5, .production_id = 5),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [174] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2), SHIFT_REPEAT(32),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2),
  [179] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2), SHIFT_REPEAT(91),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5, .production_id = 4),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5, .production_id = 4),
  [186] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 4),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 4),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [200] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5, .production_id = 6),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5, .production_id = 6),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 3, .production_id = 3),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 3, .production_id = 3),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_recurse_repeat1, 2),
  [214] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_recurse_repeat1, 2), SHIFT_REPEAT(54),
  [217] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__macro_inProperty_name_recurse_repeat1, 2), SHIFT_REPEAT(89),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2),
  [222] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_ability_identifier_repeat1, 2), SHIFT_REPEAT(59),
  [225] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_ability_identifier_repeat1, 2), SHIFT_REPEAT(59),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ability_identifier_repeat1, 2),
  [230] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability_identifier, 1),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_inProperty_name_recurse_repeat1, 2),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2),
  [240] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro_inProperty_and_wsp, 2),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_and_wsp, 2),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name, 2),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 4),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot, 2),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 4),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 2),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 1),
  [322] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty, 2),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name, 2),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
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
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .public_symbol_map = ts_symbol_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .field_count = FIELD_COUNT,
    .field_names = ts_field_names,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .external_scanner = {
      (const bool *)ts_external_scanner_states,
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
