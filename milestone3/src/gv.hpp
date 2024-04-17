#ifndef GLOBAL_VARS_HPP
#define GLOBAL_VARS_HPP

#include <bits/stdc++.h>
#include "symtab.cpp"
#include "ast.h"
#include "3ac.cpp"
#include "x86.cpp"

extern unsigned long long int num_scopes;
extern "C" int yylineno;

extern SYMTAB *main_table;

extern map<string, int> type_to_size;
extern set<string> primitive_types;
extern const int address_size;
extern const int stack_offset;

enum MODIFIER {
    M_PUBLIC,
    M_PRIVATE,
    M_PROTECTED,
    M_STATIC,
    M_ABSTRACT,
    M_NATIVE,
    M_SYNCHRONIZED,
    M_TRANSIENT,
    M_VOLATILE,
    M_FINAL,
    COUNT
};

extern Node* root;     // contains the root node of the parse tree
extern codegen* gen;    // finally generates all the x86 code
extern int func_count;  // used to rename functions
extern map<string, string> func_name_map;       //  maps original function names to renamed functions

#endif