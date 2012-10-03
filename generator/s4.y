%{
#include "header.h"

 extern FILE *yyin;
 extern char* yytext;

 int temp_counter = 0;
 int label_counter = 0;

 //
 char intercode[99999];

/*Symbol Table*/
 struct symtable* top;

 struct id* new_id(char* lexeme, struct id* next);
 char* strconn(char* s1, char* s2);
 char* strconn3(char* s1, char* s2, char* s3);

/*Function declaration*/
 void set_id_type(struct id*,char*);
 char* get_id_type(struct id* id);
 char* get_type_from_symtab(char*);
 char* get_array_type(int a,int b,char* type);
 char* get_record_type(struct id* ids, char* type);
 char* to_num(char* sign,char* value);
 void check_type_equal(char* v1, char* v2, char* l1);

 void set_new_scope();
 void release_scope();

 void check_undeclared_var(struct id* id);
 int check_multi_def(struct id* id);

 int install_id_lexeme(char* idstr);
 void install_id(struct id* id);
 void install_ids(struct id* ids, char* type);
 void install_func(struct id*,char*);

 char* new_temp();
 char* new_label();

 struct expr* new_expr();
 struct expr* new_expr_with_code(char*);
 struct expr* new_expr_with_addr(char*);
 struct expr* new_expr_with_both(char* addr);

 char* gen2(char* res,char* op1);
 char* gen3(char* res, char* op1, char* operator);
 char* gen4(char* res,char* op1,char* op2,char* operator);
 char* gen_expr(char* op1, char* op2, char* operator);

 char* gen_if_then(struct condition* expr,char* stmt);
 char* gen_if_then_else(struct condition* expr,char* stmt1,char* stmt2);
 char* gen_while(struct condition* expr,char* stmt);
 char* gen_for(char* id,struct condition* condition,struct condition* eval, char* stmt);
 char* gen_param(struct condition* expr);
 char* gen_procedure(char* id, char* param);
 char* gen_function(char* id,char* func, char* param);
 char* gen_funreturn(char* id);
 char* gen_proreturn();
 struct condition* gen_next_var(char* id,char* next,char* type);
 struct condition* gen_vars(struct id* ids);
 struct condition* new_cond(); 
 struct condition* new_cond1(struct condition* exp1);
 struct condition* new_cond2(struct condition* exp,char* op);
 struct condition* new_cond3(struct condition* exp1,struct condition* exp2, char* op);


 void output(char* code);
 void output_label(char* code);
 void output_start(char* code);
%}

%union {
  struct id* idtype;
  int num;
  char* strtype;
  struct condition* condition;
}

%token <strtype> LT
%token <strtype> EQ
%token <strtype> NE
%token <strtype> GT
%token <strtype> GE
%token <strtype> LE
%token RELOP
%token <strtype> PLUS
%token <strtype> MINUS
%token <strtype> MULTI
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
%token <strtype> ANDSYM
%token BEGINSYM
%token FORWARDSYM
%token <strtype> DIVSYM
%token DOSYM
%token ELSESYM
%token ENDSYM
%token FORSYM
%token FUNCTIONSYM
%token IFSYM
%token ARRAYSYM
%token <strtype> MODSYM
%token <strtype> NOTSYM
%token OFSYM
%token <strtype> ORSYM
%token PROCEDURESYM
%token PROGRAMSYM
%token RECORDSYM
%token THENSYM
%token TOSYM
%token TYPESYM
%token VARSYM
%token WHILESYM
%token <strtype> ID
%token <strtype> NUMBER
%token <strtype> STRING
%token UNREC

%type <strtype> Type RelationalOp AddOp MulOp Sign
%type <strtype> CompoundStatement StatementSequence Statement SimpleStatement StructuredStatement AssignmentStatement ProcedureStatement ActualParameterList ActualParameterListSub Block
%type <idtype> ComponentSelection
%type <condition> Expression SimpleExpression SimpleExpressionSub Term Factor FunctionReference Variable Constant

