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
  //exit(1);;
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
  YYSYMBOL_107_3 = 107,                    /* $@3  */
  YYSYMBOL_parameters = 108,               /* parameters  */
  YYSYMBOL_typedargslist = 109,            /* typedargslist  */
  YYSYMBOL_datatype = 110,                 /* datatype  */
  YYSYMBOL_stmt = 111,                     /* stmt  */
  YYSYMBOL_simple_stmt = 112,              /* simple_stmt  */
  YYSYMBOL_small_stmt_list = 113,          /* small_stmt_list  */
  YYSYMBOL_small_stmt = 114,               /* small_stmt  */
  YYSYMBOL_expr_stmt = 115,                /* expr_stmt  */
  YYSYMBOL_expr_stmt_tail = 116,           /* expr_stmt_tail  */
  YYSYMBOL_decl_type = 117,                /* decl_type  */
  YYSYMBOL_augassign_op = 118,             /* augassign_op  */
  YYSYMBOL_annassign = 119,                /* annassign  */
  YYSYMBOL_testlist_star_expr = 120,       /* testlist_star_expr  */
  YYSYMBOL_testlist_star_expr_opt1 = 121,  /* testlist_star_expr_opt1  */
  YYSYMBOL_testlist_star_expr_rep = 122,   /* testlist_star_expr_rep  */
  YYSYMBOL_augassign = 123,                /* augassign  */
  YYSYMBOL_del_stmt = 124,                 /* del_stmt  */
  YYSYMBOL_pass_stmt = 125,                /* pass_stmt  */
  YYSYMBOL_flow_stmt = 126,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 127,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 128,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 129,              /* return_stmt  */
  YYSYMBOL_yield_stmt = 130,               /* yield_stmt  */
  YYSYMBOL_global_stmt = 131,              /* global_stmt  */
  YYSYMBOL_global_name_list = 132,         /* global_name_list  */
  YYSYMBOL_compound_stmt = 133,            /* compound_stmt  */
  YYSYMBOL_async_stmt = 134,               /* async_stmt  */
  YYSYMBOL_async_stmt_content = 135,       /* async_stmt_content  */
  YYSYMBOL_if_stmt = 136,                  /* if_stmt  */
  YYSYMBOL_elif_stmt_rep = 137,            /* elif_stmt_rep  */
  YYSYMBOL_while_stmt = 138,               /* while_stmt  */
  YYSYMBOL_139_4 = 139,                    /* $@4  */
  YYSYMBOL_for_stmt = 140,                 /* for_stmt  */
  YYSYMBOL_141_5 = 141,                    /* $@5  */
  YYSYMBOL_range_func = 142,               /* range_func  */
  YYSYMBOL_suite = 143,                    /* suite  */
  YYSYMBOL_stmt_rep = 144,                 /* stmt_rep  */
  YYSYMBOL_test = 145,                     /* test  */
  YYSYMBOL_test_nocond = 146,              /* test_nocond  */
  YYSYMBOL_or_test = 147,                  /* or_test  */
  YYSYMBOL_or_test_rep = 148,              /* or_test_rep  */
  YYSYMBOL_and_test = 149,                 /* and_test  */
  YYSYMBOL_and_test_rep = 150,             /* and_test_rep  */
  YYSYMBOL_not_test = 151,                 /* not_test  */
  YYSYMBOL_comparison = 152,               /* comparison  */
  YYSYMBOL_comparison_rep = 153,           /* comparison_rep  */
  YYSYMBOL_comp_op = 154,                  /* comp_op  */
  YYSYMBOL_star_expr = 155,                /* star_expr  */
  YYSYMBOL_expr = 156,                     /* expr  */
  YYSYMBOL_expr_rep = 157,                 /* expr_rep  */
  YYSYMBOL_xor_expr = 158,                 /* xor_expr  */
  YYSYMBOL_xor_expr_rep = 159,             /* xor_expr_rep  */
  YYSYMBOL_and_expr = 160,                 /* and_expr  */
  YYSYMBOL_and_expr_rep = 161,             /* and_expr_rep  */
  YYSYMBOL_shift_expr = 162,               /* shift_expr  */
  YYSYMBOL_shift_expr_rep = 163,           /* shift_expr_rep  */
  YYSYMBOL_shift_expr_rep_c1 = 164,        /* shift_expr_rep_c1  */
  YYSYMBOL_arith_expr = 165,               /* arith_expr  */
  YYSYMBOL_arith_expr_rep = 166,           /* arith_expr_rep  */
  YYSYMBOL_arith_expr_rep_c1 = 167,        /* arith_expr_rep_c1  */
  YYSYMBOL_term = 168,                     /* term  */
  YYSYMBOL_term_rep = 169,                 /* term_rep  */
  YYSYMBOL_term_rep_c1 = 170,              /* term_rep_c1  */
  YYSYMBOL_factor = 171,                   /* factor  */
  YYSYMBOL_factor_c1 = 172,                /* factor_c1  */
  YYSYMBOL_power = 173,                    /* power  */
  YYSYMBOL_power_opt = 174,                /* power_opt  */
  YYSYMBOL_atom_expr = 175,                /* atom_expr  */
  YYSYMBOL_await_opt = 176,                /* await_opt  */
  YYSYMBOL_trailer_rep = 177,              /* trailer_rep  */
  YYSYMBOL_atom = 178,                     /* atom  */
  YYSYMBOL_atom_opt1 = 179,                /* atom_opt1  */
  YYSYMBOL_atom_opt2 = 180,                /* atom_opt2  */
  YYSYMBOL_string_rep = 181,               /* string_rep  */
  YYSYMBOL_testlist_comp = 182,            /* testlist_comp  */
  YYSYMBOL_testlist_comp_c1 = 183,         /* testlist_comp_c1  */
  YYSYMBOL_testlist_comp_c2 = 184,         /* testlist_comp_c2  */
  YYSYMBOL_testlist_comp_c2_rep = 185,     /* testlist_comp_c2_rep  */
  YYSYMBOL_trailer = 186,                  /* trailer  */
  YYSYMBOL_subscriptlist = 187,            /* subscriptlist  */
  YYSYMBOL_COMMA_opt = 188,                /* COMMA_opt  */
  YYSYMBOL_COMMA_subscript_rep = 189,      /* COMMA_subscript_rep  */
  YYSYMBOL_subscript = 190,                /* subscript  */
  YYSYMBOL_sliceop = 191,                  /* sliceop  */
  YYSYMBOL_exprlist = 192,                 /* exprlist  */
  YYSYMBOL_expr_star_expr = 193,           /* expr_star_expr  */
  YYSYMBOL_COMMA_expr_star_expr_rep = 194, /* COMMA_expr_star_expr_rep  */
  YYSYMBOL_testlist = 195,                 /* testlist  */
  YYSYMBOL_class_name = 196,               /* class_name  */
  YYSYMBOL_classdef = 197,                 /* classdef  */
  YYSYMBOL_arglist = 198,                  /* arglist  */
  YYSYMBOL_COMMA_argument_rep = 199,       /* COMMA_argument_rep  */
  YYSYMBOL_argument = 200,                 /* argument  */
  YYSYMBOL_comp_iter = 201,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 202,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 203,                 /* comp_for  */
  YYSYMBOL_comp_if = 204,                  /* comp_if  */
  YYSYMBOL_yield_expr = 205                /* yield_expr  */
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
#define YYLAST   1239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  106
/* YYNRULES -- Number of rules.  */
#define YYNRULES  265
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  379

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
       0,   152,   152,   157,   163,   170,   178,   179,   183,   211,
     230,   211,   278,   278,   344,   354,   362,   378,   404,   430,
     466,   472,   484,   485,   488,   496,   504,   511,   521,   531,
     539,   540,   541,   542,   543,   545,   620,   623,   633,   636,
     642,   656,   660,   673,   674,   697,   714,   723,   731,   738,
     742,   743,   746,   756,   758,   759,   760,   761,   762,   763,
     764,   765,   766,   767,   768,   769,   770,   773,   779,   781,
     782,   783,   784,   787,   789,   790,   801,   803,   804,   811,
     821,   823,   824,   825,   826,   827,   828,   831,   834,   835,
     838,   851,   863,   875,   885,   896,   905,   905,   920,   920,
     955,   969,   989,   990,  1004,  1013,  1015,  1024,  1027,  1030,
    1040,  1043,  1062,  1076,  1091,  1094,  1114,  1131,  1147,  1152,
    1166,  1170,  1184,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1212,  1213,  1221,  1230,  1239,  1242,  1256,  1265,  1274,
    1279,  1293,  1302,  1311,  1314,  1328,  1338,  1347,  1350,  1363,
    1373,  1377,  1382,  1402,  1405,  1431,  1442,  1443,  1446,  1468,
    1471,  1502,  1519,  1520,  1521,  1522,  1523,  1526,  1536,  1538,
    1539,  1540,  1543,  1554,  1560,  1571,  1580,  1773,  1779,  1784,
    1796,  1800,  1812,  1824,  1833,  1866,  1869,  1872,  1875,  1876,
    1877,  1880,  1884,  1885,  1887,  1890,  1891,  1902,  1913,  1916,
    1917,  1920,  1921,  1929,  1930,  1933,  1945,  1956,  1963,  1972,
    1985,  1993,  2005,  2012,  2026,  2034,  2040,  2046,  2049,  2053,
    2062,  2070,  2071,  2080,  2087,  2094,  2101,  2107,  2113,  2119,
    2121,  2127,  2129,  2136,  2142,  2148,  2150,  2151,  2154,  2163,
    2178,  2190,  2207,  2232,  2258,  2291,  2325,  2344,  2355,  2373,
    2382,  2399,  2412,  2418,  2426,  2432,  2438,  2440,  2441,  2443,
    2452,  2461,  2466,  2468,  2475,  2481
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
  "funcdef", "$@1", "$@2", "$@3", "parameters", "typedargslist",
  "datatype", "stmt", "simple_stmt", "small_stmt_list", "small_stmt",
  "expr_stmt", "expr_stmt_tail", "decl_type", "augassign_op", "annassign",
  "testlist_star_expr", "testlist_star_expr_opt1",
  "testlist_star_expr_rep", "augassign", "del_stmt", "pass_stmt",
  "flow_stmt", "break_stmt", "continue_stmt", "return_stmt", "yield_stmt",
  "global_stmt", "global_name_list", "compound_stmt", "async_stmt",
  "async_stmt_content", "if_stmt", "elif_stmt_rep", "while_stmt", "$@4",
  "for_stmt", "$@5", "range_func", "suite", "stmt_rep", "test",
  "test_nocond", "or_test", "or_test_rep", "and_test", "and_test_rep",
  "not_test", "comparison", "comparison_rep", "comp_op", "star_expr",
  "expr", "expr_rep", "xor_expr", "xor_expr_rep", "and_expr",
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

