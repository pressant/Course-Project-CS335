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
  exit(1);
}
void check_type(string s1,string s2, int x)
{
    if(s1 != s2)
    {
      cout<<s1<<" "<<s2<<endl;
      diff_data(x);
      exit(1); 
    }
}
bool isCompatible(string s1 , string s2,string s3){
  if(s1 == "float" && s2 == "int")
    return true;
  else if(s1 == "int" && s2 == "bool")
    return true;
  else if(s1 == "bool" && (s3 == "1" || s3 == "0"))
    return true;
  else return false;
}
Node *root = create_node("File_input");
SYMTAB* tab=new SYMTAB();
SYMTAB* gt=tab;
int curr_scope=tab->SYMSCOPE;
std::string* target_program;

#line 140 "parser.cpp"

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
  YYSYMBOL_decl_type = 114,                /* decl_type  */
  YYSYMBOL_augassign_op = 115,             /* augassign_op  */
  YYSYMBOL_annassign = 116,                /* annassign  */
  YYSYMBOL_testlist_star_expr = 117,       /* testlist_star_expr  */
  YYSYMBOL_testlist_star_expr_opt1 = 118,  /* testlist_star_expr_opt1  */
  YYSYMBOL_testlist_star_expr_rep = 119,   /* testlist_star_expr_rep  */
  YYSYMBOL_augassign = 120,                /* augassign  */
  YYSYMBOL_del_stmt = 121,                 /* del_stmt  */
  YYSYMBOL_pass_stmt = 122,                /* pass_stmt  */
  YYSYMBOL_flow_stmt = 123,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 124,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 125,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 126,              /* return_stmt  */
  YYSYMBOL_yield_stmt = 127,               /* yield_stmt  */
  YYSYMBOL_global_stmt = 128,              /* global_stmt  */
  YYSYMBOL_global_name_list = 129,         /* global_name_list  */
  YYSYMBOL_compound_stmt = 130,            /* compound_stmt  */
  YYSYMBOL_async_stmt = 131,               /* async_stmt  */
  YYSYMBOL_async_stmt_content = 132,       /* async_stmt_content  */
  YYSYMBOL_if_stmt = 133,                  /* if_stmt  */
  YYSYMBOL_elif_stmt_rep = 134,            /* elif_stmt_rep  */
  YYSYMBOL_while_stmt = 135,               /* while_stmt  */
  YYSYMBOL_for_stmt = 136,                 /* for_stmt  */
  YYSYMBOL_suite = 137,                    /* suite  */
  YYSYMBOL_stmt_rep = 138,                 /* stmt_rep  */
  YYSYMBOL_test = 139,                     /* test  */
  YYSYMBOL_test_nocond = 140,              /* test_nocond  */
  YYSYMBOL_or_test = 141,                  /* or_test  */
  YYSYMBOL_or_test_rep = 142,              /* or_test_rep  */
  YYSYMBOL_and_test = 143,                 /* and_test  */
  YYSYMBOL_and_test_rep = 144,             /* and_test_rep  */
  YYSYMBOL_not_test = 145,                 /* not_test  */
  YYSYMBOL_comparison = 146,               /* comparison  */
  YYSYMBOL_comparison_rep = 147,           /* comparison_rep  */
  YYSYMBOL_comp_op = 148,                  /* comp_op  */
  YYSYMBOL_star_expr = 149,                /* star_expr  */
  YYSYMBOL_expr = 150,                     /* expr  */
  YYSYMBOL_expr_rep = 151,                 /* expr_rep  */
  YYSYMBOL_xor_expr = 152,                 /* xor_expr  */
  YYSYMBOL_xor_expr_rep = 153,             /* xor_expr_rep  */
  YYSYMBOL_and_expr = 154,                 /* and_expr  */
  YYSYMBOL_and_expr_rep = 155,             /* and_expr_rep  */
  YYSYMBOL_shift_expr = 156,               /* shift_expr  */
  YYSYMBOL_shift_expr_rep = 157,           /* shift_expr_rep  */
  YYSYMBOL_shift_expr_rep_c1 = 158,        /* shift_expr_rep_c1  */
  YYSYMBOL_arith_expr = 159,               /* arith_expr  */
  YYSYMBOL_arith_expr_rep = 160,           /* arith_expr_rep  */
  YYSYMBOL_arith_expr_rep_c1 = 161,        /* arith_expr_rep_c1  */
  YYSYMBOL_term = 162,                     /* term  */
  YYSYMBOL_term_rep = 163,                 /* term_rep  */
  YYSYMBOL_term_rep_c1 = 164,              /* term_rep_c1  */
  YYSYMBOL_factor = 165,                   /* factor  */
  YYSYMBOL_factor_c1 = 166,                /* factor_c1  */
  YYSYMBOL_power = 167,                    /* power  */
  YYSYMBOL_power_opt = 168,                /* power_opt  */
  YYSYMBOL_atom_expr = 169,                /* atom_expr  */
  YYSYMBOL_await_opt = 170,                /* await_opt  */
  YYSYMBOL_trailer_rep = 171,              /* trailer_rep  */
  YYSYMBOL_atom = 172,                     /* atom  */
  YYSYMBOL_atom_opt1 = 173,                /* atom_opt1  */
  YYSYMBOL_atom_opt2 = 174,                /* atom_opt2  */
  YYSYMBOL_string_rep = 175,               /* string_rep  */
  YYSYMBOL_testlist_comp = 176,            /* testlist_comp  */
  YYSYMBOL_testlist_comp_c1 = 177,         /* testlist_comp_c1  */
  YYSYMBOL_testlist_comp_c2 = 178,         /* testlist_comp_c2  */
  YYSYMBOL_testlist_comp_c2_rep = 179,     /* testlist_comp_c2_rep  */
  YYSYMBOL_trailer = 180,                  /* trailer  */
  YYSYMBOL_subscriptlist = 181,            /* subscriptlist  */
  YYSYMBOL_COMMA_opt = 182,                /* COMMA_opt  */
  YYSYMBOL_COMMA_subscript_rep = 183,      /* COMMA_subscript_rep  */
  YYSYMBOL_subscript = 184,                /* subscript  */
  YYSYMBOL_sliceop = 185,                  /* sliceop  */
  YYSYMBOL_exprlist = 186,                 /* exprlist  */
  YYSYMBOL_expr_star_expr = 187,           /* expr_star_expr  */
  YYSYMBOL_COMMA_expr_star_expr_rep = 188, /* COMMA_expr_star_expr_rep  */
  YYSYMBOL_testlist = 189,                 /* testlist  */
  YYSYMBOL_classdef = 190,                 /* classdef  */
  YYSYMBOL_arglist = 191,                  /* arglist  */
  YYSYMBOL_COMMA_argument_rep = 192,       /* COMMA_argument_rep  */
  YYSYMBOL_argument = 193,                 /* argument  */
  YYSYMBOL_comp_iter = 194,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 195,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 196,                 /* comp_for  */
  YYSYMBOL_comp_if = 197,                  /* comp_if  */
  YYSYMBOL_yield_expr = 198                /* yield_expr  */
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
#define YYLAST   1208

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  259
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  372

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
       0,   125,   125,   131,   138,   146,   155,   156,   158,   184,
     221,   260,   269,   276,   285,   308,   325,   359,   366,   378,
     379,   382,   389,   397,   404,   413,   423,   431,   432,   433,
     434,   435,   437,   478,   481,   489,   492,   498,   511,   515,
     523,   524,   547,   556,   563,   568,   573,   577,   578,   581,
     590,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   607,   613,   615,   616,   617,   618,
     621,   623,   624,   631,   633,   634,   641,   651,   653,   654,
     655,   656,   657,   658,   661,   664,   665,   668,   681,   692,
     703,   712,   723,   732,   743,   752,   765,   776,   777,   791,
     800,   802,   811,   814,   817,   824,   827,   836,   842,   848,
     851,   861,   868,   875,   880,   893,   897,   906,   914,   915,
     916,   917,   918,   919,   920,   921,   927,   928,   936,   944,
     950,   953,   962,   968,   974,   979,   988,   994,  1000,  1003,
    1012,  1018,  1024,  1027,  1036,  1042,  1045,  1048,  1065,  1068,
    1088,  1096,  1097,  1100,  1125,  1128,  1137,  1144,  1145,  1146,
    1147,  1148,  1151,  1157,  1159,  1160,  1161,  1164,  1173,  1179,
    1188,  1196,  1243,  1249,  1254,  1263,  1267,  1276,  1287,  1294,
    1316,  1317,  1318,  1319,  1320,  1321,  1322,  1324,  1325,  1327,
    1330,  1331,  1341,  1350,  1353,  1354,  1357,  1358,  1366,  1367,
    1370,  1382,  1393,  1400,  1409,  1421,  1429,  1438,  1445,  1454,
    1462,  1468,  1474,  1477,  1481,  1490,  1498,  1499,  1508,  1515,
    1522,  1529,  1535,  1541,  1547,  1549,  1555,  1557,  1564,  1570,
    1576,  1578,  1579,  1582,  1591,  1606,  1618,  1634,  1645,  1655,
    1665,  1683,  1693,  1709,  1717,  1733,  1746,  1752,  1758,  1764,
    1770,  1772,  1773,  1775,  1784,  1793,  1798,  1800,  1807,  1813
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
  "expr_stmt_tail", "decl_type", "augassign_op", "annassign",
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

