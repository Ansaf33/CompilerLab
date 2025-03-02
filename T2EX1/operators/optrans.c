#include <stdio.h>
#include <stdlib.h>

char* optable[16] = {"+","-","*","/","=","<","<=",">",">=","!=","==","READ","WRITE","STATEMENT","IF","WHILE"};


char* map(int i){
  return optable[i];
}
