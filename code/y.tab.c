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
struct classtable* C;


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



#line 274 "y.tab.c"

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
  YYSYMBOL_READ = 29,                      /* READ  */
  YYSYMBOL_WRITE = 30,                     /* WRITE  */
  YYSYMBOL_IF = 31,                        /* IF  */
  YYSYMBOL_THEN = 32,                      /* THEN  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_ENDIF = 34,                     /* ENDIF  */
  YYSYMBOL_WHILE = 35,                     /* WHILE  */
  YYSYMBOL_DO = 36,                        /* DO  */
  YYSYMBOL_ENDWHILE = 37,                  /* ENDWHILE  */
  YYSYMBOL_BREAK = 38,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 39,                  /* CONTINUE  */
  YYSYMBOL_REPEAT = 40,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 41,                     /* UNTIL  */
  YYSYMBOL_RETURN = 42,                    /* RETURN  */
  YYSYMBOL_INT = 43,                       /* INT  */
  YYSYMBOL_STR = 44,                       /* STR  */
  YYSYMBOL_INIT = 45,                      /* INIT  */
  YYSYMBOL_ALLOC = 46,                     /* ALLOC  */
  YYSYMBOL_FREE = 47,                      /* FREE  */
  YYSYMBOL_NULLVAL = 48,                   /* NULLVAL  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_ = 57,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_PROGRAM = 59,                   /* PROGRAM  */
  YYSYMBOL_TypeDefBlock = 60,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 61,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 62,                   /* TypeDef  */
  YYSYMBOL_FieldDeclList = 63,             /* FieldDeclList  */
  YYSYMBOL_ClassDefBlock = 64,             /* ClassDefBlock  */
  YYSYMBOL_ClassDefList = 65,              /* ClassDefList  */
  YYSYMBOL_ClassDef = 66,                  /* ClassDef  */
  YYSYMBOL_Cname = 67,                     /* Cname  */
  YYSYMBOL_MemberDeclList = 68,            /* MemberDeclList  */
  YYSYMBOL_MemberDecl = 69,                /* MemberDecl  */
  YYSYMBOL_MethodDeclList = 70,            /* MethodDeclList  */
  YYSYMBOL_MethodDecl = 71,                /* MethodDecl  */
  YYSYMBOL_MethodDefList = 72,             /* MethodDefList  */
  YYSYMBOL_MethodDef = 73,                 /* MethodDef  */
  YYSYMBOL_GdeclBlock = 74,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 75,                 /* GdeclList  */
  YYSYMBOL_Gdecl = 76,                     /* Gdecl  */
  YYSYMBOL_TYPE = 77,                      /* TYPE  */
  YYSYMBOL_GidList = 78,                   /* GidList  */
  YYSYMBOL_FdefBlock = 79,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 80,                      /* Fdef  */
  YYSYMBOL_ParamList = 81,                 /* ParamList  */
  YYSYMBOL_LdeclBlock = 82,                /* LdeclBlock  */
  YYSYMBOL_LdeclList = 83,                 /* LdeclList  */
  YYSYMBOL_Ldecl = 84,                     /* Ldecl  */
  YYSYMBOL_LidList = 85,                   /* LidList  */
  YYSYMBOL_MainBlock = 86,                 /* MainBlock  */
  YYSYMBOL_Body = 87,                      /* Body  */
  YYSYMBOL_SL = 88,                        /* SL  */
  YYSYMBOL_S = 89,                         /* S  */
  YYSYMBOL_IFST = 90,                      /* IFST  */
  YYSYMBOL_WHILEST = 91,                   /* WHILEST  */
  YYSYMBOL_REPEATST = 92,                  /* REPEATST  */
  YYSYMBOL_DOWHILEST = 93,                 /* DOWHILEST  */
  YYSYMBOL_ASSG = 94,                      /* ASSG  */
  YYSYMBOL_E = 95,                         /* E  */
  YYSYMBOL_IDENTIFIER = 96,                /* IDENTIFIER  */
  YYSYMBOL_FIELD = 97,                     /* FIELD  */
  YYSYMBOL_ArgList = 98,                   /* ArgList  */
  YYSYMBOL_CONSTANT = 99,                  /* CONSTANT  */
  YYSYMBOL_INPUT = 100,                    /* INPUT  */
  YYSYMBOL_OUTPUT = 101,                   /* OUTPUT  */
  YYSYMBOL_INITIALIZE = 102,               /* INITIALIZE  */
  YYSYMBOL_ALLOCATE = 103                  /* ALLOCATE  */
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
#define YYLAST   480

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
      52,    53,     2,     2,    54,     2,    57,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    85,    87,    90,    95,   102,   104,   108,
     115,   119,   126,   127,   131,   133,   137,   144,   148,   152,
     154,   158,   163,   165,   169,   176,   177,   182,   187,   192,
     196,   198,   202,   208,   212,   216,   222,   226,   230,   234,
     238,   242,   246,   250,   257,   259,   263,   288,   293,   298,
     305,   308,   312,   314,   318,   323,   327,   335,   355,   362,
     368,   372,   378,   380,   382,   384,   386,   388,   390,   392,
     396,   400,   404,   410,   414,   420,   426,   432,   439,   443,
     447,   451,   458,   462,   466,   470,   474,   478,   482,   486,
     490,   494,   498,   502,   504,   506,   510,   514,   518,   522,
     526,   532,   536,   543,   547,   554,   558,   562,   569,   575,
     581,   587
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
  "ENDTYPE", "BEGINCLASS", "ENDCLASS", "NEW", "DELETE", "EXTENDS", "READ",
  "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "BREAK", "CONTINUE", "REPEAT", "UNTIL", "RETURN", "INT", "STR", "INIT",
  "ALLOC", "FREE", "NULLVAL", "'{'", "'}'", "';'", "'('", "')'", "','",
  "'['", "']'", "'.'", "$accept", "PROGRAM", "TypeDefBlock", "TypeDefList",
  "TypeDef", "FieldDeclList", "ClassDefBlock", "ClassDefList", "ClassDef",
  "Cname", "MemberDeclList", "MemberDecl", "MethodDeclList", "MethodDecl",
  "MethodDefList", "MethodDef", "GdeclBlock", "GdeclList", "Gdecl", "TYPE",
  "GidList", "FdefBlock", "Fdef", "ParamList", "LdeclBlock", "LdeclList",
  "Ldecl", "LidList", "MainBlock", "Body", "SL", "S", "IFST", "WHILEST",
  "REPEATST", "DOWHILEST", "ASSG", "E", "IDENTIFIER", "FIELD", "ArgList",
  "CONSTANT", "INPUT", "OUTPUT", "INITIALIZE", "ALLOCATE", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    32,    44,    43,     9,    16,  -136,  -136,   104,   -11,
      45,  -136,  -136,    89,    18,  -136,    63,    21,   100,   126,
    -136,  -136,  -136,  -136,   101,   146,   158,  -136,  -136,   144,
    -136,    97,  -136,   168,   139,   100,   222,   126,  -136,  -136,
    -136,   223,   141,  -136,    45,  -136,  -136,   -17,    36,   176,
     178,  -136,  -136,   177,  -136,    45,  -136,   227,    45,   228,
    -136,   230,   186,    45,  -136,  -136,   298,  -136,   233,   187,
     236,    -1,   189,    61,   224,    27,  -136,  -136,   238,    34,
    -136,  -136,  -136,    45,   191,    45,   242,   302,   225,   200,
     110,   198,    45,   290,   246,    49,   239,  -136,   292,   422,
    -136,   321,   248,   224,  -136,  -136,   293,    70,  -136,   243,
    -136,   249,  -136,   120,  -136,  -136,    52,   252,   253,   260,
     265,   266,   394,   269,   271,   394,    79,   272,   336,  -136,
     283,   296,   304,   307,   311,   327,    -9,   313,   319,  -136,
     225,   325,   322,  -136,   343,  -136,   345,    58,    79,   378,
    -136,   383,    79,    79,    79,   409,  -136,  -136,   350,  -136,
    -136,  -136,    79,   278,  -136,   342,  -136,   383,   355,  -136,
    -136,  -136,  -136,  -136,  -136,   131,    79,   389,  -136,  -136,
     358,    45,  -136,   361,  -136,  -136,   461,    84,     4,  -136,
     123,   368,   188,   199,   210,   376,   379,   247,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,  -136,   382,
    -136,   385,   390,   461,  -136,  -136,   461,  -136,  -136,   128,
    -136,  -136,    79,   391,  -136,  -136,   418,   416,    79,    79,
    -136,   175,   175,   175,   175,   301,   301,   170,   170,  -136,
    -136,   402,   401,   404,   406,   461,    79,   394,   394,   258,
     268,  -136,  -136,  -136,   224,    64,   297,   365,   416,  -136,
     225,  -136,   394,  -136,  -136,   408,   380,  -136,  -136
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
       0,     0,     0,    36,     0,     0,    26,    22,     0,     0,
      21,    48,    43,     0,    41,    49,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,    51,     0,     0,
      53,     0,     0,     0,    16,    25,     0,     0,    47,     0,
      39,    37,    56,     0,    50,    52,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,    42,     0,    54,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,    69,    70,     0,   106,
     105,   107,     0,     0,    94,    95,    93,     0,     0,    60,
      65,    66,    67,    68,    62,     0,     0,     0,    63,    64,
       0,    49,    24,     0,    55,    99,   104,     0,     0,   102,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
      58,     0,     0,    78,    80,    81,    79,   101,    46,     0,
      38,   100,     0,    97,   108,   109,     0,     0,     0,     0,
      92,    86,    87,    88,    89,    91,    90,    82,    83,    84,
      85,     0,     0,     0,     0,   103,     0,     0,     0,     0,
       0,    72,   110,   111,     0,     0,     0,     0,    77,    76,
       0,    98,     0,    74,    75,     0,     0,    27,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,   454,  -136,  -136,  -136,   446,  -136,
    -136,   407,  -136,   395,  -136,  -136,  -136,  -136,   432,   149,
    -136,  -136,   427,   -55,  -102,  -136,   381,  -136,    14,  -135,
    -119,  -124,  -136,  -136,  -136,  -136,  -136,  -107,  -101,   -99,
    -136,  -136,  -136,  -136,  -136,  -136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    24,     9,    14,    15,    16,
      55,    56,    66,    67,    90,   105,    19,    31,    32,    70,
      48,    37,    38,    71,    88,    99,   100,   113,    20,   102,
     128,   129,   130,   131,   132,   133,   134,   163,   164,   165,
     187,   166,   137,   138,   214,   215
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     135,   140,   136,   155,   169,   180,   158,   176,    75,    17,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
       4,   135,    13,   136,   135,    21,   136,   135,     1,   136,
      95,   169,    18,    39,   169,    58,     4,   107,    59,    11,
     186,   188,    30,    27,     7,   192,   193,   194,   177,    21,
     191,    52,    82,    83,   135,   197,   136,   135,    10,   136,
     223,   159,   116,   160,    22,    23,   209,     8,   213,   216,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      89,    83,   159,   116,   160,    80,    92,    60,    22,    23,
      61,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,    21,   110,    83,   147,    21,   161,   148,    13,   149,
     162,   185,    29,    85,    21,   245,    86,    26,    45,    34,
     261,   249,   250,   142,    83,   265,   219,   161,   256,   257,
      21,   162,   169,   169,   159,   116,   160,   221,   222,   255,
      22,    23,   169,   266,    22,    23,   135,   135,   136,   136,
      42,    40,   260,    22,    23,   135,   135,   136,   136,    25,
     104,   135,    43,   136,    44,   135,    33,   136,    36,    35,
      23,   145,    47,    41,   146,   147,   211,   212,   148,   161,
      33,   244,    83,   162,   206,   207,    36,   204,   205,   206,
     207,    49,    54,    57,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    68,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    78,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    50,    53,    64,    62,
      63,    69,    93,    72,    73,    74,    98,    79,    80,   106,
      81,   225,    91,   101,    87,    84,    94,    96,    98,   103,
      92,   109,   226,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   227,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   108,   111,   112,   141,   139,   143,
     230,   116,    21,   150,   144,   151,    21,   198,   199,   200,
     201,   258,   152,   204,   205,   206,   207,   153,   154,    76,
     156,   259,   157,    97,   167,   116,   118,   119,   120,   208,
     262,   263,   121,   122,   170,   123,   124,   125,   117,   126,
     116,    22,    23,   175,   127,    22,    23,   171,   183,   184,
     118,   119,   120,   168,   116,   172,   121,   122,   173,   123,
     124,   125,   174,   126,   178,   118,   119,   120,   127,   116,
     179,   121,   122,   182,   123,   124,   125,   181,   126,   118,
     119,   120,   189,   127,   116,   121,   122,   190,   123,   124,
     125,   196,   126,   217,   118,   119,   120,   127,   116,   177,
     121,   122,   264,   123,   124,   125,   210,   126,   218,   118,
     119,   120,   127,   116,   268,   121,   122,   220,   123,   124,
     125,   224,   126,   118,   119,   120,    21,   127,   228,   121,
     122,   229,   123,   124,   125,   241,   126,   242,   118,   119,
     120,   127,   243,   114,   195,   122,   246,   123,   124,   125,
     247,   126,   248,   251,   252,   254,   127,   253,   267,    12,
      28,    77,    65,    46,    51,    22,    23,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,     0,     0,
     115
};

