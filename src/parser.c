#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 73
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 54
#define ALIAS_COUNT 4
#define TOKEN_COUNT 29
#define EXTERNAL_TOKEN_COUNT 3
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5

enum {
  aux_sym__stringNL_token1 = 1,
  anon_sym_selected = 2,
  anon_sym_target = 3,
  aux_sym__propertyName_token1 = 4,
  aux_sym__propertyName_token2 = 5,
  aux_sym__propertyName_token3 = 6,
  aux_sym__propertyName_token4 = 7,
  aux_sym__propertyNameWithMacros_token1 = 8,
  aux_sym__propertyNameWithMacros_token2 = 9,
  aux_sym__propertyNameWithMacros_token3 = 10,
  anon_sym_ = 11,
  anon_sym_POUND = 12,
  anon_sym_RBRACE = 13,
  anon_sym_AT_LBRACE = 14,
  anon_sym_PIPE = 15,
  anon_sym_max = 16,
  aux_sym__attribute_token1 = 17,
  aux_sym__attribute_token2 = 18,
  anon_sym_PERCENT_LBRACE = 19,
  aux_sym__macro_spaceNL_token1 = 20,
  anon_sym_POUND2 = 21,
  aux_sym_macroName_token1 = 22,
  anon_sym_AT = 23,
  aux_sym__macroNameInsideAttributeName_token1 = 24,
  anon_sym_2 = 25,
  sym__EOF = 26,
  sym___attribute_start = 27,
  sym___ability_start = 28,
  sym_roll20_script = 29,
  sym__stringNL = 30,
  sym__tokenSelector = 31,
  sym__propertyName = 32,
  sym__propertyNameWithMacros = 33,
  sym__selector = 34,
  sym__selectorWithMacros = 35,
  sym_attribute = 36,
  sym__attribute_empty = 37,
  sym__attribute = 38,
  sym_ability = 39,
  sym__ability_empty = 40,
  sym__ability = 41,
  sym__macro_spaceNL = 42,
  sym_macro = 43,
  sym_macroName = 44,
  sym__macroInsideAttributeName = 45,
  sym__macroNameInsideAttributeName = 46,
  aux_sym_roll20_script_repeat1 = 47,
  aux_sym__stringNL_repeat1 = 48,
  aux_sym__propertyName_repeat1 = 49,
  aux_sym__propertyNameWithMacros_repeat1 = 50,
  aux_sym__attribute_repeat1 = 51,
  aux_sym_macroName_repeat1 = 52,
  aux_sym__macroNameInsideAttributeName_repeat1 = 53,
  alias_sym_abilityName = 54,
  alias_sym_attributeName = 55,
  alias_sym_characterName = 56,
  alias_sym_invalid = 57,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym__stringNL_token1] = "_stringNL_token1",
  [anon_sym_selected] = "token",
  [anon_sym_target] = "token",
  [aux_sym__propertyName_token1] = "_propertyName_token1",
  [aux_sym__propertyName_token2] = "_propertyName_token2",
  [aux_sym__propertyName_token3] = "_propertyName_token3",
  [aux_sym__propertyName_token4] = "invalid",
  [aux_sym__propertyNameWithMacros_token1] = "_propertyNameWithMacros_token1",
  [aux_sym__propertyNameWithMacros_token2] = "_propertyNameWithMacros_token2",
  [aux_sym__propertyNameWithMacros_token3] = "_propertyNameWithMacros_token3",
  [anon_sym_] = " ",
  [anon_sym_POUND] = "# ",
  [anon_sym_RBRACE] = "}",
  [anon_sym_AT_LBRACE] = "invalid",
  [anon_sym_PIPE] = "|",
  [anon_sym_max] = "keyword",
  [aux_sym__attribute_token1] = "invalid",
  [aux_sym__attribute_token2] = "_attribute_token2",
  [anon_sym_PERCENT_LBRACE] = "invalid",
  [aux_sym__macro_spaceNL_token1] = "_macro_spaceNL_token1",
  [anon_sym_POUND2] = "#",
  [aux_sym_macroName_token1] = "macroName_token1",
  [anon_sym_AT] = "@",
  [aux_sym__macroNameInsideAttributeName_token1] = "_macroNameInsideAttributeName_token1",
  [anon_sym_2] = "",
  [sym__EOF] = "_EOF",
  [sym___attribute_start] = "__attribute_start",
  [sym___ability_start] = "__ability_start",
  [sym_roll20_script] = "roll20_script",
  [sym__stringNL] = "_stringNL",
  [sym__tokenSelector] = "_tokenSelector",
  [sym__propertyName] = "_propertyName",
  [sym__propertyNameWithMacros] = "_propertyNameWithMacros",
  [sym__selector] = "_selector",
  [sym__selectorWithMacros] = "_selectorWithMacros",
  [sym_attribute] = "attribute",
  [sym__attribute_empty] = "invalid",
  [sym__attribute] = "_attribute",
  [sym_ability] = "ability",
  [sym__ability_empty] = "invalid",
  [sym__ability] = "_ability",
  [sym__macro_spaceNL] = "_macro_spaceNL",
  [sym_macro] = "macro",
  [sym_macroName] = "macroName",
  [sym__macroInsideAttributeName] = "_macroInsideAttributeName",
  [sym__macroNameInsideAttributeName] = "macroName",
  [aux_sym_roll20_script_repeat1] = "roll20_script_repeat1",
  [aux_sym__stringNL_repeat1] = "_stringNL_repeat1",
  [aux_sym__propertyName_repeat1] = "_propertyName_repeat1",
  [aux_sym__propertyNameWithMacros_repeat1] = "_propertyNameWithMacros_repeat1",
  [aux_sym__attribute_repeat1] = "_attribute_repeat1",
  [aux_sym_macroName_repeat1] = "macroName_repeat1",
  [aux_sym__macroNameInsideAttributeName_repeat1] = "_macroNameInsideAttributeName_repeat1",
  [alias_sym_abilityName] = "abilityName",
  [alias_sym_attributeName] = "attributeName",
  [alias_sym_characterName] = "characterName",
  [alias_sym_invalid] = "invalid",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym__stringNL_token1] = aux_sym__stringNL_token1,
  [anon_sym_selected] = anon_sym_selected,
  [anon_sym_target] = anon_sym_selected,
  [aux_sym__propertyName_token1] = aux_sym__propertyName_token1,
  [aux_sym__propertyName_token2] = aux_sym__propertyName_token2,
  [aux_sym__propertyName_token3] = aux_sym__propertyName_token3,
  [aux_sym__propertyName_token4] = aux_sym__propertyName_token4,
  [aux_sym__propertyNameWithMacros_token1] = aux_sym__propertyNameWithMacros_token1,
  [aux_sym__propertyNameWithMacros_token2] = aux_sym__propertyNameWithMacros_token2,
  [aux_sym__propertyNameWithMacros_token3] = aux_sym__propertyNameWithMacros_token3,
  [anon_sym_] = anon_sym_,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_AT_LBRACE] = aux_sym__propertyName_token4,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_max] = anon_sym_max,
  [aux_sym__attribute_token1] = aux_sym__propertyName_token4,
  [aux_sym__attribute_token2] = aux_sym__attribute_token2,
  [anon_sym_PERCENT_LBRACE] = aux_sym__propertyName_token4,
  [aux_sym__macro_spaceNL_token1] = aux_sym__macro_spaceNL_token1,
  [anon_sym_POUND2] = anon_sym_POUND2,
  [aux_sym_macroName_token1] = aux_sym_macroName_token1,
  [anon_sym_AT] = anon_sym_AT,
  [aux_sym__macroNameInsideAttributeName_token1] = aux_sym__macroNameInsideAttributeName_token1,
  [anon_sym_2] = anon_sym_2,
  [sym__EOF] = sym__EOF,
  [sym___attribute_start] = sym___attribute_start,
  [sym___ability_start] = sym___ability_start,
  [sym_roll20_script] = sym_roll20_script,
  [sym__stringNL] = sym__stringNL,
  [sym__tokenSelector] = sym__tokenSelector,
  [sym__propertyName] = sym__propertyName,
  [sym__propertyNameWithMacros] = sym__propertyNameWithMacros,
  [sym__selector] = sym__selector,
  [sym__selectorWithMacros] = sym__selectorWithMacros,
  [sym_attribute] = sym_attribute,
  [sym__attribute_empty] = aux_sym__propertyName_token4,
  [sym__attribute] = sym__attribute,
  [sym_ability] = sym_ability,
  [sym__ability_empty] = aux_sym__propertyName_token4,
  [sym__ability] = sym__ability,
  [sym__macro_spaceNL] = sym__macro_spaceNL,
  [sym_macro] = sym_macro,
  [sym_macroName] = sym_macroName,
  [sym__macroInsideAttributeName] = sym__macroInsideAttributeName,
  [sym__macroNameInsideAttributeName] = sym_macroName,
  [aux_sym_roll20_script_repeat1] = aux_sym_roll20_script_repeat1,
  [aux_sym__stringNL_repeat1] = aux_sym__stringNL_repeat1,
  [aux_sym__propertyName_repeat1] = aux_sym__propertyName_repeat1,
  [aux_sym__propertyNameWithMacros_repeat1] = aux_sym__propertyNameWithMacros_repeat1,
  [aux_sym__attribute_repeat1] = aux_sym__attribute_repeat1,
  [aux_sym_macroName_repeat1] = aux_sym_macroName_repeat1,
  [aux_sym__macroNameInsideAttributeName_repeat1] = aux_sym__macroNameInsideAttributeName_repeat1,
  [alias_sym_abilityName] = alias_sym_abilityName,
  [alias_sym_attributeName] = alias_sym_attributeName,
  [alias_sym_characterName] = alias_sym_characterName,
  [alias_sym_invalid] = alias_sym_invalid,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__stringNL_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_selected] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_target] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__propertyName_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__propertyName_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__propertyName_token3] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__propertyName_token4] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__propertyNameWithMacros_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__propertyNameWithMacros_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__propertyNameWithMacros_token3] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT_LBRACE] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_max] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__attribute_token1] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__attribute_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_PERCENT_LBRACE] = {
    .visible = true,
    .named = true,
  },
  [aux_sym__macro_spaceNL_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_POUND2] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_macroName_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__macroNameInsideAttributeName_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_2] = {
    .visible = true,
    .named = false,
  },
  [sym__EOF] = {
    .visible = false,
    .named = true,
  },
  [sym___attribute_start] = {
    .visible = false,
    .named = true,
  },
  [sym___ability_start] = {
    .visible = false,
    .named = true,
  },
  [sym_roll20_script] = {
    .visible = true,
    .named = true,
  },
  [sym__stringNL] = {
    .visible = false,
    .named = true,
  },
  [sym__tokenSelector] = {
    .visible = false,
    .named = true,
  },
  [sym__propertyName] = {
    .visible = false,
    .named = true,
  },
  [sym__propertyNameWithMacros] = {
    .visible = false,
    .named = true,
  },
  [sym__selector] = {
    .visible = false,
    .named = true,
  },
  [sym__selectorWithMacros] = {
    .visible = false,
    .named = true,
  },
  [sym_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym__attribute_empty] = {
    .visible = true,
    .named = true,
  },
  [sym__attribute] = {
    .visible = false,
    .named = true,
  },
  [sym_ability] = {
    .visible = true,
    .named = true,
  },
  [sym__ability_empty] = {
    .visible = true,
    .named = true,
  },
  [sym__ability] = {
    .visible = false,
    .named = true,
  },
  [sym__macro_spaceNL] = {
    .visible = false,
    .named = true,
  },
  [sym_macro] = {
    .visible = true,
    .named = true,
  },
  [sym_macroName] = {
    .visible = true,
    .named = true,
  },
  [sym__macroInsideAttributeName] = {
    .visible = false,
    .named = true,
  },
  [sym__macroNameInsideAttributeName] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_roll20_script_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__stringNL_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__propertyName_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__propertyNameWithMacros_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__attribute_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_macroName_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__macroNameInsideAttributeName_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_abilityName] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_attributeName] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_characterName] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_invalid] = {
    .visible = true,
    .named = true,
  },
};

