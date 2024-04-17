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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct quadruple{
    string op;
    string arg1;
    string arg2;
    string result;
    int index;// target label for this particular instruction

    string code = "";        // Construct from each node
    int rel_jump = 0, abs_jump = 0, ins_line = 0;
    int made_from = 0;
    bool is_target = false;
    
    enum code_code {
        BINARY,
        UNARY,
        ASSIGNMENT,
        CONDITIONAL,
        CAST,
        STORE,
        LOAD,
        FUNC_CALL,
        GOTO,
        BEGIN_FUNC,
        END_FUNC,
        RETURN,
        SHIFT_POINTER,
        PUSH_PARAM,
        POP_PARAM,
        RETURN_VAL
    };

    quadruple();
    quadruple(string r, string a1, string o, string a2);     // res = arg1 op arg2
    void make_code_from_return_val() {
    made_from = RETURN_VAL;
    if(result != "") {
        code = "\t\t" + result + " = " + "return_value;\n";
    }
    else {
        code = "\t\treturn_value;\n";
    }

    arg1 = "";
    arg2 = "";
}

void make_code_from_binary(){
    made_from = BINARY;
    code = "\t\t" + result + " = " + arg1 + " " + op + " " + arg2 + ";\n";
}

void make_code_from_unary(){
    made_from = UNARY;
    code = "\t\t" + result + " = " + op + "(" + arg1 + ");\n";
    arg2 = "";
}

void make_code_from_assignment(){
    made_from = ASSIGNMENT;
    code = "\t\t" + result + " = " + arg1 + ";\n";
    op = "=";
    arg2 = "";
}

void make_code_from_cast(){
    made_from = CAST;
    code = "\t\t" + result + " = (" + op + ") " + arg1 + ";\n";
    arg2 = "";
}

void make_code_from_store(){
    made_from = STORE;
    code = "\t\t*(" + result;
    if(arg2 != ""){
        code += " + " + arg2;
    }
    code += ") = " + arg1 + ";\n";
    op = "";
}

void make_code_from_load(){
    made_from = LOAD;
    code = "\t\t" + result + " = *(" + arg1;
    if(arg2 != "") {
        code = code + " + " + arg2;
    }
    code = code + ");\n";
    op = "";
}

void make_code_from_conditional(){
    made_from = CONDITIONAL;
    if(!rel_jump){
        rel_jump = stoi(arg2.substr(1, arg2.size()-1));
    }
    code = "\t\t" + op + " " + arg1 + " goto ";

    result = "";
}

void make_code_from_func_call(){
    made_from = FUNC_CALL;
    code = "\t\t" + op + " " + arg1 + ";\n";
    result = "";
    arg2 = "";
}

void make_code_from_goto(){
    made_from = GOTO;
    if(!rel_jump){
        rel_jump = stoi(arg1.substr(1, arg1.size()-1));
    }
    code = "\t\t" + op + " ";       // op is "GOTO"
    arg2 = "";
    result = "";
}

void check_jump(const int ins_line){
    this->ins_line = ins_line;
    if(rel_jump){
        abs_jump = ins_line + rel_jump;
        code += to_string(abs_jump) + ";\n";
    }
}
    
void make_code_begin_func() {
    made_from = BEGIN_FUNC;
    code = "\t\tbegin_func " + arg1 + "\n";
    arg2 = "";
    op = "";
    result = "";
}

void make_code_end_func() {
    made_from = END_FUNC;
    code = "\t\tend_func\n";
    arg1 = "";
    arg2 = "";
    op = "";
    result = "";
}

void make_code_from_return() {
    made_from = RETURN;
    if(arg1 != ""){
        code = "\t\t" + op + " " + arg1 + ";\n";    // op is "return"
    }
    else{
        code = "\t\t" + op + ";\n";                 // op is "return"
    }
    arg2 = "";
    result = "";
}

void make_code_shift_pointer() {
    made_from = SHIFT_POINTER;
    code = "\t\tshift_pointer " + arg1 + "\n";

    result = "";
    op = "";
    arg2 = "";
}

void make_code_push_param(){
    made_from = PUSH_PARAM;
    code = "\t\t" + op + " " + arg1 + ";\n";

    arg2 = "";
    result = "";
}

void make_code_pop_param() {
    made_from = POP_PARAM;
    code = "\t\t" + result + " = pop_param;\n";

    arg2 = "";
    arg1 = "";
    op = "";
}

void make_code(){
    if(this -> made_from == BINARY){
        this -> make_code_from_binary();
    }
    else if(this -> made_from == UNARY){
        this -> make_code_from_unary();
    }
    else if(this -> made_from == ASSIGNMENT){
        this -> make_code_from_assignment();
    }
    else if(this -> made_from == CONDITIONAL){
        this -> make_code_from_conditional();
    }
    else if(this -> made_from == CAST){
        this -> make_code_from_cast();
    }
    else if(this -> made_from == STORE){
        this -> make_code_from_store();
    }
    else if(this -> made_from == LOAD){
        this -> make_code_from_load();
    }
    else if(this -> made_from == FUNC_CALL){
        this -> make_code_from_func_call();
    }
    else if(this -> made_from == GOTO){
        this -> make_code_from_goto();
    }
    else if(this -> made_from == PUSH_PARAM){
        this -> make_code_push_param();
    }
    else if(this -> made_from == BEGIN_FUNC){
        this -> make_code_begin_func();
    }
    else if(this -> made_from == END_FUNC){
        this -> make_code_end_func();
    }
    else if(this -> made_from == RETURN){
        this -> make_code_from_return();
    }
    else if(this -> made_from == SHIFT_POINTER){
        this -> make_code_shift_pointer();
    }
    else if(this -> made_from == POP_PARAM) {
        this -> make_code_pop_param();
    }
    else if(this -> made_from == RETURN_VAL) {
        this -> make_code_from_return_val();
    }
}

}quadruple;

