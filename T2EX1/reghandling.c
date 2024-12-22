#include "reghandling.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AST.h"

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

// PRINTING SOMETHING IN CONSOLE 

void getInput(FILE* f,char* s){

  int r = getReg();
  fprintf(f,"MOV R%d, \"%s\"\n",r,s);

  fprintf(f,"MOV SP, %d\n",4500);

  // pushing "write"
  int r1 = getReg();
  fprintf(f,"MOV R%d, \"write\"\n",r1);
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // pushing -1 -> argument 1
  r1 = getReg();
  fprintf(f,"MOV R%d, -2\n",r1);
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // pushing data -> argument 2
  r1 = getReg();
  fprintf(f,"PUSH R%d\n",r);
  freeReg();

  // pushing empty register -> argument 3
  r1 = getReg();
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // pushing register for return value
  r1 = getReg();
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // CALL
  fprintf(f,"CALL 0\n");

  // POPPING REGISTERS
  int retReg = getReg();
  fprintf(f,"POP R%d\n",retReg);
  r1 = getReg();
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  freeReg();

}


// CODE GENERATION FOR EXPRESSIONS

int expression_codeGen(FILE* f,struct TreeNode* root){
  if(root->left == NULL && root->right == NULL){
    int regIdx = getReg();
    // IF CONSTANT, USE ROOT->VAL
    if(root->val != -1 ){
      fprintf(f,"MOV R%d, %d\n",regIdx,root->val);
    }
    else{
      int memlocation = 4095 + ( (int)root->varname -96 );
      fprintf(f, "MOV R%d, [%d]\n",regIdx,memlocation);
    }

    return regIdx;
  }

  int lReg = expression_codeGen(f,root->left);
  int rReg = expression_codeGen(f,root->right);

  switch(root->op){
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

// CODE GENERATION FOR ASSIGNMENTS

void assignment_codeGen(FILE* f,struct TreeNode* root){
  int fReg = expression_codeGen(f,root->right);
  // NOW GET THE CHARACTER VALUE
  int variable = (int)root->left->varname - 96;
  int storeIn = 4095 + variable;

  // store the register contents in the memory location 'storeIn'
  int r1 = getReg();
  fprintf(f,"MOV R%d, %d\n",r1,storeIn);
  fprintf(f,"MOV [R%d], R%d\n",r1, fReg);
  

}

// CODE GENERATION FOR READ OPERATIONS

void read_codeGen(FILE* f,struct TreeNode* root){

  int variable = (int)root->left->varname - 96;
  int storeIn = 4095 + variable;

  char s[50];
  snprintf(s,sizeof(s),"Enter %c : ", root->left->varname);
  getInput(f,s);

  // STACK POINTER
  fprintf(f,"MOV SP, %d\n",4500);
  

  // pushing "read"
  int r1 = getReg();
  fprintf(f,"MOV R%d, \"read\"\n",r1);
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // pushing -1 -> argument 1
  r1 = getReg();
  fprintf(f,"MOV R%d, -1\n",r1);
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // pushing buffer -> argument 2
  r1 = getReg();
  fprintf(f,"MOV R%d, %d\n",r1,storeIn);
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // pushing empty register -> argument 3
  r1 = getReg();
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // pushing register for return value
  r1 = getReg();
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // CALL
  fprintf(f,"CALL 0\n");

  // POPPING REGISTERS
  int retReg = getReg();
  fprintf(f,"POP R%d\n",retReg);
  r1 = getReg();
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  freeReg();


}

void write_codeGen(FILE* f,struct TreeNode* root){

  // GET THE REGISTER WHERE VALUE IS STORED
  int R = expression_codeGen(f,root->left);


  getInput(f,"Output : ");

  // stack pointer
  fprintf(f,"MOV SP, %d\n",4500);

  // pushing "write"
  int r1 = getReg();
  fprintf(f,"MOV R%d, \"write\"\n",r1);
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // pushing -1 -> argument 1
  r1 = getReg();
  fprintf(f,"MOV R%d, -2\n",r1);
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // pushing R -> argument 2
  r1 = getReg();
  fprintf(f,"PUSH R%d\n",R);
  freeReg();

  // pushing empty register -> argument 3
  r1 = getReg();
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // pushing register for return value
  r1 = getReg();
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // CALL
  fprintf(f,"CALL 0\n");

  // POPPING REGISTERS
  int retReg = getReg();
  fprintf(f,"POP R%d\n",retReg);
  r1 = getReg();
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  freeReg();


}

bool isAssignment(struct TreeNode* root){
    return root->op == '=';
}
bool isRead(struct TreeNode* root){
    return root->op == 'R';
}
bool isWrite(struct TreeNode* root){
    return root->op == 'W';
}
bool isExpression(struct TreeNode* root){
    return root->op == '+' || root->op == '-' || root->op == '*' || root->op == '/';
}


void codeGen(FILE* f,struct TreeNode* root){
    if(root == NULL){
      return;
    }
    codeGen(f,root->left);
    if( isAssignment(root) ){
      assignment_codeGen(f,root);
    }
    else if( isRead(root) ){
      read_codeGen(f,root);
    }
    else if( isWrite(root) ){
      write_codeGen(f,root);
    }
    codeGen(f,root->right);


}

