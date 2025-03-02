#ifndef FIELDLIST_H
#define FIELDLIST_H

#include <stdio.h>
#include "../typetable/typetable.h"

struct fieldlist{
  char* name;
  int fieldIndex;

  char* deemed;
  struct typetable* type;

  struct fieldlist* next;

};

// CREATING A FIELD LIST NODE

struct fieldlist* createFLNode(char* name,char* deemed);

// ADDING FIELD LIST NODE TO END OF LL

struct fieldlist* addFLNode(struct fieldlist* head,char* name,char* deemed);

// ADDING REFRESHED TYPES AFTER TYPETABLE ENTERED

void addTypes(struct fieldlist* head);

// LOOKING UP FIELD BASED ON FIELD NAME

struct fieldlist* lookFLUp(struct fieldlist* head,char* name);

// PRINTING FIELD LIST

void printFL(struct fieldlist* head);

// RETURNS FIELD SIZE

int getFLSize(struct fieldlist* head);

#endif
