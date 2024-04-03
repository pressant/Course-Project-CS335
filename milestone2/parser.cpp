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
#include <regex>
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
      // cout<<s1<<" "<<s2<<endl;
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

#line 142 "parser.cpp"

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
  YYSYMBOL_class_name = 190,               /* class_name  */
  YYSYMBOL_classdef = 191,                 /* classdef  */
  YYSYMBOL_arglist = 192,                  /* arglist  */
  YYSYMBOL_COMMA_argument_rep = 193,       /* COMMA_argument_rep  */
  YYSYMBOL_argument = 194,                 /* argument  */
  YYSYMBOL_comp_iter = 195,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 196,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 197,                 /* comp_for  */
  YYSYMBOL_comp_if = 198,                  /* comp_if  */
  YYSYMBOL_yield_expr = 199                /* yield_expr  */
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
#define YYFINAL  104
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  260
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  373

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
       0,   127,   127,   133,   140,   148,   157,   158,   160,   186,
     223,   262,   271,   278,   287,   310,   327,   361,   368,   380,
     381,   384,   391,   399,   406,   415,   425,   433,   434,   435,
     436,   437,   439,   480,   483,   491,   494,   500,   513,   517,
     525,   526,   549,   558,   565,   570,   575,   579,   580,   583,
     592,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   609,   615,   617,   618,   619,   620,
     623,   625,   626,   633,   635,   636,   643,   653,   655,   656,
     657,   658,   659,   660,   663,   666,   667,   670,   683,   694,
     705,   714,   725,   734,   745,   754,   767,   778,   779,   793,
     802,   804,   813,   816,   819,   826,   829,   838,   844,   850,
     853,   863,   870,   877,   882,   895,   899,   908,   916,   917,
     918,   919,   920,   921,   922,   923,   929,   930,   938,   946,
     952,   955,   964,   970,   976,   981,   990,   996,  1002,  1005,
    1014,  1020,  1026,  1029,  1038,  1044,  1047,  1050,  1067,  1070,
    1090,  1098,  1099,  1102,  1127,  1130,  1139,  1146,  1147,  1148,
    1149,  1150,  1153,  1159,  1161,  1162,  1163,  1166,  1175,  1181,
    1190,  1198,  1257,  1263,  1268,  1277,  1281,  1291,  1302,  1309,
    1331,  1332,  1333,  1334,  1335,  1336,  1337,  1339,  1340,  1342,
    1345,  1346,  1356,  1365,  1368,  1369,  1372,  1373,  1381,  1382,
    1385,  1397,  1408,  1415,  1424,  1436,  1444,  1453,  1460,  1469,
    1477,  1483,  1489,  1492,  1496,  1505,  1513,  1514,  1523,  1530,
    1537,  1544,  1550,  1556,  1562,  1564,  1570,  1572,  1579,  1585,
    1591,  1593,  1594,  1597,  1606,  1621,  1633,  1650,  1673,  1708,
    1741,  1775,  1793,  1803,  1819,  1827,  1843,  1856,  1862,  1868,
    1874,  1880,  1882,  1883,  1885,  1894,  1903,  1908,  1910,  1917,
    1923
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
  "expr_star_expr", "COMMA_expr_star_expr_rep", "testlist", "class_name",
  "classdef", "arglist", "COMMA_argument_rep", "argument", "comp_iter",
  "sync_comp_for", "comp_for", "comp_if", "yield_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-248)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,    34,  1082,  -248,    77,    56,  1082,    77,    70,  1082,
     140,  1082,  -248,  -248,  -248,  -248,  -248,   148,  -248,   701,
     761,  -248,    83,   306,    26,  -248,  -248,  -248,    18,  -248,
     705,    37,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,    87,    99,   115,  -248,
    -248,   200,    89,    91,    98,   134,   152,   173,   148,  -248,
     111,    44,    66,   120,    -4,  -248,  -248,  -248,    96,  -248,
    -248,  -248,   154,   118,  -248,   129,  -248,  -248,   132,  -248,
    -248,  -248,  -248,   133,  -248,  -248,  -248,   142,  -248,    45,
    -248,  -248,   141,  -248,  -248,  -248,  -248,  -248,    46,   110,
    -248,   480,    19,   208,  1082,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
     913,   930,   143,  1082,  1082,   171,  1082,   194,  -248,   182,
     203,  -248,  -248,  -248,  -248,  -248,  -248,   200,   148,   148,
     172,   148,   175,   148,   174,  -248,  -248,   134,   148,  -248,
    -248,   152,   148,  -248,  -248,  -248,  -248,  -248,   173,   148,
    -248,   148,  -248,    66,   624,   807,   228,    66,  -248,  -248,
     684,   528,  -248,  1082,    77,   163,   528,   233,   528,  -248,
      77,   212,   930,  -248,   167,  -248,  -248,  -248,   128,  -248,
     176,   528,  1082,  -248,  -248,  -248,   576,   177,   164,  -248,
    -248,  -248,  -248,  -248,   930,   230,  -248,  1082,  -248,  1082,
    -248,  -248,   148,  -248,  -248,   148,  -248,   148,  -248,   148,
     148,  -248,   148,  -248,   148,  -248,  -248,    66,  1082,  1082,
    -248,    79,   180,   170,  -248,   990,   178,   183,   181,  -248,
    -248,   184,   187,   239,  -248,  -248,   186,  -248,    77,   238,
    -248,    25,   250,  -248,  -248,  -248,   930,   253,   265,  -248,
    -248,   196,  -248,  -248,   267,  -248,  -248,  1082,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  1082,
    -248,  -248,   853,   199,  1082,   201,  -248,   990,  -248,  1036,
    -248,   204,   528,   202,   432,   528,  -248,   206,   207,  1082,
      97,  1082,  -248,  -248,  -248,   209,   210,   528,   215,  -248,
    -248,  -248,   853,  -248,  -248,   201,  -248,  -248,  1036,  -248,
    -248,   528,  -248,   372,   261,   528,   528,   214,   216,  1082,
     109,   282,   253,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,   217,  -248,  -248,   528,   528,   218,  1082,  -248,  -248,
    -248,   223,  -248,   528,  -248,  -248,   528,   109,  -248,  -248,
    -248,  -248,  -248
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   179,   181,     3,     7,   186,   173,    65,   184,    70,
     185,     0,    73,    71,     0,     0,     0,     0,     0,     0,
       0,     0,   260,   180,   190,   164,   165,     0,   166,     0,
       0,   183,     0,     0,     0,    81,     6,    19,     0,    27,
      33,    46,    28,    29,    30,    66,    67,    68,    69,    31,
      20,    83,    78,    79,    80,    47,   102,   105,   109,   113,
      48,   115,   130,   134,   138,   142,   148,   154,     0,   163,
     168,     0,   172,   182,     0,    82,    74,   237,   236,    72,
     232,   231,     0,   230,     8,     0,    64,    77,    75,   112,
      85,    84,    86,     0,   128,   194,   195,     0,   188,   193,
     187,   178,     0,   189,     1,     2,     4,     5,     0,     0,
      21,     0,     0,     0,     0,    51,    52,    53,    55,    63,
      56,    54,    57,    58,    59,    61,    60,    62,    32,    35,
       0,    45,    44,     0,     0,   104,     0,   108,   124,   126,
       0,   118,   119,   122,   121,   120,   123,   114,     0,     0,
     129,     0,   133,     0,   137,   145,   146,   141,     0,   151,
     152,   147,     0,   157,   159,   161,   160,   158,   153,     0,
     162,     0,   167,     0,     0,     0,     0,   171,   175,   191,
       0,     0,   235,     0,   228,   229,     0,     0,     0,   176,
       0,     0,   198,   192,   199,   257,   196,   177,    13,    12,
       0,     0,     0,    23,    26,    22,     0,    38,    36,    42,
      37,    41,    40,    50,    43,     0,   107,     0,   111,     0,
     127,   125,     0,   117,   132,     0,   136,     0,   140,     0,
       0,   144,     0,   150,     0,   156,   169,   170,     0,     0,
     205,   251,     0,   244,   207,   224,   216,     0,   212,   208,
     174,     0,     0,     0,    97,   240,     0,   234,   227,    94,
      76,    90,     0,   256,   202,   203,   197,     0,     0,    11,
      10,     0,    24,    25,     0,    34,    49,     0,   106,   110,
     116,   131,   135,   139,   143,   149,   155,   250,   249,     0,
     247,   204,   242,   243,   226,   222,   221,   223,   206,   213,
     210,   211,     0,     0,     0,     0,   233,     0,     0,     0,
      88,     0,   200,   201,    15,    17,    14,     0,     0,   101,
     248,   246,   241,   225,   218,   220,   219,   215,   213,   209,
     239,     0,   100,     0,    96,     0,     0,     0,     0,     0,
     255,     0,     0,     9,    39,   245,   217,   214,   238,    98,
      99,     0,    93,    89,     0,     0,     0,     0,   254,   252,
     253,     0,    16,     0,    92,    87,     0,   259,   103,    18,
      95,    91,   258
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -248,  -248,  -248,  -248,   273,  -248,  -247,  -248,   -31,     0,
    -248,   -95,  -248,  -248,  -248,  -248,    86,  -248,  -116,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,   275,  -158,  -248,   -11,
    -248,  -125,  -248,  -111,  -248,   -16,  -248,  -248,   149,    -8,
     -10,  -248,  -124,  -248,  -127,  -248,  -122,  -248,   144,  -126,
    -248,   136,  -102,  -248,   131,   -55,  -248,  -248,  -248,  -248,
    -248,   127,   232,  -248,  -248,  -248,   276,  -248,  -248,  -248,
    -135,  -248,     4,  -248,  -172,  -164,    -5,  -132,  -248,  -101,
    -248,  -248,   138,  -248,  -237,   -60,   117,   -88,  -248,   -15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    32,    33,    34,    35,   109,   200,   316,    36,   254,
     112,    38,    39,   128,   208,   210,   129,    40,    41,   132,
     130,    42,    43,    44,    45,    46,    47,    48,    49,    88,
      50,    51,    91,    52,   310,    53,    54,   255,   333,    55,
     367,    56,   135,    57,   137,    58,    59,   147,   148,    60,
      61,   150,    62,   152,    63,   154,    64,   157,   158,    65,
     161,   162,    66,   168,   169,    67,    68,    69,   172,    70,
      71,   177,    72,    97,   102,    73,    98,    99,   193,   194,
     178,   247,   300,   301,   248,   296,    82,    83,   185,    79,
      74,    75,   242,   293,   243,   358,   195,   359,   360,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    78,   107,    89,    81,    85,    80,    81,   215,    80,
      93,   196,    86,   170,   100,   213,   204,    94,    95,    95,
     314,    96,    96,   216,   226,   224,   110,   205,   259,   211,
     261,   228,   231,    37,     1,     2,   308,    77,     3,     4,
       5,     6,   250,   270,     7,     8,     9,     1,     2,   198,
      10,    11,   257,     5,    12,   321,    13,    14,     8,    84,
     233,    15,   180,    10,    16,   309,    17,    18,    19,   181,
      20,   190,    21,    87,    22,    23,    24,    25,    26,    27,
       1,     2,   256,   104,   191,   345,     5,     6,    23,    24,
      28,     8,   108,   111,   206,   362,    10,    29,   276,    30,
     282,   281,   250,   209,   284,   190,   278,   283,   338,   131,
      29,   273,    30,   199,   235,   212,   236,   192,   191,    78,
     218,    23,    24,    25,    26,    27,   306,   327,   133,    31,
     285,   324,   174,   326,   175,   190,    28,   339,   223,   136,
     176,   134,    31,    29,   330,    30,   149,   334,   191,   151,
     357,     1,     2,   290,   153,   289,   347,     5,     6,   343,
     171,   346,     8,   241,   246,   179,    14,    10,   182,   241,
      15,   183,    78,   348,    81,    31,    80,   352,   353,   286,
      81,   264,    80,   201,   265,   262,   340,   202,   155,   156,
     184,   271,    23,    24,    25,    26,   364,   365,   159,   160,
     267,   268,   186,   279,   187,   370,   188,    28,   371,   189,
     197,   207,   280,   217,    29,   214,    30,   138,   219,   220,
     221,   163,   139,   164,   165,   166,   167,   287,   288,   225,
     229,   249,   368,   227,   295,   258,   260,   140,   190,   266,
     114,   277,   292,   269,   304,   274,    31,   291,    81,   307,
      80,   297,   298,   299,   303,   312,   198,   302,   313,   305,
     141,   142,   143,   144,   145,   146,   319,   311,   315,   317,
     318,   322,   351,   332,   294,   331,   328,   341,   320,   335,
     336,   241,   342,   323,   344,   361,   325,   354,   246,   355,
     363,   366,   369,    90,   275,    92,   222,   232,   337,   234,
     237,   230,   350,   173,    37,   329,   103,   372,   263,     1,
       2,   241,     0,   105,   106,     5,     6,   246,   252,     7,
       8,     9,     0,     0,     0,    10,    11,     0,   356,    12,
       0,    13,    14,    37,     0,     0,    15,     0,     0,    16,
       0,    17,    18,    19,     0,    20,     0,    21,     0,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     0,
       0,     0,    29,     0,    30,     1,     2,     0,   349,     0,
       0,     5,     6,     0,     0,     7,     8,     9,     0,     0,
       0,    10,    11,     0,     0,    12,     0,    13,    14,     0,
       0,     0,    15,     0,    31,    16,     0,    17,    18,    19,
       0,    20,     0,    21,     0,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     1,     2,     0,    29,     0,
      30,     5,     6,     0,     0,     7,     8,     9,     0,     0,
       0,    10,    11,     0,     0,    12,     0,    13,    14,     0,
       0,     0,    15,     0,     0,    16,     0,    17,    18,    19,
      31,    20,     0,    21,     0,    22,    23,    24,    25,    26,
      27,     0,     0,     1,     2,     0,     0,     0,   203,     5,
       6,    28,     0,     7,     8,     9,     0,     0,    29,    10,
      30,     0,     0,    12,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    19,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,     0,
      31,     1,     2,     0,     0,     0,   253,     5,     6,    28,
       0,     7,     8,     9,     0,     0,    29,    10,    30,     0,
       0,    12,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    19,     0,     0,     0,     0,
       0,    22,    23,    24,    25,    26,    27,     0,    31,     1,
       2,     0,     0,     0,   272,     5,     6,    28,     0,     7,
       8,     9,     0,     0,    29,    10,    30,     0,     0,    12,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,     0,    31,     1,     2,     0,
       0,     0,     0,     5,     6,    28,     0,     0,     8,     0,
       0,     0,    29,    10,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,   238,   239,    31,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     1,     2,     0,
      29,   240,    30,     5,     6,     0,     0,     0,     8,     0,
       0,     0,     0,    10,     1,     2,     0,     0,     0,     0,
       5,     6,     0,     0,     0,     8,     0,     0,     0,     0,
      10,    19,    31,     0,     0,     0,     0,     0,    23,    24,
      25,    26,   238,   239,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    28,    22,    23,    24,    25,    26,    27,
      29,   251,    30,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     1,     2,     0,    29,     0,    30,
       5,     6,     0,     0,     0,     8,     0,     0,   113,     0,
      10,   114,    31,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,     0,    19,    31,
       0,     0,     0,     0,     0,    23,    24,    25,    26,    27,
       1,     2,     0,     0,     0,     0,     5,     6,     0,     0,
      28,     8,     0,     0,     0,     0,    10,    29,     0,    30,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,     0,     1,     2,     0,    31,
       0,     0,     5,     6,     0,     0,    28,     8,     0,     0,
       0,     0,    10,    29,     0,    30,   244,     0,     0,     0,
     245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,   238,   239,     0,     0,    31,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,     1,     2,     0,    29,
       0,    30,     5,     6,     0,     0,     0,     8,     0,     0,
       0,     0,    10,     1,     2,     0,     0,     0,     0,     5,
       6,     0,     0,     0,     8,     0,     0,     0,     0,    10,
      19,    31,     0,     0,     0,     0,    22,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,    28,     0,    23,    24,    25,    26,    27,    29,
       0,    30,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,     0,     1,     2,     0,    29,     0,    30,     5,
       6,     0,     0,     0,     8,     0,     0,     0,     0,    10,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    31,     0,
       0,     0,     0,     0,    23,    24,    25,    26,     0,     1,
       2,     0,     0,     0,     0,     5,     6,     0,     0,    28,
       8,     0,     0,     0,     0,    10,    29,     0,    30,     0,
       0,     0,     0,   294,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,     0,     1,     2,     0,    31,     0,
       0,     5,     6,     0,     0,    28,     8,     0,     0,     0,
       0,    10,    29,     0,    30,     0,     0,     0,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     0,     0,     0,    29,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31
};

