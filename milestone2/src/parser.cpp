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
  cout<<"Datatype mismatch in line no "<< x<<endl;
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
unordered_map<int,SYMTAB*> tablist;

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


#line 168 "parser.cpp"

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
  YYSYMBOL_if_stmt = 135,                  /* if_stmt  */
  YYSYMBOL_elif_stmt_rep = 136,            /* elif_stmt_rep  */
  YYSYMBOL_while_stmt = 137,               /* while_stmt  */
  YYSYMBOL_138_3 = 138,                    /* $@3  */
  YYSYMBOL_for_stmt = 139,                 /* for_stmt  */
  YYSYMBOL_140_4 = 140,                    /* $@4  */
  YYSYMBOL_range_func = 141,               /* range_func  */
  YYSYMBOL_suite = 142,                    /* suite  */
  YYSYMBOL_stmt_rep = 143,                 /* stmt_rep  */
  YYSYMBOL_test = 144,                     /* test  */
  YYSYMBOL_test_nocond = 145,              /* test_nocond  */
  YYSYMBOL_or_test = 146,                  /* or_test  */
  YYSYMBOL_or_test_rep = 147,              /* or_test_rep  */
  YYSYMBOL_and_test = 148,                 /* and_test  */
  YYSYMBOL_and_test_rep = 149,             /* and_test_rep  */
  YYSYMBOL_not_test = 150,                 /* not_test  */
  YYSYMBOL_comparison = 151,               /* comparison  */
  YYSYMBOL_comparison_rep = 152,           /* comparison_rep  */
  YYSYMBOL_comp_op = 153,                  /* comp_op  */
  YYSYMBOL_star_expr = 154,                /* star_expr  */
  YYSYMBOL_expr = 155,                     /* expr  */
  YYSYMBOL_expr_rep = 156,                 /* expr_rep  */
  YYSYMBOL_xor_expr = 157,                 /* xor_expr  */
  YYSYMBOL_xor_expr_rep = 158,             /* xor_expr_rep  */
  YYSYMBOL_and_expr = 159,                 /* and_expr  */
  YYSYMBOL_and_expr_rep = 160,             /* and_expr_rep  */
  YYSYMBOL_shift_expr = 161,               /* shift_expr  */
  YYSYMBOL_shift_expr_rep = 162,           /* shift_expr_rep  */
  YYSYMBOL_shift_expr_rep_c1 = 163,        /* shift_expr_rep_c1  */
  YYSYMBOL_arith_expr = 164,               /* arith_expr  */
  YYSYMBOL_arith_expr_rep = 165,           /* arith_expr_rep  */
  YYSYMBOL_arith_expr_rep_c1 = 166,        /* arith_expr_rep_c1  */
  YYSYMBOL_term = 167,                     /* term  */
  YYSYMBOL_term_rep = 168,                 /* term_rep  */
  YYSYMBOL_term_rep_c1 = 169,              /* term_rep_c1  */
  YYSYMBOL_factor = 170,                   /* factor  */
  YYSYMBOL_factor_c1 = 171,                /* factor_c1  */
  YYSYMBOL_power = 172,                    /* power  */
  YYSYMBOL_power_opt = 173,                /* power_opt  */
  YYSYMBOL_atom_expr = 174,                /* atom_expr  */
  YYSYMBOL_await_opt = 175,                /* await_opt  */
  YYSYMBOL_trailer_rep = 176,              /* trailer_rep  */
  YYSYMBOL_atom = 177,                     /* atom  */
  YYSYMBOL_atom_opt1 = 178,                /* atom_opt1  */
  YYSYMBOL_atom_opt2 = 179,                /* atom_opt2  */
  YYSYMBOL_string_rep = 180,               /* string_rep  */
  YYSYMBOL_testlist_comp = 181,            /* testlist_comp  */
  YYSYMBOL_testlist_comp_c1 = 182,         /* testlist_comp_c1  */
  YYSYMBOL_testlist_comp_c2 = 183,         /* testlist_comp_c2  */
  YYSYMBOL_testlist_comp_c2_rep = 184,     /* testlist_comp_c2_rep  */
  YYSYMBOL_trailer = 185,                  /* trailer  */
  YYSYMBOL_subscriptlist = 186,            /* subscriptlist  */
  YYSYMBOL_COMMA_opt = 187,                /* COMMA_opt  */
  YYSYMBOL_COMMA_subscript_rep = 188,      /* COMMA_subscript_rep  */
  YYSYMBOL_subscript = 189,                /* subscript  */
  YYSYMBOL_sliceop = 190,                  /* sliceop  */
  YYSYMBOL_exprlist = 191,                 /* exprlist  */
  YYSYMBOL_expr_star_expr = 192,           /* expr_star_expr  */
  YYSYMBOL_COMMA_expr_star_expr_rep = 193, /* COMMA_expr_star_expr_rep  */
  YYSYMBOL_testlist = 194,                 /* testlist  */
  YYSYMBOL_class_name = 195,               /* class_name  */
  YYSYMBOL_classdef = 196,                 /* classdef  */
  YYSYMBOL_arglist = 197,                  /* arglist  */
  YYSYMBOL_COMMA_argument_rep = 198,       /* COMMA_argument_rep  */
  YYSYMBOL_argument = 199,                 /* argument  */
  YYSYMBOL_comp_iter = 200,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 201,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 202,                 /* comp_for  */
  YYSYMBOL_comp_if = 203,                  /* comp_if  */
  YYSYMBOL_yield_expr = 204                /* yield_expr  */
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
#define YYLAST   1173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  105
/* YYNRULES -- Number of rules.  */
#define YYNRULES  264
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  378

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
       0,   154,   154,   159,   165,   172,   180,   181,   185,   214,
     214,   267,   267,   332,   342,   350,   360,   386,   402,   439,
     445,   457,   458,   461,   468,   476,   483,   493,   503,   511,
     512,   513,   514,   515,   517,   574,   577,   586,   589,   595,
     608,   612,   625,   626,   649,   665,   674,   682,   689,   693,
     694,   697,   707,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   724,   730,   732,   733,
     734,   735,   738,   740,   741,   749,   751,   752,   759,   769,
     771,   772,   773,   774,   775,   776,   779,   782,   783,   786,
     799,   811,   823,   833,   844,   853,   853,   868,   868,   903,
     917,   937,   938,   952,   961,   963,   972,   975,   978,   988,
     991,  1010,  1024,  1039,  1042,  1062,  1079,  1095,  1100,  1114,
    1118,  1132,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1160,  1161,  1169,  1178,  1187,  1190,  1204,  1213,  1222,  1227,
    1241,  1250,  1259,  1262,  1276,  1286,  1295,  1298,  1311,  1321,
    1325,  1330,  1350,  1353,  1378,  1389,  1390,  1393,  1415,  1418,
    1431,  1440,  1441,  1442,  1443,  1444,  1447,  1455,  1457,  1458,
    1459,  1462,  1473,  1479,  1490,  1499,  1618,  1624,  1629,  1638,
    1642,  1654,  1667,  1676,  1709,  1712,  1715,  1718,  1719,  1720,
    1723,  1727,  1728,  1730,  1733,  1734,  1745,  1754,  1757,  1758,
    1761,  1762,  1770,  1771,  1774,  1786,  1797,  1804,  1813,  1826,
    1834,  1846,  1853,  1862,  1870,  1876,  1882,  1885,  1889,  1898,
    1906,  1907,  1916,  1923,  1930,  1937,  1943,  1949,  1955,  1957,
    1963,  1965,  1972,  1978,  1984,  1986,  1987,  1990,  1999,  2014,
    2026,  2043,  2068,  2103,  2136,  2170,  2189,  2200,  2217,  2226,
    2243,  2256,  2262,  2270,  2276,  2282,  2284,  2285,  2287,  2296,
    2305,  2310,  2312,  2319,  2325
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
  "async_stmt_content", "if_stmt", "elif_stmt_rep", "while_stmt", "$@3",
  "for_stmt", "$@4", "range_func", "suite", "stmt_rep", "test",
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

