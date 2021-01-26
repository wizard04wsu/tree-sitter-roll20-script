#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 55
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 44
#define ALIAS_COUNT 5
#define TOKEN_COUNT 25
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5

enum {
  aux_sym__stringNL_token1 = 1,
  anon_sym_selected = 2,
  anon_sym_target = 3,
  sym__propertyName = 4,
  aux_sym__propertyNameWithMacros_token1 = 5,
  aux_sym__propertyNameWithMacros_token2 = 6,
  aux_sym__propertyNameWithMacros_token3 = 7,
  aux_sym__propertyNameWithMacros_token4 = 8,
  anon_sym_ = 9,
  anon_sym_POUND = 10,
  aux_sym__propertyNameWithMacros_token5 = 11,
  anon_sym_RBRACE = 12,
  anon_sym_AT_LBRACE = 13,
  anon_sym_PIPE = 14,
  anon_sym_max = 15,
  aux_sym__attribute_token1 = 16,
  aux_sym__attribute_token2 = 17,
  anon_sym_PERCENT_LBRACE = 18,
  anon_sym_POUND2 = 19,
  anon_sym_AT = 20,
  aux_sym__macroNameInsideAttributeName_token1 = 21,
  anon_sym_2 = 22,
  sym___attribute_start = 23,
  sym___ability_start = 24,
  sym_roll20_script = 25,
  sym__stringNL = 26,
  sym__tokenSelector = 27,
  sym__propertyNameWithMacros = 28,
  sym__selector = 29,
  sym__selectorWithMacros = 30,
  sym_attribute = 31,
  sym__attribute_empty = 32,
  sym__attribute = 33,
  sym_ability = 34,
  sym__ability_empty = 35,
  sym__ability = 36,
  sym__macroInsideAttributeName = 37,
  sym__macroNameInsideAttributeName = 38,
  aux_sym_roll20_script_repeat1 = 39,
  aux_sym__stringNL_repeat1 = 40,
  aux_sym__propertyNameWithMacros_repeat1 = 41,
  aux_sym__attribute_repeat1 = 42,
  aux_sym__macroNameInsideAttributeName_repeat1 = 43,
  alias_sym_abilityName = 44,
  alias_sym_attributeName = 45,
  alias_sym_characterName = 46,
  alias_sym_invalid = 47,
  alias_sym_macro = 48,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym__stringNL_token1] = "_stringNL_token1",
  [anon_sym_selected] = "token",
  [anon_sym_target] = "token",
  [sym__propertyName] = "_propertyName",
  [aux_sym__propertyNameWithMacros_token1] = "_propertyNameWithMacros_token1",
  [aux_sym__propertyNameWithMacros_token2] = "_propertyNameWithMacros_token2",
  [aux_sym__propertyNameWithMacros_token3] = "_propertyNameWithMacros_token3",
  [aux_sym__propertyNameWithMacros_token4] = "_propertyNameWithMacros_token4",
  [anon_sym_] = " ",
  [anon_sym_POUND] = "# ",
  [aux_sym__propertyNameWithMacros_token5] = "invalid",
  [anon_sym_RBRACE] = "}",
  [anon_sym_AT_LBRACE] = "invalid",
  [anon_sym_PIPE] = "|",
  [anon_sym_max] = "keyword",
  [aux_sym__attribute_token1] = "invalid",
  [aux_sym__attribute_token2] = "_attribute_token2",
  [anon_sym_PERCENT_LBRACE] = "invalid",
  [anon_sym_POUND2] = "#",
  [anon_sym_AT] = "@",
  [aux_sym__macroNameInsideAttributeName_token1] = "_macroNameInsideAttributeName_token1",
  [anon_sym_2] = "",
  [sym___attribute_start] = "__attribute_start",
  [sym___ability_start] = "__ability_start",
  [sym_roll20_script] = "roll20_script",
  [sym__stringNL] = "_stringNL",
  [sym__tokenSelector] = "_tokenSelector",
  [sym__propertyNameWithMacros] = "_propertyNameWithMacros",
  [sym__selector] = "_selector",
  [sym__selectorWithMacros] = "_selectorWithMacros",
  [sym_attribute] = "attribute",
  [sym__attribute_empty] = "invalid",
  [sym__attribute] = "_attribute",
  [sym_ability] = "ability",
  [sym__ability_empty] = "invalid",
  [sym__ability] = "_ability",
  [sym__macroInsideAttributeName] = "_macroInsideAttributeName",
  [sym__macroNameInsideAttributeName] = "macroName",
  [aux_sym_roll20_script_repeat1] = "roll20_script_repeat1",
  [aux_sym__stringNL_repeat1] = "_stringNL_repeat1",
  [aux_sym__propertyNameWithMacros_repeat1] = "_propertyNameWithMacros_repeat1",
  [aux_sym__attribute_repeat1] = "_attribute_repeat1",
  [aux_sym__macroNameInsideAttributeName_repeat1] = "_macroNameInsideAttributeName_repeat1",
  [alias_sym_abilityName] = "abilityName",
  [alias_sym_attributeName] = "attributeName",
  [alias_sym_characterName] = "characterName",
  [alias_sym_invalid] = "invalid",
  [alias_sym_macro] = "macro",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym__stringNL_token1] = aux_sym__stringNL_token1,
  [anon_sym_selected] = anon_sym_selected,
  [anon_sym_target] = anon_sym_selected,
  [sym__propertyName] = sym__propertyName,
  [aux_sym__propertyNameWithMacros_token1] = aux_sym__propertyNameWithMacros_token1,
  [aux_sym__propertyNameWithMacros_token2] = aux_sym__propertyNameWithMacros_token2,
  [aux_sym__propertyNameWithMacros_token3] = aux_sym__propertyNameWithMacros_token3,
  [aux_sym__propertyNameWithMacros_token4] = aux_sym__propertyNameWithMacros_token4,
  [anon_sym_] = anon_sym_,
  [anon_sym_POUND] = anon_sym_POUND,
  [aux_sym__propertyNameWithMacros_token5] = aux_sym__propertyNameWithMacros_token5,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_AT_LBRACE] = aux_sym__propertyNameWithMacros_token5,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_max] = anon_sym_max,
  [aux_sym__attribute_token1] = aux_sym__propertyNameWithMacros_token5,
  [aux_sym__attribute_token2] = aux_sym__attribute_token2,
  [anon_sym_PERCENT_LBRACE] = aux_sym__propertyNameWithMacros_token5,
  [anon_sym_POUND2] = anon_sym_POUND2,
  [anon_sym_AT] = anon_sym_AT,
  [aux_sym__macroNameInsideAttributeName_token1] = aux_sym__macroNameInsideAttributeName_token1,
  [anon_sym_2] = anon_sym_2,
  [sym___attribute_start] = sym___attribute_start,
  [sym___ability_start] = sym___ability_start,
  [sym_roll20_script] = sym_roll20_script,
  [sym__stringNL] = sym__stringNL,
  [sym__tokenSelector] = sym__tokenSelector,
  [sym__propertyNameWithMacros] = sym__propertyNameWithMacros,
  [sym__selector] = sym__selector,
  [sym__selectorWithMacros] = sym__selectorWithMacros,
  [sym_attribute] = sym_attribute,
  [sym__attribute_empty] = aux_sym__propertyNameWithMacros_token5,
  [sym__attribute] = sym__attribute,
  [sym_ability] = sym_ability,
  [sym__ability_empty] = aux_sym__propertyNameWithMacros_token5,
  [sym__ability] = sym__ability,
  [sym__macroInsideAttributeName] = sym__macroInsideAttributeName,
  [sym__macroNameInsideAttributeName] = sym__macroNameInsideAttributeName,
  [aux_sym_roll20_script_repeat1] = aux_sym_roll20_script_repeat1,
  [aux_sym__stringNL_repeat1] = aux_sym__stringNL_repeat1,
  [aux_sym__propertyNameWithMacros_repeat1] = aux_sym__propertyNameWithMacros_repeat1,
  [aux_sym__attribute_repeat1] = aux_sym__attribute_repeat1,
  [aux_sym__macroNameInsideAttributeName_repeat1] = aux_sym__macroNameInsideAttributeName_repeat1,
  [alias_sym_abilityName] = alias_sym_abilityName,
  [alias_sym_attributeName] = alias_sym_attributeName,
  [alias_sym_characterName] = alias_sym_characterName,
  [alias_sym_invalid] = alias_sym_invalid,
  [alias_sym_macro] = alias_sym_macro,
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
  [sym__propertyName] = {
    .visible = false,
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
  [aux_sym__propertyNameWithMacros_token4] = {
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
  [aux_sym__propertyNameWithMacros_token5] = {
    .visible = true,
    .named = true,
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
  [anon_sym_POUND2] = {
    .visible = true,
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
  [aux_sym__propertyNameWithMacros_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__attribute_repeat1] = {
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
  [alias_sym_macro] = {
    .visible = true,
    .named = true,
  },
};

static TSSymbol ts_alias_sequences[14][MAX_ALIAS_SEQUENCE_LENGTH] = {
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
    [1] = alias_sym_invalid,
  },
  [5] = {
    [0] = alias_sym_macro,
  },
  [6] = {
    [1] = anon_sym_2,
  },
  [7] = {
    [0] = alias_sym_abilityName,
  },
  [8] = {
    [1] = alias_sym_macro,
  },
  [9] = {
    [2] = alias_sym_attributeName,
  },
  [10] = {
    [2] = alias_sym_invalid,
  },
  [11] = {
    [2] = alias_sym_attributeName,
    [3] = alias_sym_invalid,
  },
  [12] = {
    [2] = alias_sym_abilityName,
  },
  [13] = {
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
      if (eof) ADVANCE(16);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(53);
      if (lookahead == '%') ADVANCE(11);
      if (lookahead == '|') ADVANCE(59);
      if (lookahead == '}') ADVANCE(56);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(53);
      if (lookahead == '@') ADVANCE(67);
      if (lookahead == '|') ADVANCE(60);
      if (lookahead == '}') ADVANCE(57);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(69);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(53);
      if (lookahead == '@') ADVANCE(67);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(69);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(66);
      if (lookahead == 's') ADVANCE(42);
      if (lookahead == 't') ADVANCE(39);
      if (lookahead == '}') ADVANCE(56);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(38);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(63);
      if (lookahead != 0) ADVANCE(51);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(66);
      if (lookahead == '|') ADVANCE(59);
      if (lookahead == '}') ADVANCE(56);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(38);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(51);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(66);
      if (lookahead == '}') ADVANCE(56);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(38);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(63);
      if (lookahead != 0) ADVANCE(51);
      END_STATE();
    case 7:
      if (lookahead == '@') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '{') ADVANCE(68);
      END_STATE();
    case 8:
      if (lookahead == 'm') ADVANCE(64);
      if (lookahead == '}') ADVANCE(56);
      if (lookahead != 0) ADVANCE(63);
      END_STATE();
    case 9:
      if (lookahead == 's') ADVANCE(27);
      if (lookahead == 't') ADVANCE(24);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 10:
      if (lookahead == 'x') ADVANCE(61);
      END_STATE();
    case 11:
      if (lookahead == '{') ADVANCE(65);
      END_STATE();
    case 12:
      if (lookahead == '}') ADVANCE(56);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(63);
      if (lookahead != 0) ADVANCE(36);
      END_STATE();
    case 13:
      if (lookahead == '}') ADVANCE(56);
      if (lookahead != 0) ADVANCE(63);
      END_STATE();
    case 14:
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(52);
      END_STATE();
    case 15:
      if (eof) ADVANCE(16);
      if (lookahead != 0 &&
          lookahead != '\r' &&
          lookahead != '@') ADVANCE(17);
      if (lookahead == '\r') ADVANCE(18);
      if (lookahead == '@') ADVANCE(19);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '\n') ADVANCE(17);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '{') ADVANCE(58);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 'a') ADVANCE(33);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 'c') ADVANCE(35);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 'd') ADVANCE(20);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 'e') ADVANCE(32);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 'e') ADVANCE(25);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 'e') ADVANCE(26);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 'e') ADVANCE(34);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 'g') ADVANCE(30);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 'l') ADVANCE(28);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 'r') ADVANCE(31);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 't') ADVANCE(22);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == 't') ADVANCE(29);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(37);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym__propertyName);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(36);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token1);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(52);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'a') ADVANCE(48);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'c') ADVANCE(50);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'd') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(47);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(40);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(41);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(49);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'g') ADVANCE(45);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'l') ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'r') ADVANCE(46);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 't') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 't') ADVANCE(44);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token3);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token5);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(69);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(69);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_max);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym__attribute_token1);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym__attribute_token2);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym__attribute_token2);
      if (lookahead == 'a') ADVANCE(10);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_PERCENT_LBRACE);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_POUND2);
      if (lookahead == ' ') ADVANCE(54);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead == '@') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '{') ADVANCE(68);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym__macroNameInsideAttributeName_token1);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym__macroNameInsideAttributeName_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(69);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 15, .external_lex_state = 1},
  [2] = {.lex_state = 4},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 15, .external_lex_state = 1},
  [5] = {.lex_state = 15, .external_lex_state = 1},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 5},
  [8] = {.lex_state = 5},
  [9] = {.lex_state = 5},
  [10] = {.lex_state = 9},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 15, .external_lex_state = 1},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 15, .external_lex_state = 1},
  [15] = {.lex_state = 15, .external_lex_state = 1},
  [16] = {.lex_state = 8},
  [17] = {.lex_state = 15, .external_lex_state = 1},
  [18] = {.lex_state = 15, .external_lex_state = 1},
  [19] = {.lex_state = 15, .external_lex_state = 1},
  [20] = {.lex_state = 12},
  [21] = {.lex_state = 3},
  [22] = {.lex_state = 3},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 13},
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 13},
  [30] = {.lex_state = 13},
  [31] = {.lex_state = 13},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 13},
  [34] = {.lex_state = 13},
  [35] = {.lex_state = 5},
  [36] = {.lex_state = 5},
  [37] = {.lex_state = 5},
  [38] = {.lex_state = 5},
  [39] = {.lex_state = 13},
  [40] = {.lex_state = 4},
  [41] = {.lex_state = 5},
  [42] = {.lex_state = 5},
  [43] = {.lex_state = 4},
  [44] = {.lex_state = 2},
  [45] = {.lex_state = 4},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 5},
  [48] = {.lex_state = 1},
  [49] = {.lex_state = 4},
  [50] = {.lex_state = 0, .external_lex_state = 2},
  [51] = {.lex_state = 4},
  [52] = {.lex_state = 4},
  [53] = {.lex_state = 0, .external_lex_state = 2},
  [54] = {.lex_state = 0},
};

