%{
#include "header.h"

extern FILE *yyin;
extern int count;
extern char* yytext;

extern struct token entity[1000];
%}

%union {
  struct ids* idtype;
  int num;
  char* strtype;
}

%token CMP
%token AND
%token BEGINSYM
%token FORWARD
%token DIV
%token DO
%token ELSE
%token END
%token FOR
%token FUNCTION
%token IF
%token ARRAY
%token MOD
%token NOT
%token OF
%token OR
%token PROCEDURE
%token PROGRAM
%token RECORD
%token THEN
%token TO
%token TYPE
%token VAR
%token WHILE
%token <num> ID
%token NUMBER
%token STRING
%token UNREC

%type <idtype> Identifierlist TypeDefinition VariableDeclaration ProcedureDeclaration FunctionDeclaration FormalParameterList FormalParameterListSub
%type <strtype> Type

%%
Program: PROGRAMSYM ID SEMICOLON CompoundStatement DOT {printf("Program\n");}
       | PROGRAMSYM ID SEMICOLON TypeDefinitions CompoundStatement DOT {printf("Program\n");}
       | PROGRAMSYM ID SEMICOLON VariableDeclarations CompoundStatement DOT {printf("Program\n");}
       | PROGRAMSYM ID SEMICOLON SubprogramDeclarations CompoundStatement DOT {printf("Program\n");}
       | PROGRAMSYM ID SEMICOLON TypeDefinitions VariableDeclarations CompoundStatement DOT {printf("Program\n");}
       | PROGRAMSYM ID SEMICOLON VariableDeclarations SubprogramDeclarations CompoundStatement DOT {printf("Program\n");}
       | PROGRAMSYM ID SEMICOLON TypeDefinitions SubprogramDeclarations CompoundStatement DOT {printf("Program\n");}
       | PROGRAMSYM ID SEMICOLON TypeDefinitions VariableDeclarations SubprogramDeclarations CompoundStatement DOT {printf("Program\n");}
;

TypeDefinitions: TYPE TypeDefinitionSub {printf("TypeDefinitions\n");} 
;

TypeDefinitionSub: TypeDefinition ';'
                 | TypeDefinition ';' TypeDefinitionSub
;

VariableDeclarations: VAR VariableDeclarationSub {printf("VariableDeclaration\n");} 
;

VariableDeclarationSub: VariableDeclaration ';' 
                      | VariableDeclaration ';' VariableDeclarationSub
;

SubprogramDeclarations: ProcedureDeclarationSub {printf("SubprogramDeclarations\n");}
                      | FunctionDeclarationSub {printf("SubprogramDeclarations\n");}
;	     

ProcedureDeclarationSub: ProcedureDeclaration ';'
                       | ProcedureDeclarationSub SubprogramDeclarations
;

FunctionDeclarationSub: FunctionDeclaration ';'
		      | FunctionDeclarationSub SubprogramDeclarations
;

TypeDefinition: ID CMP Type {printf("TypeDefinition\n");updateID($1,$3);}
;

VariableDeclaration: Identifierlist ':' Type {printf("VariableDeclaration\n");updateVars($1,$3);}
;

ProcedureDeclaration: PROCEDURE ID '(' FormalParameterList ')' ';' Block 
                         {printf("ProcedureDeclaration\n");updateFunc($2, $4);}
                    | PROCEDURE ID '(' FormalParameterList ')' ';' FORWARD
		         {printf("ProcedureDeclaration\n");updateFunc($2, $4);}
;

FunctionDeclaration: FUNCTION ID '(' FormalParameterList ')' ':' ResultType ';' Block 
			{printf("FunctionDeclaration\n");updateFunc($2, $4);}
                   | FUNCTION ID '(' FormalParameterList ')' ':' ResultType ';' FORWARD 
			{printf("FunctionDeclaration\n");updateFunc($2, $4);}
;

FormalParameterList: {printf("FormalParameterList\n");}
                   | FormalParameterListSub {printf("FormalParameterList\n");}
;

FormalParameterListSub: Identifierlist ':' Type { $$->depth = $1->depth; }
                      | Identifierlist ':' Type ';' FormalParameterListSub { $$->depth = $1->depth + $5->depth; }
;

Block: VariableDeclarations CompoundStatement {printf("Block\n");}
     | CompoundStatement {printf("Block");}
;

CompoundStatement: BEGINSYM StatementSequence END {printf("CompoundStatement\n");}
;

StatementSequence: Statement {printf("StatementSequence\n");}
                 | Statement ';' StatementSequence {printf("StatementSequence\n");}
;

Statement: SimpleStatement {printf("Statement\n");}
         | StructuredStatement {printf("Statement\n");}
;

SimpleStatement: {printf("SimpleStatement\n");}
         | AssignmentStatement {printf("SimpleStatement\n");}
         | ProcedureStatement {printf("SimpleStatement\n");}
