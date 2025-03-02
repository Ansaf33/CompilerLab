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
#include "evaluator.h"
#include "symbol_table/Gsymbol.h"
#include "symbol_table/varList.h"
#include "symbol_table/paramlist.h"
#include "symbol_table/Lsymbol.h"
#include "functions/checker.h"



struct TreeNode* root;


extern FILE* yyin;

int yylex(void);
void yyerror(char* s);
FILE* xsm;



#line 99 "y.tab.c"

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
    STR = 292                      /* STR  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "parser.y"

  struct TreeNode* node;
  char* string;
  int integer;
  struct list* list;
  struct paramlist* paramlist;
  struct Lsymbol* Lsymbol;




#line 238 "y.tab.c"

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
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '['  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_PROGRAM = 47,                   /* PROGRAM  */
  YYSYMBOL_GdeclBlock = 48,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 49,                 /* GdeclList  */
  YYSYMBOL_Gdecl = 50,                     /* Gdecl  */
  YYSYMBOL_TYPE = 51,                      /* TYPE  */
  YYSYMBOL_GidList = 52,                   /* GidList  */
  YYSYMBOL_FdefBlock = 53,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 54,                      /* Fdef  */
  YYSYMBOL_ParamList = 55,                 /* ParamList  */
  YYSYMBOL_LdeclBlock = 56,                /* LdeclBlock  */
  YYSYMBOL_LdeclList = 57,                 /* LdeclList  */
  YYSYMBOL_Ldecl = 58,                     /* Ldecl  */
  YYSYMBOL_LidList = 59,                   /* LidList  */
  YYSYMBOL_MainBlock = 60,                 /* MainBlock  */
  YYSYMBOL_Body = 61,                      /* Body  */
  YYSYMBOL_SL = 62,                        /* SL  */
  YYSYMBOL_S = 63,                         /* S  */
  YYSYMBOL_IFST = 64,                      /* IFST  */
  YYSYMBOL_WHILEST = 65,                   /* WHILEST  */
  YYSYMBOL_REPEATST = 66,                  /* REPEATST  */
  YYSYMBOL_DOWHILEST = 67,                 /* DOWHILEST  */
  YYSYMBOL_ASSG = 68,                      /* ASSG  */
  YYSYMBOL_E = 69,                         /* E  */
  YYSYMBOL_IDENTIFIER = 70,                /* IDENTIFIER  */
  YYSYMBOL_ArgList = 71,                   /* ArgList  */
  YYSYMBOL_CONSTANT = 72,                  /* CONSTANT  */
  YYSYMBOL_INPUT = 73,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 74                     /* OUTPUT  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  187

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      42,    43,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    62,    64,    68,    73,    77,    79,    83,
      89,    93,    99,   103,   107,   111,   115,   119,   123,   127,
     134,   136,   140,   167,   172,   177,   184,   187,   191,   193,
     197,   202,   206,   213,   239,   247,   253,   257,   263,   265,
     267,   269,   271,   273,   275,   277,   281,   285,   291,   295,
     301,   307,   313,   320,   326,   330,   334,   338,   342,   346,
     350,   354,   358,   362,   366,   370,   372,   376,   380,   384,
     388,   392,   398,   402,   409,   413,   420,   426
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
  "RETURN", "MAIN", "DECL", "ENDDECL", "INT", "STR", "';'", "','", "'['",
  "']'", "'('", "')'", "'{'", "'}'", "$accept", "PROGRAM", "GdeclBlock",
  "GdeclList", "Gdecl", "TYPE", "GidList", "FdefBlock", "Fdef",
  "ParamList", "LdeclBlock", "LdeclList", "Ldecl", "LidList", "MainBlock",
  "Body", "SL", "S", "IFST", "WHILEST", "REPEATST", "DOWHILEST", "ASSG",
  "E", "IDENTIFIER", "ArgList", "CONSTANT", "INPUT", "OUTPUT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    62,   -31,     7,    66,   -87,   -87,   -87,   -87,    78,
     -87,     6,   -23,   -87,   -31,    23,    66,   -87,   -87,   -87,
     -87,    19,   180,   -13,    -9,   -87,   -87,    42,   189,   -87,
      64,    29,   189,    44,    86,   -27,    27,    77,    -1,    84,
     -87,   189,   -87,   123,   189,    83,   114,   101,   151,   228,
     192,     0,   -87,   232,   187,   -87,   233,   199,    77,   207,
     -87,   215,   -87,   -87,   191,   -87,   -87,    85,   214,   218,
     226,   229,   230,   313,   235,   238,   313,    32,   249,   -87,
     242,   246,   250,   251,   254,   247,   262,   266,   -87,   114,
     -87,   282,   -87,   299,    32,    20,   301,    32,   -87,    32,
      32,   329,   -87,   -87,   265,   -87,   -87,    32,   201,   -87,
     -87,   274,   -87,   -87,   -87,   -87,   -87,   -87,    32,   -87,
     -87,   271,   278,   -87,   179,   -87,   356,    21,   277,    80,
     124,   135,   286,   290,   146,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,   -87,   -87,   356,   -87,   -87,
     284,    32,   -87,   -87,   -87,   314,   309,    32,    32,   -87,
     219,   219,   -87,   -87,   100,   100,   100,   100,    69,    69,
      32,   356,   313,   313,   157,   168,   190,   217,   281,   309,
     -87,   -87,   313,   -87,   -87,   297,   -87
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    10,    11,     0,
       8,     0,     0,     1,    10,     0,     0,    21,     3,     5,
       7,    16,     0,     0,     0,    20,     2,     0,    25,     9,
       0,     0,    25,     0,     0,     0,    12,     0,     0,    17,
      24,     0,    19,     0,    25,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,    29,     0,     0,     0,     0,
      23,    13,    15,    32,     0,    26,    28,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
      18,     0,    30,     0,     0,     0,     0,     0,    35,     0,
       0,     0,    45,    46,     0,    75,    74,     0,     0,    66,
      65,     0,    36,    41,    42,    43,    44,    38,     0,    39,
      40,     0,     0,    31,     0,    70,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    34,    53,    22,    14,
      68,     0,    71,    76,    77,     0,     0,     0,     0,    64,
      54,    55,    56,    57,    58,    59,    60,    61,    63,    62,
       0,    72,     0,     0,     0,     0,     0,     0,     0,    52,
      51,    69,     0,    49,    50,     0,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   328,    25,   -87,   -87,   324,   -29,
     291,   -87,   294,   -87,     2,   255,   -72,   -73,   -87,   -87,
     -87,   -87,   -87,   -86,   -56,   -87,   -87,   -87,   -87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     9,    10,    34,    22,    16,    17,    35,
      46,    54,    55,    64,     5,    57,    78,    79,    80,    81,
      82,    83,    84,   108,   109,   127,   110,    86,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      85,   101,    12,    38,   104,   112,    18,    13,   124,   126,
      21,   129,    41,   130,   131,    51,    42,    85,    26,    23,
      85,   134,    85,   105,    67,   106,    11,    24,   112,    15,
      31,   112,   147,    32,    11,   105,    67,   106,    41,    41,
     128,    15,    47,    62,     1,    85,     2,    33,    85,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    27,
     151,    28,   107,   125,   152,   171,    49,    43,    36,    44,
      53,   174,   175,    37,   107,   135,   136,   137,   138,    53,
     139,   140,   141,   142,   176,    39,   135,   136,   137,   138,
      40,   139,   140,   141,   142,   143,   144,     6,     7,     8,
     177,   178,    14,     8,   112,   112,   135,   136,   137,   138,
     185,    45,   112,    19,     7,     8,    85,    85,    52,     7,
       8,    85,    85,   154,    48,    94,    85,    95,    50,    85,
     135,   136,   137,   138,    56,   139,   140,   141,   142,   143,
     144,   135,   136,   137,   138,    58,   139,   140,   141,   142,
     143,   144,   135,   136,   137,   138,    59,   139,   140,   141,
     142,   143,   144,   135,   136,   137,   138,   155,   139,   140,
     141,   142,   143,   144,   135,   136,   137,   138,   156,   139,
     140,   141,   142,   143,   144,   135,   136,   137,   138,   159,
     139,   140,   141,   142,   143,   144,   135,   136,   137,   138,
     179,   139,   140,   141,   142,   143,   144,   135,   136,   137,
     138,   180,   139,   140,   141,   142,   143,   144,    29,    30,
     150,    67,    65,     7,     8,     7,     8,   137,   138,    92,
      93,   181,    60,    61,    68,    69,    63,    67,    71,   145,
     182,   183,    72,    73,    88,    74,    75,    76,    90,    77,
      68,    69,    70,    67,    71,    91,    96,   118,    72,    73,
      97,    74,    75,    76,    98,    77,    68,    69,   111,    67,
      71,    99,   100,   102,    72,    73,   103,    74,    75,    76,
     113,    77,    68,    69,   114,    67,    71,   122,   115,   116,
      72,    73,   117,    74,    75,    76,   133,    77,    68,    69,
     119,    67,    71,   123,   120,    67,    72,    73,   184,    74,
      75,    76,   146,    77,    68,    69,   148,    67,    71,   149,
     153,   186,    72,    73,   170,    74,    75,    76,   157,    77,
      68,    69,   158,    67,    71,   173,   172,    20,    72,    73,
      25,    74,    75,    76,   121,    77,    68,    69,    66,    89,
      71,     0,     0,     0,   132,    73,     0,    74,    75,    76,
       0,    77,   135,   136,   137,   138,     0,   139,   140,   141,
     142,   143,   144
};

static const yytype_int16 yycheck[] =
{
      56,    73,    33,    32,    76,    78,     4,     0,    94,    95,
       4,    97,    39,    99,   100,    44,    43,    73,    16,    42,
      76,   107,    78,     3,     4,     5,     1,     4,   101,     4,
      43,   104,   118,    42,     9,     3,     4,     5,    39,    39,
      96,    16,    43,    43,    34,   101,    36,     5,   104,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    40,
      39,    42,    42,    43,    43,   151,    41,    40,     4,    42,
      45,   157,   158,    44,    42,     6,     7,     8,     9,    54,
      11,    12,    13,    14,   170,    41,     6,     7,     8,     9,
       4,    11,    12,    13,    14,    15,    16,    35,    36,    37,
     172,   173,    36,    37,   177,   178,     6,     7,     8,     9,
     182,    34,   185,    35,    36,    37,   172,   173,    35,    36,
      37,   177,   178,    43,    40,    40,   182,    42,     5,   185,
       6,     7,     8,     9,    20,    11,    12,    13,    14,    15,
      16,     6,     7,     8,     9,    44,    11,    12,    13,    14,
      15,    16,     6,     7,     8,     9,     5,    11,    12,    13,
      14,    15,    16,     6,     7,     8,     9,    43,    11,    12,
      13,    14,    15,    16,     6,     7,     8,     9,    43,    11,
      12,    13,    14,    15,    16,     6,     7,     8,     9,    43,
      11,    12,    13,    14,    15,    16,     6,     7,     8,     9,
      43,    11,    12,    13,    14,    15,    16,     6,     7,     8,
       9,    43,    11,    12,    13,    14,    15,    16,    38,    39,
      41,     4,    35,    36,    37,    36,    37,     8,     9,    38,
      39,    41,     4,    41,    17,    18,     4,     4,    21,    38,
      23,    24,    25,    26,    45,    28,    29,    30,    41,    32,
      17,    18,    19,     4,    21,    40,    42,    10,    25,    26,
      42,    28,    29,    30,    38,    32,    17,    18,    19,     4,
      21,    42,    42,    38,    25,    26,    38,    28,    29,    30,
      38,    32,    17,    18,    38,     4,    21,     5,    38,    38,
      25,    26,    38,    28,    29,    30,    31,    32,    17,    18,
      38,     4,    21,     4,    38,     4,    25,    26,    27,    28,
      29,    30,    38,    32,    17,    18,    45,     4,    21,    41,
      43,    24,    25,    26,    40,    28,    29,    30,    42,    32,
      17,    18,    42,     4,    21,    26,    22,     9,    25,    26,
      16,    28,    29,    30,    89,    32,    17,    18,    54,    58,
      21,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      -1,    32,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    36,    47,    48,    60,    35,    36,    37,    49,
      50,    51,    33,     0,    36,    51,    53,    54,    60,    35,
      50,     4,    52,    42,     4,    54,    60,    40,    42,    38,
      39,    43,    42,     5,    51,    55,     4,    44,    55,    41,
       4,    39,    43,    40,    42,    34,    56,    43,    40,    51,
       5,    55,    35,    51,    57,    58,    20,    61,    44,     5,
       4,    41,    43,     4,    59,    35,    58,     4,    17,    18,
      19,    21,    25,    26,    28,    29,    30,    32,    62,    63,
      64,    65,    66,    67,    68,    70,    73,    74,    45,    56,
      41,    40,    38,    39,    40,    42,    42,    42,    38,    42,
      42,    62,    38,    38,    62,     3,     5,    42,    69,    70,
      72,    19,    63,    38,    38,    38,    38,    38,    10,    38,
      38,    61,     5,     4,    69,    43,    69,    71,    70,    69,
      69,    69,    25,    31,    69,     6,     7,     8,     9,    11,
      12,    13,    14,    15,    16,    38,    38,    69,    45,    41,
      41,    39,    43,    43,    43,    43,    43,    42,    42,    43,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      40,    69,    22,    26,    69,    69,    69,    62,    62,    43,
      43,    41,    23,    24,    27,    62,    24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    47,    48,    48,    49,    49,    50,
      51,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    54,    55,    55,    55,    56,    56,    57,    57,
      58,    59,    59,    60,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    66,    67,    68,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    73,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     3,     6,     9,     6,     1,     4,     7,     4,
       2,     1,     9,     4,     2,     0,     3,     2,     2,     1,
       3,     3,     1,     8,     4,     3,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     9,     7,
       7,     6,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     4,     7,
       3,     4,     3,     1,     1,     1,     4,     4
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
  case 5: /* GdeclBlock: DECL GdeclList ENDDECL  */
