#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <stdio.h>
#include <stdlib.h>
#include "AST.h"

void evaluate(struct TreeNode* root);

int expressionEvaluator(struct TreeNode* root);

int getDetails(void);

#endif
