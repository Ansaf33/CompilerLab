#include "reghandling.h"
#include <stdio.h>
#include <stdlib.h>

#define NOR 20

// INITIALLY, NO REGISTERS ARE USED
static int highestUsedReg = -1;


// IMPLEMENTATION OF FUNCTIONS



// GET REG FUNCTION

int getReg(void){
  // FIRST CHECK IF ANY REGISTER IS FREE
  if( highestUsedReg == NOR - 1 ){
      printf("Cannot allocate more registers.");
      exit(1);
  }
  return ++highestUsedReg;



}

// FREE REG FUNCTION

void freeReg(){
  // CHECK IF ALL REGISTERS ARE FREE
  if( highestUsedReg >= 0 ){
    --highestUsedReg;
  }
  // IF ALL REGISTERS ARE ALREADY FREE
  else{
    printf("All registers already free.");
  }

}


// CODE GENERATION

// PARAMETERS :
// FILE* F = FILE.XSM where assembly code is to be written. (First 8 lines are header)
// STRUCT TREENODE* T = ROOT OF THE TREE

int codeGen(FILE* f,struct TreeNode* root){
  if(root->left == NULL && root->right == NULL){
    int regIdx = getReg();
    fprintf(f,"MOV R%d, %d\n",regIdx,root->val);

    return regIdx;
  }

  int lReg = codeGen(f,root->left);
  int rReg = codeGen(f,root->right);

  switch(*(root->op)){
      case '+':
        fprintf(f,"ADD R%d, R%d\n",lReg,rReg);
        break;
      case '-':
        fprintf(f,"SUB R%d, R%d\n",lReg,rReg);
        break;
      case '*':
        fprintf(f,"MUL R%d, R%d\n",lReg,rReg);
        break;
      case '/':
        fprintf(f,"DIV R%d, R%d\n",lReg,rReg);
        break;
  }

  freeReg();

  return lReg;



}


