%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "AST.h"
%}





%%

[0-9]+ {
  yylval.node = createTree(atoi(yytext),-1,0,"\0",NULL,NULL);
  return NUM;
}

"begin" {
  return BEG;
}

"end" {
  return END;
}

"read" {
  return READ;
}

"write" {
  return WRITE;
}

"if" {
  printf("if detected\n");
  return IF;
}

"then" {
  return THEN;
}

"else" {
  return ELSE;
}

"endif" {
  printf("endif detected\n");
  return ENDIF;
}

"while" {
  return WHILE;
}

"do" {
  return DO;
}

"endwhile" {
  return ENDWHILE;
}


[+] {

  return PLUS;
}

[-] {
  return MINUS;
}

[*] {
  return MUL;
}

[/] {
  return DIV;
}

[=] {
  return EQUALS;
}

[<] {
  return LT;
}

"<=" {
  return LTE;
}

[>] {
  return GT;
}

">=" {
  return GTE;
}

"==" {
  return EQ;
}

"!=" {
  return NEQ;
}

[a-z] {
  yylval.node = createTree(-1,-1,0,yytext,NULL,NULL);
  return ID;
}

[ \t] ;


[(] {
  return '(';
}
[)] {
  return ')';
}
[;] {
  return ';';
}
. {
  return yytext[0];
}


%%


int yywrap(){
  return 1;
}
