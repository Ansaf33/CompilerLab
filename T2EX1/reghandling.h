#ifndef reghandling_h
#define reghandling_h

#include <stdio.h>
#include "AST.h"

// GETTING THE SMALLEST FREE REGISTER


int getReg(void);

// FREEING THE HIGHEST OCCUPIED REGISTER

void freeReg(void);

// code generation for expressions -> returns the register with the final value (completed in stage 1, reuse it)

int expression_codeGen(FILE* f, struct TreeNode* root);

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


// codeGen for entire statement lists

void codeGen(FILE* f,struct TreeNode* root);

#endif
