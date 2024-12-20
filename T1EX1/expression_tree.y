%{
#include <stdio.h>
#include <stdlib.h>
#include "reghandling.h"
#include "tree_generator.h"

extern FILE* yyin;
void yyerror(char* s);
int yylex(void);

struct TreeNode* root;

%}

%union{
  struct TreeNode* node;
  int integer;
}

%type<node> E
%token NUM PLUS MINUS MUL DIV
%left PLUS MINUS
%left MUL DIV


%%

S : E '\n'{
      root = $1;
      printf("Postorder Traversal : ");
      Postorder($1);
      printf("\n");
      printf("Preorder Traversal : ");
      Preorder($1);
      printf("\n");
      return 0;
    }
    |
    '\n' {
      printf("Invalid Expression.");
      return 1;
    }
    ;

E : E PLUS E {
      //printf("+ ");
      $$ = makeOperatorNode('+',$1,$3);
    }
    |
    E MINUS E {
      //printf("- ");
      $$ = makeOperatorNode('-',$1,$3);
    }
    |
    E MUL E {
      //printf("* ");
      $$ = makeOperatorNode('*',$1,$3);
    }
    |
    E DIV E {
      if( $3 == 0 ){
        printf("Division by 0.\n");
        exit(1);
      }
      //printf("/ ");
      $$ = makeOperatorNode('/',$1,$3);
    }
    |
    '(' E ')' {
      $$ = $2;
    }
    |
    NUM {
      //printf("Number ");
      $$ = makeLeafNode($<integer>1);
    }
    ;




%%

int main(int argc, char* argv[]){
  FILE* fp = fopen(argv[1], "r");
  yyin = fp;
  yyparse();

  FILE* xsmfile = fopen(argv[2],"w");
    
  // INCLUDE HEADERS
  fprintf(xsmfile,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);

  int indexOfEvaluated = codeGen(xsmfile,root);
  printf("Register with final value : %d\n",indexOfEvaluated);

  // NOW I NEED TO WRITE ASSEMBLY CODE TO PRINT THE CONTENTS OF THE REGISTER USING THE WRITE SYSTEM CALL IN LIBRARY.LIB
  fprintf(xsmfile,"BRKP\n");
  fprintf(xsmfile,"MOV SP, 4095\n");
  fprintf(xsmfile,"MOV R15, \"write\"\n");
  fprintf(xsmfile,"PUSH R15\n");
  fprintf(xsmfile,"MOV R16, -2\n");
  fprintf(xsmfile,"PUSH R16\n");
  fprintf(xsmfile,"PUSH R%d\n",indexOfEvaluated);
  fprintf(xsmfile,"PUSH R0\n");
  fprintf(xsmfile,"PUSH R0\n");
  fprintf(xsmfile,"CALL 0\n");
  fprintf(xsmfile,"POP R1\n");
  fprintf(xsmfile,"POP R0\n");
  fprintf(xsmfile,"POP R0\n");
  fprintf(xsmfile,"POP R0\n");
  fprintf(xsmfile,"POP R0");


  return 1;

}



void yyerror(char* s){
  printf("ERROR:%s\n",s);
}
