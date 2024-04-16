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
#include "3ac.cpp"
#define YYDEBUG 1
#define YYDEB 0
using namespace std;
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern int yylex();
void yyerror(const char*);
int yybye =0;
string extractSubstring(const std::string& str) {
    // Find the position of '[' and ']'
    size_t startPos = str.find('[');
    size_t endPos = str.find(']');

    // Check if both '[' and ']' are found and if they are in the correct order
    if (startPos != std::string::npos && endPos != std::string::npos && startPos < endPos) {
        // Extract the substring between '[' and ']'
        return str.substr(startPos + 1, endPos - startPos - 1);
    }

    // Return an empty string if '[' and ']' are not found or in incorrect order
    return "";
}
void diff_data(int x)
{
  cout<<"Datatype mismatch in line no "<< x <<endl;
  exit(1);
}
void check_type(string s1,string s2, int x)
{
    if(s1 != s2)
    {
      diff_data(x);
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
 int get_siz(string type){
    if(type.substr(0,3)=="int" || type.substr(0,5)=="float") return 4;
    else if(type.substr(0,4)=="char" ) return 2;
    else if(type.substr(0,4)=="bool") return 1;
    else if(type.substr(0,4)=="long" || type.substr(0,6)=="double") return 8;
    else return 8;
}
extern int inst_num;
vector<tuple<string,string,string,int,int> > arguments;
vector<int> loop_stack;


#line 166 "parser.cpp"

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
  YYSYMBOL_105_1 = 105,                    /* $@1  */
  YYSYMBOL_106_2 = 106,                    /* $@2  */
  YYSYMBOL_parameters = 107,               /* parameters  */
  YYSYMBOL_typedargslist = 108,            /* typedargslist  */
  YYSYMBOL_datatype = 109,                 /* datatype  */
  YYSYMBOL_stmt = 110,                     /* stmt  */
  YYSYMBOL_simple_stmt = 111,              /* simple_stmt  */
  YYSYMBOL_small_stmt_list = 112,          /* small_stmt_list  */
  YYSYMBOL_small_stmt = 113,               /* small_stmt  */
  YYSYMBOL_expr_stmt = 114,                /* expr_stmt  */
  YYSYMBOL_expr_stmt_tail = 115,           /* expr_stmt_tail  */
  YYSYMBOL_decl_type = 116,                /* decl_type  */
  YYSYMBOL_augassign_op = 117,             /* augassign_op  */
  YYSYMBOL_annassign = 118,                /* annassign  */
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
  YYSYMBOL_ifkeyword = 135,                /* ifkeyword  */
  YYSYMBOL_if_stmt = 136,                  /* if_stmt  */
  YYSYMBOL_137_3 = 137,                    /* $@3  */
  YYSYMBOL_elif_stmt_rep = 138,            /* elif_stmt_rep  */
  YYSYMBOL_while_stmt = 139,               /* while_stmt  */
  YYSYMBOL_140_4 = 140,                    /* $@4  */
  YYSYMBOL_for_stmt = 141,                 /* for_stmt  */
  YYSYMBOL_142_5 = 142,                    /* $@5  */
  YYSYMBOL_range_func = 143,               /* range_func  */
  YYSYMBOL_suite = 144,                    /* suite  */
  YYSYMBOL_stmt_rep = 145,                 /* stmt_rep  */
  YYSYMBOL_test = 146,                     /* test  */
  YYSYMBOL_test_nocond = 147,              /* test_nocond  */
  YYSYMBOL_or_test = 148,                  /* or_test  */
  YYSYMBOL_or_test_rep = 149,              /* or_test_rep  */
  YYSYMBOL_and_test = 150,                 /* and_test  */
  YYSYMBOL_and_test_rep = 151,             /* and_test_rep  */
  YYSYMBOL_not_test = 152,                 /* not_test  */
  YYSYMBOL_comparison = 153,               /* comparison  */
  YYSYMBOL_comparison_rep = 154,           /* comparison_rep  */
  YYSYMBOL_comp_op = 155,                  /* comp_op  */
  YYSYMBOL_star_expr = 156,                /* star_expr  */
  YYSYMBOL_expr = 157,                     /* expr  */
  YYSYMBOL_expr_rep = 158,                 /* expr_rep  */
  YYSYMBOL_xor_expr = 159,                 /* xor_expr  */
  YYSYMBOL_xor_expr_rep = 160,             /* xor_expr_rep  */
  YYSYMBOL_and_expr = 161,                 /* and_expr  */
  YYSYMBOL_and_expr_rep = 162,             /* and_expr_rep  */
  YYSYMBOL_shift_expr = 163,               /* shift_expr  */
  YYSYMBOL_shift_expr_rep = 164,           /* shift_expr_rep  */
  YYSYMBOL_shift_expr_rep_c1 = 165,        /* shift_expr_rep_c1  */
  YYSYMBOL_arith_expr = 166,               /* arith_expr  */
  YYSYMBOL_arith_expr_rep = 167,           /* arith_expr_rep  */
  YYSYMBOL_arith_expr_rep_c1 = 168,        /* arith_expr_rep_c1  */
  YYSYMBOL_term = 169,                     /* term  */
  YYSYMBOL_term_rep = 170,                 /* term_rep  */
  YYSYMBOL_term_rep_c1 = 171,              /* term_rep_c1  */
  YYSYMBOL_factor = 172,                   /* factor  */
  YYSYMBOL_factor_c1 = 173,                /* factor_c1  */
  YYSYMBOL_power = 174,                    /* power  */
  YYSYMBOL_power_opt = 175,                /* power_opt  */
  YYSYMBOL_atom_expr = 176,                /* atom_expr  */
  YYSYMBOL_await_opt = 177,                /* await_opt  */
  YYSYMBOL_trailer_rep = 178,              /* trailer_rep  */
  YYSYMBOL_atom = 179,                     /* atom  */
  YYSYMBOL_atom_opt1 = 180,                /* atom_opt1  */
  YYSYMBOL_atom_opt2 = 181,                /* atom_opt2  */
  YYSYMBOL_string_rep = 182,               /* string_rep  */
  YYSYMBOL_testlist_comp = 183,            /* testlist_comp  */
  YYSYMBOL_testlist_comp_c1 = 184,         /* testlist_comp_c1  */
  YYSYMBOL_testlist_comp_c2 = 185,         /* testlist_comp_c2  */
  YYSYMBOL_testlist_comp_c2_rep = 186,     /* testlist_comp_c2_rep  */
  YYSYMBOL_trailer = 187,                  /* trailer  */
  YYSYMBOL_subscriptlist = 188,            /* subscriptlist  */
  YYSYMBOL_COMMA_opt = 189,                /* COMMA_opt  */
  YYSYMBOL_COMMA_subscript_rep = 190,      /* COMMA_subscript_rep  */
  YYSYMBOL_subscript = 191,                /* subscript  */
  YYSYMBOL_sliceop = 192,                  /* sliceop  */
  YYSYMBOL_exprlist = 193,                 /* exprlist  */
  YYSYMBOL_expr_star_expr = 194,           /* expr_star_expr  */
  YYSYMBOL_COMMA_expr_star_expr_rep = 195, /* COMMA_expr_star_expr_rep  */
  YYSYMBOL_testlist = 196,                 /* testlist  */
  YYSYMBOL_class_name = 197,               /* class_name  */
  YYSYMBOL_classdef = 198,                 /* classdef  */
  YYSYMBOL_arglist = 199,                  /* arglist  */
  YYSYMBOL_COMMA_argument_rep = 200,       /* COMMA_argument_rep  */
  YYSYMBOL_argument = 201,                 /* argument  */
  YYSYMBOL_comp_iter = 202,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 203,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 204,                 /* comp_for  */
  YYSYMBOL_comp_if = 205,                  /* comp_if  */
  YYSYMBOL_yield_expr = 206                /* yield_expr  */
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
#define YYFINAL  105
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  266
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  380

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
       0,   152,   152,   157,   163,   170,   178,   179,   183,   210,
     210,   266,   266,   332,   342,   350,   366,   392,   418,   455,
     461,   473,   474,   477,   485,   493,   500,   510,   520,   528,
     529,   530,   531,   532,   534,   610,   613,   623,   626,   632,
     646,   650,   663,   664,   687,   704,   713,   721,   728,   732,
     733,   736,   746,   748,   749,   750,   751,   752,   753,   754,
     755,   756,   757,   758,   759,   760,   763,   769,   771,   772,
     773,   774,   777,   779,   780,   788,   790,   791,   798,   808,
     810,   811,   812,   813,   814,   815,   818,   821,   822,   824,
     833,   846,   857,   857,   869,   879,   890,   899,   899,   914,
     914,   951,   965,   985,   986,  1000,  1009,  1011,  1020,  1023,
    1026,  1036,  1039,  1058,  1072,  1087,  1090,  1110,  1127,  1143,
    1148,  1162,  1166,  1180,  1195,  1196,  1197,  1198,  1199,  1200,
    1201,  1202,  1208,  1209,  1217,  1226,  1235,  1238,  1252,  1261,
    1270,  1275,  1289,  1298,  1307,  1310,  1324,  1334,  1343,  1346,
    1359,  1369,  1373,  1378,  1398,  1401,  1427,  1438,  1439,  1442,
    1464,  1467,  1498,  1513,  1514,  1515,  1516,  1517,  1520,  1529,
    1531,  1532,  1533,  1536,  1547,  1553,  1564,  1573,  1769,  1775,
    1780,  1792,  1796,  1808,  1820,  1829,  1864,  1867,  1870,  1873,
    1874,  1875,  1878,  1882,  1883,  1885,  1888,  1889,  1900,  1911,
    1914,  1915,  1918,  1919,  1927,  1928,  1931,  1943,  1954,  1961,
    1970,  1983,  1991,  2003,  2010,  2024,  2032,  2038,  2044,  2047,
    2051,  2060,  2068,  2069,  2078,  2085,  2092,  2099,  2105,  2111,
    2117,  2119,  2125,  2127,  2134,  2140,  2146,  2148,  2149,  2152,
    2161,  2176,  2188,  2205,  2230,  2256,  2289,  2323,  2342,  2353,
    2371,  2377,  2394,  2407,  2413,  2421,  2427,  2433,  2435,  2436,
    2438,  2447,  2456,  2461,  2463,  2470,  2476
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
  "funcdef", "$@1", "$@2", "parameters", "typedargslist", "datatype",
  "stmt", "simple_stmt", "small_stmt_list", "small_stmt", "expr_stmt",
  "expr_stmt_tail", "decl_type", "augassign_op", "annassign",
  "testlist_star_expr", "testlist_star_expr_opt1",
  "testlist_star_expr_rep", "augassign", "del_stmt", "pass_stmt",
  "flow_stmt", "break_stmt", "continue_stmt", "return_stmt", "yield_stmt",
  "global_stmt", "global_name_list", "compound_stmt", "async_stmt",
  "async_stmt_content", "ifkeyword", "if_stmt", "$@3", "elif_stmt_rep",
  "while_stmt", "$@4", "for_stmt", "$@5", "range_func", "suite",
  "stmt_rep", "test", "test_nocond", "or_test", "or_test_rep", "and_test",
  "and_test_rep", "not_test", "comparison", "comparison_rep", "comp_op",
  "star_expr", "expr", "expr_rep", "xor_expr", "xor_expr_rep", "and_expr",
  "and_expr_rep", "shift_expr", "shift_expr_rep", "shift_expr_rep_c1",
  "arith_expr", "arith_expr_rep", "arith_expr_rep_c1", "term", "term_rep",
  "term_rep_c1", "factor", "factor_c1", "power", "power_opt", "atom_expr",
  "await_opt", "trailer_rep", "atom", "atom_opt1", "atom_opt2",
  "string_rep", "testlist_comp", "testlist_comp_c1", "testlist_comp_c2",
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

#define YYPACT_NINF (-273)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-12)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      32,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,    40,   976,  -273,  1005,    57,   976,  1005,    67,   976,
     133,   976,  -273,  -273,  -273,  -273,  -273,  1022,  -273,    80,
     231,  -273,   109,   298,    54,  -273,  -273,  -273,    17,  -273,
     782,    61,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,    76,  -273,  -273,  -273,  -273,   102,   116,   136,
    -273,  -273,   150,   104,   108,   112,    31,    85,   103,  1022,
    -273,   120,   131,    70,   126,     8,  -273,  -273,  -273,   101,
    -273,  -273,  -273,   157,   117,  -273,  -273,  -273,  -273,   119,
    -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,   113,  -273,
      90,  -273,  -273,   124,  -273,  -273,  -273,  -273,  -273,    46,
     121,  -273,   472,    21,   192,   976,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,   778,   838,   132,   520,   976,   976,   156,   976,   179,
    -273,   168,   190,  -273,  -273,  -273,  -273,  -273,  -273,   150,
    1022,  1022,   151,  1022,   158,  1022,   153,  -273,  -273,    31,
    1022,  -273,  -273,    85,  1022,  -273,  -273,  -273,  -273,  -273,
     103,  1022,  -273,  1022,  -273,    70,   616,   693,   214,    70,
    -273,  -273,   676,   520,  -273,   215,  1005,   147,   149,   217,
    -273,  1005,   198,   838,  -273,   154,  -273,  -273,  -273,    69,
    -273,   160,   148,   155,  -273,  -273,  -273,   568,   164,   162,
    -273,  -273,  -273,  -273,  -273,   838,   234,  -273,    42,   225,
    -273,   976,  -273,   976,  -273,  -273,  1022,  -273,  -273,  1022,
    -273,  1022,  -273,  1022,  1022,  -273,  1022,  -273,  1022,  -273,
    -273,    70,   976,   976,  -273,    11,   175,   171,  -273,   884,
     173,   178,   172,  -273,  -273,   180,   181,  -273,   185,  -273,
    -273,  1005,   520,  -273,   237,  -273,  -273,  -273,   838,   252,
     254,  -273,   976,   520,  -273,  -273,   258,  -273,  -273,   424,
    -273,   976,    97,   976,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,  -273,   976,  -273,  -273,   761,   191,
     976,   189,  -273,   884,  -273,   930,  -273,   193,   520,   194,
     976,   197,  -273,  -273,   976,  -273,  -273,  -273,   196,   200,
     201,  -273,   204,  -273,   364,   208,   209,   211,   976,  -273,
    -273,  -273,   761,  -273,  -273,   189,  -273,  -273,   930,  -273,
    -273,   520,    -8,   520,    22,   263,   252,   520,  -273,  -273,
    -273,   520,   520,   520,   212,  -273,  -273,  -273,  -273,  -273,
     976,  -273,   976,  -273,  -273,  -273,   218,  -273,  -273,  -273,
    -273,  -273,   520,   222,    22,  -273,  -273,  -273,  -273,  -273
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   185,   187,     3,     7,   192,   179,    67,   190,    72,
     191,     0,    75,    73,     0,     0,     0,     0,     0,     0,
       0,     0,   266,   186,   196,   170,   171,     0,   172,     0,
       0,   189,     0,     0,     0,    83,     6,    21,     0,    29,
      35,    48,    30,    31,    32,    68,    69,    70,    71,    33,
      22,    85,     0,    80,    81,    82,    49,   108,   111,   115,
     119,    50,   121,   136,   140,   144,   148,   154,   160,     0,
     169,   174,     0,   178,   188,     0,    84,    76,   243,   242,
      74,   238,   237,     0,   236,     8,    97,    66,    79,    77,
     118,    87,    86,    88,    89,   134,   200,   201,     0,   194,
     199,   193,   184,     0,   195,     1,     2,     4,     5,     0,
       9,    23,     0,     0,     0,     0,    53,    54,    55,    57,
      65,    58,    56,    59,    60,    61,    63,    62,    64,    34,
      37,     0,    47,    46,     0,     0,     0,   110,     0,   114,
     130,   132,     0,   124,   125,   128,   127,   126,   129,   120,
       0,     0,   135,     0,   139,     0,   143,   151,   152,   147,
       0,   157,   158,   153,     0,   163,   165,   167,   166,   164,
     159,     0,   168,     0,   173,     0,     0,     0,     0,   177,
     181,   197,     0,     0,   241,     0,   234,   235,     0,     0,
     182,     0,     0,   204,   198,   205,   263,   202,   183,    15,
      14,     0,     0,     0,    25,    28,    24,     0,    40,    38,
      44,    39,    43,    42,    52,    45,     0,   103,    94,     0,
     113,     0,   117,     0,   133,   131,     0,   123,   138,     0,
     142,     0,   146,     0,     0,   150,     0,   156,     0,   162,
     175,   176,     0,     0,   211,   257,     0,   250,   213,   230,
     222,     0,   218,   214,   180,     0,     0,   246,     0,    99,
     240,   233,     0,    78,     0,   262,   208,   209,   203,     0,
       0,    13,     0,     0,    26,    27,     0,    36,    51,     0,
      92,     0,    91,     0,   112,   116,   122,   137,   141,   145,
     149,   155,   161,   256,   255,     0,   253,   210,   248,   249,
     232,   228,   227,   229,   212,   219,   216,   217,     0,     0,
       0,     0,   239,    98,     0,   206,   207,    17,    19,    16,
       0,    12,     0,   106,     0,     0,     0,     0,     0,   107,
     254,   252,   247,   231,   224,   226,   225,   221,   219,   215,
     245,     0,     0,     0,   261,     0,     0,     0,    41,   104,
     105,     0,     0,     0,     0,   251,   223,   220,   244,   101,
       0,   100,     0,   260,   258,   259,     0,    18,    10,    93,
      96,    90,     0,     0,   265,   109,    20,    95,   102,   264
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -273,  -273,  -273,  -273,   272,  -273,  -273,  -273,  -239,  -273,
     -30,     1,  -273,   -97,  -273,  -273,  -273,  -273,    86,  -273,
    -113,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,   276,  -273,  -273,  -151,  -273,   -12,  -273,  -129,  -273,
    -120,  -273,   -17,  -273,  -273,   161,    -9,    -3,  -273,  -125,
    -273,  -126,  -273,  -127,  -273,   144,  -116,  -273,   141,  -141,
    -273,   139,   -59,  -273,  -273,  -273,  -273,  -273,   140,   242,
    -273,  -273,  -273,   289,  -273,  -273,  -273,  -148,  -273,    15,
    -273,  -272,  -247,    -5,  -164,  -273,   199,  -273,  -273,   145,
    -273,  -260,   -42,   146,   -93,  -273,   -16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    32,    33,    34,    35,   202,   203,   110,   201,   319,
      36,   217,   113,    38,    39,   129,   209,   211,   130,    40,
      41,   133,   131,    42,    43,    44,    45,    46,    47,    48,
      49,    89,    50,    51,    92,    52,    53,   325,   282,    54,
     188,    55,   311,   259,   218,   324,    56,   374,    57,   137,
      58,   139,    59,    60,   149,   150,    61,    62,   152,    63,
     154,    64,   156,    65,   159,   160,    66,   163,   164,    67,
     170,   171,    68,    69,    70,   174,    71,    72,   179,    73,
      98,   103,    74,    99,   100,   194,   195,   180,   251,   306,
     307,   252,   302,    83,    84,   187,    80,    75,    76,   246,
     299,   247,   363,   196,   364,   365,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    37,    90,   108,    86,    81,   219,   197,    81,    94,
     172,    82,    87,   101,    82,   205,   220,    96,    96,   214,
      97,    97,   260,   237,    95,   111,   228,   230,   232,   206,
     317,   254,   257,   337,    37,     1,     2,   191,   331,     3,
       4,     5,     6,    78,   235,     7,     8,     9,   191,   199,
     192,    10,    11,   280,   334,    12,   336,    13,    14,   359,
      85,   192,    15,   362,   360,    16,   357,    17,    18,    19,
      88,    20,   355,    21,   182,    22,    23,    24,    25,    26,
      27,   183,   281,     1,     2,   157,   158,   295,   356,     5,
       6,    28,   112,   254,     8,   291,   207,   312,    29,    10,
      30,   284,   278,   210,   287,   288,   289,   367,   327,   105,
     275,   313,   239,   200,   240,   213,   191,    19,   290,    79,
     109,   222,   321,    22,    23,    24,    25,    26,    27,   192,
      31,   161,   162,   132,     1,     2,   176,   328,   177,    28,
       5,   269,   270,   135,   178,     8,    29,   227,    30,   134,
      10,   165,   296,   166,   167,   168,   169,   340,   136,    14,
     138,   151,   193,    15,   245,   250,   153,   140,   155,   173,
     245,   181,   141,   184,   185,    23,    24,    81,    31,   292,
     190,   266,    81,    82,   267,   344,   264,   142,    82,   186,
     358,   189,   361,   198,   -11,   208,   368,    29,   221,    30,
     369,   370,   371,   223,   215,   224,   285,   225,   229,   233,
     143,   144,   145,   146,   147,   148,   231,   253,   258,   261,
     263,   377,   262,   286,   191,   272,   268,   271,   273,    31,
     293,   294,   276,   375,     1,     2,   283,   301,   115,   279,
       5,     6,   297,   298,   305,     8,   303,   304,   309,   323,
      10,   310,    81,   308,   314,   199,   315,   318,    82,   316,
     320,   322,   300,   332,   345,   338,   366,   341,    19,   326,
     343,   329,   346,   348,   347,    23,    24,    25,    26,    27,
      37,   351,   352,   330,   353,   372,   245,   376,   333,   378,
      28,   335,    91,   250,   350,   277,    93,    29,   342,    30,
     102,     1,     2,   234,   236,   106,   107,     5,     6,   238,
     226,     7,     8,     9,   175,   241,   354,    10,    11,   104,
     245,    12,   339,    13,    14,    37,   250,   256,    15,    31,
     212,    16,   379,    17,    18,    19,     0,    20,   265,    21,
       0,    22,    23,    24,    25,    26,    27,     0,   373,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,     0,
       0,     0,     0,     0,    29,     0,    30,     1,     2,     0,
     349,     0,     0,     5,     6,     0,     0,     7,     8,     9,
       0,     0,     0,    10,    11,     0,     0,    12,     0,    13,
      14,     0,     0,     0,    15,     0,    31,    16,     0,    17,
      18,    19,     0,    20,     0,    21,     0,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     1,     2,     0,
      29,     0,    30,     5,     6,     0,     0,     7,     8,     9,
       0,     0,     0,    10,    11,     0,     0,    12,     0,    13,
      14,     0,     0,     0,    15,     0,     0,    16,     0,    17,
      18,    19,    31,    20,     0,    21,     0,    22,    23,    24,
      25,    26,    27,     0,     0,     1,     2,     0,     0,     0,
     204,     5,     6,    28,     0,     7,     8,     9,     0,     0,
      29,    10,    30,     0,     0,    12,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
       0,     0,     0,     0,     0,    22,    23,    24,    25,    26,
      27,     0,    31,     1,     2,     0,     0,     0,   216,     5,
       6,    28,     0,     7,     8,     9,     0,     0,    29,    10,
      30,     0,     0,    12,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    19,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,     0,
      31,     1,     2,     0,     0,     0,   274,     5,     6,    28,
       0,     7,     8,     9,     0,     0,    29,    10,    30,     0,
       0,    12,     0,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    19,     0,     0,     0,     0,
       0,    22,    23,    24,    25,    26,    27,     0,    31,     1,
       2,     0,     0,     0,     0,     5,     6,    28,     0,     0,
       8,     0,     0,     0,    29,    10,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   242,   243,    31,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     1,
       2,     0,    29,   244,    30,     5,     6,     0,     0,     0,
       8,     0,     0,     0,     0,    10,     1,     2,     0,     0,
       0,     0,     5,     6,     0,     0,     0,     8,     0,     0,
       0,     0,    10,    19,    31,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   242,   243,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    28,     0,    23,    24,    25,
      26,     0,    29,   255,    30,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,     0,     0,     0,    29,
       0,    30,   248,     0,     1,     2,   249,     0,     0,     0,
       5,     6,     0,     0,    31,     8,     0,     0,     0,     0,
      10,     1,     2,     0,     0,     0,     0,     5,     6,     0,
       0,    31,     8,     0,     0,     0,     0,    10,    19,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   242,
     243,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      28,    22,    23,    24,    25,    26,     0,    29,     0,    30,
       0,     0,     0,     0,     0,     0,     0,    28,     0,     0,
       0,     1,     2,     0,    29,     0,    30,     5,     6,     0,
       0,     0,     8,     0,     0,   114,     0,    10,   115,    31,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,     0,     0,    19,    31,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,     1,     2,     0,
       0,     0,     0,     5,     6,     0,     0,    28,     8,     0,
       0,     0,     0,    10,    29,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,     0,     1,     2,     0,    31,     0,     0,     5,
       6,     0,     0,    28,     8,     0,     0,     0,     0,    10,
      29,     0,    30,     0,     0,     0,     0,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,     0,     1,
       2,     0,    31,     0,     0,     5,     6,     0,     0,    28,
       8,     0,     0,     0,     0,    10,    29,     0,    30,     0,
       0,     0,     0,   249,     0,     0,     0,     0,     1,     2,
       0,     0,     0,    19,     5,     6,     0,     0,     0,     8,
      23,    24,    25,    26,    10,     1,     2,     0,    31,     0,
       0,     5,     6,     0,     0,    28,     8,     0,     0,     0,
       0,    10,    29,     0,    30,     0,     0,     0,     0,    23,
      24,    25,    26,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,    23,    24,    25,    26,
       0,    29,     0,    30,    31,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     0,     0,     0,    29,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31
};

static const yytype_int16 yycheck[] =
{
      12,     0,    19,    33,    16,    14,   135,   100,    17,    21,
      69,    14,    17,    29,    17,   112,   136,    29,    30,   132,
      29,    30,   186,   164,    27,     8,   151,   153,   155,     8,
     269,   179,   183,   305,    33,     3,     4,    26,   298,     7,
       8,     9,    10,     3,   160,    13,    14,    15,    26,     3,
      39,    19,    20,    11,   301,    23,   303,    25,    26,    67,
       3,    39,    30,    41,    72,    33,   338,    35,    36,    37,
       3,    39,   332,    41,    66,    43,    44,    45,    46,    47,
      48,    73,    40,     3,     4,    54,    55,    76,   335,     9,
      10,    59,    75,   241,    14,   236,    75,   261,    66,    19,
      68,   221,   215,   115,   229,   231,   233,   346,    11,     0,
     207,   262,   171,    67,   173,   131,    26,    37,   234,   131,
      66,   138,   273,    43,    44,    45,    46,    47,    48,    39,
      98,    46,    47,    72,     3,     4,    66,    40,    68,    59,
       9,    72,    73,    41,    74,    14,    66,   150,    68,    73,
      19,    48,   245,    50,    51,    52,    53,   308,    42,    26,
      24,    57,    72,    30,   176,   177,    58,    17,    56,    49,
     182,    45,    22,    72,    17,    44,    45,   186,    98,   238,
      67,   193,   191,   186,   193,   314,   191,    37,   191,    72,
     341,    72,   343,    69,    73,     3,   347,    66,    42,    68,
     351,   352,   353,    24,    72,    37,   223,    17,    57,    56,
      60,    61,    62,    63,    64,    65,    58,     3,     3,    72,
       3,   372,    73,   226,    26,    77,    72,    67,    73,    98,
     242,   243,    68,   362,     3,     4,    11,   249,    76,     5,
       9,    10,    67,    72,    72,    14,    73,    69,    67,   279,
      19,    66,   261,    73,    17,     3,   268,     3,   261,   268,
     272,     3,    73,    72,    68,    72,     3,    73,    37,   281,
      73,   283,    72,    69,    73,    44,    45,    46,    47,    48,
     279,    73,    73,   295,    73,    73,   298,    69,   300,    67,
      59,   303,    20,   305,   324,   209,    20,    66,   310,    68,
      69,     3,     4,   159,   163,     7,     8,     9,    10,   170,
     149,    13,    14,    15,    72,   175,   328,    19,    20,    30,
     332,    23,   307,    25,    26,   324,   338,   182,    30,    98,
     131,    33,   374,    35,    36,    37,    -1,    39,   192,    41,
      -1,    43,    44,    45,    46,    47,    48,    -1,   360,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,     3,     4,    -1,
       6,    -1,    -1,     9,    10,    -1,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    98,    33,    -1,    35,
      36,    37,    -1,    39,    -1,    41,    -1,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,     3,     4,    -1,
      66,    -1,    68,     9,    10,    -1,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    35,
      36,    37,    98,    39,    -1,    41,    -1,    43,    44,    45,
      46,    47,    48,    -1,    -1,     3,     4,    -1,    -1,    -1,
       8,     9,    10,    59,    -1,    13,    14,    15,    -1,    -1,
      66,    19,    68,    -1,    -1,    23,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    -1,    98,     3,     4,    -1,    -1,    -1,     8,     9,
      10,    59,    -1,    13,    14,    15,    -1,    -1,    66,    19,
      68,    -1,    -1,    23,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    -1,
      98,     3,     4,    -1,    -1,    -1,     8,     9,    10,    59,
      -1,    13,    14,    15,    -1,    -1,    66,    19,    68,    -1,
      -1,    23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    -1,    98,     3,
       4,    -1,    -1,    -1,    -1,     9,    10,    59,    -1,    -1,
      14,    -1,    -1,    -1,    66,    19,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,     3,
       4,    -1,    66,    67,    68,     9,    10,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    19,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    19,    37,    98,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    59,    -1,    44,    45,    46,
      47,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    68,    69,    -1,     3,     4,    73,    -1,    -1,    -1,
       9,    10,    -1,    -1,    98,    14,    -1,    -1,    -1,    -1,
      19,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    -1,
      -1,    98,    14,    -1,    -1,    -1,    -1,    19,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      59,    43,    44,    45,    46,    47,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,     3,     4,    -1,    66,    -1,    68,     9,    10,    -1,
      -1,    -1,    14,    -1,    -1,    73,    -1,    19,    76,    98,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    -1,    37,    98,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    -1,    -1,    59,    14,    -1,
      -1,    -1,    -1,    19,    66,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,     3,     4,    -1,    98,    -1,    -1,     9,
      10,    -1,    -1,    59,    14,    -1,    -1,    -1,    -1,    19,
      66,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,     3,
       4,    -1,    98,    -1,    -1,     9,    10,    -1,    -1,    59,
      14,    -1,    -1,    -1,    -1,    19,    66,    -1,    68,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,    -1,    37,     9,    10,    -1,    -1,    -1,    14,
      44,    45,    46,    47,    19,     3,     4,    -1,    98,    -1,
      -1,     9,    10,    -1,    -1,    59,    14,    -1,    -1,    -1,
      -1,    19,    66,    -1,    68,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    44,    45,    46,    47,
      -1,    66,    -1,    68,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
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
      68,    98,   101,   102,   103,   104,   110,   111,   113,   114,
     119,   120,   123,   124,   125,   126,   127,   128,   129,   130,
     132,   133,   135,   136,   139,   141,   146,   148,   150,   152,
     153,   156,   157,   159,   161,   163,   166,   169,   172,   173,
     174,   176,   177,   179,   182,   197,   198,   206,     3,   146,
     196,   156,   157,   193,   194,     3,   146,   193,     3,   131,
     152,   104,   134,   141,   146,   157,   146,   156,   180,   183,
     184,   206,    69,   181,   183,     0,     7,     8,   110,    66,
     107,     8,    75,   112,    73,    76,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   115,
     118,   122,    72,   121,    73,    41,    42,   149,    24,   151,
      17,    22,    37,    60,    61,    62,    63,    64,    65,   154,
     155,    57,   158,    58,   160,    56,   162,    54,    55,   164,
     165,    46,    47,   167,   168,    48,    50,    51,    52,    53,
     170,   171,   172,    49,   175,   179,    66,    68,    74,   178,
     187,    45,    66,    73,    72,    17,    72,   195,   140,    72,
      67,    26,    39,    72,   185,   186,   203,   204,    69,     3,
      67,   108,   105,   106,     8,   113,     8,    75,     3,   116,
     146,   117,   196,   206,   120,    72,     8,   111,   144,   148,
     150,    42,   152,    24,    37,    17,   155,   157,   159,    57,
     161,    58,   163,    56,   165,   166,   168,   169,   171,   172,
     172,   178,    48,    49,    67,   146,   199,   201,    69,    73,
     146,   188,   191,     3,   187,    67,   199,   144,     3,   143,
     194,    72,    73,     3,   193,   203,   146,   156,    72,    72,
      73,    67,    77,    73,     8,   113,    68,   118,   120,     5,
      11,    40,   138,    11,   150,   152,   157,   159,   161,   163,
     166,   169,   172,   146,   146,    76,   204,    67,    72,   200,
      73,   146,   192,    73,    69,    72,   189,   190,    73,    67,
      66,   142,   194,   144,    17,   146,   156,   108,     3,   109,
     146,   144,     3,   110,   145,   137,   146,    11,    40,   146,
     146,   201,    72,   146,   192,   146,   192,   191,    72,   189,
     144,    73,   146,    73,   148,    68,    72,    73,    69,     6,
     110,    73,    73,    73,   146,   201,   192,   191,   144,    67,
      72,   144,    41,   202,   204,   205,     3,   108,   144,   144,
     144,   144,    73,   146,   147,   148,    69,   144,    67,   202
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   102,   102,   102,   102,   103,   105,
     104,   106,   104,   107,   107,   108,   108,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   114,   114,   115,   115,   115,   115,
     116,   116,   117,   117,   118,   119,   119,   119,   119,   120,
     120,   121,   121,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   123,   124,   125,   125,
     125,   125,   126,   127,   128,   128,   129,   130,   131,   131,
     132,   132,   132,   132,   132,   132,   133,   134,   134,   135,
     136,   136,   137,   136,   136,   138,   138,   140,   139,   142,
     141,   143,   143,   144,   144,   145,   145,   146,   146,   147,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     153,   153,   154,   154,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   161,   162,   162,   163,   163,   164,
     164,   165,   165,   166,   166,   167,   167,   168,   168,   169,
     169,   170,   170,   171,   171,   171,   171,   171,   172,   172,
     173,   173,   173,   174,   174,   175,   176,   176,   176,   177,
     178,   178,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   180,   180,   181,   182,   182,   183,   183,
     184,   184,   185,   185,   185,   185,   186,   186,   186,   186,
     187,   187,   187,   187,   187,   188,   188,   188,   188,   189,
     190,   190,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   192,   192,   193,   193,   193,   193,   194,   194,   195,
     195,   196,   196,   197,   198,   198,   198,   199,   199,   199,
     199,   200,   200,   201,   201,   201,   201,   201,   202,   202,
     203,   203,   204,   204,   205,   205,   206
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     1,     2,     0,
       7,     0,     5,     3,     2,     1,     3,     3,     5,     1,
       4,     1,     1,     2,     3,     3,     4,     3,     2,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     2,     2,
       1,     4,     1,     1,     2,     3,     2,     2,     1,     1,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       7,     4,     0,     7,     3,     5,     4,     0,     5,     0,
       7,     4,     6,     1,     4,     2,     1,     5,     1,     1,
       2,     1,     3,     2,     2,     1,     3,     2,     2,     1,
       2,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     2,     2,     1,     3,     2,     2,
       1,     3,     2,     2,     1,     3,     2,     2,     1,     3,
       2,     1,     1,     2,     1,     3,     2,     1,     1,     2,
       1,     3,     2,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     2,     1,     2,     3,     2,     1,     1,
       2,     1,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     2,     1,     1,     3,     3,     2,     2,
       3,     2,     3,     2,     2,     3,     2,     2,     1,     1,
       3,     2,     1,     4,     3,     3,     3,     2,     2,     2,
       1,     2,     1,     3,     2,     2,     1,     1,     1,     3,
       2,     2,     1,     2,     6,     5,     3,     3,     2,     2,
       1,     3,     2,     2,     3,     2,     2,     1,     1,     1,
       5,     4,     2,     1,     3,     2,     1
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
#line 152 "parser.y"
                               {
    (yyval.node) = root;
    root->children.push_back((yyvsp[-1].node));
    root->children.push_back((yyvsp[0].node));
  }
#line 2100 "parser.cpp"
    break;

  case 3: /* file_input: ENDMARKER  */
#line 157 "parser.y"
              {
    (yyval.node) = NULL;
    }
#line 2108 "parser.cpp"
    break;

  case 4: /* newline_stat_rep: newline_stat_rep NEWLINE  */
#line 163 "parser.y"
                             {
    Node* n = create_node("newline_stat_rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
  }
#line 2120 "parser.cpp"
    break;

  case 5: /* newline_stat_rep: newline_stat_rep stmt  */
#line 170 "parser.y"
                          { 
    Node* n = create_node("newline_stat_rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));
  }
#line 2133 "parser.cpp"
    break;

  case 6: /* newline_stat_rep: stmt  */
#line 178 "parser.y"
         {  (yyval.node) = (yyvsp[0].node);}
#line 2139 "parser.cpp"
    break;

  case 7: /* newline_stat_rep: NEWLINE  */
#line 179 "parser.y"
            {  
    // cout<<yylineno<<endl;
  }
#line 2147 "parser.cpp"
    break;

  case 8: /* funcname: DEF NAME  */
#line 183 "parser.y"
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
               newtab->tab_type = FUNC;
              //  tab->childs.push_back(newtab);
               tab->childs[(yyvsp[0].node)->label] = newtab;
               tab=newtab;
             }
             else {
              cout<<"Function redeclared in line no "<< (yyvsp[0].node)->line_number<<endl;
                      //exit(1);
             }
            // cout<<"funcname "<<$1->line_number<<endl;
          }
#line 2177 "parser.cpp"
    break;

  case 9: /* $@1: %empty  */
#line 210 "parser.y"
                               {
             codepush("begin",(yyvsp[-1].node)->label,"","",-1);
            SYMTAB* newt = new SYMTAB();
            newt = tab->parent;
            if(newt->SYMVAL.find((yyvsp[-1].node)->label)!= newt->SYMVAL.end())
            {
                newt->SYMVAL[(yyvsp[-1].node)->label].identity=FUNC;
                newt->SYMVAL[(yyvsp[-1].node)->label].scope=curr_scope;
                newt->SYMVAL[(yyvsp[-1].node)->label].line_no=(yyvsp[-1].node)->line_number;
                newt->SYMVAL[(yyvsp[-1].node)->label].name=(yyvsp[-1].node)->label;
                newt->SYMVAL[(yyvsp[-1].node)->label].size=(yyvsp[0].node)->count;
                newt->SYMVAL[(yyvsp[-1].node)->label].params=(yyvsp[0].node)->p_f;
            }
            for(int i=0;i<arguments.size();i++) { 
            string s1 = get<0>(arguments[i]);
            codepush("","popparam","",tab->SYMVAL[s1].temp_var,-1);
            codepush("",tab->SYMVAL[s1].temp_var,"",get<0>(arguments[i]),-1);}
            }
#line 2200 "parser.cpp"
    break;

  case 10: /* funcdef: funcname parameters $@1 ARROW test COLON suite  */
#line 228 "parser.y"
                                  {
             Node* n = create_node("Function");
             n->children.push_back((yyvsp[-6].node));
             n->children.push_back((yyvsp[-5].node));
             n->children.push_back((yyvsp[-3].node));
             n->children.push_back((yyvsp[-2].node));
             n->children.push_back((yyvsp[-1].node));
             n->children.push_back((yyvsp[0].node));
             (yyval.node) =n;
             tab=tab->parent;
             if(tab->SYMVAL.find((yyvsp[-6].node)->label)!= tab->SYMVAL.end()){
                tab->SYMVAL[(yyvsp[-6].node)->label].identity=FUNC;
                tab->SYMVAL[(yyvsp[-6].node)->label].scope=curr_scope;
                tab->SYMVAL[(yyvsp[-6].node)->label].line_no=(yyvsp[-6].node)->line_number;
                tab->SYMVAL[(yyvsp[-6].node)->label].type=(yyvsp[-2].node)->type;
                tab->SYMVAL[(yyvsp[-6].node)->label].name=(yyvsp[-6].node)->label;
                tab->SYMVAL[(yyvsp[-6].node)->label].size=(yyvsp[-5].node)->count;
                tab->SYMVAL[(yyvsp[-6].node)->label].params=(yyvsp[-5].node)->p_f;
             }

             else{
              cout<<"error in inserting function" << endl;
              //exit(1);
             }
             
              if(((yyvsp[-2].node)->type == "bool" && (yyvsp[0].node)->type == "int")||((yyvsp[-2].node)->type == "float" && (yyvsp[0].node)->type =="int"))
              {

              }
              else {
                if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)cout<<"Function return ";
                check_type((yyvsp[-2].node)->type , (yyvsp[0].node)->type , (yyvsp[-6].node)->line_number);
              }
            //  cout<<$1->line_number<<endl;
            // check_type($4->type , $5->type , $1->line_number);
             codepush("","$ra","","goto",-1);
             arguments.clear();
         }
#line 2243 "parser.cpp"
    break;

  case 11: /* $@2: %empty  */
#line 266 "parser.y"
                            {
             codepush("begin",(yyvsp[-1].node)->label,"","",-1);
            SYMTAB* newt = new SYMTAB();
            newt = tab->parent;
            if(newt->SYMVAL.find((yyvsp[-1].node)->label)!= newt->SYMVAL.end())
            {
                newt->SYMVAL[(yyvsp[-1].node)->label].identity=FUNC;
                newt->SYMVAL[(yyvsp[-1].node)->label].scope=curr_scope;
                newt->SYMVAL[(yyvsp[-1].node)->label].line_no=(yyvsp[-1].node)->line_number;
                newt->SYMVAL[(yyvsp[-1].node)->label].name=(yyvsp[-1].node)->label;
                newt->SYMVAL[(yyvsp[-1].node)->label].size=(yyvsp[0].node)->count;
                newt->SYMVAL[(yyvsp[-1].node)->label].params=(yyvsp[0].node)->p_f;
            }
        for(int i=0;i<arguments.size();i++) { 
        string s1 = get<0>(arguments[i]);
        codepush("","popparam","",tab->SYMVAL[s1].temp_var,-1);
        codepush("",tab->SYMVAL[s1].temp_var,"",get<0>(arguments[i]),-1);}}
#line 2265 "parser.cpp"
    break;

  case 12: /* funcdef: funcname parameters $@2 COLON suite  */
#line 282 "parser.y"
                                                                                        {
             Node* n = create_node("Function");
             n->children.push_back((yyvsp[-4].node));
             n->children.push_back((yyvsp[-3].node));
             n->children.push_back((yyvsp[-1].node));
             n->children.push_back((yyvsp[0].node));
             (yyval.node) =n;
             tab=tab->parent;
             if(tab!=NULL){

               if(tab->SYMVAL.find((yyvsp[-4].node)->label)!= tab->SYMVAL.end()){
                  tab->SYMVAL[(yyvsp[-4].node)->label].identity=FUNC;
                  tab->SYMVAL[(yyvsp[-4].node)->label].scope=curr_scope;
                  tab->SYMVAL[(yyvsp[-4].node)->label].line_no=(yyvsp[-4].node)->line_number;
                  tab->SYMVAL[(yyvsp[-4].node)->label].type="None";
                  tab->SYMVAL[(yyvsp[-4].node)->label].name=(yyvsp[-4].node)->label;
                  tab->SYMVAL[(yyvsp[-4].node)->label].size=(yyvsp[-3].node)->count;
                  tab->SYMVAL[(yyvsp[-4].node)->label].params=(yyvsp[-3].node)->p_f;
               }
               else{
                cout<<"error in inserting function "<<endl;
                exit(0);
               }
              if((yyvsp[0].node)->type != "None")
              {
                if((yyvsp[0].node)->type != "None") cout<<"Function return ";
                check_type((yyvsp[0].node)->type , "None" , (yyvsp[-4].node)->line_number);
              }
            // check_type("void" , $3->type , $1->line_number);
             }
             codepush("","$ra","","goto",-1);
             arguments.clear();
         }
#line 2303 "parser.cpp"
    break;

  case 13: /* parameters: LPAREN typedargslist RPAREN  */
#line 332 "parser.y"
                                         {
                Node* n = create_node("Parameters");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                n->children.push_back((yyvsp[0].node));
                n->count=(yyvsp[-1].node)->count;
                (yyval.node)->line_number = (yyvsp[-2].node)->line_number;
                n->p_f=(yyvsp[-1].node)->p_f;
                (yyval.node)=n;
            }
#line 2318 "parser.cpp"
    break;

  case 14: /* parameters: LPAREN RPAREN  */
#line 342 "parser.y"
                           {
                (yyval.node) = create_node("Parameters");
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));
                (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
            }
