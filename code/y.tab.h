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
    SELF = 284,                    /* SELF  */
    READ = 285,                    /* READ  */
    WRITE = 286,                   /* WRITE  */
    IF = 287,                      /* IF  */
    THEN = 288,                    /* THEN  */
    ELSE = 289,                    /* ELSE  */
    ENDIF = 290,                   /* ENDIF  */
    WHILE = 291,                   /* WHILE  */
    DO = 292,                      /* DO  */
    ENDWHILE = 293,                /* ENDWHILE  */
    BREAK = 294,                   /* BREAK  */
    CONTINUE = 295,                /* CONTINUE  */
    REPEAT = 296,                  /* REPEAT  */
    UNTIL = 297,                   /* UNTIL  */
    RETURN = 298,                  /* RETURN  */
    INT = 299,                     /* INT  */
    STR = 300,                     /* STR  */
    INIT = 301,                    /* INIT  */
    ALLOC = 302,                   /* ALLOC  */
    FREE = 303,                    /* FREE  */
    NULLVAL = 304                  /* NULLVAL  */
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
#define SELF 284
#define READ 285
#define WRITE 286
#define IF 287
#define THEN 288
#define ELSE 289
#define ENDIF 290
#define WHILE 291
#define DO 292
#define ENDWHILE 293
#define BREAK 294
#define CONTINUE 295
#define REPEAT 296
#define UNTIL 297
#define RETURN 298
#define INT 299
#define STR 300
#define INIT 301
#define ALLOC 302
#define FREE 303
#define NULLVAL 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 43 "parser.y"

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
