#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classtable.h"
#include "classmethod.h"
#include "classmember.h"
#include "../AST.h"

static int classIndex = 0;
struct classtable* Chead = NULL;


struct classtable* createCNode(char* name,struct classtable* parentPtr){
  struct classtable* temp = (struct classtable*)malloc(sizeof(struct classtable));

  temp->name = (char*)malloc(sizeof(char)*100);
  strcpy(temp->name,name);

  temp->parentPtr = parentPtr;
  temp->classIndex = classIndex++;
  temp->memberCount = 0;
  temp->methodCount = 0;

  return temp;
}

struct classtable* addClassNode(char* name,struct classtable* parentPtr){

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


  struct classtable* temp = createCNode(name,parentPtr);


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
  c->memberCount++;
}

struct classmethod* addMethodToClass(struct classtable* c,struct typetable* type,char* name,struct paramlist* param){

  struct classmethod* inParent = lookMethodInClassUp(c->parentPtr,name,param,NULL);

  if( inParent ){
    struct classmethod* inChild = lookMethodInClassUp(c,name,param,NULL);
    inChild->mLabel = incrementmLabel();
  }
  else{
    c->classmethod = addMethodNode(c->classmethod,type,name,param);
    c->methodCount++;
  }

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

struct classmember* lookMemberInClassUp(struct classtable* c,char* name){
  if( c ){
    return lookMemberUp(c->classmember,name);
  }
  return NULL;
}

struct classmethod* lookMethodInClassUp(struct classtable* c,char* name,struct paramlist* p,struct TreeNode* a){
  if( c ){
    return lookMethodUp(c->classmethod,name,p,a);
  }
  return NULL;
}

void printClass(struct classtable* c){
  printf("N A M E : %s\nP A R E N T : %s\nC L A S S I N D E X : %d\nM E M B E R C O U N T : %d | M E T H O D C O U N T : %d\n",
         c->name,
         c->parentPtr?c->parentPtr->name:"NULL",
         c->classIndex,
         c->memberCount,
         c->methodCount
         );
  printf("M E M B E R S : \n");
  printClassMembers(c->classmember);
  printf("M E T H O D S : \n");
  printClassMethods(c->classmethod);
  

}



// CHECK DECLARED AND DEFINED TYPES AND PARAMETERS
void checkDeclDef(struct classtable* c,struct typetable* type,char* name,struct paramlist* param){

  // check if method is declared
  struct classmethod* method = lookMethodInClassUp(c,name,param,NULL);

  if( method == NULL ){
    printf("Method | %s | not declared in class.\n",name);
    exit(1);
  }

  if( method->type == NULL ){
    printf("Type for function | %s | not defined in typetable.\n",name);
    exit(1);
  }

  if( method->type != type ){
    printf("Declared return type | %s | does not match with defined return type | %s | for function | %s |\n",method->type->name,type->name,name);
    exit(1);
  }


  struct paramlist* defined = param;
  struct paramlist* declared = method->param;

  while( defined && declared ){
  
    if( strcmp(defined->name,declared->name) != 0 ){
      printf("Defined name | %s | does not match with declared name | %s | of function | %s |\n",defined->name,declared->name,name);
      exit(1);
    }
    if( defined->type != declared->type ){
      printf("Defined type | %s | does not match with declared type | %s | of function | %s |\n",defined->type->name,declared->type->name,name);
      exit(1);
    }

    defined = defined->next;
    declared = declared->next;
  }

  if( defined || declared ){
    printf("Defined size does not match Declared size of function | %s |\n",name);
    exit(1);
  }

}

// GET NUMBER OF CLASSES
int getNoOfClasses(){
  struct classtable* cur = Chead;
  int sz = 0;
  while(cur){
    cur = cur->next;
    sz++;
  }
  return sz;
}

