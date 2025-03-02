#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "paramlist.h"

struct paramlist* createParamNode(char* name,int type){

  struct paramlist* temp = (struct paramlist*)malloc(sizeof(struct paramlist));
  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);
  temp->type = type;
  temp->next = NULL;
  return temp;

}

struct paramlist* addParameter(struct paramlist* head,char* name,int type){

    if( paramPresent(head,name) ){
      printf("Cannot have parameters with same name.\n");
      exit(1);
    }

    struct paramlist* temp = createParamNode(name,type);
    temp->next = head;
    head = temp;

    return head;


}

bool paramPresent(struct paramlist* head,char* name){
  struct paramlist* cur = head;
  while(cur!=NULL){
    if( strcmp(cur->name,name) == 0 ){
      return true;
    }
    cur = cur->next;
  }
  return false;

}



void printParameters(struct paramlist* head){
  printf("------- PARAMETER LIST -------");
  struct paramlist* cur = head;
  while(cur!=NULL){
    printf("Name : %s | Type : %d |\n",cur->name,cur->type);
    cur = cur->next;
  }

}
