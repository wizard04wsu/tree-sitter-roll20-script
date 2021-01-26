#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 42
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 37
#define ALIAS_COUNT 4
#define TOKEN_COUNT 22
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5

enum {
  aux_sym__stringNL_token1 = 1,
  anon_sym_selected = 2,
  anon_sym_target = 3,
  aux_sym__propertyNameWithMacros_token1 = 4,
  aux_sym__propertyNameWithMacros_token2 = 5,
  aux_sym__propertyNameWithMacros_token3 = 6,
  aux_sym__propertyNameWithMacros_token4 = 7,
  anon_sym_ = 8,
  anon_sym_POUND = 9,
  aux_sym__propertyNameWithMacros_token5 = 10,
  anon_sym_RBRACE = 11,
  anon_sym_AT_LBRACE = 12,
  anon_sym_PIPE = 13,
  anon_sym_max = 14,
  aux_sym__attribute_token1 = 15,
  aux_sym__attribute_token2 = 16,
  anon_sym_POUND2 = 17,
  anon_sym_AT = 18,
  aux_sym__macroNameInsideAttributeName_token1 = 19,
  anon_sym_2 = 20,
  sym___attribute_start = 21,
  sym_roll20_script = 22,
  sym__stringNL = 23,
  sym__tokenSelector = 24,
  sym__propertyNameWithMacros = 25,
  sym__selectorWithMacros = 26,
  sym_attribute = 27,
  sym__attribute_empty = 28,
  sym__attribute = 29,
  sym__macroInsideAttributeName = 30,
  sym__macroNameInsideAttributeName = 31,
  aux_sym_roll20_script_repeat1 = 32,
  aux_sym__stringNL_repeat1 = 33,
  aux_sym__propertyNameWithMacros_repeat1 = 34,
  aux_sym__attribute_repeat1 = 35,
  aux_sym__macroNameInsideAttributeName_repeat1 = 36,
  alias_sym_attributeName = 37,
  alias_sym_characterName = 38,
  alias_sym_invalid = 39,
  alias_sym_macro = 40,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym__stringNL_token1] = "_stringNL_token1",
  [anon_sym_selected] = "token",
  [anon_sym_target] = "token",
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
  [anon_sym_POUND2] = "#",
  [anon_sym_AT] = "@",
  [aux_sym__macroNameInsideAttributeName_token1] = "_macroNameInsideAttributeName_token1",
  [anon_sym_2] = "",
  [sym___attribute_start] = "__attribute_start",
  [sym_roll20_script] = "roll20_script",
  [sym__stringNL] = "_stringNL",
  [sym__tokenSelector] = "_tokenSelector",
  [sym__propertyNameWithMacros] = "_propertyNameWithMacros",
  [sym__selectorWithMacros] = "_selectorWithMacros",
  [sym_attribute] = "attribute",
  [sym__attribute_empty] = "invalid",
  [sym__attribute] = "_attribute",
  [sym__macroInsideAttributeName] = "_macroInsideAttributeName",
  [sym__macroNameInsideAttributeName] = "macroName",
  [aux_sym_roll20_script_repeat1] = "roll20_script_repeat1",
  [aux_sym__stringNL_repeat1] = "_stringNL_repeat1",
  [aux_sym__propertyNameWithMacros_repeat1] = "_propertyNameWithMacros_repeat1",
  [aux_sym__attribute_repeat1] = "_attribute_repeat1",
  [aux_sym__macroNameInsideAttributeName_repeat1] = "_macroNameInsideAttributeName_repeat1",
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
  [anon_sym_POUND2] = anon_sym_POUND2,
  [anon_sym_AT] = anon_sym_AT,
  [aux_sym__macroNameInsideAttributeName_token1] = aux_sym__macroNameInsideAttributeName_token1,
  [anon_sym_2] = anon_sym_2,
  [sym___attribute_start] = sym___attribute_start,
  [sym_roll20_script] = sym_roll20_script,
  [sym__stringNL] = sym__stringNL,
  [sym__tokenSelector] = sym__tokenSelector,
  [sym__propertyNameWithMacros] = sym__propertyNameWithMacros,
  [sym__selectorWithMacros] = sym__selectorWithMacros,
  [sym_attribute] = sym_attribute,
  [sym__attribute_empty] = aux_sym__propertyNameWithMacros_token5,
  [sym__attribute] = sym__attribute,
  [sym__macroInsideAttributeName] = sym__macroInsideAttributeName,
  [sym__macroNameInsideAttributeName] = sym__macroNameInsideAttributeName,
  [aux_sym_roll20_script_repeat1] = aux_sym_roll20_script_repeat1,
  [aux_sym__stringNL_repeat1] = aux_sym__stringNL_repeat1,
  [aux_sym__propertyNameWithMacros_repeat1] = aux_sym__propertyNameWithMacros_repeat1,
  [aux_sym__attribute_repeat1] = aux_sym__attribute_repeat1,
  [aux_sym__macroNameInsideAttributeName_repeat1] = aux_sym__macroNameInsideAttributeName_repeat1,
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

