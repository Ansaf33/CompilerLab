#include <stdio.h>
#include <stdlib.h>

char* optable[14] = {"+","-","*","/","=","<","<=",">",">=","!=","==","READ","WRITE","STATEMENT"};


char* map(int i){
  return optable[i];
}
