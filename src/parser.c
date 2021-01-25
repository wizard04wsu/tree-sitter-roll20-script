#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 11
#define STATE_COUNT 43
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 37
#define ALIAS_COUNT 9
#define TOKEN_COUNT 23
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
  anon_sym_AT_LBRACE_RBRACE = 11,
  anon_sym_AT_LBRACE = 12,
  anon_sym_RBRACE = 13,
  anon_sym_PIPE = 14,
  anon_sym_max = 15,
  aux_sym__attribute_token1 = 16,
  aux_sym__attribute_token2 = 17,
  anon_sym_POUND2 = 18,
  anon_sym_AT = 19,
  aux_sym__macroNameInsideAttributeName_token1 = 20,
  anon_sym_2 = 21,
  sym__will_close_brace = 22,
  sym_roll20_script = 23,
  sym__stringNL = 24,
  sym__tokenSelector = 25,
  sym__propertyNameWithMacros = 26,
  sym__selectorWithMacros = 27,
  sym_attribute = 28,
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
  alias_sym_invalid_1 = 39,
  alias_sym_invalid_2 = 40,
  alias_sym_invalid_3 = 41,
  alias_sym_invalid_4 = 42,
  alias_sym_invalid_5 = 43,
  alias_sym_invalid_open = 44,
  alias_sym_macro = 45,
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
  [anon_sym_AT_LBRACE_RBRACE] = "invalid_empty",
  [anon_sym_AT_LBRACE] = "@{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_PIPE] = "|",
  [anon_sym_max] = "keyword",
  [aux_sym__attribute_token1] = "invalid_6",
  [aux_sym__attribute_token2] = "_attribute_token2",
  [anon_sym_POUND2] = "#",
  [anon_sym_AT] = "@",
  [aux_sym__macroNameInsideAttributeName_token1] = "_macroNameInsideAttributeName_token1",
  [anon_sym_2] = "",
  [sym__will_close_brace] = "_will_close_brace",
  [sym_roll20_script] = "roll20_script",
  [sym__stringNL] = "_stringNL",
  [sym__tokenSelector] = "_tokenSelector",
  [sym__propertyNameWithMacros] = "_propertyNameWithMacros",
  [sym__selectorWithMacros] = "_selectorWithMacros",
  [sym_attribute] = "attribute",
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
  [alias_sym_invalid_1] = "invalid_1",
  [alias_sym_invalid_2] = "invalid_2",
  [alias_sym_invalid_3] = "invalid_3",
  [alias_sym_invalid_4] = "invalid_4",
  [alias_sym_invalid_5] = "invalid_5",
  [alias_sym_invalid_open] = "invalid_open",
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
  [anon_sym_AT_LBRACE_RBRACE] = anon_sym_AT_LBRACE_RBRACE,
  [anon_sym_AT_LBRACE] = anon_sym_AT_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_max] = anon_sym_max,
  [aux_sym__attribute_token1] = aux_sym__attribute_token1,
  [aux_sym__attribute_token2] = aux_sym__attribute_token2,
  [anon_sym_POUND2] = anon_sym_POUND2,
  [anon_sym_AT] = anon_sym_AT,
  [aux_sym__macroNameInsideAttributeName_token1] = aux_sym__macroNameInsideAttributeName_token1,
  [anon_sym_2] = anon_sym_2,
  [sym__will_close_brace] = sym__will_close_brace,
  [sym_roll20_script] = sym_roll20_script,
  [sym__stringNL] = sym__stringNL,
  [sym__tokenSelector] = sym__tokenSelector,
  [sym__propertyNameWithMacros] = sym__propertyNameWithMacros,
  [sym__selectorWithMacros] = sym__selectorWithMacros,
  [sym_attribute] = sym_attribute,
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
  [alias_sym_invalid_1] = alias_sym_invalid_1,
  [alias_sym_invalid_2] = alias_sym_invalid_2,
  [alias_sym_invalid_3] = alias_sym_invalid_3,
  [alias_sym_invalid_4] = alias_sym_invalid_4,
  [alias_sym_invalid_5] = alias_sym_invalid_5,
  [alias_sym_invalid_open] = alias_sym_invalid_open,
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
  [anon_sym_AT_LBRACE_RBRACE] = {
    .visible = true,
    .named = true,
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
  [sym__will_close_brace] = {
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
  [alias_sym_invalid_1] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_invalid_2] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_invalid_3] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_invalid_4] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_invalid_5] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_invalid_open] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_macro] = {
    .visible = true,
    .named = true,
  },
};

