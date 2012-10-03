%{
#include <math.h>
#include <string.h>

enum yytokentype {
     LT = 258,
     EQ = 259,
     NE = 260,
     GT = 261,
     GE = 262,
     LE = 263,
     RELOP = 264,
     PLUS = 265,
     MINUS = 266,
     MULTI = 267,
     ARIOP = 268,
     DOT = 269,
     COMMA = 270,
     COLON = 271,
     SEMICOLON = 272,
     ASSIGN = 273,
     DDOT = 274,
     L_BRACE = 275,
     R_BRACE = 276,
     L_BRACKET = 277,
     R_BRACKET = 278,
     OTHEROP = 279,
     ANDSYM = 280,
     BEGINSYM = 281,
     FORWARDSYM = 282,
     DIVSYM = 283,
     DOSYM = 284,
     ELSESYM = 285,
     ENDSYM = 286,
     FORSYM = 287,
     FUNCTIONSYM = 288,
     IFSYM = 289,
     ARRAYSYM = 290,
     MODSYM = 291,
     NOTSYM = 292,
     OFSYM = 293,
     ORSYM = 294,
     PROCEDURESYM = 295,
     PROGRAMSYM = 296,
     RECORDSYM = 297,
     THENSYM = 298,
     TOSYM = 299,
     TYPESYM = 300,
     VARSYM = 301,
     WHILESYM = 302,
     ID = 303,
     NUMBER = 304,
     STRING = 305,
     UNREC = 306
   };

int yyval = -1;

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

of 		{return(OFSYM);}
or		{return(ORSYM);}
program		{return(PROGRAMSYM);}
do 		{return(DOSYM);}
else		{return(ELSESYM);}
end		{return(ENDSYM);}
for		{return(FORSYM);}
if		{return(IFSYM);}
array		{return(ARRAYSYM);}
mod		{return(MODSYM);}
not		{return(NOTSYM);}
procedure	{return(PROCEDURESYM);}
record		{return(RECORDSYM);}
then		{return(THENSYM);}
to		{return(TOSYM);}
type		{return(TYPESYM);}
var		{return(VARSYM);}
while		{return(WHILESYM);}
and		{return(ANDSYM);}
begin	 	{return(BEGINSYM);}
forward  	{return(FORWARDSYM);}
div		{return(DIVSYM);}
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
 return 0;
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
    yyin = fopen(argv[0], "r");    
    int tok;
    while(tok = yylex()){
      switch(tok){
      case NUMBER:
	printf("Token:(number, %s)\t Lexeme: %s\n",yytext, yytext);break;
      case ID:
	printf("Token:(id, %d)\t Lexeme: %s\n",yyval, yytext);break;     
      case STRING:
      	printf("Token:(literal,%s)\t Lexeme: %s\n", yytext,yytext);break;
      case RELOP:
	printf("Token:(relop,%s)\t Lexeme: %s\n",yytext,yytext);break;
      case ARIOP:
	printf("Token:(arithop,%s)\t Lexeme: %s\n",yytext, yytext);break;
      case OTHEROP:
       	printf("Token:(otherop,%s)\t Lexeme: %s\n",yytext, yytext);break;
      case UNREC:
      	printf("Token:(unknown,%s)\t Lexeme: %s\n", yytext, yytext); break;
      default:
	printf("Token:(%s)\t Lexeme: %s\n",yytext, yytext);break;
      }
    }

    return 0;
}
