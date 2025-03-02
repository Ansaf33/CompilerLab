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



struct TreeNode* root;


extern FILE* yyin;

int yylex(void);
void yyerror(char* s);
FILE* xsm;



#line 104 "y.tab.c"

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
    PLUS = 261,                    /* PLUS  */
    MINUS = 262,                   /* MINUS  */
    MUL = 263,                     /* MUL  */
    DIV = 264,                     /* DIV  */
    EQUALS = 265,                  /* EQUALS  */
    LT = 266,                      /* LT  */
    LTE = 267,                     /* LTE  */
    GT = 268,                      /* GT  */
    GTE = 269,                     /* GTE  */
    EQ = 270,                      /* EQ  */
    NEQ = 271,                     /* NEQ  */
    READ = 272,                    /* READ  */
    WRITE = 273,                   /* WRITE  */
    END = 274,                     /* END  */
    BEG = 275,                     /* BEG  */
    IF = 276,                      /* IF  */
    THEN = 277,                    /* THEN  */
    ELSE = 278,                    /* ELSE  */
    ENDIF = 279,                   /* ENDIF  */
    WHILE = 280,                   /* WHILE  */
    DO = 281,                      /* DO  */
    ENDWHILE = 282,                /* ENDWHILE  */
    BREAK = 283,                   /* BREAK  */
    CONTINUE = 284,                /* CONTINUE  */
    REPEAT = 285,                  /* REPEAT  */
    UNTIL = 286,                   /* UNTIL  */
    RETURN = 287,                  /* RETURN  */
    MAIN = 288,                    /* MAIN  */
    DECL = 289,                    /* DECL  */
    ENDDECL = 290,                 /* ENDDECL  */
    INT = 291,                     /* INT  */
    STR = 292,                     /* STR  */
    BEGINTYPE = 293,               /* BEGINTYPE  */
    ENDTYPE = 294                  /* ENDTYPE  */
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
#define PLUS 261
#define MINUS 262
#define MUL 263
#define DIV 264
#define EQUALS 265
#define LT 266
#define LTE 267
#define GT 268
#define GTE 269
#define EQ 270
#define NEQ 271
#define READ 272
#define WRITE 273
#define END 274
#define BEG 275
#define IF 276
#define THEN 277
#define ELSE 278
#define ENDIF 279
#define WHILE 280
#define DO 281
#define ENDWHILE 282
#define BREAK 283
#define CONTINUE 284
#define REPEAT 285
#define UNTIL 286
#define RETURN 287
#define MAIN 288
#define DECL 289
#define ENDDECL 290
#define INT 291
#define STR 292
#define BEGINTYPE 293
#define ENDTYPE 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "parser.y"

  struct TreeNode* node;
  char* string;
  int integer;
  struct list* list;
  struct paramlist* paramlist;
  struct Lsymbol* Lsymbol;
  struct typetable* typetable;
  struct fieldlist* fieldlist;



