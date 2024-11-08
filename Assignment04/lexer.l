%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * symbol_name;
int lineno;
%}

%%
"main"    { return MAIN; }
"("	  { return LPAREN; }
")"	  { return RPAREN; }
"{"	  { return LBRACE; }
"}"	  { return RBRACE; }
"="	  { return EQUAL; }
";"       { return SEMICOLON; }
"if"      { return IF; }
"else"    { return ELSE; }
"while"   { return WHILE; }
"for"     { return FOR; }
"do"      { return DO; }
"return"  { return RETURN; }
","       { return COMMA; }
"int"     { return INT; }
"float"   { return FLOAT; }
"char"    { return CHAR; }
"void"    { return VOID; }
"+"       { return PLUS; }
"-"       { return MINUS; }
"*"	  { return MUL; }
"/"	  { return DIV; }
"%"	  { return PERCENT; }
"&"       { return AND; }
"|"       { return OR; }
"!"       { return NOT; }
"<"       { return LESS; }
">"       { return GREAT; }
"~"       { return COMPLEMENT; }
"=="	  { return EQUAL_EQUAL; }
"!="      { return NOT_EQUAL; }
"<="      { return LESS_EQUAL; }
">="      { return GREAT_EQUAL; }
"++"      { return PLUS_PLUS; }
"--"      { return MINUS_MINUS; }
"+="      { return PLUS_EQUAL; }
"-="      { return MINUS_EQUAL; }
"*="      { return MUL_EQUAL; }
"/="      { return DIV_EQUAL; }
"%="      { return PERCENT_EQUAL; }
[0-9]+   { return NUM;} 
[a-zA-z][a-zA-Z0-9]*    { strcpy(symbol_name,yytext);return ID; }
"\n"     { lineno++;}
[ "\t"]* {}
.         { printf("Lexical Error at line no %d and token %s",lineno,yytext); }
%%
int yywrap()
{
	return 1;
}