#define YYPACT_NINF (-248)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-12)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,    48,  1029,  -248,  1058,    57,  1029,  1058,    93,  1029,
      46,  1029,  -248,  -248,  -248,  -248,  -248,  1075,  -248,   648,
     708,  -248,    39,   319,    66,  -248,  -248,  -248,    32,  -248,
     652,    51,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,    94,    97,   123,  -248,
    -248,   207,    92,    95,    96,    19,    40,    90,  1075,  -248,
     101,    80,    62,   106,    60,  -248,  -248,  -248,    82,  -248,
    -248,  -248,   139,    85,  -248,  -248,  -248,  -248,    86,  -248,
    -248,  -248,  -248,    88,  -248,  -248,  -248,    99,  -248,    36,
    -248,  -248,    91,  -248,  -248,  -248,  -248,  -248,    50,    98,
    -248,   427,    41,   156,  1029,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
     860,   877,   100,  1029,  1029,   122,  1029,   143,  -248,   137,
     165,  -248,  -248,  -248,  -248,  -248,  -248,   207,  1075,  1075,
     128,  1075,   130,  1075,   135,  -248,  -248,    19,  1075,  -248,
    -248,    40,  1075,  -248,  -248,  -248,  -248,  -248,    90,  1075,
    -248,  1075,  -248,    62,   571,   754,   183,    62,  -248,  -248,
     631,   475,  -248,   189,  1058,   121,   124,   191,   475,  -248,
    1058,   169,   877,  -248,   131,  -248,  -248,  -248,    72,  -248,
     129,   136,   127,  -248,  -248,  -248,   523,   138,   140,  -248,
    -248,  -248,  -248,  -248,   877,   196,  -248,  1029,  -248,  1029,
    -248,  -248,  1075,  -248,  -248,  1075,  -248,  1075,  -248,  1075,
    1075,  -248,  1075,  -248,  1075,  -248,  -248,    62,  1029,  1029,
    -248,    17,   150,   147,  -248,   937,   149,   154,   173,  -248,
    -248,   164,   179,   242,  -248,  -248,   185,  -248,  -248,  1058,
     475,  -248,    81,   232,  -248,  -248,  -248,   877,   249,   250,
    -248,  1029,   475,  -248,  -248,   253,  -248,  -248,  1029,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    1029,  -248,  -248,   800,   188,  1029,   184,  -248,   937,  -248,
     983,  -248,   190,   475,   192,   379,  1029,   200,  -248,  -248,
     202,  1029,    87,  1029,  -248,  -248,  -248,   208,   205,   206,
    -248,   211,  -248,  -248,  -248,   800,  -248,  -248,   184,  -248,
    -248,   983,  -248,  -248,   475,  -248,   195,    28,   475,   475,
     209,   212,  1029,    38,   261,   249,   475,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  1029,  -248,  -248,   475,   475,
     214,  1029,  -248,  -248,  -248,   215,  -248,  -248,   222,  -248,
    -248,   475,    38,  -248,  -248,  -248,  -248,  -248
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   183,   185,     3,     7,   190,   177,    67,   188,    72,
     189,     0,    75,    73,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   184,   194,   168,   169,     0,   170,     0,
       0,   187,     0,     0,     0,    83,     6,    21,     0,    29,
      35,    48,    30,    31,    32,    68,    69,    70,    71,    33,
      22,    85,    80,    81,    82,    49,   106,   109,   113,   117,
      50,   119,   134,   138,   142,   146,   152,   158,     0,   167,
     172,     0,   176,   186,     0,    84,    76,   241,   240,    74,
     236,   235,     0,   234,     8,    95,    66,    79,    77,   116,
      87,    86,    88,     0,   132,   198,   199,     0,   192,   197,
     191,   182,     0,   193,     1,     2,     4,     5,     0,     9,
      23,     0,     0,     0,     0,    53,    54,    55,    57,    65,
      58,    56,    59,    60,    61,    63,    62,    64,    34,    37,
       0,    47,    46,     0,     0,   108,     0,   112,   128,   130,
       0,   122,   123,   126,   125,   124,   127,   118,     0,     0,
     133,     0,   137,     0,   141,   149,   150,   145,     0,   155,
     156,   151,     0,   161,   163,   165,   164,   162,   157,     0,
     166,     0,   171,     0,     0,     0,     0,   175,   179,   195,
       0,     0,   239,     0,   232,   233,     0,     0,     0,   180,
       0,     0,   202,   196,   203,   261,   200,   181,    15,    14,
       0,     0,     0,    25,    28,    24,     0,    40,    38,    44,
      39,    43,    42,    52,    45,     0,   111,     0,   115,     0,
     131,   129,     0,   121,   136,     0,   140,     0,   144,     0,
       0,   148,     0,   154,     0,   160,   173,   174,     0,     0,
     209,   255,     0,   248,   211,   228,   220,     0,   216,   212,
     178,     0,     0,     0,   101,   244,     0,    97,   238,   231,
       0,    78,    92,     0,   260,   206,   207,   201,     0,     0,
      13,     0,     0,    26,    27,     0,    36,    51,     0,   110,
     114,   120,   135,   139,   143,   147,   153,   159,   254,   253,
       0,   251,   208,   246,   247,   230,   226,   225,   227,   210,
     217,   214,   215,     0,     0,     0,     0,     0,   237,    96,
       0,     0,    90,     0,   204,   205,    17,    19,    16,     0,
      12,     0,   105,   252,   250,   245,   229,   222,   224,   223,
     219,   217,   213,   243,     0,   104,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,    41,   249,   221,
     218,   242,   102,   103,    99,     0,    98,    91,     0,     0,
       0,     0,   258,   256,   257,     0,    18,    10,     0,    94,
      89,     0,   263,   107,    20,   100,    93,   262
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -248,  -248,  -248,  -248,   270,  -248,  -248,  -248,  -244,  -248,
     -31,     1,  -248,   -96,  -248,  -248,  -248,  -248,    83,  -248,
    -109,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,   272,
    -248,  -248,  -169,  -248,   -12,  -248,  -126,  -248,  -111,  -248,
      -7,  -248,  -248,   148,    -9,   -11,  -248,  -121,  -248,  -118,
    -248,  -115,  -248,   141,  -108,  -248,   142,  -135,  -248,   132,
     -58,  -248,  -248,  -248,  -248,  -248,   134,   225,  -248,  -248,
    -248,   267,  -248,  -248,  -248,  -106,  -248,    -1,  -248,  -246,
    -216,    -6,  -140,  -248,   172,  -248,  -248,   144,  -248,  -247,
     -68,   117,   -86,  -248,   -15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    32,    33,    34,    35,   201,   202,   109,   200,   318,
      36,   254,   112,    38,    39,   128,   208,   210,   129,    40,
      41,   132,   130,    42,    43,    44,    45,    46,    47,    48,
      49,    88,    50,    51,    91,    52,   312,    53,   186,    54,
     307,   257,   255,   336,    55,   372,    56,   135,    57,   137,
      58,    59,   147,   148,    60,    61,   150,    62,   152,    63,
     154,    64,   157,   158,    65,   161,   162,    66,   168,   169,
      67,    68,    69,   172,    70,    71,   177,    72,    97,   102,
      73,    98,    99,   193,   194,   178,   247,   301,   302,   248,
     297,    82,    83,   185,    79,    74,    75,   242,   294,   243,
     362,   195,   363,   364,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    37,   107,    81,    85,    80,    81,   215,    80,    93,
     170,    86,    89,   196,   100,   204,    94,    95,    95,   262,
      96,    96,   213,   216,   316,     1,     2,   233,   224,     3,
       4,     5,     6,   226,    37,     7,     8,     9,   228,   104,
     110,    10,    11,   190,   258,    12,   324,    13,    14,   205,
     231,    77,    15,   198,   330,    16,   191,    17,    18,    19,
      84,    20,   190,    21,   190,    22,    23,    24,    25,    26,
      27,   250,    14,   155,   156,   191,    15,   191,   348,   361,
     327,    28,   329,     1,     2,   350,   159,   160,    29,     5,
      30,   309,   310,   290,     8,   354,    87,   286,   341,    10,
     355,   366,   209,   320,   282,   277,   279,   111,   192,   283,
     274,   235,   349,   236,   284,   212,   206,   199,    78,   308,
      31,   311,   285,   131,    23,    24,   180,   342,   174,   218,
     175,   250,   108,   181,   333,   133,   176,   223,   163,   134,
     164,   165,   166,   167,   268,   269,    29,   136,    30,   149,
     171,   179,   153,   151,   182,   291,   183,   184,   187,   207,
     197,   188,   241,   246,   217,   351,   189,   219,   241,   356,
     357,   -11,   214,    81,   220,    80,   287,   367,    31,    81,
     265,    80,   221,   266,   263,   225,   249,   343,   227,   369,
     370,   229,   256,   259,   261,   190,   270,   260,     1,     2,
     272,   352,   376,   267,     5,     6,   275,   278,     7,     8,
       9,   281,   280,   271,    10,    11,   114,   292,    12,   293,
      13,    14,   298,   299,   138,    15,   288,   289,    16,   139,
      17,    18,    19,   296,    20,   373,    21,   303,    22,    23,
      24,    25,    26,    27,   140,   300,   304,   305,    81,   313,
      80,   306,   198,   317,    28,   314,   321,   295,   315,   319,
     325,    29,   331,    30,   365,   334,   322,   141,   142,   143,
     144,   145,   146,   338,   335,   339,   344,   345,   323,   346,
     347,   241,   358,   326,   374,   359,   328,   371,   246,   375,
      90,   276,    92,    31,   337,   222,   173,   103,   230,   340,
     234,   332,   211,   232,   377,   353,    37,   237,   264,     0,
       0,     0,     0,   241,     0,     0,     0,     0,     0,   246,
       0,     0,     1,     2,   252,     0,   105,   106,     5,     6,
     360,     0,     7,     8,     9,     0,     0,    37,    10,    11,
       0,     0,    12,   368,    13,    14,     0,     0,     0,    15,
       0,     0,    16,     0,    17,    18,    19,     0,    20,     0,
      21,     0,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     1,     2,     0,    29,     0,    30,     5,     6,
       0,     0,     7,     8,     9,     0,     0,     0,    10,    11,
       0,     0,    12,     0,    13,    14,     0,     0,     0,    15,
       0,     0,    16,     0,    17,    18,    19,    31,    20,     0,
      21,     0,    22,    23,    24,    25,    26,    27,     0,     0,
       1,     2,     0,     0,     0,   203,     5,     6,    28,     0,
       7,     8,     9,     0,     0,    29,    10,    30,     0,     0,
      12,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,     0,     0,     0,     0,     0,
      22,    23,    24,    25,    26,    27,     0,    31,     1,     2,
       0,     0,     0,   253,     5,     6,    28,     0,     7,     8,
       9,     0,     0,    29,    10,    30,     0,     0,    12,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,     0,    31,     1,     2,     0,     0,
       0,   273,     5,     6,    28,     0,     7,     8,     9,     0,
       0,    29,    10,    30,     0,     0,    12,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,     0,     0,     0,     0,     0,    22,    23,    24,    25,
      26,    27,     0,    31,     1,     2,     0,     0,     0,     0,
       5,     6,    28,     0,     0,     8,     0,     0,     0,    29,
      10,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   238,
     239,    31,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     1,     2,     0,    29,   240,    30,
       5,     6,     0,     0,     0,     8,     0,     0,     0,     0,
      10,     1,     2,     0,     0,     0,     0,     5,     6,     0,
       0,     0,     8,     0,     0,     0,     0,    10,    19,    31,
       0,     0,     0,     0,     0,    23,    24,    25,    26,   238,
     239,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      28,    22,    23,    24,    25,    26,    27,    29,   251,    30,
       0,     0,     0,     0,     0,     0,     0,    28,     0,     0,
       0,     1,     2,     0,    29,     0,    30,     5,     6,     0,
       0,     0,     8,     0,     0,   113,     0,    10,   114,    31,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     0,     0,    19,    31,     0,     0,     0,
       0,     0,    23,    24,    25,    26,    27,     1,     2,     0,
       0,     0,     0,     5,     6,     0,     0,    28,     8,     0,
       0,     0,     0,    10,    29,     0,    30,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,     0,     1,     2,     0,    31,     0,     0,     5,
       6,     0,     0,    28,     8,     0,     0,     0,     0,    10,
      29,     0,    30,   244,     0,     0,     0,   245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,   238,   239,
       0,     0,    31,     0,     0,     0,     0,     0,     0,    28,
       0,     0,     0,     1,     2,     0,    29,     0,    30,     5,
       6,     0,     0,     0,     8,     0,     0,     0,     0,    10,
       1,     2,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     8,     0,     0,     0,     0,    10,    19,    31,     0,
       0,     0,     0,    22,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    28,
       0,    23,    24,    25,    26,    27,    29,     0,    30,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       1,     2,     0,    29,     0,    30,     5,     6,     0,     0,
       0,     8,     0,     0,     0,     0,    10,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    31,     0,     0,     0,     0,
       0,    23,    24,    25,    26,     0,     1,     2,     0,     0,
       0,     0,     5,     6,     0,     0,    28,     8,     0,     0,
       0,     0,    10,    29,     0,    30,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,     0,     1,     2,     0,    31,     0,     0,     5,     6,
       0,     0,    28,     8,     0,     0,     0,     0,    10,    29,
       0,    30,     0,     0,     0,     0,   245,     0,     0,     0,
       0,     1,     2,     0,     0,     0,    19,     5,     6,     0,
       0,     0,     8,    23,    24,    25,    26,    10,     1,     2,
       0,    31,     0,     0,     5,     6,     0,     0,    28,     8,
       0,     0,     0,     0,    10,    29,     0,    30,     0,     0,
       0,     0,    23,    24,    25,    26,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,    23,
      24,    25,    26,     0,    29,     0,    30,    31,     0,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,     0,
       0,    29,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
      12,     0,    33,    14,    16,    14,    17,   133,    17,    21,
      68,    17,    19,    99,    29,   111,    27,    29,    30,   188,
      29,    30,   131,   134,   268,     3,     4,   162,   149,     7,
       8,     9,    10,   151,    33,    13,    14,    15,   153,     0,
       8,    19,    20,    26,   184,    23,   293,    25,    26,     8,
     158,     3,    30,     3,   300,    33,    39,    35,    36,    37,
       3,    39,    26,    41,    26,    43,    44,    45,    46,    47,
      48,   177,    26,    54,    55,    39,    30,    39,   325,    41,
     296,    59,   298,     3,     4,   331,    46,    47,    66,     9,
      68,   260,    11,    76,    14,    67,     3,   232,    11,    19,
      72,   345,   114,   272,   225,   214,   217,    75,    72,   227,
     206,   169,   328,   171,   229,   130,    75,    67,   130,   259,
      98,    40,   230,    72,    44,    45,    66,    40,    66,   136,
      68,   237,    66,    73,   303,    41,    74,   148,    48,    42,
      50,    51,    52,    53,    72,    73,    66,    24,    68,    57,
      49,    45,    56,    58,    72,   241,    17,    72,    72,     3,
      69,    73,   174,   175,    42,   334,    67,    24,   180,   338,
     339,    73,    72,   184,    37,   184,   234,   346,    98,   190,
     192,   190,    17,   192,   190,    57,     3,   313,    58,   358,
     359,    56,     3,    72,     3,    26,    67,    73,     3,     4,
      73,     6,   371,    72,     9,    10,    68,    11,    13,    14,
      15,   222,   219,    77,    19,    20,    76,    67,    23,    72,
      25,    26,    73,    69,    17,    30,   238,   239,    33,    22,
      35,    36,    37,   245,    39,   361,    41,    73,    43,    44,
      45,    46,    47,    48,    37,    72,    67,     5,   259,    17,
     259,    66,     3,     3,    59,   267,     3,    73,   267,   271,
      72,    66,    72,    68,     3,    73,   278,    60,    61,    62,
      63,    64,    65,    73,   305,    73,    68,    72,   290,    73,
      69,   293,    73,   295,    69,    73,   298,    73,   300,    67,
      20,   208,    20,    98,   306,   147,    71,    30,   157,   311,
     168,   302,   130,   161,   372,   336,   305,   173,   191,    -1,
      -1,    -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,   331,
      -1,    -1,     3,     4,   180,    -1,     7,     8,     9,    10,
     342,    -1,    13,    14,    15,    -1,    -1,   336,    19,    20,
      -1,    -1,    23,   355,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    37,    -1,    39,    -1,
      41,    -1,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,     3,     4,    -1,    66,    -1,    68,     9,    10,
      -1,    -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      -1,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    35,    36,    37,    98,    39,    -1,
      41,    -1,    43,    44,    45,    46,    47,    48,    -1,    -1,
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
      -1,     8,     9,    10,    59,    -1,    13,    14,    15,    -1,
      -1,    66,    19,    68,    -1,    -1,    23,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    -1,    98,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    59,    -1,    -1,    14,    -1,    -1,    -1,    66,
      19,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,     3,     4,    -1,    66,    67,    68,
       9,    10,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      19,     3,     4,    -1,    -1,    -1,    -1,     9,    10,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    37,    98,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      59,    43,    44,    45,    46,    47,    48,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,     3,     4,    -1,    66,    -1,    68,     9,    10,    -1,
      -1,    -1,    14,    -1,    -1,    73,    -1,    19,    76,    98,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    -1,    37,    98,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,     3,     4,    -1,
      -1,    -1,    -1,     9,    10,    -1,    -1,    59,    14,    -1,
      -1,    -1,    -1,    19,    66,    -1,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,     3,     4,    -1,    98,    -1,    -1,     9,
      10,    -1,    -1,    59,    14,    -1,    -1,    -1,    -1,    19,
      66,    -1,    68,    69,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,     3,     4,    -1,    66,    -1,    68,     9,
      10,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,
       3,     4,    -1,    -1,    -1,    -1,     9,    10,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    19,    37,    98,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    59,
      -1,    44,    45,    46,    47,    48,    66,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
       3,     4,    -1,    66,    -1,    68,     9,    10,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    19,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    98,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,     3,     4,    -1,    -1,
      -1,    -1,     9,    10,    -1,    -1,    59,    14,    -1,    -1,
      -1,    -1,    19,    66,    -1,    68,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,     3,     4,    -1,    98,    -1,    -1,     9,    10,
      -1,    -1,    59,    14,    -1,    -1,    -1,    -1,    19,    66,
      -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,     3,     4,    -1,    -1,    -1,    37,     9,    10,    -1,
      -1,    -1,    14,    44,    45,    46,    47,    19,     3,     4,
      -1,    98,    -1,    -1,     9,    10,    -1,    -1,    59,    14,
      -1,    -1,    -1,    -1,    19,    66,    -1,    68,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    44,
      45,    46,    47,    -1,    66,    -1,    68,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
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
      68,    98,   101,   102,   103,   104,   110,   111,   113,   114,
     119,   120,   123,   124,   125,   126,   127,   128,   129,   130,
     132,   133,   135,   137,   139,   144,   146,   148,   150,   151,
     154,   155,   157,   159,   161,   164,   167,   170,   171,   172,
     174,   175,   177,   180,   195,   196,   204,     3,   144,   194,
     154,   155,   191,   192,     3,   144,   191,     3,   131,   150,
     104,   134,   139,   144,   155,   144,   154,   178,   181,   182,
     204,    69,   179,   181,     0,     7,     8,   110,    66,   107,
       8,    75,   112,    73,    76,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   115,   118,
     122,    72,   121,    41,    42,   147,    24,   149,    17,    22,
      37,    60,    61,    62,    63,    64,    65,   152,   153,    57,
     156,    58,   158,    56,   160,    54,    55,   162,   163,    46,
      47,   165,   166,    48,    50,    51,    52,    53,   168,   169,
     170,    49,   173,   177,    66,    68,    74,   176,   185,    45,
      66,    73,    72,    17,    72,   193,   138,    72,    73,    67,
      26,    39,    72,   183,   184,   201,   202,    69,     3,    67,
     108,   105,   106,     8,   113,     8,    75,     3,   116,   144,
     117,   194,   204,   120,    72,   146,   148,    42,   150,    24,
      37,    17,   153,   155,   157,    57,   159,    58,   161,    56,
     163,   164,   166,   167,   169,   170,   170,   176,    48,    49,
      67,   144,   197,   199,    69,    73,   144,   186,   189,     3,
     185,    67,   197,     8,   111,   142,     3,   141,   192,    72,
      73,     3,   142,   191,   201,   144,   154,    72,    72,    73,
      67,    77,    73,     8,   113,    68,   118,   120,    11,   148,
     150,   155,   157,   159,   161,   164,   167,   170,   144,   144,
      76,   202,    67,    72,   198,    73,   144,   190,    73,    69,
      72,   187,   188,    73,    67,     5,    66,   140,   192,   142,
      11,    40,   136,    17,   144,   154,   108,     3,   109,   144,
     142,     3,   144,   144,   199,    72,   144,   190,   144,   190,
     189,    72,   187,   142,    73,   110,   143,   144,    73,    73,
     144,    11,    40,   146,    68,    72,    73,    69,   199,   190,
     189,   142,     6,   110,    67,    72,   142,   142,    73,    73,
     144,    41,   200,   202,   203,     3,   108,   142,   144,   142,
     142,    73,   145,   146,    69,    67,   142,   200
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
     135,   135,   135,   136,   136,   138,   137,   140,   139,   141,
     141,   142,   142,   143,   143,   144,   144,   145,   146,   146,
     147,   147,   148,   148,   149,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   154,   155,   155,   156,   156,   157,   157,   158,
     158,   159,   159,   160,   160,   161,   161,   162,   162,   163,
     163,   164,   164,   165,   165,   166,   166,   167,   167,   168,
     168,   169,   169,   169,   169,   169,   170,   170,   171,   171,
     171,   172,   172,   173,   174,   174,   174,   175,   176,   176,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   178,   178,   179,   180,   180,   181,   181,   182,   182,
     183,   183,   183,   183,   184,   184,   184,   184,   185,   185,
     185,   185,   185,   186,   186,   186,   186,   187,   188,   188,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   190,
     190,   191,   191,   191,   191,   192,   192,   193,   193,   194,
     194,   195,   196,   196,   196,   197,   197,   197,   197,   198,
     198,   199,   199,   199,   199,   199,   200,   200,   201,   201,
     202,   202,   203,   203,   204
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
       1,     1,     1,     1,     1,     1,     2,     1,     1,     8,
       5,     7,     4,     5,     4,     0,     5,     0,     7,     4,
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
       1,     2,     6,     5,     3,     3,     2,     2,     1,     3,
       2,     2,     3,     2,     2,     1,     1,     1,     5,     4,
       2,     1,     3,     2,     1
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
#line 154 "parser.y"
                               {
    (yyval.node) = root;
    root->children.push_back((yyvsp[-1].node));
    root->children.push_back((yyvsp[0].node));
  }
