#ifndef GSYMBOL_H

#define GSYMBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "paramlist.h"
#include "../typetable/typetable.h"
#include "../class/classtable.h"

struct Gsymbol{
  char* name;
  struct typetable* type;
  struct typetable* pointsto;
  struct classtable* Ctype;

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

struct Gsymbol* createGNode(char* name,struct typetable* type,struct classtable* Ctype,int rowSize,int colSize,struct paramlist* param,int isFunction,int isPointer);

// ADDING IT TO LL

void addGSymbol(char* name,struct typetable* type,struct classtable* Ctype,int rowSize,int colSize,struct paramlist* param,int isFunction,int isPointer);


// LOOKUP DETAILS BASED ON NAME

struct Gsymbol* lookGUp(char* name);

// PRINTING DETAILS

void getGSymbolTable(void);



#endif
