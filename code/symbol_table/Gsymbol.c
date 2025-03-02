#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Gsymbol.h"

struct Gsymbol* Ghead = NULL;
static int address = 4096;
static int label = 0;


// ------------ CREATE A Gsymbol Node

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


// ------------------------ ADD A Gsymbol to the table

void addGSymbol(char* name,int type,int rowSize,int colSize,struct paramlist* param){

  if( !lookGUp(name) ){
    struct Gsymbol* temp = createGNode(name,type,rowSize,colSize,param);

    // ADDING TO END OF LINKED LIST
    if( Ghead == NULL ){
      Ghead = temp;
    }
    else{
      struct Gsymbol* end = Ghead;
      while(end->next != NULL){
        end = end->next;
      }
      end->next = temp;
    }

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

// ------------------------ RETURN A POINTER TO THE Gsymbol ENTRY IN THE TABLE BASED ON THE NAME

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



// ----------------------------- PRINTING DETAILS OF ALL SYMBOLS IN THE LINKED LIST

void getGSymbolTable(){
  printf("------------------------------ GLOBAL SYMBOL TABLE ------------------------------\n");
  struct Gsymbol* current = Ghead;
  while( current != NULL ){
    printf("| name : %s | type : %d | rowSize : %d | colSize : %d  | address : %d  | flabel : %d | hasParam : %d |\n",current->name,current->type,current->rowSize,current->colSize,current->address,current->flabel,current->param?1:0);
    current = current->next;
  }
  printf("\n");
  
}




