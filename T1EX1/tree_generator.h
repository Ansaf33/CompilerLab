#ifndef tree_generator_h
#define tree_generator_h

#include <stdio.h>

struct TreeNode{
  int val;
  char* op;
  struct TreeNode* left;
  struct TreeNode* right;
};

// FUNCTION FOR CREATING LEAF NODE (FOR DIGITS)

struct TreeNode* makeLeafNode(int val);

// FUNCTION FOR CREATING OPERATOR NODE (INTERNAL NODE)

struct TreeNode* makeOperatorNode(char op,struct TreeNode* l,struct TreeNode* r);

// PREORDER TRAVERSAL

void Preorder(struct TreeNode* root);

// INORDER TRAVERSAL

void Inorder(struct TreeNode* root);

// POSTORDER TRAVERSAL 

void Postorder(struct TreeNode* root);


#endif