#define YYPACT_NINF (-263)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,    66,  1081,  -263,   196,    84,  1081,   196,   106,  1081,
      55,  1081,  -263,  -263,  -263,  -263,  -263,  1110,  -263,   700,
     760,  -263,   128,   305,    17,  -263,  -263,  -263,    29,  -263,
     704,    77,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,    90,   108,   127,  -263,
    -263,   361,    97,    99,   100,    80,    98,    88,  1110,  -263,
     110,    44,    59,   115,  -263,  -263,   -14,    89,  -263,  -263,
    -263,   138,    92,  -263,    93,  -263,  -263,    95,  -263,  -263,
    -263,  -263,    96,  -263,  -263,  -263,   103,  -263,    54,  -263,
    -263,   105,  -263,  -263,  -263,  -263,  -263,    25,     9,  -263,
     479,    41,   162,  1081,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,   912,
     929,   113,  1081,  1081,   140,  1081,   163,  -263,   151,   172,
    -263,  -263,  -263,  -263,  -263,  -263,   361,  1110,  1110,   134,
    1110,   135,  1110,   136,  -263,  -263,    80,  1110,  -263,  -263,
      98,  1110,  -263,  -263,  -263,  -263,  -263,    88,  1110,  -263,
    1110,  -263,    59,   623,   806,   191,    59,  -263,  -263,   683,
     527,  -263,  1081,   196,   125,   527,   195,   527,  -263,   196,
     175,   929,  -263,   131,  -263,  -263,  -263,    75,  -263,   141,
     527,  1081,  -263,  -263,  -263,   575,   144,   133,  -263,  -263,
    -263,  -263,  -263,   929,   202,  -263,  1081,  -263,  1081,  -263,
    -263,  1110,  -263,  -263,  1110,  -263,  1110,  -263,  1110,  1110,
    -263,  1110,  -263,  1110,  -263,  -263,    59,  1081,  1081,  -263,
      45,   147,   145,  -263,   989,   143,   149,   148,  -263,  -263,
     146,   154,   217,  -263,  -263,   150,  -263,   196,   213,  -263,
      51,   208,  -263,  -263,  -263,   929,   225,   226,  -263,  -263,
     157,  -263,  -263,   228,  -263,  -263,  1081,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  1081,  -263,
    -263,   852,   164,  1081,   161,  -263,   989,  -263,  1035,  -263,
     165,   527,   166,   431,   527,  -263,   173,   177,  1081,    83,
    1081,  -263,  -263,  -263,   167,   176,   527,   169,  -263,  -263,
    -263,   852,  -263,  -263,   161,  -263,  -263,  1035,  -263,  -263,
     527,  -263,   371,   234,   527,   527,   178,   179,  1081,    91,
     250,   225,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
     183,  -263,  -263,   527,   527,   185,  1081,  -263,  -263,  -263,
     190,  -263,   527,  -263,  -263,   527,    91,  -263,  -263,  -263,
    -263,  -263
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   179,   181,     3,     7,   186,   173,    65,   184,    70,
     185,     0,    73,    71,     0,     0,     0,     0,     0,     0,
       0,     0,   259,   180,   190,   164,   165,     0,   166,     0,
       0,   183,     0,     0,     0,    81,     6,    19,     0,    27,
      33,    46,    28,    29,    30,    66,    67,    68,    69,    31,
      20,    83,    78,    79,    80,    47,   102,   105,   109,   113,
      48,   115,   130,   134,   138,   142,   148,   154,     0,   163,
     168,     0,   172,   182,    82,    74,     0,   236,    72,   232,
     231,     0,   230,     8,     0,    64,    77,    75,   112,    85,
      84,    86,     0,   128,   194,   195,     0,   188,   193,   187,
     178,     0,   189,     1,     2,     4,     5,     0,     0,    21,
       0,     0,     0,     0,    51,    52,    53,    55,    63,    56,
      54,    57,    58,    59,    61,    60,    62,    32,    35,     0,
      45,    44,     0,     0,   104,     0,   108,   124,   126,     0,
     118,   119,   122,   121,   120,   123,   114,     0,     0,   129,
       0,   133,     0,   137,   145,   146,   141,     0,   151,   152,
     147,     0,   157,   159,   161,   160,   158,   153,     0,   162,
       0,   167,     0,     0,     0,     0,   171,   175,   191,     0,
       0,   235,     0,   228,   229,     0,     0,     0,   176,     0,
       0,   198,   192,   199,   256,   196,   177,    13,    12,     0,
       0,     0,    23,    26,    22,     0,    38,    36,    42,    37,
      41,    40,    50,    43,     0,   107,     0,   111,     0,   127,
     125,     0,   117,   132,     0,   136,     0,   140,     0,     0,
     144,     0,   150,     0,   156,   169,   170,     0,     0,   205,
     250,     0,   243,   207,   224,   216,     0,   212,   208,   174,
       0,     0,     0,    97,   239,     0,   234,   227,    94,    76,
      90,     0,   255,   202,   203,   197,     0,     0,    11,    10,
       0,    24,    25,     0,    34,    49,     0,   106,   110,   116,
     131,   135,   139,   143,   149,   155,   249,   248,     0,   246,
     204,   241,   242,   226,   222,   221,   223,   206,   213,   210,
     211,     0,     0,     0,     0,   233,     0,     0,     0,    88,
       0,   200,   201,    15,    17,    14,     0,     0,   101,   247,
     245,   240,   225,   218,   220,   219,   215,   213,   209,   238,
       0,   100,     0,    96,     0,     0,     0,     0,     0,   254,
       0,     0,     9,    39,   244,   217,   214,   237,    98,    99,
       0,    93,    89,     0,     0,     0,     0,   253,   251,   252,
       0,    16,     0,    92,    87,     0,   258,   103,    18,    95,
      91,   257
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -263,  -263,  -263,  -263,   240,  -263,  -234,  -263,   -31,     0,
    -263,   -94,  -263,  -263,  -263,  -263,    56,  -263,  -115,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,   241,  -158,  -263,   -11,
    -263,  -124,  -263,  -113,  -263,   -16,  -263,  -263,   120,    -8,
     -10,  -263,  -123,  -263,  -126,  -263,  -122,  -263,   111,  -134,
    -263,   109,  -135,  -263,   101,   -55,  -263,  -263,  -263,  -263,
    -263,   102,   199,  -263,  -263,  -263,   243,  -263,  -263,  -263,
    -116,  -263,   -29,  -263,  -262,  -172,    -5,  -152,  -263,   -74,
    -263,   104,  -263,  -248,   -91,    86,   -87,  -263,   -15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    32,    33,    34,    35,   108,   199,   315,    36,   253,
     111,    38,    39,   127,   207,   209,   128,    40,    41,   131,
     129,    42,    43,    44,    45,    46,    47,    48,    49,    87,
      50,    51,    90,    52,   309,    53,    54,   254,   332,    55,
     366,    56,   134,    57,   136,    58,    59,   146,   147,    60,
      61,   149,    62,   151,    63,   153,    64,   156,   157,    65,
     160,   161,    66,   167,   168,    67,    68,    69,   171,    70,
      71,   176,    72,    96,   101,    73,    97,    98,   192,   193,
     177,   246,   299,   300,   247,   295,    81,    82,   184,    78,
      74,   241,   292,   242,   357,   194,   358,   359,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    77,   106,    88,    80,    84,    79,    80,   214,    79,
      92,   195,    85,   169,    99,   212,   203,    93,    94,    94,
     215,    95,    95,   230,   225,   223,   232,   258,   197,   260,
     227,   256,   313,    37,     1,     2,   326,   109,     3,     4,
       5,     6,   269,   320,     7,     8,     9,     1,     2,   204,
      10,    11,   179,     5,    12,   210,    13,    14,     8,   180,
     249,    15,   307,    10,    16,   346,    17,    18,    19,    76,
      20,   189,    21,   344,    22,    23,    24,    25,    26,    27,
     189,    14,   200,   107,   190,    15,   201,    83,    23,    24,
      28,   308,   198,   190,   337,   283,   284,    29,   275,    30,
     281,   280,   208,   277,   110,   305,   282,   361,   255,    86,
      29,   272,    30,   234,   211,   235,   205,   189,    77,   217,
     249,   288,   323,   338,   325,   173,   191,   174,   103,    31,
     190,   132,   356,   175,   154,   155,   162,   222,   163,   164,
     165,   166,    31,   329,   158,   159,   333,   266,   267,   130,
     133,   135,   345,   289,   148,   182,   152,   150,   342,   170,
     178,   181,   240,   245,   183,   206,   185,   186,   240,   187,
     188,    77,   347,    80,   196,    79,   351,   352,   285,    80,
     263,    79,   216,   264,   261,   213,   339,   218,   219,   220,
     270,   224,   228,   226,   248,   363,   364,   257,   259,     1,
       2,   189,   278,   265,   369,     5,     6,   370,   268,   113,
       8,   279,   273,   276,   290,    10,   296,   291,   297,   301,
     298,   302,   303,   304,   306,   310,   286,   287,   197,   314,
     316,   317,   367,   294,   293,   340,   321,   327,   343,   330,
      23,    24,    25,    26,    27,   350,   334,    80,   341,    79,
     335,   353,   354,   360,   311,    28,   362,   312,   365,   368,
      89,    91,    29,   274,    30,   318,   221,   229,   233,   231,
     172,   328,   331,   102,   236,   371,   262,   319,     0,     0,
     240,     0,   322,   251,     0,   324,     0,   245,     0,     0,
       0,     0,     0,     0,    31,     0,     0,   336,     0,     0,
       0,   349,     0,    37,     0,     0,     0,     0,     1,     2,
     240,     0,   104,   105,     5,     6,   245,     0,     7,     8,
       9,     0,     0,     0,    10,    11,     0,   355,    12,     0,
      13,    14,    37,     0,     0,    15,     0,     0,    16,     0,
      17,    18,    19,     0,    20,     0,    21,     0,    22,    23,
      24,    25,    26,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,     0,
       0,    29,     0,    30,     1,     2,     0,   348,   137,     0,
       5,     6,     0,   138,     7,     8,     9,     0,     0,     0,
      10,    11,     0,     0,    12,     0,    13,    14,   139,     0,
       0,    15,     0,    31,    16,     0,    17,    18,    19,     0,
      20,     0,    21,     0,    22,    23,    24,    25,    26,    27,
       0,   140,   141,   142,   143,   144,   145,     0,     0,     0,
      28,     0,     0,     0,     1,     2,     0,    29,     0,    30,
       5,     6,     0,     0,     7,     8,     9,     0,     0,     0,
      10,    11,     0,     0,    12,     0,    13,    14,     0,     0,
       0,    15,     0,     0,    16,     0,    17,    18,    19,    31,
      20,     0,    21,     0,    22,    23,    24,    25,    26,    27,
       0,     0,     1,     2,     0,     0,     0,   202,     5,     6,
      28,     0,     7,     8,     9,     0,     0,    29,    10,    30,
       0,     0,    12,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,     0,    31,
       1,     2,     0,     0,     0,   252,     5,     6,    28,     0,
       7,     8,     9,     0,     0,    29,    10,    30,     0,     0,
      12,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,     0,     0,     0,     0,     0,
      22,    23,    24,    25,    26,    27,     0,    31,     1,     2,
       0,     0,     0,   271,     5,     6,    28,     0,     7,     8,
       9,     0,     0,    29,    10,    30,     0,     0,    12,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,     0,    31,     1,     2,     0,     0,
       0,     0,     5,     6,    28,     0,     0,     8,     0,     0,
       0,    29,    10,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   237,   238,    31,     0,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,     1,     2,     0,    29,
     239,    30,     5,     6,     0,     0,     0,     8,     0,     0,
       0,     0,    10,     1,     2,     0,     0,     0,     0,     5,
       6,     0,     0,     0,     8,     0,     0,     0,     0,    10,
      19,    31,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   237,   238,     0,     0,     0,     0,    19,     0,     0,
       0,     0,    28,    22,    23,    24,    25,    26,    27,    29,
     250,    30,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,     0,     1,     2,     0,    29,     0,    30,     5,
       6,     0,     0,     0,     8,     0,     0,   112,     0,    10,
     113,    31,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     0,     0,    19,    31,     0,
       0,     0,     0,     0,    23,    24,    25,    26,    27,     1,
       2,     0,     0,     0,     0,     5,     6,     0,     0,    28,
       8,     0,     0,     0,     0,    10,    29,     0,    30,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,     0,     1,     2,     0,    31,     0,
       0,     5,     6,     0,     0,    28,     8,     0,     0,     0,
       0,    10,    29,     0,    30,   243,     0,     0,     0,   244,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
     237,   238,     0,     0,    31,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     1,     2,     0,    29,     0,
      30,     5,     6,     0,     0,     0,     8,     0,     0,     0,
       0,    10,     1,     2,     0,     0,     0,     0,     5,     6,
       0,     0,     0,     8,     0,     0,     0,     0,    10,    19,
      31,     0,     0,     0,     0,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,    28,     0,    23,    24,    25,    26,    27,    29,     0,
      30,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     1,     2,     0,    29,     0,    30,     5,     6,
       0,     0,     0,     8,     0,     0,     0,     0,    10,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    31,     0,     0,
       0,     0,     0,    23,    24,    25,    26,     0,     1,     2,
       0,     0,     0,     0,     5,     6,     0,     0,    28,     8,
       0,     0,     0,     0,    10,    29,     0,    30,     0,     0,
       0,     0,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,    23,
      24,    25,    26,     0,     1,     2,     0,    31,     0,     0,
       5,     6,     0,     0,    28,     8,     0,     0,     0,     0,
      10,    29,     0,    30,     0,     0,     0,     0,   244,     0,
       0,     0,     0,     1,     2,     0,     0,     0,    19,     5,
       6,     0,     0,     0,     8,    23,    24,    25,    26,    10,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     0,     0,     0,    29,     0,    30,
       0,     0,     0,     0,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,     0,     0,     0,     0,    29,     0,    30,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
       0,    12,    33,    19,    14,    16,    14,    17,   132,    17,
      21,    98,    17,    68,    29,   130,   110,    27,    29,    30,
     133,    29,    30,   157,   150,   148,   161,   185,     3,   187,
     152,   183,   266,    33,     3,     4,   298,     8,     7,     8,
       9,    10,   200,   291,    13,    14,    15,     3,     4,     8,
      19,    20,    66,     9,    23,   129,    25,    26,    14,    73,
     176,    30,    11,    19,    33,   327,    35,    36,    37,     3,
      39,    26,    41,   321,    43,    44,    45,    46,    47,    48,
      26,    26,    73,    66,    39,    30,    77,     3,    44,    45,
      59,    40,    67,    39,    11,   229,   231,    66,   213,    68,
     226,   224,   113,   216,    75,   257,   228,   341,   182,     3,
      66,   205,    68,   168,   129,   170,    75,    26,   129,   135,
     236,    76,   294,    40,   296,    66,    72,    68,     0,    98,
      39,    41,    41,    74,    54,    55,    48,   147,    50,    51,
      52,    53,    98,   301,    46,    47,   304,    72,    73,    72,
      42,    24,   324,   240,    57,    17,    56,    58,   316,    49,
      45,    72,   173,   174,    72,     3,    73,    72,   179,    73,
      67,   182,   330,   183,    69,   183,   334,   335,   233,   189,
     191,   189,    42,   191,   189,    72,   310,    24,    37,    17,
     201,    57,    56,    58,     3,   353,   354,    72,     3,     3,
       4,    26,   218,    72,   362,     9,    10,   365,    67,    76,
      14,   221,    68,    11,    67,    19,    73,    72,    69,    73,
      72,    67,     5,    73,    11,    17,   237,   238,     3,     3,
      73,     3,   356,   244,    73,    68,    72,    72,    69,    73,
      44,    45,    46,    47,    48,    11,    73,   257,    72,   257,
      73,    73,    73,     3,   265,    59,    73,   265,    73,    69,
      20,    20,    66,   207,    68,   276,   146,   156,   167,   160,
      71,   300,   303,    30,   172,   366,   190,   288,    -1,    -1,
     291,    -1,   293,   179,    -1,   296,    -1,   298,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,   308,    -1,    -1,
      -1,   332,    -1,   303,    -1,    -1,    -1,    -1,     3,     4,
     321,    -1,     7,     8,     9,    10,   327,    -1,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    -1,   338,    23,    -1,
      25,    26,   332,    -1,    -1,    30,    -1,    -1,    33,    -1,
      35,    36,    37,    -1,    39,    -1,    41,    -1,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    68,     3,     4,    -1,     6,    17,    -1,
       9,    10,    -1,    22,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    -1,    -1,    23,    -1,    25,    26,    37,    -1,
      -1,    30,    -1,    98,    33,    -1,    35,    36,    37,    -1,
      39,    -1,    41,    -1,    43,    44,    45,    46,    47,    48,
      -1,    60,    61,    62,    63,    64,    65,    -1,    -1,    -1,
      59,    -1,    -1,    -1,     3,     4,    -1,    66,    -1,    68,
       9,    10,    -1,    -1,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    -1,    -1,    23,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    35,    36,    37,    98,
      39,    -1,    41,    -1,    43,    44,    45,    46,    47,    48,
      -1,    -1,     3,     4,    -1,    -1,    -1,     8,     9,    10,
      59,    -1,    13,    14,    15,    -1,    -1,    66,    19,    68,
      -1,    -1,    23,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    -1,    98,
       3,     4,    -1,    -1,    -1,     8,     9,    10,    59,    -1,
      13,    14,    15,    -1,    -1,    66,    19,    68,    -1,    -1,
      23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    -1,    98,     3,     4,
      -1,    -1,    -1,     8,     9,    10,    59,    -1,    13,    14,
      15,    -1,    -1,    66,    19,    68,    -1,    -1,    23,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    -1,    98,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    59,    -1,    -1,    14,    -1,    -1,
      -1,    66,    19,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,     3,     4,    -1,    66,
      67,    68,     9,    10,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    19,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,
      37,    98,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    59,    43,    44,    45,    46,    47,    48,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,     3,     4,    -1,    66,    -1,    68,     9,
      10,    -1,    -1,    -1,    14,    -1,    -1,    73,    -1,    19,
      76,    98,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    -1,    37,    98,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    -1,    -1,    59,
      14,    -1,    -1,    -1,    -1,    19,    66,    -1,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,     3,     4,    -1,    98,    -1,
      -1,     9,    10,    -1,    -1,    59,    14,    -1,    -1,    -1,
      -1,    19,    66,    -1,    68,    69,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,     3,     4,    -1,    66,    -1,
      68,     9,    10,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      -1,    19,     3,     4,    -1,    -1,    -1,    -1,     9,    10,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    37,
      98,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    59,    -1,    44,    45,    46,    47,    48,    66,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,     3,     4,    -1,    66,    -1,    68,     9,    10,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    98,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,     3,     4,
      -1,    -1,    -1,    -1,     9,    10,    -1,    -1,    59,    14,
      -1,    -1,    -1,    -1,    19,    66,    -1,    68,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,     3,     4,    -1,    98,    -1,    -1,
       9,    10,    -1,    -1,    59,    14,    -1,    -1,    -1,    -1,
      19,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    37,     9,
      10,    -1,    -1,    -1,    14,    44,    45,    46,    47,    19,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,     8,     9,    10,    13,    14,    15,
      19,    20,    23,    25,    26,    30,    33,    35,    36,    37,
      39,    41,    43,    44,    45,    46,    47,    48,    59,    66,
      68,    98,   101,   102,   103,   104,   108,   109,   111,   112,
     117,   118,   121,   122,   123,   124,   125,   126,   127,   128,
     130,   131,   133,   135,   136,   139,   141,   143,   145,   146,
     149,   150,   152,   154,   156,   159,   162,   165,   166,   167,
     169,   170,   172,   175,   190,   198,     3,   139,   189,   149,
     150,   186,   187,     3,   139,   186,     3,   129,   145,   104,
     132,   136,   139,   150,   139,   149,   173,   176,   177,   198,
      69,   174,   176,     0,     7,     8,   108,    66,   105,     8,
      75,   110,    73,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   113,   116,   120,
      72,   119,    41,    42,   142,    24,   144,    17,    22,    37,
      60,    61,    62,    63,    64,    65,   147,   148,    57,   151,
      58,   153,    56,   155,    54,    55,   157,   158,    46,    47,
     160,   161,    48,    50,    51,    52,    53,   163,   164,   165,
      49,   168,   172,    66,    68,    74,   171,   180,    45,    66,
      73,    72,    17,    72,   188,    73,    72,    73,    67,    26,
      39,    72,   178,   179,   195,   196,    69,     3,    67,   106,
      73,    77,     8,   111,     8,    75,     3,   114,   139,   115,
     189,   198,   118,    72,   141,   143,    42,   145,    24,    37,
      17,   148,   150,   152,    57,   154,    58,   156,    56,   158,
     159,   161,   162,   164,   165,   165,   171,    48,    49,    67,
     139,   191,   193,    69,    73,   139,   181,   184,     3,   180,
      67,   191,     8,   109,   137,   189,   187,    72,   137,     3,
     137,   186,   195,   139,   149,    72,    72,    73,    67,   137,
     139,     8,   111,    68,   116,   118,    11,   143,   145,   150,
     152,   154,   156,   159,   162,   165,   139,   139,    76,   196,
      67,    72,   192,    73,   139,   185,    73,    69,    72,   182,
     183,    73,    67,     5,    73,   187,    11,    11,    40,   134,
      17,   139,   149,   106,     3,   107,    73,     3,   139,   139,
     193,    72,   139,   185,   139,   185,   184,    72,   182,   137,
      73,   108,   138,   137,    73,    73,   139,    11,    40,   141,
      68,    72,   137,    69,   193,   185,   184,   137,     6,   108,
      11,   137,   137,    73,    73,   139,    41,   194,   196,   197,
       3,   106,    73,   137,   137,    73,   140,   141,    69,   137,
     137,   194
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   102,   102,   102,   102,   103,   104,
     104,   105,   105,   106,   106,   106,   106,   107,   107,   108,
     108,   109,   109,   109,   109,   110,   110,   111,   111,   111,
     111,   111,   112,   112,   113,   113,   113,   113,   114,   114,
     115,   115,   116,   117,   117,   117,   117,   118,   118,   119,
     119,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   122,   123,   123,   123,   123,
     124,   125,   126,   126,   127,   128,   129,   129,   130,   130,
     130,   130,   130,   130,   131,   132,   132,   133,   133,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   146,   146,   147,   147,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   149,   150,
     150,   151,   151,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   156,   157,   157,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   164,   164,   164,
     164,   164,   165,   165,   166,   166,   166,   167,   167,   168,
     169,   169,   169,   170,   171,   171,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   173,   173,   174,
     175,   175,   176,   176,   177,   177,   178,   178,   178,   178,
     179,   179,   179,   179,   180,   180,   180,   180,   180,   181,
     181,   181,   181,   182,   183,   183,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   185,   185,   186,   186,   186,
     186,   187,   187,   188,   188,   189,   189,   190,   190,   190,
     191,   191,   191,   191,   192,   192,   193,   193,   193,   193,
     193,   194,   194,   195,   195,   196,   196,   197,   197,   198
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     1,     2,     6,
       4,     3,     2,     1,     3,     3,     5,     1,     4,     1,
       1,     2,     3,     3,     4,     3,     2,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     2,     2,     1,     4,
       1,     1,     2,     3,     2,     2,     1,     1,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     8,     5,     7,
       4,     5,     4,     7,     4,     9,     6,     1,     4,     2,
       1,     5,     1,     1,     2,     1,     3,     2,     2,     1,
       3,     2,     2,     1,     2,     1,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     2,     2,
       1,     3,     2,     2,     1,     3,     2,     2,     1,     3,
       2,     2,     1,     3,     2,     1,     1,     2,     1,     3,
       2,     1,     1,     2,     1,     3,     2,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     1,     2,
       3,     2,     1,     1,     2,     1,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     2,     1,     1,
       3,     3,     2,     2,     3,     2,     3,     2,     2,     3,
       2,     2,     1,     1,     3,     2,     1,     4,     3,     3,
       3,     2,     2,     2,     1,     2,     1,     3,     2,     2,
       1,     1,     1,     3,     2,     2,     1,     7,     6,     4,
       3,     2,     2,     1,     3,     2,     2,     3,     2,     2,
       1,     1,     1,     5,     4,     2,     1,     3,     2,     1
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
#line 125 "parser.y"
                               {
    if(yybye) cout<<"LINE 107";
    (yyval.node) = root;
    root->children.push_back((yyvsp[-1].node));
    root->children.push_back((yyvsp[0].node));
  }
