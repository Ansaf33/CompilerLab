#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "classmethod.h"
#include "classtable.h"
#include "../symbol_table/paramlist.h"

static int methodPos = 0;
static int mLabel = 0;


// CREATING A METHOD NODE
struct classmethod* createMethodNode(struct typetable* type,char* name,struct paramlist* param){
  struct classmethod* temp = (struct classmethod*)malloc(sizeof(struct classmethod));

  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);
  temp->type = type;
  temp->param = param;
  temp->methodPos = methodPos++;
  temp->mLabel = mLabel++;

  return temp;
}


// ADDING METHOD NODE TO END OF LL
struct classmethod* addMethodNode(struct classmethod* head,struct typetable* type,char* name,struct paramlist* param){

  // check if method already exists
  if( lookMethodUp(head,name) != NULL ){
    printf("Method named | %s | already exists.\n",name);
    exit(1);
  }

  // check if return type exists in typetable
  if( type == NULL ){
    printf("Return type of function | %s | does not exist.\n",name);
    exit(1);
  }

  if( head == NULL ){
    methodPos = 0;
    mLabel = 0;
  }
 
  struct classmethod* temp = createMethodNode(type,name,param);

  if( head == NULL ){
    head = temp;
  }
  else{
    struct classmethod* cur = head;
    while(cur->next!=NULL){
      cur = cur->next;
    }
    cur->next = temp;
  }
  return head;

}

// LOOKING UP METHOD BASED ON NAME
struct classmethod* lookMethodUp(struct classmethod* head,char* name){
  struct classmethod* temp = head;
  while(temp!=NULL){
    if(strcmp(temp->name,name)==0){
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

// PRINTING THE CLASSMETHOD LIST
void printClassMethods(struct classmethod* head){
  struct classmethod* cur = head;
  while(cur!=NULL){
    printf(" | name : %s | type : %s | hasParams : %d | methodPos : %d | mLabel : %d | \n",
           cur->name,
           cur->type->name,
           cur->param?1:0,
           cur->methodPos,
           cur->mLabel
           );
    printParameters(cur->param);
    cur = cur->next;
  }
}


