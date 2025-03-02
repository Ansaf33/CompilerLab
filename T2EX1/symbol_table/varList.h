#ifndef varList_H

#define varList_H

#include <stdio.h>
#include <stdlib.h>

struct list{
  char* name;
  int rowSize;
  int colSize;

  struct list* next;
};

struct list* createVarNode(char* name,int rowSize,int colSize);

struct list* addVariable(struct list* head,char* name);

struct list* addArray(struct list* head,char* name,int rowSize,int colSize);

void printDetails(struct list* head);

void addAllSymbols(struct list* head,int type);


#endif
