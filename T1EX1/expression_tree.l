%{
#include <stdio.h>
#include <stdlib.h>
#include "tree_generator.h"
#include "y.tab.h"

%}  


%%




[0-9]+ {
  yylval.node = makeLeafNode(atoi(yytext));
  return NUM;
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
[\n] {
  return yytext[0];
}

[ \t] ;

. {
  return yytext[0];
}




%%


int yywrap(){
    return 1;
} 
