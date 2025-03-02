#include <stdio.h>
#include <stdlib.h>
#include "Lsymbol.h"
#include "LsymbolTable.h"

struct LsymbolTables* mergeLsymbolTables(struct LsymbolTables* LSThead, struct Lsymbol* LsymbolHead){

  struct LsymbolTables* temp = (struct LsymbolTables*)malloc(sizeof(struct LsymbolTables));
  temp->LsymbolHead = LsymbolHead;

  temp->next = LSThead;
  LSThead = temp;

  return LSThead;
}