static TSSymbol ts_alias_sequences[15][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = alias_sym_characterName,
  },
  [2] = {
    [0] = alias_sym_attributeName,
  },
  [3] = {
    [0] = alias_sym_invalid,
  },
  [4] = {
    [0] = alias_sym_abilityName,
  },
  [5] = {
    [1] = alias_sym_invalid,
  },
  [6] = {
    [0] = sym_macro,
  },
  [7] = {
    [1] = anon_sym_2,
  },
  [8] = {
    [1] = sym_macro,
  },
  [9] = {
    [2] = alias_sym_attributeName,
  },
  [10] = {
    [2] = alias_sym_invalid,
  },
  [11] = {
    [2] = alias_sym_abilityName,
  },
  [12] = {
    [2] = alias_sym_attributeName,
    [3] = alias_sym_invalid,
  },
  [13] = {
    [2] = anon_sym_2,
    [3] = alias_sym_invalid,
  },
  [14] = {
    [2] = alias_sym_attributeName,
    [4] = alias_sym_invalid,
  },
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ACCEPT_TOKEN(anon_sym_2);
      if (eof) ADVANCE(20);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(21);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(72);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(60);
      if (lookahead == '@') ADVANCE(77);
      if (lookahead == '|') ADVANCE(66);
      if (lookahead == '}') ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(79);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(60);
      if (lookahead == '@') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(79);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(60);
      if (lookahead == '|') ADVANCE(65);
      if (lookahead == '}') ADVANCE(62);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(73);
      if (lookahead == 's') ADVANCE(49);
      if (lookahead == 't') ADVANCE(46);
      if (lookahead == '}') ADVANCE(62);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(29);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(69);
      if (lookahead != 0) ADVANCE(58);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(73);
      if (lookahead == '|') ADVANCE(65);
      if (lookahead == '}') ADVANCE(62);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(29);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(58);
      END_STATE();
    case 8:
      if (lookahead == '#') ADVANCE(73);
      if (lookahead == '}') ADVANCE(62);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(29);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(69);
      if (lookahead != 0) ADVANCE(58);
      END_STATE();
    case 9:
      if (lookahead == '@') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '{') ADVANCE(78);
      END_STATE();
    case 10:
      if (lookahead == 'm') ADVANCE(70);
      if (lookahead == '}') ADVANCE(62);
      if (lookahead != 0) ADVANCE(69);
      END_STATE();
    case 11:
      if (lookahead == 's') ADVANCE(34);
      if (lookahead == 't') ADVANCE(31);
      if (lookahead == '}') ADVANCE(62);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(30);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(69);
      if (lookahead != 0) ADVANCE(43);
      END_STATE();
    case 12:
      if (lookahead == 'x') ADVANCE(67);
      END_STATE();
    case 13:
      if (lookahead == '|') ADVANCE(65);
      if (lookahead == '}') ADVANCE(62);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(30);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(43);
      END_STATE();
    case 14:
      if (lookahead == '}') ADVANCE(62);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(30);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(69);
      if (lookahead != 0) ADVANCE(43);
      END_STATE();
    case 15:
      if (lookahead == '}') ADVANCE(62);
      if (lookahead != 0) ADVANCE(69);
      END_STATE();
    case 16:
      if (lookahead == '\n' ||
          lookahead == ' ') ADVANCE(72);
      if (lookahead == '\r') ADVANCE(2);
      if (lookahead == '@') ADVANCE(75);
      if (lookahead != 0) ADVANCE(76);
      END_STATE();
    case 17:
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(59);
      END_STATE();
    case 18:
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(44);
      END_STATE();
    case 19:
      if (eof) ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@') ADVANCE(21);
      if (lookahead == '\r') ADVANCE(22);
      if (lookahead == '#') ADVANCE(74);
      if (lookahead == '%') ADVANCE(23);
      if (lookahead == '@') ADVANCE(24);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '\n') ADVANCE(21);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '{') ADVANCE(71);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '{') ADVANCE(64);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym__propertyName_token1);
      if (lookahead == '{') ADVANCE(45);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(59);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym__propertyName_token1);
      if (lookahead == '{') ADVANCE(45);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(44);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'a') ADVANCE(40);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'c') ADVANCE(42);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'd') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'e') ADVANCE(39);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'e') ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'e') ADVANCE(33);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'e') ADVANCE(41);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'g') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'l') ADVANCE(35);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'r') ADVANCE(38);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 't') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 't') ADVANCE(36);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym__propertyName_token3);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym__propertyName_token4);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'a') ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'c') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'd') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(47);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(48);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'g') ADVANCE(52);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'l') ADVANCE(50);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'r') ADVANCE(53);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 't') ADVANCE(28);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 't') ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token3);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(79);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(79);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_max);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(68);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym__attribute_token1);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(68);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym__attribute_token2);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym__attribute_token2);
      if (lookahead == 'a') ADVANCE(12);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_PERCENT_LBRACE);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(aux_sym__macro_spaceNL_token1);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_POUND2);
      if (lookahead == ' ') ADVANCE(61);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_POUND2);
      if (lookahead == '\n' ||
          lookahead == ' ') ADVANCE(21);
      if (lookahead == '\r') ADVANCE(1);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_macroName_token1);
      if (lookahead == '{') ADVANCE(64);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(aux_sym_macroName_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(76);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead == '@') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '{') ADVANCE(78);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym__macroNameInsideAttributeName_token1);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym__macroNameInsideAttributeName_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(79);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 19, .external_lex_state = 2},
  [2] = {.lex_state = 6},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 19, .external_lex_state = 2},
  [5] = {.lex_state = 19, .external_lex_state = 2},
  [6] = {.lex_state = 11},
  [7] = {.lex_state = 8},
  [8] = {.lex_state = 7},
  [9] = {.lex_state = 7},
  [10] = {.lex_state = 7},
  [11] = {.lex_state = 14},
  [12] = {.lex_state = 7},
  [13] = {.lex_state = 19, .external_lex_state = 2},
  [14] = {.lex_state = 19, .external_lex_state = 2},
  [15] = {.lex_state = 16, .external_lex_state = 3},
  [16] = {.lex_state = 16, .external_lex_state = 3},
  [17] = {.lex_state = 13},
  [18] = {.lex_state = 13},
  [19] = {.lex_state = 19, .external_lex_state = 2},
  [20] = {.lex_state = 16, .external_lex_state = 4},
  [21] = {.lex_state = 14},
  [22] = {.lex_state = 19, .external_lex_state = 2},
  [23] = {.lex_state = 19, .external_lex_state = 2},
  [24] = {.lex_state = 19, .external_lex_state = 2},
  [25] = {.lex_state = 19, .external_lex_state = 2},
  [26] = {.lex_state = 19, .external_lex_state = 2},
  [27] = {.lex_state = 19, .external_lex_state = 2},
  [28] = {.lex_state = 14},
  [29] = {.lex_state = 3},
  [30] = {.lex_state = 3},
  [31] = {.lex_state = 16, .external_lex_state = 3},
  [32] = {.lex_state = 10},
  [33] = {.lex_state = 16, .external_lex_state = 3},
  [34] = {.lex_state = 16, .external_lex_state = 3},
  [35] = {.lex_state = 4},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 4},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 15},
  [40] = {.lex_state = 5},
  [41] = {.lex_state = 15},
  [42] = {.lex_state = 5},
  [43] = {.lex_state = 5},
  [44] = {.lex_state = 15},
  [45] = {.lex_state = 5},
  [46] = {.lex_state = 15},
  [47] = {.lex_state = 15},
  [48] = {.lex_state = 15},
  [49] = {.lex_state = 15},
  [50] = {.lex_state = 15},
  [51] = {.lex_state = 16, .external_lex_state = 5},
  [52] = {.lex_state = 15},
  [53] = {.lex_state = 7},
  [54] = {.lex_state = 7},
  [55] = {.lex_state = 7},
  [56] = {.lex_state = 16, .external_lex_state = 5},
  [57] = {.lex_state = 7},
  [58] = {.lex_state = 19},
  [59] = {.lex_state = 7},
  [60] = {.lex_state = 7},
  [61] = {.lex_state = 15},
  [62] = {.lex_state = 7},
  [63] = {.lex_state = 15},
  [64] = {.lex_state = 6},
  [65] = {.lex_state = 7},
  [66] = {.lex_state = 3},
  [67] = {.lex_state = 7},
  [68] = {.lex_state = 3},
  [69] = {.lex_state = 6},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 6},
  [72] = {.lex_state = 6},
};

