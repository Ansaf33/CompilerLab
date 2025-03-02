#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../user_defined_type/fieldlist.h"
#include "../AST.h"

struct typetable* TThead = NULL;

// ----------- CREATING NODE FOR TYPETABLE

struct typetable* createTTNode(char* name,int size,struct fieldlist* fieldlist){
  struct typetable* temp = (struct typetable*)malloc(sizeof(struct typetable));

  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);

  temp->size = size;

  temp->fieldlist = fieldlist;

  return temp;

}

// --------- ADDING NODE TO END OF LINKED LIST

void addTTNode(char* name,int size,struct fieldlist* fieldlist){

  if( lookTTUp(name) != NULL ){
    printf("Type | %s | already exists.\n",name);
    exit(1);
  }
  
  struct typetable* temp = createTTNode(name,size,fieldlist);

  if(TThead == NULL){
    TThead = temp;
  }
  else{
    struct typetable* end = TThead;
    while(end->next != NULL){
      end = end->next;
    }
    end->next = temp;
  }


}

// -------------- CREATING TYPETABLE LINKEDLIST FOR PRIMITIVE DATA TYPES

void createPrimitive(){
  addTTNode("int",1,NULL);
  addTTNode("bool",1,NULL);
  addTTNode("str",1,NULL);
}

// ------------- RETURNING TYPETABLE POINTER BASED ON NAME

struct typetable* lookTTUp(char* name){

  struct typetable* cur = TThead;
  while(cur!=NULL){
    if( strcmp(cur->name,name) == 0 ){
      return cur;
    }
    cur = cur->next;

  }

  return NULL;
}

// -------------- RETURNING MEMORY WORDS NEEDED TO STORE A VARIABLE OF THAT TYPE

int getSize(struct typetable* type){
  return type->size;
}

// --------------- PRINTING TYPETABLE 

void printTT(void){
  printf("---------- T Y P E T A B L E --------\n");
  struct typetable* cur = TThead;
  while( cur != NULL ){
    printf("| name : %s | size : %d | fieldlist : %d |\n",cur->name,cur->size,cur->fieldlist?1:0);
    cur = cur->next;
  }

}

// -------------- CHECK IF BOTH ARE SAME

bool same(char* t1,char* t2){
  return strcmp(t1,t2) == 0;
}
