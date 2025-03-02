#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"
#include "../typetable/typetable.h"

int fieldIndex = 0;
// ------------------- CREATING A FIELDLIST NODE

struct fieldlist* createFLNode(char* name,char* deemed){
  struct fieldlist* temp = (struct fieldlist*)malloc(sizeof(struct fieldlist));

  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);

  temp->fieldIndex = fieldIndex++;


  temp->deemed = (char*)malloc(sizeof(char)*100);
  strcpy(temp->deemed,deemed);
  

  return temp;
}

// -------------------- ADDING A FIELDLIST NODE TO END OF LL

struct fieldlist* addFLNode(struct fieldlist* head,char* name,char* deemed){

  // check if fieldname already exists
  if( lookFLUp(head,name) != NULL ){
    printf("Field | %s | already exists in the fieldlist.\n",name);
    exit(1);
  }

  // reset field index
  if( head == NULL ){
    fieldIndex = 0;
  }

  struct fieldlist* temp = createFLNode(name,deemed);


  // add to end of ll
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

// -------------------- REFRESH TYPES AFTER TYPETABLE DECLARATION

void addTypes(struct fieldlist* head){
  struct fieldlist* cur = head;
  while(cur != NULL){
    cur->type = lookTTUp(cur->deemed);

    if( cur->type == NULL ){
      printf("Type | %s | does not exist within typetable.\n",cur->deemed);
      exit(1);
    }

    cur = cur->next;
  }
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
    printf("--------------------------> | name : %s | type : %s | fieldIndex : %d |\n",cur->name,cur->type->name,cur->fieldIndex);
    cur = cur->next;
  }
}


// -------------- GET SIZE OF FIELDLIST

int getFLSize(struct fieldlist* head){
  int sz = 0;
  struct fieldlist* cur = head;
  while(cur!=NULL){
    cur = cur->next;
    sz++;
  }
  return sz;

}

// --------------- CHECK IF A GIVEN TYPE IS A UDT

bool isUDT(char* type){
  if( type == NULL ){
    return false;
  }
  bool isPrimitive = (strcmp(type,"int") == 0 || strcmp(type,"bool") == 0 || strcmp(type,"str") == 0);
  return !isPrimitive; 

}
