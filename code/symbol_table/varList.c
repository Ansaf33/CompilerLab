#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "varList.h"
#include "Gsymbol.h"
#include "Lsymbol.h"
#include "../typetable/typetable.h"

struct list* createVarNode(char* name,int rowSize,int colSize){

  struct list* temp = (struct list*)malloc(sizeof(struct list));
  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);

  temp->rowSize = rowSize;
  temp->colSize = colSize;

  temp->next = NULL;

  return temp;
}

// ----------- CODE TO ADD VARIABLE TO LIST

struct list* addVariable(struct list* head,char* name){
  struct list* temp = createVarNode(name,1,1);
  temp->isFunction = 0;
   
  // ADDING TO END OF LINKED LIST
  if( head == NULL ){
    head = temp;
  }
  else{
    struct list* end = head;
    while(end->next != NULL){
      end = end->next;
    }
    end->next = temp;
  }

 
  return head;
}

// --------------- CODE TO ADD AN ARRAY TO THE LIST

struct list* addArray(struct list* head,char* name,int rowSize,int colSize){
  struct list* temp = createVarNode(name,rowSize,colSize);
  temp->isFunction = 0;

  // ADDING TO END OF LINKED LIST
  if( head == NULL ){
    head = temp;
  }
  else{
    struct list* end = head;
    while(end->next != NULL){
      end = end->next;
    }
    end->next = temp;
  }


  return head;
}

// ------------------ CODE TO ADD A FUNCTION TO THE LIST

struct list* addFunction(struct list* head,char* name,struct paramlist* param){
  struct list* temp = createVarNode(name,1,1);
  temp->isFunction = 1;
  temp->param = param;
  // ADDING TO END OF LINKED LIST
  if( head == NULL ){
    head = temp;
  }
  else{
    struct list* end = head;
    while(end->next != NULL){
      end = end->next;
    }
    end->next = temp;
  }


  return head;

}

// ------------ PRINTING DETAILS

void printDetails(struct list* head){
  struct list* cur = head;
  while(cur != NULL){
    printf("%s ",cur->name);
    cur = cur->next;
  }
}

// ---------------- INPUT IS A LIST, ADDED TO GSYMBOL TABLE

void addAllGSymbols(struct list* head,struct typetable* type){
  struct list* cur = head;
  while(cur != NULL){
    addGSymbol(cur->name,type,cur->rowSize,cur->colSize,cur->param,cur->isFunction);
    cur = cur->next;
  }
}


// ----------------- INPUT IS A LIST, ADDED TO LSYMBOL TABLE

void addAllLSymbols(struct list* head,struct typetable* type){
  struct Lsymbol* Lhead = NULL;
  struct list* cur = head;
  while(cur != NULL){
    Lhead = addLSymbol(cur->name,type);
    cur = cur->next;
  }



}


