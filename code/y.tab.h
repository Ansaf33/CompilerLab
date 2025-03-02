/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRING = 258,                  /* STRING  */
    ID = 259,                      /* ID  */
    NUM = 260,                     /* NUM  */
    LT = 261,                      /* LT  */
    LTE = 262,                     /* LTE  */
    GT = 263,                      /* GT  */
    GTE = 264,                     /* GTE  */
    EQ = 265,                      /* EQ  */
    NEQ = 266,                     /* NEQ  */
    PLUS = 267,                    /* PLUS  */
    MINUS = 268,                   /* MINUS  */
    MUL = 269,                     /* MUL  */
    DIV = 270,                     /* DIV  */
    EQUALS = 271,                  /* EQUALS  */
    END = 272,                     /* END  */
    BEG = 273,                     /* BEG  */
    MAIN = 274,                    /* MAIN  */
    DECL = 275,                    /* DECL  */
    ENDDECL = 276,                 /* ENDDECL  */
    BEGINTYPE = 277,               /* BEGINTYPE  */
    ENDTYPE = 278,                 /* ENDTYPE  */
    BEGINCLASS = 279,              /* BEGINCLASS  */
    ENDCLASS = 280,                /* ENDCLASS  */
    NEW = 281,                     /* NEW  */
    DELETE = 282,                  /* DELETE  */
    EXTENDS = 283,                 /* EXTENDS  */
    READ = 284,                    /* READ  */
    WRITE = 285,                   /* WRITE  */
    IF = 286,                      /* IF  */
    THEN = 287,                    /* THEN  */
    ELSE = 288,                    /* ELSE  */
    ENDIF = 289,                   /* ENDIF  */
    WHILE = 290,                   /* WHILE  */
    DO = 291,                      /* DO  */
    ENDWHILE = 292,                /* ENDWHILE  */
    BREAK = 293,                   /* BREAK  */
    CONTINUE = 294,                /* CONTINUE  */
    REPEAT = 295,                  /* REPEAT  */
    UNTIL = 296,                   /* UNTIL  */
    RETURN = 297,                  /* RETURN  */
    INT = 298,                     /* INT  */
    STR = 299,                     /* STR  */
    INIT = 300,                    /* INIT  */
    ALLOC = 301,                   /* ALLOC  */
    FREE = 302,                    /* FREE  */
    NULLVAL = 303                  /* NULLVAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define STRING 258
#define ID 259
#define NUM 260
#define LT 261
#define LTE 262
#define GT 263
#define GTE 264
#define EQ 265
#define NEQ 266
#define PLUS 267
#define MINUS 268
#define MUL 269
#define DIV 270
#define EQUALS 271
#define END 272
#define BEG 273
#define MAIN 274
#define DECL 275
#define ENDDECL 276
#define BEGINTYPE 277
#define ENDTYPE 278
#define BEGINCLASS 279
#define ENDCLASS 280
#define NEW 281
#define DELETE 282
#define EXTENDS 283
#define READ 284
#define WRITE 285
#define IF 286
#define THEN 287
#define ELSE 288
#define ENDIF 289
#define WHILE 290
#define DO 291
#define ENDWHILE 292
#define BREAK 293
#define CONTINUE 294
#define REPEAT 295
#define UNTIL 296
#define RETURN 297
#define INT 298
#define STR 299
#define INIT 300
#define ALLOC 301
#define FREE 302
#define NULLVAL 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "parser.y"

  struct TreeNode* node;
  char* string;
  int integer;
  struct list* list;
  struct paramlist* paramlist;
  struct Lsymbol* Lsymbol;
  struct typetable* typetable;
  struct fieldlist* fieldlist;



#line 176 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
