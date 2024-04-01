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

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <bitset>
#include <array>
#include <deque>
#include <list>
#include <functional>
#include <iterator>
#include <iomanip>
#include <memory>
#include <numeric>
#include <stdexcept>
#include <utility>
#include <forward_list>
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYDEBUG 1
#define YYDEB 0
using namespace std;
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern int yylex();
void yyerror(const char*);
int yybye =0;
void diff_data(int x)
{
  cout<<"Datatype mismatch in line no "<< x<<endl;
}
void check_type(string s1,string s2, int x)
{
    if(s1 != s2)
    {
      diff_data(x);
      exit(1);
    }
}
Node *root = create_node("File_input");
SYMTAB* tab=new SYMTAB();
SYMTAB* gt=tab;
int curr_scope=tab->SYMSCOPE;
std::string* target_program;

#line 129 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NAME = 3,                       /* NAME  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_INDENT = 5,                     /* INDENT  */
  YYSYMBOL_DEDENT = 6,                     /* DEDENT  */
  YYSYMBOL_ENDMARKER = 7,                  /* ENDMARKER  */
  YYSYMBOL_NEWLINE = 8,                    /* NEWLINE  */
  YYSYMBOL_FALSE_TOKEN = 9,                /* FALSE_TOKEN  */
  YYSYMBOL_AWAIT = 10,                     /* AWAIT  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_IMPORT = 12,                    /* IMPORT  */
  YYSYMBOL_PASS = 13,                      /* PASS  */
  YYSYMBOL_NONE = 14,                      /* NONE  */
  YYSYMBOL_BREAK = 15,                     /* BREAK  */
  YYSYMBOL_EXCEPT = 16,                    /* EXCEPT  */
  YYSYMBOL_IN = 17,                        /* IN  */
  YYSYMBOL_RAISE = 18,                     /* RAISE  */
  YYSYMBOL_TRUE_TOKEN = 19,                /* TRUE_TOKEN  */
  YYSYMBOL_CLASS = 20,                     /* CLASS  */
  YYSYMBOL_FINALLY = 21,                   /* FINALLY  */
  YYSYMBOL_IS = 22,                        /* IS  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_CONTINUE = 25,                  /* CONTINUE  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_LAMBDA = 27,                    /* LAMBDA  */
  YYSYMBOL_TRY = 28,                       /* TRY  */
  YYSYMBOL_AS = 29,                        /* AS  */
  YYSYMBOL_DEF = 30,                       /* DEF  */
  YYSYMBOL_FROM = 31,                      /* FROM  */
  YYSYMBOL_NONLOCAL = 32,                  /* NONLOCAL  */
  YYSYMBOL_WHILE = 33,                     /* WHILE  */
  YYSYMBOL_ASSERT = 34,                    /* ASSERT  */
  YYSYMBOL_DEL = 35,                       /* DEL  */
  YYSYMBOL_GLOBAL = 36,                    /* GLOBAL  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_WITH = 38,                      /* WITH  */
  YYSYMBOL_ASYNC = 39,                     /* ASYNC  */
  YYSYMBOL_ELIF = 40,                      /* ELIF  */
  YYSYMBOL_IF = 41,                        /* IF  */
  YYSYMBOL_OR = 42,                        /* OR  */
  YYSYMBOL_YIELD = 43,                     /* YIELD  */
  YYSYMBOL_NUMBER = 44,                    /* NUMBER  */
  YYSYMBOL_STRING = 45,                    /* STRING  */
  YYSYMBOL_PLUS = 46,                      /* PLUS  */
  YYSYMBOL_MINUS = 47,                     /* MINUS  */
  YYSYMBOL_TIMES = 48,                     /* TIMES  */
  YYSYMBOL_POWER = 49,                     /* POWER  */
  YYSYMBOL_DIVIDEDBY = 50,                 /* DIVIDEDBY  */
  YYSYMBOL_FLOORDIV = 51,                  /* FLOORDIV  */
  YYSYMBOL_MODULO = 52,                    /* MODULO  */
  YYSYMBOL_AT = 53,                        /* AT  */
  YYSYMBOL_SHIFT_LEFT = 54,                /* SHIFT_LEFT  */
  YYSYMBOL_SHIFT_RIGHT = 55,               /* SHIFT_RIGHT  */
  YYSYMBOL_BITWISE_AND = 56,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 57,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 58,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_NOT = 59,               /* BITWISE_NOT  */
  YYSYMBOL_LESS_THAN = 60,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 61,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN_OR_EQUAL = 62,        /* LESS_THAN_OR_EQUAL  */
  YYSYMBOL_GREATER_THAN_OR_EQUAL = 63,     /* GREATER_THAN_OR_EQUAL  */
  YYSYMBOL_EQUAL = 64,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 65,                 /* NOT_EQUAL  */
  YYSYMBOL_LPAREN = 66,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 67,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 68,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 69,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 70,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 71,                    /* RBRACE  */
  YYSYMBOL_COMMA = 72,                     /* COMMA  */
  YYSYMBOL_COLON = 73,                     /* COLON  */
  YYSYMBOL_DOT = 74,                       /* DOT  */
  YYSYMBOL_SEMICOLON = 75,                 /* SEMICOLON  */
  YYSYMBOL_EQUAL_SIGN = 76,                /* EQUAL_SIGN  */
  YYSYMBOL_ARROW = 77,                     /* ARROW  */
  YYSYMBOL_PLUS_EQUAL = 78,                /* PLUS_EQUAL  */
  YYSYMBOL_MINUS_EQUAL = 79,               /* MINUS_EQUAL  */
  YYSYMBOL_TIMES_EQUAL = 80,               /* TIMES_EQUAL  */
  YYSYMBOL_DIVIDEDBY_EQUAL = 81,           /* DIVIDEDBY_EQUAL  */
  YYSYMBOL_FLOORDIV_EQUAL = 82,            /* FLOORDIV_EQUAL  */
  YYSYMBOL_MODULO_EQUAL = 83,              /* MODULO_EQUAL  */
  YYSYMBOL_AT_EQUAL = 84,                  /* AT_EQUAL  */
  YYSYMBOL_BITWISE_AND_EQUAL = 85,         /* BITWISE_AND_EQUAL  */
  YYSYMBOL_BITWISE_OR_EQUAL = 86,          /* BITWISE_OR_EQUAL  */
  YYSYMBOL_BITWISE_XOR_EQUAL = 87,         /* BITWISE_XOR_EQUAL  */
  YYSYMBOL_SHIFT_RIGHT_EQUAL = 88,         /* SHIFT_RIGHT_EQUAL  */
  YYSYMBOL_SHIFT_LEFT_EQUAL = 89,          /* SHIFT_LEFT_EQUAL  */
  YYSYMBOL_POWER_EQUAL = 90,               /* POWER_EQUAL  */
  YYSYMBOL_SINGLE_QUOTE = 91,              /* SINGLE_QUOTE  */
  YYSYMBOL_DOUBLE_QUOTE = 92,              /* DOUBLE_QUOTE  */
  YYSYMBOL_HASH = 93,                      /* HASH  */
  YYSYMBOL_BACKSLASH = 94,                 /* BACKSLASH  */
  YYSYMBOL_DOLLAR = 95,                    /* DOLLAR  */
  YYSYMBOL_QUESTION_MARK = 96,             /* QUESTION_MARK  */
  YYSYMBOL_BACKTICK = 97,                  /* BACKTICK  */
  YYSYMBOL_TRIPLEDOT = 98,                 /* TRIPLEDOT  */
  YYSYMBOL_RANGE = 99,                     /* RANGE  */
  YYSYMBOL_YYACCEPT = 100,                 /* $accept  */
  YYSYMBOL_file_input = 101,               /* file_input  */
  YYSYMBOL_newline_stat_rep = 102,         /* newline_stat_rep  */
  YYSYMBOL_funcname = 103,                 /* funcname  */
  YYSYMBOL_funcdef = 104,                  /* funcdef  */
  YYSYMBOL_parameters = 105,               /* parameters  */
  YYSYMBOL_typedargslist = 106,            /* typedargslist  */
  YYSYMBOL_datatype = 107,                 /* datatype  */
  YYSYMBOL_stmt = 108,                     /* stmt  */
  YYSYMBOL_simple_stmt = 109,              /* simple_stmt  */
  YYSYMBOL_small_stmt_list = 110,          /* small_stmt_list  */
  YYSYMBOL_small_stmt = 111,               /* small_stmt  */
  YYSYMBOL_expr_stmt = 112,                /* expr_stmt  */
  YYSYMBOL_expr_stmt_tail = 113,           /* expr_stmt_tail  */
  YYSYMBOL_augassign_op = 114,             /* augassign_op  */
  YYSYMBOL_rep_expr_stmt_tail = 115,       /* rep_expr_stmt_tail  */
  YYSYMBOL_rep_expr_stmt_tail_op = 116,    /* rep_expr_stmt_tail_op  */
  YYSYMBOL_annassign = 117,                /* annassign  */
  YYSYMBOL_annasign_op = 118,              /* annasign_op  */
  YYSYMBOL_testlist_star_expr = 119,       /* testlist_star_expr  */
  YYSYMBOL_testlist_star_expr_opt1 = 120,  /* testlist_star_expr_opt1  */
  YYSYMBOL_testlist_star_expr_rep = 121,   /* testlist_star_expr_rep  */
  YYSYMBOL_augassign = 122,                /* augassign  */
  YYSYMBOL_del_stmt = 123,                 /* del_stmt  */
  YYSYMBOL_pass_stmt = 124,                /* pass_stmt  */
  YYSYMBOL_flow_stmt = 125,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 126,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 127,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 128,              /* return_stmt  */
  YYSYMBOL_yield_stmt = 129,               /* yield_stmt  */
  YYSYMBOL_global_stmt = 130,              /* global_stmt  */
  YYSYMBOL_global_name_list = 131,         /* global_name_list  */
  YYSYMBOL_compound_stmt = 132,            /* compound_stmt  */
  YYSYMBOL_async_stmt = 133,               /* async_stmt  */
  YYSYMBOL_async_stmt_content = 134,       /* async_stmt_content  */
  YYSYMBOL_if_stmt = 135,                  /* if_stmt  */
  YYSYMBOL_elif_stmt_rep = 136,            /* elif_stmt_rep  */
  YYSYMBOL_while_stmt = 137,               /* while_stmt  */
  YYSYMBOL_for_stmt = 138,                 /* for_stmt  */
  YYSYMBOL_suite = 139,                    /* suite  */
  YYSYMBOL_stmt_rep = 140,                 /* stmt_rep  */
  YYSYMBOL_test = 141,                     /* test  */
  YYSYMBOL_test_nocond = 142,              /* test_nocond  */
  YYSYMBOL_or_test = 143,                  /* or_test  */
  YYSYMBOL_or_test_rep = 144,              /* or_test_rep  */
  YYSYMBOL_and_test = 145,                 /* and_test  */
  YYSYMBOL_and_test_rep = 146,             /* and_test_rep  */
  YYSYMBOL_not_test = 147,                 /* not_test  */
  YYSYMBOL_comparison = 148,               /* comparison  */
  YYSYMBOL_comparison_rep = 149,           /* comparison_rep  */
  YYSYMBOL_comp_op = 150,                  /* comp_op  */
  YYSYMBOL_star_expr = 151,                /* star_expr  */
  YYSYMBOL_expr = 152,                     /* expr  */
  YYSYMBOL_expr_rep = 153,                 /* expr_rep  */
  YYSYMBOL_xor_expr = 154,                 /* xor_expr  */
  YYSYMBOL_xor_expr_rep = 155,             /* xor_expr_rep  */
  YYSYMBOL_and_expr = 156,                 /* and_expr  */
  YYSYMBOL_and_expr_rep = 157,             /* and_expr_rep  */
  YYSYMBOL_shift_expr = 158,               /* shift_expr  */
  YYSYMBOL_shift_expr_rep = 159,           /* shift_expr_rep  */
  YYSYMBOL_shift_expr_rep_c1 = 160,        /* shift_expr_rep_c1  */
  YYSYMBOL_arith_expr = 161,               /* arith_expr  */
  YYSYMBOL_arith_expr_rep = 162,           /* arith_expr_rep  */
  YYSYMBOL_arith_expr_rep_c1 = 163,        /* arith_expr_rep_c1  */
  YYSYMBOL_term = 164,                     /* term  */
  YYSYMBOL_term_rep = 165,                 /* term_rep  */
  YYSYMBOL_term_rep_c1 = 166,              /* term_rep_c1  */
  YYSYMBOL_factor = 167,                   /* factor  */
  YYSYMBOL_factor_c1 = 168,                /* factor_c1  */
  YYSYMBOL_power = 169,                    /* power  */
  YYSYMBOL_power_opt = 170,                /* power_opt  */
  YYSYMBOL_atom_expr = 171,                /* atom_expr  */
  YYSYMBOL_await_opt = 172,                /* await_opt  */
  YYSYMBOL_trailer_rep = 173,              /* trailer_rep  */
  YYSYMBOL_atom = 174,                     /* atom  */
  YYSYMBOL_atom_opt1 = 175,                /* atom_opt1  */
  YYSYMBOL_atom_opt2 = 176,                /* atom_opt2  */
  YYSYMBOL_string_rep = 177,               /* string_rep  */
  YYSYMBOL_testlist_comp = 178,            /* testlist_comp  */
  YYSYMBOL_testlist_comp_c1 = 179,         /* testlist_comp_c1  */
  YYSYMBOL_testlist_comp_c2 = 180,         /* testlist_comp_c2  */
  YYSYMBOL_testlist_comp_c2_rep = 181,     /* testlist_comp_c2_rep  */
  YYSYMBOL_trailer = 182,                  /* trailer  */
  YYSYMBOL_subscriptlist = 183,            /* subscriptlist  */
  YYSYMBOL_COMMA_opt = 184,                /* COMMA_opt  */
  YYSYMBOL_COMMA_subscript_rep = 185,      /* COMMA_subscript_rep  */
  YYSYMBOL_subscript = 186,                /* subscript  */
  YYSYMBOL_sliceop = 187,                  /* sliceop  */
  YYSYMBOL_exprlist = 188,                 /* exprlist  */
  YYSYMBOL_expr_star_expr = 189,           /* expr_star_expr  */
  YYSYMBOL_COMMA_expr_star_expr_rep = 190, /* COMMA_expr_star_expr_rep  */
  YYSYMBOL_testlist = 191,                 /* testlist  */
  YYSYMBOL_classdef = 192,                 /* classdef  */
  YYSYMBOL_arglist = 193,                  /* arglist  */
  YYSYMBOL_COMMA_argument_rep = 194,       /* COMMA_argument_rep  */
  YYSYMBOL_argument = 195,                 /* argument  */
  YYSYMBOL_comp_iter = 196,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 197,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 198,                 /* comp_for  */
  YYSYMBOL_comp_if = 199,                  /* comp_if  */
  YYSYMBOL_yield_expr = 200                /* yield_expr  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  103
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  263
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  375

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   354


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   120,   127,   135,   144,   145,   147,   172,
     210,   249,   258,   265,   274,   297,   314,   347,   354,   366,
     367,   370,   377,   385,   392,   401,   411,   419,   420,   421,
     422,   423,   425,   454,   457,   460,   466,   470,   471,   473,
     482,   490,   491,   493,   501,   509,   514,   516,   523,   528,
     533,   537,   538,   541,   550,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   567,   573,
     575,   576,   577,   578,   581,   583,   584,   592,   594,   595,
     602,   612,   614,   615,   616,   617,   618,   619,   622,   625,
     626,   629,   642,   653,   664,   673,   684,   693,   704,   713,
     726,   737,   738,   750,   760,   762,   771,   774,   777,   784,
     787,   796,   802,   808,   811,   821,   828,   835,   840,   853,
     857,   866,   874,   875,   876,   877,   878,   879,   880,   881,
     887,   888,   896,   904,   910,   913,   922,   928,   934,   939,
     948,   954,   960,   963,   972,   978,   984,   987,   996,  1002,
    1005,  1008,  1021,  1024,  1031,  1039,  1040,  1043,  1057,  1060,
    1069,  1076,  1077,  1078,  1079,  1080,  1083,  1089,  1091,  1092,
    1093,  1096,  1105,  1111,  1120,  1128,  1138,  1144,  1149,  1158,
    1162,  1170,  1178,  1185,  1207,  1208,  1209,  1210,  1211,  1212,
    1213,  1215,  1216,  1218,  1221,  1222,  1232,  1238,  1241,  1242,
    1245,  1246,  1252,  1253,  1256,  1266,  1275,  1281,  1289,  1298,
    1304,  1312,  1318,  1326,  1334,  1340,  1346,  1349,  1353,  1362,
    1370,  1371,  1380,  1387,  1394,  1401,  1407,  1413,  1419,  1421,
    1427,  1429,  1436,  1442,  1448,  1450,  1451,  1454,  1463,  1478,
    1490,  1506,  1517,  1527,  1537,  1552,  1559,  1572,  1577,  1589,
    1599,  1605,  1611,  1617,  1623,  1625,  1626,  1628,  1637,  1646,
    1651,  1653,  1660,  1666
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NAME", "FLOAT",
  "INDENT", "DEDENT", "ENDMARKER", "NEWLINE", "FALSE_TOKEN", "AWAIT",
  "ELSE", "IMPORT", "PASS", "NONE", "BREAK", "EXCEPT", "IN", "RAISE",
  "TRUE_TOKEN", "CLASS", "FINALLY", "IS", "RETURN", "AND", "CONTINUE",
  "FOR", "LAMBDA", "TRY", "AS", "DEF", "FROM", "NONLOCAL", "WHILE",
  "ASSERT", "DEL", "GLOBAL", "NOT", "WITH", "ASYNC", "ELIF", "IF", "OR",
  "YIELD", "NUMBER", "STRING", "PLUS", "MINUS", "TIMES", "POWER",
  "DIVIDEDBY", "FLOORDIV", "MODULO", "AT", "SHIFT_LEFT", "SHIFT_RIGHT",
  "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT", "LESS_THAN",
  "GREATER_THAN", "LESS_THAN_OR_EQUAL", "GREATER_THAN_OR_EQUAL", "EQUAL",
  "NOT_EQUAL", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LBRACE",
  "RBRACE", "COMMA", "COLON", "DOT", "SEMICOLON", "EQUAL_SIGN", "ARROW",
  "PLUS_EQUAL", "MINUS_EQUAL", "TIMES_EQUAL", "DIVIDEDBY_EQUAL",
  "FLOORDIV_EQUAL", "MODULO_EQUAL", "AT_EQUAL", "BITWISE_AND_EQUAL",
  "BITWISE_OR_EQUAL", "BITWISE_XOR_EQUAL", "SHIFT_RIGHT_EQUAL",
  "SHIFT_LEFT_EQUAL", "POWER_EQUAL", "SINGLE_QUOTE", "DOUBLE_QUOTE",
  "HASH", "BACKSLASH", "DOLLAR", "QUESTION_MARK", "BACKTICK", "TRIPLEDOT",
  "RANGE", "$accept", "file_input", "newline_stat_rep", "funcname",
  "funcdef", "parameters", "typedargslist", "datatype", "stmt",
  "simple_stmt", "small_stmt_list", "small_stmt", "expr_stmt",
  "expr_stmt_tail", "augassign_op", "rep_expr_stmt_tail",
  "rep_expr_stmt_tail_op", "annassign", "annasign_op",
  "testlist_star_expr", "testlist_star_expr_opt1",
  "testlist_star_expr_rep", "augassign", "del_stmt", "pass_stmt",
  "flow_stmt", "break_stmt", "continue_stmt", "return_stmt", "yield_stmt",
  "global_stmt", "global_name_list", "compound_stmt", "async_stmt",
  "async_stmt_content", "if_stmt", "elif_stmt_rep", "while_stmt",
  "for_stmt", "suite", "stmt_rep", "test", "test_nocond", "or_test",
  "or_test_rep", "and_test", "and_test_rep", "not_test", "comparison",
  "comparison_rep", "comp_op", "star_expr", "expr", "expr_rep", "xor_expr",
  "xor_expr_rep", "and_expr", "and_expr_rep", "shift_expr",
  "shift_expr_rep", "shift_expr_rep_c1", "arith_expr", "arith_expr_rep",
  "arith_expr_rep_c1", "term", "term_rep", "term_rep_c1", "factor",
  "factor_c1", "power", "power_opt", "atom_expr", "await_opt",
  "trailer_rep", "atom", "atom_opt1", "atom_opt2", "string_rep",
  "testlist_comp", "testlist_comp_c1", "testlist_comp_c2",
  "testlist_comp_c2_rep", "trailer", "subscriptlist", "COMMA_opt",
  "COMMA_subscript_rep", "subscript", "sliceop", "exprlist",
  "expr_star_expr", "COMMA_expr_star_expr_rep", "testlist", "classdef",
  "arglist", "COMMA_argument_rep", "argument", "comp_iter",
  "sync_comp_for", "comp_for", "comp_if", "yield_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-237)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      28,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,    31,  1085,  -237,    89,    65,  1085,    89,    75,  1085,
     115,  1085,  -237,  -237,  -237,  -237,  -237,   228,  -237,   704,
     764,  -237,    83,   309,    77,  -237,  -237,  -237,    15,  -237,
     137,    90,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,   105,   126,   151,  -237,
    -237,   365,   122,   128,   132,   111,    82,   101,   228,  -237,
     141,    41,    14,   147,  -237,  -237,     4,   127,  -237,  -237,
    -237,   177,   129,  -237,   130,  -237,  -237,   134,  -237,  -237,
    -237,  -237,   135,  -237,  -237,  -237,   133,  -237,    58,  -237,
    -237,   140,  -237,  -237,  -237,  -237,  -237,    54,    94,  -237,
     483,    48,  1085,   704,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,   136,  -237,
     916,   933,   139,  1085,  1085,   160,  1085,   204,  -237,   196,
     218,  -237,  -237,  -237,  -237,  -237,  -237,   365,   228,   228,
     182,   228,   183,   228,   184,  -237,  -237,   111,   228,  -237,
    -237,    82,   228,  -237,  -237,  -237,  -237,  -237,   101,   228,
    -237,   228,  -237,    14,   627,   810,   240,    14,  -237,  -237,
     687,   531,  -237,  1085,    89,   172,   531,   242,   531,  -237,
      89,   220,   933,  -237,   176,  -237,  -237,  -237,   125,  -237,
     186,   531,  1085,  -237,  -237,  -237,   579,   173,  -237,  -237,
    -237,   704,  -237,  -237,  -237,  -237,   933,   243,  -237,  1085,
    -237,  1085,  -237,  -237,   228,  -237,  -237,   228,  -237,   228,
    -237,   228,   228,  -237,   228,  -237,   228,  -237,  -237,    14,
    1085,  1085,  -237,    74,   188,   179,  -237,   993,   185,   187,
     189,  -237,  -237,   190,   192,   257,  -237,  -237,   191,  -237,
      89,   255,  -237,   116,   250,  -237,  -237,  -237,   933,   265,
     267,  -237,  -237,   198,  -237,  -237,  1085,  -237,  -237,  -237,
    1085,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  1085,  -237,  -237,   856,   205,  1085,   206,  -237,
     993,  -237,  1039,  -237,   208,   531,   209,   435,   531,  -237,
     210,   212,  1085,   120,  1085,  -237,  -237,  -237,   222,   216,
     531,  -237,  -237,  -237,  -237,   856,  -237,  -237,   206,  -237,
    -237,  1039,  -237,  -237,   531,  -237,   375,   281,   531,   531,
     224,   225,  1085,    40,   275,   265,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,   226,  -237,  -237,   531,   531,   227,  1085,
    -237,  -237,  -237,   233,  -237,   531,  -237,  -237,   531,    40,
    -237,  -237,  -237,  -237,  -237
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   183,   185,     3,     7,   190,   177,    69,   188,    74,
     189,     0,    77,    75,     0,     0,     0,     0,     0,     0,
       0,     0,   263,   184,   194,   168,   169,     0,   170,     0,
       0,   187,     0,     0,     0,    85,     6,    19,     0,    27,
      33,    50,    28,    29,    30,    70,    71,    72,    73,    31,
      20,    87,    82,    83,    84,    51,   106,   109,   113,   117,
      52,   119,   134,   138,   142,   146,   152,   158,     0,   167,
     172,     0,   176,   186,    86,    78,     0,   240,    76,   236,
     235,     0,   234,     8,     0,    68,    81,    79,   116,    89,
      88,    90,     0,   132,   198,   199,     0,   192,   197,   191,
     182,     0,   193,     1,     2,     4,     5,     0,     0,    21,
       0,     0,     0,     0,    55,    56,    57,    59,    67,    60,
      58,    61,    62,    63,    65,    64,    66,    32,    36,    34,
       0,    49,    48,     0,     0,   108,     0,   112,   128,   130,
       0,   122,   123,   126,   125,   124,   127,   118,     0,     0,
     133,     0,   137,     0,   141,   149,   150,   145,     0,   155,
     156,   151,     0,   161,   163,   165,   164,   162,   157,     0,
     166,     0,   171,     0,     0,     0,     0,   175,   179,   195,
       0,     0,   239,     0,   232,   233,     0,     0,     0,   180,
       0,     0,   202,   196,   203,   260,   200,   181,    13,    12,
       0,     0,     0,    23,    26,    22,     0,    44,    40,    42,
      41,     0,    35,    38,    37,    54,    47,     0,   111,     0,
     115,     0,   131,   129,     0,   121,   136,     0,   140,     0,
     144,     0,     0,   148,     0,   154,     0,   160,   173,   174,
       0,     0,   209,   254,     0,   247,   211,   228,   220,     0,
     216,   212,   178,     0,     0,     0,   101,   243,     0,   238,
     231,    98,    80,    94,     0,   259,   206,   207,   201,     0,
       0,    11,    10,     0,    24,    25,    46,    43,    39,    53,
       0,   110,   114,   120,   135,   139,   143,   147,   153,   159,
     253,   252,     0,   250,   208,   245,   246,   230,   226,   225,
     227,   210,   217,   214,   215,     0,     0,     0,     0,   237,
       0,     0,     0,    92,     0,   204,   205,    15,    17,    14,
       0,    45,   105,   251,   249,   244,   229,   222,   224,   223,
     219,   217,   213,   242,     0,   104,     0,   100,     0,     0,
       0,     0,     0,   258,     0,     0,     9,   248,   221,   218,
     241,   102,   103,     0,    97,    93,     0,     0,     0,     0,
     257,   255,   256,     0,    16,     0,    96,    91,     0,   262,
     107,    18,    99,    95,   261
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -237,  -237,  -237,  -237,   273,  -237,  -223,  -237,   -31,     0,
    -237,   -96,  -237,  -237,  -237,  -237,    84,  -237,  -237,   -97,
    -111,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,   283,  -161,
    -237,   -11,  -237,  -125,  -237,  -108,  -237,   -16,  -237,  -237,
     157,    -8,   -10,  -237,  -121,  -237,  -127,  -237,  -114,  -237,
     149,  -128,  -237,   148,  -110,  -237,   142,   -53,  -237,  -237,
    -237,  -237,  -237,   138,   237,  -237,  -237,  -237,   285,  -237,
    -237,  -237,  -148,  -237,    17,  -237,  -170,  -158,    -5,  -135,
    -237,   -68,  -237,   145,  -237,  -236,   -42,   146,   -85,  -237,
     -18
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    32,    33,    34,    35,   108,   200,   319,    36,   256,
     111,    38,    39,   127,   212,   128,   208,   129,   277,    40,
      41,   132,   130,    42,    43,    44,    45,    46,    47,    48,
      49,    87,    50,    51,    90,    52,   313,    53,    54,   257,
     336,    55,   369,    56,   135,    57,   137,    58,    59,   147,
     148,    60,    61,   150,    62,   152,    63,   154,    64,   157,
     158,    65,   161,   162,    66,   168,   169,    67,    68,    69,
     172,    70,    71,   177,    72,    96,   101,    73,    97,    98,
     193,   194,   178,   249,   303,   304,   250,   299,    81,    82,
     185,    78,    74,   244,   296,   245,   360,   195,   361,   362,
      75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    77,   106,    88,    80,    84,    79,    80,   217,    79,
      92,    99,    85,   196,   204,   170,   209,    93,    94,    94,
     215,    95,    95,   109,   228,   261,   218,   263,   226,   252,
     233,     1,     2,    37,    76,     3,     4,     5,     6,   230,
     272,     7,     8,     9,     1,     2,   317,    10,    11,   259,
       5,    12,   235,    13,    14,     8,   205,   198,    15,   324,
      10,    16,   213,    17,    18,    19,   190,    20,    83,    21,
     180,    22,    23,    24,    25,    26,    27,   181,    86,   191,
     174,   359,   175,   103,   190,    23,    24,    28,   176,   347,
     110,   252,     1,     2,    29,   210,    30,   191,     5,     6,
     190,   207,   285,     8,   287,   279,   284,    29,    10,    30,
     275,   281,   214,   191,   209,   258,   237,   286,   238,    77,
     220,   199,   364,   206,   288,   309,    31,   311,   159,   160,
     192,   341,   330,    23,    24,    25,    26,    27,   225,    31,
     327,    14,   329,   107,   333,    15,   133,   337,    28,   163,
     292,   164,   165,   166,   167,    29,   312,    30,   293,   346,
     342,   349,   131,   243,   248,   155,   156,   201,   134,   243,
     348,   202,    77,   350,    80,   136,    79,   354,   355,   149,
      80,   266,    79,   289,   267,   264,   151,    31,   153,   343,
     171,   273,   179,   210,   183,   366,   367,   269,   270,   182,
     189,   184,   219,   186,   372,   282,   187,   373,   188,   197,
     112,   216,   211,   113,   283,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   221,   290,
     291,     1,     2,   222,   370,   223,   298,     5,     6,   227,
     231,   229,     8,   251,   260,   262,   190,    10,   268,   276,
      80,   295,    79,   271,   280,   294,   301,   315,   300,   306,
     316,   302,   307,   305,   308,   321,   310,   314,   198,   322,
     318,   320,    23,    24,    25,    26,   335,   325,   363,   297,
     331,   323,   334,   338,   243,   339,   326,    28,   345,   328,
     344,   248,   353,    89,    29,   278,    30,   356,   357,   365,
     368,   340,   371,    91,   224,   352,   232,    37,   173,   234,
     236,   239,     1,     2,   243,   102,   104,   105,     5,     6,
     248,   332,     7,     8,     9,   254,    31,   374,    10,    11,
       0,   358,    12,     0,    13,    14,    37,   265,     0,    15,
       0,     0,    16,     0,    17,    18,    19,     0,    20,     0,
      21,     0,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     0,     0,     0,    29,     0,    30,     1,     2,
       0,   351,   138,     0,     5,     6,     0,   139,     7,     8,
       9,     0,     0,     0,    10,    11,     0,     0,    12,     0,
      13,    14,   140,     0,     0,    15,     0,    31,    16,     0,
      17,    18,    19,     0,    20,     0,    21,     0,    22,    23,
      24,    25,    26,    27,     0,   141,   142,   143,   144,   145,
     146,     0,     0,     0,    28,     0,     0,     0,     1,     2,
       0,    29,     0,    30,     5,     6,     0,     0,     7,     8,
       9,     0,     0,     0,    10,    11,     0,     0,    12,     0,
      13,    14,     0,     0,     0,    15,     0,     0,    16,     0,
      17,    18,    19,    31,    20,     0,    21,     0,    22,    23,
      24,    25,    26,    27,     0,     0,     1,     2,     0,     0,
       0,   203,     5,     6,    28,     0,     7,     8,     9,     0,
       0,    29,    10,    30,     0,     0,    12,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,     0,     0,     0,     0,     0,    22,    23,    24,    25,
      26,    27,     0,    31,     1,     2,     0,     0,     0,   255,
       5,     6,    28,     0,     7,     8,     9,     0,     0,    29,
      10,    30,     0,     0,    12,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,    19,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
       0,    31,     1,     2,     0,     0,     0,   274,     5,     6,
      28,     0,     7,     8,     9,     0,     0,    29,    10,    30,
       0,     0,    12,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,     0,    31,
       1,     2,     0,     0,     0,     0,     5,     6,    28,     0,
       0,     8,     0,     0,     0,    29,    10,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   240,   241,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       1,     2,     0,    29,   242,    30,     5,     6,     0,     0,
       0,     8,     0,     0,     0,     0,    10,     1,     2,     0,
       0,     0,     0,     5,     6,     0,     0,     0,     8,     0,
       0,     0,     0,    10,    19,    31,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   240,   241,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    28,    22,    23,    24,
      25,    26,    27,    29,   253,    30,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     1,     2,     0,
      29,     0,    30,     5,     6,     0,     0,     0,     8,     0,
       0,     0,     0,    10,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    31,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,     1,     2,     0,     0,     0,     0,     5,
       6,     0,     0,    28,     8,     0,     0,     0,     0,    10,
      29,     0,    30,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,     0,     1,
       2,     0,    31,     0,     0,     5,     6,     0,     0,    28,
       8,     0,     0,     0,     0,    10,    29,     0,    30,   246,
       0,     0,     0,   247,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   240,   241,     0,     0,    31,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     1,
       2,     0,    29,     0,    30,     5,     6,     0,     0,     0,
       8,     0,     0,     0,     0,    10,     1,     2,     0,     0,
       0,     0,     5,     6,     0,     0,     0,     8,     0,     0,
       0,     0,    10,    19,    31,     0,     0,     0,     0,    22,
      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    28,     0,    23,    24,    25,
      26,    27,    29,     0,    30,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,     1,     2,     0,    29,
       0,    30,     5,     6,     0,     0,     0,     8,     0,     0,
       0,     0,    10,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    31,     0,     0,     0,     0,     0,    23,    24,    25,
      26,     0,     1,     2,     0,     0,     0,     0,     5,     6,
       0,     0,    28,     8,     0,     0,     0,     0,    10,    29,
       0,    30,     0,     0,     0,     0,   297,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,     0,     1,     2,
       0,    31,     0,     0,     5,     6,     0,     0,    28,     8,
       0,     0,     0,     0,    10,    29,     0,    30,     0,     0,
       0,     0,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,     0,
       0,    29,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
       0,    12,    33,    19,    14,    16,    14,    17,   133,    17,
      21,    29,    17,    98,   110,    68,   113,    27,    29,    30,
     131,    29,    30,     8,   151,   186,   134,   188,   149,   177,
     158,     3,     4,    33,     3,     7,     8,     9,    10,   153,
     201,    13,    14,    15,     3,     4,   269,    19,    20,   184,
       9,    23,   162,    25,    26,    14,     8,     3,    30,   295,
      19,    33,   130,    35,    36,    37,    26,    39,     3,    41,
      66,    43,    44,    45,    46,    47,    48,    73,     3,    39,
      66,    41,    68,     0,    26,    44,    45,    59,    74,   325,
      75,   239,     3,     4,    66,   113,    68,    39,     9,    10,
      26,   112,   229,    14,   232,   216,   227,    66,    19,    68,
     206,   219,   130,    39,   211,   183,   169,   231,   171,   130,
     136,    67,   345,    75,   234,   260,    98,    11,    46,    47,
      72,    11,   302,    44,    45,    46,    47,    48,   148,    98,
     298,    26,   300,    66,   305,    30,    41,   308,    59,    48,
      76,    50,    51,    52,    53,    66,    40,    68,   243,   320,
      40,   331,    72,   174,   175,    54,    55,    73,    42,   180,
     328,    77,   183,   334,   184,    24,   184,   338,   339,    57,
     190,   192,   190,   236,   192,   190,    58,    98,    56,   314,
      49,   202,    45,   211,    17,   356,   357,    72,    73,    72,
      67,    72,    42,    73,   365,   221,    72,   368,    73,    69,
      73,    72,    76,    76,   224,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    24,   240,
     241,     3,     4,    37,   359,    17,   247,     9,    10,    57,
      56,    58,    14,     3,    72,     3,    26,    19,    72,    76,
     260,    72,   260,    67,    11,    67,    69,   268,    73,    67,
     268,    72,     5,    73,    73,   276,    11,    17,     3,   280,
       3,    73,    44,    45,    46,    47,   307,    72,     3,    73,
      72,   292,    73,    73,   295,    73,   297,    59,    72,   300,
      68,   302,    11,    20,    66,   211,    68,    73,    73,    73,
      73,   312,    69,    20,   147,   336,   157,   307,    71,   161,
     168,   173,     3,     4,   325,    30,     7,     8,     9,    10,
     331,   304,    13,    14,    15,   180,    98,   369,    19,    20,
      -1,   342,    23,    -1,    25,    26,   336,   191,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    37,    -1,    39,    -1,
      41,    -1,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    68,     3,     4,
      -1,     6,    17,    -1,     9,    10,    -1,    22,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,
      25,    26,    37,    -1,    -1,    30,    -1,    98,    33,    -1,
      35,    36,    37,    -1,    39,    -1,    41,    -1,    43,    44,
      45,    46,    47,    48,    -1,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    59,    -1,    -1,    -1,     3,     4,
      -1,    66,    -1,    68,     9,    10,    -1,    -1,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,    37,    98,    39,    -1,    41,    -1,    43,    44,
      45,    46,    47,    48,    -1,    -1,     3,     4,    -1,    -1,
      -1,     8,     9,    10,    59,    -1,    13,    14,    15,    -1,
      -1,    66,    19,    68,    -1,    -1,    23,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    -1,    98,     3,     4,    -1,    -1,    -1,     8,
       9,    10,    59,    -1,    13,    14,    15,    -1,    -1,    66,
      19,    68,    -1,    -1,    23,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      -1,    98,     3,     4,    -1,    -1,    -1,     8,     9,    10,
      59,    -1,    13,    14,    15,    -1,    -1,    66,    19,    68,
      -1,    -1,    23,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    -1,    98,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    59,    -1,
      -1,    14,    -1,    -1,    -1,    66,    19,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
       3,     4,    -1,    66,    67,    68,     9,    10,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    19,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    19,    37,    98,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    59,    43,    44,    45,
      46,    47,    48,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,     3,     4,    -1,
      66,    -1,    68,     9,    10,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    19,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    98,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    -1,    -1,    59,    14,    -1,    -1,    -1,    -1,    19,
      66,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,     3,
       4,    -1,    98,    -1,    -1,     9,    10,    -1,    -1,    59,
      14,    -1,    -1,    -1,    -1,    19,    66,    -1,    68,    69,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,     3,
       4,    -1,    66,    -1,    68,     9,    10,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    19,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    19,    37,    98,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    59,    -1,    44,    45,    46,
      47,    48,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,     3,     4,    -1,    66,
      -1,    68,     9,    10,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    19,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    98,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      -1,    -1,    59,    14,    -1,    -1,    -1,    -1,    19,    66,
      -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,     3,     4,
      -1,    98,    -1,    -1,     9,    10,    -1,    -1,    59,    14,
      -1,    -1,    -1,    -1,    19,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,     8,     9,    10,    13,    14,    15,
      19,    20,    23,    25,    26,    30,    33,    35,    36,    37,
      39,    41,    43,    44,    45,    46,    47,    48,    59,    66,
      68,    98,   101,   102,   103,   104,   108,   109,   111,   112,
     119,   120,   123,   124,   125,   126,   127,   128,   129,   130,
     132,   133,   135,   137,   138,   141,   143,   145,   147,   148,
     151,   152,   154,   156,   158,   161,   164,   167,   168,   169,
     171,   172,   174,   177,   192,   200,     3,   141,   191,   151,
     152,   188,   189,     3,   141,   188,     3,   131,   147,   104,
     134,   138,   141,   152,   141,   151,   175,   178,   179,   200,
      69,   176,   178,     0,     7,     8,   108,    66,   105,     8,
      75,   110,    73,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   113,   115,   117,
     122,    72,   121,    41,    42,   144,    24,   146,    17,    22,
      37,    60,    61,    62,    63,    64,    65,   149,   150,    57,
     153,    58,   155,    56,   157,    54,    55,   159,   160,    46,
      47,   162,   163,    48,    50,    51,    52,    53,   165,   166,
     167,    49,   170,   174,    66,    68,    74,   173,   182,    45,
      66,    73,    72,    17,    72,   190,    73,    72,    73,    67,
      26,    39,    72,   180,   181,   197,   198,    69,     3,    67,
     106,    73,    77,     8,   111,     8,    75,   141,   116,   119,
     200,    76,   114,   191,   200,   120,    72,   143,   145,    42,
     147,    24,    37,    17,   150,   152,   154,    57,   156,    58,
     158,    56,   160,   161,   163,   164,   166,   167,   167,   173,
      48,    49,    67,   141,   193,   195,    69,    73,   141,   183,
     186,     3,   182,    67,   193,     8,   109,   139,   191,   189,
      72,   139,     3,   139,   188,   197,   141,   151,    72,    72,
      73,    67,   139,   141,     8,   111,    76,   118,   116,   120,
      11,   145,   147,   152,   154,   156,   158,   161,   164,   167,
     141,   141,    76,   198,    67,    72,   194,    73,   141,   187,
      73,    69,    72,   184,   185,    73,    67,     5,    73,   189,
      11,    11,    40,   136,    17,   141,   151,   106,     3,   107,
      73,   141,   141,   141,   195,    72,   141,   187,   141,   187,
     186,    72,   184,   139,    73,   108,   140,   139,    73,    73,
     141,    11,    40,   143,    68,    72,   139,   195,   187,   186,
     139,     6,   108,    11,   139,   139,    73,    73,   141,    41,
     196,   198,   199,     3,   106,    73,   139,   139,    73,   142,
     143,    69,   139,   139,   196
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   102,   102,   102,   102,   103,   104,
     104,   105,   105,   106,   106,   106,   106,   107,   107,   108,
     108,   109,   109,   109,   109,   110,   110,   111,   111,   111,
     111,   111,   112,   112,   113,   113,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   118,   118,   119,   119,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   123,   124,
     125,   125,   125,   125,   126,   127,   128,   128,   129,   130,
     131,   131,   132,   132,   132,   132,   132,   132,   133,   134,
     134,   135,   135,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   140,   140,   141,   141,   142,   143,   143,
     144,   144,   145,   145,   146,   146,   147,   147,   148,   148,
     149,   149,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   151,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   156,   157,   157,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   167,   167,   168,   168,
     168,   169,   169,   170,   171,   171,   171,   172,   173,   173,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   175,   175,   176,   177,   177,   178,   178,   179,   179,
     180,   180,   180,   180,   181,   181,   181,   181,   182,   182,
     182,   182,   182,   183,   183,   183,   183,   184,   185,   185,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   187,
     187,   188,   188,   188,   188,   189,   189,   190,   190,   191,
     191,   192,   192,   192,   193,   193,   193,   193,   194,   194,
     195,   195,   195,   195,   195,   196,   196,   197,   197,   198,
     198,   199,   199,   200
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     1,     2,     6,
       4,     3,     2,     1,     3,     3,     5,     1,     4,     1,
       1,     2,     3,     3,     4,     3,     2,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     1,     1,     1,     3,
       2,     1,     1,     3,     2,     2,     1,     3,     2,     2,
       1,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     8,     5,     7,     4,     5,     4,     7,     4,     9,
       6,     1,     4,     2,     1,     5,     1,     1,     2,     1,
       3,     2,     2,     1,     3,     2,     2,     1,     2,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     2,     2,     1,     3,     2,     2,     1,     3,
       2,     2,     1,     3,     2,     2,     1,     3,     2,     1,
       1,     2,     1,     3,     2,     1,     1,     2,     1,     3,
       2,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     2,     1,     2,     3,     2,     1,     1,     2,     1,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     2,     1,     1,     3,     3,     2,     2,     3,     2,
       3,     2,     2,     3,     2,     2,     1,     1,     3,     2,
       1,     4,     3,     3,     3,     2,     2,     2,     1,     2,
       1,     3,     2,     2,     1,     1,     1,     3,     2,     2,
       1,     7,     6,     4,     3,     2,     2,     1,     3,     2,
       2,     3,     2,     2,     1,     1,     1,     5,     4,     2,
       1,     3,     2,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* file_input: newline_stat_rep ENDMARKER  */
