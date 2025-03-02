#ifndef CLASSTABLE_H
#define CLASSTABLE_H

#include <stdio.h>
#include "classmember.h"
#include "classmethod.h"
#include "../udt/fieldlist.h"
#include "../symbol_table/paramlist.h"
#include "../typetable/typetable.h"

struct classtable{
  char* name;
  struct classmember* classmember;
  struct classmethod* classmethod;
  struct classtable* parentPtr;
  int classIndex;
  int fieldCount;
  int methodCount;
  struct classtable* next;
};

struct classtable* createCNode(char* name);

struct classtable* addClassNode(char* name);

struct classmember* addMemberToClass(struct classtable* c,struct typetable* type,struct classtable* Ctype,char* name);

struct classmethod* addMethodToClass(struct classtable* c,struct typetable* type,char* name,struct paramlist* param);

struct classtable* lookClassUp(char* name);

struct classmember* lookMemberInClassUp(struct classtable* c,char* name);

struct classmethod* lookMethodInClassUp(struct classtable* c,char* name);

void printClass(struct classtable* head);

void checkDeclDef(struct classtable* c,struct typetable* type,char* name,struct paramlist* param);

int getNoOfClasses(void);

#endif