#line 2110 "parser.cpp"
    break;

  case 3: /* file_input: ENDMARKER  */
#line 159 "parser.y"
              {
    (yyval.node) = NULL;
    }
#line 2118 "parser.cpp"
    break;

  case 4: /* newline_stat_rep: newline_stat_rep NEWLINE  */
#line 165 "parser.y"
                             {
    Node* n = create_node("newline_stat_rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
  }
#line 2130 "parser.cpp"
    break;

  case 5: /* newline_stat_rep: newline_stat_rep stmt  */
#line 172 "parser.y"
                          { 
    Node* n = create_node("newline_stat_rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));
  }
#line 2143 "parser.cpp"
    break;

  case 6: /* newline_stat_rep: stmt  */
#line 180 "parser.y"
         {  (yyval.node) = (yyvsp[0].node);}
#line 2149 "parser.cpp"
    break;

  case 7: /* newline_stat_rep: NEWLINE  */
#line 181 "parser.y"
            {  
    // cout<<yylineno<<endl;
  }
#line 2157 "parser.cpp"
    break;

  case 8: /* funcname: DEF NAME  */
#line 185 "parser.y"
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
               
               newtab->tag=(yyvsp[0].node)->label;
               newtab->SYMSCOPE=++curr_scope;
               newtab->parent=tab;
              //  tab->childs.push_back(newtab);
               tab->childs[(yyvsp[0].node)->label] = newtab;
               tab=newtab;
               tablist[curr_scope]=tab;
             }
             else {
              cout<<"Function redeclared in line no "<< (yyvsp[0].node)->line_number<<endl;
                      exit(1);
             }
            // cout<<"funcname "<<$1->line_number<<endl;
          }
#line 2189 "parser.cpp"
    break;

  case 9: /* $@1: %empty  */
#line 214 "parser.y"
                               {
             codepush("begin",(yyvsp[-1].node)->label,"","",-1);
          
        for(int i=0;i<arguments.size();i++) { 
        string s1 = get<0>(arguments[i]);
        codepush("","popparam","",tab->SYMVAL[s1].temp_var,-1);
        codepush("",tab->SYMVAL[s1].temp_var,"",get<0>(arguments[i]),-1);}}
#line 2201 "parser.cpp"
    break;

  case 10: /* funcdef: funcname parameters $@1 ARROW test COLON suite  */
#line 220 "parser.y"
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
                // tab-SYMVAL[$1->labe].params = 
                //int g_index;
                //int reg_name;
                for(int i=0;i<(yyvsp[-5].node)->children.size();i++){
                  Node* t=(yyvsp[-5].node)->children[i];
                  string temp=t->label;
                   if(temp!="[" && temp!="]"){
                      tab->SYMVAL[(yyvsp[-6].node)->label].params=(yyvsp[-5].node)->p_f;
                   }
                }              
             }

             else{
              cout<<"error in inserting function" << endl;
              exit(1);
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
#line 2253 "parser.cpp"
    break;

  case 11: /* $@2: %empty  */
#line 267 "parser.y"
                            {
             codepush("begin",(yyvsp[-1].node)->label,"","",-1);
          
        for(int i=0;i<arguments.size();i++) { 
        string s1 = get<0>(arguments[i]);
        codepush("","popparam","",tab->SYMVAL[s1].temp_var,-1);
        codepush("",tab->SYMVAL[s1].temp_var,"",get<0>(arguments[i]),-1);}}
#line 2265 "parser.cpp"
    break;

  case 12: /* funcdef: funcname parameters $@2 COLON suite  */
#line 273 "parser.y"
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
#line 2312 "parser.cpp"
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
#line 2327 "parser.cpp"
    break;

  case 14: /* parameters: LPAREN RPAREN  */
#line 342 "parser.y"
                           {
                (yyval.node) = create_node("Parameters");
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));
                (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
            }
#line 2338 "parser.cpp"
    break;

  case 15: /* typedargslist: NAME  */
#line 350 "parser.y"
                     {
                  Node *n = create_node("Typedargslist1");
                  n->children.push_back((yyvsp[0].node));
                  Param* temp=new Param();
                  temp->par_name=(yyvsp[0].node)->label;
                  n->p_f.push_back(temp);
                  n->count=1;
                  (yyval.node)=n;
                  arguments.push_back(make_tuple((yyvsp[0].node)->label,"",(yyvsp[0].node)->type,0,0));
                  }
#line 2353 "parser.cpp"
    break;

  case 16: /* typedargslist: NAME COLON datatype  */
