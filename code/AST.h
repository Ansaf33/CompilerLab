#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "symbol_table/Gsymbol.h"
#include "symbol_table/Lsymbol.h"
#include "typetable/typetable.h"

struct TreeNode{

  int val;
  char* string;

  int op;

  struct typetable* type;
  struct classtable* Ctype;

  char* varname;
  
  // FOR USER DEFINED FUNCTIONS
  char* fieldName;

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

  // FOR CLASSES
  char* methodName;
};

char* getName(struct TreeNode* root);

bool arithmetic_typeSatisfied(struct TreeNode* root);

bool assignment_typeSatisfied(struct TreeNode* root);

bool logical_typeSatisfied(struct TreeNode* root);

bool read_typeSatisfied(struct TreeNode* root);

bool write_typeSatisfied(struct TreeNode* root);

bool if_typeSatisfied(struct TreeNode* root);

bool while_typeSatisfied(struct TreeNode* root);

bool return_typeSatisfied(struct TreeNode* root);

bool free_typeSatisfied(struct TreeNode* root);


struct TreeNode* createNumNode(int val);

struct TreeNode* createOpNode(struct typetable* type,int op,struct TreeNode* left,struct TreeNode* right);

struct TreeNode* createStringNode(char* string);

struct TreeNode* createIdNode(char* varname,struct TreeNode* row,struct TreeNode* column);

struct TreeNode* createIfNode(struct TreeNode* middle, struct TreeNode* left,struct TreeNode* right);

struct TreeNode* createWhileNode(int op,struct TreeNode* left, struct TreeNode* right);

struct TreeNode* createFunctionNode(char* varname,struct TreeNode* argListHead);

struct TreeNode* createReturnNode(struct TreeNode* middle);

struct TreeNode* addFieldToEnd(struct TreeNode* head,char* fieldName);

struct TreeNode* addMethodToEnd(struct TreeNode* head,char* name,struct TreeNode* argList);

struct TreeNode* addArgToList(struct TreeNode* listHead,struct TreeNode* argHead);

struct TreeNode* createFreeNode(struct TreeNode* id);

struct TreeNode* createDeleteNode(struct TreeNode* id);

struct TreeNode* createNullNode(void);

struct TreeNode* createSelfNode(struct classtable* c,char* memberName,struct TreeNode* argList);

struct TreeNode* createNewNode(char* id);

void Inorder(struct TreeNode* root);

void printExprList(struct TreeNode* head);

#endif