#line 2078 "parser.cpp"
    break;

  case 3: /* file_input: ENDMARKER  */
#line 131 "parser.y"
              {
    if(yybye) cout<<"LINE 115";
    (yyval.node) = NULL;
    }
#line 2087 "parser.cpp"
    break;

  case 4: /* newline_stat_rep: newline_stat_rep NEWLINE  */
#line 138 "parser.y"
                             {
    if(yybye) cout<<"LINE 119";
    Node* n = create_node("newline_stat_rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
  }
#line 2100 "parser.cpp"
    break;

  case 5: /* newline_stat_rep: newline_stat_rep stmt  */
#line 146 "parser.y"
                          { 
    if(yybye) cout<<"LINE 126";
    Node* n = create_node("newline_stat_rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));
  }
#line 2114 "parser.cpp"
    break;

  case 6: /* newline_stat_rep: stmt  */
#line 155 "parser.y"
         { (yyval.node) = (yyvsp[0].node) ; if(yybye) cout<<"LINE 132"; (yyval.node) = (yyvsp[0].node);}
#line 2120 "parser.cpp"
    break;

  case 7: /* newline_stat_rep: NEWLINE  */
#line 156 "parser.y"
            {  if(yybye) cout<<"LINE 133"; cout<<yylineno<<endl;}
#line 2126 "parser.cpp"
    break;

  case 8: /* funcname: DEF NAME  */
#line 158 "parser.y"
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
              //  tab->childs.push_back(newtab);
               tab->childs[(yyvsp[0].node)->label] = newtab;
               tab=newtab;
             }
             else {
              cout<<"Function redeclared in line no "<< (yyvsp[0].node)->line_number<<endl;
                      /* exit(1); */
             }
            // cout<<"funcname "<<$1->line_number<<endl;
          }