#line 360 "parser.y"
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
                    exit(1);
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
#line 2384 "parser.cpp"
    break;

  case 17: /* typedargslist: NAME COMMA typedargslist  */
#line 386 "parser.y"
                                         {
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
#line 2405 "parser.cpp"
    break;

  case 18: /* typedargslist: NAME COLON datatype COMMA typedargslist  */
#line 402 "parser.y"
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
#line 2445 "parser.cpp"
    break;

  case 19: /* datatype: NAME  */
#line 439 "parser.y"
                {
              Node *n = create_node("Datatype");
              n->children.push_back((yyvsp[0].node));
              n->label=(yyvsp[0].node)->label;
              (yyval.node) = n;
            }
#line 2456 "parser.cpp"
    break;

  case 20: /* datatype: NAME LBRACKET NAME RBRACKET  */
#line 445 "parser.y"
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
#line 2471 "parser.cpp"
    break;

  case 21: /* stmt: simple_stmt  */
#line 457 "parser.y"
                      { (yyval.node)=(yyvsp[0].node);}
#line 2477 "parser.cpp"
    break;

  case 22: /* stmt: compound_stmt  */
#line 458 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2483 "parser.cpp"
    break;

  case 23: /* simple_stmt: small_stmt NEWLINE  */
#line 461 "parser.y"
                                {
               Node* n = create_node("simple_stmt");
               n->children.push_back((yyvsp[-1].node));
               (yyval.node)=n;
               (yyval.node)->type = (yyvsp[-1].node)->type;
               (yyval.node)->line_number = (yyvsp[0].node)->line_number;
            }
#line 2495 "parser.cpp"
    break;

  case 24: /* simple_stmt: small_stmt small_stmt_list NEWLINE  */
#line 468 "parser.y"
                                               {

                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
                (yyval.node)->line_number = (yyvsp[0].node)->line_number;
              }
#line 2508 "parser.cpp"
    break;

  case 25: /* simple_stmt: small_stmt SEMICOLON NEWLINE  */
#line 476 "parser.y"
                                         {
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));
                (yyval.node)=n;
                (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
              }
#line 2520 "parser.cpp"
    break;

  case 26: /* simple_stmt: small_stmt small_stmt_list SEMICOLON NEWLINE  */
#line 483 "parser.y"
                                                         {
                Node* n =create_node("simple_stmt");
                n->children.push_back((yyvsp[-3].node));
                n->children.push_back((yyvsp[-2].node));
                n->children.push_back((yyvsp[-1].node));    
                (yyval.node)->line_number = (yyvsp[-1].node)->line_number; 
                (yyval.node)=n;         
              }
#line 2533 "parser.cpp"
    break;

  case 27: /* small_stmt_list: small_stmt_list SEMICOLON small_stmt  */
#line 493 "parser.y"
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
#line 2548 "parser.cpp"
    break;

  case 28: /* small_stmt_list: SEMICOLON small_stmt  */
#line 503 "parser.y"
                                      {
                  Node* n =create_node("small_stmt_list");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                  (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
                }
#line 2560 "parser.cpp"
    break;

  case 29: /* small_stmt: expr_stmt  */
#line 511 "parser.y"
                      { (yyval.node)=(yyvsp[0].node);}
#line 2566 "parser.cpp"
    break;

  case 30: /* small_stmt: del_stmt  */
#line 512 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2572 "parser.cpp"
    break;

  case 31: /* small_stmt: pass_stmt  */
#line 513 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2578 "parser.cpp"
    break;

  case 32: /* small_stmt: flow_stmt  */
#line 514 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2584 "parser.cpp"
    break;

  case 33: /* small_stmt: global_stmt  */
#line 515 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2590 "parser.cpp"
    break;

  case 34: /* expr_stmt: testlist_star_expr expr_stmt_tail  */
#line 517 "parser.y"
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
                  tab->SYMVAL[(yyvsp[-1].node)->label].temp_var = (yyvsp[0].node)->temp_var;
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
              else if((yyvsp[0].node)->label=="annassign_op")
              {
                // cout<<$1->label<<endl;
                if(tab->SYMVAL.find((yyvsp[-1].node)->label)==tab->SYMVAL.end())
                {
                  if(gt->SYMVAL.find((yyvsp[-1].node)->label)==gt->SYMVAL.end()){
                  cout<<"Use of undeclared variable " <<" in line number "<<(yyvsp[0].node)->line_number<<endl;
                  exit(1);}
                }


              }
            //   cout << $1->temp_var<<"inside expr_stmt"<<endl;
              codepush("",(yyvsp[0].node)->temp_var,"",(yyvsp[-1].node)->temp_var,-1);
                // cout<<$1->type <<" hii "<<$2->type<<endl;
             }
#line 2652 "parser.cpp"
    break;

  case 35: /* expr_stmt: testlist_star_expr  */
#line 574 "parser.y"
                                 { (yyval.node) = (yyvsp[0].node);}
#line 2658 "parser.cpp"
    break;

  case 36: /* expr_stmt_tail: COLON decl_type annassign  */
#line 577 "parser.y"
                                           {
                  (yyval.node) =create_node("annassign");
                  (yyval.node)->children.push_back((yyvsp[-2].node));
                  (yyval.node)->children.push_back((yyvsp[-1].node));
                  (yyval.node)->children.push_back((yyvsp[0].node));
                  (yyval.node)->type = (yyvsp[-1].node)->type;
                  check_type((yyvsp[-1].node)->type, (yyvsp[0].node)->type, (yyvsp[-2].node)->line_number);
                  (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
                  }
#line 2672 "parser.cpp"
    break;

  case 37: /* expr_stmt_tail: annassign  */
#line 586 "parser.y"
                          {
                  (yyval.node) = (yyvsp[0].node);
               }
#line 2680 "parser.cpp"
    break;

  case 38: /* expr_stmt_tail: COLON decl_type  */
#line 589 "parser.y"
                                 {
                  (yyval.node) =create_node("annassign");
                  (yyval.node)->children.push_back((yyvsp[-1].node));
                  (yyval.node)->children.push_back((yyvsp[0].node));
                  (yyval.node)->type = (yyvsp[0].node)->type;
               }
#line 2691 "parser.cpp"
    break;

  case 39: /* expr_stmt_tail: augassign augassign_op  */
#line 595 "parser.y"
                                        {
                  Node* n =create_node("expr_stmt_tail");
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  (yyval.node)=n;
                  (yyval.node)->type = (yyvsp[0].node)->type;
                  // cout<<$$->type <<" expr_stmt_tail"<<endl;
               }
#line 2704 "parser.cpp"
    break;

  case 40: /* decl_type: NAME  */
#line 608 "parser.y"
                {
                (yyval.node) = create_node("decl_type");
                (yyval.node)->type = (yyvsp[0].node)->type;
            }
#line 2713 "parser.cpp"
    break;

  case 41: /* decl_type: NAME LBRACKET NAME RBRACKET  */
#line 612 "parser.y"
                                          {
                (yyval.node) = create_node("decl_type");
               if((yyvsp[-3].node)->label != "list"){
                  cout << "Invalid datatype at line no: " << (yyvsp[-3].node)->line_number << endl;
                  exit(1);
                }
                (yyval.node)->children.push_back((yyvsp[-3].node));
                (yyval.node)->children.push_back((yyvsp[-2].node));
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));
                (yyval.node)->type = (yyvsp[-3].node)->type + (yyvsp[-2].node)->label + (yyvsp[-1].node)->type + (yyvsp[0].node)->label;
            }
#line 2730 "parser.cpp"
    break;

  case 42: /* augassign_op: yield_expr  */
#line 625 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2736 "parser.cpp"
    break;

  case 43: /* augassign_op: testlist  */
#line 626 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2742 "parser.cpp"
    break;

  case 44: /* annassign: EQUAL_SIGN test  */
#line 649 "parser.y"
                           {
                  Node* n =create_node("annassign_op");
                   n->children.push_back((yyvsp[-1].node));
                   n->children.push_back((yyvsp[0].node));
                   (yyval.node) = n;
                   (yyval.node)->line_number= (yyvsp[-1].node)->line_number;
                   if((yyvsp[0].node)->type == (yyvsp[0].node)->label)
                   {
                      cout<<"Variable not declared or invalid comparison in line no "<<(yyvsp[-1].node)->line_number<<endl;
                      exit(1);
                   }
                   else 
                   (yyval.node)->type = (yyvsp[0].node)->type;
                   (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
}
#line 2762 "parser.cpp"
    break;

  case 45: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep COMMA  */
#line 665 "parser.y"
                                                                         {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-2].node));
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                     (yyval.node)=n;
                     (yyval.node)->line_number = (yyvsp[0].node)->line_number;
                     (yyval.node)->temp_var = (yyvsp[-2].node)->temp_var + (yyvsp[-1].node)->temp_var + ",";
                    }
#line 2776 "parser.cpp"
    break;

  case 46: /* testlist_star_expr: testlist_star_expr_opt1 testlist_star_expr_rep  */