#line 114 "parser.y"
                               {
    if(yybye) cout<<"LINE 107";
    (yyval.node) = root;
    root->children.push_back((yyvsp[-1].node));
    root->children.push_back((yyvsp[0].node));
  }
#line 2071 "parser.cpp"
    break;

  case 3: /* file_input: ENDMARKER  */
#line 120 "parser.y"
              {
    if(yybye) cout<<"LINE 115";
    (yyval.node) = NULL;
    }
#line 2080 "parser.cpp"
    break;

  case 4: /* newline_stat_rep: newline_stat_rep NEWLINE  */
#line 127 "parser.y"
                             {
    if(yybye) cout<<"LINE 119";
    Node* n = create_node("newline_stat_rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
  }
#line 2093 "parser.cpp"
    break;

  case 5: /* newline_stat_rep: newline_stat_rep stmt  */
#line 135 "parser.y"
                          { 
    if(yybye) cout<<"LINE 126";
    Node* n = create_node("newline_stat_rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));
  }
#line 2107 "parser.cpp"
    break;

  case 6: /* newline_stat_rep: stmt  */
#line 144 "parser.y"
         { (yyval.node) = (yyvsp[0].node) ; if(yybye) cout<<"LINE 132"; (yyval.node) = (yyvsp[0].node);}
#line 2113 "parser.cpp"
    break;

  case 7: /* newline_stat_rep: NEWLINE  */
#line 145 "parser.y"
            {  if(yybye) cout<<"LINE 133"; cout<<yylineno<<endl;}
#line 2119 "parser.cpp"
    break;

  case 8: /* funcname: DEF NAME  */
#line 147 "parser.y"
                    {
            Node* n = create_node((yyvsp[0].node)->label);
            n->children.push_back((yyvsp[-1].node));
            n->children.push_back((yyvsp[0].node));
            (yyval.node) = n;
            (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
            if(tab->SYMVAL.find((yyvsp[0].node)->label)== tab->SYMVAL.end()){
                tab->SYMVAL[(yyvsp[0].node)->label].identity=FUNC;
                tab->SYMVAL[(yyvsp[0].node)->label].scope=curr_scope;
                tab->SYMVAL[(yyvsp[0].node)->label].line_no=(yyvsp[-1].node)->line_number;
              //  cout<<tab->SYMVAL[$2->label].name<<endl;
               SYMTAB* newtab=new SYMTAB();
               newtab->SYMSCOPE=++curr_scope;
               newtab->parent=tab;
               tab->childs.push_back(newtab);
               tab=newtab;
             }
             else {
              cout<<"Function redeclared in line no "<< (yyvsp[0].node)->line_number<<endl;
              exit(1);
             }
            // cout<<"funcname "<<$1->line_number<<endl;
          }
#line 2147 "parser.cpp"
    break;

  case 9: /* funcdef: funcname parameters ARROW test COLON suite  */
#line 172 "parser.y"
                                                      {
             Node* n = create_node("Function");
             n->children.push_back((yyvsp[-5].node));
             n->children.push_back((yyvsp[-4].node));
             n->children.push_back((yyvsp[-3].node));
             n->children.push_back((yyvsp[-2].node));
             n->children.push_back((yyvsp[-1].node));
             n->children.push_back((yyvsp[0].node));
             (yyval.node) =n;
             tab=tab->parent;
             if(tab->SYMVAL.find((yyvsp[-5].node)->label)!= tab->SYMVAL.end()){
                tab->SYMVAL[(yyvsp[-5].node)->label].identity=FUNC;
                tab->SYMVAL[(yyvsp[-5].node)->label].scope=curr_scope;
                tab->SYMVAL[(yyvsp[-5].node)->label].line_no=(yyvsp[-5].node)->line_number;
                tab->SYMVAL[(yyvsp[-5].node)->label].type=(yyvsp[-2].node)->type;
                tab->SYMVAL[(yyvsp[-5].node)->label].name=(yyvsp[-5].node)->label;
                tab->SYMVAL[(yyvsp[-5].node)->label].size=(yyvsp[-4].node)->count;
                //int g_index;
                //int reg_name;
                for(int i=0;i<(yyvsp[-3].node)->children.size();i++){
                  Node* t=(yyvsp[-3].node)->children[i];
                  string temp=t->label;
                   if(temp!="[" && temp!="]"){
                      tab->SYMVAL[(yyvsp[-4].node)->label].params=(yyvsp[-3].node)->p_f;
                   }
                }
              
             }

             else{
              cout<<"error";
              exit(0);
             }
            //  cout<<$1->line_number<<endl;
              if(YYDEB) cout<<(yyvsp[-2].node)->type <<" "<<(yyvsp[0].node)->type<<endl;
             check_type((yyvsp[-2].node)->type , (yyvsp[0].node)->type , (yyvsp[-5].node)->line_number);

         }
#line 2190 "parser.cpp"
    break;

  case 10: /* funcdef: funcname parameters COLON suite  */
#line 210 "parser.y"
                                         {
             Node* n = create_node("Function");
             n->children.push_back((yyvsp[-3].node));
             n->children.push_back((yyvsp[-2].node));
             n->children.push_back((yyvsp[-1].node));
             n->children.push_back((yyvsp[0].node));
             (yyval.node) =n;
             tab=tab->parent;
             if(tab!=NULL){

               if(tab->SYMVAL.find((yyvsp[-3].node)->label)!= tab->SYMVAL.end()){
                  tab->SYMVAL[(yyvsp[-3].node)->label].identity=FUNC;
                  tab->SYMVAL[(yyvsp[-3].node)->label].scope=curr_scope;
                  tab->SYMVAL[(yyvsp[-3].node)->label].line_no=(yyvsp[-3].node)->line_number;
                  tab->SYMVAL[(yyvsp[-3].node)->label].type="void";
                  tab->SYMVAL[(yyvsp[-3].node)->label].name=(yyvsp[-3].node)->label;
                  tab->SYMVAL[(yyvsp[-3].node)->label].size=(yyvsp[-2].node)->count;
                  //int g_index;
                  //int reg_name;
                  for(int i=0;i<(yyvsp[-1].node)->children.size();i++){
                    Node* t=(yyvsp[-1].node)->children[i];
                    string temp=t->label;
                     if(temp!="[" && temp!="]"){
                        tab->SYMVAL[(yyvsp[-2].node)->label].params=(yyvsp[-1].node)->p_f;
                     }
                  }

               }
               else{
                cout<<"error";
                exit(0);
               }
             check_type("void" , (yyvsp[0].node)->type , (yyvsp[-3].node)->line_number);
              if(YYDEB) cout<<(yyvsp[0].node)->label <<" "<<endl;
             }
             
         }
#line 2232 "parser.cpp"
    break;

  case 11: /* parameters: LPAREN typedargslist RPAREN  */
#line 249 "parser.y"
                                         {
                Node* n = create_node("Parameters");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                n->children.push_back((yyvsp[0].node));
                n->count=(yyvsp[-1].node)->count;
                n->p_f=(yyvsp[-1].node)->p_f;
                (yyval.node)=n;
            }
#line 2246 "parser.cpp"
    break;

  case 12: /* parameters: LPAREN RPAREN  */
#line 258 "parser.y"
                           {
                (yyval.node) = create_node("Parameters");
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 2256 "parser.cpp"
    break;

  case 13: /* typedargslist: NAME  */
#line 265 "parser.y"
                     {
                  Node *n = create_node("Typedargslist");
                  n->children.push_back((yyvsp[0].node));
                  Param* temp=new Param();
                  temp->par_name=(yyvsp[0].node)->label;
                  n->p_f.push_back(temp);
                  n->count=1;
                  (yyval.node)=n;
                  }
#line 2270 "parser.cpp"
    break;

  case 14: /* typedargslist: NAME COLON datatype  */
#line 274 "parser.y"
                                       {
                  if(yybye) cout<<"LINE 188";
                  Node *n = create_node("Typedargslist");
                  n->children.push_back((yyvsp[-2].node));
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  n->count=1;
                  Param* temp=new Param();
                  temp->par_type=(yyvsp[0].node)->label;
                  temp->par_name=(yyvsp[-2].node)->label;
                  n->p_f.push_back(temp);
                if(tab->SYMVAL.find((yyvsp[-2].node)->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared"<<(yyvsp[-2].node)->label<<endl;
                  return 0;
                }
                 tab->SYMVAL[(yyvsp[-2].node)->label].identity=NORMIE;
                  tab->SYMVAL[(yyvsp[-2].node)->label].scope=curr_scope;
                  tab->SYMVAL[(yyvsp[-2].node)->label].line_no=(yyvsp[-2].node)->line_number;
                  tab->SYMVAL[(yyvsp[-2].node)->label].type=(yyvsp[0].node)->label;
                  tab->SYMVAL[(yyvsp[-2].node)->label].name=(yyvsp[-2].node)->label;
                  tab->SYMVAL[(yyvsp[-2].node)->label].size=0;
                  (yyval.node) = n;
                }
#line 2298 "parser.cpp"
    break;

  case 15: /* typedargslist: NAME COMMA typedargslist  */
#line 297 "parser.y"
                                         {
                  if(yybye) cout<<"LINE 196";
                  Node *n = create_node("Typedargslist");
                  n->children.push_back((yyvsp[-2].node));
                  n->children.push_back((yyvsp[-1].node));
                  for(int i=0; i<(yyvsp[0].node)->children.size(); i++) {
                    n->children.push_back((yyvsp[0].node)->children[i]);
                  }
                  (yyval.node) = n;
                  n->count=1+(yyvsp[0].node)->count;
                  Param* temp=new Param();
                  temp->par_type=(yyvsp[-2].node)->label;
                  vector<Param*> t2;
                  t2.push_back(temp);
                  t2.insert(t2.end(),(yyvsp[0].node)->p_f.begin(),(yyvsp[0].node)->p_f.end());
                  n->p_f=t2;
                }
#line 2320 "parser.cpp"
    break;

  case 16: /* typedargslist: NAME COLON datatype COMMA typedargslist  */
#line 314 "parser.y"
                                                        {
                  if(yybye) cout<<"LINE 203";
                  Node *n = create_node("Typedargslist");
                  n->children.push_back((yyvsp[-4].node));
                  n->children.push_back((yyvsp[-3].node));
                  n->children.push_back((yyvsp[-2].node));
                  n->children.push_back((yyvsp[-1].node));
                  for(int i=0; i<(yyvsp[0].node)->children.size(); i++) {
                    n->children.push_back((yyvsp[0].node)->children[i]);
                  }
                  (yyval.node) = n;
                  n->count=1+(yyvsp[0].node)->count;
                  Param* temp=new Param();
                  temp->par_type=(yyvsp[-2].node)->label;
                  temp->par_name=(yyvsp[-4].node)->label;
                  vector<Param*> t2;
                  t2.push_back(temp);
                  t2.insert(t2.end(),(yyvsp[-2].node)->p_f.begin(),(yyvsp[-2].node)->p_f.end());
                  n->p_f=t2;
                  if(tab->SYMVAL.find((yyvsp[-4].node)->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared"<<(yyvsp[-4].node)->label<<endl;
                  return 0;
                }
                 tab->SYMVAL[(yyvsp[-4].node)->label].identity=NORMIE;
                  tab->SYMVAL[(yyvsp[-4].node)->label].scope=curr_scope;
                  tab->SYMVAL[(yyvsp[-4].node)->label].line_no=(yyvsp[-4].node)->line_number;
                  tab->SYMVAL[(yyvsp[-4].node)->label].type=(yyvsp[-2].node)->label;
                  tab->SYMVAL[(yyvsp[-4].node)->label].name=(yyvsp[-4].node)->label;
                  tab->SYMVAL[(yyvsp[-4].node)->label].size=0;
                  (yyval.node) = n;
                }
#line 2356 "parser.cpp"
    break;

  case 17: /* datatype: NAME  */
#line 347 "parser.y"
                {
              if(yybye) cout<<"LINE 215";
              Node *n = create_node("Datatype");
              n->children.push_back((yyvsp[0].node));
              n->label=(yyvsp[0].node)->label;
              (yyval.node) = n;
            }
#line 2368 "parser.cpp"
    break;

  case 18: /* datatype: NAME LBRACKET NAME RBRACKET  */
#line 354 "parser.y"
                                       {
              if(yybye) cout<<"LINE 222";
              Node *n = create_node("Datatype");
              n->children.push_back((yyvsp[-3].node));
              n->children.push_back((yyvsp[-2].node));
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));
              n->label=(yyvsp[-3].node)->label+(yyvsp[-2].node)->label+(yyvsp[-1].node)->label+(yyvsp[0].node)->label;
              (yyval.node) = n;
            }
#line 2383 "parser.cpp"
    break;

  case 19: /* stmt: simple_stmt  */
#line 366 "parser.y"
                      { if(yybye) cout<<"LINE 231 \n";(yyval.node)=(yyvsp[0].node);}
#line 2389 "parser.cpp"
    break;

  case 20: /* stmt: compound_stmt  */
#line 367 "parser.y"
                       {if(yybye) cout<<"LINE 232 \n";(yyval.node)=(yyvsp[0].node);}
#line 2395 "parser.cpp"
    break;

  case 21: /* simple_stmt: small_stmt NEWLINE  */
#line 370 "parser.y"
                                {
              if(yybye) cout<<"LINE 235 \n";
               Node* n = create_node("simple_stmt");
               n->children.push_back((yyvsp[-1].node));
               (yyval.node)=n;
               (yyval.node)->type = (yyvsp[-1].node)->type;
            }
#line 2407 "parser.cpp"
    break;

  case 22: /* simple_stmt: small_stmt small_stmt_list NEWLINE  */
#line 377 "parser.y"
                                               {

                if(yybye) cout<<"LINE 241 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
              }
#line 2420 "parser.cpp"
    break;

  case 23: /* simple_stmt: small_stmt SEMICOLON NEWLINE  */
#line 385 "parser.y"
                                         {
                if(yybye) cout<<"LINE 242 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
              }
#line 2432 "parser.cpp"
    break;

  case 24: /* simple_stmt: small_stmt small_stmt_list SEMICOLON NEWLINE  */
#line 392 "parser.y"
                                                         {
                if(yybye) cout<<"LINE 243 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-3].node));
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));              
              }
#line 2444 "parser.cpp"
    break;

  case 25: /* small_stmt_list: small_stmt_list SEMICOLON small_stmt  */
#line 401 "parser.y"
                                                      {
                  if(yybye) cout<<"LINE 247 \n";
                  Node* n =create_node("small_stmt_list");
                  for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
                    n->children.push_back((yyvsp[-2].node)->children[i]);
                  }
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                }
#line 2459 "parser.cpp"
    break;

  case 26: /* small_stmt_list: SEMICOLON small_stmt  */
#line 411 "parser.y"
                                      {
                  if(yybye) cout<<"LINE 255 \n";
                  Node* n =create_node("small_stmt_list");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                }
#line 2471 "parser.cpp"
    break;

  case 27: /* small_stmt: expr_stmt  */
#line 419 "parser.y"
                      {if(yybye) cout<<"LINE 262 \n"; (yyval.node)=(yyvsp[0].node);}
#line 2477 "parser.cpp"
    break;

  case 28: /* small_stmt: del_stmt  */
#line 420 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2483 "parser.cpp"
    break;

  case 29: /* small_stmt: pass_stmt  */
#line 421 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2489 "parser.cpp"
    break;

  case 30: /* small_stmt: flow_stmt  */
#line 422 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2495 "parser.cpp"
    break;

  case 31: /* small_stmt: global_stmt  */
#line 423 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2501 "parser.cpp"
    break;

  case 32: /* expr_stmt: testlist_star_expr expr_stmt_tail  */
#line 425 "parser.y"
                                             { 
              Node* n =create_node("expr_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));
              if((yyvsp[0].node)->label=="annassign"){
                if(tab->SYMVAL.find((yyvsp[-1].node)->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared "<<(yyvsp[-1].node)->label<<endl;
                  cout<<endl;
                  // exit(1);
                }
                 tab->SYMVAL[(yyvsp[-1].node)->label].identity=NORMIE;
                  tab->SYMVAL[(yyvsp[-1].node)->label].scope=curr_scope;
                  tab->SYMVAL[(yyvsp[-1].node)->label].line_no=(yyvsp[-1].node)->line_number;
                  tab->SYMVAL[(yyvsp[-1].node)->label].type=(yyvsp[0].node)->type;
                  tab->SYMVAL[(yyvsp[-1].node)->label].name=(yyvsp[0].node)->label;
                  tab->SYMVAL[(yyvsp[-1].node)->label].size=0;
              }
              else if(tab->SYMVAL.find((yyvsp[-1].node)->label)!=tab->SYMVAL.end())
              {
                check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[-1].node)->line_number);
                // cout<<yylineno<<endl;
                // if($1->type != $2->type)
                // {
                //   cout<<"Different datatypes compared in line no "<<$1->line_no<<endl;
                //   exit(1);
                // }
              }
              (yyval.node)=n;
             }
#line 2535 "parser.cpp"
    break;

  case 33: /* expr_stmt: testlist_star_expr  */
#line 454 "parser.y"
                                 { (yyval.node) = (yyvsp[0].node);}
#line 2541 "parser.cpp"
    break;

  case 34: /* expr_stmt_tail: annassign  */
#line 457 "parser.y"
                           {
                  (yyval.node)=(yyvsp[0].node);
                  }
#line 2549 "parser.cpp"
    break;

  case 35: /* expr_stmt_tail: augassign augassign_op  */
#line 460 "parser.y"
                                        {
                  Node* n =create_node("expr_stmt_tail");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
               }
#line 2560 "parser.cpp"
    break;

  case 36: /* expr_stmt_tail: rep_expr_stmt_tail  */
#line 466 "parser.y"
                                   {
                   (yyval.node)=(yyvsp[0].node);
               }
#line 2568 "parser.cpp"
    break;

  case 37: /* augassign_op: yield_expr  */
#line 470 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2574 "parser.cpp"
    break;

  case 38: /* augassign_op: testlist  */
#line 471 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2580 "parser.cpp"
    break;

  case 39: /* rep_expr_stmt_tail: rep_expr_stmt_tail EQUAL_SIGN rep_expr_stmt_tail_op  */
#line 473 "parser.y"
                                                                         { 
                      Node* n =create_node("rep_expr_stmt_tail1");
                      for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
                        n->children.push_back((yyvsp[-2].node)->children[i]);
                      }
                      n->children.push_back((yyvsp[-1].node));
                      n->children.push_back((yyvsp[0].node));
                      (yyval.node)=n;
                     }