static const yytype_int16 yycheck[] =
{
       0,    12,    33,    19,    14,    16,    14,    17,   133,    17,
      21,    99,    17,    68,    29,   131,   111,    27,    29,    30,
     267,    29,    30,   134,   151,   149,     8,     8,   186,   130,
     188,   153,   158,    33,     3,     4,    11,     3,     7,     8,
       9,    10,   177,   201,    13,    14,    15,     3,     4,     3,
      19,    20,   184,     9,    23,   292,    25,    26,    14,     3,
     162,    30,    66,    19,    33,    40,    35,    36,    37,    73,
      39,    26,    41,     3,    43,    44,    45,    46,    47,    48,
       3,     4,   183,     0,    39,   322,     9,    10,    44,    45,
      59,    14,    66,    75,    75,   342,    19,    66,   214,    68,
     227,   225,   237,   114,   230,    26,   217,   229,    11,    72,
      66,   206,    68,    67,   169,   130,   171,    72,    39,   130,
     136,    44,    45,    46,    47,    48,   258,   299,    41,    98,
     232,   295,    66,   297,    68,    26,    59,    40,   148,    24,
      74,    42,    98,    66,   302,    68,    57,   305,    39,    58,
      41,     3,     4,   241,    56,    76,   328,     9,    10,   317,
      49,   325,    14,   174,   175,    45,    26,    19,    72,   180,
      30,    17,   183,   331,   184,    98,   184,   335,   336,   234,
     190,   192,   190,    73,   192,   190,   311,    77,    54,    55,
      72,   202,    44,    45,    46,    47,   354,   355,    46,    47,
      72,    73,    73,   219,    72,   363,    73,    59,   366,    67,
      69,     3,   222,    42,    66,    72,    68,    17,    24,    37,
      17,    48,    22,    50,    51,    52,    53,   238,   239,    57,
      56,     3,   357,    58,   245,    72,     3,    37,    26,    72,
      76,    11,    72,    67,     5,    68,    98,    67,   258,    11,
     258,    73,    69,    72,    67,   266,     3,    73,   266,    73,
      60,    61,    62,    63,    64,    65,   277,    17,     3,    73,
       3,    72,    11,   304,    73,    73,    72,    68,   289,    73,
      73,   292,    72,   294,    69,     3,   297,    73,   299,    73,
      73,    73,    69,    20,   208,    20,   147,   161,   309,   168,
     173,   157,   333,    71,   304,   301,    30,   367,   191,     3,
       4,   322,    -1,     7,     8,     9,    10,   328,   180,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    -1,   339,    23,
      -1,    25,    26,   333,    -1,    -1,    30,    -1,    -1,    33,
      -1,    35,    36,    37,    -1,    39,    -1,    41,    -1,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    68,     3,     4,    -1,     6,    -1,
      -1,     9,    10,    -1,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    98,    33,    -1,    35,    36,    37,
      -1,    39,    -1,    41,    -1,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,     3,     4,    -1,    66,    -1,
      68,     9,    10,    -1,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    -1,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    33,    -1,    35,    36,    37,
      98,    39,    -1,    41,    -1,    43,    44,    45,    46,    47,
      48,    -1,    -1,     3,     4,    -1,    -1,    -1,     8,     9,
      10,    59,    -1,    13,    14,    15,    -1,    -1,    66,    19,
      68,    -1,    -1,    23,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    -1,
      98,     3,     4,    -1,    -1,    -1,     8,     9,    10,    59,
      -1,    13,    14,    15,    -1,    -1,    66,    19,    68,    -1,
      -1,    23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    98,     3,
       4,    -1,    -1,    -1,     8,     9,    10,    59,    -1,    13,
      14,    15,    -1,    -1,    66,    19,    68,    -1,    -1,    23,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    -1,    98,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    59,    -1,    -1,    14,    -1,
      -1,    -1,    66,    19,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,     3,     4,    -1,
      66,    67,    68,     9,    10,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    19,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      19,    37,    98,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    59,    43,    44,    45,    46,    47,    48,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,     3,     4,    -1,    66,    -1,    68,
       9,    10,    -1,    -1,    -1,    14,    -1,    -1,    73,    -1,
      19,    76,    98,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    -1,    37,    98,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    -1,    -1,
      59,    14,    -1,    -1,    -1,    -1,    19,    66,    -1,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,     3,     4,    -1,    98,
      -1,    -1,     9,    10,    -1,    -1,    59,    14,    -1,    -1,
      -1,    -1,    19,    66,    -1,    68,    69,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,     3,     4,    -1,    66,
      -1,    68,     9,    10,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    19,     3,     4,    -1,    -1,    -1,    -1,     9,
      10,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,
      37,    98,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    59,    -1,    44,    45,    46,    47,    48,    66,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,     3,     4,    -1,    66,    -1,    68,     9,
      10,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    98,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    -1,    -1,    59,
      14,    -1,    -1,    -1,    -1,    19,    66,    -1,    68,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,     3,     4,    -1,    98,    -1,
      -1,     9,    10,    -1,    -1,    59,    14,    -1,    -1,    -1,
      -1,    19,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98
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
     169,   170,   172,   175,   190,   191,   199,     3,   139,   189,
     149,   150,   186,   187,     3,   139,   186,     3,   129,   145,
     104,   132,   136,   139,   150,   139,   149,   173,   176,   177,
     199,    69,   174,   176,     0,     7,     8,   108,    66,   105,
       8,    75,   110,    73,    76,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   113,   116,
     120,    72,   119,    41,    42,   142,    24,   144,    17,    22,
      37,    60,    61,    62,    63,    64,    65,   147,   148,    57,
     151,    58,   153,    56,   155,    54,    55,   157,   158,    46,
      47,   160,   161,    48,    50,    51,    52,    53,   163,   164,
     165,    49,   168,   172,    66,    68,    74,   171,   180,    45,
      66,    73,    72,    17,    72,   188,    73,    72,    73,    67,
      26,    39,    72,   178,   179,   196,   197,    69,     3,    67,
     106,    73,    77,     8,   111,     8,    75,     3,   114,   139,
     115,   189,   199,   118,    72,   141,   143,    42,   145,    24,
      37,    17,   148,   150,   152,    57,   154,    58,   156,    56,
     158,   159,   161,   162,   164,   165,   165,   171,    48,    49,
      67,   139,   192,   194,    69,    73,   139,   181,   184,     3,
     180,    67,   192,     8,   109,   137,   189,   187,    72,   137,
       3,   137,   186,   196,   139,   149,    72,    72,    73,    67,
     137,   139,     8,   111,    68,   116,   118,    11,   143,   145,
     150,   152,   154,   156,   159,   162,   165,   139,   139,    76,
     197,    67,    72,   193,    73,   139,   185,    73,    69,    72,
     182,   183,    73,    67,     5,    73,   187,    11,    11,    40,
     134,    17,   139,   149,   106,     3,   107,    73,     3,   139,
     139,   194,    72,   139,   185,   139,   185,   184,    72,   182,
     137,    73,   108,   138,   137,    73,    73,   139,    11,    40,
     141,    68,    72,   137,    69,   194,   185,   184,   137,     6,
     108,    11,   137,   137,    73,    73,   139,    41,   195,   197,
     198,     3,   106,    73,   137,   137,    73,   140,   141,    69,
     137,   137,   195
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
     186,   187,   187,   188,   188,   189,   189,   190,   191,   191,
     191,   192,   192,   192,   192,   193,   193,   194,   194,   194,
     194,   194,   195,   195,   196,   196,   197,   197,   198,   198,
     199
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
       1,     1,     1,     3,     2,     2,     1,     2,     6,     5,
       3,     3,     2,     2,     1,     3,     2,     2,     3,     2,
       2,     1,     1,     1,     5,     4,     2,     1,     3,     2,
       1
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
#line 127 "parser.y"
                               {
    if(yybye) cout<<"LINE 107";
    (yyval.node) = root;
    root->children.push_back((yyvsp[-1].node));
    root->children.push_back((yyvsp[0].node));
  }
#line 2080 "parser.cpp"
    break;

  case 3: /* file_input: ENDMARKER  */
#line 133 "parser.y"
              {
    if(yybye) cout<<"LINE 115";
    (yyval.node) = NULL;
    }
#line 2089 "parser.cpp"
    break;

  case 4: /* newline_stat_rep: newline_stat_rep NEWLINE  */
#line 140 "parser.y"
                             {
    if(yybye) cout<<"LINE 119";
    Node* n = create_node("newline_stat_rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
  }
#line 2102 "parser.cpp"
    break;

  case 5: /* newline_stat_rep: newline_stat_rep stmt  */
#line 148 "parser.y"
                          { 
    if(yybye) cout<<"LINE 126";
    Node* n = create_node("newline_stat_rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));
  }
#line 2116 "parser.cpp"
    break;

  case 6: /* newline_stat_rep: stmt  */
#line 157 "parser.y"
         { (yyval.node) = (yyvsp[0].node) ; if(yybye) cout<<"LINE 132"; (yyval.node) = (yyvsp[0].node);}
#line 2122 "parser.cpp"
    break;

  case 7: /* newline_stat_rep: NEWLINE  */
#line 158 "parser.y"
            {  if(yybye) cout<<"LINE 133"; cout<<yylineno<<endl;}
#line 2128 "parser.cpp"
    break;

  case 8: /* funcname: DEF NAME  */
#line 160 "parser.y"
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
                      exit(1);
             }
            // cout<<"funcname "<<$1->line_number<<endl;
          }
#line 2157 "parser.cpp"
    break;

  case 9: /* funcdef: funcname parameters ARROW test COLON suite  */
#line 186 "parser.y"
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
#line 2199 "parser.cpp"
    break;

  case 10: /* funcdef: funcname parameters COLON suite  */
#line 223 "parser.y"
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
#line 2241 "parser.cpp"
    break;

  case 11: /* parameters: LPAREN typedargslist RPAREN  */
#line 262 "parser.y"
                                         {
                Node* n = create_node("Parameters");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                n->children.push_back((yyvsp[0].node));
                n->count=(yyvsp[-1].node)->count;
                n->p_f=(yyvsp[-1].node)->p_f;
                (yyval.node)=n;
            }
#line 2255 "parser.cpp"
    break;

  case 12: /* parameters: LPAREN RPAREN  */
#line 271 "parser.y"
                           {
                (yyval.node) = create_node("Parameters");
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 2265 "parser.cpp"
    break;

  case 13: /* typedargslist: NAME  */
#line 278 "parser.y"
                     {
                  Node *n = create_node("Typedargslist1");
                  n->children.push_back((yyvsp[0].node));
                  Param* temp=new Param();
                  temp->par_name=(yyvsp[0].node)->label;
                  n->p_f.push_back(temp);
                  n->count=1;
                  (yyval.node)=n;
                  }
#line 2279 "parser.cpp"
    break;

  case 14: /* typedargslist: NAME COLON datatype  */
#line 287 "parser.y"
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
#line 2307 "parser.cpp"
    break;

  case 15: /* typedargslist: NAME COMMA typedargslist  */
#line 310 "parser.y"
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
#line 2329 "parser.cpp"
    break;

  case 16: /* typedargslist: NAME COLON datatype COMMA typedargslist  */
#line 327 "parser.y"
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
#line 2366 "parser.cpp"
    break;

  case 17: /* datatype: NAME  */
#line 361 "parser.y"
                {
              if(yybye) cout<<"LINE 215";
              Node *n = create_node("Datatype");
              n->children.push_back((yyvsp[0].node));
              n->label=(yyvsp[0].node)->label;
              (yyval.node) = n;
            }
#line 2378 "parser.cpp"
    break;

  case 18: /* datatype: NAME LBRACKET NAME RBRACKET  */
#line 368 "parser.y"
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
#line 2393 "parser.cpp"
    break;

  case 19: /* stmt: simple_stmt  */
#line 380 "parser.y"
                      { if(yybye) cout<<"LINE 231 \n";(yyval.node)=(yyvsp[0].node);}
#line 2399 "parser.cpp"
    break;

  case 20: /* stmt: compound_stmt  */
#line 381 "parser.y"
                       {if(yybye) cout<<"LINE 232 \n";(yyval.node)=(yyvsp[0].node);}
#line 2405 "parser.cpp"
    break;

  case 21: /* simple_stmt: small_stmt NEWLINE  */
#line 384 "parser.y"
                                {
              if(yybye) cout<<"LINE 235 \n";
               Node* n = create_node("simple_stmt");
               n->children.push_back((yyvsp[-1].node));
               (yyval.node)=n;
               (yyval.node)->type = (yyvsp[-1].node)->type;
            }
#line 2417 "parser.cpp"
    break;

  case 22: /* simple_stmt: small_stmt small_stmt_list NEWLINE  */
#line 391 "parser.y"
                                               {

                if(yybye) cout<<"LINE 241 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
              }
#line 2430 "parser.cpp"
    break;

  case 23: /* simple_stmt: small_stmt SEMICOLON NEWLINE  */
#line 399 "parser.y"
                                         {
                if(yybye) cout<<"LINE 242 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
              }
#line 2442 "parser.cpp"
    break;

  case 24: /* simple_stmt: small_stmt small_stmt_list SEMICOLON NEWLINE  */
#line 406 "parser.y"
                                                         {
                if(yybye) cout<<"LINE 243 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-3].node));
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));              
              }
