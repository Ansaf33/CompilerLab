/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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



struct TreeNode* root;
struct classtable* C = NULL;


extern FILE* yyin;

int yylex(void);
void yyerror(char* s);
FILE* xsm;

void initxsm(FILE* f);
void endxsm(FILE* f);



#line 113 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 275 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_NUM = 5,                        /* NUM  */
  YYSYMBOL_LT = 6,                         /* LT  */
  YYSYMBOL_LTE = 7,                        /* LTE  */
  YYSYMBOL_GT = 8,                         /* GT  */
  YYSYMBOL_GTE = 9,                        /* GTE  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_NEQ = 11,                       /* NEQ  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_MUL = 14,                       /* MUL  */
  YYSYMBOL_DIV = 15,                       /* DIV  */
  YYSYMBOL_EQUALS = 16,                    /* EQUALS  */
  YYSYMBOL_END = 17,                       /* END  */
  YYSYMBOL_BEG = 18,                       /* BEG  */
  YYSYMBOL_MAIN = 19,                      /* MAIN  */
  YYSYMBOL_DECL = 20,                      /* DECL  */
  YYSYMBOL_ENDDECL = 21,                   /* ENDDECL  */
  YYSYMBOL_BEGINTYPE = 22,                 /* BEGINTYPE  */
  YYSYMBOL_ENDTYPE = 23,                   /* ENDTYPE  */
  YYSYMBOL_BEGINCLASS = 24,                /* BEGINCLASS  */
  YYSYMBOL_ENDCLASS = 25,                  /* ENDCLASS  */
  YYSYMBOL_NEW = 26,                       /* NEW  */
  YYSYMBOL_DELETE = 27,                    /* DELETE  */
  YYSYMBOL_EXTENDS = 28,                   /* EXTENDS  */
  YYSYMBOL_SELF = 29,                      /* SELF  */
  YYSYMBOL_READ = 30,                      /* READ  */
  YYSYMBOL_WRITE = 31,                     /* WRITE  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_THEN = 33,                      /* THEN  */
  YYSYMBOL_ELSE = 34,                      /* ELSE  */
  YYSYMBOL_ENDIF = 35,                     /* ENDIF  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_DO = 37,                        /* DO  */
  YYSYMBOL_ENDWHILE = 38,                  /* ENDWHILE  */
  YYSYMBOL_BREAK = 39,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 40,                  /* CONTINUE  */
  YYSYMBOL_REPEAT = 41,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 42,                     /* UNTIL  */
  YYSYMBOL_RETURN = 43,                    /* RETURN  */
  YYSYMBOL_INT = 44,                       /* INT  */
  YYSYMBOL_STR = 45,                       /* STR  */
  YYSYMBOL_INIT = 46,                      /* INIT  */
  YYSYMBOL_ALLOC = 47,                     /* ALLOC  */
  YYSYMBOL_FREE = 48,                      /* FREE  */
  YYSYMBOL_NULLVAL = 49,                   /* NULLVAL  */
  YYSYMBOL_50_ = 50,                       /* '{'  */
  YYSYMBOL_51_ = 51,                       /* '}'  */
  YYSYMBOL_52_ = 52,                       /* ';'  */
  YYSYMBOL_53_ = 53,                       /* '('  */
  YYSYMBOL_54_ = 54,                       /* ')'  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ']'  */
  YYSYMBOL_58_ = 58,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_PROGRAM = 60,                   /* PROGRAM  */
  YYSYMBOL_TypeDefBlock = 61,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 62,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 63,                   /* TypeDef  */
  YYSYMBOL_FieldDeclList = 64,             /* FieldDeclList  */
  YYSYMBOL_ClassDefBlock = 65,             /* ClassDefBlock  */
  YYSYMBOL_ClassDefList = 66,              /* ClassDefList  */
  YYSYMBOL_ClassDef = 67,                  /* ClassDef  */
  YYSYMBOL_Cname = 68,                     /* Cname  */
  YYSYMBOL_MemberDeclList = 69,            /* MemberDeclList  */
  YYSYMBOL_MemberDecl = 70,                /* MemberDecl  */
  YYSYMBOL_MethodDeclList = 71,            /* MethodDeclList  */
  YYSYMBOL_MethodDecl = 72,                /* MethodDecl  */
  YYSYMBOL_MethodDefList = 73,             /* MethodDefList  */
  YYSYMBOL_MethodDef = 74,                 /* MethodDef  */
  YYSYMBOL_GdeclBlock = 75,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 76,                 /* GdeclList  */
  YYSYMBOL_Gdecl = 77,                     /* Gdecl  */
  YYSYMBOL_TYPE = 78,                      /* TYPE  */
  YYSYMBOL_GidList = 79,                   /* GidList  */
  YYSYMBOL_FdefBlock = 80,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 81,                      /* Fdef  */
  YYSYMBOL_ParamList = 82,                 /* ParamList  */
  YYSYMBOL_LdeclBlock = 83,                /* LdeclBlock  */
  YYSYMBOL_LdeclList = 84,                 /* LdeclList  */
  YYSYMBOL_Ldecl = 85,                     /* Ldecl  */
  YYSYMBOL_LidList = 86,                   /* LidList  */
  YYSYMBOL_MainBlock = 87,                 /* MainBlock  */
  YYSYMBOL_Body = 88,                      /* Body  */
  YYSYMBOL_SL = 89,                        /* SL  */
  YYSYMBOL_S = 90,                         /* S  */
  YYSYMBOL_IFST = 91,                      /* IFST  */
  YYSYMBOL_WHILEST = 92,                   /* WHILEST  */
  YYSYMBOL_REPEATST = 93,                  /* REPEATST  */
  YYSYMBOL_DOWHILEST = 94,                 /* DOWHILEST  */
  YYSYMBOL_ASSG = 95,                      /* ASSG  */
  YYSYMBOL_E = 96,                         /* E  */
  YYSYMBOL_IDENTIFIER = 97,                /* IDENTIFIER  */
  YYSYMBOL_FIELD = 98,                     /* FIELD  */
  YYSYMBOL_FIELDFUNCTION = 99,             /* FIELDFUNCTION  */
  YYSYMBOL_ArgList = 100,                  /* ArgList  */
  YYSYMBOL_CONSTANT = 101,                 /* CONSTANT  */
  YYSYMBOL_INPUT = 102,                    /* INPUT  */
  YYSYMBOL_OUTPUT = 103,                   /* OUTPUT  */
  YYSYMBOL_INITIALIZE = 104,               /* INITIALIZE  */
  YYSYMBOL_ALLOCATE = 105                  /* ALLOCATE  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   611

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  315

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      53,    54,     2,     2,    55,     2,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    84,    86,    89,    94,   101,   103,   107,
     114,   118,   125,   126,   130,   132,   136,   142,   146,   150,
     152,   156,   161,   163,   167,   174,   176,   180,   197,   202,
     206,   208,   212,   221,   225,   229,   235,   239,   243,   247,
     252,   256,   260,   264,   271,   273,   277,   301,   306,   311,
     317,   320,   324,   326,   330,   335,   339,   347,   365,   372,
     378,   382,   388,   390,   392,   394,   396,   398,   400,   402,
     406,   410,   414,   418,   422,   426,   432,   436,   442,   448,
     454,   461,   465,   469,   473,   478,   483,   488,   496,   500,
     504,   508,   512,   516,   520,   524,   528,   532,   536,   540,
     542,   544,   546,   550,   554,   558,   562,   566,   572,   576,
     581,   587,   591,   596,   600,   604,   609,   615,   619,   627,
     631,   635,   642,   646,   652,   658,   664
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "ID", "NUM",
  "LT", "LTE", "GT", "GTE", "EQ", "NEQ", "PLUS", "MINUS", "MUL", "DIV",
  "EQUALS", "END", "BEG", "MAIN", "DECL", "ENDDECL", "BEGINTYPE",
  "ENDTYPE", "BEGINCLASS", "ENDCLASS", "NEW", "DELETE", "EXTENDS", "SELF",
  "READ", "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "BREAK", "CONTINUE", "REPEAT", "UNTIL", "RETURN", "INT",
  "STR", "INIT", "ALLOC", "FREE", "NULLVAL", "'{'", "'}'", "';'", "'('",
  "')'", "','", "'['", "']'", "'.'", "$accept", "PROGRAM", "TypeDefBlock",
  "TypeDefList", "TypeDef", "FieldDeclList", "ClassDefBlock",
  "ClassDefList", "ClassDef", "Cname", "MemberDeclList", "MemberDecl",
  "MethodDeclList", "MethodDecl", "MethodDefList", "MethodDef",
  "GdeclBlock", "GdeclList", "Gdecl", "TYPE", "GidList", "FdefBlock",
  "Fdef", "ParamList", "LdeclBlock", "LdeclList", "Ldecl", "LidList",
  "MainBlock", "Body", "SL", "S", "IFST", "WHILEST", "REPEATST",
  "DOWHILEST", "ASSG", "E", "IDENTIFIER", "FIELD", "FIELDFUNCTION",
  "ArgList", "CONSTANT", "INPUT", "OUTPUT", "INITIALIZE", "ALLOCATE", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-190)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,    23,    45,    27,    22,    21,  -190,  -190,   103,   -12,
       3,  -190,  -190,    99,    13,  -190,    81,   115,   124,    32,
    -190,  -190,  -190,  -190,     5,   133,   149,  -190,  -190,   148,
    -190,   125,  -190,   154,   146,   124,   203,    32,  -190,  -190,
    -190,   222,   157,  -190,     3,  -190,  -190,    52,    62,   189,
     193,  -190,  -190,   190,  -190,     3,  -190,   245,     3,   246,
    -190,   252,   214,     3,  -190,  -190,   208,  -190,   266,   219,
     268,   -44,   216,   188,   254,    58,     3,  -190,   271,    69,
    -190,  -190,  -190,     3,   221,     3,   274,   224,   267,   278,
      65,  -190,   280,   233,     3,   326,   324,    87,   284,  -190,
     331,   236,  -190,   434,   291,   254,  -190,  -190,   290,   118,
    -190,   287,  -190,   289,  -190,   126,  -190,  -190,    70,   295,
     296,   293,   297,   299,   300,   301,   543,   303,   305,   543,
     234,   306,   463,  -190,   308,   309,   310,   311,   313,   332,
       4,   345,   346,  -190,   267,     3,   347,  -190,   353,  -190,
     360,    11,   234,   396,  -190,     8,   397,     8,   234,   234,
     234,   563,  -190,  -190,   483,  -190,    91,  -190,   344,  -190,
     234,   381,  -190,   358,  -190,  -190,     8,   351,  -190,  -190,
    -190,  -190,  -190,  -190,   201,   229,   413,  -190,  -190,   367,
     138,  -190,   362,  -190,  -190,   399,   143,    73,  -190,   366,
     -36,  -190,   368,    16,   282,   292,   302,   370,   373,   417,
     420,   312,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,  -190,   424,   388,    17,  -190,   391,   392,   393,
     399,  -190,  -190,   394,   399,  -190,  -190,  -190,   402,  -190,
    -190,   234,   398,   401,   403,  -190,  -190,  -190,   416,   419,
     234,   234,   404,   405,  -190,   151,   151,   151,   151,   325,
     325,   199,   199,  -190,  -190,   406,   408,   410,   446,   414,
     415,   468,   254,   399,   234,  -190,  -190,   543,   543,   361,
     371,    86,   147,   182,  -190,  -190,   422,  -190,  -190,   425,
     267,   210,   400,   503,   419,  -190,  -190,   205,  -190,   207,
    -190,   211,  -190,  -190,   427,  -190,   543,  -190,  -190,  -190,
    -190,  -190,  -190,   523,  -190
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,    13,     0,     0,     8,     1,     0,     0,
       0,     5,     7,    17,     0,    15,     0,     0,     0,     0,
       4,    35,    33,    34,     0,     0,     0,    12,    14,     0,
      29,     0,    31,     0,     0,    33,     0,     0,    45,     3,
       9,     0,     0,    18,     0,    28,    30,    40,     0,     0,
       0,    44,     2,     0,    11,     0,    20,     0,    49,     0,
      32,     0,     0,    49,    10,    19,     0,    23,     0,     0,
       0,     0,     0,    36,     0,     0,     0,    22,     0,     0,
      21,    48,    43,     0,    41,    49,     0,     0,     0,     0,
       0,    26,     0,     0,    49,     0,     0,     0,     0,    51,
       0,     0,    53,     0,     0,     0,    16,    25,     0,     0,
      47,     0,    39,    37,    56,     0,    50,    52,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,    49,     0,    42,     0,    54,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,    69,    70,     0,   120,   103,   119,     0,   121,
       0,     0,   100,   101,   102,    99,     0,     0,    60,    65,
      66,    67,    68,    62,     0,     0,     0,    63,    64,     0,
       0,    24,     0,    55,   106,   118,     0,     0,   109,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,     0,    58,     0,     0,     0,
      81,    83,    84,     0,    82,    85,   108,    46,     0,    38,
     107,     0,   104,     0,     0,   122,   123,   124,     0,     0,
       0,     0,   109,   110,    98,    92,    93,    94,    95,    97,
      96,    88,    89,    90,    91,   108,     0,     0,     0,     0,
       0,     0,     0,   117,     0,    74,    75,     0,     0,     0,
       0,     0,     0,     0,    72,    73,     0,   125,   126,     0,
       0,     0,     0,     0,    80,    79,   115,     0,   114,     0,
     116,     0,    86,    87,     0,   105,     0,    77,    78,   112,
     111,   113,    27,     0,    76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,  -190,  -190,   476,  -190,  -190,  -190,   469,  -190,
    -190,   429,  -190,   423,  -190,   395,  -190,  -190,   455,   101,
    -190,  -190,   451,   -39,  -101,  -190,   390,  -190,     2,  -142,
    -123,  -131,  -190,  -190,  -190,  -190,  -190,  -117,  -103,   -98,
    -190,  -189,  -190,  -190,  -190,  -190,   316
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    24,     9,    14,    15,    16,
      55,    56,    66,    67,    90,    91,    19,    31,    32,    70,
      48,    37,    38,    71,    88,   101,   102,   115,    20,   104,
     132,   133,   134,   135,   136,   137,   138,   195,   172,   173,
     174,   196,   175,   141,   142,   231,   232
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     139,   178,   189,   161,   144,   140,   164,    21,    17,    21,
      82,    83,   118,   171,   165,   166,   167,    13,   244,     1,
     185,    39,   186,   139,    75,     4,   139,     4,   140,   139,
     178,   140,    18,   178,   140,   197,    21,   121,    27,    52,
     168,   204,   205,   206,    11,     7,    97,    22,    23,    22,
      23,     8,   199,   211,   202,   109,    40,   200,   139,   203,
     169,   139,   186,   140,   170,   194,   140,   230,   234,    21,
     246,   267,    10,   224,   186,   186,    35,    23,   225,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   165,
     166,   167,   297,   299,   301,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    58,   190,    13,    59,    22,
      23,    25,    89,    83,    60,   168,   106,    61,    33,    21,
      36,    80,    94,   151,   273,    41,   152,    26,   153,    21,
     242,    29,    33,   279,   280,   169,    30,    42,    36,   170,
     296,   112,    83,    34,   151,    57,    45,   152,   304,   209,
     165,   166,   167,    43,   292,   293,    68,   291,    47,    22,
      23,   178,   178,   218,   219,   220,   221,    78,    44,    22,
      23,   290,   146,    83,   139,   139,   168,    92,   149,   140,
     140,   150,   178,   313,    95,   165,   166,   167,   100,   139,
     139,    92,   238,    83,   140,   140,   169,   240,   241,    49,
     170,   298,   100,   139,   165,   166,   167,    50,   140,    54,
     139,   168,    21,   220,   221,   140,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    53,   227,    21,    76,
     168,   169,   165,   166,   167,   170,   300,   165,   166,   167,
      21,    85,    64,    62,    86,    99,    63,   228,   229,    69,
     169,    72,    22,    23,   170,   233,    73,   116,   168,   309,
     241,   310,   241,   168,    74,   311,   241,   305,    22,    23,
      79,    80,    81,    84,    87,    93,   229,    96,   169,    98,
      22,    23,   170,   169,   108,   103,    94,   170,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   105,   111,
     110,   212,   213,   214,   215,   114,   247,   218,   219,   220,
     221,   113,   143,   145,   147,   148,   248,   154,   184,   155,
     157,   156,   158,   159,   160,   162,   249,   163,   192,   176,
     179,   180,   181,   182,   193,   183,   254,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   187,   188,   191,
     198,   201,   210,   226,   118,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   294,   223,   236,   237,   239,
     243,   252,   245,   250,   253,   295,   251,   120,   265,   121,
     122,   123,   124,   222,   306,   307,   125,   126,   118,   127,
     128,   129,   266,   130,   268,   269,   270,   271,   131,   277,
     286,   119,   272,   275,   274,   276,   278,   281,   282,   283,
     284,   120,   285,   121,   122,   123,   124,   118,   287,   288,
     125,   126,   289,   127,   128,   129,   302,   130,   312,   303,
     177,    12,   131,    28,    65,   107,    46,   118,    51,    77,
     120,   117,   121,   122,   123,   124,     0,     0,     0,   125,
     126,   235,   127,   128,   129,     0,   130,   118,     0,     0,
     120,   131,   121,   122,   123,   124,     0,     0,     0,   125,
     126,     0,   127,   128,   129,   208,   130,   118,     0,     0,
     120,   131,   121,   122,   123,   124,     0,     0,     0,   125,
     126,   308,   127,   128,   129,     0,   130,   118,     0,     0,
     120,   131,   121,   122,   123,   124,     0,     0,   314,   125,
     126,     0,   127,   128,   129,     0,   130,   118,     0,     0,
     120,   131,   121,   122,   123,   124,     0,     0,     0,   125,
     126,     0,   127,   128,   129,     0,   130,     0,     0,     0,
     120,   131,   121,   122,   123,   124,     0,     0,     0,   207,
     126,     0,   127,   128,   129,     0,   130,     0,     0,     0,
       0,   131
};

static const yytype_int16 yycheck[] =
{
     103,   132,   144,   126,   105,   103,   129,     4,    20,     4,
      54,    55,     4,   130,     3,     4,     5,     4,    54,    22,
      16,    19,    58,   126,    63,     4,   129,     4,   126,   132,
     161,   129,    44,   164,   132,   152,     4,    29,    25,    37,
      29,   158,   159,   160,    23,     0,    85,    44,    45,    44,
      45,    24,   155,   170,   157,    94,    51,   155,   161,   157,
      49,   164,    58,   161,    53,    54,   164,   184,   185,     4,
      54,    54,    50,   176,    58,    58,    44,    45,   176,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     3,
       4,     5,   281,   282,   283,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,    53,   145,     4,    56,    44,
      45,    10,    54,    55,    52,    29,    51,    55,    17,     4,
      19,    52,    53,    53,   241,    24,    56,    28,    58,     4,
      57,    50,    31,   250,   251,    49,    21,     4,    37,    53,
      54,    54,    55,    19,    53,    44,    21,    56,   290,    58,
       3,     4,     5,     4,   277,   278,    55,   274,     4,    44,
      45,   292,   293,    12,    13,    14,    15,    66,    20,    44,
      45,   272,    54,    55,   277,   278,    29,    76,    52,   277,
     278,    55,   313,   306,    83,     3,     4,     5,    87,   292,
     293,    90,    54,    55,   292,   293,    49,    54,    55,    53,
      53,    54,   101,   306,     3,     4,     5,     4,   306,    52,
     313,    29,     4,    14,    15,   313,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     4,    26,     4,    21,
      29,    49,     3,     4,     5,    53,    54,     3,     4,     5,
       4,    53,    52,    54,    56,    21,    53,    46,    47,     4,
      49,     5,    44,    45,    53,    26,     4,    21,    29,    54,
      55,    54,    55,    29,    50,    54,    55,    57,    44,    45,
       4,    52,     4,    57,    20,     4,    47,    56,    49,     5,
      44,    45,    53,    49,     4,    18,    53,    53,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    50,     5,
       4,     6,     7,     8,     9,     4,    54,    12,    13,    14,
      15,    57,    51,    53,    57,    56,    54,    52,    16,    53,
      53,    58,    53,    53,    53,    52,    54,    52,     5,    53,
      52,    52,    52,    52,     4,    52,    54,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    52,    52,    52,
       4,     4,    58,    52,     4,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    54,    58,     4,    51,    57,
      54,     4,    54,    53,     4,    54,    53,    27,     4,    29,
      30,    31,    32,    52,    34,    35,    36,    37,     4,    39,
      40,    41,    54,    43,    53,    53,    53,    53,    48,    33,
       4,    17,    50,    52,    56,    52,    37,    53,    53,    53,
      52,    27,    52,    29,    30,    31,    32,     4,    54,    54,
      36,    37,     4,    39,    40,    41,    54,    43,    51,    54,
      17,     5,    48,    14,    55,    90,    31,     4,    37,    66,
      27,   101,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      37,   185,    39,    40,    41,    -1,    43,     4,    -1,    -1,
      27,    48,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      37,    -1,    39,    40,    41,    42,    43,     4,    -1,    -1,
      27,    48,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    -1,    43,     4,    -1,    -1,
      27,    48,    29,    30,    31,    32,    -1,    -1,    35,    36,
      37,    -1,    39,    40,    41,    -1,    43,     4,    -1,    -1,
      27,    48,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      37,    -1,    39,    40,    41,    -1,    43,    -1,    -1,    -1,
      27,    48,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      37,    -1,    39,    40,    41,    -1,    43,    -1,    -1,    -1,
      -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    60,    61,     4,    62,    63,     0,    24,    65,
      50,    23,    63,     4,    66,    67,    68,    20,    44,    75,
      87,     4,    44,    45,    64,    78,    28,    25,    67,    50,
      21,    76,    77,    78,    19,    44,    78,    80,    81,    87,
      51,    78,     4,     4,    20,    21,    77,     4,    79,    53,
       4,    81,    87,     4,    52,    69,    70,    78,    53,    56,
      52,    55,    54,    53,    52,    70,    71,    72,    78,     4,
      78,    82,     5,     4,    50,    82,    21,    72,    78,     4,
      52,     4,    54,    55,    57,    53,    56,    20,    83,    54,
      73,    74,    78,     4,    53,    78,    56,    82,     5,    21,
      78,    84,    85,    18,    88,    50,    51,    74,     4,    82,
       4,     5,    54,    57,     4,    86,    21,    85,     4,    17,
      27,    29,    30,    31,    32,    36,    37,    39,    40,    41,
      43,    48,    89,    90,    91,    92,    93,    94,    95,    97,
      98,   102,   103,    51,    83,    53,    54,    57,    56,    52,
      55,    53,    56,    58,    52,    53,    58,    53,    53,    53,
      53,    89,    52,    52,    89,     3,     4,     5,    29,    49,
      53,    96,    97,    98,    99,   101,    53,    17,    90,    52,
      52,    52,    52,    52,    16,    16,    58,    52,    52,    88,
      82,    52,     5,     4,    54,    96,   100,    96,     4,    97,
      98,     4,    97,    98,    96,    96,    96,    36,    42,    58,
      58,    96,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    52,    58,    97,    98,    52,    26,    46,    47,
      96,   104,   105,    26,    96,   105,     4,    51,    54,    57,
      54,    55,    57,    54,    54,    54,    54,    54,    54,    54,
      53,    53,     4,     4,    54,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,     4,    54,    54,    53,    53,
      53,    53,    50,    96,    56,    52,    52,    33,    37,    96,
      96,    53,    53,    53,    52,    52,     4,    54,    54,     4,
      83,    96,    89,    89,    54,    54,    54,   100,    54,   100,
      54,   100,    54,    54,    88,    57,    34,    35,    38,    54,
      54,    54,    51,    89,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    60,    60,    61,    61,    62,    62,    63,
      64,    64,    65,    65,    66,    66,    67,    68,    68,    69,
      69,    70,    71,    71,    72,    73,    73,    74,    75,    75,
      76,    76,    77,    78,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    79,    80,    80,    81,    82,    82,    82,
      83,    83,    84,    84,    85,    86,    86,    87,    88,    88,
      89,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    91,    91,    92,    93,
      94,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    97,    97,    98,    98,
      98,    99,    99,    99,    99,    99,    99,   100,   100,   101,
     101,   101,   102,   102,   103,   104,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     2,     1,     4,
       4,     3,     3,     0,     2,     1,     8,     1,     3,     2,
       1,     3,     2,     1,     6,     2,     1,     9,     3,     2,
       2,     1,     3,     1,     1,     1,     3,     6,     9,     6,
       1,     4,     7,     4,     2,     1,     9,     4,     2,     0,
       3,     2,     2,     1,     3,     3,     1,     8,     4,     3,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     5,     5,     5,     5,     9,     7,     7,     6,
       6,     3,     3,     3,     3,     3,     6,     6,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     4,     7,     3,     4,     3,     3,
       3,     6,     6,     6,     5,     5,     5,     3,     1,     1,
       1,     1,     4,     4,     4,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* TypeDefBlock: BEGINTYPE TypeDefList ENDTYPE  */
