#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
  int val;
  char op;
  int vartype;
  char varname;
  struct TreeNode* left;
  struct TreeNode* right;

};

struct TreeNode* createTree(int val,char op,int vartype,char* varname,struct TreeNode* left, struct TreeNode* right);

void Inorder(struct TreeNode* root);

#endif