#line 2454 "parser.cpp"
    break;

  case 25: /* small_stmt_list: small_stmt_list SEMICOLON small_stmt  */
#line 415 "parser.y"
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
#line 2469 "parser.cpp"
    break;

  case 26: /* small_stmt_list: SEMICOLON small_stmt  */
#line 425 "parser.y"
                                      {
                  if(yybye) cout<<"LINE 255 \n";
                  Node* n =create_node("small_stmt_list");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                }
#line 2481 "parser.cpp"
    break;

  case 27: /* small_stmt: expr_stmt  */
#line 433 "parser.y"
                      {if(yybye) cout<<"LINE 262 \n"; (yyval.node)=(yyvsp[0].node);}
#line 2487 "parser.cpp"
    break;

  case 28: /* small_stmt: del_stmt  */
#line 434 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2493 "parser.cpp"
    break;

  case 29: /* small_stmt: pass_stmt  */
#line 435 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2499 "parser.cpp"
    break;

  case 30: /* small_stmt: flow_stmt  */
#line 436 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2505 "parser.cpp"
    break;

  case 31: /* small_stmt: global_stmt  */
#line 437 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2511 "parser.cpp"
    break;

  case 32: /* expr_stmt: testlist_star_expr expr_stmt_tail  */
#line 439 "parser.y"
                                             { 
              Node* n =create_node("expr_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));
              (yyval.node)=n;
              if((yyvsp[0].node)->label=="annassign"){
                if(tab->SYMVAL.find((yyvsp[-1].node)->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared "<<(yyvsp[-1].node)->label<<endl;
                  cout<<endl;
                          exit(1);
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
                //           exit(1);
                // }
              }
                // cout<<$1->type <<" hii "<<$2->type<<endl;
             }
#line 2557 "parser.cpp"
    break;

  case 33: /* expr_stmt: testlist_star_expr  */
#line 480 "parser.y"
                                 { (yyval.node) = (yyvsp[0].node);}
#line 2563 "parser.cpp"
    break;

  case 34: /* expr_stmt_tail: COLON decl_type annassign  */
#line 483 "parser.y"
                                           {
                  (yyval.node) =create_node("annassign");
                  (yyval.node)->children.push_back((yyvsp[-2].node));
                  (yyval.node)->children.push_back((yyvsp[-1].node));
                  (yyval.node)->children.push_back((yyvsp[0].node));
                  (yyval.node)->type = (yyvsp[-1].node)->type;
                  check_type((yyvsp[-1].node)->type, (yyvsp[0].node)->type, (yyvsp[-2].node)->line_number);
                  }
#line 2576 "parser.cpp"
    break;

  case 35: /* expr_stmt_tail: annassign  */
#line 491 "parser.y"
                          {
                  (yyval.node) = (yyvsp[0].node);
               }
#line 2584 "parser.cpp"
    break;

  case 36: /* expr_stmt_tail: COLON decl_type  */
#line 494 "parser.y"
                                 {
                  (yyval.node) =create_node("annassign");
                  (yyval.node)->children.push_back((yyvsp[-1].node));
                  (yyval.node)->children.push_back((yyvsp[0].node));
                  (yyval.node)->type = (yyvsp[0].node)->type;
               }
#line 2595 "parser.cpp"
    break;

  case 37: /* expr_stmt_tail: augassign augassign_op  */
#line 500 "parser.y"
                                        {
                  Node* n =create_node("expr_stmt_tail");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                  (yyval.node)->type = (yyvsp[0].node)->type;
                  // cout<<$$->type <<" expr_stmt_tail"<<endl;
               }
#line 2608 "parser.cpp"
    break;

  case 38: /* decl_type: NAME  */
#line 513 "parser.y"
                {
                (yyval.node) = create_node("decl_type");
                (yyval.node)->type = (yyvsp[0].node)->type;
            }
#line 2617 "parser.cpp"
    break;

  case 39: /* decl_type: NAME LBRACKET NAME RBRACKET  */
#line 517 "parser.y"
                                          {
                if((yyvsp[-3].node)->label != "list"){
                  cout << "Invalid datatype at line no: " << (yyvsp[-3].node)->line_number << endl;
                  exit(1);
                }
                (yyval.node)->type = (yyvsp[-3].node)->type + (yyvsp[-2].node)->label + (yyvsp[-1].node)->type + (yyvsp[0].node)->label;
            }
#line 2629 "parser.cpp"
    break;

  case 40: /* augassign_op: yield_expr  */
#line 525 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2635 "parser.cpp"
    break;

  case 41: /* augassign_op: testlist  */
#line 526 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2641 "parser.cpp"
    break;

  case 42: /* annassign: EQUAL_SIGN test  */
#line 549 "parser.y"
                           {
                  Node* n =create_node("annassign_op");
                   n->children.push_back((yyvsp[-1].node));
                   n->children.push_back((yyvsp[0].node));
                   (yyval.node) = n;
                   (yyval.node)->type = (yyvsp[0].node)->type;
                  //  cout<<$$->type <<"HII"<<endl;
}
#line 2654 "parser.cpp"
    break;

  case 43: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep COMMA  */
#line 558 "parser.y"
                                                                         {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-2].node));
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                     (yyval.node)=n;
                    }
