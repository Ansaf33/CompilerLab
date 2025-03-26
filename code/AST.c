
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "AST.h"
#include "operators/optrans.h"
#include "symbol_table/Gsymbol.h"
#include "symbol_table/Lsymbol.h"
#include "typetable/typetable.h"
#include "typesatisfy/typesatisfy.h"


struct paramlist* init_dummy_param(){
  struct paramlist* param = (struct paramlist*)malloc(sizeof(struct paramlist));
  param->type = lookTTUp("null");
  param->name = (char*)malloc(sizeof(char)*10);
  strcpy(param->name,"nulll");
  return param;
}


// ------------------------------------------------------------------------------------------------------------ CREATE NODE FOR NUMBERS

struct TreeNode* createNumNode(int val){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = val;
  temp->string = NULL;
  temp->op = -1;
  temp->type = lookTTUp("int");
  temp->varname = NULL;
  temp->left = NULL;
  temp->right = NULL;
  temp->middle = NULL;
 

  return temp;
}

// -------------------------------------------------------------------------------------------------------------- CREATE NODE FOR OPERATORS


struct TreeNode* createOpNode(struct typetable* type,int op,struct TreeNode* left,struct TreeNode* right){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));

  bool anyptr = ( (left && left->type == lookTTUp("ptr"))  ||  ( right && right->type == lookTTUp("ptr") ) );

  temp->val = -1;
  temp->string = NULL;
  temp->op = op;
  temp->type = (anyptr && op != 27 )?lookTTUp("ptr"):type;
  temp->varname = NULL;
  temp->left = left;
  temp->right = right;
  temp->middle = NULL;

  switch(op){
    case 0:
    case 1:
    case 2:
    case 3:
      arithmetic_typeSatisfied(temp);
      break;
    case 4:
      assignment_typeSatisfied(temp);
      break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      logical_typeSatisfied(temp);
      break;
    case 11:
      read_typeSatisfied(temp);
      break;
    case 12:
      write_typeSatisfied(temp);
      break;
  }


  


  return temp;
}

// ------------------------------------------------------------------------------------------------------------  CREATE NODE FOR STRINGS


struct TreeNode* createStringNode(char* string){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->string = (char*)malloc(sizeof(char)*100);
  strcpy(temp->string,string);
  temp->op = -1;
  temp->type = lookTTUp("str");
  temp->varname = NULL;
  temp->left = NULL;
  temp->right = NULL;
  temp->middle = NULL;

  return temp;
}



// --------------------------------------------------------------------------------------------------------------- CREATE NODE FOR IDs

struct TreeNode* createIdNode(char* varname,struct TreeNode* row,struct TreeNode* column){

  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->Gsymbol = lookGUp(varname);
  temp->Lsymbol = lookLUp(varname);


  // ------------------------- DECIDING LOCAL / GLOBAL / NOT DECLARED --------------
  
  if( temp->Lsymbol  ){ 
    temp->Gsymbol = NULL;
  }
  else if( temp->Gsymbol ){
    temp->Lsymbol = NULL;
  }
  else{
    printf("Cannot declare variable | %s | outside declaration scope\n",varname);
    exit(1);
  }
  // if row/column is present, must be an array
  if( row || column ){
    if( temp->Gsymbol && !temp->Gsymbol->isArray ){
      printf("| %s | is not an array, but has row and column attributes\n",varname);
      exit(1);
    }
  }
  if( !row && !column ){
    if( temp->Gsymbol && temp->Gsymbol->isArray ){
      printf("| %s | is array, but does not have row and column attributes\n",varname);
      exit(1);

    }
  }
  // ------------------------- DECIDING DONE ----------------------------------------
 
  temp->val = -1;
  temp->string = NULL;

  temp->op = -1;


  temp->type = temp->Lsymbol?temp->Lsymbol->type:temp->Gsymbol->type;
  temp->Ctype = temp->Gsymbol?temp->Gsymbol->Ctype:NULL;


  temp->varname = (char*)malloc(sizeof(char)*100);
  strcpy(temp->varname,varname);

  temp->row = row;
  temp->column = column;

  temp->left = NULL;
  temp->right = NULL;
  temp->middle = NULL;



