#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "checker.h"
#include "../symbol_table/Gsymbol.h"
#include "../symbol_table/paramlist.h"

// ---------------------- CHECK IF DECLARED AND DEFINED PARAMETERS ARE THE SAME

bool checkValidParams(struct paramlist* param,char* name){

  // CHECKING IF PARAMETERS ARE THE SAME

  struct paramlist* p = param;
  struct paramlist* s = lookGUp(name)->param;

  while( p && s ){
    if( p->type != s->type  ){
      printf("Declared and defined parameter types don't match.\n");
      exit(1);
    }
    if( strcmp(p->name,s->name) != 0 ){
      printf("Declared and defined parameter names don't match.\n");
      exit(1);

    }
    p = p->next;
    s = s->next;
  }

  if ( p || s ){
    printf("Sizes of declared and defined parameters don't match.\n");
    exit(1);

  }

  return true;

}

// --------------------- CHECK IF DECLARED AND DEFINED RETURN TYPES ARE THE SAME

bool checkValidRetType(int declaredType,char* name){
  int definedType = lookGUp(name)->type;
  if(declaredType!=definedType){
    printf("Ret type of declared and defined function do not match.\n");
    exit(1);
  }
  return true;
}

// --------------------- CHECK IF DECLARED FUNCTION WAS DEFINED

bool checkFunctionDefined(char* name){
  if( lookGUp(name) == NULL ){
    printf("Function is not defined.\n");
    exit(1);
  }
  return true;
}
