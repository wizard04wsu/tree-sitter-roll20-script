const _debugging = true;
function debugAlias(theToken, aliasToken, fieldName){
	if(!_debugging) return theToken;
	if(fieldName !== void 0){
		fieldName = fieldName.toString().replace(/^(\w+).*/, "$1");
		if(fieldName){
			return field(fieldName, alias(theToken, aliasToken));
		}
	}
	return alias(theToken, aliasToken);
}



module.exports = grammar({
	name: "roll20_script",
	
	externals: $ => [
		$.__ROLLQUERY_START,
		$.__ROLLQUERY_END,
		
		$.__INLINEROLL_START,
		$.__INLINEROLL_END,
		
		$.__LABEL_START,
		$.__LABEL_END,
		
		$.__BUTTON_START,
		$.__BUTTON_END,
		
		$.__GROUPROLL_START,
		$.__GROUPROLL_END,
		
		$.__TABLEROLL_START,
		$.__TABLEROLL_END,
		
		$.__PIPE,
		$.__COMMA,
		$.__LEFT_BRACE,
		$.__RIGHT_BRACE,
		$.__LEFT_PAREN,
		$.__RIGHT_PAREN,
		
		$.__HTML_ENTITY,
		
		$.__AMPERSAND,
		
		$.__ANYTHING,	//to prevent problems when the scanner tries to error correct with conflicts
	],
	
	extras: $ => [],
	
	//supertypes: $ => [],
	
	//inline: $ => [],
	
	precedences: $ => [
		[
			"multiplication",
			"summation",
		],
	],
	
	conflicts: $ => [
		[ $.rollQuery, $._queryOption, ],
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
		
		script: $ => repeat(choice(
			$._placeholder,	//attributes, abilities
			$.inlineRoll,
			$.rollQuery,
			$.hash,
			$._htmlEntity_or_ampersand,
			
			$.abilityCommandButton,
			
			//TODO:
			//template
			//property
			//tracker
			
			/[^&]/,
		)),
		
		_wsp: $ => /\s+/,
		
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
			$._attribute,
			$.ability,
		),
		
		character_token_identifier: $ => choice(
			field("target", "target"),
			field("selected", "selected"),
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
		
		_attribute: $ => choice(
			$.attribute,
			alias($._attribute_of_character, $.attribute),
			alias($._attribute_of_character_maximum, $.attribute_maximum),
		),
		attribute: $ => seq(
			"@{",
			$.attribute_identifier,
			"}",
		),
		_attribute_of_character: $ => seq(
			"@{",
			choice(
				$.character_token_identifier,
				alias($.attribute_identifier, $.character_identifier),
			),
			"|",
			$.attribute_identifier,
			"}",
		),
		_attribute_of_character_maximum: $ => seq(
			"@{",
			choice(
				$.character_token_identifier,
				alias($.attribute_identifier, $.character_identifier),
			),
			"|",
			$.attribute_identifier,
			"|max}",
		),
		
		attribute_identifier: $ => repeat1(choice(
			$.htmlEntity,
			$.hash,
			token(choice(
				/\{+/,
				/\{*[@%]+/,
				seq(
					choice(
						/[^@%#{|}\r\n]+/,
						repeat1(seq(
							choice(
								/\{+/,
								/\{*[@%]+/,
							),
							/[^@%#{|}\r\n]+/,
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
			"%{",
			optional(seq(
				choice(
					$.character_token_identifier,
					alias($.ability_identifier, $.character_identifier),
				),
				"|",
			)),
			$.ability_identifier,
			"}",
		),
		
		ability_identifier: $ => repeat1(choice(
			$.htmlEntity,
			token(choice(
				/\{+/,
				/\{*[@%]+/,
				seq(
					choice(
						/[^@%{|}\r\n]+/,
						repeat1(seq(
							choice(
								/\{+/,
								/\{*[@%]+/,
							),
							/[^@%{|}\r\n]+/,
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
			$.__BUTTON_START,
			optional(seq(
				choice(
					$.character_token_identifier,
					alias($._acb_identifier_text, $.character_identifier),
				),
				$.__PIPE,
			)),
			alias($._acb_identifier_text, $.ability_identifier),
			$.__BUTTON_END,
		),
		
		_acb_identifier_text: $ => prec.right(repeat1(choice(
			/[^#\r\n|,})&]/,
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
		   └─────────────────────────────*/
		
		hash: $ => "#",
		
		_macro: $ => prec.right(seq(
			$.hash,
			repeat1(choice(
				$._placeholder,
				/[^@%&{|}\[\]() \r\n]+/,
					//some of these characters can technically be used in a macro name,
					// but this implementation will assume they're all invalid
			)),
			optional(choice( $._wsp, /\r?\n/ )),	//making whitespace optional for the same reason
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Inline Rolls
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ An inline roll may be used as a root element or in place of a
		   │   number, and contains its own formula. When evaluated, it is
		   │   reduced to a number.
		   └─────────────────────────────*/
		
		inlineRoll: $ => seq(
			$.__INLINEROLL_START,
			$.formula,
			$.__INLINEROLL_END,
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Numbers
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ Numbers are combined with attributes, abilities, and inline rolls.
		   └───────────────────────────────────────────────────────────*/
		
		_integer: $ => prec.right(repeat1(choice(
			/\d+/,
			$._placeholder,
			$.inlineRoll,
			$.rollQuery,
		))),
		
		number: $ => choice(
			$._number_signable,
			$._number_unsignable,
		),
		_number_signable: $ => prec.right(seq(
			$._integer,
			optional(seq(
				".",
				$._integer,
			)),
		)),
		_number_unsignable: $ => prec.right(seq(
			".",
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
		   └─────────────────────────────*/
		
		formula: $ => prec.right(seq(
			optional($._labels),
			alias($._term_first, $.term),
			optional($._labels),
			repeat(seq(
				choice(
					seq(
						alias($._operator_summation, $.operator),
						optional($._labels),
						alias($._term_unsigned, $.term),
					),
					seq(
						alias($._operator_multiplication, $.operator),
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
		
		_term_first: $ => choice(
			seq(
				choice(
					seq(
						optional(alias(/[+-]/, $.operator)),
						alias($._number_signable, $.number),	//numbers, attributes, abilities, and inline rolls
					),
					alias($._number_unsignable, $.number),	//numbers, attributes, abilities, and inline rolls
					$.parenthesized,
					$.function,
					$.diceRoll,
					$.groupRoll,
					$.tableRoll,
				),
				optional($._macro),
			),
			$._macro,
		),
		
		_term_unsigned: $ => choice(
			seq(
				choice(
					$.number,	//numbers, attributes, abilities, and inline rolls
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
		),
		
		_term_signed: $ => seq(
			alias($._operator_summation, $.operator),
			optional($._labels),
			$._term_unsigned,
		),
		
		
		/*┌──────────────────────────────
		  │ Parenthesized Formula
		  └──────────────────────────────*/
		
		parenthesized: $ => $._parenthesized,
		
		_parenthesized: $ => seq(
			$.__LEFT_PAREN,
			$.formula,
			$.__RIGHT_PAREN,
		),
		
		function: $ => seq(
			alias(/abs|ceil|floor|round/, $.name),
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
		
		_operator_multiplication: $ => prec.right("multiplication", /[\/%]|\*\*?/),
		_operator_summation: $ => prec.right("summation", choice(
			$._operator_summation_plus,
			$._operator_summation_minus,
		)),
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
			$.__LABEL_START,
			optional($.labelText),
			$.__LABEL_END,
		),
		
		labelText: $ => prec.right(seq(
			choice(
				/[^#&\r\n\[\]]/,
				$._placeholder,
				$.hash,
				$._htmlEntity_or_ampersand,
			),
			repeat($._text_label_or_tableRoll),
		)),
		
		_text_label_or_tableRoll: $ => choice(
			/[^#&\r\n\[\]]/,
			$._placeholder,
			$.hash,
			$._htmlEntity_or_ampersand,
		),
		
		_labels: $ => prec.right(choice(
			$._wsp,
			seq(
				optional($._wsp),
				repeat1(seq(
					$.label,
					optional($._wsp),
				)),
			),
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Rolls
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ Roll modifiers can be injected with attributes, abilities, and
		   │   inline rolls. This script does not parse the modifiers.
		   └─────────────────────────────*/
		
		/*┌──────────────────────────────
		  │ Dice Roll
		  └──────────────────────────────*/
		
		diceRoll: $ => prec.right(seq(
			optional(alias($._integer, $.count)),
			/[dD]/,
			choice(
				alias($._integer, $.sides),
				alias(/[fF]/, $.fate),
			),
			optional(alias($._diceRoll_modifiers, $.modifiers)),
		)),
		
		_diceRoll_modifiers: $ => repeat1(choice(
			$._integer,
			/[aAcCdDfFhHkKlLmMoOpPrRsStT<=>!]+/,
		)),
		
		
		/*┌──────────────────────────────
		  │ Group Roll
		  └──────────────────────────────*/
		
		groupRoll: $ => prec.right(seq(
			$.__GROUPROLL_START,
			$.formula,
			repeat(seq(
				$.__COMMA,
				$.formula,
			)),
			$.__GROUPROLL_END,
			optional(alias($._groupRoll_modifiers, $.modifiers)),
		)),
		
		_groupRoll_modifiers: $ => repeat1(choice(
			$._integer,
			/[dDfFhHkKlL<=>]+/,
		)),
		
		
		/*┌──────────────────────────────
		  │ Table Roll
		  └┬─────────────────────────────*/
		 /*│ A table name:
		   │ • cannot contain new lines or closing square brackets.
		   │ • can include attributes, abilities, and macros.
		   └─────────────────────────────*/
		
		tableRoll: $ => seq(
			optional(alias($._integer, $.count)),
			$.__TABLEROLL_START,
			$.tableName,
			$.__TABLEROLL_END,
		),
		
		tableName: $ => prec.right(repeat1($._text_label_or_tableRoll)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Roll Queries
		  ╚════════════════════════════════════════════════════════════*/
		
		rollQuery: $ => seq(
			$.__ROLLQUERY_START,
			choice(
				alias($._text_query_pd, $.prompt),
				seq(
					optional(alias($._text_query_pd, $.prompt)),
					$.__PIPE,
					optional(choice(
						alias($._text_query_pd, $.defaultValue),
						seq(
							optional(alias($._queryOption, $.option)),
							repeat1(seq(
								$.__PIPE,
								optional(alias($._queryOption, $.option)),
							)),
						),
					)),
				),
			),
			$.__ROLLQUERY_END,
		),
		
		_text_query: $ => choice(
			/[^}|{,()&]/,	//new lines are allowed, but end up being removed or replaced with a space
			$.__LEFT_BRACE,
			$.__RIGHT_BRACE,
			$.__LEFT_PAREN,
			$.__RIGHT_PAREN,
			$._placeholder,
			$.hash,
			$._htmlEntity_or_ampersand,
		),
		
		_text_query_pd: $ => repeat1(choice(
			$._text_query,
			$.__COMMA,
		)),
		
		_queryOption: $ => prec.right(choice(
			alias($._queryOptionName, $.optionName),
			seq(
				optional(alias($._queryOptionName, $.optionName)),
				$.__COMMA,
				optional(alias($._queryOptionValue, $.optionValue)),
			),
		)),
		
		_queryOptionName: $ => repeat1($._text_query),
		
		_queryOptionValue: $ => repeat1(choice(
			$._text_query,
			$.rollQuery,
			$.abilityCommandButton,
			//TODO:
			//$.property,
		)),
		
		
	},
});
