module.exports = grammar({
	name: "roll20_script",
	
	externals: $ => [
		$.__ROLLQUERY_START,	// ?{
		$.__ROLLQUERY_END,		// }
		
		$.__INLINEROLL_START,	// [[
		$.__INLINEROLL_END,		// ]]
		
		$.__LABEL_START,		// [
		$.__LABEL_END,			// ]
		
		$.__BUTTON_START,		// (~
		$.__BUTTON_END,			// )
		
		$.__GROUPROLL_START,	// {
		$.__GROUPROLL_END,		// }
		
		$.__TABLEROLL_START,	// t[
		$.__TABLEROLL_END,		// ]
		
		$.__PIPE,				// |
		$.__COMMA,				// ,
		$.__LEFT_BRACE,			// {
		$.__RIGHT_BRACE,		// }
		$.__LEFT_PAREN,			// (
		$.__RIGHT_PAREN,		// )
		$.__COLON,				// :
		
		$.__FLAG_START,			// &{
		$.__FLAG_END,			// }
		$.__ROLLTEMPLATE_PROPERTY_START,	// {{
		$.__ROLLTEMPLATE_PROPERTY_END,		// }}
		
		$.__HTML_ENTITY,
		
		$.__AMPERSAND,			// &
	],
	
	extras: $ => [],
	
	//supertypes: $ => [],
	
	//inline: $ => [],
	
	precedences: $ => [
		/*[
			"multiplication",
			"summation",
		],*/
	],
	
	conflicts: $ => [
		[ $.rollQuery, $._rq_option, ],
		[ $.script, $.rollTemplate, ],
	],
	
	//word: $ => $.___,
	
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
		  ║ Start Rule, Basics
		  ╚════════════════════════════════════════════════════════════*/
		
		script: $ => choice(
			$._script,
			$.rollCommand,
			$.rollTemplate,
		),
		
		
		_script: $ => repeat1(choice(
			$._script_common1,
			$._script_common2,
			//alias(/[^#&\s\]]/, $.string),
			/[^#&\s\]]/,
		)),
		
		_script_common1: $ => choice(
			$._placeholder,	//attributes, abilities
			$.rollQuery,
			/\s/,
		),
		_script_common2: $ => choice(
			$.inlineRoll,
			$.hash,
			$._htmlEntity_or_ampersand,
			$.abilityCommandButton,
		),
		
		
		_htmlEntity_or_ampersand: $ => choice(
			$.__AMPERSAND,
			$.htmlEntity,
		),
		
		htmlEntity: $ => $.__HTML_ENTITY,
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Attributes (getters), Abilities (methods)
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ In this grammar, these are collectively referred to as "placeholders".
		   └───────────────────────────────────────────────────────────*/
		
		_placeholder: $ => choice(
			$.attribute,
			$.ability,
		),
		
		character_token: $ => choice(
			"target",
			"selected",
		),
		
		
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
		
		attribute: $ => choice(
			$._attribute,
			$._attribute_of_character,
			$._attribute_of_character_maximum,
		),
		_attribute: $ => seq(
			alias("@{", $.delimiter_start),
			$.attribute_identifier,
			alias("}", $.delimiter_end),
		),
		_attribute_of_character: $ => seq(
			alias("@{", $.delimiter_start),
			choice(
				$.character_token,
				alias($.attribute_identifier, $.character_identifier),
			),
			alias("|", $.separator),
			$.attribute_identifier,
			alias("}", $.delimiter_end),
		),
		_attribute_of_character_maximum: $ => seq(
			alias("@{", $.delimiter_start),
			choice(
				$.character_token,
				alias($.attribute_identifier, $.character_identifier),
			),
			alias("|", $.separator),
			$.attribute_identifier,
			alias("|", $.separator),
			field("max", alias("max", $.keyword)),
			alias("}", $.delimiter_end),
		),
		
		attribute_identifier: $ => repeat1(choice(
			$.htmlEntity,
			$.hash,
			token(choice(
				/\{+/,
				/\{*[@%]+/,
				seq(
					choice(
						/[^@%#{|}]+/,
						repeat1(seq(
							choice(
								/\{+/,
								/\{*[@%]+/,
							),
							/[^@%#{|}]+/,
						)),
					),
					/\{*[@%]*/,
				),
			)),
		)),
		
		
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
		
		ability: $ => seq(
			alias("%{", $.delimiter_start),
			optional(seq(
				choice(
					$.character_token,
					alias($.ability_identifier, $.character_identifier),
				),
				alias("|", $.separator),
			)),
			$.ability_identifier,
			alias("}", $.delimiter_end),
		),
		
		ability_identifier: $ => repeat1(choice(
			$.htmlEntity,
			token(choice(
				/\{+/,
				/\{*[@%]+/,
				seq(
					choice(
						/[^@%{|}]+/,
						repeat1(seq(
							choice(
								/\{+/,
								/\{*[@%]+/,
							),
							/[^@%{|}]+/,
						)),
					),
					/\{*[@%]*/,
				),
			)),
		)),
		
		
		/*┌──────────────────────────────
		  │ Ability Command Button
		  └┬─────────────────────────────*/
		 /*│ Ability Command Buttons can be used to call abilities (or sheet
		   │ button rolls) from a clickable button in the text chat.
		   │ 
		   │ For an ability command button, the character name and/or ability
		   │ name:
		   │ • can contain spaces, tabs, and hash characters.
		   │ • cannot contain new lines, pipes, or closing curly braces.
		   │ • can include attributes, abilities, or macros.
		   │ 
		   │ [label](~abilityName)
		   │ [label](~selected|abilityName)
		   │ [label](~target|abilityName)
		   │ [label](~characterName|abilityName)
		   │ [label](~characterID|abilityName)
		   └─────────────────────────────*/
		
		abilityCommandButton: $ => seq(
			$.label,
			alias($.__BUTTON_START, $.delimiter_start),
			optional(seq(
				choice(
					$.character_token,
					alias($._acb_identifier_text, $.character_identifier),
				),
				alias($.__PIPE, $.separator),
			)),
			alias($._acb_identifier_text, $.ability_identifier),
			alias($.__BUTTON_END, $.delimiter_end),
		),
		
		_acb_identifier_text: $ => prec.right(repeat1(choice(
			/[^#&|,})]/,
			$.__PIPE,
			$.__COMMA,
			$.__RIGHT_BRACE,
			$.__RIGHT_PAREN,
			$._placeholder,
			$.hash,
			$._htmlEntity_or_ampersand,
		))),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Macros
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ This grammar will just pick out hash characters, which might
		   │   refer to a macro. It's impossible to know whether a valid macro
		   │   name actually does refer to a macro, since we can't check a name
		   │   against the list of defined macros.
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
		   └───────────────────────────────────────────────────────────*/
		
		hash: $ => "#",
		
		_macro: $ => prec.right(seq(
			$.hash,
			repeat1(choice(
				$._placeholder,
				/[^@%&{|}\[\]() ]+/,
					//some of these characters can technically be used in a macro name,
					// but this implementation will assume they're all invalid
			)),
			optional(/ |\r?\n/),	//making whitespace optional for the same reason
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Inline Rolls and Roll Command
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ An inline roll may be used as a root element or in place of a
		   │   number, and contains its own formula. When evaluated, it is
		   │   reduced to a number.
		   │ 
		   │ If there is any invalid content after the formula, it will still be
		   │   visible in the tooltip when you hover your mouse over the total.
		   └───────────────────────────────────────────────────────────*/
		
		inlineRoll: $ => seq(
			alias($.__INLINEROLL_START, $.delimiter_start),
			$.formula,
			alias($.__INLINEROLL_END, $.delimiter_end),
		),
		
		rollCommand: $ => seq(
			alias("/", $.delimiter),
			alias(/r(oll)?/, $.command_identifier),
			/\s+/,
			$.formula,
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Numbers
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ Numbers are combined with attributes, abilities, and inline rolls.
		   └───────────────────────────────────────────────────────────*/
		
		_integer: $ => prec.right(repeat1(choice(
			alias(/\d+/, $.number_constant),
			$._placeholder,
			$.inlineRoll,
			$.rollQuery,
		))),
		
		_number: $ => choice(
			$._number_signable,
			$._number_unsignable,
		),
		_number_signable: $ => prec.right(seq(
			$._integer,
			optional(seq(
				alias(".", $.decimal_point),
				$._integer,
			)),
		)),
		_number_unsignable: $ => prec.right(seq(
			alias(".", $.decimal_point),
			$._integer,
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
		   │   This implementation does not check for that.
		   │ 
		   │ A formula cannot have more than one turn tracker flag in it, but
		   │   this implementation does not check for that.
		   └───────────────────────────────────────────────────────────*/
		
		formula: $ => prec.right(seq(
			optional($._labels),
			alias($._term_first, $.term),
			optional($._labels),
			repeat(seq(
				choice(
					seq(
						$._operator_summation,
						optional($._labels),
						alias($._term_unsigned, $.term),
					),
					seq(
						$._operator_multiplication,
						optional($._labels),
						choice(
							alias($._term_unsigned, $.term),
							alias($._term_signed, $.term),
						),
					),
				),
				optional($._labels),
			)),
		)),
		
		_term_first: $ => prec.right(choice(
			seq(
				choice(
					seq(
						optional(alias(/[+-]/, $.operator)),
						$._number_signable,
					),
					$._number_unsignable,
					$.parenthesized,
					$.function,
					$.diceRoll,
					$.groupRoll,
					$.tableRoll,
				),
				optional($._macro),
			),
			$._macro,
		)),
		
		_term_unsigned: $ => prec.right(choice(
			seq(
				choice(
					$._number,
					$.diceRoll,
					$.groupRoll,
					seq(
						choice(
							$.parenthesized,
							$.function,
							$.tableRoll,
						),
						optional($._placeholder),
					),
				),
				optional($._macro),
			),
			$._macro,
		)),
		
		_term_signed: $ => seq(
			$._operator_summation,
			optional($._labels),
			$._term_unsigned,
		),
		
		
		/*┌──────────────────────────────
		  │ Parenthesized Formula
		  └──────────────────────────────*/
		
		parenthesized: $ => $._parenthesized,
		
		_parenthesized: $ => seq(
			alias($.__LEFT_PAREN, $.delimiter_start),
			$.formula,
			alias($.__RIGHT_PAREN, $.delimiter_end),
		),
		
		function: $ => seq(
			alias(/abs|ceil|floor|round/, $.function_identifier),
			$._parenthesized,
		),
		
		
		/*┌──────────────────────────────
		  │ Operator
		  └┬─────────────────────────────*/
		 /*│ `+-` and `-+` are evaluated as subtraction.
		   │ 
		   │ The only place a unary negative/positive operator can be is as a
		   │   prefix of a number that is the first element in a formula, or
		   │   right after a multiplication-type operator.
		   └─────────────────────────────*/
		
		/*_operator_multiplication: $ => prec.right("multiplication", alias(/[\/%]|\*\*?/, $.operator)),
		_operator_summation: $ => prec.right("summation", alias(choice(
			$._operator_summation_plus,
			$._operator_summation_minus,
		), $.operator)),*/
		_operator_multiplication: $ => prec.right(1, alias(/[\/%]|\*\*?/, $.operator)),
		_operator_summation: $ => prec.right(alias(choice(
			$._operator_summation_plus,
			$._operator_summation_minus,
		), $.operator)),
		_operator_summation_plus: $ => /\+(\s*\-(\s*\+\s*\-)*(\s*\+)?)?/,
		_operator_summation_minus: $ => /\-(\s*\+(\s*\-\s*\+)*(\s*\-)?)?/,
		
		
		/*┌──────────────────────────────
		  │ Inline Label
		  └┬─────────────────────────────*/
		 /*│ An inline label:
		   │ • cannot contain new lines or closing square brackets.
		   │ • can include attributes, abilities, and macros.
		   └─────────────────────────────*/
		
		label: $ => seq(
			alias($.__LABEL_START, $.delimiter_start),
			optional(alias($._label_text, $.label_text)),
			alias($.__LABEL_END, $.delimiter_end),
		),
		
		_label_text: $ => prec.right(seq(
			choice(
				/[^#&\[\]{|,}()]/,
				$._placeholder,
				$.hash,
				$._htmlEntity_or_ampersand,
				$.__LEFT_BRACE,
				$.__PIPE,
				$.__COMMA,
				$.__RIGHT_BRACE,
				$.__LEFT_PAREN,
				$.__RIGHT_PAREN,
			),
			repeat($._label_text_2),
		)),
		
		_label_text_2: $ => choice(
			/[^#&\]{|,}()]/,
			$._placeholder,
			$.hash,
			$._htmlEntity_or_ampersand,
			$.__LEFT_BRACE,
			$.__PIPE,
			$.__COMMA,
			$.__RIGHT_BRACE,
			$.__LEFT_PAREN,
			$.__RIGHT_PAREN,
		),
		
		//labels and/or a turn tracker flag
		_labels: $ => prec.right(choice(
			/\s+/,
			seq(
				optional(/\s+/),
				repeat1(seq(
					$.label,
					optional(/\s+/),
				)),
			),
			seq(
				optional(/\s+/),
				repeat(seq(
					$.label,
					optional(/\s+/),
				)),
				field("tracker", alias($._flag_tracker, $.flag)),
				optional(/\s+/),
				repeat(seq(
					$.label,
					optional(/\s+/),
				)),
			),
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Rolls
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ Roll modifiers can be injected with attributes, abilities, and
		   │   inline rolls. This script does not parse the modifiers.
		   └───────────────────────────────────────────────────────────*/
		
		/*┌──────────────────────────────
		  │ Dice Roll
		  └──────────────────────────────*/
		
		diceRoll: $ => prec.right(seq(
			optional(alias($._integer, $.count)),
			alias(/[dD]/, $.delimiter),
			alias($._diceRoll_sides, $.sides),
			optional(alias($._diceRoll_modifiers, $.modifiers)),
		)),
		_diceRoll_sides: $ => choice(
			$._integer,
			alias(/[fF]/, $.fate),
		),
		
		_diceRoll_modifiers: $ => repeat1(choice(
			$._integer,
			/[aAcCdDfFhHkKlLmMoOpPrRsStT<=>!]+/,
		)),
		
		
		/*┌──────────────────────────────
		  │ Grouped Rolls
		  └──────────────────────────────*/
		
		groupRoll: $ => prec.right(seq(
			alias($.__GROUPROLL_START, $.delimiter_start),
			$.formula,
			repeat(seq(
				alias($.__COMMA, $.separator),
				$.formula,
			)),
			alias($.__GROUPROLL_END, $.delimiter_end),
			optional(alias($._groupRoll_modifiers, $.modifiers)),
		)),
		
		_groupRoll_modifiers: $ => repeat1(choice(
			$._integer,
			/[dDfFhHkKlL<=>]+/,
		)),
		
		
		/*┌──────────────────────────────
		  │ Rollable Table
		  └┬─────────────────────────────*/
		 /*│ A table name:
		   │ • cannot contain new lines or closing square brackets.
		   │ • can include attributes, abilities, and macros.
		   └─────────────────────────────*/
		
		tableRoll: $ => seq(
			optional(alias($._integer, $.count)),
			alias($.__TABLEROLL_START, $.delimiter_start),
			$.table_identifier,
			alias($.__TABLEROLL_END, $.delimiter_end),
		),
		
		table_identifier: $ => prec.right(repeat1($._tableRoll_text)),
		
		_tableRoll_text: $ => $._label_text_2,
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Roll Queries
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ • If an option has an identifier, optionally a comma, and no value,
		   │   the identifier acts as the value as well. Which means that HTML
		   │   entities in the identifier can be interpreted as characters in
		   │   the value.
		   └───────────────────────────────────────────────────────────*/
		
		rollQuery: $ => seq(
			alias($.__ROLLQUERY_START, $.delimiter_start),
			choice(
				alias($._rq_text_pd, $.prompt),
				seq(
					optional(alias($._rq_text_pd, $.prompt)),
					alias($.__PIPE, $.separator),
					optional(choice(
						alias($._rq_text_pd, $.default_value),
						seq(
							optional(alias($._rq_option, $.option)),
							repeat1(seq(
								alias($.__PIPE, $.separator),
								optional(alias($._rq_option, $.option)),
							)),
						),
					)),
				),
			),
			alias($.__ROLLQUERY_END, $.delimiter_end),
		),
		
		_rq_text: $ => choice(
			/[^#&{|,}()]/,
			$._placeholder,
			$.hash,
			$._htmlEntity_or_ampersand,
			$.__LEFT_BRACE,
			$.__LEFT_PAREN,
			$.__RIGHT_PAREN,
		),
		
		_rq_text_pd: $ => repeat1(choice(
			$._rq_text,
			$.__COMMA,
		)),
		
		_rq_text_option: $ => repeat1($._rq_text),
		
		_rq_text_optionValue: $ => repeat1(choice(
			$._rq_text,
			$.rollQuery,
			$.abilityCommandButton,
			$.inlineRoll,
			alias($._flag_tracker, $.flag),
			alias($._flag_rollTemplate, $.flag),
			alias($._rt_property, $.template_property),
		)),
		
		_rq_option: $ => prec.right(choice(
			alias($._rq_text_option, $.option_identifier),
			seq(
				optional(alias($._rq_text_option, $.option_identifier)),
				alias($.__COMMA, $.separator),
				optional(alias($._rq_text_optionValue, $.option_value)),
			),
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Flag
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ E.g.: &{tracker}, &{template:atkdmg}
		   └───────────────────────────────────────────────────────────*/
		
		flag_value: $ => repeat1(choice(
			/[^#&}]/,
			$._placeholder,
			$.hash,
			$._htmlEntity_or_ampersand,
			$.inlineRoll,
		)),
		
		
		/*┌──────────────────────────────
		  │ Turn Tracker flag
		  └──────────────────────────────*/
		
		_flag_tracker: $ => seq(
			alias($.__FLAG_START, $.delimiter_start),
			field("tracker", alias("tracker", $.flag_identifier)),
			optional(seq(
				alias(":", $.separator),
				$.flag_value,
			)),
			alias($.__FLAG_END, $.delimiter_end),
		),
		
		
		/*┌──────────────────────────────
		  │ Roll Template flag
		  └──────────────────────────────*/
		
		_flag_rollTemplate: $ => seq(
			alias($.__FLAG_START, $.delimiter_start),
			field("template", alias("template", $.flag_identifier)),
			alias(":", $.separator),
			$.flag_value,
			alias($.__FLAG_END, $.delimiter_end),
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Roll Templates
		  ╚════════════════════════════════════════════════════════════*/
		
		rollTemplate: $ => seq(
			repeat(choice(
				$._script_common1,
				$._script_common2,
				alias($._rt_property, $.template_property),
				field("rtype", alias($._rt_rtype, $.template_property)),
				/\r?\n/,
			)),
			alias($._flag_rollTemplate, $.flag),
			repeat(choice(
				$._script_common1,
				$._script_common2,
				alias($._rt_property, $.template_property),
				field("rtype", alias($._rt_rtype, $.template_property)),
				/\r?\n/,
			)),
		),
		
		_rt_property: $ => seq(
			alias($.__ROLLTEMPLATE_PROPERTY_START, $.delimiter_start),
			optional(alias($._rt_propertyName, $.property_identifier)),
			alias("=", $.operator),
			optional(alias($._rt_propertyValue, $.property_value)),
			alias($.__ROLLTEMPLATE_PROPERTY_END, $.delimiter_end),
		),
		_rt_propertyName: $ => repeat1(choice(
			/[^#&=}]|\r?\n/,
			$._placeholder,
			$.hash,
			$._htmlEntity_or_ampersand,
			$.inlineRoll,
			$.abilityCommandButton,
		)),
		_rt_propertyValue: $ => repeat1(prec.right(choice(
			$._script,
			/\r?\n/,
		))),
		
		_rt_rtype: $ => prec.right(seq(
			alias($._rt_rtype_attribute, $.attribute),
			optional(alias($._rt_rtype_formula, $.formula)),
			alias($.__INLINEROLL_END, $.delimiter_end),
			optional(/(\s|\r?\n)+/),
			alias("}}", $.delimiter_end),
		)),
		_rt_rtype_attribute: $ => seq(
			alias("@{", $.delimiter_start),
			alias("rtype", $.attribute_identifier),
			alias("}", $.delimiter_end),
		),
		_rt_rtype_formula: $ => seq(
			optional($._labels),
			repeat1(seq(
				choice(
					seq(
						$._operator_summation,
						optional($._labels),
						alias($._term_unsigned, $.term),
					),
					seq(
						$._operator_multiplication,
						optional($._labels),
						choice(
							alias($._term_unsigned, $.term),
							alias($._term_signed, $.term),
						),
					),
				),
				optional($._labels),
			)),
		),
		
		
	},
});
