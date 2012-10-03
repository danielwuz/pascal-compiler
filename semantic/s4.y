%{
#include "header.h"

 extern FILE *yyin;
 extern char* yytext;

/*Symbol Table*/
 struct symtable* top;

 struct id* new_id(char* lexeme, struct id* next);
 char* strconn(char* s1, char* s2);

/*Function declaration*/
 void set_id_type(struct id*,char*);
 char* get_id_type(struct id* id);
 char* get_type_from_symtab(char*);
 char* get_array_type(int a,int b,char* type);
 char* get_record_type(struct id* ids, char* type);
 int to_num(char sign,char* value);
 void check_type_equal(char* v1, char* v2, char* l1);

 void set_new_scope();
 void release_scope();

 void check_undeclared_var(struct id* id);
 int check_multi_def(struct id* id);

 int install_id_lexeme(char* idstr);
 void install_id(struct id* id);
 void install_ids(struct id* ids, char* type);
 void install_func(struct id*,char*);
%}

%union {
  struct id* idtype;
  int num;
  char* strtype;
}

%token LT
%token EQ
%token NE
%token GT
%token GE
%token LE
%token RELOP
%token PLUS
%token MINUS
%token MULTI
%token ARIOP
%token DOT
%token COMMA
%token COLON
%token SEMICOLON
%token ASSIGN
%token DDOT
%token L_BRACE
%token R_BRACE
%token L_BRACKET
%token R_BRACKET
%token OTHEROP
%token ANDSYM
%token BEGINSYM
%token FORWARDSYM
%token DIVSYM
%token DOSYM
%token ELSESYM
%token ENDSYM
%token FORSYM
%token FUNCTIONSYM
%token IFSYM
%token ARRAYSYM
%token MODSYM
%token NOTSYM
%token OFSYM
%token ORSYM
%token PROCEDURESYM
%token PROGRAMSYM
%token RECORDSYM
%token THENSYM
%token TOSYM
%token TYPESYM
%token VARSYM
%token WHILESYM
%token <idtype> ID
%token <strtype> NUMBER
%token STRING
%token UNREC

%type <idtype> Identifierlist VariableDeclaration Variable FunctionReference ResultType
%type <strtype> Type Factor Expression SimpleExpression SimpleExpressionSub Term FieldlistSub Fieldlist
%type <num> Constant
%type <num> Sign

%%
Program: PROGRAMSYM ID SEMICOLON CompoundStatement DOT {install_id($2);set_id_type($2,"program"); }
       | PROGRAMSYM ID SEMICOLON TypeDefinitions CompoundStatement DOT {install_id($2); set_id_type($2,"program");}
       | PROGRAMSYM ID SEMICOLON VariableDeclarations CompoundStatement DOT {install_id($2); set_id_type($2,"program");}
       | PROGRAMSYM ID SEMICOLON SubprogramDeclarations CompoundStatement DOT {install_id($2);set_id_type($2,"program"); }
       | PROGRAMSYM ID SEMICOLON TypeDefinitions VariableDeclarations CompoundStatement DOT {install_id($2); set_id_type($2,"program");}
       | PROGRAMSYM ID SEMICOLON VariableDeclarations SubprogramDeclarations CompoundStatement DOT {install_id($2);set_id_type($2,"program"); }
       | PROGRAMSYM ID SEMICOLON TypeDefinitions SubprogramDeclarations CompoundStatement DOT {install_id($2); set_id_type($2,"program");}
       | PROGRAMSYM ID SEMICOLON TypeDefinitions VariableDeclarations SubprogramDeclarations CompoundStatement DOT {install_id($2);set_id_type($2,"program"); }
;

TypeDefinitions: TYPESYM TypeDefinitionSub
;

TypeDefinitionSub: TypeDefinition SEMICOLON
                 | TypeDefinition SEMICOLON TypeDefinitionSub
;

TypeDefinition: ID EQ Type {check_multi_def($1); install_id($1); set_id_type($1,$3);}
;

VariableDeclarations: VARSYM VariableDeclarationSub
;

VariableDeclarationSub: VariableDeclaration SEMICOLON 
                      | VariableDeclaration SEMICOLON VariableDeclarationSub
;

VariableDeclaration: Identifierlist COLON Type {install_ids($1,$3);}
;

SubprogramDeclarations: {set_new_scope(top);} ProcedureDeclarationSub {release_scope();}
                      | {set_new_scope(top);} FunctionDeclarationSub {release_scope();}
;	     

ProcedureDeclarationSub: ProcedureDeclaration SEMICOLON
                       | ProcedureDeclarationSub SubprogramDeclarations
;

FunctionDeclarationSub: FunctionDeclaration SEMICOLON
		      | FunctionDeclarationSub SubprogramDeclarations
;

