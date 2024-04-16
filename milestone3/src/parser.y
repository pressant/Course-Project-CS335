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

%type<node> parameters typedargslist expr_star_expr funcname decl_type
%type<node> stmt small_stmt_list small_stmt expr_stmt expr_stmt_tail annassign rep_expr_stmt_tail rep_expr_stmt_tail_op annasign_op testlist_star_expr testlist_star_expr_opt1 testlist_star_expr_opt2
%type<node> del_stmt pass_stmt flow_stmt break_stmt continue_stmt return_stmt yield_stmt raise_stmt raise_stmt_opt raise_stmt_opt_opt import_stmt import_name import_from import_from_c1 import_from_c2
%type<node> import_as_name dotted_as_name AS_name_opt import_as_names import_as_name_c1 dotted_as_names dotted_as_names_list dotted_name dotted_name_list global_stmt global_name_list nonlocal_stmt
%type<node> nonlocal_name_list assert_stmt assert_stmt_opt if_stmt else_suite_opt elif_stmt_rep while_stmt for_stmt try_stmt try_stmt_c1 try_stmt_c1_rep finally_suite_opt except_clause suite
%type<node> test test_opt test_nocond or_test or_test_rep and_test and_test_rep not_test comparison comparison_rep comp_op xor_expr xor_expr_rep and_expr and_expr_rep
%type<node> shift_expr shift_expr_rep arith_expr arith_expr_rep term term_rep factor factor_c1 power power_opt atom_expr await_opt trailer trailer_rep atom atom_opt1 atom_opt2 string_rep
%type<node> testlist_comp testlist_comp_c1 testlist_comp_c2 subscriptlist COMMA_subscript_rep subscript test_opt1 sliceop exprlist COMMA_expr_star_expr_rep testlist COMMA_test_rep
%type<node>  test_star_expr classdef classdef_opt1 arglist COMMA_argument_rep argument comp_for_opt comp_iter sync_comp_for
%type<node> comp_iter_opt comp_for ASYNC_opt comp_if yield_expr yield_arg async_stmt with_stmt class_name
%type<node> finalfunc range_func


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
    $$ = root;
    root->children.push_back($1);
    root->children.push_back($2);
  }
  | ENDMARKER {
    $$ = NULL;
    }
;