#line 2329 "parser.cpp"
    break;

  case 15: /* typedargslist: NAME  */
#line 350 "parser.y"
                     {
                  Node *n = create_node("Typedargslist1");
                  n->children.push_back((yyvsp[0].node));
                  Param* temp=new Param();
                  temp->par_name=(yyvsp[0].node)->label;
                  // cout<<tab->tab_type<<endl;
                  if((tab->parent->tab_type ==  CLS )&& ((yyvsp[0].node)->label == "self")){ 
                    n->count = 0;
                  }
                  else{
                    n->p_f.push_back(temp);
                    n->count=1;
                  } 
                  (yyval.node)=n;
                  arguments.push_back(make_tuple((yyvsp[0].node)->label,"",(yyvsp[0].node)->type,0,0));
                  }
#line 2350 "parser.cpp"
    break;

  case 16: /* typedargslist: NAME COLON datatype  */
#line 366 "parser.y"
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
                  cout<<"Already declared "<<(yyvsp[-2].node)->label<<" in line no "<<(yyvsp[-2].node)->line_number<<endl;
                    //exit(1);
                  }
                  tab->SYMVAL[(yyvsp[-2].node)->label].identity=NORMIE;
                  tab->SYMVAL[(yyvsp[-2].node)->label].scope=curr_scope;
                  tab->SYMVAL[(yyvsp[-2].node)->label].line_no=(yyvsp[-2].node)->line_number;
                  tab->SYMVAL[(yyvsp[-2].node)->label].type=(yyvsp[0].node)->label;
                  tab->SYMVAL[(yyvsp[-2].node)->label].name=(yyvsp[-2].node)->label;
                  tab->SYMVAL[(yyvsp[-2].node)->label].size=0;
                  (yyval.node) = n;
                  string t = new_temporary();
                  tab->SYMVAL[(yyvsp[-2].node)->label].temp_var = t;
                  arguments.push_back(make_tuple((yyvsp[-2].node)->label,t,(yyvsp[0].node)->type,0,0));
                }
