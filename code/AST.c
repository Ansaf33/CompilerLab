
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "AST.h"
#include "operators/optrans.h"
#include "symbol_table/Gsymbol.h"
#include "symbol_table/Lsymbol.h"
#include "typetable/typetable.h"



// ------------- CHECK IF TYPE IS SAME

char* getName(struct TreeNode* root){
  struct TreeNode* cur = root;
  while(cur->middle != NULL ){
    cur = cur->middle;
  }
  return cur == NULL ? "NULL" : cur->type->name;
 }


// CONDITION FOR ARITHMETIC OPERATORS
bool arithmetic_typeSatisfied(struct TreeNode* root){
  // if nothing passed in
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  // true condition, both should be integers
  if( same( getName(root->left) , "int" ) && same( getName(root->right) , "int" ) ){
    return true;
  }
  // false condition, both not integers
  printf("Arithmetic type | %s | not satisfied", map(root->op) );
  printf("[L R] = [%s %s]\n",root->left->type->name,root->right->type->name);
  exit(1);

}

// CONDITION FOR ASSIGNMENT STATEMENTS
bool assignment_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  // if allocating, can only allocate for user defined datatype
  if( root->right->op == 22 && ( same(getName(root->left),"str") || same(getName(root->left),"int")  ) ){
    printf("Cannot dynamically allocate space for primitive datatype | %s |\n",getName(root->left));
    exit(1);
  }
  // true condition, both should be of the same type
  bool nullCondition = same(getName(root->right),"null");
  bool bothsameCondition = same(getName(root->left),getName(root->right));
  bool notBoolCondition = !same(getName(root->left),"bool") && !same(getName(root->right),"bool");

  if ( nullCondition || bothsameCondition && notBoolCondition ){
    return true;
  }
  printf("Assignment type | %s | not satisfied", map(root->op) );
  printf("[L R] = [%s %s]\n",root->left->type->name,root->right->type->name);
  exit(1);


}

// CONDITION FOR LOGICAL OPERATORS
bool logical_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  bool isNullCondition = same(getName(root->right),"null");
  bool bothIntCondition = same(getName(root->left),"int") && same(getName(root->right),"int");

  if( isNullCondition || bothIntCondition ){
    return true;
  }
  printf("Logical type | %s | not satisfied", map(root->op) );
  printf("[L R] = [%s %s]\n",root->left->type->name,root->right->type->name);
  exit(1);
}

// CONDITION FOR READ STATEMENT
bool read_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  bool intorstringCondition = same(getName(root->left),"int") || same(getName(root->left),"str");
  if( intorstringCondition ){
    return true;
  }
  printf("Read type is | %s |\n",getName(root->left));
  exit(1);
}

// CONDITION FOR WRITE STATEMENT
bool write_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  bool intorstringCondition = same(getName(root->left),"int") || same(getName(root->left),"str");
  if( intorstringCondition ){
    return true;
  }
  printf("Write type is | %s |\n",getName(root->left));
  exit(1);
}


// CONDITION FOR IF STATEMENT
bool if_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  bool boolCondition = same(getName(root->middle),"bool");
  if( boolCondition ){
    return true;
  }
  printf("IF type is | %s |\n",getName(root->middle));
  exit(1);
}

// CONDITION FOR WHILE, DOWHILE AND REPEAT STATEMENT
bool while_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  bool boolCondition = same(getName(root->left),"bool");
  if( boolCondition ){
    return true;
  }
  printf("WHILE/DOWHILE/REPEAT type is | %s |\n",getName(root->left));
  exit(1);
}

// CONDITION FOR RETURN STATEMENT
bool return_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  bool notboolCondition = !same(getName(root->middle),"bool");
  if( notboolCondition ){
    return true;
  }
  printf("RETURN type is | %s |\n",getName(root->middle));
  exit(1);
}

// CONDITION FOR FREE STATEMENT
bool free_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  // can only free user defined datatype
  bool udtCondition = !same(getName(root->middle),"int") && !same(getName(root->middle),"str");
  if( udtCondition ){
    return true;
  }
  printf("FREE type is | %s |\n",getName(root->middle));
  exit(1);
}


// -------------- CREATE NODE FOR NUMBERS

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

// -------------- CREATE NODE FOR OPERATORS


struct TreeNode* createOpNode(struct typetable* type,int op,struct TreeNode* left,struct TreeNode* right){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->string = NULL;
  temp->op = op;
  temp->type = type;
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

// --------------- CREATE NODE FOR STRINGS


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



// -------------- CREATE NODE FOR IDs

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
  // ------------------------- DECIDING DONE ----------------------------------------
 
  temp->val = -1;
  temp->string = NULL;

  temp->op = -1;
  temp->type = temp->Lsymbol?temp->Lsymbol->type:temp->Gsymbol->type;
  temp->varname = (char*)malloc(sizeof(char)*100);
  strcpy(temp->varname,varname);

  temp->row = row;
  temp->column = column;

  temp->left = NULL;
  temp->right = NULL;
  temp->middle = NULL;


  return temp;

}



// -------------- CREATE NODE FOR IF STATEMENTS

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

// ---------------- CREATE NODE FOR WHILE STATEMENTS

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

//--------------- CREATE NODE FOR FUNCTIONS

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

    if( !arg && param || !param && arg ){
      printf("Argument size does not match parameter size.\n");
      exit(1);
    }
  // ------------------------------------------------ CHECKING DONE --------------------------------------------
  
  return temp;
}

// -------------- CREATE LIST OF ARGUMENTS

struct TreeNode* addArgToList(struct TreeNode* listHead,struct TreeNode* argHead){


  // ADDING ARGHEAD TO END OF LINKED LIST
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



// ----------------- CREATE RETURN NODE 

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

// ------------------- ADD CHILD TO ROOT'S MIDDLE

struct TreeNode* addFieldToEnd(struct TreeNode* head,char* fieldName){

  struct TreeNode* cur = head;

  while(cur->middle!=NULL){
    cur = cur->middle;
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

// ----------------------------- CREATE NODE FOR FREE

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

// ------------------- CREATING A NULL NODE FOR TYPE NULL

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









// ------------------- INORDER TRAVERSAL

void Inorder(struct TreeNode* root){
  if(root == NULL){
    return;
  }
  Inorder(root->left);
  // IT IS A NUMBER
  if(root->val != -1 ){
    printf(" ( %d )",root->val);
  }
  // IT IS A STRING
  if(root->string != NULL ){
    printf(" ( %s )",root->string);
  }
  // IT IS AN OPERATOR
  else if(root->op != -1 ){
    printf(" ( %s )",map(root->op));
  }
  // IT IS A VARIABLE
  else if( root->varname != NULL ){
    printf(" ( %s )",root->varname);
    if(root->argList){
      printExprList(root->argList);
    }
  }
  // IT IS A FIELD MEMBER
  else if( root->fieldName != NULL ){
    printf(" (.%s)",root->fieldName);
  }
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
