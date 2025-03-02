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

void initxsm(FILE* f);
void endxsm(FILE* f);



#line 107 "y.tab.c"

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
    READ = 283,                    /* READ  */
    WRITE = 284,                   /* WRITE  */
    IF = 285,                      /* IF  */
    THEN = 286,                    /* THEN  */
    ELSE = 287,                    /* ELSE  */
    ENDIF = 288,                   /* ENDIF  */
    WHILE = 289,                   /* WHILE  */
    DO = 290,                      /* DO  */
    ENDWHILE = 291,                /* ENDWHILE  */
    BREAK = 292,                   /* BREAK  */
    CONTINUE = 293,                /* CONTINUE  */
    REPEAT = 294,                  /* REPEAT  */
    UNTIL = 295,                   /* UNTIL  */
    RETURN = 296,                  /* RETURN  */
    INT = 297,                     /* INT  */
    STR = 298,                     /* STR  */
    INIT = 299,                    /* INIT  */
    ALLOC = 300,                   /* ALLOC  */
    FREE = 301,                    /* FREE  */
    NULLVAL = 302                  /* NULLVAL  */
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
#define READ 283
#define WRITE 284
#define IF 285
#define THEN 286
#define ELSE 287
#define ENDIF 288
#define WHILE 289
#define DO 290
#define ENDWHILE 291
#define BREAK 292
#define CONTINUE 293
#define REPEAT 294
#define UNTIL 295
#define RETURN 296
#define INT 297
#define STR 298
#define INIT 299
#define ALLOC 300
#define FREE 301
#define NULLVAL 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "parser.y"

  struct TreeNode* node;
  char* string;
  int integer;
  struct list* list;
  struct paramlist* paramlist;
  struct Lsymbol* Lsymbol;
  struct typetable* typetable;
  struct fieldlist* fieldlist;



