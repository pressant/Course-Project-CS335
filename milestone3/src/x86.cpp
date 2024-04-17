#include <iostream>
#include <vector>
#include <variant>
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
#include <variant>
#include "runt_env.cpp"
#include "symtab.cpp"
#include "3ac.cpp"
#include "gv.hpp"
using namespace std;

typedef quadruple quad;

struct instruction{
    string op = "";
    string arg1 = "";
    string arg2 = "";
    string arg3 = "";
    string code = "";
    string ins_type = "";

    string comment = "";

    instruction();
    instruction(string, string a1 = "", string a2 = "", string a3 = "", string it = "ins", string comment = "");

};
struct subroutine_entry{
    string name = "";
    int offset = 0;         // offset from the base pointer in subroutine
    
    subroutine_entry();
    subroutine_entry(string, int);
    // other entries may be added later
};

struct subroutine_table{
    string subroutine_name;
    bool is_main_function = false;
    map<string, subroutine_entry> lookup_table;
    int total_space;
    int number_of_params = 0;

    subroutine_table();
    void construct_subroutine_table(vector<quadruple> subroutine_ins);
    bool isVariable(string s);
};

struct codegen {
    vector< vector<quadruple> > subroutines;
    vector<instruction> code;
    vector<subroutine_table* > sub_tables;
    // string code;
    
    codegen();
    void append_ins(instruction ins);
    void print_code(string asm_file = "asm.s");

    void get_tac_subroutines(vector<quad> tac);                             // generates all the subroutines from the tac
    void gen_tac_basic_block(vector<quadruple>, subroutine_table*);      // generates all the basic blocks from subroutines
    
    bool isVariable(string s);
    bool isMainFunction(string s);
    string get_func_name(string s);          

    void gen_global();                                      // generates code for the global region
    void gen_text();                                        // generates code for the text region
    void gen_fixed_subroutines();                           // generates some fixed subroutines
    void gen_subroutine(vector<quadruple> subroutine);           // generates code for individual subroutines
    void gen_basic_block(vector<quadruple> BB, subroutine_table*);       // generates code for basic blocks
    vector<instruction> make_x86_code(quadruple, int x = 0, int y = 0, int z = 0);     // generates x86 for a single tac instruction
};

vector<instruction> code_x86_64;

// Define CodeGen class
class CodeGen {
private:
    int stack_offset;
    int func_count;
    map<string, string> func_name_map;

    // Helper functions for code generation
    bool isVariable(string s);
    bool isMainFunction(string s);
    string get_func_name(string s);
    vector<instruction> make_x86_code(/* parameters */);

public:
    CodeGen() : stack_offset(8), func_count(0) {}

    // Main function to generate x86_64 code
    void generate_x86_64(/* parameters */);
};

quadruple* curri;
ActivationRecord* curr_ar=Display.top();
int counter=0;
bool isVariable(string s) {   // if the first character is a digit/-/+, then it is a constant and not a variable
    return !(s[0] >= '0' && s[0] <= '9') && (s[0] != '-') && (s[0] != '+');
}
MAPVAL* myval(string s){
   if ((*(curr_ar->localdecs)).find(s) != (*(curr_ar->localdecs)).end()){
        return &(*(curr_ar->localdecs))[s];
    } else if ((*(curr_ar->freevars)).find(s) != (*(curr_ar->freevars)).end()) {
        return (*(curr_ar->freevars))[s];
    } else if (curr_ar->tempo.find(s) != curr_ar->tempo.end()){
        return curr_ar->tempo[s];
    } 
    return NULL;
}