#line 2155 "parser.cpp"
    break;

  case 9: /* funcdef: funcname parameters ARROW test COLON suite  */
#line 184 "parser.y"
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
                // tab-SYMVAL[$1->labe].params = 
                //int g_index;
                //int reg_name;
                for(int i=0;i<(yyvsp[-4].node)->children.size();i++){
                  Node* t=(yyvsp[-4].node)->children[i];
                  string temp=t->label;
                   if(temp!="[" && temp!="]"){
                      tab->SYMVAL[(yyvsp[-5].node)->label].params=(yyvsp[-4].node)->p_f;
                   }
                }              
             }

             else{
              cout<<"error";
              exit(0);
             }
            //  cout<<$1->line_number<<endl;
             check_type((yyvsp[-2].node)->type , (yyvsp[0].node)->type , (yyvsp[-5].node)->line_number);

         }
#line 2197 "parser.cpp"
    break;

  case 10: /* funcdef: funcname parameters COLON suite  */
#line 221 "parser.y"
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
#line 2239 "parser.cpp"
    break;

  case 11: /* parameters: LPAREN typedargslist RPAREN  */
#line 260 "parser.y"
                                         {
                Node* n = create_node("Parameters");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                n->children.push_back((yyvsp[0].node));
                n->count=(yyvsp[-1].node)->count;
                n->p_f=(yyvsp[-1].node)->p_f;
                (yyval.node)=n;
            }
#line 2253 "parser.cpp"
    break;

  case 12: /* parameters: LPAREN RPAREN  */
#line 269 "parser.y"
                           {
                (yyval.node) = create_node("Parameters");
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 2263 "parser.cpp"
    break;

  case 13: /* typedargslist: NAME  */
#line 276 "parser.y"
                     {
                  Node *n = create_node("Typedargslist1");
                  n->children.push_back((yyvsp[0].node));
                  Param* temp=new Param();
                  temp->par_name=(yyvsp[0].node)->label;
                  n->p_f.push_back(temp);
                  n->count=1;
                  (yyval.node)=n;
                  }
#line 2277 "parser.cpp"
    break;

  case 14: /* typedargslist: NAME COLON datatype  */
#line 285 "parser.y"
                                       {
                  if(yybye) cout<<"LINE 188";
                  Node *n = create_node("Typedargslist2");
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
#line 2305 "parser.cpp"
    break;

  case 15: /* typedargslist: NAME COMMA typedargslist  */
#line 308 "parser.y"
                                         {
                  if(yybye) cout<<"LINE 196";
                  Node *n = create_node("Typedargslist3");
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
#line 2327 "parser.cpp"
    break;

  case 16: /* typedargslist: NAME COLON datatype COMMA typedargslist  */
#line 325 "parser.y"
                                                        {
                  if(yybye) cout<<"LINE 203";
                  Node *n = create_node("Typedargslist4");
                  n->children.push_back((yyvsp[-4].node));
                  n->children.push_back((yyvsp[-3].node));
                  n->children.push_back((yyvsp[-2].node));
                  n->children.push_back((yyvsp[-1].node));
                  for(int i=0; i<(yyvsp[0].node)->children.size(); i++) {
                    n->children.push_back((yyvsp[0].node)->children[i]);
                  }
                  n->count=1+(yyvsp[0].node)->count;
                  Param* temp=new Param();
                  temp->par_type=(yyvsp[-2].node)->label;
                  temp->par_name=(yyvsp[-4].node)->label;
                  vector<Param*> t2;
                  t2.push_back(temp);
                  t2.insert(t2.end(),(yyvsp[0].node)->p_f.begin(),(yyvsp[0].node)->p_f.end());
                  n->p_f=t2;
                  (yyval.node) = n;
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
#line 2364 "parser.cpp"
    break;

  case 17: /* datatype: NAME  */
#line 359 "parser.y"
                {
              if(yybye) cout<<"LINE 215";
              Node *n = create_node("Datatype");
              n->children.push_back((yyvsp[0].node));
              n->label=(yyvsp[0].node)->label;
              (yyval.node) = n;
            }
#line 2376 "parser.cpp"
    break;

  case 18: /* datatype: NAME LBRACKET NAME RBRACKET  */
#line 366 "parser.y"
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
#line 2391 "parser.cpp"
    break;

  case 19: /* stmt: simple_stmt  */
#line 378 "parser.y"
                      { if(yybye) cout<<"LINE 231 \n";(yyval.node)=(yyvsp[0].node);}
#line 2397 "parser.cpp"
    break;

  case 20: /* stmt: compound_stmt  */
#line 379 "parser.y"
                       {if(yybye) cout<<"LINE 232 \n";(yyval.node)=(yyvsp[0].node);}
#line 2403 "parser.cpp"
    break;

  case 21: /* simple_stmt: small_stmt NEWLINE  */
#line 382 "parser.y"
                                {
              if(yybye) cout<<"LINE 235 \n";
               Node* n = create_node("simple_stmt");
               n->children.push_back((yyvsp[-1].node));
               (yyval.node)=n;
               (yyval.node)->type = (yyvsp[-1].node)->type;
            }
#line 2415 "parser.cpp"
    break;

  case 22: /* simple_stmt: small_stmt small_stmt_list NEWLINE  */
#line 389 "parser.y"
                                               {

                if(yybye) cout<<"LINE 241 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
              }
#line 2428 "parser.cpp"
    break;

  case 23: /* simple_stmt: small_stmt SEMICOLON NEWLINE  */
#line 397 "parser.y"
                                         {
                if(yybye) cout<<"LINE 242 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
              }
#line 2440 "parser.cpp"
    break;

  case 24: /* simple_stmt: small_stmt small_stmt_list SEMICOLON NEWLINE  */
#line 404 "parser.y"
                                                         {
                if(yybye) cout<<"LINE 243 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-3].node));
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));              
              }
#line 2452 "parser.cpp"
    break;

  case 25: /* small_stmt_list: small_stmt_list SEMICOLON small_stmt  */
#line 413 "parser.y"
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
#line 2467 "parser.cpp"
    break;

  case 26: /* small_stmt_list: SEMICOLON small_stmt  */
#line 423 "parser.y"
                                      {
                  if(yybye) cout<<"LINE 255 \n";
                  Node* n =create_node("small_stmt_list");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                }
#line 2479 "parser.cpp"
    break;

  case 27: /* small_stmt: expr_stmt  */
#line 431 "parser.y"
                      {if(yybye) cout<<"LINE 262 \n"; (yyval.node)=(yyvsp[0].node);}
#line 2485 "parser.cpp"
    break;

  case 28: /* small_stmt: del_stmt  */
#line 432 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2491 "parser.cpp"
    break;

  case 29: /* small_stmt: pass_stmt  */
#line 433 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2497 "parser.cpp"
    break;

  case 30: /* small_stmt: flow_stmt  */
#line 434 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2503 "parser.cpp"
    break;

  case 31: /* small_stmt: global_stmt  */
#line 435 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2509 "parser.cpp"
    break;

  case 32: /* expr_stmt: testlist_star_expr expr_stmt_tail  */
#line 437 "parser.y"
                                             { 
              Node* n =create_node("expr_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));
              (yyval.node)=n;
              if((yyvsp[0].node)->label=="annassign"){
                if(tab->SYMVAL.find((yyvsp[-1].node)->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared "<<(yyvsp[-1].node)->label<<endl;
                  cout<<endl;
                          /* exit(1); */
                }
                  // cout<<"enterd expr_stmt "<<$2->type<<endl;
                  tab->SYMVAL[(yyvsp[-1].node)->label].identity=NORMIE;
                  tab->SYMVAL[(yyvsp[-1].node)->label].scope=curr_scope;
                  tab->SYMVAL[(yyvsp[-1].node)->label].line_no=(yyvsp[-1].node)->line_number;
                  tab->SYMVAL[(yyvsp[-1].node)->label].type=(yyvsp[0].node)->type;
                  tab->SYMVAL[(yyvsp[-1].node)->label].name=(yyvsp[0].node)->label;
                  tab->SYMVAL[(yyvsp[-1].node)->label].size=0;
              }
              else if((yyvsp[0].node)->label == "expr_stmt_tail")
              {
                  if((yyvsp[-1].node)->type != (yyvsp[0].node)->type)
                  {
                    if((yyvsp[-1].node)->type == "float" && (yyvsp[0].node)->type == "int"){}
                    else if((yyvsp[-1].node)->type == "int" && (yyvsp[0].node)->type=="bool"){}
                    else 
                      check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[-1].node)->line_number);
                  }
              }
              else if(tab->SYMVAL.find((yyvsp[-1].node)->label)!=tab->SYMVAL.end())
              {
                check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[-1].node)->line_number);
                // cout<<yylineno<<endl;
                // if($1->type != $2->type)
                // {
                //   cout<<"Different datatypes compared in line no "<<$1->line_no<<endl;
                //           /* exit(1); */
                // }
              }
                // cout<<$1->type <<" hii "<<$2->type<<endl;
             }
#line 2555 "parser.cpp"
    break;

  case 33: /* expr_stmt: testlist_star_expr  */
#line 478 "parser.y"
                                 { (yyval.node) = (yyvsp[0].node);}
#line 2561 "parser.cpp"
    break;

  case 34: /* expr_stmt_tail: COLON decl_type annassign  */
#line 481 "parser.y"
                                           {
                  (yyval.node) =create_node("annassign");
                  (yyval.node)->children.push_back((yyvsp[-2].node));
                  (yyval.node)->children.push_back((yyvsp[-1].node));
                  (yyval.node)->children.push_back((yyvsp[0].node));
                  (yyval.node)->type = (yyvsp[-1].node)->type;
                  check_type((yyvsp[-1].node)->type, (yyvsp[0].node)->type, (yyvsp[-2].node)->line_number);
                  }
#line 2574 "parser.cpp"
    break;

  case 35: /* expr_stmt_tail: annassign  */
#line 489 "parser.y"
                          {
                  (yyval.node) = (yyvsp[0].node);
               }
#line 2582 "parser.cpp"
    break;

  case 36: /* expr_stmt_tail: COLON decl_type  */
#line 492 "parser.y"
                                 {
                  (yyval.node) =create_node("annassign");
                  (yyval.node)->children.push_back((yyvsp[-1].node));
                  (yyval.node)->children.push_back((yyvsp[0].node));
                  (yyval.node)->type = (yyvsp[0].node)->type;
               }
#line 2593 "parser.cpp"
    break;

  case 37: /* expr_stmt_tail: augassign augassign_op  */
#line 498 "parser.y"
                                        {
                  Node* n =create_node("expr_stmt_tail");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                  (yyval.node)->type = (yyvsp[0].node)->type;
                  // cout<<$$->type <<" expr_stmt_tail"<<endl;
               }
#line 2606 "parser.cpp"
    break;

  case 38: /* decl_type: NAME  */
#line 511 "parser.y"
                {
                (yyval.node) = create_node("decl_type");
                (yyval.node)->type = (yyvsp[0].node)->type;
            }
#line 2615 "parser.cpp"
    break;

  case 39: /* decl_type: NAME LBRACKET NAME RBRACKET  */
#line 515 "parser.y"
                                          {
                if((yyvsp[-3].node)->label != "list"){
                  cout << "Invalid datatype at line no: " << (yyvsp[-3].node)->line_number << endl;
                  exit(1);
                }
                (yyval.node)->type = (yyvsp[-3].node)->type + (yyvsp[-2].node)->label + (yyvsp[-1].node)->type + (yyvsp[0].node)->label;
            }