#line 248 "y.tab.c"

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
  YYSYMBOL_PLUS = 6,                       /* PLUS  */
  YYSYMBOL_MINUS = 7,                      /* MINUS  */
  YYSYMBOL_MUL = 8,                        /* MUL  */
  YYSYMBOL_DIV = 9,                        /* DIV  */
  YYSYMBOL_EQUALS = 10,                    /* EQUALS  */
  YYSYMBOL_LT = 11,                        /* LT  */
  YYSYMBOL_LTE = 12,                       /* LTE  */
  YYSYMBOL_GT = 13,                        /* GT  */
  YYSYMBOL_GTE = 14,                       /* GTE  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_NEQ = 16,                       /* NEQ  */
  YYSYMBOL_READ = 17,                      /* READ  */
  YYSYMBOL_WRITE = 18,                     /* WRITE  */
  YYSYMBOL_END = 19,                       /* END  */
  YYSYMBOL_BEG = 20,                       /* BEG  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_THEN = 22,                      /* THEN  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_ENDIF = 24,                     /* ENDIF  */
  YYSYMBOL_WHILE = 25,                     /* WHILE  */
  YYSYMBOL_DO = 26,                        /* DO  */
  YYSYMBOL_ENDWHILE = 27,                  /* ENDWHILE  */
  YYSYMBOL_BREAK = 28,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 29,                  /* CONTINUE  */
  YYSYMBOL_REPEAT = 30,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 31,                     /* UNTIL  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_MAIN = 33,                      /* MAIN  */
  YYSYMBOL_DECL = 34,                      /* DECL  */
  YYSYMBOL_ENDDECL = 35,                   /* ENDDECL  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_STR = 37,                       /* STR  */
  YYSYMBOL_BEGINTYPE = 38,                 /* BEGINTYPE  */
  YYSYMBOL_ENDTYPE = 39,                   /* ENDTYPE  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '['  */
  YYSYMBOL_45_ = 45,                       /* ']'  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_PROGRAM = 50,                   /* PROGRAM  */
  YYSYMBOL_TypeDefBlock = 51,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 52,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 53,                   /* TypeDef  */
  YYSYMBOL_FieldDeclList = 54,             /* FieldDeclList  */
  YYSYMBOL_GdeclBlock = 55,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 56,                 /* GdeclList  */
  YYSYMBOL_Gdecl = 57,                     /* Gdecl  */
  YYSYMBOL_TYPE = 58,                      /* TYPE  */
  YYSYMBOL_GidList = 59,                   /* GidList  */
  YYSYMBOL_FdefBlock = 60,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 61,                      /* Fdef  */
  YYSYMBOL_ParamList = 62,                 /* ParamList  */
  YYSYMBOL_LdeclBlock = 63,                /* LdeclBlock  */
  YYSYMBOL_LdeclList = 64,                 /* LdeclList  */
  YYSYMBOL_Ldecl = 65,                     /* Ldecl  */
  YYSYMBOL_LidList = 66,                   /* LidList  */
  YYSYMBOL_MainBlock = 67,                 /* MainBlock  */
  YYSYMBOL_Body = 68,                      /* Body  */
  YYSYMBOL_SL = 69,                        /* SL  */
  YYSYMBOL_S = 70,                         /* S  */
  YYSYMBOL_IFST = 71,                      /* IFST  */
  YYSYMBOL_WHILEST = 72,                   /* WHILEST  */
  YYSYMBOL_REPEATST = 73,                  /* REPEATST  */
  YYSYMBOL_DOWHILEST = 74,                 /* DOWHILEST  */
  YYSYMBOL_ASSG = 75,                      /* ASSG  */
  YYSYMBOL_E = 76,                         /* E  */
  YYSYMBOL_IDENTIFIER = 77,                /* IDENTIFIER  */
  YYSYMBOL_FIELD = 78,                     /* FIELD  */
  YYSYMBOL_ArgList = 79,                   /* ArgList  */
  YYSYMBOL_CONSTANT = 80,                  /* CONSTANT  */
  YYSYMBOL_INPUT = 81,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 82                     /* OUTPUT  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   418

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      46,    47,     2,     2,    43,     2,    48,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    69,    71,    74,    79,    86,    88,    92,
      99,   103,   109,   114,   118,   120,   124,   130,   134,   138,
     144,   148,   152,   156,   160,   164,   168,   172,   179,   181,
     185,   210,   215,   220,   227,   230,   234,   236,   240,   245,
     249,   256,   282,   289,   295,   299,   305,   307,   309,   311,
     313,   315,   317,   319,   323,   327,   333,   337,   343,   349,
     355,   362,   366,   372,   376,   380,   384,   388,   392,   396,
     400,   404,   408,   412,   416,   418,   420,   424,   428,   432,
     436,   440,   446,   450,   457,   461,   468,   472,   479,   485
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
  "PLUS", "MINUS", "MUL", "DIV", "EQUALS", "LT", "LTE", "GT", "GTE", "EQ",
  "NEQ", "READ", "WRITE", "END", "BEG", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "DO", "ENDWHILE", "BREAK", "CONTINUE", "REPEAT", "UNTIL",
  "RETURN", "MAIN", "DECL", "ENDDECL", "INT", "STR", "BEGINTYPE",
  "ENDTYPE", "'{'", "'}'", "';'", "','", "'['", "']'", "'('", "')'", "'.'",
  "$accept", "PROGRAM", "TypeDefBlock", "TypeDefList", "TypeDef",
  "FieldDeclList", "GdeclBlock", "GdeclList", "Gdecl", "TYPE", "GidList",
  "FdefBlock", "Fdef", "ParamList", "LdeclBlock", "LdeclList", "Ldecl",
  "LidList", "MainBlock", "Body", "SL", "S", "IFST", "WHILEST", "REPEATST",
  "DOWHILEST", "ASSG", "E", "IDENTIFIER", "FIELD", "ArgList", "CONSTANT",
  "INPUT", "OUTPUT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -32,    25,    34,    41,   -25,     4,   -90,   -90,     9,    43,
      15,   -90,    81,   -90,   -90,   -90,   -90,   -90,   -90,    35,
     -90,    64,    46,    43,    76,    15,   -90,   -90,    12,    93,
     -90,   -90,    10,    97,    58,    78,   -90,   -90,   -90,   124,
     135,   145,    81,   -90,   180,   156,    81,   165,   -90,   169,
     212,   -38,    60,   181,    22,   -90,   184,   -90,    81,   -90,
     246,    81,   108,   232,   213,   261,   264,   226,    31,   -90,
     268,   116,   -90,   279,   233,   181,   228,   -90,   231,   -90,
     -90,   105,   -90,   -90,    11,   230,   236,   235,   239,   255,
     359,   252,   260,   359,    33,   295,   -90,   275,   276,   277,
     280,   284,   293,    -8,   288,   291,   -90,   232,   -90,   273,
     -90,   302,    33,    20,   306,   330,    33,   -90,    33,    33,
     375,   -90,   -90,   311,   -90,   -90,    33,   248,   -90,   287,
     -90,   296,   -90,   -90,   -90,   -90,   -90,   -90,    33,    33,
     342,   -90,   -90,   308,   305,   -90,    87,   -90,   402,   222,
     -90,    83,   304,    75,   174,   186,   312,   316,   197,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,   -90,
     -90,   402,   402,   -90,   -90,   -90,   321,    33,   -90,   -90,
     -90,   344,   348,    33,    33,   -90,    54,    54,   -90,   -90,
     158,   158,   158,   158,   162,   162,    33,   402,   359,   359,
     211,   223,   234,   263,   327,   348,   -90,   -90,   359,   -90,
     -90,   343,   -90
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,     0,     0,     0,     8,     1,     0,     0,
       0,     4,     0,     5,     7,    19,    13,    17,    18,     0,
      15,     0,     0,    17,     0,     0,    29,     3,     0,     0,
      12,    14,    24,     0,     0,     0,    28,     2,     9,     0,
       0,     0,    33,    16,     0,     0,    33,     0,    11,     0,
       0,     0,    20,     0,     0,    10,    25,    32,     0,    27,
       0,    33,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,    37,     0,     0,     0,     0,    31,    21,    23,
      40,     0,    34,    36,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,    26,     0,
      38,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,    53,    54,     0,    87,    86,     0,     0,    75,    76,
      74,     0,    44,    49,    50,    51,    52,    46,     0,     0,
       0,    47,    48,     0,     0,    39,     0,    80,    85,     0,
      83,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      42,    61,    62,    82,    30,    22,    78,     0,    81,    88,
      89,     0,     0,     0,     0,    73,    63,    64,    65,    66,
      67,    68,    69,    70,    72,    71,     0,    84,     0,     0,
       0,     0,     0,     0,     0,    60,    59,    79,     0,    57,
      58,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -90,   -90,   365,   -90,   -90,   -90,   362,     2,
     -90,   -90,   353,   -43,   307,   -90,   315,   -90,    16,   283,
     -89,   -88,   -90,   -90,   -90,   -90,   -90,    -5,   -73,   -62,
     -90,   -90,   -90,   -90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    28,    10,    19,    20,    50,
      33,    25,    26,    51,    63,    71,    72,    81,    11,    74,
      95,    96,    97,    98,    99,   100,   101,   127,   128,   129,
     149,   130,   104,   105
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     102,   120,   139,    54,   123,    58,     1,   132,     4,    59,
      21,   103,    24,    15,    29,    12,    15,   102,    68,    15,
     102,    21,   102,   124,    84,   125,    27,    24,   103,     4,
      39,   103,   132,   103,     7,   132,   124,    84,   125,    15,
     140,    37,   152,    13,    16,    17,    18,   102,    17,    18,
     102,    23,    18,    38,    41,   112,    42,   113,   103,   114,
      66,   103,   161,   162,    70,    58,   126,   147,    32,    64,
      30,    17,    18,    70,    58,     8,    22,     9,    79,   126,
      35,   159,   160,   161,   162,    15,   163,   164,   165,   166,
     167,   168,    34,   159,   160,   161,   162,    40,   163,   164,
     165,   166,   167,   168,    60,    45,    61,   146,   148,   203,
     204,   153,    15,   154,   155,   132,   132,    17,    18,   211,
      15,   158,   180,   132,    46,   102,   102,   112,    47,   113,
     102,   102,   176,   171,   172,   102,   103,   103,   102,    43,
      44,   103,   103,    69,    17,    18,   103,   110,   111,   103,
      49,    82,    17,    18,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   159,   160,   161,   162,   159,   160,
     161,   162,   197,   163,   164,   165,   166,    48,   200,   201,
     159,   160,   161,   162,    52,   163,   164,   165,   166,   167,
     168,   202,   159,   160,   161,   162,    53,   163,   164,   165,
     166,   167,   168,   159,   160,   161,   162,    55,   163,   164,
     165,   166,   167,   168,    56,    62,    57,   159,   160,   161,
     162,   181,   163,   164,   165,   166,   167,   168,    65,   159,
     160,   161,   162,   182,   163,   164,   165,   166,   167,   168,
     159,   160,   161,   162,   185,   163,   164,   165,   166,   167,
     168,    67,    73,    75,   159,   160,   161,   162,   205,   163,
     164,   165,   166,   167,   168,   177,    76,    84,    77,   178,
     206,    78,    80,   108,   106,   109,   115,   117,   144,   207,
      85,    86,   116,    84,    88,   118,   208,   209,    89,    90,
     169,    91,    92,    93,   121,    94,    85,    86,    87,    84,
      88,   119,   122,   138,    89,    90,   145,    91,    92,    93,
     150,    94,    85,    86,   131,    84,    88,   133,   134,   135,
      89,    90,   136,    91,    92,    93,   137,    94,    85,    86,
     141,    84,    88,   142,   151,   140,    89,    90,   170,    91,
      92,    93,   157,    94,    85,    86,   173,    84,    88,   174,
     175,   179,    89,    90,   210,    91,    92,    93,   183,    94,
      85,    86,   184,    84,    88,   196,   198,   212,    89,    90,
      14,    91,    92,    93,   199,    94,    85,    86,    36,    84,
      88,    31,   107,     0,    89,    90,    83,    91,    92,    93,
     143,    94,    85,    86,     0,     0,    88,     0,     0,     0,
     156,    90,     0,    91,    92,    93,     0,    94,   159,   160,
     161,   162,     0,   163,   164,   165,   166,   167,   168
};

static const yytype_int16 yycheck[] =
{
      73,    90,    10,    46,    93,    43,    38,    95,     4,    47,
       8,    73,    10,     4,    12,    40,     4,    90,    61,     4,
      93,    19,    95,     3,     4,     5,    10,    25,    90,     4,
      28,    93,   120,    95,     0,   123,     3,     4,     5,     4,
      48,    25,   115,    39,    35,    36,    37,   120,    36,    37,
     123,    36,    37,    41,    44,    44,    46,    46,   120,    48,
      58,   123,     8,     9,    62,    43,    46,    47,     4,    47,
      35,    36,    37,    71,    43,    34,    33,    36,    47,    46,
       4,     6,     7,     8,     9,     4,    11,    12,    13,    14,
      15,    16,    46,     6,     7,     8,     9,     4,    11,    12,
      13,    14,    15,    16,    44,    47,    46,   112,   113,   198,
     199,   116,     4,   118,   119,   203,   204,    36,    37,   208,
       4,   126,    47,   211,    46,   198,   199,    44,     4,    46,
     203,   204,    45,   138,   139,   208,   198,   199,   211,    42,
      43,   203,   204,    35,    36,    37,   208,    42,    43,   211,
       5,    35,    36,    37,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,     6,     7,     8,     9,     6,     7,
       8,     9,   177,    11,    12,    13,    14,    42,   183,   184,
       6,     7,     8,     9,     4,    11,    12,    13,    14,    15,
      16,   196,     6,     7,     8,     9,    40,    11,    12,    13,
      14,    15,    16,     6,     7,     8,     9,    42,    11,    12,
      13,    14,    15,    16,    45,    34,     4,     6,     7,     8,
       9,    47,    11,    12,    13,    14,    15,    16,    44,     6,
       7,     8,     9,    47,    11,    12,    13,    14,    15,    16,
       6,     7,     8,     9,    47,    11,    12,    13,    14,    15,
      16,     5,    20,    40,     6,     7,     8,     9,    47,    11,
      12,    13,    14,    15,    16,    43,     5,     4,     4,    47,
      47,    45,     4,    45,    41,    44,    46,    42,     5,    45,
      17,    18,    46,     4,    21,    46,    23,    24,    25,    26,
      42,    28,    29,    30,    42,    32,    17,    18,    19,     4,
      21,    46,    42,    10,    25,    26,     4,    28,    29,    30,
       4,    32,    17,    18,    19,     4,    21,    42,    42,    42,
      25,    26,    42,    28,    29,    30,    42,    32,    17,    18,
      42,     4,    21,    42,     4,    48,    25,    26,    42,    28,
      29,    30,    31,    32,    17,    18,     4,     4,    21,    41,
      45,    47,    25,    26,    27,    28,    29,    30,    46,    32,
      17,    18,    46,     4,    21,    44,    22,    24,    25,    26,
       5,    28,    29,    30,    26,    32,    17,    18,    25,     4,
      21,    19,    75,    -1,    25,    26,    71,    28,    29,    30,
     107,    32,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    -1,    32,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    50,    51,     4,    52,    53,     0,    34,    36,
      55,    67,    40,    39,    53,     4,    35,    36,    37,    56,
      57,    58,    33,    36,    58,    60,    61,    67,    54,    58,
      35,    57,     4,    59,    46,     4,    61,    67,    41,    58,
       4,    44,    46,    42,    43,    47,    46,     4,    42,     5,
      58,    62,     4,    40,    62,    42,    45,     4,    43,    47,
      44,    46,    34,    63,    47,    44,    58,     5,    62,    35,
      58,    64,    65,    20,    68,    40,     5,     4,    45,    47,
       4,    66,    35,    65,     4,    17,    18,    19,    21,    25,
      26,    28,    29,    30,    32,    69,    70,    71,    72,    73,
      74,    75,    77,    78,    81,    82,    41,    63,    45,    44,
      42,    43,    44,    46,    48,    46,    46,    42,    46,    46,
      69,    42,    42,    69,     3,     5,    46,    76,    77,    78,
      80,    19,    70,    42,    42,    42,    42,    42,    10,    10,
      48,    42,    42,    68,     5,     4,    76,    47,    76,    79,
       4,     4,    77,    76,    76,    76,    25,    31,    76,     6,
       7,     8,     9,    11,    12,    13,    14,    15,    16,    42,
      42,    76,    76,     4,    41,    45,    45,    43,    47,    47,
      47,    47,    47,    46,    46,    47,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    44,    76,    22,    26,
      76,    76,    76,    69,    69,    47,    47,    45,    23,    24,
      27,    69,    24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    50,    51,    51,    52,    52,    53,
      54,    54,    55,    55,    56,    56,    57,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    62,    62,    62,    63,    63,    64,    64,    65,    66,
      66,    67,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    72,    73,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     0,     2,     1,     4,
       4,     3,     3,     2,     2,     1,     3,     1,     1,     1,
       3,     6,     9,     6,     1,     4,     7,     4,     2,     1,
       9,     4,     2,     0,     3,     2,     2,     1,     3,     3,
       1,     8,     4,     3,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     9,     7,     7,     6,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     4,     7,
       3,     4,     3,     3,     3,     1,     1,     1,     4,     4
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
#line 74 "parser.y"
                                          {
             printf("All Type definitions parsed.\n");
             printTT();
             }
#line 1487 "y.tab.c"
    break;

  case 6: /* TypeDefBlock: %empty  */
