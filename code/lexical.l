%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "AST.h"


%}




%%

[0-9]+ {
  yylval.string = (char*)malloc(sizeof(char)*16);
  strcpy(yylval.string,yytext);
  return NUM;
}

"initialize" {
  return INIT;
}

"alloc" {
  return ALLOC;
}

"free" {
  return FREE;
}

"null" {
  return NULLVAL;
}

"class" {
  return BEGINCLASS;
}

"self" {
  return SELF;
}

"extends" {
  return EXTENDS;
}

"new" {
  return NEW;
}

"delete" {
  return DELETE;
}

"endclass" {
  return ENDCLASS;
}

"type" {
  return BEGINTYPE;
}

"endtype" {
  return ENDTYPE;
}

"decl" {
  return DECL;
}

"enddecl" {
  return ENDDECL;
}

"int" {
  yylval.string = "int";
  return INT;
}

"str" {
  yylval.string = "str";
  return STR;
}

"main" {
  return MAIN;
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
  return IF;
}

"then" {
  return THEN;
}

"else" {
  return ELSE;
}

"endif" {
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

"break" {
  return BREAK;
}

"continue" {
  return CONTINUE;
}

"repeat" {
  return REPEAT;
}

"until" {
  return UNTIL;
}

"return" {
  return RETURN;
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

[a-zA-Z][a-zA-Z0-9]* {

  yylval.string = (char*)malloc(sizeof(char)*100);
  strcpy(yylval.string,yytext);


  return ID;
}

["][a-zA-Z0-9_ !@#$%^&*()]*["] {
  yylval.string = (char*)malloc(sizeof(char)*100);
  strcpy(yylval.string,yytext);

  return STRING;
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