#line 2381 "parser.cpp"
    break;

  case 17: /* typedargslist: NAME COMMA typedargslist  */
#line 392 "parser.y"
                                         {
                  Node *n = create_node("Typedargslist3");
                  n->children.push_back((yyvsp[-2].node));
                  n->children.push_back((yyvsp[-1].node));
                  for(int i=0; i<(yyvsp[0].node)->children.size(); i++) {
                    n->children.push_back((yyvsp[0].node)->children[i]);
                  }
                  (yyval.node) = n;
                  Param* temp=new Param();
                  temp->par_type=(yyvsp[-2].node)->label;
                  vector<Param*> t2;
                  if((tab->parent->tab_type == 3 )&& ((yyvsp[-2].node)->label == "self") )
                  {
                    n->count = (yyvsp[0].node)->count;

                  }
                  else {
                    // cout<<"yes"<<endl;
                    n->count=1+(yyvsp[0].node)->count;
                    t2.push_back(temp);
                  }

                  t2.insert(t2.end(),(yyvsp[0].node)->p_f.begin(),(yyvsp[0].node)->p_f.end());
                  // cout<<t2.size()<<endl;
                  n->p_f=t2;
                }
#line 2412 "parser.cpp"
    break;

  case 18: /* typedargslist: NAME COLON datatype COMMA typedargslist  */