#line 68 "parser.y"
                                   {
                printf("All Global Declarations parsed.\n");
                getGSymbolTable();
              }
#line 1445 "y.tab.c"
    break;

  case 9: /* Gdecl: TYPE GidList ';'  */
#line 83 "parser.y"
                      {
        addAllGSymbols((yyvsp[-1].list),(yyvsp[-2].integer));
     }
#line 1453 "y.tab.c"
    break;

  case 10: /* TYPE: INT  */
#line 89 "parser.y"
         {
     (yyval.integer) = (yyvsp[0].integer);
     }
#line 1461 "y.tab.c"
    break;

  case 11: /* TYPE: STR  */
#line 93 "parser.y"
         {
     (yyval.integer) = (yyvsp[0].integer);
     }
#line 1469 "y.tab.c"
    break;

  case 12: /* GidList: GidList ',' ID  */
#line 99 "parser.y"
                       {
          (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1477 "y.tab.c"
    break;

  case 13: /* GidList: GidList ',' ID '[' NUM ']'  */
#line 103 "parser.y"
                                   {
          (yyval.list) = addArray((yyvsp[-5].list),(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1485 "y.tab.c"
    break;

  case 14: /* GidList: GidList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 107 "parser.y"
                                               {
          (yyval.list) = addArray((yyvsp[-8].list),(yyvsp[-8].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1493 "y.tab.c"
    break;

  case 15: /* GidList: GidList ',' ID '(' ParamList ')'  */
#line 111 "parser.y"
                                         {
          (yyval.list) = addFunction((yyvsp[-5].list),(yyvsp[-3].string),(yyvsp[-1].paramlist));
        }
#line 1501 "y.tab.c"
    break;

  case 16: /* GidList: ID  */
#line 115 "parser.y"
           {
          (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1509 "y.tab.c"
    break;

  case 17: /* GidList: ID '[' NUM ']'  */
#line 119 "parser.y"
                       {
          (yyval.list) = addArray(NULL,(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1517 "y.tab.c"
    break;

  case 18: /* GidList: ID '[' NUM ']' '[' NUM ']'  */
#line 123 "parser.y"
                                   {
          (yyval.list) = addArray(NULL,(yyvsp[-6].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1525 "y.tab.c"
    break;

  case 19: /* GidList: ID '(' ParamList ')'  */
#line 127 "parser.y"
                             { 
          (yyval.list) = addFunction(NULL,(yyvsp[-3].string),(yyvsp[-1].paramlist));
          deleteLSymbolTable();
        }
#line 1534 "y.tab.c"
    break;

  case 22: /* Fdef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 140 "parser.y"
                                                       {
     printf("|| ------------------------- FUNCTION : %s ---------------------- ||\n\n",(yyvsp[-7].string));

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
     checkValidRetType((yyvsp[-8].integer),(yyvsp[-7].string));
     // ---------------------------------------- CHECKING DONE --------------------------------------------------------------

     // GENERATE CODE FOR THE FUNCTION ( PASS IN THE NAME OF FUNCTION, AND ROOT OF TREE )
  
     define_function_codeGen(xsm,(yyvsp[-7].string),(yyvsp[-1].node));

     deleteLSymbolTable();

     }
#line 1562 "y.tab.c"
    break;

  case 23: /* ParamList: ParamList ',' TYPE ID  */
#line 167 "parser.y"
                                {
           (yyval.paramlist) = addParameter((yyvsp[-3].paramlist),(yyvsp[0].string),(yyvsp[-1].integer));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1571 "y.tab.c"
    break;

  case 24: /* ParamList: TYPE ID  */
#line 172 "parser.y"
                  {
           (yyval.paramlist) = addParameter(NULL,(yyvsp[0].string),(yyvsp[-1].integer));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1580 "y.tab.c"
    break;

  case 25: /* ParamList: %empty  */
#line 177 "parser.y"
           {
           (yyval.paramlist) = NULL;
          }
#line 1588 "y.tab.c"
    break;

  case 26: /* LdeclBlock: DECL LdeclList ENDDECL  */
#line 184 "parser.y"
                                  {
           }
#line 1595 "y.tab.c"
    break;

  case 30: /* Ldecl: TYPE LidList ';'  */
#line 197 "parser.y"
                       {
         addAllLSymbols((yyvsp[-1].list),(yyvsp[-2].integer));
      }
#line 1603 "y.tab.c"
    break;

  case 31: /* LidList: LidList ',' ID  */
#line 202 "parser.y"
                       {
        (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1611 "y.tab.c"
    break;

  case 32: /* LidList: ID  */
#line 206 "parser.y"
           {
        (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1619 "y.tab.c"
    break;

  case 33: /* MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 213 "parser.y"
                                                   {
          printf("|| ------------------------- FUNCTION : Main ---------------------- ||\n\n");
 
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
#line 1647 "y.tab.c"
    break;

  case 34: /* Body: BEG SL END ';'  */
#line 239 "parser.y"
                 {

    (yyval.node) = (yyvsp[-2].node);
    root = (yyvsp[-2].node);
    printf("Valid Program.\n");
    Inorder((yyvsp[-2].node));
  }
#line 1659 "y.tab.c"
    break;

  case 35: /* Body: BEG END ';'  */
#line 247 "parser.y"
              {
  printf("Valid program.\n");
  }
#line 1667 "y.tab.c"
    break;

  case 36: /* SL: SL S  */
#line 253 "parser.y"
         {
   (yyval.node) = createOpNode(-1,13,(yyvsp[-1].node),(yyvsp[0].node));
  }
#line 1675 "y.tab.c"
    break;

  case 37: /* SL: S  */
#line 257 "parser.y"
      {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1683 "y.tab.c"
    break;

  case 45: /* S: BREAK ';'  */
#line 277 "parser.y"
            {
    (yyval.node) = createOpNode(-1,16,NULL,NULL);
  }
#line 1691 "y.tab.c"
    break;

  case 46: /* S: CONTINUE ';'  */
#line 281 "parser.y"
               {
    (yyval.node) = createOpNode(-1,17,NULL,NULL);
  }
#line 1699 "y.tab.c"
    break;

  case 47: /* S: RETURN E ';'  */
#line 285 "parser.y"
               {
    (yyval.node) = createReturnNode((yyvsp[-1].node));
  }
#line 1707 "y.tab.c"
    break;

  case 48: /* IFST: IF '(' E ')' THEN SL ELSE SL ENDIF  */
#line 291 "parser.y"
                                        {
      (yyval.node) = createIfNode((yyvsp[-6].node),(yyvsp[-3].node),(yyvsp[-1].node));
    }
#line 1715 "y.tab.c"
    break;

  case 49: /* IFST: IF '(' E ')' THEN SL ENDIF  */
#line 295 "parser.y"
                               {
      (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-1].node),NULL);
    }
#line 1723 "y.tab.c"
    break;

  case 50: /* WHILEST: WHILE '(' E ')' DO SL ENDWHILE  */
#line 301 "parser.y"
                                       {
        (yyval.node) = createWhileNode(15,(yyvsp[-4].node),(yyvsp[-1].node));
        }
#line 1731 "y.tab.c"
    break;

  case 51: /* REPEATST: REPEAT SL UNTIL '(' E ')'  */
#line 307 "parser.y"
                                   {
         (yyval.node) = createWhileNode(18,(yyvsp[-1].node),(yyvsp[-4].node));
        }
#line 1739 "y.tab.c"
    break;

  case 52: /* DOWHILEST: DO SL WHILE '(' E ')'  */
#line 313 "parser.y"
                                { 
          (yyval.node) = createWhileNode(19,(yyvsp[-1].node),(yyvsp[-4].node));
          }
#line 1747 "y.tab.c"
    break;

  case 53: /* ASSG: IDENTIFIER EQUALS E  */
#line 320 "parser.y"
                      {
  (yyval.node) = createOpNode(-1,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1755 "y.tab.c"
    break;

  case 54: /* E: E PLUS E  */
#line 326 "parser.y"
           {
  (yyval.node) = createOpNode(0,0,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1763 "y.tab.c"
    break;

  case 55: /* E: E MINUS E  */
#line 330 "parser.y"
            {
  (yyval.node) = createOpNode(0,1,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1771 "y.tab.c"
    break;

  case 56: /* E: E MUL E  */
#line 334 "parser.y"
          {
  (yyval.node) = createOpNode(0,2,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1779 "y.tab.c"
    break;

  case 57: /* E: E DIV E  */
#line 338 "parser.y"
          {
  (yyval.node) = createOpNode(0,3,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1787 "y.tab.c"
    break;

  case 58: /* E: E LT E  */
#line 342 "parser.y"
         {
  (yyval.node) = createOpNode(1,5,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1795 "y.tab.c"
    break;

  case 59: /* E: E LTE E  */
#line 346 "parser.y"
          {
  (yyval.node) = createOpNode(1,6,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1803 "y.tab.c"
    break;

  case 60: /* E: E GT E  */
#line 350 "parser.y"
         {
  (yyval.node) = createOpNode(1,7,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1811 "y.tab.c"
    break;

  case 61: /* E: E GTE E  */
#line 354 "parser.y"
          {
  (yyval.node) = createOpNode(1,8,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1819 "y.tab.c"
    break;

  case 62: /* E: E NEQ E  */
#line 358 "parser.y"
          {
  (yyval.node) = createOpNode(1,9,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1827 "y.tab.c"
    break;

  case 63: /* E: E EQ E  */
#line 362 "parser.y"
         {
  (yyval.node) = createOpNode(1,10,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1835 "y.tab.c"
    break;

  case 64: /* E: '(' E ')'  */
#line 366 "parser.y"
            {
  (yyval.node) = (yyvsp[-1].node);
  }
#line 1843 "y.tab.c"
    break;

  case 67: /* IDENTIFIER: ID  */
#line 376 "parser.y"
              { 
            (yyval.node) = createIdNode((yyvsp[0].string),NULL,NULL);
           }
#line 1851 "y.tab.c"
    break;

  case 68: /* IDENTIFIER: ID '[' E ']'  */
#line 380 "parser.y"
                        {
            (yyval.node) = createIdNode((yyvsp[-3].string),NULL,(yyvsp[-1].node));
            }
#line 1859 "y.tab.c"
    break;

  case 69: /* IDENTIFIER: ID '[' E ']' '[' E ']'  */
#line 384 "parser.y"
                                  {
            (yyval.node) = createIdNode((yyvsp[-6].string),(yyvsp[-4].node),(yyvsp[-1].node));
            }
#line 1867 "y.tab.c"
    break;

  case 70: /* IDENTIFIER: ID '(' ')'  */
#line 388 "parser.y"
                       {
            (yyval.node) = createFunctionNode((yyvsp[-2].string),NULL);
            }
#line 1875 "y.tab.c"
    break;

  case 71: /* IDENTIFIER: ID '(' ArgList ')'  */
#line 392 "parser.y"
                               { 
            (yyval.node) = createFunctionNode((yyvsp[-3].string),(yyvsp[-1].node));
            }
#line 1883 "y.tab.c"
    break;

  case 72: /* ArgList: ArgList ',' E  */
#line 398 "parser.y"
                       {
        (yyval.node) = addArgToList((yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1891 "y.tab.c"
    break;

  case 73: /* ArgList: E  */
#line 402 "parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
        }
#line 1899 "y.tab.c"
    break;

  case 74: /* CONSTANT: NUM  */
#line 409 "parser.y"
             {
          (yyval.node) = createNumNode(atoi((yyvsp[0].string)));
          }
#line 1907 "y.tab.c"
    break;

  case 75: /* CONSTANT: STRING  */
#line 413 "parser.y"
                {
          (yyval.node) = createStringNode((yyvsp[0].string));
          }
#line 1915 "y.tab.c"
    break;

  case 76: /* INPUT: READ '(' IDENTIFIER ')'  */
#line 420 "parser.y"
                               {
       (yyval.node) = createOpNode(-1,11,(yyvsp[-1].node),NULL);
      }
#line 1923 "y.tab.c"
    break;

  case 77: /* OUTPUT: WRITE '(' E ')'  */
#line 426 "parser.y"
                       {
        (yyval.node) = createOpNode(-1,12,(yyvsp[-1].node),NULL);
      }
#line 1931 "y.tab.c"
    break;


#line 1935 "y.tab.c"

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

#line 433 "parser.y"



int main(int argc, char* argv[]){

  FILE* f = fopen(argv[1],"r");
  yyin = f;

  addGSymbol("main",0,0,0,NULL,1);
  


  xsm = fopen("assembly_code.xsm","w");
  fprintf(xsm,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
  //fprintf(xsm,"BRKP\n");

  fprintf(xsm,"MOV SP, 4500\n");
  fprintf(xsm,"MOV BP, SP\n");

  // F0 IS THE MAIN FUNCTION, SO GO THERE
  fprintf(xsm,"JMP F0\n");

  
// --------------------------------- PARSING INPUT 
  yyparse();



// --------------------------------- ASSEMBLY CODE




// --------------------------------- EXERCISE 1


/*
  printf("RUNNING EXERCISE1\n");
  evaluate(root);
  getDetails();
*/

  return 0;
}

void yyerror(char* s){
  printf("ERROR:%s\n",s);
}

