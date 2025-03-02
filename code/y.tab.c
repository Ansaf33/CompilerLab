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
#line 42 "parser.y"

  struct TreeNode* node;
  char* string;
  int integer;
  struct list* list;
  struct paramlist* paramlist;
  struct Lsymbol* Lsymbol;
  struct typetable* typetable;
  struct fieldlist* fieldlist;



#line 276 "y.tab.c"

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
#define YYLAST   563

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  309

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
       0,    83,    83,    85,    87,    90,    95,   102,   104,   108,
     115,   119,   126,   127,   131,   133,   137,   143,   147,   151,
     153,   157,   162,   164,   168,   175,   177,   181,   198,   203,
     207,   209,   213,   222,   226,   230,   236,   240,   244,   248,
     253,   257,   261,   265,   272,   274,   278,   302,   307,   312,
     318,   321,   325,   327,   331,   336,   340,   348,   366,   373,
     379,   383,   389,   391,   393,   395,   397,   399,   401,   403,
     407,   411,   415,   419,   425,   429,   435,   441,   447,   454,
     458,   462,   466,   471,   476,   484,   488,   492,   496,   500,
     504,   508,   512,   516,   520,   524,   528,   530,   532,   534,
     538,   542,   546,   550,   554,   560,   564,   569,   575,   579,
     584,   588,   592,   597,   603,   607,   615,   619,   623,   630,
     634,   640,   646,   652
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

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,     8,    27,    23,    44,    14,  -141,  -141,    60,   -12,
     134,  -141,  -141,    38,    11,  -141,    77,   103,   122,   323,
    -141,  -141,  -141,  -141,     6,   147,   170,  -141,  -141,   161,
    -141,   208,  -141,   192,   141,   122,   194,   323,  -141,  -141,
    -141,   221,   204,  -141,   134,  -141,  -141,    76,     7,   174,
     182,  -141,  -141,   248,  -141,   134,  -141,   301,   134,   310,
    -141,   315,   270,   134,  -141,  -141,   371,  -141,   317,   271,
     318,   -16,   267,    80,   305,    17,   134,  -141,   324,   136,
    -141,  -141,  -141,   134,   273,   134,   325,   375,   313,   283,
     101,  -141,   328,   281,   134,   365,   330,    66,   314,  -141,
     366,   421,  -141,   178,   321,   305,  -141,  -141,   320,   176,
    -141,   319,  -141,   322,  -141,    87,  -141,  -141,   -42,   329,
     327,   326,   333,   334,   335,   336,   479,   338,   339,   479,
     114,   340,   404,  -141,   342,   346,   360,   362,   372,   361,
      -9,   374,   376,  -141,   313,   134,   377,  -141,   378,  -141,
     413,    16,   114,   418,  -141,   423,   426,     5,   114,   114,
     114,   494,  -141,  -141,   419,  -141,    70,  -141,   379,  -141,
     114,   351,  -141,   380,  -141,  -141,   423,   387,  -141,  -141,
    -141,  -141,  -141,  -141,   187,   198,   428,  -141,  -141,   403,
     183,  -141,   400,  -141,  -141,   537,   190,    68,  -141,   167,
     409,  -141,   410,   -10,   252,   262,   272,   416,   417,   467,
     468,   282,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,  -141,   469,   420,  -141,   422,   424,   429,   537,
    -141,  -141,   431,   537,  -141,  -141,   332,  -141,  -141,   114,
     446,   461,  -141,  -141,  -141,   481,   480,   114,   114,   475,
     476,  -141,   299,   299,   299,   299,   295,   295,   227,   227,
    -141,  -141,   483,   486,   528,   485,   487,   536,   305,   537,
     114,  -141,   479,   479,   331,   341,   105,   108,   111,  -141,
     499,  -141,  -141,   500,   313,    78,   370,   449,   480,  -141,
    -141,   200,  -141,   244,  -141,   263,  -141,  -141,   504,  -141,
     479,  -141,  -141,  -141,  -141,  -141,  -141,   464,  -141
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
      47,     0,    39,    37,    56,     0,    50,    52,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,    49,     0,    42,     0,    54,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,    69,    70,     0,   117,   100,   116,     0,   118,
       0,     0,    97,    98,    99,    96,     0,     0,    60,    65,
      66,    67,    68,    62,     0,     0,     0,    63,    64,     0,
       0,    24,     0,    55,   103,   115,     0,     0,   106,   100,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,    58,     0,     0,     0,    79,
      81,    82,     0,    80,   105,    46,     0,    38,   104,     0,
     101,     0,   119,   120,   121,     0,     0,     0,     0,   106,
     107,    95,    89,    90,    91,    92,    94,    93,    85,    86,
      87,    88,   105,     0,     0,     0,     0,     0,     0,   114,
       0,    73,     0,     0,     0,     0,     0,     0,     0,    72,
       0,   122,   123,     0,     0,     0,     0,     0,    78,    77,
     112,     0,   111,     0,   113,     0,    83,    84,     0,   102,
       0,    75,    76,   109,   108,   110,    27,     0,    74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,   551,  -141,  -141,  -141,   543,  -141,
    -141,   503,  -141,   493,  -141,   470,  -141,  -141,   530,   156,
    -141,  -141,   525,   -39,  -100,  -141,   462,  -141,     3,  -140,
    -123,  -131,  -141,  -141,  -141,  -141,  -141,  -117,  -103,  -101,
    -141,   -28,  -141,  -141,  -141,  -141,  -141
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    24,     9,    14,    15,    16,
      55,    56,    66,    67,    90,    91,    19,    31,    32,    70,
      48,    37,    38,    71,    88,   101,   102,   115,    20,   104,
     132,   133,   134,   135,   136,   137,   138,   195,   172,   173,
     174,   196,   175,   141,   142,   230,   231
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     139,   178,   140,   161,   189,   144,   164,   185,    17,   118,
      21,   151,     4,   171,   152,    13,   153,     1,     4,   165,
     166,   167,    39,   139,    75,   140,   139,     7,   140,   139,
     178,   140,    18,   178,   121,   197,    27,    11,    82,    83,
      52,   204,   205,   206,   243,   168,    97,     8,   186,   186,
      22,    23,   200,   211,   202,   109,   203,    40,   139,    60,
     140,   139,    61,   140,    13,   169,    26,   229,   233,   170,
     194,    89,    83,   224,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    10,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,    21,   190,    21,   165,   166,
     167,   165,   166,   167,   165,   166,   167,   165,   166,   167,
     112,    83,   269,   151,    30,   240,   152,    29,   209,    58,
     274,   275,    59,    85,   168,   299,    86,   168,    21,   149,
     168,    34,   150,   168,   298,    22,    23,    22,    23,   286,
     287,    42,   106,   285,   169,   178,   178,   169,   170,   290,
     169,   170,   292,   169,   170,   294,    25,   170,   284,   139,
     139,   140,   140,    33,    43,    36,   178,   307,    22,    23,
      41,    44,   118,   139,   139,   140,   140,    33,    80,    94,
     165,   166,   167,    36,    49,   119,    47,   139,    50,   140,
      57,   165,   166,   167,   139,   120,   140,   121,   122,   123,
     124,    68,    21,   226,   125,   126,   168,   127,   128,   129,
     151,   130,    78,   152,   232,    53,   131,   168,    62,    45,
     146,    83,    92,   227,   228,    63,   169,   236,    83,    95,
     170,   220,   221,   100,   238,   239,    92,   169,   291,   293,
     295,   170,    22,    23,   303,   239,    54,   100,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   304,   239,
      64,   212,   213,   214,   215,    69,   244,   218,   219,   220,
     221,   218,   219,   220,   221,    72,   245,   305,   239,    73,
      74,    79,    81,    80,    84,    87,   246,    21,    93,    96,
      98,   103,   108,   105,    94,   111,   251,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    35,    23,   110,
     114,   113,   143,   145,   118,    21,   147,   184,   148,    21,
     155,   154,   268,   192,   156,   288,   157,   158,   159,   160,
     162,   163,    76,   176,   179,   289,    99,   120,   180,   121,
     122,   123,   124,   222,   300,   301,   125,   126,   118,   127,
     128,   129,   181,   130,   182,    22,    23,   193,   131,    22,
      23,   177,   198,   118,   183,    21,   187,   199,   188,   191,
     201,   120,   234,   121,   122,   123,   124,   210,   223,   225,
     125,   126,   116,   127,   128,   129,   120,   130,   121,   122,
     123,   124,   131,   118,   235,   125,   126,   237,   127,   128,
     129,   208,   130,   241,   242,    22,    23,   131,   118,   247,
     248,   249,   250,   262,   263,   264,   120,   265,   121,   122,
     123,   124,   266,   118,   267,   125,   126,   302,   127,   128,
     129,   120,   130,   121,   122,   123,   124,   131,   118,   308,
     125,   126,   270,   127,   128,   129,   120,   130,   121,   122,
     123,   124,   131,   271,   272,   125,   126,   273,   127,   128,
     129,   120,   130,   121,   122,   123,   124,   131,   276,   277,
     207,   126,   280,   127,   128,   129,   278,   130,   279,   281,
     283,   282,   131,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   296,   297,   306,    12,    28,    65,    77,
     107,    46,    51,   117
};