%%
Program: PROGRAMSYM ID SEMICOLON CompoundStatement DOT {output_label($2);output($4);} 
       | PROGRAMSYM ID SEMICOLON TypeDefinitions CompoundStatement DOT {output_label($2);output($5);} 
       | PROGRAMSYM ID SEMICOLON VariableDeclarations CompoundStatement DOT {output_label($2);output($5);} 
       | PROGRAMSYM ID SEMICOLON SubprogramDeclarations CompoundStatement DOT {output_label($2);output($5);} 
       | PROGRAMSYM ID SEMICOLON TypeDefinitions VariableDeclarations CompoundStatement DOT {output_label($2);output($6);} 
       | PROGRAMSYM ID SEMICOLON VariableDeclarations SubprogramDeclarations CompoundStatement DOT {output_label($2);output($6);} 
       | PROGRAMSYM ID SEMICOLON TypeDefinitions SubprogramDeclarations CompoundStatement DOT  {output_label($2);output($6);} 
       | PROGRAMSYM ID SEMICOLON TypeDefinitions VariableDeclarations SubprogramDeclarations CompoundStatement DOT  {output_label($2);output($7);} 
;

TypeDefinitions: TYPESYM TypeDefinitionSub
;

TypeDefinitionSub: TypeDefinition SEMICOLON
                 | TypeDefinition SEMICOLON TypeDefinitionSub
;

TypeDefinition: ID EQ Type
;

VariableDeclarations: VARSYM VariableDeclarationSub
;

VariableDeclarationSub: VariableDeclaration SEMICOLON 
                      | VariableDeclaration SEMICOLON VariableDeclarationSub
;

VariableDeclaration: Identifierlist COLON Type
;

SubprogramDeclarations: ProcedureDeclarationSub
                      | FunctionDeclarationSub
;	     

ProcedureDeclarationSub: ProcedureDeclaration SEMICOLON
                       | ProcedureDeclarationSub SubprogramDeclarations
;

FunctionDeclarationSub: FunctionDeclaration SEMICOLON
		      | FunctionDeclarationSub SubprogramDeclarations
;

ProcedureDeclaration: PROCEDURESYM ID L_BRACE FormalParameterList R_BRACE SEMICOLON Block {output_label($2);output(strconn($7,gen_proreturn()));}
                    | PROCEDURESYM ID L_BRACE FormalParameterList R_BRACE SEMICOLON FORWARDSYM
;

FunctionDeclaration: FUNCTIONSYM ID L_BRACE FormalParameterList R_BRACE COLON ResultType SEMICOLON Block {output_label($2);output(strconn($9,gen_funreturn($2)));}
                   | FUNCTIONSYM ID L_BRACE FormalParameterList R_BRACE COLON ResultType SEMICOLON FORWARDSYM
;

FormalParameterList: {}
                   | FormalParameterListSub
;

FormalParameterListSub: Identifierlist COLON Type
                      | Identifierlist COLON Type SEMICOLON FormalParameterListSub
;

Block: VariableDeclarations CompoundStatement {$$ = $2;}
     | CompoundStatement
;

CompoundStatement: BEGINSYM StatementSequence ENDSYM {$$ = $2;}
;

StatementSequence: Statement
                 | Statement SEMICOLON StatementSequence {$$ = strconn($1,$3);}
;

Statement: SimpleStatement
         | StructuredStatement
;

SimpleStatement: {$$ = "";}
         | AssignmentStatement 
         | ProcedureStatement 
;

AssignmentStatement: Variable ASSIGN Expression {char* assign = gen2($1->addr,$3->addr);$$ = strconn3($1->code,$3->code,assign);}
;

ProcedureStatement: ID L_BRACE ActualParameterList R_BRACE {$$ = gen_procedure($1,$3);}
;

StructuredStatement: CompoundStatement
                   | IFSYM Expression THENSYM Statement {$$ = gen_if_then($2,$4);}
                   | IFSYM Expression THENSYM Statement ELSESYM Statement {$$ = gen_if_then_else($2,$4,$6);}
                   | WHILESYM Expression DOSYM Statement {$$ = gen_while($2,$4);}
		   | FORSYM ID ASSIGN Expression TOSYM Expression DOSYM Statement {$$ = gen_for($2,$4,$6,$8);}
;

Type: ID
| ARRAYSYM L_BRACKET Constant DDOT Constant R_BRACKET OFSYM Type {$$ = "array";}
| RECORDSYM Fieldlist ENDSYM {$$ = "record";}
;

