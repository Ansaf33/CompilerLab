#ifndef CLASSMEMBER_H
#define CLASSMEMBER_H


#include <stdio.h>
#include <stdlib.h>
#include "../typetable/typetable.h"
#include "classtable.h"



struct classmember{
  char* name;
  struct typetable* type;
  struct classtable* Ctype;
  int memberIndex;
  struct classmember* next;
};


struct classmember* createMemberNode(struct typetable* type,struct classtable* Ctype,char* name);

struct classmember* addMemberNode(struct classmember* head,struct typetable* type,struct classtable* Ctype,char* name);

struct classmember* lookMemberUp(struct classmember* head,char* name);

void printClassMembers(struct classmember* head);



#endif




