#ifndef CLASSTABLE_H
#define CLASSTABLE_H

#include <stdio.h>
#include "classmember.h"
#include "classmethod.h"
#include "../udt/fieldlist.h"
#include "../symbol_table/paramlist.h"
#include "../typetable/typetable.h"
#include "../AST.h"

struct classtable{
  char* name;
  struct classmember* classmember;
  struct classmethod* classmethod;
  struct classtable* parentPtr;
  struct classtable* childPtr;
  int classIndex;
  int memberCount;
  int methodCount;
  struct classtable* next;
};

struct TreeNode;

struct TreeNode* init_dummy(void);

struct classtable* createCNode(char* name,struct classtable* parentPtr);

struct classtable* addClassNode(char* name,struct classtable* parentPtr);

struct classmember* addMemberToClass(struct classtable* c,struct typetable* type,struct classtable* Ctype,char* name);

struct classmethod* addMethodToClass(struct classtable* c,struct typetable* type,char* name,struct paramlist* param);

struct classtable* lookClassUp(char* name);

struct classmember* lookMemberInClassUp(struct classtable* c,char* name);

struct classmethod* lookMethodInClassUp(struct classtable* c,char* name,struct paramlist* p,struct TreeNode* argList);

void printClass(struct classtable* head);

void checkDeclDef(struct classtable* c,struct typetable* type,char* name,struct paramlist* param);

int getNoOfClasses(void);

#endif