#line 418 "parser.y"
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
                  cout<<"Already declared "<<(yyvsp[-4].node)->label<<endl;
                  return 0;
                
                }
                 tab->SYMVAL[(yyvsp[-4].node)->label].identity=NORMIE;
                  tab->SYMVAL[(yyvsp[-4].node)->label].scope=curr_scope;
                  tab->SYMVAL[(yyvsp[-4].node)->label].line_no=(yyvsp[-4].node)->line_number;
                  tab->SYMVAL[(yyvsp[-4].node)->label].type=(yyvsp[-2].node)->label;
                  tab->SYMVAL[(yyvsp[-4].node)->label].name=(yyvsp[-4].node)->label;
                  tab->SYMVAL[(yyvsp[-4].node)->label].size=0;
                  (yyval.node) = n;
                string t = new_temporary();
                tab->SYMVAL[(yyvsp[-4].node)->label].temp_var = t;
                arguments.push_back(make_tuple((yyvsp[-4].node)->label,t,(yyvsp[-2].node)->type,0,0));
                }
#line 2452 "parser.cpp"
    break;

  case 19: /* datatype: NAME  */
#line 455 "parser.y"
                {
              Node *n = create_node("Datatype");
              n->children.push_back((yyvsp[0].node));
              n->label=(yyvsp[0].node)->label;
              (yyval.node) = n;
            }
#line 2463 "parser.cpp"
    break;

  case 20: /* datatype: NAME LBRACKET NAME RBRACKET  */
#line 461 "parser.y"
                                       {
              Node *n = create_node("Datatype");
              n->children.push_back((yyvsp[-3].node));
              n->children.push_back((yyvsp[-2].node));
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));
              n->label=(yyvsp[-3].node)->label+(yyvsp[-2].node)->label+(yyvsp[-1].node)->label+(yyvsp[0].node)->label;
              n->type=(yyvsp[-1].node)->type;
              (yyval.node) = n;
            }
#line 2478 "parser.cpp"
    break;

  case 21: /* stmt: simple_stmt  */
#line 473 "parser.y"
                      { (yyval.node)=(yyvsp[0].node);}
#line 2484 "parser.cpp"
    break;

  case 22: /* stmt: compound_stmt  */
#line 474 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2490 "parser.cpp"
    break;

  case 23: /* simple_stmt: small_stmt NEWLINE  */
#line 477 "parser.y"
                                {
               Node* n = create_node("simple_stmt");
               n->children.push_back((yyvsp[-1].node));
               (yyval.node)=n;
               (yyval.node)->type = (yyvsp[-1].node)->type;
              //  cout<<" entered simple-stmt"<<yylineno<<<<endl;
               (yyval.node)->line_number = (yyvsp[0].node)->line_number;
            }
#line 2503 "parser.cpp"
    break;

  case 24: /* simple_stmt: small_stmt small_stmt_list NEWLINE  */
#line 485 "parser.y"
                                               {

                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
                (yyval.node)->line_number = (yyvsp[0].node)->line_number;
              }
#line 2516 "parser.cpp"
    break;

  case 25: /* simple_stmt: small_stmt SEMICOLON NEWLINE  */
#line 493 "parser.y"
                                         {
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
                (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
              }
#line 2528 "parser.cpp"
    break;

  case 26: /* simple_stmt: small_stmt small_stmt_list SEMICOLON NEWLINE  */
#line 500 "parser.y"
                                                         {
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-3].node));
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));    
                (yyval.node)->line_number = (yyvsp[-1].node)->line_number; 
                (yyval.node)=n;         
              }
#line 2541 "parser.cpp"
    break;

  case 27: /* small_stmt_list: small_stmt_list SEMICOLON small_stmt  */
#line 510 "parser.y"
                                                      {
                  Node* n =create_node("small_stmt_list");
                  for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
                    n->children.push_back((yyvsp[-2].node)->children[i]);
                  }
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                  (yyval.node)->line_number= (yyvsp[-1].node)->line_number;
                }
#line 2556 "parser.cpp"
    break;

  case 28: /* small_stmt_list: SEMICOLON small_stmt  */
#line 520 "parser.y"
                                      {
                  Node* n =create_node("small_stmt_list");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                  (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
                }
#line 2568 "parser.cpp"
    break;

  case 29: /* small_stmt: expr_stmt  */
#line 528 "parser.y"
                      { (yyval.node)=(yyvsp[0].node);}
#line 2574 "parser.cpp"
    break;

  case 30: /* small_stmt: del_stmt  */
#line 529 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2580 "parser.cpp"
    break;

  case 31: /* small_stmt: pass_stmt  */
#line 530 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2586 "parser.cpp"
    break;

  case 32: /* small_stmt: flow_stmt  */
#line 531 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2592 "parser.cpp"
    break;

  case 33: /* small_stmt: global_stmt  */
#line 532 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2598 "parser.cpp"
    break;

  case 34: /* expr_stmt: testlist_star_expr expr_stmt_tail  */
#line 534 "parser.y"
                                             { 
              
              Node* n =create_node("expr_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));
              (yyval.node)=n;
              if((yyvsp[0].node)->label=="annassign"){
                if(tab->SYMVAL.find((yyvsp[-1].node)->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared "<<(yyvsp[-1].node)->label<<endl;
                  cout<<endl;
                          //exit(1);
                }
                  tab->SYMVAL[(yyvsp[-1].node)->label].identity=NORMIE;
                  tab->SYMVAL[(yyvsp[-1].node)->label].scope=curr_scope;
                  tab->SYMVAL[(yyvsp[-1].node)->label].line_no=(yyvsp[-1].node)->line_number;
                  tab->SYMVAL[(yyvsp[-1].node)->label].type=(yyvsp[0].node)->type;
                  tab->SYMVAL[(yyvsp[-1].node)->label].name=(yyvsp[0].node)->label;
                  tab->SYMVAL[(yyvsp[-1].node)->label].size=0;
                  tab->SYMVAL[(yyvsp[-1].node)->label].temp_var = (yyvsp[0].node)->temp_var;
              }
              else if((yyvsp[0].node)->label == "expr_stmt_tail")
              {
                  if((yyvsp[-1].node)->type != (yyvsp[0].node)->type)
                  {
                    if((yyvsp[-1].node)->type == "float" && (yyvsp[0].node)->type == "int"){}
                    else if((yyvsp[-1].node)->type == "int" && (yyvsp[0].node)->type=="bool"){}
                    else
                    {
                      check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[0].node)->line_number);
                    } 
                  }
              }
              else if(tab->SYMVAL.find((yyvsp[-1].node)->label)!=tab->SYMVAL.end())
              {
                check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[0].node)->line_number);
                // cout<<yylineno<<endl;
                // if($1->type != $2->type)
                // {
                //   cout<<"Different datatypes compared in line no "<<$1->line_no<<endl;
                //           //exit(1);
                // }
              }
              else if((yyvsp[0].node)->label=="annassign_op")
              {



                //this part to check expression like self.x
                cout<<(yyvsp[-1].node)->label<< " unfdins "<<endl;
                if(((yyvsp[-1].node)->label == "self") && (tab->parent->tab_type == CLS) &&((yyvsp[-1].node)->p_f.size() ==1))
                {
                  // cout<<$1->p_f.size()<<" expr_stmt "<<endl;
                  if( tab->parent->SYMVAL.find((yyvsp[-1].node)->p_f[0]->par_name)==tab->SYMVAL.end())
                  {
                    cout<<"Use of undeclared attribute for class "<< endl;
                    //exit(1);
                  }
                  else {

                      check_type(tab->parent->SYMVAL[(yyvsp[-1].node)->p_f[0]->par_name].type ,(yyvsp[0].node)->type,(yyvsp[0].node)->line_number );
                  }
                }
                else if(tab->SYMVAL.find((yyvsp[-1].node)->label)==tab->SYMVAL.end())
                {
                  if(gt->SYMVAL.find((yyvsp[-1].node)->label)==gt->SYMVAL.end()){
                  cout<<"Use of undeclared variable " << (yyvsp[-1].node)->label <<" in line number "<<(yyvsp[0].node)->line_number<<endl;
                  //exit(1);
                  }
                  
                }


              }
            //   cout << $1->temp_var<<"inside expr_stmt"<<endl;
              codepush("",(yyvsp[0].node)->temp_var,"",(yyvsp[-1].node)->temp_var,-1);
             }
#line 2679 "parser.cpp"
    break;

  case 35: /* expr_stmt: testlist_star_expr  */
#line 610 "parser.y"
                                 { (yyval.node) = (yyvsp[0].node);}
#line 2685 "parser.cpp"
    break;

  case 36: /* expr_stmt_tail: COLON decl_type annassign  */
#line 613 "parser.y"
                                           {
                  (yyval.node) =create_node("annassign");
                  (yyval.node)->children.push_back((yyvsp[-2].node));
                  (yyval.node)->children.push_back((yyvsp[-1].node));
                  (yyval.node)->children.push_back((yyvsp[0].node));
                  (yyval.node)->type = (yyvsp[-1].node)->type;
                  
                  check_type((yyvsp[-1].node)->type, (yyvsp[0].node)->type, (yyvsp[-2].node)->line_number);
                  (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
                  }
#line 2700 "parser.cpp"
    break;

  case 37: /* expr_stmt_tail: annassign  */
#line 623 "parser.y"
                          {
                  (yyval.node) = (yyvsp[0].node);
               }
#line 2708 "parser.cpp"
    break;

  case 38: /* expr_stmt_tail: COLON decl_type  */
#line 626 "parser.y"
                                 {
                  (yyval.node) =create_node("annassign");
                  (yyval.node)->children.push_back((yyvsp[-1].node));
                  (yyval.node)->children.push_back((yyvsp[0].node));
                  (yyval.node)->type = (yyvsp[0].node)->type;
               }
#line 2719 "parser.cpp"
    break;

  case 39: /* expr_stmt_tail: augassign augassign_op  */
#line 632 "parser.y"
                                        {
                  Node* n =create_node("expr_stmt_tail");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                  (yyval.node)->type = (yyvsp[0].node)->type;
                  (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
                  // cout<<$$->type <<" expr_stmt_tail"<<endl;
               }
#line 2733 "parser.cpp"
    break;

  case 40: /* decl_type: NAME  */
#line 646 "parser.y"
                {
                (yyval.node) = create_node("decl_type");
                (yyval.node)->type = (yyvsp[0].node)->type;
            }
#line 2742 "parser.cpp"
    break;

  case 41: /* decl_type: NAME LBRACKET NAME RBRACKET  */
#line 650 "parser.y"
                                          {
                (yyval.node) = create_node("decl_type");
               if((yyvsp[-3].node)->label != "list"){
                  cout << "Invalid datatype at line no: " << (yyvsp[-3].node)->line_number << endl;
                  //exit(1);
                }
                (yyval.node)->children.push_back((yyvsp[-3].node));
                (yyval.node)->children.push_back((yyvsp[-2].node));
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));
                (yyval.node)->type = (yyvsp[-3].node)->type + (yyvsp[-2].node)->label + (yyvsp[-1].node)->type + (yyvsp[0].node)->label;
            }
#line 2759 "parser.cpp"
    break;

  case 42: /* augassign_op: yield_expr  */
#line 663 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2765 "parser.cpp"
    break;

  case 43: /* augassign_op: testlist  */
#line 664 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2771 "parser.cpp"
    break;

  case 44: /* annassign: EQUAL_SIGN test  */
#line 687 "parser.y"
                           {
                  Node* n =create_node("annassign_op");
                   n->children.push_back((yyvsp[-1].node));
                   n->children.push_back((yyvsp[0].node));
                   (yyval.node) = n;
                   (yyval.node)->line_number= (yyvsp[-1].node)->line_number;
                   if((yyvsp[0].node)->type == (yyvsp[0].node)->label)
                   {
                      cout<<"Variable not declared or invalid comparison in line no "<<(yyvsp[-1].node)->line_number<<endl;
                      //exit(1);
                   }
                   else 
                   (yyval.node)->type = (yyvsp[0].node)->type;

                   (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
}
#line 2792 "parser.cpp"
    break;

  case 45: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep COMMA  */
#line 704 "parser.y"
                                                                         {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-2].node));
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                     (yyval.node)=n;
                     (yyval.node)->line_number = (yyvsp[0].node)->line_number;
                     (yyval.node)->temp_var = (yyvsp[-2].node)->temp_var + (yyvsp[-1].node)->temp_var + ",";
                    }
#line 2806 "parser.cpp"
    break;

  case 46: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep  */
