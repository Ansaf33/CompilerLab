#include "reghandling.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "AST.h"

#include "symbol_table/Gsymbol.h"
#include "symbol_table/Lsymbol.h"

#include "udt/fieldlist.h"

#include "class/classtable.h"
#include "class/classmember.h"
#include "class/classmethod.h"

#define NOR 20 // maximum number of registers 
#define SP 4500 // initial stack pointer
#define BP 4500 // initial base pointer
#define ALLOC_ID 196 // library call address for alloc()
#define INIT_ID 128 // library call address for initialize()
#define FREE_ID 244 // library call address for free()



struct classtable* class = NULL; // global variable to check current class
static int highestUsedReg = -1; // as per definition
static int highestUsedLabel = -1; // as per definition

// --------------------------------------------------------------------------------------------- CHECK IF END CHILD IS A MEMBER

void checkLastMember(struct TreeNode* root){
  struct TreeNode* cur = root;
  int c = 1;
  while(cur->middle){
    cur = cur->middle;
    c++;
  }
  if( cur->methodName == NULL && c > 2 ){
    printf("Cannot access members of a class\n");
    exit(1);
  }
}


// --------------------------------------------------------------------------------------------- ROW OVERFLOW CODEGEN

void rowOverflowCheck(FILE* f,int exprReg,struct TreeNode* root){
      int rReg = getReg();
      fprintf(f,"MOV R%d, %d\n",rReg,root->Gsymbol->rowSize);
      fprintf(f,"LE R%d, R%d\n",rReg,exprReg);
      fprintf(f,"JNZ R%d, L50\n",rReg);
      freeReg();
}

// ---------------------------------------------------------------------------------------------- COLUMN OVERFLOW CODEGEN

void columnOverflowCheck(FILE* f,int resReg,struct TreeNode* root){
    int cReg = getReg();
    fprintf(f,"MOV R%d, %d\n",cReg,root->Gsymbol->colSize);
    fprintf(f,"LE R%d, R%d\n",cReg,resReg);
    fprintf(f,"JNZ R%d, L50\n",cReg);
    freeReg();
}

// ----------------------------------------------------------------------------------------------- NOT ALLOCATED CODEGEN

void notAllocatedCheck(FILE* f,int dynamic_start){
      int zReg = getReg();
      fprintf(f,"MOV R%d, %d\n",zReg,0);
      fprintf(f,"EQ R%d, R%d\n",zReg,dynamic_start);
      fprintf(f,"JNZ R%d, L52\n",zReg);
      freeReg();
}

// ----------------------------------------------------------------------------------------------- GET ADDRESS OF FIELD MEMBER

void fieldMemberAddress(FILE* f,int adReg,struct TreeNode* root){
      int dynamic_start = getReg();
      fprintf(f,"MOV R%d, [R%d]\n",dynamic_start,adReg);

      notAllocatedCheck(f,dynamic_start); // check if address is zero

      struct TreeNode* cur = root;

      // non primitive field members
      while( cur->middle && !same(cur->type->name,"int") && !same(cur->type->name,"str") ){

        struct fieldlist* fieldlist = cur->type->fieldlist;
        cur = cur->middle;

        // add offset to starting address
        struct fieldlist* curField = lookFLUp(fieldlist,cur->fieldName);
        int offset = curField->fieldIndex;
        fprintf(f,"ADD R%d, %d\n",dynamic_start,offset);

        // jumping address condition
        if( cur->middle ){
          fprintf(f,"MOV R%d, [R%d]\n",dynamic_start,dynamic_start);
        }

        notAllocatedCheck(f,dynamic_start); // check if allocated again

      }

      fprintf(f,"MOV R%d, R%d\n",adReg,dynamic_start);

      // free dynamic_start register
      freeReg();
}

// ---------------------------------------------------------------------------------------- GET ADDRESS OF CLASS MEMBER