;

AssignmentStatement: Variable ':=' Expression  {printf("AssignmentStatement\n");}
;

ProcedureStatement: ID '(' ActualParameterList ')' {printf("ProcedureStatement\n");}
;

StructuredStatement: CompoundStatement {printf("StructuredStatement\n");}
                   | IF Expression THEN Statement {printf("StructuredStatement\n");}
                   | IF Expression THEN Statement ELSE Statement {printf("StructuredStatement\n");}
                   | WHILE Expression DO Statement {printf("StructuredStatement\n");}
                   | FOR ID ':=' Expression TO Expression DO Statement {printf("StructuredStatement\n");}
;

Type: ID {printf("Type\n"); $$ = toStr($1);}
    | ARRAY '[' Constant '..' Constant ']' OF Type {printf("Type\n"); $$ = "array";}
    | RECORD Fieldlist END {printf("Type\n"); $$ ="record";}
;

ResultType: ID {printf("ResultType\n");}
;

Fieldlist: {printf("Fieldlist\n");}
          | FieldlistSub {printf("Fieldlist\n");}
;

FieldlistSub: Identifierlist ':' Type {updateVars($1,$3);}
            | Identifierlist ':' Type ';' FieldlistSub {updateVars($1,$3);}
;

Constant: Sign NUMBER {printf("Constant\n");}
        | NUMBER {printf("Constant\n");}
;

Expression: SimpleExpression {printf("Expression\n");}
          | SimpleExpression RelationalOp SimpleExpression {printf("Expression\n");}
;

RelationalOp: CMP {printf("RelationalOp\n");}
;

SimpleExpression: Sign SimpleExpressionSub {printf("SimpleExpression\n");}
                | SimpleExpressionSub {printf("SimpleExpression\n");}
;

SimpleExpressionSub: Term
                   | Term AddOp SimpleExpressionSub
;

AddOp: '+' {printf("AddOp\n");}
     | '-' {printf("AddOp\n");}
     | OR {printf("AddOp\n");}
;

Term: Factor {printf("Factor\n");}
    | Factor MulOp Term {printf("Factor\n");}
;

MulOp: '*' {printf("MulOp\n");}
     | DIV {printf("MulOp\n");}
     | MOD {printf("MulOp\n");}
     | AND {printf("MulOp\n");}
;

Factor: NUMBER {printf("Factor\n");}
      | STRING {printf("Factor\n");}
      | Variable  {printf("Factor\n");}
      | FunctionReference {printf("Factor\n");}
      | NOT Factor {printf("Factor\n");}
      | '(' Expression ')'  {printf("Factor\n");}
;

FunctionReference: ID '(' ActualParameterList ')'  {printf("FunctionReference\n");}
;

Variable: ID ComponentSelection {printf("Variable\n");}
;

ComponentSelection: {printf("ComponentSelection\n");}
                  | '.' ID ComponentSelection {printf("ComponentSelection\n");}
                  | '[' Expression ']' ComponentSelection {printf("ComponentSelection\n");}
;

ActualParameterList: {printf("ActualParameterList\n");}
                  | ActualParameterListSub {printf("ActualParameterList\n");}
;

ActualParameterListSub: Expression
                      | Expression ',' ActualParameterListSub
;

Identifierlist: ID { $$ = idList($1,NULL); printf("Identifierlist\n");}
              | ID ',' Identifierlist { $$ = idList($1,$3); printf("Identifierlist\n");}
;

Sign: '+' {printf("Sign\n");}
    | '-' {printf("Sign\n");}
;
%%
int main(int argc, char *argv[])
{
    ++argv, --argc;    /* skip argv[0] */
    yyin = fopen(argv[0], "r");
    printf("\n\nFINISH.\n\n");
    freopen("rule.out","w",stdout);
    yyparse();

    freopen("symtable.out","w",stdout);
    int i;
    for(i=0;i<count;i++){
      printf("index: %2d, lexeme: %10s, property: %3s, type: %4s \n",i,entity[i].value,entity[i].property,entity[i].type);
    }
    return 0;
};

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
};

void updateID(int id, char* type){
  entity[id].type = strdup(type);
}

void updateFunc(int id, struct ids* idptr){
  char buffer[10];
  sprintf(buffer,"%d",idptr->depth);
  entity[id].type = strdup(buffer);
}

void updateVars(struct ids* ids,char* type){
  while(ids != NULL){
    entity[ids->index].type = strdup(type);
    ids = ids->next;
  }
}

struct ids* idList(int id,struct ids* next){
  struct ids* i = malloc(sizeof(struct ids));
  i->index = id;
  i->next = next;
  if(next == NULL){
    i->depth = 1;
  }else{
    i->depth = 1 + (next->depth);
  }
  return i;
}

char* toStr(int id){
  return entity[id].value;
}
