#ifndef parser_header
# define parser_header
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct token{
 char* property;
 char* value;
 char* type;
};

struct ids {
  int index;
  struct ids* next;
  int depth;
};

struct ids* idList(int id, struct ids* next);

void updateID(int,char*);
void updateFunc(int,struct ids* idptr);
void updateVars(struct ids*,char*);
char* toStr(int);
#endif
