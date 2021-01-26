let depth = 0;
const incrementDepth = () => { depth++; return /()/; };
const decrementDepth = () => { depth--; return /()/; };
const escapedAtDepth = (escapes) => {
	return RegExp("&(("+escapes.ampersand+");){" + (depth) + "}(" + escapes + ");");
};
const unescapedAtDepth = (char, escapes) => {
	if(!depth) return RegExp(char);
	return RegExp("&(("+escapes.ampersand+");){" + (depth-1) + "}(" + escapes + ");");
};
const unescapedAtDepthOrAbove = (char, escapes) => {
	if(!depth) return RegExp(char);
	return RegExp(char + "|&(("+escapes.ampersand+");){0," + (depth-1) + "}(" + escapes + ");");
};
const queryBegin = () => {
	if(!depth) return /\?\{/;
	return RegExp("\\?\\{|&(("+escapes.ampersand+");){0,"+(depth-1)+"}("+escapes.questionMark+");&(("+escapes.ampersand+");){0,"+(depth-1)+"}("+escapes.leftBrace+");");
};

const stringOfChars = (charRxp) => prec.right(repeat1(charRxp));


let escapes = {
	htmlCharacter: "[a-zA-Z\\d]+|#\\d+|#[xX]([a-fA-F\\d]{2}){1,2}",
	
	questionMark: "quest|#63|#[xX](00)?3[fF]",
	equals: "equals|#61|#[xX](00)?3[dD]",
	leftBracket: "lsqb|lbrack|#91|#[xX](00)?[bB]",
	rightBracket: "rsqb|rbrack|#93|#[xX](00)5[dD]?",
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
		   │ 5. inline rolls, ... TODO
		   └───────────────────────────────────────────────────────────*/
		
		roll20_script: $ => //seq(
			prec.right(repeat(
				//seq(
					//prec.right(repeat1(
						//seq(
							//optional(alias(/([^@%#\[]|\r?\n)+/, $.string)),
							choice(
								//alias(prec.right(repeat1( /.|\n|#\s/ )), $.string),
								//alias(prec.right(repeat1( /.|\n/ )), $.string),
								///\r?\n/,
								//alias(/(.|\r?\n)+/, $.string),
								$._stringNL,
								$.attribute,
								$.ability,
								//$._macroNL,
								//$.inlineRoll,
							),
							//alias(prec.right(repeat(/.|\r?\n/)), $.string),
						//),
					//)),
					//optional(alias(/(.|\r?\n)+/, $.string)),
				//),
			)),
			//alias(prec.right(repeat(/.|\r?\n/)), $.string),
			//optional($.macro),
		//),
		/*_string: $ => prec.left(seq(
			choice(
				/[^\[@%#]+/,
				/[\[@%#\n]+/,
			),
			optional($._string),
		)),*/
		
		
		/*┌──────────────────────────────
		  │ helper rules
		  └──────────────────────────────*/
		
		_string: $ => stringOfChars(/./),
		_stringNL: $ => stringOfChars(/.|\r?\n/),
		/*_string: $ => stringOfChars(choice(
			/./,
			seq( "#", choice( " ", $._EOF ) ),
		)),
		_stringNL: $ => stringOfChars(choice(
			/.|\r?\n/,
			seq( "#", choice( / |\r?\n/, $._EOF ) ),
		)),*/
		
		
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
							alias(stringOfChars(/[^}]/), $.invalid),
						),
					),
					seq(
						alias($._propertyNameWithMacros, $.attributeName),
						alias("|", $.invalid),
					),
					alias(stringOfChars(/[^}]/), $.invalid),
				),
			),
			seq(
				$._selectorWithMacros,
				alias("|", $.invalid),
			),
			alias(stringOfChars(/[^}]/), $.invalid),
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
						stringOfChars(/[^}]/),
					), $.invalid),
					alias(stringOfChars(/[^}]/), $.invalid),
				),
			),
			seq(
				$._selector,
				alias("|", $.invalid),
			),
			alias(stringOfChars(/[^}]/), $.invalid),
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
		
		_macroSp: $ => prec(1, seq( $.macro, choice( " ", $._EOF ) )),
		_macroNL: $ => prec(1, seq( $.macro, choice( / |\r?\n/, $._EOF ) )),
		macro: $ => seq( "#", $.macroName ),
		macroName: $ => prec.right(repeat1(choice( $.attribute, /@+|[^ \r\n@]+/ ))),
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
		 
		/*** inline roll ***/
		
		inlineRoll: $ => choice(
			seq( "[[", $.formula, "]]" ),
			//alias(/\[\[[\s\n]*\]\]/, $.invalid_inlineRoll),
		),
		
		
		parenthetical: $ => seq( "(", $.formula, ")" ),
		
		
		operator: $ => /[*/+-]|\+\s*-|-\s*\+/,
		
		
		formula: $ => seq(
			$._element_first,
			repeat(
				choice(
					seq(
						$.operator,
						$._element,
					),
					seq(
						alias($.operator, $.invalid_formula1),
						"",
					),
				),
			),
			alias(repeat( /[^\]]|\][^\]]|\n/ ), $.invalid_formula2),
		),
		
		
		_element_first: $ => seq(
			optional($._wsp),
			choice(
				seq(
					$.label,
					optional($._labels),
					choice(
						$._placeholders,
						seq(
							optional($._placeholders),
							choice(
								$.diceRoll,
								$.tableRoll,
							),
							optional($._placeholders),
						),
					),
				),
				choice(
					$._placeholders,
					seq(
						optional($._placeholders),
						choice(
							$.inlineRoll,
							$.parenthetical,
							$.diceRoll,
							$.tableRoll,
							$.groupRoll,
							seq(alias($._number_signed_decimal, $.number), ""),
						),
						optional($._placeholders),
					),
				),
			),
			optional($._macroSp),
			optional($._labels),
		),
		_element: $ => prec(1, seq(
			optional($._labels),
			choice(
				$._placeholders,
				seq(
					optional($._placeholders),
					choice(
						$.inlineRoll,
						$.parenthetical,
						$.diceRoll,
						$.tableRoll,
						$.groupRoll,
						alias($._number_unsigned_decimal, $.number),
					),
					optional($._placeholders),
				),
			),
			optional($._macroSp),
			optional($._labels),
		)),
		
		_placeholders: $ => prec.right(repeat1(choice( $.attribute, $.ability ))),
		
		
		/*** inline label ***/
		
		_labels: $ => repeat1(choice( $.label, $._wsp )),
		label: $ => seq(
			$._leftBracket,
			repeat(choice(
				/[^\]&@%#\n]+/,
				$.attribute,
				$.ability,
				$._macroSp,
				$._ampersand,
				$._at,
				$._percent,
				$._hash,
				$._escapedCharacter,
			)),
			$._rightBracket,
		),
		
		
		/*** dice roll ***/
		
		diceRoll: $ => prec.right(seq(
			optional(alias($._number_unsigned_integer, $.count)),
			/d/i,
			alias(choice(
				/\d+|f/i,
				$.attribute,
				$.ability,
			), $.sides),
			//seq(
				//alias(seq(
					//optional($.diceRoll_modifiers),
					//optional($.diceRoll_modifiers_alt),	//TODO
				//), $.modifiers),
				//"",
			//),
			repeat(
				choice(
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
					alias(/[acdfhklmoprst<=>\d!]/i, $.char),
					//$._placeholders,
				),
			),
		)),
		diceRoll_modifiers: $ => repeat1(
			choice(
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
		),
		diceRoll_modifiers_alt: $ => repeat1(
			choice(
				/[acdfhklmoprst<=>\d!]+/,
				$._placeholders,
			),
		),
		
		
		/*** table roll ***/
		
		tableRoll: $ => seq(
			optional(alias($._number_unsigned_integer, $.count)),
			/t/i,
			$._leftBracket,
			alias(repeat1(
				choice(
					/[^|}&@%#\n]+/,
					$.attribute,
					$.ability,
					$._macroSp,
					$._escapedCharacter,
					$._ampersand,
					$._at,
					$._percent,
					$._hash,
				),
			), $.tableName),
			$._rightBracket,
		),
		
		
		/*** group roll ***/
		
		groupRoll: $ => seq(
			$._leftBrace,
			$.formula,
			repeat(seq( $._comma, $.formula )),
			$._rightBrace,
			optional(alias($._groupRoll_modifiers, $.modifiers)),
		),
		_groupRoll_modifiers: $ => repeat1(
			choice(
				alias(/k[hl]?\d+/i, $.keep),
				alias(/d[hl]?\d+/i, $.drop),
				alias(/[<=>]\d+/i, $.successes),
				alias(/[<=>]\d+f[<=>]?\d+/i, $.successesMinusFailures),
			),
		),
		
		
		//$._query,
		//$._template,
		//$._property,
		//$._button,
		//$._tracker,
		//htmlCharacter
		
		
		/*** numbers ***/
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
		
		
		/*** characters ***/
		
		_wsp: $ => /(\s|\r?\n)+/,
		
		_questionMark: $ => unescapedAtDepthOrAbove("\\?", escapes.questionMark),
		_leftBrace: $ => unescapedAtDepthOrAbove("\\{", escapes.leftBrace),
		_equals: $ => unescapedAtDepthOrAbove("=", escapes.equals),
		_leftBracket: $ => unescapedAtDepthOrAbove("\\[", escapes.leftBracket),
		_rightBracket: $ => unescapedAtDepthOrAbove("\\]", escapes.rightBracket),
		_plus: $ => unescapedAtDepthOrAbove("\\+", escapes.plus),
		_minus: $ => unescapedAtDepthOrAbove("\\-", escapes.minus),
		_digit: $ => unescapedAtDepthOrAbove("\\d", escapes.digit),
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
		
	},
});
