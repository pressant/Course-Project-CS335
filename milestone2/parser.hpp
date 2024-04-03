/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    NAME = 258,                    /* NAME  */
    FLOAT = 259,                   /* FLOAT  */
    INDENT = 260,                  /* INDENT  */
    DEDENT = 261,                  /* DEDENT  */
    ENDMARKER = 262,               /* ENDMARKER  */
    NEWLINE = 263,                 /* NEWLINE  */
    FALSE_TOKEN = 264,             /* FALSE_TOKEN  */
    AWAIT = 265,                   /* AWAIT  */
    ELSE = 266,                    /* ELSE  */
    IMPORT = 267,                  /* IMPORT  */
    PASS = 268,                    /* PASS  */
    NONE = 269,                    /* NONE  */
    BREAK = 270,                   /* BREAK  */
    EXCEPT = 271,                  /* EXCEPT  */
    IN = 272,                      /* IN  */
    RAISE = 273,                   /* RAISE  */
    TRUE_TOKEN = 274,              /* TRUE_TOKEN  */
    CLASS = 275,                   /* CLASS  */
    FINALLY = 276,                 /* FINALLY  */
    IS = 277,                      /* IS  */
    RETURN = 278,                  /* RETURN  */
    AND = 279,                     /* AND  */
    CONTINUE = 280,                /* CONTINUE  */
    FOR = 281,                     /* FOR  */
    LAMBDA = 282,                  /* LAMBDA  */
    TRY = 283,                     /* TRY  */
    AS = 284,                      /* AS  */
    DEF = 285,                     /* DEF  */
    FROM = 286,                    /* FROM  */
    NONLOCAL = 287,                /* NONLOCAL  */
    WHILE = 288,                   /* WHILE  */
    ASSERT = 289,                  /* ASSERT  */
    DEL = 290,                     /* DEL  */
    GLOBAL = 291,                  /* GLOBAL  */
    NOT = 292,                     /* NOT  */
    WITH = 293,                    /* WITH  */
    ASYNC = 294,                   /* ASYNC  */
    ELIF = 295,                    /* ELIF  */
    IF = 296,                      /* IF  */
    OR = 297,                      /* OR  */
    YIELD = 298,                   /* YIELD  */
    NUMBER = 299,                  /* NUMBER  */
    STRING = 300,                  /* STRING  */
    PLUS = 301,                    /* PLUS  */
    MINUS = 302,                   /* MINUS  */
    TIMES = 303,                   /* TIMES  */
    POWER = 304,                   /* POWER  */
    DIVIDEDBY = 305,               /* DIVIDEDBY  */
    FLOORDIV = 306,                /* FLOORDIV  */
    MODULO = 307,                  /* MODULO  */
    AT = 308,                      /* AT  */
    SHIFT_LEFT = 309,              /* SHIFT_LEFT  */
    SHIFT_RIGHT = 310,             /* SHIFT_RIGHT  */
    BITWISE_AND = 311,             /* BITWISE_AND  */
    BITWISE_OR = 312,              /* BITWISE_OR  */
    BITWISE_XOR = 313,             /* BITWISE_XOR  */
    BITWISE_NOT = 314,             /* BITWISE_NOT  */
    LESS_THAN = 315,               /* LESS_THAN  */
    GREATER_THAN = 316,            /* GREATER_THAN  */
    LESS_THAN_OR_EQUAL = 317,      /* LESS_THAN_OR_EQUAL  */
    GREATER_THAN_OR_EQUAL = 318,   /* GREATER_THAN_OR_EQUAL  */
    EQUAL = 319,                   /* EQUAL  */
    NOT_EQUAL = 320,               /* NOT_EQUAL  */
    LPAREN = 321,                  /* LPAREN  */
    RPAREN = 322,                  /* RPAREN  */
    LBRACKET = 323,                /* LBRACKET  */
    RBRACKET = 324,                /* RBRACKET  */
    LBRACE = 325,                  /* LBRACE  */
    RBRACE = 326,                  /* RBRACE  */
    COMMA = 327,                   /* COMMA  */
    COLON = 328,                   /* COLON  */
    DOT = 329,                     /* DOT  */
    SEMICOLON = 330,               /* SEMICOLON  */
    EQUAL_SIGN = 331,              /* EQUAL_SIGN  */
    ARROW = 332,                   /* ARROW  */
    PLUS_EQUAL = 333,              /* PLUS_EQUAL  */
    MINUS_EQUAL = 334,             /* MINUS_EQUAL  */
    TIMES_EQUAL = 335,             /* TIMES_EQUAL  */
    DIVIDEDBY_EQUAL = 336,         /* DIVIDEDBY_EQUAL  */
    FLOORDIV_EQUAL = 337,          /* FLOORDIV_EQUAL  */
    MODULO_EQUAL = 338,            /* MODULO_EQUAL  */
    AT_EQUAL = 339,                /* AT_EQUAL  */
    BITWISE_AND_EQUAL = 340,       /* BITWISE_AND_EQUAL  */
    BITWISE_OR_EQUAL = 341,        /* BITWISE_OR_EQUAL  */
    BITWISE_XOR_EQUAL = 342,       /* BITWISE_XOR_EQUAL  */
    SHIFT_RIGHT_EQUAL = 343,       /* SHIFT_RIGHT_EQUAL  */
    SHIFT_LEFT_EQUAL = 344,        /* SHIFT_LEFT_EQUAL  */
    POWER_EQUAL = 345,             /* POWER_EQUAL  */
    SINGLE_QUOTE = 346,            /* SINGLE_QUOTE  */
    DOUBLE_QUOTE = 347,            /* DOUBLE_QUOTE  */
    HASH = 348,                    /* HASH  */
    BACKSLASH = 349,               /* BACKSLASH  */
    DOLLAR = 350,                  /* DOLLAR  */
    QUESTION_MARK = 351,           /* QUESTION_MARK  */
    BACKTICK = 352,                /* BACKTICK  */
    TRIPLEDOT = 353,               /* TRIPLEDOT  */
    RANGE = 354                    /* RANGE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 70 "parser.y"

  
 
	struct Node* node;
  


#line 171 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