ResultType: ID
;

Fieldlist: {}
          | FieldlistSub
;

FieldlistSub: Identifierlist COLON Type
            | Identifierlist COLON Type SEMICOLON FieldlistSub
;

Constant: Sign NUMBER {$$ = new_cond();$$->addr = new_temp();$$->code = gen3($$->addr,$1,$2);}
        | NUMBER {$$ = new_cond();$$->addr = $1;}
;

Expression: SimpleExpression {$$ = new_cond1($1);$$->left = $1->left;$$->right=$1->right;}
          | SimpleExpression RelationalOp SimpleExpression {$$ = new_cond3($1,$3,$2);}
;

RelationalOp: LT
             |LE
             |GT
             |GE
             |NE
             |EQ
;

SimpleExpression: Sign SimpleExpressionSub { $$ = new_cond2($2,$1);}
                | SimpleExpressionSub {$$ = new_cond1($1);$$->left = $1->left;$$->right=$1->right;}
;

SimpleExpressionSub: Term {$$ = new_cond1($1);$$->left = $1->left;$$->right=$1->right;}
                   | Term AddOp SimpleExpressionSub {$$ = new_cond3($1,$3,$2)}
;

AddOp: PLUS
     | MINUS
     | ORSYM //TODO
;

Term: Factor {$$ = new_cond1($1);$$->left = $1->left;$$->right=$1->right;}
    | Factor MulOp Term {$$ = new_cond3($1,$3,$2);}
;

MulOp: MULTI
     | DIVSYM
     | MODSYM
     | ANDSYM //TODO
;

Factor: NUMBER {$$ = new_cond(); $$->addr = $1;}
      | STRING {$$ = new_cond(); $$->addr = $1;}
      | Variable
      | FunctionReference
      | NOTSYM Factor {$$ = new_cond2($2,$1); }
      | L_BRACE Expression R_BRACE {$$ = new_cond1($2);$$->left = $2->left;$$->right=$2->right;}
;

FunctionReference: ID L_BRACE ActualParameterList R_BRACE {$$ = new_cond(); $$->addr = new_temp();$$->code = gen_function($$->addr,$1,$3);}
;

Variable: ID ComponentSelection {struct id* ids = new_id($1,$2); $$ = gen_vars(ids);}
;

ComponentSelection: {$$ = NULL;}
                  | DOT ID ComponentSelection {$$ = new_id($2,$3);$$->type = "record";}
                  | L_BRACKET Expression R_BRACKET ComponentSelection {$$ = new_id($2->addr,$4);$$->type = "array"; $$->code = strconn($2->code,$$->code);}
;

ActualParameterList: {$$ = "";}
                  | ActualParameterListSub
;

ActualParameterListSub: Expression {$$ = gen_param($1);}
                      | Expression COMMA ActualParameterListSub {char* param = gen_param($1);$$ = strconn(param,$3);}
;

Identifierlist: ID
              | ID COMMA Identifierlist 
;

Sign: PLUS
    | MINUS
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
    freopen("a.txt","w",stdout);
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
  if(next != NULL){
    i->code = next->code;
  }else{
    i->code = "";
  }
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