static const yytype_int16 yycheck[] =
{
     101,   103,   101,   122,   128,   140,   125,    16,    63,    20,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       4,   122,     4,   122,   125,     4,   125,   128,    22,   128,
      85,   155,    43,    19,   158,    52,     4,    92,    55,    23,
     147,   148,    21,    25,     0,   152,   153,   154,    57,     4,
     151,    37,    53,    54,   155,   162,   155,   158,    49,   158,
      56,     3,     4,     5,    43,    44,   167,    24,   175,   176,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      53,    54,     3,     4,     5,    51,    52,    51,    43,    44,
      54,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,     4,    53,    54,    52,     4,    48,    55,     4,    57,
      52,    53,    49,    52,     4,   222,    55,    28,    21,    19,
      56,   228,   229,    53,    54,   260,   181,    48,   247,   248,
       4,    52,   256,   257,     3,     4,     5,    53,    54,   246,
      43,    44,   266,   262,    43,    44,   247,   248,   247,   248,
       4,    50,   254,    43,    44,   256,   257,   256,   257,    10,
      50,   262,     4,   262,    20,   266,    17,   266,    19,    43,
      44,    51,     4,    24,    54,    52,    45,    46,    55,    48,
      31,    53,    54,    52,    14,    15,    37,    12,    13,    14,
      15,    52,    51,    44,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    55,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    66,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     4,     4,    51,    53,
      52,     4,    83,     5,     4,    49,    87,     4,    51,    90,
       4,    53,     4,    18,    20,    56,    55,     5,    99,    49,
      52,     5,    53,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    53,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     4,    56,     4,     4,    50,    56,
      53,     4,     4,    51,    55,    52,     4,     6,     7,     8,
       9,    53,    52,    12,    13,    14,    15,    52,    52,    21,
      51,    53,    51,    21,    52,     4,    29,    30,    31,    51,
      33,    34,    35,    36,    51,    38,    39,    40,    17,    42,
       4,    43,    44,    16,    47,    43,    44,    51,     5,     4,
      29,    30,    31,    17,     4,    51,    35,    36,    51,    38,
      39,    40,    51,    42,    51,    29,    30,    31,    47,     4,
      51,    35,    36,    51,    38,    39,    40,    52,    42,    29,
      30,    31,     4,    47,     4,    35,    36,     4,    38,    39,
      40,    41,    42,     4,    29,    30,    31,    47,     4,    57,
      35,    36,    37,    38,    39,    40,    51,    42,    50,    29,
      30,    31,    47,     4,    34,    35,    36,    56,    38,    39,
      40,    53,    42,    29,    30,    31,     4,    47,    52,    35,
      36,    52,    38,    39,    40,    53,    42,    52,    29,    30,
      31,    47,    52,    21,    35,    36,    55,    38,    39,    40,
      32,    42,    36,    51,    53,    49,    47,    53,    50,     5,
      14,    66,    55,    31,    37,    43,    44,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      99
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    59,    60,     4,    61,    62,     0,    24,    64,
      49,    23,    62,     4,    65,    66,    67,    20,    43,    74,
      86,     4,    43,    44,    63,    77,    28,    25,    66,    49,
      21,    75,    76,    77,    19,    43,    77,    79,    80,    86,
      50,    77,     4,     4,    20,    21,    76,     4,    78,    52,
       4,    80,    86,     4,    51,    68,    69,    77,    52,    55,
      51,    54,    53,    52,    51,    69,    70,    71,    77,     4,
      77,    81,     5,     4,    49,    81,    21,    71,    77,     4,
      51,     4,    53,    54,    56,    52,    55,    20,    82,    53,
      72,     4,    52,    77,    55,    81,     5,    21,    77,    83,
      84,    18,    87,    49,    50,    73,    77,    81,     4,     5,
      53,    56,     4,    85,    21,    84,     4,    17,    29,    30,
      31,    35,    36,    38,    39,    40,    42,    47,    88,    89,
      90,    91,    92,    93,    94,    96,    97,   100,   101,    50,
      82,     4,    53,    56,    55,    51,    54,    52,    55,    57,
      51,    52,    52,    52,    52,    88,    51,    51,    88,     3,
       5,    48,    52,    95,    96,    97,    99,    52,    17,    89,
      51,    51,    51,    51,    51,    16,    16,    57,    51,    51,
      87,    52,    51,     5,     4,    53,    95,    98,    95,     4,
       4,    96,    95,    95,    95,    35,    41,    95,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    51,    96,
      51,    45,    46,    95,   102,   103,    95,     4,    50,    81,
      56,    53,    54,    56,    53,    53,    53,    53,    52,    52,
      53,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    53,    52,    52,    53,    95,    55,    32,    36,    95,
      95,    51,    53,    53,    49,    95,    88,    88,    53,    53,
      82,    56,    33,    34,    37,    87,    88,    50,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    59,    60,    60,    61,    61,    62,
      63,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      68,    69,    70,    70,    71,    72,    72,    73,    74,    74,
      75,    75,    76,    77,    77,    77,    78,    78,    78,    78,
      78,    78,    78,    78,    79,    79,    80,    81,    81,    81,
      82,    82,    83,    83,    84,    85,    85,    86,    87,    87,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    91,    92,    93,    94,    94,
      94,    94,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    96,    96,    96,    96,
      96,    97,    97,    98,    98,    99,    99,    99,   100,   101,
     102,   103
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     2,     1,     4,
       4,     3,     3,     0,     2,     1,     8,     1,     3,     2,
       1,     3,     2,     1,     6,     2,     0,     9,     3,     2,
       2,     1,     3,     1,     1,     1,     3,     6,     9,     6,
       1,     4,     7,     4,     2,     1,     9,     4,     2,     0,
       3,     2,     2,     1,     3,     3,     1,     8,     4,     3,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     5,     9,     7,     7,     6,     6,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     4,     7,     3,
       4,     3,     3,     3,     1,     1,     1,     1,     4,     4,
       3,     3
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
#line 1578 "y.tab.c"
    break;

  case 6: /* TypeDefBlock: %empty  */
#line 95 "parser.y"
             {
             printf("No Type definitions present\n");
             printTT();
             }
#line 1587 "y.tab.c"
    break;

  case 9: /* TypeDef: ID '{' FieldDeclList '}'  */
#line 108 "parser.y"
                                 {
         addTTNode((yyvsp[-3].string),getFLSize((yyvsp[-1].fieldlist)),(yyvsp[-1].fieldlist));
         addTypes((yyvsp[-1].fieldlist));
        }
#line 1596 "y.tab.c"
    break;

  case 10: /* FieldDeclList: FieldDeclList TYPE ID ';'  */
#line 115 "parser.y"
                                        {
              (yyval.fieldlist) = addFLNode((yyvsp[-3].fieldlist),(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1604 "y.tab.c"
    break;

  case 11: /* FieldDeclList: TYPE ID ';'  */
#line 119 "parser.y"
                          {
              (yyval.fieldlist) = addFLNode(NULL,(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1612 "y.tab.c"
    break;

  case 16: /* ClassDef: Cname '{' DECL MemberDeclList MethodDeclList ENDDECL MethodDefList '}'  */
#line 137 "parser.y"
                                                                                {
         printf("Class declared\n");
         printClass(C);
         }
#line 1621 "y.tab.c"
    break;

  case 17: /* Cname: ID  */
#line 144 "parser.y"
         {
      C = addClassNode((yyvsp[0].string));
      }
#line 1629 "y.tab.c"
    break;

  case 21: /* MemberDecl: TYPE ID ';'  */
#line 158 "parser.y"
                  {
        addMemberToClass(C,lookTTUp((yyvsp[-2].string)),lookClassUp((yyvsp[-2].string)),(yyvsp[-1].string));
      }
#line 1637 "y.tab.c"
    break;

  case 24: /* MethodDecl: TYPE ID '(' ParamList ')' ';'  */
#line 169 "parser.y"
                                    {
        addMethodToClass(C,lookTTUp((yyvsp[-5].string)),(yyvsp[-4].string),(yyvsp[-2].paramlist));
        deleteLSymbolTable();
      }
#line 1646 "y.tab.c"
    break;

  case 27: /* MethodDef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 182 "parser.y"
                                                            {
          }
#line 1653 "y.tab.c"
    break;

  case 28: /* GdeclBlock: DECL GdeclList ENDDECL  */
#line 187 "parser.y"
                                   {
                printf("All Global Declarations parsed.\n");
                getGSymbolTable();
              }
#line 1662 "y.tab.c"
    break;

  case 32: /* Gdecl: TYPE GidList ';'  */
#line 202 "parser.y"
                      {
          addAllGSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)),lookClassUp((yyvsp[-2].string)));
     }
#line 1670 "y.tab.c"
    break;

  case 33: /* TYPE: INT  */
#line 208 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1678 "y.tab.c"
    break;

  case 34: /* TYPE: STR  */
#line 212 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1686 "y.tab.c"
    break;

  case 35: /* TYPE: ID  */
#line 216 "parser.y"
        {
     (yyval.string) = (yyvsp[0].string);  
     }
#line 1694 "y.tab.c"
    break;

  case 36: /* GidList: GidList ',' ID  */
#line 222 "parser.y"
                       {
          (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1702 "y.tab.c"
    break;

  case 37: /* GidList: GidList ',' ID '[' NUM ']'  */
#line 226 "parser.y"
                                   {
          (yyval.list) = addArray((yyvsp[-5].list),(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1710 "y.tab.c"
    break;

  case 38: /* GidList: GidList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 230 "parser.y"
                                               {
          (yyval.list) = addArray((yyvsp[-8].list),(yyvsp[-8].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1718 "y.tab.c"
    break;

  case 39: /* GidList: GidList ',' ID '(' ParamList ')'  */
#line 234 "parser.y"
                                         {
          (yyval.list) = addFunction((yyvsp[-5].list),(yyvsp[-3].string),(yyvsp[-1].paramlist));
        }
#line 1726 "y.tab.c"
    break;

  case 40: /* GidList: ID  */
#line 238 "parser.y"
           {
          (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1734 "y.tab.c"
    break;

  case 41: /* GidList: ID '[' NUM ']'  */
#line 242 "parser.y"
                       {
          (yyval.list) = addArray(NULL,(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1742 "y.tab.c"
    break;

  case 42: /* GidList: ID '[' NUM ']' '[' NUM ']'  */
#line 246 "parser.y"
                                   {
          (yyval.list) = addArray(NULL,(yyvsp[-6].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1750 "y.tab.c"
    break;

  case 43: /* GidList: ID '(' ParamList ')'  */
#line 250 "parser.y"
                             { 
          (yyval.list) = addFunction(NULL,(yyvsp[-3].string),(yyvsp[-1].paramlist));
          deleteLSymbolTable();
        }
#line 1759 "y.tab.c"
    break;

  case 46: /* Fdef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 263 "parser.y"
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
#line 1785 "y.tab.c"
    break;

  case 47: /* ParamList: ParamList ',' TYPE ID  */
#line 288 "parser.y"
                                {
           (yyval.paramlist) = addParameter((yyvsp[-3].paramlist),(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1794 "y.tab.c"
    break;

  case 48: /* ParamList: TYPE ID  */
#line 293 "parser.y"
                  {
           (yyval.paramlist) = addParameter(NULL,(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1803 "y.tab.c"
    break;

  case 49: /* ParamList: %empty  */
#line 298 "parser.y"
           {
           (yyval.paramlist) = NULL;
          }
#line 1811 "y.tab.c"
    break;

  case 50: /* LdeclBlock: DECL LdeclList ENDDECL  */
#line 305 "parser.y"
                                  {
           }
#line 1818 "y.tab.c"
    break;

  case 54: /* Ldecl: TYPE LidList ';'  */
#line 318 "parser.y"
                       {
         addAllLSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)));
      }
#line 1826 "y.tab.c"
    break;

  case 55: /* LidList: LidList ',' ID  */
#line 323 "parser.y"
                       {
        (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1834 "y.tab.c"
    break;

  case 56: /* LidList: ID  */
#line 327 "parser.y"
           {
        (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1842 "y.tab.c"
    break;

  case 57: /* MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 335 "parser.y"
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
#line 1864 "y.tab.c"
    break;

  case 58: /* Body: BEG SL END ';'  */
#line 355 "parser.y"
                 {
    (yyval.node) = (yyvsp[-2].node);
    root = (yyvsp[-2].node);
    printf("Valid Program.\n");
    Inorder((yyvsp[-2].node));
  }
#line 1875 "y.tab.c"
    break;

  case 59: /* Body: BEG END ';'  */
#line 362 "parser.y"
              {
  printf("Valid program.\n");
  }
#line 1883 "y.tab.c"
    break;

  case 60: /* SL: SL S  */
#line 368 "parser.y"
         {
   (yyval.node) = createOpNode(NULL,13,(yyvsp[-1].node),(yyvsp[0].node));
  }
#line 1891 "y.tab.c"
    break;

  case 61: /* SL: S  */
#line 372 "parser.y"
      {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1899 "y.tab.c"
    break;

  case 69: /* S: BREAK ';'  */
#line 392 "parser.y"
            {
    (yyval.node) = createOpNode(NULL,16,NULL,NULL);
  }
#line 1907 "y.tab.c"
    break;

  case 70: /* S: CONTINUE ';'  */
#line 396 "parser.y"
               {
    (yyval.node) = createOpNode(NULL,17,NULL,NULL);
  }
#line 1915 "y.tab.c"
    break;

  case 71: /* S: RETURN E ';'  */
#line 400 "parser.y"
               {
    (yyval.node) = createReturnNode((yyvsp[-1].node));
  }
#line 1923 "y.tab.c"
    break;

  case 72: /* S: FREE '(' IDENTIFIER ')' ';'  */
#line 404 "parser.y"
                              {
    (yyval.node) = createFreeNode((yyvsp[-2].node));
  }
#line 1931 "y.tab.c"
    break;

  case 73: /* IFST: IF '(' E ')' THEN SL ELSE SL ENDIF  */
#line 410 "parser.y"
                                        {
      (yyval.node) = createIfNode((yyvsp[-6].node),(yyvsp[-3].node),(yyvsp[-1].node));
    }
#line 1939 "y.tab.c"
    break;

  case 74: /* IFST: IF '(' E ')' THEN SL ENDIF  */
#line 414 "parser.y"
                               {
      (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-1].node),NULL);
    }
#line 1947 "y.tab.c"
    break;

  case 75: /* WHILEST: WHILE '(' E ')' DO SL ENDWHILE  */
#line 420 "parser.y"
                                       {
        (yyval.node) = createWhileNode(15,(yyvsp[-4].node),(yyvsp[-1].node));
        }
#line 1955 "y.tab.c"
    break;

  case 76: /* REPEATST: REPEAT SL UNTIL '(' E ')'  */
#line 426 "parser.y"
                                   {
         (yyval.node) = createWhileNode(18,(yyvsp[-1].node),(yyvsp[-4].node));
        }
#line 1963 "y.tab.c"
    break;

  case 77: /* DOWHILEST: DO SL WHILE '(' E ')'  */
#line 432 "parser.y"
                                { 
          (yyval.node) = createWhileNode(19,(yyvsp[-1].node),(yyvsp[-4].node));
          }
#line 1971 "y.tab.c"
    break;

  case 78: /* ASSG: IDENTIFIER EQUALS E  */
#line 439 "parser.y"
                      {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1979 "y.tab.c"
    break;

  case 79: /* ASSG: FIELD EQUALS E  */
#line 443 "parser.y"
                 {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1987 "y.tab.c"
    break;

  case 80: /* ASSG: IDENTIFIER EQUALS INITIALIZE  */
#line 447 "parser.y"
                               {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1995 "y.tab.c"
    break;

  case 81: /* ASSG: IDENTIFIER EQUALS ALLOCATE  */
#line 451 "parser.y"
                             {
  (yyvsp[0].node)->type = (yyvsp[-2].node)->type;
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2004 "y.tab.c"
    break;

  case 82: /* E: E PLUS E  */
#line 458 "parser.y"
           {
  (yyval.node) = createOpNode(lookTTUp("int"),0,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2012 "y.tab.c"
    break;

  case 83: /* E: E MINUS E  */
#line 462 "parser.y"
            {
  (yyval.node) = createOpNode(lookTTUp("int"),1,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2020 "y.tab.c"
    break;

  case 84: /* E: E MUL E  */
#line 466 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),2,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2028 "y.tab.c"
    break;

  case 85: /* E: E DIV E  */
#line 470 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),3,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2036 "y.tab.c"
    break;

  case 86: /* E: E LT E  */
#line 474 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),5,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2044 "y.tab.c"
    break;

  case 87: /* E: E LTE E  */
#line 478 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),6,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2052 "y.tab.c"
    break;

  case 88: /* E: E GT E  */
#line 482 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),7,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2060 "y.tab.c"
    break;

  case 89: /* E: E GTE E  */
#line 486 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),8,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2068 "y.tab.c"
    break;

  case 90: /* E: E NEQ E  */
#line 490 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),9,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2076 "y.tab.c"
    break;

  case 91: /* E: E EQ E  */
#line 494 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),10,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2084 "y.tab.c"
    break;

  case 92: /* E: '(' E ')'  */
#line 498 "parser.y"
            {
  (yyval.node) = (yyvsp[-1].node);
  }
#line 2092 "y.tab.c"
    break;

  case 96: /* IDENTIFIER: ID  */
#line 510 "parser.y"
              { 
            (yyval.node) = createIdNode((yyvsp[0].string),NULL,NULL);
           }
#line 2100 "y.tab.c"
    break;

  case 97: /* IDENTIFIER: ID '[' E ']'  */
#line 514 "parser.y"
                        {
            (yyval.node) = createIdNode((yyvsp[-3].string),NULL,(yyvsp[-1].node));
            }
#line 2108 "y.tab.c"
    break;

  case 98: /* IDENTIFIER: ID '[' E ']' '[' E ']'  */
#line 518 "parser.y"
                                  {
            (yyval.node) = createIdNode((yyvsp[-6].string),(yyvsp[-4].node),(yyvsp[-1].node));
            }
#line 2116 "y.tab.c"
    break;

  case 99: /* IDENTIFIER: ID '(' ')'  */
#line 522 "parser.y"
                       {
            (yyval.node) = createFunctionNode((yyvsp[-2].string),NULL);
            }
#line 2124 "y.tab.c"
    break;

  case 100: /* IDENTIFIER: ID '(' ArgList ')'  */
#line 526 "parser.y"
                               { 
            (yyval.node) = createFunctionNode((yyvsp[-3].string),(yyvsp[-1].node));
            }
#line 2132 "y.tab.c"
    break;

  case 101: /* FIELD: FIELD '.' ID  */
#line 532 "parser.y"
                   {
      (yyval.node) = addFieldToEnd((yyvsp[-2].node),(yyvsp[0].string));
      }
#line 2140 "y.tab.c"
    break;

  case 102: /* FIELD: ID '.' ID  */
#line 536 "parser.y"
                {
      (yyval.node) = createIdNode((yyvsp[-2].string),NULL,NULL);
      (yyval.node) = addFieldToEnd((yyval.node),(yyvsp[0].string));
      }
#line 2149 "y.tab.c"
    break;

  case 103: /* ArgList: ArgList ',' E  */
#line 543 "parser.y"
                       {
        (yyval.node) = addArgToList((yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2157 "y.tab.c"
    break;

  case 104: /* ArgList: E  */
#line 547 "parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
        }
#line 2165 "y.tab.c"
    break;

  case 105: /* CONSTANT: NUM  */
#line 554 "parser.y"
             {
          (yyval.node) = createNumNode(atoi((yyvsp[0].string)));
          }
#line 2173 "y.tab.c"
    break;

  case 106: /* CONSTANT: STRING  */
#line 558 "parser.y"
                {
          (yyval.node) = createStringNode((yyvsp[0].string));
          }
#line 2181 "y.tab.c"
    break;

  case 107: /* CONSTANT: NULLVAL  */
#line 562 "parser.y"
                 {
          (yyval.node) = createNullNode();
          }
#line 2189 "y.tab.c"
    break;

  case 108: /* INPUT: READ '(' IDENTIFIER ')'  */
#line 569 "parser.y"
                               {
       (yyval.node) = createOpNode(NULL,11,(yyvsp[-1].node),NULL);
      }
#line 2197 "y.tab.c"
    break;

  case 109: /* OUTPUT: WRITE '(' E ')'  */
#line 575 "parser.y"
                       {
        (yyval.node) = createOpNode(NULL,12,(yyvsp[-1].node),NULL);
      }
#line 2205 "y.tab.c"
    break;

  case 110: /* INITIALIZE: INIT '(' ')'  */
#line 581 "parser.y"
                        {
           (yyval.node) = createOpNode(lookTTUp("int"),21,NULL,NULL);
           }
#line 2213 "y.tab.c"
    break;

  case 111: /* ALLOCATE: ALLOC '(' ')'  */
#line 587 "parser.y"
                       {
         (yyval.node) = createOpNode(lookTTUp("int"),22,NULL,NULL);
         }
#line 2221 "y.tab.c"
    break;


#line 2225 "y.tab.c"

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

#line 592 "parser.y"



int main(int argc, char* argv[]){

  //SOME INITIAL STUFF
  createPrimitive();
  addGSymbol("main",lookTTUp("int"),NULL,1,1,NULL,1);

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
