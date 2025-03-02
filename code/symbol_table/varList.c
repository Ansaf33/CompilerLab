#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "varList.h"
#include "Gsymbol.h"
#include "Lsymbol.h"

struct list* createVarNode(char* name,int rowSize,int colSize){

  struct list* temp = (struct list*)malloc(sizeof(struct list));
  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);

  temp->rowSize = rowSize;
  temp->colSize = colSize;

  temp->next = NULL;

  return temp;
}

struct list* addVariable(struct list* head,char* name){
  struct list* temp = createVarNode(name,1,1);
  temp->next = head;
  head = temp;

  return head;
}

struct list* addArray(struct list* head,char* name,int rowSize,int colSize){
  struct list* temp = createVarNode(name,rowSize,colSize);
  temp->next = head;
  head = temp;

  return head;
}

struct list* addFunction(struct list* head,char* name,struct paramlist* param){
  struct list* temp = createVarNode(name,1,1);
  temp->param = param;
  temp->next = head;
  head = temp;

  return head;

}

void printDetails(struct list* head){
  struct list* cur = head;
  while(cur != NULL){
    printf("%s ",cur->name);
    cur = cur->next;
  }
}

void addAllGSymbols(struct list* head, int type){
  struct list* cur = head;
  while(cur != NULL){
    addGSymbol(cur->name,type,cur->rowSize,cur->colSize,cur->param);
    cur = cur->next;
  }
}

void addAllLSymbols(struct list* head,int type){
  struct Lsymbol* Lhead = NULL;
  struct list* cur = head;
  while(cur != NULL){
    Lhead = addLSymbol(cur->name,type);
    cur = cur->next;
  }



}