#line 267 "y.tab.c"

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
  YYSYMBOL_READ = 28,                      /* READ  */
  YYSYMBOL_WRITE = 29,                     /* WRITE  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_THEN = 31,                      /* THEN  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_ENDIF = 33,                     /* ENDIF  */
  YYSYMBOL_WHILE = 34,                     /* WHILE  */
  YYSYMBOL_DO = 35,                        /* DO  */
  YYSYMBOL_ENDWHILE = 36,                  /* ENDWHILE  */
  YYSYMBOL_BREAK = 37,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 38,                  /* CONTINUE  */
  YYSYMBOL_REPEAT = 39,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 40,                     /* UNTIL  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_INT = 42,                       /* INT  */
  YYSYMBOL_STR = 43,                       /* STR  */
  YYSYMBOL_INIT = 44,                      /* INIT  */
  YYSYMBOL_ALLOC = 45,                     /* ALLOC  */
  YYSYMBOL_FREE = 46,                      /* FREE  */
  YYSYMBOL_NULLVAL = 47,                   /* NULLVAL  */
  YYSYMBOL_48_ = 48,                       /* '{'  */
  YYSYMBOL_49_ = 49,                       /* '}'  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '['  */
  YYSYMBOL_53_ = 53,                       /* ']'  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_PROGRAM = 58,                   /* PROGRAM  */
  YYSYMBOL_TypeDefBlock = 59,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 60,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 61,                   /* TypeDef  */
  YYSYMBOL_FieldDeclList = 62,             /* FieldDeclList  */
  YYSYMBOL_GdeclBlock = 63,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 64,                 /* GdeclList  */
  YYSYMBOL_Gdecl = 65,                     /* Gdecl  */
  YYSYMBOL_TYPE = 66,                      /* TYPE  */
  YYSYMBOL_GidList = 67,                   /* GidList  */
  YYSYMBOL_FdefBlock = 68,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 69,                      /* Fdef  */
  YYSYMBOL_ParamList = 70,                 /* ParamList  */
  YYSYMBOL_LdeclBlock = 71,                /* LdeclBlock  */
  YYSYMBOL_LdeclList = 72,                 /* LdeclList  */
  YYSYMBOL_Ldecl = 73,                     /* Ldecl  */
  YYSYMBOL_LidList = 74,                   /* LidList  */
  YYSYMBOL_MainBlock = 75,                 /* MainBlock  */
  YYSYMBOL_Body = 76,                      /* Body  */
  YYSYMBOL_SL = 77,                        /* SL  */
  YYSYMBOL_S = 78,                         /* S  */
  YYSYMBOL_IFST = 79,                      /* IFST  */
  YYSYMBOL_WHILEST = 80,                   /* WHILEST  */
  YYSYMBOL_REPEATST = 81,                  /* REPEATST  */
  YYSYMBOL_DOWHILEST = 82,                 /* DOWHILEST  */
  YYSYMBOL_ASSG = 83,                      /* ASSG  */
  YYSYMBOL_E = 84,                         /* E  */
  YYSYMBOL_IDENTIFIER = 85,                /* IDENTIFIER  */
  YYSYMBOL_FIELD = 86,                     /* FIELD  */
  YYSYMBOL_ArgList = 87,                   /* ArgList  */
  YYSYMBOL_CONSTANT = 88,                  /* CONSTANT  */
  YYSYMBOL_INPUT = 89,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 90,                    /* OUTPUT  */
  YYSYMBOL_INITIALIZE = 91,                /* INITIALIZE  */
  YYSYMBOL_ALLOCATE = 92                   /* ALLOCATE  */
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
#define YYLAST   485

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      54,    55,     2,     2,    51,     2,    56,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    80,    82,    85,    90,    97,    99,   103,
     110,   114,   120,   125,   129,   131,   135,   141,   145,   149,
     155,   159,   163,   167,   171,   175,   179,   183,   190,   192,
     196,   221,   226,   231,   238,   241,   245,   247,   251,   256,
     260,   268,   288,   295,   301,   305,   311,   313,   315,   317,
     319,   321,   323,   325,   329,   333,   337,   343,   347,   353,
     359,   365,   372,   376,   380,   384,   391,   395,   399,   403,
     407,   411,   415,   419,   423,   427,   431,   435,   437,   439,
     443,   447,   451,   455,   459,   465,   469,   476,   480,   487,
     491,   495,   502,   508,   514,   520
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
  "ENDTYPE", "BEGINCLASS", "ENDCLASS", "NEW", "DELETE", "READ", "WRITE",
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "BREAK",
  "CONTINUE", "REPEAT", "UNTIL", "RETURN", "INT", "STR", "INIT", "ALLOC",
  "FREE", "NULLVAL", "'{'", "'}'", "';'", "','", "'['", "']'", "'('",
  "')'", "'.'", "$accept", "PROGRAM", "TypeDefBlock", "TypeDefList",
  "TypeDef", "FieldDeclList", "GdeclBlock", "GdeclList", "Gdecl", "TYPE",
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

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    32,   107,   -10,    -5,    93,   -94,   -94,   279,    40,
       4,   -94,    29,   -94,   -94,   -94,   -94,   -94,   -94,   413,
     -94,   104,    69,    40,   122,     4,   -94,   -94,    60,   130,
     -94,   -94,    47,   -38,    80,    99,   -94,   -94,   -94,   191,
     146,   192,    29,   -94,   194,   155,    29,   160,   -94,   156,
     207,   -25,    75,   195,   -13,   -94,   161,   -94,    29,   -94,
     211,    29,   421,   199,   164,   213,   215,   167,    49,   -94,
     217,   432,   -94,   297,   173,   195,   170,   -94,   174,   -94,
     -94,    43,   -94,   -94,    63,   175,   176,   177,   178,   221,
     392,   183,   226,   392,    64,   223,   316,   -94,   228,   230,
     231,   235,   236,   212,   -11,   237,   238,   -94,   199,   -94,
     222,   -94,   225,    64,    11,   275,   -94,   285,    64,    64,
      64,   411,   -94,   -94,   335,   -94,   -94,   -94,    64,   259,
     -94,   234,   -94,   285,   241,   -94,   -94,   -94,   -94,   -94,
     -94,    51,    64,   289,   -94,   -94,   245,   242,   -94,   239,
     -94,   470,    59,   -94,    96,   243,    67,   149,   159,   250,
     251,   169,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,   -94,   244,   -94,   264,   269,   470,   -94,   -94,
     470,   -94,   -94,   -94,   276,    64,   -94,   -94,   -94,   265,
     262,    64,    64,   -94,   128,   128,   128,   128,   193,   193,
     116,   116,   -94,   -94,   253,   274,   282,    64,   470,   392,
     392,   179,   229,   -94,   -94,   -94,   249,   278,   354,   262,
     -94,   -94,   392,   -94,   -94,   373,   -94
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
      40,     0,    34,    36,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,    26,
       0,    38,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,    53,    54,     0,    90,    89,    91,     0,     0,
      78,    79,    77,     0,     0,    44,    49,    50,    51,    52,
      46,     0,     0,     0,    47,    48,     0,     0,    39,     0,
      83,    88,     0,    86,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    42,     0,     0,    62,    64,    65,
      63,    85,    30,    22,    81,     0,    84,    92,    93,     0,
       0,     0,     0,    76,    70,    71,    72,    73,    75,    74,
      66,    67,    68,    69,     0,     0,     0,     0,    87,     0,
       0,     0,     0,    56,    94,    95,     0,     0,     0,    61,
      60,    82,     0,    58,    59,     0,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   -94,   -94,   325,   -94,   -94,   -94,   321,    -1,
     -94,   -94,   317,   -40,   266,   -94,   277,   -94,    27,   248,
     -89,   -93,   -94,   -94,   -94,   -94,   -94,   -79,   -73,   -71,
     -94,   -94,   -94,   -94,   -94,   -94
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    28,    10,    19,    20,    50,
      33,    25,    26,    51,    63,    71,    72,    81,    11,    74,
      96,    97,    98,    99,   100,   101,   102,   129,   130,   131,
     152,   132,   105,   106,   178,   179
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     103,   121,   104,   135,   124,   142,    54,    21,    15,    24,
       8,    29,    43,    44,   125,    84,   126,   103,    21,   104,
     103,    68,   104,   103,    24,   104,    58,    39,   135,     1,
      59,   135,     9,    15,   149,   151,     4,    27,    58,   156,
     157,   158,    64,    12,   155,   143,    23,    18,   103,   161,
     104,   103,    37,   104,   125,    84,   126,    66,   127,    22,
     173,    70,   177,   180,    15,   128,   150,   125,    84,   126,
      70,    17,    18,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   111,   112,   175,   176,     4,   127,    41,
      58,    42,    17,    18,    79,   128,   208,     7,    32,    38,
     185,   127,   211,   212,   186,   113,    13,   114,   128,   115,
     217,   218,   188,    34,   135,   135,    35,    60,   216,    61,
     170,   171,   135,   225,    40,    45,   103,   103,   104,   104,
     168,   169,   170,   171,   103,   103,   104,   104,   113,   103,
     114,   104,   103,    46,   104,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    47,    48,    49,    52,   162,
     163,   164,   165,    53,   189,   168,   169,   170,   171,    56,
      55,    57,    75,    65,   190,    62,    67,    73,    76,    77,
      78,    80,   107,   109,   193,   116,   110,   147,   141,   148,
     117,   118,   119,   122,   219,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   120,   123,   133,   136,   153,
     137,   138,    84,    15,   220,   139,   140,   144,   145,   154,
     143,   174,   184,   181,   182,   183,   209,   210,   187,   204,
      16,    84,   221,   213,   191,   192,    86,    87,    88,   172,
     222,   223,    89,    90,    85,    91,    92,    93,   205,    94,
      84,    17,    18,   206,    95,    86,    87,    88,   207,   214,
      14,    89,    90,   134,    91,    92,    93,   215,    94,    84,
      31,   108,    36,    95,    86,    87,    88,     0,    83,     0,
      89,    90,     0,    91,    92,    93,   146,    94,    84,     0,
       0,     0,    95,    86,    87,    88,     0,     0,     0,    89,
      90,     0,    91,    92,    93,   160,    94,    84,     0,     0,
       0,    95,    86,    87,    88,     0,     0,     0,    89,    90,
     224,    91,    92,    93,     0,    94,    84,     0,     0,     0,
      95,    86,    87,    88,     0,     0,   226,    89,    90,     0,
      91,    92,    93,     0,    94,    84,     0,    15,     0,    95,
      86,    87,    88,     0,     0,    15,    89,    90,     0,    91,
      92,    93,     0,    94,    30,     0,    15,     0,    95,    86,
      87,    88,    69,     0,     0,   159,    90,     0,    91,    92,
      93,     0,    94,    82,     0,    17,    18,    95,     0,     0,
       0,     0,     0,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171
};

