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
    REF = 267,                     /* REF  */
    DEREF = 268,                   /* DEREF  */
    PLUS = 269,                    /* PLUS  */
    MINUS = 270,                   /* MINUS  */
    MUL = 271,                     /* MUL  */
    DIV = 272,                     /* DIV  */
    EQUALS = 273,                  /* EQUALS  */
    END = 274,                     /* END  */
    BEG = 275,                     /* BEG  */
    MAIN = 276,                    /* MAIN  */
    DECL = 277,                    /* DECL  */
    ENDDECL = 278,                 /* ENDDECL  */
    BEGINTYPE = 279,               /* BEGINTYPE  */
    ENDTYPE = 280,                 /* ENDTYPE  */
    BEGINCLASS = 281,              /* BEGINCLASS  */
    ENDCLASS = 282,                /* ENDCLASS  */
    NEW = 283,                     /* NEW  */
    DELETE = 284,                  /* DELETE  */
    EXTENDS = 285,                 /* EXTENDS  */
    SELF = 286,                    /* SELF  */
    READ = 287,                    /* READ  */
    WRITE = 288,                   /* WRITE  */
    IF = 289,                      /* IF  */
    THEN = 290,                    /* THEN  */
    ELSE = 291,                    /* ELSE  */
    ENDIF = 292,                   /* ENDIF  */
    WHILE = 293,                   /* WHILE  */
    DO = 294,                      /* DO  */
    ENDWHILE = 295,                /* ENDWHILE  */
    BREAK = 296,                   /* BREAK  */
    CONTINUE = 297,                /* CONTINUE  */
    REPEAT = 298,                  /* REPEAT  */
    UNTIL = 299,                   /* UNTIL  */
    RETURN = 300,                  /* RETURN  */
    INT = 301,                     /* INT  */
    STR = 302,                     /* STR  */
    INIT = 303,                    /* INIT  */
    ALLOC = 304,                   /* ALLOC  */
    FREE = 305,                    /* FREE  */
    NULLVAL = 306                  /* NULLVAL  */
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
#define REF 267
#define DEREF 268
#define PLUS 269
#define MINUS 270
#define MUL 271
#define DIV 272
#define EQUALS 273
#define END 274
#define BEG 275
#define MAIN 276
#define DECL 277
#define ENDDECL 278
#define BEGINTYPE 279
#define ENDTYPE 280
#define BEGINCLASS 281
#define ENDCLASS 282
#define NEW 283
#define DELETE 284
#define EXTENDS 285
#define SELF 286
#define READ 287
#define WRITE 288
#define IF 289
#define THEN 290
#define ELSE 291
#define ENDIF 292
#define WHILE 293
#define DO 294
#define ENDWHILE 295
#define BREAK 296
#define CONTINUE 297
#define REPEAT 298
#define UNTIL 299
#define RETURN 300
#define INT 301
#define STR 302
#define INIT 303
#define ALLOC 304
#define FREE 305
#define NULLVAL 306

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

#line 180 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
