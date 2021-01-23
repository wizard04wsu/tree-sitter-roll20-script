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
	],
	
	extras: $ => [],
	
	conflicts: $ => [
		//[ $.macro, $._hash, ],
		//[ $._diceRoll_modifiers, $._diceRoll_modifiers_alt, ],
	],
	
	inline: $ => [],
	
	rules: {
		
		roll20_script: $ => repeat(
			choice(
				$.inlineRoll,
				$.attribute,
				$.ability,
				$.macro,
				seq( alias("#", $.string), $._EOF ),
				alias(prec.right(repeat1( /.|\n|#\s/ )), $.string),
			),
		),
		
		
		inlineRoll: $ => choice(
			seq( "[[", $.formula, "]]" ),
			alias(/\[\[[\s\n]*\]\]/, $.invalid_inlineRoll),
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
			optional($._macro),
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
			optional($._macro),
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
				$._macro,
				$._ampersand,
				$._at,
				$._percent,
				$._hash,
				$._escapedCharacter,
			)),
			$._rightBracket,
		),
		
		
		/*** attribute ***/
		
		attribute: $ => choice(
			seq("@{", $.attributeName, "}"),
			seq(
				"@{",
				choice(
					alias("selected", $.token),
					alias("target", $.token),
					alias($.attributeName, $.characterName),
				),
				"|",
				$.attributeName,
				choice(
					"}",
					seq("|", alias("max", $.keyword), "}"),
					seq("|", alias(/[^}]*/, $.invalid_attribute1), "}"),
				),
			),
			alias(token(seq("@{", /(\|[^}]*|[^}]+\|)?/, "}")), $.invalid_attribute2),
		),
		attributeName: $ => /[^|}\n]+/,
		
		
		/*** ability ***/
		
		ability: $ => choice(
			seq(
				"%{",
				choice(
					alias(/selected/i, $.token),
					alias(/target/i, $.token),
					alias(token(choice(
						"@",
						seq(
							repeat1(/@+[^|}@{]|[^|}@]+/),
							optional("@"),
						)
					)), $.characterName),
				),
				"|",
				$.abilityName,
				"}",
			),
			alias(token(seq("%{", /[^|}]*|\|[^|}]*|[^|}]+\||[^|}]*\|[^|}]*\|[^}]*/, "}")), $.invalid_ability),
		),
		abilityName: $ => /[^|}\n]+/,
		
		
		/*** macro ***/
		
		_macro: $ => seq(
			$.macro,
			choice($._wsp, $._EOF),
		),
		macro: $ => choice(
			seq("#", $.macroName),
		),
		macroName: $ => prec.right(repeat1(
			choice(
				/@|[^@\s\n]+/,
				$.attribute,
			),
		)),
		
		
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
					$._macro,
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
		
		_wsp: $ => /[\s\n]+/,
		
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
