#ifndef varList_H

#define varList_H

#include <stdio.h>
#include <stdlib.h>
#include "paramlist.h"
#include "../class/classtable.h"


struct list{
  char* name;
  int rowSize;
  int colSize;
  int isFunction;

  struct paramlist* param;

  struct list* next;
};

struct list* createVarNode(char* name,int rowSize,int colSize);

struct list* addVariable(struct list* head,char* name);

struct list* addArray(struct list* head,char* name,int rowSize,int colSize);

struct list* addFunction(struct list* head,char* name,struct paramlist* param);

void printDetails(struct list* head);

void addAllGSymbols(struct list* head,struct typetable* type,struct classtable* Ctype);

void addAllLSymbols(struct list* head,struct typetable* type);



#endif
