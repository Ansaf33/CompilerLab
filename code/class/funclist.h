#ifndef FUNCLIST_H
#define FUNCLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../typetable/typetable.h"
#include "../symbol_table/paramlist.h"

struct funclist{
  char* name;
  struct typetable* type;
  struct paramlist* param;
  int funcPos;
  int flabel;
  struct funclist* next;
};

struct funclist* createFuncNode(char* name,struct typetable* type,struct paramlist* param);

struct funclist* addFuncNode(struct funclist* head,char* name,struct typetable* type,struct paramlist* param);

struct funclist* lookFUp(struct funclist* head,char* name);

int getMLSize(struct funclist* head);

#endif
