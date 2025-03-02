#ifndef reghandling_h
#define reghandling_h

#include <stdio.h>
#include <stdbool.h>
#include "AST.h"

// CHECK ROW OVERFLOW

void rowOverflowCheck(FILE* f,int reg,struct TreeNode* root);

// COLUMN OVERFLOW CHECK

void columnOverflowCheck(FILE* f,int reg,struct TreeNode* root);

// GET ADDRESS OF FIELD

void fieldMemberAddress(FILE* f,int reg,struct TreeNode* root);

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

// code generation for arithmetic expressions -> returns the register with the final value 

int arithmetic_expression_codeGen(FILE* f, struct TreeNode* root);

// code generation for boolean expressions -> returns the register containing 0 or 1

int boolean_expression_codeGen(FILE* f,struct TreeNode* root);

// code generation for assignments -> ID = E
// call expression_codeGen on right subtree, we get the register with the final value
// now we need to move the contents of that register to a memory location using MOV

void assignment_codeGen(FILE* f, struct TreeNode* root);

// code generation for read
// LHS contains the variable character
// memory address to be read into = 4095 + (int)(character)
// perform read operation using read system call


void read_codeGen(FILE* f,struct TreeNode* root);


// code generation for write
// LHS contains an expression, so call expression_codeGen on Left Subtree first
// result is stored in a register
// simple write the contents of that register

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


// codeGen for entire statement lists

void codeGen(FILE* f,struct TreeNode* root,int bl,int cl);

// codeGen for initialize statement

int initialize_codeGen(FILE* f);

// codeGen for alloc statement

int alloc_codeGen(FILE* f);

// codeGen for free statement

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

void define_method_codeGen(FILE* f,struct classtable* c,char* name,struct TreeNode* body);

#endif