#line 674 "parser.y"
                                                                   { 
                      Node* n =create_node("testlist_star_expr");
                      n->children.push_back((yyvsp[-1].node));
                      n->children.push_back((yyvsp[0].node));
                      (yyval.node)=n;
                      (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var + (yyvsp[0].node)->temp_var;
                      (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
                    }
#line 2789 "parser.cpp"
    break;

  case 47: /* testlist_star_expr: testlist_star_expr_opt1 COMMA  */
#line 682 "parser.y"
                                                  {
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back((yyvsp[-1].node));
                     n->children.push_back((yyvsp[0].node));
                     (yyval.node)=n;
                     (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var + ",";
                    }
#line 2801 "parser.cpp"
    break;

  case 48: /* testlist_star_expr: testlist_star_expr_opt1  */
#line 689 "parser.y"
                                             { (yyval.node) = (yyvsp[0].node);}
#line 2807 "parser.cpp"
    break;

  case 49: /* testlist_star_expr_opt1: test  */
#line 693 "parser.y"
                              {(yyval.node)=(yyvsp[0].node);}
#line 2813 "parser.cpp"
    break;

  case 50: /* testlist_star_expr_opt1: star_expr  */
#line 694 "parser.y"
                                   {(yyval.node)=(yyvsp[0].node);}
#line 2819 "parser.cpp"
    break;

  case 51: /* testlist_star_expr_rep: testlist_star_expr_rep COMMA testlist_star_expr_opt1  */
#line 697 "parser.y"
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
#line 2834 "parser.cpp"
    break;

  case 52: /* testlist_star_expr_rep: COMMA testlist_star_expr_opt1  */
#line 707 "parser.y"
                                  {(yyval.node) = NULL; (yyval.node)->temp_var = ","+(yyvsp[0].node)->temp_var;}
#line 2840 "parser.cpp"
    break;

  case 53: /* augassign: PLUS_EQUAL  */
#line 709 "parser.y"
                       {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "+=";}
#line 2846 "parser.cpp"
    break;

  case 54: /* augassign: MINUS_EQUAL  */
#line 710 "parser.y"
                        {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "-=";}
#line 2852 "parser.cpp"
    break;

  case 55: /* augassign: TIMES_EQUAL  */
#line 711 "parser.y"
                        {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "*=";}
#line 2858 "parser.cpp"
    break;

  case 56: /* augassign: AT_EQUAL  */
#line 712 "parser.y"
                     {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "@=";}
#line 2864 "parser.cpp"
    break;

  case 57: /* augassign: DIVIDEDBY_EQUAL  */
#line 713 "parser.y"
                            {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "/=";}
#line 2870 "parser.cpp"
    break;

  case 58: /* augassign: MODULO_EQUAL  */
#line 714 "parser.y"
                         {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "%=";}
#line 2876 "parser.cpp"
    break;

  case 59: /* augassign: BITWISE_AND_EQUAL  */
#line 715 "parser.y"
                              {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "&=";}
#line 2882 "parser.cpp"
    break;

  case 60: /* augassign: BITWISE_OR_EQUAL  */
#line 716 "parser.y"
                             {(yyval.node)=(yyvsp[0].node);  (yyval.node)->temp_op = "|=";}
#line 2888 "parser.cpp"
    break;

  case 61: /* augassign: BITWISE_XOR_EQUAL  */
#line 717 "parser.y"
                              {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "^=";}
#line 2894 "parser.cpp"
    break;

  case 62: /* augassign: SHIFT_LEFT_EQUAL  */
#line 718 "parser.y"
                             {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "<<=";}
#line 2900 "parser.cpp"
    break;

  case 63: /* augassign: SHIFT_RIGHT_EQUAL  */
#line 719 "parser.y"
                              {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = ">>=";}
#line 2906 "parser.cpp"
    break;

  case 64: /* augassign: POWER_EQUAL  */
#line 720 "parser.y"
                        {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "**=";}
#line 2912 "parser.cpp"
    break;

  case 65: /* augassign: FLOORDIV_EQUAL  */
#line 721 "parser.y"
                           {(yyval.node)=(yyvsp[0].node); (yyval.node)->temp_op = "//=";}
#line 2918 "parser.cpp"
    break;

  case 66: /* del_stmt: DEL exprlist  */
#line 724 "parser.y"
                      {Node* n =create_node("del_stmt");
                         n->children.push_back((yyvsp[-1].node));
                         n->children.push_back((yyvsp[0].node));
                         (yyval.node)=n;
                          }
#line 2928 "parser.cpp"
    break;

  case 67: /* pass_stmt: PASS  */
#line 730 "parser.y"
               {(yyval.node)=(yyvsp[0].node);}
#line 2934 "parser.cpp"
    break;

  case 68: /* flow_stmt: break_stmt  */
#line 732 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2940 "parser.cpp"
    break;

  case 69: /* flow_stmt: continue_stmt  */
#line 733 "parser.y"
                         {(yyval.node)=(yyvsp[0].node);}
#line 2946 "parser.cpp"
    break;

  case 70: /* flow_stmt: return_stmt  */
#line 734 "parser.y"
                       {(yyval.node)=(yyvsp[0].node); }
#line 2952 "parser.cpp"
    break;

  case 71: /* flow_stmt: yield_stmt  */
#line 735 "parser.y"
                     {(yyval.node)=(yyvsp[0].node);}
#line 2958 "parser.cpp"
    break;

  case 72: /* break_stmt: BREAK  */
#line 738 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 2964 "parser.cpp"
    break;

  case 73: /* continue_stmt: CONTINUE  */
#line 740 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2970 "parser.cpp"
    break;

  case 74: /* return_stmt: RETURN testlist  */
#line 741 "parser.y"
                            {
              Node* n =create_node("return_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n;
              (yyval.node)->type = (yyvsp[0].node)->type;
              codepush("",(yyvsp[0].node)->temp_var,"","pushparam",-1);
            }
#line 2983 "parser.cpp"
    break;

  case 75: /* return_stmt: RETURN  */
#line 749 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "None";}
#line 2989 "parser.cpp"
    break;

  case 76: /* yield_stmt: yield_expr  */
#line 751 "parser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2995 "parser.cpp"
    break;

  case 77: /* global_stmt: GLOBAL global_name_list  */
#line 752 "parser.y"
                                    {
              Node* n =create_node("global_stmt");
              n->children.push_back((yyvsp[-1].node));
              n->children.push_back((yyvsp[0].node));      
              (yyval.node)=n; 
            }
#line 3006 "parser.cpp"
    break;

  case 78: /* global_name_list: global_name_list COMMA NAME  */
#line 759 "parser.y"
                                              {
                  Node* n =create_node("global_name_list");
                  for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
                    n->children.push_back((yyvsp[-2].node)->children[i]);
                  }
                  n->children.push_back((yyvsp[-1].node));
                  n->children.push_back((yyvsp[0].node));
                  
                  (yyval.node)=n;
                }
#line 3021 "parser.cpp"
    break;

  case 79: /* global_name_list: NAME  */
#line 769 "parser.y"
                       { (yyval.node) = (yyvsp[0].node);}
#line 3027 "parser.cpp"
    break;

  case 80: /* compound_stmt: if_stmt  */
#line 771 "parser.y"
                       { (yyval.node)=(yyvsp[0].node);}
#line 3033 "parser.cpp"
    break;

  case 81: /* compound_stmt: while_stmt  */
#line 772 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 3039 "parser.cpp"
    break;

  case 82: /* compound_stmt: for_stmt  */
#line 773 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 3045 "parser.cpp"
    break;

  case 83: /* compound_stmt: funcdef  */
#line 774 "parser.y"
                       { (yyval.node)=(yyvsp[0].node);}
#line 3051 "parser.cpp"
    break;

  case 84: /* compound_stmt: classdef  */
#line 775 "parser.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 3057 "parser.cpp"
    break;

  case 85: /* compound_stmt: async_stmt  */
#line 776 "parser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 3063 "parser.cpp"
    break;

  case 89: /* if_stmt: IF test COLON suite elif_stmt_rep ELSE COLON suite  */
#line 786 "parser.y"
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
#line 3081 "parser.cpp"
    break;

  case 90: /* if_stmt: IF test COLON suite elif_stmt_rep  */
#line 799 "parser.y"
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
#line 3098 "parser.cpp"
    break;

  case 91: /* if_stmt: IF test COLON suite ELSE COLON suite  */
#line 811 "parser.y"
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
#line 3115 "parser.cpp"
    break;

  case 92: /* if_stmt: IF test COLON suite  */
#line 823 "parser.y"
                         { 
      Node* n=create_node("if_stmt");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
      (yyval.node)->line_number = (yyvsp[-3].node)->line_number;
    }
#line 3129 "parser.cpp"
    break;

  case 93: /* elif_stmt_rep: elif_stmt_rep ELIF test COLON suite  */
#line 833 "parser.y"
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
#line 3145 "parser.cpp"
    break;

  case 94: /* elif_stmt_rep: ELIF test COLON suite  */
#line 844 "parser.y"
                           { 
      Node* n=create_node("elif_stmt_rep");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)=n;
    }
#line 3158 "parser.cpp"
    break;

  case 95: /* $@3: %empty  */
#line 853 "parser.y"
                       {
      codepush("","","","loop:",-1);
        string s2 = (yyvsp[0].node)->temp_var;
        codepush("if",s2,"true","==",-1);
        loop_stack.push_back(inst_num-2); 
}
#line 3169 "parser.cpp"
    break;

  case 96: /* while_stmt: WHILE test $@3 COLON suite  */
#line 858 "parser.y"
              { 
      Node* n=create_node("while_stmt");
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[-1].node)); 
      (yyval.node)=n;
      codepush("",to_string(loop_stack[(loop_stack.size())-1]),"","goto",-1); loop_stack.pop_back();codepush("","","","end loop",-1);
  }
#line 3183 "parser.cpp"
    break;

  case 97: /* $@4: %empty  */
#line 868 "parser.y"
                                    {
        codepush("","","","loop:",-1);
        string s2 = (yyvsp[0].node)->temp_var;
        codepush("if",(yyvsp[-2].node)->label,s2,">",-1);
        codepush("+",(yyvsp[-2].node)->label,"1",(yyvsp[-2].node)->label,-1);
        loop_stack.push_back(inst_num-2);
         }
#line 3195 "parser.cpp"
    break;

  case 98: /* for_stmt: FOR exprlist IN range_func $@4 COLON suite  */
#line 874 "parser.y"
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
         exit(1);
      }

      (yyval.node)=n;
      codepush("",to_string(loop_stack[(loop_stack.size())-1]),"","goto",-1); loop_stack.pop_back();codepush("","","","end loop",-1);
    }
#line 3228 "parser.cpp"
    break;

  case 99: /* range_func: NAME LPAREN test RPAREN  */
#line 903 "parser.y"
                                    {
      Node* n=create_node("range_func");
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node)); 
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node)); 
      (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var;
      if((yyvsp[-3].node)->label != "range"){
        cout<<"For loop supports only range function in line no "<<(yyvsp[-3].node)->line_number<<endl;
        exit(1);
      }


  }
#line 3247 "parser.cpp"
    break;

  case 100: /* range_func: NAME LPAREN test COMMA test RPAREN  */
#line 917 "parser.y"
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
         exit(1);
      }
      else if(((yyvsp[-3].node)->type != "int")&& ((yyvsp[-1].node)->type != "int"))
      {
        cout<<"Invalid datatype used in range function in line no "<<(yyvsp[-5].node)->line_number<<endl;
        exit(1);
      }
  }
#line 3271 "parser.cpp"
    break;

  case 101: /* suite: simple_stmt  */
#line 937 "parser.y"
                    {if(yybye) cout<<"LINE 462 \n"; (yyval.node) = (yyvsp[0].node);}
#line 3277 "parser.cpp"
    break;

  case 102: /* suite: NEWLINE INDENT stmt_rep DEDENT  */
#line 938 "parser.y"
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
#line 3294 "parser.cpp"
    break;

  case 103: /* stmt_rep: stmt_rep stmt  */
#line 952 "parser.y"
                           {
            Node* n = create_node("Multi Statements");
            (yyval.node) = n;
            for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
              n->children.push_back((yyvsp[-1].node)->children[i]);
            }
            n->children.push_back((yyvsp[0].node));
            (yyval.node)->type = (yyvsp[0].node)->type;
          }
#line 3308 "parser.cpp"
    break;

  case 104: /* stmt_rep: stmt  */
#line 961 "parser.y"
                 {(yyval.node)=(yyvsp[0].node); }
#line 3314 "parser.cpp"
    break;

  case 105: /* test: or_test IF or_test ELSE test  */
#line 963 "parser.y"
                                    {
      Node* n = create_node("Test");
      (yyval.node) = n;
      n->children.push_back((yyvsp[-4].node));
      n->children.push_back((yyvsp[-3].node));
      n->children.push_back((yyvsp[-2].node));
      n->children.push_back((yyvsp[-1].node));
      n->children.push_back((yyvsp[0].node));
}
#line 3328 "parser.cpp"
    break;

  case 106: /* test: or_test  */
#line 972 "parser.y"
         {(yyval.node)=(yyvsp[0].node);}
#line 3334 "parser.cpp"
    break;

  case 107: /* test_nocond: or_test  */
#line 975 "parser.y"
          {(yyval.node) = (yyvsp[0].node);}
#line 3340 "parser.cpp"
    break;

  case 108: /* or_test: and_test or_test_rep  */
