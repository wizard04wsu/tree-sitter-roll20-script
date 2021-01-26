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
  aux_sym__macroNL_token1 = 20,
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
  sym__macroNL = 42,
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
  [aux_sym__macroNL_token1] = "_macroNL_token1",
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
  [sym__macroNL] = "_macroNL",
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
  [aux_sym__macroNL_token1] = aux_sym__macroNL_token1,
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
  [sym__macroNL] = sym__macroNL,
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
  [aux_sym__macroNL_token1] = {
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
  [sym__macroNL] = {
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
      if (eof) ADVANCE(19);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(71);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(59);
      if (lookahead == '@') ADVANCE(77);
      if (lookahead == '|') ADVANCE(65);
      if (lookahead == '}') ADVANCE(62);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(79);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(59);
      if (lookahead == '@') ADVANCE(77);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(79);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(59);
      if (lookahead == '|') ADVANCE(64);
      if (lookahead == '}') ADVANCE(61);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(73);
      if (lookahead == 's') ADVANCE(48);
      if (lookahead == 't') ADVANCE(45);
      if (lookahead == '}') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(28);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(68);
      if (lookahead != 0) ADVANCE(57);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(73);
      if (lookahead == '|') ADVANCE(64);
      if (lookahead == '}') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(28);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(57);
      END_STATE();
    case 7:
      if (lookahead == '#') ADVANCE(73);
      if (lookahead == '}') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(28);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(68);
      if (lookahead != 0) ADVANCE(57);
      END_STATE();
    case 8:
      if (lookahead == '@') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '{') ADVANCE(78);
      END_STATE();
    case 9:
      if (lookahead == 'm') ADVANCE(69);
      if (lookahead == '}') ADVANCE(61);
      if (lookahead != 0) ADVANCE(68);
      END_STATE();
    case 10:
      if (lookahead == 's') ADVANCE(33);
      if (lookahead == 't') ADVANCE(30);
      if (lookahead == '}') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(29);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(68);
      if (lookahead != 0) ADVANCE(42);
      END_STATE();
    case 11:
      if (lookahead == 'x') ADVANCE(66);
      END_STATE();
    case 12:
      if (lookahead == '|') ADVANCE(64);
      if (lookahead == '}') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(29);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(42);
      END_STATE();
    case 13:
      if (lookahead == '}') ADVANCE(61);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(29);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(68);
      if (lookahead != 0) ADVANCE(42);
      END_STATE();
    case 14:
      if (lookahead == '}') ADVANCE(61);
      if (lookahead != 0) ADVANCE(68);
      END_STATE();
    case 15:
      if (lookahead == '\n' ||
          lookahead == ' ') ADVANCE(71);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '@') ADVANCE(75);
      if (lookahead != 0) ADVANCE(76);
      END_STATE();
    case 16:
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(16);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(58);
      END_STATE();
    case 17:
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(43);
      END_STATE();
    case 18:
      if (eof) ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@') ADVANCE(20);
      if (lookahead == '\r') ADVANCE(21);
      if (lookahead == '#') ADVANCE(72);
      if (lookahead == '%') ADVANCE(22);
      if (lookahead == '@') ADVANCE(23);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '\n') ADVANCE(20);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '{') ADVANCE(70);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '{') ADVANCE(63);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym__propertyName_token1);
      if (lookahead == '{') ADVANCE(44);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(16);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym__propertyName_token1);
      if (lookahead == '{') ADVANCE(44);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'a') ADVANCE(39);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'c') ADVANCE(41);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'd') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'e') ADVANCE(38);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'e') ADVANCE(31);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
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
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'e') ADVANCE(40);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'g') ADVANCE(36);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'l') ADVANCE(34);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 'r') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 't') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead == 't') ADVANCE(35);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym__propertyName_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym__propertyName_token3);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym__propertyName_token4);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'a') ADVANCE(54);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'c') ADVANCE(56);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'd') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(53);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(46);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
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
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'g') ADVANCE(51);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'l') ADVANCE(49);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'r') ADVANCE(52);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 't') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 't') ADVANCE(50);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(57);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token3);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(79);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(79);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_max);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(67);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym__attribute_token1);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(67);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym__attribute_token2);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym__attribute_token2);
      if (lookahead == 'a') ADVANCE(11);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_PERCENT_LBRACE);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym__macroNL_token1);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_POUND2);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_POUND2);
      if (lookahead == ' ') ADVANCE(60);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(aux_sym_macroName_token1);
      if (lookahead == '@') ADVANCE(74);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(aux_sym_macroName_token1);
      if (lookahead == '@') ADVANCE(74);
      if (lookahead == '{') ADVANCE(63);
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
      if (lookahead == '@') ADVANCE(8);
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
  [1] = {.lex_state = 18, .external_lex_state = 2},
  [2] = {.lex_state = 5},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 18, .external_lex_state = 2},
  [5] = {.lex_state = 18, .external_lex_state = 2},
  [6] = {.lex_state = 10},
  [7] = {.lex_state = 7},
  [8] = {.lex_state = 6},
  [9] = {.lex_state = 6},
  [10] = {.lex_state = 6},
  [11] = {.lex_state = 13},
  [12] = {.lex_state = 6},
  [13] = {.lex_state = 18, .external_lex_state = 2},
  [14] = {.lex_state = 18, .external_lex_state = 2},
  [15] = {.lex_state = 15, .external_lex_state = 3},
  [16] = {.lex_state = 15, .external_lex_state = 3},
  [17] = {.lex_state = 12},
  [18] = {.lex_state = 12},
  [19] = {.lex_state = 18, .external_lex_state = 2},
  [20] = {.lex_state = 15, .external_lex_state = 4},
  [21] = {.lex_state = 13},
  [22] = {.lex_state = 18, .external_lex_state = 2},
  [23] = {.lex_state = 18, .external_lex_state = 2},
  [24] = {.lex_state = 18, .external_lex_state = 2},
  [25] = {.lex_state = 18, .external_lex_state = 2},
  [26] = {.lex_state = 18, .external_lex_state = 2},
  [27] = {.lex_state = 18, .external_lex_state = 2},
  [28] = {.lex_state = 13},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 15, .external_lex_state = 3},
  [32] = {.lex_state = 9},
  [33] = {.lex_state = 15, .external_lex_state = 3},
  [34] = {.lex_state = 15, .external_lex_state = 3},
  [35] = {.lex_state = 3},
  [36] = {.lex_state = 3},
  [37] = {.lex_state = 3},
  [38] = {.lex_state = 3},
  [39] = {.lex_state = 14},
  [40] = {.lex_state = 4},
  [41] = {.lex_state = 14},
  [42] = {.lex_state = 4},
  [43] = {.lex_state = 4},
  [44] = {.lex_state = 14},
  [45] = {.lex_state = 4},
  [46] = {.lex_state = 14},
  [47] = {.lex_state = 14},
  [48] = {.lex_state = 14},
  [49] = {.lex_state = 14},
  [50] = {.lex_state = 14},
  [51] = {.lex_state = 15, .external_lex_state = 5},
  [52] = {.lex_state = 14},
  [53] = {.lex_state = 6},
  [54] = {.lex_state = 6},
  [55] = {.lex_state = 6},
  [56] = {.lex_state = 15, .external_lex_state = 5},
  [57] = {.lex_state = 6},
  [58] = {.lex_state = 18},
  [59] = {.lex_state = 6},
  [60] = {.lex_state = 6},
  [61] = {.lex_state = 14},
  [62] = {.lex_state = 6},
  [63] = {.lex_state = 14},
  [64] = {.lex_state = 5},
  [65] = {.lex_state = 6},
  [66] = {.lex_state = 2},
  [67] = {.lex_state = 6},
  [68] = {.lex_state = 2},
  [69] = {.lex_state = 5},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 5},
  [72] = {.lex_state = 5},
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
    [sym__macroNL] = STATE(4),
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
      sym__macroNL,
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
      sym__macroNL,
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
  [351] = 3,
    ACTIONS(106), 1,
      aux_sym__stringNL_token1,
    STATE(14), 1,
      aux_sym__stringNL_repeat1,
    ACTIONS(104), 6,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND2,
  [366] = 3,
    ACTIONS(110), 1,
      aux_sym__stringNL_token1,
    STATE(14), 1,
      aux_sym__stringNL_repeat1,
    ACTIONS(108), 6,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND2,
  [381] = 6,
    ACTIONS(113), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(117), 1,
      aux_sym_macroName_token1,
    ACTIONS(119), 1,
      sym___attribute_start,
    STATE(33), 1,
      sym__attribute_empty,
    ACTIONS(115), 2,
      sym__EOF,
      aux_sym__macroNL_token1,
    STATE(16), 2,
      sym_attribute,
      aux_sym_macroName_repeat1,
  [402] = 6,
    ACTIONS(121), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(126), 1,
      aux_sym_macroName_token1,
    ACTIONS(129), 1,
      sym___attribute_start,
    STATE(33), 1,
      sym__attribute_empty,
    ACTIONS(124), 2,
      sym__EOF,
      aux_sym__macroNL_token1,
    STATE(16), 2,
      sym_attribute,
      aux_sym_macroName_repeat1,
  [423] = 4,
    ACTIONS(132), 1,
      aux_sym__propertyName_token1,
    STATE(18), 1,
      aux_sym__propertyName_repeat1,
    ACTIONS(136), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(134), 3,
      aux_sym__propertyName_token2,
      aux_sym__propertyName_token3,
      aux_sym__propertyName_token4,
  [439] = 4,
    ACTIONS(138), 1,
      aux_sym__propertyName_token1,
    STATE(18), 1,
      aux_sym__propertyName_repeat1,
    ACTIONS(143), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(140), 3,
      aux_sym__propertyName_token2,
      aux_sym__propertyName_token3,
      aux_sym__propertyName_token4,
  [455] = 2,
    ACTIONS(147), 1,
      aux_sym__stringNL_token1,
    ACTIONS(145), 6,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND2,
  [467] = 6,
    ACTIONS(113), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(119), 1,
      sym___attribute_start,
    ACTIONS(149), 1,
      aux_sym_macroName_token1,
    STATE(33), 1,
      sym__attribute_empty,
    STATE(51), 1,
      sym_macroName,
    STATE(15), 2,
      sym_attribute,
      aux_sym_macroName_repeat1,
  [487] = 4,
    ACTIONS(143), 1,
      anon_sym_RBRACE,
    STATE(21), 1,
      aux_sym__propertyName_repeat1,
    ACTIONS(138), 2,
      aux_sym__propertyName_token1,
      aux_sym__attribute_token2,
    ACTIONS(151), 3,
      aux_sym__propertyName_token2,
      aux_sym__propertyName_token3,
      aux_sym__propertyName_token4,
  [503] = 2,
    ACTIONS(156), 1,
      aux_sym__stringNL_token1,
    ACTIONS(154), 6,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND2,
  [515] = 2,
    ACTIONS(160), 1,
      aux_sym__stringNL_token1,
    ACTIONS(158), 6,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND2,
  [527] = 2,
    ACTIONS(164), 1,
      aux_sym__stringNL_token1,
    ACTIONS(162), 6,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND2,
  [539] = 2,
    ACTIONS(168), 1,
      aux_sym__stringNL_token1,
    ACTIONS(166), 6,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND2,
  [551] = 2,
    ACTIONS(172), 1,
      aux_sym__stringNL_token1,
    ACTIONS(170), 6,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND2,
  [563] = 2,
    ACTIONS(176), 1,
      aux_sym__stringNL_token1,
    ACTIONS(174), 6,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
      anon_sym_PERCENT_LBRACE,
      anon_sym_POUND2,
  [575] = 5,
    ACTIONS(136), 1,
      anon_sym_RBRACE,
    ACTIONS(178), 1,
      aux_sym__propertyName_token1,
    ACTIONS(182), 1,
      aux_sym__attribute_token2,
    STATE(21), 1,
      aux_sym__propertyName_repeat1,
    ACTIONS(180), 3,
      aux_sym__propertyName_token2,
      aux_sym__propertyName_token3,
      aux_sym__propertyName_token4,
  [593] = 5,
    ACTIONS(184), 1,
      anon_sym_,
    ACTIONS(188), 1,
      anon_sym_AT,
    ACTIONS(190), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(30), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    ACTIONS(186), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [610] = 4,
    ACTIONS(192), 1,
      anon_sym_,
    ACTIONS(196), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(30), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    ACTIONS(194), 3,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      anon_sym_AT,
  [625] = 2,
    ACTIONS(176), 1,
      aux_sym_macroName_token1,
    ACTIONS(174), 4,
      sym__EOF,
      sym___attribute_start,
      anon_sym_AT_LBRACE,
      aux_sym__macroNL_token1,
  [635] = 5,
    ACTIONS(29), 1,
      aux_sym__attribute_token2,
    ACTIONS(199), 1,
      anon_sym_RBRACE,
    ACTIONS(201), 1,
      anon_sym_max,
    ACTIONS(203), 1,
      aux_sym__attribute_token1,
    STATE(46), 1,
      aux_sym__attribute_repeat1,
  [651] = 2,
    ACTIONS(156), 1,
      aux_sym_macroName_token1,
    ACTIONS(154), 4,
      sym__EOF,
      sym___attribute_start,
      anon_sym_AT_LBRACE,
      aux_sym__macroNL_token1,
  [661] = 2,
    ACTIONS(164), 1,
      aux_sym_macroName_token1,
    ACTIONS(162), 4,
      sym__EOF,
      sym___attribute_start,
      anon_sym_AT_LBRACE,
      aux_sym__macroNL_token1,
  [671] = 4,
    ACTIONS(205), 1,
      anon_sym_AT,
    ACTIONS(207), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(38), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    STATE(43), 1,
      sym__macroNameInsideAttributeName,
  [684] = 4,
    ACTIONS(192), 1,
      anon_sym_,
    ACTIONS(194), 1,
      anon_sym_AT,
    ACTIONS(209), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(36), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
  [697] = 4,
    ACTIONS(205), 1,
      anon_sym_AT,
    ACTIONS(212), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(29), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    STATE(43), 1,
      sym__macroNameInsideAttributeName,
  [710] = 4,
    ACTIONS(184), 1,
      anon_sym_,
    ACTIONS(188), 1,
      anon_sym_AT,
    ACTIONS(214), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(36), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
  [723] = 3,
    ACTIONS(216), 1,
      anon_sym_RBRACE,
    ACTIONS(218), 1,
      aux_sym__attribute_token2,
    STATE(47), 1,
      aux_sym__attribute_repeat1,
  [733] = 1,
    ACTIONS(220), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [739] = 3,
    ACTIONS(218), 1,
      aux_sym__attribute_token2,
    ACTIONS(222), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [749] = 2,
    ACTIONS(224), 1,
      anon_sym_,
    ACTIONS(226), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [757] = 1,
    ACTIONS(228), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [763] = 3,
    ACTIONS(230), 1,
      anon_sym_RBRACE,
    ACTIONS(232), 1,
      aux_sym__attribute_token2,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [773] = 1,
    ACTIONS(184), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [779] = 3,
    ACTIONS(218), 1,
      aux_sym__attribute_token2,
    ACTIONS(235), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [789] = 3,
    ACTIONS(218), 1,
      aux_sym__attribute_token2,
    ACTIONS(237), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [799] = 3,
    ACTIONS(218), 1,
      aux_sym__attribute_token2,
    ACTIONS(239), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [809] = 3,
    ACTIONS(218), 1,
      aux_sym__attribute_token2,
    ACTIONS(241), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [819] = 3,
    ACTIONS(218), 1,
      aux_sym__attribute_token2,
    ACTIONS(243), 1,
      anon_sym_RBRACE,
    STATE(44), 1,
      aux_sym__attribute_repeat1,
  [829] = 1,
    ACTIONS(245), 2,
      sym__EOF,
      aux_sym__macroNL_token1,
  [834] = 1,
    ACTIONS(247), 2,
      anon_sym_RBRACE,
      aux_sym__attribute_token2,
  [839] = 2,
    ACTIONS(249), 1,
      anon_sym_RBRACE,
    ACTIONS(251), 1,
      anon_sym_PIPE,
  [846] = 1,
    ACTIONS(253), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [851] = 2,
    ACTIONS(255), 1,
      anon_sym_RBRACE,
    ACTIONS(257), 1,
      anon_sym_PIPE,
  [858] = 1,
    ACTIONS(259), 2,
      sym__EOF,
      aux_sym__macroNL_token1,
  [863] = 1,
    ACTIONS(136), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [868] = 2,
    ACTIONS(261), 1,
      anon_sym_POUND2,
    STATE(68), 1,
      sym__macroInsideAttributeName,
  [875] = 1,
    ACTIONS(73), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [880] = 1,
    ACTIONS(247), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [885] = 1,
    ACTIONS(263), 2,
      anon_sym_RBRACE,
      aux_sym__attribute_token2,
  [890] = 2,
    ACTIONS(265), 1,
      anon_sym_RBRACE,
    ACTIONS(267), 1,
      anon_sym_PIPE,
  [897] = 1,
    ACTIONS(136), 2,
      anon_sym_RBRACE,
      aux_sym__attribute_token2,
  [902] = 1,
    ACTIONS(269), 1,
      anon_sym_RBRACE,
  [906] = 1,
    ACTIONS(271), 1,
      anon_sym_PIPE,
  [910] = 1,
    ACTIONS(224), 1,
      anon_sym_,
  [914] = 1,
    ACTIONS(273), 1,
      anon_sym_PIPE,
  [918] = 1,
    ACTIONS(275), 1,
      anon_sym_,
  [922] = 1,
    ACTIONS(277), 1,
      anon_sym_RBRACE,
  [926] = 1,
    ACTIONS(279), 1,
      ts_builtin_sym_end,
  [930] = 1,
    ACTIONS(281), 1,
      anon_sym_RBRACE,
  [934] = 1,
    ACTIONS(283), 1,
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
  [SMALL_STATE(14)] = 366,
  [SMALL_STATE(15)] = 381,
  [SMALL_STATE(16)] = 402,
  [SMALL_STATE(17)] = 423,
  [SMALL_STATE(18)] = 439,
  [SMALL_STATE(19)] = 455,
  [SMALL_STATE(20)] = 467,
  [SMALL_STATE(21)] = 487,
  [SMALL_STATE(22)] = 503,
  [SMALL_STATE(23)] = 515,
  [SMALL_STATE(24)] = 527,
  [SMALL_STATE(25)] = 539,
  [SMALL_STATE(26)] = 551,
  [SMALL_STATE(27)] = 563,
  [SMALL_STATE(28)] = 575,
  [SMALL_STATE(29)] = 593,
  [SMALL_STATE(30)] = 610,
  [SMALL_STATE(31)] = 625,
  [SMALL_STATE(32)] = 635,
  [SMALL_STATE(33)] = 651,
  [SMALL_STATE(34)] = 661,
  [SMALL_STATE(35)] = 671,
  [SMALL_STATE(36)] = 684,
  [SMALL_STATE(37)] = 697,
  [SMALL_STATE(38)] = 710,
  [SMALL_STATE(39)] = 723,
  [SMALL_STATE(40)] = 733,
  [SMALL_STATE(41)] = 739,
  [SMALL_STATE(42)] = 749,
  [SMALL_STATE(43)] = 757,
  [SMALL_STATE(44)] = 763,
  [SMALL_STATE(45)] = 773,
  [SMALL_STATE(46)] = 779,
  [SMALL_STATE(47)] = 789,
  [SMALL_STATE(48)] = 799,
  [SMALL_STATE(49)] = 809,
  [SMALL_STATE(50)] = 819,
  [SMALL_STATE(51)] = 829,
  [SMALL_STATE(52)] = 834,
  [SMALL_STATE(53)] = 839,
  [SMALL_STATE(54)] = 846,
  [SMALL_STATE(55)] = 851,
  [SMALL_STATE(56)] = 858,
  [SMALL_STATE(57)] = 863,
  [SMALL_STATE(58)] = 868,
  [SMALL_STATE(59)] = 875,
  [SMALL_STATE(60)] = 880,
  [SMALL_STATE(61)] = 885,
  [SMALL_STATE(62)] = 890,
  [SMALL_STATE(63)] = 897,
  [SMALL_STATE(64)] = 902,
  [SMALL_STATE(65)] = 906,
  [SMALL_STATE(66)] = 910,
  [SMALL_STATE(67)] = 914,
  [SMALL_STATE(68)] = 918,
  [SMALL_STATE(69)] = 922,
  [SMALL_STATE(70)] = 926,
  [SMALL_STATE(71)] = 930,
  [SMALL_STATE(72)] = 934,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_roll20_script, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
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
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(20),
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
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stringNL_repeat1, 2),
  [110] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__stringNL_repeat1, 2), SHIFT_REPEAT(14),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macroName, 1),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [121] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_macroName_repeat1, 2), SHIFT_REPEAT(33),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_macroName_repeat1, 2),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_macroName_repeat1, 2), SHIFT_REPEAT(16),
  [129] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_macroName_repeat1, 2), SHIFT_REPEAT(3),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyName, 1),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyName_repeat1, 2),
  [140] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__propertyName_repeat1, 2), SHIFT_REPEAT(18),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyName_repeat1, 2),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 1),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 1),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [151] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__propertyName_repeat1, 2), SHIFT_REPEAT(21),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [156] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 1),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability_empty, 2),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__ability_empty, 2),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_empty, 2),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_empty, 2),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroNL, 2),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macroNL, 2),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 3),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 3),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__propertyName, 1),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroNameInsideAttributeName, 1),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macroNameInsideAttributeName, 1),
  [188] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [190] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2),
  [196] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2), SHIFT_REPEAT(30),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 4, .production_id = 12),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [209] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2), SHIFT_REPEAT(36),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 3, .production_id = 11),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroNameInsideAttributeName, 2),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 1, .production_id = 3),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 2, .production_id = 7),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroInsideAttributeName, 2),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 2),
  [232] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 2), SHIFT_REPEAT(61),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 5, .production_id = 14),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 4, .production_id = 13),
  [239] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 3, .production_id = 10),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 1, .production_id = 3),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 3, .production_id = 10),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_macro, 2),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyName, 2),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 3, .production_id = 9),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 2),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 1, .production_id = 4),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selector, 1, .production_id = 1),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 1),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 1, .production_id = 2),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selectorWithMacros, 1, .production_id = 1),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 5, .production_id = 9),
  [279] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
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
