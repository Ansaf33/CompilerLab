#ifndef GSYMBOL_H

#define GSYMBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "paramlist.h"
#include "../typetable/typetable.h"

struct Gsymbol{
  char* name;
  struct typetable* type;

  int rowSize;
  int colSize;

  int binding;

  // parameters of function
  struct paramlist* param;

  int flabel;
  bool defined;

  struct Gsymbol* next;

};


// CREATING A NODE

struct Gsymbol* createGNode(char* name,struct typetable* type,int rowSize,int colSize,struct paramlist* param,int isFunction);

// ADDING IT TO LL

void addGSymbol(char* name,struct typetable* type,int rowSize,int colSize,struct paramlist* param,int isFunction);


// LOOKUP DETAILS BASED ON NAME

struct Gsymbol* lookGUp(char* name);

// PRINTING DETAILS

void getGSymbolTable(void);



#endif
