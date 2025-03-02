%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AST.h"
#include "reghandling.h"
#include "evaluator.h"


struct TreeNode* root;


extern FILE* yyin;

int yylex(void);
void yyerror(char* s);


%}

%union{
  struct TreeNode* node;

}

%type<node> E ASSG INPUT OUTPUT S SL IFST WHILEST
%token BEG ID NUM PLUS MINUS MUL DIV EQUALS LT LTE GT GTE EQ NEQ READ WRITE END IF THEN ELSE ENDIF WHILE DO ENDWHILE
%left EQ NEQ
%left LT LTE GT GTE
%left PLUS MINUS
%left MUL DIV



%%

P :
  BEG SL END ';' {
    root = $2;
    printf("Valid Program.\n");
    Inorder($2);
  }
  |
  BEG END ';' {
  printf("Valid program.\n");
  }
  ;

SL :
   SL S  {
   $$ = createTree(-1,13,-1,"\0",$1,$2);
  }
  |
   S  {
    $$ = $1;
  }
   ;

S :
  ASSG ';'
  |
  INPUT ';'
  |
  OUTPUT ';'
  |
  IFST ';'
  |
  WHILEST ';'
  ;

IFST :
     IF '(' E ')' THEN SL ELSE SL ENDIF {
      $$ = createIfTree(14,$3,$6,$8);
    }
    |
    IF '(' E ')' THEN SL ENDIF {
      $$ = createIfTree(14,$3,$6,NULL);
    }
     ;

WHILEST :
        WHILE '(' E ')' DO SL ENDWHILE {
        $$ = createWhileTree(15,$3,$6);
        }
        ;


ASSG :
  ID EQUALS E {
  $$ = createTree(-1,4,-1,"\0",$<node>1,$3);
  }
  ;

E :
  E PLUS E {
  $$ = createTree(-1,0,0,"\0",$1,$3);
  }
  |
  E MINUS E {
  $$ = createTree(-1,1,0,"\0",$1,$3);
  }
  |
  E MUL E {
  $$ = createTree(-1,2,0,"\0",$1,$3);
  }
  |
  E DIV E {
  $$ = createTree(-1,3,0,"\0",$1,$3);
  }
  |
  E LT E {
  $$ = createTree(-1,5,1,"\0",$1,$3);
  }
  |
  E LTE E {
  $$ = createTree(-1,6,1,"\0",$1,$3);
  }
  |
  E GT E {
  $$ = createTree(-1,7,1,"\0",$1,$3);
  }
  |
  E GTE E {
  $$ = createTree(-1,8,1,"\0",$1,$3);
  }
  |
  E NEQ E {
  $$ = createTree(-1,9,1,"\0",$1,$3);
  }
  |
  E EQ E {
  $$ = createTree(-1,10,1,"\0",$1,$3);
  }
  |
  '(' E ')' {
  $$ = $2;
  }
  |
  NUM {
  $$ = $<node>1;
  }
  |
  ID {
  $$ = $<node>1;
  }
  ;

INPUT :
       READ '(' ID ')' {
       $$ = createTree(-1,11,-1,"\0",$<node>3,NULL);
      }
       ;

OUTPUT :
       WRITE '(' E ')' {
        $$ = createTree(-1,12,-1,"\0",$3,NULL);
      }
       ;




%%









int main(int argc, char* argv[]){

// --------------------------------- PARSING INPUT 
  FILE* f = fopen(argv[1],"r");
  yyin = f;
  yyparse();
  printf("\n");

// --------------------------------- ASSEMBLY CODE

/*
  FILE* xsm = fopen(argv[2],"w");
  fprintf(xsm,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
  //fprintf(xsm,"BRKP\n");
  codeGen(xsm,root);
  fprintf(xsm,"INT 10\n");
*/

// --------------------------------- EXERCISE 1

/*

  printf("RUNNING EXERCISE1\n");
  evaluate(root);
  getDetails();

*/

  return 0;
}

void yyerror(char* s){
  printf("ERROR:%s\n",s);
}