#line 2594 "parser.cpp"
    break;

  case 40: /* rep_expr_stmt_tail: EQUAL_SIGN rep_expr_stmt_tail_op  */
#line 482 "parser.y"
                                                      {
                      Node* n =create_node("rep_expr_stmt_tail2");
                      n->children.push_back((yyvsp[-1].node));
                      n->children.push_back((yyvsp[0].node));
                      (yyval.node)=n;
                      (yyval.node)->type = (yyvsp[0].node)->type;
                    }
#line 2606 "parser.cpp"
    break;

  case 41: /* rep_expr_stmt_tail_op: yield_expr  */
#line 490 "parser.y"
                                  {(yyval.node)=(yyvsp[0].node);}
#line 2612 "parser.cpp"
    break;

  case 42: /* rep_expr_stmt_tail_op: testlist_star_expr  */
#line 491 "parser.y"
                                          {(yyval.node)=(yyvsp[0].node);}
#line 2618 "parser.cpp"
    break;

  case 43: /* annassign: COLON test annasign_op  */
#line 493 "parser.y"
                                  {
                  Node* n =create_node("annassign");
                  n->children.push_back((yyvsp[-2].node));
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  n->type=(yyvsp[-1].node)->type;
                  (yyval.node)=n;
                 }
#line 2631 "parser.cpp"
    break;

  case 44: /* annassign: COLON test  */
