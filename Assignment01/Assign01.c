#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TOKEN_LEN_LIMIT 100

char yytext[TOKEN_LEN_LIMIT];
int yylen;
int yyLineNo=1;
char* inp=NULL;
size_t input_size = 0;
int pos=0;

char *keywords[]={"char","int","float","double","for","while","if","else"};
int key_count=8;


void readInp(FILE* file){
printf("Enter the code to be analysed lexically: ");
fseek(file, 0, SEEK_END);
    input_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    inp = malloc(input_size + 1);
    if (inp) {
        fread(inp, 1, input_size, file);
        inp[input_size] = '\0';
    } else {
        perror("Failed to allocate memory for input buffer");
        exit(1);
    }
}


void ignoreSpace(){
while(isspace(inp[pos])){
if(inp[pos]=='\n'){
yyLineNo++;
}
pos++;
}
}

// reads the token and identifies it (like whether its number/alphnumeric/operator/paraenthesis)
void getToken(){
yylen=0;
ignoreSpace();
// end of program
if(inp[pos]=='\0'){
yytext[yylen]='\0';
return;
}
// for variable names
if(isalpha(inp[pos])){
while(isalnum(inp[pos]) || inp[pos]=='_' ){
yytext[yylen++]=inp[pos++];
}
yytext[yylen]='\0';
return;
}
// for numbers
 if (isdigit(inp[pos])) {
        while (isdigit(inp[pos]) || inp[pos]=='.') {
            yytext[yylen++] = inp[pos++];
        }
        yytext[yylen] = '\0';
        return;
    }
    // for opeartors
    if (strchr("+-*/%=<>!&|^", inp[pos])) {
        yytext[yylen++] = inp[pos++];
        // check for compound operators  like  ++,--,==,<=,>=,!=,&&,||
        if ((yytext[0] == '+' && inp[pos] == '+') || 
            (yytext[0] == '-' && inp[pos] == '-') ||
            (yytext[0] == '=' && inp[pos] == '=') ||
            (yytext[0] == '<' && inp[pos] == '=') ||
            (yytext[0] == '>' && inp[pos] == '=') ||
            (yytext[0] == '!' && inp[pos] == '=') ||
            (yytext[0] == '&' && inp[pos] == '&') ||
            (yytext[0] == '|' && inp[pos] == '|')) {
            yytext[yylen++] = inp[pos++];
        }
        yytext[yylen] = '\0';
        return;
    }
    // for curly and normal paranthesis
    if (strchr("(){}", inp[pos])) {
        yytext[yylen++] = inp[pos++];
        yytext[yylen] = '\0';
        return;
    }
    yytext[yylen++] = inp[pos++];
    yytext[yylen] = '\0';


}
bool isKeyword(char *str){
for(int i=0;i<key_count;i++){
if(strcmp(keywords[i],str)==0){
return true;
}
}
return false;
}
// classifies and prints the tokens in the input
void analyzeToken() {
    while (inp[pos] != '\0') {
        getToken();
        if (yytext[0] == '\0') {
            break;
        }
        if (isKeyword(yytext)) {
            printf("Keyword: %s\n", yytext);
        } else if (isalpha(yytext[0])) {
            printf("Identifier: %s\n", yytext);
        } else if (isdigit(yytext[0])) {
        if(strchr(yytext,'.')){
        printf("Float Constant: %s\n", yytext);
        }
            else printf("Integer Constant: %s\n", yytext);
        } else if (strchr("+-*/%=<>!&|^", yytext[0])) {
            printf("Operator: %s\n", yytext);
        } else if (strchr("(){}", yytext[0])) {
            if(yytext[0]==')' || yytext[0]=='(') printf("Parenthesis: %s\n", yytext);
            else printf("Curly brace: %s\n", yytext);
        } else {
            printf("Statement Terminator: %s\n", yytext);
        }
    }
}


int main(){
FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Could not open input file");
        return 1;
    }
    
readInp(file);
printf("%s\n",inp);
analyzeToken();
return 0;
}
