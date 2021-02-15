
const chainOf = (rule) => prec.right(repeat1(rule));

const name = (charsRule) => {
	let forMacroName = prec.right(repeat1(choice( charsRule, "#" )));
	let notForMacroName = prec.right(repeat1(choice( charsRule, " " )));
	return $ => choice(
		notForMacroName,
		seq(
			optional(notForMacroName),
			seq(
				alias($.__macro_start, $.macroHash),
				forMacroName,
				repeat(seq(
					/ |\r?\n/,
					optional(notForMacroName),
					alias($.__macro_start, $.macroHash),
					forMacroName,
				)),
				optional(seq(
					/ |\r?\n/,
					optional(notForMacroName),
				)),
			),
		),
	);
};


module.exports = grammar({
	name: 'roll20_script',
	
	externals: $ => [
		$.__attribute_start,			// @
		
		$.__ability_start,				// %
		
		$.__macro_start,				// #
		
		//$.__html_entity,				// HTML entity
		
		$.__rollQuery_start,			// ?{  or equivalent HTML entity(ies)
		$.__rollQuery_pipe_hasDefault,	// |  or equivalent HTML entity
		$.__rollQuery_pipe_hasOptions,	// |  or equivalent HTML entity
		$.__rollQuery_end,				// }  or equivalent HTML entity
		
		//$.__label_start,
		//$.__label_end,
		
		//$.__inlineRoll_start,
		//$.__inlineRoll_end,
		
		//$.__parenthesized_start,
		//$.__parenthesized_end,
		
		//$.__groupRoll_start,
		//$.__groupRoll_end,
		
		$.__diceRoll_start,				// d or D  or equivalent HTML entity
		
		$.__tableRoll_start,			// t or T  or equivalent HTML entity
		//$.__tableRoll_end,
		
		
		$.__just_at,					// @
		$.__just_percent,				// %
		$.__just_hash,					// #
		$.__just_ampersand,				// &
		$.__just_d,						// d or D
		$.__just_t,						// t or T
		$.__just_questionmark,			// ?
		$.__pipe,						// |
		//$.__comma,					// ,
		//$.__leftBrace,				// {
		//$.__rightBrace,				// }
		//$.__leftBracket,				// [
		//$.__rightBracket,				// ]
		
		$.__integer,
		$.__decimal,
	],
	
	extras: $ => [
		//(manually handle whitespace)
	],
	
	conflicts: $ => [
		[ $._integer_etc, $.diceRoll, $.tableRoll, ],
	],
	
	inline: $ => [
		$.formula,
	],
	
	rules: {
		
		/*╔════════════════════════════════════════════════════════════
		  ║ General Notes
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ Roll20 appears to evaluate script elements in this order:
		   │ 1. abilities
		   │ 2. macros (skip ones that have an attribute in their name)
		   │ 3. attributes
		   │ 4. repeat steps 1 to 3 if necessary
		   │ 5. roll queries
		   │    a. prompt for a value or a choice from a dropdown box
		   │    b. if a dropdown box was used, unescape HTML character entities
		   │       in the option value (once)
		   │    c. repeat step 5 if needed
		   │ 6. inline rolls (most deeply nested first)
		   │    a. group rolls (most deeply nested first)
		   │       i. rolls (dice, table)
		   │       ii. repeat step 6.a if needed
		   │    b. remaining rolls (dice, table)
		   │    c. math (order of operations is below)
		   │    d. repeat step 6 if needed
		   │ 7. remaining group rolls (most deeply nested first)
		   │    a. rolls (dice, table)
		   │    b. repeat step 7 if needed
		   │ 8. remaining rolls (dice, table)
		   │ 9. math
		   │ 
		   │ Order of math operations:
		   │ 1. parentheses (most deeply nested first)
		   │    a. floor/ceil/abs/round functions (most deeply nested first)
		   │       i.   exponentiation
		   │       ii.  multiplication, division, modulus
		   │       iii. addition, subtraction
		   │       iv.  repeat step 1.a as needed
		   │    b. repeat step 1 as needed
		   │ 3. unescape HTML character entities (again)
		   └───────────────────────────────────────────────────────────*/
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Start rule
		  ╚════════════════════════════════════════════════════════════*/
		
		roll20_script: $ => prec.right(repeat(
			choice(
				$._attribute,
				$._ability,
				$._macro,
				$._rollQuery,
				$._inlineRoll,
				//TODO:
				//template
				//property
				//button	//ability command button
				//tracker
				$._stringNL,
			),
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Strings and Special Characters
		  ╚════════════════════════════════════════════════════════════*/
		
		/*┌──────────────────────────────
		  │ Strings
		  └──────────────────────────────*/
		
		_stringNL: $ => chainOf(choice( /[^#]/, $.__just_hash )),
		
		_wsp_inline: $ => /\s+/,
		
		
		/*┌──────────────────────────────
		  │ Special Characters
		  └──────────────────────────────*/
		
		//TODO: get these from the scanner so they're properly escaped
		__just_ampersand: $ => "&",
		__leftBracket: $ => "[",
		__leftBrace: $ => "{",
		__rightBrace: $ => "}",
		__rightBracket: $ => "]",
		__comma: $ => ",",
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Attributes, Abilities, and Macros
		  ╚════════════════════════════════════════════════════════════*/
		
		/*┌──────────────────────────────
		  │ helper rules
		  └┬─────────────────────────────*/
		 /*│ Note that the website sometimes allows special characters in
		   │   names, even though it would prevent the property from being
		   │   accessed from within a script.
		   └─────────────────────────────*/
		
		_tokenSelector: $ => choice(
			alias("selected", $.token),
			alias("target", $.token),
		),
		_propertyName: $ => name(choice(
			///[^@%#&}| \r\n]+/,
			/[^@%#&}| \r\n]+/,
			//$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			$.__just_ampersand,
			alias("@{", $.invalid),
			alias("%{", $.invalid),
		))($),
		_selector: $ => choice(
			$._tokenSelector,
			alias($._propertyName, $.characterName),
		),
		
		_placeholders: $ => prec.right(repeat1(choice( $._attribute, $._ability ))),
		
		
		/*┌──────────────────────────────
		  │ Attribute
		  └┬─────────────────────────────*/
		 /*│ For an attribute, the character name and/or attribute name:
		   │ • can contain spaces and tabs.
		   │ • cannot contain new lines, pipes, closing curly braces, or the
		   │   character sequences "@{" and "%{".
		   │ • cannot include attributes or abilities.
		   │ • can include macros, but the space required after each macro name
		   │   must also be part of the character/attribute name itself. (So the
		   │   name has to have a space in it for each macro you want to
		   │   include.)
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
		
		_attribute: $ => choice(
			$.attribute,
			alias($._attribute_empty, $.invalid),	//@{}
			alias("@{", $.invalid),
		),
		attribute: $ => seq(
			$.__attribute_start,
			"{",
			$._attribute_content,
			"}",
		),
		_attribute_empty: $ => seq( $.__attribute_start, "{}" ),
		_attribute_content: $ => choice(
			alias($._propertyName, $.attributeName),
			seq(
				$._selector,
				"|",
				choice(
					alias($._propertyName, $.attributeName),
					seq(
						alias($._propertyName, $.attributeName),
						"|",
						choice(
							alias("max", $.keyword),
							alias(/max[^}]+/, $.invalid),
							alias(chainOf(/[^}]/), $.invalid),
						),
					),
					seq(
						alias($._propertyName, $.attributeName),
						alias("|", $.invalid),
					),
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
		  │ Ability
		  └┬─────────────────────────────*/
		 /*│ For an ability, the character name and/or ability name:
		   │ • can contain spaces, tabs, and hash characters.
		   │ • cannot contain new lines, pipes, closing curly braces, or the
		   │   character sequences "@{" and "%{".
		   │ • cannot include attributes, abilities, or macros.
		   │ 
		   │ %{selected|abilityName}
		   │ %{target|abilityName}
		   │ %{characterName|abilityName}
		   └─────────────────────────────*/
		
		_ability: $ => choice(
			$.ability,
			alias($._ability_empty, $.invalid),	//%{}
			alias("%{", $.invalid),
		),
		ability: $ => seq(
			$.__ability_start,
			"{",
			$._ability_content,
			"}",
		),
		_ability_empty: $ => seq( $.__ability_start, "{}" ),
		_ability_content: $ => choice(
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
		  └┬─────────────────────────────*/
		 /*│ This grammar will just pick out the hash characters that could
		   │   refer to a macro. It's impossible to know whether they actually
		   │   do, since we can't check a name against the list of defined
		   │   macros.
		   │ 
		   │ For example, "&#124;_" could refer to:
		   │ • an ampersand followed by a macro named "124;_".
		   │ • a HTML entity of a pipe, followed by an underscore.
		   │ If the macro is defined, Roll20 will go with the first option.
		   │   Otherwise, Roll20 sticks with the second option.
		   │ 
		   │ The macro name:
		   │ • cannot contain spaces, new lines, or  the character sequences
		   │  "@{" and "%{".
		   │ • if inside a roll query, cannot contain pipes or closing curly
		   │   braces.
		   │ • cannot include macros.
		   │ • can include attributes and abilities.
		   │ 
		   │ To call the macro, its name must be followed by either a space or
		   │   a new line, or be at the end of the script.
		   │ 
		   │ #macroName 
		   └─────────────────────────────*/
		
		
		_macro: $ => seq(
			alias($.__macro_start, $.macroHash),
			prec.right(repeat1(choice(
				/[^@% \r\n]+/,
				$._attribute,
				$._ability,
				$.__just_at,
				$.__just_percent,
			))),
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Roll Queries
		  ╚════════════════════════════════════════════════════════════*/
		 
		/*┌──────────────────────────────
		  │ Roll Query
		  └──────────────────────────────*/
		
		_rollQuery: $ => choice(
			$.rollQuery,
			alias($._rollQuery_empty, $.invalid),	//?{}
			alias("?{", $.invalid),
		),
		rollQuery: $ => choice(
			seq(
				$.__rollQuery_start,	//?
				"{",
				$._rollQuery_content,
				$.__rollQuery_end,	//}
			),
		),
		_rollQuery_empty: $ => seq( $.__rollQuery_start, $.__rollQuery_end ),	//?{}
		_rollQuery_content: $ => prec.right(choice(
			$.prompt,
			seq(
				optional($.prompt),
				choice(
					seq(
						$.__rollQuery_pipe_hasDefault,
						optional($.defaultValue),
					),
					seq(
						$.__rollQuery_pipe_hasOptions,
						optional($.option),
						$.__pipe,
						optional($.option),
						repeat(
							seq(
								$.__pipe,
								optional($.option),
							),
						),
					),
				),
			),
		)),
		
		prompt: $ => $._propertyName,
		
		defaultValue: $ => repeat1(choice(
			/[^@%&}|]+|[@%]/,
			$._attribute,
			$._ability,
			//alias($._escapedHtmlEntity, $.htmlEntity),
			$.__just_ampersand,
		)),
		
		option: $ => choice(
			$.optionName,
			prec.right(seq(
				optional($.optionName),
				$.__comma,
				optional($.optionValue),
			)),
		),
		optionName: $ => name(prec.right(choice(
			/[^@%#&}|,\r\n]+/,
			$._attribute,
			$._ability,
			alias($.__macro_start, $.macroHash),
			//$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			$.__just_ampersand,
		)))($),
		optionValue: $ => name(prec.right(choice(
			/[^@%#&}|,?\r\n]+/,
			$._attribute,
			$._ability,
			alias($.__macro_start, $.macroHash),
			//$.htmlEntity,
			$._rollQuery,
			//$.property,
			//$.button,
			$.__just_at,
			$.__just_percent,
			$.__just_ampersand,
			$.__just_questionmark,
		)))($),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Formulas
		  ╚════════════════════════════════════════════════════════════*/
		 
		/*┌──────────────────────────────
		  │ Formula
		  └┬─────────────────────────────*/
		 /*│ A formula consisting of only whitespace and/or labels is invalid. 
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
				choice(
					$._expression_first_pair,
					$._expression_invalid,
				),
			),
		)),
		_expression_next: $ => prec.right(choice(
			seq(
				$._element_next,
				optional($._labels_and_wsp),
			),
			$._expression_next_pair,
			$._expression_invalid,
		)),
		_expression_invalid: $ => prec.right(choice(
			seq(
				$._element_invalid,
				optional($._labels_and_wsp),
			),
			$._expression_invalid_pair,
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
					$._expression_invalid,
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
					$._expression_invalid,
				),
			),
		),
		_expression_invalid_pair: $ => seq(
			$._element_invalid,
			choice(
				seq(
					optional($._labels_and_wsp),
					$._operator,
					optional($._labels_and_wsp),
					$._expression_next,
				),
				seq(
					$._labels_and_wsp,
					$._expression_invalid,
				),
			),
		),
		
		_element_first: $ => prec.right(2, choice(
			$._element_parenthesized,
			$._element_groupRoll,
			$._element_diceRoll,
			$._element_tableRoll,
			$._element_number_unsigned,
			$._element_number_signed,
			$._inlineRoll_signed,
			//TODO: query
			seq(
				$._placeholders,
				optional($._macro),
			),
			$._macro,
		)),
		_element_next: $ => prec.right(1, choice(
			$._element_parenthesized,
			$._element_groupRoll,
			$._element_diceRoll,
			$._element_tableRoll,
			$._element_number_unsigned,
			$._inlineRoll,
			//TODO: query
			seq(
				$._placeholders,
				optional($._macro),
			),
			$._macro,
		)),
		
		_element_invalid: $ => seq(
			optional($._placeholders),
			alias($._element_invalid_2, $.invalid),
			optional($._macro),
		),
		_element_invalid_2: $ => choice(
			seq(
				$._element_invalid_begin,
				optional($._element_invalid_remainder),
			),
			$._element_invalid_number,
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
		_element_invalid_remainder: $ => prec.right(seq(
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
		)),
		
		
		/*┌──────────────────────────────
		  │ Operator
		  └┬─────────────────────────────*/
		 /*│ `+-` and `-+` are evaluated as subtraction.
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
		  └┬─────────────────────────────*/
		 /*│ An inline label:
		   │ • cannot contain new lines or closing square brackets.
		   │ • can include attributes, abilities, and macros.
		   └─────────────────────────────*/
		
		label: $ => seq(
			$.__leftBracket,
			optional(name(choice(
				///[^@%#&\[ \r\n\]]+/,
				/[^@%#\[ \r\n\]]+/,
				$._attribute,
				$._ability,
				//$.htmlEntity,
				$.__just_at,
				$.__just_percent,
				//$.__just_ampersand,
			))($)),
			$.__rightBracket,
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
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ • Numbers can be injected with attributes and abilities.
		   │ • Inline rolls can be used in place of numbers.
		   └───────────────────────────────────────────────────────────*/
		
		_element_number_signed: $ => prec(2, seq(
			$._sign,
			choice(
				seq(
					alias($._integer_etc, $.number),
					optional(alias($._number_invalid_integer_remainder, $.invalid)),
				),
				seq(
					alias($._number_signed_decimal, $.number),
					optional(alias($._number_invalid_decimal_remainder, $.invalid)),
				),
			),
		)),
		_number_signed_decimal: $ => prec.right(1, seq(
			$._integer_etc,
			$._number_fraction,
		)),
		
		
		_element_number_unsigned: $ => prec(1, choice(
			seq(
				alias($._integer_etc, $.number),
				optional(alias($._number_invalid_integer_remainder, $.invalid)),
			),
			seq(
				alias($._number_unsigned_decimal, $.number),
				optional(alias($._number_invalid_decimal_remainder, $.invalid)),
			),
		)),
		_number_unsigned_decimal: $ => prec.right(1, seq(
			optional($._integer_etc),
			$._number_fraction,
		)),
		
		
		_element_invalid_number: $ => seq(
			choice(
				$.__decimal,
				seq(
					$._sign,
					$.__decimal,
					repeat(choice(
						/[^@%#\[({*/+\-\s})\]]/,
						$._placeholders,
						$._inlineRoll,
					)),
				),
				seq(
					$.__decimal,
					/[^@%#\[({*/+\-\s})\]\d]/,
					repeat(choice(
						/[^@%#\[({*/+\-\s})\]]/,
						$._placeholders,
						$._inlineRoll,
					)),
				),
			),
		),
		_number_invalid_integer_remainder: $ => choice(
			$.__decimal,
			seq(
				$.__decimal,
				/[^@%#\[({*/+\-\s})\]\d]/,
				repeat(choice(
					/[^@%#\[({*/+\-\s})\]]/,
					$._placeholders,
					$._inlineRoll,
				)),
			),
			seq(
				/[^@%#\[({*/+\-\s})\]\d.]/,
				repeat(choice(
					/[^@%#\[({*/+\-\s})\]]/,
					$._placeholders,
					$._inlineRoll,
				)),
			),
		),
		_number_invalid_decimal_remainder: $ => seq(
			/[^@%#\[({*/+\-\s})\]\d]/,
			repeat(choice(
				/[^@%#\[({*/+\-\s})\]]/,
				$._placeholders,
				$._inlineRoll,
			)),
		),
		
		
		_sign: $ => alias(/[+-]/, $.operator),
		
		_integer_etc: $ => choice(
			seq(
				$.__integer,
				repeat(choice(
					$.__integer,
					$._placeholders,
					$._inlineRoll,
				)),
			),
			seq(
				repeat1(choice(
					$._placeholders,
					$._inlineRoll,
				)),
				$.__integer,
				repeat(choice(
					$.__integer,
					$._placeholders,
					$._inlineRoll,
				)),
			),
		),
		
		_number_fraction: $ => seq( $.__decimal, $._integer_etc),
		
		
		/*┌──────────────────────────────
		  │ Inline Roll
		  └┬─────────────────────────────*/
		 /*│ An inline roll may be used as a root element or in place of a
		   │   number, and contains its own formula. When evaluated, it is
		   │   reduced to a number.
		   └─────────────────────────────*/
		
		_element_inlineRoll: $ => seq(
			optional($._placeholders),
			$._inlineRoll,
			optional($._placeholders),
			optional(alias($._element_invalid_remainder, $.invalid)),
			optional($._macro),
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
		_inlineRoll_signed: $ => prec(1, seq(
			optional($._sign),
			$._inlineRoll,
		)),
		
		
		/*┌──────────────────────────────
		  │ Parenthesized Formula / Math Function
		  └┬─────────────────────────────*/
		 /*│ A nested formula, wrapped in parentheses, or a math function with a
		   │   formula as its argument.
		   └─────────────────────────────*/
		
		_element_parenthesized: $ => seq(
			optional($._placeholders),
			$._parenthesized,
			optional($._placeholders),
			optional(alias($._element_invalid_remainder, $.invalid)),
			optional($._macro),
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
		  └┬─────────────────────────────*/
		 /*│ Roll modifiers can be injected with attributes and abilities.
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
			optional($._macro),
		),
		
		_groupRoll: $ => choice(
			$.groupRoll,
			alias($._groupRoll_invalid, $.invalid),
		),
		groupRoll: $ => prec.right(seq(
			$.__leftBrace,
			optional(alias($._groupRoll_invalid_commas, $.invalid)),
			$.formula,
			repeat(seq(
				$.__comma,
				optional(alias($._groupRoll_invalid_commas, $.invalid)),
				$.formula,
			)),
			optional(alias($._groupRoll_invalid_commas, $.invalid)),
			$.__rightBrace,
			optional(alias($._groupRoll_modifiers, $.modifiers)),
			optional(alias($._element_invalid_remainder, $.invalid)),
		)),
		_groupRoll_modifiers: $ => repeat1(choice(
				$._shared_modifier,
				$._placeholders,
				/[dfhklDFHKL<=>\d]/,	//potentially valid
		)),
		_groupRoll_invalid: $ => seq(
			$.__leftBrace,
			/\s*(,\s*)*/,
			$.__rightBrace,
			optional(alias($._groupRoll_modifiers, $.modifiers)),
			optional($._groupRoll_invalid_remainder),
		),
		_groupRoll_invalid_commas: $ => prec.right(repeat1(prec.right(choice($._labels_and_wsp, $.__comma)))),
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
			optional($._macro),
		),
		
		diceRoll: $ => prec.right(1, seq(
			//count: number of dice (optional)
			optional(alias($._diceRoll_count, $.count)),
			//keyword (the letter 'd')
			$.__diceRoll_start,
			//sides: number of sides per die
			alias($._diceRoll_sides, $.sides),
			//modifiers (optional)
			optional(alias($._diceRoll_modifiers, $.modifiers)),
		)),
		_diceRoll_count: $ => repeat1(choice(
			alias($.__integer, $.number),
			$._placeholders,
			$._inlineRoll,
		)),
		_diceRoll_sides: $ => choice(
			alias(/\d+/, $.number),
			alias(/[fF]/, $.fate),
			$._attribute,
			$._ability,
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
			optional($._macro),
		),
		
		tableRoll: $ => prec.right(seq(
			//count: number of "dice" (optional)
			optional(alias($._diceRoll_count, $.count)),
			//keyword (the letter 't')
			$.__tableRoll_start,
			$.__leftBracket,
			//table name
			$.tableName,
			$.__rightBracket,
		)),
		tableName: $ => name(choice(
			///[^@%#& \r\n\]]+/,
			/[^@%# \r\n\]]+/,
			$._attribute,
			$._ability,
			prec(1, "@{"),
			prec(1, "%{"),
			$.__just_at,
			$.__just_percent,
			//$.__just_ampersand,
		))($),
		
		
	},
});