#line 713 "parser.y"
                                                                   { 
                      Node* n =create_node("testlist_star_expr");
                      n->children.push_back((yyvsp[-1].node));
                      n->children.push_back((yyvsp[0].node));
                      (yyval.node)=n;
                      (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var + (yyvsp[0].node)->temp_var;
                      (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
                    }
#line 2819 "parser.cpp"
    break;

  case 47: /* testlist_star_expr: testlist_star_expr_opt1 COMMA  */
#line 721 "parser.y"
                                                  {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                     (yyval.node)=n;
                     (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var + ",";
                    }
#line 2831 "parser.cpp"
    break;

  case 48: /* testlist_star_expr: testlist_star_expr_opt1  */
#line 728 "parser.y"
                                             { (yyval.node) = (yyvsp[0].node);}
#line 2837 "parser.cpp"
    break;

  case 49: /* testlist_star_expr_opt1: test  */
#line 732 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2843 "parser.cpp"
    break;

  case 50: /* testlist_star_expr_opt1: star_expr  */
#line 733 "parser.y"
                                   {(yyval.node)=(yyvsp[0].node);}
#line 2849 "parser.cpp"
    break;

  case 51: /* testlist_star_expr_rep: testlist_star_expr_rep COMMA testlist_star_expr_opt1  */
#line 736 "parser.y"
                                                          {
      Node* n =create_node("testlist_star_expr_rep");
      for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
        n->children.push_back((yyvsp[-2].node)->children[i]);
      }
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n;
      (yyval.node)->temp_var = (yyvsp[-2].node)->temp_var+","+(yyvsp[0].node)->temp_var;
  }
#line 2864 "parser.cpp"
    break;

  case 52: /* testlist_star_expr_rep: COMMA testlist_star_expr_opt1  */
#line 746 "parser.y"
                                  {(yyval.node) = NULL; (yyval.node)->temp_var = ","+(yyvsp[0].node)->temp_var;}
#line 2870 "parser.cpp"
    break;

  case 53: /* augassign: PLUS_EQUAL  */
#line 748 "parser.y"
                       {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "+=";}
#line 2876 "parser.cpp"
    break;

  case 54: /* augassign: MINUS_EQUAL  */
#line 749 "parser.y"
                        {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "-=";}
#line 2882 "parser.cpp"
    break;

  case 55: /* augassign: TIMES_EQUAL  */
#line 750 "parser.y"
                        {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "*=";}
#line 2888 "parser.cpp"
    break;

  case 56: /* augassign: AT_EQUAL  */
#line 751 "parser.y"
                     {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "@=";}
#line 2894 "parser.cpp"
    break;

  case 57: /* augassign: DIVIDEDBY_EQUAL  */
#line 752 "parser.y"
                            {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "/=";}
#line 2900 "parser.cpp"
    break;

  case 58: /* augassign: MODULO_EQUAL  */
#line 753 "parser.y"
                         {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "%=";}
#line 2906 "parser.cpp"
    break;

  case 59: /* augassign: BITWISE_AND_EQUAL  */
#line 754 "parser.y"
                              {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "&=";}
#line 2912 "parser.cpp"
    break;

  case 60: /* augassign: BITWISE_OR_EQUAL  */
#line 755 "parser.y"
                             {(yyval.node)=(yyvsp[0].node);  (yyval.node)->temp_op = "|=";}
#line 2918 "parser.cpp"
    break;

  case 61: /* augassign: BITWISE_XOR_EQUAL  */
#line 756 "parser.y"
                              {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "^=";}
#line 2924 "parser.cpp"
    break;

  case 62: /* augassign: SHIFT_LEFT_EQUAL  */
#line 757 "parser.y"
                             {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "<<=";}
#line 2930 "parser.cpp"
    break;

  case 63: /* augassign: SHIFT_RIGHT_EQUAL  */
#line 758 "parser.y"
                              {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = ">>=";}
#line 2936 "parser.cpp"
    break;

  case 64: /* augassign: POWER_EQUAL  */
#line 759 "parser.y"
                        {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "**=";}
#line 2942 "parser.cpp"
    break;

  case 65: /* augassign: FLOORDIV_EQUAL  */
#line 760 "parser.y"
                           {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "//=";}
#line 2948 "parser.cpp"
    break;

  case 66: /* del_stmt: DEL exprlist  */
#line 763 "parser.y"
                      {Node* n =create_node("del_stmt");
                         n->children.push_back((yyvsp[-1].node));
                         n->children.push_back((yyvsp[0].node));
                         (yyval.node)=n;
                          }
#line 2958 "parser.cpp"
    break;

  case 67: /* pass_stmt: PASS  */
#line 769 "parser.y"
               {(yyval.node)=(yyvsp[0].node);}
#line 2964 "parser.cpp"
    break;

  case 68: /* flow_stmt: break_stmt  */
#line 771 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2970 "parser.cpp"
    break;

  case 69: /* flow_stmt: continue_stmt  */
#line 772 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2976 "parser.cpp"
    break;

  case 70: /* flow_stmt: return_stmt  */
#line 773 "parser.y"
                       {(yyval.node)=(yyvsp[0].node); }
#line 2982 "parser.cpp"
    break;

  case 71: /* flow_stmt: yield_stmt  */
#line 774 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2988 "parser.cpp"
    break;

  case 72: /* break_stmt: BREAK  */
#line 777 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 2994 "parser.cpp"
    break;

  case 73: /* continue_stmt: CONTINUE  */
#line 779 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 3000 "parser.cpp"
    break;

  case 74: /* return_stmt: RETURN testlist  */
#line 780 "parser.y"
                            {
              Node* n =create_node("return_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n;
              (yyval.node)->type = (yyvsp[0].node)->type;
              codepush("",(yyvsp[0].node)->temp_var,"","pushparam",-1);
            }
#line 3013 "parser.cpp"
    break;

  case 75: /* return_stmt: RETURN  */
#line 788 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "None";}
#line 3019 "parser.cpp"
    break;

  case 76: /* yield_stmt: yield_expr  */
#line 790 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 3025 "parser.cpp"
    break;

  case 77: /* global_stmt: GLOBAL global_name_list  */
#line 791 "parser.y"
                                    {
              Node* n =create_node("global_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n; 
            }
#line 3036 "parser.cpp"
    break;

  case 78: /* global_name_list: global_name_list COMMA NAME  */
#line 798 "parser.y"
                                              {
                  Node* n =create_node("global_name_list");
                  for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
                    n->children.push_back((yyvsp[-2].node)->children[i]);
                  }
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  
                  (yyval.node)=n;
                }
#line 3051 "parser.cpp"
    break;

  case 79: /* global_name_list: NAME  */
#line 808 "parser.y"
                       { (yyval.node) = (yyvsp[0].node);}
#line 3057 "parser.cpp"
    break;

  case 80: /* compound_stmt: if_stmt  */
#line 810 "parser.y"
                       { (yyval.node)=(yyvsp[0].node);}
#line 3063 "parser.cpp"
    break;

  case 81: /* compound_stmt: while_stmt  */
#line 811 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 3069 "parser.cpp"
    break;

  case 82: /* compound_stmt: for_stmt  */
#line 812 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 3075 "parser.cpp"
    break;

  case 83: /* compound_stmt: funcdef  */
#line 813 "parser.y"
                       { (yyval.node)=(yyvsp[0].node);}
#line 3081 "parser.cpp"
    break;

  case 84: /* compound_stmt: classdef  */
#line 814 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 3087 "parser.cpp"
    break;

  case 85: /* compound_stmt: async_stmt  */
#line 815 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 3093 "parser.cpp"
    break;

  case 89: /* ifkeyword: IF test  */
#line 824 "parser.y"
                   { Node* n = create_node("ifkeyword");
                    n->children.push_back((yyvsp[-1].node));
                    n->children.push_back((yyvsp[0].node));
                    codepush("if",(yyvsp[0].node)->temp_var,"0",">",-1);
                    (yyval.node)->i_number = inst_num-1;
                    (yyval.node)=n;
                    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
                  }
#line 3106 "parser.cpp"
    break;

  case 90: /* if_stmt: ifkeyword COLON suite elif_stmt_rep ELSE COLON suite  */
#line 833 "parser.y"
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
    (yyval.node)->line_number = (yyvsp[-6].node)->line_number;
    codepush("","","","end else",-1);
  }
#line 3124 "parser.cpp"
    break;

  case 91: /* if_stmt: ifkeyword COLON suite elif_stmt_rep  */
#line 846 "parser.y"
                                         {

      Node* n=create_node("if_stmt");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
      (yyval.node)->line_number = (yyvsp[-3].node)->line_number;
      
  }
#line 3140 "parser.cpp"
    break;

  case 92: /* $@3: %empty  */
#line 857 "parser.y"
                                 {codepush("","","","else",-1);}
#line 3146 "parser.cpp"
    break;

  case 93: /* if_stmt: ifkeyword COLON suite ELSE $@3 COLON suite  */
#line 857 "parser.y"
                                                                            { 
      Node* n=create_node("if_stmt");
      n->children.push_back((yyvsp[-6].node));
      n->children.push_back((yyvsp[-5].node)); 
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node)); 
      n->children.push_back((yyvsp[0].node));
      n->children.push_back((yyvsp[-1].node)); 
      (yyval.node)=n;
    (yyval.node)->line_number = (yyvsp[-6].node)->line_number;
      codepush("","","","end else",-1);
    }
#line 3163 "parser.cpp"
    break;

  case 94: /* if_stmt: ifkeyword COLON suite  */
#line 869 "parser.y"
                            { 
      Node* n=create_node("if_stmt");
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node)); 
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n;
      (yyval.node)->line_number = (yyvsp[-2].node)->line_number;
      codepush("","","","end if",-1);
    }
#line 3177 "parser.cpp"
    break;

  case 95: /* elif_stmt_rep: elif_stmt_rep ELIF test COLON suite  */
#line 879 "parser.y"
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
#line 3193 "parser.cpp"
    break;

  case 96: /* elif_stmt_rep: ELIF test COLON suite  */
#line 890 "parser.y"
                           { 
      Node* n=create_node("elif_stmt_rep");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
    }
#line 3206 "parser.cpp"
    break;

  case 97: /* $@4: %empty  */
#line 899 "parser.y"
                       {
      codepush("","","","loop:",-1);
        string s2 = (yyvsp[0].node)->temp_var;
        codepush("if",s2,"true","==",-1);
        loop_stack.push_back(inst_num-2); 
}
#line 3217 "parser.cpp"
    break;

  case 98: /* while_stmt: WHILE test $@4 COLON suite  */
#line 904 "parser.y"
              { 
      Node* n=create_node("while_stmt");
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[-1].node)); 
      (yyval.node)=n;
      codepush("",to_string(loop_stack[(loop_stack.size())-1]),"","goto",-1); loop_stack.pop_back();codepush("","","","end loop",-1);
  }
#line 3231 "parser.cpp"
    break;

  case 99: /* $@5: %empty  */
#line 914 "parser.y"
                                    {
        codepush("","","","loop:",-1);
        string s2 = (yyvsp[0].node)->temp_var;
        codepush("if",(yyvsp[-2].node)->label,s2,">",-1);
        (yyvsp[-3].node)->i_number = inst_num-1;
        codepush("+",(yyvsp[-2].node)->label,"1",(yyvsp[-2].node)->label,-1);
        loop_stack.push_back(inst_num-2);
         }
#line 3244 "parser.cpp"
    break;

  case 100: /* for_stmt: FOR exprlist IN range_func $@5 COLON suite  */
#line 921 "parser.y"
                       {
      Node* n=create_node("for_stmt");
      n->children.push_back((yyvsp[-6].node));
      n->children.push_back((yyvsp[-5].node)); 
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
      if(tab->SYMVAL.find((yyvsp[-5].node)->label)!=tab->SYMVAL.end())
      {
        // cout<<"Already declared"<<endl;
        if(tab->SYMVAL[(yyvsp[-5].node)->label].type != "int")
          cout<<" Invalid type iterator in for statement in line no "<< (yyvsp[-6].node)->line_number<<endl;
        // cout<<$$->type<<" Name "<< yylineno << " "<< $$->label<<endl;
      }
      else if(gt->SYMVAL.find((yyvsp[-5].node)->label)!=gt->SYMVAL.end())
      {
        if(gt->SYMVAL[(yyvsp[-5].node)->label].type != "int")
        cout<<" Invalid type iterator in for statement in line no "<< (yyvsp[-6].node)->line_number<<endl;
      }
      else {
        cout<<"Undeclared variable used as iterator in for statement in line no "<< (yyvsp[-6].node)->line_number<<endl;
         //exit(1);
      }

      (yyval.node)=n;
      codepush("",to_string(loop_stack[(loop_stack.size())-1]),"","goto",-1); loop_stack.pop_back();codepush("","","","end loop",-1);
      code[(yyvsp[-6].node)->i_number].index = inst_num;
    }
#line 3278 "parser.cpp"
    break;

  case 101: /* range_func: NAME LPAREN test RPAREN  */
#line 951 "parser.y"
                                    {
      Node* n=create_node("range_func");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var;
      if((yyvsp[-3].node)->label != "range"){
        cout<<"For loop supports only range function in line no "<<(yyvsp[-3].node)->line_number<<endl;
        //exit(1);
      }


  }
#line 3297 "parser.cpp"
    break;

  case 102: /* range_func: NAME LPAREN test COMMA test RPAREN  */
#line 965 "parser.y"
                                      {
      Node* n=create_node("range_func");
      n->children.push_back((yyvsp[-5].node));
      n->children.push_back((yyvsp[-4].node)); 
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
      (yyval.node)->temp_var = (yyvsp[-3].node)->temp_var;
      if((yyvsp[-5].node)->label != "range"){
        cout<<"For loop supports only range function"<<endl;
         //exit(1);
      }
      else if(((yyvsp[-3].node)->type != "int")&& ((yyvsp[-1].node)->type != "int"))
      {
        cout<<"Invalid datatype used in range function in line no "<<(yyvsp[-5].node)->line_number<<endl;
        //exit(1);
      }
  }
#line 3321 "parser.cpp"
    break;

  case 103: /* suite: simple_stmt  */
#line 985 "parser.y"
                    {if(yybye) cout<<"LINE 462 \n"; (yyval.node) = (yyvsp[0].node);}
#line 3327 "parser.cpp"
    break;

  case 104: /* suite: NEWLINE INDENT stmt_rep DEDENT  */
#line 986 "parser.y"
                                      {
        Node* n = create_node("Suite");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-2].node));
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        if((yyvsp[-1].node)->type != "")
          (yyval.node)->type = (yyvsp[-1].node)->type;
        else (yyval.node)->type = "None";
        (yyval.node)->line_number = (yyvsp[-2].node)->line_number;

      }
#line 3344 "parser.cpp"
    break;

  case 105: /* stmt_rep: stmt_rep stmt  */
#line 1000 "parser.y"
                           {
            Node* n = create_node("Multi Statements");
            (yyval.node) = n;
            for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
              n->children.push_back((yyvsp[-1].node)->children[i]);
            }
            n->children.push_back((yyvsp[0].node));
            (yyval.node)->type = (yyvsp[0].node)->type;
          }
#line 3358 "parser.cpp"
    break;

  case 106: /* stmt_rep: stmt  */
#line 1009 "parser.y"
                 {(yyval.node)=(yyvsp[0].node); }
#line 3364 "parser.cpp"
    break;

  case 107: /* test: or_test IF or_test ELSE test  */
#line 1011 "parser.y"
                                    {
      Node* n = create_node("Test");
      (yyval.node) = n;
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
}
#line 3378 "parser.cpp"
    break;

  case 108: /* test: or_test  */
#line 1020 "parser.y"
         {(yyval.node)=(yyvsp[0].node);}
#line 3384 "parser.cpp"
    break;

  case 109: /* test_nocond: or_test  */
#line 1023 "parser.y"
          {(yyval.node) = (yyvsp[0].node);}
#line 3390 "parser.cpp"
    break;

  case 110: /* or_test: and_test or_test_rep  */