#line 501 "parser.y"
                        {
                  Node* n =create_node("annassign");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  n->type=(yyvsp[0].node)->type;
                  (yyval.node)=n;
                 }
#line 2643 "parser.cpp"
    break;

  case 45: /* annasign_op: EQUAL_SIGN test  */
#line 509 "parser.y"
                             {
                  Node* n =create_node("annassign_op");
                   n->children.push_back((yyvsp[-1].node));
                   n->children.push_back((yyvsp[0].node));
}
#line 2653 "parser.cpp"
    break;

  case 46: /* annasign_op: EQUAL_SIGN  */
#line 514 "parser.y"
                         { (yyval.node)=(yyvsp[0].node);}
#line 2659 "parser.cpp"
    break;

  case 47: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep COMMA  */
#line 516 "parser.y"
                                                                         {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-2].node));
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                     (yyval.node)=n;
                    }
#line 2671 "parser.cpp"
    break;

  case 48: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep  */
#line 523 "parser.y"
                                                                   { 
                      Node* n =create_node("testlist_star_expr");
                      n->children.push_back((yyvsp[-1].node));
                      n->children.push_back((yyvsp[0].node));
                    }
#line 2681 "parser.cpp"
    break;

  case 49: /* testlist_star_expr: testlist_star_expr_opt1 COMMA  */
