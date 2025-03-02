#include "reghandling.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AST.h"
#include "symbol_table/Gsymbol.h"
#include "symbol_table/Lsymbol.h"
#include "udt/fieldlist.h"

// DEFINTIONS
#define NOR 20
#define SP 4500
#define BP 4500
#define ALLOC_ID 196
#define INIT_ID 128
#define FREE_ID 244



// INITIALLY, NO REGISTERS ARE USED
static int highestUsedReg = -1;
// INITIALLY, NO LABELS ARE USED
static int highestUsedLabel = -1;

// --------------------------------------------------------- GET SYMBOL ADDRESS

int getSymbolAddress(FILE* f,struct TreeNode* root){

  // CONTAINS ADDRESS

  int adReg = getReg();
  if( root->Lsymbol ){
    fprintf(f,"MOV R%d, %d\n",adReg,root->Lsymbol->binding);
    fprintf(f,"ADD R%d, BP\n",adReg);
  }
  else{
    fprintf(f,"MOV R%d, %d\n",adReg,root->Gsymbol->binding);
  }

  // ----- FOR VARIABLES AND ARRAYS ----

  if( root->column ){
    
    int b = getReg();
    fprintf(f,"MOV R%d, %d\n",b,0);


    if( root->row ){
      int exprReg = arithmetic_expression_codeGen(f,root->row);

      // ------------------------ ROW OVERFLOW HERE ITSELF -----------------------
      int rReg = getReg();
      fprintf(f,"MOV R%d, %d\n",rReg,root->Gsymbol->rowSize);
      fprintf(f,"LE R%d, R%d\n",rReg,exprReg);
      fprintf(f,"JNZ R%d, L50\n",rReg);
      freeReg();
      // ------------------------ END OVERFLOW CHECK -----------------------------

      fprintf(f,"ADD R%d, R%d\n",b,exprReg);
      freeReg();
    }

    fprintf(f,"MUL R%d, %d\n",b,root->Gsymbol->colSize);
    fprintf(f,"ADD R%d, R%d\n",adReg,b);
    freeReg();

    int resReg = arithmetic_expression_codeGen(f,root->column);

    // ---------------------- COLUMN OVERFLOW HERE ITSELF --------------------------
    int cReg = getReg();
    fprintf(f,"MOV R%d, %d\n",cReg,root->Gsymbol->colSize);
    fprintf(f,"LE R%d, R%d\n",cReg,resReg);
    fprintf(f,"JNZ R%d, L50\n",cReg);
    freeReg();
    // ----------------------- END OVERFLOW CHECK ----------------------------------
    fprintf(f,"ADD R%d, R%d\n",adReg,resReg);
    freeReg();   
  }

  // --- FOR FIELD MEMBERS ----  

  else if( root->middle != NULL ){
    int dynamic_start = getReg();
    fprintf(f,"MOV R%d, [R%d]\n",dynamic_start,adReg);

    // -------- CHECK IF IT IS 0, IF IT IS, THEN ERR ------------
    int zReg = getReg();
    fprintf(f,"MOV R%d, %d\n",zReg,0);
    fprintf(f,"EQ R%d, R%d\n",zReg,dynamic_start);
    fprintf(f,"JNZ R%d, L52\n",zReg);
    freeReg();
    // ----------- CHECKING DONE -------------------------------


    struct TreeNode* cur = root;

    // IF FIELD MEMBERS EXIST THAT ARE NOT PRIMITIVE
    while( cur->middle && !same(cur->type->name,"int") && !same(cur->type->name,"str") ){


      struct fieldlist* fieldlist = cur->type->fieldlist;
        
    
      // CALCULATE OFFSET AND ADD IT TO STARTING ADDRESS
      cur = cur->middle;
      struct fieldlist* curField = lookFLUp(fieldlist,cur->fieldName);
      int offset = 1 + curField->fieldIndex;
      fprintf(f,"ADD R%d, %d\n",dynamic_start,offset);  

      // JUMPNG CONDITION
      if( cur->middle ){
        fprintf(f,"MOV R%d, [R%d]\n",dynamic_start,dynamic_start);
      }
      
    }

    fprintf(f,"MOV R%d, R%d\n",adReg,dynamic_start);

    // FREE DYNAMIC START REGISTER
    freeReg();

  }



  return adReg;
 

}

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