#line 979 "parser.y"
  {
    Node* n = create_node("OR Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush("or",(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3354 "parser.cpp"
    break;

  case 109: /* or_test: and_test  */
#line 988 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3360 "parser.cpp"
    break;

  case 110: /* or_test_rep: or_test_rep OR and_test  */
#line 991 "parser.y"
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
      exit(1);
    }  
    (yyval.node)->type = "bool";
    string s1=new_temporary();
    codepush("or",(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 3384 "parser.cpp"
    break;

  case 111: /* or_test_rep: OR and_test  */
#line 1010 "parser.y"
               {Node* n = create_node("ORTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int"))
    {
      cout<<"Non compatible operand type used for OR operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      exit(1);
    }  
    (yyval.node)->temp_op = "or";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3401 "parser.cpp"
    break;

  case 112: /* and_test: not_test and_test_rep  */
#line 1024 "parser.y"
                       {
    Node* n = create_node("And Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int") || (((yyvsp[-1].node)->type != "bool") && ((yyvsp[-1].node)->type != "int") ))
    {
      cout<<"Non compatible operand type used for AND    operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      exit(1);
    }
    (yyval.node)->type ="bool";
    string s1=new_temporary();
    codepush("and",(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3421 "parser.cpp"
    break;

  case 113: /* and_test: not_test  */
#line 1039 "parser.y"
           {(yyval.node)=(yyvsp[0].node);}
#line 3427 "parser.cpp"
    break;

  case 114: /* and_test_rep: and_test_rep AND not_test  */
#line 1043 "parser.y"
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
      cout<<"Non compatible operand type used for AND hii operator in line no "<<(yyvsp[-2].node)->line_number<<endl;
      exit(1);
    }  
    (yyval.node)->type = "bool";
    string s1=new_temporary();
    codepush("and",(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 3451 "parser.cpp"
    break;

  case 115: /* and_test_rep: AND not_test  */
#line 1062 "parser.y"
                {Node* n = create_node("AndTestRep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int"))
    {
      // cout<<$2->type<<endl;
      cout<<"Non compatible operand type used for AND  no operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      exit(1);
    }
    (yyval.node)->type = "bool";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    }
#line 3470 "parser.cpp"
    break;

  case 116: /* not_test: NOT not_test  */
#line 1080 "parser.y"
  {
    Node* n = create_node("Not Test");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    if(((yyvsp[0].node)->type != "bool") && ((yyvsp[0].node)->type != "int"))
    {
      cout<<"Non compatible operand type used for NOT operator in line no "<<(yyvsp[-1].node)->line_number<<endl;
      exit(1);
    }
        (yyval.node)->type = "bool";
    string s1=new_temporary();
    codepush("not",(yyvsp[0].node)->temp_var,"",s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3490 "parser.cpp"
    break;

  case 117: /* not_test: comparison  */
#line 1095 "parser.y"
               {
    (yyval.node) =(yyvsp[0].node);
  }
#line 3498 "parser.cpp"
    break;

  case 118: /* comparison: expr comparison_rep  */
#line 1100 "parser.y"
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
#line 3517 "parser.cpp"
    break;

  case 119: /* comparison: expr  */
#line 1114 "parser.y"
       {(yyval.node)=(yyvsp[0].node);}
#line 3523 "parser.cpp"
    break;

  case 120: /* comparison_rep: comparison_rep comp_op expr  */
#line 1118 "parser.y"
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
#line 3542 "parser.cpp"
    break;

  case 121: /* comparison_rep: comp_op expr  */
#line 1132 "parser.y"
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
#line 3561 "parser.cpp"
    break;

  case 122: /* comp_op: LESS_THAN  */
#line 1147 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "<";}
#line 3567 "parser.cpp"
    break;

  case 123: /* comp_op: GREATER_THAN  */
#line 1148 "parser.y"
                      {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = ">";}
#line 3573 "parser.cpp"
    break;

  case 124: /* comp_op: EQUAL  */
#line 1149 "parser.y"
               {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "==";}
#line 3579 "parser.cpp"
    break;

  case 125: /* comp_op: GREATER_THAN_OR_EQUAL  */
#line 1150 "parser.y"
                               {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = ">=";}
#line 3585 "parser.cpp"
    break;

  case 126: /* comp_op: LESS_THAN_OR_EQUAL  */
#line 1151 "parser.y"
                            {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "<=";}
#line 3591 "parser.cpp"
    break;

  case 127: /* comp_op: NOT_EQUAL  */
#line 1152 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "!=";}
#line 3597 "parser.cpp"
    break;

  case 128: /* comp_op: IN  */
#line 1153 "parser.y"
            {(yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "in";}
#line 3603 "parser.cpp"
    break;

  case 129: /* comp_op: NOT IN  */
#line 1154 "parser.y"
                {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3614 "parser.cpp"
    break;

  case 130: /* comp_op: IS  */
#line 1160 "parser.y"
            {(yyval.node) =(yyvsp[0].node);}
#line 3620 "parser.cpp"
    break;

  case 131: /* comp_op: IS NOT  */
#line 1161 "parser.y"
               {
          Node* n = create_node("Comparison Operator");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 3631 "parser.cpp"
    break;

  case 132: /* star_expr: TIMES expr  */
#line 1169 "parser.y"
            {
    Node* n = create_node("Star Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->temp_var="*"+(yyvsp[0].node)->temp_var;
  }
#line 3643 "parser.cpp"
    break;

  case 133: /* expr: xor_expr expr_rep  */
#line 1178 "parser.y"
                   {
    Node* n = create_node("Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3657 "parser.cpp"
    break;

  case 134: /* expr: xor_expr  */
#line 1187 "parser.y"
            {(yyval.node)=(yyvsp[0].node);}
#line 3663 "parser.cpp"
    break;

  case 135: /* expr_rep: expr_rep BITWISE_OR xor_expr  */
#line 1190 "parser.y"
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
#line 3682 "parser.cpp"
    break;

  case 136: /* expr_rep: BITWISE_OR xor_expr  */
#line 1204 "parser.y"
                       {Node* n = create_node("Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->temp_op = "|";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3694 "parser.cpp"
    break;

  case 137: /* xor_expr: and_expr xor_expr_rep  */
#line 1213 "parser.y"
                       {
    Node* n = create_node("XOR Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3708 "parser.cpp"
    break;

  case 138: /* xor_expr: and_expr  */
#line 1222 "parser.y"
            {
    (yyval.node)=(yyvsp[0].node);
  }
#line 3716 "parser.cpp"
    break;

  case 139: /* xor_expr_rep: xor_expr_rep BITWISE_XOR and_expr  */
#line 1227 "parser.y"
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
#line 3735 "parser.cpp"
    break;

  case 140: /* xor_expr_rep: BITWISE_XOR and_expr  */
#line 1241 "parser.y"
                       {Node* n = create_node("XOR Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->temp_op = "^";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3747 "parser.cpp"
    break;

  case 141: /* and_expr: shift_expr and_expr_rep  */
#line 1250 "parser.y"
                         {
    Node* n = create_node("AND Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3761 "parser.cpp"
    break;

  case 142: /* and_expr: shift_expr  */
#line 1259 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3767 "parser.cpp"
    break;

  case 143: /* and_expr_rep: and_expr_rep BITWISE_AND shift_expr  */
#line 1262 "parser.y"
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
#line 3786 "parser.cpp"
    break;

  case 144: /* and_expr_rep: BITWISE_AND shift_expr  */
#line 1276 "parser.y"
                         {Node* n = create_node("AND Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node)); 
    (yyval.node)->temp_op = "&";
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;

    }
#line 3799 "parser.cpp"
    break;

  case 145: /* shift_expr: arith_expr shift_expr_rep  */
#line 1286 "parser.y"
                           {
    Node* n = create_node("Shift Expression");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
  }
#line 3813 "parser.cpp"
    break;

  case 146: /* shift_expr: arith_expr  */
#line 1295 "parser.y"
              {(yyval.node)=(yyvsp[0].node);}
#line 3819 "parser.cpp"
    break;

  case 147: /* shift_expr_rep: shift_expr_rep shift_expr_rep_c1 arith_expr  */
#line 1298 "parser.y"
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
#line 3837 "parser.cpp"
    break;

  case 148: /* shift_expr_rep: shift_expr_rep_c1 arith_expr  */
#line 1311 "parser.y"
                                {Node* n = create_node("Shift Expression Rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    }
#line 3850 "parser.cpp"
    break;

  case 149: /* shift_expr_rep_c1: SHIFT_LEFT  */
#line 1321 "parser.y"
            {
    (yyval.node) = (yyvsp[0].node);
    (yyval.node)->temp_op = "<<";
  }
#line 3859 "parser.cpp"
    break;

  case 150: /* shift_expr_rep_c1: SHIFT_RIGHT  */
#line 1325 "parser.y"
                {(yyval.node) = (yyvsp[0].node);
    (yyval.node)->temp_op = ">>";
  }
#line 3867 "parser.cpp"
    break;

  case 151: /* arith_expr: term arith_expr_rep  */
#line 1330 "parser.y"
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
#line 3892 "parser.cpp"
    break;

  case 152: /* arith_expr: term  */
#line 1350 "parser.y"
        { (yyval.node)=(yyvsp[0].node);}
#line 3898 "parser.cpp"
    break;

  case 153: /* arith_expr_rep: arith_expr_rep arith_expr_rep_c1 term  */
#line 1353 "parser.y"
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

    string s1=new_temporary();
    codepush((yyvsp[-1].node)->temp_op,(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
    // cout<<$$->type <<" arth rep 1"<<endl;

  }
#line 3928 "parser.cpp"
    break;

  case 154: /* arith_expr_rep: arith_expr_rep_c1 term  */
#line 1378 "parser.y"
                         {Node* n = create_node("Arithmetic Expression Rep2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    // cout<<"Arith2 "<<$$->temp_var <<" " <<$$->temp_op<<endl;
    }
#line 3942 "parser.cpp"
    break;

  case 155: /* arith_expr_rep_c1: PLUS  */
#line 1389 "parser.y"
       { (yyval.node) = (yyvsp[0].node);(yyval.node)->temp_op = "+";}
#line 3948 "parser.cpp"
    break;

  case 156: /* arith_expr_rep_c1: MINUS  */
#line 1390 "parser.y"
          { (yyval.node) = (yyvsp[0].node);(yyval.node) ->temp_op = "-";}
#line 3954 "parser.cpp"
    break;

  case 157: /* term: factor term_rep  */
#line 1393 "parser.y"
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

    string s1=new_temporary();
    codepush((yyvsp[0].node)->temp_op,(yyvsp[-1].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1; 
  }
#line 3981 "parser.cpp"
    break;

  case 158: /* term: factor  */
#line 1415 "parser.y"
         {(yyval.node)=(yyvsp[0].node);}
#line 3987 "parser.cpp"
    break;

  case 159: /* term_rep: term_rep term_rep_c1 factor  */
#line 1418 "parser.y"
                               {
    Node* n = create_node("TERM Rep");
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
    string s1=new_temporary();
    codepush((yyvsp[-1].node)->temp_op,(yyvsp[-2].node)->temp_var,(yyvsp[0].node)->temp_var,s1,-1);
    (yyval.node)->temp_var = s1;
    (yyval.node)->temp_op = (yyvsp[-2].node)->temp_op;
  }
#line 4005 "parser.cpp"
    break;

  case 160: /* term_rep: term_rep_c1 factor  */
#line 1431 "parser.y"
                       { Node* n = create_node("TERM Rep");
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node) = n;
    (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = (yyvsp[-1].node)->temp_op;
    }
#line 4018 "parser.cpp"
    break;

  case 161: /* term_rep_c1: TIMES  */
#line 1440 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "*";}
#line 4024 "parser.cpp"
    break;

  case 162: /* term_rep_c1: AT  */
#line 1441 "parser.y"
                 { (yyval.node) =(yyvsp[0].node);(yyval.node)->temp_op = "@";}
#line 4030 "parser.cpp"
    break;

  case 163: /* term_rep_c1: DIVIDEDBY  */
#line 1442 "parser.y"
                        { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "/"; }
#line 4036 "parser.cpp"
    break;

  case 164: /* term_rep_c1: MODULO  */
#line 1443 "parser.y"
                     { (yyval.node) =(yyvsp[0].node);   (yyval.node)->temp_op = "%";}
#line 4042 "parser.cpp"
    break;

  case 165: /* term_rep_c1: FLOORDIV  */
#line 1444 "parser.y"
                       { (yyval.node) =(yyvsp[0].node);    (yyval.node)->temp_op = "//";}
#line 4048 "parser.cpp"
    break;

  case 166: /* factor: factor_c1 factor  */
#line 1447 "parser.y"
                   {
    Node* n = create_node("Factor");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->temp_op=(yyvsp[-1].node)->temp_op;
    (yyval.node)->temp_var=(yyvsp[0].node)->temp_var;
  }
#line 4061 "parser.cpp"
    break;

  case 167: /* factor: power  */
#line 1455 "parser.y"
          { if(yybye) cout<<"factor power: "<<endl;(yyval.node) = (yyvsp[0].node);}
#line 4067 "parser.cpp"
    break;

  case 168: /* factor_c1: PLUS  */
#line 1457 "parser.y"
                 { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "+";}
#line 4073 "parser.cpp"
    break;

  case 169: /* factor_c1: MINUS  */
#line 1458 "parser.y"
                  { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "-"; }
#line 4079 "parser.cpp"
    break;

  case 170: /* factor_c1: BITWISE_NOT  */
#line 1459 "parser.y"
                        { (yyval.node) =(yyvsp[0].node); (yyval.node)->temp_op = "~";}
#line 4085 "parser.cpp"
    break;

  case 171: /* power: atom_expr power_opt  */
#line 1462 "parser.y"
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
#line 4101 "parser.cpp"
    break;

  case 172: /* power: atom_expr  */
#line 1473 "parser.y"
             {
    (yyval.node) = (yyvsp[0].node);
    if(yybye) cout<<"atom_expr power: "<<endl;(yyval.node)=(yyvsp[0].node);
  }
#line 4110 "parser.cpp"
    break;

  case 173: /* power_opt: POWER factor  */
#line 1479 "parser.y"
               {
    Node* n = create_node("Power Opt");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
    (yyval.node)->temp_var = (yyvsp[0].node)->temp_var;
    (yyval.node)->temp_op = "**";
  }
#line 4124 "parser.cpp"
    break;

  case 174: /* atom_expr: await_opt atom trailer_rep  */
#line 1490 "parser.y"
                            {
    Node* n = create_node("Atom Expression1");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    n->type = (yyvsp[-1].node)->type + (yyvsp[0].node)->type;
    (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var;
  }
#line 4138 "parser.cpp"
    break;

  case 175: /* atom_expr: atom trailer_rep  */
#line 1499 "parser.y"
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
    }
    if((gt->SYMVAL.find((yyvsp[-1].node)->label) != gt->SYMVAL.end()) && (yyvsp[0].node)->category == "Func")
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
      (yyval.node)->type = gt->SYMVAL[(yyvsp[-1].node)->label].type ;
      
    }
    else if((yyvsp[0].node)->category == "Func")
    {
      if((yyvsp[-1].node)->label == "len"){
        std::regex pattern("list\\[\\w+\\]");
        // cout<<$2->type<<endl;
        if (std::regex_match((yyvsp[0].node)->type, pattern)) {

        } else {
            cout<<(yyvsp[0].node)->type <<endl;
            std::cout <<" Invalid datatype use for len function in line no : "<<(yyvsp[-1].node)->line_number<<"\n";
            exit(1);
        }
        (yyval.node)->type ="int";
      }
      else if( (yyvsp[-1].node)->label == "print")
      {
        for(int i = 0;i<(yyvsp[0].node)->p_f.size() ; i++)
        {
          if((yyvsp[0].node)->p_f[i]->par_type == "string"){}
          else{
                if(tab->SYMVAL.find((yyvsp[0].node)->p_f[i]->par_name)==tab->SYMVAL.end())
                {
                  if(gt->SYMVAL.find(((yyvsp[0].node)->p_f[i]->par_name))==gt->SYMVAL.end()){
                  cout<<"Use of undeclared variable inside print function " <<" in line number "<<(yyvsp[0].node)->line_number<<endl;
                  exit(1);}
                }
          }

        }
      }
      else{
        cout<<"Undeclared Function in line no : "<< (yyvsp[-1].node)->line_number<<endl;
        exit(1);
      }
    }
    else if((yyvsp[0].node)->label == "Trailer5")
    {
      //  to check class datatypes
      if(gt->childs[(yyvsp[-1].node)->type]->SYMVAL.find((yyvsp[0].node)->type) == gt->childs[(yyvsp[-1].node)->type]->SYMVAL.end()) 
      {
        cout<<"yes"<<endl;
        cout<<"Undefined property "<<(yyvsp[0].node)->type<<" for class "<<(yyvsp[-1].node)->type<<" used by object "<<(yyvsp[-1].node)->label<<"in line no "<<(yyvsp[-1].node)->line_number<<endl;
      }
      (yyval.node)->type = gt->childs[(yyvsp[-1].node)->type]->SYMVAL[(yyvsp[0].node)->type].type;
      cout<<(yyval.node)->type<<endl;


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
       
        codepush("call",(yyvsp[-1].node)->label,"","",-1);
        
        arguments.clear();
  }
#line 4262 "parser.cpp"
    break;

  case 176: /* atom_expr: atom  */
#line 1618 "parser.y"
       {
    (yyval.node) = (yyvsp[0].node);
    // cout<<"atom " <<$$->type<<endl;
    if(yybye) cout<<"atom_expr atom: "<<endl; 
  }
#line 4272 "parser.cpp"
    break;

  case 177: /* await_opt: AWAIT  */
#line 1624 "parser.y"
                  {
  (yyval.node) = (yyvsp[0].node);
}
#line 4280 "parser.cpp"
    break;

  case 178: /* trailer_rep: trailer_rep trailer  */
#line 1629 "parser.y"
                      {
    if(yybye) cout<<"trailer_rep: "<<endl;
    Node* n = create_node("Trailer Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));
  }
#line 4294 "parser.cpp"
    break;

  case 179: /* trailer_rep: trailer  */
#line 1638 "parser.y"
            { 
    (yyval.node) =(yyvsp[0].node);
  }
#line 4302 "parser.cpp"
    break;

  case 180: /* atom: LPAREN atom_opt1 RPAREN  */
#line 1642 "parser.y"
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
#line 4319 "parser.cpp"
    break;

  case 181: /* atom: LBRACKET atom_opt2 RBRACKET  */
#line 1654 "parser.y"
                                    {
        if(yybye) cout<<"atom atom_opt2: "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-2].node));
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        (yyval.node)->type = "list" + (yyvsp[-2].node)->type + (yyvsp[-1].node)->type +(yyvsp[0].node)->type;
        (yyval.node)->line_number = (yyvsp[-2].node)->line_number;
        // cout<<$$->type<<" "<<yylineno<<endl;
        (yyval.node)->temp_var = (yyvsp[-1].node)->temp_var;

      }
#line 4337 "parser.cpp"
    break;

  case 182: /* atom: LBRACKET RBRACKET  */
#line 1667 "parser.y"
                         { 
        if(yybye) cout<<"atom : "<<endl;
        Node* n = create_node("Atom");
        (yyval.node) = n;
        n->children.push_back((yyvsp[-1].node));
        n->children.push_back((yyvsp[0].node));
        (yyval.node)->line_number = (yyvsp[-1].node)->line_number;

      }
#line 4351 "parser.cpp"
    break;

  case 183: /* atom: NAME  */
#line 1676 "parser.y"
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
                string t = new_temporary();
                (yyval.node)->temp_var = t;
                // cout << t;
                codepush("",t,"",(yyvsp[0].node)->label,-1);  
                }
              

      }
#line 4389 "parser.cpp"
    break;

  case 184: /* atom: NUMBER  */
#line 1709 "parser.y"
                { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "int";
                  (yyval.node)->temp_var= new_temporary();
                  codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);  }
#line 4397 "parser.cpp"
    break;

  case 185: /* atom: FLOAT  */
#line 1712 "parser.y"
              {(yyval.node) = (yyvsp[0].node); (yyval.node)->type = "float";
                (yyval.node)->temp_var= new_temporary();
                codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4405 "parser.cpp"
    break;

  case 186: /* atom: string_rep  */
#line 1715 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); (yyval.node)->type = "string";
                      (yyval.node)->temp_var= new_temporary();
                      codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4413 "parser.cpp"
    break;

  case 187: /* atom: TRIPLEDOT  */
#line 1718 "parser.y"
                   { (yyval.node) =(yyvsp[0].node);}
#line 4419 "parser.cpp"
    break;

  case 188: /* atom: NONE  */
#line 1719 "parser.y"
              { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "None";}
#line 4425 "parser.cpp"
    break;

  case 189: /* atom: TRUE_TOKEN  */
#line 1720 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";
                      (yyval.node)->temp_var= new_temporary();
                      codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4433 "parser.cpp"
    break;

  case 190: /* atom: FALSE_TOKEN  */
#line 1723 "parser.y"
                    { (yyval.node) =(yyvsp[0].node); (yyval.node)->type = "bool";
                      (yyval.node)->temp_var= new_temporary();
                      codepush("",(yyvsp[0].node)->label,"",(yyval.node)->temp_var,-1);}
#line 4441 "parser.cpp"
    break;

  case 191: /* atom_opt1: yield_expr  */
#line 1727 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 4447 "parser.cpp"
    break;

  case 192: /* atom_opt1: testlist_comp  */
#line 1728 "parser.y"
                         {(yyval.node) = (yyvsp[0].node); if(yybye) cout<<"atom_opt1 testlist_comp: "<<endl;}
#line 4453 "parser.cpp"
    break;

  case 193: /* atom_opt2: testlist_comp  */
#line 1730 "parser.y"
                         {(yyval.node) =(yyvsp[0].node);}
#line 4459 "parser.cpp"
    break;

  case 194: /* string_rep: STRING  */
#line 1733 "parser.y"
         { (yyval.node) = (yyvsp[0].node);}
#line 4465 "parser.cpp"
    break;

  case 195: /* string_rep: string_rep STRING  */
#line 1734 "parser.y"
                      {
    Node* n = create_node("String Rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-1].node)->children.size(); i++){
      n->children.push_back((yyvsp[-1].node)->children[i]);
    }
    n->children.push_back((yyvsp[0].node));    
    (yyval.node)->line_number= (yyvsp[-1].node)->line_number;
  }
#line 4479 "parser.cpp"
    break;

  case 196: /* testlist_comp: testlist_comp_c1 testlist_comp_c2  */
#line 1745 "parser.y"
                                   {
    Node* n = create_node("Testlist comp");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[-1].node)->type;
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
    
  }
#line 4493 "parser.cpp"
    break;

  case 197: /* testlist_comp: testlist_comp_c1  */
#line 1754 "parser.y"
                   {(yyval.node) =(yyvsp[0].node);}
#line 4499 "parser.cpp"
    break;

  case 198: /* testlist_comp_c1: test  */
#line 1757 "parser.y"
         {(yyval.node) = (yyvsp[0].node);}
#line 4505 "parser.cpp"
    break;

  case 199: /* testlist_comp_c1: star_expr  */
#line 1758 "parser.y"
              {(yyval.node) = (yyvsp[0].node);}
#line 4511 "parser.cpp"
    break;

  case 200: /* testlist_comp_c2: comp_for  */
#line 1761 "parser.y"
           {(yyval.node) = (yyvsp[0].node);}
#line 4517 "parser.cpp"
    break;

  case 201: /* testlist_comp_c2: testlist_comp_c2_rep COMMA  */
#line 1762 "parser.y"
                              {
    Node* n = create_node("Testlist Comp C2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[-1].node)->type;
    (yyval.node)->line_number = (yyvsp[0].node)->line_number;
  }
#line 4530 "parser.cpp"
    break;

  case 202: /* testlist_comp_c2: COMMA  */
#line 1770 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 4536 "parser.cpp"
    break;

  case 203: /* testlist_comp_c2: testlist_comp_c2_rep  */
#line 1771 "parser.y"
                        {(yyval.node) =(yyvsp[0].node);}
#line 4542 "parser.cpp"
    break;

  case 204: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA test  */
#line 1775 "parser.y"
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
#line 4558 "parser.cpp"
    break;

  case 205: /* testlist_comp_c2_rep: testlist_comp_c2_rep COMMA star_expr  */
#line 1786 "parser.y"
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
#line 4574 "parser.cpp"
    break;

  case 206: /* testlist_comp_c2_rep: COMMA test  */
#line 1797 "parser.y"
             {
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 4586 "parser.cpp"
    break;

  case 207: /* testlist_comp_c2_rep: COMMA star_expr  */
#line 1804 "parser.y"
                    { 
    Node* n = create_node("Testlist Comp C2 rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->type = (yyvsp[0].node)->type;
  }
#line 4598 "parser.cpp"
    break;

  case 208: /* trailer: LPAREN arglist RPAREN  */
#line 1813 "parser.y"
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
#line 4616 "parser.cpp"
    break;

  case 209: /* trailer: LPAREN RPAREN  */
#line 1826 "parser.y"
                {
    Node* n = create_node("Trailer2");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
    (yyval.node)->category = "Func";
  }
#line 4629 "parser.cpp"
    break;

  case 210: /* trailer: LBRACKET subscriptlist RBRACKET  */
#line 1834 "parser.y"
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
#line 4646 "parser.cpp"
    break;

  case 211: /* trailer: LBRACKET RBRACKET  */
#line 1846 "parser.y"
                    { 
    Node* n = create_node("Trailer4");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
  }
#line 4658 "parser.cpp"
    break;

  case 212: /* trailer: DOT NAME  */
#line 1853 "parser.y"
            {
    Node* n = create_node("Trailer5");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
    (yyval.node)->line_number = (yyvsp[-1].node)->line_number;
  }
#line 4670 "parser.cpp"
    break;

  case 213: /* subscriptlist: subscript COMMA_subscript_rep COMMA_opt  */
#line 1862 "parser.y"
                                         {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4683 "parser.cpp"
    break;

  case 214: /* subscriptlist: subscript COMMA_opt  */
#line 1870 "parser.y"
                      {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4694 "parser.cpp"
    break;

  case 215: /* subscriptlist: subscript COMMA_subscript_rep  */
#line 1876 "parser.y"
                                {
    Node* n = create_node("Subscriptlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4705 "parser.cpp"
    break;

  case 216: /* subscriptlist: subscript  */
#line 1882 "parser.y"
             {(yyval.node) =(yyvsp[0].node);}
#line 4711 "parser.cpp"
    break;

  case 217: /* COMMA_opt: COMMA  */
#line 1885 "parser.y"
        { (yyval.node) = (yyvsp[0].node);}
#line 4717 "parser.cpp"
    break;

  case 218: /* COMMA_subscript_rep: COMMA_subscript_rep COMMA subscript  */
#line 1889 "parser.y"
                                      {
    Node* n = create_node("Comma Subscript rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4731 "parser.cpp"
    break;

  case 219: /* COMMA_subscript_rep: COMMA subscript  */
#line 1898 "parser.y"
                   {
    Node* n = create_node("COMMA subscript rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4742 "parser.cpp"
    break;

  case 220: /* subscript: test  */
#line 1906 "parser.y"
       { (yyval.node) = (yyvsp[0].node);}
#line 4748 "parser.cpp"
    break;

  case 221: /* subscript: test COLON test sliceop  */
#line 1907 "parser.y"
                           {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-3].node));
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));

  }
#line 4762 "parser.cpp"
    break;

  case 222: /* subscript: COLON test sliceop  */
#line 1916 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4774 "parser.cpp"
    break;

  case 223: /* subscript: test COLON sliceop  */
#line 1923 "parser.y"
                      {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4786 "parser.cpp"
    break;

  case 224: /* subscript: test COLON test  */
#line 1930 "parser.y"
                   {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4798 "parser.cpp"
    break;

  case 225: /* subscript: COLON sliceop  */
#line 1937 "parser.y"
                 {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4809 "parser.cpp"
    break;

  case 226: /* subscript: COLON test  */
#line 1943 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4820 "parser.cpp"
    break;

  case 227: /* subscript: test COLON  */
#line 1949 "parser.y"
              {
    Node* n = create_node("Subscript");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4831 "parser.cpp"
    break;

  case 228: /* subscript: COLON  */
#line 1955 "parser.y"
         {(yyval.node) =(yyvsp[0].node);}
#line 4837 "parser.cpp"
    break;

  case 229: /* sliceop: COLON test  */
#line 1957 "parser.y"
                    {
    Node* n = create_node("Slice OP");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4848 "parser.cpp"
    break;

  case 230: /* sliceop: COLON  */
#line 1963 "parser.y"
       {(yyval.node) = (yyvsp[0].node);}
#line 4854 "parser.cpp"
    break;

  case 231: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep COMMA  */
#line 1965 "parser.y"
                                                        {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-2].node));
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4866 "parser.cpp"
    break;

  case 232: /* exprlist: expr_star_expr COMMA  */
#line 1972 "parser.y"
                      {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4877 "parser.cpp"
    break;

  case 233: /* exprlist: expr_star_expr COMMA_expr_star_expr_rep  */
#line 1978 "parser.y"
                                         {
    Node* n = create_node("Expr List");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
}
#line 4888 "parser.cpp"
    break;

  case 234: /* exprlist: expr_star_expr  */
#line 1984 "parser.y"
                {(yyval.node) =(yyvsp[0].node);}
#line 4894 "parser.cpp"
    break;

  case 235: /* expr_star_expr: expr  */
#line 1986 "parser.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 4900 "parser.cpp"
    break;

  case 236: /* expr_star_expr: star_expr  */
#line 1987 "parser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 4906 "parser.cpp"
    break;

  case 237: /* COMMA_expr_star_expr_rep: COMMA_expr_star_expr_rep COMMA expr_star_expr  */
#line 1990 "parser.y"
                                               {
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    for(int i=0; i<(yyvsp[-2].node)->children.size(); i++){
      n->children.push_back((yyvsp[-2].node)->children[i]);
    }
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4920 "parser.cpp"
    break;

  case 238: /* COMMA_expr_star_expr_rep: COMMA expr_star_expr  */
#line 1999 "parser.y"
                       { 
    Node* n = create_node("COMMA Expr star expr rep");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4931 "parser.cpp"
    break;

  case 239: /* testlist: test COMMA  */
#line 2014 "parser.y"
             {
    Node* n = create_node("Testlist");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 4942 "parser.cpp"
    break;

  case 240: /* testlist: test  */
#line 2026 "parser.y"
        {(yyval.node) =(yyvsp[0].node);}
#line 4948 "parser.cpp"
    break;

  case 241: /* class_name: CLASS NAME  */
#line 2043 "parser.y"
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

               tablist[curr_scope]=tab;
             }
             else {
              cout<<"Class redeclared in line no "<< (yyvsp[0].node)->line_number<<endl;
                      exit(1);
             }
}
#line 4978 "parser.cpp"
    break;

  case 242: /* classdef: class_name LPAREN arglist RPAREN COLON suite  */
#line 2068 "parser.y"
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
#line 5018 "parser.cpp"
    break;

  case 243: /* classdef: class_name LPAREN RPAREN COLON suite  */
#line 2103 "parser.y"
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
#line 5056 "parser.cpp"
    break;

  case 244: /* classdef: class_name COLON suite  */
#line 2136 "parser.y"
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
#line 5093 "parser.cpp"
    break;

  case 245: /* arglist: argument COMMA_argument_rep COMMA  */
#line 2170 "parser.y"
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
#line 5117 "parser.cpp"
    break;

  case 246: /* arglist: argument COMMA  */
#line 2189 "parser.y"
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
#line 5133 "parser.cpp"
    break;

  case 247: /* arglist: argument COMMA_argument_rep  */
#line 2200 "parser.y"
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
    arguments.push_back(make_tuple((yyvsp[-1].node)->label,(yyvsp[-1].node)->temp_var, (yyvsp[-1].node)->type,0,0));
  }
#line 5155 "parser.cpp"
    break;

  case 248: /* arglist: argument  */
#line 2217 "parser.y"
           {(yyval.node) =(yyvsp[0].node);
    Param* temp = new Param();
    temp->par_type=(yyvsp[0].node)->type;
    temp->par_name=(yyvsp[0].node)->label;
    (yyval.node)->p_f.push_back(temp);
    arguments.push_back(make_tuple((yyvsp[0].node)->label,(yyvsp[0].node)->temp_var, (yyvsp[0].node)->type,0,0));
  }
#line 5167 "parser.cpp"
    break;

  case 249: /* COMMA_argument_rep: COMMA_argument_rep COMMA argument  */
#line 2226 "parser.y"
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
#line 5189 "parser.cpp"
    break;

  case 250: /* COMMA_argument_rep: COMMA argument  */
#line 2243 "parser.y"
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
#line 5205 "parser.cpp"
    break;

  case 251: /* argument: test comp_for  */
#line 2256 "parser.y"
               {
    Node* n = create_node("Argument");
    (yyval.node) = n;
    n->children.push_back((yyvsp[-1].node));
    n->children.push_back((yyvsp[0].node));
  }
#line 5216 "parser.cpp"
    break;

  case 252: /* argument: test EQUAL_SIGN test  */
#line 2262 "parser.y"
                         {
     Node* n = create_node("Argument");
     (yyval.node) = n;
     n->children.push_back((yyvsp[-2].node));
     n->children.push_back((yyvsp[-1].node));
     codepush("", (yyvsp[0].node)->temp_var, "", (yyvsp[-2].node)->temp_var, -1);
     (yyval.node)->temp_var = (yyvsp[-2].node)->temp_var;
  }
#line 5229 "parser.cpp"
    break;

  case 253: /* argument: POWER test  */
#line 2270 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));      
  }
#line 5240 "parser.cpp"
    break;

  case 254: /* argument: TIMES test  */
#line 2276 "parser.y"
              {
   Node* n = create_node("Argument");
   (yyval.node) = n;
   n->children.push_back((yyvsp[-1].node));
   n->children.push_back((yyvsp[0].node));    
  }
#line 5251 "parser.cpp"
    break;

  case 255: /* argument: test  */
#line 2282 "parser.y"
       {(yyval.node) =(yyvsp[0].node);}
#line 5257 "parser.cpp"
    break;

  case 256: /* comp_iter: comp_for  */
#line 2284 "parser.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 5263 "parser.cpp"
    break;

  case 257: /* comp_iter: comp_if  */
#line 2285 "parser.y"
                    {(yyval.node) = (yyvsp[0].node);}
#line 5269 "parser.cpp"
    break;

  case 258: /* sync_comp_for: FOR exprlist IN or_test comp_iter  */
#line 2287 "parser.y"
                                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-4].node));
          n->children.push_back((yyvsp[-3].node));  
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));   
          n->children.push_back((yyvsp[0].node));   
}
#line 5283 "parser.cpp"
    break;

  case 259: /* sync_comp_for: FOR exprlist IN or_test  */
#line 2296 "parser.y"
                                 {
          Node* n = create_node("Sync comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-3].node));
          n->children.push_back((yyvsp[-2].node));  
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 5296 "parser.cpp"
    break;

  case 260: /* comp_for: ASYNC sync_comp_for  */
#line 2305 "parser.y"
                             { 
          Node* n = create_node("Comp for");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));  }
#line 5306 "parser.cpp"
    break;

  case 261: /* comp_for: sync_comp_for  */
#line 2310 "parser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 5312 "parser.cpp"
    break;

  case 262: /* comp_if: IF test_nocond comp_iter  */
#line 2312 "parser.y"
                                  {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-2].node));
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
}
#line 5324 "parser.cpp"
    break;

  case 263: /* comp_if: IF test_nocond  */
#line 2319 "parser.y"
                        {
          Node* n = create_node("Comp if");
          (yyval.node) = n;
          n->children.push_back((yyvsp[-1].node));
          n->children.push_back((yyvsp[0].node));
        }
#line 5335 "parser.cpp"
    break;

  case 264: /* yield_expr: YIELD  */
#line 2325 "parser.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 5341 "parser.cpp"
    break;


#line 5345 "parser.cpp"

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

#line 2334 "parser.y"



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

