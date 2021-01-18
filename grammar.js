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
					$.inlineRoll,
					$.query,
					
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
					alias(repeat1(
						choice(/@|[^|}@]+/, $.attribute),
					), $.characterName),
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
		
		/*** inline roll ***/
		
		inlineRoll: $ => choice(
			seq(
				"[[",
				alias($._formula, $.formula),
				/*optional(alias(choice(
					$._mathOperator,
					///([^\]]|\][^\]])+/,
				), $.invalid)),*/
				"]]"
			),
			alias(/\[\[\s*\]\]/, $.invalid),
		),
		
		_mathOperator: $ => alias(/[+*/-]/, $.operator),
		
		
		
		
		
		
		
		
		
		___formula: $ => alias($._formula_expression_leftmost, $.formula),
		
		
		_formula_parenthesised: $ => seq( "(", $.___formula, ")" ),
		
		
		_formula_expression: $ => choice(
			$._formula_element,
			$._formula_expression_binary,
		),
		_formula_expression_leftmost: $ => choice(
			$._formula_element,
			$._formula_expression_unary,
			$._formula_expression_binary_leftmost,
		),
		_formula_expression_unary: $ => choice(
			seq( alias("+", $.operator), $._number_unsigned_decimal_withWhole ),
			seq( alias("-", $.operator), $._number_unsigned_decimal_withWhole ),
		),
		_formula_expression_binary: $ => choice(
			prec.left(2, seq( $._formula_expression, alias("*", $.operator), $._formula_expression )),
			prec.left(2, seq( $._formula_expression, alias("/", $.operator), $._formula_expression )),
			prec.left(1, seq( $._formula_expression, alias("+", $.operator), $._formula_expression )),
			prec.left(1, seq( $._formula_expression, alias(/-|\+\s*-|-\s*\+/, $.operator), $._formula_expression )),
		),
		_formula_expression_binary_leftmost: $ => choice(
			prec.left(2, seq( $._formula_expression_leftmost, alias("*", $.operator), $._formula_expression )),
			prec.left(2, seq( $._formula_expression_leftmost, alias("/", $.operator), $._formula_expression )),
			prec.left(1, seq( $._formula_expression_leftmost, alias("+", $.operator), $._formula_expression )),
			prec.left(1, seq( $._formula_expression_leftmost, alias(/-|\+\s*-|-\s*\+/, $.operator), $._formula_expression )),
		),
		
		
		_formula_element: $ => seq(
			optional($._inline_text),
			choice(
				seq($._replacements,
					choice(
						alias($._table_roll_expression, $.rollTable),
					)),
				seq($._replacements,
					choice(
						alias($._number_unsigned_decimal, $.number),
						alias($._roll_expression, $.roll),
					),
					$._replacements_macro,),
				seq(
					choice(
						alias($._group_roll_expression, $.groupRoll),
					),
					$._replacements_macro),
				$._math_function,
				$._replacements_macro,
				$._formula_parenthesised,
			),
			optional($._inline_text),
		),
		_formula_element_leftmost: $ => seq(
			optional($._inline_text),
			choice(
				seq($._replacements,
					choice(
						alias($._table_roll_expression, $.rollTable),
					)),
				seq($._replacements,
					choice(
						alias($._number_unsigned_decimal, $.number),
						alias($._roll_expression, $.roll),
					),
					$._replacements_macro,),
				seq(
					choice(
						alias($._formula_expression_unary, $.number),
						alias($._group_roll_expression, $.groupRoll),
					),
					$._replacements_macro),
				$._math_function,
				$._replacements_macro,
				$._formula_parenthesised,
			),
			optional($._inline_text),
		),
		
		
		_number_unsigned_decimal: $ => /\d+(\.\d+)?|\.\d+/,		//valid:  5  5.5  .5  invalid:  5.
		_number_unsigned_decimal_withWhole: $ => /\d+(\.\d+)?/,	//valid:  5  5.5  invalid:  .5  5.
		
		
		_math_function: $ => seq(
			alias(/abs|ceil|floor|round/, $.functionName),
			$._formula_parenthesised,
		),
		
		
		_roll_expression: $ => seq(
			optional(alias(/\d+/, $.diceCount)),
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
		
		
		_table_roll_expression: $ => seq(
			optional(alias(/\d+/, $.diceCount)),
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
		
		
		_replacements: $ => repeat1(choice( $.attribute, $.ability )),
		_replacements_macro: $ => choice(
			seq( $._replacements, optional($._macro) ),
			$._macro,
		),
		
		
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
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		_formula: $ => seq(
			optional($._inlineLabels),
			prec.right(choice(
				$._mathFunction,
				$._roll,
				$._number,
				$._groupRoll,
				$._rollTable,
				seq(
					"(",
					alias($._formula, $.formula),
					")",
				),
				$._variablesAndMacro,
			)),
			optional($._inlineLabels),
			optional(seq(
				$._mathOperator,
				$._formula,
			)),
		),
		
		number: $ => choice(
			seq(
				/\d+/,
				optional(/\.\d+/),
			),
			/\.\d+/,
		),
		_number: $ => seq(
			optional($._variables),
			$.number,
			optional($._variablesAndMacro),
		),
		
		_mathFunction: $ => seq(
			alias(/abs|ceil|floor|round/, $.functionName),
			"(", alias($._formula, $.formula), ")",
		),
		
		/*** roll of same-sided dice ***/
		
		roll: $ => seq(
			optional(alias(/\d+/, $.diceCount)),
			/d/i,
			alias(/\d+|f/i, $.diceSides),
			alias(repeat(
				choice(
					/ro?[<=>]?\d+/i,			//reroll / reroll once
					/![!p]?([<=>]?\d+)?/i,		//explode / compound / penetrate
					/[kd][hl]?\d+/i,			//keep / drop
					/[<=>]\d+(f[<=>]?\d+)?/i,	//count successes / count successes - failures
					/c[sf][<=>]?\d+/i,			//critical success / critical failure
					/mt?\d*([<=>]\d+)?/i,		//show matches / count matches (a match is a group of 2 or more dice with the same result)
					/s[ad]/i,					//sort
				),
			), $.rollModifiers),
		),
		_roll: $ => seq(
			optional($._variables),
			$.roll,
			optional($._variablesAndMacro),
		),
		
		/*** group roll ***/
		
		groupRoll: $ => seq(
			$._leftBrace,
			alias($._formula, $.formula),
			repeat(
				seq(
					$._comma,
					alias($._formula, $.formula),
				),
			),
			$._rightBrace,
			alias(repeat(
				choice(
					/[kd][hl]?\d+/i,			//keep / drop
					/[<=>]\d+(f[<=>]?\d+)?/i,	//count successes / count successes - failures
				),
			), $.rollModifiers),
		),
		_groupRoll: $ => seq(
			$.groupRoll,
			optional($._variablesAndMacro),
		),
		
		/*** roll table ***/
		
		rollTable: $ => seq(
			optional(alias(/\d+/, $.diceCount)),
			/t/i,
			$._leftBracket,
			alias(repeat1(
				choice(
					/[^|}&@%#]+/,
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
			), $.tableName),
			$._rightBracket,
		),
		_rollTable: $ => seq(
			optional($._variables),
			$.rollTable,
		),
		
		/*** labels within formulas ***/
		
		_inlineLabels: $ => repeat1(
			choice(
				/\s+/,
				$.label,
			),
		),
		label: $ => prec(1, seq(
			$._leftBracket,
			repeat(
				prec.right(choice(
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
			),
			$._rightBracket,
		)),
		
		/*** general use of attributes, abilities, and macros within math expressions ***/
		
		_variables: $ => repeat1(
			choice(
				$.attribute,
				$.ability,
			),
		),
		_variablesAndMacro: $ => choice(
			$._macro,
			seq(
				$._variables,
				optional($._macro),
			),
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