#line 528 "parser.y"
                                                  {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                    }
#line 2691 "parser.cpp"
    break;

  case 50: /* testlist_star_expr: testlist_star_expr_opt1  */
#line 533 "parser.y"
                                             { (yyval.node) = (yyvsp[0].node);}
#line 2697 "parser.cpp"
    break;

  case 51: /* testlist_star_expr_opt1: test  */
#line 537 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2703 "parser.cpp"
    break;

  case 52: /* testlist_star_expr_opt1: star_expr  */
#line 538 "parser.y"
                                   {(yyval.node)=(yyvsp[0].node);}
#line 2709 "parser.cpp"
    break;

  case 53: /* testlist_star_expr_rep: testlist_star_expr_rep COMMA testlist_star_expr_opt1  */
#line 541 "parser.y"
                                                          {
      Node* n =create_node("testlist_star_expr_rep");
      for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
        n->children.push_back((yyvsp[-2].node)->children[i]);
      }
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n;
  }
#line 2723 "parser.cpp"
    break;

  case 54: /* testlist_star_expr_rep: COMMA testlist_star_expr_opt1  */
#line 550 "parser.y"
                                  {(yyval.node) = NULL;}
#line 2729 "parser.cpp"
    break;

  case 55: /* augassign: PLUS_EQUAL  */
#line 552 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2735 "parser.cpp"
    break;

  case 56: /* augassign: MINUS_EQUAL  */
#line 553 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2741 "parser.cpp"
    break;

  case 57: /* augassign: TIMES_EQUAL  */
#line 554 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2747 "parser.cpp"
    break;

  case 58: /* augassign: AT_EQUAL  */
#line 555 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2753 "parser.cpp"
    break;

  case 59: /* augassign: DIVIDEDBY_EQUAL  */
#line 556 "parser.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2759 "parser.cpp"
    break;

  case 60: /* augassign: MODULO_EQUAL  */
#line 557 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2765 "parser.cpp"
    break;

  case 61: /* augassign: BITWISE_AND_EQUAL  */
#line 558 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2771 "parser.cpp"
    break;

  case 62: /* augassign: BITWISE_OR_EQUAL  */
#line 559 "parser.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 2777 "parser.cpp"
    break;

  case 63: /* augassign: BITWISE_XOR_EQUAL  */
#line 560 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2783 "parser.cpp"
    break;

  case 64: /* augassign: SHIFT_LEFT_EQUAL  */
#line 561 "parser.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 2789 "parser.cpp"
    break;

  case 65: /* augassign: SHIFT_RIGHT_EQUAL  */
#line 562 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2795 "parser.cpp"
    break;

  case 66: /* augassign: POWER_EQUAL  */
#line 563 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2801 "parser.cpp"
    break;

  case 67: /* augassign: FLOORDIV_EQUAL  */
#line 564 "parser.y"
                           {(yyval.node)=(yyvsp[0].node);}
#line 2807 "parser.cpp"
    break;

  case 68: /* del_stmt: DEL exprlist  */
#line 567 "parser.y"
                      {Node* n =create_node("del_stmt");
                         n->children.push_back((yyvsp[-1].node));
                         n->children.push_back((yyvsp[0].node));
                         (yyval.node)=n;
                          }
#line 2817 "parser.cpp"
    break;

  case 69: /* pass_stmt: PASS  */
