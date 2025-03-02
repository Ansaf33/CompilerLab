#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classtable.h"
#include "funclist.h"
#include "../udt/fieldlist.h"

static int classIndex = 0;
struct classtable* Chead = NULL;


// CREATING A CLASS NODE
struct classtable* createClassNode(char* name,struct fieldlist* fieldlist,struct funclist* methodlist){
  struct classtable* temp = (struct classtable*)malloc(sizeof(struct classtable));

  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);

  temp->fieldlist = fieldlist;
  temp->methodlist = methodlist;

  temp->classIndex = classIndex++;
  temp->fieldCount = getFLSize(temp->fieldlist);
  temp->methodCount = getMLSize(temp->methodlist);

  temp->next = NULL;
}


// ADDING NODE TO END OF LIST
struct classtable* addClassNode(struct classtable* head,char* name,struct fieldlist* fieldlist,struct funclist* methodlist){
  struct classtable* temp = createClassNode(name,fieldlist,methodlist);

  // CHECK IF CLASS ALREADY PRESENT
  if( lookCUp(name) != NULL ){
    printf("Class with same name | %s | already declared.\n",name);
    exit(1);
  }

  if( head == NULL ){
    head = temp;
  }

  else{
    struct classtable* cur = head;
    while( cur->next != NULL ){
      cur = cur->next;
    }
    cur->next = temp;
  }

  Chead = head;
  return head;
}



// RETURNS CLASS ENTRY BASED ON NAME
struct classtable* lookCUp(char* name){
  struct classtable* cur = Chead;
  while(cur!=NULL){
    if(strcmp(cur->name,name)==0){
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

// RETURNS FIELDLIST ENTRY BASED ON NAME
struct fieldlist* lookCFUp(struct classtable* c,char* name){
  return lookFLUp(c->fieldlist,name);
}

// RETURNS FUNCLIST ENTRY BASED ON NAME
struct funclist* lookCMUp(struct classtable* c,char* name){
  return lookFUp(c->methodlist,name);
}
