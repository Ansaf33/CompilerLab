%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "AST.h"
#include "reghandling.h"

#include "symbol_table/Gsymbol.h"
#include "symbol_table/varList.h"
#include "symbol_table/paramlist.h"
#include "symbol_table/Lsymbol.h"

#include "functions/checker.h"

#include "user_defined_type/fieldlist.h"
#include "typetable/typetable.h"



struct TreeNode* root;


extern FILE* yyin;

int yylex(void);
void yyerror(char* s);
FILE* xsm;


%}

%union{
  struct TreeNode* node;
  char* string;
  int integer;
  struct list* list;
  struct paramlist* paramlist;
  struct Lsymbol* Lsymbol;
  struct typetable* typetable;


}

%type<paramlist>ParamList
%type<list> GidList LidList
%type<typetable> TYPE
%type<node> E ASSG INPUT OUTPUT S SL IFST WHILEST REPEATST DOWHILEST IDENTIFIER CONSTANT ArgList Body
%token STRING ID NUM PLUS MINUS MUL DIV EQUALS 
%token LT LTE GT GTE EQ NEQ 
%token READ WRITE END BEG 
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE REPEAT UNTIL RETURN MAIN
%token DECL ENDDECL INT STR
%left EQ NEQ
%left LT LTE GT GTE
%left PLUS MINUS
%left MUL DIV



%%

PROGRAM :
        GdeclBlock FdefBlock MainBlock
        |
        GdeclBlock MainBlock
        |
        MainBlock


GdeclBlock :
             DECL GdeclList ENDDECL{
                printf("All Global Declarations parsed.\n");
                getGSymbolTable();
              }
             |
             DECL ENDDECL
             ;

GdeclList :
        GdeclList Gdecl
        |
        Gdecl
        ;

Gdecl :
     TYPE GidList ';' {
          addAllGSymbols($2,$1);
     }
     ;

TYPE :
     INT {
     $$ = $<typetable>1;
     }
     |
     STR {
     $$ = $<typetable>1;
     }
     ;

GidList :
        GidList ',' ID {
          $$ = addVariable($1,$<string>3);
        }
        |
        GidList ',' ID '[' NUM ']' {
          $$ = addArray($1,$<string>3,1,atoi($<string>5));
        }
        |
        GidList ',' ID '[' NUM ']' '[' NUM ']' {
          $$ = addArray($1,$<string>1,atoi($<string>5),atoi($<string>8));
        }
        |
        GidList ',' ID '(' ParamList ')' {
          $$ = addFunction($1,$<string>3,$5);
        }
        |
        ID {
          $$ = addVariable(NULL,$<string>1);
        }
        |
        ID '[' NUM ']' {
          $$ = addArray(NULL,$<string>1,1,atoi($<string>3));
        }
        |
        ID '[' NUM ']' '[' NUM ']' {
          $$ = addArray(NULL,$<string>1,atoi($<string>3),atoi($<string>6));
        }
        |
        ID '(' ParamList ')' { 
          $$ = addFunction(NULL,$<string>1,$3);
          deleteLSymbolTable();
        }
        ;

FdefBlock :
          FdefBlock Fdef 
          |
          Fdef
          ;

Fdef :
     TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}' {
     printf("|| ------------------------- FUNCTION : %s ---------------------- ||\n\n",$<string>2);

     // --------------------------------------- CHECKING FUNCTION REQUIREMENTS ---------------------------------------------
     // PRINT THE PARAMETERS
     printParameters($4);
     // PRINT THE LOCAL SYMBOL TABLE
     getLSymbolTable();
     // CHECK IF FUNCTION IS DECLARED
     checkFunctionDeclared($<string>2);
     // CHECK IF DEFINED PARAMETERS ARE VALID (in paramlist) to DECLARED PARAMETERS (in symboltable->param) (NAME AND TYPE)
     checkValidParams($4,$<string>2);
     // CHECK IF RETURN TYPES OF DECLARED AND DEFINED FUNCTIONS ARE VALID
     checkValidRetType($1,$<string>2);
     // ---------------------------------------- CHECKING DONE --------------------------------------------------------------

     // GENERATE CODE FOR THE FUNCTION ( PASS IN THE NAME OF FUNCTION, AND ROOT OF TREE )
  
     define_function_codeGen(xsm,$<string>2,$8);

     deleteLSymbolTable();

     }

     ;

ParamList :
          ParamList ',' TYPE ID {
           $$ = addParameter($1,$<string>4,$3);
           addLastParamToLSymbolTable($$);
          }
          |
          TYPE ID {
           $$ = addParameter(NULL,$<string>2,$1);
           addLastParamToLSymbolTable($$);
          }
          |
           {
           $$ = NULL;
          }

          ;

LdeclBlock :
           DECL LdeclList ENDDECL {
           }
           |
           DECL ENDDECL
           ;

LdeclList :
          LdeclList Ldecl
          |
          Ldecl
          ;

Ldecl :
      TYPE LidList ';' {
         addAllLSymbols($2,$1);
      }

LidList : 
        LidList ',' ID {
        $$ = addVariable($1,$<string>3);
        }
        |
        ID {
        $$ = addVariable(NULL,$<string>1);
        }
        ;


