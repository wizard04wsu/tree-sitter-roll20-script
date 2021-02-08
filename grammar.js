let depth = 0;
//const increaseDepth = $ => { ++depth; return /()/; };
//const decreaseDepth = $ => { --depth; return /()/; };
const matchChar = (char, depth = 0) => {
	switch(char){
		case "@": return unescapedAtSurface(depth, char, /commat/, 64, /[xX](00)?40/);
		case "%": return unescapedAtSurface(depth, char, /percnt/, 37, /[xX](00)?25/);
		case "#": return unescapedAtSurface(depth, char, /num/, 35, /[xX](00)?23/);
		case "&": return unescapedAtSurface(depth, char, /amp|AMP/, 38, /[xX](00)?26/);
		case "[": return unescapedAtSurfaceOrBelow(depth, char, /lsqb|lbrack/, 91, /[xX](00)?5[bB]/);
		case "(": return unescapedAtSurfaceOrBelow(depth, char, /lpar/, 40, /[xX](00)?28/);
		case "{": return unescapedAtSurfaceOrBelow(depth, char, /lbrace|lcub/, 123, /[xX](00)?7[bB]/);
		case "+": return unescapedAtSurfaceOrBelow(depth, char, /plus/, 43, /[xX](00)?2[bB]/);
		case "-": return unescapedAtSurfaceOrBelow(depth, char, /hyphen|dash/, 45, /(00)?2[dD]/);
		case "}": return unescapedAtSurface(depth, char, /rbrace|rcub/, 125, /[xX](00)?7[dD]/);
		case ")": return unescapedAtSurfaceOrBelow(depth, char, /rpar/, 41, /[xX](00)?29/);
		case "]": return unescapedAtSurfaceOrBelow(depth, char, /rsqb|rbrack/, 93, /[xX](00)?5[dD]?/);
		case "|": return unescapedAtSurface(depth, char, /verbar|vert|VerticalLine/, 124, /[xX](00)?7[cC]/);
		case "?": return unescapedAtSurfaceOrBelow(depth, char, /quest/, 63, /[xX](00)?3[fF]/);
		case ",": return unescapedAtSurface(depth, char, /comma/, 44, /[xX](00)?2[cC]/);
		case "=": return unescapedAtSurfaceOrBelow(depth, char, /equals/, 61, /[xX](00)?3[dD]/);
		case "~": return unescapedAtSurfaceOrBelow(depth, char, null, 126, /[xX](00)?7[eE]/);
		default: return escapedAtSurface(depth, /[a-zA-Z\d]+/, /\d+/, /([a-fA-F\d]{2}){1,2}/);
	}
};
const escapedAtSurface = (depth, strRxp, decNumRxp, hexNumRxp) => {
	return $ => {
		let args = ["&"];
		
		while(depth-- > 0){
			args.push(choice(
				/amp|AMP/,
				seq( alias("#", $.macroHash), /38|[xX](00)?26/ ),
			));
			args.push(";");
		}
		if(strRxp !== null){
			args.push(choice(
				RegExp(strRxp),
				seq(
					alias("#", $.macroHash),
					choice(
						RegExp(decNumRxp),
						seq( /[xX]/, RegExp(hexNumRxp) ),
					),
				),
			));
		}
		else{
			args.push(seq(
				alias("#", $.macroHash),
				choice(
					RegExp(decNumRxp),
					seq( /[xX]/, RegExp(hexNumRxp) ),
				),
			));
		}
		args.push(";");
		
		return seq.apply(null, args);
	};
};
const unescapedAtSurface = (depth, char, strRxp, decNumRxp, hexNumRxp) => {
	if(!depth) return $ => char;
	return escapedAtSurface(depth-1, strRxp, decNumRxp, hexNumRxp);
};
const unescapedAtSurfaceOrBelow = (depth, char, strRxp, decNumRxp, hexNumRxp) => {
	if(!depth) return $ => char;
	return $ => choice(
		char,
		unescapedAtSurface(depth, char, strRxp, decNumRxp, hexNumRxp)($)
	);
};


const chainOf = (rule) => prec.right(repeat1(rule));


