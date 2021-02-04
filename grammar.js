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
		$.__EOF,					// (no content) determines if there are no more tokens
		
		$.__attribute_start,		// returns "@" if it begins an attribute
		$.__just_at,				// returns "@" if it does *not* begin an attribute
		
		$.__ability_start,			// returns "%" if it begins an ability
		$.__just_percent,			// returns "%" if it does *not* begin an ability
		
		$.__diceRoll_start,			// returns "d" or "D" if it begins a dice roll
		$.__just_d,					// returns "d" or "D" if it does *not* begin a dice roll
		
		$.__tableRoll_start,		// returns "t" or "T" if it begins a table roll
		$.__just_t,					// returns "t" or "T" if it does *not* begin a table roll
	],
	
	extras: $ => [
		//(manually handle whitespace)
	],
	
	conflicts: $ => [],
	
	inline: $ => [
		$.formula,
	],
	
	rules: {
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Start rule
		  ╚╤═══════════════════════════════════════════════════════════
		   │ Roll20 evaluates script elements in this order:
		   │ 1. abilities
		   │ 2. macros
		   │ 3. attributes
		   │ 4. repeat steps 1 to 3 as needed, up to 99 times
		   │ 5. roll queries
		   │    a. query a value
		   │    b. unescape HTML character entities (once)
		   │    c. repeat step 5 as needed, up to 99 times
		   │ 6. inline rolls (most deeply nested first)
		   │ 7. rolls (dice, table, group)
		   │ 8. parenthesized formulas (most deeply nested first)
		   │    a. math functions (floor/ceil/abs/round)
		   │    b. exponentiation
		   │    c. multiplication, division, modulus
		   │    d. addition, subtraction
		   │ 9. remaining formula
		   │ 10. unescape HTML character entities (once more)
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
				//button	//ability command button
				//tracker
			),
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Strings and Special Characters
		  ╚════════════════════════════════════════════════════════════*/
		
		/*┌──────────────────────────────
		  │ Strings
		  └──────────────────────────────*/
		
		_string: $ => chainOf(/.|# /),
		_stringNL: $ => chainOf(/.|# |#?\r?\n/),
		
		_wsp_inline: $ => /\s+/,
		
		
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
		   │   names, even though it would prevent the property from being
		   │   accessed from within a script.
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
		
		_placeholders: $ => prec.right(repeat1(choice( $.attribute, $.ability ))),
		
		
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
				"{",
				$._attribute,
				"}",
			),
			alias("@{", $.invalid),
		),
		_attribute_empty: $ => seq( $.__attribute_start, "{}" ),
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
				"{",
				$._ability,
				"}",
			),
			alias("%{", $.invalid),
		),
		_ability_empty: $ => seq( $.__ability_start, "{}" ),
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
		
		_macro_space: $ => prec(1, seq( $.macro, choice( " ", $.__EOF ) )),
		_macro_spaceNL: $ => prec(1, seq( $.macro, choice( / |\r?\n/, $.__EOF ) )),
		macro: $ => seq( "#", $.macroName ),
		macroName: $ => prec.right(repeat1(choice( $.attribute, $.__just_at, /[^ \r\n@]+/ ))),
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
		  │ helper rules
		  └──────────────────────────────*/
		
		/*_wsp_and_more: $ => seq(
			repeat($.label),
			$._wsp_possibility,
			repeat(choice(
				$._wsp_possibility,
				$.label,
			)),
		),*/
		/*_wsp_possibility: $ => choice(
			$._wsp_inline,
			$.attribute,
			$.ability,
			$._macro_space,
		),*/
		
		
		/*┌──────────────────────────────
		  │ Formula
		  └┬─────────────────────────────
		   │ A formula consisting of only whitespace and/or labels is invalid. 
		   │ 
		   │ Labels can only be the first items in a formula if the following
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
				$._expression_first_pair,
			),
		)),
		_expression_next: $ => prec.right(choice(
			seq(
				$._element_next,
				optional($._labels_and_wsp),
			),
			$._expression_next_pair,
		)),
		
		_expression_first_pair: $ => seq(
			$._element_first,
			choice(
				seq(
					optional($._labels_and_wsp),
					$._operator,
					optional($._labels_and_wsp),
					$._expression_next,
				),
				seq(
					$._labels_and_wsp,
					alias($._expression_next, $.invalid),
				),
			),
		),
		_expression_next_pair: $ => seq(
			$._element_next,
			choice(
				seq(
					optional($._labels_and_wsp),
					$._operator,
					optional($._labels_and_wsp),
					$._expression_next,
				),
				seq(
					$._labels_and_wsp,
					alias($._expression_next, $.invalid),
				),
			),
		),
		
		_element_first: $ => prec.right(2, choice(
			//$._element_inlineRoll,
			$._element_parenthesized,
			$._element_groupRoll,
			$._element_diceRoll,
			$._element_tableRoll,
			$._element_number_signed,
			//TODO: query
			seq(
				$._placeholders,
				optional($._macro_space),
			),
			$._macro_space,
			$._element_invalid,
		)),
		_element_next: $ => prec.right(1, choice(
			//$._element_inlineRoll,
			$._element_parenthesized,
			$._element_groupRoll,
			$._element_diceRoll,
			$._element_tableRoll,
			$._element_number_unsigned,
			//TODO: query
			seq(
				$._placeholders,
				optional($._macro_space),
			),
			$._macro_space,
			$._element_invalid,
		)),
		
		_element_invalid: $ => seq(
			optional($._placeholders),
			alias($._element_invalid_2, $.invalid),
			optional($._macro_space),
		),
		_element_invalid_2: $ => seq(
			$._element_invalid_begin,
			optional($._element_invalid_remainder),
		),
		_element_invalid_begin: $ => choice(
											//-------------------------------------------
											// doesn't    |  so it's *not* one of
											// match this |  these potentially valid things
			/[^@%#\d.dDtT\[({*/+\-\s]/,		//-------------------------------------------
											// @          |  attribute
											// %          |  ability
											// #          |  macro
											// digit      |  number, dice roll, table roll
											// .          |  number
											// d or D     |  dice roll
											// t or T     |  table roll (TODO)
											// [          |  label or inline roll
											// (          |  parenthesized
											// {          |  group roll
											// * or /     |  operator
											// + or -     |  operator, first number
											// \s         |  whitespace
			
											//-------------------------------------------
											// matches    |  so it's an *invalid*
											// this       |  one of these
											//-------------------------------------------
			$.__just_at,					// @          |  attribute
			$.__just_percent,				// %          |  ability
			$.__just_d,						// d or D     |  dice roll
			//TODO
		),
		_element_invalid_remainder: $ => seq(
											//-------------------------------------------
											// doesn't    |  so it's *not* the start of
											// match this |  this other thing
			/[^@%#\[({*/+\-\s})\]]/,		//-------------------------------------------
											// @          |  attribute
											// %          |  ability
											// #          |  macro
											// [          |  label or inline roll
											// (          |  parenthesized
											// {          |  group roll
											// * / + -    |  operator
											// \s         |  whitespace
											//-------------------------------------------
											// doesn't    |  so it's *not* the end of a
											// match this |  parent container
											//-------------------------------------------
											// {          |  group roll
											// (          |  parenthesized
											// [          |  label or inline roll
			
			repeat(choice(
				$._placeholders,
				/[^@%#\[({*/+\-\s})\]]/,
			)),
		),
		
		
		/*┌──────────────────────────────
		  │ Operator
		  └┬─────────────────────────────
		   │ `+-` and `-+` are evaluated as subtraction.
		   │ 
		   │ The only place a unary negative/positive operator can be is as a
		   │   prefix of a number that is the first element in a formula.
		   └─────────────────────────────*/
		
		_operator: $ => seq(
			$.operator,
			optional(alias($._invalid_operators, $.invalid)),
		),
		operator: $ => seq( /[*/%]|\*\*|\+(\s*-)?|-(\s*\+)?/ ),
		_invalid_operators: $ => repeat1(alias($.operator, "")),
		
		
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
				/[^@%#&\[\r\n\]]+/,
				$.attribute,
				$.ability,
				$._macro_space,
				$._escapedCharacter,
				$._at,
				$._percent,
				$._hash,
				$._ampersand,
			)),
			$._rightBracket,
		),
		
		_labels_and_wsp: $ => prec.right(choice(
			$._wsp_inline,
			seq(
				optional($._wsp_inline),
				repeat1(seq( $.label, optional($._wsp_inline) )),
			),
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Numbers
		  ╚╤═══════════════════════════════════════════════════════════
		   │ • Numbers can be injected with attributes and abilities.
		   │ • Inline rolls can be used in place of numbers.
		   └───────────────────────────────────────────────────────────*/
		
		/*┌──────────────────────────────
		  │ Signed Number
		  └──────────────────────────────*/
		
		_element_number_signed: $ => choice(
			$._element_number_unsigned,
			seq(
				choice(
					//valid: -5  -5.5
					//both: -5_  -5.5_
					seq(
						choice(
							alias($._element_number_signed_integer, $.number),	// -5
							alias($._element_number_signed_decimal, $.number),	// -5.5
						),
						optional(alias($._number_invalid_remainder, $.invalid)),	// _
					),
					
					//both: -5.  -5._
					seq(
						alias($._element_number_signed_integer, $.number),	// -5
						alias($._number_invalid_decimal, $.invalid),	// .  ._
					),
					
					//invalid:  -.5  -_  -.  -._
					alias($._element_number_signed_invalid, $.invalid),	// -.5  -_  -.  -._
				),
				optional($._macro_space),
			),
		),
		
		_sign: $ => /[+-]/,
		
		_element_number_signed_integer: $ => prec.left(seq(	// -5
			$._sign,
			$._unsigned_integer_with_placeholders
		)),
		_element_number_signed_decimal: $ => seq(	// -5.5
			$._element_number_signed_integer,
			".",
			$._unsigned_integer_with_placeholders,
		),
		_element_number_signed_invalid: $ => seq(
			$._sign,
			choice(
				$._number_predicate,	// -.5
				$._number_invalid_remainder,	// -_
				$._number_invalid_decimal,	// -.  -._
			),
		),
		
		
		/*┌──────────────────────────────
		  │ Unsigned Number
		  └──────────────────────────────*/
		
		_element_number_unsigned: $ => seq(
			choice(
				//valid: 5  5.5  .5
				//both: 5_  5.5_  .5_
				seq(
					choice(
						alias($._unsigned_integer_with_placeholders, $.number),
						alias($._unsigned_decimal_with_placeholders, $.number),
						alias($._number_predicate, $.number),
					),
					optional(alias($._number_invalid_remainder, $.invalid)),
				),
				
				//both: 5.  5._
				seq(
					alias($._unsigned_integer_with_placeholders, $.number),
					alias($._number_invalid_decimal, $.invalid),
				),
				
				//invalid: .  ._
				alias($._number_invalid_decimal, $.invalid),
			),
			optional($._macro_space),
		),
		
		_number_invalid_decimal: $ => seq( ".", optional($._number_invalid_remainder) ),	// .  ._
		_number_invalid_remainder: $ => seq(	// _
			/[^@%#\[({*/+\-\s})\]\d]/,	//definitely invalid
			//treat the rest as invalid
			optional($._element_invalid_remainder),
		),
		
		_unsigned_integer_with_placeholders: $ => repeat1(choice(	// 5
			/\d+/,
			$._placeholders,
			$._inlineRoll,
		)),
		_number_predicate: $ => seq( ".", $._unsigned_integer_with_placeholders ),	// .5
		_unsigned_decimal_with_placeholders: $ => prec(1, seq(	// 5.5
			$._unsigned_integer_with_placeholders,
			$._number_predicate,
		)),
		
		
		/*┌──────────────────────────────
		  │ Inline Roll
		  └┬─────────────────────────────
		   │ An inline roll may be used as a root element or in place of a
		   │   number, and contains its own formula. When evaluated, it is
		   │   reduced to a number.
		   └─────────────────────────────*/
		
		_element_inlineRoll: $ => seq(
			optional($._placeholders),
			$._inlineRoll,
			optional($._placeholders),
			optional(alias($._element_invalid_remainder, $.invalid)),
			optional($._macro_space),
		),
		
		_inlineRoll: $ => choice(
			$.inlineRoll,
			alias(/\[\[\s*\]\]/, $.invalid),
		),
		inlineRoll: $ => seq(
			/\[\[\s*/,
			choice(
				$.formula,
				alias($._labels_and_wsp, $.invalid),
			),
			/\s*\]\]/,
		),
		
		
		/*┌──────────────────────────────
		  │ Parenthesized Formula / Math Function
		  └┬─────────────────────────────
		   │ A nested formula, wrapped in parentheses, or a math function with a
		   │   formula as its argument.
		   └─────────────────────────────*/
		
		_element_parenthesized: $ => seq(
			optional($._placeholders),
			$._parenthesized,
			optional($._placeholders),
			optional(alias($._element_invalid_remainder, $.invalid)),
			optional($._macro_space),
		),
		
		_parenthesized: $ => choice(
			$.parenthesized,
			alias(/(abs|ceil|floor|round)?\(\s*\)/, $.invalid),
		),
		parenthesized: $ => seq(
			optional(alias(/abs|ceil|floor|round/, $.functionName)),
			/\(\s*/,
			choice(
				$.formula,
				alias($._labels_and_wsp, $.invalid),
			),
			/\s*\)/,
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Rolls
		  ╚════════════════════════════════════════════════════════════*/
		 
		/*┌──────────────────────────────
		  │ Roll Modifiers
		  └┬─────────────────────────────
		   │ Roll modifiers can be injected with attributes and abilities.
		   └─────────────────────────────*/
		
		_shared_modifier: $ => prec(1, choice(
			alias(/[kK][hHlL]?\d+/, $.keep),
			alias(/[dD][hHlL]?\d+/, $.drop),
			alias(/[<=>]\d+/, $.successes),
			alias(/[<=>]\d+[fF][<=>]?\d+/, $.successesMinusFailures),
		)),
		_diceRoll_modifier: $ => prec(1, choice(
			alias(/[rR][<=>]?\d+/, $.reroll),
			alias(/[rR][oO][<=>]?\d+/, $.reroll_once),
			alias(/!([<=>]?\d+)?/, $.exploding),
			alias(/!!([<=>]?\d+)?/, $.compounding),
			alias(/![pP]([<=>]?\d+)?/, $.penetrating),
			$._shared_modifier,
			alias(/[cC][Ss][<=>]?\d+/, $.criticalSuccess),
			alias(/[cC][fF][<=>]?\d+/, $.criticalFailure),
			alias(/[mM]\d*([<=>]\d+)?/, $.showMatches),
			alias(/[mM][tT]\d*([<=>]\d+)?/, $.countMatches),
			alias(/[sS][aAdD]/, $.sort),
		)),
		
		
		/*┌──────────────────────────────
		  │ Group Roll
		  └──────────────────────────────*/
		
		_element_groupRoll: $ => seq(
			optional($._placeholders),
			$._groupRoll,
			optional($._macro_space),
		),
		
		_groupRoll: $ => choice(
			$.groupRoll,
			alias($._groupRoll_invalid, $.invalid),
		),
		groupRoll: $ => prec.right(seq(
			$._leftBrace,
			optional(alias($._groupRoll_invalid_commas, $.invalid)),
			$.formula,
			repeat(seq(
				$._comma,
				optional(alias($._groupRoll_invalid_commas, $.invalid)),
				$.formula,
			)),
			optional(alias($._groupRoll_invalid_commas, $.invalid)),
			$._rightBrace,
			optional(alias($._groupRoll_modifiers, $.modifiers)),
			optional(alias($._element_invalid_remainder, $.invalid)),
		)),
		_groupRoll_modifiers: $ => repeat1(choice(
				$._shared_modifier,
				$._placeholders,
				/[dfhklDFHKL<=>\d]/,	//potentially valid
		)),
		_groupRoll_invalid: $ => seq(
			$._leftBrace,
			/\s*(,\s*)*/,
			$._rightBrace,
			optional(alias($._groupRoll_modifiers, $.modifiers)),
			optional($._groupRoll_invalid_remainder),
		),
		_groupRoll_invalid_commas: $ => prec.right(repeat1(prec.right(choice($._labels_and_wsp, $._comma)))),
		_groupRoll_invalid_remainder: $ => seq(
			/[^@%#\[({*/+\-\s})\]dfhklDFHKL<=>\d]/,	//definitely invalid
			//treat the rest as invalid
			optional($._element_invalid_remainder),
		),
		
		
		/*┌──────────────────────────────
		  │ Dice Roll
		  └──────────────────────────────*/
		
		_element_diceRoll: $ => seq(
			$.diceRoll,
			//any invalid stuff on the end
			optional(alias($._diceRoll_invalid_remainder, $.invalid)),
			//macro (optional)
			optional($._macro_space),
		),
		
		diceRoll: $ => prec.right(seq(
			//count: number of dice (optional)
			optional(alias($._unsigned_integer_with_placeholders, $.count)),
			//keyword (the letter 'd')
			$.__diceRoll_start,
			//sides: number of sides per die
			alias($._diceRoll_sides, $.sides),
			//modifiers (optional)
			optional(alias($._diceRoll_modifiers, $.modifiers)),
		)),
		_diceRoll_sides: $ => choice(
			/\d+|[fF]/,
			$.attribute,
			$.ability,
		),
		_diceRoll_modifiers: $ => repeat1(choice(
			$._diceRoll_modifier,
			$._placeholders,
			/[acdfhklmoprstACDFHKLMOPRST<=>\d!]/,	//potentially valid
		)),
		_diceRoll_invalid_remainder: $ => seq(
			/[^@%#\[({*/+\-\s})\]acdfhklmoprstACDFHKLMOPRST<=>\d!]/,	//definitely invalid
			//treat the rest as invalid
			optional($._element_invalid_remainder),
		),
		
		
		/*┌──────────────────────────────
		  │ Table Roll
		  └──────────────────────────────*/
		
		_element_tableRoll: $ => seq(
			$.tableRoll,
			//attributes and abilities (optional)
			optional($._placeholders),
			//any invalid stuff on the end
			optional(alias($._element_invalid_remainder, $.invalid)),
			//macro (optional)
			optional($._macro_space),
		),
		
		tableRoll: $ => seq(
			//count: number of "dice" (optional)
			optional(alias($._unsigned_integer_with_placeholders, $.count)),
			//keyword (the letter 't')
			$.__tableRoll_start,
			$._leftBracket,
			//table name
			alias(repeat1(
				choice(
					/[^@%#&\]]+/,
					$.attribute,
					$.ability,
					prec(1, "@{"),
					prec(1, "%{"),
					$._macro_space,
					$._at,
					$._percent,
					$._hash,
					$._ampersand,
				),
			), $.tableName),
			$._rightBracket,
		),
		
		
	},
});
