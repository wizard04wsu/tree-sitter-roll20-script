let depth = 0;
let escapes = {
	htmlCharacter: "[a-zA-Z\\d]+|#\\d+|#[xX]([a-fA-F\\d]{2}){1,2}",
	
	questionMark: "quest|#63|#[xX](00)?3[fF]",
	equals: "equals|#61|#[xX](00)?3[dD]",
	leftBracket: "lsqb|lbrack|#91|#[xX](00)?5[bB]",
	rightBracket: "rsqb|rbrack|#93|#[xX](00)?5[dD]?",
	plus: "plus|#43|#[xX](00)?2[bB]",
	minus: "hyphen|dash|#8208|#[xX]2010",
	digit: "#4[89]|#5[0-7]|#[xX](00)?3[0-9]",
	
	leftBrace: "lbrace|lcub|#123|#[xX](00)?7[bB]",
	rightBrace: "rbrace|rcub|#125|#[xX](00)?7[dD]",
	pipe: "verbar|vert|VerticalLine|#124|#[xX](00)?7[cC]",
	comma: "comma|#44|#[xX](00)?2[cC]",
	ampersand: "amp|AMP|#38|#[xX](00)?26",
	at: "commat|#64|#[xX](00)?40",
	percent: "percnt|#37|#[xX](00)?25",
	hash: "num|#35|#[xX](00)?23",
	leftParen: "lpar|#40|#[xX](00)?28",
	rightParen: "rpar|#41|#[xX](00)?29",
	tilde: "#126|#[xX](00)?7[eE]",
};

const escapedAtDepth = (escapeString) => {
	return RegExp("&(("+escapes.ampersand+");){" + (depth) + "}(" + escapeString + ");");
};
const unescapedAtDepth = (char, escapeString) => {
	if(!depth) return RegExp(char);
	return RegExp("&(("+escapes.ampersand+");){" + (depth-1) + "}(" + escapeString + ");");
};
const unescapedAtDepthOrAbove = (char, escapeString) => {
	if(!depth) return RegExp(char);
	return RegExp(char + "|&(("+escapes.ampersand+");){0," + (depth-1) + "}(" + escapeString + ");");
};


const chainOf = (rule) => prec.right(repeat1(rule));