void classMemberAddress(FILE* f,int adReg,struct TreeNode* root){

  int dynamic_start = getReg();
  fprintf(f,"MOV R%d, [R%d]\n",dynamic_start,adReg);


  notAllocatedCheck(f,dynamic_start); // check if address was allocated

  struct TreeNode* cur = root;

  // for subsequent class members, jump to that address
  while( cur->middle && cur->Ctype != NULL && cur->middle->methodName == NULL ){

    // add offset to starting address
    struct classmember* nextMember = lookMemberInClassUp(cur->Ctype,cur->middle->fieldName);
    int offset = nextMember->memberIndex;
    fprintf(f,"ADD R%d, %d\n",dynamic_start,offset);

    cur = cur->middle;
    
    // jumping condition
    if( cur->middle ){
      fprintf(f,"MOV R%d, [R%d]\n",dynamic_start,dynamic_start);
    }

    notAllocatedCheck(f,dynamic_start); // check if allocated again or it points to 0

  }

  fprintf(f,"MOV R%d, R%d\n",adReg,dynamic_start);

  // free dynamic_start register
  freeReg();

}


// ------------------------------------------------------------------------------------------------------------------ GET SYMBOL ADDRESS FOR SELF

void getSelfAddress(FILE* f,int adReg,struct TreeNode* root){
  struct Lsymbol* local = lookLUp("self");
  fprintf(f,"MOV R%d, %d\n",adReg,local->binding);
  fprintf(f,"ADD R%d, BP\n",adReg);
}


// ------------------------------------------------------------------------------------------------------------------- GET SYMBOL ADDRESS (MAIN FUNC)

int getSymbolAddress(FILE* f,struct TreeNode* root){

  int adReg = getReg();

  // if varname is self
  if( root->varname && strcmp(root->varname,"self") == 0 ){
    getSelfAddress(f,adReg,root);
  }

  if( root->Lsymbol ){
      fprintf(f,"MOV R%d, %d\n",adReg,root->Lsymbol->binding);
      fprintf(f,"ADD R%d, BP\n",adReg);
  }
  else if( root->Gsymbol ){
      fprintf(f,"MOV R%d, %d\n",adReg,root->Gsymbol->binding);
  } 

  // ---------------------------- FOR VARIABLES AND ARRAYS --------------------------
  if( root->column ){

    int b = getReg();
    fprintf(f,"MOV R%d, %d\n",b,0);

    if( root->row ){
      int exprReg = arithmetic_expression_codeGen(f,root->row);

      rowOverflowCheck(f,exprReg,root); // check for row overflow

      fprintf(f,"ADD R%d, R%d\n",b,exprReg);
      freeReg();
    }

    fprintf(f,"MUL R%d, %d\n",b,root->Gsymbol->colSize);
    fprintf(f,"ADD R%d, R%d\n",adReg,b);
    freeReg();

    int resReg = arithmetic_expression_codeGen(f,root->column);

    columnOverflowCheck(f,resReg,root); // check for column overflow

    fprintf(f,"ADD R%d, R%d\n",adReg,resReg);
    freeReg();   
  }

  // ------------------------------------ FOR FIELD MEMBERS / CLASS MEMBERS  --------------------------
  

  if( root->middle ){
    // udt member access
    if( root->Ctype == NULL ){
      fieldMemberAddress(f,adReg,root);
    }
    // class member
    else if( root->middle->methodName == NULL ){
      classMemberAddress(f,adReg,root);
    }
  }

  return adReg;
 
}

// ------------------------------------------------------------------------------------------------------------------------ GET LABEL FUNCTION

int getLabel(void){
  ++highestUsedLabel;
  return highestUsedLabel;
}


// --------------------------------------------------------------------------------------------------------------------------- GET REG FUNCTION

int getReg(void){
  if( highestUsedReg == NOR - 1 ){
      printf("Cannot allocate more registers.");
      exit(1);
  }
  return ++highestUsedReg;

}

// ---------------------------------------------------------------------------------------------------------------------------- CHECK REGISTER LEAK

