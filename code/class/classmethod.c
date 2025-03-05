#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "classmethod.h"
#include "classtable.h"
#include "../symbol_table/paramlist.h"
#include "../AST.h"
#include "../typesatisfy/typesatisfy.h"

static int methodPos = 0;
static int mLabel = 0;


// CREATING A METHOD NODE
struct classmethod* createMethodNode(struct typetable* type,char* name,struct paramlist* param){
  struct classmethod* temp = (struct classmethod*)malloc(sizeof(struct classmethod));

  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);
  temp->type = type;
  temp->param = param;
  temp->methodPos = methodPos++;
  temp->mLabel = incrementmLabel();

  return temp;
}


// ADDING METHOD NODE TO END OF LL
struct classmethod* addMethodNode(struct classmethod* head,struct typetable* type,char* name,struct paramlist* param){

  // check if method already exists
  if( lookMethodUp(head,name,param,NULL) != NULL ){
    // check the parent class
    printf("Method named | %s | already exists.\n",name);
    exit(1);
  }

  // check if return type exists in typetable
  if( type == NULL ){
    printf("Return type of function | %s | does not exist.\n",name);
    exit(1);
  }

  if( head == NULL ){
    methodPos = 0;
  }
 
  struct classmethod* temp = createMethodNode(type,name,param);

  if( head == NULL ){
    head = temp;
  }
  else{
    struct classmethod* cur = head;
    while(cur->next!=NULL){
      cur = cur->next;
    }
    cur->next = temp;
  }
  return head;

}

// LOOKING UP METHOD BASED ON NAME
struct classmethod* lookMethodUp(struct classmethod* head,char* name,struct paramlist* param,struct TreeNode* t){
  struct classmethod* temp = head;
  while(temp!=NULL){
    if(strcmp(temp->name,name)==0){
      bool p = matching_params_params(param,temp->param);
      bool a = matching_params_argList(temp->param,t);
      if( p || a ){
        return temp;
      }
    }
    temp = temp->next;
  }
  return NULL;
}

// PRINTING THE CLASSMETHOD LIST
void printClassMethods(struct classmethod* head){
  struct classmethod* cur = head;
  while(cur!=NULL){
    printf(" | name : %s | type : %s | hasParams : %d | methodPos : %d | mLabel : %d |",
           cur->name,
           cur->type->name,
           cur->param?1:0,
           cur->methodPos,
           cur->mLabel
           );
    printParameters(cur->param);
    cur = cur->next;
  }
}

// NUMBER OF ARGUMENTS
int argCount(struct classmethod* head){
  struct classmethod* temp = head;
  int c = 0;
  while(temp){
    temp = temp->next;
    c++;
  }
  return c;
}

// DECREMENT M LABEL
int decrementmLabel(){
  return mLabel--;
}

// INCREMENT M LABEL
int incrementmLabel(){
  return mLabel++;
}

//------------------------------------------------------------------------------------------ COMPARE PARAMS TO ARGUMENTLIST
bool matching_params_argList(struct paramlist* p,struct TreeNode* a){

  struct paramlist* cur1 = p;
  struct TreeNode* cur2 = a;

  // size of params
  int sz_of_params = getParamSize(p);
  // size of argList
  int sz_of_args = 0;
  struct TreeNode* curr = a;
  while(curr){
    curr = curr->next;
    sz_of_args++;
  }


  while(cur1&&cur2){
    if( cur1->type != cur2->type ){

      return false;
    }
    cur1 = cur1->next;
    cur2 = cur2->next;
  }

  if( cur1 || cur2 ){

    return false;
  }

  return true;
}

// ---------------------------------------------------------------------------------------- COMPARE PARAMS TO PARAMS
bool matching_params_params(struct paramlist* p1,struct paramlist* p2){

  struct paramlist* a = p1;
  struct paramlist* b = p2;

  while( a && b ){
    bool sameName = strcmp(a->name,b->name) == 0;
    bool sameType = (a->type == b->type);

    if( !( sameName && sameType ) ){
      return false;
    }
    a = a->next;
    b = b->next;
  }

  if( a || b ){

    return false;
  }

  return true;
}

 
