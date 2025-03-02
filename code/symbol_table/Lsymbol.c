#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Lsymbol.h"


struct Lsymbol* createLNode(char* name,int type,int address){
  struct Lsymbol* temp = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);
  temp->type = type;
  temp->address = address;

  temp->next = NULL;

  return temp;
}

struct Lsymbol* addLSymbol(struct Lsymbol* head,char* name,int type,int address){
  struct Lsymbol* temp = createLNode(name,type,address);
  temp->next = head;
  head = temp;

  return head;
}


void getLSymbolTable(struct Lsymbol* head){
  struct Lsymbol* cur = head;
  while(cur != NULL){
    printf("Name : %s | Type : %d | Address : %d |\n",cur->name,cur->type,cur->address);
    cur = cur->next;
  }


}
