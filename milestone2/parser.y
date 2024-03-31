%{
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
using namespace std;
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern int yylex();
void yyerror(const char*);
int yybye =0;
Node *root = create_node("File_input");
SYMTAB* tab=new SYMTAB();
SYMTAB* gt=tab;
int curr_scope=tab->SYMSCOPE;
std::string* target_program;
%}



%union {
  
 
	struct Node* node;
  

}


%define parse.error verbose

/*
 * These are all of the terminals in our grammar, i.e. the syntactic
 * categories that can be recognized by the lexer.
 */
%token<node> NAME FLOAT INDENT DEDENT ENDMARKER NEWLINE
%token<node> FALSE_TOKEN AWAIT ELSE IMPORT PASS NONE BREAK EXCEPT IN RAISE TRUE_TOKEN CLASS FINALLY IS RETURN AND CONTINUE FOR LAMBDA TRY
%token<node> AS DEF FROM NONLOCAL WHILE ASSERT DEL GLOBAL NOT WITH ASYNC ELIF IF OR YIELD NUMBER STRING

%token<node> PLUS MINUS TIMES POWER DIVIDEDBY FLOORDIV MODULO AT SHIFT_LEFT SHIFT_RIGHT BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_NOT
%token<node> LESS_THAN GREATER_THAN LESS_THAN_OR_EQUAL GREATER_THAN_OR_EQUAL EQUAL NOT_EQUAL LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE

%token<node> COMMA COLON DOT SEMICOLON EQUAL_SIGN ARROW PLUS_EQUAL MINUS_EQUAL TIMES_EQUAL DIVIDEDBY_EQUAL FLOORDIV_EQUAL MODULO_EQUAL AT_EQUAL BITWISE_AND_EQUAL BITWISE_OR_EQUAL BITWISE_XOR_EQUAL SHIFT_RIGHT_EQUAL SHIFT_LEFT_EQUAL POWER_EQUAL
%token<node> SINGLE_QUOTE DOUBLE_QUOTE HASH BACKSLASH DOLLAR QUESTION_MARK BACKTICK TRIPLEDOT RANGE
%type <node> simple_stmt compound_stmt eval_input 

%type<node> arglist_opt funcdef augassign file_input newline_stat_rep new_line return_annotation_opt typedargslist_opt datatype SEMI_opt augassign_op
%type<node> testlist_star_expr_rep return_stmt_opt stmt_rep star_expr expr_rep expr shift_expr_rep_c1 arith_expr_rep_c1 term_rep_c1 testlist_comp_c2_rep COMMA_opt sliceop_opt

%type<node> parameters typedargslist expr_star_expr funcname
%type<node> stmt small_stmt_list small_stmt expr_stmt expr_stmt_tail annassign rep_expr_stmt_tail rep_expr_stmt_tail_op annasign_op testlist_star_expr testlist_star_expr_opt1 testlist_star_expr_opt2
%type<node> del_stmt pass_stmt flow_stmt break_stmt continue_stmt return_stmt yield_stmt raise_stmt raise_stmt_opt raise_stmt_opt_opt import_stmt import_name import_from import_from_c1 import_from_c2
%type<node> import_as_name dotted_as_name AS_name_opt import_as_names import_as_name_c1 dotted_as_names dotted_as_names_list dotted_name dotted_name_list global_stmt global_name_list nonlocal_stmt
%type<node> nonlocal_name_list assert_stmt assert_stmt_opt if_stmt else_suite_opt elif_stmt_rep while_stmt for_stmt try_stmt try_stmt_c1 try_stmt_c1_rep finally_suite_opt except_clause suite
%type<node> test test_opt test_nocond or_test or_test_rep and_test and_test_rep not_test comparison comparison_rep comp_op xor_expr xor_expr_rep and_expr and_expr_rep
%type<node> shift_expr shift_expr_rep arith_expr arith_expr_rep term term_rep factor factor_c1 power power_opt atom_expr await_opt trailer trailer_rep atom atom_opt1 atom_opt2 string_rep
%type<node> testlist_comp testlist_comp_c1 testlist_comp_c2 subscriptlist COMMA_subscript_rep subscript test_opt1 sliceop exprlist COMMA_expr_star_expr_rep testlist COMMA_test_rep
%type<node>  test_star_expr classdef classdef_opt1 arglist COMMA_argument_rep argument comp_for_opt comp_iter sync_comp_for
%type<node> comp_iter_opt comp_for ASYNC_opt comp_if encoding_decl yield_expr yield_arg async_stmt with_stmt


%left OR
%left AND
%left PLUS MINUS
%left TIMES DIVIDEDBY
%left EQUAL NOT_EQUAL GREATER_THAN GREATER_THAN_OR_EQUAL LESS_THAN LESS_THAN_OR_EQUAL
%right NOT

%start file_input

%%