MainBlock :
          INT MAIN '(' ')' '{' LdeclBlock Body '}' {
          printf("|| ------------------------- FUNCTION : Main ---------------------- ||\n\n");
 
          // GETTING LOCAL SYMBOL TABLE
          getLSymbolTable();
    
          define_function_codeGen(xsm,"main",$7);

          fprintf(xsm,"JMP L51\n");

          // OVERFLOW CONDITION
          fprintf(xsm,"L50:\n");
          getInput(xsm,"Overflow");
          fprintf(xsm,"INT 10\n");

          // END
          fprintf(xsm,"L51:\n");
          fprintf(xsm,"INT 10\n");

          deleteLSymbolTable();


          }


Body :
  BEG SL END ';' {
    $$ = $2;
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
   $$ = createOpNode(NULL,13,$1,$2);
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
  |
  REPEATST ';'
  |
  DOWHILEST ';'
  |
  BREAK ';' {
    $<node>$ = createOpNode(NULL,16,NULL,NULL);
  }
  |
  CONTINUE ';' {
    $<node>$ = createOpNode(NULL,17,NULL,NULL);
  }
  |
  RETURN E ';' {
    $<node>$ = createReturnNode($2);
  }
  ;

IFST :
     IF '(' E ')' THEN SL ELSE SL ENDIF {
      $$ = createIfNode($3,$6,$8);
    }
    |
    IF '(' E ')' THEN SL ENDIF {
      $$ = createIfNode($3,$6,NULL);
    }
     ;

WHILEST :
        WHILE '(' E ')' DO SL ENDWHILE {
        $$ = createWhileNode(15,$3,$6);
        }
        ;

REPEATST :
         REPEAT SL UNTIL '(' E ')' {
         $$ = createWhileNode(18,$5,$2);
        }
        ;

DOWHILEST :
          DO SL WHILE '(' E ')' { 
          $$ = createWhileNode(19,$5,$2);
          }
          ;


ASSG :
  IDENTIFIER EQUALS E {
  $$ = createOpNode(NULL,4,$<node>1,$3);
  }
  ;

E :
  E PLUS E {
  $$ = createOpNode(lookTTUp("int"),0,$1,$3);
  }
  |
  E MINUS E {
  $$ = createOpNode(lookTTUp("int"),1,$1,$3);
  }
  |
  E MUL E {
  $$ = createOpNode(lookTTUp("int"),2,$1,$3);
  }
  |
  E DIV E {
  $$ = createOpNode(lookTTUp("int"),3,$1,$3);
  }
  |
  E LT E {
  $$ = createOpNode(lookTTUp("bool"),5,$1,$3);
  }
  |
  E LTE E {
  $$ = createOpNode(lookTTUp("bool"),6,$1,$3);
  }
  |
  E GT E {
  $$ = createOpNode(lookTTUp("bool"),7,$1,$3);
  }
  |
  E GTE E {
  $$ = createOpNode(lookTTUp("bool"),8,$1,$3);
  }
  |
  E NEQ E {
  $$ = createOpNode(lookTTUp("bool"),9,$1,$3);
  }
  |
  E EQ E {
  $$ = createOpNode(lookTTUp("bool"),10,$1,$3);
  }
  |
  '(' E ')' {
  $$ = $2;
  }
  |
  CONSTANT
  |
  IDENTIFIER
  ;

IDENTIFIER : 
           ID { 
            $$ = createIdNode($<string>1,NULL,NULL);
           }
           |
           ID '[' E ']' {
            $$ = createIdNode($<string>1,NULL,$3);
            }
            |
           ID '[' E ']' '[' E ']' {
            $$ = createIdNode($<string>1,$3,$6);
            }
            |
            ID '(' ')' {
            $$ = createFunctionNode($<string>1,NULL);
            }
            |
            ID '(' ArgList ')' { 
            $$ = createFunctionNode($<string>1,$3);
            }
            ;

ArgList :
        ArgList ','  E {
        $$ = addArgToList($1,$3);
        }
        |
        E {
        $$ = $1;
        }
        ;


CONSTANT :
         NUM {
          $$ = createNumNode(atoi($<string>1));
          }
          |
         STRING {
          $$ = createStringNode($<string>1);
          }
          ;
        

INPUT :
       READ '(' IDENTIFIER ')' {
       $$ = createOpNode(NULL,11,$<node>3,NULL);
      }
       ;

OUTPUT :
       WRITE '(' E ')' {
        $$ = createOpNode(NULL,12,$3,NULL);
      }
       ;



%%


int main(int argc, char* argv[]){

  //SOME INITIAL STUFF
  createPrimitive();

  FILE* f = fopen(argv[1],"r");
  yyin = f;

  addGSymbol("main",lookTTUp("int"),0,0,NULL,1);


  printTT();


  xsm = fopen("assembly_code.xsm","w");
  fprintf(xsm,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
  //fprintf(xsm,"BRKP\n");
  fprintf(xsm,"MOV SP, 4500\n");
  fprintf(xsm,"MOV BP, SP\n");
  fprintf(xsm,"JMP F0\n"); 
  yyparse();


  return 0;
}

void yyerror(char* s){
  printf("ERROR:%s\n",s);
}

