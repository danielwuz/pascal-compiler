/* Compiler Design Project 1 by Zhe Wu N16445442*/
%{
#include "s4.tab.h"
#include "header.h"
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

and		{yylval.strtype = "and";return(ANDSYM);}
begin	 	{return(BEGINSYM);}
forward  	{return(FORWARDSYM);}
div		{yylval.strtype = "/"; return(DIVSYM);}
do 		{return(DOSYM);}
else		{return(ELSESYM);}
end		{return(ENDSYM);}
for		{return(FORSYM);}
if		{return(IFSYM);}
array		{return(ARRAYSYM);}
mod		{yylval.strtype = "%"; return(MODSYM);}
not		{yylval.strtype = "not"; return(NOTSYM);}
of 		{return(OFSYM);}
or		{yylval.strtype = "or"; return(ORSYM);}
program		{return(PROGRAMSYM);}
record		{return(RECORDSYM);}
then		{return(THENSYM);}
to		{return(TOSYM);}
type		{return(TYPESYM);}
var		{return(VARSYM);}
while		{return(WHILESYM);}
procedure	{return(PROCEDURESYM);}
function	{return(FUNCTIONSYM);}

{id}   		{yylval.strtype = strdup(yytext); return(ID);}
{integer}	{yylval.strtype = strdup(yytext); return(NUMBER);}
{string}	{yylval.strtype = strdup(yytext); return(STRING);}

"+"		{yylval.strtype = "+"; return(PLUS);}
"-"		{yylval.strtype = "-"; return(MINUS);}
"*"		{yylval.strtype = "*"; return(MULTI);}

"<"		{yylval.strtype = "<"; return(LT);}
"<="		{yylval.strtype = "<="; return(LE);}
"="		{yylval.strtype = "="; return(EQ);}
"<>"		{yylval.strtype = "<>"; return(NE);}
">"		{yylval.strtype = ">"; return(GT);}
">="		{yylval.strtype = ">="; return(GE);}

"."		{yylval.num = DOT; return(DOT);}
","		{yylval.num = COMMA; return(COMMA);}
":"		{yylval.num = COLON; return(COLON);}
";"		{yylval.num = SEMICOLON; return(SEMICOLON);}
":="		{yylval.num = ASSIGN; return(ASSIGN);}
".."		{yylval.num = DDOT; return(DDOT);}
"("		{yylval.num = L_BRACE; return(L_BRACE);}
")"		{yylval.num = R_BRACE; return(R_BRACE);}
"["		{yylval.num = L_BRACKET; return(L_BRACKET);}
"]"		{yylval.num = R_BRACKET; return(R_BRACKET);}

.            	{return(UNREC);}

%% 
int yywrap(void){return 1;}
