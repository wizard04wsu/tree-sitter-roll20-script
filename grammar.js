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



function _atDepth(rxpChar, rxpHtmlEscape){
	return $ => prec("charSingle", choice(
		rxpChar,
		seq(
			$.__AMP_AT_DEPTH,
			rxpHtmlEscape,
			";",
		),
	));
}
function _atOrAboveDepth(rxpChar, rxpHtmlEscape){
	return $ => prec("charSingle", choice(
		rxpChar,
		seq(
			$.__AMP_AT_OR_ABOVE_DEPTH,
			rxpHtmlEscape,
			";",
		),
	));
}
function _atDepth_pair(rxpPair, rxpChar1, rxpHtmlEscape1, rxpChar2, rxpHtmlEscape2){
	return $ => prec("charPair", choice(
		seq(
			rxpPair,
		),
		seq(
			choice(
				rxpChar1,
				seq(
					$.__AMP_AT_DEPTH,
					rxpHtmlEscape1,
					";",
				),
			),
			choice(
				rxpChar2,
				seq(
					$.__AMP_AT_DEPTH,
					rxpHtmlEscape2,
					";",
				),
			),
		),
	));
}
function _atOrAboveDepth_pair(rxpPair, rxpChar1, rxpHtmlEscape1, rxpChar2, rxpHtmlEscape2){
	return $ => prec("charPair", choice(
		seq(
			rxpPair,
		),
		seq(
			choice(
				rxpChar1,
				seq(
					$.__AMP_AT_OR_ABOVE_DEPTH,
					rxpHtmlEscape1,
					";",
				),
			),
			choice(
				rxpChar2,
				seq(
					$.__AMP_AT_OR_ABOVE_DEPTH,
					rxpHtmlEscape2,
					";",
				),
			),
		),
	));
}



