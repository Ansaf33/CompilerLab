#ifndef PARAMLIST_H

#define PARAMLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct paramlist{
  char* name;
  int type;
  struct paramlist* next;
};


struct paramlist* createParamNode(char* name,int type);

struct paramlist* addParameter(struct paramlist* head,char* name,int type);

bool paramPresent(struct paramlist* head,char* name);

void printParameters(struct paramlist* head);

#endif
