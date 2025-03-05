#ifndef CLASSMETHOD_H
#define CLASSMETHOD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "classtable.h"
#include "../typetable/typetable.h"
#include "../symbol_table/paramlist.h"
#include "../AST.h"

struct classmethod{
  char* name;
  struct typetable* type;
  struct paramlist* param;
  int methodPos;
  int mLabel;
  struct classmethod* next;
};

struct TreeNode;

struct classmethod* createMethodNode(struct typetable* type,char* name,struct paramlist* param);

struct classmethod* addMethodNode(struct classmethod* head,struct typetable* type,char* name,struct paramlist* param);

struct classmethod* lookMethodUp(struct classmethod* head,char* name,struct paramlist* p,struct TreeNode* argList);

void printClassMethods(struct classmethod* head);

int argCount(struct classmethod* head);

int decrementmLabel(void);

int incrementmLabel(void);

int check(struct TreeNode* ff);

bool matching_params_params(struct paramlist* p1,struct paramlist* p2);

bool matching_params_argList(struct paramlist* p,struct TreeNode* t);

#endif
