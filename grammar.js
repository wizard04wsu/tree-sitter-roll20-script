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
		$._end_of_content,	// (no content) determines if there are no more tokens
	],
	
	extras: $ => [],
	
	conflicts: $ => [
		[ $.macro, $._hash, ],
	],
	
	inline: $ => [],
	
	rules: {
		
		roll20_script: $ => repeat(
			choice(
				choice(
					$.attribute,
					$.ability,
					$._macro,
					$.___inlineRoll,
					$.query,
					//TODO
					$.template,
					$.tracker,
				),
				alias(prec.right(repeat1(/.|\n|#\s/)), $.string),
				seq(alias("#", $.string), $._end_of_content),
			),
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
					seq("|", alias(/[^}]*/, $.invalid), "}"),
				),
			),
			alias(token(seq("@{", /(\|[^}]*|[^}]+\|)?/, "}")), $.invalid),
		),
		attributeName: $ => /[^|}]+/,
		
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
			alias(token(seq("%{", /[^|}]*|\|[^|}]*|[^|}]+\||[^|}]*\|[^|}]*\|[^}]*/, "}")), $.invalid),
		),
		abilityName: $ => seq(
			/[^|}]+/,
		),
		
		/*** macro ***/
		
		macro: $ => choice(
			seq("#", $.macroName),
		),
		macroName: $ => repeat1(
			choice(
				/@|[^\s@]+/,
				$.attribute,
			),
		),
		_macro: $ => seq(
			$.macro,
			choice(/\s+/, $._end_of_content),
		),
		
		
		___inlineRoll: $ => alias($._inlineRoll, $.inlineRoll),
		_inlineRoll: $ => choice(
			seq( "[[", $.___formula, "]]" ),
			alias(/\[\[\s*\]\]/, $.invalid),
		),
		
		
		___formula: $ => alias($._formula, $.formula),
		_formula: $ => choice(
			$._formula_expression_binary_first,
			$._invalid_expression_adjacent_elements,
			$._formula_expression_unary,
			$._formula_element,
		),
		_formula_expression_binary_first: $ => seq(
			choice( $._formula_expression_unary, $._formula_element ),
			alias(/[*/+-]|\+\s*-|-\s*\+/, $.operator),
			choice( $._formula_expression_binary, $._formula_element ),
		),
		_formula_expression_binary: $ => seq(
			$._formula_element,
			alias(/[*/+-]|\+\s*-|-\s*\+/, $.operator),
			choice( $._formula_expression_binary, $._formula_element ),
		),
		_invalid_expression_adjacent_elements: $ => seq(
			choice( $._formula_expression_unary, $._formula_element ),
			choice(
				alias(/[*/+-]|\+\s*-|-\s*\+/, $.invalid_operator),
				alias(token(seq( /[^*/+\-\]\s]/, repeat(/\]?[^\]]+/) )), $.invalid_remainder),
			),
		),
		_formula_expression_unary: $ => choice(
			alias(seq( alias(/[+-]/, $.operator), $._number_unsigned_decimal_withWhole ), $.number),
		),
		
		
		_formula_element: $ => choice(
			$._valid_element,
			//$._invalid_element,
		),
		_valid_element: $ => seq(
			optional($._inline_text),
			choice(
				seq(optional($._replacements), $.___rollTable),
				seq(optional($._replacements),
					choice(
						alias($._number_unsigned_decimal, $.number),
						$.___roll,
					),
					optional($._replacements_incl_macro)),
				seq($.___groupRoll, optional($._replacements_incl_macro)),
				$.___function,
				$._replacements_incl_macro,
				$._formula_parenthesised,
				$.___inlineRoll,
				
			),
			optional($._inline_text),
		),
		_invalid_element: $ => alias(token(repeat1(/\]?[^\]]+/)), $.invalid_element),
		
		
		_inline_text: $ => repeat1(choice( /\s+/, alias($._inline_label, $.label) )),
		_inline_label: $ => seq(
			$._leftBracket,
			repeat(choice(
				/[^\]&@%#]+/,
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
		
		
		_replacements: $ => repeat1(choice( $.attribute, $.ability )),
		_replacements_incl_macro: $ => choice(
			seq( $._replacements, optional($._macro) ),
			$._macro,
		),
		
		
		_formula_parenthesised: $ => seq( "(", $.___formula, ")" ),
		
		
		_number_unsigned_integer: $ => /\d+/,
		_number_unsigned_decimal: $ => choice(	//valid:  5  5.5  .5  invalid:  5.
			seq(
				$._number_unsigned_integer,
				optional(seq( ".", $._number_unsigned_integer )),
			),
			seq( ".", $._number_unsigned_integer ),
		),
		_number_unsigned_decimal_withWhole: $ => seq(	//valid:  5  5.5  invalid:  .5  5.
			$._number_unsigned_integer,
			optional(seq( ".", $._number_unsigned_integer )),
		),
		
		
		___function: $ => alias($._math_function, $.function),
		_math_function: $ => seq(
			alias(/abs|ceil|floor|round/, $.functionName),
			$._formula_parenthesised,
		),
		
		
		___roll: $ => alias($._roll_expression, $.roll),
		_roll_expression: $ => seq(
			optional(alias($._number_unsigned_integer, $.diceCount)),
			"d",
			alias(/\d+|f/i, $.diceSides),
			optional(alias($._roll_modifiers, $.rollModifiers)),
		),
		_roll_modifiers: $ => repeat1(
			choice(
				/ro?[<=>]?\d+/i,			//reroll / reroll once
				/![!p]?([<=>]?\d+)?/i,		//explode / compound / penetrate
				/[kd][hl]?\d+/i,			//keep / drop
				/[<=>]\d+(f[<=>]?\d+)?/i,	//count successes / count successes - failures
				/c[sf][<=>]?\d+/i,			//critical success / critical failure
				/mt?\d*([<=>]\d+)?/i,		//show matches / count matches (a match is a group of 2 or more dice with the same result)
				/s[ad]/i,					//sort
			),
		),
		
		
		___groupRoll: $ => alias($._group_roll_expression, $.groupRoll),
		_group_roll_expression: $ => seq(
			$._leftBrace,
			$.___formula,
			repeat(seq( $._comma, $.___formula )),
			$._rightBrace,
			optional(alias($._group_roll_modifiers, $.rollModifiers)),
		),
		_group_roll_modifiers: $ => repeat1(
			choice(
				/[kd][hl]?\d+/i,			//keep / drop
				/[<=>]\d+(f[<=>]?\d+)?/i,	//count successes / count successes - failures
			),
		),
		
		
		___rollTable: $ => alias($._table_roll_expression, $.rollTable),
		_table_roll_expression: $ => seq(
			optional(alias($._number_unsigned_integer, $.diceCount)),
			/t/i,
			$._leftBracket,
			alias(repeat1(
				choice(
					/[^|}&@%#]+/,
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
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		/*** query ***/
		
		query: $ => seq(
			queryBegin(),
			incrementDepth(),
			choice(
				$.prompt,
				$._pipe,
				seq(
					optional($.prompt),
					$._pipe,
					choice(
						seq(
							$.option,
							$._pipe,
							$.option,
							repeat(
								seq(
									$._pipe,
									$.option,
								),
							),
						),
						optional($.defaultValue),
					),
				),
			),
			decrementDepth(),
			$._rightBrace,
		),
		prompt: $ => prec.right(repeat1(
			prec.right(choice(
				/[^|}&@%#]+/,
				$.attribute,
				$.ability,
				$._macro,
				$._escapedCharacter,
				$._ampersand,
				$._at,
				$._percent,
				$._hash,
			)),
		)),
		defaultValue: $ => repeat1(
			prec.right(choice(
				/[^|}@%#]+/,
				$.attribute,
				$.ability,
				$._macro,
				$._at,
				$._percent,
				$._hash,
			)),
		),
		option: $ => prec.right(choice(
			$.optionName,
			seq(
				optional($.optionName),
				$._comma,
				optional($.optionValue),
			),
		)),
		optionName: $ => repeat1(
			prec.right(1, choice(
				/[^|},&@%#]+/,
				$.attribute,
				$.ability,
				$._macro,
				$._escapedCharacter,
				$._ampersand,
				$._at,
				$._percent,
				$._hash,
			)),
		),
		optionValue: $ => repeat1(
			prec.right(choice(
				/[^|},&@%#?{]+/,
				$.query,
				//$.property,
				//$.button,
				$.attribute,
				$.ability,
				$._macro,
				$._escapedCharacter,
				$._ampersand,
				$._at,
				$._percent,
				$._hash,
				$._questionMark,
				$._leftBrace,
			)),
		),
		
		/*** property ***/
		
/*		property: $ => seq(
			alias(seq(
				$._leftBrace,
				$._leftBrace,
			), $.delimiter),
			repeat1(
				choice(
					/[^|},&@%#?{=]+/,
					prec.right(choice(
//						$.query,
						$.attribute,
						$.ability,
						$._macro,
						$._escapedCharacter,
						$._ampersand,
						$._at,
						$._percent,
						$._hash,
						$._questionMark,
						$._leftBrace,
					)),
				),
			),
			optional(seq(
				$._equals,
				repeat(
					choice(
						/[^|},&@%#?{]+/,
						prec.right(choice(
//							$.query,
							$.attribute,
							$.ability,
							$._macro,
							$._escapedCharacter,
							$._ampersand,
							$._at,
							$._percent,
							$._hash,
							$._questionMark,
							$._leftBrace,
						)),
					),
				),
			)),
			alias(seq(
				$._rightBrace,
				$._rightBrace,
			), $.delimiter),
		),
		
		/*** button ***/
		
/*		button: $ => seq(
			$._leftBracket,
			repeat1(
				choice(
					/[^|}\]&@%#]+/,
					prec.right(choice(
						$.attribute,
						$.ability,
						$._macro,
						$._escapedCharacter,
						$._ampersand,
						$._at,
						$._percent,
						$._hash,
					)),
				),
			),
			alias(seq(
				$._rightBracket,
				$._leftParen,
				$._tilde,
			), $.delimiter),
			optional(seq(
				alias(repeat1(
					choice(
						/[^|})&@%#]+/,
						prec.right(choice(
							$.attribute,
							$.ability,
							$._macro,
							$._escapedCharacter,
							$._ampersand,
							$._at,
							$._percent,
							$._hash,
						)),
					),
				), $.characterName),
				$._pipe,
			)),
			alias(repeat1(
				choice(
					/[^|})&@%#]+/,
					prec.right(choice(
						$.attribute,
						$.ability,
						$._macro,
						$._escapedCharacter,
						$._ampersand,
						$._at,
						$._percent,
						$._hash,
					)),
				),
			), $.abilityName),
			$._rightParen,
		),
		
		/*** template selector ***/
		
		template: $ => seq(
			unescapedAtDepthOrAbove("&", escapes.ampersand),
			$._leftBrace,
			/template:/,
			repeat1(
				choice(
					/[^\s}&@%#]/,
					$.attribute,
					$.ability,
				),
			),
			optional($._macro),
			/\s*/,
			$._rightBrace,
		),
		
		/*** to add a result to the tracker ***/
		
		tracker: $ => seq(
			unescapedAtDepthOrAbove("&", escapes.ampersand),
			$._leftBrace,
			/tracker(:[+-])?/,
			$._rightBrace,
		),
		
		/*** characters ***/
		
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