#line 2666 "parser.cpp"
    break;

  case 44: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep  */
#line 565 "parser.y"
                                                                   { 
                      Node* n =create_node("testlist_star_expr");
                      n->children.push_back((yyvsp[-1].node));
                      n->children.push_back((yyvsp[0].node));
                    }
#line 2676 "parser.cpp"
    break;

  case 45: /* testlist_star_expr: testlist_star_expr_opt1 COMMA  */
#line 570 "parser.y"
                                                  {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                    }
#line 2686 "parser.cpp"
    break;

  case 46: /* testlist_star_expr: testlist_star_expr_opt1  */
#line 575 "parser.y"
                                             { (yyval.node) = (yyvsp[0].node);}
#line 2692 "parser.cpp"
    break;

  case 47: /* testlist_star_expr_opt1: test  */
#line 579 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2698 "parser.cpp"
    break;

  case 48: /* testlist_star_expr_opt1: star_expr  */
#line 580 "parser.y"
                                   {(yyval.node)=(yyvsp[0].node);}
#line 2704 "parser.cpp"
    break;

  case 49: /* testlist_star_expr_rep: testlist_star_expr_rep COMMA testlist_star_expr_opt1  */
#line 583 "parser.y"
                                                          {
      Node* n =create_node("testlist_star_expr_rep");
      for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
        n->children.push_back((yyvsp[-2].node)->children[i]);
      }
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n;
  }
#line 2718 "parser.cpp"
    break;

  case 50: /* testlist_star_expr_rep: COMMA testlist_star_expr_opt1  */
#line 592 "parser.y"
                                  {(yyval.node) = NULL;}
#line 2724 "parser.cpp"
    break;

  case 51: /* augassign: PLUS_EQUAL  */
#line 594 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2730 "parser.cpp"
    break;

  case 52: /* augassign: MINUS_EQUAL  */
#line 595 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2736 "parser.cpp"
    break;

  case 53: /* augassign: TIMES_EQUAL  */
#line 596 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2742 "parser.cpp"
    break;

  case 54: /* augassign: AT_EQUAL  */
#line 597 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2748 "parser.cpp"
    break;

  case 55: /* augassign: DIVIDEDBY_EQUAL  */
#line 598 "parser.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2754 "parser.cpp"
    break;

  case 56: /* augassign: MODULO_EQUAL  */
#line 599 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2760 "parser.cpp"
    break;

  case 57: /* augassign: BITWISE_AND_EQUAL  */
#line 600 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2766 "parser.cpp"
    break;

  case 58: /* augassign: BITWISE_OR_EQUAL  */
#line 601 "parser.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 2772 "parser.cpp"
    break;

  case 59: /* augassign: BITWISE_XOR_EQUAL  */
#line 602 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2778 "parser.cpp"
    break;

  case 60: /* augassign: SHIFT_LEFT_EQUAL  */
#line 603 "parser.y"
                             {(yyval.node)=(yyvsp[0].node);}
#line 2784 "parser.cpp"
    break;

  case 61: /* augassign: SHIFT_RIGHT_EQUAL  */
#line 604 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2790 "parser.cpp"
    break;

  case 62: /* augassign: POWER_EQUAL  */
#line 605 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2796 "parser.cpp"
    break;

  case 63: /* augassign: FLOORDIV_EQUAL  */
#line 606 "parser.y"
                           {(yyval.node)=(yyvsp[0].node);}
#line 2802 "parser.cpp"
    break;

  case 64: /* del_stmt: DEL exprlist  */
#line 609 "parser.y"
                      {Node* n =create_node("del_stmt");
                         n->children.push_back((yyvsp[-1].node));
                         n->children.push_back((yyvsp[0].node));
                         (yyval.node)=n;
                          }
#line 2812 "parser.cpp"
    break;

  case 65: /* pass_stmt: PASS  */
#line 615 "parser.y"
               {(yyval.node)=(yyvsp[0].node);}
#line 2818 "parser.cpp"
    break;

  case 66: /* flow_stmt: break_stmt  */
#line 617 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2824 "parser.cpp"
    break;

  case 67: /* flow_stmt: continue_stmt  */
#line 618 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2830 "parser.cpp"
    break;

  case 68: /* flow_stmt: return_stmt  */
#line 619 "parser.y"
                       {(yyval.node)=(yyvsp[0].node); }
#line 2836 "parser.cpp"
    break;

  case 69: /* flow_stmt: yield_stmt  */
#line 620 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2842 "parser.cpp"
    break;

  case 70: /* break_stmt: BREAK  */
#line 623 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 2848 "parser.cpp"
    break;

  case 71: /* continue_stmt: CONTINUE  */
