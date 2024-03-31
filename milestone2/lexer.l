%{
#include <iostream>
#include <stack>
#include <cstdlib>
#include "parser.hpp"
#include "ast.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <FlexLexer.h>
using namespace std;

int indent_stack[1000];
int top = -1;
int dedent_level = 0;  
bool ended = false;
void handle_dedent(){
  top--;
}

char firstChar;
char *copyyytext;
char* string_literal_value = NULL;
int lno=1;

%}

%option yylineno

%x DEDENTATION
decinteger      {nonzerodigit}([_]*[0-9])*
bininteger      0[xX]([_]?{bindigit})+
octinteger      0[oO]([_]?{octdigit})+
hexinteger      0[xX]([_]?{hexdigit})+
nonzerodigit    [1-9]
digit           [0-9]
bindigit        [0-1]
octdigit        [0-7]
hexdigit        ({digit}|[a-f]|[A-F])
number          {decinteger}|{bininteger}|{octinteger}|{hexinteger}|[0]
literal  (\"([^\"]|\\.)*\")|(\'([^\']|\\.)*\')
floatnumber     ({pointfloat})|({exponentfloat})
pointfloat      ({digitpart})?{fraction}|({digitpart}"."{digitpart})
exponentfloat   ({digitpart}|{pointfloat}){exponent}
digitpart       {digit}([_]?{digit})*
fraction        "."{digitpart}
exponent        [eE][+-]?{digitpart}
%%

%{
  
  if (top == -1) {
        indent_stack[++top] = 0;
    }

  
  #define PUSH_TOKEN(cat, lexeme,token) \
    yylval.node = create_node(lexeme);\
    if( token != "")\
    {\
      yylval.node->type = token;\
      yylval.node->category = token;\
    }\
    return cat;
%}

^[ \t]*\r?\n   { /* Skip blank lines */ }

^[ \t]*#.*\r?\n    { /* Skip whole-line comments. */ }

#.*$             { /* Skip comments on the same line as a statement. */ }


^[^ \t\n]+ {
    if (indent_stack[top]!= 0){
        copyyytext=strdup(yytext);
        firstChar = yytext[0];
        unput(yytext[0]);
        BEGIN(DEDENTATION);
    }
    else
    {
        REJECT;
    }
}

^[ \t]+  {
    if (indent_stack[top] < yyleng) {
        indent_stack[++top] = yyleng;
     
        PUSH_TOKEN(INDENT, "INDENT","");
    } else if (indent_stack[top] > yyleng) {
        dedent_level=yyleng;
        unput(32);/*32 for space*/
        BEGIN(DEDENTATION);
    }
}


<DEDENTATION>[ ] {
        if (top >= 0 && indent_stack[top] != dedent_level) {
            top = top-1;
          
            unput(32);
            PUSH_TOKEN(DEDENT, "DEDENT","");
        }
        else
        {
            dedent_level=0;
            BEGIN(INITIAL);
        }

        if (top == -1) {
            fprintf(stderr, "Error: Incorrect indentation on line %d\n", yylineno);
            exit(1);
        }
}

<DEDENTATION>[^ \t\n] {
    if (indent_stack[top] != 0) {
        top--;
        unput(yytext[0]);
      
        PUSH_TOKEN(DEDENT, "DEDENT","");
    }
    else
    {
        for (int i = strlen(copyyytext) - 1; i >= 0; i--) {
            unput(copyyytext[i]);
        }
    BEGIN(INITIAL);
    }
    
}

<<EOF>>    {
    while (top >0) {
        top--;
    PUSH_TOKEN(DEDENT, "DEDENT","");
    }
    if(ended) return 0;
    ended = true;
    PUSH_TOKEN(ENDMARKER, "ENDMARKER" , "");
    unput(yytext[0]);
}
\r?\n {
    PUSH_TOKEN(NEWLINE,"NEWLINE","");
}
[ \t]       { /* Ignore spaces that haven't been handled above. */ }

False       { PUSH_TOKEN(FALSE_TOKEN, "FALSE_TOKEN", "BOOLEAN"); }
await       { PUSH_TOKEN(AWAIT, "AWAIT", "BOOLEAN"); }
else        { PUSH_TOKEN(ELSE, "ELSE", "KEYWORD"); }
import      { PUSH_TOKEN(IMPORT, "IMPORT", "KEYWORD"); }
pass        { PUSH_TOKEN(PASS, "PASS", "KEYWORD"); }

None        { PUSH_TOKEN(NONE, "NONE", "KEYWORD"); }
break       { PUSH_TOKEN(BREAK, "BREAK", "KEYWORD"); }
except      { PUSH_TOKEN(EXCEPT, "EXCEPT", "KEYWORD"); }
in          { PUSH_TOKEN(IN, "IN", "KEYWORD"); }
raise       { PUSH_TOKEN(RAISE, "RAISE", "KEYWORD"); }

True        { PUSH_TOKEN(TRUE_TOKEN, "TRUE_TOKEN", "KEYWORD"); }
class       { PUSH_TOKEN(CLASS, "CLASS", "KEYWORD"); }
finally     { PUSH_TOKEN(FINALLY, "FINALLY", "KEYWORD"); }
is          { PUSH_TOKEN(IS, "IS", "KEYWORD"); }
return      { PUSH_TOKEN(RETURN, "RETURN", "KEYWORD"); }

and         { PUSH_TOKEN(AND, "AND", "OPERATOR"); }
continue    { PUSH_TOKEN(CONTINUE, "CONTINUE", "KEYWORD"); }
for         { PUSH_TOKEN(FOR, "FOR", "KEYWORD"); }
lambda      { PUSH_TOKEN(LAMBDA, "LAMBDA", "KEYWORD"); }
try         { PUSH_TOKEN(TRY, "TRY", "KEYWORD"); }

as          { PUSH_TOKEN(AS, "AS", "KEYWORD"); }
def         { PUSH_TOKEN(DEF, "DEF", "KEYWORD"); }
from        { PUSH_TOKEN(FROM, "FROM", "KEYWORD"); }
nonlocal    { PUSH_TOKEN(NONLOCAL, "NONLOCAL", "KEYWORD"); }
while       { PUSH_TOKEN(WHILE, "WHILE", "KEYWORD"); }

assert      { PUSH_TOKEN(ASSERT, "ASSERT", "KEYWORD"); }
del         { PUSH_TOKEN(DEL, "DEL", "KEYWORD"); }
global      { PUSH_TOKEN(GLOBAL, "GLOBAL", "KEYWORD"); }
not         { PUSH_TOKEN(NOT, "NOT", "OPERATOR"); }
with        { PUSH_TOKEN(WITH, "WITH", "KEYWORD"); }

async       { PUSH_TOKEN(ASYNC, "ASYNC", "KEYWORD"); }
elif        { PUSH_TOKEN(ELIF, "ELIF", "KEYWORD"); }
if          { PUSH_TOKEN(IF, "IF", "KEYWORD"); }
or          { PUSH_TOKEN(OR, "OR", "OPERATOR"); }
yield       { PUSH_TOKEN(YIELD, "YIELD", "KEYWORD"); }

[a-zA-Z_][a-zA-Z0-9_]*  {     
                            // yylval.node = create_node(yytext);
                            // yylval.node->category = "NAME";
                            PUSH_TOKEN(NAME, yytext,"NAME"); }
{literal} { PUSH_TOKEN(STRING, yytext,"STRING");}

{floatnumber}       { PUSH_TOKEN(FLOAT, yytext, "FLOAT"); }

{number}     { PUSH_TOKEN(NUMBER, yytext , "INTEGER"); }
"+"         { PUSH_TOKEN(PLUS, "+", "OPERATOR"); }
"-"         { PUSH_TOKEN(MINUS, "-", "OPERATOR"); }
"*"         { PUSH_TOKEN(TIMES, "*", "OPERATOR"); }
"**"        { PUSH_TOKEN(POWER, "**", "OPERATOR"); }
"/"         { PUSH_TOKEN(DIVIDEDBY, "/", "OPERATOR"); }
"//"        { PUSH_TOKEN(FLOORDIV, "//", "OPERATOR"); }
"%"         { PUSH_TOKEN(MODULO, "%", "OPERATOR"); }
"@"         { PUSH_TOKEN(AT, "@", "OPERATOR"); }

"<<"        { PUSH_TOKEN(SHIFT_LEFT, "<<", "OPERATOR"); }
">>"        { PUSH_TOKEN(SHIFT_RIGHT, ">>", "OPERATOR"); }
"&"         { PUSH_TOKEN(BITWISE_AND, "&", "OPERATOR"); }
"|"         { PUSH_TOKEN(BITWISE_OR, "|", "OPERATOR"); }
"^"         { PUSH_TOKEN(BITWISE_XOR, "^", "OPERATOR"); }
"~"         { PUSH_TOKEN(BITWISE_NOT, "~", "OPERATOR"); }

"<"         { PUSH_TOKEN(LESS_THAN, "<", "OPERATOR"); }
">"         { PUSH_TOKEN(GREATER_THAN, ">", "OPERATOR"); }
"<="        { PUSH_TOKEN(LESS_THAN_OR_EQUAL, "<=", "OPERATOR"); }
">="        { PUSH_TOKEN(GREATER_THAN_OR_EQUAL, ">=", "OPERATOR"); }
"=="        { PUSH_TOKEN(EQUAL, "==", "OPERATOR"); }
"!="        { PUSH_TOKEN(NOT_EQUAL, "!=", "OPERATOR"); }

"("         { PUSH_TOKEN(LPAREN, "(", "DELIMITER"); }
")"         { PUSH_TOKEN(RPAREN, ")", "DELIMITER"); }
"["         { PUSH_TOKEN(LBRACKET, "[", "DELIMITER"); }
"]"         { PUSH_TOKEN(RBRACKET, "]", "DELIMITER"); }
"{"         { PUSH_TOKEN(LBRACE, "{", "DELIMITER"); }
"}"         { PUSH_TOKEN(RBRACE, "}", "DELIMITER"); }

","         { PUSH_TOKEN(COMMA, ",", "DELIMITER"); }
":"         { PUSH_TOKEN(COLON, ":", "DELIMITER"); }
"."         { PUSH_TOKEN(DOT, ".", "DELIMITER"); }
";"         { PUSH_TOKEN(SEMICOLON, ";", "DELIMITER"); }
"="         { PUSH_TOKEN(EQUAL_SIGN, "=", "OPERATOR"); }
"->"        { PUSH_TOKEN(ARROW, "->", "DELIMITER"); }

"+="        { PUSH_TOKEN(PLUS_EQUAL, "+=", "OPERATOR"); }
"-="        { PUSH_TOKEN(MINUS_EQUAL, "-=", "OPERATOR"); }
"*="        { PUSH_TOKEN(TIMES_EQUAL, "*=", "OPERATOR"); }
"/="        { PUSH_TOKEN(DIVIDEDBY_EQUAL, "/=", "OPERATOR"); }
"//="       { PUSH_TOKEN(FLOORDIV_EQUAL, "//=", "OPERATOR"); }
"%="        { PUSH_TOKEN(MODULO_EQUAL, "%=", "OPERATOR"); }
"@="        { PUSH_TOKEN(AT_EQUAL, "@=", "OPERATOR"); }
"&="        { PUSH_TOKEN(BITWISE_AND_EQUAL, "&=", "OPERATOR"); }
"|="        { PUSH_TOKEN(BITWISE_OR_EQUAL, "|=", "OPERATOR"); }
"^="        { PUSH_TOKEN(BITWISE_XOR_EQUAL, "^=", "OPERATOR"); }
">>="       { PUSH_TOKEN(SHIFT_RIGHT_EQUAL, ">>=", "OPERATOR"); }
"<<="       { PUSH_TOKEN(SHIFT_LEFT_EQUAL, "<<=", "OPERATOR"); }
"**="       { PUSH_TOKEN(POWER_EQUAL, "**=", "OPERATOR"); }

"'"         { PUSH_TOKEN(SINGLE_QUOTE, "'", "DELIMITER"); }
"\""        { PUSH_TOKEN(DOUBLE_QUOTE, "\"", "DELIMITER"); }
"#"         { PUSH_TOKEN(HASH, "#", "DELIMITER"); }
"\\"        { PUSH_TOKEN(BACKSLASH, "\\", "DELIMITER"); }
"$"         { PUSH_TOKEN(DOLLAR, "$", "DELIMITER"); }
"?"         { PUSH_TOKEN(QUESTION_MARK, "?", "DELIMITER"); }
"`"         { PUSH_TOKEN(BACKTICK, "`", "DELIMITER"); }
"..."      { PUSH_TOKEN(TRIPLEDOT, "...", "DELIMITER"); }
.           {
              cerr << "Unrecognized token on line " << yylineno << ": "
                << yytext << endl;
              PUSH_TOKEN(yytext[0], yytext,"");
            }


%%

int yywrap(){
  return 1;
}