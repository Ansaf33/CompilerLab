#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Lsymbol.h"
#include "paramlist.h"

static int Laddress = 0;
struct Lsymbol* Lhead = NULL;


// -------------------- CREATING A NODE FOR LOCAL SYMBOL TABLE

struct Lsymbol* createLNode(char* name,int type){
  struct Lsymbol* temp = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);
  temp->type = type;
  temp->address = Laddress++;;

  temp->next = NULL;

  return temp;
}

// ------------------- ADDING A LOCAL SYMBOL (NAME,TYPE,ADDRESS) TO THE LOCAL SYMBOL TABLE

struct Lsymbol* addLSymbol(char* name,int type){

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

  addLSymbol(cur->name,cur->type);

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
    printf("--------------- LOCAL SYMBOL TABLE ---------------------\n\n");
    struct Lsymbol* cur = Lhead;
    while(cur != NULL){
      printf("| name : %s | type : %d | address : %d |\n",cur->name,cur->type,cur->address);
      cur = cur->next;
    }
    printf("\n");
  }

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
  Laddress = 0;


}

