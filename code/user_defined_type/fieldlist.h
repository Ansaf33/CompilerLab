#ifndef FIELDLIST_H
#define FIELDLIST_H

#include <stdio.h>
#include "../typetable/typetable.h"

struct fieldlist{
  char* name;
  int fieldIndex;
  struct typetable* type;
  struct fieldlist* next;

};


struct fieldlist* createFLNode(char* name,struct typetable* type);

struct fieldlist* addFLNode(struct fieldlist* head,char* name,struct typetable* type);

struct fieldlist* lookFLUp(struct fieldlist* head,char* name);

void printFL(struct fieldlist* head);

#endif
