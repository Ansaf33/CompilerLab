#include <stdio.h>
#include <stdlib.h>
#include "../class/classtable.h"
#include "../class/classmethod.h"
#include "../class/classmember.h"



// COPY METHODS FROM PARENT TO CHILD
void copyMethods(struct classtable* child,struct classtable* parent){

  if( !child || !parent ){
    printf("One of the classes is not defined\n");
    exit(1);
  }

  struct classmethod* parent_method = parent->classmethod;
  while(parent_method!=NULL){

    // ------------------------------ creating new node --------------------------------
    struct classmethod* temp = (struct classmethod*)malloc(sizeof(struct classmethod));
    temp->name = parent_method->name;
    temp->type = parent_method->type;
    temp->param = parent_method->param;
    temp->methodPos = parent_method->methodPos;
    temp->mLabel = parent_method->mLabel;
    // ------------------------------- created -----------------------------------------

    // add to end of ll
    struct classmethod* ch = child->classmethod;
    if( child->classmethod == NULL ){
      child->classmethod = temp;
    }
    else{
      struct classmethod* cur = child->classmethod;
      while(cur->next){
        cur = cur->next;
      }
      cur->next = temp;
    }
   

    parent_method = parent_method->next;
  }

  // add them to the methodcount
  child->methodCount = parent->methodCount;

}

// COPY MEMBERS FROM PARENT CLASS TO CHILD CLASS
void copyMembers(struct classtable* child,struct classtable* parent){
  struct classmember* parent_member = parent->classmember;

  if( !child || !parent ){
    printf("One of the classes is not defined\n");
    exit(1);
  }

  while( parent_member != NULL ){

    // ------------------------------ creating new node --------------------------------
    struct classmember* temp = (struct classmember*)malloc(sizeof(struct classmember));
    temp->name = parent_member->name;
    temp->type = parent_member->type;
    temp->Ctype = parent_member->Ctype;
    temp->memberIndex = parent_member->memberIndex;
    // ------------------------------- created -----------------------------------------

    // add to end of ll
    struct classmember* ch = child->classmember;
    if( child->classmember == NULL ){
      child->classmember = temp;
    }
    else{
      struct classmember* cur = child->classmember;
      while(cur->next){
        cur = cur->next;
      }
      cur->next = temp;
    }

    parent_member = parent_member->next;
 
  }

  // add them to membercount
  child->memberCount = parent->memberCount;

}