  return temp;

}



// ------------------------------------------------------------------------------------------------------------ CREATE NODE FOR IF STATEMENTS

struct TreeNode* createIfNode(struct TreeNode* middle,struct TreeNode* left,struct TreeNode* right){

  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->string = NULL;
  temp->op = 14;
  temp->type = NULL;
  temp->varname = NULL;
  temp->left = left;
  temp->middle = middle;
  temp->right = right;

  // CHECK IF SATISFIABLE
  if_typeSatisfied(temp);

  
  return temp;

}

// ------------------------------------------------------------------------------------------------------------ CREATE NODE FOR WHILE STATEMENTS

struct TreeNode* createWhileNode(int op,struct TreeNode* left,struct TreeNode* right){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));  
  temp->val = -1;
  temp->string = NULL;
  temp->op = op;
  temp->type = NULL;
  temp->varname = NULL;
  temp->left = left;
  temp->right = right;
  temp->middle = NULL;

  while_typeSatisfied(temp);

  

  return temp;


}

// ------------------------------------------------------------------------------------------------------------ CREATE NODE FOR FUNCTIONS

struct TreeNode* createFunctionNode(char* varname,struct TreeNode* argList){

  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));


  // ---------------- CHECK IF PRESENT IN GLOBAL TABLE -------------------
  temp->Gsymbol = lookGUp(varname);

  if(temp->Gsymbol == NULL){
    printf("Function | %s | is not declared.\n",varname);
    exit(1);
  }
  // -------------------- CHECK IF FUNCTION IS DEFINED ------------------- ( SMALL SACRIFICE MADE HERE )

  /*
  if( !temp->Gsymbol->defined ){
    printf("Function | %s | is not defined.\n",varname);
    exit(1);
  }
  */

  // ------------------ CHECKING DONE ------------------------------------

  temp->val = -1;
  temp->op = -1;
  temp->type = temp->Gsymbol->type;
  temp->varname = (char*)malloc(sizeof(char)*100);
  strcpy(temp->varname,varname);

  temp->left = NULL;
  temp->right = NULL;
  temp->middle = NULL;

  //  ---------- CHECK IF ARGLIST GIVEN MATCHES THE TYPE IN THE PARAMETER TABLE OF THAT FUNCTION ----------------
    temp->argList = argList;

    struct TreeNode* arg = temp->argList;
    struct paramlist* param = temp->Gsymbol->param;

    while( arg && param ){
      if( !same(arg->type->name,param->type->name) ){
        printf("Argument and parameter does not match types\n");
        exit(1);
      }
      arg = arg->next;
      param = param->next;
    }
    if( arg || param ){
      printf("Argument size does not match parameter size.\n");
      exit(1);
    }
  // ------------------------------------------------ CHECKING DONE --------------------------------------------
  
  return temp;
}

// ------------------------------------------------------------------------------------------------------------- CREATE LIST OF ARGUMENTS

struct TreeNode* addArgToList(struct TreeNode* listHead,struct TreeNode* argHead){
  if( listHead == NULL ){
    listHead = argHead;
  }
  else{
    struct TreeNode* end = listHead;
    while(end->next != NULL){
      end = end->next;
    }
    end->next = argHead;
  }
  return listHead;
}



// ---------------------------------------------------------------------------------------------------------------------- CREATE RETURN NODE 

struct TreeNode* createReturnNode(struct TreeNode* middle){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->string = NULL;

  temp->op = 20;
  temp->type = NULL;
  temp->varname = NULL;

  temp->left = NULL;
  temp->middle = middle;
  temp->right = NULL;

  return_typeSatisfied(temp);

 
  return temp;
}

// ------------------------------------------------------------------------------------------------------------------ ADD FIELD TO END ( TT & CT )

struct TreeNode* addFieldToEnd(struct TreeNode* head,char* fieldName){

  // CANNOT ADD FIELDS TO OBJECT BECAUSE ENCAPSULATION
 /* 
  if( head->Ctype != NULL ){
    printf("Object | %s | cannot access members | %s | outside class.\n",head->varname,fieldName);
    exit(1);
  }
  */


  struct TreeNode* cur = head;

  while(cur->middle!=NULL){
    cur = cur->middle;
  }