#define YYPACT_NINF (-242)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-13)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,    71,  1095,  -242,  1124,   107,  1095,  1124,   125,  1095,
     127,  1095,  -242,  -242,  -242,  -242,  -242,  1141,  -242,   714,
     774,  -242,   126,   319,    70,  -242,  -242,  -242,    48,  -242,
      62,    67,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,   119,   129,   143,  -242,
    -242,   155,   117,   120,   132,    18,   123,    41,  1141,  -242,
     133,    35,    90,   144,    11,  -242,  -242,  -242,   118,  -242,
    -242,  -242,   174,   121,  -242,  -242,  -242,  -242,   124,  -242,
    -242,  -242,  -242,   122,  -242,  -242,  -242,   130,  -242,    25,
    -242,  -242,   131,  -242,  -242,  -242,  -242,  -242,    40,   128,
    -242,   493,    52,   196,  1095,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
     926,   943,   134,  1095,  1095,   160,  1095,   179,  -242,   167,
     188,  -242,  -242,  -242,  -242,  -242,  -242,   155,  1141,  1141,
     150,  1141,   151,  1141,   152,  -242,  -242,    18,  1141,  -242,
    -242,   123,  1141,  -242,  -242,  -242,  -242,  -242,    41,  1141,
    -242,  1141,  -242,    90,   637,   820,   207,    90,  -242,  -242,
     697,   541,  -242,   210,  1124,   142,   148,   219,   541,  -242,
    1124,   197,   943,  -242,   153,  -242,  -242,  -242,    10,  -242,
     157,   154,   156,  -242,  -242,  -242,   589,   162,   158,  -242,
    -242,  -242,  -242,  -242,   943,   217,  -242,  1095,  -242,  1095,
    -242,  -242,  1141,  -242,  -242,  1141,  -242,  1141,  -242,  1141,
    1141,  -242,  1141,  -242,  1141,  -242,  -242,    90,  1095,  1095,
    -242,    36,   165,   164,  -242,  1003,   166,   168,   169,  -242,
    -242,   170,   171,   235,  -242,  -242,   176,  -242,  -242,  1124,
     541,  -242,    84,   227,  -242,  -242,  -242,   943,   242,   243,
    -242,  1095,   541,  -242,  -242,   244,  -242,  -242,  1095,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    1095,  -242,  -242,   866,   177,  1095,   178,  -242,  1003,  -242,
    1049,  -242,   180,   541,   181,   445,  1095,   183,  -242,  -242,
     184,  1095,    85,  1095,  -242,  -242,  -242,   185,   189,  -242,
    -242,   191,  -242,  -242,  -242,   866,  -242,  -242,   178,  -242,
    -242,  1049,  -242,  -242,   541,  -242,   385,    87,   541,   541,
     190,   192,  1095,    93,   259,   242,   194,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  1095,  -242,  -242,   541,   541,
     195,  1095,  -242,  -242,  -242,   200,  -242,   541,   203,  -242,
    -242,   541,    93,  -242,  -242,  -242,  -242,  -242,  -242
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   184,   186,     3,     7,   191,   178,    68,   189,    73,
     190,     0,    76,    74,     0,     0,     0,     0,     0,     0,
       0,     0,   265,   185,   195,   169,   170,     0,   171,     0,
       0,   188,     0,     0,     0,    84,     6,    22,     0,    30,
      36,    49,    31,    32,    33,    69,    70,    71,    72,    34,
      23,    86,    81,    82,    83,    50,   107,   110,   114,   118,
      51,   120,   135,   139,   143,   147,   153,   159,     0,   168,
     173,     0,   177,   187,     0,    85,    77,   242,   241,    75,
     237,   236,     0,   235,     8,    96,    67,    80,    78,   117,
      88,    87,    89,     0,   133,   199,   200,     0,   193,   198,
     192,   183,     0,   194,     1,     2,     4,     5,     0,     9,
      24,     0,     0,     0,     0,    54,    55,    56,    58,    66,
      59,    57,    60,    61,    62,    64,    63,    65,    35,    38,
       0,    48,    47,     0,     0,   109,     0,   113,   129,   131,
       0,   123,   124,   127,   126,   125,   128,   119,     0,     0,
     134,     0,   138,     0,   142,   150,   151,   146,     0,   156,
     157,   152,     0,   162,   164,   166,   165,   163,   158,     0,
     167,     0,   172,     0,     0,     0,     0,   176,   180,   196,
       0,     0,   240,     0,   233,   234,     0,     0,     0,   181,
       0,     0,   203,   197,   204,   262,   201,   182,    16,    15,
       0,     0,     0,    26,    29,    25,     0,    41,    39,    45,
      40,    44,    43,    53,    46,     0,   112,     0,   116,     0,
     132,   130,     0,   122,   137,     0,   141,     0,   145,     0,
       0,   149,     0,   155,     0,   161,   174,   175,     0,     0,
     210,   256,     0,   249,   212,   229,   221,     0,   217,   213,
     179,     0,     0,     0,   102,   245,     0,    98,   239,   232,
       0,    79,    93,     0,   261,   207,   208,   202,     0,     0,
      14,     0,     0,    27,    28,     0,    37,    52,     0,   111,
     115,   121,   136,   140,   144,   148,   154,   160,   255,   254,
       0,   252,   209,   247,   248,   231,   227,   226,   228,   211,
     218,   215,   216,     0,     0,     0,     0,     0,   238,    97,
       0,     0,    91,     0,   205,   206,    18,    20,    17,    10,
      13,     0,   106,   253,   251,   246,   230,   223,   225,   224,
     220,   218,   214,   244,     0,   105,     0,     0,     0,     0,
       0,     0,     0,   260,     0,     0,     0,    42,   250,   222,
     219,   243,   103,   104,   100,     0,    99,    92,     0,     0,
       0,     0,   259,   257,   258,     0,    19,     0,     0,    95,
      90,     0,   264,   108,    21,    11,   101,    94,   263
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -242,  -242,  -242,  -242,   251,  -242,  -242,  -242,  -242,  -241,
    -242,   -31,     1,  -242,   -92,  -242,  -242,  -242,  -242,    56,
    -242,  -109,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
    -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,  -242,
     252,  -242,  -242,  -173,  -242,   -12,  -242,  -126,  -242,  -111,
    -242,    -7,  -242,  -242,   135,    -9,   -11,  -242,  -125,  -242,
    -118,  -242,  -113,  -242,   116,  -108,  -242,   114,  -134,  -242,
     108,   -58,  -242,  -242,  -242,  -242,  -242,   104,   208,  -242,
    -242,  -242,   250,  -242,  -242,  -242,  -106,  -242,   -18,  -242,
    -214,  -220,    -6,  -138,  -242,   159,  -242,  -242,   105,  -242,
    -240,   -85,    99,   -86,  -242,   -15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    32,    33,    34,    35,   201,   346,   202,   109,   200,
     318,    36,   254,   112,    38,    39,   128,   208,   210,   129,
      40,    41,   132,   130,    42,    43,    44,    45,    46,    47,
      48,    49,    88,    50,    51,    91,    52,   312,    53,   186,
      54,   307,   257,   255,   336,    55,   372,    56,   135,    57,
     137,    58,    59,   147,   148,    60,    61,   150,    62,   152,
      63,   154,    64,   157,   158,    65,   161,   162,    66,   168,
     169,    67,    68,    69,   172,    70,    71,   177,    72,    97,
     102,    73,    98,    99,   193,   194,   178,   247,   301,   302,
     248,   297,    82,    83,   185,    79,    74,    75,   242,   294,
     243,   362,   195,   363,   364,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    37,   107,    81,    85,    80,    81,   215,    80,    93,
     170,    86,    89,   196,   100,   262,    94,    95,    95,   204,
      96,    96,   213,   216,   224,     1,     2,   316,   233,     3,
       4,     5,     6,   226,    37,     7,     8,     9,     1,     2,
     228,    10,    11,   198,     5,    12,   258,    13,    14,     8,
     231,   190,    15,   324,    10,    16,   110,    17,    18,    19,
     205,    20,   190,    21,   191,    22,    23,    24,    25,    26,
      27,   250,   155,   156,    77,   191,   327,   180,   329,    23,
      24,    28,   268,   269,   181,   348,   330,   309,    29,   163,
      30,   164,   165,   166,   167,   310,   341,   192,   286,   320,
     282,    29,   209,    30,   366,   277,   279,   199,   349,   283,
      84,   235,   290,   236,   274,   212,   284,   350,    78,   190,
      31,   308,   285,   111,   311,   342,   104,   206,    87,   218,
     333,   250,   191,    31,   361,   113,   108,   223,   114,   131,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    14,   354,   291,   174,    15,   175,   355,
     133,   351,   241,   246,   176,   356,   357,   136,   241,   159,
     160,   134,   138,    81,   149,    80,   287,   139,   151,    81,
     265,    80,   171,   266,   263,   369,   370,   343,   153,   179,
     182,   183,   140,   184,   375,   188,   187,   189,   377,   207,
     197,   -12,   217,   219,   220,   221,   214,   225,   229,   227,
     249,   281,   280,   256,   259,   141,   142,   143,   144,   145,
     146,   260,   261,   190,   270,   267,   288,   289,   278,   272,
     275,   271,   292,   296,   114,   373,   293,   299,   304,   298,
     305,   300,   306,   303,   313,   198,   317,   321,    81,   325,
      80,   295,   331,   344,   334,   314,   338,   339,   315,   319,
     347,   345,   365,   358,   276,   359,   322,   367,   371,   374,
     376,    90,    92,   230,   335,   232,   234,   237,   323,   173,
     103,   241,   222,   326,   332,   252,   328,   378,   246,   211,
     264,     0,     0,     0,   337,     0,     0,     0,     0,   340,
       0,     0,     0,     0,     0,   353,    37,     0,     0,     0,
       0,     0,     0,   241,     0,     0,     0,     0,     0,   246,
       0,     0,     1,     2,     0,     0,   105,   106,     5,     6,
     360,     0,     7,     8,     9,     0,     0,    37,    10,    11,
       0,     0,    12,   368,    13,    14,     0,     0,     0,    15,
       0,     0,    16,     0,    17,    18,    19,     0,    20,     0,
      21,     0,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     0,     0,     0,    29,     0,    30,     1,     2,
       0,   352,     0,     0,     5,     6,     0,     0,     7,     8,
       9,     0,     0,     0,    10,    11,     0,     0,    12,     0,
      13,    14,     0,     0,     0,    15,     0,    31,    16,     0,
      17,    18,    19,     0,    20,     0,    21,     0,    22,    23,
      24,    25,    26,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     1,     2,
       0,    29,     0,    30,     5,     6,     0,     0,     7,     8,
       9,     0,     0,     0,    10,    11,     0,     0,    12,     0,
      13,    14,     0,     0,     0,    15,     0,     0,    16,     0,
      17,    18,    19,    31,    20,     0,    21,     0,    22,    23,
      24,    25,    26,    27,     0,     0,     1,     2,     0,     0,
       0,   203,     5,     6,    28,     0,     7,     8,     9,     0,
       0,    29,    10,    30,     0,     0,    12,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,     0,     0,     0,     0,     0,    22,    23,    24,    25,
      26,    27,     0,    31,     1,     2,     0,     0,     0,   253,
       5,     6,    28,     0,     7,     8,     9,     0,     0,    29,
      10,    30,     0,     0,    12,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,    19,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
       0,    31,     1,     2,     0,     0,     0,   273,     5,     6,
      28,     0,     7,     8,     9,     0,     0,    29,    10,    30,
       0,     0,    12,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,     0,    31,
       1,     2,     0,     0,     0,     0,     5,     6,    28,     0,
       0,     8,     0,     0,     0,    29,    10,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   238,   239,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       1,     2,     0,    29,   240,    30,     5,     6,     0,     0,
       0,     8,     0,     0,     0,     0,    10,     1,     2,     0,
       0,     0,     0,     5,     6,     0,     0,     0,     8,     0,
       0,     0,     0,    10,    19,    31,     0,     0,     0,     0,
       0,    23,    24,    25,    26,   238,   239,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    28,    22,    23,    24,
      25,    26,    27,    29,   251,    30,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     1,     2,     0,
      29,     0,    30,     5,     6,     0,     0,     0,     8,     0,
       0,     0,     0,    10,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    31,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,     1,     2,     0,     0,     0,     0,     5,
       6,     0,     0,    28,     8,     0,     0,     0,     0,    10,
      29,     0,    30,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,     0,     1,
       2,     0,    31,     0,     0,     5,     6,     0,     0,    28,
       8,     0,     0,     0,     0,    10,    29,     0,    30,   244,
       0,     0,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,   238,   239,     0,     0,    31,     0,
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
       0,    30,     0,     0,     0,     0,   295,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,     0,     1,     2,
       0,    31,     0,     0,     5,     6,     0,     0,    28,     8,
       0,     0,     0,     0,    10,    29,     0,    30,     0,     0,
       0,     0,   245,     0,     0,     0,     0,     1,     2,     0,
       0,     0,    19,     5,     6,     0,     0,     0,     8,    23,
      24,    25,    26,    10,     1,     2,     0,    31,     0,     0,
       5,     6,     0,     0,    28,     8,     0,     0,     0,     0,
      10,    29,     0,    30,     0,     0,     0,     0,    23,    24,
      25,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,    23,    24,    25,    26,     0,
      29,     0,    30,    31,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     0,     0,     0,    29,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
      12,     0,    33,    14,    16,    14,    17,   133,    17,    21,
      68,    17,    19,    99,    29,   188,    27,    29,    30,   111,
      29,    30,   131,   134,   149,     3,     4,   268,   162,     7,
       8,     9,    10,   151,    33,    13,    14,    15,     3,     4,
     153,    19,    20,     3,     9,    23,   184,    25,    26,    14,
     158,    26,    30,   293,    19,    33,     8,    35,    36,    37,
       8,    39,    26,    41,    39,    43,    44,    45,    46,    47,
      48,   177,    54,    55,     3,    39,   296,    66,   298,    44,
      45,    59,    72,    73,    73,   325,   300,   260,    66,    48,
      68,    50,    51,    52,    53,    11,    11,    72,   232,   272,
     225,    66,   114,    68,   345,   214,   217,    67,   328,   227,
       3,   169,    76,   171,   206,   130,   229,   331,   130,    26,
      98,   259,   230,    75,    40,    40,     0,    75,     3,   136,
     303,   237,    39,    98,    41,    73,    66,   148,    76,    72,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    26,    67,   241,    66,    30,    68,    72,
      41,   334,   174,   175,    74,   338,   339,    24,   180,    46,
      47,    42,    17,   184,    57,   184,   234,    22,    58,   190,
     192,   190,    49,   192,   190,   358,   359,   313,    56,    45,
      72,    17,    37,    72,   367,    73,    72,    67,   371,     3,
      69,    73,    42,    24,    37,    17,    72,    57,    56,    58,
       3,   222,   219,     3,    72,    60,    61,    62,    63,    64,
      65,    73,     3,    26,    67,    72,   238,   239,    11,    73,
      68,    77,    67,   245,    76,   361,    72,    69,    67,    73,
       5,    72,    66,    73,    17,     3,     3,     3,   259,    72,
     259,    73,    72,    68,    73,   267,    73,    73,   267,   271,
      69,    72,     3,    73,   208,    73,   278,    73,    73,    69,
      67,    20,    20,   157,   305,   161,   168,   173,   290,    71,
      30,   293,   147,   295,   302,   180,   298,   372,   300,   130,
     191,    -1,    -1,    -1,   306,    -1,    -1,    -1,    -1,   311,
      -1,    -1,    -1,    -1,    -1,   336,   305,    -1,    -1,    -1,
      -1,    -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,   331,
      -1,    -1,     3,     4,    -1,    -1,     7,     8,     9,    10,
     342,    -1,    13,    14,    15,    -1,    -1,   336,    19,    20,
      -1,    -1,    23,   355,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    37,    -1,    39,    -1,
      41,    -1,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    68,     3,     4,
      -1,     6,    -1,    -1,     9,    10,    -1,    -1,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    98,    33,    -1,
      35,    36,    37,    -1,    39,    -1,    41,    -1,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,     3,     4,
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
      -1,    -1,    73,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    37,     9,    10,    -1,    -1,    -1,    14,    44,
      45,    46,    47,    19,     3,     4,    -1,    98,    -1,    -1,
       9,    10,    -1,    -1,    59,    14,    -1,    -1,    -1,    -1,
      19,    66,    -1,    68,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    44,    45,    46,    47,    -1,
      66,    -1,    68,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     7,     8,     9,    10,    13,    14,    15,
      19,    20,    23,    25,    26,    30,    33,    35,    36,    37,
      39,    41,    43,    44,    45,    46,    47,    48,    59,    66,
      68,    98,   101,   102,   103,   104,   111,   112,   114,   115,
     120,   121,   124,   125,   126,   127,   128,   129,   130,   131,
     133,   134,   136,   138,   140,   145,   147,   149,   151,   152,
     155,   156,   158,   160,   162,   165,   168,   171,   172,   173,
     175,   176,   178,   181,   196,   197,   205,     3,   145,   195,
     155,   156,   192,   193,     3,   145,   192,     3,   132,   151,
     104,   135,   140,   145,   156,   145,   155,   179,   182,   183,
     205,    69,   180,   182,     0,     7,     8,   111,    66,   108,
       8,    75,   113,    73,    76,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   116,   119,
     123,    72,   122,    41,    42,   148,    24,   150,    17,    22,
      37,    60,    61,    62,    63,    64,    65,   153,   154,    57,
     157,    58,   159,    56,   161,    54,    55,   163,   164,    46,
      47,   166,   167,    48,    50,    51,    52,    53,   169,   170,
     171,    49,   174,   178,    66,    68,    74,   177,   186,    45,
      66,    73,    72,    17,    72,   194,   139,    72,    73,    67,
      26,    39,    72,   184,   185,   202,   203,    69,     3,    67,
     109,   105,   107,     8,   114,     8,    75,     3,   117,   145,
     118,   195,   205,   121,    72,   147,   149,    42,   151,    24,
      37,    17,   154,   156,   158,    57,   160,    58,   162,    56,
     164,   165,   167,   168,   170,   171,   171,   177,    48,    49,
      67,   145,   198,   200,    69,    73,   145,   187,   190,     3,
     186,    67,   198,     8,   112,   143,     3,   142,   193,    72,
      73,     3,   143,   192,   202,   145,   155,    72,    72,    73,
      67,    77,    73,     8,   114,    68,   119,   121,    11,   149,
     151,   156,   158,   160,   162,   165,   168,   171,   145,   145,
      76,   203,    67,    72,   199,    73,   145,   191,    73,    69,
      72,   188,   189,    73,    67,     5,    66,   141,   193,   143,
      11,    40,   137,    17,   145,   155,   109,     3,   110,   145,
     143,     3,   145,   145,   200,    72,   145,   191,   145,   191,
     190,    72,   188,   143,    73,   111,   144,   145,    73,    73,
     145,    11,    40,   147,    68,    72,   106,    69,   200,   191,
     190,   143,     6,   111,    67,    72,   143,   143,    73,    73,
     145,    41,   201,   203,   204,     3,   109,    73,   145,   143,
     143,    73,   146,   147,    69,   143,    67,   143,   201
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   102,   102,   102,   102,   103,   105,
     106,   104,   107,   104,   108,   108,   109,   109,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   113,   113,
     114,   114,   114,   114,   114,   115,   115,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   120,   120,   120,   120,
     121,   121,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   125,   126,
     126,   126,   126,   127,   128,   129,   129,   130,   131,   132,
     132,   133,   133,   133,   133,   133,   133,   134,   135,   135,
     136,   136,   136,   136,   137,   137,   139,   138,   141,   140,
     142,   142,   143,   143,   144,   144,   145,   145,   146,   147,
     147,   148,   148,   149,   149,   150,   150,   151,   151,   152,
     152,   153,   153,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   155,   156,   156,   157,   157,   158,   158,
     159,   159,   160,   160,   161,   161,   162,   162,   163,   163,
     164,   164,   165,   165,   166,   166,   167,   167,   168,   168,
     169,   169,   170,   170,   170,   170,   170,   171,   171,   172,
     172,   172,   173,   173,   174,   175,   175,   175,   176,   177,
     177,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   179,   179,   180,   181,   181,   182,   182,   183,
     183,   184,   184,   184,   184,   185,   185,   185,   185,   186,
     186,   186,   186,   186,   187,   187,   187,   187,   188,   189,
     189,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     191,   191,   192,   192,   192,   192,   193,   193,   194,   194,
     195,   195,   196,   197,   197,   197,   198,   198,   198,   198,
     199,   199,   200,   200,   200,   200,   200,   201,   201,   202,
     202,   203,   203,   204,   204,   205
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     1,     2,     0,
       0,     8,     0,     5,     3,     2,     1,     3,     3,     5,
       1,     4,     1,     1,     2,     3,     3,     4,     3,     2,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     2,
       2,     1,     4,     1,     1,     2,     3,     2,     2,     1,
       1,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       8,     5,     7,     4,     5,     4,     0,     5,     0,     7,
       4,     6,     1,     4,     2,     1,     5,     1,     1,     2,
       1,     3,     2,     2,     1,     3,     2,     2,     1,     2,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     2,     2,     1,     3,     2,     2,     1,
       3,     2,     2,     1,     3,     2,     2,     1,     3,     2,
       1,     1,     2,     1,     3,     2,     1,     1,     2,     1,
       3,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     2,     1,     2,     3,     2,     1,     1,     2,
       1,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     2,     1,     1,     3,     3,     2,     2,     3,
       2,     3,     2,     2,     3,     2,     2,     1,     1,     3,
       2,     1,     4,     3,     3,     3,     2,     2,     2,     1,
       2,     1,     3,     2,     2,     1,     1,     1,     3,     2,
       2,     1,     2,     6,     5,     3,     3,     2,     2,     1,
       3,     2,     2,     3,     2,     2,     1,     1,     1,     5,
       4,     2,     1,     3,     2,     1
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
#line 2121 "parser.cpp"
    break;

  case 3: /* file_input: ENDMARKER  */