#line 573 "parser.y"
               {(yyval.node)=(yyvsp[0].node);}
#line 2823 "parser.cpp"
    break;

  case 70: /* flow_stmt: break_stmt  */
#line 575 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2829 "parser.cpp"
    break;

  case 71: /* flow_stmt: continue_stmt  */
#line 576 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2835 "parser.cpp"
    break;

  case 72: /* flow_stmt: return_stmt  */
#line 577 "parser.y"
                       {(yyval.node)=(yyvsp[0].node); }
#line 2841 "parser.cpp"
    break;

  case 73: /* flow_stmt: yield_stmt  */
#line 578 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2847 "parser.cpp"
    break;

  case 74: /* break_stmt: BREAK  */
#line 581 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 2853 "parser.cpp"
    break;

  case 75: /* continue_stmt: CONTINUE  */
#line 583 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2859 "parser.cpp"
    break;

  case 76: /* return_stmt: RETURN testlist  */
#line 584 "parser.y"
                            {
              Node* n =create_node("return_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n; 
              (yyval.node)->type = (yyvsp[0].node)->type;
              if(YYDEB) cout<<"return_stmt" <<" "<<(yyvsp[0].node)->type<<endl;
            }
#line 2872 "parser.cpp"
    break;

  case 77: /* return_stmt: RETURN  */
#line 592 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "void";}
#line 2878 "parser.cpp"
    break;

  case 78: /* yield_stmt: yield_expr  */
#line 594 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2884 "parser.cpp"
    break;

  case 79: /* global_stmt: GLOBAL global_name_list  */
#line 595 "parser.y"
                                    {
              Node* n =create_node("global_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n; 
            }
#line 2895 "parser.cpp"
    break;

  case 80: /* global_name_list: global_name_list COMMA NAME  */
#line 602 "parser.y"
                                              {
                  Node* n =create_node("global_name_list");
                  for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
                    n->children.push_back((yyvsp[-2].node)->children[i]);
                  }
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  
                  (yyval.node)=n;
                }
#line 2910 "parser.cpp"
    break;

  case 81: /* global_name_list: NAME  */
#line 612 "parser.y"
                       { (yyval.node) = (yyvsp[0].node);}
#line 2916 "parser.cpp"
    break;

  case 82: /* compound_stmt: if_stmt  */
#line 614 "parser.y"
                       {if(yybye) cout<<"cmpd_stmnt 1 \n"; (yyval.node)=(yyvsp[0].node);}
#line 2922 "parser.cpp"
    break;

  case 83: /* compound_stmt: while_stmt  */
#line 615 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2928 "parser.cpp"
    break;

  case 84: /* compound_stmt: for_stmt  */
#line 616 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2934 "parser.cpp"
    break;

  case 85: /* compound_stmt: funcdef  */
#line 617 "parser.y"
                       {if(yybye) cout<<"cmpd_stmnt \n"; (yyval.node)=(yyvsp[0].node);}
#line 2940 "parser.cpp"
    break;

  case 86: /* compound_stmt: classdef  */
#line 618 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2946 "parser.cpp"
    break;

  case 87: /* compound_stmt: async_stmt  */
#line 619 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2952 "parser.cpp"
    break;

  case 91: /* if_stmt: IF test COLON suite elif_stmt_rep ELSE COLON suite  */
#line 629 "parser.y"
                                                            {
    if(yybye) cout<<" if_stmt: \n";
    Node* n=create_node("if_stmt");
    n->children.push_back((yyvsp[-7].node));
    n->children.push_back((yyvsp[-6].node)); 
    n->children.push_back((yyvsp[-5].node));
    n->children.push_back((yyvsp[-4].node)); 
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node)); 
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node)); 
    (yyval.node)=n;
  }
#line 2970 "parser.cpp"
    break;

  case 92: /* if_stmt: IF test COLON suite elif_stmt_rep  */
#line 642 "parser.y"
                                       {

      if(yybye) cout<<"if_stmt 2: \n"; 
      Node* n=create_node("if_stmt");
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node)); 
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node)); 
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n;
  }
#line 2986 "parser.cpp"
    break;

  case 93: /* if_stmt: IF test COLON suite ELSE COLON suite  */
#line 653 "parser.y"
                                          { 
      Node* n=create_node("if_stmt");
      n->children.push_back((yyvsp[-6].node));
      n->children.push_back((yyvsp[-5].node)); 
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node)); 
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node)); 
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n;
    }
#line 3002 "parser.cpp"
    break;

  case 94: /* if_stmt: IF test COLON suite  */
#line 664 "parser.y"
                         { 
      Node* n=create_node("if_stmt");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
    }
#line 3015 "parser.cpp"
    break;

  case 95: /* elif_stmt_rep: elif_stmt_rep ELIF test COLON suite  */
#line 673 "parser.y"
                                                    {
      Node* n=create_node("elif_stmt_rep");
      for(int i=0; i<(yyvsp[-4].node)->children.size(); i++){
        n->children.push_back((yyvsp[-4].node)->children[i]);
      }
      n->children.push_back((yyvsp[-3].node)); 
      n->children.push_back((yyvsp[-2].node));
       n->children.push_back((yyvsp[-1].node)); 
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n; 
    }
#line 3031 "parser.cpp"
    break;

  case 96: /* elif_stmt_rep: ELIF test COLON suite  */
#line 684 "parser.y"
                           { 
      Node* n=create_node("elif_stmt_rep");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
    }
#line 3044 "parser.cpp"
    break;

  case 97: /* while_stmt: WHILE test COLON suite ELSE COLON suite  */
#line 693 "parser.y"
                                                   {
      Node* n=create_node("while_stmt");
      n->children.push_back((yyvsp[-6].node));
      n->children.push_back((yyvsp[-5].node)); 
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node)); 
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n; 
    }
#line 3060 "parser.cpp"
    break;

  case 98: /* while_stmt: WHILE test COLON suite  */
#line 704 "parser.y"
                           { 
      Node* n=create_node("while_stmt");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
  }
#line 3073 "parser.cpp"
    break;

  case 99: /* for_stmt: FOR exprlist IN testlist COLON suite ELSE COLON suite  */
#line 713 "parser.y"
                                                               {
      Node* n=create_node("for_stmt");
      n->children.push_back((yyvsp[-8].node));
      n->children.push_back((yyvsp[-7].node)); 
      n->children.push_back((yyvsp[-6].node));
      n->children.push_back((yyvsp[-5].node)); 
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n; 
    }
#line 3091 "parser.cpp"
    break;

  case 100: /* for_stmt: FOR exprlist IN testlist COLON suite  */
#line 726 "parser.y"
                                           {
      Node* n=create_node("while_stmt");
      n->children.push_back((yyvsp[-5].node));
      n->children.push_back((yyvsp[-4].node)); 
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n;
    }
#line 3106 "parser.cpp"
    break;

  case 101: /* suite: simple_stmt  */
#line 737 "parser.y"
                    {if(yybye) cout<<"LINE 462 \n"; (yyval.node) = (yyvsp[0].node);}
#line 3112 "parser.cpp"
    break;

  case 102: /* suite: NEWLINE INDENT stmt_rep DEDENT  */
#line 738 "parser.y"
                                      {
        Node* n = create_node("Suite");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-2].node));
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        (yyval.node)->type = (yyvsp[-1].node)->type;
        if(YYDEB) cout<<"suite" <<(yyvsp[-1].node)->type <<endl;

      }
#line 3127 "parser.cpp"
    break;

  case 103: /* stmt_rep: stmt_rep stmt  */
#line 750 "parser.y"
                           {
            Node* n = create_node("Multi Statements");
            (yyval.node) = n;
            for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
              n->children.push_back((yyvsp[-1].node)->children[i]);
            }
            n->children.push_back((yyvsp[0].node));
            (yyval.node)->type = (yyvsp[0].node)->type;
            if(YYDEB) cout<<(yyvsp[0].node)->type<<" stmt_rep"<<endl;
          }
#line 3142 "parser.cpp"
    break;

  case 104: /* stmt_rep: stmt  */
#line 760 "parser.y"
                 {(yyval.node)=(yyvsp[0].node); }
#line 3148 "parser.cpp"
    break;

  case 105: /* test: or_test IF or_test ELSE test  */
#line 762 "parser.y"
                                    {
      Node* n = create_node("Test");
      (yyval.node) = n;
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
}
#line 3162 "parser.cpp"
    break;

  case 106: /* test: or_test  */
#line 771 "parser.y"
         {(yyval.node)=(yyvsp[0].node);}
#line 3168 "parser.cpp"
    break;

  case 107: /* test_nocond: or_test  */
#line 774 "parser.y"
          {(yyval.node) = (yyvsp[0].node);}
#line 3174 "parser.cpp"
    break;

  case 108: /* or_test: and_test or_test_rep  */
