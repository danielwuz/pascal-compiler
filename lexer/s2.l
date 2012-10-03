/* Compiler Design Project 1 by Zhe Wu N16445442*/
%{
#include <math.h>
#include <string.h>

/*Definitions of manifest constants*/
enum TAG {
LT = 1, EQ, NE, GT, GE, LE, RELOP, 
PLUS = 10, MINUS, MULTI, ARIOP, 
DOT = 20, COMMA, COLON, SEMICOLON,ASSIGN, DDOT,L_BRACE, R_BRACE,L_BRACKET,R_BRACKET, OTHEROP, 
ANDSYM = 100, BEGINSYM, FORWARDSYM, DIVSYM, DOSYM, ELSESYM, ENDSYM, FORSYM, FUNCTIONSYM, IFSYM, ARRAYSYM, MODSYM, NOTSYM, OFSYM, ORSYM, PROCEDURESYM, PROGRAMSYM, RECORDSYM, THENSYM, TOSYM, TYPESYM, VARSYM, WHILESYM, 
ID = 200, NUMBER = 300, STRING = 400, UNREC = 999  };

int yyval = -1;

/*Symbol Table*/
struct token{
 char* property;
 char* value;
} entity[1000];

int count = 0;     //number of tokens

%}

delim 	[ \t\n\r]
ws    	{delim}+
letter 	[A-Za-z]
digit 	[0-9]
id   	{letter}({letter}|{digit}|_)*
number 	{digit}+(\.{digit}+)?(E[+-]?{digit}+)?
integer {digit}+
string  \"[^\"]*\"

%%
{ws} 		{/*no action and no return*/}
"{"[^{}]*"}" 	{/* ignore comments */}

and		{return(ANDSYM);}
begin	 	{return(BEGINSYM);}
forward  	{return(FORWARDSYM);}
div		{return(DIVSYM);}
do 		{return(DOSYM);}
else		{return(ELSESYM);}
end		{return(ENDSYM);}
for		{return(FORSYM);}
if		{return(IFSYM);}
array		{return(ARRAYSYM);}
mod		{return(MODSYM);}
not		{return(NOTSYM);}
of 		{return(OFSYM);}
or		{return(ORSYM);}
program		{return(PROGRAMSYM);}
record		{return(RECORDSYM);}
then		{return(THENSYM);}
to		{return(TOSYM);}
type		{return(TYPESYM);}
var		{return(VARSYM);}
while		{return(WHILESYM);}
procedure	{return(PROCEDURESYM);}
function	{return(FUNCTIONSYM);}

{id}   		{yyval = (int)installID(); return(ID);}
{integer}	{yyval = (int)installNum(); return(NUMBER);}
{string}	{yyval = (int)installStr(); return(STRING);}

"+"		{yyval = PLUS; return(ARIOP);}
"-"		{yyval = MINUS; return(ARIOP);}
"*"		{yyval = MULTI; return(ARIOP);}

"<"		{yyval = LT; return(RELOP);}
"<="		{yyval = LE; return(RELOP);}
"="		{yyval = EQ; return(RELOP);}
"<>"		{yyval = NE; return(RELOP);}
">"		{yyval = GT; return(RELOP);}
">="		{yyval = GE; return(RELOP);}

"."		{yyval = DOT; return(OTHEROP);}
","		{yyval = COMMA; return(OTHEROP);}
":"		{yyval = COLON; return(OTHEROP);}
";"		{yyval = SEMICOLON; return(OTHEROP);}
":="		{yyval = ASSIGN; return(OTHEROP);}
".."		{yyval = DDOT; return(OTHEROP);}
"("		{yyval = L_BRACE; return(OTHEROP);}
")"		{yyval = R_BRACE; return(OTHEROP);}
"["		{yyval = L_BRACKET; return(OTHEROP);}
"]"		{yyval = R_BRACKET; return(OTHEROP);}

.            	{return(UNREC);}

%% 
int yywrap(void){return 1;}

int installID(){
char* str = strdup(yytext);
int i;
 for(i=0;i<count;i++){
  if(!strcmp(entity[i].value,str)){
   //already exists in symbol table
   return i;
  }
 }
 int index = count;
 entity[index].value = str;
 entity[index].property = "ID";
 count++;
 return index;
}

int installNum(){
 return 0;
}

int installStr(){
 return 0;
}

int main(int argc, char *argv[])
{
    ++argv, --argc;    /* skip argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    
    printf("\n\nStart scanning...:\n\n");
    int tok;
    while(tok = yylex()){
      if (tok == NUMBER) {
	/*Integer*/
	printf("Token: < number , %s >\t Lexeme: %s\n",yytext, yytext);
      } else if (tok >= 100 && tok < 200){
	/*Keywords*/
	printf("Token: < %s >\t Lexeme: %s\n",yytext, yytext);
      } else if(tok == ID){
	/*Identifier*/
	printf("Token: < id, %d >\t Lexeme: %s\n",yyval, yytext);
      } else if(tok == STRING){ 
	/*String*/	
	printf("Token: < literal , %s >\t Lexeme: %s\n", yytext,yytext);
      } else if(tok == RELOP){
	/*RELATION OP*/	
	printf("Token: < relop , %s >\t Lexeme: %s\n",yytext,yytext);
      } else if(tok == ARIOP){
	/*Arithmetic OP*/	
	printf("Token: < arithop , %s >\t Lexeme: %s\n",yytext, yytext);
      } else if(tok == OTHEROP){
	/*Other OP*/	
	printf("Token: < otherop , %s >\t Lexeme: %s\n",yytext, yytext);
      } else if(tok == UNREC){
	printf("Token: < unknown , %s >\t Lexeme: %s\n", yytext, yytext); 
      } else {
	printf("\n");
      }
    }

    printf("\n\nSymbol Table:\n");
    int i;
    for(i=0;i<count;i++){
      printf("entry: %3d, symbol: %12s, property: %3s \n",i,entity[i].value,entity[i].property);
    }

    return 0;
}
