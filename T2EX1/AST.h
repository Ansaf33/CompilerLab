#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode{
  int val;
  int op;
  int type;
  char varname;
  struct TreeNode* left;
  struct TreeNode* middle;
  struct TreeNode* right;

};

bool typeSatisfied(struct TreeNode* root);

struct TreeNode* createTree(int val,int op,int type,char* varname,struct TreeNode* left, struct TreeNode* right);

struct TreeNode* createIfTree(int op,struct TreeNode* middle, struct TreeNode* left,struct TreeNode* right);

struct TreeNode* createWhileTree(int op,struct TreeNode* left, struct TreeNode* right);

void Inorder(struct TreeNode* root);

#endif


