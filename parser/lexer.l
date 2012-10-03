%{
#include "parser.tab.h"
#include "header.h"

/*Symbol Table*/
struct token entity[1000];

int count = 0;
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

and		{return(AND);}
begin	 	{return(BEGINSYM);}
forward  	{return(FORWARD);}
div		{return(DIV);}
do 		{return(DO);}
else		{return(ELSE);}
end		{return(END);}
for		{return(FOR);}
if		{return(IF);}
array		{return(ARRAY);}
mod		{return(MOD);}
not		{return(NOT);}
of 		{return(OF);}
or		{return(OR);}
program		{return(PROGRAM);}
record		{return(RECORD);}
then		{return(THEN);}
to		{return(TO);}
type		{return(TYPE);}
var		{return(VAR);}
while		{return(WHILE);}
procedure	{return(PROCEDURE);}
function	{return(FUNCTION);}

{id}   		{yylval.num = (int)installID(); return(ID);}
{integer}	{return(NUMBER);}
{string}	{return(STRING);}

"." |		
"," |		
":" |		
";" |		
":=" |	
".." |	
"(" |		
")" |		
"[" |		
"]" |		
"+" |
"-" |
"*" 		{return yytext[0];}

"<"  |
"<=" |
"="  |
"<>" |
">"  |
">="		{return CMP;}

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


