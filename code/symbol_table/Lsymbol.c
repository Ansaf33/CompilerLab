#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Lsymbol.h"
#include "paramlist.h"
#include "../typetable/typetable.h"

static int binding = 1;
static int diff = -4;

struct Lsymbol* Lhead = NULL;


// -------------------- CREATING A NODE FOR LOCAL SYMBOL TABLE

struct Lsymbol* createLNode(char* name,struct typetable* type){
  struct Lsymbol* temp = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);
  temp->type = type;

  if(type == NULL){
    printf("Type for Local Symbol | %s | not present.\n",name);
    exit(1);
  }

  temp->binding = binding++;

  temp->next = NULL;

  return temp;
}

// ------------------- ADDING A LOCAL SYMBOL (NAME,TYPE,ADDRESS) TO THE LOCAL SYMBOL TABLE

struct Lsymbol* addLSymbol(char* name,struct typetable* type){

  if( lookLUp(name) ){
    printf("Local variable %s already declared.\n",name);
    exit(1);
  }

  struct Lsymbol* temp = createLNode(name,type);

  // ADDING TO END OF LINKED LIST
    if( Lhead == NULL ){
      Lhead = temp;
    }
    else{
      struct Lsymbol* end = Lhead;
      while(end->next != NULL){
        end = end->next;
      }
      end->next = temp;
    }
  

  return Lhead;

}


// ------------------ ADD LAST PARAMETER TO LOCAL SYMBOL TABLE

void addLastParamToLSymbolTable(struct paramlist* paramhead){
  struct paramlist* cur = paramhead;

  while(cur->next != NULL){
    cur = cur->next;
  }

  struct Lsymbol* curr = addLSymbol(cur->name,cur->type);

  while(curr->next != NULL ){
    curr = curr->next;
  }

  curr->binding+=diff;
  binding--;
  diff-=1;

}


// ------------------ LOOKING UP AN ENTRY IN THE LOCAL SYMBOL TABLE BY ITS NAME

struct Lsymbol* lookLUp(char* name){
  struct Lsymbol* temp = Lhead;
  while(temp != NULL){
    if(strcmp(temp->name,name) == 0 ){
      return temp;
    }
    temp = temp->next;

  }
  return NULL;

}

// ------------------- PRINTING DETAILS OF LOCAL SYMBOL TABLE

struct Lsymbol* getLSymbolTable(){
  if(Lhead){
    printf("--------------- L O C A L S Y M B O L T A B L E ---------------------\n\n");
    struct Lsymbol* cur = Lhead;
    while(cur != NULL){
      printf("| name : %s | type : %s | binding : %d |\n",cur->name,cur->type->name,cur->binding);
      cur = cur->next;
    }
    printf("\n");
  }

  return Lhead;


}

// ----------------- GETTING HEAD

struct Lsymbol* getLHead(){
  return Lhead;
}

// --------------- DELETING LOCAL TABLE

void deleteLSymbolTable(){
  struct Lsymbol* cur = Lhead;
  struct Lsymbol* prev = NULL;
  while(cur!=NULL){
    prev = cur;
    cur = cur->next;
    free(prev);
  }

  Lhead = NULL;
  binding = 1;
  diff = -4;

}