module.exports = grammar({
	name: 'roll20_script',
	
	externals: $ => [
		$.__EOF,					// (no content) determines if there are no more tokens
		
		$.__just_at,				// returns "@" if it does *not* begin an attribute
		$.__attribute_start,		// returns "@" if it begins an attribute
		
		$.__just_percent,			// returns "%" if it does *not* begin an ability
		$.__ability_start,			// returns "%" if it begins an ability
		
		$.__just_hash,				// returns "#" if it does *not* reference a macro
		$.__macro_start,			// returns "#" if it could be refrencing a macro
		
		$.__just_d,					// returns "d" or "D" if it does *not* begin a dice roll
		$.__diceRoll_start,			// returns "d" or "D" if it begins a dice roll
		
		$.__just_t,					// returns "t" or "T" if it does *not* begin a table roll
		$.__tableRoll_start,		// returns "t" or "T" if it begins a table roll
		
		$.__just_questionmark,		// returns "?" if it does *not* begin a roll query
		$.__rollQuery_start,		// returns "?" (or equivalent HTML entity) if it begins a roll query
		$.__rollQuery_pipe_hasDefault,	// returns "|" (or equivalent HTML entity) if it has a default value (i.e., only one option)
		$.__rollQuery_pipe_hasOptions,	// returns "|" (or equivalent HTML entity) if it has multiple options
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
				$.attribute,
				$.ability,
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
		
		/*_string: $ => prec.right(seq(
			chainOf(/[^#]|# /),
			optional(seq( "#", $.__EOF )),
		)),*/
		_stringNL: $ => prec.right(choice(
			seq(
				chainOf(/[^#]|# |#?\r?\n/),
				optional(seq( "#", $.__EOF )),
			),
			seq( "#", $.__EOF ),
		)),
		
		_wsp_inline: $ => /\s+/,
		
		
		/*┌──────────────────────────────
		  │ Special Characters
		  └──────────────────────────────*/
		
		//__increaseDepth: increaseDepth,
		//__decreaseDepth: increaseDepth,
		
		_at: matchChar("@", depth),
		_at1: matchChar("@", depth+1),
		_percent: matchChar("%", depth),
		_percent1: matchChar("%", depth+1),
		_hash: matchChar("#", depth),
		_hash1: matchChar("#", depth+1),
		_ampersand: matchChar("&", depth),
		_ampersand1: matchChar("&", depth+1),
		_leftBracket: matchChar("[", depth),
		_leftBracket1: matchChar("[", depth+1),
		_leftParen: matchChar("(", depth),
		_leftParen1: matchChar("(", depth+1),
		_leftBrace: matchChar("{", depth),
		_leftBrace1: matchChar("{", depth+1),
		_plus: matchChar("+", depth),
		_plus1: matchChar("+", depth+1),
		_minus: matchChar("-", depth),
		_minus1: matchChar("-", depth+1),
		_rightBrace: matchChar("}", depth),
		_rightBrace1: matchChar("}", depth+1),
		_rightParen: matchChar(")", depth),
		_rightParen1: matchChar(")", depth+1),
		_rightBracket: matchChar("]", depth),
		_rightBracket1: matchChar("]", depth+1),
		_pipe: matchChar("|", depth),
		_pipe1: matchChar("|", depth+1),
		_questionMark: matchChar("?", depth),
		_questionMark1: matchChar("?", depth+1),
		_comma: matchChar(",", depth),
		_comma1: matchChar(",", depth+1),
		_equals: matchChar("=", depth),
		_equals1: matchChar("=", depth+1),
		_tilde: matchChar("~", depth),
		_tilde1: matchChar("~", depth+1),
		
		htmlEntity: $ => prec(1, matchChar()($)),
		_escapedHtmlEntity: $ => prec(1, matchChar(void 0, depth+2)($)),
		
		
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
		_propertyName: $ => choice(
			$._propertyName_notMacroName,
			seq(
				optional($._propertyName_notMacroName),
				alias($.__macro_start, $.macroHash),
				$._propertyName_macroName,
				repeat(seq(
					/ |\r?\n/,
					optional($._propertyName_notMacroName),
					alias($.__macro_start, $.macroHash),
					$._propertyName_macroName,
				)),
				optional(seq(
					/ |\r?\n/,
					$._propertyName_notMacroName
				)),
			),
		),
		_propertyName_notMacroName: $ => prec.right(repeat1(choice(
			/[^@%#}|\r\n]+/,
			//$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			//$._ampersand,
			alias(/[@%]\{/, $.invalid),
		))),
		_propertyName_macroName: $ => prec.right(repeat1(choice(
			/[^@%}| \r\n]+/,
			//$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			//$._ampersand,
			alias(/[@%]\{/, $.invalid),
		))),
		_selector: $ => choice(
			$._tokenSelector,
			alias($._propertyName, $.characterName),
		),
		
		_placeholders: $ => prec.right(repeat1(choice( $.attribute, $.ability ))),
		
		
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
				/[^@% \r\n]/,
				$.attribute,
				$.ability,
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
			alias($._rollQuery_invalid_start, $.invalid),
		),
		rollQuery: $ => {
			depth++;
			let result = choice(
				alias($._rollQuery_empty, $.invalid),
				seq(
					$.__rollQuery_start,
					alias($._leftBrace, $.LEFT),
					$._rollQuery_content,
					alias($._rightBrace, $.RIGHT),
				),
			);
			depth--;
			return result;
		},
		_rollQuery_empty: $ => seq( $.__rollQuery_start, $._leftBrace, $._rightBrace ),
		_rollQuery_invalid_start: $ => seq( $._questionMark, $._leftBrace ),
		_rollQuery_content: $ => seq(
			choice(
				$.prompt,
				prec.right(1, seq(
					optional($.prompt),
					choice(
						seq(
							$.__rollQuery_pipe_hasDefault,
							optional($.defaultValue),
						),
						seq(
							$.__rollQuery_pipe_hasOptions,
							optional(seq(
								optional($.option),
								alias($._pipe, $.PIPE),
								optional($.option),
								repeat(
									seq(
										alias($._pipe, $.PIPE),
										optional($.option),
									),
								),
							)),
						),
					),
				)),
			),
		),
		
		/*prompt: $ => prec.right(repeat1(choice(
			///[^@%#&}|]+/,
			/[^}|]+/,
			$.attribute,
			$.ability,
			$.__macro_start,
			//$.htmlEntity,
			//$._at,
			//$._percent,
			//$._ampersand,
		))),*/
		prompt: $ => $._propertyName,
		
		defaultValue: $ => seq(
			repeat1(
				choice(
					/[^@%}|]+|[@%]/,
					$.attribute,
					$.ability,
					//alias($._escapedHtmlEntity, $.htmlEntity),
				),
			),
		),
		
		option: $ => prec.right(seq(
			$.optionName,
			optional(seq(
				$._comma,
				optional($.optionValue),
			)),
		)),
		optionName: $ => seq(
			prec.right(repeat1(
				prec(1, choice(
					/[^@%#&}|,]+/,
					$.attribute,
					$.ability,
					alias($.__macro_start, $.macroHash),
					//$.htmlEntity,
					$._at,
					$._percent,
					$._ampersand,
				)),
			)),
		),
		optionValue: $ => seq(
			prec.right(repeat1(
				choice(
					/[^@%#&}|,?{]+/,
					$.attribute,
					$.ability,
					alias($.__macro_start, $.macroHash),
					//$.htmlEntity,
					seq(
						//$.__increaseDepth,
						$.rollQuery,
						//$.__decreaseDepth,
					),
					//$.property,
					//$.button,
					$._at,
					$._percent,
					$._ampersand,
					$._questionMark,
					$._leftBrace,
				),
			)),
		),
		
		
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
			$._element_parenthesized,
			$._element_groupRoll,
			$._element_diceRoll,
			$._element_tableRoll,
			$._element_number_signed,
			//TODO: query
			seq(
				$._placeholders,
				optional($._macro),
			),
			$._macro,
			$._element_invalid,
		)),
		_element_next: $ => prec.right(1, choice(
			$._element_parenthesized,
			$._element_groupRoll,
			$._element_diceRoll,
			$._element_tableRoll,
			$._element_number_unsigned,
			//TODO: query
			seq(
				$._placeholders,
				optional($._macro),
			),
			$._macro,
			$._element_invalid,
		)),
		
		_element_invalid: $ => seq(
			optional($._placeholders),
			alias($._element_invalid_2, $.invalid),
			optional($._macro),
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
			$._leftBracket,
			optional(choice(
				$._label_notMacroName,
				seq(
					optional($._label_notMacroName),
					alias($.__macro_start, $.macroHash),
					$._label_macroName,
					repeat(seq(
						/ |\r?\n/,
						optional($._label_notMacroName),
						alias($.__macro_start, $.macroHash),
						$._label_macroName,
					)),
					optional(seq(
						/ |\r?\n/,
						$._label_notMacroName
					)),
				),
			)),
			$._rightBracket,
		),
		_label_notMacroName: $ => repeat1(choice(
			/[^@%#&\[\r\n\]]+/,
			$.attribute,
			$.ability,
			//$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			$._ampersand,
		)),
		_label_macroName: $ => repeat1(choice(
			/[^@%&\[ \r\n\]]+/,
			$.attribute,
			$.ability,
			//$.htmlEntity,
			$.__just_at,
			$.__just_percent,
			$._ampersand,
		)),
		
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
				optional($._macro),
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
			optional($._macro),
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
			optional($._macro),
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
			optional($._macro),
		),
		
		tableRoll: $ => seq(
			//count: number of "dice" (optional)
			optional(alias($._unsigned_integer_with_placeholders, $.count)),
			//keyword (the letter 't')
			$.__tableRoll_start,
			$._leftBracket,
			//table name
			$.tableName,
			$._rightBracket,
		),
		tableName: $ => choice(
			$._tableRoll_notMacroName,
			seq(
				optional($._tableRoll_notMacroName),
				alias($.__macro_start, $.macroHash),
				$._tableRoll_macroName,
				repeat(seq(
					/ |\r?\n/,
					optional($._tableRoll_notMacroName),
					alias($.__macro_start, $.macroHash),
					$._tableRoll_macroName,
				)),
				optional(seq(
					/ |\r?\n/,
					$._tableRoll_notMacroName
				)),
			),
		),
		_tableRoll_notMacroName: $ => repeat1(choice(
			/[^@%#&\r\n\]]+/,
			$.attribute,
			$.ability,
			prec(1, "@{"),
			prec(1, "%{"),
			$.__just_at,
			$.__just_percent,
			$._ampersand,
		)),
		_tableRoll_macroName: $ => repeat1(choice(
			/[^@%& \r\n\]]+/,
			$.attribute,
			$.ability,
			prec(1, "@{"),
			prec(1, "%{"),
			$.__just_at,
			$.__just_percent,
			$._ampersand,
		)),
		
		
	},
});
