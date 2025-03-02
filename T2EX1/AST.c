
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AST.h"
#include "operators/optrans.h"



// ------------- CHECK IF TYPE IS SAME

bool typeSatisfied(struct TreeNode* root){
    
    // if arithmetic operator, left and right should be integers
    if(root->op >=0 && root->op <= 3){
      return root->left->type == 0 && root->right->type == 0;
    }
    // if assigns, left should be an identifier (integer) and right should be integer
    else if( root->op == 4 ){
      return root->left->type == 0 && root->right->type == 0;
    }
    // if logical operators, left and right type should be the type for expressions (integer)
    else if( root->op >= 5 && root->op <= 10 ){
          return root->left->type == 0 && root->right->type == 0;
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

// ------------- CREATE NODE FOR CONSTANTS, EXPRESSIONS, STATEMENTS

struct TreeNode* createTree(int val,int op,int type,char* varname,struct TreeNode* left,struct TreeNode* right){



  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));

  // IF IT IS A NUMBER, OTHERWISE PASS AS -1
  temp->val = val;
  // IF IT IS AN OPERATOR, OTHERWISE PASS AS -1
  temp->op = op;
  // TYPE OF NODE. IF IT IS A CONSTANT, IT IS AN INTEGER. IF IT IS AN ID, IT IS AN INTEGER.
  temp->type = type;

  temp->varname = *(varname);

   // LEFT AND RIGHT SUBTREES
  temp->left = left;
  temp->right = right;

  // no need for third child in while statements
  temp->middle = NULL;

  // CHECK IF ROOT SATISFIES ITS LEFT AND RIGHT CHILDREN
  if( left && right ){ 
    if(!typeSatisfied(temp)){
      printf("Operation '%s' : Type not matching.\n",map(temp->op));
      exit(1);
    }
        
  }

  return temp;

}

// -------------- CREATE NODE FOR IF STATEMENTS

struct TreeNode* createIfTree(int op,struct TreeNode* middle,struct TreeNode* left,struct TreeNode* right){

  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->op = op;
  temp->type = -1;
  temp->varname = '\0';
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

struct TreeNode* createWhileTree(int op,struct TreeNode* left,struct TreeNode* right){
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));  
  temp->val = -1;
  temp->op = op;
  temp->type = -1;
  temp->varname = '\0';
  temp->left = left;
  temp->right = right;
  // no need for third child in while statements
  temp->middle = NULL;

  // CHECK IF SATISFIABLE

  if( left && right ){ 
    if(!typeSatisfied(temp)){
      printf("While Condition : Type not matching.\n");
      exit(1);
    }
        
  }
  

  return temp;


}


void Inorder(struct TreeNode* root){
  if(root == NULL){
    return;
  }
  Inorder(root->left);
  if(root->val != -1 ){
    printf("(%d) ",root->val);
  }
  else if(root->op != -1 ){
    printf("(%s) ",map(root->op));
  }
  else if(root->varname != 'n' ){
    printf("(%c) ",root->varname);
  } 

  Inorder(root->middle);
  Inorder(root->right);
}
