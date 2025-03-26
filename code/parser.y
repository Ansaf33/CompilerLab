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
#include "typesatisfy/typesatisfy.h"

#include "class/classtable.h"
#include "class/classmember.h"
#include "class/classmethod.h"

#include "inheritance/copier.h"



struct TreeNode* root;
struct classtable* C = NULL;
extern FILE* yyin;
FILE* xsm;

int yylex(void);
void yyerror(char* s);
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
%type<node> INITIALIZE ALLOCATE
%type<node> IFST WHILEST REPEATST DOWHILEST
%type<node> ASSG INPUT OUTPUT
%type<node> E S SL Body
%type<node> FIELD IDENTIFIER CONSTANT ArgList FIELDFUNCTION

%token STRING ID NUM
%token LT LTE GT GTE EQ NEQ REF DEREF
%token PLUS MINUS MUL DIV EQUALS
%token END BEG MAIN DECL ENDDECL BEGINTYPE ENDTYPE BEGINCLASS ENDCLASS
%token NEW DELETE EXTENDS SELF
%token READ WRITE
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE REPEAT UNTIL RETURN
%token INT STR
%token INIT ALLOC FREE NULLVAL

%left EQ NEQ
%left LT LTE GT GTE
%left PLUS MINUS
%left MUL DIV
%right REF DEREF


%%

PROGRAM :
        TypeDefBlock ClassDefBlock GdeclBlock FdefBlock MainBlock
        |
        TypeDefBlock ClassDefBlock GdeclBlock MainBlock
        |
        TypeDefBlock ClassDefBlock MainBlock

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


ClassDefBlock :
              BEGINCLASS ClassDefList ENDCLASS 
              |
              ;

ClassDefList :
             ClassDefList ClassDef
             |
             ClassDef
             ;

ClassDef :
         Cname '{' DECL MemberDeclList MethodDeclList ENDDECL MethodDefList '}' {
         printClass(C);
         }
         ;

Cname :
      ID {
      C = addClassNode($<string>1,NULL);
      }
      |
      ID EXTENDS ID {
      C = addClassNode($<string>1,lookClassUp($<string>3));
      copyMembers(lookClassUp($<string>1),lookClassUp($<string>3));
      copyMethods(lookClassUp($<string>1),lookClassUp($<string>3));
      }
      ;

MemberDeclList :
          MemberDeclList MemberDecl
          |
          MemberDecl
          ;

MemberDecl :
      TYPE ID ';' {
        addMemberToClass(C,lookTTUp($1),lookClassUp($1),$<string>2);
      }

MethodDeclList : 
           MethodDeclList MethodDecl
           |
           MethodDecl
           ;

MethodDecl :
      TYPE ID '(' ParamList ')' ';' { 
        addMethodToClass(C,lookTTUp($1),$<string>2,$4);
        deleteLSymbolTable();
      }
      ;

MethodDefList :
           MethodDefList MethodDef
           |
           MethodDef
           ;

MethodDef :
          TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}' {

          checkDeclDef(C,lookTTUp($1),$<string>2,$4);

          int size = getParamSize($4);
          addSelfToLSymbolTable(C,size);

          getLSymbolTable();

          define_method_codeGen(xsm,C,$<string>2,$4,$8);

          deleteLSymbolTable();
          }
          ;


GdeclBlock :
             DECL GdeclList ENDDECL{
                C = NULL;
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
          if( !lookGUp("main") ){
              addGSymbol("main",lookTTUp("int"),NULL,1,1,NULL,1,0,0,0); 
          }
          addAllGSymbols($2,lookTTUp($1),lookClassUp($1));
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
          deleteLSymbolTable();
        }
        |
        GidList ',' MUL ID {
          $$ = addPointer($1,$<string>4);
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
        |
        MUL ID {
          $$ = addPointer(NULL,$<string>2);
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
  |
  FREE '(' FIELD ')' ';' {
    $<node>$ = createFreeNode($3);
  }
  |
  DELETE '(' IDENTIFIER ')' ';' {
    $<node>$ = createDeleteNode($3);
  }
  |
  DELETE '(' FIELD ')' ';' {
    $<node>$ = createDeleteNode($3);
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
  |
  FIELD EQUALS ALLOCATE {
  $3->type = lookTTUp(getName($1));
  $$ = createOpNode(NULL,4,$1,$3);
  }
  |
  IDENTIFIER EQUALS NEW '(' ID ')' {
  struct TreeNode* RHS = createNewNode($<string>5);
  $$ = createOpNode(NULL,4,$1,RHS);
  }
  |
  FIELD EQUALS NEW '(' ID ')' {
  struct TreeNode* RHS = createNewNode($<string>5);
  $$ = createOpNode(NULL,4,$1,RHS);
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
  |
  FIELDFUNCTION
  ;

IDENTIFIER : 
           ID { 
            $$ = createIdNode($<string>1,NULL,NULL);
           }
           |
           MUL E %prec DEREF {
            $$ = createOpNode(lookTTUp("int"),27,$2,NULL);
           }
           |
           REF IDENTIFIER {
           $$ = createOpNode(lookTTUp("ptr"),26,$2,NULL);
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
      |
      SELF '.' ID {
      $$ = createSelfNode(C,$<string>3,NULL);
      }
      ;

FIELDFUNCTION :
              SELF '.' ID '(' ArgList ')' {
              $$ = createSelfNode(C,$<string>3,$5);
              }
              |
              ID '.' ID '(' ArgList ')' {
              $$ = createIdNode($<string>1,NULL,NULL);
              $$ = addMethodToEnd($$,$<string>3,$5);
              }
              |
              FIELD '.' ID '(' ArgList ')' {
              $$ = addMethodToEnd($1,$<string>3,$5);
              }
              |
              SELF '.' ID '(' ')' {
              $$ = createSelfNode(C,$<string>3,NULL);
              }
              |
              ID '.' ID '(' ')' {
              $$ = createIdNode($<string>1,NULL,NULL);
              $$ = addMethodToEnd($$,$<string>3,NULL);
              }
              |
              FIELD '.' ID '(' ')' {
                $$ = addMethodToEnd($1,$<string>3,NULL);
              }
              ;

ArgList :
        ArgList ',' E {
        $$ = addArgToList($1,$3);
        }
        |
        E
        {
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
      |
      READ '(' FIELD ')' {
      $$ = createOpNode(NULL,11,$3,NULL);
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
  fprintf(xsm,"BRKP\n");
}

void endxsm(FILE* f){
          fprintf(xsm,"JMP L51\n"); 

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
          getInput(xsm,"Completed");
          fprintf(xsm,"INT 10\n");

}
