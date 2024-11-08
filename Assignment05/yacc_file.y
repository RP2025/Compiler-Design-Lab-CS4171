%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();  // Declare yylex()
extern void yyerror(const char *s);  // Declare yyerror()

extern FILE *yyin;  // Declare yyin here

typedef struct {
    char name[100];  // Variable name
    char type[10];   // Data type (int, float, etc.)
    char scope[10];  // Scope (global or local)
} SymbolTableEntry;

SymbolTableEntry symbolTable[100];  // Array of symbol table entries
int symbolCount = 0;  // Number of entries in the symbol table

void add_to_symbol_table(char *name, char *type, char *scope);
void print_symbol_table();
%}

%union {
    char id[100];  // For variable names and types
}

%token <id> IDENTIFIER
%token <id> INT FLOAT
%type <id> type_specifier declaration

%%

program:
    function
;

function:
    INT IDENTIFIER '(' ')' '{' declarations '}'  { 
        printf("Function parsed: %s\n", $2); 
        print_symbol_table();  // Print symbol table after function parsing
    }
;

declarations:
    /* empty */
    | declaration declarations
;

declaration:
/* int a ; */
    type_specifier IDENTIFIER ';'  { 
        add_to_symbol_table($2, $1, "local");  // Add variable to symbol table
        printf("Declared variable: %s of type: %s\n", $2, $1);
    }
;

type_specifier:
    INT   { strcpy($$, "int"); }
    | FLOAT  { strcpy($$, "float"); }
;

%%

void add_to_symbol_table(char *name, char *type, char *scope) {
    strcpy(symbolTable[symbolCount].name, name);
    strcpy(symbolTable[symbolCount].type, type);
    strcpy(symbolTable[symbolCount].scope, scope);
    symbolCount++;
}

void print_symbol_table() {
    printf("\nSymbol Table:\n");
    printf("Name\tType\tScope\n");
    printf("-------------------------\n");
    for (int i = 0; i < symbolCount; i++) {
        printf("%s\t%s\t%s\n", symbolTable[i].name, symbolTable[i].type, symbolTable[i].scope);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.c>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        exit(1);
    }

    yyin = file;  // Set the file as input for lex
    yyparse();    // Start parsing

    fclose(file); // Close the file after parsing
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}



/*

(start symbol ) program => function

function =>  datatype IDENTIFIER { declarations } ;

declarations => | 


scope =0;

a  10 scope 1
b   8 scope 1
a   5 scope 2
int main(){
    declaration => scope = 1;
    int a = 10;
    int b = 8
    {
        scope  = 2;
        int a =  5;;
        cout<<a; // 5
        cout<<b; // 8
    }
}

*/
