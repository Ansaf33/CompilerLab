#ifndef reghandling_h
#define reghandling_h

#include <stdio.h>
#include "tree_generator.h"

// GETTING THE SMALLEST FREE REGISTER


int getReg(void);

// FREEING THE HIGHEST OCCUPIED REGISTER

void freeReg(void);

// CODE GENERATION MODULE -> RETURNS THE INDEX OF THE REGISTER (0-19) CONTAINING THE FINAL RESULT

int codeGen(FILE* f, struct TreeNode* root);


#endif
