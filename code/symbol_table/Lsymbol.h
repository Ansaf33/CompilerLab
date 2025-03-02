#ifndef LSYMBOL_H
#define LSYMBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paramlist.h"

struct Lsymbol{
  char* name;
  int type;
  int address;
  struct Lsymbol* next;
};

// CREATING NODE

struct Lsymbol* createLNode(char* name,int type);

// ADDING LOCAL SYMBOL

struct Lsymbol* addLSymbol(char* name,int type);

// ADD LAST PARAMS TO LOCAL SYMBOL TABLE

void addLastParamToLSymbolTable(struct paramlist* paramhead);

// CHECKING IF NAME PRESENT IN LOCAL SYMBOL TABLE

struct Lsymbol* lookLUp(char* name);

// PRINTING DETAILS OF LOCAL SYMBOL TABLE

struct Lsymbol* getLSymbolTable(void);

// DELETING LOCALSYMBOL TABLE

void deleteLSymbolTable(void);

#endif
