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


struct TreeNode* root;


extern FILE* yyin;

int yylex(void);
void yyerror(char* s);




#line 96 "y.tab.c"

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
    DECL = 287,                    /* DECL  */
    ENDDECL = 288,                 /* ENDDECL  */
    INT = 289,                     /* INT  */
    STR = 290                      /* STR  */
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
#define DECL 287
#define ENDDECL 288
#define INT 289
#define STR 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

  struct TreeNode* node;
  char* string;
  int integer;
  struct list* list;
  struct paramlist* paramlist;




#line 230 "y.tab.c"

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
  YYSYMBOL_DECL = 32,                      /* DECL  */
  YYSYMBOL_ENDDECL = 33,                   /* ENDDECL  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_STR = 35,                       /* STR  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_PROGRAM = 45,                   /* PROGRAM  */
  YYSYMBOL_GdeclBlock = 46,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 47,                 /* GdeclList  */
  YYSYMBOL_Gdecl = 48,                     /* Gdecl  */
  YYSYMBOL_TYPE = 49,                      /* TYPE  */
  YYSYMBOL_GidList = 50,                   /* GidList  */
  YYSYMBOL_FdefBlock = 51,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 52,                      /* Fdef  */
  YYSYMBOL_ParamList = 53,                 /* ParamList  */
  YYSYMBOL_LdeclBlock = 54,                /* LdeclBlock  */
  YYSYMBOL_LdeclList = 55,                 /* LdeclList  */
  YYSYMBOL_Ldecl = 56,                     /* Ldecl  */
  YYSYMBOL_LidList = 57,                   /* LidList  */
  YYSYMBOL_Body = 58,                      /* Body  */
  YYSYMBOL_MainBlock = 59,                 /* MainBlock  */
  YYSYMBOL_SL = 60,                        /* SL  */
  YYSYMBOL_S = 61,                         /* S  */
  YYSYMBOL_IFST = 62,                      /* IFST  */
  YYSYMBOL_WHILEST = 63,                   /* WHILEST  */
  YYSYMBOL_REPEATST = 64,                  /* REPEATST  */
  YYSYMBOL_DOWHILEST = 65,                 /* DOWHILEST  */
  YYSYMBOL_ASSG = 66,                      /* ASSG  */
  YYSYMBOL_E = 67,                         /* E  */
  YYSYMBOL_IDENTIFIER = 68,                /* IDENTIFIER  */
  YYSYMBOL_ArgList = 69,                   /* ArgList  */
  YYSYMBOL_CONSTANT = 70,                  /* CONSTANT  */
  YYSYMBOL_INPUT = 71,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 72                     /* OUTPUT  */
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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   401

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      40,    41,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    58,    60,    64,    69,    73,    75,    79,
      85,    89,    95,    99,   103,   107,   111,   115,   119,   123,
     129,   131,   135,   139,   143,   149,   151,   155,   157,   161,
     164,   166,   170,   200,   206,   212,   216,   222,   224,   226,
     228,   230,   232,   234,   236,   240,   246,   250,   256,   262,
     268,   275,   281,   285,   289,   293,   297,   301,   305,   309,
     313,   317,   321,   325,   327,   331,   335,   339,   343,   347,
     353,   355,   360,   364,   371,   377
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
  "DECL", "ENDDECL", "INT", "STR", "';'", "','", "'['", "']'", "'('",
  "')'", "'{'", "'}'", "$accept", "PROGRAM", "GdeclBlock", "GdeclList",
  "Gdecl", "TYPE", "GidList", "FdefBlock", "Fdef", "ParamList",
  "LdeclBlock", "LdeclList", "Ldecl", "LidList", "Body", "MainBlock", "SL",
  "S", "IFST", "WHILEST", "REPEATST", "DOWHILEST", "ASSG", "E",
  "IDENTIFIER", "ArgList", "CONSTANT", "INPUT", "OUTPUT", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-86)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   258,    55,    39,     6,   -86,    -8,     2,     5,    11,
      28,    34,   336,    45,    62,   336,   274,   -86,    86,    92,
      94,   106,   108,   125,   115,   116,   -86,   -86,   -86,    72,
     -86,   149,   -86,   152,     6,   -86,   -86,    16,    13,   154,
      16,   -86,    16,    16,   351,   -86,   -86,   228,   123,   -86,
     -86,   -86,   -86,   -86,   -86,    16,   -86,   -86,   -86,   -86,
      17,    14,   124,   -86,   -86,   -86,   -86,    16,   202,   -86,
     -86,   -86,   376,   -34,   122,    71,    88,   102,   141,   159,
     -86,   376,   187,    57,   -86,   161,    57,   160,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,   162,    16,
     -86,   -86,   -86,   180,   177,    16,    16,   165,   201,   -13,
      83,   -10,   -86,   139,   139,   -86,   -86,    64,    64,    64,
      64,   387,   387,    16,   376,   336,   336,   171,   182,   168,
     -86,    57,   -86,   225,    57,   189,   213,   243,   290,   177,
     -86,   229,   203,   194,     7,   204,   -86,   336,   -86,   -86,
     196,   -86,   199,   -86,    99,   218,   305,   -86,   234,   -86,
     236,   105,   -86,   336,   200,   -86,   205,   -86,   113,   -86,
     -86,   320,   -86,   -86,   -86,   238,   212,   -86,   -86
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     6,    10,    11,     0,
       8,     0,     1,     0,     0,    21,     3,     0,     0,     0,
       0,    34,     0,     0,     0,    44,    45,     0,     0,    35,
      40,    41,    42,    43,    37,     0,    38,    39,     5,     7,
      16,     0,     0,    20,     2,    73,    72,     0,     0,    64,
      63,    68,    71,     0,     0,     0,     0,     0,     0,     0,
      33,    51,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
      69,    74,    75,     0,     0,     0,     0,     0,     0,     0,
      12,     0,    62,    52,    53,    54,    55,    56,    57,    58,
      59,    61,    60,     0,    70,     0,     0,     0,     0,    17,
      24,     0,    19,     0,     0,     0,     0,     0,     0,    50,
      49,     0,     0,     0,     0,     0,    67,     0,    47,    48,
       0,    23,    13,    15,     0,     0,     0,    18,     0,    26,
       0,     0,    28,     0,     0,    46,     0,    31,     0,    25,
      27,     0,    22,    14,    29,     0,     0,    30,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   -86,   -86,   -86,   221,     0,   -86,   -86,   217,   -85,
     -86,   -86,   104,   -86,   -86,    18,    -6,   -11,   -86,   -86,
     -86,   -86,   -86,   -30,    -1,   -86,   -86,   -86,   -86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    29,    30,   108,    61,    34,    35,   109,
     155,   161,   162,   168,   164,     5,    16,    17,    18,    19,
      20,    21,    22,    68,    69,    73,    70,    24,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,   111,    31,    99,    33,    49,    44,   100,    72,    47,
      75,    23,    76,    77,    23,    23,    65,     6,    66,    65,
       6,    66,    36,     1,   131,    81,     1,   131,   132,    31,
      37,   135,    38,    49,    33,     2,    49,    87,    74,    32,
      27,    28,    39,    23,   131,    40,    23,    41,   153,   144,
      84,    85,    64,    67,    71,    82,    67,    83,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    42,   124,
      88,    89,    90,    91,    43,   127,   128,    88,    89,    90,
      91,    45,    92,    93,    94,    95,    96,    97,    26,    27,
      28,    27,    28,   136,    88,    89,    90,    91,    46,    92,
      93,    94,    95,    96,    97,    58,    27,    28,    88,    89,
      90,    91,   102,    92,    93,    94,    95,    96,    97,   137,
     138,   133,    50,   134,    23,    23,    49,    49,    51,   103,
      52,   142,   159,    27,    28,    55,    23,    23,   169,    27,
      28,   156,    53,   104,    54,    49,    23,    90,    91,   174,
     175,    56,    57,    60,   160,    23,    62,   171,     6,    80,
      49,   160,    23,   101,    86,   110,    88,    89,    90,    91,
      23,    92,    93,    94,    95,    96,    97,    88,    89,    90,
      91,   105,    92,    93,    94,    95,    96,    97,    88,    89,
      90,    91,   107,    92,    93,    94,    95,    96,    97,   106,
     123,   112,   125,   126,   129,   130,   141,   151,    88,    89,
      90,    91,   139,    92,    93,    94,    95,    96,    97,    88,
      89,    90,    91,   140,    92,    93,    94,    95,    96,    97,
     143,   145,     6,   152,   150,   157,   154,   158,   163,   166,
     167,    98,   177,   172,   173,     7,     8,     6,   178,    10,
      59,    63,   146,    11,    12,     0,    13,    14,    15,    79,
       7,     8,     6,     0,    10,   170,   147,   148,    11,    12,
       0,    13,    14,    15,     0,     7,     8,     9,     6,    10,
       0,     0,     0,    11,    12,     0,    13,    14,    15,     0,
       0,     7,     8,    48,     6,    10,     0,     0,     0,    11,
      12,     0,    13,    14,    15,     0,     0,     7,     8,     6,
       0,    10,     0,     0,     0,    11,    12,   149,    13,    14,
      15,     0,     7,     8,     6,     0,    10,     0,     0,   165,
      11,    12,     0,    13,    14,    15,     0,     7,     8,   176,
       6,    10,     0,     0,     0,    11,    12,     0,    13,    14,
      15,     0,     0,     7,     8,     6,     0,    10,     0,     0,
       0,    11,    12,     0,    13,    14,    15,     0,     7,     8,
       0,     0,    10,     0,     0,     0,    78,    12,     0,    13,
      14,    15,    88,    89,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    88,    89,    90,    91,     0,    92,    93,
      94,    95
};

