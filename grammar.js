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



let _depth = -1;

function incrementDepth(){
	_depth++;
	return "";
}
function decrementDepth(){
	_depth--;
	return "";
}

function _atDepth(charRxp, htmlEscapeRxp){
	if(_depth <= 0) return new RegExp(charRxp);
	return new RegExp(`&(amp;){${_depth-1}}(${htmlEscapeRxp})`);
}
function _atOrAboveDepth(charRxp, htmlEscapeRxp){
	if(_depth <= 0) return new RegExp(charRxp);
	return new RegExp(`${charRxp}|&(amp;){0,${_depth-1}}(${htmlEscapeRxp})`);
}

const __leftBrace 		= () => _atDepth("\\{", "#123|#[xX](00)?7[bB]|lcub|lbrace");
const __pipe 			= () => _atDepth("\\|", "#124|#[xX](00)?7[cC]|vert|verbar|VerticalLine");
const __comma 			= () => _atDepth(",", "#44|#[xX](00)?2[cC]|comma");
const __rightBrace 		= () => _atDepth("\\}", "#125|#[xX](00)?7[dD]|rcub|rbrace");
const __leftBracket 	= () => _atDepth("\\[", "#91|#[xX](00)?5[bB]|lsqb|lbrack");
const __rightBracket 	= () => _atDepth("\\]", "#93|#[xX](00)?5[dD]|rsqb|rbrack");
const __leftParen 		= () => _atDepth("\\(", "#40|#[xX](00)?28|lpar");
const __rightParen 		= () => _atDepth("\\)", "#41|#[xX](00)?29|rpar");
const __slash 			= () => _atDepth("/", "#47|#[xX](00)?2[fF]|sol");
const __asterisk 		= () => _atDepth("\\*", "#42|#[xX](00)?2[aA]|ast");
const __plus 			= () => _atDepth("\\+", "#43|#[xX](00)?2[bB]|plus");
const __dash 			= () => _atDepth("\\-", "#45|#[xX](00)?2[dD]|dash|hyphen");
const __ampersand 		= () => _atDepth("&", "#38|#[xX](00)?26|amp|AMP");
const __d 				= () => _atOrAboveDepth("[dD]", "#100|#[xX](00)?64|#68|#[xX](00)?44");
const __t 				= () => _atOrAboveDepth("[tT]", "#116|#[xX](00)?74|#84|#[xX](00)?54");
const __questionmark 	= () => _atOrAboveDepth("\\?", "#63|#[xX](00)?3[fF]|quest");
const __period 			= () => _atOrAboveDepth("\\.", "#46|#[xX](00)?2[eE]|period");

