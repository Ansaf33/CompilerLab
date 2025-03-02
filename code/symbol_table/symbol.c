#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symbol.h"

struct symbol* head = NULL;
static int address = 4096;

struct symbol* createNode(char* name, int type,int rowSize,int colSize){
  struct symbol* temp = (struct symbol*)malloc(sizeof(struct symbol));
  temp->name = (char*)malloc(sizeof(char)*100);
  temp->name = strcpy(temp->name,name);
  temp->type = type;
  temp->rowSize = rowSize;
  temp->colSize = colSize;
  temp->address = address;
  address = address + rowSize*colSize;

  return temp;

}


void addSymbol(char* name,int type,int rowSize,int colSize){

  if( !lookUp(name) ){
    struct symbol* temp = createNode(name,type,rowSize,colSize);
    temp->next = head;
    head = temp;

  }
  else{
    printf("Variable %s already declared.\n",name);
    exit(1);
  }
  

}

struct symbol* lookUp(char* name){

  struct symbol* current = head;

  while(current != NULL){

    if( strcmp(current->name,name) == 0 ){
      return current;
    }

    current = current->next;


  }

  return NULL;


}


bool checkIfDeclared(char* name){

  struct symbol* current = head;
  while(current!=NULL){
    if( strcmp(current->name,name) == 0 ){
      return true;    
    }
    current = current->next;
  }
  printf("Not declared\n");
  exit(1);
  return false;


}

// PRINTING DETAILS OF ALL SYMBOLS IN THE LINKED LIST

void getAll(){
  struct symbol* current = head;
  while( current != NULL ){
    printf("name : %s | type : %d | rowSize : %d | colSize : %d | address : %d\n",current->name,current->type,current->rowSize,current->colSize,current->address);
    current = current->next;
  }
}


