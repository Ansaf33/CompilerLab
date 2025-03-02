#ifndef varList_H

#define varList_H

#include <stdio.h>
#include <stdlib.h>

struct list{
  char* name;
  int size;
  struct list* next;
};

struct list* createVarNode(char* name,int size);

struct list* addVariable(struct list* head,char* name);

struct list* addArray(struct list* head,char* name,int size);

void printDetails(struct list* head);

void addAllSymbols(struct list* head,int type);


#endif