static TSSymbol ts_alias_sequences[13][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = alias_sym_invalid_open,
  },
  [2] = {
    [0] = alias_sym_characterName,
  },
  [3] = {
    [0] = alias_sym_attributeName,
  },
  [4] = {
    [0] = alias_sym_invalid_1,
  },
  [5] = {
    [1] = alias_sym_invalid_2,
  },
  [6] = {
    [0] = alias_sym_macro,
  },
  [7] = {
    [1] = anon_sym_2,
  },
  [8] = {
    [1] = alias_sym_macro,
  },
  [9] = {
    [2] = alias_sym_attributeName,
  },
  [10] = {
    [2] = alias_sym_invalid_3,
  },
  [11] = {
    [2] = alias_sym_attributeName,
    [3] = alias_sym_invalid_4,
  },
  [12] = {
    [2] = alias_sym_attributeName,
    [4] = alias_sym_invalid_5,
  },
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ACCEPT_TOKEN(anon_sym_2);
      if (eof) ADVANCE(14);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(35);
      if (lookahead == '@') ADVANCE(50);
      if (lookahead == '|') ADVANCE(44);
      if (lookahead == '}') ADVANCE(42);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(52);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(35);
      if (lookahead == '@') ADVANCE(50);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(52);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(35);
      if (lookahead == '@') ADVANCE(10);
      if (lookahead == '|') ADVANCE(43);
      if (lookahead == '}') ADVANCE(41);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(49);
      if (lookahead == 's') ADVANCE(24);
      if (lookahead == 't') ADVANCE(21);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(20);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(47);
      if (lookahead != 0) ADVANCE(33);
      END_STATE();
    case 5:
      if (lookahead == '#') ADVANCE(49);
      if (lookahead == '|') ADVANCE(43);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(33);
      END_STATE();
    case 6:
      if (lookahead == '#') ADVANCE(49);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(20);
      if (lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == '|') ADVANCE(47);
      if (lookahead != 0) ADVANCE(33);
      END_STATE();
    case 7:
      if (lookahead == '@') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '{') ADVANCE(51);
      END_STATE();
    case 8:
      if (lookahead == 'm') ADVANCE(48);
      if (lookahead == '}') ADVANCE(41);
      if (lookahead != 0) ADVANCE(47);
      END_STATE();
    case 9:
      if (lookahead == 'x') ADVANCE(45);
      END_STATE();
    case 10:
      if (lookahead == '{') ADVANCE(40);
      END_STATE();
    case 11:
      if (lookahead == '}') ADVANCE(41);
      if (lookahead != 0) ADVANCE(47);
      END_STATE();
    case 12:
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          (lookahead < '{' || '}' < lookahead)) ADVANCE(34);
      END_STATE();
    case 13:
      if (eof) ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '\r' &&
          lookahead != '@') ADVANCE(15);
      if (lookahead == '\r') ADVANCE(16);
      if (lookahead == '@') ADVANCE(17);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '\n') ADVANCE(15);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym__stringNL_token1);
      if (lookahead == '{') ADVANCE(39);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_selected);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_target);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token1);
      if (lookahead == '{') ADVANCE(37);
      if (lookahead == '%' ||
          lookahead == '@') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(34);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'a') ADVANCE(30);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'c') ADVANCE(32);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'd') ADVANCE(18);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(29);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
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
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'e') ADVANCE(31);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'g') ADVANCE(27);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'l') ADVANCE(25);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 'r') ADVANCE(28);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 't') ADVANCE(19);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead == 't') ADVANCE(26);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token2);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '#' &&
          lookahead != '%' &&
          lookahead != '@' &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token3);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(aux_sym__propertyNameWithMacros_token5);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE_RBRACE);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_AT_LBRACE);
      if (lookahead == '}') ADVANCE(38);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(52);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(52);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_max);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(46);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym__attribute_token1);
      if (lookahead != 0 &&
          lookahead != '}') ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym__attribute_token2);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym__attribute_token2);
      if (lookahead == 'a') ADVANCE(9);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_POUND2);
      if (lookahead == ' ') ADVANCE(36);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead == '@') ADVANCE(7);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '{') ADVANCE(51);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym__macroNameInsideAttributeName_token1);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym__macroNameInsideAttributeName_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != ' ' &&
          lookahead != '@') ADVANCE(52);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 13, .external_lex_state = 1},
  [2] = {.lex_state = 4},
  [3] = {.lex_state = 6},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 5},
  [8] = {.lex_state = 13, .external_lex_state = 1},
  [9] = {.lex_state = 13, .external_lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 13, .external_lex_state = 1},
  [13] = {.lex_state = 8},
  [14] = {.lex_state = 13, .external_lex_state = 1},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 13, .external_lex_state = 1},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 13, .external_lex_state = 1},
  [21] = {.lex_state = 13, .external_lex_state = 1},
  [22] = {.lex_state = 11},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 3},
  [26] = {.lex_state = 11},
  [27] = {.lex_state = 3},
  [28] = {.lex_state = 11},
  [29] = {.lex_state = 11},
  [30] = {.lex_state = 3},
  [31] = {.lex_state = 5},
  [32] = {.lex_state = 5},
  [33] = {.lex_state = 11},
  [34] = {.lex_state = 4},
  [35] = {.lex_state = 5},
  [36] = {.lex_state = 5},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 4},
  [40] = {.lex_state = 4},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 5},
};

