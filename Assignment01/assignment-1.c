#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
// Define token types
typedef enum
{
TOKEN_ARITH_OP,
TOKEN_REL_OP,
TOKEN_LOGICAL_OP,
TOKEN_BITWISE_OP,
TOKEN_ASSIGN_OP,
TOKEN_RESERVED_WORD,
TOKEN_IDENTIFIER,
TOKEN_INT_CONST,
TOKEN_PAREN,
TOKEN_BRACE,
TOKEN_UNKNOWN
} TokenType;
// Structure for a token
typedef struct
{
TokenType type;
char yytext[100];
} Token;
// List of reserved words
const char *reservedWords[] = {"auto", "break", "case", "char",

"const", "continue", "default", "do",
"double", "else", "enum", "extern",
"float", "for", "goto", "if",
"int", "long", "register", "return",
"short", "signed", "sizeof", "static",
"struct", "switch", "typedef", "union",
"unsigned", "void", "volatile", "while" };

const int numReservedWords = 32;
// Function prototypes
int isReservedWord(const char *word);
Token getNextToken(const char *input, int *index);
char *readFile(const char *filename);
int main()
{
const char *filename = "input.txt";
char *input = readFile(filename);
if (input == NULL)
{
printf("Error reading file: %s\n", filename);
return 1;
}
int index = 0;
Token token;
while (input[index] != '\0')
{
token = getNextToken(input, &index);
printf("Token: %-5s Type: %d\n", token.yytext, token.type);
}
free(input); // Free the allocated memory
return 0;
}

// Read the contents of a file into a dynamically allocated string
char *readFile(const char *filename)
{
FILE *file = fopen(filename, "r");
if (file == NULL)
{
return NULL;
}
// Determine the file size
fseek(file, 0, SEEK_END);
long fileSize = ftell(file);
fseek(file, 0, SEEK_SET);
// Allocate memory for the file contents
char *buffer = (char *)malloc(fileSize + 1);
if (buffer == NULL)
{
fclose(file);
return NULL;
}
// Read the file contents into the buffer
fread(buffer, 1, fileSize, file);
buffer[fileSize] = '\0'; // Null-terminate the string
fclose(file);
return buffer;
}
// Check if a word is a Reserved word
int isReservedWord(const char *word)
{
for (int i = 0; i < numReservedWords; i++)
{
if (strcmp(word, reservedWords[i]) == 0)

{
return 1;
}
}
return 0;
}
// Get the next token from the input string
Token getNextToken(const char *input, int *index)
{
Token token;
token.type = TOKEN_UNKNOWN;
int yyleng = 0;
// Skip white spaces
while (isspace(input[*index]))
{
(*index)++;
}
// Check for operators and special symbols
char currentChar = input[*index];
if (strchr("+-*/", currentChar))
{
token.type = TOKEN_ARITH_OP;
token.yytext[yyleng++] = input[(*index)++];
}
else if (strchr("><=", currentChar))
{
token.type = TOKEN_REL_OP;
token.yytext[yyleng++] = input[(*index)++];
if (input[*index] == '=' && (currentChar == '>' || currentChar == '<' || currentChar == '='))
{
token.yytext[yyleng++] = input[(*index)++];

}
}
else if (currentChar == '&' || currentChar == '|')
{
if (input[*index + 1] == currentChar)
{
token.type = TOKEN_LOGICAL_OP;
token.yytext[yyleng++] = input[(*index)++];
token.yytext[yyleng++] = input[(*index)++];
}
else
{
token.type = TOKEN_BITWISE_OP;
token.yytext[yyleng++] = input[(*index)++];
}
}
else if (currentChar == '=')
{
token.type = TOKEN_ASSIGN_OP;
token.yytext[yyleng++] = input[(*index)++];
}
else if (strchr("()", currentChar))
{
token.type = TOKEN_PAREN;
token.yytext[yyleng++] = input[(*index)++];
}
else if (strchr("{}", currentChar))
{
token.type = TOKEN_BRACE;
token.yytext[yyleng++] = input[(*index)++];
}

else if (isdigit(currentChar))
{ // Integer constants
token.type = TOKEN_INT_CONST;
while (isdigit(input[*index]))
{
token.yytext[yyleng++] = input[(*index)++];
}
}
else if (isalpha(currentChar))
{ // Identifiers and reserved words
while (isalnum(input[*index]))
{
token.yytext[yyleng++] = input[(*index)++];
}
token.yytext[yyleng] = '\0';
if (isReservedWord(token.yytext))
{
token.type = TOKEN_RESERVED_WORD;
}
else
{
token.type = TOKEN_IDENTIFIER;
}
}
else
{ // Handle unknown characters to prevent infinite loop
(*index)++;
}

token.yytext[yyleng] = '\0';
return token;}