#line 2627 "parser.cpp"
    break;

  case 40: /* augassign_op: yield_expr  */
#line 523 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2633 "parser.cpp"
    break;

  case 41: /* augassign_op: testlist  */
#line 524 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2639 "parser.cpp"
    break;

  case 42: /* annassign: EQUAL_SIGN test  */
#line 547 "parser.y"
                           {
                  Node* n =create_node("annassign_op");
                   n->children.push_back((yyvsp[-1].node));
                   n->children.push_back((yyvsp[0].node));
                   (yyval.node) = n;
                   (yyval.node)->type = (yyvsp[0].node)->type;
                  //  cout<<$$->type <<"HII"<<endl;
}
#line 2652 "parser.cpp"
    break;

  case 43: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep COMMA  */
#line 556 "parser.y"
                                                                         {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-2].node));
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                     (yyval.node)=n;
                    }
#line 2664 "parser.cpp"
    break;

  case 44: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep  */
#line 563 "parser.y"
                                                                   { 
                      Node* n =create_node("testlist_star_expr");
                      n->children.push_back((yyvsp[-1].node));
                      n->children.push_back((yyvsp[0].node));
                    }
#line 2674 "parser.cpp"
    break;

  case 45: /* testlist_star_expr: testlist_star_expr_opt1 COMMA  */
#line 568 "parser.y"
                                                  {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                    }
#line 2684 "parser.cpp"
    break;

  case 46: /* testlist_star_expr: testlist_star_expr_opt1  */
#line 573 "parser.y"
                                             { (yyval.node) = (yyvsp[0].node);}
#line 2690 "parser.cpp"
    break;

  case 47: /* testlist_star_expr_opt1: test  */
#line 577 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2696 "parser.cpp"
    break;

  case 48: /* testlist_star_expr_opt1: star_expr  */
#line 578 "parser.y"
                                   {(yyval.node)=(yyvsp[0].node);}
#line 2702 "parser.cpp"
    break;

  case 49: /* testlist_star_expr_rep: testlist_star_expr_rep COMMA testlist_star_expr_opt1  */
#line 581 "parser.y"
                                                          {
      Node* n =create_node("testlist_star_expr_rep");
      for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
        n->children.push_back((yyvsp[-2].node)->children[i]);
      }
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n;
  }
#line 2716 "parser.cpp"
    break;

  case 50: /* testlist_star_expr_rep: COMMA testlist_star_expr_opt1  */
#line 590 "parser.y"
                                  {(yyval.node) = NULL;}
#line 2722 "parser.cpp"
    break;

  case 51: /* augassign: PLUS_EQUAL  */
#line 592 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2728 "parser.cpp"
    break;

  case 52: /* augassign: MINUS_EQUAL  */
#line 593 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2734 "parser.cpp"
    break;

  case 53: /* augassign: TIMES_EQUAL  */
#line 594 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2740 "parser.cpp"
    break;

  case 54: /* augassign: AT_EQUAL  */
#line 595 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2746 "parser.cpp"
    break;

  case 55: /* augassign: DIVIDEDBY_EQUAL  */
#line 596 "parser.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2752 "parser.cpp"
    break;

  case 56: /* augassign: MODULO_EQUAL  */
#line 597 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2758 "parser.cpp"
    break;

  case 57: /* augassign: BITWISE_AND_EQUAL  */
#line 598 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2764 "parser.cpp"
    break;

  case 58: /* augassign: BITWISE_OR_EQUAL  */
#line 599 "parser.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 2770 "parser.cpp"
    break;

  case 59: /* augassign: BITWISE_XOR_EQUAL  */
#line 600 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2776 "parser.cpp"
    break;

  case 60: /* augassign: SHIFT_LEFT_EQUAL  */
#line 601 "parser.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 2782 "parser.cpp"
    break;

  case 61: /* augassign: SHIFT_RIGHT_EQUAL  */
#line 602 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2788 "parser.cpp"
    break;

  case 62: /* augassign: POWER_EQUAL  */
#line 603 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2794 "parser.cpp"
    break;

  case 63: /* augassign: FLOORDIV_EQUAL  */
#line 604 "parser.y"
                           {(yyval.node)=(yyvsp[0].node);}
#line 2800 "parser.cpp"
    break;

  case 64: /* del_stmt: DEL exprlist  */
#line 607 "parser.y"
                      {Node* n =create_node("del_stmt");
                         n->children.push_back((yyvsp[-1].node));
                         n->children.push_back((yyvsp[0].node));
                         (yyval.node)=n;
                          }
#line 2810 "parser.cpp"
    break;

  case 65: /* pass_stmt: PASS  */
#line 613 "parser.y"
               {(yyval.node)=(yyvsp[0].node);}
#line 2816 "parser.cpp"
    break;

  case 66: /* flow_stmt: break_stmt  */
#line 615 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2822 "parser.cpp"
    break;

  case 67: /* flow_stmt: continue_stmt  */
#line 616 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2828 "parser.cpp"
    break;

  case 68: /* flow_stmt: return_stmt  */
#line 617 "parser.y"
                       {(yyval.node)=(yyvsp[0].node); }
#line 2834 "parser.cpp"
    break;

  case 69: /* flow_stmt: yield_stmt  */
#line 618 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2840 "parser.cpp"
    break;

  case 70: /* break_stmt: BREAK  */
#line 621 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 2846 "parser.cpp"
    break;

  case 71: /* continue_stmt: CONTINUE  */
#line 623 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2852 "parser.cpp"
    break;

  case 72: /* return_stmt: RETURN testlist  */
#line 624 "parser.y"
                            {
              Node* n =create_node("return_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n;
              (yyval.node)->type = (yyvsp[0].node)->type;
            }
#line 2864 "parser.cpp"
    break;

  case 73: /* return_stmt: RETURN  */
#line 631 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "void";}
#line 2870 "parser.cpp"
    break;

  case 74: /* yield_stmt: yield_expr  */
#line 633 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2876 "parser.cpp"
    break;

  case 75: /* global_stmt: GLOBAL global_name_list  */
#line 634 "parser.y"
                                    {
              Node* n =create_node("global_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n; 
            }
#line 2887 "parser.cpp"
    break;

  case 76: /* global_name_list: global_name_list COMMA NAME  */
#line 641 "parser.y"
                                              {
                  Node* n =create_node("global_name_list");
                  for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
                    n->children.push_back((yyvsp[-2].node)->children[i]);
                  }
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  
                  (yyval.node)=n;
                }
#line 2902 "parser.cpp"
    break;

  case 77: /* global_name_list: NAME  */
#line 651 "parser.y"
                       { (yyval.node) = (yyvsp[0].node);}
#line 2908 "parser.cpp"
    break;

  case 78: /* compound_stmt: if_stmt  */
#line 653 "parser.y"
                       {if(yybye) cout<<"cmpd_stmnt 1 \n"; (yyval.node)=(yyvsp[0].node);}
#line 2914 "parser.cpp"
    break;

  case 79: /* compound_stmt: while_stmt  */
#line 654 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2920 "parser.cpp"
    break;

  case 80: /* compound_stmt: for_stmt  */
#line 655 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2926 "parser.cpp"
    break;

  case 81: /* compound_stmt: funcdef  */
#line 656 "parser.y"
                       {if(yybye) cout<<"cmpd_stmnt \n"; (yyval.node)=(yyvsp[0].node);}
#line 2932 "parser.cpp"
    break;

  case 82: /* compound_stmt: classdef  */
#line 657 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2938 "parser.cpp"
    break;

  case 83: /* compound_stmt: async_stmt  */
#line 658 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2944 "parser.cpp"
    break;

  case 87: /* if_stmt: IF test COLON suite elif_stmt_rep ELSE COLON suite  */
#line 668 "parser.y"
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
#line 2962 "parser.cpp"
    break;

  case 88: /* if_stmt: IF test COLON suite elif_stmt_rep  */
#line 681 "parser.y"
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
#line 2978 "parser.cpp"
    break;

  case 89: /* if_stmt: IF test COLON suite ELSE COLON suite  */
#line 692 "parser.y"
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
#line 2994 "parser.cpp"
    break;

  case 90: /* if_stmt: IF test COLON suite  */
#line 703 "parser.y"
                         { 
      Node* n=create_node("if_stmt");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
    }
#line 3007 "parser.cpp"
    break;

  case 91: /* elif_stmt_rep: elif_stmt_rep ELIF test COLON suite  */
#line 712 "parser.y"
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
#line 3023 "parser.cpp"
    break;

  case 92: /* elif_stmt_rep: ELIF test COLON suite  */
#line 723 "parser.y"
                           { 
      Node* n=create_node("elif_stmt_rep");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
    }
#line 3036 "parser.cpp"
    break;

  case 93: /* while_stmt: WHILE test COLON suite ELSE COLON suite  */
#line 732 "parser.y"
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
#line 3052 "parser.cpp"
    break;

  case 94: /* while_stmt: WHILE test COLON suite  */
#line 743 "parser.y"
                           { 
      Node* n=create_node("while_stmt");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
  }
#line 3065 "parser.cpp"
    break;

  case 95: /* for_stmt: FOR exprlist IN testlist COLON suite ELSE COLON suite  */
#line 752 "parser.y"
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
#line 3083 "parser.cpp"
    break;

  case 96: /* for_stmt: FOR exprlist IN testlist COLON suite  */
#line 765 "parser.y"
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
#line 3098 "parser.cpp"
    break;

  case 97: /* suite: simple_stmt  */
#line 776 "parser.y"
                    {if(yybye) cout<<"LINE 462 \n"; (yyval.node) = (yyvsp[0].node);}
#line 3104 "parser.cpp"
    break;

  case 98: /* suite: NEWLINE INDENT stmt_rep DEDENT  */
#line 777 "parser.y"
                                      {
        Node* n = create_node("Suite");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-2].node));
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        if((yyvsp[-1].node)->type != "")
          (yyval.node)->type = (yyvsp[-1].node)->type;
        else (yyval.node)->type = "void";
        if(YYDEB) cout<<"suite" <<(yyvsp[-1].node)->type <<endl;

      }
#line 3121 "parser.cpp"
    break;

  case 99: /* stmt_rep: stmt_rep stmt  */
#line 791 "parser.y"
                           {
            Node* n = create_node("Multi Statements");
            (yyval.node) = n;
            for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
              n->children.push_back((yyvsp[-1].node)->children[i]);
            }
            n->children.push_back((yyvsp[0].node));
            (yyval.node)->type = (yyvsp[0].node)->type;
          }
#line 3135 "parser.cpp"
    break;

  case 100: /* stmt_rep: stmt  */
#line 800 "parser.y"
                 {(yyval.node)=(yyvsp[0].node); }
#line 3141 "parser.cpp"
    break;

  case 101: /* test: or_test IF or_test ELSE test  */
#line 802 "parser.y"
                                    {
      Node* n = create_node("Test");
      (yyval.node) = n;
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
}
#line 3155 "parser.cpp"
    break;

  case 102: /* test: or_test  */
#line 811 "parser.y"
         {(yyval.node)=(yyvsp[0].node);}
#line 3161 "parser.cpp"
    break;

  case 103: /* test_nocond: or_test  */
#line 814 "parser.y"
          {(yyval.node) = (yyvsp[0].node);}
#line 3167 "parser.cpp"
    break;

  case 104: /* or_test: and_test or_test_rep  */
