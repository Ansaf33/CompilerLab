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


struct TreeNode* root;


extern FILE* yyin;

int yylex(void);
void yyerror(char* s);




#line 97 "y.tab.c"

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
    MAIN = 276,                    /* MAIN  */
    IF = 277,                      /* IF  */
    THEN = 278,                    /* THEN  */
    ELSE = 279,                    /* ELSE  */
    ENDIF = 280,                   /* ENDIF  */
    WHILE = 281,                   /* WHILE  */
    DO = 282,                      /* DO  */
    ENDWHILE = 283,                /* ENDWHILE  */
    BREAK = 284,                   /* BREAK  */
    CONTINUE = 285,                /* CONTINUE  */
    REPEAT = 286,                  /* REPEAT  */
    UNTIL = 287,                   /* UNTIL  */
    DECL = 288,                    /* DECL  */
    ENDDECL = 289,                 /* ENDDECL  */
    INT = 290,                     /* INT  */
    STR = 291                      /* STR  */
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
#define MAIN 276
#define IF 277
#define THEN 278
#define ELSE 279
#define ENDIF 280
#define WHILE 281
#define DO 282
#define ENDWHILE 283
#define BREAK 284
#define CONTINUE 285
#define REPEAT 286
#define UNTIL 287
#define DECL 288
#define ENDDECL 289
#define INT 290
#define STR 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "parser.y"

  struct TreeNode* node;
  char* string;
  int integer;
  struct list* list;
  struct paramlist* paramlist;