module.exports = grammar({
	name: "roll20_script",
	
	externals: $ => [
		$.__ROLLQUERY_START,
		$.__ROLLQUERY_PIPE,
		$.__ROLLQUERY_COMMA,
		$.__ROLLQUERY_END,
		$.__AMP_AT_OR_ABOVE_DEPTH,
		$.__AMP_AT_DEPTH,
		$.__HTML_ENTITY,
	],
	
	extras: $ => [],
	
	//supertypes: $ => [],
	
	//inline: $ => [],
	
	precedences: $ => [
		[
			"multiplication",
			"summation",
		],
		[
			"charPair",
			"charSingle",
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
			$._IrPh,	//attributes, abilities, inline rolls
			$.hash,
			$._htmlEntity_or_ampersand,
			
			$.rollQuery,
			
			//TODO:
			//template
			//property
			//ability command button
			//tracker
			
			/[^&]/,
		)),
		
		_wsp: $ => /\s+/,
		
		_htmlEntity_or_ampersand: $ => choice(
			$.__ampersand,
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
			alias($.ability_identifier, $.ability_identifier),
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
			$.__inlineRoll_start,
			$.formula,
			$.__inlineRoll_end,
		),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Numbers
		  ╚╤═══════════════════════════════════════════════════════════*/
		 /*│ Numbers are combined with attributes, abilities, and inline rolls.
		   └───────────────────────────────────────────────────────────*/
		
		_IrPh: $ => choice($.inlineRoll, $._placeholder),
		
		_integer: $ => prec.right(repeat1(choice(
			/\d+/,
			$._IrPh,
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
					$.rollQuery,
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
							$.rollQuery,
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
			$.__leftParen,
			$.formula,
			$.__rightParen,
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
			$.__leftBracket,
			optional($.labelText),
			$.__rightBracket,
		),
		
		labelText: $ => prec.right(seq(
			choice(
				/[^#\[\]\r\n{|,}()&]/,
				$.__leftBrace,
				$.__pipe,
				$.__comma,
				$.__rightBrace,
				$.__leftParen,
				$.__rightParen,
				$._placeholder,
				$.hash,
				$._htmlEntity_or_ampersand,
			),
			repeat($._text_label_or_tableRoll),
		)),
		
		_text_label_or_tableRoll: $ => choice(
			/[^#\]\r\n{|,}()&]/,
			$.__leftBrace,
			$.__pipe,
			$.__comma,
			$.__rightBrace,
			$.__leftParen,
			$.__rightParen,
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
			$.__leftBrace,
			$.formula,
			repeat(seq(
				$.__comma,
				$.formula,
			)),
			$.__rightBrace,
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
			$.__tableRoll_start,
			$.tableName,
			$.__rightBracket,
		),
		
		tableName: $ => prec.right(repeat1($._text_label_or_tableRoll)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Roll Queries
		  ╚════════════════════════════════════════════════════════════*/
		
		rollQuery: $ => seq(
			$.__ROLLQUERY_START,
			choice(
				alias($._text_query_prompt_or_defaultValue, $.prompt),
				seq(
					optional(alias($._text_query_prompt_or_defaultValue, $.prompt)),
					$.__ROLLQUERY_PIPE,
					optional(choice(
						alias($._text_query_prompt_or_defaultValue, $.defaultValue),
						seq(
							optional(alias($._queryOption, $.option)),
							repeat1(seq(
								$.__ROLLQUERY_PIPE,
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
			$.__leftBrace,
			$.__leftParen,
			$.__rightParen,
			$._placeholder,
			$.hash,
			$._htmlEntity_or_ampersand,
		),
		
		_text_query_prompt_or_defaultValue: $ => repeat1(choice(
			$._text_query,
			$.__comma,
		)),
		
		_queryOption: $ => prec.right(choice(
			alias($._queryOptionName, $.optionName),
			seq(
				optional(alias($._queryOptionName, $.optionName)),
				$.__ROLLQUERY_COMMA,
				optional(alias($._queryOptionValue, $.optionValue)),
			),
		)),
		
		_queryOptionName: $ => repeat1($._text_query),
		
		_text_queryOptionValue: $ => choice(
			/[^}|?{,()&]/,	//new lines are allowed, but end up being removed or replaced with a space
			$.__questionmark,
			$.__leftBrace,
			$.__leftParen,
			$.__rightParen,
			$._placeholder,
			$.hash,
			$._htmlEntity_or_ampersand,
		),
		
		_queryOptionValue: $ => repeat1(choice(
			$._text_queryOptionValue,
			$.rollQuery,
			//TODO:
			//$.property,
			//$.button,
		)),
		
		
		
		
		__questionmark: 	_atDepth(/\?/, /#63|#[xX](00)?3[fF]|quest/),
		__leftBrace: 		_atDepth(/\{/, /#123|#[xX](00)?7[bB]|lcub|lbrace/),
		__pipe: 			_atDepth(/\|/, /#124|#[xX](00)?7[cC]|vert|verbar|VerticalLine/),
		__comma: 			_atDepth(/,/, /#44|#[xX](00)?2[cC]|comma/),
		__rightBrace: 		_atDepth(/\}/, /#125|#[xX](00)?7[dD]|rcub|rbrace/),
		__leftBracket: 		_atDepth(/\[/, /#91|#[xX](00)?5[bB]|lsqb|lbrack/),
		__rightBracket: 	_atDepth(/\]/, /#93|#[xX](00)?5[dD]|rsqb|rbrack/),
		__leftParen: 		_atDepth(/\(/, /#40|#[xX](00)?28|lpar/),
		__rightParen: 		_atDepth(/\)/, /#41|#[xX](00)?29|rpar/),
		
		__ampersand: $ => choice( $.__AMP_AT_DEPTH, $.__AMP_AT_OR_ABOVE_DEPTH, ),
		
		__inlineRoll_start: _atOrAboveDepth_pair(
			/\[\[/,
			/\[/,
			/#91|#[xX](00)?5[bB]|lsqb|lbrack/,
			/\[/,
			/#91|#[xX](00)?5[bB]|lsqb|lbrack/,
		),
		__inlineRoll_end: _atDepth_pair(
			/\]\]/,
			/\]/,
			/#93|#[xX](00)?5[dD]|rsqb|rbrack/,
			/\]/,
			/#93|#[xX](00)?5[dD]|rsqb|rbrack/,
		),
		__tableRoll_start: _atOrAboveDepth_pair(
			/[tT]\[/,
			/[tT]/,
			/#116|#[xX](00)?74|#84|#[xX](00)?54/,
			/\[/,
			/#91|#[xX](00)?5[bB]|lsqb|lbrack/,
		),
		/*__rollQuery_start: $ => prec("charPair", choice(
			seq(
				_atOrAboveDepth(/\?/, /#63|#[xX](00)?3[fF]|quest/)($),
				_atOrAboveDepth(/\{/, /#123|#[xX](00)?7[bB]|lcub|lbrace/)($),
			),
		)),*/
		
		
	},
});
