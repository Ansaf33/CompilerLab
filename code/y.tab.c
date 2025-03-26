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

#include "inheritance/copier.h"



struct TreeNode* root;
struct classtable* C = NULL;
extern FILE* yyin;
FILE* xsm;

int yylex(void);
void yyerror(char* s);
void initxsm(FILE* f);
void endxsm(FILE* f);



#line 112 "y.tab.c"

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

#line 278 "y.tab.c"

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
  YYSYMBOL_REF = 12,                       /* REF  */
  YYSYMBOL_DEREF = 13,                     /* DEREF  */
  YYSYMBOL_PLUS = 14,                      /* PLUS  */
  YYSYMBOL_MINUS = 15,                     /* MINUS  */
  YYSYMBOL_MUL = 16,                       /* MUL  */
  YYSYMBOL_DIV = 17,                       /* DIV  */
  YYSYMBOL_EQUALS = 18,                    /* EQUALS  */
  YYSYMBOL_END = 19,                       /* END  */
  YYSYMBOL_BEG = 20,                       /* BEG  */
  YYSYMBOL_MAIN = 21,                      /* MAIN  */
  YYSYMBOL_DECL = 22,                      /* DECL  */
  YYSYMBOL_ENDDECL = 23,                   /* ENDDECL  */
  YYSYMBOL_BEGINTYPE = 24,                 /* BEGINTYPE  */
  YYSYMBOL_ENDTYPE = 25,                   /* ENDTYPE  */
  YYSYMBOL_BEGINCLASS = 26,                /* BEGINCLASS  */
  YYSYMBOL_ENDCLASS = 27,                  /* ENDCLASS  */
  YYSYMBOL_NEW = 28,                       /* NEW  */
  YYSYMBOL_DELETE = 29,                    /* DELETE  */
  YYSYMBOL_EXTENDS = 30,                   /* EXTENDS  */
  YYSYMBOL_SELF = 31,                      /* SELF  */
  YYSYMBOL_READ = 32,                      /* READ  */
  YYSYMBOL_WRITE = 33,                     /* WRITE  */
  YYSYMBOL_IF = 34,                        /* IF  */
  YYSYMBOL_THEN = 35,                      /* THEN  */
  YYSYMBOL_ELSE = 36,                      /* ELSE  */
  YYSYMBOL_ENDIF = 37,                     /* ENDIF  */
  YYSYMBOL_WHILE = 38,                     /* WHILE  */
  YYSYMBOL_DO = 39,                        /* DO  */
  YYSYMBOL_ENDWHILE = 40,                  /* ENDWHILE  */
  YYSYMBOL_BREAK = 41,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 42,                  /* CONTINUE  */
  YYSYMBOL_REPEAT = 43,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 44,                     /* UNTIL  */
  YYSYMBOL_RETURN = 45,                    /* RETURN  */
  YYSYMBOL_INT = 46,                       /* INT  */
  YYSYMBOL_STR = 47,                       /* STR  */
  YYSYMBOL_INIT = 48,                      /* INIT  */
  YYSYMBOL_ALLOC = 49,                     /* ALLOC  */
  YYSYMBOL_FREE = 50,                      /* FREE  */
  YYSYMBOL_NULLVAL = 51,                   /* NULLVAL  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_58_ = 58,                       /* '['  */
  YYSYMBOL_59_ = 59,                       /* ']'  */
  YYSYMBOL_60_ = 60,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_PROGRAM = 62,                   /* PROGRAM  */
  YYSYMBOL_TypeDefBlock = 63,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 64,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 65,                   /* TypeDef  */
  YYSYMBOL_FieldDeclList = 66,             /* FieldDeclList  */
  YYSYMBOL_ClassDefBlock = 67,             /* ClassDefBlock  */
  YYSYMBOL_ClassDefList = 68,              /* ClassDefList  */
  YYSYMBOL_ClassDef = 69,                  /* ClassDef  */
  YYSYMBOL_Cname = 70,                     /* Cname  */
  YYSYMBOL_MemberDeclList = 71,            /* MemberDeclList  */
  YYSYMBOL_MemberDecl = 72,                /* MemberDecl  */
  YYSYMBOL_MethodDeclList = 73,            /* MethodDeclList  */
  YYSYMBOL_MethodDecl = 74,                /* MethodDecl  */
  YYSYMBOL_MethodDefList = 75,             /* MethodDefList  */
  YYSYMBOL_MethodDef = 76,                 /* MethodDef  */
  YYSYMBOL_GdeclBlock = 77,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 78,                 /* GdeclList  */
  YYSYMBOL_Gdecl = 79,                     /* Gdecl  */
  YYSYMBOL_TYPE = 80,                      /* TYPE  */
  YYSYMBOL_GidList = 81,                   /* GidList  */
  YYSYMBOL_FdefBlock = 82,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 83,                      /* Fdef  */
  YYSYMBOL_ParamList = 84,                 /* ParamList  */
  YYSYMBOL_LdeclBlock = 85,                /* LdeclBlock  */
  YYSYMBOL_LdeclList = 86,                 /* LdeclList  */
  YYSYMBOL_Ldecl = 87,                     /* Ldecl  */
  YYSYMBOL_LidList = 88,                   /* LidList  */
  YYSYMBOL_MainBlock = 89,                 /* MainBlock  */
  YYSYMBOL_Body = 90,                      /* Body  */
  YYSYMBOL_SL = 91,                        /* SL  */
  YYSYMBOL_S = 92,                         /* S  */
  YYSYMBOL_IFST = 93,                      /* IFST  */
  YYSYMBOL_WHILEST = 94,                   /* WHILEST  */
  YYSYMBOL_REPEATST = 95,                  /* REPEATST  */
  YYSYMBOL_DOWHILEST = 96,                 /* DOWHILEST  */
  YYSYMBOL_ASSG = 97,                      /* ASSG  */
  YYSYMBOL_E = 98,                         /* E  */
  YYSYMBOL_IDENTIFIER = 99,                /* IDENTIFIER  */
  YYSYMBOL_FIELD = 100,                    /* FIELD  */
  YYSYMBOL_FIELDFUNCTION = 101,            /* FIELDFUNCTION  */
  YYSYMBOL_ArgList = 102,                  /* ArgList  */
  YYSYMBOL_CONSTANT = 103,                 /* CONSTANT  */
  YYSYMBOL_INPUT = 104,                    /* INPUT  */
  YYSYMBOL_OUTPUT = 105,                   /* OUTPUT  */
  YYSYMBOL_INITIALIZE = 106,               /* INITIALIZE  */
  YYSYMBOL_ALLOCATE = 107                  /* ALLOCATE  */
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
#define YYLAST   721

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  324

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
      55,    56,     2,     2,    57,     2,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    85,    87,    90,    95,   102,   104,   108,
     115,   119,   126,   127,   131,   133,   137,   143,   147,   155,
     157,   161,   166,   168,   172,   179,   181,   185,   202,   207,
     211,   213,   217,   226,   230,   234,   240,   244,   248,   252,
     257,   261,   265,   269,   273,   278,   284,   286,   290,   314,
     319,   324,   330,   333,   337,   339,   343,   348,   352,   360,
     378,   385,   391,   395,   401,   403,   405,   407,   409,   411,
     413,   415,   419,   423,   427,   431,   435,   439,   445,   449,
     455,   461,   467,   474,   478,   482,   486,   491,   496,   501,
     509,   513,   517,   521,   525,   529,   533,   537,   541,   545,
     549,   553,   555,   557,   559,   563,   567,   571,   575,   579,
     583,   587,   593,   597,   602,   608,   612,   617,   621,   625,
     630,   636,   640,   648,   652,   656,   663,   667,   673,   679,
     685
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
  "LT", "LTE", "GT", "GTE", "EQ", "NEQ", "REF", "DEREF", "PLUS", "MINUS",
  "MUL", "DIV", "EQUALS", "END", "BEG", "MAIN", "DECL", "ENDDECL",
  "BEGINTYPE", "ENDTYPE", "BEGINCLASS", "ENDCLASS", "NEW", "DELETE",
  "EXTENDS", "SELF", "READ", "WRITE", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "DO", "ENDWHILE", "BREAK", "CONTINUE", "REPEAT", "UNTIL",
  "RETURN", "INT", "STR", "INIT", "ALLOC", "FREE", "NULLVAL", "'{'", "'}'",
  "';'", "'('", "')'", "','", "'['", "']'", "'.'", "$accept", "PROGRAM",
  "TypeDefBlock", "TypeDefList", "TypeDef", "FieldDeclList",
  "ClassDefBlock", "ClassDefList", "ClassDef", "Cname", "MemberDeclList",
  "MemberDecl", "MethodDeclList", "MethodDecl", "MethodDefList",
  "MethodDef", "GdeclBlock", "GdeclList", "Gdecl", "TYPE", "GidList",
  "FdefBlock", "Fdef", "ParamList", "LdeclBlock", "LdeclList", "Ldecl",
  "LidList", "MainBlock", "Body", "SL", "S", "IFST", "WHILEST", "REPEATST",
  "DOWHILEST", "ASSG", "E", "IDENTIFIER", "FIELD", "FIELDFUNCTION",
  "ArgList", "CONSTANT", "INPUT", "OUTPUT", "INITIALIZE", "ALLOCATE", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      46,    81,    27,   119,    38,    18,  -146,  -146,   145,    -1,
      42,  -146,  -146,   125,     2,  -146,   126,    33,   130,   115,
    -146,  -146,  -146,  -146,    11,   176,   198,  -146,  -146,   177,
    -146,    48,  -146,    45,   163,   130,   218,   115,  -146,  -146,
    -146,   225,   194,  -146,    42,  -146,  -146,   -23,   256,    99,
     206,   208,  -146,  -146,   211,  -146,    42,  -146,   262,    42,
     227,  -146,  -146,   144,   215,    42,  -146,  -146,    51,  -146,
     266,   217,   270,    43,   216,   108,   272,   258,    65,    42,
    -146,   277,    75,  -146,  -146,  -146,    42,   224,    42,   280,
    -146,    64,   268,   234,    19,  -146,   286,   236,    42,   288,
     290,   128,   237,  -146,   293,   142,  -146,   487,   246,   258,
    -146,  -146,   249,   157,  -146,   247,  -146,   257,  -146,   110,
    -146,  -146,    92,    47,   328,   251,   259,   260,   261,   263,
     267,   269,   623,   273,   275,   623,   328,   271,   519,  -146,
     276,   282,   283,   285,   287,   299,    23,   289,   295,  -146,
     268,    42,   296,  -146,   316,  -146,   330,   165,   328,   338,
     121,  -146,  -146,   173,  -146,   291,  -146,   328,  -146,  -146,
     294,  -146,  -146,  -146,    22,   343,    22,   328,   328,   328,
     647,  -146,  -146,   543,   433,    22,   301,  -146,  -146,  -146,
    -146,  -146,  -146,   297,   307,   349,  -146,  -146,   304,   179,
    -146,   302,  -146,  -146,   692,   183,     3,  -146,   356,   365,
     117,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   366,   319,    -6,  -146,   320,    36,   357,   378,   390,
     322,   323,  -146,   324,    60,  -146,   326,   327,   335,   692,
    -146,  -146,   336,   692,  -146,  -146,  -146,   350,  -146,  -146,
     328,   345,   353,   354,  -146,   178,   178,   178,   178,   704,
     704,   228,   228,  -146,  -146,   355,   358,   367,  -146,  -146,
    -146,   376,   381,   328,   328,   372,   379,   441,   396,   397,
     450,   258,   692,   328,   222,   238,   252,  -146,  -146,   623,
     623,   408,   421,  -146,  -146,   399,  -146,  -146,   400,   268,
      98,  -146,   190,  -146,   195,  -146,   202,   447,   567,   381,
    -146,  -146,  -146,   404,  -146,  -146,  -146,  -146,   623,  -146,
    -146,  -146,   599,  -146
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,    13,     0,     0,     8,     1,     0,     0,
       0,     5,     7,    17,     0,    15,     0,     0,     0,     0,
       4,    35,    33,    34,     0,     0,     0,    12,    14,     0,
      29,     0,    31,     0,     0,    33,     0,     0,    47,     3,
       9,     0,     0,    18,     0,    28,    30,    41,     0,     0,
       0,     0,    46,     2,     0,    11,     0,    20,     0,    51,
       0,    45,    32,     0,     0,    51,    10,    19,     0,    23,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
      22,     0,     0,    21,    50,    44,     0,    42,    51,     0,
      40,     0,     0,     0,     0,    26,     0,     0,    51,     0,
       0,     0,     0,    53,     0,     0,    55,     0,     0,     0,
      16,    25,     0,     0,    49,     0,    39,    37,    58,     0,
      52,    54,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
       0,    51,     0,    43,     0,    56,     0,     0,     0,     0,
     105,   107,   124,   105,   123,     0,   125,     0,   106,   102,
     103,   104,   101,    61,     0,     0,     0,     0,     0,     0,
       0,    71,    72,     0,     0,     0,     0,    62,    67,    68,
      69,    70,    64,     0,     0,     0,    65,    66,     0,     0,
      24,     0,    57,   110,   122,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,    73,     0,     0,    60,     0,     0,     0,    83,
      85,    86,     0,    84,    87,   112,    48,     0,    38,   111,
       0,   108,   113,   114,   100,    94,    95,    96,    97,    99,
      98,    90,    91,    92,    93,   112,     0,     0,   126,   127,
     128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,     0,    76,    77,     0,
       0,     0,     0,    74,    75,     0,   129,   130,     0,     0,
       0,   119,     0,   118,     0,   120,     0,     0,     0,    82,
      81,    88,    89,     0,   109,   116,   115,   117,     0,    79,
      80,    27,     0,    78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,  -146,   453,  -146,  -146,  -146,   446,  -146,
    -146,   405,  -146,   394,  -146,   371,  -146,  -146,   435,   193,
    -146,  -146,   430,   -58,  -106,  -146,   363,  -146,     5,  -145,
    -131,  -136,  -146,  -146,  -146,  -146,  -146,   -76,  -107,   -99,
    -146,   -80,  -146,  -146,  -146,  -146,   278
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    24,     9,    14,    15,    16,
      56,    57,    68,    69,    94,    95,    19,    31,    32,    72,
      49,    37,    38,    73,    92,   105,   106,   119,    20,   108,
     138,   139,   140,   141,   142,   143,   144,   204,   169,   170,
     171,   205,   172,   147,   148,   240,   241
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     145,   180,   187,   150,   183,   198,    13,    78,   146,   211,
     212,   213,   214,   215,   216,    21,   161,   217,   218,   219,
     220,    17,     4,    21,    39,   145,   122,     7,   145,    27,
     101,   145,    59,   146,   123,    60,   146,    21,   124,   146,
     113,   194,    53,    11,   187,    18,    21,   187,   168,    47,
     267,   160,    21,   127,   195,    21,    30,    22,    23,   123,
     184,    48,   251,   124,    40,    22,    23,   222,    21,   225,
       1,    45,   110,   145,    79,   223,   145,   226,   233,    22,
      23,   146,   206,   195,   146,     4,   234,   103,    22,    23,
      10,   210,   269,   199,    22,    23,   195,    22,    23,    85,
      86,   227,   228,   229,   211,   212,   213,   214,   215,   216,
      22,    23,   217,   218,   219,   220,   276,   239,   243,    21,
     195,    93,    86,   211,   212,   213,   214,   215,   216,    83,
      98,   217,   218,   219,   220,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,     8,    21,   157,    75,    13,
     158,    34,   159,    62,   313,    26,    63,   314,   307,   308,
      76,    35,    23,    88,   155,   120,    89,   156,   162,   163,
     164,   187,   187,   254,   282,   299,   157,   123,    29,   158,
      42,   124,   145,   145,   116,    86,   187,   322,    22,    23,
     146,   146,   217,   218,   219,   220,   165,   291,   292,    44,
     145,   145,    43,    25,   302,   304,   306,   300,   146,   146,
      33,   145,    36,   152,    86,   145,   166,    41,    50,   146,
     167,   203,    51,   146,    33,   162,   163,   164,   157,    54,
      36,   158,    74,   208,   123,   247,    86,    58,   124,   249,
     250,   162,   163,   164,   219,   220,   315,   250,    55,    70,
     123,   316,   250,   165,   124,   162,   163,   164,   317,   250,
      61,    81,    64,    65,   123,    66,    71,    77,   124,   165,
      82,    83,    96,   166,    84,    87,    90,   167,   301,    99,
      91,    97,   100,   165,   104,   102,   109,    96,   107,   166,
     112,    98,   114,   167,   303,   115,   117,   118,   104,   149,
     162,   163,   164,   166,   151,   173,   153,   167,   305,   123,
     162,   163,   164,   124,   174,   154,   176,   193,   177,   123,
     175,   201,   178,   124,   179,   236,   185,   181,   165,   182,
     188,   162,   163,   164,   202,   242,   189,   190,   165,   191,
     123,   192,   207,   196,   124,   237,   238,   224,   166,   197,
     200,   209,   167,   245,   221,   235,   238,   246,   166,   165,
     252,   248,   167,   211,   212,   213,   214,   215,   216,   253,
     265,   217,   218,   219,   220,   266,   268,   273,   274,   166,
     275,   277,   278,   167,   211,   212,   213,   214,   215,   216,
     279,   280,   217,   218,   219,   220,   211,   212,   213,   214,
     215,   216,   281,   283,   217,   218,   219,   220,   284,   285,
     286,   289,   287,   270,   211,   212,   213,   214,   215,   216,
     290,   288,   217,   218,   219,   220,   293,   211,   212,   213,
     214,   215,   216,   294,   271,   217,   218,   219,   220,   211,
     212,   213,   214,   215,   216,   295,   272,   217,   218,   219,
     220,   122,   296,   297,   298,   311,   312,   321,    12,   123,
      28,    67,    80,   124,   309,   111,    46,    52,   121,     0,
       0,     0,   244,     0,     0,     0,   126,   310,   127,   128,
     129,   130,     0,   318,   319,   131,   132,   232,   133,   134,
     135,   122,   136,     0,     0,     0,     0,   137,     0,   123,
       0,     0,     0,   124,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,   127,   128,
     129,   130,     0,   122,     0,   131,   132,     0,   133,   134,
     135,   123,   136,     0,     0,   124,     0,   137,   186,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   126,     0,
     127,   128,   129,   130,     0,   123,     0,   131,   132,   124,
     133,   134,   135,     0,   136,     0,     0,     0,     0,   137,
       0,   122,   126,     0,   127,   128,   129,   130,     0,   123,
       0,   131,   132,   124,   133,   134,   135,   231,   136,     0,
       0,     0,     0,   137,     0,     0,   126,     0,   127,   128,
     129,   130,     0,   122,     0,   131,   132,   320,   133,   134,
     135,   123,   136,     0,     0,   124,     0,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   126,     0,
     127,   128,   129,   130,     0,   123,   323,   131,   132,   124,
     133,   134,   135,     0,   136,     0,     0,     0,     0,   137,
       0,   122,   126,     0,   127,   128,   129,   130,     0,   123,
       0,   131,   132,   124,   133,   134,   135,     0,   136,     0,
       0,     0,     0,   137,     0,     0,   126,     0,   127,   128,
     129,   130,     0,     0,     0,   230,   132,     0,   133,   134,
     135,     0,   136,     0,     0,     0,     0,   137,   211,   212,
     213,   214,   215,   216,     0,     0,   217,   218,   219,   220,
     211,   212,   213,   214,     0,     0,     0,     0,   217,   218,
     219,   220
};

