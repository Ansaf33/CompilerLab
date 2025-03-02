#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "typesatisfy.h"
#include "../AST.h"
#include "../operators/optrans.h"


// ------------------------------------------------------------------------------------------------------------------ GET TYPENAME
char* getName(struct TreeNode* root){
  struct TreeNode* cur = root;
  while(cur->middle != NULL ){
    cur = cur->middle;
  }
  return cur == NULL ? "NULL" : ( cur->type == NULL ? cur->Ctype->name : cur->type->name );
 }


// ------------------------------------------------------------------------------------------------------------------ CONDITION FOR ARITHMETIC OPERATORS
bool arithmetic_typeSatisfied(struct TreeNode* root){

  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  // true condition, both should be integers
  if( same( getName(root->left) , "int" ) && same( getName(root->right) , "int" ) ){
    return true;
  }
  printf("Arithmetic type | %s | not satisfied", map(root->op) );
  printf("[L R] = [%s %s]\n",root->left->type->name,root->right->type->name);
  exit(1);


}

// ------------------------------------------------------------------------------------------------------------------ CONDITION FOR ASSIGNMENT STATEMENTS
bool assignment_typeSatisfied(struct TreeNode* root){

  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }

  // CONDITION FOR ALLOC STATEMENT

  if( root->right->op == 22 && ( same(getName(root->left),"str") || same(getName(root->left),"int")  ) ){
    printf("Cannot dynamically allocate space for primitive datatype | %s |\n",getName(root->left));
    exit(1);
  }

  // CONDITION FOR NEW STATEMENT

  if( root->right->op == 25 && lookClassUp(getName(root->left)) != root->right->Ctype ){
    printf("NEW assignment does not match types\n");
    exit(1); 
  }

  // true condition, both should be of the same type ( right can be null )
  bool nullCondition = same(getName(root->right),"null");
  bool bothsameCondition = same(getName(root->left),getName(root->right));
  bool notBoolCondition = !same(getName(root->left),"bool") && !same(getName(root->right),"bool");


  if ( nullCondition || bothsameCondition && notBoolCondition ){
    return true;

  }

  printf("Assignment type | %s | not satisfied\n", map(root->op) );
  printf("[L R] = [%s %s]\n",getName(root->left),getName(root->right));
  printf("here\n");
  exit(1);

}

// ------------------------------------------------------------------------------------------------------------------ CONDITION FOR LOGICAL OPERATORS

bool logical_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  // either rhs is null, or both are integers
  bool isNullCondition = same(getName(root->right),"null");
  bool bothIntCondition = same(getName(root->left),"int") && same(getName(root->right),"int");

  if( isNullCondition || bothIntCondition ){
    return true;
  }

  printf("Logical type | %s | not satisfied", map(root->op) );
  printf("[L R] = [%s %s]\n",getName(root->left),getName(root->right));
  exit(1);
}

// ------------------------------------------------------------------------------------------------------------------ CONDITION FOR READ STATEMENT
bool read_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  // left is either int or str
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
  // left is either int or str
  bool intorstringCondition = same(getName(root->left),"int") || same(getName(root->left),"str");
  if( intorstringCondition ){
    return true;
  }
  printf("Write type is | %s |\n",getName(root->left));
  exit(1);
}

// ------------------------------------------------------------------------------------------------------------------ CONDITION FOR IF STATEMENT
bool if_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  // middle must be bool
  bool boolCondition = same(getName(root->middle),"bool");
  if( boolCondition ){
    return true;
  }
  printf("IF type is | %s |\n",getName(root->middle));
  exit(1);
}

// ----------------------------------------------------------------------------------------------------CONDITION FOR WHILE, DOWHILE AND REPEAT STATEMENT
bool while_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  // middle must be bool
  bool boolCondition = same(getName(root->left),"bool");
  if( boolCondition ){
    return true;
  }
  printf("WHILE/DOWHILE/REPEAT type is | %s |\n",getName(root->left));
  exit(1);
}

// ------------------------------------------------------------------------------------------------------------------ CONDITION FOR RETURN STATEMENT
bool return_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  // middle must not be bool
  bool notboolCondition = !same(getName(root->middle),"bool");
  if( notboolCondition ){
    return true;
  }
  printf("RETURN type is | %s |\n",getName(root->middle));
  exit(1);
}

// ------------------------------------------------------------------------------------------------------------------ CONDITION FOR FREE STATEMENT
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

// ------------------------------------------------------------------------------------------------------------------ CONDITION FOR DELETE STATEMENT
bool delete_typeSatisfied(struct TreeNode* root){
  if( root == NULL ){
    printf("Nothing passed\n");
    exit(1);
  }
  
  struct classtable* Ctype = lookClassUp(getName(root));

  if( Ctype == NULL ){
    printf("Cannot find type for Field inside delete\n");
    exit(1);
  }

  return true;
  
}



