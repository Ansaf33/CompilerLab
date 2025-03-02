#include <stdio.h>
#include <stdlib.h>

char* optable[21] = {"+","-","*","/","=","<","<=",">",">=","!=","==","READ","WRITE","STATEMENT","IF","WHILE","BREAK","CONTINUE","REPEAT","DO WHILE","RETURN"};


char* map(int i){
  return optable[i];
}
