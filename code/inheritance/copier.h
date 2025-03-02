#ifndef COPIER_H

#define COPIER_H

#include <stdio.h>
#include <stdlib.h>
#include "../class/classtable.h"
#include "../class/classmethod.h"
#include "../class/classmember.h"


void copyMembers(struct classtable* child,struct classtable* parent);

void copyMethods(struct classtable* child,struct classtable* parent);


#endif
