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
		//$.__inlineRoll_start,	// returns "[["
		//$.__label_start,	// returns "["
	],
	
	extras: $ => [
		//(manually handle whitespace)
	],
	
	conflicts: $ => [
		//[ $.formula, $.inlineRoll, ],
		//[ $._inlineRoll_invalid_first, $._labels, $._labels_invalid_alias, ],
		//[ $._labels, $._labels_invalid_alias, ],
		//[ $._inlineRoll_invalid, $.formula, ],
	],
	
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
				$.inlineRoll,
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
		_number_unsigned_decimal: $ => prec(1, choice(	//valid:  5  5.5  .5  invalid:  5.
			seq(
				$._number_unsigned_integer,
				optional(seq( ".", $._number_unsigned_integer )),
			),
			seq( ".", $._number_unsigned_integer ),
		)),
		_number_signed_decimal: $ => seq(	//valid:  (plus, minus, or neither) 5  5.5  invalid:  .5  5.
			optional(/[+-]/),
			$._number_unsigned_integer,
			optional(seq( ".", $._number_unsigned_integer )),
		),
		
		
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
		//_digit: $ => unescapedAtDepthOrAbove("\\d", escapes.digit),
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
		
		//_inlineRoll: $ => $.inlineRoll,
		inlineRoll: $ => seq(
			$._inlineRoll_start,
			optional(choice(
				$.formula,
				$._wsp_inline,
			)),
			$._inlineRoll_end,
		),
		_inlineRoll_start: $ => "[[",
		_inlineRoll_end: $ => "]]",
		
		
		/*┌──────────────────────────────
		  │ Parenthetical / Math Function
		  └┬─────────────────────────────
		   │ • Parentheticals may be used as elements inside an inline roll,
		   │   containing their own formula. Parentheticals are not simplified
		   │   like nested inline rolls are.
		   └─────────────────────────────*/
		
		parenthetical: $ => seq(
			optional(alias(/abs|ceil|floor|round/, $.functionName)),
			"(",
			$.formula,
			")",
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
		   │   This implementation does not detect that.
		   │ • Labels can only be the first items in a formula if the following
		   │   item is a dice roll or table roll (or attribute/ability/macro).
		   │   This implementation does not detect that.
		   └─────────────────────────────*/
		
		formula: $ => choice(
			seq(
				optional($._wsp_inline),
				$.label,
				repeat(prec.right(seq( optional($._wsp_inline), $.label ))),
				optional($._wsp_inline),
			),
			seq(
				optional($._wsp_inline),
				optional(seq(
					$.label,
					repeat(prec.right(seq( optional($._wsp_inline), $.label ))),
					optional($._wsp_inline),
				)),
				
				choice(
					seq(
						optional($._placeholders),
						choice(
							$.inlineRoll,
							$.parenthetical,
							alias($._number_signed_decimal, $.number),
							$.diceRoll,
							$.tableRoll,
							$.groupRoll,
							//TODO: query
						),
						optional($._placeholders),
						optional($._macro_space),
					),
					seq(
						$._placeholders,
						optional($._macro_space),
					),
					$._macro_space,
				),
				
				optional($._wsp_inline),
				optional(seq(
					$.label,
					repeat(prec.right(seq( optional($._wsp_inline), $.label ))),
					optional($._wsp_inline),
				)),
				
				//optional(alias($._formula_invalidString, $.invalid1)),
				
				prec.right(repeat(
					seq(
						optional(alias("]", $.invalid2)),
						
						$.operator,
						
						optional($._wsp_inline),
						optional(seq(
							$.label,
							repeat(prec.right(seq( optional($._wsp_inline), $.label ))),
							optional($._wsp_inline),
						)),
						
						choice(
							seq(
								optional($._placeholders),
								choice(
									$.inlineRoll,
									$.parenthetical,
									alias($._number_signed_decimal, $.number),
									$.diceRoll,
									$.tableRoll,
									$.groupRoll,
									//TODO: query
								),
								optional($._placeholders),
								optional($._macro_space),
							),
							seq(
								$._placeholders,
								optional($._macro_space),
							),
							$._macro_space,
						),
						
						optional($._wsp_inline),
						optional(seq(
							$.label,
							repeat(prec.right(seq( optional($._wsp_inline), $.label ))),
							optional($._wsp_inline),
						)),
						
						//optional(alias($._formula_invalidString, $.invalid3)),
					),
				)),
			),
		),
		
		_placeholders: $ => prec.right(repeat1(choice( $.attribute, $.ability ))),
		
		_formula_invalidString: $ => /([^*/+\-\[\]]+|\][^*/+\-\[\]])+/,
		
		
		/*┌──────────────────────────────
		  │ Inline Label
		  └┬─────────────────────────────
		   │ An inline label:
		   │ • cannot contain new lines or closing square brackets.
		   │ • can include attributes, abilities, and macros.
		   └─────────────────────────────*/
		
		/*_labels: $ => prec.right(seq(
			$.label,
			repeat(seq(
				optional($._wsp_inline),
				$.label,
			)),
		)),
		_labels_invalid_alias: $ => prec.right(seq(
			alias($.label, $.invalid),
			repeat(seq(
				optional($._wsp_inline),
				alias($.label, $.invalid),
			)),
		)),*/
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
		  │ Roll Modifiers
		  └┬─────────────────────────────
		   │ • Roll modifiers can include attributes and abilities. This
		   │   implementation allows for that, but it also allows some
		   │   invalid modifiers.
		   │ TODO: make this more precise
		   └─────────────────────────────*/
		
		_diceRoll_modifiers: $ => prec.right(repeat1(choice(
			//prec(1, $._diceRoll_modifier),
			$._diceRoll_modifier,
			//$._roll_modifier_with_placeholders,
		))),
		_groupRoll_modifiers: $ => prec.right(repeat1(choice(
			//prec(1, $._groupRoll_modifier),
			$._groupRoll_modifier,
			//$._roll_modifier_with_placeholders,
		))),
		_diceRoll_modifier: $ => choice(
			alias(/r[<=>]?\d+/i, $.reroll),
			alias(/ro[<=>]?\d+/i, $.reroll_once),
			alias(/!([<=>]?\d+)?/i, $.exploding),
			alias(/!!([<=>]?\d+)?/i, $.compounding),
			alias(/!p([<=>]?\d+)?/i, $.penetrating),
			alias(/k[hl]?\d+/i, $.keep),
			alias(/d[hl]?\d+/i, $.drop),
			alias(/[<=>]\d+/i, $.successes),
			alias(/[<=>]\d+f[<=>]?\d+/i, $.successesMinusFailures),
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
		
		diceRoll: $ => prec.right(seq(
			optional(alias($._number_unsigned_integer, $.count)),
			/d/i,
			alias(choice(
				/\d+|f/i,
				$.attribute,
				$.ability,
			), $.sides),
			optional(alias($._diceRoll_modifiers, $.modifiers)),
		)),
		
		
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
			$.formula,
			repeat(seq( $._comma, $.formula )),
			$._rightBrace,
			optional(alias($._groupRoll_modifiers, $.modifiers)),
		)),
		
		
	},
});