newline_stat_rep 
  : newline_stat_rep NEWLINE {
    Node* n = create_node("newline_stat_rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
  }
  | newline_stat_rep stmt { 
    Node* n = create_node("newline_stat_rep");
    $$ = n;
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
  }
  | stmt {  $$ = $1;}
  | NEWLINE {  
    // cout<<yylineno<<endl;
  };

funcname : DEF NAME {
            Node* n = create_node($2->label);
            n->children.push_back($1);
            n->children.push_back($2);
            $$ = n;
            $$->line_number = $1->line_number;
            if(tab->SYMVAL.find($2->label)== tab->SYMVAL.end()){
                tab->SYMVAL[$2->label].identity=FUNC;
                tab->SYMVAL[$2->label].scope=curr_scope;
                tab->SYMVAL[$2->label].line_no=$1->line_number;
              //  cout<<tab->SYMVAL[$2->label].name<<endl;
               SYMTAB* newtab=new SYMTAB();
               newtab->SYMSCOPE=++curr_scope;
               newtab->parent=tab;
               newtab->tab_type = FUNC;
              //  tab->childs.push_back(newtab);
               tab->childs[$2->label] = newtab;
               tab=newtab;
             }
             else {
              cout<<"Function redeclared in line no "<< $2->line_number<<endl;
                      //exit(1);;
             }
            // cout<<"funcname "<<$1->line_number<<endl;
          }
         ;

funcdef :  funcname parameters {
            codepush("begin",$1->label,"","",-1);
            SYMTAB* newt = new SYMTAB();
            newt = tab->parent;
            if(newt->SYMVAL.find($1->label)!= newt->SYMVAL.end())
            {
                newt->SYMVAL[$1->label].identity=FUNC;
                newt->SYMVAL[$1->label].scope=curr_scope;
                newt->SYMVAL[$1->label].line_no=$1->line_number;
                newt->SYMVAL[$1->label].name=$1->label;
                newt->SYMVAL[$1->label].size=$2->count;
                newt->SYMVAL[$1->label].params=$2->p_f;
            }
            for(int i=0;i<arguments.size();i++) { 
              string s1 = get<0>(arguments[i]);
              codepush("","popparam","",tab->SYMVAL[s1].temp_var,-1);
              codepush("",tab->SYMVAL[s1].temp_var,"",get<0>(arguments[i]),-1);}
            } 
            ARROW test {
            SYMTAB* newt = new SYMTAB();
            newt = tab->parent;
            if(newt->SYMVAL.find($1->label)!= newt->SYMVAL.end())
            {
                newt->SYMVAL[$1->label].identity=FUNC;
                newt->SYMVAL[$1->label].scope=curr_scope;
                newt->SYMVAL[$1->label].line_no=$1->line_number;
                newt->SYMVAL[$1->label].name=$1->label;
                newt->SYMVAL[$1->label].type=$5->type;
                newt->SYMVAL[$1->label].size=$2->count;
                newt->SYMVAL[$1->label].params=$2->p_f;
            }
            }COLON suite{
             Node* n = create_node("Function");
             n->children.push_back($1);
             n->children.push_back($2);
             n->children.push_back($4);
             n->children.push_back($5);
             n->children.push_back($7);
             n->children.push_back($8);
             $$ =n;
             tab=tab->parent;
             if(tab->SYMVAL.find($1->label)!= tab->SYMVAL.end()){
                tab->SYMVAL[$1->label].identity=FUNC;
                tab->SYMVAL[$1->label].scope=curr_scope;
                tab->SYMVAL[$1->label].line_no=$1->line_number;
                tab->SYMVAL[$1->label].type=$5->type;
                tab->SYMVAL[$1->label].name=$1->label;
                tab->SYMVAL[$1->label].size=$2->count;
                tab->SYMVAL[$1->label].params=$2->p_f;
             }

             else{
              cout<<"error in inserting function" << endl;
              //exit(1);;
             }
              if(($5->type == "bool" && $8->type == "int")||($5->type == "float" && $8->type =="int"))
              {

              }
              else {
                if($5->type != $8->type)cout<<"Function return ";
                check_type($5->type , $8->type , $1->line_number);
              }
             codepush("","$ra","","goto",-1);
             arguments.clear();
         }
       | funcname parameters{
             codepush("begin",$1->label,"","",-1);
            SYMTAB* newt = new SYMTAB();
            newt = tab->parent;
            if(newt->SYMVAL.find($1->label)!= newt->SYMVAL.end())
            {
                newt->SYMVAL[$1->label].identity=FUNC;
                newt->SYMVAL[$1->label].scope=curr_scope;
                newt->SYMVAL[$1->label].line_no=$1->line_number;
                newt->SYMVAL[$1->label].name=$1->label;
                newt->SYMVAL[$1->label].size=$2->count;
                newt->SYMVAL[$1->label].params=$2->p_f;
            }
        for(int i=0;i<arguments.size();i++) { 
        string s1 = get<0>(arguments[i]);
        codepush("","popparam","",tab->SYMVAL[s1].temp_var,-1);
        codepush("",tab->SYMVAL[s1].temp_var,"",get<0>(arguments[i]),-1);}} COLON suite {
             Node* n = create_node("Function");
             n->children.push_back($1);
             n->children.push_back($2);
             n->children.push_back($4);
             n->children.push_back($5);
             $$ =n;
             tab=tab->parent;
             if(tab!=NULL){

               if(tab->SYMVAL.find($1->label)!= tab->SYMVAL.end()){
                  tab->SYMVAL[$1->label].identity=FUNC;
                  tab->SYMVAL[$1->label].scope=curr_scope;
                  tab->SYMVAL[$1->label].line_no=$1->line_number;
                  tab->SYMVAL[$1->label].type="None";
                  tab->SYMVAL[$1->label].name=$1->label;
                  tab->SYMVAL[$1->label].size=$2->count;
                  tab->SYMVAL[$1->label].params=$2->p_f;
               }
               else{
                cout<<"error in inserting function "<<endl;
                exit(0);
               }
              if($5->type != "None")
              {
                if($5->type != "None") cout<<"Function return ";
                check_type($5->type , "None" , $1->line_number);
              }
            // check_type("void" , $3->type , $1->line_number);
             }
             codepush("","$ra","","goto",-1);
             arguments.clear();
         }
       ;
/* finalfunc : funcdef suite{
              Node* n = create_node("finalfunc");
              n->children.push_back($1);
              n->children.push_back($2);
              $$ = n;
              arguments.clear();
            }
            | funcdef NEWLINE suite{
              Node* n = create_node("finalfunc");
              n->children.push_back($1);
              n->children.push_back($2);
               n->children.push_back($3);
              $$ = n;
              arguments.clear();
            }
          ; */
parameters : LPAREN typedargslist RPAREN {
                Node* n = create_node("Parameters");
                n->children.push_back($1);
                n->children.push_back($2);
                n->children.push_back($3);
                n->count=$2->count;
                $$->line_number = $1->line_number;
                n->p_f=$2->p_f;
                $$=n;
            }
           | LPAREN RPAREN {
                $$ = create_node("Parameters");
                $$->children.push_back($1);
                $$->children.push_back($2);
                $$->line_number = $1->line_number;
            }
           ;

typedargslist : NAME {
                  Node *n = create_node("Typedargslist1");
                  n->children.push_back($1);
                  Param* temp=new Param();
                  temp->par_name=$1->label;
                  // cout<<tab->tab_type<<endl;
                  if((tab->parent->tab_type ==  CLS )&& ($1->label == "self")){ 
                    n->count = 0;
                  }
                  else{
                    n->p_f.push_back(temp);
                    n->count=1;
                  } 
                  $$=n;
                  arguments.push_back(make_tuple($1->label,"",$1->type,0,0));
                  } 
                 | NAME COLON datatype {
                  if(yybye) cout<<"LINE 188";
                  Node *n = create_node("Typedargslist2");
                  n->children.push_back($1);
                  n->children.push_back($2);
                  n->children.push_back($3);
                  n->count=1;
                  Param* temp=new Param();
                  temp->par_type=$3->label;
                  temp->par_name=$1->label;
                  n->p_f.push_back(temp);
                  if(tab->SYMVAL.find($1->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared "<<$1->label<<" in line no "<<$1->line_number<<endl;
                    //exit(1);;
                  }
                  tab->SYMVAL[$1->label].identity=NORMIE;
                  tab->SYMVAL[$1->label].scope=curr_scope;
                  tab->SYMVAL[$1->label].line_no=$1->line_number;
                  tab->SYMVAL[$1->label].type=$3->label;
                  tab->SYMVAL[$1->label].name=$1->label;
                  tab->SYMVAL[$1->label].size=0;
                  $$ = n;
                  string t = new_temporary();
                  tab->SYMVAL[$1->label].temp_var = t;
                  arguments.push_back(make_tuple($1->label,t,$3->type,0,0));
                }
              | NAME COMMA typedargslist {
                  Node *n = create_node("Typedargslist3");
                  n->children.push_back($1);
                  n->children.push_back($2);
                  for(int i=0; i<$3->children.size(); i++) {
                    n->children.push_back($3->children[i]);
                  }
                  $$ = n;
                  Param* temp=new Param();
                  temp->par_type=$1->label;
                  vector<Param*> t2;
                  if((tab->parent->tab_type == 3 )&& ($1->label == "self") )
                  {
                    n->count = $3->count;

                  }
                  else {
                    // cout<<"yes"<<endl;
                    n->count=1+$3->count;
                    t2.push_back(temp);
                  }

                  t2.insert(t2.end(),$3->p_f.begin(),$3->p_f.end());
                  // cout<<t2.size()<<endl;
                  n->p_f=t2;
                }
              | NAME COLON datatype COMMA typedargslist {
                  if(yybye) cout<<"LINE 203";
                  Node *n = create_node("Typedargslist4");
                  n->children.push_back($1);
                  n->children.push_back($2);
                  n->children.push_back($3);
                  n->children.push_back($4);
                  for(int i=0; i<$5->children.size(); i++) {
                    n->children.push_back($5->children[i]);
                  }
                  n->count=1+$5->count;
                  Param* temp=new Param();
                  temp->par_type=$3->label;
                  temp->par_name=$1->label;
                  vector<Param*> t2;
                  t2.push_back(temp);
                  t2.insert(t2.end(),$5->p_f.begin(),$5->p_f.end());
                  n->p_f=t2;
                  $$ = n;
                  if(tab->SYMVAL.find($1->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared "<<$1->label<<endl;
                  return 0;
                
                }
                 tab->SYMVAL[$1->label].identity=NORMIE;
                  tab->SYMVAL[$1->label].scope=curr_scope;
                  tab->SYMVAL[$1->label].line_no=$1->line_number;
                  tab->SYMVAL[$1->label].type=$3->label;
                  tab->SYMVAL[$1->label].name=$1->label;
                  tab->SYMVAL[$1->label].size=0;
                  $$ = n;
                string t = new_temporary();
                tab->SYMVAL[$1->label].temp_var = t;
                arguments.push_back(make_tuple($1->label,t,$3->type,0,0));
                }
              ;

datatype : NAME {
              Node *n = create_node("Datatype");
              n->children.push_back($1);
              n->label=$1->label;
              $$ = n;
            }
         | NAME LBRACKET NAME RBRACKET {
              Node *n = create_node("Datatype");
              n->children.push_back($1);
              n->children.push_back($2);
              n->children.push_back($3);
              n->children.push_back($4);
              n->label=$1->label+$2->label+$3->label+$4->label;
              n->type=$3->type;
              $$ = n;
            }
         ;
stmt  
        : simple_stmt { $$=$1;}
        | compound_stmt{$$=$1;}
;

simple_stmt : small_stmt NEWLINE{
               Node* n = create_node("simple_stmt");
               n->children.push_back($1);
               $$=n;
               $$->type = $1->type;
              //  cout<<" entered simple-stmt"<<yylineno<<<<endl;
               $$->line_number = $2->line_number;
            }
            |small_stmt small_stmt_list NEWLINE{

                Node* n =create_node("simple_stmt");
                n->children.push_back($1);
                n->children.push_back($2);
                $$=n;
                $$->line_number = $3->line_number;
              }
            |small_stmt SEMICOLON NEWLINE{
                Node* n =create_node("simple_stmt");
                n->children.push_back($1);
                n->children.push_back($2);
                $$=n;
                $$->line_number = $2->line_number;
              }
            |small_stmt small_stmt_list SEMICOLON NEWLINE{
                Node* n =create_node("simple_stmt");
                n->children.push_back($1);
                n->children.push_back($2);
                n->children.push_back($3);    
                $$->line_number = $3->line_number; 
                $$=n;         
              }
;
small_stmt_list : 
                  small_stmt_list SEMICOLON small_stmt{
                  Node* n =create_node("small_stmt_list");
                  for(int i=0; i<$1->children.size(); i++){
                    n->children.push_back($1->children[i]);
                  }
                  n->children.push_back($2);
                  n->children.push_back($3);
                  $$=n;
                  $$->line_number= $2->line_number;
                }
                | SEMICOLON small_stmt{
                  Node* n =create_node("small_stmt_list");
                  n->children.push_back($1);
                  n->children.push_back($2);
                  $$=n;
                  $$->line_number = $1->line_number;
                }
;
small_stmt : expr_stmt{ $$=$1;}
           | del_stmt{$$=$1;}
           | pass_stmt{$$=$1;}
           | flow_stmt{$$=$1;}
            | global_stmt{$$=$1;}
           ;
expr_stmt : testlist_star_expr expr_stmt_tail{ 
              
              Node* n =create_node("expr_stmt");
              n->children.push_back($1);
              n->children.push_back($2);
              $$=n;
              if($2->label=="annassign"){
                if(tab->SYMVAL.find($1->label)!=tab->SYMVAL.end()){
                  cout<<"Already declared "<<$1->label<<endl;
                  cout<<endl;
                          //exit(1);;
                }
                  tab->SYMVAL[$1->label].identity=NORMIE;
                  tab->SYMVAL[$1->label].scope=curr_scope;
                  tab->SYMVAL[$1->label].line_no=$1->line_number;
                  tab->SYMVAL[$1->label].type=$2->type;
                  tab->SYMVAL[$1->label].name=$2->label;
                  tab->SYMVAL[$1->label].size=0;
                  tab->SYMVAL[$1->label].temp_var = $2->temp_var;
              }
              else if($2->label == "expr_stmt_tail")
              {
                  if($1->type != $2->type)
                  {
                    if($1->type == "float" && $2->type == "int"){}
                    else if($1->type == "int" && $2->type=="bool"){}
                    else
                    {
                      check_type($1->type , $2->type, $2->line_number);
                    } 
                  }
              }
              else if(tab->SYMVAL.find($1->label)!=tab->SYMVAL.end())
              {
                check_type($1->type , $2->type, $2->line_number);
                // cout<<yylineno<<endl;
                // if($1->type != $2->type)
                // {
                //   cout<<"Different datatypes compared in line no "<<$1->line_no<<endl;
                //           //exit(1);;
                // }
              }
              else if($2->label=="annassign_op")
              {



                //this part to check expression like self.x
                if(($1->label == "self") && (tab->parent->tab_type == CLS) &&($1->p_f.size() ==1))
                {
                  // cout<<$1->p_f.size()<<" expr_stmt "<<endl;
                  if( tab->parent->SYMVAL.find($1->p_f[0]->par_name)==tab->SYMVAL.end())
                  {
                    cout<<"Use of undeclared attribute for class "<< endl;
                    //exit(1);;
                  }
                  else {

                      check_type(tab->parent->SYMVAL[$1->p_f[0]->par_name].type ,$2->type,$2->line_number );
                  }
                }
                else if(tab->SYMVAL.find($1->label)==tab->SYMVAL.end())
                {
                  if(gt->SYMVAL.find($1->label)==gt->SYMVAL.end()){
                  cout<<"Use of undeclared variable " << $1->label <<" in line number "<<$2->line_number<<endl;
                  //exit(1);;
                  }
                  
                }


              }
              // cout << $1->temp_var<<"inside expr_stmt "<<yylineno<<endl;
              codepush("",$2->temp_var,"",$1->temp_var,-1);
             }
             |testlist_star_expr { $$ = $1;}
          ;

expr_stmt_tail : COLON decl_type annassign {
                  $$ =create_node("annassign");
                  $$->children.push_back($1);
                  $$->children.push_back($2);
                  $$->children.push_back($3);
                  $$->type = $2->type;
                  
                  check_type($2->type, $3->type, $1->line_number);
                  $$->temp_var = $3->temp_var;
                  }
               | annassign{
                  $$ = $1;
               }
               | COLON decl_type {
                  $$ =create_node("annassign");
                  $$->children.push_back($1);
                  $$->children.push_back($2);
                  $$->type = $2->type;
               }
               | augassign augassign_op {
                  Node* n =create_node("expr_stmt_tail");
                  n->children.push_back($1);
                  n->children.push_back($2);
                  $$=n;
                  $$->type = $2->type;
                  $$->line_number = $1->line_number;
                  // cout<<$$->type <<" expr_stmt_tail"<<endl;
               }
               /* | rep_expr_stmt_tail{
                   $$=$1;
               } */
               ;

decl_type: NAME {
                $$ = create_node("decl_type");
                $$->type = $1->type;
            }
            | NAME LBRACKET NAME RBRACKET {
                $$ = create_node("decl_type");
               if($1->label != "list"){
                  cout << "Invalid datatype at line no: " << $1->line_number << endl;
                  //exit(1);;
                }
                $$->children.push_back($1);
                $$->children.push_back($2);
                $$->children.push_back($3);
                $$->children.push_back($4);
                $$->type = $1->type + $2->label + $3->type + $4->label;
            }

augassign_op : yield_expr{$$=$1;}
             | testlist{$$=$1;}
             ;
/* rep_expr_stmt_tail : rep_expr_stmt_tail EQUAL_SIGN rep_expr_stmt_tail_op { 
                      Node* n =create_node("rep_expr_stmt_tail1");
                      for(int i=0; i<$1->children.size(); i++){
                        n->children.push_back($1->children[i]);
                      }
                      n->children.push_back($2);
                      n->children.push_back($3);
                      $$=n;
                     }
                    |EQUAL_SIGN rep_expr_stmt_tail_op {
                      Node* n =create_node("rep_expr_stmt_tail2");
                      n->children.push_back($1);
                      n->children.push_back($2);
                      $$=n;
                      $$->type = $2->type;
                      // cout<<$$->type << " rep_expr_2"<<endl;
                    }
                   ;
rep_expr_stmt_tail_op : yield_expr{$$=$1;}
                      | testlist_star_expr{$$=$1;}
                      ; */
annassign : EQUAL_SIGN test{
                  Node* n =create_node("annassign_op");
                   n->children.push_back($1);
                   n->children.push_back($2);
                   $$ = n;
                   $$->line_number= $1->line_number;
                   if($2->type == $2->label)
                   {
                      cout<<"Variable not declared or invalid comparison in line no "<<$1->line_number<<endl;
                      //exit(1);;
                   }
                   else 
                   $$->type = $2->type;

                   $$->temp_var = $2->temp_var;
}
;
testlist_star_expr : testlist_star_expr_opt1 testlist_star_expr_rep COMMA{
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back($1);
                     n->children.push_back($2);
                     n->children.push_back($3);
                     $$=n;
                     $$->line_number = $3->line_number;
                     $$->temp_var = $1->temp_var + $2->temp_var + ",";
                    }
                    |testlist_star_expr_opt1 testlist_star_expr_rep{ 
                      Node* n =create_node("testlist_star_expr");
                      n->children.push_back($1);
                      n->children.push_back($2);
                      $$=n;
                      $$->temp_var = $1->temp_var + $2->temp_var;
                      $$->line_number = $1->line_number;
                    }
                    |testlist_star_expr_opt1 COMMA{
                     Node* n =create_node("testlist_star_expr");
                     n->children.push_back($1);
                     n->children.push_back($2);
                     $$=n;
                     $$->temp_var = $1->temp_var + ",";
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
      $$->temp_var = $1->temp_var+","+$3->temp_var;
  }
  | COMMA testlist_star_expr_opt1 {$$ = NULL; $$->temp_var = ","+$2->temp_var;}

augassign : PLUS_EQUAL {$$=$1; $$->temp_op = "+=";}
          | MINUS_EQUAL {$$=$1; $$->temp_op = "-=";}
          | TIMES_EQUAL {$$=$1; $$->temp_op = "*=";}
          | AT_EQUAL {$$=$1; $$->temp_op = "@=";}
          | DIVIDEDBY_EQUAL {$$=$1; $$->temp_op = "/=";}
          | MODULO_EQUAL {$$=$1; $$->temp_op = "%=";}
          | BITWISE_AND_EQUAL {$$=$1; $$->temp_op = "&=";}
          | BITWISE_OR_EQUAL {$$=$1;  $$->temp_op = "|=";}
          | BITWISE_XOR_EQUAL {$$=$1; $$->temp_op = "^=";}
          | SHIFT_LEFT_EQUAL {$$=$1; $$->temp_op = "<<=";}
          | SHIFT_RIGHT_EQUAL {$$=$1; $$->temp_op = ">>=";}
          | POWER_EQUAL {$$=$1; $$->temp_op = "**=";}
          | FLOORDIV_EQUAL {$$=$1; $$->temp_op = "//=";}
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
         | return_stmt {$$=$1; }
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
              $$->type = $2->type;
              codepush("",$2->temp_var,"","pushparam",-1);
            }
            | RETURN { $$ = $1; $$->type = "None";}
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
compound_stmt : if_stmt{ $$=$1;}
              | while_stmt{$$=$1;}
              | for_stmt{$$=$1;}
              | funcdef{ $$=$1;}
              | classdef{$$=$1;}
              | async_stmt{$$=$1;}
              ;

async_stmt : ASYNC async_stmt_content
           ;

async_stmt_content : funcdef
                   | for_stmt
                   ;

if_stmt : IF test COLON suite elif_stmt_rep ELSE COLON suite{
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
    $$->line_number = $1->line_number;
  }
    | IF test COLON suite elif_stmt_rep{

      Node* n=create_node("if_stmt");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      n->children.push_back($5);
      $$=n;
      $$->line_number = $1->line_number;

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
    $$->line_number = $1->line_number;
    }
    | IF test COLON suite{ 
      Node* n=create_node("if_stmt");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      $$=n;
      $$->line_number = $1->line_number;
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
while_stmt:  WHILE test{
      codepush("","","","loop:",-1);
        string s2 = $2->temp_var;
        codepush("if",s2,"true","==",-1);
        loop_stack.push_back(inst_num-2); 
} COLON suite { 
      Node* n=create_node("while_stmt");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($4);
      n->children.push_back($4); 
      $$=n;
      codepush("",to_string(loop_stack[(loop_stack.size())-1]),"","goto",-1); loop_stack.pop_back();codepush("","","","end loop",-1);
  }
;
for_stmt: FOR exprlist IN range_func{
        codepush("","","","loop:",-1);
        string s2 = $4->temp_var;
        codepush("if",$2->label,s2,">",-1);
        codepush("+",$2->label,"1",$2->label,-1);
        loop_stack.push_back(inst_num-2);
         } COLON suite {
      Node* n=create_node("for_stmt");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      n->children.push_back($6);
      n->children.push_back($7);
      if(tab->SYMVAL.find($2->label)!=tab->SYMVAL.end())
      {
        // cout<<"Already declared"<<endl;
        if(tab->SYMVAL[$2->label].type != "int")
          cout<<" Invalid type iterator in for statement in line no "<< $1->line_number<<endl;
        // cout<<$$->type<<" Name "<< yylineno << " "<< $$->label<<endl;
      }
      else if(gt->SYMVAL.find($2->label)!=gt->SYMVAL.end())
      {
        if(gt->SYMVAL[$2->label].type != "int")
        cout<<" Invalid type iterator in for statement in line no "<< $1->line_number<<endl;
      }
      else {
        cout<<"Undeclared variable used as iterator in for statement in line no "<< $1->line_number<<endl;
         //exit(1);;
      }

      $$=n;
      codepush("",to_string(loop_stack[(loop_stack.size())-1]),"","goto",-1); loop_stack.pop_back();codepush("","","","end loop",-1);
    }
;
range_func : NAME LPAREN test RPAREN{
      Node* n=create_node("range_func");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      $$->temp_var = $3->temp_var;
      if($1->label != "range"){
        cout<<"For loop supports only range function in line no "<<$1->line_number<<endl;
        //exit(1);;
      }


  }
  | NAME LPAREN test COMMA test RPAREN{
      Node* n=create_node("range_func");
      n->children.push_back($1);
      n->children.push_back($2); 
      n->children.push_back($3);
      n->children.push_back($4); 
      n->children.push_back($5);
      n->children.push_back($6);
      $$->temp_var = $3->temp_var;
      if($1->label != "range"){
        cout<<"For loop supports only range function"<<endl;
         //exit(1);;
      }
      else if(($3->type != "int")&& ($5->type != "int"))
      {
        cout<<"Invalid datatype used in range function in line no "<<$1->line_number<<endl;
        //exit(1);;
      }
  }
;
suite : simple_stmt {if(yybye) cout<<"LINE 462 \n"; $$ = $1;}
      | NEWLINE INDENT stmt_rep DEDENT{
        Node* n = create_node("Suite");
        $$ = n;
        n->children.push_back($2);
        n->children.push_back($3);
        n->children.push_back($4);
        if($3->type != "")
          $$->type = $3->type;
        else $$->type = "None";
        $$->line_number = $2->line_number;

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
            $$->type = $2->type;
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
    string s1=new_temporary();
    codepush("or",$1->temp_var,$2->temp_var,s1,-1);
    $$->temp_var = s1;
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
    if(($3->type != "bool") && ($3->type != "int") || (($1->type != "bool") && ($1->type != "int") ))
    {
      cout<<"Non compatible operand type used for OR operator in line no "<<$1->line_number<<endl;
      //exit(1);;
    }  
    $$->type = "bool";
    string s1=new_temporary();
    codepush("or",$1->temp_var,$3->temp_var,s1,-1);
    $$->temp_var = s1;
    $$->temp_op = $1->temp_op;
  }
  | OR and_test{Node* n = create_node("ORTestRep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    if(($2->type != "bool") && ($2->type != "int"))
    {
      cout<<"Non compatible operand type used for OR operator in line no "<<$1->line_number<<endl;
      //exit(1);;
    }  
    $$->temp_op = "or";
    $$->temp_var = $2->temp_var;
    }
;
and_test : 
  not_test and_test_rep{
    Node* n = create_node("And Test");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    if(($2->type != "bool") && ($2->type != "int") || (($1->type != "bool") && ($1->type != "int") ))
    {
      cout<<"Non compatible operand type used for AND    operator in line no "<<$1->line_number<<endl;
      //exit(1);;
    }
    $$->type ="bool";
    string s1=new_temporary();
    codepush("and",$1->temp_var,$2->temp_var,s1,-1);
    $$->temp_var = s1;
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
    if(($3->type != "bool") && ($3->type != "int") || (($1->type != "bool") && ($1->type != "int") ))
    {
      cout<<"Non compatible operand type used for AND operator in line no "<<$1->line_number<<endl;
      //exit(1);;
    }  
    $$->type = "bool";
    string s1=new_temporary();
    codepush("and",$1->temp_var,$3->temp_var,s1,-1);
    $$->temp_var = s1;
    $$->temp_op = $1->temp_op;
  }
  | AND not_test{Node* n = create_node("AndTestRep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    if(($2->type != "bool") && ($2->type != "int"))
    {
      // cout<<$2->type<<endl;
      cout<<"Non compatible operand type used for AND  no operator in line no "<<$1->line_number<<endl;
      //exit(1);;
    }
    $$->type = "bool";
    $$->temp_var = $2->temp_var;
    $$->temp_op = $1->temp_op;
    }
;

not_test : 
  NOT not_test 
  {
    Node* n = create_node("Not Test");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    if(($2->type != "bool") && ($2->type != "int"))
    {
      cout<<"Non compatible operand type used for NOT operator in line no "<<$1->line_number<<endl;
      //exit(1);;
    }
        $$->type = "bool";
    string s1=new_temporary();
    codepush("not",$2->temp_var,"",s1,-1);
    $$->temp_var = s1;
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
    if($1->label == "__name__" )
    $1->type ="bool";
    check_type($1->type , $2->type, $1->line_number);
    $$->type = "bool";
//  doubt in this part 
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$2->temp_var,s1,-1);
    $$->temp_var = s1;
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
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$3->temp_var,s1,-1);
    $$->temp_var = s1;
    $$->temp_op = $1->temp_op;

  }
 | comp_op expr {
   Node* n = create_node("Comparison Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    if($2->label == "\"__main__\"")
    {
      $2->type = "bool";
    }

    $$->type = $2->type;
    $$->temp_var = $2->temp_var;
    $$->temp_op = $1->temp_op;
 }
;
comp_op : LESS_THAN{$$ =$1;$$->temp_op = "<";}
        |GREATER_THAN {$$ =$1;$$->temp_op = ">";}
        |EQUAL {$$ =$1;$$->temp_op = "==";}
        |GREATER_THAN_OR_EQUAL {$$ =$1;$$->temp_op = ">=";}
        |LESS_THAN_OR_EQUAL {$$ =$1;$$->temp_op = "<=";}
        |NOT_EQUAL {$$ =$1;$$->temp_op = "!=";}
        |IN {$$ =$1;$$->temp_op = "in";}
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
    $$->temp_var="*"+$2->temp_var;
  }
;
expr:
  xor_expr expr_rep{
    Node* n = create_node("Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$2->temp_var,s1,-1);
    $$->temp_var = s1;
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
    $2->temp_op = "|";
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$3->temp_var,s1,-1);
    $$->temp_var = s1;
    $$->temp_op = $1->temp_op;
  }
  | BITWISE_OR xor_expr{Node* n = create_node("Expression Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    $$->temp_op = "|";
    $$->temp_var = $2->temp_var;
    } 
;
xor_expr: 
  and_expr xor_expr_rep{
    Node* n = create_node("XOR Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$2->temp_var,s1,-1);
    $$->temp_var = s1;
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
    $2->temp_op = "^";
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$3->temp_var,s1,-1);
    $$->temp_var = s1;
    $$->temp_op = $1->temp_op;
  }
 | BITWISE_XOR and_expr{Node* n = create_node("XOR Expression Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    $$->temp_op = "^";
    $$->temp_var = $2->temp_var;
    } 
;
and_expr: 
  shift_expr and_expr_rep{
    Node* n = create_node("AND Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$2->temp_var,s1,-1);
    $$->temp_var = s1;
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
    $2->temp_op = "&";
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$3->temp_var,s1,-1);
    $$->temp_var = s1;
    $$->temp_op = $1->temp_op;
  }
  |BITWISE_AND shift_expr{Node* n = create_node("AND Expression Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2); 
    $$->temp_op = "&";
    $$->temp_var = $2->temp_var;

    }
;
shift_expr :
  arith_expr shift_expr_rep{
    Node* n = create_node("Shift Expression");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$2->temp_var,s1,-1);
    $$->temp_var = s1;
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
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$3->temp_var,s1,-1);
    $$->temp_var = s1;
    $$->temp_op = $1->temp_op;
  }
  | shift_expr_rep_c1 arith_expr{Node* n = create_node("Shift Expression Rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    
    $$->temp_op = $1->temp_op;
    $$->temp_var = $2->temp_var;
    }
;
shift_expr_rep_c1 : 
  SHIFT_LEFT{
    $$ = $1;
    $$->temp_op = "<<";
  }
  | SHIFT_RIGHT {$$ = $1;
    $$->temp_op = ">>";
  }
;
arith_expr : 
  term arith_expr_rep{
    Node* n = create_node("Arithmetic Expression");
    n->children.push_back($1);
    n->children.push_back($2);

    $$ = n;
    if($1->type != $2->type)
    {
      if(($1->type == "int"|| $1->type =="float" ) && ($2->type == "int"|| $2->type =="float" ))
      $$->type = "float";
      if(($1->type == "int"|| $1->type =="bool" ) && ($2->type == "int"|| $2->type =="bool" ))
      $$->type = "int";
    }
    else 
      $$->type = $1->type;
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$2->temp_var,s1,-1);
    $$->temp_var = s1;
    // cout<<$$->type<< " "<<$1->line_number<<endl;
  }
  |term {$$=$1;}
;
arith_expr_rep : 
  arith_expr_rep arith_expr_rep_c1 term {
    Node* n = create_node("Arithmetic Expression Rep1");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    if($1->type != $3->type)
    {
      if(($1->type == "int"|| $1->type =="float" ) && ($3->type == "int"|| $3->type =="float" ))
      $$->type = "float";
      else if(($1->type == "int"|| $1->type =="bool" ) && ($3->type == "int"|| $3->type =="bool" ))
      $$->type = "int";
      else {
        check_type($1->type , $3->type, $3->line_number);
      }
    }
    else 
      $$->type = $3->type;

    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$3->temp_var,s1,-1);
    $$->temp_var = s1;
    $$->temp_op = $1->temp_op;
    // cout<<$$->type <<" arth rep 1"<<endl;

  }
  |arith_expr_rep_c1 term{Node* n = create_node("Arithmetic Expression Rep2");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    $$->type = $2->type;
    $$->temp_var = $2->temp_var;
    $$->temp_op = $1->temp_op;
    // cout<<"Arith2 "<<$$->temp_var <<" " <<$$->temp_op<<endl;
    }
;
arith_expr_rep_c1 : 
  PLUS { $$ = $1;$$->temp_op = "+";}
  | MINUS { $$ = $1;$$ ->temp_op = "-";}
;
term : 
  factor term_rep{
    if(yybye) cout<<"term factor term_rep: "<<endl;
    Node* n = create_node("TERM");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    if($1->type != $2->type)
    {
      if(($1->type == "int"|| $1->type =="float" ) && ($2->type == "int"|| $2->type =="float" ))
      $$->type = "float";
      else if(($1->type == "int"|| $1->type =="bool" ) && ($2->type == "int"|| $2->type =="bool" ))
      $$->type = "int";
      else 
      check_type($1->type , $2->type, $1->line_number);
    }
    else 
      $$->type = $2->type;
    $$->line_number = $1->line_number;
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$2->temp_var,s1,-1);
    $$->temp_var = s1; 
  }
  |factor{$$=$1;}
;
term_rep : 
   term_rep term_rep_c1 factor {
    Node* n = create_node("TERM Rep");
    for(int i=0; i<$1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
    $$ = n;
    if((($1->type != "int")&&($1->type != "float"))&&(($2->type != "float")&&($2->type != "int")))
    {
      cout<<"Invalid datatype "<< $1->type << " and "<<$3->type <<" used for operator "<<$2->label<<endl;
      //exit(1);;
      
    }
    if($3->type != $1->type)
    {
      if(($3->type == "int"|| $3->type =="float" ) && ($1->type == "int"|| $1->type =="float" ))
      $$->type = "float";
      else 
      check_type($1->type , $1->type, $1->line_number);
    }
    if($2->type == "/")
     $$->type = "float";
    else 
      $$->type = $3->type;
    $$->line_number = $3->line_number;
    string s1=new_temporary();
    codepush($2->temp_op,$1->temp_var,$3->temp_var,s1,-1);
    $$->temp_var = s1;
    $$->temp_op = $1->temp_op;
  }
  | term_rep_c1 factor { Node* n = create_node("TERM Rep");
    n->children.push_back($1);
    n->children.push_back($2);
    $$ = n;
    $$->line_number = $2->line_number;
    $$->type = $2->type;
    if(($2->type != "bool")&&($2->type != "float")&&($2->type != "int"))
    {
      cout<<"Invalid datatype used for operator "<<$1->label<<" in line no "<<$1->line_number<<endl;
      // //exit(1);;
    }
    $$->temp_var = $2->temp_var;
    $$->temp_op = $1->temp_op;
    }
;
term_rep_c1 : TIMES { $$ =$1; $$->temp_op = "*";}
            | AT { $$ =$1;$$->temp_op = "@";}
            | DIVIDEDBY { $$ =$1; $$->temp_op = "/"; }
            | MODULO { $$ =$1;   $$->temp_op = "%";}
            | FLOORDIV { $$ =$1;    $$->temp_op = "//";}
;
factor : 
  factor_c1 factor {
    Node* n = create_node("Factor");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    $$->line_number = $2->line_number;
    $$->type = $2->type;
    $$->temp_op=$1->temp_op;
    $$->temp_var=$2->temp_var;
  }
  | power { if(yybye) cout<<"factor power: "<<endl;$$ = $1;}
;
factor_c1 : PLUS { $$ =$1; $$->temp_op = "+";} 
          | MINUS { $$ =$1; $$->temp_op = "-"; }
          | BITWISE_NOT { $$ =$1; $$->temp_op = "~";}
          ;
power : 
  atom_expr power_opt{
    Node* n = create_node("Power");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    check_type($1->type , $2->type , $1->line_number);
    $$->type = $1->type;
    string s1 = new_temporary();
    codepush($2->temp_op,$1->temp_var,$2->temp_var,s1,-1);
    $$->temp_var = s1;
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
    $$->type = $2->type;
    $$->temp_var = $2->temp_var;
    $$->temp_op = "**";
  }
;
atom_expr : 
  await_opt atom trailer_rep{
    Node* n = create_node("Atom Expression1");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    n->type = $2->type + $3->type;
    $$->temp_var = $2->temp_var;
  }
  |atom trailer_rep{
    Node* n = create_node("Atom Expression2");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);


    if($2->type == "list")
    {
      // done to check cases list x = arr[1]
      if(tab->SYMVAL.find($1->label) != tab->SYMVAL.end())
      {
        $$->type = extractSubstring(tab->SYMVAL[$1->label].type);
      }
      else if (gt->SYMVAL.find($1->label) != gt->SYMVAL.end())
      {
        $$->type = extractSubstring(gt->SYMVAL[$1->label].type);
      }
      $$->label = $1->label;
      // cout<<$$->type <<endl;
    }
    if((gt->SYMVAL.find($1->label) != gt->SYMVAL.end()) && ($2->category == "Func") && (gt->childs[$1->label]->tab_type != CLS))
    {
      vector<Param*> p = gt->SYMVAL[$1->label].params;
      if(p.size() > $2->p_f.size())
      {
        cout<<p.size()<<" "<<$2->p_f.size()<<endl;
        cout<<"Lesser number of arguments for function call "<< $1->label <<" in line number "<< $1->line_number<<endl;

        //exit(1);;
      }
      else if(p.size() < $2->p_f.size())
      {
        cout<<"Greater number of arguments for function call "<< $1->label <<" in line number "<< $1->line_number<<endl;
                //exit(1);;
      }
      else {
        for(int i=0;i<p.size();i++)
        {
          if(p[i]->par_type != $2->p_f[i]->par_type)
          {
            if(isCompatible(p[i]->par_type,$2->p_f[i]->par_type,$2->p_f[i]->par_name))
            {

            }
            else{
              cout<<" Type mismatch for argument "<<i<<" in function call "<< $1->label <<" in line number "<<$1->line_number<<endl;
                      //exit(1);;
            }
          }
        }
      }
      $$->type = gt->SYMVAL[$1->label].type ;
      
    }
    else if((gt->SYMVAL.find($1->label) != gt->SYMVAL.end()) && ($2->category == "Func") && (gt->childs[$1->label]->tab_type == CLS))
    {
      $$->type = gt->SYMVAL[$1->label].type;
      SYMTAB* s = gt->childs[$1->label];
      string y = "__init__";

      if(s->SYMVAL.find("__init__")!= s->SYMVAL.end())
      {
        vector<Param*> p = s->SYMVAL[y].params;
        if(p.size() > $2->p_f.size())
        {
         cout<<"Lesser number of arguments for constructor call "<< $1->label <<" in line number "<< $1->line_number<<endl;

         //exit(1);;
        }
        else if(p.size() < $2->p_f.size())
        {
          cout<<"Greater number of arguments for constructor call "<< $1->label <<" in line number "<< $1->line_number<<endl;
                //exit(1);;
        }
        else {
        for(int i=0;i<p.size();i++)
        {

          if(p[i]->par_type != $2->p_f[i]->par_type)
          {
            if(isCompatible(p[i]->par_type,$2->p_f[i]->par_type,$2->p_f[i]->par_name))
            {

            }
            else{
              cout<<" Type mismatch for argument "<<i<<" in function call "<< $1->label <<" in line number "<<$1->line_number<<endl;
                      //exit(1);;
            }
          }
        }
        }
        // cout<<p.size()<<endl;

      }
    }
    else if($2->category == "Func")
    {
      // to support function which are pre defined like len print and range
      if($1->label == "len"){
        std::regex pattern("list\\[\\w+\\]");
        // cout<<$2->type<<endl;
        if (std::regex_match($2->type, pattern)) {

        } else {
            // cout<<$2->type <<endl;

            std::cout <<" Invalid datatype use for len function in line no : "<<$1->line_number<<"\n";
            //exit(1);;
        }
        $$->type ="int";
      }
      else if( $1->label == "print")
      {
        for(int i = 0;i<$2->p_f.size() ; i++)
        {
          // cout<<$2->p_f[i]->par_type<<" "<<endl;
          if($2->p_f[i]->par_type == "string"){}
          else{
                if($2->p_f[i]->par_type == $2->p_f[i]->par_name)
                {
                  cout<<"Use of undeclared variable inside print function " <<" in line number "<<$2->line_number<<endl;
                  //exit(1);;
                }
          }

        }
      }
      
      else{

        cout<<"Undeclared Function in line no : "<< $1->line_number<<endl;
        //exit(1);;
      }
    }
    else if($2->label == "Trailer5")
    {
      //  to check class datatypes  x.a.b.c abhi ispe kaam bcha h 
      if($1->label == "self")
      {
        
        if(tab->parent->SYMVAL.find($2->type) == tab->parent->SYMVAL.end()) 
        {
          cout<<"Undefined property "<<$2->type<<" for class "<<$1->type<<" used by object "<<$1->label<<" in line no "<<$1->line_number<<endl;
          //exit(1);;
        }
        $$->type = tab->parent->SYMVAL[$2->type].type;
      }
      else 
      {

        if(gt->childs[$1->type]->SYMVAL.find($2->type) == gt->childs[$1->type]->SYMVAL.end()) 
        {
          cout<<"Undefined property "<<$2->type<<" for class "<<$1->type<<" used by object "<<$1->label<<"in line no "<<$1->line_number<<endl;
          //exit(1);;
        }
        $$->type = gt->childs[$1->type]->SYMVAL[$2->type].type;
      }
      $$->label = $1->label;

      // cout<<$2->p_f[0]->par_type<<" sadv" <<endl;
      // string s_s = $2->p_f[$2->p_f.size()-1]->par_name ;
      // strings cls_label = $1->label;
      // for(int i=0;i<$2->p_f.size()<i++)
      // {
      //   s_s = $2->p_f[$2->p_f.size()-1]->par_name;
        
      //   cls_label = $2->p_f[i]->par_name 
      // }
      if($2->p_f.size()==1)
      {
        $2->p_f[0]->par_type = gt->childs[$1->type]->SYMVAL[$2->p_f[0]->par_name].type;
      }
      $$->p_f = $2->p_f;


    }
    $$->temp_var = $1->temp_var;
    for(int i=0;i<arguments.size();i++) { 
      string s1 = get<0>(arguments[i]);
      if(tab->SYMVAL.find(s1)!=tab->SYMVAL.end()){
      codepush("",tab->SYMVAL[s1].temp_var,"","pushparam",-1);
      } 
      else{
        codepush("",get<1>(arguments[i]),"","pushparam",-1);
      } 
    }
    if($1->type=="None")
    codepush("call",$1->label,"","",-1);
    else{
      codepush(" ","call",$1->label,"",-1);
    }
    arguments.clear();
  }
  |atom{
    $$ = $1;
    // cout<<"atom " <<$$->type<<endl;
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
    cout<<" Datatypes like in line number "<<$2->line_number <<" not supported for now "<<endl;
    //exit(1);;

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
        $$->category = "Func";
        $$->type = $2->type;
        $$->line_number = $1->line_number;
        $$->temp_var = $2->temp_var;
      }
      | LBRACKET atom_opt2 RBRACKET {
        if(yybye) cout<<"atom atom_opt2: "<<endl;
        Node* n = create_node("Atom");
        $$ = n;
        n->children.push_back($1);
        n->children.push_back($2);
        n->children.push_back($3);
        $$->type = "list" + $1->type + $2->type +$3->type;
        $$->line_number = $1->line_number;
        $$->temp_var = $2->temp_var;

      }
      |LBRACKET RBRACKET { 
        if(yybye) cout<<"atom : "<<endl;
        Node* n = create_node("Atom");
        $$ = n;
        n->children.push_back($1);
        n->children.push_back($2);
        $$->line_number = $1->line_number;

      }
      | NAME  { $$ =$1;
                if(tab->SYMVAL.find($1->label)!=tab->SYMVAL.end())
                {
                  // cout<<"Already declared"<<endl;
                  $$->type = tab->SYMVAL[$1->label].type;
                  $$->temp_var = tab->SYMVAL[$1->label].temp_var;
                }
                else if(gt->SYMVAL.find($1->label)!=gt->SYMVAL.end())
                {
                  $$->type = gt->SYMVAL[$1->label].type;
                }
                else{

                if($1->label == "int")
                  $$->type = "int";
                else if($1->label == "float")
                  $$->type = "float";
                else if($1->label == "str")
                  $$->type = "str";
                else if($1->label == "bool")
                  $$->type = "bool";
                else if($1->label == "len")
                  $$->type = "int";
                else{
                string t = new_temporary();

                $$->temp_var = t;
                // cout << t;
                codepush("",t,"",$1->label,-1);}  
                }
              

      }
      | NUMBER  { $$ =$1; $$->type = "int";
                  $$->temp_var= new_temporary();
                  codepush("",$1->label,"",$$->temp_var,-1);  }
      | FLOAT {$$ = $1; $$->type = "float";
                $$->temp_var= new_temporary();
                codepush("",$1->label,"",$$->temp_var,-1);}
      | string_rep { $$ = $1; $$->type = "string";
                      $$->temp_var= new_temporary();
                      codepush("",$1->label,"",$$->temp_var,-1);}
      | TRIPLEDOT  { $$ =$1;}
      | NONE  { $$ =$1; $$->type = "None";}
      | TRUE_TOKEN  { $$ =$1; $$->type = "bool";
                      $$->temp_var= new_temporary();
                      codepush("",$1->label,"",$$->temp_var,-1);}
      | FALSE_TOKEN { $$ =$1; $$->type = "bool";
                      $$->temp_var= new_temporary();
                      codepush("",$1->label,"",$$->temp_var,-1);}
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
    $$->line_number= $1->line_number;
  }