#line 818 "parser.y"
  {
    Node* n = create_node("OR Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3178 "parser.cpp"
    break;

  case 105: /* or_test: and_test  */
#line 824 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3184 "parser.cpp"
    break;

  case 106: /* or_test_rep: or_test_rep OR and_test  */
#line 827 "parser.y"
                           {
    Node* n = create_node("ORTestRep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3198 "parser.cpp"
    break;

  case 107: /* or_test_rep: OR and_test  */
#line 836 "parser.y"
               {Node* n = create_node("ORTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3207 "parser.cpp"
    break;

  case 108: /* and_test: not_test and_test_rep  */
#line 842 "parser.y"
                       {
    Node* n = create_node("And Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3218 "parser.cpp"
    break;

  case 109: /* and_test: not_test  */
#line 848 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3224 "parser.cpp"
    break;

  case 110: /* and_test_rep: and_test_rep AND not_test  */
#line 852 "parser.y"
  {
    Node* n = create_node("AndTestRep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3238 "parser.cpp"
    break;

  case 111: /* and_test_rep: AND not_test  */
#line 861 "parser.y"
                {Node* n = create_node("AndTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3247 "parser.cpp"
    break;

  case 112: /* not_test: NOT not_test  */
#line 869 "parser.y"
  {
    Node* n = create_node("Not Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3258 "parser.cpp"
    break;

  case 113: /* not_test: comparison  */
#line 875 "parser.y"
               {
    (yyval.node) =(yyvsp[0].node);
  }
#line 3266 "parser.cpp"
    break;

  case 114: /* comparison: expr comparison_rep  */
#line 880 "parser.y"
                     {
    Node* n = create_node("Comparison");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[-1].node)->line_number);
    // if($1->type != $2->type){
    //   diff_data($1->line_no);
    //           /* exit(1); */
    // }
    (yyval.node)->type = (yyvsp[-1].node)->type;

  }
#line 3284 "parser.cpp"
    break;

  case 115: /* comparison: expr  */
#line 893 "parser.y"
       {(yyval.node)=(yyvsp[0].node);}
#line 3290 "parser.cpp"
    break;

  case 116: /* comparison_rep: comparison_rep comp_op expr  */
#line 897 "parser.y"
                              {
    Node* n = create_node("Comparison Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3304 "parser.cpp"
    break;

  case 117: /* comparison_rep: comp_op expr  */
#line 906 "parser.y"
                {
   Node* n = create_node("Comparison Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
 }
#line 3316 "parser.cpp"
    break;

  case 118: /* comp_op: LESS_THAN  */
#line 914 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 3322 "parser.cpp"
    break;

  case 119: /* comp_op: GREATER_THAN  */
#line 915 "parser.y"
                      {(yyval.node) =(yyvsp[0].node);}
#line 3328 "parser.cpp"
    break;

  case 120: /* comp_op: EQUAL  */
#line 916 "parser.y"
               {(yyval.node) =(yyvsp[0].node);}
#line 3334 "parser.cpp"
    break;

  case 121: /* comp_op: GREATER_THAN_OR_EQUAL  */
#line 917 "parser.y"
                               {(yyval.node) =(yyvsp[0].node);}
#line 3340 "parser.cpp"
    break;

  case 122: /* comp_op: LESS_THAN_OR_EQUAL  */
#line 918 "parser.y"
                            {(yyval.node) =(yyvsp[0].node);}
#line 3346 "parser.cpp"
    break;

  case 123: /* comp_op: NOT_EQUAL  */
#line 919 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 3352 "parser.cpp"
    break;

  case 124: /* comp_op: IN  */
#line 920 "parser.y"
            {(yyval.node) =(yyvsp[0].node);}
#line 3358 "parser.cpp"
    break;

  case 125: /* comp_op: NOT IN  */
#line 921 "parser.y"
                {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3369 "parser.cpp"
    break;

  case 126: /* comp_op: IS  */
#line 927 "parser.y"
            {(yyval.node) =(yyvsp[0].node);}
#line 3375 "parser.cpp"
    break;

  case 127: /* comp_op: IS NOT  */
#line 928 "parser.y"
               {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3386 "parser.cpp"
    break;

  case 128: /* star_expr: TIMES expr  */
#line 936 "parser.y"
            {
    Node* n = create_node("Star Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3397 "parser.cpp"
    break;

  case 129: /* expr: xor_expr expr_rep  */
#line 944 "parser.y"
                   {
    Node* n = create_node("Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3408 "parser.cpp"
    break;

  case 130: /* expr: xor_expr  */
#line 950 "parser.y"
            {(yyval.node)=(yyvsp[0].node);}
#line 3414 "parser.cpp"
    break;

  case 131: /* expr_rep: expr_rep BITWISE_OR xor_expr  */
#line 953 "parser.y"
                               {
    Node* n = create_node("Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3428 "parser.cpp"
    break;

  case 132: /* expr_rep: BITWISE_OR xor_expr  */
#line 962 "parser.y"
                       {Node* n = create_node("Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3437 "parser.cpp"
    break;

  case 133: /* xor_expr: and_expr xor_expr_rep  */
#line 968 "parser.y"
                       {
    Node* n = create_node("XOR Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3448 "parser.cpp"
    break;

  case 134: /* xor_expr: and_expr  */
#line 974 "parser.y"
            {
    (yyval.node)=(yyvsp[0].node);
  }
#line 3456 "parser.cpp"
    break;

  case 135: /* xor_expr_rep: xor_expr_rep BITWISE_XOR and_expr  */
#line 979 "parser.y"
                                    {
    Node* n = create_node("XOR Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3470 "parser.cpp"
    break;

  case 136: /* xor_expr_rep: BITWISE_XOR and_expr  */
#line 988 "parser.y"
                       {Node* n = create_node("XOR Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3479 "parser.cpp"
    break;

  case 137: /* and_expr: shift_expr and_expr_rep  */
#line 994 "parser.y"
                         {
    Node* n = create_node("AND Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3490 "parser.cpp"
    break;

  case 138: /* and_expr: shift_expr  */
#line 1000 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3496 "parser.cpp"
    break;

  case 139: /* and_expr_rep: and_expr_rep BITWISE_AND shift_expr  */
#line 1003 "parser.y"
                                      {
    Node* n = create_node("AND Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node)); 
  }
#line 3510 "parser.cpp"
    break;

  case 140: /* and_expr_rep: BITWISE_AND shift_expr  */
#line 1012 "parser.y"
                         {Node* n = create_node("AND Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node)); }
#line 3519 "parser.cpp"
    break;

  case 141: /* shift_expr: arith_expr shift_expr_rep  */
#line 1018 "parser.y"
                           {
    Node* n = create_node("Shift Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3530 "parser.cpp"
    break;

  case 142: /* shift_expr: arith_expr  */
#line 1024 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3536 "parser.cpp"
    break;

  case 143: /* shift_expr_rep: shift_expr_rep shift_expr_rep_c1 arith_expr  */
#line 1027 "parser.y"
                                              {
    Node* n = create_node("Shift Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3550 "parser.cpp"
    break;

  case 144: /* shift_expr_rep: shift_expr_rep_c1 arith_expr  */
#line 1036 "parser.y"
                                {Node* n = create_node("Shift Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3559 "parser.cpp"
    break;

  case 145: /* shift_expr_rep_c1: SHIFT_LEFT  */
#line 1042 "parser.y"
            {
    (yyval.node) = (yyvsp[0].node);
  }
#line 3567 "parser.cpp"
    break;

  case 146: /* shift_expr_rep_c1: SHIFT_RIGHT  */
#line 1045 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 3573 "parser.cpp"
    break;

  case 147: /* arith_expr: term arith_expr_rep  */
#line 1048 "parser.y"
                     {
    Node* n = create_node("Arithmetic Expression");
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

    (yyval.node) = n;
    if((yyvsp[-1].node)->type != (yyvsp[0].node)->type)
    {
      if(((yyvsp[-1].node)->type == "int"|| (yyvsp[-1].node)->type =="float" ) && ((yyvsp[0].node)->type == "int"|| (yyvsp[0].node)->type =="float" ))
      (yyval.node)->type = "float";
      if(((yyvsp[-1].node)->type == "int"|| (yyvsp[-1].node)->type =="bool" ) && ((yyvsp[0].node)->type == "int"|| (yyvsp[0].node)->type =="bool" ))
      (yyval.node)->type = "int";
    }
    else 
      (yyval.node)->type = (yyvsp[-1].node)->type;
    // cout<<$$->type<< " "<<$1->line_number<<endl;
  }
#line 3595 "parser.cpp"
    break;

  case 148: /* arith_expr: term  */
#line 1065 "parser.y"
        { if(yybye) cout<<"term arith_expr: "<<endl;(yyval.node)=(yyvsp[0].node);}
#line 3601 "parser.cpp"
    break;

  case 149: /* arith_expr_rep: arith_expr_rep arith_expr_rep_c1 term  */
#line 1068 "parser.y"
                                        {
    Node* n = create_node("Arithmetic Expression Rep1");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
    {
      if(((yyvsp[-2].node)->type == "int"|| (yyvsp[-2].node)->type =="float" ) && ((yyvsp[0].node)->type == "int"|| (yyvsp[0].node)->type =="float" ))
      (yyval.node)->type = "float";
      else if(((yyvsp[-2].node)->type == "int"|| (yyvsp[-2].node)->type =="bool" ) && ((yyvsp[0].node)->type == "int"|| (yyvsp[0].node)->type =="bool" ))
      (yyval.node)->type = "int";
      else 
      check_type((yyvsp[-2].node)->type , (yyvsp[0].node)->type, (yyvsp[0].node)->line_number);
    }
    else 
      (yyval.node)->type = (yyvsp[0].node)->type;
    // cout<<$$->type <<" arth rep 1"<<endl;

  }
#line 3626 "parser.cpp"
    break;

  case 150: /* arith_expr_rep: arith_expr_rep_c1 term  */
#line 1088 "parser.y"
                         {Node* n = create_node("Arithmetic Expression Rep2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 3637 "parser.cpp"
    break;

  case 151: /* arith_expr_rep_c1: PLUS  */
#line 1096 "parser.y"
       { (yyval.node) = (yyvsp[0].node);}
#line 3643 "parser.cpp"
    break;

  case 152: /* arith_expr_rep_c1: MINUS  */
#line 1097 "parser.y"
          { (yyval.node) = (yyvsp[0].node);}
#line 3649 "parser.cpp"
    break;

  case 153: /* term: factor term_rep  */
#line 1100 "parser.y"
                 {
    if(yybye) cout<<"term factor term_rep: "<<endl;
    Node* n = create_node("TERM");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if((yyvsp[-1].node)->type != (yyvsp[0].node)->type)
    {
      if(((yyvsp[-1].node)->type == "int"|| (yyvsp[-1].node)->type =="float" ) && ((yyvsp[0].node)->type == "int"|| (yyvsp[0].node)->type =="float" ))
      (yyval.node)->type = "float";
      else if(((yyvsp[-1].node)->type == "int"|| (yyvsp[-1].node)->type =="bool" ) && ((yyvsp[0].node)->type == "int"|| (yyvsp[0].node)->type =="bool" ))
      (yyval.node)->type = "int";
      else 
      check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[0].node)->line_number);
    }
    else 
      (yyval.node)->type = (yyvsp[0].node)->type;
    // check_type($1->type , $2->type, $1->line_number);
    // if($1->type != $2->type)
    // {
    //   diff_data($1->line_no);
    //           /* exit(1); */
    // }
    // $$->type = $1->type;
  }
#line 3679 "parser.cpp"
    break;

  case 154: /* term: factor  */
#line 1125 "parser.y"
         {if(yybye) cout<<"factor term: "<<endl;(yyval.node)=(yyvsp[0].node);}
#line 3685 "parser.cpp"
    break;

  case 155: /* term_rep: term_rep term_rep_c1 factor  */
#line 1128 "parser.y"
                               {
    Node* n = create_node("TERM Rep");
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
  }
#line 3699 "parser.cpp"
    break;

  case 156: /* term_rep: term_rep_c1 factor  */
#line 1137 "parser.y"
                       { Node* n = create_node("TERM Rep");
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
    (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 3710 "parser.cpp"
    break;

  case 157: /* term_rep_c1: TIMES  */
#line 1144 "parser.y"
                    { (yyval.node) =(yyvsp[0].node);}
#line 3716 "parser.cpp"
    break;

  case 158: /* term_rep_c1: AT  */
#line 1145 "parser.y"
                 { (yyval.node) =(yyvsp[0].node);}
#line 3722 "parser.cpp"
    break;

  case 159: /* term_rep_c1: DIVIDEDBY  */
#line 1146 "parser.y"
                        { (yyval.node) =(yyvsp[0].node);}
#line 3728 "parser.cpp"
    break;

  case 160: /* term_rep_c1: MODULO  */
#line 1147 "parser.y"
                     { (yyval.node) =(yyvsp[0].node);}
#line 3734 "parser.cpp"
    break;

  case 161: /* term_rep_c1: FLOORDIV  */
#line 1148 "parser.y"
                       { (yyval.node) =(yyvsp[0].node);}
#line 3740 "parser.cpp"
    break;

  case 162: /* factor: factor_c1 factor  */
#line 1151 "parser.y"
                   {
    Node* n = create_node("Factor");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3751 "parser.cpp"
    break;

  case 163: /* factor: power  */
#line 1157 "parser.y"
          { if(yybye) cout<<"factor power: "<<endl;(yyval.node) = (yyvsp[0].node);}
#line 3757 "parser.cpp"
    break;

  case 164: /* factor_c1: PLUS  */
#line 1159 "parser.y"
                 { (yyval.node) =(yyvsp[0].node);}
#line 3763 "parser.cpp"
    break;

  case 165: /* factor_c1: MINUS  */
#line 1160 "parser.y"
                  { (yyval.node) =(yyvsp[0].node);}
#line 3769 "parser.cpp"
    break;

  case 166: /* factor_c1: BITWISE_NOT  */
#line 1161 "parser.y"
                        { (yyval.node) =(yyvsp[0].node);}
#line 3775 "parser.cpp"
    break;

  case 167: /* power: atom_expr power_opt  */
#line 1164 "parser.y"
                     {
    Node* n = create_node("Power");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type , (yyvsp[-1].node)->line_number);
    (yyval.node)->type = (yyvsp[-1].node)->type;

  }
#line 3789 "parser.cpp"
    break;

  case 168: /* power: atom_expr  */
#line 1173 "parser.y"
             {
    (yyval.node) = (yyvsp[0].node);
    if(yybye) cout<<"atom_expr power: "<<endl;(yyval.node)=(yyvsp[0].node);
  }
#line 3798 "parser.cpp"
    break;

  case 169: /* power_opt: POWER factor  */
#line 1179 "parser.y"
               {
    Node* n = create_node("Power Opt");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 3810 "parser.cpp"
    break;

  case 170: /* atom_expr: await_opt atom trailer_rep  */
#line 1188 "parser.y"
                            {
    Node* n = create_node("Atom Expression1");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    n->type = (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
  }
#line 3823 "parser.cpp"
    break;

  case 171: /* atom_expr: atom trailer_rep  */
#line 1196 "parser.y"
                   {
    Node* n = create_node("Atom Expression2");
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    n->type = (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
    if((gt->SYMVAL.find((yyvsp[-1].node)->label) != tab->SYMVAL.end()) && (yyvsp[0].node)->type == "Func")
    {
      vector<Param*> p = gt->SYMVAL[(yyvsp[-1].node)->label].params;
      if(p.size() > (yyvsp[0].node)->p_f.size())
      {
        cout<<"Lesser number of arguments for function call "<< (yyvsp[-1].node)->label <<" in line number "<< (yyvsp[-1].node)->line_number<<endl;
                /* exit(1); */
      }
      else if(p.size() < (yyvsp[0].node)->p_f.size())
      {
        cout<<"Greater number of arguments for function call "<< (yyvsp[-1].node)->label <<" in line number "<< (yyvsp[-1].node)->line_number<<endl;
                /* exit(1); */
      }
      else {
        for(int i=0;i<p.size();i++)
        {

          if(p[i]->par_type != (yyvsp[0].node)->p_f[i]->par_type)
          {
            if(isCompatible(p[i]->par_type,(yyvsp[0].node)->p_f[i]->par_type,(yyvsp[0].node)->p_f[i]->par_name))
            {

            }
            else{
              cout<<" Type mismatch for argument "<<i<<" in function call "<< (yyvsp[-1].node)->label <<" in line number "<<(yyvsp[-1].node)->line_number<<endl;
                      /* exit(1); */
            }
          }
        }
      }
      
    }
    else if((yyvsp[0].node)->type == "Func")
    {
      cout<<"Undeclared Function in line no : "<< (yyvsp[-1].node)->line_number<<endl;
              /* exit(1); */
    }
    (yyval.node) = n;
    if(yybye) cout<<"atom trailer_rep atom_expr: "<<endl;
    

  }
#line 3875 "parser.cpp"
    break;

  case 172: /* atom_expr: atom  */
#line 1243 "parser.y"
       {
    (yyval.node) = (yyvsp[0].node);
    // cout<<"atom " <<$$->type<<endl;
    if(yybye) cout<<"atom_expr atom: "<<endl; 
  }
#line 3885 "parser.cpp"
    break;

  case 173: /* await_opt: AWAIT  */
#line 1249 "parser.y"
                  {
  (yyval.node) = (yyvsp[0].node);
}
#line 3893 "parser.cpp"
    break;

  case 174: /* trailer_rep: trailer_rep trailer  */
#line 1254 "parser.y"
                      {
    if(yybye) cout<<"trailer_rep: "<<endl;
    Node* n = create_node("Trailer Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));
  }
#line 3907 "parser.cpp"
    break;

  case 175: /* trailer_rep: trailer  */
#line 1263 "parser.y"
            { 
    (yyval.node) =(yyvsp[0].node);
  }
#line 3915 "parser.cpp"
    break;

  case 176: /* atom: LPAREN atom_opt1 RPAREN  */
#line 1267 "parser.y"
                               {
        if(yybye) cout<<"atom atom_opt1: "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-2].node));
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        (yyval.node)->type = "Func";
      }
#line 3929 "parser.cpp"
    break;

  case 177: /* atom: LBRACKET atom_opt2 RBRACKET  */
#line 1276 "parser.y"
                                    {
        if(yybye) cout<<"atom atom_opt2: "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-2].node));
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        (yyval.node)->type = "list" + (yyvsp[-2].node)->type + (yyvsp[-1].node)->type +(yyvsp[0].node)->type;
        // cout<<$$->type<<" "<<yylineno<<endl;

      }
#line 3945 "parser.cpp"
    break;

  case 178: /* atom: LBRACKET RBRACKET  */
#line 1287 "parser.y"
                         { 
        if(yybye) cout<<"atom : "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
      }
#line 3957 "parser.cpp"
    break;

  case 179: /* atom: NAME  */
#line 1294 "parser.y"
              { (yyval.node) =(yyvsp[0].node);
                if(tab->SYMVAL.find((yyvsp[0].node)->label)!=tab->SYMVAL.end())
                {
                  // cout<<"Already declared"<<endl;
                  (yyval.node)->type = tab->SYMVAL[(yyvsp[0].node)->label].type;
                  // cout<<$$->type<<" Name "<< yylineno << " "<< $$->label<<endl;
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
#line 3984 "parser.cpp"
    break;

  case 180: /* atom: NUMBER  */
#line 1316 "parser.y"
                { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "int";}
#line 3990 "parser.cpp"
    break;

  case 181: /* atom: FLOAT  */
#line 1317 "parser.y"
              {(yyval.node) = (yyvsp[0].node); (yyval.node)->type = "float";}
#line 3996 "parser.cpp"
    break;

  case 182: /* atom: string_rep  */
#line 1318 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "string";}
#line 4002 "parser.cpp"
    break;

  case 183: /* atom: TRIPLEDOT  */
#line 1319 "parser.y"
                   { (yyval.node) =(yyvsp[0].node);}
#line 4008 "parser.cpp"
    break;

  case 184: /* atom: NONE  */
#line 1320 "parser.y"
              { (yyval.node) =(yyvsp[0].node);}
#line 4014 "parser.cpp"
    break;

  case 185: /* atom: TRUE_TOKEN  */
#line 1321 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";}
#line 4020 "parser.cpp"
    break;

  case 186: /* atom: FALSE_TOKEN  */
#line 1322 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";}
#line 4026 "parser.cpp"
    break;

  case 187: /* atom_opt1: yield_expr  */
#line 1324 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 4032 "parser.cpp"
    break;

  case 188: /* atom_opt1: testlist_comp  */
#line 1325 "parser.y"
                         {(yyval.node) = (yyvsp[0].node); if(yybye) cout<<"atom_opt1 testlist_comp: "<<endl;}
#line 4038 "parser.cpp"
    break;

  case 189: /* atom_opt2: testlist_comp  */
#line 1327 "parser.y"
                         {(yyval.node) =(yyvsp[0].node);}
#line 4044 "parser.cpp"
    break;

  case 190: /* string_rep: STRING  */
#line 1330 "parser.y"
         { (yyval.node) = (yyvsp[0].node);}
#line 4050 "parser.cpp"
    break;

  case 191: /* string_rep: string_rep STRING  */
#line 1331 "parser.y"
                      {
    Node* n = create_node("String Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));    
  }
#line 4063 "parser.cpp"
    break;

  case 192: /* testlist_comp: testlist_comp_c1 testlist_comp_c2  */
#line 1341 "parser.y"
                                   {
    Node* n = create_node("Testlist comp");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[-1].node)->type;
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
    
  }
#line 4077 "parser.cpp"
    break;

  case 193: /* testlist_comp: testlist_comp_c1  */
#line 1350 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 4083 "parser.cpp"
    break;

  case 194: /* testlist_comp_c1: test  */
#line 1353 "parser.y"
         {(yyval.node) = (yyvsp[0].node);}
#line 4089 "parser.cpp"
    break;

  case 195: /* testlist_comp_c1: star_expr  */
#line 1354 "parser.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 4095 "parser.cpp"
    break;

  case 196: /* testlist_comp_c2: comp_for  */
#line 1357 "parser.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 4101 "parser.cpp"
    break;

  case 197: /* testlist_comp_c2: testlist_comp_c2_rep COMMA  */
#line 1358 "parser.y"
                              {
    Node* n = create_node("Testlist Comp C2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[-1].node)->type;
    (yyval.node)->line_number = (yyvsp[0].node)->line_number;
  }
#line 4114 "parser.cpp"
    break;

  case 198: /* testlist_comp_c2: COMMA  */
#line 1366 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 4120 "parser.cpp"
    break;

  case 199: /* testlist_comp_c2: testlist_comp_c2_rep  */
#line 1367 "parser.y"
                        {(yyval.node) =(yyvsp[0].node);}
#line 4126 "parser.cpp"
    break;

  case 200: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA test  */
#line 1371 "parser.y"
  {
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    for(int i = 0; i < (yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    check_type((yyvsp[-2].node)->type , (yyvsp[0].node)->type , (yyvsp[-1].node)->line_number);
    (yyval.node)->type = (yyvsp[-2].node)->type;
  }
#line 4142 "parser.cpp"
    break;

  case 201: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA star_expr  */
#line 1382 "parser.y"
                                        {
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    for(int i = 0; i < (yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    check_type((yyvsp[-2].node)->type , (yyvsp[-1].node)->type , (yyvsp[-1].node)->line_number);
    (yyval.node)->type = (yyvsp[-2].node)->type;
  }
#line 4158 "parser.cpp"
    break;

  case 202: /* testlist_comp_c2_rep: COMMA test  */
#line 1393 "parser.y"
             {
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 4170 "parser.cpp"
    break;

  case 203: /* testlist_comp_c2_rep: COMMA star_expr  */
#line 1400 "parser.y"
                    { 
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 4182 "parser.cpp"
    break;

  case 204: /* trailer: LPAREN arglist RPAREN  */
#line 1409 "parser.y"
                       {
    if(yybye) cout<<"trailer: "<<endl;
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = "Func";
    (yyval.node)->line_number = (yyvsp[-2].node)->line_number;
    (yyval.node)->p_f = (yyvsp[-1].node)->p_f;

  }
#line 4199 "parser.cpp"
    break;

  case 205: /* trailer: LPAREN RPAREN  */
#line 1421 "parser.y"
                {
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
    (yyval.node)->type = "Func";
  }
#line 4212 "parser.cpp"
    break;

  case 206: /* trailer: LBRACKET subscriptlist RBRACKET  */
#line 1429 "parser.y"
                                    {
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-2].node)->line_number;
    (yyval.node)->type = (yyvsp[-2].node)->type + (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
  }
#line 4226 "parser.cpp"
    break;

  case 207: /* trailer: LBRACKET RBRACKET  */
#line 1438 "parser.y"
                    { 
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
  }
#line 4238 "parser.cpp"
    break;

  case 208: /* trailer: DOT NAME  */
#line 1445 "parser.y"
            {
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
  }
#line 4250 "parser.cpp"
    break;

  case 209: /* subscriptlist: subscript COMMA_subscript_rep COMMA_opt  */
#line 1454 "parser.y"
                                         {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4263 "parser.cpp"
    break;

  case 210: /* subscriptlist: subscript COMMA_opt  */
#line 1462 "parser.y"
                      {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4274 "parser.cpp"
    break;

  case 211: /* subscriptlist: subscript COMMA_subscript_rep  */
#line 1468 "parser.y"
                                {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4285 "parser.cpp"
    break;

  case 212: /* subscriptlist: subscript  */
#line 1474 "parser.y"
             {(yyval.node) =(yyvsp[0].node);}
#line 4291 "parser.cpp"
    break;

  case 213: /* COMMA_opt: COMMA  */
#line 1477 "parser.y"
        { (yyval.node) = (yyvsp[0].node);}
#line 4297 "parser.cpp"
    break;

  case 214: /* COMMA_subscript_rep: COMMA_subscript_rep COMMA subscript  */
#line 1481 "parser.y"
                                      {
    Node* n = create_node("Comma Subscript rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4311 "parser.cpp"
    break;

  case 215: /* COMMA_subscript_rep: COMMA subscript  */
#line 1490 "parser.y"
                   {
    Node* n = create_node("COMMA subscript rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4322 "parser.cpp"
    break;

  case 216: /* subscript: test  */
#line 1498 "parser.y"
       { (yyval.node) = (yyvsp[0].node);}
#line 4328 "parser.cpp"
    break;

  case 217: /* subscript: test COLON test sliceop  */
#line 1499 "parser.y"
                           {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4342 "parser.cpp"
    break;

  case 218: /* subscript: COLON test sliceop  */
#line 1508 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4354 "parser.cpp"
    break;

  case 219: /* subscript: test COLON sliceop  */
#line 1515 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4366 "parser.cpp"
    break;

  case 220: /* subscript: test COLON test  */
#line 1522 "parser.y"
                   {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4378 "parser.cpp"
    break;

  case 221: /* subscript: COLON sliceop  */
#line 1529 "parser.y"
                 {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4389 "parser.cpp"
    break;

  case 222: /* subscript: COLON test  */
#line 1535 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4400 "parser.cpp"
    break;

  case 223: /* subscript: test COLON  */
#line 1541 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4411 "parser.cpp"
    break;

  case 224: /* subscript: COLON  */
#line 1547 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 4417 "parser.cpp"
    break;

  case 225: /* sliceop: COLON test  */
#line 1549 "parser.y"
                    {
    Node* n = create_node("Slice OP");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4428 "parser.cpp"
    break;

  case 226: /* sliceop: COLON  */
#line 1555 "parser.y"
       {(yyval.node) = (yyvsp[0].node);}
#line 4434 "parser.cpp"
    break;

  case 227: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep COMMA  */
#line 1557 "parser.y"
                                                        {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4446 "parser.cpp"
    break;

  case 228: /* exprlist: expr_star_expr COMMA  */
#line 1564 "parser.y"
                      {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4457 "parser.cpp"
    break;

  case 229: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep  */
#line 1570 "parser.y"
                                         {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4468 "parser.cpp"
    break;

  case 230: /* exprlist: expr_star_expr  */
#line 1576 "parser.y"
                {(yyval.node) =(yyvsp[0].node);}
#line 4474 "parser.cpp"
    break;

  case 231: /* expr_star_expr: expr  */
#line 1578 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 4480 "parser.cpp"
    break;

  case 232: /* expr_star_expr: star_expr  */
#line 1579 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 4486 "parser.cpp"
    break;

  case 233: /* COMMA_expr_star_expr_rep: COMMA_expr_star_expr_rep COMMA expr_star_expr  */
#line 1582 "parser.y"
                                               {
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4500 "parser.cpp"
    break;

  case 234: /* COMMA_expr_star_expr_rep: COMMA expr_star_expr  */
#line 1591 "parser.y"
                       { 
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4511 "parser.cpp"
    break;

  case 235: /* testlist: test COMMA  */
#line 1606 "parser.y"
             {
    Node* n = create_node("Testlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4522 "parser.cpp"
    break;

  case 236: /* testlist: test  */
#line 1618 "parser.y"
        {(yyval.node) =(yyvsp[0].node);}
#line 4528 "parser.cpp"
    break;

  case 237: /* classdef: CLASS NAME LPAREN arglist RPAREN COLON suite  */
#line 1634 "parser.y"
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
#line 4544 "parser.cpp"
    break;

  case 238: /* classdef: CLASS NAME LPAREN RPAREN COLON suite  */
#line 1645 "parser.y"
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
#line 4559 "parser.cpp"
    break;

  case 239: /* classdef: CLASS NAME COLON suite  */
#line 1655 "parser.y"
                        {
    Node* n = create_node("Class Def");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4572 "parser.cpp"
    break;

  case 240: /* arglist: argument COMMA_argument_rep COMMA  */
#line 1665 "parser.y"
                                   {
    Node* n = create_node("Arglist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    Param* temp = new Param();
    temp->par_type=(yyvsp[-2].node)->type;
    temp->par_name=(yyvsp[-2].node)->label;
    (yyval.node)->p_f.push_back(temp);
    (yyval.node)->p_f.insert((yyval.node)->p_f.end(), (yyvsp[-1].node)->p_f.begin(), (yyvsp[-1].node)->p_f.end());
    // cout<<"Arglist 1";
    // for (auto it = $2->parameters.begin(); it != $2->parameters.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // cout<<endl;

  }
#line 4595 "parser.cpp"
    break;

  case 241: /* arglist: argument COMMA  */
#line 1683 "parser.y"
                  {
    Node* n = create_node("Arglist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    Param* temp = new Param();
    temp->par_type=(yyvsp[-1].node)->type;
    temp->par_name=(yyvsp[-1].node)->label;
    (yyval.node)->p_f.push_back(temp);
  }
#line 4610 "parser.cpp"
    break;

  case 242: /* arglist: argument COMMA_argument_rep  */
#line 1693 "parser.y"
                               {
    Node* n = create_node("Arglist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    // cout<<"Arglist 3 "<<endl;
    Param* temp = new Param();
    temp->par_type=(yyvsp[-1].node)->type;
    temp->par_name=(yyvsp[-1].node)->label;
    (yyval.node)->p_f.push_back(temp);
    (yyval.node)->p_f.insert((yyval.node)->p_f.end(), (yyvsp[0].node)->p_f.begin(), (yyvsp[0].node)->p_f.end());
    // for (auto it = $$->parameters.begin(); it != $$->parameters.end(); ++it) {
    //   std::cout << *it << " ";
    // }
    // cout<<endl;
  }
#line 4631 "parser.cpp"
    break;

  case 243: /* arglist: argument  */
#line 1709 "parser.y"
           {(yyval.node) =(yyvsp[0].node);
    Param* temp = new Param();
    temp->par_type=(yyvsp[0].node)->type;
    temp->par_name=(yyvsp[0].node)->label;
    (yyval.node)->p_f.push_back(temp);
  }
#line 4642 "parser.cpp"
    break;

  case 244: /* COMMA_argument_rep: COMMA_argument_rep COMMA argument  */
#line 1717 "parser.y"
                                    { 
    Node* n = create_node("Comma Argument rep1");
    (yyval.node) = n;
    // for(int i=0; i<$1->children.size(); i++){
    //   n->children.push_back($1->children[i]);
    // }
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

    Param* temp = new Param();
    temp->par_type=(yyvsp[0].node)->type;
    temp->par_name=(yyvsp[0].node)->label;
    (yyval.node)->p_f.insert((yyval.node)->p_f.end(), (yyvsp[-2].node)->p_f.begin(), (yyvsp[-2].node)->p_f.end());
    (yyval.node)->p_f.push_back(temp);
  }
#line 4663 "parser.cpp"
    break;

  case 245: /* COMMA_argument_rep: COMMA argument  */
#line 1733 "parser.y"
                   {
    Node* n = create_node("Comma Argument rep2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    Param* temp = new Param();
    temp->par_type=(yyvsp[0].node)->type;
    temp->par_name=(yyvsp[0].node)->label;
    (yyval.node)->p_f.push_back(temp);

  }
#line 4679 "parser.cpp"
    break;

  case 246: /* argument: test comp_for  */
#line 1746 "parser.y"
               {
    Node* n = create_node("Argument");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4690 "parser.cpp"
    break;

  case 247: /* argument: test EQUAL_SIGN test  */
#line 1752 "parser.y"
                         {
     Node* n = create_node("Argument");
     (yyval.node) = n;
     n->children.push_back((yyvsp[-2].node));
     n->children.push_back((yyvsp[-1].node));
  }
#line 4701 "parser.cpp"
    break;

  case 248: /* argument: POWER test  */
#line 1758 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));      
  }
#line 4712 "parser.cpp"
    break;

  case 249: /* argument: TIMES test  */
#line 1764 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));    
  }
#line 4723 "parser.cpp"
    break;

  case 250: /* argument: test  */
#line 1770 "parser.y"
       {(yyval.node) =(yyvsp[0].node);}
#line 4729 "parser.cpp"
    break;

  case 251: /* comp_iter: comp_for  */
#line 1772 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 4735 "parser.cpp"
    break;

  case 252: /* comp_iter: comp_if  */
#line 1773 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 4741 "parser.cpp"
    break;

  case 253: /* sync_comp_for: FOR exprlist IN or_test comp_iter  */
#line 1775 "parser.y"
                                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-4].node));
          n->children.push_back((yyvsp[-3].node));  
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));   
          n->children.push_back((yyvsp[0].node));   
}
#line 4755 "parser.cpp"
    break;

  case 254: /* sync_comp_for: FOR exprlist IN or_test  */
#line 1784 "parser.y"
                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-3].node));
          n->children.push_back((yyvsp[-2].node));  
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 4768 "parser.cpp"
    break;

  case 255: /* comp_for: ASYNC sync_comp_for  */
#line 1793 "parser.y"
                             { 
          Node* n = create_node("Comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));  }
#line 4778 "parser.cpp"
    break;

  case 256: /* comp_for: sync_comp_for  */
#line 1798 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 4784 "parser.cpp"
    break;

  case 257: /* comp_if: IF test_nocond comp_iter  */
#line 1800 "parser.y"
                                  {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
}
#line 4796 "parser.cpp"
    break;

  case 258: /* comp_if: IF test_nocond  */
#line 1807 "parser.y"
                        {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 4807 "parser.cpp"
    break;

  case 259: /* yield_expr: YIELD  */
#line 1813 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 4813 "parser.cpp"
    break;


#line 4817 "parser.cpp"

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

#line 1822 "parser.y"



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
        /*         /* exit(1); */ 
    }
    yyparse();
    cout<<endl;
    gt->PrintSYMTAB();
    fclose(yyin);
    simplify(root);
    printDot(root, output_filename);
    return 0;
}
void yyerror(const char* err) {
  std::cerr << "Error (line " << "): "<<yylineno << err << "token : " << yychar << std::endl;
}

