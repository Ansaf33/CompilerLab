#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Gsymbol.h"

struct Gsymbol* Ghead = NULL;
static int address = 4096;
static int label = 0;

struct Gsymbol* createGNode(char* name, int type,int rowSize,int colSize,struct paramlist* param){

  struct Gsymbol* temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));

  temp->name = (char*)malloc(sizeof(char)*100);
  temp->name = strcpy(temp->name,name);
  temp->type = type;

  temp->rowSize = rowSize;
  temp->colSize = colSize;

  temp->param = param;
  temp->flabel = param?label++:-1;

  temp->address = address;
  address = address + rowSize*colSize;

  return temp;

}


void addGSymbol(char* name,int type,int rowSize,int colSize,struct paramlist* param){

  if( !lookGUp(name) ){
    struct Gsymbol* temp = createGNode(name,type,rowSize,colSize,param);
    temp->next = Ghead;
    Ghead = temp;

  }
  else{
    if( !param ){
      printf("Variable %s already declared.\n",name);
    }
    else{
      printf("Function %s already declared.\n",name);
    }
    exit(1);
  }
  

}

struct Gsymbol* lookGUp(char* name){

  struct Gsymbol* current = Ghead;

  while(current != NULL){

    if( strcmp(current->name,name) == 0 ){
      return current;
    }

    current = current->next;

  }

  return NULL;


}


bool checkIfDeclared(char* name){

  struct Gsymbol* current = Ghead;
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

void getGSymbolTable(){
  printf("---------------------------- GLOBAL SYMBOL TABLE ----------------------------\n");
  struct Gsymbol* current = Ghead;
  while( current != NULL ){
    printf("name : %s | type : %d | rowSize : %d | colSize : %d | address : %d | flabel : %d\n",current->name,current->type,current->rowSize,current->colSize,current->address,current->flabel);
    current = current->next;
  }
  getParamTable();
}

void getParamTable(){
  struct Gsymbol* current = Ghead;
  while( current != NULL ){
    if( current->param != NULL ){
      printf("---------------- PARAMETER TABLE FOR FUNCTION : %s ---------------\n",current->name);
      struct paramlist* p = current->param;
      // ITERATING THROUGH EACH PARAMETER
      while( p != NULL ){
        printf("Name : %s | Type : %d | \n",p->name,p->type);
        p = p->next;
      }
    }
    current = current->next;

  }


}


