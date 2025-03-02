#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classmember.h"
#include "classtable.h"
#include "../typetable/typetable.h"
#include "../AST.h"

static int memberIndex = 0;

// CREATING A MEMBER NODE
struct classmember* createMemberNode(struct typetable* type,struct classtable* Ctype,char* name){
  struct classmember* temp = (struct classmember*)malloc(sizeof(struct classmember));
  temp->type = type;
  temp->Ctype = Ctype;
  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);
  temp->memberIndex = memberIndex++;


  if( temp->Ctype ){
    memberIndex++;
  }


  return temp;
}

// ADDING MEMBER NODE
struct classmember* addMemberNode(struct classmember* head,struct typetable* type,struct classtable* Ctype,char* name){

  // check if member with same name already exists
  if( lookMemberUp(head,name) != NULL ){
    printf("Member with same name | %s | already exists.\n",name);
    exit(1);
  }

  if( type == NULL && Ctype == NULL ){
    printf("Type of member | %s | is not defined.\n",name);
    exit(1);
  }

  if( head == NULL ){
    memberIndex = 0;
  }

  struct classmember* temp = createMemberNode(type,Ctype,name);
  
  if( head == NULL ){
    head = temp;
  }
  else{
    struct classmember* cur = head;
    while(cur->next!=NULL){
      cur = cur->next;
    }
    cur->next = temp;
  }

  return head;
}

// LOOKING MEMBER UP
struct classmember* lookMemberUp(struct classmember* head,char* name){
  struct classmember* cur = head;
  while(cur!=NULL){
    if(strcmp(cur->name,name)==0){
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

// PRINT CLASS MEMBERS
void printClassMembers(struct classmember* head){
  struct classmember* cur = head;
  while(cur!=NULL){
    printf("| name : %s | type : %s | ctype : %s | memberIndex : %d |\n",
           cur->name,
           cur->type?cur->type->name:"NULL",
           cur->Ctype?cur->Ctype->name:"NULL",
           cur->memberIndex
           );
    cur = cur->next;
  }
}