vector<instruction> codegen::make_x86_code(quadruple q, int x, int y, int z){
    vector<instruction> insts;
    instruction ins;

    if(q.code == ""){
        return insts;        
    }
    else{
        if(q.made_from != quadruple::POP_PARAM){
            ins = instruction("", "", "", "", "comment", q.code.substr(2, q.code.size() - 2));
            insts.push_back(ins);
        }
    }

    if(q.is_target) {   // if this is a target, a label needs to be added
        ins = instruction("", "L" + to_string(q.ins_line), "", "", "label");
        insts.push_back(ins);
    }
    if(q.made_from == quadruple::BINARY){            // c(z) = a(x) op b(y)
        // Load value of a into %rax

        if(q.op == "+"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            if(!isVariable(q.arg2)){
                ins = instruction("add", "$" + q.arg2, "%rdx");
            }
            else{
                ins = instruction("add", to_string(y) + "(%rbp)", "%rdx");
            }
        }
        else if(q.op == "-"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            if(!isVariable(q.arg2)){
                ins = instruction("sub", "$" + q.arg2, "%rdx");
            }
            else{
                ins = instruction("sub", to_string(y) + "(%rbp)", "%rdx");
            }
        }
        else if(q.op == "*"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            if(!isVariable(q.arg2)){
                ins = instruction("imul", "$" + q.arg2, "%rdx");
            }
            else{
                ins = instruction("imul", to_string(y) + "(%rbp)", "%rdx");
            }
        }
        else if(q.op == "/"){
            if(!isVariable(q.arg1)){   // arg1 is a literal
                ins = instruction("movq", "$" + q.arg1, "%rax");
                insts.push_back(ins);
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rax");
                insts.push_back(ins);                
            }
            ins = instruction("cqto");
            insts.push_back(ins);

            if(!isVariable(q.arg2)){  // arg2 is a literal
                ins = instruction("movq", "$" + q.arg2, "%rbx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rbx");
            }
            insts.push_back(ins);
            ins = instruction("idiv", "%rbx", "");
            insts.push_back(ins);
            ins = instruction("movq", "%rax", "%rdx");
        }
        else if(q.op == "%"){
            if(!isVariable(q.arg1)){   // arg1 is a literal
                ins = instruction("movq", "$" + q.arg1, "%rax");
                insts.push_back(ins);
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rax");
                insts.push_back(ins);                
            }
            ins = instruction("cqto");
            insts.push_back(ins);

            if(!isVariable(q.arg2)){  // arg2 is a literal
                ins = instruction("movq", "$" + q.arg2, "%rbx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rbx");
            }
            insts.push_back(ins);
            ins = instruction("idiv", "%rbx", "");
        }
        else if(q.op == "<<"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            if(!isVariable(q.arg2)){
                ins = instruction("movq", "$" + q.arg2, "%rcx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rcx");
            }
            insts.push_back(ins);
            ins = instruction("sal", "%cl", "%rdx");
        }
        else if(q.op == ">>"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            if(!isVariable(q.arg2)){
                ins = instruction("movq", "$" + q.arg2, "%rcx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rcx");
            }
            insts.push_back(ins);
            ins = instruction("sar", "%cl", "%rdx");
        }
        else if(q.op == ">>>"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            if(!isVariable(q.arg2)){
                ins = instruction("movq", "$" + q.arg2, "%rcx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rcx");
            }
            insts.push_back(ins);
            ins = instruction("shr", "%cl", "%rdx");
        }
        else if(q.op == ">"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);

            if(!isVariable(q.arg2)){
                ins = instruction("movq", "$" + q.arg2, "%rcx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rcx");
            }
            insts.push_back(ins);
            ins = instruction("cmp", "%rdx", "%rcx");
            insts.push_back(ins);
            ins = instruction("jl", "1f");  // true
            insts.push_back(ins);
            ins = instruction("movq", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f"); // false
            insts.push_back(ins);
            ins = instruction("", "1", "", "", "label");
            insts.push_back(ins);
            ins = instruction("movq", "$1", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f");
            insts.push_back(ins);
            ins = instruction("", "2", "", "", "label");
        }
        else if(q.op == "<"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);

            if(!isVariable(q.arg2)){
                ins = instruction("movq", "$" + q.arg2, "%rcx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rcx");
            }
            insts.push_back(ins);
            ins = instruction("cmp", "%rdx", "%rcx");
            insts.push_back(ins);
            ins = instruction("jg", "1f");  // true
            insts.push_back(ins);
            ins = instruction("movq", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f"); // false
            insts.push_back(ins);
            ins = instruction("", "1", "", "", "label");
            insts.push_back(ins);
            ins = instruction("movq", "$1", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f");
            insts.push_back(ins);
            ins = instruction("", "2", "", "", "label");
        }
        else if(q.op == ">="){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);

            if(!isVariable(q.arg2)){
                ins = instruction("movq", "$" + q.arg2, "%rcx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rcx");
            }
            insts.push_back(ins);
            ins = instruction("cmp", "%rdx", "%rcx");
            insts.push_back(ins);
            ins = instruction("jle", "1f");  // true
            insts.push_back(ins);
            ins = instruction("movq", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f"); // false
            insts.push_back(ins);
            ins = instruction("", "1", "", "", "label");
            insts.push_back(ins);
            ins = instruction("movq", "$1", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f");
            insts.push_back(ins);
            ins = instruction("", "2", "", "", "label");
        }
        else if(q.op == "<="){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);

            if(!isVariable(q.arg2)){
                ins = instruction("movq", "$" + q.arg2, "%rcx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rcx");
            }
            insts.push_back(ins);
            ins = instruction("cmp", "%rdx", "%rcx");
            insts.push_back(ins);
            ins = instruction("jge", "1f");  // true
            insts.push_back(ins);
            ins = instruction("movq", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f"); // false
            insts.push_back(ins);
            ins = instruction("", "1", "", "", "label");
            insts.push_back(ins);
            ins = instruction("movq", "$1", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f");
            insts.push_back(ins);
            ins = instruction("", "2", "", "", "label");
        }
        else if(q.op == "=="){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);

            if(!isVariable(q.arg2)){
                ins = instruction("movq", "$" + q.arg2, "%rcx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rcx");
            }
            insts.push_back(ins);
            ins = instruction("cmp", "%rdx", "%rcx");
            insts.push_back(ins);
            ins = instruction("je", "1f");  // true
            insts.push_back(ins);
            ins = instruction("movq", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f"); // false
            insts.push_back(ins);
            ins = instruction("", "1", "", "", "label");
            insts.push_back(ins);
            ins = instruction("movq", "$1", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f");
            insts.push_back(ins);
            ins = instruction("", "2", "", "", "label");
        }
        else if(q.op == "!="){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);

            if(!isVariable(q.arg2)){
                ins = instruction("movq", "$" + q.arg2, "%rcx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rcx");
            }
            insts.push_back(ins);
            ins = instruction("cmp", "%rdx", "%rcx");
            insts.push_back(ins);
            ins = instruction("jne", "1f");  // true
            insts.push_back(ins);
            ins = instruction("movq", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f"); // false
            insts.push_back(ins);
            ins = instruction("", "1", "", "", "label");
            insts.push_back(ins);
            ins = instruction("movq", "$1", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f");
            insts.push_back(ins);
            ins = instruction("", "2", "", "", "label");
        }
        else if(q.op == "&"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            if(!isVariable(q.arg2)){
                ins = instruction("and", "$" + q.arg2, "%rdx");
            }
            else{
                ins = instruction("and", to_string(y) + "(%rbp)", "%rdx");
            }     
        }
        else if(q.op == "|"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            if(!isVariable(q.arg2)){
                ins = instruction("or", "$" + q.arg2, "%rdx");
            }
            else{
                ins = instruction("or", to_string(y) + "(%rbp)", "%rdx");
            }     
        }
        else if(q.op == "^"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            if(!isVariable(q.arg2)){
                ins = instruction("xor", "$" + q.arg2, "%rdx");
            }
            else{
                ins = instruction("xor", to_string(y) + "(%rbp)", "%rdx");
            }
        }
        else if(q.op == "&&"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            ins = instruction("cmp", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("je", "1f");
            insts.push_back(ins);
            if(!isVariable(q.arg2)){
                ins = instruction("movq", "$" + q.arg2, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            ins = instruction("cmp", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("je", "1f");
            insts.push_back(ins);
            ins = instruction("movq", "$1", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f");
            insts.push_back(ins);
            ins = instruction("", "1", "", "", "label");
            insts.push_back(ins);
            ins = instruction("movq", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("", "2", "", "", "label");
        }
        else if(q.op == "||"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            ins = instruction("cmp", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("jne", "1f");     // true
            insts.push_back(ins);
            if(!isVariable(q.arg2)){
                ins = instruction("movq", "$" + q.arg2, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            ins = instruction("cmp", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("jne", "1f");     // true
            insts.push_back(ins);
            ins = instruction("movq", "$0", "%rdx");
            insts.push_back(ins);
            ins = instruction("jmp", "2f");     // false
            insts.push_back(ins);
            ins = instruction("", "1", "", "", "label");
            insts.push_back(ins);
            ins = instruction("movq", "$1", "%rdx");
            insts.push_back(ins);
            ins = instruction("", "2", "", "", "label");
        }
        insts.push_back(ins);
        
        ins = instruction("movq", "%rdx", to_string(z) + "(%rbp)");
        insts.push_back(ins);
    }
    else if(q.made_from == quadruple::UNARY){        // b(y) = op a(x)
        if(q.op == "~"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            ins = instruction("neg", "%rdx", "");
        }
        else if(q.op == "!"){
            if(!isVariable(q.arg1)){
                ins = instruction("movq", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            }
            insts.push_back(ins);
            ins = instruction("not", "%rdx", "");
        }
        else if(q.op == "-"){
            ins = instruction("xor", "%rdx", "%rdx");
            insts.push_back(ins);
            if(!isVariable(q.arg1)){
                ins = instruction("sub", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("sub", to_string(x) + "(%rbp)", "%rdx");
            }
        }
        else if(q.op == "+"){
            ins = instruction("xor", "%rdx", "%rdx");
            insts.push_back(ins);
            if(!isVariable(q.arg1)){
                ins = instruction("add", "$" + q.arg1, "%rdx");
            }
            else{
                ins = instruction("add", to_string(x) + "(%rbp)", "%rdx");
            }
        }
        insts.push_back(ins);
        
        ins = instruction("movq", "%rdx", to_string(y) + "(%rbp)");
        insts.push_back(ins);
    }
    else if(q.made_from == quadruple::ASSIGNMENT){   // b(y) = a(x)
        if(!isVariable(q.arg1)){
            ins = instruction("movq", "$" + q.arg1, to_string(y) + "(%rbp)");
            insts.push_back(ins);
        }
        else{
            ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
            insts.push_back(ins);            
            ins = instruction("movq", "%rdx", to_string(y) + "(%rbp)");
            insts.push_back(ins);
        }
    }
    else if(q.made_from == quadruple::CONDITIONAL){  // if_false/if_true(op) a(x) goto y
        if(!isVariable(q.arg1)){
            ins = instruction("movq", "$" + q.arg1, "%rdx");
        }
        else{
            ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
        }
        insts.push_back(ins);
        ins = instruction("cmp", "$0", "%rdx");
        insts.push_back(ins);
        
        if(q.op == "if_false"){
            ins = instruction("je", "L" + to_string(y));
        }
        else if(q.op == "if_true"){
            ins = instruction("jne", "L" + to_string(y));
        }
        insts.push_back(ins);
    } 
    else if(q.made_from == quadruple::GOTO){         // goto (x)
        ins = instruction("jmp", "L" + to_string(x));
        insts.push_back(ins);
    }
    else if(q.made_from == quadruple::STORE){        // *(r(z) + a2) = a1(x)
        if(!isVariable(q.arg1)){
            ins = instruction("movq", "$" + q.arg1, "%rax");
        }
        else{
            ins = instruction("movq", to_string(x) + "(%rbp)", "%rax");
        }
        insts.push_back(ins);
        
        ins = instruction("movq", to_string(z) + "(%rbp)", "%rdx");
        insts.push_back(ins);

        if(q.arg2 == "" || !isVariable(q.arg2)) {
            ins = instruction("movq", "%rax", q.arg2 + "(%rdx)");
            insts.push_back(ins);
        }
        else {
            cout << "Unknown TAC `" << q.code << "`. Cannot make load from this code!" << endl;
            exit(1);  
        }
    }
    else if(q.made_from == quadruple::LOAD){         // r(z) = *(a1(x) + a2(y))
        ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx");
        insts.push_back(ins);

        if(q.arg2 == "" || !isVariable(q.arg2)) {
            ins = instruction("movq", q.arg2 + "(%rdx)", "%rdx");
            insts.push_back(ins);
        }
        else {
            cout << "Unknown TAC `" << q.code << "`. Cannot make load from this code!" << endl;
            exit(1);
        }

        ins = instruction("movq", "%rdx", to_string(z) + "(%rbp)");
        insts.push_back(ins);
    }
    else if(q.made_from == quadruple::BEGIN_FUNC) {  // perform callee duties
        if(y == 1) {        // make start label if it is the main function
            ins = instruction("", "main", "", "", "label");
            insts.push_back(ins);
        }

        ins = instruction("", get_func_name(q.arg1), "", "", "label");     // add label
        insts.push_back(ins);


        ins = instruction("pushq", "%rbp");      // old base pointer
        insts.push_back(ins);
        ins = instruction("movq", "%rsp", "%rbp");    // shift base pointer to the base of the new activation frame
        insts.push_back(ins);
        ins = instruction("pushq", "%rbx");
        insts.push_back(ins);
        ins = instruction("pushq", "%rdi");
        insts.push_back(ins);
        ins = instruction("pushq", "%rsi");
        insts.push_back(ins);
        ins = instruction("pushq", "%r12");
        insts.push_back(ins);
        ins = instruction("pushq", "%r13");
        insts.push_back(ins);
        ins = instruction("pushq", "%r14");
        insts.push_back(ins);
        ins = instruction("pushq", "%r15");
        insts.push_back(ins);

        // shift stack pointer to make space for locals and temporaries, ignore if no locals/temporaries in function
        if(x > 0) {
            ins = instruction("sub", "$" + to_string(x), "%rsp");
            insts.push_back(ins);
        }
    }
    else if(q.made_from == quadruple::RETURN) {    // clean up activation record
        if(q.arg1 != "") {      // Load %rax with the return value if non-void function
            if(!isVariable(q.arg1)) {
                ins = instruction("movq", "$" + q.arg1, "%rax");
            }
            else {
                ins = instruction("movq", to_string(y) + "(%rbp)", "%rax");
            }
            insts.push_back(ins);
        }
        
        ins = instruction("add", "$" + to_string(x), "%rsp");   // delete all local and temporary variables
        insts.push_back(ins);
        ins = instruction("popq", "%r15");                      // restore old register values
        insts.push_back(ins);
        ins = instruction("popq", "%r14");
        insts.push_back(ins);
        ins = instruction("popq", "%r13");
        insts.push_back(ins);
        ins = instruction("popq", "%r12");
        insts.push_back(ins);
        ins = instruction("popq", "%rsi");
        insts.push_back(ins);
        ins = instruction("popq", "%rdi");
        insts.push_back(ins);
        ins = instruction("popq", "%rbx");
        insts.push_back(ins);
        ins = instruction("popq", "%rbp");
        insts.push_back(ins);

        ins = instruction("ret");
        insts.push_back(ins);
    }
    else if(q.made_from == quadruple::END_FUNC) {
        if(x == 1) {        // if main function
            ins = instruction("movq", "$60", "%rax");
            insts.push_back(ins);
            ins = instruction("xor", "%rdi", "%rdi");
            insts.push_back(ins);
            ins = instruction("syscall");
            insts.push_back(ins);
        }
        else {              // otherwise we perform usual callee clean up
            // end func cannot return any values    
            ins = instruction("add", "$" + to_string(y), "%rsp");   // delete all local and temporary variables
            insts.push_back(ins);
            ins = instruction("popq", "%r15");                      // restore old register values
            insts.push_back(ins);
            ins = instruction("popq", "%r14");
            insts.push_back(ins);
            ins = instruction("popq", "%r13");
            insts.push_back(ins);
            ins = instruction("popq", "%r12");
            insts.push_back(ins);
            ins = instruction("popq", "%rsi");
            insts.push_back(ins);
            ins = instruction("popq", "%rdi");
            insts.push_back(ins);
            ins = instruction("popq", "%rbx");
            insts.push_back(ins);
            ins = instruction("popq", "%rbp");
            insts.push_back(ins);
            ins = instruction("ret");
            insts.push_back(ins);
        }
    }
    else if(q.made_from == quadruple::SHIFT_POINTER) {
        // no need to do anything really for x86
    }
    else if(q.made_from == quadruple::FUNC_CALL) {
        if(x == 0) {        // if function is called without any parameters, we have yet to perform caller responsibilities
            ins = instruction("pushq", "%rax");
            insts.push_back(ins);
            ins = instruction("pushq", "%rcx");
            insts.push_back(ins);
            ins = instruction("pushq", "%rdx");
            insts.push_back(ins);
            ins = instruction("pushq", "%r8");
            insts.push_back(ins);
            ins = instruction("pushq", "%r9");
            insts.push_back(ins);
            ins = instruction("pushq", "%r10");
            insts.push_back(ins);
            ins = instruction("pushq", "%r11");
            insts.push_back(ins);
        }
        ins = instruction("call", this -> get_func_name(q.arg1));      // call the function
        insts.push_back(ins);

        if(this -> get_func_name(q.arg1) == "print") {          // deal specially with print
            ins = instruction("add", "$8", "%rsp");
            insts.push_back(ins);
        }
        else if(this -> get_func_name(q.arg1) == "allocmem") {
            ins = instruction("add", "$8", "%rsp");             // deal specially with allocmem
            insts.push_back(ins);
        }
        else if(x > 0) {                             // pop the parameters
            ins = instruction("add", "$" + to_string(x*stack_offset), "%rsp");
            insts.push_back(ins);
        }
    }
    else if(q.made_from == quadruple::RETURN_VAL) {
        // move the return value stored in %rax to the required location
        if(q.result != "") {      // if the function returns a value
            ins = instruction("mov", "%rax", to_string(x) + "(%rbp)");
            insts.push_back(ins);
        }

        // restore original state of registers
        ins = instruction("popq", "%r11");
        insts.push_back(ins);
        ins = instruction("popq", "%r10");
        insts.push_back(ins);
        ins = instruction("popq", "%r9");
        insts.push_back(ins);
        ins = instruction("popq", "%r8");
        insts.push_back(ins);
        ins = instruction("popq", "%rdx");
        insts.push_back(ins);
        ins = instruction("popq", "%rcx");
        insts.push_back(ins);
        ins = instruction("popq", "%rax");
        insts.push_back(ins);
    }
    else if(q.made_from == quadruple::PUSH_PARAM){   // pushq a(x) || pushq const
        if(y == 1) {        // first parameter, perform caller saved registers
            ins = instruction("pushq", "%rax");
            insts.push_back(ins);
            ins = instruction("pushq", "%rcx");
            insts.push_back(ins);
            ins = instruction("pushq", "%rdx");
            insts.push_back(ins);
            ins = instruction("pushq", "%r8");
            insts.push_back(ins);
            ins = instruction("pushq", "%r9");
            insts.push_back(ins);
            ins = instruction("pushq", "%r10");
            insts.push_back(ins);
            ins = instruction("pushq", "%r11");
            insts.push_back(ins);
        }
        if(!isVariable(q.arg1)) {  // it is just a constant
            ins = instruction("pushq", "$" + q.arg1, "");
            insts.push_back(ins);
        } 
        else {
            ins = instruction("pushq", to_string(x) + "(%rbp)"); // load rbp + x
            insts.push_back(ins);    
        }
    }
    else if(q.made_from == quadruple::CAST){     // r(y) = (op) a(x)
        if(!isVariable(q.arg1)) {  // it is a constant
            ins = instruction("movq", "$" + q.arg1, "%rdx");
        } 
        else {
            ins = instruction("movq", to_string(x) + "(%rbp)", "%rdx"); // load rbp + x
        }
        insts.push_back(ins);    
        ins = instruction("movq", "%rdx", to_string(y) + "(%rbp)");
        insts.push_back(ins);    
    }

    return insts;
}

codegen::codegen() {        // initialize the data members
    code.clear();
    subroutines.clear();
}

void codegen::append_ins(instruction ins) {
    this -> code . push_back(ins);
}

// void codegen::get_tac_subroutines() {
//     vector<quad> subroutine;

//     bool func_started = false;

//     for(quad q : root -> ta_codes) {
//         if(q.made_from == quad::BEGIN_FUNC) {
//             func_started = true;
//         }

//         if(func_started) {
//             subroutine.push_back(q);
//         }

//         if(q.made_from == quad::END_FUNC) {
//             func_started = false;
//             if(subroutine.size()){
//                 this -> subroutines.push_back(subroutine);
//                 subroutine.clear();
//             }
//         }
//     }
// }

void codegen::get_tac_subroutines(vector<quad> tac) {
    
    vector<quad> subroutine;
    bool func_started = false;

    for (quad q : tac) {

        if (q.made_from == quad::BEGIN_FUNC) {
            func_started = true;
        }

        if (func_started) {
            subroutine.push_back(q);
        }

        if (q.made_from == quad::END_FUNC) {
            func_started = false;
            if (!subroutine.empty()) {
                this->subroutines.push_back(subroutine);
                subroutine.clear();
            }
        }
    }
}

void codegen::gen_global() {
    // @TODO
    instruction ins;
    ins = instruction(".data", "", "", "", "segment");
    this -> code.push_back(ins);

    ins = instruction("integer_format:", ".asciz", "\"%ld\\n\"", "", "ins");
    this -> code.push_back(ins);

    ins = instruction(".global", "main", "", "", "segment");      // define entry point
    this -> code.push_back(ins);
}

void codegen::gen_basic_block(vector<quadruple> BB, subroutine_table* sub_table) {
    for(quadruple q : BB) {
        vector<instruction> insts;
        if(q.made_from == quadruple::CONDITIONAL){
            int x = sub_table -> lookup_table[q.arg1].offset;
            int y = q.abs_jump;
            insts = this -> make_x86_code(q, x, y);
        }
        else if(q.made_from == quad::GOTO){
            insts = this -> make_x86_code(q, q.abs_jump);
        }
        else if(q.made_from == quad::BINARY){
            int z = sub_table -> lookup_table[q.result].offset;
            int x = sub_table -> lookup_table[q.arg1].offset;
            int y = sub_table -> lookup_table[q.arg2].offset;
            insts = this -> make_x86_code(q, x, y, z);            
        }
        else if(q.made_from == quad::UNARY){    // b(y) = op a(x)
            int y = sub_table -> lookup_table[q.result].offset;
            int x = sub_table -> lookup_table[q.arg1].offset;
            insts = this -> make_x86_code(q, x, y);           
        }
        else if(q.made_from == quad::ASSIGNMENT){   // b(y) = a(x)
            int y = sub_table -> lookup_table[q.result].offset;
            int x = sub_table -> lookup_table[q.arg1].offset;
            insts = this -> make_x86_code(q, x, y);                
        }
        else if(q.made_from == quad::STORE){        // *(r(z) + a2) = a1(x)
            int x = sub_table -> lookup_table[q.arg1].offset;
            int y = sub_table -> lookup_table[q.arg2].offset;   // always 0 since q.arg2 contains a constant always
            int z = sub_table -> lookup_table[q.result].offset;

            insts = this -> make_x86_code(q, x, y, z);
        }
        else if(q.made_from == quad::LOAD){         // r(z) = *(a1(x) + a2)
            int x = sub_table -> lookup_table[q.arg1].offset;
            int y = sub_table -> lookup_table[q.arg2].offset; // always 0 since q.arg2 contains a constant always
            int z = sub_table -> lookup_table[q.result].offset;

            insts = this -> make_x86_code(q, x, y, z);
        }
        else if(q.made_from == quad::CAST){         // b(y) = (op) a(x)
            int x = sub_table -> lookup_table[q.arg1].offset;
            int y = sub_table -> lookup_table[q.result].offset;
            insts = this -> make_x86_code(q, x, y);
        }
        else if(q.made_from == quad::PUSH_PARAM){   // push_param a1(x)
            int x = sub_table -> lookup_table[q.arg1].offset;
            sub_table -> number_of_params++;
            insts = this -> make_x86_code(q, x, sub_table -> number_of_params);
        }
        else if(q.made_from == quad::POP_PARAM){   // r(x) = pop_param
            // no need to do anything really

            insts = this -> make_x86_code(q);
        }
        else if(q.made_from == quad::FUNC_CALL) {
            insts = this -> make_x86_code(q, sub_table -> number_of_params);
            sub_table -> number_of_params = 0;          // reset variable
        }
        else if(q.made_from == quad::RETURN_VAL) {
            insts = this -> make_x86_code(q, sub_table -> lookup_table[q.result].offset);
        }
        else if(q.made_from == quad::BEGIN_FUNC) {  // manage callee saved registers
            if(isMainFunction(q.arg1)) {
                sub_table -> is_main_function = true;
            }
            insts = this -> make_x86_code(q, sub_table -> total_space - 8 * stack_offset, sub_table -> is_main_function);        // space of 8 registers is not considered
        }
        else if(q.made_from == quad::END_FUNC) {    // clean up activation record
            // ideally only reaches this place in a void function
            insts = this -> make_x86_code(q, sub_table -> is_main_function, sub_table -> total_space - 8 * stack_offset);
        }
        else if(q.made_from == quad::SHIFT_POINTER) {       // no need to do anything really
            insts = this -> make_x86_code(q);
        }
        else if(q.made_from == quad::RETURN) {     // clean up activation record
            insts = this -> make_x86_code(q, sub_table -> total_space - 8 * stack_offset, sub_table -> lookup_table[q.arg1].offset);
        }
        else{
            insts = this -> make_x86_code(q);
        }

        // append all the instructions finally
        for(instruction ins : insts) {
            this -> append_ins(ins);
        }
    }
}

void codegen::gen_tac_basic_block(vector<quad> subroutine, subroutine_table* sub_table) {    // generates basic blocks from subroutines
    set<int> leaders;
    vector<quad > BB;

    int base_offset = subroutine[0].ins_line;
    leaders.insert(base_offset);

    for(quad q : subroutine) {
        if(q.made_from == quad::CONDITIONAL || q.made_from == quad::GOTO) {
            leaders.insert(q.abs_jump);
            leaders.insert(q.ins_line + 1);
        }
        else if(q.made_from == quad::FUNC_CALL) {
            leaders.insert(q.ins_line);
            leaders.insert(q.ins_line + 1); // call func is made of a singular basic block
        }
    }

    vector<int> ascending_leaders;
    for(int leader : leaders) { 
        ascending_leaders.push_back(leader); 
    }
    
    int prev_leader = ascending_leaders[0];
    for(int i = 1; i < ascending_leaders.size(); i++) {
        BB.clear();
        
        for(int j = prev_leader; j < ascending_leaders[i]; j++) {
            BB.push_back(subroutine[j - base_offset]);
        }
        prev_leader = ascending_leaders[i];

        this -> gen_basic_block(BB, sub_table);
    }

    BB.clear();
    int final_leader = ascending_leaders[ascending_leaders.size() - 1];
    for(int i = final_leader; i - base_offset < subroutine.size(); i++) {
        BB.push_back(subroutine[i - base_offset]);
    }

    this -> gen_basic_block(BB, sub_table);
}

void codegen::gen_fixed_subroutines() {
    func_name_map["print"] = "print";
    func_name_map["allocmem"] = "allocmem";
}

void codegen::gen_text() {
    instruction ins(".text", "", "", "", "segment");
    this -> code.push_back(ins);

    this -> gen_fixed_subroutines();

    this -> get_tac_subroutines();      // get the subroutines from entire TAC

    for(auto subroutine : this -> subroutines) {
        subroutine_table* sub_table = new subroutine_table();
        sub_table -> construct_subroutine_table(subroutine);

        this -> sub_tables .push_back(sub_table);
        this -> gen_tac_basic_block(subroutine, sub_table);
    }
}

void codegen::print_code(string asm_file) {
    ofstream out(asm_file);
    
    if(asm_file == "") {
        for(auto ins : this -> code) {
            cout << ins.code;
        }
    }
    else {
        for(auto ins : this -> code) {
            out << ins.code;
        }
    }

    ifstream print_func("print_func.s");
    string line;

    while(getline(print_func, line)){
        out << line << '\n';
    }

    ifstream alloc_mem("allocmem.s");
    while(getline(alloc_mem, line)) {
        out << line << '\n';
    }
}

subroutine_entry::subroutine_entry(){;}

subroutine_entry::subroutine_entry(string name, int offset) {
    this -> name = name;
    this -> offset = offset;
}

subroutine_table::subroutine_table(){;}

bool subroutine_table::isVariable(string s) {   // if the first character is a digit/-/+, then it is a constant and not a variable
    return !(s[0] >= '0' && s[0] <= '9') && (s[0] != '-') && (s[0] != '+');
}

void subroutine_table::construct_subroutine_table(vector<quad> subroutine_ins) {
    int pop_cnt = 2;         // 1 8 byte space for the return address + old base pointer
    int local_offset = 8;    // 8 callee saved registers hence, 8 spaces kept free, rsp shall automatically be restored, rbp too
    
    for(quad q : subroutine_ins) {
        if(q.made_from == quad::BEGIN_FUNC || q.made_from == quad::SHIFT_POINTER || q.made_from == quad::FUNC_CALL) {   // No nested procedures
            continue; 
        }
         
        if(q.made_from == quad::POP_PARAM) {
            this -> lookup_table[q.result] = subroutine_entry(q.result, stack_offset*pop_cnt);
            pop_cnt++;
        }
        else {
            if(q.made_from == quad::CONDITIONAL) {
                if(this -> lookup_table.find(q.arg1) == this -> lookup_table.end() && isVariable(q.arg1)) {
                    this -> lookup_table[q.arg1] = subroutine_entry(q.arg1, -stack_offset*local_offset);
                    local_offset++;
                }
            }
            else if(q.made_from == quad::GOTO){
                continue;
            }
            else {
                if(q.arg1 != "" && this -> lookup_table.find(q.arg1) == this -> lookup_table.end() && isVariable(q.arg1)) {
                    this -> lookup_table[q.arg1] = subroutine_entry(q.arg1, -stack_offset*local_offset);
                    local_offset++;
                }
                else if(q.arg2 != "" && this -> lookup_table.find(q.arg2) == this -> lookup_table.end() && isVariable(q.arg2)) {
                    this -> lookup_table[q.arg2] = subroutine_entry(q.arg2, -stack_offset*local_offset);
                    local_offset++;
                }
                else if(q.result != "" && this -> lookup_table.find(q.result) == this -> lookup_table.end() && isVariable(q.result)) {
                    this -> lookup_table[q.result] = subroutine_entry(q.result, -stack_offset*local_offset);
                    local_offset++;
                }
            }
        }
    }

    this -> total_space = stack_offset * local_offset;   // total space occupied by callee saved registers + locals + temporaries
}
