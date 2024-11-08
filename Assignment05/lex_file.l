%{
#include "y.tab.h"
#include <stdio.h>
#include <string.h>  // For strcpy

extern FILE *yyin;  // Declaring the input file pointer for `yacc`
%}

digit       [0-9]
letter      [a-zA-Z_]
id          {letter}({letter}|{digit})*

%%
"int"       { return INT; }
"float"     { return FLOAT; }
{id}        { strcpy(yylval.id, yytext); return IDENTIFIER; }
"("         { return '('; }
")"         { return ')'; }
"{"         { return '{'; }
"}"         { return '}'; }
";"         { return ';'; }
[ \t\n]     { /* Ignore whitespace */ }
.           { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}


