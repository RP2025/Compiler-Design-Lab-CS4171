%{
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
typedef struct
{
	char * name;
	uint8_t initialized;
}symbol;
symbol ** symbol_table;
uint8_t symbol_count=0;

char ** function_table;
uint8_t function_count=0;

void add_symbol(char *);
void update_symbol(char *);
void add_function(char *);
int find_symbol(char *);
int find_function(char *);
char * fn_name;
char * var_name;

int yylex();
void yyerror(const char *);

extern char* symbol_name;
extern int lineno;
%}


%union
{
	int ival;
	float fval;
	char * sval;
};

%token<ival> MAIN LPAREN RPAREN LBRACE RBRACE ID EQUAL SEMICOLON IF ELSE WHILE FOR DO RETURN COMMA INT FLOAT CHAR VOID PLUS MINUS MUL DIV PERCENT AND OR NOT LESS GREAT COMPLEMENT NUM EQUAL_EQUAL NOT_EQUAL LESS_EQUAL GREAT_EQUAL PLUS_PLUS MINUS_MINUS PLUS_EQUAL MINUS_EQUAL MUL_EQUAL DIV_EQUAL PERCENT_EQUAL

%left PLUS MINUS
%%
program : functions mainfunction;

mainfunction: MAIN LPAREN RPAREN LBRACE codes RBRACE
	     {
		printf("Parsed main function\n\n");
	     };

codes : code codes | ;
code : declarative | assignment | conditional | iterative | function_call | return;

declarative : type ID SEMICOLON
	    {
		char * variable = symbol_name;
		if(find_symbol(variable)!=-1)
		{
			printf("Error : Line no : %d : Variable %s already declared\n",lineno,variable);
			YYABORT;
		}
		else{
		add_symbol(variable);
		printf("Line no : %d : Declared variable %s\n", lineno,variable);}
                memset(symbol_name,'\0',sizeof(symbol_name));
	    } | type ID{strcpy(var_name,symbol_name);} EQUAL expr1 SEMICOLON
	    {
		if(find_symbol(var_name)!=-1)
		{
			printf("Error : Line no : %d : Variable %s already declared\n",lineno, var_name);
			YYABORT;
		}
		else{
		add_symbol(var_name);
		update_symbol(var_name);
		printf("Line no : %d : Initialized variable %s\n",lineno, var_name);}
               
	    };

assignment : ID{strcpy(var_name,symbol_name);} EQUAL expr1 SEMICOLON
	   {
		if(find_symbol(var_name)==-1)
		{
			printf("Error : Line no : %d : Variable %s not declared\n",lineno, var_name);
			YYABORT;
		}
		else{
		update_symbol(var_name);
		printf("Line no : %d : Assigned variabled %s\n",lineno, var_name);}
		
	   };

conditional : IF condition LBRACE codes RBRACE {printf("Parsed if\n\n");} conditional1;

conditional1 : ELSE IF condition LBRACE codes RBRACE {printf("Parsed else if\n\n");} conditional1
	     |conditional2;

conditional2 : ELSE LBRACE codes RBRACE
	     { printf("Parsed else\n\n");}|;

condition : LPAREN expr1 RPAREN ;

iterative : WHILE condition LBRACE codes RBRACE
	 { printf("Parsed while loop\n\n");} 
	| DO LBRACE codes RBRACE condition SEMICOLON
	{ printf("Parsed do while loop\n\n");}
	|FOR LPAREN initialize terminate SEMICOLON update RPAREN LBRACE codes RBRACE
	{ printf("Parsed for loop\n\n");};

initialize : declarative | assignment | SEMICOLON;

terminate : expr | ;

update : expr | ;

function_call : ID {strcpy(fn_name, symbol_name);} LPAREN parameters RPAREN SEMICOLON
	      {
		if(find_function(fn_name)==-1)
		{
			printf("Error : Line no : %d : Function %s not defined\n",lineno,fn_name);
			YYABORT;
	        }
		else{
			printf("Line no : %d : Function call of %s()\n",lineno,fn_name);
		}
	      };

parameters : value COMMA parameters | value | ;
value : ID{if(find_symbol(symbol_name)==-1)
      	   {
		printf("Error : Line no : %d : Variable %s not defined\n",lineno,symbol_name);
                YYABORT;
	   }
	  } | NUM;

