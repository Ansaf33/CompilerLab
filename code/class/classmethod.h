#ifndef CLASSMETHOD_H
#define CLASSMETHOD_H

#include <stdio.h>
#include <stdlib.h>
#include "../typetable/typetable.h"
#include "../symbol_table/paramlist.h"

struct classmethod{
  char* name;
  struct typetable* type;
  struct paramlist* param;
  int methodPos;
  int mLabel;
  struct classmethod* next;
};

struct classmethod* createMethodNode(struct typetable* type,char* name,struct paramlist* param);

struct classmethod* addMethodNode(struct classmethod* head,struct typetable* type,char* name,struct paramlist* param);

struct classmethod* lookMethodUp(struct classmethod* head,char* name);

void printClassMethods(struct classmethod* head);

#endif