#line 157 "parser.y"
              {
    (yyval.node) = NULL;
    }
#line 2129 "parser.cpp"
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
#line 2141 "parser.cpp"
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
#line 2154 "parser.cpp"
    break;

  case 6: /* newline_stat_rep: stmt  */
#line 178 "parser.y"
         {  (yyval.node) = (yyvsp[0].node);}
#line 2160 "parser.cpp"
    break;

  case 7: /* newline_stat_rep: NEWLINE  */
#line 179 "parser.y"
            {  
    // cout<<yylineno<<endl;
  }
#line 2168 "parser.cpp"
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
               newtab->SYMTAB_NAME = (yyvsp[0].node)->label;
               newtab->SYMSCOPE=++curr_scope;
               newtab->parent=tab;
               newtab->tab_type = FUNC;
              //  tab->childs.push_back(newtab);
               tab->childs[(yyvsp[0].node)->label] = newtab;
               tab=newtab;
             }
             else {
              cout<<"Function redeclared in line no "<< (yyvsp[0].node)->line_number<<endl;
                      //exit(1);;
             }
            // cout<<"funcname "<<$1->line_number<<endl;
          }
#line 2199 "parser.cpp"
    break;

  case 9: /* $@1: %empty  */
#line 211 "parser.y"
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
#line 2223 "parser.cpp"
    break;

  case 10: /* $@2: %empty  */
#line 230 "parser.y"
                       {
            SYMTAB* newt = new SYMTAB();
            newt = tab->parent;
            if(newt->SYMVAL.find((yyvsp[-4].node)->label)!= newt->SYMVAL.end())
            {
                newt->SYMVAL[(yyvsp[-4].node)->label].identity=FUNC;
                newt->SYMVAL[(yyvsp[-4].node)->label].scope=curr_scope;
                newt->SYMVAL[(yyvsp[-4].node)->label].line_no=(yyvsp[-4].node)->line_number;
                newt->SYMVAL[(yyvsp[-4].node)->label].name=(yyvsp[-4].node)->label;
                newt->SYMVAL[(yyvsp[-4].node)->label].type=(yyvsp[0].node)->type;
                newt->SYMVAL[(yyvsp[-4].node)->label].size=(yyvsp[-3].node)->count;
                newt->SYMVAL[(yyvsp[-4].node)->label].params=(yyvsp[-3].node)->p_f;
            }
            }