static const yytype_int16 yycheck[] =
{
       1,    86,     2,    37,     4,    16,    12,    41,    38,    15,
      40,    12,    42,    43,    15,    16,     3,     4,     5,     3,
       4,     5,     4,    20,    37,    55,    20,    37,    41,    29,
      38,    41,    40,    44,    34,    32,    47,    67,    39,     0,
      34,    35,    40,    44,    37,    40,    47,    36,    41,   134,
      36,    37,    34,    40,    41,    38,    40,    40,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    40,    99,
       6,     7,     8,     9,    40,   105,   106,     6,     7,     8,
       9,    36,    11,    12,    13,    14,    15,    16,    33,    34,
      35,    34,    35,   123,     6,     7,     8,     9,    36,    11,
      12,    13,    14,    15,    16,    33,    34,    35,     6,     7,
       8,     9,    41,    11,    12,    13,    14,    15,    16,   125,
     126,    38,    36,    40,   125,   126,   137,   138,    36,    41,
      36,   131,    33,    34,    35,    10,   137,   138,    33,    34,
      35,   147,    36,    41,    36,   156,   147,     8,     9,    36,
      37,    36,    36,     4,   154,   156,     4,   163,     4,    36,
     171,   161,   163,    41,    40,     4,     6,     7,     8,     9,
     171,    11,    12,    13,    14,    15,    16,     6,     7,     8,
       9,    40,    11,    12,    13,    14,    15,    16,     6,     7,
       8,     9,     5,    11,    12,    13,    14,    15,    16,    40,
      38,    41,    22,    26,    39,     4,    38,     4,     6,     7,
       8,     9,    41,    11,    12,    13,    14,    15,    16,     6,
       7,     8,     9,    41,    11,    12,    13,    14,    15,    16,
       5,    42,     4,    39,     5,    39,    32,    38,    20,     5,
       4,    39,     4,    43,    39,    17,    18,     4,    36,    21,
      29,    34,    39,    25,    26,    -1,    28,    29,    30,    31,
      17,    18,     4,    -1,    21,   161,    23,    24,    25,    26,
      -1,    28,    29,    30,    -1,    17,    18,    19,     4,    21,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    -1,
      -1,    17,    18,    19,     4,    21,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    -1,    -1,    17,    18,     4,
      -1,    21,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    -1,    17,    18,     4,    -1,    21,    -1,    -1,    24,
      25,    26,    -1,    28,    29,    30,    -1,    17,    18,    19,
       4,    21,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    -1,    -1,    17,    18,     4,    -1,    21,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    -1,    17,    18,
      -1,    -1,    21,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    16,     6,     7,     8,     9,    -1,    11,    12,
      13,    14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    20,    32,    45,    46,    59,     4,    17,    18,    19,
      21,    25,    26,    28,    29,    30,    60,    61,    62,    63,
      64,    65,    66,    68,    71,    72,    33,    34,    35,    47,
      48,    49,     0,    49,    51,    52,    59,    38,    40,    40,
      40,    36,    40,    40,    60,    36,    36,    60,    19,    61,
      36,    36,    36,    36,    36,    10,    36,    36,    33,    48,
       4,    50,     4,    52,    59,     3,     5,    40,    67,    68,
      70,    41,    67,    69,    68,    67,    67,    67,    25,    31,
      36,    67,    38,    40,    36,    37,    40,    67,     6,     7,
       8,     9,    11,    12,    13,    14,    15,    16,    39,    37,
      41,    41,    41,    41,    41,    40,    40,     5,    49,    53,
       4,    53,    41,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    38,    67,    22,    26,    67,    67,    39,
       4,    37,    41,    38,    40,    41,    67,    60,    60,    41,
      41,    38,    49,     5,    53,    42,    39,    23,    24,    27,
       5,     4,    39,    41,    32,    54,    60,    39,    38,    33,
      49,    55,    56,    20,    58,    24,     5,     4,    57,    33,
      56,    60,    43,    39,    36,    37,    19,     4,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    45,    46,    46,    47,    47,    48,
      49,    49,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      57,    57,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    63,    64,
      65,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     3,     6,     9,     6,     1,     4,     7,     4,
       2,     1,     9,     4,     2,     3,     2,     2,     1,     3,
       3,     1,     4,     4,     3,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     9,     7,     7,     6,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     4,     7,     3,     4,
       3,     1,     1,     1,     4,     4
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
#line 64 "parser.y"
                                   {
                printf("All declarations parsed.\n");
                getGSymbolTable();
              }
#line 1438 "y.tab.c"
    break;

  case 9: /* Gdecl: TYPE GidList ';'  */
#line 79 "parser.y"
                      {
        addAllSymbols((yyvsp[-1].list),(yyvsp[-2].integer));
     }
#line 1446 "y.tab.c"
    break;

  case 10: /* TYPE: INT  */
#line 85 "parser.y"
         {
     (yyval.integer) = (yyvsp[0].integer);
     }
#line 1454 "y.tab.c"
    break;

  case 11: /* TYPE: STR  */
#line 89 "parser.y"
         {
     (yyval.integer) = (yyvsp[0].integer);
     }
#line 1462 "y.tab.c"
    break;

  case 12: /* GidList: GidList ',' ID  */
#line 95 "parser.y"
                       {
          (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1470 "y.tab.c"
    break;

  case 13: /* GidList: GidList ',' ID '[' NUM ']'  */
#line 99 "parser.y"
                                   {
          (yyval.list) = addArray((yyvsp[-5].list),(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1478 "y.tab.c"
    break;

  case 14: /* GidList: GidList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 103 "parser.y"
                                               {
          (yyval.list) = addArray((yyvsp[-8].list),(yyvsp[-8].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1486 "y.tab.c"
    break;

  case 15: /* GidList: GidList ',' ID '(' ParamList ')'  */
#line 107 "parser.y"
                                         {
          (yyval.list) = addFunction((yyvsp[-5].list),(yyvsp[-3].string),(yyvsp[-1].paramlist));
        }
#line 1494 "y.tab.c"
    break;

  case 16: /* GidList: ID  */
#line 111 "parser.y"
           {
          (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1502 "y.tab.c"
    break;

  case 17: /* GidList: ID '[' NUM ']'  */
#line 115 "parser.y"
                       {
          (yyval.list) = addArray(NULL,(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1510 "y.tab.c"
    break;

  case 18: /* GidList: ID '[' NUM ']' '[' NUM ']'  */
#line 119 "parser.y"
                                   {
          (yyval.list) = addArray(NULL,(yyvsp[-6].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1518 "y.tab.c"
    break;

  case 19: /* GidList: ID '(' ParamList ')'  */
#line 123 "parser.y"
                             {
          (yyval.list) = addFunction(NULL,(yyvsp[-3].string),(yyvsp[-1].paramlist));
        }
#line 1526 "y.tab.c"
    break;

  case 23: /* ParamList: ParamList ',' TYPE ID  */
#line 139 "parser.y"
                                {
           (yyval.paramlist) = addParameter((yyvsp[-3].paramlist),(yyvsp[0].string),(yyvsp[-1].integer));
          }
#line 1534 "y.tab.c"
    break;

  case 24: /* ParamList: TYPE ID  */
#line 143 "parser.y"
                  {
           (yyval.paramlist) = addParameter(NULL,(yyvsp[0].string),(yyvsp[-1].integer));
          }
#line 1542 "y.tab.c"
    break;

  case 33: /* MainBlock: BEG SL END ';'  */
#line 200 "parser.y"
                 {
    root = (yyvsp[-2].node);
    printf("Valid Program.\n");
    Inorder((yyvsp[-2].node));
  }
#line 1552 "y.tab.c"
    break;

  case 34: /* MainBlock: BEG END ';'  */
#line 206 "parser.y"
              {
  printf("Valid program.\n");
  }
#line 1560 "y.tab.c"
    break;

  case 35: /* SL: SL S  */
#line 212 "parser.y"
         {
   (yyval.node) = createOpNode(-1,13,(yyvsp[-1].node),(yyvsp[0].node));
  }
#line 1568 "y.tab.c"
    break;

  case 36: /* SL: S  */
#line 216 "parser.y"
      {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1576 "y.tab.c"
    break;

  case 44: /* S: BREAK ';'  */
#line 236 "parser.y"
            {
    (yyval.node) = createOpNode(-1,16,NULL,NULL);
  }
#line 1584 "y.tab.c"
    break;

  case 45: /* S: CONTINUE ';'  */
#line 240 "parser.y"
               {
    (yyval.node) = createOpNode(-1,17,NULL,NULL);
  }
#line 1592 "y.tab.c"
    break;

  case 46: /* IFST: IF '(' E ')' THEN SL ELSE SL ENDIF  */
#line 246 "parser.y"
                                        {
      (yyval.node) = createIfNode((yyvsp[-6].node),(yyvsp[-3].node),(yyvsp[-1].node));
    }
#line 1600 "y.tab.c"
    break;

  case 47: /* IFST: IF '(' E ')' THEN SL ENDIF  */
#line 250 "parser.y"
                               {
      (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-1].node),NULL);
    }
#line 1608 "y.tab.c"
    break;

  case 48: /* WHILEST: WHILE '(' E ')' DO SL ENDWHILE  */
#line 256 "parser.y"
                                       {
        (yyval.node) = createWhileNode(15,(yyvsp[-4].node),(yyvsp[-1].node));
        }
#line 1616 "y.tab.c"
    break;

  case 49: /* REPEATST: REPEAT SL UNTIL '(' E ')'  */
#line 262 "parser.y"
                                   {
         (yyval.node) = createWhileNode(18,(yyvsp[-1].node),(yyvsp[-4].node));
        }
#line 1624 "y.tab.c"
    break;

  case 50: /* DOWHILEST: DO SL WHILE '(' E ')'  */
#line 268 "parser.y"
                                { 
          (yyval.node) = createWhileNode(19,(yyvsp[-1].node),(yyvsp[-4].node));
          }
#line 1632 "y.tab.c"
    break;

  case 51: /* ASSG: IDENTIFIER EQUALS E  */
#line 275 "parser.y"
                      {
  (yyval.node) = createOpNode(-1,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1640 "y.tab.c"
    break;

  case 52: /* E: E PLUS E  */
#line 281 "parser.y"
           {
  (yyval.node) = createOpNode(0,0,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1648 "y.tab.c"
    break;

  case 53: /* E: E MINUS E  */
#line 285 "parser.y"
            {
  (yyval.node) = createOpNode(0,1,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1656 "y.tab.c"
    break;

  case 54: /* E: E MUL E  */
#line 289 "parser.y"
          {
  (yyval.node) = createOpNode(0,2,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1664 "y.tab.c"
    break;

  case 55: /* E: E DIV E  */
#line 293 "parser.y"
          {
  (yyval.node) = createOpNode(0,3,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1672 "y.tab.c"
    break;

  case 56: /* E: E LT E  */
#line 297 "parser.y"
         {
  (yyval.node) = createOpNode(1,5,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1680 "y.tab.c"
    break;

  case 57: /* E: E LTE E  */
#line 301 "parser.y"
          {
  (yyval.node) = createOpNode(1,6,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1688 "y.tab.c"
    break;

  case 58: /* E: E GT E  */
#line 305 "parser.y"
         {
  (yyval.node) = createOpNode(1,7,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1696 "y.tab.c"
    break;

  case 59: /* E: E GTE E  */
#line 309 "parser.y"
          {
  (yyval.node) = createOpNode(1,8,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1704 "y.tab.c"
    break;

  case 60: /* E: E NEQ E  */
#line 313 "parser.y"
          {
  (yyval.node) = createOpNode(1,9,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1712 "y.tab.c"
    break;

  case 61: /* E: E EQ E  */
#line 317 "parser.y"
         {
  (yyval.node) = createOpNode(1,10,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1720 "y.tab.c"
    break;

  case 62: /* E: '(' E ')'  */
#line 321 "parser.y"
            {
  (yyval.node) = (yyvsp[-1].node);
  }
#line 1728 "y.tab.c"
    break;

  case 65: /* IDENTIFIER: ID  */
#line 331 "parser.y"
              { 
            (yyval.node) = createIdNode((yyvsp[0].string),NULL,NULL);
           }
#line 1736 "y.tab.c"
    break;

  case 66: /* IDENTIFIER: ID '[' E ']'  */
#line 335 "parser.y"
                        {
            (yyval.node) = createIdNode((yyvsp[-3].string),NULL,(yyvsp[-1].node));
            }
#line 1744 "y.tab.c"
    break;

  case 67: /* IDENTIFIER: ID '[' E ']' '[' E ']'  */
#line 339 "parser.y"
                                  {
            (yyval.node) = createIdNode((yyvsp[-6].string),(yyvsp[-4].node),(yyvsp[-1].node));
            }
#line 1752 "y.tab.c"
    break;

  case 68: /* IDENTIFIER: ID '(' ')'  */
#line 343 "parser.y"
                       {
            (yyval.node) = NULL;
            }
#line 1760 "y.tab.c"
    break;

  case 69: /* IDENTIFIER: ID '(' ArgList ')'  */
#line 347 "parser.y"
                               {
            (yyval.node) = NULL;
            }
#line 1768 "y.tab.c"
    break;

  case 72: /* CONSTANT: NUM  */
#line 360 "parser.y"
             {
          (yyval.node) = createNumNode(atoi((yyvsp[0].string)));
          }
#line 1776 "y.tab.c"
    break;

  case 73: /* CONSTANT: STRING  */
#line 364 "parser.y"
                {
          (yyval.node) = createStringNode((yyvsp[0].string));
          }
#line 1784 "y.tab.c"
    break;

  case 74: /* INPUT: READ '(' IDENTIFIER ')'  */
#line 371 "parser.y"
                               {
       (yyval.node) = createOpNode(-1,11,(yyvsp[-1].node),NULL);
      }
#line 1792 "y.tab.c"
    break;

  case 75: /* OUTPUT: WRITE '(' E ')'  */
#line 377 "parser.y"
                       {
        (yyval.node) = createOpNode(-1,12,(yyvsp[-1].node),NULL);
      }
#line 1800 "y.tab.c"
    break;


#line 1804 "y.tab.c"

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

#line 385 "parser.y"










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