bool checkLeak(){
  if(highestUsedReg > -1 ){
    printf("Register leak present\n");
    exit(1);
  }
}

// -------------------------------------------------------------------------------------------------------------------------- FREE REG FUNCTION

void freeReg(){
  if( highestUsedReg >= 0 ){
    --highestUsedReg;
  }
  else{
    printf("All registers already free.");
  }
}

// ------------------------------------------------------------------------------------------------------------- WRITING STRING TO CONSOLE

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


// ---------------------------------------------------------------------------------------------- CODE GENERATION FOR ARITHMETIC EXPRESSIONS ( E )

int arithmetic_expression_codeGen(FILE* f,struct TreeNode* root){

    // if leaf node
    if( root->left == NULL && root->right == NULL ){
      int regIdx = getReg();

      // if number, move value to register
      if(root->val != -1 ){
        fprintf(f,"MOV R%d, %d\n",regIdx,root->val);
      }

      // if string, move string to register
      if(root->string != NULL ){
        fprintf(f,"MOV R%d, %s\n",regIdx,root->string);
      }

      // if variable/function
      else if( root->varname != NULL  ){

        struct Gsymbol* global = lookGUp(root->varname);
        struct Lsymbol* local = lookLUp(root->varname);

        // if null, simply move 0 to register
        if( strcmp(root->varname,"null") == 0 ){
          fprintf(f,"MOV R%d, %d\n",regIdx,0);
        }

        // if variable, get the address of the variable and move contents to register
        else if( local || global->flabel == -1 ){
          // local variable
          if( root->type != NULL ){
            int memlocationReg = getSymbolAddress(f,root);
            fprintf(f, "MOV R%d, [R%d]\n",regIdx,memlocationReg);
            freeReg();
          }

          // if it is of type class
          else if( root->Ctype != NULL ){
            

            checkLastMember(root); // check last member ( exit condition )

            // check if it leads to a method
            struct TreeNode* parent = root;
            struct TreeNode* child = root->middle;
            while(child->middle){
              parent = child;
              child = child->middle;
            }

            // if method, invoke the function and store return value in register
            if( child->methodName ){
              int retReg = invoke_method_codeGen(f,root);
              fprintf(f,"MOV R%d, R%d\n",regIdx,retReg);
              freeReg();
            }
            
            // if member, get address and store in register
            else{
              int memlocationReg = getSymbolAddress(f,root);
              fprintf(f,"MOV R%d, [R%d]\n",regIdx,memlocationReg);
              freeReg();
            }
          
          }

        }

        // if function, invoke the function and store return value in register
        else if( global->flabel >= 0 ){
          int retReg = invoke_function_codeGen(f,root);
          fprintf(f,"MOV R%d, R%d\n",regIdx,retReg);
          freeReg();
        }

      }

      // if initialize function, it returns 1/0 depending on success/failure
      if( root->op == 21 ){
        int retReg = initialize_codeGen(f);
        fprintf(f,"MOV R%d, R%d\n",regIdx,retReg);
        freeReg();
      }

      // if alloc function, it returns the starting address of heap allocated
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

  freeReg(); //freeing the right register

  return lReg; // free this register in statements that call this function

}

// ---------------------------------------------------------------------------------------------- CODE GENERATION FOR BOOLEAN EXPRESSIONS ( E < E )

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

  freeReg(); // free right register

  return lReg; // left register must be freed by statements that call this function

}


// ------------------------------------------------------------------------------------------------------ CODE GENERATION FOR ASSIGNMENTS ( a = 3*4+7 )

void assignment_codeGen(FILE* f,struct TreeNode* root){


  // get address where expression result is to be stored
  int r1 = getReg();
  int memAddressReg = getSymbolAddress(f,root->left);
  fprintf(f,"MOV R%d, R%d\n",r1,memAddressReg);
  freeReg();

  // evaluate the expression and move contents to the address
  int fReg = arithmetic_expression_codeGen(f,root->right);
  fprintf(f,"MOV [R%d], R%d\n",r1, fReg);
  freeReg();


  freeReg();

  checkLeak();
}

