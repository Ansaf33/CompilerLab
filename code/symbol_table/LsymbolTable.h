#ifndef LSYMBOLTABLE_H
#define LSYMBOLTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "Lsymbol.h"

struct LsymbolTables{

  struct Lsymbol* LsymbolHead;
  struct LsymbolTables* next;

};

struct LsymbolTables* mergeLsymbolTables(struct LsymbolTables* LSThead,struct Lsymbol* LsymbolHead);



#endif