enum {
  ts_external_token___attribute_start = 0,
  ts_external_token___ability_start = 1,
};

static TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token___attribute_start] = sym___attribute_start,
  [ts_external_token___ability_start] = sym___ability_start,
};

static bool ts_external_scanner_states[3][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token___attribute_start] = true,
    [ts_external_token___ability_start] = true,
  },
  [2] = {
    [ts_external_token___ability_start] = true,
  },
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_2] = ACTIONS(1),
    [sym___attribute_start] = ACTIONS(1),
    [sym___ability_start] = ACTIONS(1),
  },
  [1] = {
    [sym_roll20_script] = STATE(54),
    [sym__stringNL] = STATE(5),
    [sym_attribute] = STATE(5),
    [sym__attribute_empty] = STATE(19),
    [sym_ability] = STATE(5),
    [sym__ability_empty] = STATE(53),
    [aux_sym_roll20_script_repeat1] = STATE(5),
    [aux_sym__stringNL_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym__stringNL_token1] = ACTIONS(5),
    [anon_sym_AT_LBRACE] = ACTIONS(7),
    [sym___attribute_start] = ACTIONS(9),
    [sym___ability_start] = ACTIONS(11),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 14,
    ACTIONS(15), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(17), 1,
      aux_sym__propertyNameWithMacros_token2,
    ACTIONS(21), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(23), 1,
      anon_sym_RBRACE,
    ACTIONS(25), 1,
      aux_sym__attribute_token2,
    ACTIONS(27), 1,
      anon_sym_POUND2,
    STATE(6), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(33), 1,
      aux_sym__attribute_repeat1,
    STATE(38), 1,
      sym__propertyNameWithMacros,
    STATE(44), 1,
      sym__macroInsideAttributeName,
    STATE(45), 1,
      sym__attribute,
    ACTIONS(13), 2,
      anon_sym_selected,
      anon_sym_target,
    STATE(47), 2,
      sym__tokenSelector,
      sym__selectorWithMacros,
    ACTIONS(19), 3,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [47] = 10,
    ACTIONS(15), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(21), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(25), 1,
      aux_sym__attribute_token2,
    ACTIONS(27), 1,
      anon_sym_POUND2,
    ACTIONS(29), 1,
      anon_sym_RBRACE,
    STATE(6), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(31), 1,
      aux_sym__attribute_repeat1,
    STATE(36), 1,
      sym__propertyNameWithMacros,
    STATE(44), 1,
      sym__macroInsideAttributeName,
    ACTIONS(19), 4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [81] = 9,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      aux_sym__stringNL_token1,
    ACTIONS(36), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(39), 1,
      sym___attribute_start,
    ACTIONS(42), 1,
      sym___ability_start,
    STATE(12), 1,
      aux_sym__stringNL_repeat1,
    STATE(19), 1,
      sym__attribute_empty,
    STATE(53), 1,
      sym__ability_empty,
    STATE(4), 4,
      sym__stringNL,
      sym_attribute,
      sym_ability,
      aux_sym_roll20_script_repeat1,
  [112] = 9,
    ACTIONS(5), 1,
      aux_sym__stringNL_token1,
    ACTIONS(7), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(9), 1,
      sym___attribute_start,
    ACTIONS(11), 1,
      sym___ability_start,
    ACTIONS(45), 1,
      ts_builtin_sym_end,
    STATE(12), 1,
      aux_sym__stringNL_repeat1,
    STATE(19), 1,
      sym__attribute_empty,
    STATE(53), 1,
      sym__ability_empty,
    STATE(4), 4,
      sym__stringNL,
      sym_attribute,
      sym_ability,
      aux_sym_roll20_script_repeat1,
  [143] = 7,
    ACTIONS(21), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(47), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(53), 1,
      anon_sym_POUND2,
    STATE(7), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(32), 1,
      sym__macroInsideAttributeName,
    ACTIONS(51), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(49), 4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [169] = 7,
    ACTIONS(55), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(60), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(65), 1,
      anon_sym_POUND2,
    STATE(7), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(44), 1,
      sym__macroInsideAttributeName,
    ACTIONS(63), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(57), 4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [195] = 2,
    ACTIONS(68), 3,
      aux_sym__propertyNameWithMacros_token1,
      aux_sym__propertyNameWithMacros_token4,
      anon_sym_POUND2,
    ACTIONS(70), 6,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [209] = 2,
    ACTIONS(72), 3,
      aux_sym__propertyNameWithMacros_token1,
      aux_sym__propertyNameWithMacros_token4,
      anon_sym_POUND2,
    ACTIONS(74), 6,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [223] = 6,
    ACTIONS(25), 1,
      aux_sym__attribute_token2,
    ACTIONS(78), 1,
      sym__propertyName,
    STATE(25), 1,
      aux_sym__attribute_repeat1,
    STATE(43), 1,
      sym__ability,
    ACTIONS(76), 2,
      anon_sym_selected,
      anon_sym_target,
    STATE(42), 2,
      sym__tokenSelector,
      sym__selector,
  [244] = 5,
    ACTIONS(80), 1,
      anon_sym_,
    ACTIONS(84), 1,
      anon_sym_AT,
    ACTIONS(86), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(13), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    ACTIONS(82), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [261] = 3,
    ACTIONS(90), 1,
      aux_sym__stringNL_token1,
    STATE(14), 1,
      aux_sym__stringNL_repeat1,
    ACTIONS(88), 4,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [274] = 4,
    ACTIONS(92), 1,
      anon_sym_,
    ACTIONS(96), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(13), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    ACTIONS(94), 3,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      anon_sym_AT,
  [289] = 3,
    ACTIONS(101), 1,
      aux_sym__stringNL_token1,
    STATE(14), 1,
      aux_sym__stringNL_repeat1,
    ACTIONS(99), 4,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [302] = 2,
    ACTIONS(106), 1,
      aux_sym__stringNL_token1,
    ACTIONS(104), 4,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [312] = 5,
    ACTIONS(25), 1,
      aux_sym__attribute_token2,
    ACTIONS(108), 1,
      anon_sym_RBRACE,
    ACTIONS(110), 1,
      anon_sym_max,
    ACTIONS(112), 1,
      aux_sym__attribute_token1,
    STATE(29), 1,
      aux_sym__attribute_repeat1,
  [328] = 2,
    ACTIONS(116), 1,
      aux_sym__stringNL_token1,
    ACTIONS(114), 4,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [338] = 2,
    ACTIONS(120), 1,
      aux_sym__stringNL_token1,
    ACTIONS(118), 4,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [348] = 2,
    ACTIONS(124), 1,
      aux_sym__stringNL_token1,
    ACTIONS(122), 4,
      sym___attribute_start,
      sym___ability_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [358] = 4,
    ACTIONS(25), 1,
      aux_sym__attribute_token2,
    ACTIONS(126), 1,
      sym__propertyName,
    ACTIONS(128), 1,
      anon_sym_RBRACE,
    STATE(30), 1,
      aux_sym__attribute_repeat1,
  [371] = 4,
    ACTIONS(130), 1,
      anon_sym_AT,
    ACTIONS(132), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(24), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    STATE(28), 1,
      sym__macroNameInsideAttributeName,
  [384] = 4,
    ACTIONS(92), 1,
      anon_sym_,
    ACTIONS(94), 1,
      anon_sym_AT,
    ACTIONS(134), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(22), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
  [397] = 4,
    ACTIONS(130), 1,
      anon_sym_AT,
    ACTIONS(137), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(11), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    STATE(28), 1,
      sym__macroNameInsideAttributeName,
  [410] = 4,
    ACTIONS(80), 1,
      anon_sym_,
    ACTIONS(84), 1,
      anon_sym_AT,
    ACTIONS(139), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(22), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
  [423] = 3,
    ACTIONS(141), 1,
      anon_sym_RBRACE,
    ACTIONS(143), 1,
      aux_sym__attribute_token2,
    STATE(34), 1,
      aux_sym__attribute_repeat1,
  [433] = 1,
    ACTIONS(145), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [439] = 1,
    ACTIONS(80), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [445] = 1,
    ACTIONS(147), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [451] = 3,
    ACTIONS(143), 1,
      aux_sym__attribute_token2,
    ACTIONS(149), 1,
      anon_sym_RBRACE,
    STATE(34), 1,
      aux_sym__attribute_repeat1,
  [461] = 3,
    ACTIONS(143), 1,
      aux_sym__attribute_token2,
    ACTIONS(151), 1,
      anon_sym_RBRACE,
    STATE(34), 1,
      aux_sym__attribute_repeat1,
  [471] = 3,
    ACTIONS(143), 1,
      aux_sym__attribute_token2,
    ACTIONS(153), 1,
      anon_sym_RBRACE,
    STATE(34), 1,
      aux_sym__attribute_repeat1,
  [481] = 2,
    ACTIONS(155), 1,
      anon_sym_,
    ACTIONS(157), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [489] = 3,
    ACTIONS(143), 1,
      aux_sym__attribute_token2,
    ACTIONS(159), 1,
      anon_sym_RBRACE,
    STATE(34), 1,
      aux_sym__attribute_repeat1,
  [499] = 3,
    ACTIONS(161), 1,
      anon_sym_RBRACE,
    ACTIONS(163), 1,
      aux_sym__attribute_token2,
    STATE(34), 1,
      aux_sym__attribute_repeat1,
  [509] = 2,
    ACTIONS(166), 1,
      anon_sym_RBRACE,
    ACTIONS(168), 1,
      anon_sym_PIPE,
  [516] = 2,
    ACTIONS(170), 1,
      anon_sym_RBRACE,
    ACTIONS(172), 1,
      anon_sym_PIPE,
  [523] = 1,
    ACTIONS(174), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [528] = 2,
    ACTIONS(176), 1,
      anon_sym_RBRACE,
    ACTIONS(178), 1,
      anon_sym_PIPE,
  [535] = 1,
    ACTIONS(180), 2,
      anon_sym_RBRACE,
      aux_sym__attribute_token2,
  [540] = 2,
    ACTIONS(182), 1,
      anon_sym_POUND2,
    STATE(46), 1,
      sym__macroInsideAttributeName,
  [547] = 1,
    ACTIONS(51), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [552] = 1,
    ACTIONS(184), 1,
      anon_sym_PIPE,
  [556] = 1,
    ACTIONS(186), 1,
      anon_sym_RBRACE,
  [560] = 1,
    ACTIONS(155), 1,
      anon_sym_,
  [564] = 1,
    ACTIONS(188), 1,
      anon_sym_RBRACE,
  [568] = 1,
    ACTIONS(190), 1,
      anon_sym_,
  [572] = 1,
    ACTIONS(192), 1,
      anon_sym_PIPE,
  [576] = 1,
    ACTIONS(194), 1,
      anon_sym_PERCENT_LBRACE,
  [580] = 1,
    ACTIONS(196), 1,
      anon_sym_RBRACE,
  [584] = 1,
    ACTIONS(198), 1,
      sym___ability_start,
  [588] = 1,
    ACTIONS(200), 1,
      anon_sym_RBRACE,
  [592] = 1,
    ACTIONS(202), 1,
      anon_sym_RBRACE,
  [596] = 1,
    ACTIONS(204), 1,
      sym___ability_start,
  [600] = 1,
    ACTIONS(206), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 47,
  [SMALL_STATE(4)] = 81,
  [SMALL_STATE(5)] = 112,
  [SMALL_STATE(6)] = 143,
  [SMALL_STATE(7)] = 169,
  [SMALL_STATE(8)] = 195,
  [SMALL_STATE(9)] = 209,
  [SMALL_STATE(10)] = 223,
  [SMALL_STATE(11)] = 244,
  [SMALL_STATE(12)] = 261,
  [SMALL_STATE(13)] = 274,
  [SMALL_STATE(14)] = 289,
  [SMALL_STATE(15)] = 302,
  [SMALL_STATE(16)] = 312,
  [SMALL_STATE(17)] = 328,
  [SMALL_STATE(18)] = 338,
  [SMALL_STATE(19)] = 348,
  [SMALL_STATE(20)] = 358,
  [SMALL_STATE(21)] = 371,
  [SMALL_STATE(22)] = 384,
  [SMALL_STATE(23)] = 397,
  [SMALL_STATE(24)] = 410,
  [SMALL_STATE(25)] = 423,
  [SMALL_STATE(26)] = 433,
  [SMALL_STATE(27)] = 439,
  [SMALL_STATE(28)] = 445,
  [SMALL_STATE(29)] = 451,
  [SMALL_STATE(30)] = 461,
  [SMALL_STATE(31)] = 471,
  [SMALL_STATE(32)] = 481,
  [SMALL_STATE(33)] = 489,
  [SMALL_STATE(34)] = 499,
  [SMALL_STATE(35)] = 509,
  [SMALL_STATE(36)] = 516,
  [SMALL_STATE(37)] = 523,
  [SMALL_STATE(38)] = 528,
  [SMALL_STATE(39)] = 535,
  [SMALL_STATE(40)] = 540,
  [SMALL_STATE(41)] = 547,
  [SMALL_STATE(42)] = 552,
  [SMALL_STATE(43)] = 556,
  [SMALL_STATE(44)] = 560,
  [SMALL_STATE(45)] = 564,
  [SMALL_STATE(46)] = 568,
  [SMALL_STATE(47)] = 572,
  [SMALL_STATE(48)] = 576,
  [SMALL_STATE(49)] = 580,
  [SMALL_STATE(50)] = 584,
  [SMALL_STATE(51)] = 588,
  [SMALL_STATE(52)] = 592,
  [SMALL_STATE(53)] = 596,
  [SMALL_STATE(54)] = 600,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_roll20_script, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 2, .production_id = 4),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2),
  [33] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(12),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(19),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(2),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(52),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_roll20_script, 1),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 1),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(7),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(40),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(21),
  [68] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 3, .production_id = 8),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 3, .production_id = 8),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2, .production_id = 5),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2, .production_id = 5),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [78] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroNameInsideAttributeName, 1),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macroNameInsideAttributeName, 1),
  [84] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [86] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__stringNL, 1),
  [90] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2),
  [96] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2), SHIFT_REPEAT(13),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stringNL_repeat1, 2),
  [101] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__stringNL_repeat1, 2), SHIFT_REPEAT(14),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_empty, 2),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_empty, 2),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 4, .production_id = 11),
  [110] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ability, 5),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ability, 5),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 1),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 2, .production_id = 4),
  [130] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2), SHIFT_REPEAT(22),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 1, .production_id = 3),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroNameInsideAttributeName, 2),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroInsideAttributeName, 2),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 5, .production_id = 13),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 3, .production_id = 10),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 3, .production_id = 10),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 2, .production_id = 6),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 1, .production_id = 3),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 2),
  [163] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 2), SHIFT_REPEAT(39),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 1, .production_id = 7),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selector, 1, .production_id = 1),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 3, .production_id = 9),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 2),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 1, .production_id = 2),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selectorWithMacros, 1, .production_id = 1),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 1),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability, 3, .production_id = 12),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ability_empty, 2),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 5, .production_id = 9),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [206] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