#line 233 "y.tab.c"

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
  YYSYMBOL_MAIN = 21,                      /* MAIN  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_THEN = 23,                      /* THEN  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_ENDIF = 25,                     /* ENDIF  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_DO = 27,                        /* DO  */
  YYSYMBOL_ENDWHILE = 28,                  /* ENDWHILE  */
  YYSYMBOL_BREAK = 29,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 30,                  /* CONTINUE  */
  YYSYMBOL_REPEAT = 31,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 32,                     /* UNTIL  */
  YYSYMBOL_DECL = 33,                      /* DECL  */
  YYSYMBOL_ENDDECL = 34,                   /* ENDDECL  */
  YYSYMBOL_INT = 35,                       /* INT  */
  YYSYMBOL_STR = 36,                       /* STR  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_PROGRAM = 46,                   /* PROGRAM  */
  YYSYMBOL_GdeclBlock = 47,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 48,                 /* GdeclList  */
  YYSYMBOL_Gdecl = 49,                     /* Gdecl  */
  YYSYMBOL_TYPE = 50,                      /* TYPE  */
  YYSYMBOL_GidList = 51,                   /* GidList  */
  YYSYMBOL_FdefBlock = 52,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 53,                      /* Fdef  */
  YYSYMBOL_ParamList = 54,                 /* ParamList  */
  YYSYMBOL_LdeclBlock = 55,                /* LdeclBlock  */
  YYSYMBOL_LdeclList = 56,                 /* LdeclList  */
  YYSYMBOL_Ldecl = 57,                     /* Ldecl  */
  YYSYMBOL_LidList = 58,                   /* LidList  */
  YYSYMBOL_MainBlock = 59,                 /* MainBlock  */
  YYSYMBOL_Body = 60,                      /* Body  */
  YYSYMBOL_SL = 61,                        /* SL  */
  YYSYMBOL_S = 62,                         /* S  */
  YYSYMBOL_IFST = 63,                      /* IFST  */
  YYSYMBOL_WHILEST = 64,                   /* WHILEST  */
  YYSYMBOL_REPEATST = 65,                  /* REPEATST  */
  YYSYMBOL_DOWHILEST = 66,                 /* DOWHILEST  */
  YYSYMBOL_ASSG = 67,                      /* ASSG  */
  YYSYMBOL_E = 68,                         /* E  */
  YYSYMBOL_IDENTIFIER = 69,                /* IDENTIFIER  */
  YYSYMBOL_ArgList = 70,                   /* ArgList  */
  YYSYMBOL_CONSTANT = 71,                  /* CONSTANT  */
  YYSYMBOL_INPUT = 72,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 73                     /* OUTPUT  */
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
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      41,    42,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    59,    61,    65,    70,    74,    76,    80,
      86,    90,    96,   100,   104,   108,   112,   116,   120,   124,
     130,   132,   136,   145,   149,   153,   160,   166,   170,   172,
     178,   183,   187,   194,   203,   209,   215,   219,   225,   227,
     229,   231,   233,   235,   237,   239,   243,   249,   253,   259,
     265,   271,   278,   284,   288,   292,   296,   300,   304,   308,
     312,   316,   320,   324,   328,   330,   334,   338,   342,   346,
     350,   356,   360,   367,   371,   378,   384
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
  "NEQ", "READ", "WRITE", "END", "BEG", "MAIN", "IF", "THEN", "ELSE",
  "ENDIF", "WHILE", "DO", "ENDWHILE", "BREAK", "CONTINUE", "REPEAT",
  "UNTIL", "DECL", "ENDDECL", "INT", "STR", "';'", "','", "'['", "']'",
  "'('", "')'", "'{'", "'}'", "$accept", "PROGRAM", "GdeclBlock",
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
      25,    68,   -13,    13,    10,   -90,   -90,   -90,   -90,    75,
     -90,    15,   -14,   -90,   -13,    31,    10,   -90,   -90,   -90,
     -90,    28,    26,    -2,    30,   -90,   -90,    83,    60,   -90,
      79,    56,    60,    72,   120,   -27,    38,    92,   -26,   103,
     -90,    60,   -90,   148,    60,    81,   111,   122,   159,   162,
     127,    -1,   -90,   165,   126,   -90,   254,   124,    92,   156,
     -90,   166,   -90,   -90,    84,   -90,   -90,    41,   163,   167,
     170,   168,   169,   307,   174,   187,   307,   270,   -90,   188,
     195,   202,   205,   209,   193,   211,   214,   -90,   111,   -90,
     255,   -90,   208,    29,    20,   240,    29,   -90,    29,    29,
     331,   -90,   -90,   223,   225,   -90,   -90,   -90,   -90,   -90,
     -90,    29,   -90,   -90,   215,   227,   -90,   -90,   -90,    29,
     186,   -90,   -90,   -90,   222,     0,   233,    78,   121,   132,
     236,   237,   -90,   222,   -90,   -90,   143,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,   243,    29,   -90,
     -90,   -90,   256,   259,    29,    29,   -90,    97,    97,   -90,
     -90,    67,    67,    67,    67,   333,   333,    29,   222,   307,
     307,   164,   175,   207,   239,   286,   259,   -90,   -90,   307,
     -90,   -90,   301,   -90
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
      23,    13,    15,    32,     0,    26,    28,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,    18,
       0,    30,     0,     0,     0,     0,     0,    35,     0,     0,
       0,    45,    46,     0,     0,    36,    41,    42,    43,    44,
      38,     0,    39,    40,     0,     0,    31,    74,    73,     0,
       0,    65,    64,    69,    72,     0,     0,     0,     0,     0,
       0,     0,    34,    52,    22,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,    70,
      75,    76,     0,     0,     0,     0,    63,    53,    54,    55,
      56,    57,    58,    59,    60,    62,    61,     0,    71,     0,
       0,     0,     0,     0,     0,     0,    51,    50,    68,     0,
      48,    49,     0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   -90,   -90,   282,    27,   -90,   -90,   277,   -30,
     244,   -90,   241,   -90,     2,   206,   -72,   -74,   -90,   -90,
     -90,   -90,   -90,   -89,   -56,   -90,   -90,   -90,   -90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     9,    10,    34,    22,    16,    17,    35,
      46,    54,    55,    64,     5,    57,    77,    78,    79,    80,
      81,    82,    83,   120,   121,   125,   122,    85,    86
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      84,   100,    38,   105,   103,   124,    18,   127,    12,   128,
     129,    41,    41,    13,    51,    42,    47,    84,    26,    21,
      84,    84,   133,   117,    67,   118,   105,    23,    11,   105,
     136,    15,   117,    67,   118,    24,    11,    41,   148,   126,
      31,    62,   149,    15,    84,    14,     8,    84,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,     1,   168,
       2,   119,   123,    29,    30,   171,   172,    27,    49,    28,
     119,    32,    53,   137,   138,   139,   140,    43,   173,    44,
      93,    53,    94,    36,   137,   138,   139,   140,    33,   141,
     142,   143,   144,   145,   146,     7,     8,   174,   175,    37,
     105,   105,     6,     7,     8,   139,   140,   182,   105,    19,
       7,     8,    39,    84,    84,    52,     7,     8,    84,    84,
     151,    91,    92,    84,    40,    45,    84,   137,   138,   139,
     140,    56,   141,   142,   143,   144,   145,   146,   137,   138,
     139,   140,    48,   141,   142,   143,   144,   145,   146,   137,
     138,   139,   140,    50,   141,   142,   143,   144,   145,   146,
      65,     7,     8,   152,    59,    58,    60,    61,    87,    63,
     137,   138,   139,   140,   153,   141,   142,   143,   144,   145,
     146,   137,   138,   139,   140,   156,   141,   142,   143,   144,
     145,   146,   137,   138,   139,   140,    89,   141,   142,   143,
     144,   145,   146,   111,    95,    90,   176,    97,    96,    98,
      99,   101,   116,   137,   138,   139,   140,   177,   141,   142,
     143,   144,   145,   146,   102,   106,   147,    67,   137,   138,
     139,   140,   107,   141,   142,   143,   144,   145,   146,   108,
      68,    69,   109,    67,    67,    71,   110,   178,   112,    72,
      73,   113,    74,    75,    76,   131,    68,    69,    67,   134,
     115,    71,   132,   179,   180,    72,    73,   135,    74,    75,
      76,    68,    69,    70,    67,   150,    71,   154,   155,   169,
      72,    73,   167,    74,    75,    76,   170,    68,    69,   104,
      67,    20,    71,    25,   114,    66,    72,    73,     0,    74,
      75,    76,    88,    68,    69,    67,     0,     0,    71,     0,
       0,    67,    72,    73,   181,    74,    75,    76,    68,    69,
       0,     0,     0,    71,    68,    69,   183,    72,    73,    71,
      74,    75,    76,    72,    73,    67,    74,    75,    76,   137,
     138,   139,   140,     0,   141,   142,   143,   144,    68,    69,
       0,     0,     0,    71,     0,     0,     0,   130,    73,     0,
      74,    75,    76
};

