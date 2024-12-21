%{
#include <stdio.h>
#include <stdlib.h>
#include "AST.h"


extern FILE* yyin;

int yylex(void);
void yyerror(char* s);


%}

%union{
  struct TreeNode* node;

}

%type<node> E ASSG INPUT OUTPUT S SL ID NUM
%token PLUS MINUS MUL DIV NUM ID BEG END EQUALS READ WRITE
%left PLUS MINUS
%left MUL DIV



%%

P :
  BEG '\n' SL END ';' '\n'{
    printf("Valid Program.\n");
    Inorder($3);
  }
  |
  BEG END ';' '\n' {
  printf("Valid program.\n");
  }
  ;

SL :
   SL S '\n' {
   $$ = createTree(-1,'S',-1,NULL,$1,$2);
  }
  |
   S '\n' {
    $$ = $1;
  }
   ;

S :
  ASSG ';'
  |
  INPUT ';'
  |
  OUTPUT ';'
  ;

ASSG :
  ID EQUALS E {
  $$ = createTree(-1,'=',-1,NULL,$1,$3);
  }
  ;

E :
  E PLUS E {
  $$ = createTree(-1,'+',-1,NULL,$1,$3);
  }
  |
  E MINUS E {
  $$ = createTree(-1,'-',-1,NULL,$1,$3);
  }
  |
  E MUL E {
  $$ = createTree(-1,'*',-1,NULL,$1,$3);
  }
  |
  E DIV E {
  $$ = createTree(-1,'/',-1,NULL,$1,$3);
  }
  |
  '(' E ')' {
  $$ = $2;
  }
  |
  NUM {
  $$ = $1;
  }
  |
  ID {
  $$ = $1;
  }
  ;

INPUT :
       READ '(' ID ')' {
       $$ = createTree(-1,'R',-1,NULL,$3,NULL);
      }
       ;

OUTPUT :
       WRITE '(' E ')' {
        $$ = createTree(-1,'W',-1,NULL,$3,NULL);
      }
       ;




%%









int main(){
  FILE* f = fopen("sample.txt","r");
  yyin = f;
  yyparse();

  return 1;
}

void yyerror(char* s){
  printf("ERROR:%s\n",s);
}
