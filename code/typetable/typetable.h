#ifndef TYPETABLE_H

#define TYPETABLE_H

#include <stdio.h>
#include <stdbool.h>
#include "../user_defined_type/fieldlist.h"
#include "../AST.h"

struct typetable{
  char* name;
  int size;
  struct fieldlist* fieldlist;
  struct typetable* next;
};

struct typetable* createTTNode(char* name,int size,struct fieldlist* fieldlist);

void addTTNode(char* name,int size,struct fieldlist* fieldlist);

void createPrimitive(void);

struct typetable* lookTTUp(char* name);

int getSize(struct typetable* type);

void printTT(void);

bool same(char* t1,char* t2);

#endif
