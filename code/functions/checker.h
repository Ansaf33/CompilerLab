#ifndef CHECKER_H
#define CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include "../symbol_table/Gsymbol.h"
#include "../symbol_table/paramlist.h"



// CHECKING IF DECLARED AND DEFINED ARGTYPES ARE SAME

bool checkValidParams(struct paramlist* head,char* name);

// CHECKING IF DECLARED AND DEFINED RETTYPES ARE SAME

bool checkValidRetType(int a,char* name);

// CHECKING IF FUNCTION WAS ALREADY DEFINED BEFORE IT WAS DECLARED

bool checkFunctionDefined(char* name);



#endif