// ---------------------------------------------------------------------------------------- CODE GENERATION FOR CLASS ASSIGNMENTS ( arbitrary = first )

void class_assignment_codeGen(FILE* f,struct TreeNode* root){

  // get address that contains starting address of heap of RHS
  int Radr = getReg();
  int memAddressReg = getSymbolAddress(f,root->right);
  fprintf(f,"MOV R%d, R%d\n",Radr,memAddressReg);
  freeReg();

  // get address of LHS
  int Ladr = getReg();
  memAddressReg = getSymbolAddress(f,root->left);
  fprintf(f,"MOV R%d, R%d\n",Ladr,memAddressReg);
  freeReg();

  // move heap start of RHS to LHS
  int dynamic_start = getReg();
  fprintf(f,"MOV R%d, [R%d]\n",dynamic_start,Radr);
  fprintf(f,"MOV [R%d], R%d\n",Ladr,dynamic_start);
  freeReg();

  fprintf(f,"ADD R%d, %d\n",Ladr,1);
  fprintf(f,"ADD R%d, %d\n",Radr,1);
  
  // move VFTP of RHS to LHS
  int vftp = getReg();
  fprintf(f,"MOV R%d, [R%d]\n",vftp,Radr);
  fprintf(f,"MOV [R%d], R%d\n",Ladr,vftp);
  freeReg();

  freeReg(); // freeing Ladr
  freeReg(); // freeing Radr

}

// --------------------------------------------------------------------------------------------------------------- CODE GENERATION FOR READ OPERATIONS

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

  // call
  fprintf(f,"CALL 0\n");

  // pop registers
  r1 = getReg();
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  freeReg();



}

// ----------------------------------------------------------------------------------------------------------- CODE GENERATION FOR WRITE ASSIGNMENTS

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
  freeReg();

  // pushing empty register -> argument 3
  r1 = getReg();
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // pushing register for return value
  r1 = getReg();
  fprintf(f,"PUSH R%d\n",r1);
  freeReg();

  // call
  fprintf(f,"CALL 0\n");

  // popping registers
  r1 = getReg();
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  fprintf(f,"POP R%d\n",r1);
  freeReg();


}

// -------------------------------------------------------------------------------------------------------------- CODE GENERATION FOR IF STATEMENTS

void if_codeGen(FILE* f,struct TreeNode* root,int bl,int cl){

  int boolReg = boolean_expression_codeGen(f,root->middle);
  int l0 = getLabel();
  int l1 = getLabel();

  // if the boolean expression is false, go to else condition
  fprintf(f,"JZ R%d, L%d\n",boolReg,l0);
  freeReg();

  // if block
  codeGen(f,root->left,bl,cl);

  // jump to the end
  fprintf(f,"JMP L%d\n",l1);

  // else block
  fprintf(f,"L%d:\n",l0);
  codeGen(f,root->right,bl,cl);

  // exit label
  fprintf(f,"L%d:\n",l1);

}

// ----------------------------------------------------------------------------------------------------------------- CODE GENERATION FOR WHILE LOOPS

