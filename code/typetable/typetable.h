#ifndef TYPETABLE_H

#define TYPETABLE_H

#include <stdio.h>
#include <stdbool.h>
#include "../udt/fieldlist.h"
#include "../AST.h"

struct typetable{
  char* name;
  int size;
  struct fieldlist* fieldlist;
  struct typetable* next;
};

// CREATING A TYPETABLE NODE 

struct typetable* createTTNode(char* name,int size,struct fieldlist* fieldlist);

// ADDING A NODE TO END OF LL

void addTTNode(char* name,int size,struct fieldlist* fieldlist);

// CREATING PRIMITIVE NODES LIKE (INT,STR,BOOL)

void createPrimitive(void);

// LOOKING UP TYPETABLE ENTRY BASED ON NAME

struct typetable* lookTTUp(char* name);

// GETTING SIZE OF TYPE

int getSize(struct typetable* type);

// PRINTING DETAILS OF TYPETABLE

void printTT(void);

// CHECKING IF TWO TYPES ARE SAME

bool same(char* t1,char* t2);


#endif