function __inlineRoll_start(){
	if(_depth <= 0) return /\[\[/;
	return new RegExp(`&(amp;){${_depth-1}}\\[&(amp;){0,${_depth-1}}\\[`);
}
function __inlineRoll_end(){
	if(_depth <= 0) return /\]\]/;
	return new RegExp(`&(amp;){${_depth-1}}\\]&(amp;){0,${_depth-1}}\\]`);
}
function __tableRoll_start(){
	if(_depth <= 0) return /[tT]\[/;
	return new RegExp(`&(amp;){${_depth-1}}[tT]&(amp;){0,${_depth-1}}\\[`);
}
function __rollQuery_start(){
	if(_depth <= 0) return /\?\{/;
	return new RegExp(`&(amp;){${_depth-1}}\\?&(amp;){0,${_depth-1}}\\{`);
}



module.exports = grammar({
	name: "roll20_script",
	
	externals: $ => [
		//$.INCREMENT_DEPTH,
		//$.DECREMENT_DEPTH,
		//$.AMP_SERIES,
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
			$._IrPh,	//attributes, abilities, inline rolls
			$.hash,
			$.htmlEntity,
			
			$.rollQuery,
			
			//TODO:
			//template
			//property
			//ability command button
			//tracker
			
			/./,
		)),
		
		_wsp: $ => /\s+/,
		
		htmlEntity: $ => token(seq(
			__ampersand(),
			choice(
				/[0-9a-zA-Z]+/,
				seq(
					"#",
					/\d+|[xX][0-9a-fA-F]+/,
				),
			),
			";",
		)),
		
		
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
			$._$inlineRoll_start,
			$.formula,
			$._$inlineRoll_end,
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
		
		formula: $ => seq(
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
		),
		
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
			$._$leftParen,
			$.formula,
			$._$rightParen,
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
			$._$leftBracket,
			optional($.labelText),
			$._$rightBracket,
		),
		
		labelText: $ => seq(
			choice(
				/[^#\[\]\r\n{|,}()&]/,
				$._$leftBrace,
				$._$pipe,
				$._$comma,
				$._$rightBrace,
				$._$leftParen,
				$._$rightParen,
				$._$ampersand,
				$._placeholder,
				$.hash,
				$.htmlEntity,
			),
			repeat(choice(
					/[^#\]\r\n{|,}()&]/,
					$._$leftBrace,
					$._$pipe,
					$._$comma,
					$._$rightBrace,
					$._$leftParen,
					$._$rightParen,
					$._$ampersand,
					$._placeholder,
					$.hash,
					$.htmlEntity,
			)),
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
		
		diceRoll: $ => seq(
			optional(alias($._integer, $.count)),
			/[dD]/,
			choice(
				alias($._integer, $.sides),
				alias(/[fF]/, $.fate),
			),
			optional(alias($._diceRoll_modifiers, $.modifiers)),
		),
		
		_diceRoll_modifiers: $ => repeat1(choice(
			$._integer,
			/[aAcCdDfFhHkKlLmMoOpPrRsStT<=>!]+/,
		)),
		
		
		/*┌──────────────────────────────
		  │ Group Roll
		  └──────────────────────────────*/
		
		groupRoll: $ => seq(
			$._$leftBrace,
			$.formula,
			repeat(seq(
				$._$comma,
				$.formula,
			)),
			$._$rightBrace,
			optional(alias($._groupRoll_modifiers, $.modifiers)),
		),
		
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
			$._$tableRoll_start,
			$.tableName,
			$._$rightBracket,
		),
		
		tableName: $ => repeat1(choice(
			/[^#\]\r\n{|,}()&]/,
			$._$leftBrace,
			$._$pipe,
			$._$comma,
			$._$rightBrace,
			$._$leftParen,
			$._$rightParen,
			$._$ampersand,
			$._placeholder,
			$.hash,
			$.htmlEntity,
		)),
		
		
		/*╔════════════════════════════════════════════════════════════
		  ║ Roll Queries
		  ╚════════════════════════════════════════════════════════════*/
		
		rollQuery: $ => seq(
			$._$rollQuery_start,
			incrementDepth(),
			choice(
				alias($._queryText_pdv, $.prompt),
				seq(
					optional(alias($._queryText_pdv, $.prompt)),
					$._$pipe,
					optional(choice(
						alias($._queryText_pdv, $.defaultValue),
						seq(
							optional(alias($._queryOption, $.option)),
							repeat1(seq(
								$._$pipe,
								optional(alias($._queryOption, $.option)),
							)),
						),
					)),
				),
			),
			decrementDepth(),
			$._$rightBrace,
		),
		
		_queryText: $ => choice(
			/[^}|{,()&]/,	//new lines are allowed, but end up being removed or replaced with a space
			$._$leftBrace,
			$._$leftParen,
			$._$rightParen,
			$._$ampersand,
			$._placeholder,
			$.hash,
			$.htmlEntity,
		),
		
		_queryText_pdv: $ => repeat1(choice(
			$._queryText,
			$._$comma,
		)),
		
		_queryOption: $ => choice(
			alias($._queryOptionName, $.optionName),
			seq(
				optional(alias($._queryOptionName, $.optionName)),
				$._$comma,
				optional(alias($._queryOptionValue, $.optionValue)),
			),
		),
		
		_queryOptionName: $ => repeat1($._queryText),
		
		_queryOptionValue: $ => repeat1(choice(
			$._queryText,
			$.rollQuery,
			//TODO:
			//$.property,
			//$.button,
		)),
		
		
		
		
		_$leftBrace: $ => __leftBrace(),
		_$pipe: $ => __pipe(),
		_$comma: $ => __comma(),
		_$rightBrace: $ => __rightBrace(),
		_$leftBracket: $ => __leftBracket(),
		_$rightBracket: $ => __rightBracket(),
		_$leftParen: $ => __leftParen(),
		_$rightParen: $ => __rightParen(),
		_$slash: $ => __slash(),
		_$asterisk: $ => __asterisk(),
		_$plus: $ => __plus(),
		_$dash: $ => __dash(),
		_$ampersand: $ => __ampersand(),
		_$d: $ => __d(),
		_$t: $ => __t(),
		_$questionmark: $ => __questionmark(),
		_$period: $ => __period(),
		
		_$inlineRoll_start: $ => __inlineRoll_start(),
		_$inlineRoll_end: $ => __inlineRoll_end(),
		_$tableRoll_start: $ => __tableRoll_start(),
		_$rollQuery_start: $ => __rollQuery_start(),
		
		
	},
});
