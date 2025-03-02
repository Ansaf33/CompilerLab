#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "symbol_table/Gsymbol.h"
#include "symbol_table/Lsymbol.h"

struct TreeNode{

  int val;
  char* string;

  int op;
  int type;
  char* varname;

  // USED FOR VARIABLES/ARRAYS
  struct TreeNode* row;
  struct TreeNode* column;


  // USED FOR EXPRESSIONS / STATEMENTS
  struct TreeNode* left;
  struct TreeNode* middle;
  struct TreeNode* right;

  // FOR STORING ARGUMENTS OF A FUNCTION IN A LIST
  struct TreeNode* argList;
  struct TreeNode* next;

  // POINTER TO GLOBAL SYMBOL TABLE ENTRY AND/OR LOCAL SYMBOL TABLE ENTRY
  struct Gsymbol* Gsymbol;
  struct Lsymbol* Lsymbol;
};



bool typeSatisfied(struct TreeNode* root);

struct TreeNode* createNumNode(int val);

struct TreeNode* createOpNode(int type,int op,struct TreeNode* left,struct TreeNode* right);

struct TreeNode* createStringNode(char* string);

struct TreeNode* createIdNode(char* varname,struct TreeNode* row,struct TreeNode* column);

struct TreeNode* createIfNode(struct TreeNode* middle, struct TreeNode* left,struct TreeNode* right);

struct TreeNode* createWhileNode(int op,struct TreeNode* left, struct TreeNode* right);

struct TreeNode* createFunctionNode(char* varname,struct TreeNode* argListHead);

struct TreeNode* addArgToList(struct TreeNode* listHead,struct TreeNode* argHead);

void Inorder(struct TreeNode* root);

void printExprList(struct TreeNode* head);

#endif


