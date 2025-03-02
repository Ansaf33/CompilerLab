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

// CREATING NODE

struct paramlist* createParamNode(char* name,int type);

// ADDING PARAMETER TO LIST

struct paramlist* addParameter(struct paramlist* head,char* name,int type);

// CHECKING IF PARAMETER IS PRESENT BASED ON NAME

bool paramPresent(struct paramlist* head,char* name);

// PRINTING PARAMETERS

void printParameters(struct paramlist* head);


#endif