#line 1027 "parser.y"
  {
    Node* n = create_node("OR Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush("or",(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3404 "parser.cpp"
    break;

  case 111: /* or_test: and_test  */
#line 1036 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3410 "parser.cpp"
    break;

  case 112: /* or_test_rep: or_test_rep OR and_test  */
#line 1039 "parser.y"
                           {
    Node* n = create_node("ORTestRep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int") || (((yyvsp[-2].node)->type != "bool") && ((yyvsp[-2].node)->type != "int") ))
    {
      cout<<"Non compatible operand type used for OR operator in line no "<<(yyvsp[-2].node)->line_number<<endl;
      //exit(1);
    }  
    (yyval.node)->type = "bool";
    string s1=new_temporary();
    codepush("or",(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 3434 "parser.cpp"
    break;

  case 113: /* or_test_rep: OR and_test  */
#line 1058 "parser.y"
               {Node* n = create_node("ORTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int"))
    {
      cout<<"Non compatible operand type used for OR operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      //exit(1);
    }  
    (yyval.node)->temp_op = "or";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3451 "parser.cpp"
    break;

  case 114: /* and_test: not_test and_test_rep  */
#line 1072 "parser.y"
                       {
    Node* n = create_node("And Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int") || (((yyvsp[-1].node)->type != "bool") && ((yyvsp[-1].node)->type != "int") ))
    {
      cout<<"Non compatible operand type used for AND    operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      //exit(1);
    }
    (yyval.node)->type ="bool";
    string s1=new_temporary();
    codepush("and",(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3471 "parser.cpp"
    break;

  case 115: /* and_test: not_test  */
#line 1087 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3477 "parser.cpp"
    break;

  case 116: /* and_test_rep: and_test_rep AND not_test  */
#line 1091 "parser.y"
  {
    Node* n = create_node("AndTestRep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int") || (((yyvsp[-2].node)->type != "bool") && ((yyvsp[-2].node)->type != "int") ))
    {
      cout<<"Non compatible operand type used for AND operator in line no "<<(yyvsp[-2].node)->line_number<<endl;
      //exit(1);
    }  
    (yyval.node)->type = "bool";
    string s1=new_temporary();
    codepush("and",(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 3501 "parser.cpp"
    break;

  case 117: /* and_test_rep: AND not_test  */
#line 1110 "parser.y"
                {Node* n = create_node("AndTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int"))
    {
      // cout<<$2->type<<endl;
      cout<<"Non compatible operand type used for AND  no operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      //exit(1);
    }
    (yyval.node)->type = "bool";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    }
#line 3520 "parser.cpp"
    break;

  case 118: /* not_test: NOT not_test  */
#line 1128 "parser.y"
  {
    Node* n = create_node("Not Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int"))
    {
      cout<<"Non compatible operand type used for NOT operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      //exit(1);
    }
        (yyval.node)->type = "bool";
    string s1=new_temporary();
    codepush("not",(yyvsp[0].node)->temp_var,"",s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3540 "parser.cpp"
    break;

  case 119: /* not_test: comparison  */
#line 1143 "parser.y"
               {
    (yyval.node) =(yyvsp[0].node);
  }
#line 3548 "parser.cpp"
    break;

  case 120: /* comparison: expr comparison_rep  */
#line 1148 "parser.y"
                     {
    Node* n = create_node("Comparison");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if((yyvsp[-1].node)->label == "__name__" )
    (yyvsp[-1].node)->type ="bool";
    check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[-1].node)->line_number);
    (yyval.node)->type = "bool";
//  doubt in this part 
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3567 "parser.cpp"
    break;

  case 121: /* comparison: expr  */
#line 1162 "parser.y"
       {(yyval.node)=(yyvsp[0].node);}
#line 3573 "parser.cpp"
    break;

  case 122: /* comparison_rep: comparison_rep comp_op expr  */
#line 1166 "parser.y"
                              {
    Node* n = create_node("Comparison Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[-1].node)->temp_op,(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;

  }
#line 3592 "parser.cpp"
    break;

  case 123: /* comparison_rep: comp_op expr  */
#line 1180 "parser.y"
                {
   Node* n = create_node("Comparison Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if((yyvsp[0].node)->label == "\"__main__\"")
    {
      (yyvsp[0].node)->type = "bool";
    }

    (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
 }
#line 3611 "parser.cpp"
    break;

  case 124: /* comp_op: LESS_THAN  */
#line 1195 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "<";}
#line 3617 "parser.cpp"
    break;

  case 125: /* comp_op: GREATER_THAN  */
#line 1196 "parser.y"
                      {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = ">";}
#line 3623 "parser.cpp"
    break;

  case 126: /* comp_op: EQUAL  */
#line 1197 "parser.y"
               {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "==";}
#line 3629 "parser.cpp"
    break;

  case 127: /* comp_op: GREATER_THAN_OR_EQUAL  */
#line 1198 "parser.y"
                               {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = ">=";}
#line 3635 "parser.cpp"
    break;

  case 128: /* comp_op: LESS_THAN_OR_EQUAL  */
#line 1199 "parser.y"
                            {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "<=";}
#line 3641 "parser.cpp"
    break;

  case 129: /* comp_op: NOT_EQUAL  */
#line 1200 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "!=";}
#line 3647 "parser.cpp"
    break;

  case 130: /* comp_op: IN  */
#line 1201 "parser.y"
            {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "in";}
#line 3653 "parser.cpp"
    break;

  case 131: /* comp_op: NOT IN  */
#line 1202 "parser.y"
                {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3664 "parser.cpp"
    break;

  case 132: /* comp_op: IS  */
#line 1208 "parser.y"
            {(yyval.node) =(yyvsp[0].node);}
#line 3670 "parser.cpp"
    break;

  case 133: /* comp_op: IS NOT  */
#line 1209 "parser.y"
               {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3681 "parser.cpp"
    break;

  case 134: /* star_expr: TIMES expr  */
#line 1217 "parser.y"
            {
    Node* n = create_node("Star Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->temp_var="*"+(yyvsp[0].node)->temp_var;
  }
#line 3693 "parser.cpp"
    break;

  case 135: /* expr: xor_expr expr_rep  */
#line 1226 "parser.y"
                   {
    Node* n = create_node("Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3707 "parser.cpp"
    break;

  case 136: /* expr: xor_expr  */
#line 1235 "parser.y"
            {(yyval.node)=(yyvsp[0].node);}
#line 3713 "parser.cpp"
    break;

  case 137: /* expr_rep: expr_rep BITWISE_OR xor_expr  */
#line 1238 "parser.y"
                               {
    Node* n = create_node("Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyvsp[-1].node)->temp_op = "|";
    string s1=new_temporary();
    codepush((yyvsp[-1].node)->temp_op,(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 3732 "parser.cpp"
    break;

  case 138: /* expr_rep: BITWISE_OR xor_expr  */
#line 1252 "parser.y"
                       {Node* n = create_node("Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->temp_op = "|";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3744 "parser.cpp"
    break;

  case 139: /* xor_expr: and_expr xor_expr_rep  */
#line 1261 "parser.y"
                       {
    Node* n = create_node("XOR Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3758 "parser.cpp"
    break;

  case 140: /* xor_expr: and_expr  */
#line 1270 "parser.y"
            {
    (yyval.node)=(yyvsp[0].node);
  }
#line 3766 "parser.cpp"
    break;

  case 141: /* xor_expr_rep: xor_expr_rep BITWISE_XOR and_expr  */
#line 1275 "parser.y"
                                    {
    Node* n = create_node("XOR Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyvsp[-1].node)->temp_op = "^";
    string s1=new_temporary();
    codepush((yyvsp[-1].node)->temp_op,(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 3785 "parser.cpp"
    break;

  case 142: /* xor_expr_rep: BITWISE_XOR and_expr  */
#line 1289 "parser.y"
                       {Node* n = create_node("XOR Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->temp_op = "^";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3797 "parser.cpp"
    break;

  case 143: /* and_expr: shift_expr and_expr_rep  */
#line 1298 "parser.y"
                         {
    Node* n = create_node("AND Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3811 "parser.cpp"
    break;

  case 144: /* and_expr: shift_expr  */
#line 1307 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3817 "parser.cpp"
    break;

  case 145: /* and_expr_rep: and_expr_rep BITWISE_AND shift_expr  */
#line 1310 "parser.y"
                                      {
    Node* n = create_node("AND Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node)); 
    (yyvsp[-1].node)->temp_op = "&";
    string s1=new_temporary();
    codepush((yyvsp[-1].node)->temp_op,(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 3836 "parser.cpp"
    break;

  case 146: /* and_expr_rep: BITWISE_AND shift_expr  */
#line 1324 "parser.y"
                         {Node* n = create_node("AND Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node)); 
    (yyval.node)->temp_op = "&";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;

    }
#line 3849 "parser.cpp"
    break;

  case 147: /* shift_expr: arith_expr shift_expr_rep  */
#line 1334 "parser.y"
                           {
    Node* n = create_node("Shift Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3863 "parser.cpp"
    break;

  case 148: /* shift_expr: arith_expr  */
#line 1343 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3869 "parser.cpp"
    break;

  case 149: /* shift_expr_rep: shift_expr_rep shift_expr_rep_c1 arith_expr  */
#line 1346 "parser.y"
                                              {
    Node* n = create_node("Shift Expression Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[-1].node)->temp_op,(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 3887 "parser.cpp"
    break;

  case 150: /* shift_expr_rep: shift_expr_rep_c1 arith_expr  */
#line 1359 "parser.y"
                                {Node* n = create_node("Shift Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3900 "parser.cpp"
    break;

  case 151: /* shift_expr_rep_c1: SHIFT_LEFT  */
#line 1369 "parser.y"
            {
    (yyval.node) = (yyvsp[0].node);
    (yyval.node)->temp_op = "<<";
  }
#line 3909 "parser.cpp"
    break;

  case 152: /* shift_expr_rep_c1: SHIFT_RIGHT  */
#line 1373 "parser.y"
                {(yyval.node) = (yyvsp[0].node);
    (yyval.node)->temp_op = ">>";
  }
#line 3917 "parser.cpp"
    break;

  case 153: /* arith_expr: term arith_expr_rep  */
#line 1378 "parser.y"
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
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    // cout<<$$->type<< " "<<$1->line_number<<endl;
  }
#line 3942 "parser.cpp"
    break;

  case 154: /* arith_expr: term  */
#line 1398 "parser.y"
        {(yyval.node)=(yyvsp[0].node);}
#line 3948 "parser.cpp"
    break;

  case 155: /* arith_expr_rep: arith_expr_rep arith_expr_rep_c1 term  */
#line 1401 "parser.y"
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
      else {
        check_type((yyvsp[-2].node)->type , (yyvsp[0].node)->type, (yyvsp[0].node)->line_number);
      }
    }
    else 
      (yyval.node)->type = (yyvsp[0].node)->type;

    string s1=new_temporary();
    codepush((yyvsp[-1].node)->temp_op,(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
    // cout<<$$->type <<" arth rep 1"<<endl;

  }
#line 3979 "parser.cpp"
    break;

  case 156: /* arith_expr_rep: arith_expr_rep_c1 term  */
#line 1427 "parser.y"
                         {Node* n = create_node("Arithmetic Expression Rep2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    // cout<<"Arith2 "<<$$->temp_var <<" " <<$$->temp_op<<endl;
    }
#line 3993 "parser.cpp"
    break;

  case 157: /* arith_expr_rep_c1: PLUS  */
#line 1438 "parser.y"
       { (yyval.node) = (yyvsp[0].node);(yyval.node)->temp_op = "+";}
#line 3999 "parser.cpp"
    break;

  case 158: /* arith_expr_rep_c1: MINUS  */
#line 1439 "parser.y"
          { (yyval.node) = (yyvsp[0].node);(yyval.node) ->temp_op = "-";}
#line 4005 "parser.cpp"
    break;

  case 159: /* term: factor term_rep  */
#line 1442 "parser.y"
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
      check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type, (yyvsp[-1].node)->line_number);
    }
    else 
      (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1; 
  }
#line 4032 "parser.cpp"
    break;

  case 160: /* term: factor  */
#line 1464 "parser.y"
         {(yyval.node)=(yyvsp[0].node);}
#line 4038 "parser.cpp"
    break;

  case 161: /* term_rep: term_rep term_rep_c1 factor  */
#line 1467 "parser.y"
                               {
    Node* n = create_node("TERM Rep");
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
    if((((yyvsp[-2].node)->type != "int")&&((yyvsp[-2].node)->type != "float"))&&(((yyvsp[-1].node)->type != "float")&&((yyvsp[-1].node)->type != "int")))
    {
      cout<<"Invalid datatype "<< (yyvsp[-2].node)->type << " and "<<(yyvsp[0].node)->type <<" used for operator "<<(yyvsp[-1].node)->label<<endl;
      //exit(1);
      
    }
    if((yyvsp[0].node)->type != (yyvsp[-2].node)->type)
    {
      if(((yyvsp[0].node)->type == "int"|| (yyvsp[0].node)->type =="float" ) && ((yyvsp[-2].node)->type == "int"|| (yyvsp[-2].node)->type =="float" ))
      (yyval.node)->type = "float";
      else 
      check_type((yyvsp[-2].node)->type , (yyvsp[-2].node)->type, (yyvsp[-2].node)->line_number);
    }
    if((yyvsp[-1].node)->type == "/")
     (yyval.node)->type = "float";
    else 
      (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->line_number = (yyvsp[0].node)->line_number;
    string s1=new_temporary();
    codepush((yyvsp[-1].node)->temp_op,(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 4074 "parser.cpp"
    break;

  case 162: /* term_rep: term_rep_c1 factor  */
#line 1498 "parser.y"
                       { Node* n = create_node("TERM Rep");
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
    (yyval.node)->line_number = (yyvsp[0].node)->line_number;
    (yyval.node)->type = (yyvsp[0].node)->type;
    if(((yyvsp[0].node)->type != "bool")&&((yyvsp[0].node)->type != "float")&&((yyvsp[0].node)->type != "int"))
    {
      cout<<"Invalid datatype used for operator "<<(yyvsp[-1].node)->label<<" in line no "<<(yyvsp[-1].node)->line_number<<endl;
      // exit(1);
    }
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    }
#line 4093 "parser.cpp"
    break;

  case 163: /* term_rep_c1: TIMES  */
#line 1513 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "*";}
#line 4099 "parser.cpp"
    break;

  case 164: /* term_rep_c1: AT  */
#line 1514 "parser.y"
                 { (yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "@";}
#line 4105 "parser.cpp"
    break;

  case 165: /* term_rep_c1: DIVIDEDBY  */
#line 1515 "parser.y"
                        { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "/"; }
#line 4111 "parser.cpp"
    break;

  case 166: /* term_rep_c1: MODULO  */
#line 1516 "parser.y"
                     { (yyval.node) =(yyvsp[0].node);   (yyval.node)->temp_op = "%";}
#line 4117 "parser.cpp"
    break;

  case 167: /* term_rep_c1: FLOORDIV  */
#line 1517 "parser.y"
                       { (yyval.node) =(yyvsp[0].node);    (yyval.node)->temp_op = "//";}
#line 4123 "parser.cpp"
    break;

  case 168: /* factor: factor_c1 factor  */
#line 1520 "parser.y"
                   {
    Node* n = create_node("Factor");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[0].node)->line_number;
    (yyval.node)->temp_op=(yyvsp[-1].node)->temp_op;
    (yyval.node)->temp_var=(yyvsp[0].node)->temp_var;
  }
#line 4137 "parser.cpp"
    break;

  case 169: /* factor: power  */
#line 1529 "parser.y"
          { if(yybye) cout<<"factor power: "<<endl;(yyval.node) = (yyvsp[0].node);}
#line 4143 "parser.cpp"
    break;

  case 170: /* factor_c1: PLUS  */
#line 1531 "parser.y"
                 { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "+";}
#line 4149 "parser.cpp"
    break;

  case 171: /* factor_c1: MINUS  */
#line 1532 "parser.y"
                  { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "-"; }
#line 4155 "parser.cpp"
    break;

  case 172: /* factor_c1: BITWISE_NOT  */
#line 1533 "parser.y"
                        { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "~";}
#line 4161 "parser.cpp"
    break;

  case 173: /* power: atom_expr power_opt  */
#line 1536 "parser.y"
                     {
    Node* n = create_node("Power");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type , (yyvsp[-1].node)->line_number);
    (yyval.node)->type = (yyvsp[-1].node)->type;
    string s1 = new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 4177 "parser.cpp"
    break;

  case 174: /* power: atom_expr  */
#line 1547 "parser.y"
             {
    (yyval.node) = (yyvsp[0].node);
    if(yybye) cout<<"atom_expr power: "<<endl;(yyval.node)=(yyvsp[0].node);
  }
#line 4186 "parser.cpp"
    break;

  case 175: /* power_opt: POWER factor  */
#line 1553 "parser.y"
               {
    Node* n = create_node("Power Opt");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = "**";
  }
#line 4200 "parser.cpp"
    break;

  case 176: /* atom_expr: await_opt atom trailer_rep  */
#line 1564 "parser.y"
                            {
    Node* n = create_node("Atom Expression1");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    n->type = (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
    (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var;
  }
#line 4214 "parser.cpp"
    break;

  case 177: /* atom_expr: atom trailer_rep  */
#line 1573 "parser.y"
                   {
    Node* n = create_node("Atom Expression2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));


    if((yyvsp[0].node)->type == "list")
    {
      // done to check cases list x = arr[1]
      if(tab->SYMVAL.find((yyvsp[-1].node)->label) != tab->SYMVAL.end())
      {
        (yyval.node)->type = extractSubstring(tab->SYMVAL[(yyvsp[-1].node)->label].type);
      }
      else if (gt->SYMVAL.find((yyvsp[-1].node)->label) != gt->SYMVAL.end())
      {
        (yyval.node)->type = extractSubstring(gt->SYMVAL[(yyvsp[-1].node)->label].type);
      }
      (yyval.node)->label = (yyvsp[-1].node)->label;
      // cout<<$$->type <<endl;
    }
    if((gt->SYMVAL.find((yyvsp[-1].node)->label) != gt->SYMVAL.end()) && ((yyvsp[0].node)->category == "Func") && (gt->childs[(yyvsp[-1].node)->label]->tab_type != CLS))
    {
      vector<Param*> p = gt->SYMVAL[(yyvsp[-1].node)->label].params;

      if(p.size() > (yyvsp[0].node)->p_f.size())
      {

        cout<<"Lesser number of arguments for function call "<< (yyvsp[-1].node)->label <<" in line number "<< (yyvsp[-1].node)->line_number<<endl;

        //exit(1);
      }
      else if(p.size() < (yyvsp[0].node)->p_f.size())
      {
        cout<<"Greater number of arguments for function call "<< (yyvsp[-1].node)->label <<" in line number "<< (yyvsp[-1].node)->line_number<<endl;
                //exit(1);
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
                      //exit(1);
            }
          }
        }
      }
      (yyval.node)->type = gt->SYMVAL[(yyvsp[-1].node)->label].type ;

      
    }
    else if((gt->SYMVAL.find((yyvsp[-1].node)->label) != gt->SYMVAL.end()) && ((yyvsp[0].node)->category == "Func") && (gt->childs[(yyvsp[-1].node)->label]->tab_type == CLS))
    {
      (yyval.node)->type = gt->SYMVAL[(yyvsp[-1].node)->label].type;
      SYMTAB* s = gt->childs[(yyvsp[-1].node)->label];
      string y = "__init__";

      if(s->SYMVAL.find("__init__")!= s->SYMVAL.end())
      {
        vector<Param*> p = s->SYMVAL[y].params;
        if(p.size() > (yyvsp[0].node)->p_f.size())
        {
         cout<<"Lesser number of arguments for constructor call "<< (yyvsp[-1].node)->label <<" in line number "<< (yyvsp[-1].node)->line_number<<endl;

         //exit(1);
        }
        else if(p.size() < (yyvsp[0].node)->p_f.size())
        {
          cout<<"Greater number of arguments for constructor call "<< (yyvsp[-1].node)->label <<" in line number "<< (yyvsp[-1].node)->line_number<<endl;
                //exit(1);
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
                      //exit(1);
            }
          }
        }
        }
        // cout<<p.size()<<endl;

      }
    }
    else if((yyvsp[0].node)->category == "Func")
    {
      // to support function which are pre defined like len print and range
      if((yyvsp[-1].node)->label == "len"){
        std::regex pattern("list\\[\\w+\\]");
        // cout<<$2->type<<endl;
        if (std::regex_match((yyvsp[0].node)->type, pattern)) {

        } else {
            // cout<<$2->type <<endl;

            std::cout <<" Invalid datatype use for len function in line no : "<<(yyvsp[-1].node)->line_number<<"\n";
            //exit(1);
        }
        (yyval.node)->type ="int";
      }
      else if( (yyvsp[-1].node)->label == "print")
      {
        for(int i = 0;i<(yyvsp[0].node)->p_f.size() ; i++)
        {
          // cout<<$2->p_f[i]->par_type<<" "<<endl;
          if((yyvsp[0].node)->p_f[i]->par_type == "string"){}
          else{
                if((yyvsp[0].node)->p_f[i]->par_type == (yyvsp[0].node)->p_f[i]->par_name)
                {
                  cout<<"Use of undeclared variable inside print function " <<" in line number "<<(yyvsp[0].node)->line_number<<endl;
                  //exit(1);
                }
          }

        }
      }
      
      else{

        cout<<"Undeclared Function in line no : "<< (yyvsp[-1].node)->line_number<<endl;
        //exit(1);
      }
    }
    else if((yyvsp[0].node)->label == "Trailer5")
    {
      //  to check class datatypes  x.a.b.c abhi ispe kaam bcha h 
      if((yyvsp[-1].node)->label == "self")
      {
        
        if(tab->parent->SYMVAL.find((yyvsp[0].node)->type) == tab->parent->SYMVAL.end()) 
        {
          cout<<"Undefined property "<<(yyvsp[0].node)->type<<" for class "<<(yyvsp[-1].node)->type<<" used by object "<<(yyvsp[-1].node)->label<<" in line no "<<(yyvsp[-1].node)->line_number<<endl;
          //exit(1);
        }
        (yyval.node)->type = tab->parent->SYMVAL[(yyvsp[0].node)->type].type;
      }
      else 
      {

        if(gt->childs[(yyvsp[-1].node)->type]->SYMVAL.find((yyvsp[0].node)->type) == gt->childs[(yyvsp[-1].node)->type]->SYMVAL.end()) 
        {
          cout<<"Undefined property "<<(yyvsp[0].node)->type<<" for class "<<(yyvsp[-1].node)->type<<" used by object "<<(yyvsp[-1].node)->label<<"in line no "<<(yyvsp[-1].node)->line_number<<endl;
          //exit(1);
        }
        (yyval.node)->type = gt->childs[(yyvsp[-1].node)->type]->SYMVAL[(yyvsp[0].node)->type].type;
      }
      (yyval.node)->label = (yyvsp[-1].node)->label;

      // cout<<$2->p_f[0]->par_type<<" sadv" <<endl;
      // string s_s = $2->p_f[$2->p_f.size()-1]->par_name ;
      // strings cls_label = $1->label;
      // for(int i=0;i<$2->p_f.size()<i++)
      // {
      //   s_s = $2->p_f[$2->p_f.size()-1]->par_name;
        
      //   cls_label = $2->p_f[i]->par_name 
      // }
      if((yyvsp[0].node)->p_f.size()==1)
      {
        (yyvsp[0].node)->p_f[0]->par_type = gt->childs[(yyvsp[-1].node)->type]->SYMVAL[(yyvsp[0].node)->p_f[0]->par_name].type;
      }
      (yyval.node)->p_f = (yyvsp[0].node)->p_f;


    }
    (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var;
        for(int i=0;i<arguments.size();i++) { 
        string s1 = get<0>(arguments[i]);
        if(tab->SYMVAL.find(s1)!=tab->SYMVAL.end()){
        codepush("",tab->SYMVAL[s1].temp_var,"","pushparam",-1);
        
        } 
        else{
            codepush("",get<1>(arguments[i]),"","pushparam",-1);
        } }
        if((yyvsp[-1].node)->type=="None")
        codepush("call",(yyvsp[-1].node)->label,"","",-1);
        else{
          codepush(" ","call",(yyvsp[-1].node)->label,"",-1);
        }
        arguments.clear();
  }
#line 4415 "parser.cpp"
    break;

  case 178: /* atom_expr: atom  */
#line 1769 "parser.y"
       {
    (yyval.node) = (yyvsp[0].node);
    // cout<<"atom " <<$$->type<<endl;
    if(yybye) cout<<"atom_expr atom: "<<endl; 
  }
#line 4425 "parser.cpp"
    break;

  case 179: /* await_opt: AWAIT  */
#line 1775 "parser.y"
                  {
  (yyval.node) = (yyvsp[0].node);
}
#line 4433 "parser.cpp"
    break;

  case 180: /* trailer_rep: trailer_rep trailer  */
#line 1780 "parser.y"
                      {
    if(yybye) cout<<"trailer_rep: "<<endl;
    Node* n = create_node("Trailer Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));
    cout<<" Datatypes like in line number "<<(yyvsp[0].node)->line_number <<" not supported for now "<<endl;
    exit(1);

  }
#line 4450 "parser.cpp"
    break;

  case 181: /* trailer_rep: trailer  */
#line 1792 "parser.y"
            { 
    (yyval.node) =(yyvsp[0].node);
  }
#line 4458 "parser.cpp"
    break;

  case 182: /* atom: LPAREN atom_opt1 RPAREN  */
#line 1796 "parser.y"
                               {
        if(yybye) cout<<"atom atom_opt1: "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-2].node));
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        (yyval.node)->category = "Func";
        (yyval.node)->type = (yyvsp[-1].node)->type;
        (yyval.node)->line_number = (yyvsp[-2].node)->line_number;
        (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var;
      }
#line 4475 "parser.cpp"
    break;

  case 183: /* atom: LBRACKET atom_opt2 RBRACKET  */
#line 1808 "parser.y"
                                    {
        if(yybye) cout<<"atom atom_opt2: "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-2].node));
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        (yyval.node)->type = "list" + (yyvsp[-2].node)->type + (yyvsp[-1].node)->type +(yyvsp[0].node)->type;
        (yyval.node)->line_number = (yyvsp[-2].node)->line_number;
        (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var;

      }
#line 4492 "parser.cpp"
    break;

  case 184: /* atom: LBRACKET RBRACKET  */
#line 1820 "parser.y"
                         { 
        if(yybye) cout<<"atom : "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        (yyval.node)->line_number = (yyvsp[-1].node)->line_number;

      }
#line 4506 "parser.cpp"
    break;

  case 185: /* atom: NAME  */
#line 1829 "parser.y"
              { (yyval.node) =(yyvsp[0].node);
                if(tab->SYMVAL.find((yyvsp[0].node)->label)!=tab->SYMVAL.end())
                {
                  // cout<<"Already declared"<<endl;
                  (yyval.node)->type = tab->SYMVAL[(yyvsp[0].node)->label].type;
                  (yyval.node)->temp_var = tab->SYMVAL[(yyvsp[0].node)->label].temp_var;
                  // cout<<$$->type<<" Name "<< yylineno << " "<< $$->label<<endl;
                }
                else if(gt->SYMVAL.find((yyvsp[0].node)->label)!=gt->SYMVAL.end())
                {
                  // cout<<$$->type << " "<<$$->label<<endl;
                  (yyval.node)->type = gt->SYMVAL[(yyvsp[0].node)->label].type;
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
                else{
                string t = new_temporary();

                (yyval.node)->temp_var = t;
                // cout << t;
                codepush("",t,"",(yyvsp[0].node)->label,-1);}  
                }
              

      }
#line 4546 "parser.cpp"
    break;

  case 186: /* atom: NUMBER  */
#line 1864 "parser.y"
                { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "int";
                  (yyval.node)->temp_var= new_temporary();
                  codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);  }
#line 4554 "parser.cpp"
    break;

  case 187: /* atom: FLOAT  */
#line 1867 "parser.y"
              {(yyval.node) = (yyvsp[0].node); (yyval.node)->type = "float";
                (yyval.node)->temp_var= new_temporary();
                codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4562 "parser.cpp"
    break;

  case 188: /* atom: string_rep  */
#line 1870 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "string";
                      (yyval.node)->temp_var= new_temporary();
                      codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4570 "parser.cpp"
    break;

  case 189: /* atom: TRIPLEDOT  */
#line 1873 "parser.y"
                   { (yyval.node) =(yyvsp[0].node);}
#line 4576 "parser.cpp"
    break;

  case 190: /* atom: NONE  */
#line 1874 "parser.y"
              { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "None";}
#line 4582 "parser.cpp"
    break;

  case 191: /* atom: TRUE_TOKEN  */
#line 1875 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";
                      (yyval.node)->temp_var= new_temporary();
                      codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4590 "parser.cpp"
    break;

  case 192: /* atom: FALSE_TOKEN  */
#line 1878 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";
                      (yyval.node)->temp_var= new_temporary();
                      codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4598 "parser.cpp"
    break;

  case 193: /* atom_opt1: yield_expr  */
#line 1882 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 4604 "parser.cpp"
    break;

  case 194: /* atom_opt1: testlist_comp  */
#line 1883 "parser.y"
                         {(yyval.node) = (yyvsp[0].node); if(yybye) cout<<"atom_opt1 testlist_comp: "<<endl;}
#line 4610 "parser.cpp"
    break;

  case 195: /* atom_opt2: testlist_comp  */
#line 1885 "parser.y"
                         {(yyval.node) =(yyvsp[0].node);}
#line 4616 "parser.cpp"
    break;

  case 196: /* string_rep: STRING  */
#line 1888 "parser.y"
         { (yyval.node) = (yyvsp[0].node);}
#line 4622 "parser.cpp"
    break;

  case 197: /* string_rep: string_rep STRING  */
#line 1889 "parser.y"
                      {
    Node* n = create_node("String Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));    
    (yyval.node)->line_number= (yyvsp[-1].node)->line_number;
  }
#line 4636 "parser.cpp"
    break;

  case 198: /* testlist_comp: testlist_comp_c1 testlist_comp_c2  */
#line 1900 "parser.y"
                                   {
    Node* n = create_node("Testlist comp");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[-1].node)->type;
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
    check_type((yyvsp[-1].node)->type , (yyvsp[0].node)->type , (yyvsp[0].node)->line_number);
    // cout<<"Yes  "<<endl;
    (yyval.node)->type = (yyvsp[-1].node)->type;
  }
#line 4652 "parser.cpp"
    break;

  case 199: /* testlist_comp: testlist_comp_c1  */
#line 1911 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 4658 "parser.cpp"
    break;

  case 200: /* testlist_comp_c1: test  */
#line 1914 "parser.y"
         {(yyval.node) = (yyvsp[0].node);}
#line 4664 "parser.cpp"
    break;

  case 201: /* testlist_comp_c1: star_expr  */
#line 1915 "parser.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 4670 "parser.cpp"
    break;

  case 202: /* testlist_comp_c2: comp_for  */
#line 1918 "parser.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 4676 "parser.cpp"
    break;

  case 203: /* testlist_comp_c2: testlist_comp_c2_rep COMMA  */
#line 1919 "parser.y"
                              {
    Node* n = create_node("Testlist Comp C2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[-1].node)->type;
    (yyval.node)->line_number = (yyvsp[0].node)->line_number;
  }
#line 4689 "parser.cpp"
    break;

  case 204: /* testlist_comp_c2: COMMA  */
#line 1927 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 4695 "parser.cpp"
    break;

  case 205: /* testlist_comp_c2: testlist_comp_c2_rep  */
#line 1928 "parser.y"
                        {(yyval.node) =(yyvsp[0].node);}
#line 4701 "parser.cpp"
    break;

  case 206: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA test  */
#line 1932 "parser.y"
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
#line 4717 "parser.cpp"
    break;

  case 207: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA star_expr  */
#line 1943 "parser.y"
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
#line 4733 "parser.cpp"
    break;

  case 208: /* testlist_comp_c2_rep: COMMA test  */
#line 1954 "parser.y"
             {
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 4745 "parser.cpp"
    break;

  case 209: /* testlist_comp_c2_rep: COMMA star_expr  */
#line 1961 "parser.y"
                    { 
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 4757 "parser.cpp"
    break;

  case 210: /* trailer: LPAREN arglist RPAREN  */
#line 1970 "parser.y"
                       {
    if(yybye) cout<<"trailer: "<<endl;
    Node* n = create_node("Trailer1");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->category = "Func";
    (yyval.node)->type = (yyvsp[-1].node)->type;
    (yyval.node)->line_number = (yyvsp[-2].node)->line_number;
    (yyval.node)->p_f = (yyvsp[-1].node)->p_f;

  }
#line 4775 "parser.cpp"
    break;

  case 211: /* trailer: LPAREN RPAREN  */
#line 1983 "parser.y"
                {
    Node* n = create_node("Trailer2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
    (yyval.node)->category = "Func";
  }
#line 4788 "parser.cpp"
    break;

  case 212: /* trailer: LBRACKET subscriptlist RBRACKET  */
#line 1991 "parser.y"
                                    {
    Node* n = create_node("Trailer3");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-2].node)->line_number;
    if(((yyvsp[-1].node)->type == "int") && ((yyvsp[-1].node)->label != "int"))
      (yyval.node)->type = "list";
    else
      (yyval.node)->type = (yyvsp[-2].node)->type + (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
  }
#line 4805 "parser.cpp"
    break;

  case 213: /* trailer: LBRACKET RBRACKET  */
#line 2003 "parser.y"
                    { 
    Node* n = create_node("Trailer4");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
  }
#line 4817 "parser.cpp"
    break;

  case 214: /* trailer: DOT NAME  */
#line 2010 "parser.y"
            {
    Node* n = create_node("Trailer5");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
    // attributes of a class
    Param* temp = new Param();
    temp->par_name = (yyvsp[0].node)->label;
    (yyval.node)->p_f.push_back(temp);
  }
#line 4834 "parser.cpp"
    break;

  case 215: /* subscriptlist: subscript COMMA_subscript_rep COMMA_opt  */
#line 2024 "parser.y"
                                         {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4847 "parser.cpp"
    break;

  case 216: /* subscriptlist: subscript COMMA_opt  */
#line 2032 "parser.y"
                      {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4858 "parser.cpp"
    break;

  case 217: /* subscriptlist: subscript COMMA_subscript_rep  */
#line 2038 "parser.y"
                                {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4869 "parser.cpp"
    break;

  case 218: /* subscriptlist: subscript  */
#line 2044 "parser.y"
             {(yyval.node) =(yyvsp[0].node);}
#line 4875 "parser.cpp"
    break;

  case 219: /* COMMA_opt: COMMA  */
#line 2047 "parser.y"
        { (yyval.node) = (yyvsp[0].node);}
#line 4881 "parser.cpp"
    break;

  case 220: /* COMMA_subscript_rep: COMMA_subscript_rep COMMA subscript  */
#line 2051 "parser.y"
                                      {
    Node* n = create_node("Comma Subscript rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4895 "parser.cpp"
    break;

  case 221: /* COMMA_subscript_rep: COMMA subscript  */
#line 2060 "parser.y"
                   {
    Node* n = create_node("COMMA subscript rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4906 "parser.cpp"
    break;

  case 222: /* subscript: test  */
#line 2068 "parser.y"
       { (yyval.node) = (yyvsp[0].node);}
#line 4912 "parser.cpp"
    break;

  case 223: /* subscript: test COLON test sliceop  */
#line 2069 "parser.y"
                           {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4926 "parser.cpp"
    break;

  case 224: /* subscript: COLON test sliceop  */
#line 2078 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4938 "parser.cpp"
    break;

  case 225: /* subscript: test COLON sliceop  */
#line 2085 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4950 "parser.cpp"
    break;

  case 226: /* subscript: test COLON test  */
#line 2092 "parser.y"
                   {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4962 "parser.cpp"
    break;

  case 227: /* subscript: COLON sliceop  */
#line 2099 "parser.y"
                 {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4973 "parser.cpp"
    break;

  case 228: /* subscript: COLON test  */
#line 2105 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4984 "parser.cpp"
    break;

  case 229: /* subscript: test COLON  */
#line 2111 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4995 "parser.cpp"
    break;

  case 230: /* subscript: COLON  */
#line 2117 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 5001 "parser.cpp"
    break;

  case 231: /* sliceop: COLON test  */
#line 2119 "parser.y"
                    {
    Node* n = create_node("Slice OP");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 5012 "parser.cpp"
    break;

  case 232: /* sliceop: COLON  */
#line 2125 "parser.y"
       {(yyval.node) = (yyvsp[0].node);}
#line 5018 "parser.cpp"
    break;

  case 233: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep COMMA  */
#line 2127 "parser.y"
                                                        {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 5030 "parser.cpp"
    break;

  case 234: /* exprlist: expr_star_expr COMMA  */
#line 2134 "parser.y"
                      {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 5041 "parser.cpp"
    break;

  case 235: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep  */
#line 2140 "parser.y"
                                         {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 5052 "parser.cpp"
    break;

  case 236: /* exprlist: expr_star_expr  */
#line 2146 "parser.y"
                {(yyval.node) =(yyvsp[0].node);}
#line 5058 "parser.cpp"
    break;

  case 237: /* expr_star_expr: expr  */
#line 2148 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 5064 "parser.cpp"
    break;

  case 238: /* expr_star_expr: star_expr  */
#line 2149 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 5070 "parser.cpp"
    break;

  case 239: /* COMMA_expr_star_expr_rep: COMMA_expr_star_expr_rep COMMA expr_star_expr  */
#line 2152 "parser.y"
                                               {
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 5084 "parser.cpp"
    break;

  case 240: /* COMMA_expr_star_expr_rep: COMMA expr_star_expr  */
#line 2161 "parser.y"
                       { 
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 5095 "parser.cpp"
    break;

  case 241: /* testlist: test COMMA  */
#line 2176 "parser.y"
             {
    Node* n = create_node("Testlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 5106 "parser.cpp"
    break;

  case 242: /* testlist: test  */
#line 2188 "parser.y"
        {(yyval.node) =(yyvsp[0].node);}
#line 5112 "parser.cpp"
    break;

  case 243: /* class_name: CLASS NAME  */
#line 2205 "parser.y"
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
               newtab->tab_type = 3;
              //  tab->childs.push_back(newtab);
               tab->childs[(yyvsp[0].node)->label] = newtab;
              //  cout<<gt->childs[$2->label]->tab_type<<"funck"<<endl;
               tab=newtab;
             }
             else {
              cout<<"Class redeclared in line no "<< (yyvsp[0].node)->line_number<<endl;
                      //exit(1);
             }
}
#line 5142 "parser.cpp"
    break;

  case 244: /* classdef: class_name LPAREN arglist RPAREN COLON suite  */
#line 2230 "parser.y"
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
    if(tab->SYMVAL.find((yyvsp[-5].node)->label)!= tab->SYMVAL.end()){
      tab->SYMVAL[(yyvsp[-5].node)->label].identity=CLS;
      tab->SYMVAL[(yyvsp[-5].node)->label].scope=curr_scope;
      tab->SYMVAL[(yyvsp[-5].node)->label].line_no=(yyvsp[-5].node)->line_number;
      tab->SYMVAL[(yyvsp[-5].node)->label].type=(yyvsp[-5].node)->label;
      tab->SYMVAL[(yyvsp[-5].node)->label].name=(yyvsp[-5].node)->label;
      tab->SYMVAL[(yyvsp[-5].node)->label].size=(yyvsp[-3].node)->count;
      tab->SYMVAL[(yyvsp[-5].node)->label].params=(yyvsp[-3].node)->p_f;
   }

  //  else{
  //   cout<<"error"<<endl;
  //   exit(0);
  //  }   

}
#line 5173 "parser.cpp"
    break;

  case 245: /* classdef: class_name LPAREN RPAREN COLON suite  */
#line 2256 "parser.y"
                                      {
    Node* n = create_node("Class Def");
    n->children.push_back((yyvsp[-4].node));
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
    tab=tab->parent;
    if(tab->SYMVAL.find((yyvsp[-4].node)->label)!= tab->SYMVAL.end()){
      tab->SYMVAL[(yyvsp[-4].node)->label].identity=CLS;
      tab->SYMVAL[(yyvsp[-4].node)->label].scope=curr_scope;
      tab->SYMVAL[(yyvsp[-4].node)->label].line_no=(yyvsp[-4].node)->line_number;
      tab->SYMVAL[(yyvsp[-4].node)->label].type=(yyvsp[-4].node)->label;
      tab->SYMVAL[(yyvsp[-4].node)->label].name=(yyvsp[-4].node)->label;
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

  //  else{
  //   cout<<"error"<<endl;
  //   exit(0);
  //  }   
}
#line 5211 "parser.cpp"
    break;

  case 246: /* classdef: class_name COLON suite  */
#line 2289 "parser.y"
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
#line 5248 "parser.cpp"
    break;

  case 247: /* arglist: argument COMMA_argument_rep COMMA  */
#line 2323 "parser.y"
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
    arguments.push_back(make_tuple((yyvsp[-2].node)->label,(yyvsp[-2].node)->temp_var, (yyvsp[-2].node)->type,0,0));

  }
#line 5272 "parser.cpp"
    break;

  case 248: /* arglist: argument COMMA  */
#line 2342 "parser.y"
                  {
    Node* n = create_node("Arglist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    Param* temp = new Param();
    temp->par_type=(yyvsp[-1].node)->type;
    temp->par_name=(yyvsp[-1].node)->label;
    (yyval.node)->p_f.push_back(temp);
    arguments.push_back(make_tuple((yyvsp[-1].node)->label,(yyvsp[-1].node)->temp_var, (yyvsp[-1].node)->type,0,0));
  }
#line 5288 "parser.cpp"
    break;

  case 249: /* arglist: argument COMMA_argument_rep  */
#line 2353 "parser.y"
                               {
    Node* n = create_node("Arglist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    // cout<<"Arglist 3 "<<endl;
    Param* temp = new Param();
    temp->par_type=(yyvsp[-1].node)->type;
    temp->par_name=(yyvsp[-1].node)->label;
    // cout<<temp->par_type<<" ARGLIST "<<temp->par_name<<endl;
    (yyval.node)->p_f.push_back(temp);
    (yyval.node)->p_f.insert((yyval.node)->p_f.end(), (yyvsp[0].node)->p_f.begin(), (yyvsp[0].node)->p_f.end());
    // for (auto it = $$->parameters.begin(); it != $$->parameters.end(); ++it) {
    //   std::cout << *it << " ";
    // }
    // cout<<endl;
    arguments.push_back(make_tuple((yyvsp[-1].node)->label,(yyvsp[-1].node)->temp_var, (yyvsp[-1].node)->type,0,0));
  }
#line 5311 "parser.cpp"
    break;

  case 250: /* arglist: argument  */
#line 2371 "parser.y"
           {(yyval.node) =(yyvsp[0].node);

    arguments.push_back(make_tuple((yyvsp[0].node)->label,(yyvsp[0].node)->temp_var, (yyvsp[0].node)->type,0,0));
  }
#line 5320 "parser.cpp"
    break;

  case 251: /* COMMA_argument_rep: COMMA_argument_rep COMMA argument  */
#line 2377 "parser.y"
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
    arguments.push_back(make_tuple((yyvsp[0].node)->label,(yyvsp[-1].node)->temp_var, (yyvsp[0].node)->type,0,0));
  }
#line 5342 "parser.cpp"
    break;

  case 252: /* COMMA_argument_rep: COMMA argument  */
#line 2394 "parser.y"
                   {
    Node* n = create_node("Comma Argument rep2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    Param* temp = new Param();
    temp->par_type=(yyvsp[0].node)->type;
    temp->par_name=(yyvsp[0].node)->label;
    (yyval.node)->p_f.push_back(temp);
    arguments.push_back(make_tuple((yyvsp[0].node)->label,(yyvsp[0].node)->temp_var, (yyvsp[0].node)->type,0,0));
  }
#line 5358 "parser.cpp"
    break;

  case 253: /* argument: test comp_for  */
#line 2407 "parser.y"
               {
    Node* n = create_node("Argument");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 5369 "parser.cpp"
    break;

  case 254: /* argument: test EQUAL_SIGN test  */
#line 2413 "parser.y"
                         {
     Node* n = create_node("Argument");
     (yyval.node) = n;
     n->children.push_back((yyvsp[-2].node));
     n->children.push_back((yyvsp[-1].node));
     codepush("", (yyvsp[0].node)->temp_var, "", (yyvsp[-2].node)->temp_var, -1);
     (yyval.node)->temp_var = (yyvsp[-2].node)->temp_var;
  }
#line 5382 "parser.cpp"
    break;

  case 255: /* argument: POWER test  */
#line 2421 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));      
  }
#line 5393 "parser.cpp"
    break;

  case 256: /* argument: TIMES test  */
#line 2427 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));    
  }
#line 5404 "parser.cpp"
    break;

  case 257: /* argument: test  */
#line 2433 "parser.y"
       {(yyval.node) =(yyvsp[0].node); }
#line 5410 "parser.cpp"
    break;

  case 258: /* comp_iter: comp_for  */
#line 2435 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 5416 "parser.cpp"
    break;

  case 259: /* comp_iter: comp_if  */
#line 2436 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 5422 "parser.cpp"
    break;

  case 260: /* sync_comp_for: FOR exprlist IN or_test comp_iter  */
#line 2438 "parser.y"
                                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-4].node));
          n->children.push_back((yyvsp[-3].node));  
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));   
          n->children.push_back((yyvsp[0].node));   
}
#line 5436 "parser.cpp"
    break;

  case 261: /* sync_comp_for: FOR exprlist IN or_test  */
#line 2447 "parser.y"
                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-3].node));
          n->children.push_back((yyvsp[-2].node));  
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 5449 "parser.cpp"
    break;

  case 262: /* comp_for: ASYNC sync_comp_for  */
#line 2456 "parser.y"
                             { 
          Node* n = create_node("Comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));  }
#line 5459 "parser.cpp"
    break;

  case 263: /* comp_for: sync_comp_for  */
#line 2461 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 5465 "parser.cpp"
    break;

  case 264: /* comp_if: IF test_nocond comp_iter  */
#line 2463 "parser.y"
                                  {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
}
#line 5477 "parser.cpp"
    break;

  case 265: /* comp_if: IF test_nocond  */
#line 2470 "parser.y"
                        {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 5488 "parser.cpp"
    break;

  case 266: /* yield_expr: YIELD  */
#line 2476 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 5494 "parser.cpp"
    break;


#line 5498 "parser.cpp"

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

#line 2485 "parser.y"



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
        //exit(1); 
    }
    yyparse();
    cout<<endl;
    gt->WriteAllSYMTABsToCSV("symtabs.csv", gt);
    print3ac();
    fclose(yyin);
    simplify(root);
    printDot(root, output_filename);
    return 0;
}
void yyerror(const char* err) {
  std::cerr << "Error (line " << "): "<<yylineno << err << "token : " << yychar << std::endl;
}