char* to_num(char* sign,char* value){
    char buf[256];
    snprintf(buf, sizeof buf, "%s%s", sign, value);
    return strdup(buf);
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

char* strconn3(char* s1, char* s2, char* s3){
    char buf[9999];
    snprintf(buf, sizeof buf, "%s%s%s", s1,s2,s3);
    return strdup(buf);
}

struct expr* new_expr(){
  struct expr* i = malloc(sizeof(struct expr));
  i->addr = "";
  i->code = "";
  return i;
}

char* new_temp(){
 char buf[256];
 snprintf(buf, sizeof buf, "%s%d", "t", ++temp_counter);
 return strdup(buf);
}

char* new_label(){
 char buf[256];
 snprintf(buf, sizeof buf, "%s%d", "L", ++label_counter);
 return strdup(buf);
}

struct expr* new_expr_with_code(char* lexeme){
  struct expr* i = new_expr();
  i->code = strdup(lexeme);
  return i;
}

struct expr* new_expr_with_addr(char* addr){
  struct expr* i = new_expr();
  i->addr = strdup(addr);
  return i;
}

struct expr* new_expr_with_both(char* addr){
  struct expr* i = new_expr();
  i->addr = strdup(addr);
  i->code = strdup(addr);
  return i;
}

char* gen2(char* res, char* op1){
 char buf[9999];
 snprintf(buf, sizeof buf, "%5s%3s%5s\n",res," := ",op1);
 return strdup(buf);
}

char* gen4(char* res, char* op1, char* op2, char* operator){
 char buf[9999];
 snprintf(buf, sizeof buf,"%5s%3s%5s %5s %5s\n",res," := ",op1,operator,op2);
 return strdup(buf);
}

char* gen3(char* res, char* op1, char* operator){
 char buf[9999];
 snprintf(buf, sizeof buf, "%5s%3s %5s %5s\n",res," := ",operator,op1);
 return strdup(buf);
}

char* gen_expr(char* op1, char* op2, char* operator){
 char buf[9999];
 snprintf(buf, sizeof buf, "%5s %3s %5s\n",op1,operator,op2);
 return strdup(buf);
}

/**
char* gen_if_then(char* expr,char* stmt) {
 char buf[9999];char buf1[999];char buf2[999];char buf3[999];char buf4[999];char buf5[999];
 char* truelabel = new_label();char* nextlabel = new_label();
 snprintf(buf1, sizeof buf1, "%5s%3s%5s%3s\n"," if ",expr," goto ",truelabel);
 snprintf(buf2, sizeof buf2, "%5s%3s\n"," goto ",nextlabel);
 snprintf(buf3, sizeof buf3, "%s\n",truelabel);
 snprintf(buf4, sizeof buf4, "%s\n",stmt);
 snprintf(buf5, sizeof buf5, "%s\n",nextlabel);
 snprintf(buf, sizeof buf, "%s%s%s%s%s\n",strdup(buf1),strdup(buf2),strdup(buf3),strdup(buf4),strdup(buf5));
 return strdup(buf);
}
*/

char* output_if_then(struct condition* expr,char* truelabel, char* falselabel){
  char buf1[999];char buf2[999];char buf3[999];char buf4[999];char buf5[999];
  if(expr == NULL){
   return;
  }
  char* op = expr->oper;
  struct condition* left = expr->left;
  struct condition* right = expr->right;
  if(!strcmp(op,"or")){
    char buf[9999];
    char* t1 = output_if_then(left,truelabel,falselabel);
    char* t2 = output_if_then(right,truelabel,falselabel);
    snprintf(buf, sizeof buf, "%s%s%s%s",t1,strdup(buf1),t2,strdup(buf2));
    return strdup(buf);
  } else if(!strcmp(op,"and")){
    char buf[9999];
    char* tmplabel1 = new_label();
    char* t1 = output_if_then(left,tmplabel1,falselabel);
    snprintf(buf1, sizeof buf1, "%s%5s%s\n%s:\n",t1," goto ",falselabel,tmplabel1);
    char* t2 = output_if_then(right,truelabel,falselabel);
    snprintf(buf, sizeof buf, "%s%s",strdup(buf1),strdup(t2));
    return strdup(buf);
  } else {
    char buf[9999];
    snprintf(buf3, sizeof buf3, "%5s%3s%5s%3s\n"," if ",expr->addr," goto ",truelabel);
    snprintf(buf, sizeof buf, "%s%s",expr->code,strdup(buf3));
    return strdup(buf);
  }
}

char* gen_if_then(struct condition* expr,char* stmt) {
 char buf[9999];char buf1[999];char buf2[999];char buf3[999];char buf4[999];
 char* truelabel = new_label();char* nextlabel = new_label();
 char* code = output_if_then(expr,truelabel,nextlabel);
 snprintf(buf1, sizeof buf1, "%s%5s%s\n",code, " goto ",nextlabel);
 snprintf(buf2, sizeof buf2, "%s:\n",truelabel);
 snprintf(buf3, sizeof buf3, "%s",stmt);
 snprintf(buf4, sizeof buf4, "%s:\n",nextlabel);
 snprintf(buf, sizeof buf, "%s%s%s%s\n",strdup(buf1),strdup(buf2),strdup(buf3),strdup(buf4));

return strdup(buf);
}

char* gen_if_then_else(struct condition* expr,char* stmt1,char* stmt2){
 char buf[9999];char buf1[999];char buf2[999];char buf3[999];char buf4[999];char buf5[999]; char buf6[999];char buf7[999];char buf8[999];
 char* truelabel = new_label();char* falselabel = new_label();char* nextlabel = new_label();
 char* code = output_if_then(expr,truelabel,falselabel);
 snprintf(buf1, sizeof buf1, "%s%5s%s\n",code, " goto ",falselabel);
 snprintf(buf2, sizeof buf2, "%s:\n",truelabel);
 snprintf(buf3, sizeof buf3, "%s",stmt1);
 snprintf(buf4, sizeof buf4, "%5s%3s\n"," goto ",nextlabel);
 snprintf(buf5, sizeof buf5, "%s:\n",falselabel);
 snprintf(buf6, sizeof buf6, "%s",stmt2);
 snprintf(buf7, sizeof buf7, "%s:\n",nextlabel);
 snprintf(buf, sizeof buf, "%s%s%s%s%s%s%s\n",strdup(buf1),strdup(buf2),strdup(buf3),strdup(buf4),strdup(buf5),strdup(buf6),strdup(buf7));
 return strdup(buf);
}

char* gen_while(struct condition* expr,char* stmt) {
 char buf[9999];char buf1[999];char buf2[999];char buf3[999];char buf4[999];char buf5[999];char buf6[999];char buf0[999];
 char* beginlabel = new_label();char* truelabel = new_label();char* nextlabel = new_label();
 char* code = output_if_then(expr,truelabel,nextlabel);
 snprintf(buf0, sizeof buf0, "%s:\n",beginlabel);
 snprintf(buf1, sizeof buf1, "%s%5s%s\n",code, " goto ",nextlabel);
 snprintf(buf2, sizeof buf2, "%s:\n",truelabel);
 snprintf(buf3, sizeof buf3, "%s",stmt);
 snprintf(buf5, sizeof buf5, "%5s%3s\n"," goto ",beginlabel);
 snprintf(buf6, sizeof buf6, "%s:\n",nextlabel);
 snprintf(buf, sizeof buf, "%s%s%s%s%s%s\n",strdup(buf0),strdup(buf1),strdup(buf2),strdup(buf3),strdup(buf5),strdup(buf6));
 return strdup(buf);
}

char* gen_for(char* id,struct condition* expr,struct condition* eval, char* stmt) {
 char buf[9999];char buf1[999];char buf2[999];char buf3[999];char buf4[999];char buf5[999]; char buf6[999];char buf7[999];char buf8[999];char buf9[999];char buf10[999];char buf11[999];
 char* beginlabel = new_label();char* truelabel = new_label();char* falselabel = new_label();
 snprintf(buf1, sizeof buf1, "%s\n",expr->code);
 snprintf(buf2, sizeof buf2, "%5s%3s%5s\n",strdup(id)," := ",expr->addr);
 snprintf(buf3, sizeof buf3, "%s:\n",beginlabel);
 snprintf(buf4, sizeof buf4, "%s",eval->code);
 snprintf(buf5, sizeof buf5, "%5s%3s%3s%5s%5s%3s\n"," if ",strdup(id)," < ",eval->addr," goto ",truelabel);
 snprintf(buf6, sizeof buf6, "%5s%3s\n"," goto ",falselabel);
 snprintf(buf7, sizeof buf7, "%s:\n",truelabel);
 snprintf(buf8, sizeof buf8, "%s",stmt);
 snprintf(buf9, sizeof buf9, "%s",gen4(strdup(id),strdup(id),"1","+"));
 snprintf(buf10, sizeof buf10, "%5s%3s\n"," goto ",beginlabel);
 snprintf(buf11, sizeof buf11, "%s:\n",falselabel);
 snprintf(buf, sizeof buf, "%s%s%s%s%s%s%s%s%s%s%s\n",strdup(buf1),strdup(buf2),strdup(buf3),strdup(buf4),strdup(buf5),strdup(buf6),strdup(buf7),strdup(buf8),strdup(buf9),strdup(buf10),strdup(buf11));
 return strdup(buf);
}

char* gen_function(char* id,char* func, char* param){
 char buf[9999];char buf1[999];char buf2[999];
 snprintf(buf1, sizeof buf1, "%s",strdup(param));
 snprintf(buf2, sizeof buf2, "%5s%3s%8s%5s\n",strdup(id),":="," funcall ",strdup(func));
 snprintf(buf, sizeof buf, "%s%s",strdup(buf1),strdup(buf2));
 return strdup(buf);
}

char* gen_procedure(char* id, char* param){
 char buf[9999];
 snprintf(buf, sizeof buf, "%s%5s%5s\n",strdup(param)," call ",strdup(id));
 return strdup(buf);
}

char* gen_param(struct condition* expr){
 char buf[9999];
 snprintf(buf, sizeof buf, "%s%5s%3s\n",expr->code," param ",expr->addr);
 return strdup(buf);
}

struct condition* gen_vars(struct id* ids){
 struct id* tmpid = ids;
 struct condition* res = new_cond();
 res->addr = ids->lexeme;
 res->code = "";
 while(tmpid->next != NULL&&tmpid->next->next != NULL){
      tmpid = tmpid->next;
      struct condition* cur = gen_next_var(res->addr,tmpid->lexeme,tmpid->type);
      res->addr = cur->addr;
      res->code = strconn3(res->code,tmpid->code,cur->code);
 }
 if(tmpid->next != NULL){
   tmpid = tmpid->next;
   res->code = strconn(tmpid->code,res->code);
   if(!strcmp(tmpid->type,"record")){
     res->addr = strconn3(res->addr,".",tmpid->lexeme);
   }else {
     res->addr = strconn(res->addr,strconn3("[",tmpid->lexeme,"]"));
   }
 }
 return res;
}

struct condition* gen_next_var(char* id,char* next,char* type){
 struct condition* res = new_cond();
 if(next != NULL){
  char* temp = new_temp();
  res->addr = temp;
  if(!strcmp(type,"record")){
   res->code = gen2(temp,strconn3(id,".",next));
  } else {
   res->code = gen2(temp,strconn(id,strconn3("[",next,"]")));
  }
 }
 return res;
}

char* gen_proreturn(){
 return "return\n";
}

char* gen_funreturn(char* id){
 char buf[999];
 snprintf(buf, sizeof buf, "%10s%s\n","funreturn ",strdup(id));
 return strdup(buf);
}

struct condition* new_cond(){
  struct condition* i = malloc(sizeof(struct condition));
  i->truelabel = "";
  i->falselabel = "";
  i->addr = "";
  i->code = "";
  i->expression = "";
  i->left = NULL;
  i->right = NULL;
  i->oper = "";
  return i;
}

struct condition* new_cond1(struct condition* exp){
  struct condition* i = new_cond();
  i->addr = exp->addr;
  i->code = exp->code;
  i->expression = exp->expression;
  i->left = exp;
  i->oper = exp->oper;
  return i;
}

struct condition* new_cond2(struct condition* exp,char* op){
  struct condition* i = new_cond();
  char* tmpaddr = new_temp();
  i->addr = tmpaddr;
  char* code = gen3(tmpaddr,exp->addr,op); 
  i->expression = code;
  i->code = strconn(exp->code,code);
  i->left = exp;
  i->oper = strdup(op);
  return i;
}

struct condition* new_cond3(struct condition* exp1,struct condition* exp2, char* op){
  struct condition* i = new_cond();
  char* tmpaddr = new_temp();
  i->addr = tmpaddr;
  char* code = gen4(tmpaddr,exp1->addr,exp2->addr,op);
  i->expression = code;
  i->code = strconn3(exp1->code,exp2->code,code);
  i->left = exp1;
  i->right = exp2;
  i->oper = strdup(op);
  return i;
}

void output(char* code){
 printf("%s\n\n",strdup(code));
}

void output_label(char* code){
 printf("__%s:\n",strdup(code));
}

void output_start(char* code){
 printf("%5s__%s:\n"," goto ",strdup(code));
}
