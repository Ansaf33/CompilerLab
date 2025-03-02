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

#include "udt/fieldlist.h"
#include "typetable/typetable.h"



struct TreeNode* root;


extern FILE* yyin;

int yylex(void);
void yyerror(char* s);
FILE* xsm;

void initxsm(FILE* f);
void endxsm(FILE* f);


%}

%union{
  struct TreeNode* node;
  char* string;
  int integer;
  struct list* list;
  struct paramlist* paramlist;
  struct Lsymbol* Lsymbol;
  struct typetable* typetable;
  struct fieldlist* fieldlist;


}

%type<fieldlist> FieldDeclList
%type<paramlist>ParamList
%type<list> GidList LidList
%type<string> TYPE
%type<node> E ASSG INPUT OUTPUT S SL IFST WHILEST REPEATST DOWHILEST FIELD IDENTIFIER CONSTANT ArgList Body INITIALIZE ALLOCATE
%token STRING ID NUM PLUS MINUS MUL DIV EQUALS 
%token LT LTE GT GTE EQ NEQ 
%token READ WRITE END BEG 
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE REPEAT UNTIL RETURN MAIN
%token DECL ENDDECL INT STR BEGINTYPE ENDTYPE
%token INIT ALLOC FREE NULLVAL
%left EQ NEQ
%left LT LTE GT GTE
%left PLUS MINUS
%left MUL DIV



%%

PROGRAM :
        TypeDefBlock GdeclBlock FdefBlock MainBlock
        |
        TypeDefBlock GdeclBlock MainBlock
        |
        TypeDefBlock MainBlock

TypeDefBlock :
             BEGINTYPE TypeDefList ENDTYPE{
             printf("All Type definitions parsed.\n");
             printTT();
             }
             | 
             {
             printf("No Type definitions present\n");
             printTT();
             }
             ;

TypeDefList :
            TypeDefList TypeDef
            |
            TypeDef
            ;

TypeDef :
        ID '{' FieldDeclList '}' {
         addTTNode($<string>1,getFLSize($3),$3);
         addTypes($3);
        }
        ;

FieldDeclList :
              FieldDeclList TYPE ID ';' {
              $$ = addFLNode($1,$<string>3,$2);
              }
              |
              TYPE ID ';' {
              $$ = addFLNode(NULL,$<string>2,$1);
              }
              ;

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
          addAllGSymbols($2,lookTTUp($1));
     }
     ;

TYPE :
     INT {
     $$ = $<string>1;
     }
     |
     STR {
     $$ = $<string>1;
     }
     |
     ID {
     $$ = $<string>1;  
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
     printf("|| ------------------------- F U N C T I O N : %s ---------------------- ||\n\n",$<string>2);

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
     checkValidRetType(lookTTUp($1),$<string>2);
     // ---------------------------------------- CHECKING DONE --------------------------------------------------------------

 
     define_function_codeGen(xsm,$<string>2,$8);

     deleteLSymbolTable();
     }

     ;

ParamList :
          ParamList ',' TYPE ID {
           $$ = addParameter($1,$<string>4,lookTTUp($3));
           addLastParamToLSymbolTable($$);
          }
          |
          TYPE ID {
           $$ = addParameter(NULL,$<string>2,lookTTUp($1));
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
         addAllLSymbols($2,lookTTUp($1));
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
          printf("|| ------------------------- F U N C T I O N : Main ---------------------- ||\n\n");
 
          // GETTING LOCAL SYMBOL TABLE
          getLSymbolTable();

          // DEFINING THE FUNCTION
          define_function_codeGen(xsm,"main",$7);

          // ENDING LABELS
          endxsm(xsm);

          // DELETING LOCAL SYMBOL TABLE OF MAINN
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
  |
  FREE '(' IDENTIFIER ')' ';' {
    $<node>$ = createFreeNode($3);
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
  |
  FIELD EQUALS E {
  $$ = createOpNode(NULL,4,$1,$3);
  }
  |
  IDENTIFIER EQUALS INITIALIZE {
  $$ = createOpNode(NULL,4,$1,$3);
  }
  |
  IDENTIFIER EQUALS ALLOCATE {
  $3->type = $1->type;
  $$ = createOpNode(NULL,4,$1,$3);
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
  |
  FIELD
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

FIELD :
      FIELD '.' ID {
      $$ = addFieldToEnd($1,$<string>3);
      }
      |
      ID '.' ID {
      $$ = createIdNode($<string>1,NULL,NULL);
      $$ = addFieldToEnd($$,$<string>3);
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
          |
         NULLVAL {
          $$ = createNullNode();
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

INITIALIZE :
           INIT '(' ')' {
           $$ = createOpNode(lookTTUp("int"),21,NULL,NULL);
           }
           ;

ALLOCATE :
         ALLOC '(' ')' {
         $$ = createOpNode(lookTTUp("int"),22,NULL,NULL);
         }
         ;

%%


int main(int argc, char* argv[]){

  //SOME INITIAL STUFF
  createPrimitive();
  addGSymbol("main",lookTTUp("int"),1,1,NULL,1);

  FILE* f = fopen(argv[1],"r");
  yyin = f;

  xsm = fopen("assembly_code.xsm","w");

  initxsm(xsm);

  yyparse();


  return 0;
}

void yyerror(char* s){
  printf("ERROR:%s\n",s);
}

void initxsm(FILE* f){
  fprintf(xsm,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
  fprintf(xsm,"BRKP\n");
  fprintf(xsm,"MOV SP, 4500\n");
  fprintf(xsm,"MOV BP, SP\n");
  fprintf(xsm,"JMP F0\n"); 
}

void endxsm(FILE* f){
          fprintf(xsm,"JMP L51\n");

          // ALREADY FREED SPACE




          // NO MEMORY ALLOCATED
          fprintf(xsm,"L52:\n");
          getInput(xsm,"Not Allocated");
          fprintf(xsm,"INT 10\n");

          // OVERFLOW CONDITION
          fprintf(xsm,"L50:\n");
          getInput(xsm,"Overflow");
          fprintf(xsm,"INT 10\n");

          // END
          fprintf(xsm,"L51:\n");
          fprintf(xsm,"INT 10\n");




}