#line 625 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2854 "parser.cpp"
    break;

  case 72: /* return_stmt: RETURN testlist  */
#line 626 "parser.y"
                            {
              Node* n =create_node("return_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n;
              (yyval.node)->type = (yyvsp[0].node)->type;
            }
#line 2866 "parser.cpp"
    break;

  case 73: /* return_stmt: RETURN  */
#line 633 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "void";}
#line 2872 "parser.cpp"
    break;

  case 74: /* yield_stmt: yield_expr  */
#line 635 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2878 "parser.cpp"
    break;

  case 75: /* global_stmt: GLOBAL global_name_list  */
#line 636 "parser.y"
                                    {
              Node* n =create_node("global_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n; 
            }
#line 2889 "parser.cpp"
    break;

  case 76: /* global_name_list: global_name_list COMMA NAME  */
#line 643 "parser.y"
                                              {
                  Node* n =create_node("global_name_list");
                  for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
                    n->children.push_back((yyvsp[-2].node)->children[i]);
                  }
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  
                  (yyval.node)=n;
                }
#line 2904 "parser.cpp"
    break;

  case 77: /* global_name_list: NAME  */
#line 653 "parser.y"
                       { (yyval.node) = (yyvsp[0].node);}
#line 2910 "parser.cpp"
    break;

  case 78: /* compound_stmt: if_stmt  */
#line 655 "parser.y"
                       {if(yybye) cout<<"cmpd_stmnt 1 \n"; (yyval.node)=(yyvsp[0].node);}
#line 2916 "parser.cpp"
    break;

  case 79: /* compound_stmt: while_stmt  */
#line 656 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2922 "parser.cpp"
    break;

  case 80: /* compound_stmt: for_stmt  */
#line 657 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2928 "parser.cpp"
    break;

  case 81: /* compound_stmt: funcdef  */
#line 658 "parser.y"
                       {if(yybye) cout<<"cmpd_stmnt \n"; (yyval.node)=(yyvsp[0].node);}
#line 2934 "parser.cpp"
    break;

  case 82: /* compound_stmt: classdef  */
#line 659 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2940 "parser.cpp"
    break;

  case 83: /* compound_stmt: async_stmt  */
#line 660 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2946 "parser.cpp"
    break;

  case 87: /* if_stmt: IF test COLON suite elif_stmt_rep ELSE COLON suite  */
#line 670 "parser.y"
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
#line 2964 "parser.cpp"
    break;

  case 88: /* if_stmt: IF test COLON suite elif_stmt_rep  */
#line 683 "parser.y"
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
#line 2980 "parser.cpp"
    break;

  case 89: /* if_stmt: IF test COLON suite ELSE COLON suite  */
#line 694 "parser.y"
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
#line 2996 "parser.cpp"
    break;

  case 90: /* if_stmt: IF test COLON suite  */
#line 705 "parser.y"
                         { 
      Node* n=create_node("if_stmt");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
    }
#line 3009 "parser.cpp"
    break;

  case 91: /* elif_stmt_rep: elif_stmt_rep ELIF test COLON suite  */
#line 714 "parser.y"
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
#line 3025 "parser.cpp"
    break;

  case 92: /* elif_stmt_rep: ELIF test COLON suite  */
#line 725 "parser.y"
                           { 
      Node* n=create_node("elif_stmt_rep");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
    }
#line 3038 "parser.cpp"
    break;

  case 93: /* while_stmt: WHILE test COLON suite ELSE COLON suite  */
#line 734 "parser.y"
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
#line 3054 "parser.cpp"
    break;

  case 94: /* while_stmt: WHILE test COLON suite  */
#line 745 "parser.y"
                           { 
      Node* n=create_node("while_stmt");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
  }
#line 3067 "parser.cpp"
    break;

  case 95: /* for_stmt: FOR exprlist IN testlist COLON suite ELSE COLON suite  */
#line 754 "parser.y"
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
#line 3085 "parser.cpp"
    break;

  case 96: /* for_stmt: FOR exprlist IN testlist COLON suite  */
#line 767 "parser.y"
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
#line 3100 "parser.cpp"
    break;

  case 97: /* suite: simple_stmt  */
#line 778 "parser.y"
                    {if(yybye) cout<<"LINE 462 \n"; (yyval.node) = (yyvsp[0].node);}
#line 3106 "parser.cpp"
    break;

  case 98: /* suite: NEWLINE INDENT stmt_rep DEDENT  */
#line 779 "parser.y"
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
#line 3123 "parser.cpp"
    break;

  case 99: /* stmt_rep: stmt_rep stmt  */
#line 793 "parser.y"
                           {
            Node* n = create_node("Multi Statements");
            (yyval.node) = n;
            for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
              n->children.push_back((yyvsp[-1].node)->children[i]);
            }
            n->children.push_back((yyvsp[0].node));
            (yyval.node)->type = (yyvsp[0].node)->type;
          }
#line 3137 "parser.cpp"
    break;

  case 100: /* stmt_rep: stmt  */
#line 802 "parser.y"
                 {(yyval.node)=(yyvsp[0].node); }
#line 3143 "parser.cpp"
    break;

  case 101: /* test: or_test IF or_test ELSE test  */
#line 804 "parser.y"
                                    {
      Node* n = create_node("Test");
      (yyval.node) = n;
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
}
#line 3157 "parser.cpp"
    break;

  case 102: /* test: or_test  */
#line 813 "parser.y"
         {(yyval.node)=(yyvsp[0].node);}
#line 3163 "parser.cpp"
    break;

  case 103: /* test_nocond: or_test  */
#line 816 "parser.y"
          {(yyval.node) = (yyvsp[0].node);}
#line 3169 "parser.cpp"
    break;

  case 104: /* or_test: and_test or_test_rep  */