#line 2242 "parser.cpp"
    break;

  case 11: /* funcdef: funcname parameters $@1 ARROW test $@2 COLON suite  */
#line 243 "parser.y"
                        {
             Node* n = create_node("Function");
             n->children.push_back((yyvsp[-7].node));
             n->children.push_back((yyvsp[-6].node));
             n->children.push_back((yyvsp[-4].node));
             n->children.push_back((yyvsp[-3].node));
             n->children.push_back((yyvsp[-1].node));
             n->children.push_back((yyvsp[0].node));
             (yyval.node) =n;
             tab=tab->parent;
             if(tab->SYMVAL.find((yyvsp[-7].node)->label)!= tab->SYMVAL.end()){
                tab->SYMVAL[(yyvsp[-7].node)->label].identity=FUNC;
                tab->SYMVAL[(yyvsp[-7].node)->label].scope=curr_scope;
                tab->SYMVAL[(yyvsp[-7].node)->label].line_no=(yyvsp[-7].node)->line_number;
                tab->SYMVAL[(yyvsp[-7].node)->label].type=(yyvsp[-3].node)->type;
                tab->SYMVAL[(yyvsp[-7].node)->label].name=(yyvsp[-7].node)->label;
                tab->SYMVAL[(yyvsp[-7].node)->label].size=(yyvsp[-6].node)->count;
                tab->SYMVAL[(yyvsp[-7].node)->label].params=(yyvsp[-6].node)->p_f;
             }

             else{
              cout<<"error in inserting function" << endl;
              //exit(1);;
             }
              if(((yyvsp[-3].node)->type == "bool" && (yyvsp[0].node)->type == "int")||((yyvsp[-3].node)->type == "float" && (yyvsp[0].node)->type =="int"))
              {

              }
              else {
                if((yyvsp[-3].node)->type != (yyvsp[0].node)->type)cout<<"Function return ";
                check_type((yyvsp[-3].node)->type , (yyvsp[0].node)->type , (yyvsp[-7].node)->line_number);
              }
             codepush("","$ra","","goto",-1);
             arguments.clear();
         }
#line 2282 "parser.cpp"
    break;

  case 12: /* $@3: %empty  */
#line 278 "parser.y"
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
#line 2304 "parser.cpp"
    break;

  case 13: /* funcdef: funcname parameters $@3 COLON suite  */
#line 294 "parser.y"
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
#line 2342 "parser.cpp"
    break;

  case 14: /* parameters: LPAREN typedargslist RPAREN  */
#line 344 "parser.y"
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
#line 2357 "parser.cpp"
    break;

  case 15: /* parameters: LPAREN RPAREN  */
#line 354 "parser.y"
                           {
                (yyval.node) = create_node("Parameters");
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));
                (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
            }
#line 2368 "parser.cpp"
    break;

  case 16: /* typedargslist: NAME  */
#line 362 "parser.y"
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
#line 2389 "parser.cpp"
    break;

  case 17: /* typedargslist: NAME COLON datatype  */
#line 378 "parser.y"
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
                    //exit(1);;
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
#line 2420 "parser.cpp"
    break;

  case 18: /* typedargslist: NAME COMMA typedargslist  */
#line 404 "parser.y"
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
#line 2451 "parser.cpp"
    break;

  case 19: /* typedargslist: NAME COLON datatype COMMA typedargslist  */
#line 430 "parser.y"
                                                        {
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
#line 2490 "parser.cpp"
    break;

  case 20: /* datatype: NAME  */
#line 466 "parser.y"
                {
              Node *n = create_node("Datatype");
              n->children.push_back((yyvsp[0].node));
              n->label=(yyvsp[0].node)->label;
              (yyval.node) = n;
            }
#line 2501 "parser.cpp"
    break;

  case 21: /* datatype: NAME LBRACKET NAME RBRACKET  */
#line 472 "parser.y"
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
#line 2516 "parser.cpp"
    break;

  case 22: /* stmt: simple_stmt  */
#line 484 "parser.y"
                      { (yyval.node)=(yyvsp[0].node);}
#line 2522 "parser.cpp"
    break;

  case 23: /* stmt: compound_stmt  */
#line 485 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2528 "parser.cpp"
    break;

  case 24: /* simple_stmt: small_stmt NEWLINE  */
#line 488 "parser.y"
                                {
               Node* n = create_node("simple_stmt");
               n->children.push_back((yyvsp[-1].node));
               (yyval.node)=n;
               (yyval.node)->type = (yyvsp[-1].node)->type;
              //  cout<<" entered simple-stmt"<<yylineno<<<<endl;
               (yyval.node)->line_number = (yyvsp[0].node)->line_number;
            }
#line 2541 "parser.cpp"
    break;

  case 25: /* simple_stmt: small_stmt small_stmt_list NEWLINE  */
#line 496 "parser.y"
                                               {

                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
                (yyval.node)->line_number = (yyvsp[0].node)->line_number;
              }
#line 2554 "parser.cpp"
    break;

  case 26: /* simple_stmt: small_stmt SEMICOLON NEWLINE  */
#line 504 "parser.y"
                                         {
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
                (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
              }
#line 2566 "parser.cpp"
    break;

  case 27: /* simple_stmt: small_stmt small_stmt_list SEMICOLON NEWLINE  */
#line 511 "parser.y"
                                                         {
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-3].node));
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));    
                (yyval.node)->line_number = (yyvsp[-1].node)->line_number; 
                (yyval.node)=n;         
              }
#line 2579 "parser.cpp"
    break;

  case 28: /* small_stmt_list: small_stmt_list SEMICOLON small_stmt  */
#line 521 "parser.y"
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
#line 2594 "parser.cpp"
    break;

  case 29: /* small_stmt_list: SEMICOLON small_stmt  */