ProcedureDeclaration: PROCEDURESYM ID L_BRACE FormalParameterList R_BRACE SEMICOLON {install_func($2,"procedure");} Block 
                    | PROCEDURESYM ID L_BRACE FormalParameterList R_BRACE SEMICOLON {install_func($2,"procedure");} FORWARDSYM
;

FunctionDeclaration: FUNCTIONSYM ID L_BRACE FormalParameterList R_BRACE COLON ResultType SEMICOLON {install_func($2,$7->lexeme);} Block
                   | FUNCTIONSYM ID L_BRACE FormalParameterList R_BRACE COLON ResultType SEMICOLON {install_func($2,$7->lexeme);} FORWARDSYM
;

FormalParameterList: {}
                   | FormalParameterListSub
;

FormalParameterListSub: Identifierlist COLON Type { install_ids($1,$3);}
                      | Identifierlist COLON Type SEMICOLON FormalParameterListSub { install_ids($1,$3); }
;

Block: VariableDeclarations CompoundStatement
     | CompoundStatement
;

CompoundStatement: BEGINSYM StatementSequence ENDSYM
;

StatementSequence: Statement
                 | Statement SEMICOLON StatementSequence
;

Statement: SimpleStatement
         | StructuredStatement
;

SimpleStatement: 
         | AssignmentStatement 
         | ProcedureStatement 
;

AssignmentStatement: Variable ASSIGN Expression {char* type = get_id_type($1); check_type_equal(type,$3,$1->lexeme);}
;

ProcedureStatement: ID L_BRACE ActualParameterList R_BRACE {install_id($1);}
;

StructuredStatement: CompoundStatement
                   | IFSYM Expression THENSYM Statement
                   | IFSYM Expression THENSYM Statement ELSESYM Statement
                   | WHILESYM Expression DOSYM Statement
| FORSYM ID{check_undeclared_var($2)} ASSIGN Expression TOSYM Expression DOSYM Statement {char* type = get_id_type($2); check_type_equal(type,$5,$2->lexeme);check_type_equal(type,$7,$2->lexeme);}
;

Type: ID {check_undeclared_var($1); $$ = $1->lexeme;}
| ARRAYSYM L_BRACKET Constant DDOT Constant R_BRACKET OFSYM Type { $$ = get_array_type($3,$5,$8);}
| RECORDSYM Fieldlist ENDSYM { $$ = strconn("record",$2); }
;

ResultType: ID {check_undeclared_var($1);}
;

Fieldlist: {$$=NULL}
          | FieldlistSub
;

FieldlistSub: Identifierlist COLON Type {$$ = get_record_type($1,$3);}
            | Identifierlist COLON Type SEMICOLON FieldlistSub {$$ = strconn(get_record_type($1,$3),$5);}
;

Constant: Sign NUMBER {$$ = to_num($1,$2);}
        | NUMBER {$$ = to_num('+',$1);}
;

Expression: SimpleExpression
          | SimpleExpression RelationalOp SimpleExpression
;

RelationalOp: LT
             |LE
             |GT
             |GE
             |NE
             |EQ
;

SimpleExpression: Sign SimpleExpressionSub {$$ = $2}
                | SimpleExpressionSub
;

SimpleExpressionSub: Term
                   | Term AddOp SimpleExpressionSub
;

AddOp: PLUS
     | MINUS
     | ORSYM
;

Term: Factor
    | Factor MulOp Term
;

MulOp: MULTI
     | DIVSYM
     | MODSYM
     | ANDSYM
;

Factor: NUMBER {$$ = "integer";}
      | STRING {$$ = "string";}
      | Variable {$$ = get_id_type($1);}
      | FunctionReference {$$ = get_id_type($1);}
      | NOTSYM Factor {$$ = $2;}
      | L_BRACE Expression R_BRACE {$$ = $2;}
;

FunctionReference: ID L_BRACE ActualParameterList R_BRACE  {}
;

Variable: ID {check_undeclared_var($1);}  ComponentSelection
;

ComponentSelection:
                  | DOT ID{check_undeclared_var($2);} ComponentSelection
                  | L_BRACKET Expression R_BRACKET ComponentSelection
;

ActualParameterList:
                  | ActualParameterListSub
;

ActualParameterListSub: Expression
                      | Expression COMMA ActualParameterListSub
;

Identifierlist: ID 
              | ID COMMA Identifierlist {$$ = new_id($1->lexeme , $3); }
;

Sign: PLUS {$$ = '+';}
    | MINUS {$$ = '-';}
