#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Gsymbol.h"
#include "../typetable/typetable.h"
#include "../class/classtable.h"

struct Gsymbol* Ghead = NULL;
static int address = 4096;
static int label = 0;


// ------------ CREATE A Gsymbol Node

struct Gsymbol* createGNode(char* name, struct typetable* type,struct classtable* Ctype,int rowSize,int colSize,struct paramlist* param,int isFunction){

  struct Gsymbol* temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));

  temp->name = (char*)malloc(sizeof(char)*100);
  temp->name = strcpy(temp->name,name);
  temp->type = type;
  temp->Ctype = Ctype;

  temp->rowSize = rowSize;
  temp->colSize = colSize;

  temp->param = param;
  temp->flabel = isFunction?label++:-1;

  temp->binding = address;
  address = address + rowSize*colSize;

  return temp;
}


// ------------------------ ADD A Gsymbol to the table

void addGSymbol(char* name,struct typetable* type,struct classtable* Ctype,int rowSize,int colSize,struct paramlist* param,int isFunction){


  if( !lookGUp(name) ){
    struct Gsymbol* temp = createGNode(name,type,Ctype,rowSize,colSize,param,isFunction);

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
    if( !isFunction ){
      printf("Variable | %s | already declared.\n",name);
    }
    else{
      printf("Function | %s | already declared.\n",name);
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
  printf("------------------------------ G L O B A L S Y M B O L T A B L E ------------------------------\n");
  struct Gsymbol* current = Ghead;
  while( current != NULL ){ 
    printf("| name : %s | type : %s | Ctype : %s | rowSize : %d | colSize : %d  | binding : %d  | flabel : %d | hasParam : %d |\n",
           current->name,
           current->type?current->type->name:"NULL",
           current->Ctype?current->Ctype->name:"NULL",
           current->rowSize,
           current->colSize,
           current->binding,
           current->flabel,
           current->param?1:0);

    current = current->next;
  }
  printf("\n");
  
}




