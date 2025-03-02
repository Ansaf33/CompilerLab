#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int idx = 0;

char* label[50];
int address[50];


void add(char* l,int a){
  label[idx] = l;
  address[idx] = a;
  idx++;
}

void printTable(){
  for(int i=0;i<idx;i++){
    printf("%s : %d\n",label[i],address[i]);
  }
}

int getAddress(char* l){
  for(int i=0;i<idx;i++){
    //printf("comparing %s and %s\n",label[i],l);
    if( strcmp(label[i],l) == 0 ){
        return address[i];
    }
  }
  return -1;

}





