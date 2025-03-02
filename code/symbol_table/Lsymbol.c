#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Lsymbol.h"

static int Laddress = 0;
struct Lsymbol* Lhead = NULL;

struct Lsymbol* createLNode(char* name,int type){
  struct Lsymbol* temp = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);
  temp->type = type;
  temp->address = Laddress++;;

  temp->next = NULL;

  return temp;
}

struct Lsymbol* addLSymbol(char* name,int type){
  struct Lsymbol* temp = createLNode(name,type);
  temp->next = Lhead;
  Lhead = temp;

  return Lhead;

}

struct Lsymbol* lookLUp(char* name){
  struct Lsymbol* temp = Lhead;
  while(temp != NULL){
    if(strcpy(temp->name,name) == 0 ){
      return temp;
    }
    temp = temp->next;

  }
  return NULL;

}


void getLSymbolTable(){
  struct Lsymbol* cur = Lhead;
  while(cur != NULL){
    printf("Name : %s | Type : %d | Address : %d |\n",cur->name,cur->type,cur->address);
    cur = cur->next;
  }


}
