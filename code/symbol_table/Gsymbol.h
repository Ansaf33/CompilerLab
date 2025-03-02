#ifndef GSYMBOL_H

#define GSYMBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "paramlist.h"

struct Gsymbol{
  char* name;
  int type;

  int rowSize;
  int colSize;

  int address;

  struct paramlist* param;
  int flabel;

  struct Gsymbol* next;

};


// CREATING A NODE

struct Gsymbol* createGNode(char* name,int type,int rowSize,int colSize,struct paramlist* param);

// ADDING IT TO LL

void addGSymbol(char* name,int type,int rowSize,int colSize,struct paramlist* param);


// LOOKUP DETAILS BASED ON NAME

struct Gsymbol* lookGUp(char* name);

// CHECK IF DECLARED, IF NO, THEN EXIT

bool checkIfDeclared(char* name);

// PRINTING DETAILS

void getGSymbolTable(void);

// PRINTING PARAMETER DETAILS ( CALLED VIA GETGSYMBOLTABLE )

void getParamTable(void);

#endif
