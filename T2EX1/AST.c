
#include <stdio.h>
#include <stdlib.h>
#include "AST.h"


/*

for ID = (-1,'n',0,yytext,NULL,NULL)
for NUM = (num,'n',-1,NULL,NULL,NULL)
for OPS = (-1,'=',-1,NULL,$1,$3)


*/

struct TreeNode* createTree(int val,char op,int vartype,char* varname,struct TreeNode* left,struct TreeNode* right){

  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));

  // IF IT IS A NUMBER, OTHERWISE PASS AS -1
  temp->val = val;
  // IF IT IS AN OPERATOR, OTHERWISE PASS AS 'n'
  temp->op = op;
  // IF IT IS A VARIABLE, OTHERWISE PASS AS -1
  temp->vartype = vartype;
  // DEPENDING ON VARTYPE
  temp->varname = (temp->vartype==-1)?'n':*(varname);
   // LEFT AND RIGHT SUBTREES
  temp->left = left;
  temp->right = right;

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
  else if(root->op != 'n' ){
    printf("(%c) ",root->op);
  }
  else if(root->varname != 'n' ){
    printf("(%c) ",root->varname);
  } 
  Inorder(root->right);
}
