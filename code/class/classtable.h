#ifndef CLASSTABLE_H
#define CLASSTABLE_H

#include <stdio.h>
#include "funclist.h"
#include "../udt/fieldlist.h"

struct classtable{
  char* name;
  struct fieldlist* fieldlist;
  struct funclist* methodlist;
  struct classtable* parentPtr;
  int classIndex;
  int fieldCount;
  int methodCount;
  struct classtable* next;
};

struct classtable* createClassNode(char* name,struct fieldlist* fieldlist,struct funclist* methodlist);

struct classtable* addClassNode(struct classtable* head,char* name,struct fieldlist* fieldlist,struct funclist* methodlist);

struct classtable* lookCUp(char* name);

struct fieldlist* lookCFUp(struct classtable* c,char* name);

struct funclist* lookCMUp(struct classtable* c,char* name);


#endif
