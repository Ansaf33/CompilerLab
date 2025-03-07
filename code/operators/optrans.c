#include <stdio.h>
#include <stdlib.h>

char* optable[28] = {"+","-","*","/","=","<","<=",">",">=","!=","==","READ","WRITE","STATEMENT","IF","WHILE","BREAK","CONTINUE","REPEAT","DO WHILE","RETURN","INITIALIZE()","alloc()","free()","delete()","new()","&","DRF*"};


char* map(int i){
  return optable[i];
}
