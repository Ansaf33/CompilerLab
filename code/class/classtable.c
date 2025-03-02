#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classtable.h"
#include "classmethod.h"
#include "classmember.h"


static int classIndex = 0;
struct classtable* Chead = NULL;


struct classtable* createClassNode(char* name){
  struct classtable* temp = (struct classtable*)malloc(sizeof(struct classtable));

  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);

  temp->classIndex = classIndex++;
  temp->fieldCount = 0;
  temp->methodCount = 0;

  return temp;
}

struct classtable* addClassNode(char* name){

  // check if class already present
  if( lookClassUp(name) != NULL ){
    printf("Class with name | %s | already exists in the classtable.\n",name);
    exit(1);
  }

  // check if the name is present in the typetable
  if( lookTTUp(name) != NULL ){
    printf("Class with name | %s | already exists in the typetable.\n",name);
    exit(1);
  }

  struct classtable* temp = createClassNode(name);


  if( Chead == NULL ){
    Chead = temp;
  }

  else{
    struct classtable* cur = Chead;
    while(cur->next!=NULL){
      cur = cur->next;
    }
    cur->next = temp;
  }
  return temp;
}

struct classmember* addMemberToClass(struct classtable* c,struct typetable* type,struct classtable* Ctype,char* name){
  c->classmember = addMemberNode(c->classmember,type,Ctype,name);
  c->fieldCount++;
}

struct classmethod* addMethodToClass(struct classtable* c,struct typetable* type,char* name,struct paramlist* param){
  c->classmethod = addMethodNode(c->classmethod,type,name,param);
  c->methodCount++;
}


struct classtable* lookClassUp(char* name){
  struct classtable* cur = Chead;
  while(cur!=NULL){
    if(strcmp(cur->name,name)==0){
      return cur;
    }
    cur = cur->next;
  }
  return NULL;

}

void printClass(struct classtable* c){
  printf(" | N A M E : %s | C L A S S I N D E X : %d | M E M B E R C O U N T : %d | M E T H O D C O U N T : %d\n",
         c->name,
         c->classIndex,
         c->fieldCount,
         c->methodCount
         );
  printf("M E M B E R S : \n");
  printClassMembers(c->classmember);
  printf("M E T H O D S : \n");
  printClassMethods(c->classmethod);
  

}




