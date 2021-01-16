let depth = 0;
const incrementDepth = () => { depth++; return /()/; };
const decrementDepth = () => { depth--; return /()/; };
const escapedAtDepth = (escapes) => {
	return RegExp("&((amp|AMP);){" + (depth) + "}(" + escapes + ");");
};
const unescapedAtDepth = (char, escapes) => {
	if(!depth) return RegExp(char);
	return RegExp("&((amp|AMP);){" + (depth-1) + "}(" + escapes + ");");
};
const unescapedAtDepthOrAbove = (char, escapes) => {
	if(!depth) return RegExp(char);
	return RegExp(char + "|&((amp|AMP);){0," + (depth-1) + "}(" + escapes + ");");
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
	name: 'roll20_macro',
	
	//externals: $ => [],
	
	//extras: $ => [],
	
	//conflicts: $ => [],
	
	inline: $ => [
		$.$macro,
		
		$.$queryOptionValue,
		$.$queryOption,
		
		$.$rollMath,
		$.$inlineOperator,
		$.$inlineRoll,
		$.$inlineGroupRoll,
		$.$inlineNumber,
		$.$mathFunction,
		$.$inlineLabel,
		
		$.$questionMark,
		$.$leftBrace,
		$.$equals,
		$.$leftBracket,
		$.$rightBracket,
		$.$plus,
		$.$minus,
		$.$digit,
		$.$leftParen,
		$.$rightParen,
		$.$tilde,
		
		$.$rightBrace,
		$.$pipe,
		$.$comma,
		$.$ampersand,
		$.$at,
		$.$percent,
		$.$hash,
		
		$.$escapedCharacter,
	],
	
	rules: {
		
		/*** attribute ***/
		
		attribute: $ => seq(
			alias(/@\{/, $.delimiter),
			choice(
				alias(/[^|}]+/, $.attributeName),
				seq(
					choice(
						prec(1, alias(/selected|target/, $.token)),
						alias(/[^|}]+/, $.characterName),
					),
					alias(/\|/, $.delimiter),
					alias(/[^|}]+/, $.attributeName),
					optional(seq(
						alias(/\|/, $.delimiter),
						alias(/max/, $.keyword),
					)),
				),
			),
			alias(/\}/, $.delimiter),
		),
		
		/*** ability ***/
		
		ability: $ => seq(
			alias(/%\{/, $.delimiter),
			choice(
				prec(1, alias(/selected|target/i, $.token)),
				alias(repeat1(
					choice(
						/[^|}@]+/,
						prec.right(choice(
							$.attribute,
							/@/,
						)),
					),
				), $.characterName),
			),
			alias(/\|/, $.delimiter),
			alias(/[^|}]+/, $.abilityName),
			alias(/\}/, $.delimiter),
		),
		
		/*** macro ***/
		
		macro: $ => seq(
			alias(/#/, $.delimiter),
			alias(repeat1(
				choice(
					/[^\s@]+/,
					prec.right(choice(
						$.attribute,
						/@/,
					)),
				),
			), $.macroName),
		),
		$macro: $ => seq(
			$.macro,
			/\s+/,
		),
		
		/*** query ***/
		
		query: $ => seq(
			alias(seq(
				$.$questionMark,
				$.$leftBrace,
				incrementDepth(),
			), $.delimiter),
			optional($.prompt),
			optional(prec.right(choice(
				seq(
					alias($.$pipe, $.delimiter),
					optional($.default),
				),
				seq(
					$.$queryOption,
					repeat1(
						$.$queryOption,
					),
				),
			))),
			alias(seq(
				decrementDepth(),
				$.$rightBrace,
			), $.delimiter),
		),
		prompt: $ => repeat1(
			choice(
				/[^|}&@%#]+/,
				prec.right(choice(
					$.attribute,
					$.ability,
					$.$macro,
					$.$escapedCharacter,
					$.$ampersand,
					$.$at,
					$.$percent,
					$.$hash,
				)),
			),
		),
		default: $ => repeat1(
			choice(
				/[^|}@%#]+/,
				prec.right(choice(
					$.attribute,
					$.ability,
					$.$macro,
					$.$at,
					$.$percent,
					$.$hash,
				)),
			),
		),
		optionName: $ => repeat1(
			choice(
				/[^|},&@%#]+/,
				prec.right(choice(
					$.attribute,
					$.ability,
					$.$macro,
					$.$escapedCharacter,
					$.$ampersand,
					$.$at,
					$.$percent,
					$.$hash,
				)),
			),
		),
		$queryOptionValue: $ => choice(
			/[^|},&@%#?{]+/,
			prec.right(choice(
				$.query,
				$.property,
				$.button,
				$.attribute,
				$.ability,
				$.$macro,
				$.$escapedCharacter,
				$.$ampersand,
				$.$at,
				$.$percent,
				$.$hash,
				$.$questionMark,
				$.$leftBrace,
			)),
		),
		$queryOption: $ => seq(
			alias($.$pipe, $.delimiter),
			alias(seq(
				optional($.optionName),
				optional(seq(
					alias($.$comma, $.delimiter),
					alias(seq(
						repeat($.$queryOptionValue),
						repeat(
							seq(
								alias(unescapedAtDepthOrAbove(",", escapes.comma), $.invalid),
								repeat($.$queryOptionValue),
							),
						),
					), $.optionValue),
				)),
			), $.option),
		),
		
		/*** property ***/
		
		property: $ => seq(
			alias(seq(
				$.$leftBrace,
				$.$leftBrace,
			), $.delimiter),
			repeat1(
				choice(
					/[^|},&@%#?{=]+/,
					prec.right(choice(
						$.query,
						$.attribute,
						$.ability,
						$.$macro,
						$.$escapedCharacter,
						$.$ampersand,
						$.$at,
						$.$percent,
						$.$hash,
						$.$questionMark,
						$.$leftBrace,
					)),
				),
			),
			optional(seq(
				alias($.$equals, $.delimiter),
				repeat(
					choice(
						/[^|},&@%#?{]+/,
						prec.right(choice(
							$.query,
							$.attribute,
							$.ability,
							$.$macro,
							$.$escapedCharacter,
							$.$ampersand,
							$.$at,
							$.$percent,
							$.$hash,
							$.$questionMark,
							$.$leftBrace,
						)),
					),
				),
			)),
			alias(seq(
				$.$rightBrace,
				$.$rightBrace,
			), $.delimiter),
		),
		
		/*** dice roll ***/
		
		roll: $ => seq(
			alias(/\d*/, $.diceCount),
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
		
		/*** group roll ***/
		
		groupRoll: $ => seq(
			alias($.$leftBrace, $.delimiter),
			$.$rollMath,
			repeat(
				seq(
					alias($.$comma, $.delimiter),
					$.$rollMath,
				),
			),
			alias($.$rightBrace, $.delimiter),
			alias(repeat(
				choice(
					/[kd][hl]?\d+/i,			//keep / drop
					/[<=>]\d+(f[<=>]?\d+)?/i,	//count successes / count successes - failures
				),
			), $.rollModifiers),
		),
		
		/*** roll table ***/
		
		rollTable: $ => seq(
			alias(/\d*/, $.diceCount),
			/t/i,
			$.$leftBracket,
			alias(repeat1(
				choice(
					/[^|}&@%#]+/,
					prec.right(choice(
						$.attribute,
						$.ability,
						$.$macro,
						$.$escapedCharacter,
						$.$ampersand,
						$.$at,
						$.$percent,
						$.$hash,
					)),
				),
			), $.tableName),
			$.$rightBracket,
		),
		
		/*** inline roll ***/
		
		inlineRoll: $ => seq(
			alias(seq(
				$.$leftBracket,
				$.$leftBracket,
			), $.delimiter),
			$.$rollMath,
			alias(seq(
				$.$rightBracket,
				$.$rightBracket,
			), $.delimiter),
		),
		
		$rollMath: $ => seq(
			$.$inlineLabel,
			choice(
				seq(
					choice(
						$.$inlineRoll,
						$.$inlineGroupRoll,
						$.rollTable,
						$.$inlineNumber,
						$.$mathFunction,
						seq(
							alias(/\(/, $.delimiter),
							$.$rollMath,
							alias(/\)/, $.delimiter),
						),
					),
					$.$inlineLabel,
				),
				repeat1(
					seq(
						choice(
							$.attribute,
							$.ability,
							$.$macro,
						),
						$.$inlineLabel
					),
				),
			),
			optional(seq(
				$.$inlineOperator,
				$.$rollMath,
			)),
		),
		$inlineOperator: $ => /[+*/-]/,
		$inlineRoll: $ => seq(
			repeat(
				choice(
					$.attribute,
					$.ability,
				),
			),
			$.roll,
			repeat(
				choice(
					$.attribute,
					$.ability,
				),
			),
			optional($.$macro),
		),
		$inlineGroupRoll: $ => seq(
			$.groupRoll,
			repeat(
				choice(
					$.attribute,
					$.ability,
				),
			),
			optional($.$macro),
		),
		$inlineNumber: $ => seq(
			repeat(
				choice(
					$.attribute,
					$.ability,
				),
			),
			alias(/\d+(\.\d*)?|\.\d+/, $.number),
			repeat(
				choice(
					$.attribute,
					$.ability,
				),
			),
			optional($.$macro),
		),
		$mathFunction: $ => seq(
			alias(/abs|ceil|floor|round/, $.functionName),
			alias(/\(/, $.delimiter),
			$.$rollMath,
			alias(/\)/, $.delimiter),
		),
		$inlineLabel: $ => seq(
			/\s*/,
			repeat(
				seq(
					/\[/,
					repeat(
						prec.right(choice(
							/[^\]&@%#]+/,
							/&((amp|AMP);)*([a-zA-Z\\d]+|#\\d+|#[xX]([a-fA-F\\d]{2}){1,2});/,
							$.attribute,
							$.ability,
							$.$macro,
							$.$ampersand,
							$.$at,
							$.$percent,
							$.$hash,
						)),
					),
					/\]\s*/,
				),
			),
		),
		
		/*** button ***/
		
		button: $ => seq(
			alias($.$leftBracket, $.delimiter),
			repeat1(
				choice(
					/[^|}\]&@%#]+/,
					prec.right(choice(
						$.attribute,
						$.ability,
						$.$macro,
						$.$escapedCharacter,
						$.$ampersand,
						$.$at,
						$.$percent,
						$.$hash,
					)),
				),
			),
			alias(seq(
				$.$rightBracket,
				$.$leftParen,
				$.$tilde,
			), $.delimiter),
			optional(seq(
				alias(repeat1(
					choice(
						/[^|})&@%#]+/,
						prec.right(choice(
							$.attribute,
							$.ability,
							$.$macro,
							$.$escapedCharacter,
							$.$ampersand,
							$.$at,
							$.$percent,
							$.$hash,
						)),
					),
				), $.characterName),
				alias($.$pipe, $.delimiter),
			)),
			alias(repeat1(
				choice(
					/[^|})&@%#]+/,
					prec.right(choice(
						$.attribute,
						$.ability,
						$.$macro,
						$.$escapedCharacter,
						$.$ampersand,
						$.$at,
						$.$percent,
						$.$hash,
					)),
				),
			), $.abilityName),
			alias($.$rightParen, $.delimiter),
		),
		
		/*** template selector ***/
		
		template: $ => seq(
			alias(seq(
				unescapedAtDepthOrAbove("&", escapes.ampersand),
				$.$leftBrace,
			), $.delimiter),
			/template:/,
			choice(
				seq(
					repeat1(
						choice(
							/[^\s}&@%#]/,
							$.attribute,
							$.ability,
						),
					),
					optional($.$macro),
				),
				$.$macro,
			),
			/\s*/,
			alias($.$rightBrace, $.delimiter),
		),
		
		/*** add to tracker ***/
		
		tracker: $ => seq(
			alias(seq(
				unescapedAtDepthOrAbove("&", escapes.ampersand),
				$.$leftBrace,
			), $.delimiter),
			/tracker(:[+-])?/,
			alias($.$rightBrace, $.delimiter),
		),
		
		/*** characters ***/
		
		$questionMark: $ => unescapedAtDepthOrAbove("\\?", escapes.questionMark),
		$leftBrace: $ => unescapedAtDepthOrAbove("\\{", escapes.leftBrace),
		$equals: $ => unescapedAtDepthOrAbove("=", escapes.equals),
		$leftBracket: $ => unescapedAtDepthOrAbove("\\[", escapes.leftBracket),
		$rightBracket: $ => unescapedAtDepthOrAbove("\\]", escapes.rightBracket),
		$plus: $ => unescapedAtDepthOrAbove("\\+", escapes.plus),
		$minus: $ => unescapedAtDepthOrAbove("\\-", escapes.minus),
		$digit: $ => unescapedAtDepthOrAbove("\\d", escapes.digit),
		$leftParen: $ => unescapedAtDepthOrAbove("\\(", escapes.leftParen),
		$rightParen: $ => unescapedAtDepthOrAbove("\\)", escapes.rightParen),
		$tilde: $ => unescapedAtDepthOrAbove("~", escapes.tilde),
		
		$rightBrace: $ => unescapedAtDepth("\\}", escapes.rightBrace),
		$pipe: $ => unescapedAtDepth("\\|", escapes.pipe),
		$comma: $ => unescapedAtDepth(",", escapes.comma),
		$ampersand: $ => unescapedAtDepth("&", escapes.ampersand),
		$at: $ => unescapedAtDepth("@", escapes.at),
		$percent: $ => unescapedAtDepth("%", escapes.percent),
		$hash: $ => unescapedAtDepth("#", escapes.hash),
		
		$escapedCharacter: $ => escapedAtDepth(escapes.htmlCharacter),
		
	},
});
