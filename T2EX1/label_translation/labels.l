%{
#include <stdio.h>
#include <stdlib.h>
#include "table.h"
int run;
int yyerror(void);
extern FILE* yyin;
FILE* f;
// 2056 + 2*(instruction_number-1)

int in;
%} 


%%


[L][0-9]+":""\n" {

  char* label = (char*)malloc(sizeof(char)*3);
  int i = 0;
  while( yytext[i] != ':' ){
    label[i] = yytext[i];
    i++;
  }

  int address = 2056 + 2*(in-8);
  add(label,address);
  in++;
  if( run == 1 ){
      fprintf(f,"JMP %d\n",address+2);
  }
}

[L][0-9]+"\n" {


  char* label = (char*)malloc(sizeof(char)*3);
  int i = 0;
  while( yytext[i] != '\n' ){
    label[i] = yytext[i];
    i++;
  }

  // PRINTING
  if(run == 1 ){
     fprintf(f,"%d\n",getAddress(label));
  }

  in++;

}


[\n] {
  in++;
  if( run == 1 ){
      fprintf(f,"\n");
  }
}


. {
  if( run == 1 ){
      fprintf(f,"%s",yytext);
  }

}

%%

int yywrap(){
  return 1;
}

int main(int argc,char* argv[]){
  in = 1;
  run = 0;
  yyin = fopen(argv[1],"r");
  yylex();
  printTable();

  in = 0;
  f = fopen(argv[2],"w");
  yyin = fopen(argv[1],"r");
  run++;
  yylex();

  return 0;
}

