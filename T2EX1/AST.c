
#include <stdio.h>
#include <stdlib.h>
#include "AST.h"
#include "operators/optrans.h"


/*

for ID = (-1,-1,0,yytext,NULL,NULL)
for NUM = (num,-1,-1,NULL,NULL,NULL)
for OPS = (-1,'=',-1,NULL,$1,$3)


*/

// ------------- CREATE NODE FOR CONSTANTS, EXPRESSIONS, STATEMENTS

struct TreeNode* createTree(int val,int op,int type,char* varname,struct TreeNode* left,struct TreeNode* right){



  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));

  // IF IT IS A NUMBER, OTHERWISE PASS AS -1
  temp->val = val;
  // IF IT IS AN OPERATOR, OTHERWISE PASS AS -1
  temp->op = op;
  // TYPE OF NODE. IF IT IS A CONSTANT, IT IS AN INTEGER. IF IT IS AN ID, IT IS AN INTEGER.
  temp->type = type;
  // DEPENDING ON VARTYPE
  temp->varname = *(varname);
   // LEFT AND RIGHT SUBTREES
  temp->left = left;
  temp->right = right;
  // no need for third child in while statements
  temp->middle = NULL;

  
  if( left && right ){ 
      if( temp->left->type != temp->right->type ){
          printf("Types do not match.\n");
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
