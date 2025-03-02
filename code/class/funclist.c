#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funclist.h"
#include "../typetable/typetable.h"
#include "../symbol_table/paramlist.h"


static int funcPos = 0;
static int flabel = 0;

// CREATING NODE FOR FUNCLIST
struct funclist* createFuncNode(char* name,struct typetable* type,struct paramlist* param){
  struct funclist* temp = (struct funclist*)malloc(sizeof(struct funclist));
  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);
  temp->type = type;
  temp->param = param;

  return temp;
}


// ADDING FUNCLIST NODE TO END OF LINKED LIST
struct funclist* addFuncNode(struct funclist* head,char* name,struct typetable* type,struct paramlist* param){
  struct funclist* temp = createFuncNode(name,type,param);

  // CHECK IF FUNCTION ALREADY DECLARED
  if( lookFUp(head,name) != NULL ){
    printf("Function | %s | already declared\n",name);
    exit(1);
  }
  
  if( head == NULL ){
    temp = head;
    return temp;
  }
  struct funclist* cur = head;
  while(cur->next!=NULL){
    cur = cur->next;
  }
  cur->next = temp;
  return head;
}

// LOOKING UP FUNCTION BASED ON NAME
struct funclist* lookFUp(struct funclist* head,char* name){
  struct funclist* cur = head;
  while(cur!=NULL){
    if(strcmp(cur->name,name) == 0){
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

// SIZE OF FUNCLIST
int getMLSize(struct funclist* head){
  struct funclist* cur = head;
  int sz = 0;
  while(cur!=NULL){
    cur=cur->next;
    sz++;
  }
  return sz;
}

