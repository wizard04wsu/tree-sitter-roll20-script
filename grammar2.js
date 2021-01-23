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
//const invalid = ($, pattern) => optional(alias(prec.right(token(pattern)), $.invalid));
//const invalid = ($, pattern) => optional(alias(token(pattern), $.invalid));
const invalid = ($, pattern) => alias(token(pattern), $.invalid);
//const invalid = ($, pattern) => optional(alias(token(repeat1(pattern)), $.invalid));


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
	],
	
	inline: $ => [],
	
	rules: {
		
		roll20_script: $ => repeat(
			choice(
				alias(prec.right(repeat1( /.|\n|#\s/ )), $.string),
				seq( alias("#", $.string), $._EOF ),
				//macro
				//ability
				//attribute
				$.inlineRoll,
			),
		),
		
		
		inlineRoll: $ => seq(
			"[[",
			$.formula,
			choice(
			//	$._inlineRoll_invalid,
			alias(/[*/+-]+[^*/+\-\]]*\]\]/, $.invalid4),
			//alias(/[*/+-]+([^*/+\-\]]|\][^\]])*\]\]/, $.invalid4),
				"]]",
			),
		),
		_inlineRoll_invalid: $ => alias(token(choice(
			seq(
				/[^\]\s\n*/+-]/,
				repeat(choice(
					/[^\]]/,
					/\][^\]]/,
				)),
				"]]",
			),
			/[*/+-][\s\n]*\]\]/,
			/[*/][\s\n]*[*/+-][^\]]*\]\]/,
			/\+[\s\n]*[*/+][^\]]*\]\]/,
			/\-[\s\n]*[*/-][^\]]*\]\]/,
			/[*/+-][^*/+-]*\]\]/,
		)), $.invalid),
		
		
		parenthetical: $ => seq(
			"(",
			$.formula,
			invalid($, repeat1( /[^)]/ )),
			")",
		),
		
		
		/*formula: $ => seq(
			$._element_plus_first,
			repeat(
				seq(
					$._operator,
					$._element_plus,
				),
			),
		),*/
		formula: $ => seq(
			$._element_plus_first,
			repeat(
				choice(
					prec(2, seq(
						$._operator,
						$._element_plus,
					)),
					alias(prec.right(repeat1( /[^*/+-]/ )), $.invalid1),
					//alias(seq(/[*/+-]/, prec.right(repeat( /[^*/+-]/ ))), $.invalid2),
				),
			),
		),
		/*formula: $ => choice(
			$._element_plus_first,
			seq(
				$._element_plus_first,
				$._operator,
				$._element_plus,
			),
			seq(
				$._element_plus,
				$._operator,
				$._element_plus,
			),
		),*/
		/*formula: $ => seq(
			choice($._element_plus_first, $._element_plus),
			repeat(seq(
				$._operator,
				$._element_plus,
			)),
		),*/
		
		
		_label: $ => "TODO",
		_element_plus_first: $ => seq(
			choice(
/*				seq(
					repeat(choice(
						$._ws,
						//$._label,
					)),
					choice(
						seq(
							repeat(choice(
								//$._attribute,
								//$._ability,
							),),
							choice(
								//dice roll,
								//table roll,
							),
						),
						//$._attribute,
						//$._ability,
					),
				),
*/				seq(
					optional($._ws),
					choice(
						seq(
/*							repeat(choice(
								//$._attribute,
								//$._ability,
							),),
*/							choice(
								$.inlineRoll,
								$.parenthetical,
								//group roll
								$._number_signed_decimal,
							),
						),
						//$._attribute,
						//$._ability,
					),
				),
			),
/*			repeat(choice(
				//$._attribute,
				//$._ability,
			)),
*/			//optional($._macro),
			seq(
				optional($._ws),
				repeat(seq(
					$._label,
					optional($._ws),
				)),
			),
		),
		_element_plus: $ => prec(1, seq(
			seq(
				optional($._ws),
				repeat(seq(
					$._label,
					optional($._ws),
				)),
			),
			choice(
				seq(
/*					repeat(choice(
						//$._attribute,
						//$._ability,
					)),
*/					choice(
						$.inlineRoll,
						$.parenthetical,
						//dice roll,
						//table roll,
						//group roll,
						$._number_unsigned_decimal,
					),
				),
				//$._attribute,
				//$._ability,
			),
/*			repeat(choice(
				//$._attribute,
				//$._ability,
			),),
*/			//optional($._macro),
			seq(
				optional($._ws),
				repeat(seq(
					$._label,
					optional($._ws),
				)),
			),
		)),
		
		
		_operator: $ => /[*/+-]|\+\s*-|-\s*\+/,
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
		
		_ws: $ => /[\s\n]+/,
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