const queryBegin = () => {
	if(!depth) return /\?\{/;
	return RegExp("\\?\\{|&(("+escapes.ampersand+");){0,"+(depth-1)+"}("+escapes.questionMark+");&(("+escapes.ampersand+");){0,"+(depth-1)+"}("+escapes.leftBrace+");");
};


module.exports = grammar({
	name: 'roll20_script',
	
	externals: $ => [
		$._EOF,	// (no content) determines if there are no more tokens
		$.__attribute_start,	// returns "@{" if there is also a closing brace
		$.__ability_start,	// returns "%{" if there is also a closing brace
	],
	
	extras: $ => [
		//(manually handle whitespace)
	],
	
	conflicts: $ => [],
	
	inline: $ => [],
	
	rules: {
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Start rule
		  ╚╤═══════════════════════════════════════════════════════════
		   │ Roll20 seems to evaluate script elements in this order:
		   │ 1. abilities
		   │ 2. attributes
		   │ 3. macros
		   │ 4. attributes (again)
		   │ 5. inline rolls & parentheticals (most-nested first)
		   └───────────────────────────────────────────────────────────*/
		
		roll20_script: $ => prec.right(repeat(
			choice(
				$._stringNL,
				$.attribute,
				$.ability,
				$._macro_spaceNL,
				$._inlineRoll,
				//TODO:
				//query
				//template
				//property
				//button
				//tracker
			),
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Strings, Numbers, and Special Characters
		  ╚════════════════════════════════════════════════════════════*/
		
		/*┌──────────────────────────────
		  │ Strings
		  └──────────────────────────────*/
		
		_string: $ => chainOf(/.|# /),
		_stringNL: $ => chainOf(/.|# |#?\r?\n/),
		
		_wsp_inline: $ => /\s+/,
		
		
		/*┌──────────────────────────────
		  │ Numbers
		  └──────────────────────────────*/
		
		_number_unsigned_integer: $ => /\d+/,
		_number_unsigned_decimal: $ => prec.right(1, choice(	//valid:  5  5.5  .5  invalid:  5.
			seq(
				$._number_unsigned_integer,
				optional(seq( ".", $._number_unsigned_integer )),
			),
			seq( ".", $._number_unsigned_integer ),
		)),
		_number_signed_decimal: $ => prec.right(seq(	//valid:  (plus, minus, or neither) 5  5.5  invalid:  .5  5.
			optional(/[+-]/),
			$._number_unsigned_integer,
			optional(seq( ".", $._number_unsigned_integer )),
		)),
		
		
		/*┌──────────────────────────────
		  │ Special Characters
		  └──────────────────────────────*/
		
		_questionMark: $ => unescapedAtDepthOrAbove("\\?", escapes.questionMark),
		_leftBrace: $ => unescapedAtDepthOrAbove("\\{", escapes.leftBrace),
		_equals: $ => unescapedAtDepthOrAbove("=", escapes.equals),
		_leftBracket: $ => unescapedAtDepthOrAbove("\\[", escapes.leftBracket),
		_rightBracket: $ => unescapedAtDepthOrAbove("\\]", escapes.rightBracket),
		_plus: $ => unescapedAtDepthOrAbove("\\+", escapes.plus),
		_minus: $ => unescapedAtDepthOrAbove("\\-", escapes.minus),
		_leftParen: $ => unescapedAtDepthOrAbove("\\(", escapes.leftParen),
		_rightParen: $ => unescapedAtDepthOrAbove("\\)", escapes.rightParen),
		_tilde: $ => unescapedAtDepthOrAbove("~", escapes.tilde),
		
		_rightBrace: $ => unescapedAtDepth("\\}", escapes.rightBrace),
		_pipe: $ => unescapedAtDepth("\\|", escapes.pipe),
		_comma: $ => unescapedAtDepth(",", escapes.comma),
		_ampersand: $ => unescapedAtDepth("&", escapes.ampersand),
		_at: $ => unescapedAtDepth("@", escapes.at),
		_percent: $ => unescapedAtDepth("%", escapes.percent),
		_hash: $ => unescapedAtDepth("#", escapes.hash),
		
		_escapedCharacter: $ => escapedAtDepth(escapes.htmlCharacter),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Attributes, Abilities, and Macros
		  ╚════════════════════════════════════════════════════════════
		
		/*┌──────────────────────────────
		  │ helper rules
		  └┬─────────────────────────────
		   │ Note that the website sometimes allows special characters in
		   │   names, even though it prevents the property from being accessed
		   │   from within a script.
		   └─────────────────────────────*/
		
		_tokenSelector: $ => choice(
			alias("selected", $.token),
			alias("target", $.token),
		),
		_propertyName: $ => choice(
			/[@%]/,
			seq(
				prec.right(repeat1(choice(
					/[^|}\r\n@%]+/,
					/[@%]+[^|}\r\n@%{]/,
					alias(/[@%]\{/, $.invalid),
				))),
				optional(/[@%]/),
			),
		),
		_propertyNameWithMacros: $ => choice(
			/[@%#]/,
			seq(
				prec.right(repeat1(choice(
					/[^|}\r\n@%#]+/,
					/[@%]+[^|}\r\n@%#{]/,
					seq( optional(/[@%]/), alias($._macroInsideAttributeName, $.macro), " " ),
					"# ",
					alias(/[@%]\{/, $.invalid),
				))),
				optional(choice(
					/[@%#]/,
					alias($._macroInsideAttributeName, ""),
				)),
			),
		),
		_selector: $ => choice(
			$._tokenSelector,
			alias($._propertyName, $.characterName),
		),
		_selectorWithMacros: $ => prec(1, choice(
			$._tokenSelector,
			alias($._propertyNameWithMacros, $.characterName),
		)),
		
		
		/*┌──────────────────────────────
		  │ Attribute
		  └┬─────────────────────────────
		   │ For an attribute, the character name and/or attribute name:
		   │ • can contain spaces and tabs.
		   │ • cannot contain new lines, pipes, closing curly braces, or the
		   │   character sequences "@{" and "%{".
		   │ • cannot be injected with attributes or abilities.
		   │ • can be injected with macros, but the space required after each
		   │   macro name must also be part of the character/attribute
		   │   name itself. (So the name has to have a space in it for each
		   │   macro you want to inject.)
		   │ • can contain hash characters that do not reference an existing
		   │   macro.
		   │ 
		   │ @{attributeName}
		   │ @{selected|attributeName}
		   │ @{selected|attributeName|max}
		   │ @{target|attributeName}
		   │ @{target|attributeName|max}
		   │ @{characterName|attributeName}
		   │ @{characterName|attributeName|max}
		   └─────────────────────────────*/
		
		attribute: $ => choice(
			alias($._attribute_empty, $.invalid),
			seq(
				$.__attribute_start,
				$._attribute,
				"}",
			),
			alias("@{", $.invalid),
		),
		_attribute_empty: $ => seq(
			$.__attribute_start,
			"}",
		),
		_attribute: $ => choice(
			alias($._propertyNameWithMacros, $.attributeName),
			seq(
				$._selectorWithMacros,
				"|",
				choice(
					alias($._propertyNameWithMacros, $.attributeName),
					seq(
						alias($._propertyNameWithMacros, $.attributeName),
						"|",
						choice(
							alias("max", $.keyword),
							alias(/max[^}]+/, $.invalid),
							alias(chainOf(/[^}]/), $.invalid),
						),
					),
					seq(
						alias($._propertyNameWithMacros, $.attributeName),
						alias("|", $.invalid),
					),
					alias(chainOf(/[^}]/), $.invalid),
				),
			),
			seq(
				$._selectorWithMacros,
				alias("|", $.invalid),
			),
			alias(chainOf(/[^}]/), $.invalid),
		),
		
		
		/*┌──────────────────────────────
		  │ Ability
		  └┬─────────────────────────────
		   │ For an ability, the character name and/or ability name:
		   │ • can contain spaces, tabs, and hash characters.
		   │ • cannot contain new lines, pipes, closing curly braces, or the
		   │   character sequences "@{" and "%{".
		   │ • cannot be injected with attributes, abilities, or macros.
		   │ 
		   │ %{selected|abilityName}
		   │ %{target|abilityName}
		   │ %{characterName|abilityName}
		   └─────────────────────────────*/
		
		ability: $ => choice(
			alias($._ability_empty, $.invalid),
			seq(
				$.__ability_start,
				$._ability,
				"}",
			),
			alias("%{", $.invalid),
		),
		_ability_empty: $ => seq(
			$.__ability_start,
			"}",
		),
		_ability: $ => choice(
			alias($._propertyName, $.abilityName),
			seq(
				$._selector,
				"|",
				choice(
					alias($._propertyName, $.abilityName),
					alias(seq(
						alias($._propertyName, ""),
						chainOf(/[^}]/),
					), $.invalid),
					alias(chainOf(/[^}]/), $.invalid),
				),
			),
			seq(
				$._selector,
				alias("|", $.invalid),
			),
			alias(chainOf(/[^}]/), $.invalid),
		),
		
		
		/*┌──────────────────────────────
		  │ Macro
		  └┬─────────────────────────────
		   │ For a macro, the macro name:
		   │ • cannot contain spaces, new lines, pipes, closing curly braces, or the
		   │   character sequence "%{".
		   │ • cannot be injected with macros.
		   │ • can be injected with attributes and abilities.
		   │ 
		   │ To call the macro, its name must be followed by either a space or
		   │   a new line. Exception: the space or new line isn't required if it
		   │   would be the last character in the script.
		   │ 
		   │ #macroName 
		   └─────────────────────────────*/
		
		_macro_space: $ => prec(1, seq( $.macro, choice( " ", $._EOF ) )),
		_macro_spaceNL: $ => prec(1, seq( $.macro, choice( / |\r?\n/, $._EOF ) )),
		macro: $ => seq( "#", $.macroName ),
		macroName: $ => prec.right(repeat1(choice( $.attribute, /@|[^ \r\n@]+/ ))),
		_macroInsideAttributeName: $ => seq( "#", alias($._macroNameInsideAttributeName, $.macroName) ),
		_macroNameInsideAttributeName: $ => choice(
			"@",
			seq(
				prec.right(repeat1( /[^ \r\n@]+|@+[^ \r\n@{]/ )),
				optional("@"),
			),
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Formulas
		  ╚════════════════════════════════════════════════════════════*/
		 
		/*┌──────────────────────────────
		  │ Inline Roll
		  └┬─────────────────────────────
		   │ • A nested inline roll is simplified for use in its parent formula.
		   │   Labels are removed and the formula is evaluated, reducing it to
		   │   only a number.
		   └─────────────────────────────*/
		
		_inlineRoll: $ => choice(
			$.inlineRoll,
			//alias(/\[\[(\s|\r?\n)*\]\]/, $.invalid),
			alias(/\[\[\s*\]\]/, $.invalid),
		),
		inlineRoll: $ => seq(
			/\[\[\s*/,
			optional(alias($._invalid_inline_elements, $.invalid)),
			optional(seq(
				choice(
					$.formula,
					alias($._labels_and_wsp, $.invalid),
				),
				optional(alias($._invalid_inline_elements, $.invalid)),
			)),
			/\s*\]\]/,
		),
		
		
		/*┌──────────────────────────────
		  │ Parenthetical / Math Function
		  └┬─────────────────────────────
		   │ • Parentheticals may be used as elements inside an inline roll,
		   │   containing their own formula. Parentheticals are not simplified
		   │   like nested inline rolls are.
		   └─────────────────────────────*/
		
		_parenthetical: $ => choice(
			$.parenthetical,
			//alias(/(abs|ceil|floor|round)?\((\s|\r?\n)*\)/, $.invalid),
			alias(/(abs|ceil|floor|round)?\(\s*\)/, $.invalid),
		),
		parenthetical: $ => seq(
			optional(alias(/abs|ceil|floor|round/, $.functionName)),
			/\(\s*/,
			optional(alias($._invalid_paren_elements, $.invalid)),
			optional(seq(
				choice(
					$.formula,
					alias($._labels_and_wsp, $.invalid),
				),
				optional(alias($._invalid_paren_elements, $.invalid)),
			)),
			/\s*\)/,
		),
		
		
		/*┌──────────────────────────────
		  │ Operator
		  └┬─────────────────────────────
		   │ • `+-` and `-+` are evaluated as subtraction.
		   │ • The only place a unary negative operator can be is as a prefix of
		   │   a number that is the first element in an inline roll or
		   │   parenthetical.
		   └─────────────────────────────*/
		
		operator: $ => /[*/+-]|\+\s*-|-\s*\+/,
		
		
		/*┌──────────────────────────────
		  │ Formula
		  └┬─────────────────────────────
		   │ • A formula consisting of only whitespace and/or labels is invalid. 
		   │ • Labels can only be the first items in a formula if the following
		   │   item is a dice roll or table roll (or attribute/ability/macro
		   │   that evaluates to one of those).
		   │   This implementation does not detect that.
		   └─────────────────────────────*/
		
		formula: $ => $._expression_first,
		
		_expression_first: $ => prec.right(choice(
			seq(
				optional($._labels_and_wsp),
				$._element_first,
				optional($._labels_and_wsp),
			),
			seq(
				optional($._labels_and_wsp),
				$._element_first_pair,
			),
		)),
		_expression_next: $ => prec.right(choice(
			seq(
				$._element_next,
				optional($._labels_and_wsp),
			),
			$._element_next_pair,
		)),
		
		_element_first_pair: $ => seq(
			$._element_first,
			choice(
				seq(
					optional($._labels_and_wsp),
					$.operator,
					optional($._labels_and_wsp),
					$._expression_next,
				),
				seq(
					$._labels_and_wsp,
					alias($._expression_next, $.invalid),
				),
			),
		),
		_element_next_pair: $ => seq(
			$._element_next,
			choice(
				seq(
					optional($._labels_and_wsp),
					$.operator,
					optional($._labels_and_wsp),
					$._expression_next,
				),
				seq(
					$._labels_and_wsp,
					alias($._expression_next, $.invalid),
				),
			),
		),
		
		_element_first: $ => prec.right(choice(
			seq(
				optional($._placeholders),
				$._element_options_first,
				optional($._placeholders),
				optional($._macro_space),
			),
			seq(
				$._placeholders,
				optional($._macro_space),
			),
			$._macro_space,
		)),
		_element_next: $ => prec.right(choice(
			seq(
				optional($._placeholders),
				$._element_options_next,
				optional($._placeholders),
				optional($._macro_space),
			),
			seq(
				$._placeholders,
				optional($._macro_space),
			),
			$._macro_space,
		)),
		
		_element_options_first: $ => choice(
			$._inlineRoll,
			$._parenthetical,
			alias($._number_signed_decimal, $.number),
			$.diceRoll,
			$.tableRoll,
			$.groupRoll,
			//TODO: query
			//alias(chainOf(/./), $.invalid),
			//alias(/./, $.invalid),
			///./,
		),
		_element_options_next: $ => choice(
			$._inlineRoll,
			$._parenthetical,
			alias($._number_unsigned_decimal, $.number),
			$.diceRoll,
			$.tableRoll,
			$.groupRoll,
			//TODO: query
			//alias(chainOf(/./), $.invalid),
			//alias(/./, $.invalid),
			///./,
		),
		
		_placeholders: $ => prec.right(repeat1(choice( $.attribute, $.ability ))),
		
		_labels_and_wsp: $ => prec.right(choice(
			$._wsp_inline,
			seq(
				optional($._wsp_inline),
				repeat1(seq( $.label, optional($._wsp_inline) )),
			),
		)),
		
		
		/*┌──────────────────────────────
		  │ Invalid Elements
		  └┬─────────────────────────────
		   │ 
		   │ TODO: handle queries & escape sequences
		   └─────────────────────────────*/
		
		_invalid_inline_elements: $ => seq(
			choice(
				/[^\ddt@%#\[{(]/i,
				/d[^\d]/i,
				/t[^\[]/i,
				///\?[^{]/,
			),
			optional(/[^@%#\[\s*/+\-\]]+|/),
		),
		_invalid_paren_elements: $ => seq(
			choice(
				/[^\ddt@%#\[{(]/i,
				/d[^\d]/i,
				/t[^\[]/i,
				///\?[^{]/,
			),
			optional(/[^@%#\[\s*/+\-)]+/),
		),
		_invalid_group_elements: $ => seq(
			choice(
				/[^\ddt@%#\[{(]/i,
				/d[^\d]/i,
				/t[^\[]/i,
				///\?[^{]/,
			),
			optional(/[^@%#\[\s*/+\-,}]+/),
		),
		
		
		/*┌──────────────────────────────
		  │ Inline Label
		  └┬─────────────────────────────
		   │ An inline label:
		   │ • cannot contain new lines or closing square brackets.
		   │ • can include attributes, abilities, and macros.
		   └─────────────────────────────*/
		
		label: $ => seq(
			$._leftBracket,
			repeat(choice(
				/[^\[\]&@%#\r\n]+/,
				$.attribute,
				$.ability,
				$._macro_space,
				$._ampersand,
				$._at,
				$._percent,
				$._hash,
				$._escapedCharacter,
			)),
			$._rightBracket,
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Rolls
		  ╚════════════════════════════════════════════════════════════*/
		 
		/*┌──────────────────────────────
		  │ Roll Modifier
		  └┬─────────────────────────────
		   │ • Roll modifiers can include attributes and abilities. This
		   │   implementation allows for that, but it also allows some
		   │   invalid modifiers.
		   │ TODO: make this more precise
		   └─────────────────────────────*/
		
		_diceRoll_modifier: $ => choice(
			alias(/r[<=>]?\d+/i, $.reroll),
			alias(/ro[<=>]?\d+/i, $.reroll_once),
			alias(/!([<=>]?\d+)?/i, $.exploding),
			alias(/!!([<=>]?\d+)?/i, $.compounding),
			alias(/!p([<=>]?\d+)?/i, $.penetrating),
			//alias(/k[hl]?\d+/i, $.keep),
			//alias(/d[hl]?\d+/i, $.drop),
			//alias(/[<=>]\d+/i, $.successes),
			//alias(/[<=>]\d+f[<=>]?\d+/i, $.successesMinusFailures),
			$._groupRoll_modifier,
			alias(/cs[<=>]?\d+/i, $.criticalSuccess),
			alias(/cf[<=>]?\d+/i, $.criticalFailure),
			alias(/m\d*([<=>]\d+)?/i, $.showMatches),
			alias(/mt\d*([<=>]\d+)?/i, $.countMatches),
			alias(/s[ad]/i, $.sort),
		),
		_groupRoll_modifier: $ => choice(
			alias(/k[hl]?\d+/i, $.keep),
			alias(/d[hl]?\d+/i, $.drop),
			alias(/[<=>]\d+/i, $.successes),
			alias(/[<=>]\d+f[<=>]?\d+/i, $.successesMinusFailures),
		),
		/*_roll_modifier_with_placeholders: $ => prec.right(repeat1(
			choice(
				/[acdfhklmoprst<=>\d!]+/,
				$._placeholders,
			),
		)),*/
		
		
		/*┌──────────────────────────────
		  │ Dice Roll
		  └──────────────────────────────*/
		
		diceRoll: $ => seq(
			optional(alias($._number_unsigned_integer, $.count)),
			/d/i,
			alias(choice(
				/\d+|f/i,
				$.attribute,
				$.ability,
			), $.sides),
			optional(alias(prec.right(repeat1($._diceRoll_modifier)), $.modifiers)),
		),
		
		
		/*┌──────────────────────────────
		  │ Table Roll
		  └──────────────────────────────*/
		
		tableRoll: $ => seq(
			optional(alias($._number_unsigned_integer, $.count)),
			/t/i,
			$._leftBracket,
			alias(repeat1(
				choice(
					/[^|}&@%#\r\n]+/,
					$.attribute,
					$.ability,
					$._macro_space,
					$._escapedCharacter,
					$._ampersand,
					$._at,
					$._percent,
					$._hash,
				),
			), $.tableName),
			$._rightBracket,
		),
		
		
		/*┌──────────────────────────────
		  │ Group Roll
		  └──────────────────────────────*/
		
		groupRoll: $ => prec.right(seq(
			$._leftBrace,
			optional(alias($._invalid_group_elements, $.invalid)),
			$.formula,
			optional(alias($._invalid_group_elements, $.invalid)),
			repeat(seq(
				$._comma,
				optional(alias($._invalid_group_elements, $.invalid)),
				$.formula,
				optional(alias($._invalid_group_elements, $.invalid)),
			)),
			$._rightBrace,
		)),
		
		
	},
});
