#ifndef LSYMBOL_H
#define LSYMBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lsymbol{
  char* name;
  int type;
  int address;
  struct Lsymbol* next;

};

struct Lsymbol* createLNode(char* name,int type,int address);

struct Lsymbol* addLsymbol(struct Lsymbol* head,char* name,int type,int address);

void getLSymbolTable(struct Lsymbol* head);

#endif
