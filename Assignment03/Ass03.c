#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#define E 0 
#define E_ 1 
#define T 2 
#define T_ 3 
#define F 4 
#define ID 5 
#define PLUS 6 
#define STAR 7 
#define LPAREN 8 
#define RPAREN 9 
#define DOLLAR 10 
char * symbol[10]={"E","E'","T","T'","F","ID","+","*","(",")"}; 
typedef struct 
{ 
int arr[1000];
int top; 
}stack; 
stack * init() 
{ 
stack * a=(stack*)malloc(sizeof(stack)); a->top=-1; 
return a; 
} 
void push(stack * stk, int elem) 
{ 
stk->arr[++stk->top]=elem; 
} 
int pop(stack * stk) 
{ 
if(stk->top>=0) 
return stk->arr[stk->top--]; 
} 
void print_rule(int lhs,int rhs) 
{ 
printf("Rule : \t"); 
printf("%s -> ",symbol[lhs]); 
if(rhs==239) 
{ 
printf("\u03B5\n"); 
return; 
} 
do 
{ 
printf("%s ",symbol[rhs%10]); 
rhs/=10; 
}while(rhs>0); 
printf("\n"); 
} 
void yyparse(int * token,int ** table) { 
token[token[0]]=DOLLAR; 
stack * stk=init(); 
push(stk,DOLLAR); 
push(stk,E); 
int pos=1;
while(stk->top!=-1) 
{ 
if(stk->arr[stk->top]==DOLLAR && token[pos]==DOLLAR) { 
printf("String matched\n"); 
return; 
} 
else if(stk->arr[stk->top]==token[pos]) 
{ 
printf("Matched : %s\n",symbol[stk->arr[stk->top]]); 
pop(stk); 
pos++; 
} 
else if(stk->arr[stk->top]<=4) 
{ 
int lhs = stk->arr[stk->top]; 
int production = table[lhs][token[pos]-5]; 
pop(stk); 
if(production==-2) 
{ 
print_rule(lhs,239); 
} 
else if(production==-1) 
{ 
printf("Invalid syntax\n"); 
break; 
} 
else 
{ 
int m=0; 
do 
{ 
push(stk,production%10); 
m=m*10+production%10; 
production=production/10; 
}while(production>0); 
print_rule(lhs,m); 
} 
} 
else 
{ 
break; 
} 
} 
printf("String not matched\n"); 
}
void yylex(int * token) 
{ 
char stmt[100]; 
fgets(stmt,sizeof(char)*100,stdin); 
stmt[strlen(stmt)-1]='\0'; 
int ctr=1; 
for(int i=0;i<strlen(stmt);++i) 
{ 
if(stmt[i]=='i') 
{ 
if(stmt[i+1]=='d') 
{ 
token[ctr++]=ID; 
i+=1; 
} 
else 
{ 
printf("Invalid token at char %d\n",i+1); 
exit(0); 
} 
} 
else if(stmt[i]=='+') 
token[ctr++]=PLUS; 
else if(stmt[i]=='*') 
token[ctr++]=STAR; 
else if(stmt[i]=='(') 
token[ctr++]=LPAREN; 
else if(stmt[i]==')') 
token[ctr++]=RPAREN; 
else 
{ 
printf("Invalid Token at char %d\n",i); 
exit(0); 
} 
} 
token[0]=ctr; 
} 
int main() 
{ 
//allocate space for the parse table 
int **a = (int **) malloc(5*sizeof(int *)); 
for(int i=0;i<5;++i) 
{ 
a[i]=(int*)malloc(6*sizeof(int)); 
}
//fill the parse table 
a[0][0] = T*10 + E_; 
a[0][1] = -1; 
a[0][2] = -1; 
a[0][3] = T*10 + E_; 
a[0][4] = -1; 
a[0][5] = -1; 
a[1][0] = -1; 
a[1][1] = PLUS*100 + T*10 + E_; 
a[1][2] = -1; 
a[1][3] = -1; 
a[1][4] = -2; 
a[1][5] = -2; 
a[2][0] = F*10 + T_; 
a[2][1] = -1; 
a[2][2] = -1; 
a[2][3] = F*10 + T_; 
a[2][4] = -1; 
a[2][5] = -1; 
a[3][0] = -1; 
a[3][1] = -2; 
a[3][2] = STAR*100+ F*10+ T_; 
a[3][3] = -1; 
a[3][4] = -2; 
a[3][5] = -2; 
a[4][0] = ID; 
a[4][1] = -1; 
a[4][2] = -1; 
a[4][3] = LPAREN*100+ E*10+ RPAREN; a[4][4] = -1; 
a[4][5] = -1; 
int *arr=(int*)malloc(sizeof(int)*100); yylex(arr); 
yyparse(arr,a); 
}