;
%%
int main(int argc, char *argv[])
{
    ++argv, --argc;    /* skip argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    printf("\n\nStart parsing...:\n\n");
    //initialize top symbol table
    set_new_scope(NULL);
    yyparse();
    release_scope();
    return 0;
};

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
};

void install_func(struct id* func, char* lexeme){
  char* type = get_type_from_symtab(lexeme);
  struct symtable* scp = top;
  while(top != NULL){
    install_id(func);
    set_id_type(func,type);
    top = top->parent;
  }
  top = scp;
}

struct id* new_id(char* lexeme, struct id* next){
  struct id* i = malloc(sizeof(struct id));
  i->lexeme = lexeme;
  i->next = next;
  return i;
}

void install_ids(struct id* ids, char* type){
  struct id* tmpid = ids;
  while(tmpid != NULL){
    int success = check_multi_def(tmpid);
    if(success){
      install_id(tmpid);
      set_id_type(tmpid,type);
    }
    tmpid = tmpid->next;
  }
}

void install_id(struct id* id){
  struct id* tmpid = id;
  if(tmpid!=NULL){
    int index = install_id_lexeme(tmpid->lexeme);
    tmpid->index = index;
  }
}

int install_id_lexeme(char* idstr){
int i;
 for(i=0;i<(top->count);i++){
  if(!strcmp(top->entity[i].value,idstr)){
   //already exists in symbol table
   return i;
  }
 }
 int index = (top->count);
 top->entity[index].value = idstr;
 top->entity[index].property = "ID";
 (top->count)++;
 return index;
}

void set_id_type(struct id* id, char* type){
  char* realType = get_type_from_symtab(type);
  top->entity[id->index].type = realType;
  id->type = realType;
}

char* get_id_type(struct id* id){
 struct symtable* scp = top;
 while(scp != NULL){
	  int i;
	  for(i=0;i<(scp->count);i++){
		if(!strcmp(scp->entity[i].value,id->lexeme)){
		    return scp->entity[i].type;
		}
	  }
	scp = scp->parent;
 }
 return NULL;
}

char* get_type_from_symtab(char* type){
 struct symtable* scp = top;
 while(scp != NULL){
	  int i;
	  for(i=0;i<(scp->count);i++){
		if(!strcmp(scp->entity[i].value,type)){
		  if(scp->entity[i].type == NULL){
		    return type;
		  } else{
		    return get_type_from_symtab(scp->entity[i].type);
		  }
		}
	  }
	scp = scp->parent;
 }
 return type;
}

void set_new_scope(struct symtable* parent){
  //printf("Enter new scope\n");
 struct symtable* newscope = malloc(sizeof(struct symtable));
 newscope->parent = parent;
 newscope->count = 0;
 top = newscope;
 //predefine type
 install_id_lexeme("integer");
 install_id_lexeme("string");
 install_id_lexeme("boolean");
 install_id_lexeme("array");
 install_id_lexeme("record");
 install_id_lexeme("true");
 install_id_lexeme("false");
}

void release_scope(){
  // printf("Exit new scope\n");
  /*
    printf("\n\nSymbol Table:\n");
    int i;
    for(i=0;i<top->count;i++){
      printf("entry: %3d, symbol: %12s, property: %3s, type: %4s \n",i,top->entity[i].value,top->entity[i].property,top->entity[i].type);
    }
  */
 top = top->parent;
}

void check_undeclared_var(struct id* id){
  char* idstr =  id->lexeme;
 //check if declared already
 struct symtable* scp = top;
 while(scp != NULL){
	  int i;
	  for(i=0;i<(scp->count);i++){
		if(!strcmp(scp->entity[i].value,idstr)){
		   //already exists in symbol table
		   return;
		}
	  }
	scp = scp->parent;
 }
 printf("Error: Variable '%s': undeclared variable\n",idstr);
}

int check_multi_def(struct id* id){
 int i;
 for(i=0;i<(top->count);i++){
  if(!strcmp(top->entity[i].value,id->lexeme)){
   //already exists in symbol table
   printf("Error: Variable '%s': multiple declaration\n",id->lexeme);
   return false;
  }
 }
 return true;
}

char* get_array_type(int a,int b,char* type) {
    char buf[256];
    snprintf(buf, sizeof buf, "%s%d%s%d", "array", a, get_type_from_symtab(type), b);
    return strdup(buf);
}

char* get_record_type(struct id* ids, char* type){
    struct id* tmpid = ids;
    char* res = "";
    while(tmpid != NULL){
      res = strconn(res,tmpid->lexeme);
      res = strconn(res,get_type_from_symtab(type));
      tmpid = tmpid->next;
    }
    return strdup(res);
}

int to_num(char sign,char* value){
    if('-' == sign){
      return 0 - atoi(value);
    } else {
      return atoi(value);
    }
}

void check_type_equal(char* v1, char* v2, char* l1){
  //  printf("%s%s\n",v1,v2);
  if(v1!=NULL&&v2!=NULL&&strcmp(v1,v2)){
    printf("Error: unequivalent types: %s is of type %s, cannot be assigned to type %s\n",l1, v1,v2);
  }
}

char* strconn(char* s1, char* s2){
    char buf[9999];
    snprintf(buf, sizeof buf, "%s%s", s1,s2);
    return strdup(buf);
}
