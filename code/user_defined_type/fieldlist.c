#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "../typetable/typetable.h"

int fieldIndex = 0;
// ------------------- CREATING A FIELDLIST NODE

struct fieldlist* createFLNode(char* name,struct typetable* type){
  struct fieldlist* temp = (struct fieldlist*)malloc(sizeof(struct fieldlist));

  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);

  temp->fieldIndex = fieldIndex++;
  temp->type = type;

  return temp;
}

// -------------------- ADDING A FIELDLIST NODE TO END OF LL

struct fieldlist* addFLNode(struct fieldlist* head,char* name,struct typetable* type){

  // CHECK IF FIELD ALREADY EXISTS
  if( lookFLUp(head,name) != NULL ){
    printf("Field | %s | already exists in the fieldlist.\n",name);
    exit(1);
  }

  // RESET FIELD INDEX
  if( head == NULL ){
    fieldIndex = 0;
  }

  struct fieldlist* temp = createFLNode(name,type);

  if( head == NULL ){
    head = temp;
  }
  else{

    struct fieldlist* end = head;

    while(end->next!=NULL){
      end = end->next;
    }

    end->next = temp;
  }
  return head;

}

// ------------------ GET FIELDLIST BY NAME

struct fieldlist* lookFLUp(struct fieldlist* head,char* name){
  struct fieldlist* cur = head;
  while(cur!=NULL){
    if( strcmp(cur->name,name) == 0 ){
      return cur;
    }
    cur = cur->next;
  }
  return NULL;


}

// ------------------- PRINTING DETAILS OF FIELDLIST

void printFL(struct fieldlist* head){
  struct fieldlist* cur = head;
  while( cur != NULL ){
    printf("| name : %s | fieldIndex : %d |\n",cur->name,cur->fieldIndex);
    cur = cur->next;
  }
}