void while_codeGen(FILE* f,struct TreeNode* root){

  int l0 = getLabel();
  int l1 = getLabel();

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

// -------------------------------------------------------------------------------------------------------------- CODE GENERATION FOR BREAK STATEMENT

void break_codeGen(FILE* f,struct TreeNode* root,int label){
  if(label!=-1){
   fprintf(f,"JMP L%d\n",label);
  }

}

// ----------------------------------------------------------------------------------------------------------- CODE GENERATION FOR CONTINUE STATEMENT

void continue_codeGen(FILE* f,struct TreeNode* root,int label){
  if(label!=-1){
    fprintf(f,"JMP L%d\n",label);
  }

}

// -------------------------------------------------------------------------------------------------------------- CODE GENERATION FOR REPEAT STATEMENT

void repeat_codeGen(FILE* f,struct TreeNode* root){


  int l0 = getLabel();
  int l1 = getLabel();
  int bl = l1;
  int cl = l0;

  fprintf(f,"F%d:\n",l0);

  // codeblock
  codeGen(f,root->right,bl,cl);

  // boolean expression result
  int boolReg = boolean_expression_codeGen(f,root->left);

  // if zero, execute body of loop again
  fprintf(f,"JZ R%d, L%d\n",boolReg,l0);
  freeReg();

  // if one, exit loop
  fprintf(f,"L%d:\n",l1);

}

// ----------------------------------------------------------------------------------------------------------- CODE GENERATION FOR DO-WHILE STATEMENT

void dowhile_codeGen(FILE* f,struct TreeNode* root){

  int l0 = getLabel();
  int l1 = getLabel();
  int bl = l1;
  int cl = l0;

  fprintf(f,"L%d:\n",l0);

  // codeblock
  codeGen(f,root->right,bl,cl);

  // boolean expression
  int boolReg = boolean_expression_codeGen(f,root->left);

  // if one, execute body of loop again
  fprintf(f,"JNZ R%d, L%d\n",boolReg,l0);
  freeReg();

  // if zero, exit loop
  fprintf(f,"L%d:\n",l1);
  
}


// ---------------------------------------------------------------------------------------------------------------- CODE GEN WHEN FUNCTION IS INVOKED

int invoke_function_codeGen(FILE* f,struct TreeNode* root){

  // push used registers
  pushRegisters(f);

  // push arguments in reverse order
  pushArgs(f,root->argList);

  // push space for return value
  fprintf(f,"PUSH R0\n");

  // call the label ( translated to address during label_translation )
  fprintf(f,"CALL F%d\n",lookGUp(root->varname)->flabel);

  // store return value
  int returnReg = getReg();
  fprintf(f,"POP R%d\n",returnReg);

  // pop arguments from stack
  popArgs(f,root->argList);

  // pop used registers from stack
  popRegisters(f);


  return returnReg;
}

// ---------------------------------------------------------------------------------------------------------------- CODE GEN WHEN FUNCTION IS DEFINED

void define_function_codeGen(FILE* f,char* name,struct TreeNode* root){

  int flabel = lookGUp(name)->flabel;

  fprintf(f,"F%d:\n",flabel);

  // push base pointer
  fprintf(f,"PUSH BP\n");
  fprintf(f,"MOV BP, SP\n");

  // create space for local symbol table
  struct Lsymbol* cur = getLHead();
  while( cur != NULL ){
    int reg = getReg();
    fprintf(f,"PUSH R%d\n",reg);
    freeReg();
    cur = cur->next;
  }

  // execute codegen for the body of function
  codeGen(f,root,-1,-1);



}

// -------------------------------------------------------------------------------------------------------------- CODE GEN WHEN RETURN IS ENCOUNTERED

void return_codeGen(FILE* f,struct TreeNode* root){


  // evaluate the return expression
  int returnReg = arithmetic_expression_codeGen(f,root->middle);


  // store it at location [BP - 2]
  int reg = getReg();
  fprintf(f,"MOV R%d, BP\n",reg);
  fprintf(f,"SUB R%d, 2\n",reg);
  fprintf(f,"MOV [R%d], R%d\n",reg,returnReg);
  freeReg();

  freeReg();


  // pop local variables from stack
  struct Lsymbol* cur = getLHead();
  int loopReg = getReg();
  while( cur != NULL ){
    fprintf(f,"POP R%d\n",loopReg);
    cur = cur->next;
  }
  freeReg();
  

  // pop base pointer and move to old base pointer
  reg = getReg();
  fprintf(f,"POP R%d\n",reg);
  fprintf(f,"MOV BP, R%d\n",reg);
  freeReg();


  fprintf(f,"RET\n");
}


// --------------------------------------------------------------------------------------------------------------------------- PUSH ALL REGISTERS

void pushRegisters(FILE* f){
  for(int i=0;i<=highestUsedReg;i++){
    fprintf(f,"PUSH R%d\n",i);
  }
}

// --------------------------------------------------------------------------------- POP ALL REGISTERS (in reverse order since we pushed inside stack)

void popRegisters(FILE* f){
  for(int i=highestUsedReg-1;i>=0;i--){
    fprintf(f,"POP R%d\n",i);
  }

}

// ----------------------------------------------------------------------------------------------------------------------- PUSH ARGUMENTS TO STACK

void pushArgs(FILE* f,struct TreeNode* head){
  if( head == NULL ){
    return;
  }
  pushArgs(f,head->next);
  int resReg = arithmetic_expression_codeGen(f,head);
  fprintf(f,"PUSH R%d\n",resReg);
  freeReg();
}

// ------------------------------------------------------------------------------------------------------------------------- POP ARGUMENTS FROM STACK

void popArgs(FILE* f,struct TreeNode* head){
  struct TreeNode* cur = head;
  int pReg = getReg();
  while(cur!=NULL){
    fprintf(f,"POP R%d\n",pReg);
    cur = cur->next;
  }
  freeReg();


}

// ----------------------------------------------------------------------------------------------------- INITIALIZE CODEGEN ( IMPLEMENTED IN LIBRARY )

int initialize_codeGen(FILE* f){

  // pushing used registers
  pushRegisters(f);

  // pushing space for return value
  fprintf(f,"PUSH R0\n");

  // calling the address
  fprintf(f,"CALL %d\n",INIT_ID);

  // store return value
  int returnReg = getReg();
  fprintf(f,"POP R%d\n",returnReg);

  // pop used registers
  popRegisters(f);

  return returnReg;
}

// ------------------------------------------------------------------------------------------ CODE GEN FOR ALLOC() FUNCTION ( IMPLEMENTED IN LIBRARY )

int alloc_codeGen(FILE* f){

  // push used registers
  pushRegisters(f);

  // push empty register for storing return value
  fprintf(f,"PUSH R0\n");

  // call the address
  fprintf(f,"CALL %d\n",ALLOC_ID);

  // store return value
  int returnReg = getReg();
  fprintf(f,"POP R%d\n",returnReg);

  // pop used registers
  popRegisters(f);

  return returnReg;
}

// ------------------------------------------------------------------------------------------------------------------ CODE GEN FOR FREE ( ID ) FUNCTION


void free_codeGen(FILE* f,struct TreeNode* root){

  // push used registers
  pushRegisters(f);

  // push argument to stack ( address of UDT to be freed )
  int ptrReg = getSymbolAddress(f,root->middle);

  // check if register contents are 0
  checkIfAllocated(f,ptrReg);

  fprintf(f,"PUSH R%d\n",ptrReg);
  freeReg();


  // push register for return value ( unnecessary step )
  fprintf(f,"PUSH R0\n");

  // call address
  fprintf(f,"CALL %d\n",FREE_ID);

  // store return value ( unnecessary step )
  int returnReg = getReg();
  fprintf(f,"POP R%d\n",returnReg);

  // pop register for argument
  int argReg = getReg();
  fprintf(f,"POP R%d\n",argReg);
  freeReg();
  
  // pop used registers
  popRegisters(f);

  // deallocate the address (if classtype, then vftp as well)
  ptrReg = getSymbolAddress(f,root->middle);
  fprintf(f,"MOV [R%d], 0\n",ptrReg);
  if( root->middle->Ctype ){
    fprintf(f,"ADD R%d, %d\n",ptrReg,1);
    fprintf(f,"MOV [R%d], 0\n",ptrReg);
  }
  freeReg();


  freeReg();

}

// --------------------------------------------------------------------------------------------------- CHECK IF HEAP MEMORY WAS ALLOCATED FOR THE ID

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

// ----------------------------------------------------------------------------------------------------------------------- NEW CODEGEN

void new_codeGen(FILE* f,struct TreeNode* root){


  // get the virtual function table's starting address
  
  int classIndex = lookClassUp(root->right->middle->varname)->classIndex;
  int vft = 4096 + classIndex*8;

  // setup vft
  vft_codeGen(f,root,vft);

  // get the symbol address of the object
  int adReg = getSymbolAddress(f,root->left);

  // get the allocated heap address for member fields
  int allocReg = alloc_codeGen(f);

  // move [mfp, vftp] to location of class
  fprintf(f,"MOV [R%d], R%d\n",adReg,allocReg);
  fprintf(f,"ADD R%d, %d\n",adReg,1);
  fprintf(f,"MOV [R%d], %d\n",adReg,vft);

  freeReg();
  freeReg();


}

// ------------------------------------------------------------------------------------------------------------------------ FILL VFT CODEGEN

void vft_codeGen(FILE* f,struct TreeNode* root,int vft_start){

  // get access to classmethods of the class
  struct classmethod* methodlist = lookClassUp(root->right->middle->varname)->classmethod;
  int adr = vft_start;

  // filling the virtual function table with labels of the methods
  struct classmethod* cur = methodlist;
  while(cur!=NULL){
    fprintf(f,"MOV [%d], M%d\n",adr,cur->mLabel);
    adr++;
    cur = cur->next;
  }
}

// -------------------------------------------------------------------------------------------------------------------------- INVOKE METHOD CODEGEN

int invoke_method_codeGen(FILE* f,struct TreeNode* root){

  // push used registers
  pushRegisters(f);

  // get the address of the method in VFT
  struct classtable* c = root->Ctype;

  struct TreeNode* head = root;

  // go to last member ( followed by a method )
  while(root->middle->methodName == NULL ){
    root = root->middle;
    c = root->Ctype;
  }

  struct classmethod* method = lookMethodInClassUp(c,root->middle->methodName,NULL,root->middle->argList);

  // pushing member field pointer
  int adReg = getSymbolAddress(f,head);
  fprintf(f,"MOV R%d, [R%d]\n",adReg,adReg);
  fprintf(f,"PUSH R%d\n",adReg);
  freeReg();

  fprintf(f,"BRKP\n");

  // pushing virtual function table pointer
  adReg = getSymbolAddress(f,head);
  fprintf(f,"ADD R%d, %d\n",adReg,1);
  int vftReg = getReg();
  fprintf(f,"MOV R%d, [R%d]\n",vftReg,adReg);
  fprintf(f,"PUSH R%d\n",vftReg);

  freeReg(); // free vftReg
  freeReg(); // free adReg


  // push arguments
  pushArgs(f,root->middle->argList);

  // push register for return value
  fprintf(f,"PUSH R0\n");

  // call address
  adReg = getSymbolAddress(f,head);
  fprintf(f,"ADD R%d, %d\n",adReg,1);
  vftReg = getReg();
  fprintf(f,"MOV R%d, [R%d]\n",vftReg,adReg);
  fprintf(f,"ADD R%d, %d\n",vftReg,method->methodPos);
  int labelReg = getReg();
  fprintf(f,"MOV R%d, [R%d]\n",labelReg,vftReg);
  fprintf(f,"CALL R%d\n",labelReg);

  freeReg(); // free labelReg
  freeReg(); // free vftReg
  freeReg(); // free adReg


  // store return value
  int returnReg = getReg();
  fprintf(f,"POP R%d\n",returnReg);

  // pop arguments
  popArgs(f,root->middle->argList);


  // pop mftp and vftp
  int r = getReg();
  fprintf(f,"POP R%d\n",r);
  fprintf(f,"POP R%d\n",r);
  freeReg();

  // pop used registers
  popRegisters(f);

  return returnReg;

}

// -------------------------------------------------------------------------------------------------------------------------- DEFINE METHOD CODEGEN

void define_method_codeGen(FILE* f,struct classtable* c,char* name,struct paramlist* param,struct TreeNode* body){

  class = c;

  // get the label
  struct classmethod* method = lookMethodInClassUp(c,name,param,NULL);
  fprintf(f,"M%d:\n",method->mLabel);

  // push base pointer
  fprintf(f,"PUSH BP\n");
  fprintf(f,"MOV BP, SP\n");

  // push local variables
  struct Lsymbol* cur = getLHead();
  while(cur!=NULL){
    int r = getReg();
    fprintf(f,"PUSH R%d\n",r);
    freeReg();
    cur = cur->next;
  }


  // execute body of method
  codeGen(f,body,-1,-1);
}


// -------------------------------------------------------------------------------------------------------------------------- DELETE OBJECT FUNCTION

void delete_codeGen(FILE* f,struct TreeNode* root){

  // go to the last class and get the classmember list
  struct TreeNode* cur = root->middle;
  while(cur->middle){
    cur = cur->middle;
  }
  struct classmember* memberlist = cur->Ctype->classmember;

  while( memberlist ){
    // if the type is UDT
    if( memberlist->type && isUDT(memberlist->type->name) ){

      // push registers
      pushRegisters(f);

      // get the symbol address of the class's heap start, add offset
      int dynamic_reg = getSymbolAddress(f,root->middle);
      fprintf(f,"MOV R%d, [R%d]\n",dynamic_reg,dynamic_reg);
      fprintf(f,"ADD R%d, %d\n",dynamic_reg,memberlist->memberIndex);

      // push argument
      fprintf(f,"PUSH R%d\n",dynamic_reg);
      freeReg();

      // push space for return value
      int retReg = getReg();
      fprintf(f,"PUSH R%d\n",retReg);
      freeReg();

      // call
      fprintf(f,"CALL %d\n",FREE_ID);

      // pop return value
      retReg = getReg();
      fprintf(f,"POP R%d\n",retReg);

      // pop argument
      int argReg = getReg();
      fprintf(f,"POP R0\n");
      freeReg();


      // pop registers
      popRegisters(f);

      // free return value register
      freeReg();

      // change the address to 0 to indicate it has been freed
      dynamic_reg = getSymbolAddress(f,root->middle);
      fprintf(f,"MOV R%d, [R%d]\n",dynamic_reg,dynamic_reg);
      fprintf(f,"ADD R%d, %d\n",dynamic_reg,memberlist->memberIndex);
      fprintf(f,"MOV [R%d], 0\n",dynamic_reg);
      freeReg();



    }
    memberlist = memberlist->next;


  }


  free_codeGen(f,root);
}

// -------------------------------------------------------------------------------------------------------------------------- MAIN CODEGEN FUNCTION

void codeGen(FILE* f,struct TreeNode* root,int bl,int cl){
    if(root == NULL){
      return;
    }
    switch(root->op){
    // assignment
    case 4:
          if( root->right->op == 25 ){
            new_codeGen(f,root);
          }
          else if( root->left->Ctype && root->right->Ctype ){
            class_assignment_codeGen(f,root);
          }
          else{
            assignment_codeGen(f,root);
          }
          break;
    // read
    case 11:
          read_codeGen(f,root);
          break;
    // write
    case 12:
          write_codeGen(f,root);
          break;
    // connector node
    case 13:
          codeGen(f,root->left,bl,cl);
          codeGen(f,root->right,bl,cl);
          break;
    // if statement
    case 14:
          if_codeGen(f,root,bl,cl);
          break;
    // while statement
    case 15: 
          while_codeGen(f,root);
          break;
    // break statement
    case 16:
          break_codeGen(f,root,bl);
          break;
    // continue statement
    case 17:
          continue_codeGen(f,root,cl);
          break;
    // repeat until statement
    case 18:
          repeat_codeGen(f,root);
          break;
    // do while statement
    case 19:
          dowhile_codeGen(f,root);
          break;
    // return statement
    case 20:
          return_codeGen(f,root);
          break;
    // free statement
    case 23:
          free_codeGen(f,root);
          break;
    // delete statement
    case 24:
          delete_codeGen(f,root);
          break;
  }

  
}

