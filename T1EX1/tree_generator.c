#include <stdio.h>
#include <stdlib.h>
#include "tree_generator.h"

// IMPLEMENTATION OF TREE_GENERATOR.C

struct TreeNode* makeLeafNode(int val){
  
  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = val;
  temp->op = NULL;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

struct TreeNode* makeOperatorNode(char op,struct TreeNode* l,struct TreeNode* r){

  struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  temp->val = -1;
  temp->op = (char*)malloc(sizeof(char));
  *(temp->op) = op;
  temp->left = l;
  temp->right = r;

  return temp;

}

void Preorder(struct TreeNode* root){
  if(root == NULL){
    return;
  }
  if(root->val!=-1){
    printf("%d ",root->val);
  }
  if(root->op!=NULL){
    printf("%c ",*(root->op));
  }
  Preorder(root->left);
  Preorder(root->right);


}

void Inorder(struct TreeNode* root){
  if(root == NULL){
    return;
  }
  Inorder(root->left);
  if(root->val!=-1){
    printf("%d ",root->val);
  }
  if(root->op!=NULL){
    printf("%c ",*(root->op));
  }
  Inorder(root->right);

}

void Postorder(struct TreeNode* root){
  if(root == NULL){
    return;
  }
  Postorder(root->left);
  Postorder(root->right);
  if(root->val!=-1){
    printf("%d ",root->val);
  }
  if(root->op!=NULL){
    printf("%c ",*(root->op));
  }

}