#line 820 "parser.y"
  {
    Node* n = create_node("OR Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3180 "parser.cpp"
    break;

  case 105: /* or_test: and_test  */
#line 826 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3186 "parser.cpp"
    break;

  case 106: /* or_test_rep: or_test_rep OR and_test  */
#line 829 "parser.y"
                           {
    Node* n = create_node("ORTestRep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3200 "parser.cpp"
    break;

  case 107: /* or_test_rep: OR and_test  */
#line 838 "parser.y"
               {Node* n = create_node("ORTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3209 "parser.cpp"
    break;

  case 108: /* and_test: not_test and_test_rep  */
#line 844 "parser.y"
                       {
    Node* n = create_node("And Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3220 "parser.cpp"
    break;

  case 109: /* and_test: not_test  */
#line 850 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3226 "parser.cpp"
    break;

  case 110: /* and_test_rep: and_test_rep AND not_test  */
#line 854 "parser.y"
  {
    Node* n = create_node("AndTestRep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3240 "parser.cpp"
    break;

  case 111: /* and_test_rep: AND not_test  */
#line 863 "parser.y"
                {Node* n = create_node("AndTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3249 "parser.cpp"
    break;

  case 112: /* not_test: NOT not_test  */
#line 871 "parser.y"
  {
    Node* n = create_node("Not Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3260 "parser.cpp"
    break;

  case 113: /* not_test: comparison  */
#line 877 "parser.y"
               {
    (yyval.node) =(yyvsp[0].node);
  }
#line 3268 "parser.cpp"
    break;

  case 114: /* comparison: expr comparison_rep  */
#line 882 "parser.y"
                     {
    Node* n = create_node("Comparison");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[-1].node)->line_number);
    // if($1->type != $2->type){
    //   diff_data($1->line_no);
    //           exit(1);
    // }
    (yyval.node)->type = (yyvsp[-1].node)->type;

  }
#line 3286 "parser.cpp"
    break;

  case 115: /* comparison: expr  */
#line 895 "parser.y"
       {(yyval.node)=(yyvsp[0].node);}
#line 3292 "parser.cpp"
    break;

  case 116: /* comparison_rep: comparison_rep comp_op expr  */
#line 899 "parser.y"
                              {
    Node* n = create_node("Comparison Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3306 "parser.cpp"
    break;

  case 117: /* comparison_rep: comp_op expr  */
#line 908 "parser.y"
                {
   Node* n = create_node("Comparison Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
 }
#line 3318 "parser.cpp"
    break;

  case 118: /* comp_op: LESS_THAN  */
#line 916 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 3324 "parser.cpp"
    break;

  case 119: /* comp_op: GREATER_THAN  */
#line 917 "parser.y"
                      {(yyval.node) =(yyvsp[0].node);}
#line 3330 "parser.cpp"
    break;

  case 120: /* comp_op: EQUAL  */
#line 918 "parser.y"
               {(yyval.node) =(yyvsp[0].node);}
#line 3336 "parser.cpp"
    break;

  case 121: /* comp_op: GREATER_THAN_OR_EQUAL  */
#line 919 "parser.y"
                               {(yyval.node) =(yyvsp[0].node);}
#line 3342 "parser.cpp"
    break;

  case 122: /* comp_op: LESS_THAN_OR_EQUAL  */
#line 920 "parser.y"
                            {(yyval.node) =(yyvsp[0].node);}
#line 3348 "parser.cpp"
    break;

  case 123: /* comp_op: NOT_EQUAL  */
#line 921 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 3354 "parser.cpp"
    break;

  case 124: /* comp_op: IN  */
#line 922 "parser.y"
            {(yyval.node) =(yyvsp[0].node);}
#line 3360 "parser.cpp"
    break;

  case 125: /* comp_op: NOT IN  */
#line 923 "parser.y"
                {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3371 "parser.cpp"
    break;

  case 126: /* comp_op: IS  */
#line 929 "parser.y"
            {(yyval.node) =(yyvsp[0].node);}
#line 3377 "parser.cpp"
    break;

  case 127: /* comp_op: IS NOT  */
#line 930 "parser.y"
               {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3388 "parser.cpp"
    break;

  case 128: /* star_expr: TIMES expr  */
#line 938 "parser.y"
            {
    Node* n = create_node("Star Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3399 "parser.cpp"
    break;

  case 129: /* expr: xor_expr expr_rep  */
#line 946 "parser.y"
                   {
    Node* n = create_node("Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3410 "parser.cpp"
    break;

  case 130: /* expr: xor_expr  */
#line 952 "parser.y"
            {(yyval.node)=(yyvsp[0].node);}
#line 3416 "parser.cpp"
    break;

  case 131: /* expr_rep: expr_rep BITWISE_OR xor_expr  */
#line 955 "parser.y"
                               {
    Node* n = create_node("Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3430 "parser.cpp"
    break;

  case 132: /* expr_rep: BITWISE_OR xor_expr  */
#line 964 "parser.y"
                       {Node* n = create_node("Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3439 "parser.cpp"
    break;

  case 133: /* xor_expr: and_expr xor_expr_rep  */
#line 970 "parser.y"
                       {
    Node* n = create_node("XOR Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3450 "parser.cpp"
    break;

  case 134: /* xor_expr: and_expr  */
#line 976 "parser.y"
            {
    (yyval.node)=(yyvsp[0].node);
  }
#line 3458 "parser.cpp"
    break;

  case 135: /* xor_expr_rep: xor_expr_rep BITWISE_XOR and_expr  */
#line 981 "parser.y"
                                    {
    Node* n = create_node("XOR Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3472 "parser.cpp"
    break;

  case 136: /* xor_expr_rep: BITWISE_XOR and_expr  */
#line 990 "parser.y"
                       {Node* n = create_node("XOR Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3481 "parser.cpp"
    break;

  case 137: /* and_expr: shift_expr and_expr_rep  */
#line 996 "parser.y"
                         {
    Node* n = create_node("AND Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3492 "parser.cpp"
    break;

  case 138: /* and_expr: shift_expr  */
#line 1002 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3498 "parser.cpp"
    break;

  case 139: /* and_expr_rep: and_expr_rep BITWISE_AND shift_expr  */
#line 1005 "parser.y"
                                      {
    Node* n = create_node("AND Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node)); 
  }
#line 3512 "parser.cpp"
    break;

  case 140: /* and_expr_rep: BITWISE_AND shift_expr  */
#line 1014 "parser.y"
                         {Node* n = create_node("AND Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node)); }
#line 3521 "parser.cpp"
    break;

  case 141: /* shift_expr: arith_expr shift_expr_rep  */
#line 1020 "parser.y"
                           {
    Node* n = create_node("Shift Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3532 "parser.cpp"
    break;

  case 142: /* shift_expr: arith_expr  */
#line 1026 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3538 "parser.cpp"
    break;

  case 143: /* shift_expr_rep: shift_expr_rep shift_expr_rep_c1 arith_expr  */
#line 1029 "parser.y"
                                              {
    Node* n = create_node("Shift Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3552 "parser.cpp"
    break;

  case 144: /* shift_expr_rep: shift_expr_rep_c1 arith_expr  */
#line 1038 "parser.y"
                                {Node* n = create_node("Shift Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));}
#line 3561 "parser.cpp"
    break;

  case 145: /* shift_expr_rep_c1: SHIFT_LEFT  */
#line 1044 "parser.y"
            {
    (yyval.node) = (yyvsp[0].node);
  }
#line 3569 "parser.cpp"
    break;

  case 146: /* shift_expr_rep_c1: SHIFT_RIGHT  */
#line 1047 "parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 3575 "parser.cpp"
    break;

  case 147: /* arith_expr: term arith_expr_rep  */
#line 1050 "parser.y"
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
#line 3597 "parser.cpp"
    break;

  case 148: /* arith_expr: term  */
#line 1067 "parser.y"
        { if(yybye) cout<<"term arith_expr: "<<endl;(yyval.node)=(yyvsp[0].node);}
#line 3603 "parser.cpp"
    break;

  case 149: /* arith_expr_rep: arith_expr_rep arith_expr_rep_c1 term  */
#line 1070 "parser.y"
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
#line 3628 "parser.cpp"
    break;

  case 150: /* arith_expr_rep: arith_expr_rep_c1 term  */
#line 1090 "parser.y"
                         {Node* n = create_node("Arithmetic Expression Rep2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 3639 "parser.cpp"
    break;

  case 151: /* arith_expr_rep_c1: PLUS  */
#line 1098 "parser.y"
       { (yyval.node) = (yyvsp[0].node);}
#line 3645 "parser.cpp"
    break;

  case 152: /* arith_expr_rep_c1: MINUS  */
#line 1099 "parser.y"
          { (yyval.node) = (yyvsp[0].node);}
#line 3651 "parser.cpp"
    break;

  case 153: /* term: factor term_rep  */
#line 1102 "parser.y"
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
    //           exit(1);
    // }
    // $$->type = $1->type;
  }
#line 3681 "parser.cpp"
    break;

  case 154: /* term: factor  */
#line 1127 "parser.y"
         {if(yybye) cout<<"factor term: "<<endl;(yyval.node)=(yyvsp[0].node);}
#line 3687 "parser.cpp"
    break;

  case 155: /* term_rep: term_rep term_rep_c1 factor  */
#line 1130 "parser.y"
                               {
    Node* n = create_node("TERM Rep");
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
  }
#line 3701 "parser.cpp"
    break;

  case 156: /* term_rep: term_rep_c1 factor  */
#line 1139 "parser.y"
                       { Node* n = create_node("TERM Rep");
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
    (yyval.node)->type = (yyvsp[0].node)->type;
    }
#line 3712 "parser.cpp"
    break;

  case 157: /* term_rep_c1: TIMES  */
#line 1146 "parser.y"
                    { (yyval.node) =(yyvsp[0].node);}
#line 3718 "parser.cpp"
    break;

  case 158: /* term_rep_c1: AT  */
#line 1147 "parser.y"
                 { (yyval.node) =(yyvsp[0].node);}
#line 3724 "parser.cpp"
    break;

  case 159: /* term_rep_c1: DIVIDEDBY  */
#line 1148 "parser.y"
                        { (yyval.node) =(yyvsp[0].node);}
#line 3730 "parser.cpp"
    break;

  case 160: /* term_rep_c1: MODULO  */
#line 1149 "parser.y"
                     { (yyval.node) =(yyvsp[0].node);}
#line 3736 "parser.cpp"
    break;

  case 161: /* term_rep_c1: FLOORDIV  */
#line 1150 "parser.y"
                       { (yyval.node) =(yyvsp[0].node);}
#line 3742 "parser.cpp"
    break;

  case 162: /* factor: factor_c1 factor  */
#line 1153 "parser.y"
                   {
    Node* n = create_node("Factor");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 3753 "parser.cpp"
    break;

  case 163: /* factor: power  */
#line 1159 "parser.y"
          { if(yybye) cout<<"factor power: "<<endl;(yyval.node) = (yyvsp[0].node);}
#line 3759 "parser.cpp"
    break;

  case 164: /* factor_c1: PLUS  */
#line 1161 "parser.y"
                 { (yyval.node) =(yyvsp[0].node);}
#line 3765 "parser.cpp"
    break;

  case 165: /* factor_c1: MINUS  */
#line 1162 "parser.y"
                  { (yyval.node) =(yyvsp[0].node);}
#line 3771 "parser.cpp"
    break;

  case 166: /* factor_c1: BITWISE_NOT  */
#line 1163 "parser.y"
                        { (yyval.node) =(yyvsp[0].node);}
#line 3777 "parser.cpp"
    break;

  case 167: /* power: atom_expr power_opt  */
#line 1166 "parser.y"
                     {
    Node* n = create_node("Power");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type , (yyvsp[-1].node)->line_number);
    (yyval.node)->type = (yyvsp[-1].node)->type;

  }
#line 3791 "parser.cpp"
    break;

  case 168: /* power: atom_expr  */
#line 1175 "parser.y"
             {
    (yyval.node) = (yyvsp[0].node);
    if(yybye) cout<<"atom_expr power: "<<endl;(yyval.node)=(yyvsp[0].node);
  }
#line 3800 "parser.cpp"
    break;

  case 169: /* power_opt: POWER factor  */
#line 1181 "parser.y"
               {
    Node* n = create_node("Power Opt");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 3812 "parser.cpp"
    break;

  case 170: /* atom_expr: await_opt atom trailer_rep  */
#line 1190 "parser.y"
                            {
    Node* n = create_node("Atom Expression1");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    n->type = (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
  }
#line 3825 "parser.cpp"
    break;

  case 171: /* atom_expr: atom trailer_rep  */
#line 1198 "parser.y"
                   {
    Node* n = create_node("Atom Expression2");
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    n->type = (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
    if((gt->SYMVAL.find((yyvsp[-1].node)->label) != tab->SYMVAL.end()) && (yyvsp[0].node)->category == "Func")
    {
      vector<Param*> p = gt->SYMVAL[(yyvsp[-1].node)->label].params;
      if(p.size() > (yyvsp[0].node)->p_f.size())
      {
        cout<<"Lesser number of arguments for function call "<< (yyvsp[-1].node)->label <<" in line number "<< (yyvsp[-1].node)->line_number<<endl;
                exit(1);
      }
      else if(p.size() < (yyvsp[0].node)->p_f.size())
      {
        cout<<"Greater number of arguments for function call "<< (yyvsp[-1].node)->label <<" in line number "<< (yyvsp[-1].node)->line_number<<endl;
                exit(1);
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
                      exit(1);
            }
          }
        }
      }
      
    }
    else if((yyvsp[0].node)->category == "Func")
    {
      if((yyvsp[-1].node)->label == "len" || (yyvsp[-1].node)->label == "print"){
        std::regex pattern("list\\[\\w+\\]");

        if (std::regex_match((yyvsp[0].node)->type, pattern)) {
            std::cout << "String matches the pattern.\n";
        } else {
            std::cout << "String does not match the pattern.\n";
            exit(1);
        }
      }
      else{
        cout<<"Undeclared Function in line no : "<< (yyvsp[-1].node)->line_number<<endl;
        exit(1);
      }
    }
    (yyval.node) = n;
    if(yybye) cout<<"atom trailer_rep atom_expr: "<<endl;
    

  }
#line 3889 "parser.cpp"
    break;

  case 172: /* atom_expr: atom  */
#line 1257 "parser.y"
       {
    (yyval.node) = (yyvsp[0].node);
    // cout<<"atom " <<$$->type<<endl;
    if(yybye) cout<<"atom_expr atom: "<<endl; 
  }
#line 3899 "parser.cpp"
    break;

  case 173: /* await_opt: AWAIT  */
#line 1263 "parser.y"
                  {
  (yyval.node) = (yyvsp[0].node);
}
#line 3907 "parser.cpp"
    break;

  case 174: /* trailer_rep: trailer_rep trailer  */
#line 1268 "parser.y"
                      {
    if(yybye) cout<<"trailer_rep: "<<endl;
    Node* n = create_node("Trailer Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));
  }
#line 3921 "parser.cpp"
    break;

  case 175: /* trailer_rep: trailer  */
#line 1277 "parser.y"
            { 
    (yyval.node) =(yyvsp[0].node);
  }
#line 3929 "parser.cpp"
    break;

  case 176: /* atom: LPAREN atom_opt1 RPAREN  */
#line 1281 "parser.y"
                               {
        if(yybye) cout<<"atom atom_opt1: "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-2].node));
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        (yyval.node)->category = "Func";
        (yyval.node)->type = (yyvsp[-1].node)->type;
      }
#line 3944 "parser.cpp"
    break;

  case 177: /* atom: LBRACKET atom_opt2 RBRACKET  */
#line 1291 "parser.y"
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
#line 3960 "parser.cpp"
    break;

  case 178: /* atom: LBRACKET RBRACKET  */
#line 1302 "parser.y"
                         { 
        if(yybye) cout<<"atom : "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
      }
#line 3972 "parser.cpp"
    break;

  case 179: /* atom: NAME  */
#line 1309 "parser.y"
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
#line 3999 "parser.cpp"
    break;

  case 180: /* atom: NUMBER  */
#line 1331 "parser.y"
                { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "int";}
#line 4005 "parser.cpp"
    break;

  case 181: /* atom: FLOAT  */
#line 1332 "parser.y"
              {(yyval.node) = (yyvsp[0].node); (yyval.node)->type = "float";}
#line 4011 "parser.cpp"
    break;

  case 182: /* atom: string_rep  */
#line 1333 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "string";}
#line 4017 "parser.cpp"
    break;

  case 183: /* atom: TRIPLEDOT  */
#line 1334 "parser.y"
                   { (yyval.node) =(yyvsp[0].node);}
#line 4023 "parser.cpp"
    break;

  case 184: /* atom: NONE  */
#line 1335 "parser.y"
              { (yyval.node) =(yyvsp[0].node);}
#line 4029 "parser.cpp"
    break;

  case 185: /* atom: TRUE_TOKEN  */
#line 1336 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";}
#line 4035 "parser.cpp"
    break;

  case 186: /* atom: FALSE_TOKEN  */
#line 1337 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";}
#line 4041 "parser.cpp"
    break;

  case 187: /* atom_opt1: yield_expr  */
#line 1339 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 4047 "parser.cpp"
    break;

  case 188: /* atom_opt1: testlist_comp  */
#line 1340 "parser.y"
                         {(yyval.node) = (yyvsp[0].node); if(yybye) cout<<"atom_opt1 testlist_comp: "<<endl;}
#line 4053 "parser.cpp"
    break;

  case 189: /* atom_opt2: testlist_comp  */
#line 1342 "parser.y"
                         {(yyval.node) =(yyvsp[0].node);}
#line 4059 "parser.cpp"
    break;

  case 190: /* string_rep: STRING  */
#line 1345 "parser.y"
         { (yyval.node) = (yyvsp[0].node);}
#line 4065 "parser.cpp"
    break;

  case 191: /* string_rep: string_rep STRING  */
#line 1346 "parser.y"
                      {
    Node* n = create_node("String Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));    
  }
#line 4078 "parser.cpp"
    break;

  case 192: /* testlist_comp: testlist_comp_c1 testlist_comp_c2  */
#line 1356 "parser.y"
                                   {
    Node* n = create_node("Testlist comp");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[-1].node)->type;
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
    
  }
#line 4092 "parser.cpp"
    break;

  case 193: /* testlist_comp: testlist_comp_c1  */
#line 1365 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 4098 "parser.cpp"
    break;

  case 194: /* testlist_comp_c1: test  */
#line 1368 "parser.y"
         {(yyval.node) = (yyvsp[0].node);}
#line 4104 "parser.cpp"
    break;

  case 195: /* testlist_comp_c1: star_expr  */
#line 1369 "parser.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 4110 "parser.cpp"
    break;

  case 196: /* testlist_comp_c2: comp_for  */
#line 1372 "parser.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 4116 "parser.cpp"
    break;

  case 197: /* testlist_comp_c2: testlist_comp_c2_rep COMMA  */
#line 1373 "parser.y"
                              {
    Node* n = create_node("Testlist Comp C2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[-1].node)->type;
    (yyval.node)->line_number = (yyvsp[0].node)->line_number;
  }
#line 4129 "parser.cpp"
    break;

  case 198: /* testlist_comp_c2: COMMA  */
#line 1381 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 4135 "parser.cpp"
    break;

  case 199: /* testlist_comp_c2: testlist_comp_c2_rep  */
#line 1382 "parser.y"
                        {(yyval.node) =(yyvsp[0].node);}
#line 4141 "parser.cpp"
    break;

  case 200: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA test  */
#line 1386 "parser.y"
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
#line 4157 "parser.cpp"
    break;

  case 201: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA star_expr  */
#line 1397 "parser.y"
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
#line 4173 "parser.cpp"
    break;

  case 202: /* testlist_comp_c2_rep: COMMA test  */
#line 1408 "parser.y"
             {
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 4185 "parser.cpp"
    break;

  case 203: /* testlist_comp_c2_rep: COMMA star_expr  */
#line 1415 "parser.y"
                    { 
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 4197 "parser.cpp"
    break;

  case 204: /* trailer: LPAREN arglist RPAREN  */
#line 1424 "parser.y"
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
#line 4214 "parser.cpp"
    break;

  case 205: /* trailer: LPAREN RPAREN  */
#line 1436 "parser.y"
                {
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
    (yyval.node)->type = "Func";
  }
#line 4227 "parser.cpp"
    break;

  case 206: /* trailer: LBRACKET subscriptlist RBRACKET  */
#line 1444 "parser.y"
                                    {
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-2].node)->line_number;
    (yyval.node)->type = (yyvsp[-2].node)->type + (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
  }
#line 4241 "parser.cpp"
    break;

  case 207: /* trailer: LBRACKET RBRACKET  */
#line 1453 "parser.y"
                    { 
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
  }
#line 4253 "parser.cpp"
    break;

  case 208: /* trailer: DOT NAME  */
#line 1460 "parser.y"
            {
    Node* n = create_node("Trailer");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
  }
#line 4265 "parser.cpp"
    break;

  case 209: /* subscriptlist: subscript COMMA_subscript_rep COMMA_opt  */
#line 1469 "parser.y"
                                         {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4278 "parser.cpp"
    break;

  case 210: /* subscriptlist: subscript COMMA_opt  */
#line 1477 "parser.y"
                      {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4289 "parser.cpp"
    break;

  case 211: /* subscriptlist: subscript COMMA_subscript_rep  */
#line 1483 "parser.y"
                                {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4300 "parser.cpp"
    break;

  case 212: /* subscriptlist: subscript  */
#line 1489 "parser.y"
             {(yyval.node) =(yyvsp[0].node);}
#line 4306 "parser.cpp"
    break;

  case 213: /* COMMA_opt: COMMA  */
#line 1492 "parser.y"
        { (yyval.node) = (yyvsp[0].node);}
#line 4312 "parser.cpp"
    break;

  case 214: /* COMMA_subscript_rep: COMMA_subscript_rep COMMA subscript  */
#line 1496 "parser.y"
                                      {
    Node* n = create_node("Comma Subscript rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4326 "parser.cpp"
    break;

  case 215: /* COMMA_subscript_rep: COMMA subscript  */
#line 1505 "parser.y"
                   {
    Node* n = create_node("COMMA subscript rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4337 "parser.cpp"
    break;

  case 216: /* subscript: test  */
#line 1513 "parser.y"
       { (yyval.node) = (yyvsp[0].node);}
#line 4343 "parser.cpp"
    break;

  case 217: /* subscript: test COLON test sliceop  */
#line 1514 "parser.y"
                           {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4357 "parser.cpp"
    break;

  case 218: /* subscript: COLON test sliceop  */
#line 1523 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4369 "parser.cpp"
    break;

  case 219: /* subscript: test COLON sliceop  */
#line 1530 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4381 "parser.cpp"
    break;

  case 220: /* subscript: test COLON test  */
#line 1537 "parser.y"
                   {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4393 "parser.cpp"
    break;

  case 221: /* subscript: COLON sliceop  */
#line 1544 "parser.y"
                 {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4404 "parser.cpp"
    break;

  case 222: /* subscript: COLON test  */
#line 1550 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4415 "parser.cpp"
    break;

  case 223: /* subscript: test COLON  */
#line 1556 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4426 "parser.cpp"
    break;

  case 224: /* subscript: COLON  */
#line 1562 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 4432 "parser.cpp"
    break;

  case 225: /* sliceop: COLON test  */
#line 1564 "parser.y"
                    {
    Node* n = create_node("Slice OP");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4443 "parser.cpp"
    break;

  case 226: /* sliceop: COLON  */
#line 1570 "parser.y"
       {(yyval.node) = (yyvsp[0].node);}
#line 4449 "parser.cpp"
    break;

  case 227: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep COMMA  */
#line 1572 "parser.y"
                                                        {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4461 "parser.cpp"
    break;

  case 228: /* exprlist: expr_star_expr COMMA  */
#line 1579 "parser.y"
                      {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4472 "parser.cpp"
    break;

  case 229: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep  */
#line 1585 "parser.y"
                                         {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4483 "parser.cpp"
    break;

  case 230: /* exprlist: expr_star_expr  */
#line 1591 "parser.y"
                {(yyval.node) =(yyvsp[0].node);}
#line 4489 "parser.cpp"
    break;

  case 231: /* expr_star_expr: expr  */
#line 1593 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 4495 "parser.cpp"
    break;

  case 232: /* expr_star_expr: star_expr  */
#line 1594 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 4501 "parser.cpp"
    break;

  case 233: /* COMMA_expr_star_expr_rep: COMMA_expr_star_expr_rep COMMA expr_star_expr  */
#line 1597 "parser.y"
                                               {
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4515 "parser.cpp"
    break;

  case 234: /* COMMA_expr_star_expr_rep: COMMA expr_star_expr  */
#line 1606 "parser.y"
                       { 
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4526 "parser.cpp"
    break;

  case 235: /* testlist: test COMMA  */
#line 1621 "parser.y"
             {
    Node* n = create_node("Testlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4537 "parser.cpp"
    break;

  case 236: /* testlist: test  */
#line 1633 "parser.y"
        {(yyval.node) =(yyvsp[0].node);}
#line 4543 "parser.cpp"
    break;

  case 237: /* class_name: CLASS NAME  */
#line 1650 "parser.y"
                      {
            Node* n = create_node((yyvsp[0].node)->label);
            n->children.push_back((yyvsp[-1].node));
            n->children.push_back((yyvsp[0].node));
            (yyval.node) = n;
            (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
            if(tab->SYMVAL.find((yyvsp[0].node)->label)== tab->SYMVAL.end()){
                tab->SYMVAL[(yyvsp[0].node)->label].identity=CLS;
                tab->SYMVAL[(yyvsp[0].node)->label].scope=curr_scope;
                tab->SYMVAL[(yyvsp[0].node)->label].line_no=(yyvsp[-1].node)->line_number;
               cout<<tab->SYMVAL[(yyvsp[0].node)->label].name<<endl;
               SYMTAB* newtab=new SYMTAB();
               newtab->SYMSCOPE=++curr_scope;
               newtab->parent=tab;
              //  tab->childs.push_back(newtab);
               tab->childs[(yyvsp[0].node)->label] = newtab;
               tab=newtab;
             }
             else {
              cout<<"Class redeclared in line no "<< (yyvsp[0].node)->line_number<<endl;
                      exit(1);
             }
}
#line 4571 "parser.cpp"
    break;

  case 238: /* classdef: class_name LPAREN arglist RPAREN COLON suite  */
#line 1673 "parser.y"
                                                       {
    Node* n = create_node("Class Def");
    n->children.push_back((yyvsp[-5].node));
    n->children.push_back((yyvsp[-4].node));
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
    tab=tab->parent;
  //   if(tab->SYMVAL.find($1->label)!= tab->SYMVAL.end()){
  //     tab->SYMVAL[$1->label].identity=CLS;
  //     tab->SYMVAL[$1->label].scope=curr_scope;
  //     tab->SYMVAL[$1->label].line_no=$1->line_number;
  //     tab->SYMVAL[$1->label].type=$4->type;
  //     tab->SYMVAL[$1->label].name=$1->label;
  //     tab->SYMVAL[$1->label].size=$2->count;
  //     // tab-SYMVAL[$1->labe].params = 
  //     //int g_index;
  //     //int reg_name;
  //     for(int i=0;i<$2->children.size();i++){
  //       Node* t=$2->children[i];
  //       string temp=t->label;
  //        if(temp!="[" && temp!="]"){
  //           tab->SYMVAL[$1->label].params=$2->p_f;
  //        }
  //     }              
  //  }

  //  else{
  //   cout<<"error"<<endl;
  //   exit(0);
  //  }   

}
#line 4611 "parser.cpp"
    break;

  case 239: /* classdef: class_name LPAREN RPAREN COLON suite  */
#line 1708 "parser.y"
                                      {
    Node* n = create_node("Class Def");
    n->children.push_back((yyvsp[-4].node));
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
    tab=tab->parent;
  //   if(tab->SYMVAL.find($1->label)!= tab->SYMVAL.end()){
  //     tab->SYMVAL[$1->label].identity=CLS;
  //     tab->SYMVAL[$1->label].scope=curr_scope;
  //     tab->SYMVAL[$1->label].line_no=$1->line_number;
  //     tab->SYMVAL[$1->label].type=$4->type;
  //     tab->SYMVAL[$1->label].name=$1->label;
  //     tab->SYMVAL[$1->label].size=$2->count;
  //     // tab-SYMVAL[$1->labe].params = 
  //     //int g_index;
  //     //int reg_name;
  //     for(int i=0;i<$2->children.size();i++){
  //       Node* t=$2->children[i];
  //       string temp=t->label;
  //        if(temp!="[" && temp!="]"){
  //           tab->SYMVAL[$1->label].params=$2->p_f;
  //        }
  //     }              
  //  }

  //  else{
  //   cout<<"error"<<endl;
  //   exit(0);
  //  }   
}
#line 4649 "parser.cpp"
    break;

  case 240: /* classdef: class_name COLON suite  */
#line 1741 "parser.y"
                        {
    Node* n = create_node("Class Def");
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
    tab=tab->parent;
    if(tab->SYMVAL.find((yyvsp[-2].node)->label)!= tab->SYMVAL.end()){
      tab->SYMVAL[(yyvsp[-2].node)->label].identity=CLS;
      tab->SYMVAL[(yyvsp[-2].node)->label].scope=curr_scope;
      tab->SYMVAL[(yyvsp[-2].node)->label].line_no=(yyvsp[-2].node)->line_number;
      tab->SYMVAL[(yyvsp[-2].node)->label].type=(yyvsp[-2].node)->label;
      tab->SYMVAL[(yyvsp[-2].node)->label].name=(yyvsp[-2].node)->label;
      // tab->SYMVAL[$1->label].size=$2->count;
      // tab-SYMVAL[$1->labe].params = 
      //int g_index;
      //int reg_name;
      // for(int i=0;i<$2->children.size();i++){
      //   Node* t=$2->children[i];
      //   string temp=t->label;
      //    if(temp!="[" && temp!="]"){
      //       tab->SYMVAL[$1->label].params=$2->p_f;
      //    }
      // }              
   }

   else{
    cout<<"error"<<endl;
    exit(0);
   }   

}
#line 4686 "parser.cpp"
    break;

  case 241: /* arglist: argument COMMA_argument_rep COMMA  */
#line 1775 "parser.y"
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
#line 4709 "parser.cpp"
    break;

  case 242: /* arglist: argument COMMA  */
#line 1793 "parser.y"
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
#line 4724 "parser.cpp"
    break;

  case 243: /* arglist: argument COMMA_argument_rep  */
#line 1803 "parser.y"
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
#line 4745 "parser.cpp"
    break;

  case 244: /* arglist: argument  */
#line 1819 "parser.y"
           {(yyval.node) =(yyvsp[0].node);
    Param* temp = new Param();
    temp->par_type=(yyvsp[0].node)->type;
    temp->par_name=(yyvsp[0].node)->label;
    (yyval.node)->p_f.push_back(temp);
  }
#line 4756 "parser.cpp"
    break;

  case 245: /* COMMA_argument_rep: COMMA_argument_rep COMMA argument  */
#line 1827 "parser.y"
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
#line 4777 "parser.cpp"
    break;

  case 246: /* COMMA_argument_rep: COMMA argument  */
#line 1843 "parser.y"
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
#line 4793 "parser.cpp"
    break;

  case 247: /* argument: test comp_for  */
#line 1856 "parser.y"
               {
    Node* n = create_node("Argument");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4804 "parser.cpp"
    break;

  case 248: /* argument: test EQUAL_SIGN test  */
#line 1862 "parser.y"
                         {
     Node* n = create_node("Argument");
     (yyval.node) = n;
     n->children.push_back((yyvsp[-2].node));
     n->children.push_back((yyvsp[-1].node));
  }
#line 4815 "parser.cpp"
    break;

  case 249: /* argument: POWER test  */
#line 1868 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));      
  }
#line 4826 "parser.cpp"
    break;

  case 250: /* argument: TIMES test  */
#line 1874 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));    
  }
#line 4837 "parser.cpp"
    break;

  case 251: /* argument: test  */
#line 1880 "parser.y"
       {(yyval.node) =(yyvsp[0].node);}
#line 4843 "parser.cpp"
    break;

  case 252: /* comp_iter: comp_for  */
#line 1882 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 4849 "parser.cpp"
    break;

  case 253: /* comp_iter: comp_if  */
#line 1883 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 4855 "parser.cpp"
    break;

  case 254: /* sync_comp_for: FOR exprlist IN or_test comp_iter  */
#line 1885 "parser.y"
                                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-4].node));
          n->children.push_back((yyvsp[-3].node));  
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));   
          n->children.push_back((yyvsp[0].node));   
}
#line 4869 "parser.cpp"
    break;

  case 255: /* sync_comp_for: FOR exprlist IN or_test  */
#line 1894 "parser.y"
                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-3].node));
          n->children.push_back((yyvsp[-2].node));  
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 4882 "parser.cpp"
    break;

  case 256: /* comp_for: ASYNC sync_comp_for  */
#line 1903 "parser.y"
                             { 
          Node* n = create_node("Comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));  }
#line 4892 "parser.cpp"
    break;

  case 257: /* comp_for: sync_comp_for  */
#line 1908 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 4898 "parser.cpp"
    break;

  case 258: /* comp_if: IF test_nocond comp_iter  */
#line 1910 "parser.y"
                                  {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
}
#line 4910 "parser.cpp"
    break;

  case 259: /* comp_if: IF test_nocond  */
#line 1917 "parser.y"
                        {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 4921 "parser.cpp"
    break;

  case 260: /* yield_expr: YIELD  */
#line 1923 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 4927 "parser.cpp"
    break;


#line 4931 "parser.cpp"

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

#line 1932 "parser.y"



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

