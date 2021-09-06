
module.exports = grammar({
	name: 'roll20_script',
	
	externals: $ => [
		$.__integer,
		
		$.__attribute_start,			// @
		
		$.__ability_start,				// %
		
		$.__macro_safe_start,				// #
		$.__macro_unsafe_start,				// #
		
		$.__html_entity,				// HTML entity
		
		$.__rollQuery_start,			// ?{  or equivalent HTML entity(ies)
		$.__rollQuery_pipe_hasDefault,	// |  or equivalent HTML entity
		$.__rollQuery_pipe_hasOptions,	// |  or equivalent HTML entity
		$.__rollQuery_end,				// }  or equivalent HTML entity
		
		$.__inlineRoll_start,
		$.__inlineRoll_end,
		
		//$.__parenthesized_start,
		//$.__parenthesized_end,
		
		//$.__groupRoll_start,
		//$.__groupRoll_end,
		
		$.__diceRoll_start,				// d or D  or equivalent HTML entity
		
		$.__tableRoll_start,			// t or T  or equivalent HTML entity
		
		
		$.__just_at,					// @
		$.__just_percent,				// %
		$.__just_hash,					// #
		$.__just_ampersand,				// &
		$.__just_d,						// d or D
		$.__just_t,						// t or T
		$.__just_questionmark,			// ?
		$.__just_leftBrace,				// {
		$.__just_pipe,					// |
		$.__just_comma,					// ,
		$.__just_rightBrace,			// }
		$.__just_leftBracket,			// [
		$.__just_rightBracket,			// ]
		$.__just_leftParen,				// (
		$.__just_rightParen,			// )
		
		$.__decimal_point,
		$.__just_period,
		
		$.__just_slash,
		$.__just_asterisk,
		$.__just_plus,
		$.__just_dash,
		$.__operator_positive,
		$.__operator_negative,
		
		$.__EOF,
	],
	
	extras: $ => [
		//(manually handle whitespace)
	],
	
	conflicts: $ => [],
	
	inline: $ => [],
	
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
				//$._placeholders,
				$.attribute,
				$.ability,
				$._root_macro_and_wsp,
				$.rollQuery,
				$.inlineRoll,
				//TODO:
				//template
				//property
				//ability command button
				//tracker
				$.htmlEntity,
				$._stringNL,
			),
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Strings and Characters
		  ╚════════════════════════════════════════════════════════════*/
		
		_stringNL: $ => prec.right(repeat1(choice( /[^#]|\r?\n/, $.__just_hash ))),
		
		_wsp_inline: $ => /\s+/,
		
		htmlEntity: $ => $.__html_entity,
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Numbers
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ Numbers are combined with attributes, abilities, and inline rolls.
		   └───────────────────────────────────────────────────────────*/
		
		_number_signed: $ => seq(
			optional(alias(choice(
				$.__operator_positive,
				$.__operator_negative,
			), $.operator)),
			$._number_signable,
		),
		_number_signed_IR_PH: $ => seq(
			optional(alias(choice(
				$.__operator_positive,
				$.__operator_negative,
			), $.operator)),
			$._number_signable_IR_PH,
		),
		
		_number: $ => choice(
			$._number_signable,
			$._number_fraction,
		),
		_number_IR_PH: $ => choice(
			$._number_signable_IR_PH,
			$._number_fraction_IR_PH,
		),
		
		_number_signable: $ => prec.right(seq(
			$.__integer,
			optional($._number_fraction),
		)),
		_number_signable_IR_PH: $ => prec.right(seq(
			prec.right(repeat1(choice(
				alias($.__integer, $.number),
				$.inlineRoll,
				$._placeholders,
			))),
			optional($._number_fraction_IR_PH),
		)),
		
		_number_fraction: $ => seq(
			alias($.__decimal_point, $.decimalPoint),
			$.__integer,
		),
		_number_fraction_IR_PH: $ => choice(
			seq(
				alias(seq(
					alias($.__decimal_point, $.decimalPoint),
					$.__integer,
				), $.number),
				optional(seq(
					choice(
						$.inlineRoll,
						$._placeholders,
					),
					repeat(choice(
						$.__integer,
						$.inlineRoll,
						$._placeholders,
					)),
				)),
			),
			seq(
				alias($.__decimal_point, $.decimalPoint),
				optional(seq(
					choice(
						$.inlineRoll,
						$._placeholders,
					),
					repeat(choice(
						$.__integer,
						$.inlineRoll,
						$._placeholders,
					)),
				)),
			),
		),
		
		_number_integer: $ => prec.right(repeat1(
			prec.right(1, choice(
				$.__integer,
				$._placeholders,
				$.inlineRoll,
			))
		)),
		_number_integer_IR_PH: $ => prec.right(repeat1(choice(
			alias($.__integer, $.number),
			$.inlineRoll,
			$._placeholders,
		))),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Attributes and Abilities (here, referred to as "placeholders")
		  ╚════════════════════════════════════════════════════════════*/
		
		/*┌──────────────────────────────
		  │ helper rules
		  └┬─────────────────────────────*/
		 /*│ Note that the website sometimes allows special characters in
		   │   names, even though it would prevent the property from being
		   │   accessed from within a script.
		   └─────────────────────────────*/
		
		_propertyName: $ => repeat1(choice(
			/[^@%#&}|\r\n]+/,
			$._macro_and_wsp,
			$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			$.__just_hash,
			$.__just_ampersand,
		)),
		_selector: $ => choice(
			alias("target", $.token),
			alias("selected", $.token),
			alias($._propertyName, $.character),
		),
		
		
		/*┌──────────────────────────────
		  │ Placeholders
		  └──────────────────────────────*/
		
		_placeholders: $ => prec.right(repeat1(
			prec(1, choice(
				$.attribute,
				$.ability,
			))
		)),
		
		
		/*┌──────────────────────────────
		  │ Attributes
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
		   │ @{name}
		   │ @{selected|name}
		   │ @{selected|name|max}
		   │ @{target|name}
		   │ @{target|name|max}
		   │ @{character|name}
		   │ @{character|name|max}
		   └─────────────────────────────*/
		
		attribute: $ => prec(2, seq(
			$._$attributeLeft,
			choice(
				alias($._propertyName, $.name),
				seq(
					$._selector,
					$._$pipe,
					choice(
						alias($._propertyName, $.name),
						seq(
							alias($._propertyName, $.name),
							$._$pipe,
							alias("max", $.keyword),
						),
						alias($._propertyName, $.name),
					),
				),
				$._selector,
			),
			$._$braceRight,
		)),
		
		
		/*┌──────────────────────────────
		  │ Abilities
		  └┬─────────────────────────────*/
		 /*│ For an ability, the character name and/or ability name:
		   │ • can contain spaces, tabs, and hash characters.
		   │ • cannot contain new lines, pipes, closing curly braces, or the
		   │   character sequences "@{" and "%{".
		   │ • cannot include attributes, abilities, or macros.
		   │ 
		   │ %{selected|name}
		   │ %{target|name}
		   │ %{character|name}
		   └─────────────────────────────*/
		
		ability: $ => prec(2, seq(
			$._$abilityLeft,
			choice(
				alias($._propertyName, $.name),
				seq(
					$._selector,
					$._$pipe,
					alias($._propertyName, $.name),
				),
				$._selector,
			),
			$._$braceRight,
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Macros
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ This grammar will sometimes just pick out the hash character that
		   │   could refer to a macro (tagged as $.macroHash). It's impossible
		   │   to know whether it actually does, since we can't check a name
		   │   against the list of defined macros.
		   │ 
		   │ For example, "&#124;_" could refer to either:
		   │ • an ampersand followed by a macro named "124;_".
		   │ • an HTML entity of a pipe, followed by an underscore.
		   │ If the macro is defined, Roll20 will go with the first option.
		   │   Otherwise, Roll20 sticks with the second option.
		   │ 
		   │ The macro name:
		   │ • cannot contain spaces, new lines, or the character sequence
		   │  "@{" or "%{".
		   │ • if inside a roll query, cannot contain pipes or closing curly
		   │   braces.
		   │ • cannot include macros (additional hashes are part of the name).
		   │ • can include attributes and abilities.
		   │ 
		   │ To call the macro, its name must be followed by either a space or
		   │   a new line, or be at the end of the script.
		   │ 
		   │ #macroName 
		   └─────────────────────────────*/
		
		_root_macro_and_wsp: $ => prec.right(1, choice(
			seq(
				alias($._root_macro_safe, $.macro),
				choice(
					/ |\r?\n/,
					$.__EOF,
				),
			),
			seq(
				$._$macroHash_unsafe,
				$._root_macro_name_safe,
			),
		)),
		_root_macro_safe: $ => seq(
			$._$macroHash_safe,
			alias($._root_macro_name_safe, $.name),
		),
		_root_macro_name_safe: $ => prec.right(choice(
			$.__just_leftBracket,
			seq(
				optional($.__just_leftBracket),
				repeat1(
					prec.right(seq(
						prec.right(repeat1(choice(
							/[^@%\[ \r\n]/,
							$.attribute,
							$.ability,
							$.__just_at,
							$.__just_percent,
						))),
						optional($.__just_leftBracket),
					)),
				),
			),
		)),
		
		_macro_and_wsp: $ => prec.right(1, choice(
			seq(
				alias($._macro_safe, $.macro),
				choice(
					/ |\r?\n/,
					$.__EOF,
				),
			),
			seq(
				$._$macroHash_unsafe,
				$._macro_name_safe,
			),
		)),
		_macro_safe: $ => seq(
			$._$macroHash_safe,
			alias($._macro_name_safe, $.name),
		),
		_macro_name_safe: $ => prec.right(repeat1(choice(
			/[^@%\[({/*+\-})\] \r\n]+/,
			$.attribute,
			$.ability,
			$.__just_at,
			$.__just_percent,
		))),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Roll Queries
		  ╚════════════════════════════════════════════════════════════*/
		
		rollQuery: $ => seq(
			$.__rollQuery_start,	//?{
			$._rollQuery_content,
			$.__rollQuery_end,	//}
		),
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
						$.__just_pipe,
						optional($.option),
						repeat(
							seq(
								$.__just_pipe,
								optional($.option),
							),
						),
					),
				),
			),
		)),
		
		prompt: $ => repeat1(choice(
			/[^@%#&}|]+/,	//new lines are allowed, but replaced with a space
			$.attribute,
			$.ability,
			$._macro_and_wsp,
			$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			$.__just_hash,
			$.__just_ampersand,
		)),
		
		defaultValue: $ => repeat1(choice(
			/[^@%#&}|]+/,	//new lines are allowed, but removed
			$.attribute,
			$.ability,
			$._macro_and_wsp,
			$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			$.__just_hash,
			$.__just_ampersand,
		)),
		
		option: $ => choice(
			$.optionName,
			prec.right(seq(
				optional($.optionName),
				$._$comma,
				optional($.optionValue),
			)),
		),
		optionName: $ => prec.right(1, repeat1(choice(
			/[^@%#&}|,]+/,	//new lines are allowed, but replaced with a space
			$.attribute,
			$.ability,
			$._macro_and_wsp,
			$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			$.__just_hash,
			$.__just_ampersand,
		))),
		optionValue: $ => prec.right(1, repeat1(choice(
			/[^@%#&}|,?]+/,	//new lines are allowed
			$.attribute,
			$.ability,
			$._macro_and_wsp,
			$.htmlEntity,
			$.rollQuery,
			//TODO:
			//$.property,
			//$.button,
			$.__just_at,
			$.__just_percent,
			$.__just_hash,
			$.__just_ampersand,
			$.__just_questionmark,
		))),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Inline Rolls
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ An inline roll may be used as a root element or in place of a
		   │   number, and contains its own formula. When evaluated, it is
		   │   reduced to a number.
		   └─────────────────────────────*/
		
		inlineRoll: $ => seq(
			$._$inlineRollStart,
			$.formula,
			$._$inlineRollEnd,
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Formulas
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ Used within an inline roll and within nested elements (i.e., within
		   │   nested inline rolls, parentheses, math functions, or group rolls).
		   │
		   │ A formula consisting of only whitespace and/or labels is invalid. 
		   │ 
		   │ Labels can only be the first items in a formula if the following
		   │   item is a dice roll or table roll (or attribute/ability/macro
		   │   that evaluates to one of those).
		   │   This implementation does not detect that.
		   └─────────────────────────────*/
		
		formula: $ => seq(
			optional($._labels_or_wsp),
			alias($._term_first, $.term),
			repeat(seq(
				optional($._labels_or_wsp),
				$._operator,
				optional($._labels_or_wsp),
				alias($._term, $.term),
			)),
			optional($._labels_or_wsp),
		),
		
		_term_first: $ => prec.right(choice(
			prec(1, seq(
				prec.right(choice(
					$._number_signed_IR_PH,
					$._number_fraction_IR_PH,
					$.diceRoll,
					$.groupRoll,
					$.rollQuery,
					$.parenthesized,
					$.function,
					$.tableRoll,
				)),
				optional($._macro_and_wsp),
			)),
			prec(1, $._macro_and_wsp),
		)),
		
		_term: $ => choice(
			prec(1, seq(
				prec.right(choice(
					$._number_IR_PH,	//numbers, attributes, abilities, and inline rolls
					$.diceRoll,
					$.groupRoll,
					seq(
						choice(
							$.rollQuery,
							$.parenthesized,
							$.function,
							$.tableRoll,
						),
						optional($._placeholders),
					),
				)),
				optional($._macro_and_wsp),
			)),
			prec(1, $._macro_and_wsp),
		),
		
		
		/*┌──────────────────────────────
		  │ Operator
		  └┬─────────────────────────────*/
		 /*│ `+-` and `-+` are evaluated as subtraction.
		   │ 
		   │ The only place a unary negative/positive operator can be is as a
		   │   prefix of a number, attribute, ability, or inline roll that is
		   │   the first element in a formula.
		   └─────────────────────────────*/
		
		_operator: $ => prec.right(choice(
			$._operator_summation,
			$._operator_multiplication,
			seq(
				$._operator_multiplication,
				$._operator_summation,
			),
		)),
		
		_operator_multiplication: $ => prec.right(1, seq(
			alias(choice(
				/\/|\*\*?/,
				$.__just_percent,
			), $.operator),
			optional($._labels_or_wsp),
		)),
		_operator_summation: $ => prec.right(choice(
			$._operator_summation_plus,
			$._operator_summation_minus,
		)),
		_operator_summation_plus: $ => prec.right(choice(
			seq(
				alias("+", $.operator),
				optional($._labels_or_wsp),
			),
			seq(
				alias(seq(
					prec.right(repeat1(seq(
						"+",
						optional($._labels_or_wsp),
						"-",
						optional($._labels_or_wsp),
					))),
					optional("+"),
				), $.operator),
				optional($._labels_or_wsp),
			),
		)),
		_operator_summation_minus: $ => prec.right(choice(
			seq(
				alias("-", $.operator),
				optional($._labels_or_wsp),
			),
			seq(
				alias(seq(
					prec.right(repeat1(seq(
						"-",
						optional($._labels_or_wsp),
						"+",
						optional($._labels_or_wsp),
					))),
					optional("-"),
				), $.operator),
				optional($._labels_or_wsp),
			),
		)),
		
		
		/*┌──────────────────────────────
		  │ Inline Label
		  └┬─────────────────────────────*/
		 /*│ An inline label:
		   │ • cannot contain new lines or closing square brackets.
		   │ • can include attributes, abilities, and macros.
		   └─────────────────────────────*/
		
		label: $ => seq(
			$._$bracketLeft,
			optional(prec.right(repeat1(
				prec(1, choice(
					/[^@%#&\]\r\n]+/,	//new lines are not allowed
					$.attribute,
					$.ability,
					$._macro_and_wsp,
					$.htmlEntity,
					$.__just_at,
					$.__just_percent,
					$.__just_hash,
					$.__just_ampersand,
				))
			))),
			$._$bracketRight,
		),
		
		_labels_or_wsp: $ => prec.right(1, choice(
			$._wsp_inline,
			$._labels_with_wsp,
		)),
		_labels_with_wsp: $ => prec.right(seq(
			optional($._wsp_inline),
			repeat1(seq(
				$.label,
				optional($._wsp_inline),
			)),
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Parenthesized Formulas and Math Functions
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ A nested formula, wrapped in parentheses, or a math function with a
		   │   formula as its argument.
		   └─────────────────────────────*/
		
		/*┌──────────────────────────────
		  │ Parenthesized Formulas
		  └──────────────────────────────*/
		
		parenthesized: $ => seq(
			$._$parenLeft,
			$.formula,
			$._$parenRight,
		),
		
		
		/*┌──────────────────────────────
		  │ Math Functions
		  └──────────────────────────────*/
		
		function: $ => seq(
			$._function_start,
			$.formula,
			$._$parenRight,
		),
		
		_function_start: $ => seq(
			alias(/abs|ceil|floor|round/, $.name),
			$._$parenLeft,
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Rolls
		  ╚════════════════════════════════════════════════════════════*/
		
		/*┌──────────────────────────────
		  │ Roll Modifiers
		  └┬─────────────────────────────*/
		 /*│ Roll modifiers can be injected with attributes, abilities, and
		   │   inline rolls. This script does not parse the modifiers.
		   └─────────────────────────────*/
		
		_diceRoll_modifiers: $ => repeat1(prec.right(choice(
			alias($._number_integer, $.number),
			/[aAcCdDfFhHkKlLmMoOpPrRsStT<=>!]+/,
		))),
		
		_groupRoll_modifiers: $ => repeat1(prec.right(choice(
			alias($._number_integer, $.number),
			/[dDfFhHkKlL<=>]+/,
		))),
		
		
		/*┌──────────────────────────────
		  │ Dice Roll
		  └──────────────────────────────*/
		
		diceRoll: $ => prec.right(1, seq(
			//number of dice to roll
			optional(alias($._number_integer_IR_PH, $.count)),
			//keyword (the letter 'd')
			$._$diceRoll,
			//sides per die
			choice(
				alias($._number_integer_IR_PH, $.sides),
				alias(/[fF]/, $.fate),
			),
			//modifiers
			optional(alias($._diceRoll_modifiers, $.modifiers)),
		)),
		
		
		/*┌──────────────────────────────
		  │ Table Roll
		  └──────────────────────────────*/
		
		tableRoll: $ => prec.right(seq(
			//number of "dice"
			optional(alias($._number_integer_IR_PH, $.count)),
			//keyword ("t[")
			$._$tableRoll,
			//table name
			$.tableName,
			$._$bracketRight,
		)),
		tableName: $ => prec.right(repeat1(choice(
			/[^@%#\]\r\n]+/,
			$.attribute,
			$.ability,
			$._macro_and_wsp,
			//TODO: make sure these aren't needed:
			//prec(1, "@{"),
			//prec(1, "%{"),
			$.__just_at,
			$.__just_percent,
			$.__just_hash,
//		))($),
		))),
		
		
		/*┌──────────────────────────────
		  │ Group Roll
		  └──────────────────────────────*/
		
		groupRoll: $ => prec.right(seq(
			$._$braceLeft,
			$._groupRoll_content,
			$._$braceRight,
			optional(alias($._groupRoll_modifiers, $.modifiers)),
		)),
		_groupRoll_content: $ => seq(
			$.formula,
			repeat(seq(
				$.__just_comma,
				$.formula,
			)),
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Delimiters
		  ╚════════════════════════════════════════════════════════════*/
		
		_$attributeLeft: $ => alias($._$_attributeLeft, $.delimiter),
		_$_attributeLeft: $ => seq( $.__attribute_start, $.__just_leftBrace ),
		
		_$abilityLeft: $ => alias($._$_abilityLeft, $.delimiter),
		_$_abilityLeft: $ => seq( $.__ability_start, $.__just_leftBrace ),
		
		_$macroHash_safe: $ => alias($.__macro_safe_start, $.delimiter),
		_$macroHash_unsafe: $ => alias($.__macro_unsafe_start, $.macroHash),
		
		
		_$inlineRollStart: $ => alias($.__inlineRoll_start, $.delimiter),
		_$inlineRollEnd: $ => alias($.__inlineRoll_end, $.delimiter),
		
		
		_$rollQueryLeft: $ => alias($.__rollQuery_start, $.delimiter),
		_$rollQueryPipeDefault: $ => alias($.__rollQuery_pipe_hasDefault, $.delimiter),
		_$rollQueryPipeFirstOption: $ => alias($.__rollQuery_pipe_hasOptions, $.delimiter),
		_$comma: $ => alias($.__just_comma, $.delimiter),
		_$rollQueryRight: $ => alias($.__rollQuery_end, $.delimiter),
		
		
		_$diceRoll: $ => alias($.__diceRoll_start, $.delimiter),
		
		_$tableRoll: $ => alias($._$_tableRoll, $.delimiter),
		_$_tableRoll: $ => seq( $.__tableRoll_start, $.__just_leftBracket ),
		
		
		_$pipe: $ => alias($.__just_pipe, $.delimiter),
		_$braceLeft: $ => alias($.__just_leftBrace, $.delimiter),
		_$braceRight: $ => alias($.__just_rightBrace, $.delimiter),
		_$bracketLeft: $ => alias($.__just_leftBracket, $.delimiter),
		_$bracketRight: $ => alias($.__just_rightBracket, $.delimiter),
		_$parenLeft: $ => prec.left(alias($.__just_leftParen, $.delimiter)),
		_$parenRight: $ => alias($.__just_rightParen, $.delimiter),
		
		
	},
});