#line 531 "parser.y"
                                      {
                  Node* n =create_node("small_stmt_list");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                  (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
                }
#line 2606 "parser.cpp"
    break;

  case 30: /* small_stmt: expr_stmt  */
#line 539 "parser.y"
                      { (yyval.node)=(yyvsp[0].node);}
#line 2612 "parser.cpp"
    break;

  case 31: /* small_stmt: del_stmt  */
#line 540 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2618 "parser.cpp"
    break;

  case 32: /* small_stmt: pass_stmt  */
#line 541 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2624 "parser.cpp"
    break;

  case 33: /* small_stmt: flow_stmt  */
#line 542 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2630 "parser.cpp"
    break;

  case 34: /* small_stmt: global_stmt  */
#line 543 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2636 "parser.cpp"
    break;

  case 35: /* expr_stmt: testlist_star_expr expr_stmt_tail  */
#line 545 "parser.y"
                                             { 
              
              Node* n =create_node("expr_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));
              (yyval.node)=n;
              if((yyvsp[0].node)->label=="annassign"){
                if(tab->SYMVAL.find((yyvsp[-1].node)->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared "<<(yyvsp[-1].node)->label<<endl;
                  cout<<endl;
                          //exit(1);;
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
                //           //exit(1);;
                // }
              }
              else if((yyvsp[0].node)->label=="annassign_op")
              {



                //this part to check expression like self.x
                if(((yyvsp[-1].node)->label == "self") && (tab->parent->tab_type == CLS) &&((yyvsp[-1].node)->p_f.size() ==1))
                {
                  // cout<<$1->p_f.size()<<" expr_stmt "<<endl;
                  if( tab->parent->SYMVAL.find((yyvsp[-1].node)->p_f[0]->par_name)==tab->SYMVAL.end())
                  {
                    cout<<"Use of undeclared attribute for class "<< endl;
                    //exit(1);;
                  }
                  else {

                      check_type(tab->parent->SYMVAL[(yyvsp[-1].node)->p_f[0]->par_name].type ,(yyvsp[0].node)->type,(yyvsp[0].node)->line_number );
                  }
                }
                else if(tab->SYMVAL.find((yyvsp[-1].node)->label)==tab->SYMVAL.end())
                {
                  if(gt->SYMVAL.find((yyvsp[-1].node)->label)==gt->SYMVAL.end()){
                  cout<<"Use of undeclared variable " << (yyvsp[-1].node)->label <<" in line number "<<(yyvsp[0].node)->line_number<<endl;
                  //exit(1);;
                  }
                  
                }


              }
              // cout << $1->temp_var<<"inside expr_stmt "<<yylineno<<endl;
              codepush("",(yyvsp[0].node)->temp_var,"",(yyvsp[-1].node)->temp_var,-1);
             }
#line 2716 "parser.cpp"
    break;

  case 36: /* expr_stmt: testlist_star_expr  */
#line 620 "parser.y"
                                 { (yyval.node) = (yyvsp[0].node);}
#line 2722 "parser.cpp"
    break;

  case 37: /* expr_stmt_tail: COLON decl_type annassign  */
#line 623 "parser.y"
                                           {
                  (yyval.node) =create_node("annassign");
                  (yyval.node)->children.push_back((yyvsp[-2].node));
                  (yyval.node)->children.push_back((yyvsp[-1].node));
                  (yyval.node)->children.push_back((yyvsp[0].node));
                  (yyval.node)->type = (yyvsp[-1].node)->type;
                  
                  check_type((yyvsp[-1].node)->type, (yyvsp[0].node)->type, (yyvsp[-2].node)->line_number);
                  (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
                  }
#line 2737 "parser.cpp"
    break;

  case 38: /* expr_stmt_tail: annassign  */
#line 633 "parser.y"
                          {
                  (yyval.node) = (yyvsp[0].node);
               }
#line 2745 "parser.cpp"
    break;

  case 39: /* expr_stmt_tail: COLON decl_type  */
#line 636 "parser.y"
                                 {
                  (yyval.node) =create_node("annassign");
                  (yyval.node)->children.push_back((yyvsp[-1].node));
                  (yyval.node)->children.push_back((yyvsp[0].node));
                  (yyval.node)->type = (yyvsp[0].node)->type;
               }
#line 2756 "parser.cpp"
    break;

  case 40: /* expr_stmt_tail: augassign augassign_op  */
#line 642 "parser.y"
                                        {
                  Node* n =create_node("expr_stmt_tail");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                  (yyval.node)->type = (yyvsp[0].node)->type;
                  (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
                  // cout<<$$->type <<" expr_stmt_tail"<<endl;
               }
#line 2770 "parser.cpp"
    break;

  case 41: /* decl_type: NAME  */
#line 656 "parser.y"
                {
                (yyval.node) = create_node("decl_type");
                (yyval.node)->type = (yyvsp[0].node)->type;
            }
#line 2779 "parser.cpp"
    break;

  case 42: /* decl_type: NAME LBRACKET NAME RBRACKET  */
#line 660 "parser.y"
                                          {
                (yyval.node) = create_node("decl_type");
               if((yyvsp[-3].node)->label != "list"){
                  cout << "Invalid datatype at line no: " << (yyvsp[-3].node)->line_number << endl;
                  //exit(1);;
                }
                (yyval.node)->children.push_back((yyvsp[-3].node));
                (yyval.node)->children.push_back((yyvsp[-2].node));
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));
                (yyval.node)->type = (yyvsp[-3].node)->type + (yyvsp[-2].node)->label + (yyvsp[-1].node)->type + (yyvsp[0].node)->label;
            }
#line 2796 "parser.cpp"
    break;

  case 43: /* augassign_op: yield_expr  */
#line 673 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2802 "parser.cpp"
    break;

  case 44: /* augassign_op: testlist  */
#line 674 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2808 "parser.cpp"
    break;

  case 45: /* annassign: EQUAL_SIGN test  */
#line 697 "parser.y"
                           {
                  Node* n =create_node("annassign_op");
                   n->children.push_back((yyvsp[-1].node));
                   n->children.push_back((yyvsp[0].node));
                   (yyval.node) = n;
                   (yyval.node)->line_number= (yyvsp[-1].node)->line_number;
                   if((yyvsp[0].node)->type == (yyvsp[0].node)->label)
                   {
                      cout<<"Variable not declared or invalid comparison in line no "<<(yyvsp[-1].node)->line_number<<endl;
                      //exit(1);;
                   }
                   else 
                   (yyval.node)->type = (yyvsp[0].node)->type;

                   (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
}
#line 2829 "parser.cpp"
    break;

  case 46: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep COMMA  */
#line 714 "parser.y"
                                                                         {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-2].node));
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                     (yyval.node)=n;
                     (yyval.node)->line_number = (yyvsp[0].node)->line_number;
                     (yyval.node)->temp_var = (yyvsp[-2].node)->temp_var + (yyvsp[-1].node)->temp_var + ",";
                    }
#line 2843 "parser.cpp"
    break;

  case 47: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep  */
#line 723 "parser.y"
                                                                   { 
                      Node* n =create_node("testlist_star_expr");
                      n->children.push_back((yyvsp[-1].node));
                      n->children.push_back((yyvsp[0].node));
                      (yyval.node)=n;
                      (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var + (yyvsp[0].node)->temp_var;
                      (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
                    }
#line 2856 "parser.cpp"
    break;

  case 48: /* testlist_star_expr: testlist_star_expr_opt1 COMMA  */
#line 731 "parser.y"
                                                  {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                     (yyval.node)=n;
                     (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var + ",";
                    }
#line 2868 "parser.cpp"
    break;

  case 49: /* testlist_star_expr: testlist_star_expr_opt1  */
#line 738 "parser.y"
                                             { (yyval.node) = (yyvsp[0].node);}
#line 2874 "parser.cpp"
    break;

  case 50: /* testlist_star_expr_opt1: test  */
#line 742 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2880 "parser.cpp"
    break;

  case 51: /* testlist_star_expr_opt1: star_expr  */
#line 743 "parser.y"
                                   {(yyval.node)=(yyvsp[0].node);}
#line 2886 "parser.cpp"
    break;

  case 52: /* testlist_star_expr_rep: testlist_star_expr_rep COMMA testlist_star_expr_opt1  */
#line 746 "parser.y"
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
#line 2901 "parser.cpp"
    break;

  case 53: /* testlist_star_expr_rep: COMMA testlist_star_expr_opt1  */
#line 756 "parser.y"
                                  {(yyval.node) = NULL; (yyval.node)->temp_var = ","+(yyvsp[0].node)->temp_var;}
#line 2907 "parser.cpp"
    break;

  case 54: /* augassign: PLUS_EQUAL  */
#line 758 "parser.y"
                       {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "+=";}
#line 2913 "parser.cpp"
    break;

  case 55: /* augassign: MINUS_EQUAL  */
#line 759 "parser.y"
                        {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "-=";}
#line 2919 "parser.cpp"
    break;

  case 56: /* augassign: TIMES_EQUAL  */
#line 760 "parser.y"
                        {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "*=";}
#line 2925 "parser.cpp"
    break;

  case 57: /* augassign: AT_EQUAL  */
#line 761 "parser.y"
                     {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "@=";}
#line 2931 "parser.cpp"
    break;

  case 58: /* augassign: DIVIDEDBY_EQUAL  */
#line 762 "parser.y"
                            {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "/=";}
#line 2937 "parser.cpp"
    break;

  case 59: /* augassign: MODULO_EQUAL  */
#line 763 "parser.y"
                         {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "%=";}
#line 2943 "parser.cpp"
    break;

  case 60: /* augassign: BITWISE_AND_EQUAL  */
#line 764 "parser.y"
                              {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "&=";}
#line 2949 "parser.cpp"
    break;

  case 61: /* augassign: BITWISE_OR_EQUAL  */
#line 765 "parser.y"
                             {(yyval.node)=(yyvsp[0].node);  (yyval.node)->temp_op = "|=";}
#line 2955 "parser.cpp"
    break;

  case 62: /* augassign: BITWISE_XOR_EQUAL  */
#line 766 "parser.y"
                              {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "^=";}
#line 2961 "parser.cpp"
    break;

  case 63: /* augassign: SHIFT_LEFT_EQUAL  */
#line 767 "parser.y"
                             {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "<<=";}
#line 2967 "parser.cpp"
    break;

  case 64: /* augassign: SHIFT_RIGHT_EQUAL  */
#line 768 "parser.y"
                              {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = ">>=";}
#line 2973 "parser.cpp"
    break;

  case 65: /* augassign: POWER_EQUAL  */
#line 769 "parser.y"
                        {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "**=";}
#line 2979 "parser.cpp"
    break;

  case 66: /* augassign: FLOORDIV_EQUAL  */
#line 770 "parser.y"
                           {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "//=";}
#line 2985 "parser.cpp"
    break;

  case 67: /* del_stmt: DEL exprlist  */
#line 773 "parser.y"
                      {Node* n =create_node("del_stmt");
                         n->children.push_back((yyvsp[-1].node));
                         n->children.push_back((yyvsp[0].node));
                         (yyval.node)=n;
                          }
#line 2995 "parser.cpp"
    break;

  case 68: /* pass_stmt: PASS  */
#line 779 "parser.y"
               {(yyval.node)=(yyvsp[0].node);}
#line 3001 "parser.cpp"
    break;

  case 69: /* flow_stmt: break_stmt  */
#line 781 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 3007 "parser.cpp"
    break;

  case 70: /* flow_stmt: continue_stmt  */
#line 782 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 3013 "parser.cpp"
    break;

  case 71: /* flow_stmt: return_stmt  */
#line 783 "parser.y"
                       {(yyval.node)=(yyvsp[0].node); }
#line 3019 "parser.cpp"
    break;

  case 72: /* flow_stmt: yield_stmt  */
#line 784 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 3025 "parser.cpp"
    break;

  case 73: /* break_stmt: BREAK  */
#line 787 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 3031 "parser.cpp"
    break;

  case 74: /* continue_stmt: CONTINUE  */
#line 789 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 3037 "parser.cpp"
    break;

  case 75: /* return_stmt: RETURN testlist  */
#line 790 "parser.y"
                            {
              Node* n =create_node("return_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n;
              (yyval.node)->type = (yyvsp[0].node)->type;
              // cout<<gt->SYMVAL[tab->SYMTAB_NAME].type <<"hii"<<endl;
              // cout<<$2->type<<endl;
              check_type((yyval.node)->type , gt->SYMVAL[tab->SYMTAB_NAME].type,(yyvsp[-1].node)->line_number);
              codepush("",(yyvsp[0].node)->temp_var,"","pushparam",-1);
            }
#line 3053 "parser.cpp"
    break;

  case 76: /* return_stmt: RETURN  */
#line 801 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "None";}
#line 3059 "parser.cpp"
    break;

  case 77: /* yield_stmt: yield_expr  */
#line 803 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 3065 "parser.cpp"
    break;

  case 78: /* global_stmt: GLOBAL global_name_list  */
#line 804 "parser.y"
                                    {
              Node* n =create_node("global_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n; 
            }
#line 3076 "parser.cpp"
    break;

  case 79: /* global_name_list: global_name_list COMMA NAME  */
#line 811 "parser.y"
                                              {
                  Node* n =create_node("global_name_list");
                  for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
                    n->children.push_back((yyvsp[-2].node)->children[i]);
                  }
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  
                  (yyval.node)=n;
                }
#line 3091 "parser.cpp"
    break;

  case 80: /* global_name_list: NAME  */
#line 821 "parser.y"
                       { (yyval.node) = (yyvsp[0].node);}
#line 3097 "parser.cpp"
    break;

  case 81: /* compound_stmt: if_stmt  */
#line 823 "parser.y"
                       { (yyval.node)=(yyvsp[0].node);}
#line 3103 "parser.cpp"
    break;

  case 82: /* compound_stmt: while_stmt  */
#line 824 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 3109 "parser.cpp"
    break;

  case 83: /* compound_stmt: for_stmt  */
#line 825 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 3115 "parser.cpp"
    break;

  case 84: /* compound_stmt: funcdef  */
#line 826 "parser.y"
                       { (yyval.node)=(yyvsp[0].node);}
#line 3121 "parser.cpp"
    break;

  case 85: /* compound_stmt: classdef  */
#line 827 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 3127 "parser.cpp"
    break;

  case 86: /* compound_stmt: async_stmt  */
#line 828 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 3133 "parser.cpp"
    break;

  case 90: /* if_stmt: IF test COLON suite elif_stmt_rep ELSE COLON suite  */
#line 838 "parser.y"
                                                            {
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
    (yyval.node)->line_number = (yyvsp[-7].node)->line_number;
  }
#line 3151 "parser.cpp"
    break;

  case 91: /* if_stmt: IF test COLON suite elif_stmt_rep  */
#line 851 "parser.y"
                                       {

      Node* n=create_node("if_stmt");
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node)); 
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node)); 
      n->children.push_back((yyvsp[0].node));
      (yyval.node)=n;
      (yyval.node)->line_number = (yyvsp[-4].node)->line_number;

  }
#line 3168 "parser.cpp"
    break;

  case 92: /* if_stmt: IF test COLON suite ELSE COLON suite  */
#line 863 "parser.y"
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
    }
#line 3185 "parser.cpp"
    break;

  case 93: /* if_stmt: IF test COLON suite  */
#line 875 "parser.y"
                         { 
      Node* n=create_node("if_stmt");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
      (yyval.node)->line_number = (yyvsp[-3].node)->line_number;
    }
#line 3199 "parser.cpp"
    break;

  case 94: /* elif_stmt_rep: elif_stmt_rep ELIF test COLON suite  */
#line 885 "parser.y"
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
#line 3215 "parser.cpp"
    break;

  case 95: /* elif_stmt_rep: ELIF test COLON suite  */
#line 896 "parser.y"
                           { 
      Node* n=create_node("elif_stmt_rep");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
    }
#line 3228 "parser.cpp"
    break;

  case 96: /* $@4: %empty  */
#line 905 "parser.y"
                       {
      codepush("","","","loop:",-1);
        string s2 = (yyvsp[0].node)->temp_var;
        codepush("if",s2,"true","==",-1);
        loop_stack.push_back(inst_num-2); 
}
#line 3239 "parser.cpp"
    break;

  case 97: /* while_stmt: WHILE test $@4 COLON suite  */
#line 910 "parser.y"
              { 
      Node* n=create_node("while_stmt");
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[-1].node)); 
      (yyval.node)=n;
      codepush("",to_string(loop_stack[(loop_stack.size())-1]),"","goto",-1); loop_stack.pop_back();codepush("","","","end loop",-1);
  }
#line 3253 "parser.cpp"
    break;

  case 98: /* $@5: %empty  */
#line 920 "parser.y"
                                    {
        codepush("","","","loop:",-1);
        string s2 = (yyvsp[0].node)->temp_var;
        codepush("if",(yyvsp[-2].node)->label,s2,">",-1);
        codepush("+",(yyvsp[-2].node)->label,"1",(yyvsp[-2].node)->label,-1);
        loop_stack.push_back(inst_num-2);
         }
#line 3265 "parser.cpp"
    break;

  case 99: /* for_stmt: FOR exprlist IN range_func $@5 COLON suite  */