#line 778 "parser.y"
  {
    Node* n = create_node("OR Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3185 "parser.cpp"
    break;

  case 109: /* or_test: and_test  */
#line 784 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3191 "parser.cpp"
    break;

  case 110: /* or_test_rep: or_test_rep OR and_test  */
#line 787 "parser.y"
                           {
    Node* n = create_node("ORTestRep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3205 "parser.cpp"
    break;

  case 111: /* or_test_rep: OR and_test  */
#line 796 "parser.y"
               {Node* n = create_node("ORTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3214 "parser.cpp"
    break;

  case 112: /* and_test: not_test and_test_rep  */
#line 802 "parser.y"
                       {
    Node* n = create_node("And Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3225 "parser.cpp"
    break;

  case 113: /* and_test: not_test  */
#line 808 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3231 "parser.cpp"
    break;

  case 114: /* and_test_rep: and_test_rep AND not_test  */
#line 812 "parser.y"
  {
    Node* n = create_node("AndTestRep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3245 "parser.cpp"
    break;

  case 115: /* and_test_rep: AND not_test  */
#line 821 "parser.y"
                {Node* n = create_node("AndTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3254 "parser.cpp"
    break;

  case 116: /* not_test: NOT not_test  */
#line 829 "parser.y"
  {
    Node* n = create_node("Not Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3265 "parser.cpp"
    break;

  case 117: /* not_test: comparison  */
#line 835 "parser.y"
               {
    (yyval.node) =(yyvsp[0].node);
  }
#line 3273 "parser.cpp"
    break;

  case 118: /* comparison: expr comparison_rep  */
#line 840 "parser.y"
                     {
    Node* n = create_node("Comparison");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[-1].node)->line_number);
    // if($1->type != $2->type){
    //   diff_data($1->line_no);
    //   exit(1);
    // }
    (yyval.node)->type = (yyvsp[-1].node)->type;

  }
#line 3291 "parser.cpp"
    break;

  case 119: /* comparison: expr  */
#line 853 "parser.y"
       {(yyval.node)=(yyvsp[0].node);}
#line 3297 "parser.cpp"
    break;

  case 120: /* comparison_rep: comparison_rep comp_op expr  */
#line 857 "parser.y"
                              {
    Node* n = create_node("Comparison Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3311 "parser.cpp"
    break;

  case 121: /* comparison_rep: comp_op expr  */
#line 866 "parser.y"
                {
   Node* n = create_node("Comparison Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
 }
#line 3323 "parser.cpp"
    break;

  case 122: /* comp_op: LESS_THAN  */
#line 874 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 3329 "parser.cpp"
    break;

  case 123: /* comp_op: GREATER_THAN  */
#line 875 "parser.y"
                      {(yyval.node) =(yyvsp[0].node);}
#line 3335 "parser.cpp"
    break;

  case 124: /* comp_op: EQUAL  */
#line 876 "parser.y"
               {(yyval.node) =(yyvsp[0].node);}
#line 3341 "parser.cpp"
    break;

  case 125: /* comp_op: GREATER_THAN_OR_EQUAL  */
#line 877 "parser.y"
                               {(yyval.node) =(yyvsp[0].node);}
#line 3347 "parser.cpp"
    break;

  case 126: /* comp_op: LESS_THAN_OR_EQUAL  */
#line 878 "parser.y"
                            {(yyval.node) =(yyvsp[0].node);}
#line 3353 "parser.cpp"
    break;

  case 127: /* comp_op: NOT_EQUAL  */
#line 879 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 3359 "parser.cpp"
    break;

  case 128: /* comp_op: IN  */
#line 880 "parser.y"
            {(yyval.node) =(yyvsp[0].node);}
#line 3365 "parser.cpp"
    break;

  case 129: /* comp_op: NOT IN  */
#line 881 "parser.y"
                {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3376 "parser.cpp"
    break;

  case 130: /* comp_op: IS  */
#line 887 "parser.y"
            {(yyval.node) =(yyvsp[0].node);}
#line 3382 "parser.cpp"
    break;

  case 131: /* comp_op: IS NOT  */
#line 888 "parser.y"
               {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3393 "parser.cpp"
    break;

  case 132: /* star_expr: TIMES expr  */
#line 896 "parser.y"
            {
    Node* n = create_node("Star Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3404 "parser.cpp"
    break;

  case 133: /* expr: xor_expr expr_rep  */
#line 904 "parser.y"
                   {
    Node* n = create_node("Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3415 "parser.cpp"
    break;

  case 134: /* expr: xor_expr  */
#line 910 "parser.y"
            {(yyval.node)=(yyvsp[0].node);}
#line 3421 "parser.cpp"
    break;

  case 135: /* expr_rep: expr_rep BITWISE_OR xor_expr  */
#line 913 "parser.y"
                               {
    Node* n = create_node("Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3435 "parser.cpp"
    break;

  case 136: /* expr_rep: BITWISE_OR xor_expr  */
#line 922 "parser.y"
                       {Node* n = create_node("Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3444 "parser.cpp"
    break;

  case 137: /* xor_expr: and_expr xor_expr_rep  */
#line 928 "parser.y"
                       {
    Node* n = create_node("XOR Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3455 "parser.cpp"
    break;

  case 138: /* xor_expr: and_expr  */
#line 934 "parser.y"
            {
    (yyval.node)=(yyvsp[0].node);
  }
#line 3463 "parser.cpp"
    break;

  case 139: /* xor_expr_rep: xor_expr_rep BITWISE_XOR and_expr  */
#line 939 "parser.y"
                                    {
    Node* n = create_node("XOR Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3477 "parser.cpp"
    break;

  case 140: /* xor_expr_rep: BITWISE_XOR and_expr  */
#line 948 "parser.y"
                       {Node* n = create_node("XOR Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3486 "parser.cpp"
    break;

  case 141: /* and_expr: shift_expr and_expr_rep  */
#line 954 "parser.y"
                         {
    Node* n = create_node("AND Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3497 "parser.cpp"
    break;

  case 142: /* and_expr: shift_expr  */
#line 960 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3503 "parser.cpp"
    break;

  case 143: /* and_expr_rep: and_expr_rep BITWISE_AND shift_expr  */
#line 963 "parser.y"
                                      {
    Node* n = create_node("AND Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node)); 
  }
#line 3517 "parser.cpp"
    break;

  case 144: /* and_expr_rep: BITWISE_AND shift_expr  */
#line 972 "parser.y"
                         {Node* n = create_node("AND Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node)); }
#line 3526 "parser.cpp"
    break;

  case 145: /* shift_expr: arith_expr shift_expr_rep  */
#line 978 "parser.y"
                           {
    Node* n = create_node("Shift Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3537 "parser.cpp"
    break;

  case 146: /* shift_expr: arith_expr  */
#line 984 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3543 "parser.cpp"
    break;

  case 147: /* shift_expr_rep: shift_expr_rep shift_expr_rep_c1 arith_expr  */
#line 987 "parser.y"
                                              {
    Node* n = create_node("Shift Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3557 "parser.cpp"
    break;

  case 148: /* shift_expr_rep: shift_expr_rep_c1 arith_expr  */
#line 996 "parser.y"
                                {Node* n = create_node("Shift Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3566 "parser.cpp"
    break;

  case 149: /* shift_expr_rep_c1: SHIFT_LEFT  */
#line 1002 "parser.y"
            {
    (yyval.node) = (yyvsp[0].node);
  }
#line 3574 "parser.cpp"
    break;

  case 150: /* shift_expr_rep_c1: SHIFT_RIGHT  */
#line 1005 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 3580 "parser.cpp"
    break;

  case 151: /* arith_expr: term arith_expr_rep  */
#line 1008 "parser.y"
                     {
    Node* n = create_node("Arithmetic Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[-1].node)->line_number);
    // if($1->type != $2->type)
    // {
    //   diff_data($1->line_no);
    //   exit(1);
    // }
    (yyval.node)->type = (yyvsp[-1].node)->type;
  }
#line 3598 "parser.cpp"
    break;

  case 152: /* arith_expr: term  */
#line 1021 "parser.y"
        { if(yybye) cout<<"term arith_expr: "<<endl;(yyval.node)=(yyvsp[0].node);}
#line 3604 "parser.cpp"
    break;

  case 153: /* arith_expr_rep: arith_expr_rep arith_expr_rep_c1 term  */
#line 1024 "parser.y"
                                        {
    Node* n = create_node("Arithmetic Expression Rep1");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3616 "parser.cpp"
    break;

  case 154: /* arith_expr_rep: arith_expr_rep_c1 term  */
#line 1031 "parser.y"
                         {Node* n = create_node("Arithmetic Expression Rep2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 3627 "parser.cpp"
    break;

  case 155: /* arith_expr_rep_c1: PLUS  */
#line 1039 "parser.y"
       { (yyval.node) = (yyvsp[0].node);}
#line 3633 "parser.cpp"
    break;

  case 156: /* arith_expr_rep_c1: MINUS  */
#line 1040 "parser.y"
          { (yyval.node) = (yyvsp[0].node);}
#line 3639 "parser.cpp"
    break;

  case 157: /* term: factor term_rep  */
#line 1043 "parser.y"
                 {
    if(yybye) cout<<"term factor term_rep: "<<endl;
    Node* n = create_node("TERM");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[-1].node)->line_number);
    // if($1->type != $2->type)
    // {
    //   diff_data($1->line_no);
    //   exit(1);
    // }
    (yyval.node)->type = (yyvsp[-1].node)->type;
  }
#line 3658 "parser.cpp"
    break;

  case 158: /* term: factor  */
#line 1057 "parser.y"
         {if(yybye) cout<<"factor term: "<<endl;(yyval.node)=(yyvsp[0].node);}
#line 3664 "parser.cpp"
    break;

  case 159: /* term_rep: term_rep term_rep_c1 factor  */
#line 1060 "parser.y"
                               {
    Node* n = create_node("TERM Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3678 "parser.cpp"
    break;

  case 160: /* term_rep: term_rep_c1 factor  */
#line 1069 "parser.y"
                       { Node* n = create_node("TERM Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 3689 "parser.cpp"
    break;

  case 161: /* term_rep_c1: TIMES  */
#line 1076 "parser.y"
                    { (yyval.node) =(yyvsp[0].node);}
#line 3695 "parser.cpp"
    break;

  case 162: /* term_rep_c1: AT  */
#line 1077 "parser.y"
                 { (yyval.node) =(yyvsp[0].node);}
#line 3701 "parser.cpp"
    break;

  case 163: /* term_rep_c1: DIVIDEDBY  */
#line 1078 "parser.y"
                        { (yyval.node) =(yyvsp[0].node);}
#line 3707 "parser.cpp"
    break;

  case 164: /* term_rep_c1: MODULO  */
#line 1079 "parser.y"
                     { (yyval.node) =(yyvsp[0].node);}
#line 3713 "parser.cpp"
    break;

  case 165: /* term_rep_c1: FLOORDIV  */
#line 1080 "parser.y"
                       { (yyval.node) =(yyvsp[0].node);}
#line 3719 "parser.cpp"
    break;

  case 166: /* factor: factor_c1 factor  */
#line 1083 "parser.y"
                   {
    Node* n = create_node("Factor");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3730 "parser.cpp"
    break;

  case 167: /* factor: power  */
#line 1089 "parser.y"
          { if(yybye) cout<<"factor power: "<<endl;(yyval.node) = (yyvsp[0].node);}
#line 3736 "parser.cpp"
    break;

  case 168: /* factor_c1: PLUS  */
#line 1091 "parser.y"
                 { (yyval.node) =(yyvsp[0].node);}
#line 3742 "parser.cpp"
    break;

  case 169: /* factor_c1: MINUS  */
#line 1092 "parser.y"
                  { (yyval.node) =(yyvsp[0].node);}
#line 3748 "parser.cpp"
    break;

  case 170: /* factor_c1: BITWISE_NOT  */
#line 1093 "parser.y"
                        { (yyval.node) =(yyvsp[0].node);}
#line 3754 "parser.cpp"
    break;

  case 171: /* power: atom_expr power_opt  */
#line 1096 "parser.y"
                     {
    Node* n = create_node("Power");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type , (yyvsp[-1].node)->line_number);
    (yyval.node)->type = (yyvsp[-1].node)->type;

  }
#line 3768 "parser.cpp"
    break;

  case 172: /* power: atom_expr  */
#line 1105 "parser.y"
             {
    (yyval.node) = (yyvsp[0].node);
    if(yybye) cout<<"atom_expr power: "<<endl;(yyval.node)=(yyvsp[0].node);
  }
#line 3777 "parser.cpp"
    break;

  case 173: /* power_opt: POWER factor  */
#line 1111 "parser.y"
               {
    Node* n = create_node("Power Opt");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 3789 "parser.cpp"
    break;

  case 174: /* atom_expr: await_opt atom trailer_rep  */
#line 1120 "parser.y"
                            {
    Node* n = create_node("Atom Expression1");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    n->type = (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
  }
#line 3802 "parser.cpp"
    break;

  case 175: /* atom_expr: atom trailer_rep  */
#line 1128 "parser.y"
                   {
    Node* n = create_node("Atom Expression2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    n->type = (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
    if(yybye) cout<<"atom trailer_rep atom_expr: "<<endl;
    

  }
#line 3817 "parser.cpp"
    break;

  case 176: /* atom_expr: atom  */
#line 1138 "parser.y"
       {
    (yyval.node) = (yyvsp[0].node);
    // cout<<"atom " <<$$->type<<endl;
    if(yybye) cout<<"atom_expr atom: "<<endl; 
  }
#line 3827 "parser.cpp"
    break;

  case 177: /* await_opt: AWAIT  */
#line 1144 "parser.y"
                  {
  (yyval.node) = (yyvsp[0].node);
}
#line 3835 "parser.cpp"
    break;

  case 178: /* trailer_rep: trailer_rep trailer  */
#line 1149 "parser.y"
                      {
    if(yybye) cout<<"trailer_rep: "<<endl;
    Node* n = create_node("Trailer Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));
  }
#line 3849 "parser.cpp"
    break;

  case 179: /* trailer_rep: trailer  */
#line 1158 "parser.y"
            { 
    (yyval.node) =(yyvsp[0].node);
  }
#line 3857 "parser.cpp"
    break;

  case 180: /* atom: LPAREN atom_opt1 RPAREN  */
#line 1162 "parser.y"
                               {
        if(yybye) cout<<"atom atom_opt1: "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-2].node));
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
      }
#line 3870 "parser.cpp"
    break;

  case 181: /* atom: LBRACKET atom_opt2 RBRACKET  */
#line 1170 "parser.y"
                                    {
        if(yybye) cout<<"atom atom_opt2: "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-2].node));
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
      }
#line 3883 "parser.cpp"
    break;

  case 182: /* atom: LBRACKET RBRACKET  */
#line 1178 "parser.y"
                         { 
        if(yybye) cout<<"atom : "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
      }
#line 3895 "parser.cpp"
    break;

  case 183: /* atom: NAME  */
#line 1185 "parser.y"
              { (yyval.node) =(yyvsp[0].node);
                if(tab->SYMVAL.find((yyvsp[0].node)->label)!=tab->SYMVAL.end())
                {
                  // cout<<"Already declared"<<endl;
                  (yyval.node)->type = tab->SYMVAL[(yyvsp[0].node)->label].type;
                  // cout<<$$->type<<endl;
                }
                else{

                if((yyvsp[0].node)->label == "int")
                  (yyval.node)->type = "int";
                else if((yyvsp[0].node)->label == "float")
                  (yyval.node)->type = "float";
                else if((yyvsp[0].node)->label == "str")
                  (yyval.node)->type = "str";
                else if((yyvsp[0].node)->label == "bool")
                  (yyval.node)->type = "bool";
                else if((yyvsp[0].node)->label == "len")
                  (yyval.node)->type = "int";
                }

      }
#line 3922 "parser.cpp"
    break;

  case 184: /* atom: NUMBER  */
#line 1207 "parser.y"
                { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "int";}
#line 3928 "parser.cpp"
    break;

  case 185: /* atom: FLOAT  */
#line 1208 "parser.y"
              {(yyval.node) = (yyvsp[0].node); (yyval.node)->type = "float";}
#line 3934 "parser.cpp"
    break;

  case 186: /* atom: string_rep  */
#line 1209 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "string";}
#line 3940 "parser.cpp"
    break;

  case 187: /* atom: TRIPLEDOT  */
#line 1210 "parser.y"
                   { (yyval.node) =(yyvsp[0].node);}
#line 3946 "parser.cpp"
    break;

  case 188: /* atom: NONE  */
#line 1211 "parser.y"
              { (yyval.node) =(yyvsp[0].node);}
#line 3952 "parser.cpp"
    break;

  case 189: /* atom: TRUE_TOKEN  */
#line 1212 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";}
#line 3958 "parser.cpp"
    break;

  case 190: /* atom: FALSE_TOKEN  */
#line 1213 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";}
#line 3964 "parser.cpp"
    break;

  case 191: /* atom_opt1: yield_expr  */
#line 1215 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 3970 "parser.cpp"
    break;

  case 192: /* atom_opt1: testlist_comp  */
#line 1216 "parser.y"
                         {(yyval.node) = (yyvsp[0].node); if(yybye) cout<<"atom_opt1 testlist_comp: "<<endl;}
#line 3976 "parser.cpp"
    break;

  case 193: /* atom_opt2: testlist_comp  */
#line 1218 "parser.y"
                         {(yyval.node) =(yyvsp[0].node);}
#line 3982 "parser.cpp"
    break;

  case 194: /* string_rep: STRING  */
#line 1221 "parser.y"
         { (yyval.node) = (yyvsp[0].node);}
#line 3988 "parser.cpp"
    break;

  case 195: /* string_rep: string_rep STRING  */
#line 1222 "parser.y"
                      {
    Node* n = create_node("String Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));    
  }
#line 4001 "parser.cpp"
    break;

  case 196: /* testlist_comp: testlist_comp_c1 testlist_comp_c2  */
#line 1232 "parser.y"
                                   {
    Node* n = create_node("Testlist comp");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4012 "parser.cpp"
    break;

  case 197: /* testlist_comp: testlist_comp_c1  */
#line 1238 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 4018 "parser.cpp"
    break;

  case 198: /* testlist_comp_c1: test  */
#line 1241 "parser.y"
         {(yyval.node) = (yyvsp[0].node);}
#line 4024 "parser.cpp"
    break;

  case 199: /* testlist_comp_c1: star_expr  */
#line 1242 "parser.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 4030 "parser.cpp"
    break;

  case 200: /* testlist_comp_c2: comp_for  */
#line 1245 "parser.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 4036 "parser.cpp"
    break;

  case 201: /* testlist_comp_c2: testlist_comp_c2_rep COMMA  */
#line 1246 "parser.y"
                              {
    Node* n = create_node("Testlist Comp C2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4047 "parser.cpp"
    break;

  case 202: /* testlist_comp_c2: COMMA  */
#line 1252 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 4053 "parser.cpp"
    break;

  case 203: /* testlist_comp_c2: testlist_comp_c2_rep  */
#line 1253 "parser.y"
                        {(yyval.node) =(yyvsp[0].node);}
#line 4059 "parser.cpp"
    break;

  case 204: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA test  */
#line 1257 "parser.y"
  {
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    for(int i = 0; i < (yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4073 "parser.cpp"
    break;

  case 205: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA star_expr  */
#line 1266 "parser.y"
                                        {
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    for(int i = 0; i < (yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4087 "parser.cpp"
    break;

  case 206: /* testlist_comp_c2_rep: COMMA test  */
#line 1275 "parser.y"
             {
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4098 "parser.cpp"
    break;

  case 207: /* testlist_comp_c2_rep: COMMA star_expr  */
#line 1281 "parser.y"
                    { 
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4109 "parser.cpp"
    break;

  case 208: /* trailer: LPAREN arglist RPAREN  */
#line 1289 "parser.y"
                       {
    if(yybye) cout<<"trailer: "<<endl;
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->parameters = (yyvsp[-1].node)->parameters;
  }
#line 4123 "parser.cpp"
    break;

  case 209: /* trailer: LPAREN RPAREN  */
#line 1298 "parser.y"
                {
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4134 "parser.cpp"
    break;

  case 210: /* trailer: LBRACKET subscriptlist RBRACKET  */
#line 1304 "parser.y"
                                    {
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[-2].node)->type + (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
  }
#line 4147 "parser.cpp"
    break;

  case 211: /* trailer: LBRACKET RBRACKET  */
#line 1312 "parser.y"
                    { 
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4158 "parser.cpp"
    break;

  case 212: /* trailer: DOT NAME  */
#line 1318 "parser.y"
            {
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4169 "parser.cpp"
    break;

  case 213: /* subscriptlist: subscript COMMA_subscript_rep COMMA_opt  */
#line 1326 "parser.y"
                                         {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4182 "parser.cpp"
    break;

  case 214: /* subscriptlist: subscript COMMA_opt  */
#line 1334 "parser.y"
                      {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4193 "parser.cpp"
    break;

  case 215: /* subscriptlist: subscript COMMA_subscript_rep  */
#line 1340 "parser.y"
                                {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4204 "parser.cpp"
    break;

  case 216: /* subscriptlist: subscript  */
#line 1346 "parser.y"
             {(yyval.node) =(yyvsp[0].node);}
#line 4210 "parser.cpp"
    break;

  case 217: /* COMMA_opt: COMMA  */
#line 1349 "parser.y"
        { (yyval.node) = (yyvsp[0].node);}
#line 4216 "parser.cpp"
    break;

  case 218: /* COMMA_subscript_rep: COMMA_subscript_rep COMMA subscript  */
#line 1353 "parser.y"
                                      {
    Node* n = create_node("Comma Subscript rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4230 "parser.cpp"
    break;

  case 219: /* COMMA_subscript_rep: COMMA subscript  */
#line 1362 "parser.y"
                   {
    Node* n = create_node("COMMA subscript rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4241 "parser.cpp"
    break;

  case 220: /* subscript: test  */
#line 1370 "parser.y"
       { (yyval.node) = (yyvsp[0].node);}
#line 4247 "parser.cpp"
    break;

  case 221: /* subscript: test COLON test sliceop  */
#line 1371 "parser.y"
                           {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4261 "parser.cpp"
    break;

  case 222: /* subscript: COLON test sliceop  */
#line 1380 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4273 "parser.cpp"
    break;

  case 223: /* subscript: test COLON sliceop  */
#line 1387 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4285 "parser.cpp"
    break;

  case 224: /* subscript: test COLON test  */
#line 1394 "parser.y"
                   {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4297 "parser.cpp"
    break;

  case 225: /* subscript: COLON sliceop  */
#line 1401 "parser.y"
                 {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4308 "parser.cpp"
    break;

  case 226: /* subscript: COLON test  */
#line 1407 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4319 "parser.cpp"
    break;

  case 227: /* subscript: test COLON  */
#line 1413 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4330 "parser.cpp"
    break;

  case 228: /* subscript: COLON  */
#line 1419 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 4336 "parser.cpp"
    break;

  case 229: /* sliceop: COLON test  */
#line 1421 "parser.y"
                    {
    Node* n = create_node("Slice OP");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4347 "parser.cpp"
    break;

  case 230: /* sliceop: COLON  */
#line 1427 "parser.y"
       {(yyval.node) = (yyvsp[0].node);}
#line 4353 "parser.cpp"
    break;

  case 231: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep COMMA  */
#line 1429 "parser.y"
                                                        {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4365 "parser.cpp"
    break;

  case 232: /* exprlist: expr_star_expr COMMA  */
#line 1436 "parser.y"
                      {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4376 "parser.cpp"
    break;

  case 233: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep  */
#line 1442 "parser.y"
                                         {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4387 "parser.cpp"
    break;

  case 234: /* exprlist: expr_star_expr  */
#line 1448 "parser.y"
                {(yyval.node) =(yyvsp[0].node);}
#line 4393 "parser.cpp"
    break;

  case 235: /* expr_star_expr: expr  */
#line 1450 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 4399 "parser.cpp"
    break;

  case 236: /* expr_star_expr: star_expr  */
#line 1451 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 4405 "parser.cpp"
    break;

  case 237: /* COMMA_expr_star_expr_rep: COMMA_expr_star_expr_rep COMMA expr_star_expr  */
#line 1454 "parser.y"
                                               {
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4419 "parser.cpp"
    break;

  case 238: /* COMMA_expr_star_expr_rep: COMMA expr_star_expr  */
#line 1463 "parser.y"
                       { 
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4430 "parser.cpp"
    break;

  case 239: /* testlist: test COMMA  */
#line 1478 "parser.y"
             {
    Node* n = create_node("Testlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4441 "parser.cpp"
    break;

  case 240: /* testlist: test  */
#line 1490 "parser.y"
        {(yyval.node) =(yyvsp[0].node);}
#line 4447 "parser.cpp"
    break;

  case 241: /* classdef: CLASS NAME LPAREN arglist RPAREN COLON suite  */
#line 1506 "parser.y"
                                                       {
    Node* n = create_node("Class Def");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-6].node));
    n->children.push_back((yyvsp[-5].node));
    n->children.push_back((yyvsp[-4].node));
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4463 "parser.cpp"
    break;

  case 242: /* classdef: CLASS NAME LPAREN RPAREN COLON suite  */
#line 1517 "parser.y"
                                      {
    Node* n = create_node("Class Def");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-5].node));
    n->children.push_back((yyvsp[-4].node));
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4478 "parser.cpp"
    break;

  case 243: /* classdef: CLASS NAME COLON suite  */
#line 1527 "parser.y"
                        {
    Node* n = create_node("Class Def");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4491 "parser.cpp"
    break;

  case 244: /* arglist: argument COMMA_argument_rep COMMA  */
#line 1537 "parser.y"
                                   {
    Node* n = create_node("Arglist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->parameters.push_back((yyvsp[-2].node)->type);
    (yyval.node)->parameters.insert((yyval.node)->parameters.end(), (yyvsp[-1].node)->parameters.begin(), (yyvsp[-1].node)->parameters.end());
    // cout<<"Arglist 1";
    // for (auto it = $2->parameters.begin(); it != $2->parameters.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // cout<<endl;

  }
#line 4511 "parser.cpp"
    break;

  case 245: /* arglist: argument COMMA  */
#line 1552 "parser.y"
                  {
    Node* n = create_node("Arglist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->parameters.push_back((yyvsp[-1].node)->label);
  }
#line 4523 "parser.cpp"
    break;

  case 246: /* arglist: argument COMMA_argument_rep  */
#line 1559 "parser.y"
                               {
    Node* n = create_node("Arglist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    // cout<<"Arglist 3 "<<endl;
    (yyval.node)->parameters.push_back((yyvsp[-1].node)->type);
    (yyval.node)->parameters.insert((yyval.node)->parameters.end(), (yyvsp[0].node)->parameters.begin(), (yyvsp[0].node)->parameters.end());
    // for (auto it = $$->parameters.begin(); it != $$->parameters.end(); ++it) {
    //   std::cout << *it << " ";
    // }
    // cout<<endl;
  }
#line 4541 "parser.cpp"
    break;

  case 247: /* arglist: argument  */
#line 1572 "parser.y"
           {(yyval.node) =(yyvsp[0].node);
  (yyval.node)->parameters.push_back((yyvsp[0].node)->type);
  }
#line 4549 "parser.cpp"
    break;

  case 248: /* COMMA_argument_rep: COMMA_argument_rep COMMA argument  */
#line 1577 "parser.y"
                                    { 
    Node* n = create_node("Comma Argument rep1");
    (yyval.node) = n;
    // for(int i=0; i<$1->children.size(); i++){
    //   n->children.push_back($1->children[i]);
    // }
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->parameters.insert((yyval.node)->parameters.end(), (yyvsp[-2].node)->parameters.begin(), (yyvsp[-2].node)->parameters.end());
    (yyval.node)->parameters.push_back((yyvsp[0].node)->type);
  }
#line 4566 "parser.cpp"
    break;

  case 249: /* COMMA_argument_rep: COMMA argument  */
#line 1589 "parser.y"
                   {
    Node* n = create_node("Comma Argument rep2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->parameters.push_back((yyvsp[0].node)->type);

  }
#line 4579 "parser.cpp"
    break;

  case 250: /* argument: test comp_for  */
#line 1599 "parser.y"
               {
    Node* n = create_node("Argument");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4590 "parser.cpp"
    break;

  case 251: /* argument: test EQUAL_SIGN test  */
#line 1605 "parser.y"
                         {
     Node* n = create_node("Argument");
     (yyval.node) = n;
     n->children.push_back((yyvsp[-2].node));
     n->children.push_back((yyvsp[-1].node));
  }
#line 4601 "parser.cpp"
    break;

  case 252: /* argument: POWER test  */
#line 1611 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));      
  }
#line 4612 "parser.cpp"
    break;

  case 253: /* argument: TIMES test  */
#line 1617 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));    
  }
#line 4623 "parser.cpp"
    break;

  case 254: /* argument: test  */
#line 1623 "parser.y"
       {(yyval.node) =(yyvsp[0].node);}
#line 4629 "parser.cpp"
    break;

  case 255: /* comp_iter: comp_for  */
#line 1625 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 4635 "parser.cpp"
    break;

  case 256: /* comp_iter: comp_if  */
#line 1626 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 4641 "parser.cpp"
    break;

  case 257: /* sync_comp_for: FOR exprlist IN or_test comp_iter  */
#line 1628 "parser.y"
                                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-4].node));
          n->children.push_back((yyvsp[-3].node));  
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));   
          n->children.push_back((yyvsp[0].node));   
}
#line 4655 "parser.cpp"
    break;

  case 258: /* sync_comp_for: FOR exprlist IN or_test  */
#line 1637 "parser.y"
                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-3].node));
          n->children.push_back((yyvsp[-2].node));  
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 4668 "parser.cpp"
    break;

  case 259: /* comp_for: ASYNC sync_comp_for  */
#line 1646 "parser.y"
                             { 
          Node* n = create_node("Comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));  }
#line 4678 "parser.cpp"
    break;

  case 260: /* comp_for: sync_comp_for  */
#line 1651 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 4684 "parser.cpp"
    break;

  case 261: /* comp_if: IF test_nocond comp_iter  */
#line 1653 "parser.y"
                                  {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
}
#line 4696 "parser.cpp"
    break;

  case 262: /* comp_if: IF test_nocond  */
#line 1660 "parser.y"
                        {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 4707 "parser.cpp"
    break;

  case 263: /* yield_expr: YIELD  */
#line 1666 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 4713 "parser.cpp"
    break;


#line 4717 "parser.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1675 "parser.y"



int main(int argc, char* argv[]) {
    /* yybye = 1; */
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " " << endl;
        return 1;
    }
    extern FILE* yyin;
    char *input_filename = argv[1], *output_filename = argv[2];
    int input =0;
    int output=0;
    for (int i = 1; i < argc; ++i)     
    {
        if (strcmp(argv[i], "-input") == 0 && i + 1 < argc) {
            input =1;
            input_filename = argv[i + 1];
            if(output==0){
                output_filename = argv[i + 2];
            }
            i++;
        }
        else if (strcmp(argv[i], "-output") == 0 && i + 1 < argc) {
            output =1;
            output_filename = argv[i + 1];
            if(input==0){
                input_filename = argv[i + 2];
            }
            i++;
        } 
        else if (strcmp(argv[i], "-verbose") == 0) {
            yydebug = 1;
        }
        else if(  strcmp(argv[i],"-help")==0 ){
            cout<<"To create the executable parse run the command make in the directory and make sure you have flex bison and g++ installed "<<endl;
            cout<<"To execute the file use ./parse followed by optional input tag(-input) to specify input and optional outptut tag(-output) to specify output, If you want to turn on the verbose mode do -verbose,Note:input and output file need to mentioned"<<endl;
            cout<<"To make pdf from .dot file generated use the command dot - Tpdf graph . dot -o graph . pdf"<<endl;
            exit(0);
        }
    }
        if(input_filename==NULL){input_filename=argv[1];}
        if(output_filename==NULL){output_filename=argv[1];}
    
    yyin = fopen(input_filename, "r");
    if(yyin == NULL) {
        cerr << ": Error: Input file " << input_filename << " not found.\n";
        exit(1);
    }
    yyparse();
    gt->PrintSYMTAB();
    fclose(yyin);
    simplify(root);
    printDot(root, output_filename);
    return 0;
}
void yyerror(const char* err) {
  std::cerr << "Error (line " << "): "<<yylineno << err << "token : " << yychar << std::endl;
}

