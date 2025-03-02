#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

// ----------- CODE TO ADD VARIABLE TO LIST

struct list* addVariable(struct list* head,char* name){
  struct list* temp = createVarNode(name,1,1);
  temp->next = head;
  head = temp;

  return head;
}

// --------------- CODE TO ADD AN ARRAY TO THE LIST

struct list* addArray(struct list* head,char* name,int rowSize,int colSize){
  struct list* temp = createVarNode(name,rowSize,colSize);
  temp->next = head;
  head = temp;

  return head;
}

// ------------------ CODE TO ADD A FUNCTION TO THE LIST

struct list* addFunction(struct list* head,char* name,struct paramlist* param){
  struct list* temp = createVarNode(name,1,1);
  temp->param = param;
  temp->next = head;
  head = temp;

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

void addAllGSymbols(struct list* head, int type){
  struct list* cur = head;
  while(cur != NULL){
    addGSymbol(cur->name,type,cur->rowSize,cur->colSize,cur->param);
    cur = cur->next;
  }
}


// ----------------- INPUT IS A LIST, ADDED TO LSYMBOL TABLE

void addAllLSymbols(struct list* head,int type){
  struct Lsymbol* Lhead = NULL;
  struct list* cur = head;
  while(cur != NULL){
    Lhead = addLSymbol(cur->name,type);
    cur = cur->next;
  }



}

// ---------------------- CHECK IF DECLARED AND DEFINED PARAMETERS ARE THE SAME

bool checkValidParams(struct paramlist* param,struct Gsymbol* symbol){

  // CHECKING IF PARAMETERS ARE THE SAME

  struct paramlist* p = param;
  struct paramlist* s = symbol->param;

  while( p && s ){
    if( p->type != s->type ){
      printf("Declared and defined parameters don't match.\n");
      exit(1);
    }
    p = p->next;
    s = s->next;
  }

  if ( p || s ){
    printf("Sizes of declared and defined parameters don't match.\n");
    exit(1);

  }

  return true;

}

// --------------------- CHECK IF DECLARED AND DEFINED RETURN TYPES ARE THE SAME

bool checkValidRetType(int declaredType,int definedType){
  if(declaredType!=definedType){
    printf("Return type of declared and defined function do not match.\n");
    exit(1);
  }
  return true;
}
