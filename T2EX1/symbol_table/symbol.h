#ifndef SYMBOL_H

#define SYMBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct symbol{
  char* name;
  int type;
  int rowSize;
  int colSize;
  int address;
  struct symbol* next;

};


// CREATING A NODE

struct symbol* createNode(char* name,int type,int rowSize,int colSize);

// ADDING IT TO LL

void addSymbol(char* name,int type,int rowSize,int colSize);


// LOOKUP DETAILS BASED ON NAME

struct symbol* lookUp(char* name);

// CHECK IF DECLARED, IF NO, THEN EXIT

bool checkIfDeclared(char* name);

// PRINTING DETAILS

void getAll(void);

#endif
