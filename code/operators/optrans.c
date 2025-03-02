#include <stdio.h>
#include <stdlib.h>

char* optable[24] = {"+","-","*","/","=","<","<=",">",">=","!=","==","READ","WRITE","STATEMENT","IF","WHILE","BREAK","CONTINUE","REPEAT","DO WHILE","RETURN","INITIALIZE()","alloc()","free()"};


char* map(int i){
  return optable[i];
}