static const yytype_int16 yycheck[] =
{
      56,    73,    32,    77,    76,    94,     4,    96,    21,    98,
      99,    38,    38,     0,    44,    42,    42,    73,    16,     4,
      76,    77,   111,     3,     4,     5,   100,    41,     1,   103,
     119,     4,     3,     4,     5,     4,     9,    38,    38,    95,
      42,    42,    42,    16,   100,    35,    36,   103,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    33,   148,
      35,    41,    42,    37,    38,   154,   155,    39,    41,    41,
      41,    41,    45,     6,     7,     8,     9,    39,   167,    41,
      39,    54,    41,     4,     6,     7,     8,     9,     5,    11,
      12,    13,    14,    15,    16,    35,    36,   169,   170,    43,
     174,   175,    34,    35,    36,     8,     9,   179,   182,    34,
      35,    36,    40,   169,   170,    34,    35,    36,   174,   175,
      42,    37,    38,   179,     4,    33,   182,     6,     7,     8,
       9,    20,    11,    12,    13,    14,    15,    16,     6,     7,
       8,     9,    39,    11,    12,    13,    14,    15,    16,     6,
       7,     8,     9,     5,    11,    12,    13,    14,    15,    16,
      34,    35,    36,    42,     5,    43,     4,    40,    44,     4,
       6,     7,     8,     9,    42,    11,    12,    13,    14,    15,
      16,     6,     7,     8,     9,    42,    11,    12,    13,    14,
      15,    16,     6,     7,     8,     9,    40,    11,    12,    13,
      14,    15,    16,    10,    41,    39,    42,    37,    41,    41,
      41,    37,     4,     6,     7,     8,     9,    42,    11,    12,
      13,    14,    15,    16,    37,    37,    40,     4,     6,     7,
       8,     9,    37,    11,    12,    13,    14,    15,    16,    37,
      17,    18,    37,     4,     4,    22,    37,    40,    37,    26,
      27,    37,    29,    30,    31,    32,    17,    18,     4,    44,
       5,    22,    37,    24,    25,    26,    27,    40,    29,    30,
      31,    17,    18,    19,     4,    42,    22,    41,    41,    23,
      26,    27,    39,    29,    30,    31,    27,    17,    18,    19,
       4,     9,    22,    16,    88,    54,    26,    27,    -1,    29,
      30,    31,    58,    17,    18,     4,    -1,    -1,    22,    -1,
      -1,     4,    26,    27,    28,    29,    30,    31,    17,    18,
      -1,    -1,    -1,    22,    17,    18,    25,    26,    27,    22,
      29,    30,    31,    26,    27,     4,    29,    30,    31,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    17,    18,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    26,    27,    -1,
      29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    35,    46,    47,    59,    34,    35,    36,    48,
      49,    50,    21,     0,    35,    50,    52,    53,    59,    34,
      49,     4,    51,    41,     4,    53,    59,    39,    41,    37,
      38,    42,    41,     5,    50,    54,     4,    43,    54,    40,
       4,    38,    42,    39,    41,    33,    55,    42,    39,    50,
       5,    54,    34,    50,    56,    57,    20,    60,    43,     5,
       4,    40,    42,     4,    58,    34,    57,     4,    17,    18,
      19,    22,    26,    27,    29,    30,    31,    61,    62,    63,
      64,    65,    66,    67,    69,    72,    73,    44,    55,    40,
      39,    37,    38,    39,    41,    41,    41,    37,    41,    41,
      61,    37,    37,    61,    19,    62,    37,    37,    37,    37,
      37,    10,    37,    37,    60,     5,     4,     3,     5,    41,
      68,    69,    71,    42,    68,    70,    69,    68,    68,    68,
      26,    32,    37,    68,    44,    40,    68,     6,     7,     8,
       9,    11,    12,    13,    14,    15,    16,    40,    38,    42,
      42,    42,    42,    42,    41,    41,    42,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    39,    68,    23,
      27,    68,    68,    68,    61,    61,    42,    42,    40,    24,
      25,    28,    61,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    46,    47,    47,    48,    48,    49,
      50,    50,    51,    51,    51,    51,    51,    51,    51,    51,
      52,    52,    53,    54,    54,    54,    55,    55,    56,    56,
      57,    58,    58,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    64,
      65,    66,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    69,    69,
      69,    70,    70,    71,    71,    72,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     3,     6,     9,     6,     1,     4,     7,     4,
       2,     1,     9,     4,     2,     0,     3,     2,     2,     1,
       3,     3,     1,     8,     4,     3,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     9,     7,     7,
       6,     6,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     4,     7,     3,
       4,     3,     1,     1,     1,     4,     4
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
#line 65 "parser.y"
                                   {
                printf("All Global Declarations parsed.\n");
                getGSymbolTable();
              }
#line 1437 "y.tab.c"
    break;

  case 9: /* Gdecl: TYPE GidList ';'  */
#line 80 "parser.y"
                      {
        addAllGSymbols((yyvsp[-1].list),(yyvsp[-2].integer));
     }
#line 1445 "y.tab.c"
    break;

  case 10: /* TYPE: INT  */
#line 86 "parser.y"
         {
     (yyval.integer) = (yyvsp[0].integer);
     }
#line 1453 "y.tab.c"
    break;

  case 11: /* TYPE: STR  */
#line 90 "parser.y"
         {
     (yyval.integer) = (yyvsp[0].integer);
     }
#line 1461 "y.tab.c"
    break;

  case 12: /* GidList: GidList ',' ID  */
#line 96 "parser.y"
                       {
          (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1469 "y.tab.c"
    break;

  case 13: /* GidList: GidList ',' ID '[' NUM ']'  */
#line 100 "parser.y"
                                   {
          (yyval.list) = addArray((yyvsp[-5].list),(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1477 "y.tab.c"
    break;

  case 14: /* GidList: GidList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 104 "parser.y"
                                               {
          (yyval.list) = addArray((yyvsp[-8].list),(yyvsp[-8].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1485 "y.tab.c"
    break;

  case 15: /* GidList: GidList ',' ID '(' ParamList ')'  */
#line 108 "parser.y"
                                         {
          (yyval.list) = addFunction((yyvsp[-5].list),(yyvsp[-3].string),(yyvsp[-1].paramlist));
        }
#line 1493 "y.tab.c"
    break;

  case 16: /* GidList: ID  */
#line 112 "parser.y"
           {
          (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1501 "y.tab.c"
    break;

  case 17: /* GidList: ID '[' NUM ']'  */
#line 116 "parser.y"
                       {
          (yyval.list) = addArray(NULL,(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1509 "y.tab.c"
    break;

  case 18: /* GidList: ID '[' NUM ']' '[' NUM ']'  */
#line 120 "parser.y"
                                   {
          (yyval.list) = addArray(NULL,(yyvsp[-6].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1517 "y.tab.c"
    break;

  case 19: /* GidList: ID '(' ParamList ')'  */
#line 124 "parser.y"
                             {
          (yyval.list) = addFunction(NULL,(yyvsp[-3].string),(yyvsp[-1].paramlist));
        }
#line 1525 "y.tab.c"
    break;

  case 22: /* Fdef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 136 "parser.y"
                                                       {



     }
#line 1535 "y.tab.c"
    break;

  case 23: /* ParamList: ParamList ',' TYPE ID  */
#line 145 "parser.y"
                                {
           (yyval.paramlist) = addParameter((yyvsp[-3].paramlist),(yyvsp[0].string),(yyvsp[-1].integer));
          }
#line 1543 "y.tab.c"
    break;

  case 24: /* ParamList: TYPE ID  */
#line 149 "parser.y"
                  {
           (yyval.paramlist) = addParameter(NULL,(yyvsp[0].string),(yyvsp[-1].integer));
          }
#line 1551 "y.tab.c"
    break;

  case 25: /* ParamList: %empty  */
#line 153 "parser.y"
           {
           (yyval.paramlist) = NULL;
          }
#line 1559 "y.tab.c"
    break;

  case 26: /* LdeclBlock: DECL LdeclList ENDDECL  */
#line 160 "parser.y"
                                  {
           printf("All Local Declarations Parsed\n");
           getLSymbolTable();

           }
#line 1569 "y.tab.c"
    break;

  case 29: /* LdeclList: Ldecl  */
#line 172 "parser.y"
                {

          }
#line 1577 "y.tab.c"
    break;

  case 30: /* Ldecl: TYPE LidList ';'  */
#line 178 "parser.y"
                       {
         addAllLSymbols((yyvsp[-1].list),(yyvsp[-2].integer));
      }
#line 1585 "y.tab.c"
    break;

  case 31: /* LidList: LidList ',' ID  */
#line 183 "parser.y"
                       {
        (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1593 "y.tab.c"
    break;

  case 32: /* LidList: ID  */
#line 187 "parser.y"
           {
        (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1601 "y.tab.c"
    break;

  case 33: /* MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 194 "parser.y"
                                                   {


          }
#line 1610 "y.tab.c"
    break;

  case 34: /* Body: BEG SL END ';'  */
#line 203 "parser.y"
                 {
    root = (yyvsp[-2].node);
    printf("Valid Program.\n");
    Inorder((yyvsp[-2].node));
  }
#line 1620 "y.tab.c"
    break;

  case 35: /* Body: BEG END ';'  */
#line 209 "parser.y"
              {
  printf("Valid program.\n");
  }
#line 1628 "y.tab.c"
    break;

  case 36: /* SL: SL S  */
#line 215 "parser.y"
         {
   (yyval.node) = createOpNode(-1,13,(yyvsp[-1].node),(yyvsp[0].node));
  }
#line 1636 "y.tab.c"
    break;

  case 37: /* SL: S  */
#line 219 "parser.y"
      {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1644 "y.tab.c"
    break;

  case 45: /* S: BREAK ';'  */
#line 239 "parser.y"
            {
    (yyval.node) = createOpNode(-1,16,NULL,NULL);
  }
#line 1652 "y.tab.c"
    break;

  case 46: /* S: CONTINUE ';'  */
#line 243 "parser.y"
               {
    (yyval.node) = createOpNode(-1,17,NULL,NULL);
  }
#line 1660 "y.tab.c"
    break;

  case 47: /* IFST: IF '(' E ')' THEN SL ELSE SL ENDIF  */
#line 249 "parser.y"
                                        {
      (yyval.node) = createIfNode((yyvsp[-6].node),(yyvsp[-3].node),(yyvsp[-1].node));
    }
#line 1668 "y.tab.c"
    break;

  case 48: /* IFST: IF '(' E ')' THEN SL ENDIF  */
#line 253 "parser.y"
                               {
      (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-1].node),NULL);
    }
#line 1676 "y.tab.c"
    break;

  case 49: /* WHILEST: WHILE '(' E ')' DO SL ENDWHILE  */
#line 259 "parser.y"
                                       {
        (yyval.node) = createWhileNode(15,(yyvsp[-4].node),(yyvsp[-1].node));
        }
#line 1684 "y.tab.c"
    break;

  case 50: /* REPEATST: REPEAT SL UNTIL '(' E ')'  */
#line 265 "parser.y"
                                   {
         (yyval.node) = createWhileNode(18,(yyvsp[-1].node),(yyvsp[-4].node));
        }
#line 1692 "y.tab.c"
    break;

  case 51: /* DOWHILEST: DO SL WHILE '(' E ')'  */
#line 271 "parser.y"
                                { 
          (yyval.node) = createWhileNode(19,(yyvsp[-1].node),(yyvsp[-4].node));
          }
#line 1700 "y.tab.c"
    break;

  case 52: /* ASSG: IDENTIFIER EQUALS E  */
#line 278 "parser.y"
                      {
  (yyval.node) = createOpNode(-1,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1708 "y.tab.c"
    break;

  case 53: /* E: E PLUS E  */
#line 284 "parser.y"
           {
  (yyval.node) = createOpNode(0,0,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1716 "y.tab.c"
    break;

  case 54: /* E: E MINUS E  */
#line 288 "parser.y"
            {
  (yyval.node) = createOpNode(0,1,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1724 "y.tab.c"
    break;

  case 55: /* E: E MUL E  */
#line 292 "parser.y"
          {
  (yyval.node) = createOpNode(0,2,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1732 "y.tab.c"
    break;

  case 56: /* E: E DIV E  */
#line 296 "parser.y"
          {
  (yyval.node) = createOpNode(0,3,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1740 "y.tab.c"
    break;

  case 57: /* E: E LT E  */
#line 300 "parser.y"
         {
  (yyval.node) = createOpNode(1,5,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1748 "y.tab.c"
    break;

  case 58: /* E: E LTE E  */
#line 304 "parser.y"
          {
  (yyval.node) = createOpNode(1,6,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1756 "y.tab.c"
    break;

  case 59: /* E: E GT E  */
#line 308 "parser.y"
         {
  (yyval.node) = createOpNode(1,7,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1764 "y.tab.c"
    break;

  case 60: /* E: E GTE E  */
#line 312 "parser.y"
          {
  (yyval.node) = createOpNode(1,8,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1772 "y.tab.c"
    break;

  case 61: /* E: E NEQ E  */
#line 316 "parser.y"
          {
  (yyval.node) = createOpNode(1,9,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1780 "y.tab.c"
    break;

  case 62: /* E: E EQ E  */
#line 320 "parser.y"
         {
  (yyval.node) = createOpNode(1,10,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1788 "y.tab.c"
    break;

  case 63: /* E: '(' E ')'  */
#line 324 "parser.y"
            {
  (yyval.node) = (yyvsp[-1].node);
  }
#line 1796 "y.tab.c"
    break;

  case 66: /* IDENTIFIER: ID  */
#line 334 "parser.y"
              { 
            (yyval.node) = createIdNode((yyvsp[0].string),NULL,NULL);
           }
#line 1804 "y.tab.c"
    break;

  case 67: /* IDENTIFIER: ID '[' E ']'  */
#line 338 "parser.y"
                        {
            (yyval.node) = createIdNode((yyvsp[-3].string),NULL,(yyvsp[-1].node));
            }
#line 1812 "y.tab.c"
    break;

  case 68: /* IDENTIFIER: ID '[' E ']' '[' E ']'  */
#line 342 "parser.y"
                                  {
            (yyval.node) = createIdNode((yyvsp[-6].string),(yyvsp[-4].node),(yyvsp[-1].node));
            }
#line 1820 "y.tab.c"
    break;

  case 69: /* IDENTIFIER: ID '(' ')'  */
#line 346 "parser.y"
                       {
            (yyval.node) = createFunctionNode((yyvsp[-2].string),NULL);
            }
#line 1828 "y.tab.c"
    break;

  case 70: /* IDENTIFIER: ID '(' ArgList ')'  */
#line 350 "parser.y"
                               { 
            (yyval.node) = createFunctionNode((yyvsp[-3].string),(yyvsp[-1].node));
            }
#line 1836 "y.tab.c"
    break;

  case 71: /* ArgList: ArgList ',' E  */
#line 356 "parser.y"
                       {
        (yyval.node) = addArgToList((yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1844 "y.tab.c"
    break;

  case 72: /* ArgList: E  */
#line 360 "parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
        }
#line 1852 "y.tab.c"
    break;

  case 73: /* CONSTANT: NUM  */
#line 367 "parser.y"
             {
          (yyval.node) = createNumNode(atoi((yyvsp[0].string)));
          }
#line 1860 "y.tab.c"
    break;

  case 74: /* CONSTANT: STRING  */
#line 371 "parser.y"
                {
          (yyval.node) = createStringNode((yyvsp[0].string));
          }
#line 1868 "y.tab.c"
    break;

  case 75: /* INPUT: READ '(' IDENTIFIER ')'  */
#line 378 "parser.y"
                               {
       (yyval.node) = createOpNode(-1,11,(yyvsp[-1].node),NULL);
      }
#line 1876 "y.tab.c"
    break;

  case 76: /* OUTPUT: WRITE '(' E ')'  */
#line 384 "parser.y"
                       {
        (yyval.node) = createOpNode(-1,12,(yyvsp[-1].node),NULL);
      }
#line 1884 "y.tab.c"
    break;


#line 1888 "y.tab.c"

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

#line 392 "parser.y"










int main(int argc, char* argv[]){


// --------------------------------- PARSING INPUT 
  FILE* f = fopen(argv[1],"r");
  yyin = f;
  yyparse();



// --------------------------------- ASSEMBLY CODE



  FILE* xsm = fopen(argv[2],"w");
  fprintf(xsm,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
  //fprintf(xsm,"BRKP\n");
  codeGen(xsm,root,-1,-1);
  fprintf(xsm,"JMP L51\n");

  // OVERFLOW CONDITION
  fprintf(xsm,"L50:\n");
  getInput(xsm,"Overflow");
  fprintf(xsm,"INT 10\n");

  // END
  fprintf(xsm,"L51:\n");
  fprintf(xsm,"INT 10\n");






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