#line 89 "parser.y"
                                          {
             printf("All Type definitions parsed.\n");
             printTT();
             }
#line 1626 "y.tab.c"
    break;

  case 6: /* TypeDefBlock: %empty  */
#line 94 "parser.y"
             {
             printf("No Type definitions present\n");
             printTT();
             }
#line 1635 "y.tab.c"
    break;

  case 9: /* TypeDef: ID '{' FieldDeclList '}'  */
#line 107 "parser.y"
                                 {
         addTTNode((yyvsp[-3].string),getFLSize((yyvsp[-1].fieldlist)),(yyvsp[-1].fieldlist));
         addTypes((yyvsp[-1].fieldlist));
        }
#line 1644 "y.tab.c"
    break;

  case 10: /* FieldDeclList: FieldDeclList TYPE ID ';'  */
#line 114 "parser.y"
                                        {
              (yyval.fieldlist) = addFLNode((yyvsp[-3].fieldlist),(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1652 "y.tab.c"
    break;

  case 11: /* FieldDeclList: TYPE ID ';'  */
#line 118 "parser.y"
                          {
              (yyval.fieldlist) = addFLNode(NULL,(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1660 "y.tab.c"
    break;

  case 16: /* ClassDef: Cname '{' DECL MemberDeclList MethodDeclList ENDDECL MethodDefList '}'  */
#line 136 "parser.y"
                                                                                {
         printClass(C);
         }
#line 1668 "y.tab.c"
    break;

  case 17: /* Cname: ID  */
#line 142 "parser.y"
         {
      C = addClassNode((yyvsp[0].string));
      }
#line 1676 "y.tab.c"
    break;

  case 21: /* MemberDecl: TYPE ID ';'  */
#line 156 "parser.y"
                  {
        addMemberToClass(C,lookTTUp((yyvsp[-2].string)),lookClassUp((yyvsp[-2].string)),(yyvsp[-1].string));
      }
#line 1684 "y.tab.c"
    break;

  case 24: /* MethodDecl: TYPE ID '(' ParamList ')' ';'  */
#line 167 "parser.y"
                                    {
        addMethodToClass(C,lookTTUp((yyvsp[-5].string)),(yyvsp[-4].string),(yyvsp[-2].paramlist));
        deleteLSymbolTable();
      }
#line 1693 "y.tab.c"
    break;

  case 27: /* MethodDef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 180 "parser.y"
                                                            {

          checkDeclDef(C,lookTTUp((yyvsp[-8].string)),(yyvsp[-7].string),(yyvsp[-5].paramlist));

          int size = getParamSize((yyvsp[-5].paramlist));
          addSelfToLSymbolTable(C,size);

          getLSymbolTable();

          define_method_codeGen(xsm,C,(yyvsp[-7].string),(yyvsp[-1].node));

          deleteLSymbolTable();
          }
#line 1711 "y.tab.c"
    break;

  case 28: /* GdeclBlock: DECL GdeclList ENDDECL  */
#line 197 "parser.y"
                                   {
                C = NULL;
                getGSymbolTable();
              }
#line 1720 "y.tab.c"
    break;

  case 32: /* Gdecl: TYPE GidList ';'  */
#line 212 "parser.y"
                      {
          if( !lookGUp("main") ){
              addGSymbol("main",lookTTUp("int"),NULL,1,1,NULL,1); 
          }
          addAllGSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)),lookClassUp((yyvsp[-2].string)));
     }
#line 1731 "y.tab.c"
    break;

  case 33: /* TYPE: INT  */
#line 221 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1739 "y.tab.c"
    break;

  case 34: /* TYPE: STR  */
#line 225 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1747 "y.tab.c"
    break;

  case 35: /* TYPE: ID  */
#line 229 "parser.y"
        {
     (yyval.string) = (yyvsp[0].string);  
     }
#line 1755 "y.tab.c"
    break;

  case 36: /* GidList: GidList ',' ID  */
#line 235 "parser.y"
                       {
          (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1763 "y.tab.c"
    break;

  case 37: /* GidList: GidList ',' ID '[' NUM ']'  */
#line 239 "parser.y"
                                   {
          (yyval.list) = addArray((yyvsp[-5].list),(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1771 "y.tab.c"
    break;

  case 38: /* GidList: GidList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 243 "parser.y"
                                               {
          (yyval.list) = addArray((yyvsp[-8].list),(yyvsp[-8].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1779 "y.tab.c"
    break;

  case 39: /* GidList: GidList ',' ID '(' ParamList ')'  */
#line 247 "parser.y"
                                         {
          (yyval.list) = addFunction((yyvsp[-5].list),(yyvsp[-3].string),(yyvsp[-1].paramlist));
          deleteLSymbolTable();
        }
#line 1788 "y.tab.c"
    break;

  case 40: /* GidList: ID  */
#line 252 "parser.y"
           {
          (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1796 "y.tab.c"
    break;

  case 41: /* GidList: ID '[' NUM ']'  */
#line 256 "parser.y"
                       {
          (yyval.list) = addArray(NULL,(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1804 "y.tab.c"
    break;

  case 42: /* GidList: ID '[' NUM ']' '[' NUM ']'  */
#line 260 "parser.y"
                                   {
          (yyval.list) = addArray(NULL,(yyvsp[-6].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1812 "y.tab.c"
    break;

  case 43: /* GidList: ID '(' ParamList ')'  */
#line 264 "parser.y"
                             { 
          (yyval.list) = addFunction(NULL,(yyvsp[-3].string),(yyvsp[-1].paramlist));
          deleteLSymbolTable();
        }
#line 1821 "y.tab.c"
    break;

  case 46: /* Fdef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 277 "parser.y"
                                                       {
     printf("|| ------------------------- F U N C T I O N : %s ---------------------- ||\n\n",(yyvsp[-7].string));

     // --------------------------------------- CHECKING FUNCTION REQUIREMENTS ---------------------------------------------
     // PRINT THE PARAMETERS
     printParameters((yyvsp[-5].paramlist));
     // PRINT THE LOCAL SYMBOL TABLE
     getLSymbolTable();
     // CHECK IF FUNCTION IS DECLARED
     checkFunctionDeclared((yyvsp[-7].string));
     // CHECK IF DEFINED PARAMETERS ARE VALID (in paramlist) to DECLARED PARAMETERS (in symboltable->param) (NAME AND TYPE)
     checkValidParams((yyvsp[-5].paramlist),(yyvsp[-7].string));
     // CHECK IF RETURN TYPES OF DECLARED AND DEFINED FUNCTIONS ARE VALID
     checkValidRetType(lookTTUp((yyvsp[-8].string)),(yyvsp[-7].string));
     // ---------------------------------------- CHECKING DONE --------------------------------------------------------------
 
     define_function_codeGen(xsm,(yyvsp[-7].string),(yyvsp[-1].node));

     deleteLSymbolTable();
     }
#line 1846 "y.tab.c"
    break;

  case 47: /* ParamList: ParamList ',' TYPE ID  */
#line 301 "parser.y"
                                {
           (yyval.paramlist) = addParameter((yyvsp[-3].paramlist),(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1855 "y.tab.c"
    break;

  case 48: /* ParamList: TYPE ID  */
#line 306 "parser.y"
                  {
           (yyval.paramlist) = addParameter(NULL,(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1864 "y.tab.c"
    break;

  case 49: /* ParamList: %empty  */
#line 311 "parser.y"
           {
           (yyval.paramlist) = NULL;
          }
#line 1872 "y.tab.c"
    break;

  case 50: /* LdeclBlock: DECL LdeclList ENDDECL  */
#line 317 "parser.y"
                                  {
           }
#line 1879 "y.tab.c"
    break;

  case 54: /* Ldecl: TYPE LidList ';'  */
#line 330 "parser.y"
                       {
         addAllLSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)));
      }
#line 1887 "y.tab.c"
    break;

  case 55: /* LidList: LidList ',' ID  */
#line 335 "parser.y"
                       {
        (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1895 "y.tab.c"
    break;

  case 56: /* LidList: ID  */
#line 339 "parser.y"
           {
        (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1903 "y.tab.c"
    break;

  case 57: /* MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 347 "parser.y"
                                                   {
          printf("|| ------------------------- F U N C T I O N : Main ---------------------- ||\n\n");
 
          // GETTING LOCAL SYMBOL TABLE
          getLSymbolTable();

          // DEFINING THE FUNCTION
          define_function_codeGen(xsm,"main",(yyvsp[-1].node));

          // ENDING LABELS
          endxsm(xsm);

          // DELETING LOCAL SYMBOL TABLE OF MAINN
          deleteLSymbolTable();

          }
#line 1924 "y.tab.c"
    break;

  case 58: /* Body: BEG SL END ';'  */
#line 365 "parser.y"
                 {
    (yyval.node) = (yyvsp[-2].node);
    root = (yyvsp[-2].node);
    printf("Valid Program.\n");
    Inorder((yyvsp[-2].node));
  }
#line 1935 "y.tab.c"
    break;

  case 59: /* Body: BEG END ';'  */
#line 372 "parser.y"
              {
  printf("Valid program.\n");
  }
#line 1943 "y.tab.c"
    break;

  case 60: /* SL: SL S  */
#line 378 "parser.y"
         {
   (yyval.node) = createOpNode(NULL,13,(yyvsp[-1].node),(yyvsp[0].node));
  }
#line 1951 "y.tab.c"
    break;

  case 61: /* SL: S  */
#line 382 "parser.y"
      {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1959 "y.tab.c"
    break;

  case 69: /* S: BREAK ';'  */
#line 402 "parser.y"
            {
    (yyval.node) = createOpNode(NULL,16,NULL,NULL);
  }
#line 1967 "y.tab.c"
    break;

  case 70: /* S: CONTINUE ';'  */
#line 406 "parser.y"
               {
    (yyval.node) = createOpNode(NULL,17,NULL,NULL);
  }
#line 1975 "y.tab.c"
    break;

  case 71: /* S: RETURN E ';'  */
#line 410 "parser.y"
               {
    (yyval.node) = createReturnNode((yyvsp[-1].node));
  }
#line 1983 "y.tab.c"
    break;

  case 72: /* S: FREE '(' IDENTIFIER ')' ';'  */
#line 414 "parser.y"
                              {
    (yyval.node) = createFreeNode((yyvsp[-2].node));
  }
#line 1991 "y.tab.c"
    break;

  case 73: /* S: FREE '(' FIELD ')' ';'  */
#line 418 "parser.y"
                         {
    (yyval.node) = createFreeNode((yyvsp[-2].node));
  }
#line 1999 "y.tab.c"
    break;

  case 74: /* S: DELETE '(' IDENTIFIER ')' ';'  */
#line 422 "parser.y"
                                {
    (yyval.node) = createDeleteNode((yyvsp[-2].node));
  }
#line 2007 "y.tab.c"
    break;

  case 75: /* S: DELETE '(' FIELD ')' ';'  */
#line 426 "parser.y"
                           {
    (yyval.node) = createDeleteNode((yyvsp[-2].node));
  }
#line 2015 "y.tab.c"
    break;

  case 76: /* IFST: IF '(' E ')' THEN SL ELSE SL ENDIF  */
#line 432 "parser.y"
                                        {
      (yyval.node) = createIfNode((yyvsp[-6].node),(yyvsp[-3].node),(yyvsp[-1].node));
    }
#line 2023 "y.tab.c"
    break;

  case 77: /* IFST: IF '(' E ')' THEN SL ENDIF  */
#line 436 "parser.y"
                               {
      (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-1].node),NULL);
    }
#line 2031 "y.tab.c"
    break;

  case 78: /* WHILEST: WHILE '(' E ')' DO SL ENDWHILE  */
#line 442 "parser.y"
                                       {
        (yyval.node) = createWhileNode(15,(yyvsp[-4].node),(yyvsp[-1].node));
        }
#line 2039 "y.tab.c"
    break;

  case 79: /* REPEATST: REPEAT SL UNTIL '(' E ')'  */
#line 448 "parser.y"
                                   {
         (yyval.node) = createWhileNode(18,(yyvsp[-1].node),(yyvsp[-4].node));
        }
#line 2047 "y.tab.c"
    break;

  case 80: /* DOWHILEST: DO SL WHILE '(' E ')'  */
#line 454 "parser.y"
                                { 
          (yyval.node) = createWhileNode(19,(yyvsp[-1].node),(yyvsp[-4].node));
          }
#line 2055 "y.tab.c"
    break;

  case 81: /* ASSG: IDENTIFIER EQUALS E  */
#line 461 "parser.y"
                      {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2063 "y.tab.c"
    break;

  case 82: /* ASSG: FIELD EQUALS E  */
#line 465 "parser.y"
                 {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2071 "y.tab.c"
    break;

  case 83: /* ASSG: IDENTIFIER EQUALS INITIALIZE  */
#line 469 "parser.y"
                               {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2079 "y.tab.c"
    break;

  case 84: /* ASSG: IDENTIFIER EQUALS ALLOCATE  */
#line 473 "parser.y"
                             {
  (yyvsp[0].node)->type = (yyvsp[-2].node)->type;
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2088 "y.tab.c"
    break;

  case 85: /* ASSG: FIELD EQUALS ALLOCATE  */
#line 478 "parser.y"
                        {
  (yyvsp[0].node)->type = lookTTUp(getName((yyvsp[-2].node)));
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2097 "y.tab.c"
    break;

  case 86: /* ASSG: IDENTIFIER EQUALS NEW '(' ID ')'  */
#line 483 "parser.y"
                                   {
  struct TreeNode* RHS = createNewNode((yyvsp[-1].string));
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-5].node),RHS);
  }
#line 2106 "y.tab.c"
    break;

  case 87: /* ASSG: FIELD EQUALS NEW '(' ID ')'  */
#line 488 "parser.y"
                              {
  struct TreeNode* RHS = createNewNode((yyvsp[-1].string));
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-5].node),RHS);
  }
#line 2115 "y.tab.c"
    break;

  case 88: /* E: E PLUS E  */
#line 496 "parser.y"
           {
  (yyval.node) = createOpNode(lookTTUp("int"),0,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2123 "y.tab.c"
    break;

  case 89: /* E: E MINUS E  */
#line 500 "parser.y"
            {
  (yyval.node) = createOpNode(lookTTUp("int"),1,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2131 "y.tab.c"
    break;

  case 90: /* E: E MUL E  */
#line 504 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),2,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2139 "y.tab.c"
    break;

  case 91: /* E: E DIV E  */
#line 508 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),3,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2147 "y.tab.c"
    break;

  case 92: /* E: E LT E  */
#line 512 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),5,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2155 "y.tab.c"
    break;

  case 93: /* E: E LTE E  */
#line 516 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),6,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2163 "y.tab.c"
    break;

  case 94: /* E: E GT E  */
#line 520 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),7,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2171 "y.tab.c"
    break;

  case 95: /* E: E GTE E  */
#line 524 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),8,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2179 "y.tab.c"
    break;

  case 96: /* E: E NEQ E  */
#line 528 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),9,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2187 "y.tab.c"
    break;

  case 97: /* E: E EQ E  */
#line 532 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),10,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2195 "y.tab.c"
    break;

  case 98: /* E: '(' E ')'  */
#line 536 "parser.y"
            {
  (yyval.node) = (yyvsp[-1].node);
  }
#line 2203 "y.tab.c"
    break;

  case 103: /* IDENTIFIER: ID  */
#line 550 "parser.y"
              { 
            (yyval.node) = createIdNode((yyvsp[0].string),NULL,NULL);
           }
#line 2211 "y.tab.c"
    break;

  case 104: /* IDENTIFIER: ID '[' E ']'  */
#line 554 "parser.y"
                        {
            (yyval.node) = createIdNode((yyvsp[-3].string),NULL,(yyvsp[-1].node));
            }
#line 2219 "y.tab.c"
    break;

  case 105: /* IDENTIFIER: ID '[' E ']' '[' E ']'  */
#line 558 "parser.y"
                                  {
            (yyval.node) = createIdNode((yyvsp[-6].string),(yyvsp[-4].node),(yyvsp[-1].node));
            }
#line 2227 "y.tab.c"
    break;

  case 106: /* IDENTIFIER: ID '(' ')'  */
#line 562 "parser.y"
                       {
            (yyval.node) = createFunctionNode((yyvsp[-2].string),NULL);
            }
#line 2235 "y.tab.c"
    break;

  case 107: /* IDENTIFIER: ID '(' ArgList ')'  */
#line 566 "parser.y"
                               { 
            (yyval.node) = createFunctionNode((yyvsp[-3].string),(yyvsp[-1].node));
            }
#line 2243 "y.tab.c"
    break;

  case 108: /* FIELD: FIELD '.' ID  */
#line 572 "parser.y"
                   {
      (yyval.node) = addFieldToEnd((yyvsp[-2].node),(yyvsp[0].string));
      }
#line 2251 "y.tab.c"
    break;

  case 109: /* FIELD: ID '.' ID  */
#line 576 "parser.y"
                {
      (yyval.node) = createIdNode((yyvsp[-2].string),NULL,NULL);
      (yyval.node) = addFieldToEnd((yyval.node),(yyvsp[0].string));
      }
#line 2260 "y.tab.c"
    break;

  case 110: /* FIELD: SELF '.' ID  */
#line 581 "parser.y"
                  {
      (yyval.node) = createSelfNode(C,(yyvsp[0].string),NULL);
      }
#line 2268 "y.tab.c"
    break;

  case 111: /* FIELDFUNCTION: SELF '.' ID '(' ArgList ')'  */
#line 587 "parser.y"
                                          {
              (yyval.node) = createSelfNode(C,(yyvsp[-3].string),(yyvsp[-1].node));
              }
#line 2276 "y.tab.c"
    break;

  case 112: /* FIELDFUNCTION: ID '.' ID '(' ArgList ')'  */
#line 591 "parser.y"
                                        {
              (yyval.node) = createIdNode((yyvsp[-5].string),NULL,NULL);
              (yyval.node) = addMethodToEnd((yyval.node),(yyvsp[-3].string),(yyvsp[-1].node));
              }
#line 2285 "y.tab.c"
    break;

  case 113: /* FIELDFUNCTION: FIELD '.' ID '(' ArgList ')'  */
#line 596 "parser.y"
                                           {
              (yyval.node) = addMethodToEnd((yyvsp[-5].node),(yyvsp[-3].string),(yyvsp[-1].node));
              }
#line 2293 "y.tab.c"
    break;

  case 114: /* FIELDFUNCTION: SELF '.' ID '(' ')'  */
#line 600 "parser.y"
                                  {
              (yyval.node) = createSelfNode(C,(yyvsp[-2].string),NULL);
              }
#line 2301 "y.tab.c"
    break;

  case 115: /* FIELDFUNCTION: ID '.' ID '(' ')'  */
#line 604 "parser.y"
                                {
              (yyval.node) = createIdNode((yyvsp[-4].string),NULL,NULL);
              (yyval.node) = addMethodToEnd((yyval.node),(yyvsp[-2].string),NULL);
              }
#line 2310 "y.tab.c"
    break;

  case 116: /* FIELDFUNCTION: FIELD '.' ID '(' ')'  */
#line 609 "parser.y"
                                   {
                (yyval.node) = addMethodToEnd((yyvsp[-4].node),(yyvsp[-2].string),NULL);
              }
#line 2318 "y.tab.c"
    break;

  case 117: /* ArgList: ArgList ',' E  */
#line 615 "parser.y"
                      {
        (yyval.node) = addArgToList((yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2326 "y.tab.c"
    break;

  case 118: /* ArgList: E  */
#line 620 "parser.y"
        {
        (yyval.node) = (yyvsp[0].node);
        }
#line 2334 "y.tab.c"
    break;

  case 119: /* CONSTANT: NUM  */
#line 627 "parser.y"
             {
          (yyval.node) = createNumNode(atoi((yyvsp[0].string)));
          }
#line 2342 "y.tab.c"
    break;

  case 120: /* CONSTANT: STRING  */
#line 631 "parser.y"
                {
          (yyval.node) = createStringNode((yyvsp[0].string));
          }
#line 2350 "y.tab.c"
    break;

  case 121: /* CONSTANT: NULLVAL  */
#line 635 "parser.y"
                 {
          (yyval.node) = createNullNode();
          }
#line 2358 "y.tab.c"
    break;

  case 122: /* INPUT: READ '(' IDENTIFIER ')'  */
#line 642 "parser.y"
                               {
       (yyval.node) = createOpNode(NULL,11,(yyvsp[-1].node),NULL);
      }
#line 2366 "y.tab.c"
    break;

  case 123: /* INPUT: READ '(' FIELD ')'  */
#line 646 "parser.y"
                         {
      (yyval.node) = createOpNode(NULL,11,(yyvsp[-1].node),NULL);
      }
#line 2374 "y.tab.c"
    break;

  case 124: /* OUTPUT: WRITE '(' E ')'  */
#line 652 "parser.y"
                       {
        (yyval.node) = createOpNode(NULL,12,(yyvsp[-1].node),NULL);
      }
#line 2382 "y.tab.c"
    break;

  case 125: /* INITIALIZE: INIT '(' ')'  */
#line 658 "parser.y"
                        {
           (yyval.node) = createOpNode(lookTTUp("int"),21,NULL,NULL);
           }
#line 2390 "y.tab.c"
    break;

  case 126: /* ALLOCATE: ALLOC '(' ')'  */
#line 664 "parser.y"
                       {
         (yyval.node) = createOpNode(lookTTUp("int"),22,NULL,NULL);
         }
#line 2398 "y.tab.c"
    break;


#line 2402 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 670 "parser.y"



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
          fprintf(xsm,"INT 10\n");

}
