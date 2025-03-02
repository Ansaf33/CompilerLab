#ifndef varList_H

#define varList_H

#include <stdio.h>
#include <stdlib.h>
#include "paramlist.h"
#include "Lsymbol.h"
#include "Gsymbol.h"

struct list{
  char* name;
  int rowSize;
  int colSize;

  struct paramlist* param;

  struct list* next;
};

struct list* createVarNode(char* name,int rowSize,int colSize);

struct list* addVariable(struct list* head,char* name);

struct list* addArray(struct list* head,char* name,int rowSize,int colSize);

struct list* addFunction(struct list* head,char* name,struct paramlist* param);

void printDetails(struct list* head);

void addAllGSymbols(struct list* head,int type);

void addAllLSymbols(struct list* head,int type);

bool checkValidParam(struct paramlist* p,struct Gsymbol* s);

bool checkValidRetType(int a,int b);

#endif