  // check if addMemberToEnd or addFieldToEnd
  if( cur->Ctype ){
    return addMemberToEnd(head,fieldName);
  }


  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->string = NULL;
  temp->op = -1;
  temp->varname = NULL;


  temp->fieldName = (char*)malloc(sizeof(char)*100);
  strcpy(temp->fieldName,fieldName);


  // GET CURRENT'S FIELD LIST
  struct fieldlist* cur_fieldlist = cur->type->fieldlist;
  // CHECK IF FIELDNAME IS IN THE FIELDLIST OF CURRENT
  struct fieldlist* tempfield_in_cur = lookFLUp(cur_fieldlist,fieldName);
  // IF NOT,
  if( !tempfield_in_cur ){
    printf("Field | %s | not present in the fieldlist of type | %s |\n",fieldName,cur->type->name);
    exit(1);
  }
  // EXTEND THE TREE
  cur->middle = temp;
  temp->type = tempfield_in_cur->type;

  return head;

}

// ---------------------------------------------------------------------------------------------------------------------- ADD MEMBER TO END

struct TreeNode* addMemberToEnd(struct TreeNode* head,char* memberName){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->string = NULL;
  temp->op = -1;
  temp->varname = NULL;

  temp->fieldName = (char*)malloc(sizeof(char)*100);
  strcpy(temp->fieldName,memberName);

  // GO DOWN
  struct TreeNode* cur = head;
  while(cur->middle!=NULL){
    cur = cur->middle;
  }

  // CHECK CUR's CTYPE
  struct classtable* Ctype = cur->Ctype;
  // CHECK MEMBERLIST AND FIND memberName
  struct classmember* memberInList = lookMemberInClassUp(Ctype,memberName);

  if( memberInList == NULL ){
    printf("Member | %s | is not present in class of type | %s |\n",memberName,Ctype->name);
    exit(1);
  }

  cur->middle = temp;
  temp->Ctype = memberInList->Ctype;

  return head;
}

// -------------------------------------------------------------------------------------------------------------------------- ADD METHOD TO END 

struct TreeNode* addMethodToEnd(struct TreeNode* head,char* name,struct TreeNode* argList){

 
  struct TreeNode* cur = head;
  while(cur->middle){
    cur = cur->middle;
  }

  // CHECK IF METHODNAME EXISTS IN THE CLASS
  struct classmethod* cm = lookMethodInClassUp(cur->Ctype,name,init_dummy_param(),argList);

  if(!cm){
    printf("Method | %s | does not exist in class | %s |\n",name,cur->Ctype->name);
    exit(1);
  }

  // ------------- CHECK IF ARGUMENTS AND PARAMETERS TYPE ARE CORRECT ----------------
  struct paramlist* c = cm->param;
  struct TreeNode* a = argList;
  while(c && a){
    if( !same(c->type->name,getName(a) ) ){
      printf("Argument type | %s | does not match with declared type | %s | for function | %s |\n",getName(a),c->type->name,name);
      exit(1);
    }
    c = c->next;
    a = a->next;
  }
  if(c||a){
    printf("Size of Arguments and Parameters of method | %s | does not match\n",name);
    exit(1);
  }
  // ------------------------- CHECKING DONE -------------------------------------------

  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->op = -1;
  temp->type = cm->type;
  temp->string = NULL;
  temp->methodName = (char*)malloc(sizeof(char)*100);
  strcpy(temp->methodName,name);
  temp->argList = argList;

  cur->middle = temp;



  return head;
}

// --------------------------------------------------------------------------------------------------------------------- CREATE NODE FOR FREE

struct TreeNode* createFreeNode(struct TreeNode* id){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->op = 23;

  temp->string = NULL;
  temp->varname = NULL;
  temp->left = NULL;
  temp->right = NULL;
  temp->middle = id;

  free_typeSatisfied(temp);
  return temp;
}

// ------------------------------------------------------------------------------------------------------------------------ CREATE NODE FOR DELETE

struct TreeNode* createDeleteNode(struct TreeNode* id){

  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->op = 24;
  temp->Ctype = lookClassUp(getName(id));
  temp->string = NULL;
  temp->varname = NULL;
  temp->left = NULL;
  temp->right = NULL;
  temp->middle = id;

