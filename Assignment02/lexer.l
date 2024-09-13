%{
#include <stdio.h>
#include <ctype.h>

int token_count = 0;

// Function to be called for each token
void print_token(const char* type, const char* text) {
    printf("| %-20s | %-25s |\n", type, text);
    token_count++;
}
%}

%%
"+"|"-"|"*"|"/"                     { print_token("ARITHMETIC_OPERATOR", yytext); }
"=="|"!="|"<="|">="|"<"|">"         { print_token("RELATIONAL_OPERATOR", yytext); }
"&&"|"||"|"!"                       { print_token("LOGICAL_OPERATOR", yytext); }
"&"|"|"|"^"|"~"|"<<"|">>"           { print_token("BITWISE_OPERATOR", yytext); }
"="|"+="|"-="|"*="|"/="|"%="|"&="   { print_token("ASSIGNMENT_OPERATOR", yytext); }

"int"|"float"|"char"|"for"|"do"|"while"|"if"|"else" { print_token("RESERVED_WORD", yytext); }

[0-9]+\.[0-9]+                     { print_token("FLOAT_CONSTANT", yytext); }
[0-9]+                             { print_token("INTEGER_CONSTANT", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*              { print_token("IDENTIFIER", yytext); }

\"(\\.|[^\\"])*\"                   { print_token("STRING_LITERAL", yytext); }
\'(\\.|[^\\'])\'                    { print_token("CHARACTER_LITERAL", yytext); }

"("                                 { print_token("PARENTHESIS_OPEN", yytext); }
")"                                 { print_token("PARENTHESIS_CLOSE", yytext); }
"{"                                 { print_token("CURLY_BRACE_OPEN", yytext); }
"}"                                 { print_token("CURLY_BRACE_CLOSE", yytext); }

"//".*                              { /* Ignore single-line comments */ }
"/*"([^*]|\*+[^*/])*\*+"/"          { /* Ignore multi-line comments */ }

[ \t\n]+                            { /* Ignore whitespace */ }

.                                   { printf("Unknown character: %s\n", yytext); }
%%

int main() {
    // Print header
    printf("+----------------------+---------------------------+\n");
    printf("| Token Type           | Token Text                 |\n");
    printf("+----------------------+---------------------------+\n");

    // Run lexer
    yylex();

    // Print footer with total count
    printf("+----------------------+---------------------------+\n");
    printf("| Total number of tokens: %d                           |\n", token_count);
    printf("+----------------------+---------------------------+\n");
    
    return 0;
}

