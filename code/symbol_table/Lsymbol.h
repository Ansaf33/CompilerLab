#ifndef LSYMBOL_H
#define LSYMBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paramlist.h"

struct Lsymbol{
  char* name;
  struct typetable* type;
  int binding;
  struct Lsymbol* next;
};

// CREATING NODE

struct Lsymbol* createLNode(char* name,struct typetable* type);

// ADDING LOCAL SYMBOL

struct Lsymbol* addLSymbol(char* name,struct typetable* type);

// ADD LAST PARAMS TO LOCAL SYMBOL TABLE

void addLastParamToLSymbolTable(struct paramlist* paramhead);

// CHECKING IF NAME PRESENT IN LOCAL SYMBOL TABLE

struct Lsymbol* lookLUp(char* name);

// PRINTING DETAILS OF LOCAL SYMBOL TABLE

struct Lsymbol* getLSymbolTable(void);

// GETTING HEAD OF LOCAL SYMBOL TABLE

struct Lsymbol* getLHead(void);

// DELETING LOCALSYMBOL TABLE

void deleteLSymbolTable(void);

#endif
