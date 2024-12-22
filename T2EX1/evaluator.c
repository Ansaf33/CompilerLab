#include <stdio.h>
#include <stdlib.h>
#include "evaluator.h"

static int variables[26];

void evaluate(struct TreeNode* root){
  if(root == NULL){
    return;
  }
  evaluate(root->left);
  switch(root->op){
    case 'R':
      char var = root->left->varname;
      printf("Enter value of %c : ",var);
      scanf("%d",&variables[(int)var-97]);
      break;
    case '=':
      var = root->left->varname;
      int value = expressionEvaluator(root->right);
      variables[(int)var-97] = value;
      break;
    case 'W':
      value = expressionEvaluator(root->left);
      printf("Output of write : %d\n",value);
      break;
  }
  evaluate(root->right);

}

int expressionEvaluator(struct TreeNode* root){

  if( root->left == NULL && root->right == NULL ){
    // IF IT IS A VARIABLE
    if( root->val == -1 ){
      return variables[(int)root->varname - 97];
    }
    else{
      return root->val;
    }
  }

  switch(root->op){
    case '+':
      return expressionEvaluator(root->left) + expressionEvaluator(root->right);
      break;

    case '-':
      return expressionEvaluator(root->left) - expressionEvaluator(root->right);
      break;

    case '*':
      return expressionEvaluator(root->left) * expressionEvaluator(root->right);
      break;

    case '/':
      return expressionEvaluator(root->left) / expressionEvaluator(root->right);
      break;

  }


  


}


int getDetails(){
  for(int i=0;i<26;i++){
    printf("%c = %d\n",i+97,variables[i]);
  }
  return 0;
    

}

