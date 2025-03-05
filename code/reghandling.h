#ifndef reghandling_h
#define reghandling_h

#include <stdio.h>
#include <stdbool.h>
#include "AST.h"

// CHECK ROW OVERFLOW

void rowOverflowCheck(FILE* f,int reg,struct TreeNode* root);

// COLUMN OVERFLOW CHECK

void columnOverflowCheck(FILE* f,int reg,struct TreeNode* root);

// CHECK IF ADDRESS IS ALLOCATED

void notAllocatedCheck(FILE* f,int reg);

// GET ADDRESS OF FIELD

void fieldMemberAddress(FILE* f,int reg,struct TreeNode* root);

// GETTING ADDRESS OF CLASS MEMBER ( FINAL MEMBER BEFORE METHOD INVOCATION )

void classMemberAddress(FILE* f,int reg,struct TreeNode* root);

// GETTING THE SMALLEST FREE REGISTER

int getReg(void);

// CHECK FOR REGISTER LEAKS

bool checkLeak(void);

// FREEING THE HIGHEST OCCUPIED REGISTER

void freeReg(void);

// GETTING LABEL

int getLabel(void);

// PRINT OUT SOMETHING IN CONSOLE

void getInput(FILE* f,char* s);

// CODE GEN FOR ARITHMETIC EXPRESSIONS

int arithmetic_expression_codeGen(FILE* f, struct TreeNode* root);

// CODE GEN FOR BOOLEAN EXPRESSIONS

int boolean_expression_codeGen(FILE* f,struct TreeNode* root);

// CODE GEN FOR ASSIGNMENT STATEMENTS

void assignment_codeGen(FILE* f, struct TreeNode* root);

// CODE GEN FOR CLASS ASSIGNMENT STATEMENTS

void class_assignment_codeGen(FILE* f,struct TreeNode* root);

// CODE GEN FOR READ STATEMENT

void read_codeGen(FILE* f,struct TreeNode* root);

// CODE GEN FOR WRITE STATEMENT

void write_codeGen(FILE* f,struct TreeNode* root);

// CODE GEN FOR IF STATEMENT

void if_codeGen(FILE* f,struct TreeNode* root,int bl,int cl);

// CODE GEN FOR WHILE STATEMENT

void while_codeGen(FILE* f,struct TreeNode* root);

// CODE GEN FOR BREAK STATEMENT

void break_codeGen(FILE* f,struct TreeNode* root,int label);

// CODE GEN FOR CONTINUE STATEMENT

void continue_codeGen(FILE* f,struct TreeNode* root,int label);

// CODE GEN FOR REPEAT STATEMENT

void repeat_codeGen(FILE* f,struct TreeNode* root);

// CODE GEN FOR DO WHILE STATEMENTS

void dowhile_codeGen(FILE* f,struct TreeNode* root);

// CODE GEN FOR INVOKING FUNCTIONS

int invoke_function_codeGen(FILE* f,struct TreeNode* root);

// CODE GEN FOR DEFINING FUNCTIONS

void define_function_codeGen(FILE* f,char* name,struct TreeNode* root);

// CODE GEN FOR RETURN STATEMENTS

void return_codeGen(FILE* f,struct TreeNode* root);

// CODE GEN FOR PUSHING REGISTERS

void pushRegisters(FILE* f);

// CODE GEN FOR POPPING REGISTERS

void popRegisters(FILE* f);

// CODE GEN FOR PUSHING ARGUMENTS

void pushArgs(FILE* f,struct TreeNode* head);

// CODE GEN FOR POPPING ARGUMENTS

void popArgs(FILE* f,struct TreeNode* head);


// MAIN CODE GEN FUNCTION

void codeGen(FILE* f,struct TreeNode* root,int bl,int cl);

// CODE GEN FOR INITIALIZE STATEMENT

int initialize_codeGen(FILE* f);

// CODE GEN FOR ALLOC STATEMENT

int alloc_codeGen(FILE* f);

// CODE GEN FOR FREE STATEMENT

void free_codeGen(FILE* f,struct TreeNode* root);

// codeGen to check if heap memory was allocated for a user defined datatype

void checkIfAllocated(FILE* f,int ptrReg);

// codeGen for new assignment ( different from ordinary assignment since 2 address assignments )

void new_codeGen(FILE* f,struct TreeNode* root);

// codeGen for filling the virtual function table

void vft_codeGen(FILE* f,struct TreeNode* root,int vft_start);

// codeGen for invoking methods ie (a.b.printdetails())

int invoke_method_codeGen(FILE* f,struct TreeNode* root);

// codeGen for defining methods

void define_method_codeGen(FILE* f,struct classtable* c,char* name,struct paramlist* p,struct TreeNode* body);

// CODE GEN FOR DELETE STATEMENT

void delete_codeGen(FILE* f,struct TreeNode* root);

#endif