enum {
  ts_external_token__EOF = 0,
  ts_external_token___attribute_start = 1,
  ts_external_token___ability_start = 2,
};

static TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__EOF] = sym__EOF,
  [ts_external_token___attribute_start] = sym___attribute_start,
  [ts_external_token___ability_start] = sym___ability_start,
};

static bool ts_external_scanner_states[6][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__EOF] = true,
    [ts_external_token___attribute_start] = true,
    [ts_external_token___ability_start] = true,
  },
  [2] = {
    [ts_external_token___attribute_start] = true,
    [ts_external_token___ability_start] = true,
  },
  [3] = {
    [ts_external_token__EOF] = true,
    [ts_external_token___attribute_start] = true,
  },
  [4] = {
    [ts_external_token___attribute_start] = true,
  },
  [5] = {
    [ts_external_token__EOF] = true,
  },
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_2] = ACTIONS(1),
    [sym__EOF] = ACTIONS(1),
    [sym___attribute_start] = ACTIONS(1),
    [sym___ability_start] = ACTIONS(1),
  },
  [1] = {
    [sym_roll20_script] = STATE(70),
    [sym__stringNL] = STATE(4),
    [sym_attribute] = STATE(4),
    [sym__attribute_empty] = STATE(22),
    [sym_ability] = STATE(4),
    [sym__ability_empty] = STATE(19),
    [sym__macro_spaceNL] = STATE(4),
    [sym_macro] = STATE(56),
    [aux_sym_roll20_script_repeat1] = STATE(4),
    [aux_sym__stringNL_repeat1] = STATE(13),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym__stringNL_token1] = ACTIONS(5),
    [anon_sym_AT_LBRACE] = ACTIONS(7),
    [anon_sym_PERCENT_LBRACE] = ACTIONS(9),
    [anon_sym_POUND2] = ACTIONS(11),
    [sym___attribute_start] = ACTIONS(13),
    [sym___ability_start] = ACTIONS(15),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 14,
    ACTIONS(19), 1,
      aux_sym__propertyName_token1,
    ACTIONS(23), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(25), 1,
      aux_sym__propertyNameWithMacros_token2,
    ACTIONS(27), 1,
      anon_sym_RBRACE,
    ACTIONS(29), 1,
      aux_sym__attribute_token2,
    ACTIONS(31), 1,
      anon_sym_POUND2,
    STATE(8), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(41), 1,
      aux_sym__attribute_repeat1,
    STATE(62), 1,
      sym__propertyNameWithMacros,
    STATE(64), 1,
      sym__attribute,
    STATE(66), 1,
      sym__macroInsideAttributeName,
    ACTIONS(17), 2,
      anon_sym_selected,
      anon_sym_target,
    STATE(65), 2,
      sym__tokenSelector,
      sym__selectorWithMacros,
    ACTIONS(21), 3,
      aux_sym__propertyName_token4,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
  [47] = 14,
    ACTIONS(19), 1,
      aux_sym__propertyName_token1,
    ACTIONS(23), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(25), 1,
      aux_sym__propertyNameWithMacros_token2,
    ACTIONS(29), 1,
      aux_sym__attribute_token2,
    ACTIONS(31), 1,
      anon_sym_POUND2,
    ACTIONS(33), 1,
      anon_sym_RBRACE,
    STATE(8), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(41), 1,
      aux_sym__attribute_repeat1,
    STATE(62), 1,
      sym__propertyNameWithMacros,
    STATE(66), 1,
      sym__macroInsideAttributeName,
    STATE(72), 1,
      sym__attribute,
    ACTIONS(17), 2,
      anon_sym_selected,
      anon_sym_target,
    STATE(65), 2,
      sym__tokenSelector,
      sym__selectorWithMacros,
    ACTIONS(21), 3,
      aux_sym__propertyName_token4,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
  [94] = 12,
    ACTIONS(5), 1,
      aux_sym__stringNL_token1,
    ACTIONS(7), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(9), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(11), 1,
      anon_sym_POUND2,
    ACTIONS(13), 1,
      sym___attribute_start,
    ACTIONS(15), 1,
      sym___ability_start,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    STATE(13), 1,
      aux_sym__stringNL_repeat1,
    STATE(19), 1,
      sym__ability_empty,
    STATE(22), 1,
      sym__attribute_empty,
    STATE(56), 1,
      sym_macro,
    STATE(5), 5,
      sym__stringNL,
      sym_attribute,
      sym_ability,
      sym__macro_spaceNL,
      aux_sym_roll20_script_repeat1,
  [135] = 12,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    ACTIONS(39), 1,
      aux_sym__stringNL_token1,
    ACTIONS(42), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(45), 1,
      anon_sym_PERCENT_LBRACE,
    ACTIONS(48), 1,
      anon_sym_POUND2,
    ACTIONS(51), 1,
      sym___attribute_start,
    ACTIONS(54), 1,
      sym___ability_start,
    STATE(13), 1,
      aux_sym__stringNL_repeat1,
    STATE(19), 1,
      sym__ability_empty,
    STATE(22), 1,
      sym__attribute_empty,
    STATE(56), 1,
      sym_macro,
    STATE(5), 5,
      sym__stringNL,
      sym_attribute,
      sym_ability,
      sym__macro_spaceNL,
      aux_sym_roll20_script_repeat1,
  [176] = 11,
    ACTIONS(29), 1,
      aux_sym__attribute_token2,
    ACTIONS(59), 1,
      aux_sym__propertyName_token1,
    ACTIONS(61), 1,
      aux_sym__propertyName_token2,
    ACTIONS(65), 1,
      anon_sym_RBRACE,
    STATE(17), 1,
      aux_sym__propertyName_repeat1,
    STATE(49), 1,
      aux_sym__attribute_repeat1,
    STATE(55), 1,
      sym__propertyName,
    STATE(71), 1,
      sym__ability,
    ACTIONS(57), 2,
      anon_sym_selected,
      anon_sym_target,
    ACTIONS(63), 2,
      aux_sym__propertyName_token3,
      aux_sym__propertyName_token4,
    STATE(67), 2,
      sym__tokenSelector,
      sym__selector,
  [213] = 10,
    ACTIONS(19), 1,
      aux_sym__propertyName_token1,
    ACTIONS(23), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(29), 1,
      aux_sym__attribute_token2,
    ACTIONS(31), 1,
      anon_sym_POUND2,
    ACTIONS(67), 1,
      anon_sym_RBRACE,
    STATE(8), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(50), 1,
      aux_sym__attribute_repeat1,
    STATE(53), 1,
      sym__propertyNameWithMacros,
    STATE(66), 1,
      sym__macroInsideAttributeName,
    ACTIONS(21), 4,
      aux_sym__propertyName_token4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
  [247] = 7,
    ACTIONS(19), 1,
      aux_sym__propertyName_token1,
    ACTIONS(71), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(75), 1,
      anon_sym_POUND2,
    STATE(9), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(42), 1,
      sym__macroInsideAttributeName,
    ACTIONS(73), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(69), 4,
      aux_sym__propertyName_token4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
  [273] = 7,
    ACTIONS(77), 1,
      aux_sym__propertyName_token1,
    ACTIONS(83), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(87), 1,
      anon_sym_POUND2,
    STATE(9), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(66), 1,
      sym__macroInsideAttributeName,
    ACTIONS(85), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(80), 4,
      aux_sym__propertyName_token4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
  [299] = 2,
    ACTIONS(90), 3,
      aux_sym__propertyName_token1,
      aux_sym__propertyNameWithMacros_token1,
      anon_sym_POUND2,
    ACTIONS(92), 6,
      aux_sym__propertyName_token4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [313] = 7,
    ACTIONS(29), 1,
      aux_sym__attribute_token2,
    ACTIONS(94), 1,
      aux_sym__propertyName_token1,
    ACTIONS(98), 1,
      anon_sym_RBRACE,
    STATE(28), 1,
      aux_sym__propertyName_repeat1,
    STATE(39), 1,
      sym__propertyName,
    STATE(48), 1,
      aux_sym__attribute_repeat1,
    ACTIONS(96), 3,
      aux_sym__propertyName_token2,
      aux_sym__propertyName_token3,
      aux_sym__propertyName_token4,
  [337] = 2,
    ACTIONS(100), 3,
      aux_sym__propertyName_token1,
      aux_sym__propertyNameWithMacros_token1,
      anon_sym_POUND2,
    ACTIONS(102), 6,
      aux_sym__propertyName_token4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [351] = 4,
    ACTIONS(106), 1,
      aux_sym__stringNL_token1,
    ACTIONS(108), 1,
      anon_sym_POUND2,
    STATE(14), 1,
      aux_sym__stringNL_repeat1,
    ACTIONS(104), 5,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [368] = 4,
    ACTIONS(112), 1,
      aux_sym__stringNL_token1,
    ACTIONS(115), 1,
      anon_sym_POUND2,
    STATE(14), 1,
      aux_sym__stringNL_repeat1,
    ACTIONS(110), 5,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [385] = 6,
    ACTIONS(117), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(121), 1,
      aux_sym_macroName_token1,
    ACTIONS(123), 1,
      sym___attribute_start,
    STATE(33), 1,
      sym__attribute_empty,
    ACTIONS(119), 2,
      sym__EOF,
      aux_sym__macro_spaceNL_token1,
    STATE(16), 2,
      sym_attribute,
      aux_sym_macroName_repeat1,
  [406] = 6,
    ACTIONS(125), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(130), 1,
      aux_sym_macroName_token1,
    ACTIONS(133), 1,
      sym___attribute_start,
    STATE(33), 1,
      sym__attribute_empty,
    ACTIONS(128), 2,
      sym__EOF,
      aux_sym__macro_spaceNL_token1,
    STATE(16), 2,
      sym_attribute,
      aux_sym_macroName_repeat1,
  [427] = 4,
    ACTIONS(136), 1,
      aux_sym__propertyName_token1,
    STATE(18), 1,
      aux_sym__propertyName_repeat1,
    ACTIONS(140), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(138), 3,
      aux_sym__propertyName_token2,
      aux_sym__propertyName_token3,
      aux_sym__propertyName_token4,
  [443] = 4,
    ACTIONS(142), 1,
      aux_sym__propertyName_token1,
    STATE(18), 1,
      aux_sym__propertyName_repeat1,
    ACTIONS(147), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(144), 3,
      aux_sym__propertyName_token2,
      aux_sym__propertyName_token3,
      aux_sym__propertyName_token4,
  [459] = 2,
    ACTIONS(151), 2,
      aux_sym__stringNL_token1,
      anon_sym_POUND2,
    ACTIONS(149), 5,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [471] = 6,
    ACTIONS(117), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(123), 1,
      sym___attribute_start,
    ACTIONS(153), 1,
      aux_sym_macroName_token1,
    STATE(33), 1,
      sym__attribute_empty,
    STATE(51), 1,
      sym_macroName,
    STATE(15), 2,
      sym_attribute,
      aux_sym_macroName_repeat1,
  [491] = 4,
    ACTIONS(147), 1,
      anon_sym_RBRACE,
    STATE(21), 1,
      aux_sym__propertyName_repeat1,
    ACTIONS(142), 2,
      aux_sym__propertyName_token1,
      aux_sym__attribute_token2,
    ACTIONS(155), 3,
      aux_sym__propertyName_token2,
      aux_sym__propertyName_token3,
      aux_sym__propertyName_token4,
  [507] = 2,
    ACTIONS(160), 2,
      aux_sym__stringNL_token1,
      anon_sym_POUND2,
    ACTIONS(158), 5,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [519] = 2,
    ACTIONS(164), 2,
      aux_sym__stringNL_token1,
      anon_sym_POUND2,
    ACTIONS(162), 5,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [531] = 2,
    ACTIONS(168), 2,
      aux_sym__stringNL_token1,
      anon_sym_POUND2,
    ACTIONS(166), 5,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [543] = 2,
    ACTIONS(172), 2,
      aux_sym__stringNL_token1,
      anon_sym_POUND2,
    ACTIONS(170), 5,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [555] = 2,
    ACTIONS(176), 2,
      aux_sym__stringNL_token1,
      anon_sym_POUND2,
    ACTIONS(174), 5,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [567] = 2,
    ACTIONS(180), 2,
      aux_sym__stringNL_token1,
      anon_sym_POUND2,
    ACTIONS(178), 5,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
  [579] = 5,
    ACTIONS(140), 1,
      anon_sym_RBRACE,
    ACTIONS(182), 1,
      aux_sym__propertyName_token1,
    ACTIONS(186), 1,
      aux_sym__attribute_token2,
    STATE(21), 1,
      aux_sym__propertyName_repeat1,
    ACTIONS(184), 3,
      aux_sym__propertyName_token2,
      aux_sym__propertyName_token3,
      aux_sym__propertyName_token4,
  [597] = 5,
    ACTIONS(188), 1,
      anon_sym_,
    ACTIONS(192), 1,
      anon_sym_AT,
    ACTIONS(194), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(30), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    ACTIONS(190), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [614] = 4,
    ACTIONS(196), 1,
      anon_sym_,
    ACTIONS(200), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(30), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    ACTIONS(198), 3,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      anon_sym_AT,
  [629] = 2,
    ACTIONS(180), 1,
      aux_sym_macroName_token1,
    ACTIONS(178), 4,
      sym__EOF,
      sym___attribute_start,
      anon_sym_AT_LBRACE,
      aux_sym__macro_spaceNL_token1,
  [639] = 5,
    ACTIONS(29), 1,
      aux_sym__attribute_token2,
    ACTIONS(203), 1,
      anon_sym_RBRACE,
    ACTIONS(205), 1,
      anon_sym_max,
    ACTIONS(207), 1,
      aux_sym__attribute_token1,
    STATE(46), 1,
      aux_sym__attribute_repeat1,
  [655] = 2,
    ACTIONS(160), 1,
      aux_sym_macroName_token1,
    ACTIONS(158), 4,
      sym__EOF,
      sym___attribute_start,
      anon_sym_AT_LBRACE,
      aux_sym__macro_spaceNL_token1,
  [665] = 2,
    ACTIONS(168), 1,
      aux_sym_macroName_token1,
    ACTIONS(166), 4,
      sym__EOF,
      sym___attribute_start,
      anon_sym_AT_LBRACE,
      aux_sym__macro_spaceNL_token1,
  [675] = 4,
    ACTIONS(209), 1,
      anon_sym_AT,
    ACTIONS(211), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(38), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    STATE(43), 1,
      sym__macroNameInsideAttributeName,
  [688] = 4,
    ACTIONS(196), 1,
      anon_sym_,
    ACTIONS(198), 1,
      anon_sym_AT,
    ACTIONS(213), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(36), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
  [701] = 4,
    ACTIONS(209), 1,
      anon_sym_AT,
    ACTIONS(216), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(29), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    STATE(43), 1,
      sym__macroNameInsideAttributeName,
  [714] = 4,
    ACTIONS(188), 1,
      anon_sym_,
    ACTIONS(192), 1,
      anon_sym_AT,
    ACTIONS(218), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(36), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
  [727] = 3,
    ACTIONS(220), 1,
      anon_sym_RBRACE,
    ACTIONS(222), 1,
      aux_sym__attribute_token2,
    STATE(47), 1,
      aux_sym__attribute_repeat1,
  [737] = 1,
    ACTIONS(224), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [743] = 3,
    ACTIONS(222), 1,
      aux_sym__attribute_token2,
    ACTIONS(226), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [753] = 2,
    ACTIONS(228), 1,
      anon_sym_,
    ACTIONS(230), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [761] = 1,
    ACTIONS(232), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [767] = 3,
    ACTIONS(234), 1,
      anon_sym_RBRACE,
    ACTIONS(236), 1,
      aux_sym__attribute_token2,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [777] = 1,
    ACTIONS(188), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [783] = 3,
    ACTIONS(222), 1,
      aux_sym__attribute_token2,
    ACTIONS(239), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [793] = 3,
    ACTIONS(222), 1,
      aux_sym__attribute_token2,
    ACTIONS(241), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [803] = 3,
    ACTIONS(222), 1,
      aux_sym__attribute_token2,
    ACTIONS(243), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [813] = 3,
    ACTIONS(222), 1,
      aux_sym__attribute_token2,
    ACTIONS(245), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [823] = 3,
    ACTIONS(222), 1,
      aux_sym__attribute_token2,
    ACTIONS(247), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [833] = 1,
    ACTIONS(249), 2,
      sym__EOF,
      aux_sym__macro_spaceNL_token1,
  [838] = 1,
    ACTIONS(251), 2,
      anon_sym_RBRACE,
      aux_sym__attribute_token2,
  [843] = 2,
    ACTIONS(253), 1,
      anon_sym_RBRACE,
    ACTIONS(255), 1,
      anon_sym_PIPE,
  [850] = 1,
    ACTIONS(257), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [855] = 2,
    ACTIONS(259), 1,
      anon_sym_RBRACE,
    ACTIONS(261), 1,
      anon_sym_PIPE,
  [862] = 1,
    ACTIONS(263), 2,
      sym__EOF,
      aux_sym__macro_spaceNL_token1,
  [867] = 1,
    ACTIONS(140), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [872] = 2,
    ACTIONS(265), 1,
      anon_sym_POUND2,
    STATE(68), 1,
      sym__macroInsideAttributeName,
  [879] = 1,
    ACTIONS(73), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [884] = 1,
    ACTIONS(251), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [889] = 1,
    ACTIONS(267), 2,
      anon_sym_RBRACE,
      aux_sym__attribute_token2,
  [894] = 2,
    ACTIONS(269), 1,
      anon_sym_RBRACE,
    ACTIONS(271), 1,
      anon_sym_PIPE,
  [901] = 1,
    ACTIONS(140), 2,
      anon_sym_RBRACE,
      aux_sym__attribute_token2,
  [906] = 1,
    ACTIONS(273), 1,
      anon_sym_RBRACE,
  [910] = 1,
    ACTIONS(275), 1,
      anon_sym_PIPE,
  [914] = 1,
    ACTIONS(228), 1,
      anon_sym_,
  [918] = 1,
    ACTIONS(277), 1,
      anon_sym_PIPE,
  [922] = 1,
    ACTIONS(279), 1,
      anon_sym_,
  [926] = 1,
    ACTIONS(281), 1,
      anon_sym_RBRACE,
  [930] = 1,
    ACTIONS(283), 1,
      ts_builtin_sym_end,
  [934] = 1,
    ACTIONS(285), 1,
      anon_sym_RBRACE,
  [938] = 1,
    ACTIONS(287), 1,
      anon_sym_RBRACE,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 47,
  [SMALL_STATE(4)] = 94,
  [SMALL_STATE(5)] = 135,
  [SMALL_STATE(6)] = 176,
  [SMALL_STATE(7)] = 213,
  [SMALL_STATE(8)] = 247,
  [SMALL_STATE(9)] = 273,
  [SMALL_STATE(10)] = 299,
  [SMALL_STATE(11)] = 313,
  [SMALL_STATE(12)] = 337,
  [SMALL_STATE(13)] = 351,
  [SMALL_STATE(14)] = 368,
  [SMALL_STATE(15)] = 385,
  [SMALL_STATE(16)] = 406,
  [SMALL_STATE(17)] = 427,
  [SMALL_STATE(18)] = 443,
  [SMALL_STATE(19)] = 459,
  [SMALL_STATE(20)] = 471,
  [SMALL_STATE(21)] = 491,
  [SMALL_STATE(22)] = 507,
  [SMALL_STATE(23)] = 519,
  [SMALL_STATE(24)] = 531,
  [SMALL_STATE(25)] = 543,
  [SMALL_STATE(26)] = 555,
  [SMALL_STATE(27)] = 567,
  [SMALL_STATE(28)] = 579,
  [SMALL_STATE(29)] = 597,
  [SMALL_STATE(30)] = 614,
  [SMALL_STATE(31)] = 629,
  [SMALL_STATE(32)] = 639,
  [SMALL_STATE(33)] = 655,
  [SMALL_STATE(34)] = 665,
  [SMALL_STATE(35)] = 675,
  [SMALL_STATE(36)] = 688,
  [SMALL_STATE(37)] = 701,
  [SMALL_STATE(38)] = 714,
  [SMALL_STATE(39)] = 727,
  [SMALL_STATE(40)] = 737,
  [SMALL_STATE(41)] = 743,
  [SMALL_STATE(42)] = 753,
  [SMALL_STATE(43)] = 761,
  [SMALL_STATE(44)] = 767,
  [SMALL_STATE(45)] = 777,
  [SMALL_STATE(46)] = 783,
  [SMALL_STATE(47)] = 793,
  [SMALL_STATE(48)] = 803,
  [SMALL_STATE(49)] = 813,
  [SMALL_STATE(50)] = 823,
  [SMALL_STATE(51)] = 833,
  [SMALL_STATE(52)] = 838,
  [SMALL_STATE(53)] = 843,
  [SMALL_STATE(54)] = 850,
  [SMALL_STATE(55)] = 855,
  [SMALL_STATE(56)] = 862,
  [SMALL_STATE(57)] = 867,
  [SMALL_STATE(58)] = 872,
  [SMALL_STATE(59)] = 879,
  [SMALL_STATE(60)] = 884,
  [SMALL_STATE(61)] = 889,
  [SMALL_STATE(62)] = 894,
  [SMALL_STATE(63)] = 901,
  [SMALL_STATE(64)] = 906,
  [SMALL_STATE(65)] = 910,
  [SMALL_STATE(66)] = 914,
  [SMALL_STATE(67)] = 918,
  [SMALL_STATE(68)] = 922,
  [SMALL_STATE(69)] = 926,
  [SMALL_STATE(70)] = 930,
  [SMALL_STATE(71)] = 934,
  [SMALL_STATE(72)] = 938,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_roll20_script, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_roll20_script, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(13),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(22),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(19),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(20),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(2),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(6),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 2, .production_id = 5),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 1),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [77] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(58),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(9),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(35),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2, .production_id = 6),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2, .production_id = 6),
  [94] = {.entry = {.count = 1, .reusable = false}}, SHIFT(63),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 2, .production_id = 5),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 3, .production_id = 8),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 3, .production_id = 8),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__stringNL, 1),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__stringNL, 1),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stringNL_repeat1, 2),
  [112] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__stringNL_repeat1, 2), SHIFT_REPEAT(14),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__stringNL_repeat1, 2),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macroName, 1),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [125] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_macroName_repeat1, 2), SHIFT_REPEAT(33),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_macroName_repeat1, 2),
  [130] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_macroName_repeat1, 2), SHIFT_REPEAT(16),
  [133] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_macroName_repeat1, 2), SHIFT_REPEAT(3),
  [136] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyName, 1),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyName_repeat1, 2),
  [144] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__propertyName_repeat1, 2), SHIFT_REPEAT(18),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyName_repeat1, 2),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 1),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 1),
  [153] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [155] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__propertyName_repeat1, 2), SHIFT_REPEAT(21),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 1),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability_empty, 2),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__ability_empty, 2),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_empty, 2),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_empty, 2),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macro_spaceNL, 2),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macro_spaceNL, 2),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 3),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 3),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [182] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__propertyName, 1),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroNameInsideAttributeName, 1),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macroNameInsideAttributeName, 1),
  [192] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [194] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2),
  [200] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2), SHIFT_REPEAT(30),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 4, .production_id = 12),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [213] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2), SHIFT_REPEAT(36),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 3, .production_id = 11),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroNameInsideAttributeName, 2),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 1, .production_id = 3),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 2, .production_id = 7),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroInsideAttributeName, 2),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 2),
  [236] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 2), SHIFT_REPEAT(61),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 5, .production_id = 14),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 4, .production_id = 13),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 3, .production_id = 10),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 1, .production_id = 3),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 3, .production_id = 10),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 2),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyName, 2),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 3, .production_id = 9),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 2),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 1, .production_id = 4),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selector, 1, .production_id = 1),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 1),
  [269] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 1, .production_id = 2),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selectorWithMacros, 1, .production_id = 1),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 5, .production_id = 9),
  [283] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
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
