
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
		$.__integer,
		
		$.__attribute_start,			// @{
		
		$.__ability_start,				// %{
		
		$.__macro_start,				// #
		
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
		$.__just_leftParent,			// (
		$.__just_rightParen,			// )
		$.__just_period,				// .
		
		$.__EOF,
	],
	
	extras: $ => [
		//(manually handle whitespace)
	],
	
	conflicts: $ => [],
	
	inline: $ => [
		$.formula,
		$.macro,
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
				$.macro,
				$.rollQuery,
				$._inlineRoll,
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
		
		_stringNL: $ => chainOf(choice( /[^#]|\r?\n/, $.__just_hash )),
		
		_wsp_inline: $ => /\s+/,
		
		htmlEntity: $ => $.__html_entity,
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Numbers
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ Numbers are combined with attributes, abilities, and inline rolls.
		   └───────────────────────────────────────────────────────────*/
		
		_number_first: $ => choice(
			seq(
				optional($._operator_sign_first),
				$._number_signable,
			),
			$._number_fraction,
		),
		_number: $ => choice(
			$._number_signable,
			$._number_fraction,
		),
		
		_number_signable: $ => seq(
			$._number_integer,
			optional($._number_fraction),
		),
		_number_fraction: $ => seq(
			$.__just_period,
			$._number_integer,
		),
		_number_integer: $ => repeat1(choice(
			$.__integer,
			$._placeholders,
			$._inlineRoll,
		)),
		
		_number_invalid: $ => seq(
			$._operator_sign_first,
			$._number_fraction,
		),
		
		
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
		
		_propertyName: $ => name(choice(
			/[^@%#&}|\r\n]+/,
			$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			$.__just_hash,
			$.__just_ampersand,
		))($),
		_selector: $ => choice(
			alias(/target|selected/, $.token),
			alias($._propertyName, $.characterName),
		),
		
		
		/*┌──────────────────────────────
		  │ Placeholders
		  └──────────────────────────────*/
		
		_placeholders: $ => prec.right(repeat1(choice(
			$.attribute,
			$.ability,
			alias($._attribute_empty, $.invalid),
			alias($._ability_empty, $.invalid),
		))),
		
		
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
		   │ @{attributeName}
		   │ @{selected|attributeName}
		   │ @{selected|attributeName|max}
		   │ @{target|attributeName}
		   │ @{target|attributeName|max}
		   │ @{characterName|attributeName}
		   │ @{characterName|attributeName|max}
		   └─────────────────────────────*/
		
		attribute: $ => prec(2, seq(
			$._$attributeLeft,
			$._attribute_content,
			$._$braceRight,
		)),
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
		
		_attribute_empty: $ => seq( $._$attributeLeft, $._$braceRight ),
		_attribute_invalid: $ => "@{",
		
		
		/*┌──────────────────────────────
		  │ Abilities
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
		
		ability: $ => prec(2, seq(
			$._$abilityLeft,
			$._ability_content,
			$._$braceRight,
		)),
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
		
		_ability_empty: $ => seq( $._$abilityLeft, $._$braceRight ),
		_ability_invalid: $ => "%{",
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Macros
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ This grammar will just pick out the hash characters that could
		   │   refer to a macro. It's impossible to know whether they actually
		   │   do, since we can't check a name against the list of defined
		   │   macros.
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
		   │ • cannot include macros (hashes would be part of the macro name).
		   │ • can include attributes and abilities.
		   │ 
		   │ To call the macro, its name must be followed by either a space or
		   │   a new line, or be at the end of the script.
		   │ 
		   │ #macroName 
		   └─────────────────────────────*/
		
		_macro_and_wsp: $ => seq(
			$.macro,
			choice(
				/ |\r?\n/,
				$.__EOF,
			),
		),
		macro: $ => seq(
			alias($.__macro_start, $.macroHash),
			$._macro_name,
		),
		_macro_name: $ => prec.right(repeat1(choice(
			/[^@% \r\n]+/,
			$.attribute,
			$.ability,
			$.__just_at,
			$.__just_percent,
		))),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Roll Queries
		  ╚════════════════════════════════════════════════════════════*/
		 
		rollQuery: $ => choice(
			seq(
				$.__rollQuery_start,	//?{
				$._rollQuery_content,
				$.__rollQuery_end,	//}
			),
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
		
		_rollQuery_empty: $ => seq( $.__rollQuery_start, $.__rollQuery_end ),	//?{}
		_rollQuery_invalid: $ => choice( $._rollQuery_empty, "?{" ),
		
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
		optionName: $ => name(prec.right(choice(
			/[^@%#&}|,]+/,	//new lines are allowed, but replaced with a space
			$.attribute,
			$.ability,
			$._macro_and_wsp,
			$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			$.__just_hash,
			$.__just_ampersand,
		)))($),
		optionValue: $ => name(prec.right(choice(
			/[^@%#&}|,?]+/,	//new lines are allowed
			$._attribute,
			$._ability,
			$._macro_and_wsp,
			$.htmlEntity,
			$._rollQuery,
			//$.property,
			//$.button,
			$.__just_at,
			$.__just_percent,
			$.__just_hash,
			$.__just_ampersand,
			$.__just_questionmark,
		)))($),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Inline Rolls
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ An inline roll may be used as a root element or in place of a
		   │   number, and contains its own formula. When evaluated, it is
		   │   reduced to a number.
		   └─────────────────────────────*/
		
		_inlineRoll: $ => choice(
			$.inlineRoll,
			alias($._inlineRoll_unclosed, $.inlineRoll),
		),
		_inlineRoll_unclosed: $ => seq(
			alias($._$inlineRollLeft, $.invalid),
			$.formula,
			optional(alias($.__just_rightBracket, $.invalid)),
			$.__EOF,
		),
		
		inlineRoll: $ => seq(
			$._$inlineRollLeft,
			$.formula,
			$._$inlineRollRight,
		),
		
		_inlineRoll_invalid: $ => prec(1, seq(
			$._$inlineRollLeft,
			optional($._wsp_inline),
			choice(
				$._$inlineRollRight,
				seq(
					optional($.__just_rightBracket),
					$.__EOF,
				),
			),
		)),
		
		
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
		
		formula: $ => prec.right(choice(
			alias($._labels_with_wsp, $.invalid),
			seq(
				//A label here will cause an error if it's followed by
				//   anything but a dice roll or table roll. I haven't found a
				//   decent way to check that since placeholders make things so
				//   indeterminate.
				$._labels_or_wsp,
				
				prec.right(choice(
					seq(
						$._number_first,
						optional(alias($._term_remainder_number, $.invalid)),
						optional($.macro),
					),
					$.term,
				)),
				prec.right(repeat(choice(
					seq(
						$._operator,
						$.term,
					),
					seq(
						$._labels_or_wsp,
						alias($.term, $.invalid),
					),
				))),
				optional($._labels_or_wsp),
			),
		)),
		
		term: $ => choice(
			prec(1, seq(
				prec.right(choice(
					seq(
						alias($._number, $.number),	//numbers, attributes, abilities, and inline rolls
						optional(alias($._term_remainder_number_invalid, $.invalid)),
					),
					seq(
						$.diceRoll,
						optional($._term_remainder_diceRoll_indeterminate),
						optional($._placeholders),
						optional(alias($._term_remainder_diceRoll_invalid, $.invalid)),
					),
					seq(
						$._groupRoll,
						optional($._term_remainder_groupRoll_indeterminate),
						optional($._placeholders),
						optional(alias($._term_remainder_groupRoll_invalid, $.invalid)),
					),
					seq(
						choice(
							$.rollQuery,
							$._parenthesized,
							$._function,
							$._tableRoll,
						),
						optional($._placeholders),
						optional(alias($._term_remainder_general_invalid, $.invalid)),
					),
					alias($._term_invalid, $.invalid),
				)),
				optional($.macro),
			)),
			prec(1, $.macro),
			alias($._term_invalid_and_unrecognized, $.invalid),
		),
		
		_term_invalid: $ => choice(
			seq(
				$._number_invalid,
				optional($._term_remainder_number_invalid),
			),
			seq(
				$._groupRoll_invalid,
				optional($._term_remainder_groupRoll_indeterminate),
				repeat(choice(
					$.attribute,
					$.ability,
					$._attribute_empty,
					$._ability_empty,
				)),
				optional($._term_remainder_groupRoll_invalid),
			),
			seq(
				choice(
					$._attribute_invalid,
					$._ability_invalid,
					$._rollQuery_invalid,
					$._inlineRoll_invalid,
					$._parenthesized_invalid,
					$._function_invalid,
					$._tableRoll_invalid,
				),
				repeat(choice(
					$.attribute,
					$.ability,
					$._attribute_empty,
					$._ability_empty,
				)),
				optional($._term_remainder_general_invalid),
			),
		),
		
		_term_remainder_number_invalid: $ => seq(
			choice(
				/[^#\[/*+\-})\]dDtT\s\r\n]/,
				$.__just_d,
				$.__just_t,
				//TODO:
				//just right brace
				//just right paren
				//just right bracket
			),
			optional($._term_remainder_general_invalid_continue),
		),
		_term_remainder_diceRoll_indeterminate: $ => repeat1(choice(
			$._number,
			/[acdfhklmoprstACDFHKLMOPRST<=>!]/,	//potentially valid
		)),
		_term_remainder_diceRoll_invalid: $ => seq(
			choice(
				/[^#\[/*+\-})\]acdfhklmoprstACDFHKLMOPRST<=>!\d\s\r\n]/,
				//TODO:
				//just right brace
				//just right paren
				//just right bracket
			),
			optional($._term_remainder_general_invalid_continue),
		),
		_term_remainder_groupRoll_indeterminate: $ => repeat1(choice(
			$._number,
			/[dfhklDFHKL<=>]/,	//potentially valid
		)),
		_term_remainder_groupRoll_invalid: $ => seq(
			choice(
				/[^#\[/*+\-})\]dfhklDFHKL<=>\d\s\r\n]/,
				//TODO:
				//just right brace
				//just right paren
				//just right bracket
			),
			optional($._term_remainder_general_invalid_continue),
		),
		_term_remainder_general_invalid: $ => seq(
			choice(
				/[^@%#\[/*+\-})\]\s\r\n]/,
				$.__just_at,
				$.__just_percent,
				//TODO:
				//just right brace
				//just right paren
				//just right bracket
			),
			optional($._term_remainder_general_invalid_continue),
		),
		_term_remainder_general_invalid_continue: $ => repeat1(choice(
			/[^@%#\[/*+\-})\]\s\r\n]/,
			$._number,
			$.__just_at,
			$.__just_percent,
			//TODO:
			//just right brace
			//just right paren
			//just right bracket
		)),
		
		_term_invalid_and_unrecognized: $ => /[^[})\]\s\r\n]/,	//TODO: make sure this only matches what's intended
		
		
		/*┌──────────────────────────────
		  │ Operator
		  └┬─────────────────────────────*/
		 /*│ `+-` and `-+` are evaluated as subtraction.
		   │ 
		   │ The only place a unary negative/positive operator can be is as a
		   │   prefix of a number, attribute, ability, or inline roll that is
		   │   the first element in a formula.
		   └─────────────────────────────*/
		
		_operator: $ => seq(
			optional($._labels_or_wsp),
			$._operator_pair,
			optional($._labels_or_wsp),
		),
		
		_operator_sign_first: $ => alias(/\+?-(\+-)*\+?/, $.operator),
		_operator_sign: $ => alias($._operator_pos_neg, $.operator),
		_operator_sum_and_sign: $ => choice(
			seq(
				alias("+", $.operator),
				optional(seq(
					optional($._wsp_inline),
					alias($._operator_minus_plus, $.operator),
				)),
			),
			seq(
				alias("-", $.operator),
				optional(seq(
					optional($._wsp_inline),
					alias($._operator_plus_minus, $.operator),
				)),
			),
		),
		_operator_pair: $ => choice(
			$._operator_sum_and_sign,
			seq(
				alias(/([/*%]|\*\*)/, $.operator),
				optional(seq(
					optional($._wsp_inline),
					$._operator_sign,
				)),
			),
		),
		
		_operator_plus_minus: $ => seq(
			"+",
			repeat(seq(
				optional($._labels_or_wsp),
				"-",
				optional($._labels_or_wsp),
				"+",
			)),
			optional(seq(
				optional($._labels_or_wsp),
				"-",
			)),
		),
		_operator_minus_plus: $ => seq(
			"-",
			repeat(seq(
				optional($._labels_or_wsp),
				"+",
				optional($._labels_or_wsp),
				"-",
			)),
			optional(seq(
				optional($._labels_or_wsp),
				"+",
			)),
		),
		_operator_pos_neg: $ => seq(
			optional(seq(
				"+",
				optional($._labels_or_wsp),
			)),
			"-",
			repeat(seq(
				optional($._labels_or_wsp),
				"+",
				optional($._labels_or_wsp),
				"-",
			)),
			optional(seq(
				optional($._labels_or_wsp),
				"+",
			)),
		),
		
		
		/*┌──────────────────────────────
		  │ Inline Label
		  └┬─────────────────────────────*/
		 /*│ An inline label:
		   │ • cannot contain new lines or closing square brackets.
		   │ • can include attributes, abilities, and macros.
		   └─────────────────────────────*/
		
		label: $ => seq(
			$._$bracketLeft,
			optional(name(choice(
				/[^@%#&\]\r\n]+/,	//new lines are not allowed
				$._attribute,
				$._ability,
				$._macro_and_wsp,
				$.htmlEntity,
				$.__just_at,
				$.__just_percent,
				$.__just_hash,
				$.__just_ampersand,
			))($)),
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
		
		_parenthesized: $ => choice(
			$.parenthesized,
			alias($._parenthesized_unclosed, $.parenthesized),
		),
		_parenthesized_unclosed: $ => seq(
			alias($._$parenLeft, $.invalid),
			$.formula,
			$.__EOF,
		),
		
		parenthesized: $ => seq(
			$._$parenLeft,
			$.formula,
			$._$parenRight,
		),
		
		_parenthesized_invalid: $ => seq(
			$._$parenLeft,
			optional($._wsp_inline),
			choice(
				$._$parenRight,
				$.__EOF,
			),
		),
		
		
		/*┌──────────────────────────────
		  │ Math Functions
		  └──────────────────────────────*/
		
		_function: $ => choice(
			$.function,
			alias($._function_unclosed, $.function),
		),
		_function_unclosed: $ => seq(
			alias($._function_unclosed_2, $.invalid),
			$.formula,
			$.__EOF,
		),
		_function_unclosed_2: $ => seq(
			alias(/abs|ceil|floor|round/, $.name),
			$._$parenLeft,
		),
		
		function: $ => seq(
			alias(/abs|ceil|floor|round/, $.name),
			alias($.parenthesized, ""),
		),
		
		_function_invalid: $ => seq(
			alias(/abs|ceil|floor|round/, $.name),
			$._parenthesized_invalid,
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Rolls
		  ╚════════════════════════════════════════════════════════════*/
		
		_dice_count: $ => alias($._number, $.number),
		
		
		/*┌──────────────────────────────
		  │ Roll Modifiers
		  └┬─────────────────────────────*/
		 /*│ Roll modifiers can be injected with attributes and abilities, but
		   │   this script doesn't allow for those.
		   └─────────────────────────────*/
		
		_shared_modifier: $ => choice(
			alias($._modifier_keep, $.keep),
			alias($._modifier_drop, $.drop),
			alias($._modifier_successes, $.successes),
			alias($._modifier_successesMinusFailures, $.successesMinusFailures),
		),
		_diceRoll_modifiers: $ => prec(1, repeat1(choice(
			alias($._modifier_reroll, $.reroll),
			alias($._modifier_reroll_once, $.reroll_once),
			alias($._modifier_exploding, $.exploding),
			alias($._modifier_compounding, $.compounding),
			alias($._modifier_penetrating, $.penetrating),
			$._shared_modifier,
			alias($._modifier_criticalSuccess, $.criticalSuccess),
			alias($._modifier_criticalFailure, $.criticalFailure),
			alias($._modifier_showMatches, $.showMatches),
			alias($._modifier_countMatches, $.countMatches),
			alias($._modifier_sort, $.sort),
		))),
		_groupRoll_modifiers: $ => prec(1, repeat1($._shared_modifier)),
		
		_modifier_reroll: $ => seq( /[rR][<=>]?/, $._number ),
		_modifier_reroll_once: $ => seq( /[rR][oO][<=>]?/, $._number ),
		_modifier_exploding: $ => seq(
			"!",
			optional(seq(
				/[<=>]?/,
				$._number,
			)),
		),
		_modifier_compounding: $ => seq(
			"!!",
			optional(seq(
				/[<=>]?/,
				$._number,
			)),
		),
		_modifier_penetrating: $ => seq(
			/![pP]/,
			optional(seq(
				/[<=>]?/,
				$._number,
			)),
		),
		_modifier_keep: $ => seq( /[kK][hHlL]?/, $._number ),
		_modifier_drop: $ => seq( /[dD][hHlL]?/, $._number ),
		_modifier_successes: $ => seq( /[<=>]/, $._number ),
		_modifier_successesMinusFailures: $ => seq( /[<=>]/, $._number, /[fF][<=>]?/, $._number ),
		_modifier_criticalSuccess: $ => seq( /[cC][Ss][<=>]?/, $._number ),
		_modifier_criticalFailure: $ => seq( /[cC][fF][<=>]?/, $._number ),
		_modifier_showMatches: $ => seq(
			/[mM]/,
			$._number,
			optional(seq(
				/[<=>]/,
				$._number,
			)),
		),
		_modifier_countMatches: $ => seq(
			/[mM][tT]/,
			$._number,
			optional(seq(
				/[<=>]/,
				$._number,
			)),
		),
		_modifier_sort: $ => /[sS][aAdD]/,
		
		
		/*┌──────────────────────────────
		  │ Dice Roll
		  └──────────────────────────────*/
		
		diceRoll: $ => prec.right(1, seq(
			//number of dice to roll
			optional(alias($._number, $.count)),
			//keyword (the letter 'd')
			$._$diceRoll,
			//number of sides per die
			alias($._diceRoll_sides, $.sides),
			//modifiers
			optional(alias($._diceRoll_modifiers, $.modifiers)),
		)),
		_diceRoll_sides: $ => choice(
			$._number,
			alias(/[fF]/, $.fate),
		),
		
		
		/*┌──────────────────────────────
		  │ Table Roll
		  └──────────────────────────────*/
		
		_tableRoll: $ => choice(
			$.tableRoll,
			alias($._tableRoll_unclosed, $.tableRoll),
		),
		_tableRoll_unclosed: $ => seq(
			alias($._$tableRoll, $.invalid),
			$.tableName,
			$.__EOF,
		),
		
		tableRoll: $ => prec.right(seq(
			//number of "dice"
			optional(alias($._dice_count, $.count)),
			//keyword ("t[")
			$._$tableRoll,
			//table name
			$.tableName,
			$._$bracketRight,
		)),
		tableName: $ => name(choice(
			/[^@%#\]\r\n]+/,
			$.attribute,
			$.ability,
			//TODO: make sure these aren't needed:
			//prec(1, "@{"),
			//prec(1, "%{"),
			$.__just_at,
			$.__just_percent,
		))($),
		
		_tableRoll_invalid: $ => seq(
			optional(alias($._dice_count, $.count)),
			$._$tableRoll,
			optional($._wsp_inline),
			choice(
				$._$bracketRight,
				$.__EOF,
			),
		),
		
		
		/*┌──────────────────────────────
		  │ Group Roll
		  └──────────────────────────────*/
		
		_groupRoll: $ => choice(
			$.groupRoll,
			alias($._groupRoll_unclosed, $.groupRoll),
		),
		_groupRoll_unclosed: $ => prec.right(seq(
			alias($._$braceLeft, $.invalid),
			$._groupRoll_content,
			$.__EOF,
		)),
		
		groupRoll: $ => prec.right(seq(
			$._$braceLeft,
			$._groupRoll_content,
			$._$braceRight,
			optional(alias($._groupRoll_modifiers, $.modifiers)),
		)),
		_groupRoll_content: $ => seq(
			optional(alias($._groupRoll_invalid_commas, $.invalid)),
			$.formula,
			repeat(seq(
				$.__just_comma,
				optional(alias($._groupRoll_invalid_commas, $.invalid)),
				$.formula,
			)),
			optional(alias($._groupRoll_invalid_commas_last, $.invalid)),
		),
		
		_groupRoll_invalid_commas: $ => repeat1(seq(
			optional($._labels_or_wsp),
			$.__just_comma,
		)),
		_groupRoll_invalid_commas_last: $ => prec.right(repeat1(
			prec.right(seq(
				$.__just_comma,
				optional($._labels_or_wsp),
			))
		)),
		
		_groupRoll_invalid: $ => seq(
			$._$braceLeft,
			optional(choice(
				seq(
					$._groupRoll_invalid_commas,
					optional($._labels_or_wsp),
				),
				$._labels_or_wsp,
			)),
			choice(
				seq(
					$._$braceRight,
					optional(alias($._groupRoll_modifiers, $.modifiers)),
				),
				$.__EOF,
			),
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Delimiters
		  ╚════════════════════════════════════════════════════════════*/
		
		_$attributeLeft: $ => alias($._$_attributeLeft, $.delimiter),
		_$_attributeLeft: $ => seq( $.__attribute_start, $.__just_leftBrace ),
		
		_$abilityLeft: $ => alias($._$_abilityLeft, $.delimiter),
		_$_abilityLeft: $ => seq( $.__ability_start, $.__just_leftBrace ),
		
		_$macro: $ => alias($.__macro_start, $.delimiter),
		
		
		_$rollQueryLeft: $ => alias($.__rollQuery_start, $.delimiter),
		_$rollQueryPipeDefault: $ => alias($.__rollQuery_pipe_hasDefault, $.delimiter),
		_$rollQueryPipeFirstOption: $ => alias($.__rollQuery_pipe_hasOptions, $.delimiter),
		_$comma: $ => alias($.__just_comma, $.delimiter),
		_$rollQueryRight: $ => alias($.__rollQuery_end, $.delimiter),
		
		
		_$inlineRollLeft: $ => alias($.__inlineRoll_start, $.delimiter),
		_$inlineRollRight: $ => alias($.__inlineRoll_end, $.delimiter),
		
		
		_$diceRoll: $ => alias($.__diceRoll_start, $.delimiter),
		
		_$tableRoll: $ => alias($._$_tableRoll, $.delimiter),
		_$_tableRoll: $ => seq( $.__tableRoll_start, $.__just_leftBracket ),
		
		
		_$pipe: $ => alias($.__just_pipe, $.delimiter),
		_$braceLeft: $ => alias($.__just_leftBrace, $.delimiter),
		_$braceRight: $ => alias($.__just_rightBrace, $.delimiter),
		_$bracketLeft: $ => alias($.__just_leftBracket, $.delimiter),
		_$bracketRight: $ => alias($.__just_rightBracket, $.delimiter),
		_$parenLeft: $ => alias($.__just_leftParen, $.delimiter),
		_$parenRight: $ => alias($.__just_rightParen, $.delimiter),
		
		
	},
});