static const yytype_int16 yycheck[] =
{
      73,    90,    73,    96,    93,    16,    46,     8,     4,    10,
      20,    12,    50,    51,     3,     4,     5,    90,    19,    90,
      93,    61,    93,    96,    25,    96,    51,    28,   121,    22,
      55,   124,    42,     4,   113,   114,     4,    10,    51,   118,
     119,   120,    55,    48,   117,    56,    42,    43,   121,   128,
     121,   124,    25,   124,     3,     4,     5,    58,    47,    19,
     133,    62,   141,   142,     4,    54,    55,     3,     4,     5,
      71,    42,    43,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    50,    51,    44,    45,     4,    47,    52,
      51,    54,    42,    43,    55,    54,   185,     0,     4,    49,
      51,    47,   191,   192,    55,    52,    23,    54,    54,    56,
     209,   210,    55,    54,   217,   218,     4,    52,   207,    54,
      14,    15,   225,   222,     4,    55,   209,   210,   209,   210,
      12,    13,    14,    15,   217,   218,   217,   218,    52,   222,
      54,   222,   225,    54,   225,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     4,    50,     5,     4,     6,
       7,     8,     9,    48,    55,    12,    13,    14,    15,    53,
      50,     4,    48,    52,    55,    20,     5,    18,     5,     4,
      53,     4,    49,    53,    55,    50,    52,     5,    16,     4,
      54,    54,    54,    50,    55,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    54,    50,    54,    50,     4,
      50,    50,     4,     4,    55,    50,    50,    50,    50,     4,
      56,    50,    53,     4,    49,    53,    31,    35,    55,    55,
      21,     4,    53,    50,    54,    54,    28,    29,    30,    50,
      32,    33,    34,    35,    17,    37,    38,    39,    54,    41,
       4,    42,    43,    54,    46,    28,    29,    30,    52,    55,
       5,    34,    35,    17,    37,    38,    39,    55,    41,     4,
      19,    75,    25,    46,    28,    29,    30,    -1,    71,    -1,
      34,    35,    -1,    37,    38,    39,   108,    41,     4,    -1,
      -1,    -1,    46,    28,    29,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,     4,    -1,    -1,
      -1,    46,    28,    29,    30,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    -1,    41,     4,    -1,    -1,    -1,
      46,    28,    29,    30,    -1,    -1,    33,    34,    35,    -1,
      37,    38,    39,    -1,    41,     4,    -1,     4,    -1,    46,
      28,    29,    30,    -1,    -1,     4,    34,    35,    -1,    37,
      38,    39,    -1,    41,    21,    -1,     4,    -1,    46,    28,
      29,    30,    21,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    -1,    41,    21,    -1,    42,    43,    46,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    58,    59,     4,    60,    61,     0,    20,    42,
      63,    75,    48,    23,    61,     4,    21,    42,    43,    64,
      65,    66,    19,    42,    66,    68,    69,    75,    62,    66,
      21,    65,     4,    67,    54,     4,    69,    75,    49,    66,
       4,    52,    54,    50,    51,    55,    54,     4,    50,     5,
      66,    70,     4,    48,    70,    50,    53,     4,    51,    55,
      52,    54,    20,    71,    55,    52,    66,     5,    70,    21,
      66,    72,    73,    18,    76,    48,     5,     4,    53,    55,
       4,    74,    21,    73,     4,    17,    28,    29,    30,    34,
      35,    37,    38,    39,    41,    46,    77,    78,    79,    80,
      81,    82,    83,    85,    86,    89,    90,    49,    71,    53,
      52,    50,    51,    52,    54,    56,    50,    54,    54,    54,
      54,    77,    50,    50,    77,     3,     5,    47,    54,    84,
      85,    86,    88,    54,    17,    78,    50,    50,    50,    50,
      50,    16,    16,    56,    50,    50,    76,     5,     4,    84,
      55,    84,    87,     4,     4,    85,    84,    84,    84,    34,
      40,    84,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    50,    85,    50,    44,    45,    84,    91,    92,
      84,     4,    49,    53,    53,    51,    55,    55,    55,    55,
      55,    54,    54,    55,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    55,    54,    54,    52,    84,    31,
      35,    84,    84,    50,    55,    55,    84,    77,    77,    55,
      55,    53,    32,    33,    36,    77,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    59,    59,    60,    60,    61,
      62,    62,    63,    63,    64,    64,    65,    66,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    70,    70,    70,    71,    71,    72,    72,    73,    74,
      74,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    80,
      81,    82,    83,    83,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    85,    85,    85,    85,    86,    86,    87,    87,    88,
      88,    88,    89,    90,    91,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     0,     2,     1,     4,
       4,     3,     3,     2,     2,     1,     3,     1,     1,     1,
       3,     6,     9,     6,     1,     4,     7,     4,     2,     1,
       9,     4,     2,     0,     3,     2,     2,     1,     3,     3,
       1,     8,     4,     3,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     5,     9,     7,     7,
       6,     6,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     4,     7,     3,     4,     3,     3,     3,     1,     1,
       1,     1,     4,     4,     3,     3
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
#line 85 "parser.y"
                                          {
             printf("All Type definitions parsed.\n");
             printTT();
             }
#line 1538 "y.tab.c"
    break;

  case 6: /* TypeDefBlock: %empty  */
#line 90 "parser.y"
             {
             printf("No Type definitions present\n");
             printTT();
             }
#line 1547 "y.tab.c"
    break;

  case 9: /* TypeDef: ID '{' FieldDeclList '}'  */
#line 103 "parser.y"
                                 {
         addTTNode((yyvsp[-3].string),getFLSize((yyvsp[-1].fieldlist)),(yyvsp[-1].fieldlist));
         addTypes((yyvsp[-1].fieldlist));
        }
#line 1556 "y.tab.c"
    break;

  case 10: /* FieldDeclList: FieldDeclList TYPE ID ';'  */
#line 110 "parser.y"
                                        {
              (yyval.fieldlist) = addFLNode((yyvsp[-3].fieldlist),(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1564 "y.tab.c"
    break;

  case 11: /* FieldDeclList: TYPE ID ';'  */
#line 114 "parser.y"
                          {
              (yyval.fieldlist) = addFLNode(NULL,(yyvsp[-1].string),(yyvsp[-2].string));
              }
#line 1572 "y.tab.c"
    break;

  case 12: /* GdeclBlock: DECL GdeclList ENDDECL  */
#line 120 "parser.y"
                                   {
                printf("All Global Declarations parsed.\n");
                getGSymbolTable();
              }
#line 1581 "y.tab.c"
    break;

  case 16: /* Gdecl: TYPE GidList ';'  */
#line 135 "parser.y"
                      {
          addAllGSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)));
     }
#line 1589 "y.tab.c"
    break;

  case 17: /* TYPE: INT  */
#line 141 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1597 "y.tab.c"
    break;

  case 18: /* TYPE: STR  */
#line 145 "parser.y"
         {
     (yyval.string) = (yyvsp[0].string);
     }
#line 1605 "y.tab.c"
    break;

  case 19: /* TYPE: ID  */
#line 149 "parser.y"
        {
     (yyval.string) = (yyvsp[0].string);  
     }
#line 1613 "y.tab.c"
    break;

  case 20: /* GidList: GidList ',' ID  */
#line 155 "parser.y"
                       {
          (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1621 "y.tab.c"
    break;

  case 21: /* GidList: GidList ',' ID '[' NUM ']'  */
#line 159 "parser.y"
                                   {
          (yyval.list) = addArray((yyvsp[-5].list),(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1629 "y.tab.c"
    break;

  case 22: /* GidList: GidList ',' ID '[' NUM ']' '[' NUM ']'  */
#line 163 "parser.y"
                                               {
          (yyval.list) = addArray((yyvsp[-8].list),(yyvsp[-8].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1637 "y.tab.c"
    break;

  case 23: /* GidList: GidList ',' ID '(' ParamList ')'  */
#line 167 "parser.y"
                                         {
          (yyval.list) = addFunction((yyvsp[-5].list),(yyvsp[-3].string),(yyvsp[-1].paramlist));
        }
#line 1645 "y.tab.c"
    break;

  case 24: /* GidList: ID  */
#line 171 "parser.y"
           {
          (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1653 "y.tab.c"
    break;

  case 25: /* GidList: ID '[' NUM ']'  */
#line 175 "parser.y"
                       {
          (yyval.list) = addArray(NULL,(yyvsp[-3].string),1,atoi((yyvsp[-1].string)));
        }
#line 1661 "y.tab.c"
    break;

  case 26: /* GidList: ID '[' NUM ']' '[' NUM ']'  */
#line 179 "parser.y"
                                   {
          (yyval.list) = addArray(NULL,(yyvsp[-6].string),atoi((yyvsp[-4].string)),atoi((yyvsp[-1].string)));
        }
#line 1669 "y.tab.c"
    break;

  case 27: /* GidList: ID '(' ParamList ')'  */
#line 183 "parser.y"
                             { 
          (yyval.list) = addFunction(NULL,(yyvsp[-3].string),(yyvsp[-1].paramlist));
          deleteLSymbolTable();
        }
#line 1678 "y.tab.c"
    break;

  case 30: /* Fdef: TYPE ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 196 "parser.y"
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
#line 1704 "y.tab.c"
    break;

  case 31: /* ParamList: ParamList ',' TYPE ID  */
#line 221 "parser.y"
                                {
           (yyval.paramlist) = addParameter((yyvsp[-3].paramlist),(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1713 "y.tab.c"
    break;

  case 32: /* ParamList: TYPE ID  */
#line 226 "parser.y"
                  {
           (yyval.paramlist) = addParameter(NULL,(yyvsp[0].string),lookTTUp((yyvsp[-1].string)));
           addLastParamToLSymbolTable((yyval.paramlist));
          }
#line 1722 "y.tab.c"
    break;

  case 33: /* ParamList: %empty  */
#line 231 "parser.y"
           {
           (yyval.paramlist) = NULL;
          }
#line 1730 "y.tab.c"
    break;

  case 34: /* LdeclBlock: DECL LdeclList ENDDECL  */
#line 238 "parser.y"
                                  {
           }
#line 1737 "y.tab.c"
    break;

  case 38: /* Ldecl: TYPE LidList ';'  */
#line 251 "parser.y"
                       {
         addAllLSymbols((yyvsp[-1].list),lookTTUp((yyvsp[-2].string)));
      }
#line 1745 "y.tab.c"
    break;

  case 39: /* LidList: LidList ',' ID  */
#line 256 "parser.y"
                       {
        (yyval.list) = addVariable((yyvsp[-2].list),(yyvsp[0].string));
        }
#line 1753 "y.tab.c"
    break;

  case 40: /* LidList: ID  */
#line 260 "parser.y"
           {
        (yyval.list) = addVariable(NULL,(yyvsp[0].string));
        }
#line 1761 "y.tab.c"
    break;

  case 41: /* MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 268 "parser.y"
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
#line 1783 "y.tab.c"
    break;

  case 42: /* Body: BEG SL END ';'  */
#line 288 "parser.y"
                 {
    (yyval.node) = (yyvsp[-2].node);
    root = (yyvsp[-2].node);
    printf("Valid Program.\n");
    Inorder((yyvsp[-2].node));
  }
#line 1794 "y.tab.c"
    break;

  case 43: /* Body: BEG END ';'  */
#line 295 "parser.y"
              {
  printf("Valid program.\n");
  }
#line 1802 "y.tab.c"
    break;

  case 44: /* SL: SL S  */
#line 301 "parser.y"
         {
   (yyval.node) = createOpNode(NULL,13,(yyvsp[-1].node),(yyvsp[0].node));
  }
#line 1810 "y.tab.c"
    break;

  case 45: /* SL: S  */
#line 305 "parser.y"
      {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1818 "y.tab.c"
    break;

  case 53: /* S: BREAK ';'  */
#line 325 "parser.y"
            {
    (yyval.node) = createOpNode(NULL,16,NULL,NULL);
  }
#line 1826 "y.tab.c"
    break;

  case 54: /* S: CONTINUE ';'  */
#line 329 "parser.y"
               {
    (yyval.node) = createOpNode(NULL,17,NULL,NULL);
  }
#line 1834 "y.tab.c"
    break;

  case 55: /* S: RETURN E ';'  */
#line 333 "parser.y"
               {
    (yyval.node) = createReturnNode((yyvsp[-1].node));
  }
#line 1842 "y.tab.c"
    break;

  case 56: /* S: FREE '(' IDENTIFIER ')' ';'  */
#line 337 "parser.y"
                              {
    (yyval.node) = createFreeNode((yyvsp[-2].node));
  }
#line 1850 "y.tab.c"
    break;

  case 57: /* IFST: IF '(' E ')' THEN SL ELSE SL ENDIF  */
#line 343 "parser.y"
                                        {
      (yyval.node) = createIfNode((yyvsp[-6].node),(yyvsp[-3].node),(yyvsp[-1].node));
    }
#line 1858 "y.tab.c"
    break;

  case 58: /* IFST: IF '(' E ')' THEN SL ENDIF  */
#line 347 "parser.y"
                               {
      (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-1].node),NULL);
    }
#line 1866 "y.tab.c"
    break;

  case 59: /* WHILEST: WHILE '(' E ')' DO SL ENDWHILE  */
#line 353 "parser.y"
                                       {
        (yyval.node) = createWhileNode(15,(yyvsp[-4].node),(yyvsp[-1].node));
        }
#line 1874 "y.tab.c"
    break;

  case 60: /* REPEATST: REPEAT SL UNTIL '(' E ')'  */
#line 359 "parser.y"
                                   {
         (yyval.node) = createWhileNode(18,(yyvsp[-1].node),(yyvsp[-4].node));
        }
#line 1882 "y.tab.c"
    break;

  case 61: /* DOWHILEST: DO SL WHILE '(' E ')'  */
#line 365 "parser.y"
                                { 
          (yyval.node) = createWhileNode(19,(yyvsp[-1].node),(yyvsp[-4].node));
          }
#line 1890 "y.tab.c"
    break;

  case 62: /* ASSG: IDENTIFIER EQUALS E  */
#line 372 "parser.y"
                      {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1898 "y.tab.c"
    break;

  case 63: /* ASSG: FIELD EQUALS E  */
#line 376 "parser.y"
                 {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1906 "y.tab.c"
    break;

  case 64: /* ASSG: IDENTIFIER EQUALS INITIALIZE  */
#line 380 "parser.y"
                               {
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1914 "y.tab.c"
    break;

  case 65: /* ASSG: IDENTIFIER EQUALS ALLOCATE  */
#line 384 "parser.y"
                             {
  (yyvsp[0].node)->type = (yyvsp[-2].node)->type;
  (yyval.node) = createOpNode(NULL,4,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1923 "y.tab.c"
    break;

  case 66: /* E: E PLUS E  */
#line 391 "parser.y"
           {
  (yyval.node) = createOpNode(lookTTUp("int"),0,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1931 "y.tab.c"
    break;

  case 67: /* E: E MINUS E  */
#line 395 "parser.y"
            {
  (yyval.node) = createOpNode(lookTTUp("int"),1,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1939 "y.tab.c"
    break;

  case 68: /* E: E MUL E  */
#line 399 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),2,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1947 "y.tab.c"
    break;

  case 69: /* E: E DIV E  */
#line 403 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("int"),3,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1955 "y.tab.c"
    break;

  case 70: /* E: E LT E  */
#line 407 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),5,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1963 "y.tab.c"
    break;

  case 71: /* E: E LTE E  */
#line 411 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),6,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1971 "y.tab.c"
    break;

  case 72: /* E: E GT E  */
#line 415 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),7,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1979 "y.tab.c"
    break;

  case 73: /* E: E GTE E  */
#line 419 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),8,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1987 "y.tab.c"
    break;

  case 74: /* E: E NEQ E  */
#line 423 "parser.y"
          {
  (yyval.node) = createOpNode(lookTTUp("bool"),9,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 1995 "y.tab.c"
    break;

  case 75: /* E: E EQ E  */
#line 427 "parser.y"
         {
  (yyval.node) = createOpNode(lookTTUp("bool"),10,(yyvsp[-2].node),(yyvsp[0].node));
  }
#line 2003 "y.tab.c"
    break;

  case 76: /* E: '(' E ')'  */
#line 431 "parser.y"
            {
  (yyval.node) = (yyvsp[-1].node);
  }
#line 2011 "y.tab.c"
    break;

  case 80: /* IDENTIFIER: ID  */
#line 443 "parser.y"
              { 
            (yyval.node) = createIdNode((yyvsp[0].string),NULL,NULL);
           }
#line 2019 "y.tab.c"
    break;

  case 81: /* IDENTIFIER: ID '[' E ']'  */
#line 447 "parser.y"
                        {
            (yyval.node) = createIdNode((yyvsp[-3].string),NULL,(yyvsp[-1].node));
            }
#line 2027 "y.tab.c"
    break;

  case 82: /* IDENTIFIER: ID '[' E ']' '[' E ']'  */
#line 451 "parser.y"
                                  {
            (yyval.node) = createIdNode((yyvsp[-6].string),(yyvsp[-4].node),(yyvsp[-1].node));
            }
#line 2035 "y.tab.c"
    break;

  case 83: /* IDENTIFIER: ID '(' ')'  */
#line 455 "parser.y"
                       {
            (yyval.node) = createFunctionNode((yyvsp[-2].string),NULL);
            }
#line 2043 "y.tab.c"
    break;

  case 84: /* IDENTIFIER: ID '(' ArgList ')'  */
#line 459 "parser.y"
                               { 
            (yyval.node) = createFunctionNode((yyvsp[-3].string),(yyvsp[-1].node));
            }
#line 2051 "y.tab.c"
    break;

  case 85: /* FIELD: FIELD '.' ID  */
#line 465 "parser.y"
                   {
      (yyval.node) = addFieldToEnd((yyvsp[-2].node),(yyvsp[0].string));
      }
#line 2059 "y.tab.c"
    break;

  case 86: /* FIELD: ID '.' ID  */
#line 469 "parser.y"
                {
      (yyval.node) = createIdNode((yyvsp[-2].string),NULL,NULL);
      (yyval.node) = addFieldToEnd((yyval.node),(yyvsp[0].string));
      }
#line 2068 "y.tab.c"
    break;

  case 87: /* ArgList: ArgList ',' E  */
#line 476 "parser.y"
                       {
        (yyval.node) = addArgToList((yyvsp[-2].node),(yyvsp[0].node));
        }
#line 2076 "y.tab.c"
    break;

  case 88: /* ArgList: E  */
#line 480 "parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
        }
#line 2084 "y.tab.c"
    break;

  case 89: /* CONSTANT: NUM  */
#line 487 "parser.y"
             {
          (yyval.node) = createNumNode(atoi((yyvsp[0].string)));
          }
#line 2092 "y.tab.c"
    break;

  case 90: /* CONSTANT: STRING  */
#line 491 "parser.y"
                {
          (yyval.node) = createStringNode((yyvsp[0].string));
          }
#line 2100 "y.tab.c"
    break;

  case 91: /* CONSTANT: NULLVAL  */
#line 495 "parser.y"
                 {
          (yyval.node) = createNullNode();
          }
#line 2108 "y.tab.c"
    break;

  case 92: /* INPUT: READ '(' IDENTIFIER ')'  */
#line 502 "parser.y"
                               {
       (yyval.node) = createOpNode(NULL,11,(yyvsp[-1].node),NULL);
      }
#line 2116 "y.tab.c"
    break;

  case 93: /* OUTPUT: WRITE '(' E ')'  */
#line 508 "parser.y"
                       {
        (yyval.node) = createOpNode(NULL,12,(yyvsp[-1].node),NULL);
      }
#line 2124 "y.tab.c"
    break;

  case 94: /* INITIALIZE: INIT '(' ')'  */
#line 514 "parser.y"
                        {
           (yyval.node) = createOpNode(lookTTUp("int"),21,NULL,NULL);
           }
#line 2132 "y.tab.c"
    break;

  case 95: /* ALLOCATE: ALLOC '(' ')'  */
#line 520 "parser.y"
                       {
         (yyval.node) = createOpNode(lookTTUp("int"),22,NULL,NULL);
         }
#line 2140 "y.tab.c"
    break;


#line 2144 "y.tab.c"

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

#line 525 "parser.y"



int main(int argc, char* argv[]){

  //SOME INITIAL STUFF
  createPrimitive();
  addGSymbol("main",lookTTUp("int"),1,1,NULL,1);

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