file_input
  : newline_stat_rep ENDMARKER {
    if(yybye) cout<<"LINE 107";
    $$ = root;
    root->children.push_back($1);
    root->children.push_back($2);
    cout<< "start of file" << endl; 
  }
  | ENDMARKER {
    if(yybye) cout<<"LINE 115";
    $$ = NULL;
    }
;

newline_stat_rep 
  : newline_stat_rep NEWLINE {
    if(yybye) cout<<"LINE 119";
    Node* n = create_node("newline_stat_rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
  }
  | newline_stat_rep stmt { 
    if(yybye) cout<<"LINE 126";
    Node* n = create_node("newline_stat_rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
  }
  | stmt { $$ = $1 ; if(yybye) cout<<"LINE 132"; $$ = $1;}
  | NEWLINE {  if(yybye) cout<<"LINE 133"; cout<<yylineno<<endl;};

funcname : DEF NAME {
            Node* n = create_node($2->label);
            n->children.push_back($1);
            n->children.push_back($2);
            $$ = n;
            if(tab->SYMVAL.find($2->label)== tab->SYMVAL.end()){
                tab->SYMVAL[$2->label].identity=FUNC;
                tab->SYMVAL[$2->label].scope=curr_scope;
                tab->SYMVAL[$2->label].line_no=yylineno;
               cout<<tab->SYMVAL[$2->label].name<<endl;
               SYMTAB* newtab=new SYMTAB();
               newtab->SYMSCOPE=++curr_scope;
               newtab->parent=tab;
               tab->childs.push_back(newtab);
               tab=newtab;
             }
          }
         ;

funcdef :  funcname parameters ARROW test COLON suite {
             Node* n = create_node("Function");
             n->children.push_back($1);
             n->children.push_back($2);
             n->children.push_back($3);
             n->children.push_back($4);
             n->children.push_back($5);
             n->children.push_back($6);
             $$ =n;
             tab=tab->parent;
             if(tab->SYMVAL.find($1->label)!= tab->SYMVAL.end()){
                tab->SYMVAL[$1->label].identity=FUNC;
                tab->SYMVAL[$1->label].scope=curr_scope;
                tab->SYMVAL[$1->label].line_no=yylineno;
                tab->SYMVAL[$1->label].type=$4->label;
                tab->SYMVAL[$1->label].name=$1->label;
                tab->SYMVAL[$1->label].size=$2->count;
                //int g_index;
                //int reg_name;
                for(int i=0;i<$3->children.size();i++){
                  Node* t=$3->children[i];
                  string temp=t->label;
                   if(temp!="[" && temp!="]"){
                      tab->SYMVAL[$2->label].params=$3->p_f;
                   }
                }
              
             }
             else{
              cout<<"error";
              exit(0);
             }
         }
       | funcname parameters COLON suite {
             Node* n = create_node("Function");
             n->children.push_back($1);
             n->children.push_back($2);
             n->children.push_back($3);
             n->children.push_back($4);
             $$ =n;
             tab=tab->parent;
             if(tab!=NULL){

               if(tab->SYMVAL.find($1->label)!= tab->SYMVAL.end()){
                  tab->SYMVAL[$1->label].identity=FUNC;
                  tab->SYMVAL[$1->label].scope=curr_scope;
                  tab->SYMVAL[$1->label].line_no=yylineno;
                  tab->SYMVAL[$1->label].type="void";
                  tab->SYMVAL[$1->label].name=$1->label;
                  tab->SYMVAL[$1->label].size=$2->count;
                  //int g_index;
                  //int reg_name;
                  for(int i=0;i<$3->children.size();i++){
                    Node* t=$3->children[i];
                    string temp=t->label;
                     if(temp!="[" && temp!="]"){
                        tab->SYMVAL[$2->label].params=$3->p_f;
                     }
                  }

               }
               else{
                cout<<"error";
                exit(0);
               }
             }
             
         }
       ;

parameters : LPAREN typedargslist RPAREN {
                Node* n = create_node("Parameters");
                n->children.push_back($1);
                n->children.push_back($2);
                n->children.push_back($3);
                n->count=$2->count;
                n->p_f=$2->p_f;
                $$=n;
            }
           | LPAREN RPAREN {
                $$ = create_node("Parameters");
                $$->children.push_back($1);
                $$->children.push_back($2);
            }
           ;

typedargslist : NAME {
                  Node *n = create_node("Typedargslist");
                  n->children.push_back($1);
                  Param* temp=new Param();
                  temp->par_name=$1->label;
                  n->p_f.push_back(temp);
                  n->count=1;
                  $$=n;
                  } 
                 | NAME COLON datatype {
                  if(yybye) cout<<"LINE 188";
                  Node *n = create_node("Typedargslist");
                  n->children.push_back($1);
                  n->children.push_back($2);
                  n->children.push_back($3);
                  n->count=1;
                  Param* temp=new Param();
                  temp->par_type=$3->label;
                  temp->par_name=$1->label;
                  n->p_f.push_back(temp);
                if(tab->SYMVAL.find($1->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared"<<$1->label<<endl;
                  return 0;
                }
                 tab->SYMVAL[$1->label].identity=NORMIE;
                  tab->SYMVAL[$1->label].scope=curr_scope;
                  tab->SYMVAL[$1->label].line_no=yylineno;
                  tab->SYMVAL[$1->label].type=$3->label;
                  tab->SYMVAL[$1->label].name=$1->label;
                  tab->SYMVAL[$1->label].size=0;
                  $$ = n;
                }
              | NAME COMMA typedargslist {
                  if(yybye) cout<<"LINE 196";
                  Node *n = create_node("Typedargslist");
                  n->children.push_back($1);
                  n->children.push_back($2);
                  for(int i=0; i<$3->children.size(); i++) {
                    n->children.push_back($3->children[i]);
                  }
                  $$ = n;
                  n->count=1+$3->count;
                  Param* temp=new Param();
                  temp->par_type=$1->label;
                  vector<Param*> t2;
                  t2.push_back(temp);
                  t2.insert(t2.end(),$3->p_f.begin(),$3->p_f.end());
                  n->p_f=t2;
                }
              | NAME COLON datatype COMMA typedargslist {
                  if(yybye) cout<<"LINE 203";
                  Node *n = create_node("Typedargslist");
                  n->children.push_back($1);
                  n->children.push_back($2);
                  n->children.push_back($3);
                  n->children.push_back($4);
                  for(int i=0; i<$5->children.size(); i++) {
                    n->children.push_back($5->children[i]);
                  }
                  $$ = n;
                  n->count=1+$5->count;
                  Param* temp=new Param();
                  temp->par_type=$3->label;
                  temp->par_name=$1->label;
                  vector<Param*> t2;
                  t2.push_back(temp);
                  t2.insert(t2.end(),$3->p_f.begin(),$3->p_f.end());
                  n->p_f=t2;
                  if(tab->SYMVAL.find($1->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared"<<$1->label<<endl;
                  return 0;
                }
                 tab->SYMVAL[$1->label].identity=NORMIE;
                  tab->SYMVAL[$1->label].scope=curr_scope;
                  tab->SYMVAL[$1->label].line_no=yylineno;
                  tab->SYMVAL[$1->label].type=$3->label;
                  tab->SYMVAL[$1->label].name=$1->label;
                  tab->SYMVAL[$1->label].size=0;
                  $$ = n;
                }
              ;

datatype : NAME {
              if(yybye) cout<<"LINE 215";
              Node *n = create_node("Datatype");
              n->children.push_back($1);
              n->label=$1->label;
              $$ = n;
            }
         | NAME LBRACKET NAME RBRACKET {
              if(yybye) cout<<"LINE 222";
              Node *n = create_node("Datatype");
              n->children.push_back($1);
              n->children.push_back($2);
              n->children.push_back($3);
              n->children.push_back($4);
              n->label=$1->label+$2->label+$3->label+$4->label;
              $$ = n;
            }
         ;
stmt  
        : simple_stmt { if(yybye) cout<<"LINE 231 \n";$$=$1;}
        | compound_stmt{if(yybye) cout<<"LINE 232 \n";$$=$1;}
;

simple_stmt : small_stmt NEWLINE{
              if(yybye) cout<<"LINE 235 \n";
               Node* n = create_node("simple_stmt");
               n->children.push_back($1);
               $$=n;
            }
            |small_stmt small_stmt_list NEWLINE{

                if(yybye) cout<<"LINE 241 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back($1);
                n->children.push_back($2);
                $$=n;
              }
            |small_stmt SEMICOLON NEWLINE{
                if(yybye) cout<<"LINE 242 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back($1);
                n->children.push_back($2);
                $$=n;
              }
            |small_stmt small_stmt_list SEMICOLON NEWLINE{
                if(yybye) cout<<"LINE 243 \n";
                Node* n =create_node("simple_stmt");
                n->children.push_back($1);
                n->children.push_back($2);
                n->children.push_back($3);              
              }
;
small_stmt_list : 
                  small_stmt_list SEMICOLON small_stmt{
                  if(yybye) cout<<"LINE 247 \n";
                  Node* n =create_node("small_stmt_list");
                  for(int i=0; i<$1->children.size(); i++){
                    n->children.push_back($1->children[i]);
                  }
                  n->children.push_back($2);
                  n->children.push_back($3);
                  $$=n;
                }
                | SEMICOLON small_stmt{
                  if(yybye) cout<<"LINE 255 \n";
                  Node* n =create_node("small_stmt_list");
                  n->children.push_back($1);
                  n->children.push_back($2);
                  $$=n;
                }
;
small_stmt : expr_stmt{if(yybye) cout<<"LINE 262 \n"; $$=$1;}
           | del_stmt{$$=$1;}
           | pass_stmt{$$=$1;}
           | flow_stmt{$$=$1;}
            | global_stmt{$$=$1;}
           ;
expr_stmt : testlist_star_expr expr_stmt_tail{ 
              Node* n =create_node("expr_stmt");
              n->children.push_back($1);
              n->children.push_back($2);
              if($2->label=="annassign"){
                if(tab->SYMVAL.find($1->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared"<<$1->label<<endl;
                  return 0;
                }
                 tab->SYMVAL[$1->label].identity=NORMIE;
                  tab->SYMVAL[$1->label].scope=curr_scope;
                  tab->SYMVAL[$1->label].line_no=yylineno;
                  tab->SYMVAL[$1->label].type=$2->type;
                  tab->SYMVAL[$1->label].name=$2->label;
                  tab->SYMVAL[$1->label].size=0;
              }
              $$=n;
             }
             |testlist_star_expr { $$ = $1;}
          ;

expr_stmt_tail : annassign {
                  $$=$1;
                  }
               | augassign augassign_op {
                  Node* n =create_node("expr_stmt_tail");
                  n->children.push_back($1);
                  n->children.push_back($2);
                  $$=n;
               }
               | rep_expr_stmt_tail{
                   $$=$1;
               }
               ;
augassign_op : yield_expr{$$=$1;}
             | testlist{$$=$1;}
             ;
rep_expr_stmt_tail : rep_expr_stmt_tail EQUAL_SIGN rep_expr_stmt_tail_op { 
                      Node* n =create_node("rep_expr_stmt_tail");
                      for(int i=0; i<$1->children.size(); i++){
                        n->children.push_back($1->children[i]);
                      }
                      n->children.push_back($2);
                      n->children.push_back($3);
                      $$=n;
                     }
                    |EQUAL_SIGN rep_expr_stmt_tail_op {
                      Node* n =create_node("rep_expr_stmt_tail");
                      n->children.push_back($1);
                      n->children.push_back($2);
                      $$=n;
                    }
                   ;
rep_expr_stmt_tail_op : yield_expr{$$=$1;}
                      | testlist_star_expr{$$=$1;}
                      ;
annassign : COLON test annasign_op{
                  Node* n =create_node("annassign");
                  n->children.push_back($1);
                  n->children.push_back($2);
                  n->children.push_back($3);
                  n->type=$2->label;
                  $$=n;
                 }
            | COLON test 
          ;
annasign_op : EQUAL_SIGN test{
                  Node* n =create_node("annassign_op");
                   n->children.push_back($1);
                   n->children.push_back($2);
}
            | EQUAL_SIGN { $$=$1;}
            ;
testlist_star_expr : testlist_star_expr_opt1 testlist_star_expr_rep COMMA{
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back($1);
                     n->children.push_back($2);
                     n->children.push_back($3);
                     $$=n;
                    }
                    |testlist_star_expr_opt1 testlist_star_expr_rep{ 
                      Node* n =create_node("testlist_star_expr");
                      n->children.push_back($1);
                      n->children.push_back($2);
                    }
                    |testlist_star_expr_opt1 COMMA{
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back($1);
                     n->children.push_back($2);
                    }
                    |testlist_star_expr_opt1 { $$ = $1;}

                   ;

testlist_star_expr_opt1 : test{$$=$1;}
                        | star_expr{$$=$1;}
                        ;
testlist_star_expr_rep: 
      testlist_star_expr_rep COMMA testlist_star_expr_opt1{
      Node* n =create_node("testlist_star_expr_rep");
      for(int i=0; i<$1->children.size(); i++){
        n->children.push_back($1->children[i]);
      }
      n->children.push_back($2);
      n->children.push_back($3);
      $$=n;
  }
  | COMMA testlist_star_expr_opt1 {$$ = NULL;}
;
augassign : PLUS_EQUAL {$$=$1;}
          | MINUS_EQUAL {$$=$1;}
          | TIMES_EQUAL {$$=$1;}
          | AT_EQUAL {$$=$1;}
          | DIVIDEDBY_EQUAL {$$=$1;}
          | MODULO_EQUAL {$$=$1;}
          | BITWISE_AND_EQUAL {$$=$1;}
          | BITWISE_OR_EQUAL {$$=$1;}
          | BITWISE_XOR_EQUAL {$$=$1;}
          | SHIFT_LEFT_EQUAL {$$=$1;}
          | SHIFT_RIGHT_EQUAL {$$=$1;}
          | POWER_EQUAL {$$=$1;}
          | FLOORDIV_EQUAL {$$=$1;}
          ;

del_stmt: DEL exprlist{Node* n =create_node("del_stmt");
                         n->children.push_back($1);
                         n->children.push_back($2);
                         $$=n;
                          }
        ;
pass_stmt: PASS{$$=$1;}
         ;
flow_stmt: break_stmt {$$=$1;}
         | continue_stmt {$$=$1;}
         | return_stmt {$$=$1;}
         | yield_stmt{$$=$1;}
         ;
         
break_stmt: BREAK{$$=$1;}
;
continue_stmt: CONTINUE{$$=$1;};
return_stmt: RETURN testlist{
              Node* n =create_node("return_stmt");
              n->children.push_back($1);
              n->children.push_back($2);      
              $$=n; 
            }
            | RETURN { $$ = $1;}
;
yield_stmt: yield_expr{$$=$1;};
global_stmt: GLOBAL global_name_list{
              Node* n =create_node("global_stmt");
              n->children.push_back($1);
              n->children.push_back($2);      
              $$=n; 
            }
            ;
global_name_list: global_name_list COMMA NAME {
                  Node* n =create_node("global_name_list");
                  for(int i=0; i<$1->children.size(); i++){
                    n->children.push_back($1->children[i]);
                  }
                  n->children.push_back($2);
                  n->children.push_back($3);
                  
                  $$=n;
                }
                | NAME { $$ = $1;}
                ;
compound_stmt : if_stmt{if(yybye) cout<<"cmpd_stmnt 1 \n"; $$=$1;}
              | while_stmt{$$=$1;}
              | for_stmt{$$=$1;}
              | funcdef{if(yybye) cout<<"cmpd_stmnt \n"; $$=$1;}
              | classdef{$$=$1;}
              | async_stmt{$$=$1;}
              ;

async_stmt : ASYNC async_stmt_content
           ;

async_stmt_content : funcdef
                   | for_stmt
                   ;

if_stmt : IF test COLON suite elif_stmt_rep ELSE COLON suite{
    if(yybye) cout<<" if_stmt: \n";
    Node* n=create_node("if_stmt");
    n->children.push_back($1);
    n->children.push_back($2); 
    n->children.push_back($3);
    n->children.push_back($4); 
    n->children.push_back($5);
    n->children.push_back($6); 
    n->children.push_back($7);
    n->children.push_back($8); 
    $$=n;
  }
    | IF test COLON suite elif_stmt_rep{

      if(yybye) cout<<"if_stmt 2: \n"; 
      Node* n=create_node("if_stmt");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      n->children.push_back($5);
      $$=n;
  }
    | IF test COLON suite ELSE COLON suite{ 
      Node* n=create_node("if_stmt");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      n->children.push_back($5);
      n->children.push_back($6); 
      n->children.push_back($7);
      $$=n;
    }
    | IF test COLON suite{ 
      Node* n=create_node("if_stmt");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      $$=n;
    }
;
elif_stmt_rep : elif_stmt_rep ELIF test COLON suite {
      Node* n=create_node("elif_stmt_rep");
      for(int i=0; i<$1->children.size(); i++){
        n->children.push_back($1->children[i]);
      }
      n->children.push_back($2); 
      n->children.push_back($3);
       n->children.push_back($4); 
      n->children.push_back($5);
      $$=n; 
    }
    | ELIF test COLON suite{ 
      Node* n=create_node("elif_stmt_rep");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      $$=n;
    }
;
while_stmt: WHILE test COLON suite ELSE COLON suite{
      Node* n=create_node("while_stmt");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      n->children.push_back($5);
      n->children.push_back($6);
      n->children.push_back($7);
      $$=n; 
    }
  | WHILE test COLON suite { 
      Node* n=create_node("while_stmt");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      $$=n;
  }
;
for_stmt: FOR exprlist IN testlist COLON suite ELSE COLON suite{
      Node* n=create_node("for_stmt");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      n->children.push_back($5);
      n->children.push_back($6);
      n->children.push_back($7);
      n->children.push_back($8);
      n->children.push_back($9);
      $$=n; 
    }
    | FOR exprlist IN testlist COLON suite {
      Node* n=create_node("while_stmt");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      n->children.push_back($5);
      n->children.push_back($6);
      $$=n;
    }
;
suite : simple_stmt {if(yybye) cout<<"LINE 462 \n"; $$ = $1;}
      | NEWLINE INDENT stmt_rep DEDENT{
        Node* n = create_node("Suite");
        $$ = n;
        n->children.push_back($2);
        n->children.push_back($3);
        n->children.push_back($4);
      }
; 
stmt_rep : 
            stmt_rep stmt  {
            Node* n = create_node("Multi Statements");
            $$ = n;
            for(int i=0; i<$1->children.size(); i++){
              n->children.push_back($1->children[i]);
            }
            n->children.push_back($2);
          }
          | stmt {$$=$1; }
;
test : or_test IF or_test ELSE test {
      Node* n = create_node("Test");
      $$ = n;
      n->children.push_back($1);
      n->children.push_back($2);
      n->children.push_back($3);
      n->children.push_back($4);
      n->children.push_back($5);
}
| or_test{$$=$1;}
;
test_nocond : 
  or_test {$$ = $1;}
;          
or_test : 
  and_test or_test_rep
  {
    Node* n = create_node("OR Test");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  |and_test{$$=$1;}
;
or_test_rep : 
  or_test_rep OR and_test  {
    Node* n = create_node("ORTestRep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
  | OR and_test{Node* n = create_node("ORTestRep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);}
;
and_test : 
  not_test and_test_rep{
    Node* n = create_node("And Test");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  |not_test{$$=$1;}
;
and_test_rep : 
  and_test_rep AND not_test 
  {
    Node* n = create_node("AndTestRep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
  | AND not_test{Node* n = create_node("AndTestRep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);}
;

not_test : 
  NOT not_test 
  {
    Node* n = create_node("Not Test");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | comparison {
    $$ =$1;
  }
;
comparison :
  expr comparison_rep{
    Node* n = create_node("Comparison");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  |expr{$$=$1;}
;

comparison_rep : 
  comparison_rep comp_op expr {
    Node* n = create_node("Comparison Rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
 | comp_op expr {
   Node* n = create_node("Comparison Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
 }
;
comp_op : LESS_THAN{$$ =$1;}
        |GREATER_THAN {$$ =$1;}
        |EQUAL {$$ =$1;}
        |GREATER_THAN_OR_EQUAL {$$ =$1;}
        |LESS_THAN_OR_EQUAL {$$ =$1;}
        |NOT_EQUAL {$$ =$1;}
        |IN {$$ =$1;}
        |NOT IN {
          Node* n = create_node("Comparison Operator");
          $$ = n;
          n->children.push_back($1);
          n->children.push_back($2);
        }
        |IS {$$ =$1;}
        |IS NOT{
          Node* n = create_node("Comparison Operator");
          $$ = n;
          n->children.push_back($1);
          n->children.push_back($2);
        }
        ;
star_expr :
  TIMES expr{
    Node* n = create_node("Star Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
;
expr:
  xor_expr expr_rep{
    Node* n = create_node("Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | xor_expr{$$=$1;}
;
expr_rep : 
  expr_rep BITWISE_OR xor_expr {
    Node* n = create_node("Expression Rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
  | BITWISE_OR xor_expr{Node* n = create_node("Expression Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);} 
;
xor_expr: 
  and_expr xor_expr_rep{
    Node* n = create_node("XOR Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | and_expr{
    $$=$1;
  }
;
xor_expr_rep : 
  xor_expr_rep BITWISE_XOR and_expr {
    Node* n = create_node("XOR Expression Rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
 | BITWISE_XOR and_expr{Node* n = create_node("XOR Expression Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);} 
;
and_expr: 
  shift_expr and_expr_rep{
    Node* n = create_node("AND Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | shift_expr{$$=$1;}
;
and_expr_rep :
  and_expr_rep BITWISE_AND shift_expr {
    Node* n = create_node("AND Expression Rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3); 
  }
  |BITWISE_AND shift_expr{Node* n = create_node("AND Expression Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2); }
;
shift_expr :
  arith_expr shift_expr_rep{
    Node* n = create_node("Shift Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | arith_expr{$$=$1;}
;
shift_expr_rep : 
  shift_expr_rep shift_expr_rep_c1 arith_expr {
    Node* n = create_node("Shift Expression Rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
  | shift_expr_rep_c1 arith_expr{Node* n = create_node("Shift Expression Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);}
;
shift_expr_rep_c1 : 
  SHIFT_LEFT{
    $$ = $1;
  }
  | SHIFT_RIGHT {$$ = $1;}
;
arith_expr : 
  term arith_expr_rep{
    Node* n = create_node("Arithmetic Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  |term { if(yybye) cout<<"term arith_expr: "<<endl;$$=$1;}
;
arith_expr_rep : 
  arith_expr_rep arith_expr_rep_c1 term {
    Node* n = create_node("Arithmetic Expression Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
  }
  |arith_expr_rep_c1 term{Node* n = create_node("Arithmetic Expression Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);}
;
arith_expr_rep_c1 : 
  PLUS { $$ = $1;}
  | MINUS { $$ = $1;}
;
term : 
  factor term_rep{
    if(yybye) cout<<"term factor term_rep: "<<endl;
    Node* n = create_node("TERM");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  |factor{if(yybye) cout<<"factor term: "<<endl;$$=$1;}
;
term_rep : 
   term_rep term_rep_c1 factor {
    Node* n = create_node("TERM Rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
  | term_rep_c1 factor { Node* n = create_node("TERM Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);}
;
term_rep_c1 : TIMES { $$ =$1;}
            | AT { $$ =$1;}
            | DIVIDEDBY { $$ =$1;}
            | MODULO { $$ =$1;}
            | FLOORDIV { $$ =$1;}
;
factor : 
  factor_c1 factor {
    Node* n = create_node("Factor");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | power { if(yybye) cout<<"factor power: "<<endl;$$ = $1;}
;
factor_c1 : PLUS { $$ =$1;} 
          | MINUS { $$ =$1;}
          | BITWISE_NOT { $$ =$1;}
          ;
power : 
  atom_expr power_opt{
    Node* n = create_node("Power");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | atom_expr{
    $$ = $1;
    if(yybye) cout<<"atom_expr power: "<<endl;$$=$1;
  }
;
power_opt : 
  POWER factor {
    Node* n = create_node("Power Opt");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
;
atom_expr : 
  await_opt atom trailer_rep{
    Node* n = create_node("Atom Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
  }
  |atom trailer_rep{
    Node* n = create_node("Atom Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    if(yybye) cout<<"atom trailer_rep atom_expr: "<<endl;
  }
  |atom{
    $$ = $1;
    if(yybye) cout<<"atom_expr atom: "<<endl; 
  }
;
await_opt : AWAIT {
  $$ = $1;
}
;
trailer_rep : 
  trailer_rep trailer {
    if(yybye) cout<<"trailer_rep: "<<endl;
    Node* n = create_node("Trailer Rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
  }
  | trailer { 
    $$ =$1;
  }
;
atom : LPAREN atom_opt1 RPAREN {
        if(yybye) cout<<"atom atom_opt1: "<<endl;
        Node* n = create_node("Atom");
        $$ = n;
        n->children.push_back($1);
        n->children.push_back($2);
        n->children.push_back($3);
      }
      | LBRACKET atom_opt2 RBRACKET {
        if(yybye) cout<<"atom atom_opt2: "<<endl;
        Node* n = create_node("Atom");
        $$ = n;
        n->children.push_back($1);
        n->children.push_back($2);
        n->children.push_back($3);
      }
      |LBRACKET RBRACKET { 
        if(yybye) cout<<"atom : "<<endl;
        Node* n = create_node("Atom");
        $$ = n;
        n->children.push_back($1);
        n->children.push_back($2);
      }
      | NAME  { $$ =$1;}
      | NUMBER  { $$ =$1;}
      | FLOAT {$$ = $1;}
      | string_rep { $$ = $1;} 
      | TRIPLEDOT  { $$ =$1;}
      | NONE  { $$ =$1;}
      | TRUE_TOKEN  { $$ =$1;}
      | FALSE_TOKEN { $$ =$1;}
      ;
atom_opt1 : yield_expr {$$ = $1;}
          | testlist_comp{$$ = $1; if(yybye) cout<<"atom_opt1 testlist_comp: "<<endl;}
          ;
atom_opt2 : testlist_comp{$$ =$1;}
          ;
string_rep : 
  STRING { $$ = $1;}
  | string_rep STRING {
    Node* n = create_node("String Rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);    
  }
;
testlist_comp :
  testlist_comp_c1 testlist_comp_c2{
    Node* n = create_node("Testlist comp");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  |testlist_comp_c1{$$ =$1;}
;
testlist_comp_c1 : 
    test {$$ = $1;}
  | star_expr {$$ = $1;}
;
testlist_comp_c2 : 
  comp_for {$$ = $1;}
  | testlist_comp_c2_rep COMMA{
    Node* n = create_node("Testlist Comp C2");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | COMMA{$$ =$1;}
  | testlist_comp_c2_rep{$$ =$1;}
  ;
testlist_comp_c2_rep : 
  testlist_comp_c2_rep COMMA test 
  {
    Node* n = create_node("Testlist Comp C2 rep");
    $$ = n;
    for(int i = 0; i < $1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
  |testlist_comp_c2_rep COMMA star_expr {
    Node* n = create_node("Testlist Comp C2 rep");
    $$ = n;
    for(int i = 0; i < $1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
  |COMMA test{
    Node* n = create_node("Testlist Comp C2 rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | COMMA star_expr { 
    Node* n = create_node("Testlist Comp C2 rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
;
trailer :
  LPAREN arglist RPAREN{
    if(yybye) cout<<"trailer: "<<endl;
    Node* n = create_node("Trailer");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
  }
  |LPAREN RPAREN{
    Node* n = create_node("Trailer");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | LBRACKET subscriptlist RBRACKET {
    Node* n = create_node("Trailer");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
  }
  |LBRACKET RBRACKET{ 
    Node* n = create_node("Trailer");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | DOT NAME{
    Node* n = create_node("Trailer");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
;
subscriptlist: 
  subscript COMMA_subscript_rep COMMA_opt{
    Node* n = create_node("Subscriptlist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);

  }
  |subscript COMMA_opt{
    Node* n = create_node("Subscriptlist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  };
  |subscript COMMA_subscript_rep{
    Node* n = create_node("Subscriptlist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  };
  |subscript {$$ =$1;}
;
COMMA_opt : 
  COMMA { $$ = $1;}
  ;

COMMA_subscript_rep : 
  COMMA_subscript_rep COMMA subscript {
    Node* n = create_node("Comma Subscript rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
  |COMMA subscript {
    Node* n = create_node("COMMA subscript rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
;
subscript : 
  test { $$ = $1;}
  | test COLON test sliceop{
    Node* n = create_node("Subscript");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    n->children.push_back($4);

  }
  | COLON test sliceop{
    Node* n = create_node("Subscript");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
  }
  | test COLON sliceop{
    Node* n = create_node("Subscript");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
  }
  | test COLON test{
    Node* n = create_node("Subscript");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
  }
  | COLON sliceop{
    Node* n = create_node("Subscript");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | COLON test{
    Node* n = create_node("Subscript");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | test COLON{
    Node* n = create_node("Subscript");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  } 
  |COLON {$$ =$1;}
;
sliceop : COLON test{
    Node* n = create_node("Slice OP");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
}
| COLON{$$ = $1;}
;
exprlist : expr_star_expr COMMA_expr_star_expr_rep COMMA{
    Node* n = create_node("Expr List");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
}
| expr_star_expr COMMA{
    Node* n = create_node("Expr List");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
}
| expr_star_expr COMMA_expr_star_expr_rep{
    Node* n = create_node("Expr List");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
}
| expr_star_expr{$$ =$1;}
;
expr_star_expr : expr {$$ = $1;}
               | star_expr {$$ = $1;}
;
COMMA_expr_star_expr_rep : 
  COMMA_expr_star_expr_rep COMMA expr_star_expr{
    Node* n = create_node("COMMA Expr star expr rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
  |COMMA expr_star_expr{ 
    Node* n = create_node("COMMA Expr star expr rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
;
testlist: 
  test COMMA_test_rep COMMA{
    Node* n = create_node("Testlist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
  }
  |test COMMA{
    Node* n = create_node("Testlist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  |test COMMA_test_rep{
    Node* n = create_node("Testlist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  |test {$$ =$1;}
;
COMMA_test_rep : 
  COMMA_test_rep COMMA test  {
    Node* n = create_node("Comma test rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
;
test_star_expr : test{ $$ = $1;}
               | star_expr{$$ = $1;}
               ;
classdef : CLASS NAME LPAREN arglist RPAREN COLON suite{
    Node* n = create_node("Class Def");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    n->children.push_back($4);
    n->children.push_back($5);
    n->children.push_back($6);
    n->children.push_back($7);
}
| CLASS NAME LPAREN RPAREN COLON suite{
    Node* n = create_node("Class Def");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    n->children.push_back($4);
    n->children.push_back($5);
    n->children.push_back($6);
}
| CLASS NAME COLON suite{
    Node* n = create_node("Class Def");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    n->children.push_back($4);
}
;
arglist : 
  argument COMMA_argument_rep COMMA{
    Node* n = create_node("Arglist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
  }
  | argument COMMA{
    Node* n = create_node("Arglist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | argument COMMA_argument_rep{
    Node* n = create_node("Arglist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  };
  |argument{$$ =$1;}
;
COMMA_argument_rep : 
  COMMA_argument_rep COMMA argument { 
    Node* n = create_node("Comma Argument rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
  }
  | COMMA argument {
    Node* n = create_node("Comma Argument rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
;
argument : 
  test comp_for{
    Node* n = create_node("Argument");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
  }
  | test EQUAL_SIGN test {
     Node* n = create_node("Argument");
     $$ = n;
     n->children.push_back($1);
     n->children.push_back($2);
  }
  | POWER test{
   Node* n = create_node("Argument");
   $$ = n;
   n->children.push_back($1);
   n->children.push_back($2);      
  }
  | TIMES test{
   Node* n = create_node("Argument");
   $$ = n;
   n->children.push_back($1);
   n->children.push_back($2);    
  }
  |test{$$ =$1;}
;
comp_iter : comp_for {$$ = $1;}
          | comp_if {$$ = $1;}
          ;
sync_comp_for : FOR exprlist IN or_test comp_iter{
          Node* n = create_node("Sync comp for");
          $$ = n;
          n->children.push_back($1);
          n->children.push_back($2);  
          n->children.push_back($3);
          n->children.push_back($4);   
          n->children.push_back($5);   
}
        | FOR exprlist IN or_test{
          Node* n = create_node("Sync comp for");
          $$ = n;
          n->children.push_back($1);
          n->children.push_back($2);  
          n->children.push_back($3);
          n->children.push_back($4);
        }
;
comp_for: ASYNC sync_comp_for{ 
          Node* n = create_node("Comp for");
          $$ = n;
          n->children.push_back($1);
          n->children.push_back($2);  }
        | sync_comp_for{$$=$1;}
        ;
comp_if : IF test_nocond comp_iter{
          Node* n = create_node("Comp if");
          $$ = n;
          n->children.push_back($1);
          n->children.push_back($2);
          n->children.push_back($3);
}
        | IF test_nocond{
          Node* n = create_node("Comp if");
          $$ = n;
          n->children.push_back($1);
          n->children.push_back($2);
        };
yield_expr: YIELD{$$=$1;};
yield_arg : FROM test{
          Node* n = create_node("yield arg");
          $$ = n;
          n->children.push_back($1);
          n->children.push_back($2);
}
          | testlist{$$=$1;}
          ;   
%%


int main(int argc, char* argv[]) {
    /* yybye = 1; */
    printf("hi");
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

