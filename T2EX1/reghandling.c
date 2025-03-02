#include "reghandling.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AST.h"

#define NOR 20

// INITIALLY, NO REGISTERS ARE USED
static int highestUsedReg = -1;
static int highestUsedLabel = -1;

// --------------------------------------------------------- GET LABEL FUNCTION

int getLabel(void){
  ++highestUsedLabel;
  return highestUsedLabel;
}


// ---------------------------------------------------------- GET REG FUNCTION

int getReg(void){
  // FIRST CHECK IF ANY REGISTER IS FREE
  if( highestUsedReg == NOR - 1 ){
      printf("Cannot allocate more registers.");
      exit(1);
  }
  return ++highestUsedReg;

}

// ----------------------------------------------------------- FREE REG FUNCTION

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

// ----------------------------------------------------------- PRINTING SOMETHING IN CONSOLE 

void getInput(FILE* f,char* s){


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
  fprintf(f,"MOV R%d, \"%s\"\n",r1,s);
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
  r1 = getReg();
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  freeReg();

}


// --------------------------------------------------------- CODE GENERATION FOR ARITHMETIC EXPRESSIONS ( E )

int arithmetic_expression_codeGen(FILE* f,struct TreeNode* root){
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

  int lReg = arithmetic_expression_codeGen(f,root->left);
  int rReg = arithmetic_expression_codeGen(f,root->right);

  switch(root->op){
      case 0:
        fprintf(f,"ADD R%d, R%d\n",lReg,rReg);
        break;
      case 1:
        fprintf(f,"SUB R%d, R%d\n",lReg,rReg);
        break;
      case 2:
        fprintf(f,"MUL R%d, R%d\n",lReg,rReg);
        break;
      case 3:
        fprintf(f,"DIV R%d, R%d\n",lReg,rReg);
        break;
  }

  // freeing the right register
  freeReg();

  return lReg;

}

// -------------------------------------------------------------------- CODE GENERATION FOR BOOLEAN EXPRESSIONS ( E < E )

int boolean_expression_codeGen(FILE* f,struct TreeNode* root){
  int lReg = arithmetic_expression_codeGen(f,root->left);
  int rReg = arithmetic_expression_codeGen(f,root->right);

  switch(root->op){
    case 5:
      fprintf(f,"LT R%d, R%d\n",lReg,rReg);
      break;
    case 6:
      fprintf(f,"LE R%d, R%d\n",lReg,rReg);
      break;
    case 7:
      fprintf(f,"GT R%d, R%d\n",lReg,rReg);
      break;
    case 8:
      fprintf(f,"GE R%d, R%d\n",lReg,rReg);
      break;
    case 9:
      fprintf(f,"NE R%d, R%d\n",lReg,rReg);
      break;
    case 10:
      fprintf(f,"EQ R%d, R%d\n",lReg,rReg);
      break;

  }

  freeReg();

  // lReg contains either 0 (if false) or 1 (if true)
  return lReg;

}


// -------------------------------------------------------------------- CODE GENERATION FOR ASSIGNMENTS

void assignment_codeGen(FILE* f,struct TreeNode* root){
  // NOW GET THE CHARACTER VALUE
  int variable = (int)root->left->varname - 96;
  int memAddress = 4095 + variable;

  // store the register contents in the memory location 'storeIn'
  int r1 = getReg();
  fprintf(f,"MOV R%d, %d\n",r1,memAddress);
  int fReg = arithmetic_expression_codeGen(f,root->right);
  fprintf(f,"MOV [R%d], R%d\n",r1, fReg);
  // freeing expression register
  freeReg();
  // freeing r1
  freeReg();
  

}

// ----------------------------------------------------------------------CODE GENERATION FOR READ OPERATIONS

void read_codeGen(FILE* f,struct TreeNode* root){

  int variable = (int)root->left->varname - 96;
  int memAddress = 4095 + variable;

  char s[50];
  snprintf(s,sizeof(s),"Enter %c : ", root->left->varname);
  //getInput(f,s);

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
  fprintf(f,"MOV R%d, %d\n",r1,memAddress);
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
  r1 = getReg();
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  freeReg();


}

// --------------------------------------------------------- CODE GENERATION FOR WRITE ASSIGNMENTS

void write_codeGen(FILE* f,struct TreeNode* root){

  //getInput(f,"Output : ");
  

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

  // pushing R -> argument 2 (data)
  int R = arithmetic_expression_codeGen(f,root->left);
  fprintf(f,"PUSH R%d\n",R);
  // freeing the register storing the result of the expression
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
  r1 = getReg();
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  freeReg();


}

// ------------------------------------------------------------- CODE GENERATION FOR IF STATEMENTS

void if_codeGen(FILE* f,struct TreeNode* root){
  int boolReg = boolean_expression_codeGen(f,root->middle);
  int l0 = getLabel();
  int l1 = getLabel();

  fprintf(f,"JZ R%d, L%d\n",boolReg,l0);
  // no need for the register storing the result of the boolean expression anymore
  freeReg();
  // code if 'if' statement is true
  codeGen(f,root->left);
  // jump to the end
  fprintf(f,"JMP L%d\n",l1);

  // code if 'if' statement is false (ie else condition)
  fprintf(f,"L%d:\n",l0);
  codeGen(f,root->right);

  fprintf(f,"L%d:\n",l1);

}

// ------------------------------------------------------------- CODE GENERATION FOR WHILE LOOPS

void while_codeGen(FILE* f,struct TreeNode* root){
  int l0 = getLabel();
  int l1 = getLabel();
  // for going through while loop again
  fprintf(f,"L%d:\n",l0);
  int boolReg = boolean_expression_codeGen(f,root->left);
  fprintf(f,"JZ R%d, L%d\n",boolReg,l1);
  freeReg();
  // generate code for body of while loop
  codeGen(f,root->right);
  // go to while loop again
  fprintf(f,"JMP L%d\n",l0);
  fprintf(f,"L%d:\n",l1);
    
}


// ------------------------------------------------------------- BOOLEAN FUNCTIONS

bool isAssignment(struct TreeNode* root){
    return root->op == 4;
}
bool isRead(struct TreeNode* root){
    return root->op == 11;
}
bool isWrite(struct TreeNode* root){
    return root->op == 12;
}
bool isArithmeticExpression(struct TreeNode* root){
    return root->op >= 0 && root->op <= 3;
}
bool isBooleanExpression(struct TreeNode* root){
    return root->op >= 5 && root->op <= 10;
}
bool isIf(struct TreeNode* root){
    return root->op == 14;
}
bool isWhile(struct TreeNode* root){
    return root->op == 15;
}



// ------------------------------------------------------------------- MAIN CODEGEN FUNCTION

void codeGen(FILE* f,struct TreeNode* root){
    if(root == NULL){
      return;
    }
    switch(root->op){
    case 4:
          assignment_codeGen(f,root);
          break;
    case 11:
          read_codeGen(f,root);
          break;
    case 12:
          write_codeGen(f,root);
          break;
    case 13:
          codeGen(f,root->left);
          codeGen(f,root->right);
          break;
    case 14:
          if_codeGen(f,root);
          break;
    case 15:
          while_codeGen(f,root);
          break;      
    }
   
}