#line 79 "parser.y"
             {
             printf("No Type definitions present\n");
             printTT();
             }
#line 1496 "y.tab.c"
    break;

  case 9: /* TypeDef: ID '{' FieldDeclList '}'  */
#line 92 "parser.y"
                                 {
         addTTNode((yyvsp[-3].string),getFLSize((yyvsp[-1].fieldlist)),(yyvsp[-1].fieldlist));
         addTypes((yyvsp[-1].fieldlist));
        }
#line 1505 "y.tab.c"
    break;

  case 10: /* FieldDeclList: FieldDeclList TYPE ID ';'  */
#line 99 "parser.y"
                                        {
              (yyval.fieldlist) = addFLNode((yyvsp[-3].fieldlist),(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1513 "y.tab.c"
    break;

  case 11: /* FieldDeclList: TYPE ID ';'  */
#line 103 "parser.y"
                          {
              (yyval.fieldlist) = addFLNode(NULL,(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1521 "y.tab.c"
    break;

  case 12: /* GdeclBlock: DECL GdeclList ENDDECL  */
#line 109 "parser.y"
                                   {
                printf("All Global Declarations parsed.\n");
                getGSymbolTable();
              }
#line 1530 "y.tab.c"
    break;

  case 16: /* Gdecl: TYPE GidList ';'  */
#line 124 "parser.y"
                      {
          addAllGSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)));
     }
#line 1538 "y.tab.c"
    break;

  case 17: /* TYPE: INT  */
#line 130 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1546 "y.tab.c"
    break;

  case 18: /* TYPE: STR  */
#line 134 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1554 "y.tab.c"
    break;

  case 19: /* TYPE: ID  */
#line 138 "parser.y"
        {
     (yyval.string) = (yyvsp[0].string);  
     }
#line 1562 "y.tab.c"
    break;

  case 20: /* GidList: GidList ',' ID  */
#line 144 "parser.y"
                       {
          (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1570 "y.tab.c"
    break;

  case 21: /* GidList: GidList ',' ID '[' NUM ']'  */
#line 148 "parser.y"
                                   {
          (yyval.list) = addArray((yyvsp[-5].list),(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1578 "y.tab.c"
    break;

  case 22: /* GidList: GidList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 152 "parser.y"
                                               {
          (yyval.list) = addArray((yyvsp[-8].list),(yyvsp[-8].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1586 "y.tab.c"
    break;

  case 23: /* GidList: GidList ',' ID '(' ParamList ')'  */
#line 156 "parser.y"
                                         {
          (yyval.list) = addFunction((yyvsp[-5].list),(yyvsp[-3].string),(yyvsp[-1].paramlist));
        }
#line 1594 "y.tab.c"
    break;

  case 24: /* GidList: ID  */
#line 160 "parser.y"
           {
          (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1602 "y.tab.c"
    break;

  case 25: /* GidList: ID '[' NUM ']'  */
#line 164 "parser.y"
                       {
          (yyval.list) = addArray(NULL,(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1610 "y.tab.c"
    break;

  case 26: /* GidList: ID '[' NUM ']' '[' NUM ']'  */
#line 168 "parser.y"
                                   {
          (yyval.list) = addArray(NULL,(yyvsp[-6].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1618 "y.tab.c"
    break;

  case 27: /* GidList: ID '(' ParamList ')'  */
#line 172 "parser.y"
                             { 
          (yyval.list) = addFunction(NULL,(yyvsp[-3].string),(yyvsp[-1].paramlist));
          deleteLSymbolTable();
        }
#line 1627 "y.tab.c"
    break;

  case 30: /* Fdef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 185 "parser.y"
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
#line 1653 "y.tab.c"
    break;

  case 31: /* ParamList: ParamList ',' TYPE ID  */
#line 210 "parser.y"
                                {
           (yyval.paramlist) = addParameter((yyvsp[-3].paramlist),(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1662 "y.tab.c"
    break;

  case 32: /* ParamList: TYPE ID  */
#line 215 "parser.y"
                  {
           (yyval.paramlist) = addParameter(NULL,(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1671 "y.tab.c"
    break;

  case 33: /* ParamList: %empty  */
#line 220 "parser.y"
           {
           (yyval.paramlist) = NULL;
          }
#line 1679 "y.tab.c"
    break;

  case 34: /* LdeclBlock: DECL LdeclList ENDDECL  */
#line 227 "parser.y"
                                  {
           }
#line 1686 "y.tab.c"
    break;

  case 38: /* Ldecl: TYPE LidList ';'  */
#line 240 "parser.y"
                       {
         addAllLSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)));
      }
#line 1694 "y.tab.c"
    break;

  case 39: /* LidList: LidList ',' ID  */
#line 245 "parser.y"
                       {
        (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1702 "y.tab.c"
    break;

  case 40: /* LidList: ID  */
#line 249 "parser.y"
           {
        (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1710 "y.tab.c"
    break;

  case 41: /* MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 256 "parser.y"
                                                   {
          printf("|| ------------------------- F U N C T I O N : Main ---------------------- ||\n\n");
 
          // GETTING LOCAL SYMBOL TABLE
          getLSymbolTable();
    
          define_function_codeGen(xsm,"main",(yyvsp[-1].node));

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
#line 1738 "y.tab.c"
    break;

  case 42: /* Body: BEG SL END ';'  */
#line 282 "parser.y"
                 {
    (yyval.node) = (yyvsp[-2].node);
    root = (yyvsp[-2].node);
    printf("Valid Program.\n");
    Inorder((yyvsp[-2].node));
  }
#line 1749 "y.tab.c"
    break;

  case 43: /* Body: BEG END ';'  */
#line 289 "parser.y"
              {
  printf("Valid program.\n");
  }
#line 1757 "y.tab.c"
    break;

  case 44: /* SL: SL S  */
#line 295 "parser.y"
         {
   (yyval.node) = createOpNode(NULL,13,(yyvsp[-1].node),(yyvsp[0].node));
  }
#line 1765 "y.tab.c"
    break;

  case 45: /* SL: S  */
#line 299 "parser.y"
      {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1773 "y.tab.c"
    break;

  case 53: /* S: BREAK ';'  */
#line 319 "parser.y"
            {
    (yyval.node) = createOpNode(NULL,16,NULL,NULL);
  }
#line 1781 "y.tab.c"
    break;

  case 54: /* S: CONTINUE ';'  */
#line 323 "parser.y"
               {
    (yyval.node) = createOpNode(NULL,17,NULL,NULL);
  }
#line 1789 "y.tab.c"
    break;

  case 55: /* S: RETURN E ';'  */
#line 327 "parser.y"
               {
    (yyval.node) = createReturnNode((yyvsp[-1].node));
  }
#line 1797 "y.tab.c"
    break;

  case 56: /* IFST: IF '(' E ')' THEN SL ELSE SL ENDIF  */
#line 333 "parser.y"
                                        {
      (yyval.node) = createIfNode((yyvsp[-6].node),(yyvsp[-3].node),(yyvsp[-1].node));
    }
#line 1805 "y.tab.c"
    break;

  case 57: /* IFST: IF '(' E ')' THEN SL ENDIF  */
#line 337 "parser.y"
                               {
      (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-1].node),NULL);
    }
#line 1813 "y.tab.c"
    break;

  case 58: /* WHILEST: WHILE '(' E ')' DO SL ENDWHILE  */
#line 343 "parser.y"
                                       {
        (yyval.node) = createWhileNode(15,(yyvsp[-4].node),(yyvsp[-1].node));
        }
#line 1821 "y.tab.c"
    break;

  case 59: /* REPEATST: REPEAT SL UNTIL '(' E ')'  */
#line 349 "parser.y"
                                   {
         (yyval.node) = createWhileNode(18,(yyvsp[-1].node),(yyvsp[-4].node));
        }
#line 1829 "y.tab.c"
    break;

  case 60: /* DOWHILEST: DO SL WHILE '(' E ')'  */
#line 355 "parser.y"
                                { 
          (yyval.node) = createWhileNode(19,(yyvsp[-1].node),(yyvsp[-4].node));
          }
#line 1837 "y.tab.c"
    break;

  case 61: /* ASSG: IDENTIFIER EQUALS E  */
#line 362 "parser.y"
                      {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1845 "y.tab.c"
    break;

  case 62: /* ASSG: FIELD EQUALS E  */
#line 366 "parser.y"
                 {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1853 "y.tab.c"
    break;

  case 63: /* E: E PLUS E  */
#line 372 "parser.y"
           {
  (yyval.node) = createOpNode(lookTTUp("int"),0,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1861 "y.tab.c"
    break;

  case 64: /* E: E MINUS E  */
#line 376 "parser.y"
            {
  (yyval.node) = createOpNode(lookTTUp("int"),1,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1869 "y.tab.c"
    break;

  case 65: /* E: E MUL E  */
#line 380 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),2,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1877 "y.tab.c"
    break;

  case 66: /* E: E DIV E  */
#line 384 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),3,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1885 "y.tab.c"
    break;

  case 67: /* E: E LT E  */
#line 388 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),5,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1893 "y.tab.c"
    break;

  case 68: /* E: E LTE E  */
#line 392 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),6,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1901 "y.tab.c"
    break;

  case 69: /* E: E GT E  */
#line 396 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),7,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1909 "y.tab.c"
    break;

  case 70: /* E: E GTE E  */
#line 400 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),8,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1917 "y.tab.c"
    break;

  case 71: /* E: E NEQ E  */
#line 404 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),9,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1925 "y.tab.c"
    break;

  case 72: /* E: E EQ E  */
#line 408 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),10,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1933 "y.tab.c"
    break;

  case 73: /* E: '(' E ')'  */
#line 412 "parser.y"
            {
  (yyval.node) = (yyvsp[-1].node);
  }
#line 1941 "y.tab.c"
    break;

  case 77: /* IDENTIFIER: ID  */
#line 424 "parser.y"
              { 
            (yyval.node) = createIdNode((yyvsp[0].string),NULL,NULL);
           }
#line 1949 "y.tab.c"
    break;

  case 78: /* IDENTIFIER: ID '[' E ']'  */
#line 428 "parser.y"
                        {
            (yyval.node) = createIdNode((yyvsp[-3].string),NULL,(yyvsp[-1].node));
            }
#line 1957 "y.tab.c"
    break;

  case 79: /* IDENTIFIER: ID '[' E ']' '[' E ']'  */
#line 432 "parser.y"
                                  {
            (yyval.node) = createIdNode((yyvsp[-6].string),(yyvsp[-4].node),(yyvsp[-1].node));
            }
#line 1965 "y.tab.c"
    break;

  case 80: /* IDENTIFIER: ID '(' ')'  */
#line 436 "parser.y"
                       {
            (yyval.node) = createFunctionNode((yyvsp[-2].string),NULL);
            }
#line 1973 "y.tab.c"
    break;

  case 81: /* IDENTIFIER: ID '(' ArgList ')'  */
#line 440 "parser.y"
                               { 
            (yyval.node) = createFunctionNode((yyvsp[-3].string),(yyvsp[-1].node));
            }
#line 1981 "y.tab.c"
    break;

  case 82: /* FIELD: FIELD '.' ID  */
#line 446 "parser.y"
                   {
      (yyval.node) = addFieldToEnd((yyvsp[-2].node),(yyvsp[0].string));
      }
#line 1989 "y.tab.c"
    break;

  case 83: /* FIELD: ID '.' ID  */
#line 450 "parser.y"
                {
      (yyval.node) = createIdNode((yyvsp[-2].string),NULL,NULL);
      (yyval.node) = addFieldToEnd((yyval.node),(yyvsp[0].string));
      }
#line 1998 "y.tab.c"
    break;

  case 84: /* ArgList: ArgList ',' E  */
#line 457 "parser.y"
                       {
        (yyval.node) = addArgToList((yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2006 "y.tab.c"
    break;

  case 85: /* ArgList: E  */
#line 461 "parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
        }
#line 2014 "y.tab.c"
    break;

  case 86: /* CONSTANT: NUM  */
#line 468 "parser.y"
             {
          (yyval.node) = createNumNode(atoi((yyvsp[0].string)));
          }
#line 2022 "y.tab.c"
    break;

  case 87: /* CONSTANT: STRING  */
#line 472 "parser.y"
                {
          (yyval.node) = createStringNode((yyvsp[0].string));
          }
#line 2030 "y.tab.c"
    break;

  case 88: /* INPUT: READ '(' IDENTIFIER ')'  */
#line 479 "parser.y"
                               {
       (yyval.node) = createOpNode(NULL,11,(yyvsp[-1].node),NULL);
      }
#line 2038 "y.tab.c"
    break;

  case 89: /* OUTPUT: WRITE '(' E ')'  */
#line 485 "parser.y"
                       {
        (yyval.node) = createOpNode(NULL,12,(yyvsp[-1].node),NULL);
      }
#line 2046 "y.tab.c"
    break;


#line 2050 "y.tab.c"

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

#line 492 "parser.y"



int main(int argc, char* argv[]){

  //SOME INITIAL STUFF
  createPrimitive();

  FILE* f = fopen(argv[1],"r");
  yyin = f;

  addGSymbol("main",lookTTUp("int"),1,1,NULL,1);



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

