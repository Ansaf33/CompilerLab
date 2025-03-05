#ifndef TYPESATIFY_H
#define TYPESATISFY_H

#include <stdio.h>
#include "../AST.h"
#include "../symbol_table/paramlist.h"

void iterateThroughClassMembers(struct TreeNode* root);

char* getName(struct TreeNode* root);

struct classtable* getType(struct TreeNode* root);

bool arithmetic_typeSatisfied(struct TreeNode* root);

bool assignment_typeSatisfied(struct TreeNode* root);

bool logical_typeSatisfied(struct TreeNode* root);

bool read_typeSatisfied(struct TreeNode* root);

bool write_typeSatisfied(struct TreeNode* root);

bool if_typeSatisfied(struct TreeNode* root);

bool while_typeSatisfied(struct TreeNode* root);

bool return_typeSatisfied(struct TreeNode* root);

bool free_typeSatisfied(struct TreeNode* root);

bool delete_typeSatisfied(struct TreeNode* root);

bool canReachAncestor(struct classtable* child,struct classtable* parent);




#endif
