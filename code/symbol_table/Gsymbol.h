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

  int binding;


  struct paramlist* param;
  int flabel;
  bool defined;

  struct Gsymbol* next;

};


// CREATING A NODE

struct Gsymbol* createGNode(char* name,int type,int rowSize,int colSize,struct paramlist* param,int isFunction);

// ADDING IT TO LL

void addGSymbol(char* name,int type,int rowSize,int colSize,struct paramlist* param,int isFunction);


// LOOKUP DETAILS BASED ON NAME

struct Gsymbol* lookGUp(char* name);

// PRINTING DETAILS

void getGSymbolTable(void);



#endif
