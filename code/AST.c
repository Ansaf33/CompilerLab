
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "AST.h"
#include "evaluator.h"
#include "operators/optrans.h"
#include "symbol_table/Gsymbol.h"
#include "symbol_table/Lsymbol.h"




// ------------- CHECK IF TYPE IS SAME


bool typeSatisfied(struct TreeNode* root){
    
    // if arithmetic operator, left and right should be integers
    if(root->op >=0 && root->op <= 3){
      return root->left->type == 0 && root->right->type == 0;
    }
    // if assigns, left should be an identifier (integer/string) and right should be an expression (integer/string)
    else if( root->op == 4 ){
       return root->left->type == 0 && root->right->type == 0 || root->left->type == 2 && root->right->type == 2;
    }
    // if logical operators, left and right type should be the type for expressions (integer)
    else if( root->op >= 5 && root->op <= 10 ){
          return root->left->type == 0 && root->right->type == 0;
   }
    // if READ statement, left type should be integer/string
    else if( root->op == 11 ){
        return root->left->type == 0 || root->left->type == 2;
   }
   // if WRITE statement, left type should be integer/string
    else if( root->op == 12 ){
        return root->left->type == 0 || root->left->type == 2;
   }
    // if IF statement, condition type should be boolean
    else if( root->op == 14 ){
        return root->middle->type == 1;
    }
    // if WHILE statement, condition type should be boolean
    else if( root->op == 15 ){
        return root->left->type == 1;
    }
    // if REPEAT statement, condition type should be boolean
    else if( root->op == 18 ){
        return root->left->type == 1;
    }
    // if DOWHILE statement, condition type should be boolean
    else if( root->op == 19 ){
        return root->left->type == 1;
    }

   return true;

}

// -------------- CREATE NODE FOR NUMBERS

struct TreeNode* createNumNode(int val){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = val;
  temp->string = NULL;
  temp->op = -1;
  temp->type = 0;
  temp->varname = NULL;
  temp->left = NULL;
  temp->right = NULL;
  temp->middle = NULL;
 

  return temp;
}

// -------------- CREATE NODE FOR OPERATORS


struct TreeNode* createOpNode(int type,int op,struct TreeNode* left,struct TreeNode* right){
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
  temp->type = 2;
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
  temp->type = -1;
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
  temp->type = -1;
  temp->varname = NULL;
  temp->left = left;
  temp->right = right;
  temp->middle = NULL;

  // CHECK IF SATISFIABLE

  if( left ){ 
    if(!typeSatisfied(temp)){
      printf("While Condition : Type not matching.\n");
      exit(1);
    }
  }
  

  return temp;


}

//--------------- CREATE NODE FOR FUNCTIONS

struct TreeNode* createFunctionNode(char* varname,struct TreeNode* argList){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));


  // ---------------- CHECK IF PRESENT IN GLOBAL TABLE -------------------
  temp->Gsymbol = lookGUp(varname);

  if(temp->Gsymbol == NULL){
    printf("Function %s is not declared.\n",varname);
    exit(1);
  }
  // -------------------- CHECK IF FUNCTION IS DEFINED -------------------
  if( !temp->Gsymbol->defined ){
    printf("Function | %s | is not defined.\n",varname);
    exit(1);
  }

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
      if( arg->type != param->type ){
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
  // ------------ CHECKING DONE ----------------
  

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
  // IT IS A VARIABLE / A FUNCTION
  else if( root->varname != NULL ){
    printf(" ( %s )",root->varname);
    if(root->argList){
      printExprList(root->argList);
    }


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