enum {
  ts_external_token__will_close_brace = 0,
};

static TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__will_close_brace] = sym__will_close_brace,
};

static bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__will_close_brace] = true,
  },
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_2] = ACTIONS(1),
    [sym__will_close_brace] = ACTIONS(1),
  },
  [1] = {
    [sym_roll20_script] = STATE(41),
    [sym__stringNL] = STATE(8),
    [sym_attribute] = STATE(8),
    [aux_sym_roll20_script_repeat1] = STATE(8),
    [aux_sym__stringNL_repeat1] = STATE(14),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym__stringNL_token1] = ACTIONS(5),
    [anon_sym_AT_LBRACE] = ACTIONS(7),
    [sym__will_close_brace] = ACTIONS(9),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 13,
    ACTIONS(13), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(15), 1,
      aux_sym__propertyNameWithMacros_token2,
    ACTIONS(19), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(21), 1,
      aux_sym__attribute_token2,
    ACTIONS(23), 1,
      anon_sym_POUND2,
    STATE(4), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(22), 1,
      aux_sym__attribute_repeat1,
    STATE(36), 1,
      sym__propertyNameWithMacros,
    STATE(38), 1,
      sym__macroInsideAttributeName,
    STATE(39), 1,
      sym__attribute,
    ACTIONS(11), 2,
      anon_sym_selected,
      anon_sym_target,
    STATE(42), 2,
      sym__tokenSelector,
      sym__selectorWithMacros,
    ACTIONS(17), 3,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [44] = 10,
    ACTIONS(13), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(19), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(21), 1,
      aux_sym__attribute_token2,
    ACTIONS(23), 1,
      anon_sym_POUND2,
    ACTIONS(25), 1,
      anon_sym_RBRACE,
    STATE(4), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(28), 1,
      aux_sym__attribute_repeat1,
    STATE(35), 1,
      sym__propertyNameWithMacros,
    STATE(38), 1,
      sym__macroInsideAttributeName,
    ACTIONS(17), 4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [78] = 7,
    ACTIONS(19), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(27), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(33), 1,
      anon_sym_POUND2,
    STATE(5), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(25), 1,
      sym__macroInsideAttributeName,
    ACTIONS(31), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(29), 4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [104] = 7,
    ACTIONS(35), 1,
      aux_sym__propertyNameWithMacros_token1,
    ACTIONS(40), 1,
      aux_sym__propertyNameWithMacros_token4,
    ACTIONS(45), 1,
      anon_sym_POUND2,
    STATE(5), 1,
      aux_sym__propertyNameWithMacros_repeat1,
    STATE(38), 1,
      sym__macroInsideAttributeName,
    ACTIONS(43), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
    ACTIONS(37), 4,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
  [130] = 2,
    ACTIONS(48), 3,
      aux_sym__propertyNameWithMacros_token1,
      aux_sym__propertyNameWithMacros_token4,
      anon_sym_POUND2,
    ACTIONS(50), 6,
      aux_sym__propertyNameWithMacros_token2,
      aux_sym__propertyNameWithMacros_token3,
      anon_sym_POUND,
      aux_sym__propertyNameWithMacros_token5,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [144] = 2,
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
  [158] = 6,
    ACTIONS(5), 1,
      aux_sym__stringNL_token1,
    ACTIONS(7), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(9), 1,
      sym__will_close_brace,
    ACTIONS(56), 1,
      ts_builtin_sym_end,
    STATE(14), 1,
      aux_sym__stringNL_repeat1,
    STATE(9), 3,
      sym__stringNL,
      sym_attribute,
      aux_sym_roll20_script_repeat1,
  [179] = 6,
    ACTIONS(58), 1,
      ts_builtin_sym_end,
    ACTIONS(60), 1,
      aux_sym__stringNL_token1,
    ACTIONS(63), 1,
      anon_sym_AT_LBRACE,
    ACTIONS(66), 1,
      sym__will_close_brace,
    STATE(14), 1,
      aux_sym__stringNL_repeat1,
    STATE(9), 3,
      sym__stringNL,
      sym_attribute,
      aux_sym_roll20_script_repeat1,
  [200] = 4,
    ACTIONS(69), 1,
      anon_sym_,
    ACTIONS(73), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(10), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    ACTIONS(71), 3,
      anon_sym_RBRACE,
      anon_sym_PIPE,
      anon_sym_AT,
  [215] = 5,
    ACTIONS(76), 1,
      anon_sym_,
    ACTIONS(80), 1,
      anon_sym_AT,
    ACTIONS(82), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(10), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    ACTIONS(78), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [232] = 3,
    ACTIONS(86), 1,
      aux_sym__stringNL_token1,
    STATE(12), 1,
      aux_sym__stringNL_repeat1,
    ACTIONS(84), 3,
      sym__will_close_brace,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [244] = 5,
    ACTIONS(21), 1,
      aux_sym__attribute_token2,
    ACTIONS(89), 1,
      anon_sym_RBRACE,
    ACTIONS(91), 1,
      anon_sym_max,
    ACTIONS(93), 1,
      aux_sym__attribute_token1,
    STATE(29), 1,
      aux_sym__attribute_repeat1,
  [260] = 3,
    ACTIONS(97), 1,
      aux_sym__stringNL_token1,
    STATE(12), 1,
      aux_sym__stringNL_repeat1,
    ACTIONS(95), 3,
      sym__will_close_brace,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [272] = 4,
    ACTIONS(76), 1,
      anon_sym_,
    ACTIONS(80), 1,
      anon_sym_AT,
    ACTIONS(99), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(19), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
  [285] = 4,
    ACTIONS(101), 1,
      anon_sym_AT,
    ACTIONS(103), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(11), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    STATE(24), 1,
      sym__macroNameInsideAttributeName,
  [298] = 4,
    ACTIONS(101), 1,
      anon_sym_AT,
    ACTIONS(105), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(15), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
    STATE(24), 1,
      sym__macroNameInsideAttributeName,
  [311] = 2,
    ACTIONS(109), 1,
      aux_sym__stringNL_token1,
    ACTIONS(107), 3,
      sym__will_close_brace,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [320] = 4,
    ACTIONS(69), 1,
      anon_sym_,
    ACTIONS(71), 1,
      anon_sym_AT,
    ACTIONS(111), 1,
      aux_sym__macroNameInsideAttributeName_token1,
    STATE(19), 1,
      aux_sym__macroNameInsideAttributeName_repeat1,
  [333] = 2,
    ACTIONS(116), 1,
      aux_sym__stringNL_token1,
    ACTIONS(114), 3,
      sym__will_close_brace,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [342] = 2,
    ACTIONS(120), 1,
      aux_sym__stringNL_token1,
    ACTIONS(118), 3,
      sym__will_close_brace,
      ts_builtin_sym_end,
      anon_sym_AT_LBRACE,
  [351] = 3,
    ACTIONS(122), 1,
      anon_sym_RBRACE,
    ACTIONS(124), 1,
      aux_sym__attribute_token2,
    STATE(26), 1,
      aux_sym__attribute_repeat1,
  [361] = 1,
    ACTIONS(76), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [367] = 1,
    ACTIONS(126), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [373] = 2,
    ACTIONS(128), 1,
      anon_sym_,
    ACTIONS(130), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [381] = 3,
    ACTIONS(132), 1,
      anon_sym_RBRACE,
    ACTIONS(134), 1,
      aux_sym__attribute_token2,
    STATE(26), 1,
      aux_sym__attribute_repeat1,
  [391] = 1,
    ACTIONS(137), 3,
      anon_sym_,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [397] = 3,
    ACTIONS(124), 1,
      aux_sym__attribute_token2,
    ACTIONS(139), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      aux_sym__attribute_repeat1,
  [407] = 3,
    ACTIONS(124), 1,
      aux_sym__attribute_token2,
    ACTIONS(141), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      aux_sym__attribute_repeat1,
  [417] = 2,
    ACTIONS(143), 1,
      anon_sym_AT_LBRACE_RBRACE,
    ACTIONS(145), 1,
      anon_sym_AT_LBRACE,
  [424] = 1,
    ACTIONS(31), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [429] = 1,
    ACTIONS(147), 2,
      anon_sym_RBRACE,
      anon_sym_PIPE,
  [434] = 1,
    ACTIONS(149), 2,
      anon_sym_RBRACE,
      aux_sym__attribute_token2,
  [439] = 2,
    ACTIONS(151), 1,
      anon_sym_POUND2,
    STATE(37), 1,
      sym__macroInsideAttributeName,
  [446] = 2,
    ACTIONS(153), 1,
      anon_sym_RBRACE,
    ACTIONS(155), 1,
      anon_sym_PIPE,
  [453] = 2,
    ACTIONS(157), 1,
      anon_sym_RBRACE,
    ACTIONS(159), 1,
      anon_sym_PIPE,
  [460] = 1,
    ACTIONS(161), 1,
      anon_sym_,
  [464] = 1,
    ACTIONS(128), 1,
      anon_sym_,
  [468] = 1,
    ACTIONS(163), 1,
      anon_sym_RBRACE,
  [472] = 1,
    ACTIONS(165), 1,
      anon_sym_RBRACE,
  [476] = 1,
    ACTIONS(167), 1,
      ts_builtin_sym_end,
  [480] = 1,
    ACTIONS(169), 1,
      anon_sym_PIPE,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 44,
  [SMALL_STATE(4)] = 78,
  [SMALL_STATE(5)] = 104,
  [SMALL_STATE(6)] = 130,
  [SMALL_STATE(7)] = 144,
  [SMALL_STATE(8)] = 158,
  [SMALL_STATE(9)] = 179,
  [SMALL_STATE(10)] = 200,
  [SMALL_STATE(11)] = 215,
  [SMALL_STATE(12)] = 232,
  [SMALL_STATE(13)] = 244,
  [SMALL_STATE(14)] = 260,
  [SMALL_STATE(15)] = 272,
  [SMALL_STATE(16)] = 285,
  [SMALL_STATE(17)] = 298,
  [SMALL_STATE(18)] = 311,
  [SMALL_STATE(19)] = 320,
  [SMALL_STATE(20)] = 333,
  [SMALL_STATE(21)] = 342,
  [SMALL_STATE(22)] = 351,
  [SMALL_STATE(23)] = 361,
  [SMALL_STATE(24)] = 367,
  [SMALL_STATE(25)] = 373,
  [SMALL_STATE(26)] = 381,
  [SMALL_STATE(27)] = 391,
  [SMALL_STATE(28)] = 397,
  [SMALL_STATE(29)] = 407,
  [SMALL_STATE(30)] = 417,
  [SMALL_STATE(31)] = 424,
  [SMALL_STATE(32)] = 429,
  [SMALL_STATE(33)] = 434,
  [SMALL_STATE(34)] = 439,
  [SMALL_STATE(35)] = 446,
  [SMALL_STATE(36)] = 453,
  [SMALL_STATE(37)] = 460,
  [SMALL_STATE(38)] = 464,
  [SMALL_STATE(39)] = 468,
  [SMALL_STATE(40)] = 472,
  [SMALL_STATE(41)] = 476,
  [SMALL_STATE(42)] = 480,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_roll20_script, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 2, .production_id = 5),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 1),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(5),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(34),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2), SHIFT_REPEAT(17),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 3, .production_id = 8),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 3, .production_id = 8),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2, .production_id = 6),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__propertyNameWithMacros_repeat1, 2, .production_id = 6),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_roll20_script, 1),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(14),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(18),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_roll20_script_repeat1, 2), SHIFT_REPEAT(30),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2), SHIFT_REPEAT(10),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroNameInsideAttributeName, 1),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__macroNameInsideAttributeName, 1),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stringNL_repeat1, 2),
  [86] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__stringNL_repeat1, 2), SHIFT_REPEAT(12),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 4, .production_id = 11),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__stringNL, 1),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 1, .production_id = 1),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 1, .production_id = 1),
  [111] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__macroNameInsideAttributeName_repeat1, 2), SHIFT_REPEAT(19),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 2),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 2),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 4),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 4),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 1, .production_id = 4),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroInsideAttributeName, 2),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 2, .production_id = 7),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 2),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 2), SHIFT_REPEAT(33),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__macroNameInsideAttributeName, 2),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 3, .production_id = 10),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 5, .production_id = 12),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [145] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__propertyNameWithMacros, 2),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__attribute_repeat1, 1),
  [151] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 3, .production_id = 9),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 1, .production_id = 3),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__selectorWithMacros, 1, .production_id = 2),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__attribute, 5, .production_id = 9),
  [167] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
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