static TSSymbol ts_alias_sequences[12][MAX_ALIAS_SEQUENCE_LENGTH] = {
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
    [1] = alias_sym_macro,
  },
  [8] = {
    [2] = alias_sym_attributeName,
  },
  [9] = {
    [2] = alias_sym_invalid,
  },
  [10] = {
    [2] = alias_sym_attributeName,
    [3] = alias_sym_invalid,
  },
  [11] = {
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
      if (eof) ADVANCE(13);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(34);
      if (lookahead == '@') ADVANCE(47);
      if (lookahead == '|') ADVANCE(41);
      if (lookahead == '}') ADVANCE(38);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(49);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(34);
      if (lookahead == '@') ADVANCE(47);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(49);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(34);
      if (lookahead == '|') ADVANCE(40);
      if (lookahead == '}') ADVANCE(37);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(46);
      if (lookahead == 's') ADVANCE(23);
      if (lookahead == 't') ADVANCE(20);
      if (lookahead == '}') ADVANCE(37);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(19);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(44);
      if (lookahead != 0) ADVANCE(32);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(46);
      if (lookahead == '|') ADVANCE(40);
      if (lookahead == '}') ADVANCE(37);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(32);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(46);
      if (lookahead == '}') ADVANCE(37);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(19);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(44);
      if (lookahead != 0) ADVANCE(32);
      END_STATE();
    case 7:
      if (lookahead == '@') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '{') ADVANCE(48);
      END_STATE();
    case 8:
      if (lookahead == 'm') ADVANCE(45);
      if (lookahead == '}') ADVANCE(37);
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 9:
      if (lookahead == 'x') ADVANCE(42);
      END_STATE();
    case 10:
      if (lookahead == '}') ADVANCE(37);
      if (lookahead != 0) ADVANCE(44);
      END_STATE();
    case 11:
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(33);
      END_STATE();
    case 12:
      if (eof) ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\r' &&
          lookahead != '@') ADVANCE(14);
      if (lookahead == '\r') ADVANCE(15);
      if (lookahead == '@') ADVANCE(16);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '\n') ADVANCE(14);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '{') ADVANCE(39);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token1);
      if (lookahead == '{') ADVANCE(36);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'a') ADVANCE(29);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'c') ADVANCE(31);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'd') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(28);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(30);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'g') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'l') ADVANCE(24);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'r') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 't') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 't') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token3);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token5);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(49);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(49);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_max);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym__attribute_token1);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym__attribute_token2);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym__attribute_token2);
      if (lookahead == 'a') ADVANCE(9);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_POUND2);
      if (lookahead == ' ') ADVANCE(35);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead == '@') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '{') ADVANCE(48);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym__macroNameInsideAttributeName_token1);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym__macroNameInsideAttributeName_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(49);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 12, .external_lex_state = 1},
  [2] = {.lex_state = 4},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 12, .external_lex_state = 1},
  [7] = {.lex_state = 5},
  [8] = {.lex_state = 5},
  [9] = {.lex_state = 12, .external_lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 12, .external_lex_state = 1},
  [13] = {.lex_state = 8},
  [14] = {.lex_state = 12, .external_lex_state = 1},
  [15] = {.lex_state = 12, .external_lex_state = 1},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 12, .external_lex_state = 1},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 12, .external_lex_state = 1},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 10},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 3},
  [26] = {.lex_state = 10},
  [27] = {.lex_state = 3},
  [28] = {.lex_state = 10},
  [29] = {.lex_state = 10},
  [30] = {.lex_state = 10},
  [31] = {.lex_state = 5},
  [32] = {.lex_state = 5},
  [33] = {.lex_state = 5},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 5},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 4},
  [40] = {.lex_state = 4},
  [41] = {.lex_state = 5},
};

