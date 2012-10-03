#ifndef s4_header
# define s4_header
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define true 1
#define false 0

struct token{
 char* property;
 char* value;
 char* type;
};

struct symtable{
 struct token entity[900];
 struct symtable* parent;
 int count;
};

struct id {
  int index;
  char* lexeme;
  char* type;
  struct id* next;
  int depth;
  char* code;
};

struct expr {
 char* addr;
 char* code;
};

struct condition {
 char* addr;
 char* code;
 char* expression;
 char* truelabel;
 char* falselabel;
 struct condition* left;
 struct condition* right;
 char* oper;
};

#endif