;
testlist_comp :
  testlist_comp_c1 testlist_comp_c2{
    Node* n = create_node("Testlist comp");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    $$->type = $1->type;
    $$->line_number = $1->line_number;
    check_type($1->type , $2->type , $2->line_number);
    // cout<<"Yes  "<<endl;
    $$->type = $1->type;
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
    $$->type = $1->type;
    $$->line_number = $2->line_number;
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
    check_type($1->type , $3->type , $2->line_number);
    $$->type = $1->type;
  }
  |testlist_comp_c2_rep COMMA star_expr {
    Node* n = create_node("Testlist Comp C2 rep");
    $$ = n;
    for(int i = 0; i < $1->children.size(); i++){
      n->children.push_back($1->children[i]);
    }
    n->children.push_back($2);
    n->children.push_back($3);
    check_type($1->type , $2->type , $2->line_number);
    $$->type = $1->type;
  }
  |COMMA test{
    Node* n = create_node("Testlist Comp C2 rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    $$->type = $2->type;
  }
  | COMMA star_expr { 
    Node* n = create_node("Testlist Comp C2 rep");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    $$->type = $2->type;
  }
;
trailer :
  LPAREN arglist RPAREN{
    if(yybye) cout<<"trailer: "<<endl;
    Node* n = create_node("Trailer1");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    $$->category = "Func";
    $$->type = $2->type;
    $$->line_number = $1->line_number;
    $$->p_f = $2->p_f;

  }
  |LPAREN RPAREN{
    Node* n = create_node("Trailer2");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    $$->line_number = $1->line_number;
    $$->category = "Func";
  }
  | LBRACKET subscriptlist RBRACKET {
    Node* n = create_node("Trailer3");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    $$->line_number = $1->line_number;
    if(($2->type == "int") && ($2->label != "int"))
      $$->type = "list";
    else
      $$->type = $1->type + $2->type + $3->type;
  }
  |LBRACKET RBRACKET{ 
    Node* n = create_node("Trailer4");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    $$->line_number = $1->line_number;
  }
  | DOT NAME{
    Node* n = create_node("Trailer5");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    $$->type = $2->type;
    $$->line_number = $1->line_number;
    // attributes of a class
    Param* temp = new Param();
    temp->par_name = $2->label;
    $$->p_f.push_back(temp);
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

class_name :CLASS NAME{
            Node* n = create_node($2->label);
            n->children.push_back($1);
            n->children.push_back($2);
            $$ = n;
            $$->line_number = $1->line_number;
            if(tab->SYMVAL.find($2->label)== tab->SYMVAL.end()){
                tab->SYMVAL[$2->label].identity=CLS;
                tab->SYMVAL[$2->label].scope=curr_scope;
                tab->SYMVAL[$2->label].line_no=$1->line_number;
               cout<<tab->SYMVAL[$2->label].name<<endl;
               SYMTAB* newtab=new SYMTAB();
               newtab->SYMSCOPE=++curr_scope;
               newtab->parent=tab;
               newtab->tab_type = 3;
              //  tab->childs.push_back(newtab);
               tab->childs[$2->label] = newtab;
              //  cout<<gt->childs[$2->label]->tab_type<<"funck"<<endl;
               tab=newtab;
             }
             else {
              cout<<"Class redeclared in line no "<< $2->line_number<<endl;
                      //exit(1);;
             }
};
classdef : class_name LPAREN arglist RPAREN COLON suite{
    Node* n = create_node("Class Def");
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    n->children.push_back($4);
    n->children.push_back($5);
    n->children.push_back($6);
    $$ = n;
    tab=tab->parent;
    if(tab->SYMVAL.find($1->label)!= tab->SYMVAL.end()){
      tab->SYMVAL[$1->label].identity=CLS;
      tab->SYMVAL[$1->label].scope=curr_scope;
      tab->SYMVAL[$1->label].line_no=$1->line_number;
      tab->SYMVAL[$1->label].type=$1->label;
      tab->SYMVAL[$1->label].name=$1->label;
      tab->SYMVAL[$1->label].size=$3->count;
      tab->SYMVAL[$1->label].params=$3->p_f;
   }

  //  else{
  //   cout<<"error"<<endl;
  //   exit(0);
  //  }   

}
| class_name LPAREN RPAREN COLON suite{
    Node* n = create_node("Class Def");
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    n->children.push_back($4);
    n->children.push_back($5);
    $$ = n;
    tab=tab->parent;
    if(tab->SYMVAL.find($1->label)!= tab->SYMVAL.end()){
      tab->SYMVAL[$1->label].identity=CLS;
      tab->SYMVAL[$1->label].scope=curr_scope;
      tab->SYMVAL[$1->label].line_no=$1->line_number;
      tab->SYMVAL[$1->label].type=$1->label;
      tab->SYMVAL[$1->label].name=$1->label;
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
| class_name COLON suite{
    Node* n = create_node("Class Def");
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    $$ = n;
    tab=tab->parent;
    if(tab->SYMVAL.find($1->label)!= tab->SYMVAL.end()){
      tab->SYMVAL[$1->label].identity=CLS;
      tab->SYMVAL[$1->label].scope=curr_scope;
      tab->SYMVAL[$1->label].line_no=$1->line_number;
      tab->SYMVAL[$1->label].type=$1->label;
      tab->SYMVAL[$1->label].name=$1->label;
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
;
arglist : 
  argument COMMA_argument_rep COMMA{
    Node* n = create_node("Arglist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);
    Param* temp = new Param();
    temp->par_type=$1->type;
    temp->par_name=$1->label;
    $$->p_f.push_back(temp);
    $$->p_f.insert($$->p_f.end(), $2->p_f.begin(), $2->p_f.end());
    // cout<<"Arglist 1";
    // for (auto it = $2->parameters.begin(); it != $2->parameters.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // cout<<endl;
    arguments.push_back(make_tuple($1->label,$1->temp_var, $1->type,0,0));

  }
  | argument COMMA{
    Node* n = create_node("Arglist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    Param* temp = new Param();
    temp->par_type=$1->type;
    temp->par_name=$1->label;
    $$->p_f.push_back(temp);
    arguments.push_back(make_tuple($1->label,$1->temp_var, $1->type,0,0));
  }
  | argument COMMA_argument_rep{
    Node* n = create_node("Arglist");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    // cout<<"Arglist 3 "<<endl;
    Param* temp = new Param();
    temp->par_type=$1->type;
    temp->par_name=$1->label;
    // cout<<temp->par_type<<" ARGLIST "<<temp->par_name<<endl;
    $$->p_f.push_back(temp);
    $$->p_f.insert($$->p_f.end(), $2->p_f.begin(), $2->p_f.end());
    // for (auto it = $$->parameters.begin(); it != $$->parameters.end(); ++it) {
    //   std::cout << *it << " ";
    // }
    // cout<<endl;
    arguments.push_back(make_tuple($1->label,$1->temp_var, $1->type,0,0));
  };
  |argument{$$ =$1;
    Param* temp = new Param();
    temp->par_type=$1->type;
    temp->par_name=$1->label;
        $$->p_f.push_back(temp);
    arguments.push_back(make_tuple($1->label,$1->temp_var, $1->type,0,0));
  }
;
COMMA_argument_rep : 
  COMMA_argument_rep COMMA argument { 
    Node* n = create_node("Comma Argument rep1");
    $$ = n;
    // for(int i=0; i<$1->children.size(); i++){
    //   n->children.push_back($1->children[i]);
    // }
    n->children.push_back($1);
    n->children.push_back($2);
    n->children.push_back($3);

    Param* temp = new Param();
    temp->par_type=$3->type;
    temp->par_name=$3->label;
    $$->p_f.insert($$->p_f.end(), $1->p_f.begin(), $1->p_f.end());
    $$->p_f.push_back(temp);
    arguments.push_back(make_tuple($3->label,$2->temp_var, $3->type,0,0));
  }
  | COMMA argument {
    Node* n = create_node("Comma Argument rep2");
    $$ = n;
    n->children.push_back($1);
    n->children.push_back($2);
    Param* temp = new Param();
    temp->par_type=$2->type;
    temp->par_name=$2->label;
    $$->p_f.push_back(temp);
    arguments.push_back(make_tuple($2->label,$2->temp_var, $2->type,0,0));
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
     codepush("", $3->temp_var, "", $1->temp_var, -1);
     $$->temp_var = $1->temp_var;
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
  |test{$$ =$1; }
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