#line 926 "parser.y"
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
         //exit(1);;
      }

      (yyval.node)=n;
      codepush("",to_string(loop_stack[(loop_stack.size())-1]),"","goto",-1); loop_stack.pop_back();codepush("","","","end loop",-1);
    }
#line 3298 "parser.cpp"
    break;

  case 100: /* range_func: NAME LPAREN test RPAREN  */
#line 955 "parser.y"
                                    {
      Node* n=create_node("range_func");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var;
      if((yyvsp[-3].node)->label != "range"){
        cout<<"For loop supports only range function in line no "<<(yyvsp[-3].node)->line_number<<endl;
        //exit(1);;
      }


  }
#line 3317 "parser.cpp"
    break;

  case 101: /* range_func: NAME LPAREN test COMMA test RPAREN  */
#line 969 "parser.y"
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
         //exit(1);;
      }
      else if(((yyvsp[-3].node)->type != "int")&& ((yyvsp[-1].node)->type != "int"))
      {
        cout<<"Invalid datatype used in range function in line no "<<(yyvsp[-5].node)->line_number<<endl;
        //exit(1);;
      }
  }
#line 3341 "parser.cpp"
    break;

  case 102: /* suite: simple_stmt  */
#line 989 "parser.y"
                    {if(yybye) cout<<"LINE 462 \n"; (yyval.node) = (yyvsp[0].node);}
#line 3347 "parser.cpp"
    break;

  case 103: /* suite: NEWLINE INDENT stmt_rep DEDENT  */
#line 990 "parser.y"
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
#line 3364 "parser.cpp"
    break;

  case 104: /* stmt_rep: stmt_rep stmt  */
#line 1004 "parser.y"
                           {
            Node* n = create_node("Multi Statements");
            (yyval.node) = n;
            for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
              n->children.push_back((yyvsp[-1].node)->children[i]);
            }
            n->children.push_back((yyvsp[0].node));
            (yyval.node)->type = (yyvsp[0].node)->type;
          }
#line 3378 "parser.cpp"
    break;

  case 105: /* stmt_rep: stmt  */
#line 1013 "parser.y"
                 {(yyval.node)=(yyvsp[0].node); }
#line 3384 "parser.cpp"
    break;

  case 106: /* test: or_test IF or_test ELSE test  */
#line 1015 "parser.y"
                                    {
      Node* n = create_node("Test");
      (yyval.node) = n;
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
}
#line 3398 "parser.cpp"
    break;

  case 107: /* test: or_test  */
#line 1024 "parser.y"
         {(yyval.node)=(yyvsp[0].node);}
#line 3404 "parser.cpp"
    break;

  case 108: /* test_nocond: or_test  */
#line 1027 "parser.y"
          {(yyval.node) = (yyvsp[0].node);}
#line 3410 "parser.cpp"
    break;

  case 109: /* or_test: and_test or_test_rep  */