int inst_num=0;
vector <quadruple> code;
vector <quadruple> curr;

int var_num = 0;
void codepush(string op,string arg1, string arg2, string result, int idx){
    quadruple entry;
    entry.op = op;
    entry.arg1 = arg1;
    entry.arg2 = arg2;
    entry.result = result;
    entry.index = idx;
    code.push_back(entry);
    inst_num++;
}

void print3ac(){
    ofstream tac_file;
    string file_name = "3ac.txt";
    tac_file.open(file_name);
    for(int i=0;i<code.size();i++){
        if(code[i].op == "param"){
            tac_file<<i<<":  "<<code[i].arg1<<endl;
        }
        if(code[i].op == "pushparam"){
            tac_file<<i<<":  "<<code[i].arg1<<endl;
        }
        if(code[i].op == "pushparam"){
            tac_file<<i<<":  "<<code[i].arg1<<endl;
        }
        else if(code[i].op == "string"){
            tac_file<<i<<":    "<<code[i].arg1<<endl;
        }
        else if(code[i].op == "cast"){
            tac_file<<i<<":    "<<code[i].result<<" = cast_to_"<<code[i].arg2<<" "<<code[i].arg1<<endl;
        }
        else if(code[i].op == "begin"){
            tac_file<<i<<": BeginFunc "<<code[i].arg1<<endl;
        }
        else if(code[i].op == "end"){
            tac_file<<i<<": EndFunc"<<endl<<endl;
        }
        else if(code[i].op == "if"){
            tac_file<<i<<":    if "<<code[i].arg1<<" "<<code[i].result<<" "<<code[i].arg2<<"goto" << code[i].index<<"\n";
        }
        else if(code[i].result=="goto"){
            tac_file<<i<<":    goto "<<code[i].arg1<<endl;
        }
        else if(code[i].op==""){
            tac_file<<i<<":    "<<code[i].result<<" = "<<code[i].arg1<<endl;
        }
        else if(code[i].arg1=="call"){
            tac_file<<i<<":    "<<code[i+1].result<<" = "<<code[i].arg1<<" "<<code[i].arg2<<endl;
            i++;
        }
        else {
            tac_file <<i<<":    "<<code[i].result<<" = "<<code[i].arg1<<" "<<code[i].op<<" "<<code[i].arg2<<"\n";
        }
    }
}

string new_temporary(){
    string temp_var="t_"+to_string(var_num);
    var_num++;
    return temp_var;
}