enum {
  ts_external_token___attribute_start = 0,
};

static TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token___attribute_start] = sym___attribute_start,
};

static bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token___attribute_start] = true,
  },
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_2] = ACTIONS(1),
    [sym___attribute_start] = ACTIONS(1),
  },
  [1] = {
    [sym_roll20_script] = STATE(36),
    [sym__stringNL] = STATE(6),
    [sym_attribute] = STATE(6),
    [sym__attribute_empty] = STATE(17),
    [aux_sym_roll20_script_repeat1] = STATE(6),
    [aux_sym__stringNL_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym__stringNL_token1] = ACTIONS(5),
    [anon_sym_AT_LBRACE] = ACTIONS(7),
    [sym___attribute_start] = ACTIONS(9),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 14,
    ACTIONS(13), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(15), 1,
      aux_sym__propertyNameWithMacros_token2,
    ACTIONS(19), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(21), 1,
      anon_sym_RBRACE,
    ACTIONS(23), 1,
      aux_sym__attribute_token2,
    ACTIONS(25), 1,
      anon_sym_POUND2,
    STATE(4), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(28), 1,
      aux_sym__attribute_repeat1,
    STATE(33), 1,
      sym__propertyNameWithMacros,
    STATE(38), 1,
      sym__macroInsideAttributeName,
    STATE(39), 1,
      sym__attribute,
    ACTIONS(11), 2,
      anon_sym_selected,
      anon_sym_target,
    STATE(41), 2,
      sym__tokenSelector,
      sym__selectorWithMacros,
    ACTIONS(17), 3,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [47] = 10,
    ACTIONS(13), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(19), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(23), 1,
      aux_sym__attribute_token2,
    ACTIONS(25), 1,
      anon_sym_POUND2,
    ACTIONS(27), 1,
      anon_sym_RBRACE,
    STATE(4), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(22), 1,
      aux_sym__attribute_repeat1,
    STATE(32), 1,
      sym__propertyNameWithMacros,
    STATE(38), 1,
      sym__macroInsideAttributeName,
    ACTIONS(17), 4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [81] = 7,
    ACTIONS(19), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(29), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(35), 1,
      anon_sym_POUND2,
    STATE(5), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(27), 1,
      sym__macroInsideAttributeName,
    ACTIONS(33), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(31), 4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [107] = 7,
    ACTIONS(37), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(42), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(47), 1,
      anon_sym_POUND2,
    STATE(5), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(38), 1,
      sym__macroInsideAttributeName,
    ACTIONS(45), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(39), 4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [133] = 7,
    ACTIONS(5), 1,
      aux_sym__stringNL_token1,
    ACTIONS(7), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(9), 1,
      sym___attribute_start,
    ACTIONS(50), 1,
      ts_builtin_sym_end,
    STATE(12), 1,
      aux_sym__stringNL_repeat1,
    STATE(17), 1,
      sym__attribute_empty,
    STATE(9), 3,
      sym__stringNL,
      sym_attribute,
      aux_sym_roll20_script_repeat1,
  [157] = 2,
    ACTIONS(52), 3,
      aux_sym__propertyNameWithMacros_token1,
      aux_sym__propertyNameWithMacros_token4,
      anon_sym_POUND2,
    ACTIONS(54), 6,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [171] = 2,
    ACTIONS(56), 3,
      aux_sym__propertyNameWithMacros_token1,
      aux_sym__propertyNameWithMacros_token4,
      anon_sym_POUND2,
    ACTIONS(58), 6,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [185] = 7,
    ACTIONS(60), 1,
      ts_builtin_sym_end,
    ACTIONS(62), 1,
      aux_sym__stringNL_token1,
    ACTIONS(65), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(68), 1,
      sym___attribute_start,
    STATE(12), 1,
      aux_sym__stringNL_repeat1,
    STATE(17), 1,
      sym__attribute_empty,
    STATE(9), 3,
      sym__stringNL,
      sym_attribute,
      aux_sym_roll20_script_repeat1,
  [209] = 4,
    ACTIONS(71), 1,
      anon_sym_,
    ACTIONS(75), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(10), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    ACTIONS(73), 3,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      anon_sym_AT,
  [224] = 5,
    ACTIONS(78), 1,
      anon_sym_,
    ACTIONS(82), 1,
      anon_sym_AT,
    ACTIONS(84), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(10), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    ACTIONS(80), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [241] = 3,
    ACTIONS(88), 1,
      aux_sym__stringNL_token1,
    STATE(14), 1,
      aux_sym__stringNL_repeat1,
    ACTIONS(86), 3,
      sym___attribute_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [253] = 5,
    ACTIONS(23), 1,
      aux_sym__attribute_token2,
    ACTIONS(90), 1,
      anon_sym_RBRACE,
    ACTIONS(92), 1,
      anon_sym_max,
    ACTIONS(94), 1,
      aux_sym__attribute_token1,
    STATE(26), 1,
      aux_sym__attribute_repeat1,
  [269] = 3,
    ACTIONS(98), 1,
      aux_sym__stringNL_token1,
    STATE(14), 1,
      aux_sym__stringNL_repeat1,
    ACTIONS(96), 3,
      sym___attribute_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [281] = 2,
    ACTIONS(103), 1,
      aux_sym__stringNL_token1,
    ACTIONS(101), 3,
      sym___attribute_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [290] = 4,
    ACTIONS(105), 1,
      anon_sym_AT,
    ACTIONS(107), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(20), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    STATE(25), 1,
      sym__macroNameInsideAttributeName,
  [303] = 2,
    ACTIONS(111), 1,
      aux_sym__stringNL_token1,
    ACTIONS(109), 3,
      sym___attribute_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [312] = 4,
    ACTIONS(71), 1,
      anon_sym_,
    ACTIONS(73), 1,
      anon_sym_AT,
    ACTIONS(113), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(18), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
  [325] = 2,
    ACTIONS(118), 1,
      aux_sym__stringNL_token1,
    ACTIONS(116), 3,
      sym___attribute_start,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [334] = 4,
    ACTIONS(78), 1,
      anon_sym_,
    ACTIONS(82), 1,
      anon_sym_AT,
    ACTIONS(120), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(18), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
  [347] = 4,
    ACTIONS(105), 1,
      anon_sym_AT,
    ACTIONS(122), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(11), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    STATE(25), 1,
      sym__macroNameInsideAttributeName,
  [360] = 3,
    ACTIONS(124), 1,
      anon_sym_RBRACE,
    ACTIONS(126), 1,
      aux_sym__attribute_token2,
    STATE(29), 1,
      aux_sym__attribute_repeat1,
  [370] = 1,
    ACTIONS(128), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [376] = 1,
    ACTIONS(78), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [382] = 1,
    ACTIONS(130), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [388] = 3,
    ACTIONS(126), 1,
      aux_sym__attribute_token2,
    ACTIONS(132), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym__attribute_repeat1,
  [398] = 2,
    ACTIONS(134), 1,
      anon_sym_,
    ACTIONS(136), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [406] = 3,
    ACTIONS(126), 1,
      aux_sym__attribute_token2,
    ACTIONS(138), 1,
      anon_sym_RBRACE,
    STATE(29), 1,
      aux_sym__attribute_repeat1,
  [416] = 3,
    ACTIONS(140), 1,
      anon_sym_RBRACE,
    ACTIONS(142), 1,
      aux_sym__attribute_token2,
    STATE(29), 1,
      aux_sym__attribute_repeat1,
  [426] = 1,
    ACTIONS(145), 2,
      anon_sym_RBRACE,
      aux_sym__attribute_token2,
  [431] = 1,
    ACTIONS(147), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [436] = 2,
    ACTIONS(149), 1,
      anon_sym_RBRACE,
    ACTIONS(151), 1,
      anon_sym_PIPE,
  [443] = 2,
    ACTIONS(153), 1,
      anon_sym_RBRACE,
    ACTIONS(155), 1,
      anon_sym_PIPE,
  [450] = 2,
    ACTIONS(157), 1,
      anon_sym_POUND2,
    STATE(37), 1,
      sym__macroInsideAttributeName,
  [457] = 1,
    ACTIONS(33), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [462] = 1,
    ACTIONS(159), 1,
      ts_builtin_sym_end,
  [466] = 1,
    ACTIONS(161), 1,
      anon_sym_,
  [470] = 1,
    ACTIONS(134), 1,
      anon_sym_,
  [474] = 1,
    ACTIONS(163), 1,
      anon_sym_RBRACE,
  [478] = 1,
    ACTIONS(165), 1,
      anon_sym_RBRACE,
  [482] = 1,
    ACTIONS(167), 1,
      anon_sym_PIPE,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 47,
  [SMALL_STATE(4)] = 81,
  [SMALL_STATE(5)] = 107,
  [SMALL_STATE(6)] = 133,
  [SMALL_STATE(7)] = 157,
  [SMALL_STATE(8)] = 171,
  [SMALL_STATE(9)] = 185,
  [SMALL_STATE(10)] = 209,
  [SMALL_STATE(11)] = 224,
  [SMALL_STATE(12)] = 241,
  [SMALL_STATE(13)] = 253,
  [SMALL_STATE(14)] = 269,
  [SMALL_STATE(15)] = 281,
  [SMALL_STATE(16)] = 290,
  [SMALL_STATE(17)] = 303,
  [SMALL_STATE(18)] = 312,
  [SMALL_STATE(19)] = 325,
  [SMALL_STATE(20)] = 334,
  [SMALL_STATE(21)] = 347,
  [SMALL_STATE(22)] = 360,
  [SMALL_STATE(23)] = 370,
  [SMALL_STATE(24)] = 376,
  [SMALL_STATE(25)] = 382,
  [SMALL_STATE(26)] = 388,
  [SMALL_STATE(27)] = 398,
  [SMALL_STATE(28)] = 406,
  [SMALL_STATE(29)] = 416,
  [SMALL_STATE(30)] = 426,
  [SMALL_STATE(31)] = 431,
  [SMALL_STATE(32)] = 436,
  [SMALL_STATE(33)] = 443,
  [SMALL_STATE(34)] = 450,
  [SMALL_STATE(35)] = 457,
  [SMALL_STATE(36)] = 462,
  [SMALL_STATE(37)] = 466,
  [SMALL_STATE(38)] = 470,
  [SMALL_STATE(39)] = 474,
  [SMALL_STATE(40)] = 478,
  [SMALL_STATE(41)] = 482,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_roll20_script, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 2, .production_id = 4),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 1),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(5),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(34),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(16),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_roll20_script, 1),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 3, .production_id = 7),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 3, .production_id = 7),
  [56] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2, .production_id = 5),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2, .production_id = 5),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(12),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(17),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(2),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2), SHIFT_REPEAT(10),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroNameInsideAttributeName, 1),
  [80] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macroNameInsideAttributeName, 1),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [84] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__stringNL, 1),
  [88] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 4, .production_id = 10),
  [92] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stringNL_repeat1, 2),
  [98] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__stringNL_repeat1, 2), SHIFT_REPEAT(14),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute_empty, 2),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__attribute_empty, 2),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 1),
  [113] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2), SHIFT_REPEAT(18),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 3, .production_id = 9),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroNameInsideAttributeName, 2),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroInsideAttributeName, 2),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 5, .production_id = 11),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 2, .production_id = 6),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 1, .production_id = 3),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 2),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 2), SHIFT_REPEAT(30),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 1),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 2),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 3, .production_id = 8),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 1, .production_id = 2),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selectorWithMacros, 1, .production_id = 1),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [159] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 5, .production_id = 8),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
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