static const yytype_int16 yycheck[] =
{
     107,   132,   138,   109,   135,   150,     4,    65,   107,     6,
       7,     8,     9,    10,    11,     4,   123,    14,    15,    16,
      17,    22,     4,     4,    19,   132,     4,     0,   135,    27,
      88,   138,    55,   132,    12,    58,   135,     4,    16,   138,
      98,    18,    37,    25,   180,    46,     4,   183,   124,     4,
      56,     4,     4,    31,    60,     4,    23,    46,    47,    12,
     136,    16,    59,    16,    53,    46,    47,   174,     4,   176,
      24,    23,    53,   180,    23,   174,   183,   176,   185,    46,
      47,   180,   158,    60,   183,     4,   185,    23,    46,    47,
      52,   167,    56,   151,    46,    47,    60,    46,    47,    56,
      57,   177,   178,   179,     6,     7,     8,     9,    10,    11,
      46,    47,    14,    15,    16,    17,    56,   193,   194,     4,
      60,    56,    57,     6,     7,     8,     9,    10,    11,    54,
      55,    14,    15,    16,    17,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    26,     4,    55,     4,     4,
      58,    21,    60,    54,   299,    30,    57,    59,   289,   290,
      16,    46,    47,    55,    54,    23,    58,    57,     3,     4,
       5,   307,   308,    56,   250,   281,    55,    12,    52,    58,
       4,    16,   289,   290,    56,    57,   322,   318,    46,    47,
     289,   290,    14,    15,    16,    17,    31,   273,   274,    22,
     307,   308,     4,    10,   284,   285,   286,   283,   307,   308,
      17,   318,    19,    56,    57,   322,    51,    24,    55,   318,
      55,    56,     4,   322,    31,     3,     4,     5,    55,     4,
      37,    58,     5,    60,    12,    56,    57,    44,    16,    56,
      57,     3,     4,     5,    16,    17,    56,    57,    54,    56,
      12,    56,    57,    31,    16,     3,     4,     5,    56,    57,
       4,    68,    56,    55,    12,    54,     4,    52,    16,    31,
       4,    54,    79,    51,     4,    59,     4,    55,    56,    86,
      22,     4,    58,    31,    91,     5,    52,    94,    20,    51,
       4,    55,     4,    55,    56,     5,    59,     4,   105,    53,
       3,     4,     5,    51,    55,    54,    59,    55,    56,    12,
       3,     4,     5,    16,    55,    58,    55,    18,    55,    12,
      60,     5,    55,    16,    55,    28,    55,    54,    31,    54,
      54,     3,     4,     5,     4,    28,    54,    54,    31,    54,
      12,    54,     4,    54,    16,    48,    49,     4,    51,    54,
      54,    60,    55,     4,    60,    54,    49,    53,    51,    31,
       4,    59,    55,     6,     7,     8,     9,    10,    11,     4,
       4,    14,    15,    16,    17,    56,    56,    55,    55,    51,
      56,    55,    55,    55,     6,     7,     8,     9,    10,    11,
      55,    55,    14,    15,    16,    17,     6,     7,     8,     9,
      10,    11,    52,    58,    14,    15,    16,    17,    55,    55,
      55,    35,    54,    56,     6,     7,     8,     9,    10,    11,
      39,    54,    14,    15,    16,    17,    54,     6,     7,     8,
       9,    10,    11,    54,    56,    14,    15,    16,    17,     6,
       7,     8,     9,    10,    11,     4,    56,    14,    15,    16,
      17,     4,    56,    56,     4,    56,    56,    53,     5,    12,
      14,    56,    68,    16,    56,    94,    31,    37,   105,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    29,    56,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    54,    41,    42,
      43,     4,    45,    -1,    -1,    -1,    -1,    50,    -1,    12,
      -1,    -1,    -1,    16,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    -1,     4,    -1,    38,    39,    -1,    41,    42,
      43,    12,    45,    -1,    -1,    16,    -1,    50,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    29,    -1,
      31,    32,    33,    34,    -1,    12,    -1,    38,    39,    16,
      41,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,
      -1,     4,    29,    -1,    31,    32,    33,    34,    -1,    12,
      -1,    38,    39,    16,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    -1,     4,    -1,    38,    39,    40,    41,    42,
      43,    12,    45,    -1,    -1,    16,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    29,    -1,
      31,    32,    33,    34,    -1,    12,    37,    38,    39,    16,
      41,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,
      -1,     4,    29,    -1,    31,    32,    33,    34,    -1,    12,
      -1,    38,    39,    16,    41,    42,    43,    -1,    45,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    -1,    41,    42,
      43,    -1,    45,    -1,    -1,    -1,    -1,    50,     6,     7,
       8,     9,    10,    11,    -1,    -1,    14,    15,    16,    17,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    14,    15,
      16,    17
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    62,    63,     4,    64,    65,     0,    26,    67,
      52,    25,    65,     4,    68,    69,    70,    22,    46,    77,
      89,     4,    46,    47,    66,    80,    30,    27,    69,    52,
      23,    78,    79,    80,    21,    46,    80,    82,    83,    89,
      53,    80,     4,     4,    22,    23,    79,     4,    16,    81,
      55,     4,    83,    89,     4,    54,    71,    72,    80,    55,
      58,     4,    54,    57,    56,    55,    54,    72,    73,    74,
      80,     4,    80,    84,     5,     4,    16,    52,    84,    23,
      74,    80,     4,    54,     4,    56,    57,    59,    55,    58,
       4,    22,    85,    56,    75,    76,    80,     4,    55,    80,
      58,    84,     5,    23,    80,    86,    87,    20,    90,    52,
      53,    76,     4,    84,     4,     5,    56,    59,     4,    88,
      23,    87,     4,    12,    16,    19,    29,    31,    32,    33,
      34,    38,    39,    41,    42,    43,    45,    50,    91,    92,
      93,    94,    95,    96,    97,    99,   100,   104,   105,    53,
      85,    55,    56,    59,    58,    54,    57,    55,    58,    60,
       4,    99,     3,     4,     5,    31,    51,    55,    98,    99,
     100,   101,   103,    54,    55,    60,    55,    55,    55,    55,
      91,    54,    54,    91,    98,    55,    19,    92,    54,    54,
      54,    54,    54,    18,    18,    60,    54,    54,    90,    84,
      54,     5,     4,    56,    98,   102,    98,     4,    60,    60,
      98,     6,     7,     8,     9,    10,    11,    14,    15,    16,
      17,    60,    99,   100,     4,    99,   100,    98,    98,    98,
      38,    44,    54,    99,   100,    54,    28,    48,    49,    98,
     106,   107,    28,    98,   107,     4,    53,    56,    59,    56,
      57,    59,     4,     4,    56,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,     4,    56,    56,    56,    56,
      56,    56,    56,    55,    55,    56,    56,    55,    55,    55,
      55,    52,    98,    58,    55,    55,    55,    54,    54,    35,
      39,    98,    98,    54,    54,     4,    56,    56,     4,    85,
      98,    56,   102,    56,   102,    56,   102,    91,    91,    56,
      56,    56,    56,    90,    59,    56,    56,    56,    36,    37,
      40,    53,    91,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    62,    63,    63,    64,    64,    65,
      66,    66,    67,    67,    68,    68,    69,    70,    70,    71,
      71,    72,    73,    73,    74,    75,    75,    76,    77,    77,
      78,    78,    79,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    83,    84,
      84,    84,    85,    85,    86,    86,    87,    88,    88,    89,
      90,    90,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    95,    96,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   101,   101,   101,   101,   101,
     101,   102,   102,   103,   103,   103,   104,   104,   105,   106,
     107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     2,     1,     4,
       4,     3,     3,     0,     2,     1,     8,     1,     3,     2,
       1,     3,     2,     1,     6,     2,     1,     9,     3,     2,
       2,     1,     3,     1,     1,     1,     3,     6,     9,     6,
       4,     1,     4,     7,     4,     2,     2,     1,     9,     4,
       2,     0,     3,     2,     2,     1,     3,     3,     1,     8,
       4,     3,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     5,     5,     5,     5,     9,     7,
       7,     6,     6,     3,     3,     3,     3,     3,     6,     6,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     2,     2,     4,     7,
       3,     4,     3,     3,     3,     6,     6,     6,     5,     5,
       5,     3,     1,     1,     1,     1,     4,     4,     4,     3,
       3
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
#line 90 "parser.y"
                                          {
             printf("All Type definitions parsed.\n");
             printTT();
             }
#line 1659 "y.tab.c"
    break;

  case 6: /* TypeDefBlock: %empty  */
#line 95 "parser.y"
             {
             printf("No Type definitions present\n");
             printTT();
             }
#line 1668 "y.tab.c"
    break;

  case 9: /* TypeDef: ID '{' FieldDeclList '}'  */
#line 108 "parser.y"
                                 {
         addTTNode((yyvsp[-3].string),getFLSize((yyvsp[-1].fieldlist)),(yyvsp[-1].fieldlist));
         addTypes((yyvsp[-1].fieldlist));
        }
#line 1677 "y.tab.c"
    break;

  case 10: /* FieldDeclList: FieldDeclList TYPE ID ';'  */
#line 115 "parser.y"
                                        {
              (yyval.fieldlist) = addFLNode((yyvsp[-3].fieldlist),(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1685 "y.tab.c"
    break;

  case 11: /* FieldDeclList: TYPE ID ';'  */
#line 119 "parser.y"
                          {
              (yyval.fieldlist) = addFLNode(NULL,(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1693 "y.tab.c"
    break;

  case 16: /* ClassDef: Cname '{' DECL MemberDeclList MethodDeclList ENDDECL MethodDefList '}'  */
#line 137 "parser.y"
                                                                                {
         printClass(C);
         }
#line 1701 "y.tab.c"
    break;

  case 17: /* Cname: ID  */
#line 143 "parser.y"
         {
      C = addClassNode((yyvsp[0].string),NULL);
      }
#line 1709 "y.tab.c"
    break;

  case 18: /* Cname: ID EXTENDS ID  */
#line 147 "parser.y"
                    {
      C = addClassNode((yyvsp[-2].string),lookClassUp((yyvsp[0].string)));
      copyMembers(lookClassUp((yyvsp[-2].string)),lookClassUp((yyvsp[0].string)));
      copyMethods(lookClassUp((yyvsp[-2].string)),lookClassUp((yyvsp[0].string)));
      }
#line 1719 "y.tab.c"
    break;

  case 21: /* MemberDecl: TYPE ID ';'  */
#line 161 "parser.y"
                  {
        addMemberToClass(C,lookTTUp((yyvsp[-2].string)),lookClassUp((yyvsp[-2].string)),(yyvsp[-1].string));
      }
#line 1727 "y.tab.c"
    break;

  case 24: /* MethodDecl: TYPE ID '(' ParamList ')' ';'  */
#line 172 "parser.y"
                                    { 
        addMethodToClass(C,lookTTUp((yyvsp[-5].string)),(yyvsp[-4].string),(yyvsp[-2].paramlist));
        deleteLSymbolTable();
      }
#line 1736 "y.tab.c"
    break;

  case 27: /* MethodDef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 185 "parser.y"
                                                            {

          checkDeclDef(C,lookTTUp((yyvsp[-8].string)),(yyvsp[-7].string),(yyvsp[-5].paramlist));

          int size = getParamSize((yyvsp[-5].paramlist));
          addSelfToLSymbolTable(C,size);

          getLSymbolTable();

          define_method_codeGen(xsm,C,(yyvsp[-7].string),(yyvsp[-5].paramlist),(yyvsp[-1].node));

          deleteLSymbolTable();
          }
#line 1754 "y.tab.c"
    break;

  case 28: /* GdeclBlock: DECL GdeclList ENDDECL  */
#line 202 "parser.y"
                                   {
                C = NULL;
                getGSymbolTable();
              }
#line 1763 "y.tab.c"
    break;

  case 32: /* Gdecl: TYPE GidList ';'  */
#line 217 "parser.y"
                      {
          if( !lookGUp("main") ){
              addGSymbol("main",lookTTUp("int"),NULL,1,1,NULL,1,0,0,0); 
          }
          addAllGSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)),lookClassUp((yyvsp[-2].string)));
     }
#line 1774 "y.tab.c"
    break;

  case 33: /* TYPE: INT  */
#line 226 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1782 "y.tab.c"
    break;

  case 34: /* TYPE: STR  */
#line 230 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1790 "y.tab.c"
    break;

  case 35: /* TYPE: ID  */
#line 234 "parser.y"
        {
     (yyval.string) = (yyvsp[0].string);  
     }
#line 1798 "y.tab.c"
    break;

  case 36: /* GidList: GidList ',' ID  */
#line 240 "parser.y"
                       {
          (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1806 "y.tab.c"
    break;

  case 37: /* GidList: GidList ',' ID '[' NUM ']'  */
#line 244 "parser.y"
                                   {
          (yyval.list) = addArray((yyvsp[-5].list),(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1814 "y.tab.c"
    break;

  case 38: /* GidList: GidList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 248 "parser.y"
                                               {
          (yyval.list) = addArray((yyvsp[-8].list),(yyvsp[-8].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1822 "y.tab.c"
    break;

  case 39: /* GidList: GidList ',' ID '(' ParamList ')'  */
#line 252 "parser.y"
                                         {
          (yyval.list) = addFunction((yyvsp[-5].list),(yyvsp[-3].string),(yyvsp[-1].paramlist));
          deleteLSymbolTable();
        }
#line 1831 "y.tab.c"
    break;

  case 40: /* GidList: GidList ',' MUL ID  */
#line 257 "parser.y"
                           {
          (yyval.list) = addPointer((yyvsp[-3].list),(yyvsp[0].string));
        }
#line 1839 "y.tab.c"
    break;

  case 41: /* GidList: ID  */
#line 261 "parser.y"
           {
          (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1847 "y.tab.c"
    break;

  case 42: /* GidList: ID '[' NUM ']'  */
#line 265 "parser.y"
                       {
          (yyval.list) = addArray(NULL,(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1855 "y.tab.c"
    break;

  case 43: /* GidList: ID '[' NUM ']' '[' NUM ']'  */
#line 269 "parser.y"
                                   {
          (yyval.list) = addArray(NULL,(yyvsp[-6].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1863 "y.tab.c"
    break;

  case 44: /* GidList: ID '(' ParamList ')'  */
#line 273 "parser.y"
                             { 
          (yyval.list) = addFunction(NULL,(yyvsp[-3].string),(yyvsp[-1].paramlist));
          deleteLSymbolTable();
        }
#line 1872 "y.tab.c"
    break;

  case 45: /* GidList: MUL ID  */
#line 278 "parser.y"
               {
          (yyval.list) = addPointer(NULL,(yyvsp[0].string));
        }
#line 1880 "y.tab.c"
    break;

  case 48: /* Fdef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 290 "parser.y"
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
#line 1905 "y.tab.c"
    break;

  case 49: /* ParamList: ParamList ',' TYPE ID  */
#line 314 "parser.y"
                                {
           (yyval.paramlist) = addParameter((yyvsp[-3].paramlist),(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1914 "y.tab.c"
    break;

  case 50: /* ParamList: TYPE ID  */
#line 319 "parser.y"
                  {
           (yyval.paramlist) = addParameter(NULL,(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1923 "y.tab.c"
    break;

  case 51: /* ParamList: %empty  */
#line 324 "parser.y"
           {
           (yyval.paramlist) = NULL;
          }
#line 1931 "y.tab.c"
    break;

  case 52: /* LdeclBlock: DECL LdeclList ENDDECL  */
#line 330 "parser.y"
                                  {
           }
#line 1938 "y.tab.c"
    break;

  case 56: /* Ldecl: TYPE LidList ';'  */
#line 343 "parser.y"
                       {
         addAllLSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)));
      }
#line 1946 "y.tab.c"
    break;

  case 57: /* LidList: LidList ',' ID  */
#line 348 "parser.y"
                       {
        (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1954 "y.tab.c"
    break;

  case 58: /* LidList: ID  */
#line 352 "parser.y"
           {
        (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1962 "y.tab.c"
    break;

  case 59: /* MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 360 "parser.y"
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
#line 1983 "y.tab.c"
    break;

  case 60: /* Body: BEG SL END ';'  */
#line 378 "parser.y"
                 {
    (yyval.node) = (yyvsp[-2].node);
    root = (yyvsp[-2].node);
    printf("Valid Program.\n");
    Inorder((yyvsp[-2].node));
  }
#line 1994 "y.tab.c"
    break;

  case 61: /* Body: BEG END ';'  */
#line 385 "parser.y"
              {
  printf("Valid program.\n");
  }
#line 2002 "y.tab.c"
    break;

  case 62: /* SL: SL S  */
#line 391 "parser.y"
         {
   (yyval.node) = createOpNode(NULL,13,(yyvsp[-1].node),(yyvsp[0].node));
  }
#line 2010 "y.tab.c"
    break;

  case 63: /* SL: S  */
#line 395 "parser.y"
      {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2018 "y.tab.c"
    break;

  case 71: /* S: BREAK ';'  */
#line 415 "parser.y"
            {
    (yyval.node) = createOpNode(NULL,16,NULL,NULL);
  }
#line 2026 "y.tab.c"
    break;

  case 72: /* S: CONTINUE ';'  */
#line 419 "parser.y"
               {
    (yyval.node) = createOpNode(NULL,17,NULL,NULL);
  }
#line 2034 "y.tab.c"
    break;

  case 73: /* S: RETURN E ';'  */
#line 423 "parser.y"
               {
    (yyval.node) = createReturnNode((yyvsp[-1].node));
  }
#line 2042 "y.tab.c"
    break;

  case 74: /* S: FREE '(' IDENTIFIER ')' ';'  */
#line 427 "parser.y"
                              {
    (yyval.node) = createFreeNode((yyvsp[-2].node));
  }
#line 2050 "y.tab.c"
    break;

  case 75: /* S: FREE '(' FIELD ')' ';'  */
#line 431 "parser.y"
                         {
    (yyval.node) = createFreeNode((yyvsp[-2].node));
  }
#line 2058 "y.tab.c"
    break;

  case 76: /* S: DELETE '(' IDENTIFIER ')' ';'  */
#line 435 "parser.y"
                                {
    (yyval.node) = createDeleteNode((yyvsp[-2].node));
  }
#line 2066 "y.tab.c"
    break;

  case 77: /* S: DELETE '(' FIELD ')' ';'  */
#line 439 "parser.y"
                           {
    (yyval.node) = createDeleteNode((yyvsp[-2].node));
  }
#line 2074 "y.tab.c"
    break;

  case 78: /* IFST: IF '(' E ')' THEN SL ELSE SL ENDIF  */
#line 445 "parser.y"
                                        {
      (yyval.node) = createIfNode((yyvsp[-6].node),(yyvsp[-3].node),(yyvsp[-1].node));
    }
#line 2082 "y.tab.c"
    break;

  case 79: /* IFST: IF '(' E ')' THEN SL ENDIF  */
#line 449 "parser.y"
                               {
      (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-1].node),NULL);
    }
#line 2090 "y.tab.c"
    break;

  case 80: /* WHILEST: WHILE '(' E ')' DO SL ENDWHILE  */
#line 455 "parser.y"
                                       {
        (yyval.node) = createWhileNode(15,(yyvsp[-4].node),(yyvsp[-1].node));
        }
#line 2098 "y.tab.c"
    break;

  case 81: /* REPEATST: REPEAT SL UNTIL '(' E ')'  */
#line 461 "parser.y"
                                   {
         (yyval.node) = createWhileNode(18,(yyvsp[-1].node),(yyvsp[-4].node));
        }
#line 2106 "y.tab.c"
    break;

  case 82: /* DOWHILEST: DO SL WHILE '(' E ')'  */
#line 467 "parser.y"
                                { 
          (yyval.node) = createWhileNode(19,(yyvsp[-1].node),(yyvsp[-4].node));
          }
#line 2114 "y.tab.c"
    break;

  case 83: /* ASSG: IDENTIFIER EQUALS E  */
#line 474 "parser.y"
                      {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2122 "y.tab.c"
    break;

  case 84: /* ASSG: FIELD EQUALS E  */
#line 478 "parser.y"
                 {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2130 "y.tab.c"
    break;

  case 85: /* ASSG: IDENTIFIER EQUALS INITIALIZE  */
#line 482 "parser.y"
                               {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2138 "y.tab.c"
    break;

  case 86: /* ASSG: IDENTIFIER EQUALS ALLOCATE  */
#line 486 "parser.y"
                             {
  (yyvsp[0].node)->type = (yyvsp[-2].node)->type;
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2147 "y.tab.c"
    break;

  case 87: /* ASSG: FIELD EQUALS ALLOCATE  */
#line 491 "parser.y"
                        {
  (yyvsp[0].node)->type = lookTTUp(getName((yyvsp[-2].node)));
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2156 "y.tab.c"
    break;

  case 88: /* ASSG: IDENTIFIER EQUALS NEW '(' ID ')'  */
#line 496 "parser.y"
                                   {
  struct TreeNode* RHS = createNewNode((yyvsp[-1].string));
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-5].node),RHS);
  }
#line 2165 "y.tab.c"
    break;

  case 89: /* ASSG: FIELD EQUALS NEW '(' ID ')'  */
#line 501 "parser.y"
                              {
  struct TreeNode* RHS = createNewNode((yyvsp[-1].string));
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-5].node),RHS);
  }
#line 2174 "y.tab.c"
    break;

  case 90: /* E: E PLUS E  */
#line 509 "parser.y"
           {
  (yyval.node) = createOpNode(lookTTUp("int"),0,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2182 "y.tab.c"
    break;

  case 91: /* E: E MINUS E  */
#line 513 "parser.y"
            {
  (yyval.node) = createOpNode(lookTTUp("int"),1,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2190 "y.tab.c"
    break;

  case 92: /* E: E MUL E  */
#line 517 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),2,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2198 "y.tab.c"
    break;

  case 93: /* E: E DIV E  */
#line 521 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),3,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2206 "y.tab.c"
    break;

  case 94: /* E: E LT E  */
#line 525 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),5,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2214 "y.tab.c"
    break;

  case 95: /* E: E LTE E  */
#line 529 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),6,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2222 "y.tab.c"
    break;

  case 96: /* E: E GT E  */
#line 533 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),7,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2230 "y.tab.c"
    break;

  case 97: /* E: E GTE E  */
#line 537 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),8,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2238 "y.tab.c"
    break;

  case 98: /* E: E NEQ E  */
#line 541 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),9,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2246 "y.tab.c"
    break;

  case 99: /* E: E EQ E  */
#line 545 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),10,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2254 "y.tab.c"
    break;

  case 100: /* E: '(' E ')'  */
#line 549 "parser.y"
            {
  (yyval.node) = (yyvsp[-1].node);
  }
#line 2262 "y.tab.c"
    break;

  case 105: /* IDENTIFIER: ID  */
#line 563 "parser.y"
              { 
            (yyval.node) = createIdNode((yyvsp[0].string),NULL,NULL);
           }
#line 2270 "y.tab.c"
    break;

  case 106: /* IDENTIFIER: MUL E  */
#line 567 "parser.y"
                             {
            (yyval.node) = createOpNode(lookTTUp("int"),27,(yyvsp[0].node),NULL);
           }
#line 2278 "y.tab.c"
    break;

  case 107: /* IDENTIFIER: REF IDENTIFIER  */
#line 571 "parser.y"
                          {
           (yyval.node) = createOpNode(lookTTUp("ptr"),26,(yyvsp[0].node),NULL);
           }
#line 2286 "y.tab.c"
    break;

  case 108: /* IDENTIFIER: ID '[' E ']'  */
#line 575 "parser.y"
                        {
            (yyval.node) = createIdNode((yyvsp[-3].string),NULL,(yyvsp[-1].node));
            }
#line 2294 "y.tab.c"
    break;

  case 109: /* IDENTIFIER: ID '[' E ']' '[' E ']'  */
#line 579 "parser.y"
                                  {
            (yyval.node) = createIdNode((yyvsp[-6].string),(yyvsp[-4].node),(yyvsp[-1].node));
            }
#line 2302 "y.tab.c"
    break;

  case 110: /* IDENTIFIER: ID '(' ')'  */
#line 583 "parser.y"
                       {
            (yyval.node) = createFunctionNode((yyvsp[-2].string),NULL);
            }
#line 2310 "y.tab.c"
    break;

  case 111: /* IDENTIFIER: ID '(' ArgList ')'  */
#line 587 "parser.y"
                               { 
            (yyval.node) = createFunctionNode((yyvsp[-3].string),(yyvsp[-1].node));
            }
#line 2318 "y.tab.c"
    break;

  case 112: /* FIELD: FIELD '.' ID  */
#line 593 "parser.y"
                   {
      (yyval.node) = addFieldToEnd((yyvsp[-2].node),(yyvsp[0].string));
      }
#line 2326 "y.tab.c"
    break;

  case 113: /* FIELD: ID '.' ID  */
#line 597 "parser.y"
                {
      (yyval.node) = createIdNode((yyvsp[-2].string),NULL,NULL);
      (yyval.node) = addFieldToEnd((yyval.node),(yyvsp[0].string));
      }
#line 2335 "y.tab.c"
    break;

  case 114: /* FIELD: SELF '.' ID  */
#line 602 "parser.y"
                  {
      (yyval.node) = createSelfNode(C,(yyvsp[0].string),NULL);
      }
#line 2343 "y.tab.c"
    break;

  case 115: /* FIELDFUNCTION: SELF '.' ID '(' ArgList ')'  */
#line 608 "parser.y"
                                          {
              (yyval.node) = createSelfNode(C,(yyvsp[-3].string),(yyvsp[-1].node));
              }
#line 2351 "y.tab.c"
    break;

  case 116: /* FIELDFUNCTION: ID '.' ID '(' ArgList ')'  */
#line 612 "parser.y"
                                        {
              (yyval.node) = createIdNode((yyvsp[-5].string),NULL,NULL);
              (yyval.node) = addMethodToEnd((yyval.node),(yyvsp[-3].string),(yyvsp[-1].node));
              }
#line 2360 "y.tab.c"
    break;

  case 117: /* FIELDFUNCTION: FIELD '.' ID '(' ArgList ')'  */
#line 617 "parser.y"
                                           {
              (yyval.node) = addMethodToEnd((yyvsp[-5].node),(yyvsp[-3].string),(yyvsp[-1].node));
              }
#line 2368 "y.tab.c"
    break;

  case 118: /* FIELDFUNCTION: SELF '.' ID '(' ')'  */
#line 621 "parser.y"
                                  {
              (yyval.node) = createSelfNode(C,(yyvsp[-2].string),NULL);
              }
#line 2376 "y.tab.c"
    break;

  case 119: /* FIELDFUNCTION: ID '.' ID '(' ')'  */
#line 625 "parser.y"
                                {
              (yyval.node) = createIdNode((yyvsp[-4].string),NULL,NULL);
              (yyval.node) = addMethodToEnd((yyval.node),(yyvsp[-2].string),NULL);
              }
#line 2385 "y.tab.c"
    break;

  case 120: /* FIELDFUNCTION: FIELD '.' ID '(' ')'  */
#line 630 "parser.y"
                                   {
                (yyval.node) = addMethodToEnd((yyvsp[-4].node),(yyvsp[-2].string),NULL);
              }
#line 2393 "y.tab.c"
    break;

  case 121: /* ArgList: ArgList ',' E  */
#line 636 "parser.y"
                      {
        (yyval.node) = addArgToList((yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2401 "y.tab.c"
    break;

  case 122: /* ArgList: E  */
#line 641 "parser.y"
        {
        (yyval.node) = (yyvsp[0].node);
        }
#line 2409 "y.tab.c"
    break;

  case 123: /* CONSTANT: NUM  */
#line 648 "parser.y"
             {
          (yyval.node) = createNumNode(atoi((yyvsp[0].string)));
          }
#line 2417 "y.tab.c"
    break;

  case 124: /* CONSTANT: STRING  */
#line 652 "parser.y"
                {
          (yyval.node) = createStringNode((yyvsp[0].string));
          }
#line 2425 "y.tab.c"
    break;

  case 125: /* CONSTANT: NULLVAL  */
#line 656 "parser.y"
                 {
          (yyval.node) = createNullNode();
          }
#line 2433 "y.tab.c"
    break;

  case 126: /* INPUT: READ '(' IDENTIFIER ')'  */
#line 663 "parser.y"
                               {
       (yyval.node) = createOpNode(NULL,11,(yyvsp[-1].node),NULL);
      }
#line 2441 "y.tab.c"
    break;

  case 127: /* INPUT: READ '(' FIELD ')'  */
#line 667 "parser.y"
                         {
      (yyval.node) = createOpNode(NULL,11,(yyvsp[-1].node),NULL);
      }
#line 2449 "y.tab.c"
    break;

  case 128: /* OUTPUT: WRITE '(' E ')'  */
#line 673 "parser.y"
                       {
        (yyval.node) = createOpNode(NULL,12,(yyvsp[-1].node),NULL);
      }
#line 2457 "y.tab.c"
    break;

  case 129: /* INITIALIZE: INIT '(' ')'  */
#line 679 "parser.y"
                        {
           (yyval.node) = createOpNode(lookTTUp("int"),21,NULL,NULL);
           }
#line 2465 "y.tab.c"
    break;

  case 130: /* ALLOCATE: ALLOC '(' ')'  */
#line 685 "parser.y"
                       {
         (yyval.node) = createOpNode(lookTTUp("int"),22,NULL,NULL);
         }
#line 2473 "y.tab.c"
    break;


#line 2477 "y.tab.c"

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

#line 691 "parser.y"



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
