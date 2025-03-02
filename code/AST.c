
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


bool typeSatisfied(struct TreeNode* root){

   
    // if arithmetic operator, left and right should be integers
    if(root->op >=0 && root->op <= 3){
      return same(root->left->type->name,"int") && same(root->right->type->name,"int");
    }

    // if assigns, left should be an identifier (integer/string/user_defined) and right should be an expression (integer/string/user_defined)
    else if( root->op == 4 ){

    // can only allocate space dynamically for user defined types
    /*
    if(root->right->op == 22){
      if( same(root->left->type->name,"str") || same(root->left->type->name,"int") ){
        printf("Cannot Dynamically Allocate Space for Primitive data types\n");
        exit(1);
      }
    }
    */

    return same(root->left->type->name,root->right->type->name) && !same(root->left->type->name,"bool") && !same(root->right->type->name,"bool");
    }

    // if logical operators, left and right type should be integers
    else if( root->op >= 5 && root->op <= 10 ){
          return same(root->left->type->name,"int") && same(root->right->type->name,"int");
   }

    // if READ statement, left type should be integer/string
    else if( root->op == 11 ){
        return same(root->left->type->name,"int") || same(root->left->type->name,"str");
   }

   // if WRITE statement, left type should be integer/string
    else if( root->op == 12 ){
        return same(root->left->type->name,"int") || same(root->left->type->name,"str");
   }

    // if IF statement, condition type should be boolean
    else if( root->op == 14 ){
        return same(root->middle->type->name,"bool");
    }

    // if WHILE statement, condition type should be boolean
    else if( root->op == 15 ){
        return same(root->left->type->name,"bool");
    }

    // if REPEAT statement, condition type should be boolean
    else if( root->op == 18 ){
        return same(root->left->type->name,"bool");
    }

    // if DOWHILE statement, condition type should be boolean
    else if( root->op == 19 ){
        return same(root->left->type->name,"bool");
    }

    // if RETURN statement, expression must evaluate to anything but bool
    else if( root->op == 20 ){
        return !same(root->middle->type->name,"bool");
  }

   return true;

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

  if( left ){ 
    if(!typeSatisfied(temp)){
      printf("Operator | %s | Condition : Type not matching.\n",map(temp->op));
      printf("Left type : %s\n",temp->left?temp->left->type->name:"NULL");
      printf("Right type : %s\n",temp->right?temp->right->type->name:"NULL");
      exit(1);
    }
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

  if( middle ){ 
    if(!typeSatisfied(temp)){
      printf("If Condition : Type not matching.\n");
      exit(1);
    }

        
  }

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

  // CHECK IF SATISFIABLE

  if( left && !typeSatisfied(temp)){
    printf("While Condition : Type not matching.\n");
    exit(1);
  }

  

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

  if( !typeSatisfied(temp) ){
    printf("Return : Type not matching\n");
    exit(1);
  }


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
  head->type = temp->type;



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