bool checkLeak(){
  if(highestUsedReg > -1 ){
    printf("Register leak present\n");
    exit(1);
  }
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

    // IF AT LEAF NODE, THEN ONLY NUMBER OR CONSTANT
    if( root->left == NULL && root->right == NULL ){
      int regIdx = getReg();

      // IF NUMBER, MOVE THE NUMBER TO REGISTER
      if(root->val != -1 ){
        fprintf(f,"MOV R%d, %d\n",regIdx,root->val);
      }

      // IF STRING, MOVE THE STRING TO REGISTER
      if(root->string != NULL ){
        fprintf(f,"MOV R%d, %s\n",regIdx,root->string);
      }

      // IF VARIABLE OR FUNCTION
      else if( root->varname != NULL  ){

        struct Gsymbol* global = lookGUp(root->varname);
        struct Lsymbol* local = lookLUp(root->varname);


        // IF IT IS NULL
        if( strcmp(root->varname,"null") == 0 ){
          fprintf(f,"MOV R%d, %d\n",regIdx,0);
        }


        // IF VARIABLE, MOVE IT FROM MEMORY TO REGISTER
      
        else if( local || global->flabel == -1 ){
          int memlocationReg = getSymbolAddress(f,root);
          fprintf(f, "MOV R%d, [R%d]\n",regIdx,memlocationReg);
          freeReg();
        }

        // IF FUNCTION, WRITE CODEGEN FOR THE FUNCTION AND STORE IT IN REGISTER

        else if( global->flabel >= 0 ){
          int retReg = invoke_function_codeGen(f,root);
          fprintf(f,"MOV R%d, R%d\n",regIdx,retReg);
          freeReg();
        }

      }

      // IF INITIALIZE FUNCTION
      if( root->op == 21 ){
        int retReg = initialize_codeGen(f);
        fprintf(f,"MOV R%d, R%d\n",regIdx,retReg);
        freeReg();
      }

      // IF ALLOC FUNCTION
      if( root->op == 22 ){
        int retReg = alloc_codeGen(f);
        fprintf(f,"MOV R%d, R%d\n",regIdx,retReg);
        freeReg();
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

  // ONE REGISTER IS USED, MUST BE FREED IN STATEMENTS THAT CALL THIS FUNCTION
  return lReg;

}

// -------------------------------------------------------------------- CODE GENERATION FOR BOOLEAN EXPRESSIONS ( E < E )

int boolean_expression_codeGen(FILE* f,struct TreeNode* root){

  // BOOLEAN EXPRESSIONS ARE OF THE FORM E < E SO EVALUATE BOTH OF THEM FIRST
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

  // free rReg
  freeReg();

  // lReg contains either 0 (if false) or 1 (if true)
  return lReg;

}


// -------------------------------------------------------------------- CODE GENERATION FOR ASSIGNMENTS ( a = 3*4+7 )

void assignment_codeGen(FILE* f,struct TreeNode* root){


  // store the register contents in the memory location 'storeIn'
  int r1 = getReg();
  
  // get memlocation in a register and move the memory location to a register
  int memAddressReg = getSymbolAddress(f,root->left);

  fprintf(f,"MOV R%d, R%d\n",r1,memAddressReg);
  freeReg();


  int fReg = arithmetic_expression_codeGen(f,root->right);

  // move the contents of fReg to memory location specified by r1
  fprintf(f,"MOV [R%d], R%d\n",r1, fReg);

  // freeing expression register
  freeReg();
  // freeing r1
  freeReg();

  checkLeak();
}

// ----------------------------------------------------------------------CODE GENERATION FOR READ OPERATIONS

void read_codeGen(FILE* f,struct TreeNode* root){


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

  int memAddressReg = getSymbolAddress(f,root->left);
  fprintf(f,"MOV R%d, R%d\n",r1,memAddressReg);
  freeReg();

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

void if_codeGen(FILE* f,struct TreeNode* root,int bl,int cl){

  int boolReg = boolean_expression_codeGen(f,root->middle);
  int l0 = getLabel();
  int l1 = getLabel();

  // if the boolean expression is false, go to else condition
  fprintf(f,"JZ R%d, L%d\n",boolReg,l0);
  // no need for the register storing the result of the boolean expression anymore
  freeReg();

  // code if 'if' statement is true
  codeGen(f,root->left,bl,cl);

  // jump to the end
  fprintf(f,"JMP L%d\n",l1);

  // code if 'if' statement is false (ie else condition)
  fprintf(f,"L%d:\n",l0);
  codeGen(f,root->right,bl,cl);

  fprintf(f,"L%d:\n",l1);

}

// ------------------------------------------------------------- CODE GENERATION FOR WHILE LOOPS

void while_codeGen(FILE* f,struct TreeNode* root){

  int l0 = getLabel();
  int l1 = getLabel();

  // BREAK LABEL AND CONTINUE LABEL
  int breakLabel = l1;
  int continueLabel = l0;

  // code for going through while loop again
  fprintf(f,"L%d:\n",l0);
  int boolReg = boolean_expression_codeGen(f,root->left);

  // if false, go out of the loop of l1
  fprintf(f,"JZ R%d, L%d\n",boolReg,l1);
  freeReg();

  // generate code for body of while loop
  codeGen(f,root->right,breakLabel,continueLabel);

  // go to while loop again 
  fprintf(f,"JMP L%d\n",l0);

  // exit while loop 
  fprintf(f,"L%d:\n",l1);

  
}

// ------------------------------------------------------------- CODE GENERATION FOR BREAK STATEMENT

void break_codeGen(FILE* f,struct TreeNode* root,int label){
  if(label!=-1){
   fprintf(f,"JMP L%d\n",label);
  }

}

// ------------------------------------------------------------- CODE GENERATION FOR CONTINUE STATEMENT

void continue_codeGen(FILE* f,struct TreeNode* root,int label){
  if(label!=-1){
    fprintf(f,"JMP L%d\n",label);
  }

}

// ------------------------------------------------------------- CODE GENERATION FOR REPEAT STATEMENT

void repeat_codeGen(FILE* f,struct TreeNode* root){


  int l0 = getLabel();
  int l1 = getLabel();
  int bl = l1;
  int cl = l0;

  // STARTING POINT
  fprintf(f,"F%d:\n",l0);

  // CODE FOR STATEMENT LIST
  codeGen(f,root->right,bl,cl);

  // CONDITION
  int boolReg = boolean_expression_codeGen(f,root->left);

  // IF IT IS FALSE, GO BACK TO L0
  fprintf(f,"JZ R%d, L%d\n",boolReg,l0);
  freeReg();

  // IF IT IS TRUE, GO OUTSIDE
  fprintf(f,"L%d:\n",l1);

}

// ------------------------------------------------------------- CODE GENERATION FOR DO-WHILE STATEMENT

void dowhile_codeGen(FILE* f,struct TreeNode* root){

  int l0 = getLabel();
  int l1 = getLabel();
  int bl = l1;
  int cl = l0;

  // STARTING POINT
  fprintf(f,"L%d:\n",l0);

  // CODE FOR STATEMENT LIST
  codeGen(f,root->right,bl,cl);

  // CONDITION
  int boolReg = boolean_expression_codeGen(f,root->left);

  // IF IT IS TRUE, GO BACK TO L0, EXECUTE WHILE LOOP AGAIN
  fprintf(f,"JNZ R%d, L%d\n",boolReg,l0);
  freeReg();

  // IF IT IS FALSE, EXIT THE WHILE LOOP
  fprintf(f,"L%d:\n",l1);
  
}


// ------------------------------------------------------------- CODE GEN WHEN FUNCTION IS INVOKED

int invoke_function_codeGen(FILE* f,struct TreeNode* root){

  // PUSH USED REGISTERS
  pushRegisters(f);

  // PUSHED ARGUMENT LIST IN REVERSE ORDER
  pushArgs(f,root->argList);

  // PUSH EMPTY REGISTER FOR RETURN VALUE
  fprintf(f,"PUSH R0\n");


  // CALL THE FUNCTION
  fprintf(f,"CALL F%d\n",lookGUp(root->varname)->flabel);

  // TOP CONTAINS RETURN VALUE, STORE IT

  int returnReg = getReg();
  fprintf(f,"POP R%d\n",returnReg);

  // POP OUT ARGUMENTS FROM THE STACK
  popArgs(f,root->argList);

  // POP OUT USED REGISTERS FROM THE STACK
  popRegisters(f);


  return returnReg;

}

// ------------------------------------------------------------- CODE GEN WHEN FUNCTION IS DEFINED

void define_function_codeGen(FILE* f,char* name,struct TreeNode* root){

  int flabel = lookGUp(name)->flabel;


  fprintf(f,"F%d:\n",flabel);


  // PUSHING BASE POINTER TO TOP OF STACK
  fprintf(f,"PUSH BP\n");

  // SET NEW BASE POINTER TO TOP OF STACK
  fprintf(f,"MOV BP, SP\n");

  // SPACE FOR LOCAL SYMBOL TABLE ( ALREADY EXISTING, SO GET THE SIZE )
  struct Lsymbol* cur = getLHead();
  while( cur != NULL ){
    int reg = getReg();
    fprintf(f,"PUSH R%d\n",reg);
    freeReg();
    cur = cur->next;
  }


  // EXECUTE CODEGEN OF THAT FUNCTION
  codeGen(f,root,-1,-1);



}

// ------------------------------------------------------------- CODE GEN WHEN RETURN IS ENCOUNTERED

void return_codeGen(FILE* f,struct TreeNode* root){


  // GET RETURN VALUE

  int returnReg = arithmetic_expression_codeGen(f,root->middle);


  int reg = getReg();
  fprintf(f,"MOV R%d, BP\n",reg);
  fprintf(f,"SUB R%d, 2\n",reg);
  
  // STORE IT IN BP - 2 -> reg
  fprintf(f,"MOV [R%d], R%d\n",reg,returnReg);

  freeReg();
  freeReg();


  // POP OUT LOCAL VARIABLES FROM STACK

  struct Lsymbol* cur = getLHead();
  reg = getReg();
  int loopReg = getReg();
  fprintf(f,"MOV R%d, BP\n",reg);

  while( cur != NULL ){

    fprintf(f,"ADD R%d, %d\n",reg,1);
    fprintf(f,"POP R%d\n",loopReg);

    cur = cur->next;

  }

  freeReg();
  freeReg();
  

  // POP BP AND SET BP TO OLD VALUE OF BP 
  
  reg = getReg();
  fprintf(f,"POP R%d\n",reg);
  fprintf(f,"MOV BP, R%d\n",reg);
  freeReg();

  // RETURN INSTRUCTION

  fprintf(f,"RET\n");


}


// ------------------------------------------------------------- PUSH ALL REGISTERS

void pushRegisters(FILE* f){
  for(int i=0;i<=highestUsedReg;i++){
    fprintf(f,"PUSH R%d\n",i);
  }
}

// ------------------------------------------------------------- POP ALL REGISTERS (in reverse order since we pushed inside stack)

void popRegisters(FILE* f){
  for(int i=highestUsedReg-1;i>=0;i--){
    fprintf(f,"POP R%d\n",i);
  }

}

// ----------------------------------------------------------- PUSH ARGUMENTS TO STACK

void pushArgs(FILE* f,struct TreeNode* head){
  if( head == NULL ){
    return;
  }
  pushArgs(f,head->next);
  // ARGUMENT SHOULD BE AN ARITHMETIC EXPRESSION 
  int resReg = arithmetic_expression_codeGen(f,head);
  fprintf(f,"PUSH R%d\n",resReg);
  freeReg();
  
}

// ----------------------------------------------------------- POP ARGUMENTS FROM STACK

void popArgs(FILE* f,struct TreeNode* head){
  struct TreeNode* cur = head;
  int pReg = getReg();

  while(cur!=NULL){
    fprintf(f,"POP R%d\n",pReg);
    cur = cur->next;
  }

  freeReg();


}

// ------------------------------------------------------------ INITIALIZE CODEGEN ( IMPLEMENTED IN LIBRARY )

int initialize_codeGen(FILE* f){
  fprintf(f,"BRKP\n");

  // PUSHING USED REGISTERS
  pushRegisters(f);

  // PUSHING FOR RETURN VALUE
  fprintf(f,"PUSH R0\n");

  // CALLING
  fprintf(f,"CALL %d\n",INIT_ID);

  // STORING RETURN VALUE
  int returnReg = getReg();
  fprintf(f,"POP R%d\n",returnReg);


  popRegisters(f);

  return returnReg;
}

// ------------------------------------------------------------ CODE GEN FOR ALLOC() FUNCTION

int alloc_codeGen(FILE* f){

  // PUSH USED REGISTERS TO STACK
  fprintf(f,"BRKP\n");
  pushRegisters(f);

  // PUSH EMPTY REGISTER FOR RETURN VALUE ( ADDRESS )
  fprintf(f,"PUSH R0\n");

  // CALL THE ADDRESS
  fprintf(f,"CALL %d\n",ALLOC_ID);

  // NOW THE TOP OF STACK HAS THE RETURN VALUE
  int returnReg = getReg();
  fprintf(f,"POP R%d\n",returnReg);

  // POP USED REGISTERS FROM STACK
  popRegisters(f);

  return returnReg;
}

// ------------------------------------------------------------- CODE GEN FOR FREE ( ID ) FUNCTION


void free_codeGen(FILE* f,struct TreeNode* root){

  fprintf(f,"BRKP\n");

  // PUSH REGISTERS TO STACK
  pushRegisters(f);

  // PUSH ONLY ARGUMENT TO STACK
  int ptrReg = getSymbolAddress(f,root->middle);

  // CHECK IF MEMORY WAS ALLOCATED FOR THE UDT
  checkIfAllocated(f,ptrReg);

  fprintf(f,"PUSH R%d\n",ptrReg);

  freeReg();


  // PUSH REGISTER FOR RETURN VALUE ( NO RETURN VALUES HERE, SO NOT NECESSARY )
  fprintf(f,"PUSH R0\n");

  // CALL FREE FUNCTION
  fprintf(f,"CALL %d\n",FREE_ID);

  // NO RETURN VALUES, SO COMPLETED.
  int returnReg = getReg();
  fprintf(f,"POP R%d\n",returnReg);
  
  // POP ALL REGISTERS
  popRegisters(f);

  ptrReg = getSymbolAddress(f,root->middle);
  fprintf(f,"MOV [R%d], 0\n",ptrReg);
  freeReg();


  // FREE THE RETURN VALUE REGISTER
  freeReg();

}

// ------------------------------------------------------------------- CHECK IF HEAP MEMORY WAS ALLOCATED FOR THE ID

void checkIfAllocated(FILE* f,int ptrReg){
  int addReg = getReg();
  fprintf(f,"MOV R%d, [R%d]\n",addReg,ptrReg);
  int zReg = getReg();
  fprintf(f,"MOV R%d, %d\n",zReg,0);
  fprintf(f,"EQ R%d, R%d\n",addReg,zReg);
  fprintf(f,"JNZ R%d, L52\n",addReg);
  freeReg();
  freeReg();
  
}

// ------------------------------------------------------------------- MAIN CODEGEN FUNCTION

void codeGen(FILE* f,struct TreeNode* root,int bl,int cl){
    if(root == NULL){
      return;
    }
    switch(root->op){
    // ASSIGNMENT STATEMENT
    case 4:
          assignment_codeGen(f,root);
          break;
    // READ STATEMENT
    case 11:
          read_codeGen(f,root);
          break;
    // WRITE STATEMENT
    case 12:
          write_codeGen(f,root);
          break;
    // STATEMENT S
    case 13:
          codeGen(f,root->left,bl,cl);
          codeGen(f,root->right,bl,cl);
          break;
    // IF STATEMENT
    case 14:
          if_codeGen(f,root,bl,cl);
          break;
    // WHILE STATEMENT
    case 15: 
          while_codeGen(f,root);
          break;
    // BREAK STATEMENT
    case 16:
          break_codeGen(f,root,bl);
          break;
    // CONTINUE STATEMENT
    case 17:
          continue_codeGen(f,root,cl);
          break;
    // REPEAT UNTIL STATEMENT
    case 18:
          repeat_codeGen(f,root);
          break;
    // DO WHILE STATEMENT
    case 19:
          dowhile_codeGen(f,root);
          break;
    // RETURN STATEMENT
    case 20:
          return_codeGen(f,root);
          break;
    // FREE STATEMENT
    case 23:
          free_codeGen(f,root);
          break;
    }
  
}