return : RETURN ID{if(find_symbol(symbol_name)==-1)
           {
                printf("Error : Line no : %d : Variable %s not defined\n",lineno,symbol_name);
                YYABORT;
           }
          } SEMICOLON{printf("Line no : %d : Parsed Return statement\n",lineno);} | RETURN SEMICOLON{printf("Line no : %d : Parsed Return statement\n",lineno);} | RETURN NUM SEMICOLON{printf("Line no : %d : Parsed Return statement\n",lineno);};

functions : function functions | ;

function : type ID{strcpy(fn_name,symbol_name);} LPAREN signature RPAREN LBRACE codes RBRACE
	 {
		add_function(fn_name);
		printf("Function %s defined\n\n",fn_name);
	 };

signature : type ID COMMA signature | type ID | ;

type : INT | FLOAT | CHAR | VOID;

expr : ID{
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       } EQUAL expr1
     | ID{
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       } PLUS_EQUAL expr1
     | ID{
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       } MINUS_EQUAL expr1
     | ID{
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       } MUL_EQUAL expr1
     | ID{
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       } DIV_EQUAL expr1
     | ID{
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       } PERCENT_EQUAL expr1
     | expr1;

expr1 : Q L1;

L1 : AND AND Q L1 | OR OR Q L1 | ;

Q : R Q1;

Q1 : EQUAL_EQUAL R Q1 | NOT_EQUAL R Q1 | ;

R : E R1;
 
R1 : LESS E R1 | GREAT E R1 | LESS_EQUAL E R1 | GREAT_EQUAL E R1 | ;

E : T E1;

E1 : PLUS T E1 | MINUS T E1 | ;

T : F T1;

T1 : MUL F T1 | DIV F T1 | PERCENT F T1 | ;

F : ID{
  	if(find_symbol(symbol_name)==-1)
  	 {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       } | 
     NUM | 
     LPAREN F RPAREN | 
     PLUS F | 
     MINUS F | 
     NOT F | 
     COMPLEMENT F |  
     PLUS_PLUS ID
     {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }  | 
     MINUS_MINUS ID
     {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }  | 
     ID PLUS_PLUS
     {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }  | 
     ID MINUS_MINUS
     {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       } ;


%%

int find_symbol(char * id)
{
	for(int i=0;i<symbol_count;++i)
	{
		if(strcmp(symbol_table[i]->name,id)==0)
			return i;
	}
	return -1;
}
void add_symbol(char * id)
{
	strcpy(symbol_table[symbol_count]->name,id);
	symbol_table[symbol_count++]->initialized=0;
}
void update_symbol(char * id)
{
	symbol_table[find_symbol(id)]->initialized=1;
}
void add_function(char * id)
{
	strcpy(function_table[function_count++],id);
}
int find_function(char * id)
{
	for(int i=0;i<function_count;++i)
	{
		if(strcmp(function_table[i],id)==0)
			return i;
	}
	return -1;
}
void yyerror(const char *s) {
	printf("%s at line no %d\n",s,lineno);   
}
int main()
{
	symbol_name = (char*)malloc(100*sizeof(char));//initialize the token value variable
	memset(symbol_name,'\0',sizeof(symbol_name));

	fn_name = (char*)malloc(100*sizeof(char));//initialize  fn_name
	memset(fn_name,'\0',sizeof(fn_name));

	var_name = (char*)malloc(100*sizeof(char));
	memset(var_name,'\0',sizeof(var_name));

	symbol_table = (symbol **)malloc(sizeof(symbol*)*100); //symbol table initialized
	for(int i=0;i<100;++i)
	{
		symbol_table[i] = (symbol*)malloc(sizeof(symbol));
		symbol_table[i]->name = (char*)malloc(100*sizeof(char));
		memset(symbol_table[i]->name,'\0',sizeof(char)*100);
		symbol_table[i]->initialized = 0;
	}

	function_table = (char **)malloc(sizeof(char*)*100); //function table initialized
	for(int i=0;i<100;++i)
	{
		function_table[i] = (char*)malloc(sizeof(char)*100);
	}	

	lineno=1;
	yyparse();

	for(int i=0;i<100;++i)	
	{
		free(symbol_table[i]->name);
		free(function_table[i]);
	}
	free(symbol_table);
	free(function_table);
}

