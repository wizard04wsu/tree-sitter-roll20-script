#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 121
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 47
#define ALIAS_COUNT 1
#define TOKEN_COUNT 21
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 5

enum {
  anon_sym_ = 1,
  anon_sym_AMP = 2,
  sym_htmlEntity = 3,
  sym__ambiguousHash = 4,
  aux_sym__placeholder_or_text_token1 = 5,
  anon_sym_target = 6,
  anon_sym_selected = 7,
  anon_sym_AT_LBRACE = 8,
  anon_sym_RBRACE = 9,
  anon_sym_PIPE = 10,
  anon_sym_PIPEmax_RBRACE = 11,
  aux_sym_attribute_identifier_token1 = 12,
  anon_sym_PERCENT_LBRACE = 13,
  aux_sym_ability_identifier_token1 = 14,
  aux_sym__macro_inProperty_name_recurse_token1 = 15,
  aux_sym__macro_inProperty_name_recurse_token2 = 16,
  aux_sym__macro_inProperty_name_recurse_token3 = 17,
  aux_sym__macro_inRoot_and_wsp_token1 = 18,
  aux_sym__macro_inRoot_name_recurse_token1 = 19,
  sym___EOF = 20,
  sym_script = 21,
  sym__htmlEntity_or_text = 22,
  sym__placeholder_or_text = 23,
  sym__placeholder = 24,
  sym_character_token_identifier = 25,
  sym__attribute = 26,
  sym_attribute = 27,
  sym__attribute_of_character = 28,
  sym__attribute_of_character_maximum = 29,
  sym_attribute_identifier = 30,
  sym_ability = 31,
  sym_ability_identifier = 32,
  sym__macro_inProperty_and_wsp = 33,
  sym__macro_inProperty = 34,
  sym__macro_inProperty_name = 35,
  sym__macro_inProperty_name_recurse = 36,
  sym__macro_inRoot_and_wsp = 37,
  sym__macro_inRoot = 38,
  sym__macro_inRoot_name = 39,
  sym__macro_inRoot_name_recurse = 40,
  aux_sym_script_repeat1 = 41,
  aux_sym_attribute_identifier_repeat1 = 42,
  aux_sym_ability_identifier_repeat1 = 43,
  aux_sym__macro_inProperty_name_repeat1 = 44,
  aux_sym__macro_inProperty_name_recurse_repeat1 = 45,
  aux_sym__macro_inRoot_name_recurse_repeat1 = 46,
  alias_sym_character_identifier = 47,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_] = " ",
  [anon_sym_AMP] = "&",
  [sym_htmlEntity] = "htmlEntity",
  [sym__ambiguousHash] = "_ambiguousHash",
  [aux_sym__placeholder_or_text_token1] = "_placeholder_or_text_token1",
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
  [anon_sym_AMP] = anon_sym_AMP,
  [sym_htmlEntity] = sym_htmlEntity,
  [sym__ambiguousHash] = sym__ambiguousHash,
  [aux_sym__placeholder_or_text_token1] = aux_sym__placeholder_or_text_token1,
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
  [aux_sym__placeholder_or_text_token1] = {
    .visible = false,
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
      if (lookahead == '\n') ADVANCE(102);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ' ') ADVANCE(23);
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '%') ADVANCE(33);
      if (lookahead == '&') ADVANCE(25);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == 's') ADVANCE(92);
      if (lookahead == 't') ADVANCE(89);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '}') ADVANCE(43);
      if (lookahead != 0) ADVANCE(101);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(102);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(23);
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '%') ADVANCE(84);
      if (lookahead == '@') ADVANCE(85);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(101);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(24);
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '%') ADVANCE(59);
      if (lookahead == '&') ADVANCE(25);
      if (lookahead == '@') ADVANCE(60);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '}') ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(46);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(24);
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '%') ADVANCE(59);
      if (lookahead == '&') ADVANCE(25);
      if (lookahead == '@') ADVANCE(60);
      if (lookahead == '{') ADVANCE(63);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(46);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '&') ADVANCE(26);
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
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '&') ADVANCE(26);
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
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '&') ADVANCE(26);
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
      if (lookahead == '&') ADVANCE(26);
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
      if (lookahead == '&') ADVANCE(26);
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
      if (lookahead == ';') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 11:
      if (lookahead == ';') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == ';') ADVANCE(28);
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
          lookahead == ' ') ADVANCE(102);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '%') ADVANCE(84);
      if (lookahead == '@') ADVANCE(85);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead != 0) ADVANCE(104);
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
      if (lookahead == ' ') ADVANCE(23);
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '%') ADVANCE(33);
      if (lookahead == '&') ADVANCE(27);
      if (lookahead == '@') ADVANCE(35);
      if (lookahead == '{') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(104);
      END_STATE();
    case 21:
      if (eof) ADVANCE(22);
      if (lookahead == '\n' ||
          lookahead == ' ') ADVANCE(102);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '#') ADVANCE(31);
      if (lookahead == '%') ADVANCE(32);
      if (lookahead == '&') ADVANCE(26);
      if (lookahead == '@') ADVANCE(34);
      if (lookahead == '|') ADVANCE(14);
      if (lookahead == '}') ADVANCE(43);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_);
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
    case 25:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '#') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '#') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '#') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(103);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(104);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_htmlEntity);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_htmlEntity);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(104);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_htmlEntity);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym__ambiguousHash);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym__placeholder_or_text_token1);
      if (lookahead == '{') ADVANCE(66);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym__placeholder_or_text_token1);
      if (lookahead == '{') ADVANCE(66);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(86);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym__placeholder_or_text_token1);
      if (lookahead == '{') ADVANCE(42);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym__placeholder_or_text_token1);
      if (lookahead == '{') ADVANCE(42);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(86);
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
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
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
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
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
      if (lookahead == '&') ADVANCE(101);
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
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token1);
      if (lookahead == '{') ADVANCE(66);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(86);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token1);
      if (lookahead == '{') ADVANCE(42);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(86);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token1);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token2);
      if (lookahead == '{') ADVANCE(87);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == ';') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'a') ADVANCE(98);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'c') ADVANCE(100);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'd') ADVANCE(41);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'e') ADVANCE(97);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'e') ADVANCE(90);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'e') ADVANCE(91);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'e') ADVANCE(99);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'g') ADVANCE(95);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'l') ADVANCE(93);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 'r') ADVANCE(96);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 't') ADVANCE(38);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead == 't') ADVANCE(94);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(aux_sym__macro_inProperty_name_recurse_token3);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(101);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(aux_sym__macro_inRoot_and_wsp_token1);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(aux_sym__macro_inRoot_name_recurse_token1);
      if (lookahead == ';') ADVANCE(29);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(103);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(104);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(aux_sym__macro_inRoot_name_recurse_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '{') ADVANCE(104);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 21},
  [2] = {.lex_state = 4},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 20},
  [5] = {.lex_state = 21},
  [6] = {.lex_state = 21},
  [7] = {.lex_state = 17, .external_lex_state = 1},
  [8] = {.lex_state = 17, .external_lex_state = 1},
  [9] = {.lex_state = 17, .external_lex_state = 1},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 17, .external_lex_state = 1},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 17, .external_lex_state = 1},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 17, .external_lex_state = 1},
  [18] = {.lex_state = 17, .external_lex_state = 1},
  [19] = {.lex_state = 5},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 5},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 5},
  [24] = {.lex_state = 6},
  [25] = {.lex_state = 6},
  [26] = {.lex_state = 7},
  [27] = {.lex_state = 7},
  [28] = {.lex_state = 8},
  [29] = {.lex_state = 6},
  [30] = {.lex_state = 8},
  [31] = {.lex_state = 8},
  [32] = {.lex_state = 6},
  [33] = {.lex_state = 17, .external_lex_state = 1},
  [34] = {.lex_state = 6},
  [35] = {.lex_state = 6},
  [36] = {.lex_state = 6},
  [37] = {.lex_state = 6},
  [38] = {.lex_state = 17, .external_lex_state = 1},
  [39] = {.lex_state = 17, .external_lex_state = 1},
  [40] = {.lex_state = 17, .external_lex_state = 1},
  [41] = {.lex_state = 17, .external_lex_state = 1},
  [42] = {.lex_state = 17, .external_lex_state = 1},
  [43] = {.lex_state = 17, .external_lex_state = 1},
  [44] = {.lex_state = 17, .external_lex_state = 1},
  [45] = {.lex_state = 2},
  [46] = {.lex_state = 17, .external_lex_state = 1},
  [47] = {.lex_state = 17, .external_lex_state = 1},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 2},
  [50] = {.lex_state = 9},
  [51] = {.lex_state = 21},
  [52] = {.lex_state = 2},
  [53] = {.lex_state = 2},
  [54] = {.lex_state = 2},
  [55] = {.lex_state = 2},
  [56] = {.lex_state = 2},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 2},
  [59] = {.lex_state = 9},
  [60] = {.lex_state = 21},
  [61] = {.lex_state = 21},
  [62] = {.lex_state = 21},
  [63] = {.lex_state = 21},
  [64] = {.lex_state = 21},
  [65] = {.lex_state = 21},
  [66] = {.lex_state = 21},
  [67] = {.lex_state = 21},
  [68] = {.lex_state = 21},
  [69] = {.lex_state = 9},
  [70] = {.lex_state = 9},
  [71] = {.lex_state = 9},
  [72] = {.lex_state = 6},
  [73] = {.lex_state = 7},
  [74] = {.lex_state = 9},
  [75] = {.lex_state = 7},
  [76] = {.lex_state = 9},
  [77] = {.lex_state = 9},
  [78] = {.lex_state = 6},
  [79] = {.lex_state = 21},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 21, .external_lex_state = 1},
  [82] = {.lex_state = 21, .external_lex_state = 1},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 21, .external_lex_state = 1},
  [85] = {.lex_state = 21, .external_lex_state = 1},
  [86] = {.lex_state = 21, .external_lex_state = 1},
  [87] = {.lex_state = 21},
  [88] = {.lex_state = 21},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 21, .external_lex_state = 1},
  [91] = {.lex_state = 17},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 21},
  [96] = {.lex_state = 21},
  [97] = {.lex_state = 21},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 20},
  [100] = {.lex_state = 20},
  [101] = {.lex_state = 20},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 20},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 20},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 20},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 20},
  [116] = {.lex_state = 0},
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
    [aux_sym__placeholder_or_text_token1] = ACTIONS(1),
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
    [sym_script] = STATE(116),
    [sym__htmlEntity_or_text] = STATE(6),
    [sym__placeholder_or_text] = STATE(6),
    [sym__placeholder] = STATE(6),
    [sym__attribute] = STATE(6),
    [sym_attribute] = STATE(6),
    [sym__attribute_of_character] = STATE(6),
    [sym__attribute_of_character_maximum] = STATE(6),
    [sym_ability] = STATE(6),
    [sym__macro_inRoot_and_wsp] = STATE(6),
    [sym__macro_inRoot] = STATE(81),
    [aux_sym_script_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_AMP] = ACTIONS(5),
    [sym_htmlEntity] = ACTIONS(7),
    [sym__ambiguousHash] = ACTIONS(9),
    [aux_sym__placeholder_or_text_token1] = ACTIONS(5),
    [anon_sym_AT_LBRACE] = ACTIONS(11),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(13),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 12,
    ACTIONS(15), 1,
      anon_sym_,
    ACTIONS(19), 1,
      sym__ambiguousHash,
    ACTIONS(21), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(27), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(15), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(100), 1,
      sym__macro_inProperty_name,
    STATE(115), 1,
      sym__macro_inProperty_name_recurse,
    ACTIONS(23), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(29), 2,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
    ACTIONS(17), 3,
      anon_sym_AMP,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(10), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [47] = 12,
    ACTIONS(19), 1,
      sym__ambiguousHash,
    ACTIONS(21), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(27), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(31), 1,
      anon_sym_,
    STATE(15), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(100), 1,
      sym__macro_inProperty_name,
    STATE(115), 1,
      sym__macro_inProperty_name_recurse,
    ACTIONS(23), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(29), 2,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
    ACTIONS(17), 3,
      anon_sym_AMP,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(10), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [94] = 12,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 1,
      anon_sym_,
    ACTIONS(41), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(43), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(45), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(47), 1,
      aux_sym__macro_inRoot_name_recurse_token1,
    STATE(12), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(85), 1,
      sym__macro_inRoot_name,
    STATE(86), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(39), 2,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
    ACTIONS(37), 3,
      anon_sym_AMP,
      sym_htmlEntity,
      aux_sym__placeholder_or_text_token1,
    STATE(9), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [140] = 8,
    ACTIONS(49), 1,
      ts_builtin_sym_end,
    ACTIONS(54), 1,
      sym_htmlEntity,
    ACTIONS(57), 1,
      sym__ambiguousHash,
    ACTIONS(60), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(63), 1,
      anon_sym_PERCENT_LBRACE,
    STATE(81), 1,
      sym__macro_inRoot,
    ACTIONS(51), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    STATE(5), 10,
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
  [175] = 8,
    ACTIONS(9), 1,
      sym__ambiguousHash,
    ACTIONS(11), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(13), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(66), 1,
      ts_builtin_sym_end,
    ACTIONS(70), 1,
      sym_htmlEntity,
    STATE(81), 1,
      sym__macro_inRoot,
    ACTIONS(68), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    STATE(5), 10,
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
  [210] = 8,
    ACTIONS(41), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(43), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(45), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(12), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(82), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(72), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    ACTIONS(39), 3,
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
  [244] = 8,
    ACTIONS(41), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(43), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(45), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(12), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(84), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(74), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    ACTIONS(39), 3,
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
  [278] = 8,
    ACTIONS(41), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(43), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(45), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(12), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    STATE(90), 1,
      sym__macro_inRoot_name_recurse,
    ACTIONS(76), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    ACTIONS(39), 3,
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
  [312] = 8,
    ACTIONS(21), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(27), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(78), 1,
      anon_sym_,
    STATE(15), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(111), 1,
      sym__macro_inProperty_name_recurse,
    ACTIONS(19), 3,
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
  [345] = 8,
    ACTIONS(21), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(27), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(80), 1,
      anon_sym_,
    STATE(15), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(101), 1,
      sym__macro_inProperty_name_recurse,
    ACTIONS(19), 3,
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
  [378] = 7,
    ACTIONS(41), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(43), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(84), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(33), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    ACTIONS(86), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
    ACTIONS(82), 3,
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
  [409] = 8,
    ACTIONS(21), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(27), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(88), 1,
      anon_sym_,
    STATE(15), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    STATE(105), 1,
      sym__macro_inProperty_name_recurse,
    ACTIONS(19), 3,
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
  [442] = 5,
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
  [468] = 7,
    ACTIONS(21), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(100), 1,
      anon_sym_,
    ACTIONS(104), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(45), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    ACTIONS(102), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(11), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [498] = 5,
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
  [523] = 5,
    ACTIONS(41), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(43), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(86), 2,
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
  [547] = 5,
    ACTIONS(41), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(43), 1,
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
  [571] = 9,
    ACTIONS(116), 1,
      sym_htmlEntity,
    ACTIONS(118), 1,
      sym__ambiguousHash,
    ACTIONS(120), 1,
      anon_sym_target,
    ACTIONS(122), 1,
      anon_sym_selected,
    STATE(98), 1,
      sym_attribute_identifier,
    STATE(99), 1,
      sym__macro_inProperty,
    STATE(119), 1,
      sym_character_token_identifier,
    ACTIONS(114), 2,
      anon_sym_AMP,
      aux_sym_attribute_identifier_token1,
    STATE(24), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [602] = 5,
    ACTIONS(21), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(80), 1,
      anon_sym_,
    ACTIONS(124), 2,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(13), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [625] = 9,
    ACTIONS(116), 1,
      sym_htmlEntity,
    ACTIONS(118), 1,
      sym__ambiguousHash,
    ACTIONS(120), 1,
      anon_sym_target,
    ACTIONS(122), 1,
      anon_sym_selected,
    STATE(92), 1,
      sym_attribute_identifier,
    STATE(99), 1,
      sym__macro_inProperty,
    STATE(117), 1,
      sym_character_token_identifier,
    ACTIONS(114), 2,
      anon_sym_AMP,
      aux_sym_attribute_identifier_token1,
    STATE(24), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [656] = 5,
    ACTIONS(21), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(25), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(100), 1,
      anon_sym_,
    ACTIONS(124), 2,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token3,
    STATE(11), 7,
      sym__placeholder,
      sym__attribute,
      sym_attribute,
      sym__attribute_of_character,
      sym__attribute_of_character_maximum,
      sym_ability,
      aux_sym__macro_inProperty_name_repeat1,
  [679] = 9,
    ACTIONS(116), 1,
      sym_htmlEntity,
    ACTIONS(118), 1,
      sym__ambiguousHash,
    ACTIONS(120), 1,
      anon_sym_target,
    ACTIONS(122), 1,
      anon_sym_selected,
    STATE(93), 1,
      sym_attribute_identifier,
    STATE(99), 1,
      sym__macro_inProperty,
    STATE(106), 1,
      sym_character_token_identifier,
    ACTIONS(114), 2,
      anon_sym_AMP,
      aux_sym_attribute_identifier_token1,
    STATE(24), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [710] = 6,
    ACTIONS(118), 1,
      sym__ambiguousHash,
    ACTIONS(126), 1,
      anon_sym_AMP,
    STATE(99), 1,
      sym__macro_inProperty,
    ACTIONS(128), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(130), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    STATE(25), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [733] = 6,
    ACTIONS(132), 1,
      anon_sym_AMP,
    ACTIONS(138), 1,
      sym__ambiguousHash,
    STATE(99), 1,
      sym__macro_inProperty,
    ACTIONS(135), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    ACTIONS(141), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    STATE(25), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [756] = 6,
    ACTIONS(143), 1,
      anon_sym_AMP,
    ACTIONS(147), 1,
      sym__ambiguousHash,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(130), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(145), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(27), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [779] = 6,
    ACTIONS(149), 1,
      anon_sym_AMP,
    ACTIONS(155), 1,
      sym__ambiguousHash,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(141), 2,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
    ACTIONS(152), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(27), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [802] = 7,
    ACTIONS(120), 1,
      anon_sym_target,
    ACTIONS(122), 1,
      anon_sym_selected,
    ACTIONS(160), 1,
      sym_htmlEntity,
    STATE(80), 1,
      sym_ability_identifier,
    STATE(120), 1,
      sym_character_token_identifier,
    ACTIONS(158), 2,
      anon_sym_AMP,
      aux_sym_ability_identifier_token1,
    STATE(59), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [826] = 6,
    ACTIONS(147), 1,
      sym__ambiguousHash,
    ACTIONS(162), 1,
      anon_sym_AMP,
    STATE(79), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(164), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(26), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [848] = 7,
    ACTIONS(120), 1,
      anon_sym_target,
    ACTIONS(122), 1,
      anon_sym_selected,
    ACTIONS(160), 1,
      sym_htmlEntity,
    STATE(94), 1,
      sym_ability_identifier,
    STATE(118), 1,
      sym_character_token_identifier,
    ACTIONS(158), 2,
      anon_sym_AMP,
      aux_sym_ability_identifier_token1,
    STATE(59), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [872] = 7,
    ACTIONS(120), 1,
      anon_sym_target,
    ACTIONS(122), 1,
      anon_sym_selected,
    ACTIONS(160), 1,
      sym_htmlEntity,
    STATE(83), 1,
      sym_ability_identifier,
    STATE(114), 1,
      sym_character_token_identifier,
    ACTIONS(158), 2,
      anon_sym_AMP,
      aux_sym_ability_identifier_token1,
    STATE(59), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [896] = 6,
    ACTIONS(147), 1,
      sym__ambiguousHash,
    ACTIONS(162), 1,
      anon_sym_AMP,
    STATE(97), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(164), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(26), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [918] = 4,
    ACTIONS(171), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(33), 1,
      aux_sym__macro_inRoot_name_recurse_repeat1,
    ACTIONS(166), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_name_recurse_token1,
    ACTIONS(169), 4,
      sym___EOF,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inRoot_and_wsp_token1,
  [936] = 6,
    ACTIONS(147), 1,
      sym__ambiguousHash,
    ACTIONS(162), 1,
      anon_sym_AMP,
    STATE(96), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(164), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(26), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [958] = 6,
    ACTIONS(147), 1,
      sym__ambiguousHash,
    ACTIONS(162), 1,
      anon_sym_AMP,
    STATE(87), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(164), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(26), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [980] = 6,
    ACTIONS(147), 1,
      sym__ambiguousHash,
    ACTIONS(162), 1,
      anon_sym_AMP,
    STATE(95), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(164), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(26), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [1002] = 6,
    ACTIONS(147), 1,
      sym__ambiguousHash,
    ACTIONS(162), 1,
      anon_sym_AMP,
    STATE(88), 1,
      sym_attribute_identifier,
    STATE(109), 1,
      sym__macro_inProperty,
    ACTIONS(164), 2,
      sym_htmlEntity,
      aux_sym_attribute_identifier_token1,
    STATE(26), 3,
      sym__htmlEntity_or_text,
      sym__macro_inProperty_and_wsp,
      aux_sym_attribute_identifier_repeat1,
  [1024] = 2,
    ACTIONS(176), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(174), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1037] = 2,
    ACTIONS(180), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(178), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1050] = 2,
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
  [1063] = 2,
    ACTIONS(188), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(186), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1076] = 2,
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
  [1089] = 2,
    ACTIONS(196), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(194), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1102] = 2,
    ACTIONS(200), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(198), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1115] = 4,
    ACTIONS(207), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    STATE(45), 1,
      aux_sym__macro_inProperty_name_recurse_repeat1,
    ACTIONS(202), 3,
      anon_sym_,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(204), 3,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1132] = 2,
    ACTIONS(210), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(169), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1145] = 2,
    ACTIONS(214), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(212), 7,
      sym___EOF,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inRoot_and_wsp_token1,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1158] = 2,
    ACTIONS(180), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(178), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1170] = 2,
    ACTIONS(192), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(190), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1182] = 4,
    ACTIONS(216), 1,
      anon_sym_AMP,
    ACTIONS(219), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    ACTIONS(222), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    STATE(50), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1198] = 2,
    ACTIONS(224), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(49), 5,
      ts_builtin_sym_end,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1210] = 2,
    ACTIONS(200), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(198), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1222] = 2,
    ACTIONS(226), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(202), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1234] = 2,
    ACTIONS(196), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(194), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1246] = 2,
    ACTIONS(184), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(182), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1258] = 2,
    ACTIONS(214), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(212), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1270] = 2,
    ACTIONS(176), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(174), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1282] = 2,
    ACTIONS(188), 1,
      aux_sym__macro_inProperty_name_recurse_token1,
    ACTIONS(186), 6,
      anon_sym_,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      aux_sym__macro_inProperty_name_recurse_token2,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1294] = 4,
    ACTIONS(228), 1,
      anon_sym_AMP,
    ACTIONS(230), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    ACTIONS(232), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    STATE(50), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1310] = 2,
    ACTIONS(236), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(234), 5,
      ts_builtin_sym_end,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1322] = 2,
    ACTIONS(188), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(186), 5,
      ts_builtin_sym_end,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1334] = 2,
    ACTIONS(192), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(190), 5,
      ts_builtin_sym_end,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1346] = 2,
    ACTIONS(176), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(174), 5,
      ts_builtin_sym_end,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1358] = 2,
    ACTIONS(214), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(212), 5,
      ts_builtin_sym_end,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1370] = 2,
    ACTIONS(184), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(182), 5,
      ts_builtin_sym_end,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1382] = 2,
    ACTIONS(196), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(194), 5,
      ts_builtin_sym_end,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1394] = 2,
    ACTIONS(180), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(178), 5,
      ts_builtin_sym_end,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1406] = 2,
    ACTIONS(200), 2,
      anon_sym_AMP,
      aux_sym__placeholder_or_text_token1,
    ACTIONS(198), 5,
      ts_builtin_sym_end,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [1418] = 4,
    ACTIONS(158), 1,
      anon_sym_AMP,
    STATE(113), 1,
      sym_ability_identifier,
    ACTIONS(160), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(59), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1433] = 4,
    ACTIONS(158), 1,
      anon_sym_AMP,
    STATE(104), 1,
      sym_ability_identifier,
    ACTIONS(160), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(59), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1448] = 4,
    ACTIONS(158), 1,
      anon_sym_AMP,
    STATE(112), 1,
      sym_ability_identifier,
    ACTIONS(160), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(59), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1463] = 2,
    ACTIONS(238), 1,
      anon_sym_AMP,
    ACTIONS(240), 5,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_attribute_identifier_token1,
  [1474] = 2,
    ACTIONS(242), 1,
      anon_sym_AMP,
    ACTIONS(141), 5,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
      aux_sym_attribute_identifier_token1,
  [1485] = 4,
    ACTIONS(158), 1,
      anon_sym_AMP,
    STATE(103), 1,
      sym_ability_identifier,
    ACTIONS(160), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(59), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1500] = 2,
    ACTIONS(238), 1,
      anon_sym_AMP,
    ACTIONS(240), 5,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_RBRACE,
      anon_sym_PIPEmax_RBRACE,
      aux_sym_attribute_identifier_token1,
  [1511] = 4,
    ACTIONS(158), 1,
      anon_sym_AMP,
    STATE(110), 1,
      sym_ability_identifier,
    ACTIONS(160), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(59), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1526] = 4,
    ACTIONS(158), 1,
      anon_sym_AMP,
    STATE(102), 1,
      sym_ability_identifier,
    ACTIONS(160), 2,
      sym_htmlEntity,
      aux_sym_ability_identifier_token1,
    STATE(59), 2,
      sym__htmlEntity_or_text,
      aux_sym_ability_identifier_repeat1,
  [1541] = 2,
    ACTIONS(242), 1,
      anon_sym_AMP,
    ACTIONS(141), 5,
      sym_htmlEntity,
      sym__ambiguousHash,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      aux_sym_attribute_identifier_token1,
  [1552] = 2,
    ACTIONS(244), 1,
      anon_sym_RBRACE,
    ACTIONS(246), 1,
      anon_sym_PIPEmax_RBRACE,
  [1559] = 2,
    ACTIONS(248), 1,
      anon_sym_RBRACE,
    ACTIONS(250), 1,
      anon_sym_PIPE,
  [1566] = 1,
    ACTIONS(252), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1571] = 1,
    ACTIONS(254), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1576] = 2,
    ACTIONS(256), 1,
      anon_sym_RBRACE,
    ACTIONS(258), 1,
      anon_sym_PIPE,
  [1583] = 1,
    ACTIONS(72), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1588] = 1,
    ACTIONS(260), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1593] = 1,
    ACTIONS(76), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1598] = 2,
    ACTIONS(262), 1,
      anon_sym_RBRACE,
    ACTIONS(264), 1,
      anon_sym_PIPEmax_RBRACE,
  [1605] = 2,
    ACTIONS(266), 1,
      anon_sym_RBRACE,
    ACTIONS(268), 1,
      anon_sym_PIPEmax_RBRACE,
  [1612] = 1,
    ACTIONS(124), 2,
      sym__ambiguousHash,
      aux_sym__macro_inProperty_name_recurse_token3,
  [1617] = 1,
    ACTIONS(270), 2,
      sym___EOF,
      aux_sym__macro_inRoot_and_wsp_token1,
  [1622] = 1,
    ACTIONS(112), 2,
      sym__ambiguousHash,
      aux_sym__macro_inRoot_name_recurse_token1,
  [1627] = 2,
    ACTIONS(272), 1,
      anon_sym_RBRACE,
    ACTIONS(274), 1,
      anon_sym_PIPE,
  [1634] = 2,
    ACTIONS(276), 1,
      anon_sym_RBRACE,
    ACTIONS(278), 1,
      anon_sym_PIPE,
  [1641] = 2,
    ACTIONS(280), 1,
      anon_sym_RBRACE,
    ACTIONS(282), 1,
      anon_sym_PIPE,
  [1648] = 2,
    ACTIONS(284), 1,
      anon_sym_RBRACE,
    ACTIONS(286), 1,
      anon_sym_PIPEmax_RBRACE,
  [1655] = 2,
    ACTIONS(288), 1,
      anon_sym_RBRACE,
    ACTIONS(290), 1,
      anon_sym_PIPEmax_RBRACE,
  [1662] = 2,
    ACTIONS(292), 1,
      anon_sym_RBRACE,
    ACTIONS(294), 1,
      anon_sym_PIPEmax_RBRACE,
  [1669] = 2,
    ACTIONS(296), 1,
      anon_sym_RBRACE,
    ACTIONS(298), 1,
      anon_sym_PIPE,
  [1676] = 1,
    ACTIONS(300), 1,
      anon_sym_,
  [1680] = 1,
    ACTIONS(302), 1,
      anon_sym_,
  [1684] = 1,
    ACTIONS(88), 1,
      anon_sym_,
  [1688] = 1,
    ACTIONS(304), 1,
      anon_sym_RBRACE,
  [1692] = 1,
    ACTIONS(306), 1,
      anon_sym_RBRACE,
  [1696] = 1,
    ACTIONS(308), 1,
      anon_sym_RBRACE,
  [1700] = 1,
    ACTIONS(310), 1,
      anon_sym_,
  [1704] = 1,
    ACTIONS(312), 1,
      anon_sym_PIPE,
  [1708] = 1,
    ACTIONS(314), 1,
      anon_sym_PIPE,
  [1712] = 1,
    ACTIONS(316), 1,
      anon_sym_PIPE,
  [1716] = 1,
    ACTIONS(318), 1,
      anon_sym_,
  [1720] = 1,
    ACTIONS(320), 1,
      anon_sym_RBRACE,
  [1724] = 1,
    ACTIONS(322), 1,
      anon_sym_,
  [1728] = 1,
    ACTIONS(324), 1,
      anon_sym_RBRACE,
  [1732] = 1,
    ACTIONS(326), 1,
      anon_sym_RBRACE,
  [1736] = 1,
    ACTIONS(328), 1,
      anon_sym_PIPE,
  [1740] = 1,
    ACTIONS(78), 1,
      anon_sym_,
  [1744] = 1,
    ACTIONS(330), 1,
      ts_builtin_sym_end,
  [1748] = 1,
    ACTIONS(332), 1,
      anon_sym_PIPE,
  [1752] = 1,
    ACTIONS(334), 1,
      anon_sym_PIPE,
  [1756] = 1,
    ACTIONS(336), 1,
      anon_sym_PIPE,
  [1760] = 1,
    ACTIONS(338), 1,
      anon_sym_PIPE,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 47,
  [SMALL_STATE(4)] = 94,
  [SMALL_STATE(5)] = 140,
  [SMALL_STATE(6)] = 175,
  [SMALL_STATE(7)] = 210,
  [SMALL_STATE(8)] = 244,
  [SMALL_STATE(9)] = 278,
  [SMALL_STATE(10)] = 312,
  [SMALL_STATE(11)] = 345,
  [SMALL_STATE(12)] = 378,
  [SMALL_STATE(13)] = 409,
  [SMALL_STATE(14)] = 442,
  [SMALL_STATE(15)] = 468,
  [SMALL_STATE(16)] = 498,
  [SMALL_STATE(17)] = 523,
  [SMALL_STATE(18)] = 547,
  [SMALL_STATE(19)] = 571,
  [SMALL_STATE(20)] = 602,
  [SMALL_STATE(21)] = 625,
  [SMALL_STATE(22)] = 656,
  [SMALL_STATE(23)] = 679,
  [SMALL_STATE(24)] = 710,
  [SMALL_STATE(25)] = 733,
  [SMALL_STATE(26)] = 756,
  [SMALL_STATE(27)] = 779,
  [SMALL_STATE(28)] = 802,
  [SMALL_STATE(29)] = 826,
  [SMALL_STATE(30)] = 848,
  [SMALL_STATE(31)] = 872,
  [SMALL_STATE(32)] = 896,
  [SMALL_STATE(33)] = 918,
  [SMALL_STATE(34)] = 936,
  [SMALL_STATE(35)] = 958,
  [SMALL_STATE(36)] = 980,
  [SMALL_STATE(37)] = 1002,
  [SMALL_STATE(38)] = 1024,
  [SMALL_STATE(39)] = 1037,
  [SMALL_STATE(40)] = 1050,
  [SMALL_STATE(41)] = 1063,
  [SMALL_STATE(42)] = 1076,
  [SMALL_STATE(43)] = 1089,
  [SMALL_STATE(44)] = 1102,
  [SMALL_STATE(45)] = 1115,
  [SMALL_STATE(46)] = 1132,
  [SMALL_STATE(47)] = 1145,
  [SMALL_STATE(48)] = 1158,
  [SMALL_STATE(49)] = 1170,
  [SMALL_STATE(50)] = 1182,
  [SMALL_STATE(51)] = 1198,
  [SMALL_STATE(52)] = 1210,
  [SMALL_STATE(53)] = 1222,
  [SMALL_STATE(54)] = 1234,
  [SMALL_STATE(55)] = 1246,
  [SMALL_STATE(56)] = 1258,
  [SMALL_STATE(57)] = 1270,
  [SMALL_STATE(58)] = 1282,
  [SMALL_STATE(59)] = 1294,
  [SMALL_STATE(60)] = 1310,
  [SMALL_STATE(61)] = 1322,
  [SMALL_STATE(62)] = 1334,
  [SMALL_STATE(63)] = 1346,
  [SMALL_STATE(64)] = 1358,
  [SMALL_STATE(65)] = 1370,
  [SMALL_STATE(66)] = 1382,
  [SMALL_STATE(67)] = 1394,
  [SMALL_STATE(68)] = 1406,
  [SMALL_STATE(69)] = 1418,
  [SMALL_STATE(70)] = 1433,
  [SMALL_STATE(71)] = 1448,
  [SMALL_STATE(72)] = 1463,
  [SMALL_STATE(73)] = 1474,
  [SMALL_STATE(74)] = 1485,
  [SMALL_STATE(75)] = 1500,
  [SMALL_STATE(76)] = 1511,
  [SMALL_STATE(77)] = 1526,
  [SMALL_STATE(78)] = 1541,
  [SMALL_STATE(79)] = 1552,
  [SMALL_STATE(80)] = 1559,
  [SMALL_STATE(81)] = 1566,
  [SMALL_STATE(82)] = 1571,
  [SMALL_STATE(83)] = 1576,
  [SMALL_STATE(84)] = 1583,
  [SMALL_STATE(85)] = 1588,
  [SMALL_STATE(86)] = 1593,
  [SMALL_STATE(87)] = 1598,
  [SMALL_STATE(88)] = 1605,
  [SMALL_STATE(89)] = 1612,
  [SMALL_STATE(90)] = 1617,
  [SMALL_STATE(91)] = 1622,
  [SMALL_STATE(92)] = 1627,
  [SMALL_STATE(93)] = 1634,
  [SMALL_STATE(94)] = 1641,
  [SMALL_STATE(95)] = 1648,
  [SMALL_STATE(96)] = 1655,
  [SMALL_STATE(97)] = 1662,
  [SMALL_STATE(98)] = 1669,
  [SMALL_STATE(99)] = 1676,
  [SMALL_STATE(100)] = 1680,
  [SMALL_STATE(101)] = 1684,
  [SMALL_STATE(102)] = 1688,
  [SMALL_STATE(103)] = 1692,
  [SMALL_STATE(104)] = 1696,
  [SMALL_STATE(105)] = 1700,
  [SMALL_STATE(106)] = 1704,
  [SMALL_STATE(107)] = 1708,
  [SMALL_STATE(108)] = 1712,
  [SMALL_STATE(109)] = 1716,
  [SMALL_STATE(110)] = 1720,
  [SMALL_STATE(111)] = 1724,
  [SMALL_STATE(112)] = 1728,
  [SMALL_STATE(113)] = 1732,
  [SMALL_STATE(114)] = 1736,
  [SMALL_STATE(115)] = 1740,
  [SMALL_STATE(116)] = 1744,
  [SMALL_STATE(117)] = 1748,
  [SMALL_STATE(118)] = 1752,
  [SMALL_STATE(119)] = 1756,
  [SMALL_STATE(120)] = 1760,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [17] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 1),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 1),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 1),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 1),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(5),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(5),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(4),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(23),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_script_repeat1, 2), SHIFT_REPEAT(31),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_script, 1),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 3),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 2),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name, 1),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name, 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 2),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [84] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 1),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 3),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2),
  [92] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(21),
  [95] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(30),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 1),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [106] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(19),
  [109] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_repeat1, 2), SHIFT_REPEAT(28),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute_identifier, 1),
  [132] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(25),
  [135] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(25),
  [138] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(3),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2),
  [143] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [149] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(27),
  [152] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(27),
  [155] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2), SHIFT_REPEAT(2),
  [158] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [166] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2), SHIFT_REPEAT(33),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2),
  [171] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2), SHIFT_REPEAT(91),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5, .production_id = 5),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5, .production_id = 5),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character, 5, .production_id = 4),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character, 5, .production_id = 4),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 3, .production_id = 3),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 3, .production_id = 3),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 4),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5, .production_id = 4),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5, .production_id = 6),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5, .production_id = 6),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_recurse_repeat1, 2),
  [204] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macro_inProperty_name_recurse_repeat1, 2), SHIFT_REPEAT(45),
  [207] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__macro_inProperty_name_recurse_repeat1, 2), SHIFT_REPEAT(89),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_inRoot_name_recurse_repeat1, 2),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_of_character_maximum, 5),
  [216] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_ability_identifier_repeat1, 2), SHIFT_REPEAT(50),
  [219] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_ability_identifier_repeat1, 2), SHIFT_REPEAT(50),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_ability_identifier_repeat1, 2),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_script_repeat1, 2),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macro_inProperty_name_recurse_repeat1, 2),
  [228] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability_identifier, 1),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_and_wsp, 2),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro_inRoot_and_wsp, 2),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro_inProperty_and_wsp, 2),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_and_wsp, 2),
  [242] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_attribute_identifier_repeat1, 2),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name_recurse, 4),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot, 2),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inRoot_name, 2),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [302] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty, 2),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [310] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name_recurse, 4),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [314] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 2),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_token_identifier, 1, .production_id = 1),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_inProperty_name, 2),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [330] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
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