  delete_typeSatisfied(temp->middle);
  return temp;
}

// --------------------------------------------------------------------------------------------------------- CREATING A NULL NODE FOR TYPE NULL

struct TreeNode* createNullNode(){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->op = -1;

  temp->type = lookTTUp("null");

  temp->string = NULL;
  temp->varname = (char*)malloc(sizeof(char)*100);
  strcpy(temp->varname,"null");

  temp->left = NULL;
  temp->middle = NULL;
  temp->right = NULL;

  return temp;
}


// ----------------------------------------------------------------------------------------------------------------- CREATING A NODE FOR SELF

struct TreeNode* createSelfNode(struct classtable* c,char* name,struct TreeNode* argList){

  // ------- CHECK IF SELF WAS DEFINED OUTSIDE CLASS DEFINITIONS

  if( c == NULL ){
    printf("Self cannot be declared outside classmethod definitions\n");
    exit(1);
  }

  // -------- CREATING THE SELF NODE
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->op = -1;

  temp->type = NULL;
  temp->Ctype = c;

  temp->string = NULL;
  temp->varname = (char*)malloc(sizeof(char)*100);
  strcpy(temp->varname,"self");

  temp->left = NULL;
  temp->right = NULL;

  // -------- CREATING CHILD OF SELF NODE
  struct TreeNode* middle = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  middle->val = -1;
  middle->op = -1;

  struct classmember* member = lookMemberInClassUp(c,name);
  struct classmethod* method = lookMethodInClassUp(c,name,NULL,argList);

  // if name does not exist in class
  if( member == NULL && method == NULL ){
    printf("No Member/Method named | %s | in class | %s | exists.\n",name,c->name);
    exit(1);
  }

  if( method != NULL ){
    middle->methodName = (char*)malloc(sizeof(char)*100);
    strcpy(middle->methodName,name);
    middle->argList = argList;
    middle->type = method->type;
  }

  else if( member != NULL ){
    middle->fieldName = (char*)malloc(sizeof(char)*100);
    strcpy(middle->fieldName,name);
    middle->type = member->type;
    middle->Ctype = member->Ctype;
  }

  temp->middle = middle;



  return temp;
}



// ------------------------------------------------------------------------------------------------------------------------ CREATE NEW NODE

struct TreeNode* createNewNode(char* id){

  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->op = 25;
  temp->string = NULL;
  temp->Ctype = lookClassUp(id);

  struct TreeNode* cur = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  cur->val = -1;
  cur->op = -1;
  cur->string = NULL;
  cur->varname = (char*)malloc(sizeof(char)*100);
  cur->Ctype = lookClassUp(id);
  strcpy(cur->varname,id);


  temp->middle = cur;

  

  return temp;
}



// ----------------------------------------------------------------------------------------------------------------------- INORDER TRAVERSAL

void Inorder(struct TreeNode* root){
  if(root == NULL){
    return;
  }
  Inorder(root->left);
  // IT IS A NUMBER
  if(root->val != -1 ){
    printf("-- %d --",root->val);
  }
  // IT IS A STRING
  if(root->string != NULL ){
    printf("-- %s --",root->string);
  }
  // IT IS AN OPERATOR
  else if(root->op != -1 ){
    printf("-- %s --",map(root->op));
  }
  // IT IS A VARIABLE
  else if( root->varname != NULL ){
    printf("-- %s --",root->varname);
    if(root->argList){
      printExprList(root->argList);
    }
  }
  // IT IS A FIELD MEMBER
  else if( root->fieldName != NULL ){
    printf("-- .%s --",root->fieldName);
  }
  else if(root->methodName != NULL ){
    printf("-- .%s --",root->methodName);
    printExprList(root->argList);
  }
  printf(" TYPE : [%s]\n",root->type?root->type->name:(root->Ctype?root->Ctype->name:"NULL"));
  Inorder(root->middle);
  Inorder(root->right);
}

void printExprList(struct TreeNode* head){
  struct TreeNode* cur = head;
  printf(" [");
  while(cur){
    Inorder(cur);
    cur = cur->next;
  }
  printf(" ]");

}