#line 1031 "parser.y"
  {
    Node* n = create_node("OR Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush("or",(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3424 "parser.cpp"
    break;

  case 110: /* or_test: and_test  */
#line 1040 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3430 "parser.cpp"
    break;

  case 111: /* or_test_rep: or_test_rep OR and_test  */
#line 1043 "parser.y"
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
      //exit(1);;
    }  
    (yyval.node)->type = "bool";
    string s1=new_temporary();
    codepush("or",(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 3454 "parser.cpp"
    break;

  case 112: /* or_test_rep: OR and_test  */
#line 1062 "parser.y"
               {Node* n = create_node("ORTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int"))
    {
      cout<<"Non compatible operand type used for OR operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      //exit(1);;
    }  
    (yyval.node)->temp_op = "or";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3471 "parser.cpp"
    break;

  case 113: /* and_test: not_test and_test_rep  */
#line 1076 "parser.y"
                       {
    Node* n = create_node("And Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int") || (((yyvsp[-1].node)->type != "bool") && ((yyvsp[-1].node)->type != "int") ))
    {
      cout<<"Non compatible operand type used for AND    operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      //exit(1);;
    }
    (yyval.node)->type ="bool";
    string s1=new_temporary();
    codepush("and",(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3491 "parser.cpp"
    break;

  case 114: /* and_test: not_test  */
#line 1091 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3497 "parser.cpp"
    break;

  case 115: /* and_test_rep: and_test_rep AND not_test  */
#line 1095 "parser.y"
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
      //exit(1);;
    }  
    (yyval.node)->type = "bool";
    string s1=new_temporary();
    codepush("and",(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 3521 "parser.cpp"
    break;

  case 116: /* and_test_rep: AND not_test  */
#line 1114 "parser.y"
                {Node* n = create_node("AndTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int"))
    {
      // cout<<$2->type<<endl;
      cout<<"Non compatible operand type used for AND  no operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      //exit(1);;
    }
    (yyval.node)->type = "bool";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    }
#line 3540 "parser.cpp"
    break;

  case 117: /* not_test: NOT not_test  */
#line 1132 "parser.y"
  {
    Node* n = create_node("Not Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int"))
    {
      cout<<"Non compatible operand type used for NOT operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      //exit(1);;
    }
        (yyval.node)->type = "bool";
    string s1=new_temporary();
    codepush("not",(yyvsp[0].node)->temp_var,"",s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3560 "parser.cpp"
    break;

  case 118: /* not_test: comparison  */
#line 1147 "parser.y"
               {
    (yyval.node) =(yyvsp[0].node);
  }
#line 3568 "parser.cpp"
    break;

  case 119: /* comparison: expr comparison_rep  */
#line 1152 "parser.y"
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
#line 3587 "parser.cpp"
    break;

  case 120: /* comparison: expr  */
#line 1166 "parser.y"
       {(yyval.node)=(yyvsp[0].node);}
#line 3593 "parser.cpp"
    break;

  case 121: /* comparison_rep: comparison_rep comp_op expr  */
#line 1170 "parser.y"
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
#line 3612 "parser.cpp"
    break;

  case 122: /* comparison_rep: comp_op expr  */
#line 1184 "parser.y"
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
#line 3631 "parser.cpp"
    break;

  case 123: /* comp_op: LESS_THAN  */
#line 1199 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "<";}
#line 3637 "parser.cpp"
    break;

  case 124: /* comp_op: GREATER_THAN  */
#line 1200 "parser.y"
                      {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = ">";}
#line 3643 "parser.cpp"
    break;

  case 125: /* comp_op: EQUAL  */
#line 1201 "parser.y"
               {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "==";}
#line 3649 "parser.cpp"
    break;

  case 126: /* comp_op: GREATER_THAN_OR_EQUAL  */
#line 1202 "parser.y"
                               {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = ">=";}
#line 3655 "parser.cpp"
    break;

  case 127: /* comp_op: LESS_THAN_OR_EQUAL  */
#line 1203 "parser.y"
                            {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "<=";}
#line 3661 "parser.cpp"
    break;

  case 128: /* comp_op: NOT_EQUAL  */
#line 1204 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "!=";}
#line 3667 "parser.cpp"
    break;

  case 129: /* comp_op: IN  */
#line 1205 "parser.y"
            {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "in";}
#line 3673 "parser.cpp"
    break;

  case 130: /* comp_op: NOT IN  */
#line 1206 "parser.y"
                {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3684 "parser.cpp"
    break;

  case 131: /* comp_op: IS  */
#line 1212 "parser.y"
            {(yyval.node) =(yyvsp[0].node);}
#line 3690 "parser.cpp"
    break;

  case 132: /* comp_op: IS NOT  */
#line 1213 "parser.y"
               {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3701 "parser.cpp"
    break;

  case 133: /* star_expr: TIMES expr  */
#line 1221 "parser.y"
            {
    Node* n = create_node("Star Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->temp_var="*"+(yyvsp[0].node)->temp_var;
  }
#line 3713 "parser.cpp"
    break;

  case 134: /* expr: xor_expr expr_rep  */
#line 1230 "parser.y"
                   {
    Node* n = create_node("Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3727 "parser.cpp"
    break;

  case 135: /* expr: xor_expr  */
#line 1239 "parser.y"
            {(yyval.node)=(yyvsp[0].node);}
#line 3733 "parser.cpp"
    break;

  case 136: /* expr_rep: expr_rep BITWISE_OR xor_expr  */
#line 1242 "parser.y"
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
#line 3752 "parser.cpp"
    break;

  case 137: /* expr_rep: BITWISE_OR xor_expr  */
#line 1256 "parser.y"
                       {Node* n = create_node("Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->temp_op = "|";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3764 "parser.cpp"
    break;

  case 138: /* xor_expr: and_expr xor_expr_rep  */
#line 1265 "parser.y"
                       {
    Node* n = create_node("XOR Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3778 "parser.cpp"
    break;

  case 139: /* xor_expr: and_expr  */
#line 1274 "parser.y"
            {
    (yyval.node)=(yyvsp[0].node);
  }
#line 3786 "parser.cpp"
    break;

  case 140: /* xor_expr_rep: xor_expr_rep BITWISE_XOR and_expr  */
#line 1279 "parser.y"
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
#line 3805 "parser.cpp"
    break;

  case 141: /* xor_expr_rep: BITWISE_XOR and_expr  */
#line 1293 "parser.y"
                       {Node* n = create_node("XOR Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->temp_op = "^";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3817 "parser.cpp"
    break;

  case 142: /* and_expr: shift_expr and_expr_rep  */
#line 1302 "parser.y"
                         {
    Node* n = create_node("AND Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3831 "parser.cpp"
    break;

  case 143: /* and_expr: shift_expr  */
#line 1311 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3837 "parser.cpp"
    break;

  case 144: /* and_expr_rep: and_expr_rep BITWISE_AND shift_expr  */
#line 1314 "parser.y"
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
#line 3856 "parser.cpp"
    break;

  case 145: /* and_expr_rep: BITWISE_AND shift_expr  */
#line 1328 "parser.y"
                         {Node* n = create_node("AND Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node)); 
    (yyval.node)->temp_op = "&";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;

    }
#line 3869 "parser.cpp"
    break;

  case 146: /* shift_expr: arith_expr shift_expr_rep  */
#line 1338 "parser.y"
                           {
    Node* n = create_node("Shift Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3883 "parser.cpp"
    break;

  case 147: /* shift_expr: arith_expr  */
#line 1347 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3889 "parser.cpp"
    break;

  case 148: /* shift_expr_rep: shift_expr_rep shift_expr_rep_c1 arith_expr  */
#line 1350 "parser.y"
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
#line 3907 "parser.cpp"
    break;

  case 149: /* shift_expr_rep: shift_expr_rep_c1 arith_expr  */
#line 1363 "parser.y"
                                {Node* n = create_node("Shift Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3920 "parser.cpp"
    break;

  case 150: /* shift_expr_rep_c1: SHIFT_LEFT  */
#line 1373 "parser.y"
            {
    (yyval.node) = (yyvsp[0].node);
    (yyval.node)->temp_op = "<<";
  }
#line 3929 "parser.cpp"
    break;

  case 151: /* shift_expr_rep_c1: SHIFT_RIGHT  */
#line 1377 "parser.y"
                {(yyval.node) = (yyvsp[0].node);
    (yyval.node)->temp_op = ">>";
  }
#line 3937 "parser.cpp"
    break;

  case 152: /* arith_expr: term arith_expr_rep  */
#line 1382 "parser.y"
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
#line 3962 "parser.cpp"
    break;

  case 153: /* arith_expr: term  */
#line 1402 "parser.y"
        {(yyval.node)=(yyvsp[0].node);}
#line 3968 "parser.cpp"
    break;

  case 154: /* arith_expr_rep: arith_expr_rep arith_expr_rep_c1 term  */
#line 1405 "parser.y"
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
#line 3999 "parser.cpp"
    break;

  case 155: /* arith_expr_rep: arith_expr_rep_c1 term  */
#line 1431 "parser.y"
                         {Node* n = create_node("Arithmetic Expression Rep2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    // cout<<"Arith2 "<<$$->temp_var <<" " <<$$->temp_op<<endl;
    }
#line 4013 "parser.cpp"
    break;

  case 156: /* arith_expr_rep_c1: PLUS  */
#line 1442 "parser.y"
       { (yyval.node) = (yyvsp[0].node);(yyval.node)->temp_op = "+";}
#line 4019 "parser.cpp"
    break;

  case 157: /* arith_expr_rep_c1: MINUS  */
#line 1443 "parser.y"
          { (yyval.node) = (yyvsp[0].node);(yyval.node) ->temp_op = "-";}
#line 4025 "parser.cpp"
    break;

  case 158: /* term: factor term_rep  */
#line 1446 "parser.y"
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
#line 4052 "parser.cpp"
    break;

  case 159: /* term: factor  */
#line 1468 "parser.y"
         {(yyval.node)=(yyvsp[0].node);}
#line 4058 "parser.cpp"
    break;

  case 160: /* term_rep: term_rep term_rep_c1 factor  */
#line 1471 "parser.y"
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
      //exit(1);;
      
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
#line 4094 "parser.cpp"
    break;

  case 161: /* term_rep: term_rep_c1 factor  */
#line 1502 "parser.y"
                       { Node* n = create_node("TERM Rep");
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
    (yyval.node)->line_number = (yyvsp[0].node)->line_number;
    (yyval.node)->type = (yyvsp[0].node)->type;
    if(((yyvsp[0].node)->type != "bool")&&((yyvsp[0].node)->type != "float")&&((yyvsp[0].node)->type != "int"))
    {
      cout<<"Invalid datatype used for operator "<<(yyvsp[-1].node)->label<<" in line no "<<(yyvsp[-1].node)->line_number<<endl;
      // //exit(1);;
    }
    if((yyvsp[-1].node)->type == "/")
     (yyval.node)->type = "float";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    }
#line 4115 "parser.cpp"
    break;

  case 162: /* term_rep_c1: TIMES  */
#line 1519 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "*";}
#line 4121 "parser.cpp"
    break;

  case 163: /* term_rep_c1: AT  */
#line 1520 "parser.y"
                 { (yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "@";}
#line 4127 "parser.cpp"
    break;

  case 164: /* term_rep_c1: DIVIDEDBY  */
#line 1521 "parser.y"
                        { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "/"; }
#line 4133 "parser.cpp"
    break;

  case 165: /* term_rep_c1: MODULO  */
#line 1522 "parser.y"
                     { (yyval.node) =(yyvsp[0].node);   (yyval.node)->temp_op = "%";}
#line 4139 "parser.cpp"
    break;

  case 166: /* term_rep_c1: FLOORDIV  */
#line 1523 "parser.y"
                       { (yyval.node) =(yyvsp[0].node);    (yyval.node)->temp_op = "//";}
#line 4145 "parser.cpp"
    break;

  case 167: /* factor: factor_c1 factor  */
#line 1526 "parser.y"
                   {
    Node* n = create_node("Factor");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[0].node)->line_number;
    (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->temp_op=(yyvsp[-1].node)->temp_op;
    (yyval.node)->temp_var=(yyvsp[0].node)->temp_var;
  }
#line 4160 "parser.cpp"
    break;

  case 168: /* factor: power  */
#line 1536 "parser.y"
          { if(yybye) cout<<"factor power: "<<endl;(yyval.node) = (yyvsp[0].node);}
#line 4166 "parser.cpp"
    break;

  case 169: /* factor_c1: PLUS  */
#line 1538 "parser.y"
                 { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "+";}
#line 4172 "parser.cpp"
    break;

  case 170: /* factor_c1: MINUS  */
#line 1539 "parser.y"
                  { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "-"; }
#line 4178 "parser.cpp"
    break;

  case 171: /* factor_c1: BITWISE_NOT  */
#line 1540 "parser.y"
                        { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "~";}
#line 4184 "parser.cpp"
    break;

  case 172: /* power: atom_expr power_opt  */
#line 1543 "parser.y"
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
#line 4200 "parser.cpp"
    break;

  case 173: /* power: atom_expr  */
#line 1554 "parser.y"
             {
    (yyval.node) = (yyvsp[0].node);
    if(yybye) cout<<"atom_expr power: "<<endl;(yyval.node)=(yyvsp[0].node);
  }
#line 4209 "parser.cpp"
    break;

  case 174: /* power_opt: POWER factor  */
#line 1560 "parser.y"
               {
    Node* n = create_node("Power Opt");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = "**";
  }
#line 4223 "parser.cpp"
    break;

  case 175: /* atom_expr: await_opt atom trailer_rep  */
#line 1571 "parser.y"
                            {
    Node* n = create_node("Atom Expression1");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    n->type = (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
    (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var;
  }
#line 4237 "parser.cpp"
    break;

  case 176: /* atom_expr: atom trailer_rep  */
#line 1580 "parser.y"
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

        //exit(1);;
      }
      else if(p.size() < (yyvsp[0].node)->p_f.size())
      {
        cout<<"Greater number of arguments for function call "<< (yyvsp[-1].node)->label <<" in line number "<< (yyvsp[-1].node)->line_number<<endl;
                //exit(1);;
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
                      //exit(1);;
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

         //exit(1);;
        }
        else if(p.size() < (yyvsp[0].node)->p_f.size())
        {
          cout<<"Greater number of arguments for constructor call "<< (yyvsp[-1].node)->label <<" in line number "<< (yyvsp[-1].node)->line_number<<endl;
                //exit(1);;
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
                      //exit(1);;
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
            //exit(1);;
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
                  //exit(1);;
                }
          }

        }
      }
      
      else{

        cout<<"Undeclared Function in line no : "<< (yyvsp[-1].node)->line_number<<endl;
        //exit(1);;
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
          //exit(1);;
        }
        (yyval.node)->type = tab->parent->SYMVAL[(yyvsp[0].node)->type].type;
      }
      else 
      {

        if(gt->childs[(yyvsp[-1].node)->type]->SYMVAL.find((yyvsp[0].node)->type) == gt->childs[(yyvsp[-1].node)->type]->SYMVAL.end()) 
        {
          cout<<"Undefined property "<<(yyvsp[0].node)->type<<" for class "<<(yyvsp[-1].node)->type<<" used by object "<<(yyvsp[-1].node)->label<<"in line no "<<(yyvsp[-1].node)->line_number<<endl;
          //exit(1);;
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
      } 
    }
    if((yyvsp[-1].node)->type=="None")
    codepush("call",(yyvsp[-1].node)->label,"","",-1);
    else{
      codepush(" ","call",(yyvsp[-1].node)->label,"",-1);
    }
    arguments.clear();
  }
#line 4435 "parser.cpp"
    break;

  case 177: /* atom_expr: atom  */
#line 1773 "parser.y"
       {
    (yyval.node) = (yyvsp[0].node);
    // cout<<"atom " <<$$->type<<endl;
    if(yybye) cout<<"atom_expr atom: "<<endl; 
  }
#line 4445 "parser.cpp"
    break;

  case 178: /* await_opt: AWAIT  */
#line 1779 "parser.y"
                  {
  (yyval.node) = (yyvsp[0].node);
}
#line 4453 "parser.cpp"
    break;

  case 179: /* trailer_rep: trailer_rep trailer  */
#line 1784 "parser.y"
                      {
    if(yybye) cout<<"trailer_rep: "<<endl;
    Node* n = create_node("Trailer Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));
    cout<<" Datatypes like in line number "<<(yyvsp[0].node)->line_number <<" not supported for now "<<endl;
    //exit(1);;

  }
#line 4470 "parser.cpp"
    break;

  case 180: /* trailer_rep: trailer  */
#line 1796 "parser.y"
            { 
    (yyval.node) =(yyvsp[0].node);
  }
#line 4478 "parser.cpp"
    break;

  case 181: /* atom: LPAREN atom_opt1 RPAREN  */
#line 1800 "parser.y"
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
#line 4495 "parser.cpp"
    break;

  case 182: /* atom: LBRACKET atom_opt2 RBRACKET  */
#line 1812 "parser.y"
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
#line 4512 "parser.cpp"
    break;

  case 183: /* atom: LBRACKET RBRACKET  */
#line 1824 "parser.y"
                         { 
        if(yybye) cout<<"atom : "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        (yyval.node)->line_number = (yyvsp[-1].node)->line_number;

      }
#line 4526 "parser.cpp"
    break;

  case 184: /* atom: NAME  */
#line 1833 "parser.y"
              { (yyval.node) =(yyvsp[0].node);
                if(tab->SYMVAL.find((yyvsp[0].node)->label)!=tab->SYMVAL.end())
                {
                  // cout<<"Already declared"<<endl;
                  (yyval.node)->type = tab->SYMVAL[(yyvsp[0].node)->label].type;
                  (yyval.node)->temp_var = tab->SYMVAL[(yyvsp[0].node)->label].temp_var;
                }
                else if(gt->SYMVAL.find((yyvsp[0].node)->label)!=gt->SYMVAL.end())
                {
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
#line 4564 "parser.cpp"
    break;

  case 185: /* atom: NUMBER  */
#line 1866 "parser.y"
                { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "int";
                  (yyval.node)->temp_var= new_temporary();
                  codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);  }
#line 4572 "parser.cpp"
    break;

  case 186: /* atom: FLOAT  */
#line 1869 "parser.y"
              {(yyval.node) = (yyvsp[0].node); (yyval.node)->type = "float";
                (yyval.node)->temp_var= new_temporary();
                codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4580 "parser.cpp"
    break;

  case 187: /* atom: string_rep  */
#line 1872 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "string";
                      (yyval.node)->temp_var= new_temporary();
                      codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4588 "parser.cpp"
    break;

  case 188: /* atom: TRIPLEDOT  */
#line 1875 "parser.y"
                   { (yyval.node) =(yyvsp[0].node);}
#line 4594 "parser.cpp"
    break;

  case 189: /* atom: NONE  */
#line 1876 "parser.y"
              { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "None";}
#line 4600 "parser.cpp"
    break;

  case 190: /* atom: TRUE_TOKEN  */
#line 1877 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";
                      (yyval.node)->temp_var= new_temporary();
                      codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4608 "parser.cpp"
    break;

  case 191: /* atom: FALSE_TOKEN  */
#line 1880 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";
                      (yyval.node)->temp_var= new_temporary();
                      codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4616 "parser.cpp"
    break;

  case 192: /* atom_opt1: yield_expr  */
#line 1884 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 4622 "parser.cpp"
    break;

  case 193: /* atom_opt1: testlist_comp  */
#line 1885 "parser.y"
                         {(yyval.node) = (yyvsp[0].node); if(yybye) cout<<"atom_opt1 testlist_comp: "<<endl;}
#line 4628 "parser.cpp"
    break;

  case 194: /* atom_opt2: testlist_comp  */
#line 1887 "parser.y"
                         {(yyval.node) =(yyvsp[0].node);}
#line 4634 "parser.cpp"
    break;

  case 195: /* string_rep: STRING  */
#line 1890 "parser.y"
         { (yyval.node) = (yyvsp[0].node);}
#line 4640 "parser.cpp"
    break;

  case 196: /* string_rep: string_rep STRING  */
#line 1891 "parser.y"
                      {
    Node* n = create_node("String Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));    
    (yyval.node)->line_number= (yyvsp[-1].node)->line_number;
  }
#line 4654 "parser.cpp"
    break;

  case 197: /* testlist_comp: testlist_comp_c1 testlist_comp_c2  */
#line 1902 "parser.y"
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
#line 4670 "parser.cpp"
    break;

  case 198: /* testlist_comp: testlist_comp_c1  */
#line 1913 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 4676 "parser.cpp"
    break;

  case 199: /* testlist_comp_c1: test  */
#line 1916 "parser.y"
         {(yyval.node) = (yyvsp[0].node);}
#line 4682 "parser.cpp"
    break;

  case 200: /* testlist_comp_c1: star_expr  */
#line 1917 "parser.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 4688 "parser.cpp"
    break;

  case 201: /* testlist_comp_c2: comp_for  */
#line 1920 "parser.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 4694 "parser.cpp"
    break;

  case 202: /* testlist_comp_c2: testlist_comp_c2_rep COMMA  */
#line 1921 "parser.y"
                              {
    Node* n = create_node("Testlist Comp C2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[-1].node)->type;
    (yyval.node)->line_number = (yyvsp[0].node)->line_number;
  }
#line 4707 "parser.cpp"
    break;

  case 203: /* testlist_comp_c2: COMMA  */
#line 1929 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 4713 "parser.cpp"
    break;

  case 204: /* testlist_comp_c2: testlist_comp_c2_rep  */
#line 1930 "parser.y"
                        {(yyval.node) =(yyvsp[0].node);}
#line 4719 "parser.cpp"
    break;

  case 205: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA test  */
#line 1934 "parser.y"
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
#line 4735 "parser.cpp"
    break;

  case 206: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA star_expr  */
#line 1945 "parser.y"
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
#line 4751 "parser.cpp"
    break;

  case 207: /* testlist_comp_c2_rep: COMMA test  */
#line 1956 "parser.y"
             {
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 4763 "parser.cpp"
    break;

  case 208: /* testlist_comp_c2_rep: COMMA star_expr  */
#line 1963 "parser.y"
                    { 
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 4775 "parser.cpp"
    break;

  case 209: /* trailer: LPAREN arglist RPAREN  */
#line 1972 "parser.y"
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
#line 4793 "parser.cpp"
    break;

  case 210: /* trailer: LPAREN RPAREN  */
#line 1985 "parser.y"
                {
    Node* n = create_node("Trailer2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
    (yyval.node)->category = "Func";
  }
#line 4806 "parser.cpp"
    break;

  case 211: /* trailer: LBRACKET subscriptlist RBRACKET  */
#line 1993 "parser.y"
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
#line 4823 "parser.cpp"
    break;

  case 212: /* trailer: LBRACKET RBRACKET  */
#line 2005 "parser.y"
                    { 
    Node* n = create_node("Trailer4");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
  }
#line 4835 "parser.cpp"
    break;

  case 213: /* trailer: DOT NAME  */
#line 2012 "parser.y"
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
#line 4852 "parser.cpp"
    break;

  case 214: /* subscriptlist: subscript COMMA_subscript_rep COMMA_opt  */
#line 2026 "parser.y"
                                         {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4865 "parser.cpp"
    break;

  case 215: /* subscriptlist: subscript COMMA_opt  */
#line 2034 "parser.y"
                      {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4876 "parser.cpp"
    break;

  case 216: /* subscriptlist: subscript COMMA_subscript_rep  */
#line 2040 "parser.y"
                                {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4887 "parser.cpp"
    break;

  case 217: /* subscriptlist: subscript  */
#line 2046 "parser.y"
             {(yyval.node) =(yyvsp[0].node);}
#line 4893 "parser.cpp"
    break;

  case 218: /* COMMA_opt: COMMA  */
#line 2049 "parser.y"
        { (yyval.node) = (yyvsp[0].node);}
#line 4899 "parser.cpp"
    break;

  case 219: /* COMMA_subscript_rep: COMMA_subscript_rep COMMA subscript  */
#line 2053 "parser.y"
                                      {
    Node* n = create_node("Comma Subscript rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4913 "parser.cpp"
    break;

  case 220: /* COMMA_subscript_rep: COMMA subscript  */
#line 2062 "parser.y"
                   {
    Node* n = create_node("COMMA subscript rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4924 "parser.cpp"
    break;

  case 221: /* subscript: test  */
#line 2070 "parser.y"
       { (yyval.node) = (yyvsp[0].node);}
#line 4930 "parser.cpp"
    break;

  case 222: /* subscript: test COLON test sliceop  */
#line 2071 "parser.y"
                           {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4944 "parser.cpp"
    break;

  case 223: /* subscript: COLON test sliceop  */
#line 2080 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4956 "parser.cpp"
    break;

  case 224: /* subscript: test COLON sliceop  */
#line 2087 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4968 "parser.cpp"
    break;

  case 225: /* subscript: test COLON test  */
#line 2094 "parser.y"
                   {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4980 "parser.cpp"
    break;

  case 226: /* subscript: COLON sliceop  */
#line 2101 "parser.y"
                 {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4991 "parser.cpp"
    break;

  case 227: /* subscript: COLON test  */
#line 2107 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 5002 "parser.cpp"
    break;

  case 228: /* subscript: test COLON  */
#line 2113 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 5013 "parser.cpp"
    break;

  case 229: /* subscript: COLON  */
#line 2119 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 5019 "parser.cpp"
    break;

  case 230: /* sliceop: COLON test  */
#line 2121 "parser.y"
                    {
    Node* n = create_node("Slice OP");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 5030 "parser.cpp"
    break;

  case 231: /* sliceop: COLON  */
#line 2127 "parser.y"
       {(yyval.node) = (yyvsp[0].node);}
#line 5036 "parser.cpp"
    break;

  case 232: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep COMMA  */
#line 2129 "parser.y"
                                                        {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 5048 "parser.cpp"
    break;

  case 233: /* exprlist: expr_star_expr COMMA  */
#line 2136 "parser.y"
                      {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 5059 "parser.cpp"
    break;

  case 234: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep  */
#line 2142 "parser.y"
                                         {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 5070 "parser.cpp"
    break;

  case 235: /* exprlist: expr_star_expr  */
#line 2148 "parser.y"
                {(yyval.node) =(yyvsp[0].node);}
#line 5076 "parser.cpp"
    break;

  case 236: /* expr_star_expr: expr  */
#line 2150 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 5082 "parser.cpp"
    break;

  case 237: /* expr_star_expr: star_expr  */
#line 2151 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 5088 "parser.cpp"
    break;

  case 238: /* COMMA_expr_star_expr_rep: COMMA_expr_star_expr_rep COMMA expr_star_expr  */
#line 2154 "parser.y"
                                               {
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 5102 "parser.cpp"
    break;

  case 239: /* COMMA_expr_star_expr_rep: COMMA expr_star_expr  */
#line 2163 "parser.y"
                       { 
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 5113 "parser.cpp"
    break;

  case 240: /* testlist: test COMMA  */
#line 2178 "parser.y"
             {
    Node* n = create_node("Testlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 5124 "parser.cpp"
    break;

  case 241: /* testlist: test  */
#line 2190 "parser.y"
        {(yyval.node) =(yyvsp[0].node);}
#line 5130 "parser.cpp"
    break;

  case 242: /* class_name: CLASS NAME  */
#line 2207 "parser.y"
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
               SYMTAB* newtab=new SYMTAB();
               newtab->SYMTAB_NAME = (yyvsp[0].node)->label;
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
                      //exit(1);;
             }
}
#line 5160 "parser.cpp"
    break;

  case 243: /* classdef: class_name LPAREN arglist RPAREN COLON suite  */
#line 2232 "parser.y"
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
#line 5191 "parser.cpp"
    break;

  case 244: /* classdef: class_name LPAREN RPAREN COLON suite  */
#line 2258 "parser.y"
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
#line 5229 "parser.cpp"
    break;

  case 245: /* classdef: class_name COLON suite  */
#line 2291 "parser.y"
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
#line 5266 "parser.cpp"
    break;

  case 246: /* arglist: argument COMMA_argument_rep COMMA  */
#line 2325 "parser.y"
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
#line 5290 "parser.cpp"
    break;

  case 247: /* arglist: argument COMMA  */
#line 2344 "parser.y"
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
#line 5306 "parser.cpp"
    break;

  case 248: /* arglist: argument COMMA_argument_rep  */
#line 2355 "parser.y"
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
#line 5329 "parser.cpp"
    break;

  case 249: /* arglist: argument  */
#line 2373 "parser.y"
           {(yyval.node) =(yyvsp[0].node);
    Param* temp = new Param();
    temp->par_type=(yyvsp[0].node)->type;
    temp->par_name=(yyvsp[0].node)->label;
        (yyval.node)->p_f.push_back(temp);
    arguments.push_back(make_tuple((yyvsp[0].node)->label,(yyvsp[0].node)->temp_var, (yyvsp[0].node)->type,0,0));
  }
#line 5341 "parser.cpp"
    break;

  case 250: /* COMMA_argument_rep: COMMA_argument_rep COMMA argument  */
#line 2382 "parser.y"
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
#line 5363 "parser.cpp"
    break;

  case 251: /* COMMA_argument_rep: COMMA argument  */
#line 2399 "parser.y"
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
#line 5379 "parser.cpp"
    break;

  case 252: /* argument: test comp_for  */
#line 2412 "parser.y"
               {
    Node* n = create_node("Argument");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 5390 "parser.cpp"
    break;

  case 253: /* argument: test EQUAL_SIGN test  */
#line 2418 "parser.y"
                         {
     Node* n = create_node("Argument");
     (yyval.node) = n;
     n->children.push_back((yyvsp[-2].node));
     n->children.push_back((yyvsp[-1].node));
     codepush("", (yyvsp[0].node)->temp_var, "", (yyvsp[-2].node)->temp_var, -1);
     (yyval.node)->temp_var = (yyvsp[-2].node)->temp_var;
  }
#line 5403 "parser.cpp"
    break;

  case 254: /* argument: POWER test  */
#line 2426 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));      
  }
#line 5414 "parser.cpp"
    break;

  case 255: /* argument: TIMES test  */
#line 2432 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));    
  }
#line 5425 "parser.cpp"
    break;

  case 256: /* argument: test  */
#line 2438 "parser.y"
       {(yyval.node) =(yyvsp[0].node); }
#line 5431 "parser.cpp"
    break;

  case 257: /* comp_iter: comp_for  */
#line 2440 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 5437 "parser.cpp"
    break;

  case 258: /* comp_iter: comp_if  */
#line 2441 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 5443 "parser.cpp"
    break;

  case 259: /* sync_comp_for: FOR exprlist IN or_test comp_iter  */
#line 2443 "parser.y"
                                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-4].node));
          n->children.push_back((yyvsp[-3].node));  
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));   
          n->children.push_back((yyvsp[0].node));   
}
#line 5457 "parser.cpp"
    break;

  case 260: /* sync_comp_for: FOR exprlist IN or_test  */
#line 2452 "parser.y"
                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-3].node));
          n->children.push_back((yyvsp[-2].node));  
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 5470 "parser.cpp"
    break;

  case 261: /* comp_for: ASYNC sync_comp_for  */
#line 2461 "parser.y"
                             { 
          Node* n = create_node("Comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));  }
#line 5480 "parser.cpp"
    break;

  case 262: /* comp_for: sync_comp_for  */
#line 2466 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 5486 "parser.cpp"
    break;

  case 263: /* comp_if: IF test_nocond comp_iter  */
#line 2468 "parser.y"
                                  {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
}
#line 5498 "parser.cpp"
    break;

  case 264: /* comp_if: IF test_nocond  */
#line 2475 "parser.y"
                        {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 5509 "parser.cpp"
    break;

  case 265: /* yield_expr: YIELD  */
#line 2481 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 5515 "parser.cpp"
    break;


#line 5519 "parser.cpp"

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

#line 2490 "parser.y"



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
        //exit(1);; 
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