static const yytype_int16 yycheck[] =
{
     103,   132,   103,   126,   144,   105,   129,    16,    20,     4,
       4,    53,     4,   130,    56,     4,    58,    22,     4,     3,
       4,     5,    19,   126,    63,   126,   129,     0,   129,   132,
     161,   132,    44,   164,    29,   152,    25,    23,    54,    55,
      37,   158,   159,   160,    54,    29,    85,    24,    58,    58,
      44,    45,   155,   170,   157,    94,   157,    51,   161,    52,
     161,   164,    55,   164,     4,    49,    28,   184,   185,    53,
      54,    54,    55,   176,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    50,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,     4,   145,     4,     3,     4,
       5,     3,     4,     5,     3,     4,     5,     3,     4,     5,
      54,    55,   239,    53,    21,    57,    56,    50,    58,    53,
     247,   248,    56,    53,    29,    57,    56,    29,     4,    52,
      29,    19,    55,    29,   284,    44,    45,    44,    45,   272,
     273,     4,    51,   270,    49,   286,   287,    49,    53,    54,
      49,    53,    54,    49,    53,    54,    10,    53,   268,   272,
     273,   272,   273,    17,     4,    19,   307,   300,    44,    45,
      24,    20,     4,   286,   287,   286,   287,    31,    52,    53,
       3,     4,     5,    37,    53,    17,     4,   300,     4,   300,
      44,     3,     4,     5,   307,    27,   307,    29,    30,    31,
      32,    55,     4,    26,    36,    37,    29,    39,    40,    41,
      53,    43,    66,    56,    26,     4,    48,    29,    54,    21,
      54,    55,    76,    46,    47,    53,    49,    54,    55,    83,
      53,    14,    15,    87,    54,    55,    90,    49,   276,   277,
     278,    53,    44,    45,    54,    55,    52,   101,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    54,    55,
      52,     6,     7,     8,     9,     4,    54,    12,    13,    14,
      15,    12,    13,    14,    15,     5,    54,    54,    55,     4,
      50,     4,     4,    52,    57,    20,    54,     4,     4,    56,
       5,    18,     4,    50,    53,     5,    54,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    44,    45,     4,
       4,    57,    51,    53,     4,     4,    57,    16,    56,     4,
      53,    52,    50,     5,    58,    54,    53,    53,    53,    53,
      52,    52,    21,    53,    52,    54,    21,    27,    52,    29,
      30,    31,    32,    52,    34,    35,    36,    37,     4,    39,
      40,    41,    52,    43,    52,    44,    45,     4,    48,    44,
      45,    17,     4,     4,    52,     4,    52,     4,    52,    52,
       4,    27,     4,    29,    30,    31,    32,    58,    58,    52,
      36,    37,    21,    39,    40,    41,    27,    43,    29,    30,
      31,    32,    48,     4,    51,    36,    37,    57,    39,    40,
      41,    42,    43,    54,    54,    44,    45,    48,     4,    53,
      53,     4,     4,     4,    54,    53,    27,    53,    29,    30,
      31,    32,    53,     4,    53,    36,    37,    38,    39,    40,
      41,    27,    43,    29,    30,    31,    32,    48,     4,    35,
      36,    37,    56,    39,    40,    41,    27,    43,    29,    30,
      31,    32,    48,    52,    33,    36,    37,    37,    39,    40,
      41,    27,    43,    29,    30,    31,    32,    48,    53,    53,
      36,    37,     4,    39,    40,    41,    53,    43,    52,    54,
       4,    54,    48,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    54,    54,    51,     5,    14,    55,    66,
      90,    31,    37,   101
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
      82,    52,     5,     4,    54,    96,   100,    96,     4,     4,
      97,     4,    97,    98,    96,    96,    96,    36,    42,    58,
      58,    96,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    52,    58,    97,    52,    26,    46,    47,    96,
     104,   105,    26,    96,     4,    51,    54,    57,    54,    55,
      57,    54,    54,    54,    54,    54,    54,    53,    53,     4,
       4,    54,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,     4,    54,    53,    53,    53,    53,    50,    96,
      56,    52,    33,    37,    96,    96,    53,    53,    53,    52,
       4,    54,    54,     4,    83,    96,    89,    89,    54,    54,
      54,   100,    54,   100,    54,   100,    54,    54,    88,    57,
      34,    35,    38,    54,    54,    54,    51,    89,    35
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
      90,    90,    90,    90,    91,    91,    92,    93,    94,    95,
      95,    95,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
      99,    99,    99,    99,   100,   100,   101,   101,   101,   102,
     102,   103,   104,   105
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
       2,     3,     5,     5,     9,     7,     7,     6,     6,     3,
       3,     3,     3,     6,     6,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     4,     7,     3,     4,     3,     3,     3,     6,     6,
       6,     5,     5,     5,     3,     1,     1,     1,     1,     4,
       4,     4,     3,     3
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
#line 1614 "y.tab.c"
    break;

  case 6: /* TypeDefBlock: %empty  */
#line 95 "parser.y"
             {
             printf("No Type definitions present\n");
             printTT();
             }
#line 1623 "y.tab.c"
    break;

  case 9: /* TypeDef: ID '{' FieldDeclList '}'  */
#line 108 "parser.y"
                                 {
         addTTNode((yyvsp[-3].string),getFLSize((yyvsp[-1].fieldlist)),(yyvsp[-1].fieldlist));
         addTypes((yyvsp[-1].fieldlist));
        }
#line 1632 "y.tab.c"
    break;

  case 10: /* FieldDeclList: FieldDeclList TYPE ID ';'  */
#line 115 "parser.y"
                                        {
              (yyval.fieldlist) = addFLNode((yyvsp[-3].fieldlist),(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1640 "y.tab.c"
    break;

  case 11: /* FieldDeclList: TYPE ID ';'  */
#line 119 "parser.y"
                          {
              (yyval.fieldlist) = addFLNode(NULL,(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1648 "y.tab.c"
    break;

  case 16: /* ClassDef: Cname '{' DECL MemberDeclList MethodDeclList ENDDECL MethodDefList '}'  */
#line 137 "parser.y"
                                                                                {
         printClass(C);
         }
#line 1656 "y.tab.c"
    break;

  case 17: /* Cname: ID  */
#line 143 "parser.y"
         {
      C = addClassNode((yyvsp[0].string));
      }
#line 1664 "y.tab.c"
    break;

  case 21: /* MemberDecl: TYPE ID ';'  */
#line 157 "parser.y"
                  {
        addMemberToClass(C,lookTTUp((yyvsp[-2].string)),lookClassUp((yyvsp[-2].string)),(yyvsp[-1].string));
      }
#line 1672 "y.tab.c"
    break;

  case 24: /* MethodDecl: TYPE ID '(' ParamList ')' ';'  */
#line 168 "parser.y"
                                    {
        addMethodToClass(C,lookTTUp((yyvsp[-5].string)),(yyvsp[-4].string),(yyvsp[-2].paramlist));
        deleteLSymbolTable();
      }
#line 1681 "y.tab.c"
    break;

  case 27: /* MethodDef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 181 "parser.y"
                                                            {

          checkDeclDef(C,lookTTUp((yyvsp[-8].string)),(yyvsp[-7].string),(yyvsp[-5].paramlist));

          int size = getParamSize((yyvsp[-5].paramlist));
          addSelfToLSymbolTable(C,size);

          getLSymbolTable();

          define_method_codeGen(xsm,C,(yyvsp[-7].string),(yyvsp[-1].node));

          deleteLSymbolTable();
          }
#line 1699 "y.tab.c"
    break;

  case 28: /* GdeclBlock: DECL GdeclList ENDDECL  */
#line 198 "parser.y"
                                   {
                C = NULL;
                getGSymbolTable();
              }
#line 1708 "y.tab.c"
    break;

  case 32: /* Gdecl: TYPE GidList ';'  */
#line 213 "parser.y"
                      {
          if( !lookGUp("main") ){
              addGSymbol("main",lookTTUp("int"),NULL,1,1,NULL,1); 
          }
          addAllGSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)),lookClassUp((yyvsp[-2].string)));
     }
#line 1719 "y.tab.c"
    break;

  case 33: /* TYPE: INT  */
#line 222 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1727 "y.tab.c"
    break;

  case 34: /* TYPE: STR  */
#line 226 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1735 "y.tab.c"
    break;

  case 35: /* TYPE: ID  */
#line 230 "parser.y"
        {
     (yyval.string) = (yyvsp[0].string);  
     }
#line 1743 "y.tab.c"
    break;

  case 36: /* GidList: GidList ',' ID  */
#line 236 "parser.y"
                       {
          (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1751 "y.tab.c"
    break;

  case 37: /* GidList: GidList ',' ID '[' NUM ']'  */
#line 240 "parser.y"
                                   {
          (yyval.list) = addArray((yyvsp[-5].list),(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1759 "y.tab.c"
    break;

  case 38: /* GidList: GidList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 244 "parser.y"
                                               {
          (yyval.list) = addArray((yyvsp[-8].list),(yyvsp[-8].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1767 "y.tab.c"
    break;

  case 39: /* GidList: GidList ',' ID '(' ParamList ')'  */
#line 248 "parser.y"
                                         {
          (yyval.list) = addFunction((yyvsp[-5].list),(yyvsp[-3].string),(yyvsp[-1].paramlist));
          deleteLSymbolTable();
        }
#line 1776 "y.tab.c"
    break;

  case 40: /* GidList: ID  */
#line 253 "parser.y"
           {
          (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1784 "y.tab.c"
    break;

  case 41: /* GidList: ID '[' NUM ']'  */
#line 257 "parser.y"
                       {
          (yyval.list) = addArray(NULL,(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1792 "y.tab.c"
    break;

  case 42: /* GidList: ID '[' NUM ']' '[' NUM ']'  */
#line 261 "parser.y"
                                   {
          (yyval.list) = addArray(NULL,(yyvsp[-6].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1800 "y.tab.c"
    break;

  case 43: /* GidList: ID '(' ParamList ')'  */
#line 265 "parser.y"
                             { 
          (yyval.list) = addFunction(NULL,(yyvsp[-3].string),(yyvsp[-1].paramlist));
          deleteLSymbolTable();
        }
#line 1809 "y.tab.c"
    break;

  case 46: /* Fdef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 278 "parser.y"
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
#line 1834 "y.tab.c"
    break;

  case 47: /* ParamList: ParamList ',' TYPE ID  */
#line 302 "parser.y"
                                {
           (yyval.paramlist) = addParameter((yyvsp[-3].paramlist),(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1843 "y.tab.c"
    break;

  case 48: /* ParamList: TYPE ID  */
#line 307 "parser.y"
                  {
           (yyval.paramlist) = addParameter(NULL,(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1852 "y.tab.c"
    break;

  case 49: /* ParamList: %empty  */
#line 312 "parser.y"
           {
           (yyval.paramlist) = NULL;
          }
#line 1860 "y.tab.c"
    break;

  case 50: /* LdeclBlock: DECL LdeclList ENDDECL  */
#line 318 "parser.y"
                                  {
           }
#line 1867 "y.tab.c"
    break;

  case 54: /* Ldecl: TYPE LidList ';'  */
#line 331 "parser.y"
                       {
         addAllLSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)));
      }
#line 1875 "y.tab.c"
    break;

  case 55: /* LidList: LidList ',' ID  */
#line 336 "parser.y"
                       {
        (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1883 "y.tab.c"
    break;

  case 56: /* LidList: ID  */
#line 340 "parser.y"
           {
        (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1891 "y.tab.c"
    break;

  case 57: /* MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 348 "parser.y"
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
#line 1912 "y.tab.c"
    break;

  case 58: /* Body: BEG SL END ';'  */
#line 366 "parser.y"
                 {
    (yyval.node) = (yyvsp[-2].node);
    root = (yyvsp[-2].node);
    printf("Valid Program.\n");
    Inorder((yyvsp[-2].node));
  }
#line 1923 "y.tab.c"
    break;

  case 59: /* Body: BEG END ';'  */
#line 373 "parser.y"
              {
  printf("Valid program.\n");
  }
#line 1931 "y.tab.c"
    break;

  case 60: /* SL: SL S  */
#line 379 "parser.y"
         {
   (yyval.node) = createOpNode(NULL,13,(yyvsp[-1].node),(yyvsp[0].node));
  }
#line 1939 "y.tab.c"
    break;

  case 61: /* SL: S  */
#line 383 "parser.y"
      {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1947 "y.tab.c"
    break;

  case 69: /* S: BREAK ';'  */
#line 403 "parser.y"
            {
    (yyval.node) = createOpNode(NULL,16,NULL,NULL);
  }
#line 1955 "y.tab.c"
    break;

  case 70: /* S: CONTINUE ';'  */
#line 407 "parser.y"
               {
    (yyval.node) = createOpNode(NULL,17,NULL,NULL);
  }
#line 1963 "y.tab.c"
    break;

  case 71: /* S: RETURN E ';'  */
#line 411 "parser.y"
               {
    (yyval.node) = createReturnNode((yyvsp[-1].node));
  }
#line 1971 "y.tab.c"
    break;

  case 72: /* S: FREE '(' IDENTIFIER ')' ';'  */
#line 415 "parser.y"
                              {
    (yyval.node) = createFreeNode((yyvsp[-2].node));
  }
#line 1979 "y.tab.c"
    break;

  case 73: /* S: DELETE '(' IDENTIFIER ')' ';'  */
#line 419 "parser.y"
                                {
    (yyval.node) = createDeleteNode((yyvsp[-2].node));
  }
#line 1987 "y.tab.c"
    break;

  case 74: /* IFST: IF '(' E ')' THEN SL ELSE SL ENDIF  */
#line 425 "parser.y"
                                        {
      (yyval.node) = createIfNode((yyvsp[-6].node),(yyvsp[-3].node),(yyvsp[-1].node));
    }
#line 1995 "y.tab.c"
    break;

  case 75: /* IFST: IF '(' E ')' THEN SL ENDIF  */
#line 429 "parser.y"
                               {
      (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-1].node),NULL);
    }
#line 2003 "y.tab.c"
    break;

  case 76: /* WHILEST: WHILE '(' E ')' DO SL ENDWHILE  */
#line 435 "parser.y"
                                       {
        (yyval.node) = createWhileNode(15,(yyvsp[-4].node),(yyvsp[-1].node));
        }
#line 2011 "y.tab.c"
    break;

  case 77: /* REPEATST: REPEAT SL UNTIL '(' E ')'  */
#line 441 "parser.y"
                                   {
         (yyval.node) = createWhileNode(18,(yyvsp[-1].node),(yyvsp[-4].node));
        }
#line 2019 "y.tab.c"
    break;

  case 78: /* DOWHILEST: DO SL WHILE '(' E ')'  */
#line 447 "parser.y"
                                { 
          (yyval.node) = createWhileNode(19,(yyvsp[-1].node),(yyvsp[-4].node));
          }
#line 2027 "y.tab.c"
    break;

  case 79: /* ASSG: IDENTIFIER EQUALS E  */
#line 454 "parser.y"
                      {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2035 "y.tab.c"
    break;

  case 80: /* ASSG: FIELD EQUALS E  */
#line 458 "parser.y"
                 {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2043 "y.tab.c"
    break;

  case 81: /* ASSG: IDENTIFIER EQUALS INITIALIZE  */
#line 462 "parser.y"
                               {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2051 "y.tab.c"
    break;

  case 82: /* ASSG: IDENTIFIER EQUALS ALLOCATE  */
#line 466 "parser.y"
                             {
  (yyvsp[0].node)->type = (yyvsp[-2].node)->type;
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2060 "y.tab.c"
    break;

  case 83: /* ASSG: IDENTIFIER EQUALS NEW '(' ID ')'  */
#line 471 "parser.y"
                                   {
  struct TreeNode* RHS = createNewNode((yyvsp[-1].string));
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-5].node),RHS);
  }
#line 2069 "y.tab.c"
    break;

  case 84: /* ASSG: FIELD EQUALS NEW '(' ID ')'  */
#line 476 "parser.y"
                              {
  struct TreeNode* RHS = createNewNode((yyvsp[-1].string));
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-5].node),RHS);
  }
#line 2078 "y.tab.c"
    break;

  case 85: /* E: E PLUS E  */
#line 484 "parser.y"
           {
  (yyval.node) = createOpNode(lookTTUp("int"),0,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2086 "y.tab.c"
    break;

  case 86: /* E: E MINUS E  */
#line 488 "parser.y"
            {
  (yyval.node) = createOpNode(lookTTUp("int"),1,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2094 "y.tab.c"
    break;

  case 87: /* E: E MUL E  */
#line 492 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),2,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2102 "y.tab.c"
    break;

  case 88: /* E: E DIV E  */
#line 496 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),3,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2110 "y.tab.c"
    break;

  case 89: /* E: E LT E  */
#line 500 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),5,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2118 "y.tab.c"
    break;

  case 90: /* E: E LTE E  */
#line 504 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),6,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2126 "y.tab.c"
    break;

  case 91: /* E: E GT E  */
#line 508 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),7,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2134 "y.tab.c"
    break;

  case 92: /* E: E GTE E  */
#line 512 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),8,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2142 "y.tab.c"
    break;

  case 93: /* E: E NEQ E  */
#line 516 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),9,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2150 "y.tab.c"
    break;

  case 94: /* E: E EQ E  */
#line 520 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),10,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2158 "y.tab.c"
    break;

  case 95: /* E: '(' E ')'  */
#line 524 "parser.y"
            {
  (yyval.node) = (yyvsp[-1].node);
  }
#line 2166 "y.tab.c"
    break;

  case 100: /* IDENTIFIER: ID  */
#line 538 "parser.y"
              { 
            (yyval.node) = createIdNode((yyvsp[0].string),NULL,NULL);
           }
#line 2174 "y.tab.c"
    break;

  case 101: /* IDENTIFIER: ID '[' E ']'  */
#line 542 "parser.y"
                        {
            (yyval.node) = createIdNode((yyvsp[-3].string),NULL,(yyvsp[-1].node));
            }
#line 2182 "y.tab.c"
    break;

  case 102: /* IDENTIFIER: ID '[' E ']' '[' E ']'  */
#line 546 "parser.y"
                                  {
            (yyval.node) = createIdNode((yyvsp[-6].string),(yyvsp[-4].node),(yyvsp[-1].node));
            }
#line 2190 "y.tab.c"
    break;

  case 103: /* IDENTIFIER: ID '(' ')'  */
#line 550 "parser.y"
                       {
            (yyval.node) = createFunctionNode((yyvsp[-2].string),NULL);
            }
#line 2198 "y.tab.c"
    break;

  case 104: /* IDENTIFIER: ID '(' ArgList ')'  */
#line 554 "parser.y"
                               { 
            (yyval.node) = createFunctionNode((yyvsp[-3].string),(yyvsp[-1].node));
            }
#line 2206 "y.tab.c"
    break;

  case 105: /* FIELD: FIELD '.' ID  */
#line 560 "parser.y"
                   {
      (yyval.node) = addFieldToEnd((yyvsp[-2].node),(yyvsp[0].string));
      }
#line 2214 "y.tab.c"
    break;

  case 106: /* FIELD: ID '.' ID  */
#line 564 "parser.y"
                {
      (yyval.node) = createIdNode((yyvsp[-2].string),NULL,NULL);
      (yyval.node) = addFieldToEnd((yyval.node),(yyvsp[0].string));
      }
#line 2223 "y.tab.c"
    break;

  case 107: /* FIELD: SELF '.' ID  */
#line 569 "parser.y"
                  {
      (yyval.node) = createSelfNode(C,(yyvsp[0].string),NULL);
      }
#line 2231 "y.tab.c"
    break;

  case 108: /* FIELDFUNCTION: SELF '.' ID '(' ArgList ')'  */
#line 575 "parser.y"
                                          {
              (yyval.node) = createSelfNode(C,(yyvsp[-3].string),(yyvsp[-1].node));
              }
#line 2239 "y.tab.c"
    break;

  case 109: /* FIELDFUNCTION: ID '.' ID '(' ArgList ')'  */
#line 579 "parser.y"
                                        {
              (yyval.node) = createIdNode((yyvsp[-5].string),NULL,NULL);
              (yyval.node) = addMethodToEnd((yyval.node),(yyvsp[-3].string),(yyvsp[-1].node));
              }
#line 2248 "y.tab.c"
    break;

  case 110: /* FIELDFUNCTION: FIELD '.' ID '(' ArgList ')'  */
#line 584 "parser.y"
                                           {
              (yyval.node) = addMethodToEnd((yyvsp[-5].node),(yyvsp[-3].string),(yyvsp[-1].node));
              }
#line 2256 "y.tab.c"
    break;

  case 111: /* FIELDFUNCTION: SELF '.' ID '(' ')'  */
#line 588 "parser.y"
                                  {
              (yyval.node) = createSelfNode(C,(yyvsp[-2].string),NULL);
              }
#line 2264 "y.tab.c"
    break;

  case 112: /* FIELDFUNCTION: ID '.' ID '(' ')'  */
#line 592 "parser.y"
                                {
              (yyval.node) = createIdNode((yyvsp[-4].string),NULL,NULL);
              (yyval.node) = addMethodToEnd((yyval.node),(yyvsp[-2].string),NULL);
              }
#line 2273 "y.tab.c"
    break;

  case 113: /* FIELDFUNCTION: FIELD '.' ID '(' ')'  */
#line 597 "parser.y"
                                   {
                (yyval.node) = addMethodToEnd((yyvsp[-4].node),(yyvsp[-2].string),NULL);
              }
#line 2281 "y.tab.c"
    break;

  case 114: /* ArgList: ArgList ',' E  */
#line 603 "parser.y"
                      {
        (yyval.node) = addArgToList((yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2289 "y.tab.c"
    break;

  case 115: /* ArgList: E  */
#line 608 "parser.y"
        {
        (yyval.node) = (yyvsp[0].node);
        }
#line 2297 "y.tab.c"
    break;

  case 116: /* CONSTANT: NUM  */
#line 615 "parser.y"
             {
          (yyval.node) = createNumNode(atoi((yyvsp[0].string)));
          }
#line 2305 "y.tab.c"
    break;

  case 117: /* CONSTANT: STRING  */
#line 619 "parser.y"
                {
          (yyval.node) = createStringNode((yyvsp[0].string));
          }
#line 2313 "y.tab.c"
    break;

  case 118: /* CONSTANT: NULLVAL  */
#line 623 "parser.y"
                 {
          (yyval.node) = createNullNode();
          }
#line 2321 "y.tab.c"
    break;

  case 119: /* INPUT: READ '(' IDENTIFIER ')'  */
#line 630 "parser.y"
                               {
       (yyval.node) = createOpNode(NULL,11,(yyvsp[-1].node),NULL);
      }
#line 2329 "y.tab.c"
    break;

  case 120: /* INPUT: READ '(' FIELD ')'  */
#line 634 "parser.y"
                         {
      (yyval.node) = createOpNode(NULL,11,(yyvsp[-1].node),NULL);
      }
#line 2337 "y.tab.c"
    break;

  case 121: /* OUTPUT: WRITE '(' E ')'  */
#line 640 "parser.y"
                       {
        (yyval.node) = createOpNode(NULL,12,(yyvsp[-1].node),NULL);
      }
#line 2345 "y.tab.c"
    break;

  case 122: /* INITIALIZE: INIT '(' ')'  */
#line 646 "parser.y"
                        {
           (yyval.node) = createOpNode(lookTTUp("int"),21,NULL,NULL);
           }
#line 2353 "y.tab.c"
    break;

  case 123: /* ALLOCATE: ALLOC '(' ')'  */
#line 652 "parser.y"
                       {
         (yyval.node) = createOpNode(lookTTUp("int"),22,NULL,NULL);
         }
#line 2361 "y.tab.c"
    break;


#line 2365 "y.tab.c"

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

#line 658 "parser.y"



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
  fprintf(xsm,"MOV SP, 4500\n");
  fprintf(xsm,"MOV BP, SP\n");
  fprintf(xsm,"JMP F0\n"); 
}

void endxsm(FILE* f){
          fprintf(xsm,"JMP L51\n");

          // FIX ISSUE
          fprintf(xsm,"L53:\n");
          getInput(xsm,"cmcant");
          fprintf(xsm,"INT 10\n");

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
