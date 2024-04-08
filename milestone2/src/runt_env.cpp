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
#include "symtab.cpp"
#include "3ac.cpp"
using namespace std;


class ActivationRecord {
public:
    vector<Param*> parameters;
    ActivationRecord* accessLink;
    ActivationRecord* controlLink;
    unordered_map<string, MAPVAL*> &localdecs;
    unordered_map<string, MAPVAL*>& freevars;
    unordered_map<string, MAPVAL*> tempo;
    void *returnAddress;

   ActivationRecord(vector<Param*>& params,
                    ActivationRecord* access,
                    ActivationRecord* control,
                    unordered_map<string, MAPVAL*>& locals,
                    unordered_map<string, MAPVAL*>& nonLocals,
                    void *retAddr)
    : parameters(params), localdecs(locals),
      returnAddress(retAddr), accessLink(access),
      controlLink(control), freevars(nonLocals){}
};

stack<ActivationRecord*> Display;
SYMTAB* g_symtab;
ActivationRecord* curr_ar;
quadruple* curri;

MAPVAL* myval(string s){
   if (curr_ar->localdecs.find(s) != curr_ar->localdecs.end()){
        return curr_ar->localdecs[s];
    } else if (curr_ar->freevars.find(s) != curr_ar->freevars.end()) {
        return curr_ar->localdecs[s];
    } else if (curr_ar->tempo.find(s) != curr_ar->tempo.end()){
        return curr_ar->tempo[s];
    } 
    return NULL;
}
void exec_3ac(quadruple& i){

    string arg1=i.arg1;
    string arg2=i.arg2;
    string result=i.result;
    string op=i.op;

    string type;

    MAPVAL* a1=myval(arg1);
    MAPVAL* a2=myval(arg2);
    MAPVAL* r=myval(result);

    if(a1) type=a1->type;
    else if(a2) type=a2->type;
    else if(r)  type=r->type;
    else throw runtime_error("vague instruct");

    if(!r){
        r=(MAPVAL*)malloc(sizeof(MAPVAL));
        r->name=result;
        r->type=type;
        curr_ar->tempo[result]=r;
    }

    if(type=="int"){
        int val1,val2;
        if(a1) val1=stoi(a1->val.val);
        else val1=stoi(arg1);
        if(a2) val2=stoi(a2->val.val);
        else val2=stoi(arg2);
        

        if(op=="+"){r->val.val=to_string(val1+val2);}
        else if(op=="-"){r->val.val=to_string(val1-val2);}
        else if(op=="*"){r->val.val=to_string(val1*val2);}
        else if(op=="/"){r->val.val=to_string(val1/val2);}
        else if(op=="="){r->val.val=to_string(val1);}
    }
    else if(type=="float"){
        float val1,val2;
        if(a1) val1=stof(a1->val.val);
        else val1=stof(arg1);
        if(a2) val2=stof(a2->val.val);
        else val2=stof(arg2);

        if(op=="+"){r->val.val=to_string(val1+val2);}
        else if(op=="-"){r->val.val=to_string(val1-val2);}
        else if(op=="*"){r->val.val=to_string(val1*val2);}
        else if(op=="/"){r->val.val=to_string(val1/val2);}
        else if(op=="="){r->val.val=to_string(val1);}
    }    
}



    void execute_function_body(string function_name) {
        SYMTAB* function_def = global_symbol_table->findmytab(function_name, global_symbol_table);
        vector<quadruple>& function_body = function_def->SYMVAL[function_name].body;

        for (auto& instruction : function_body) {
            execute_3ac(instruction);
        }
    }

    void execute_function_call(string function_name) {
        SYMTAB* function_def = global_symbol_table->findmytab(function_name, global_symbol_table);
        ActivationRecord* new_ar = create_activation_record(function_def->SYMVAL[function_name].params,
                                                            function_def->SYMVAL[function_name].localdecs,
                                                            get_current_instruction_address(),
                                                            current_activation_record,
                                                            function_def->SYMVAL[function_name].freevar_Offsets);
        current_activation_record = new_ar;

        execute_function_body(function_name);

        current_activation_record = current_activation_record->accessLink;
    }

    void execute_function_return() {
        current_activation_record = current_activation_record->accessLink;
    }


// void execute_3ac(quadruple& instruction) {

//     if (instruction.op == "=") {
//         execute_assignment(instruction.arg1, instruction.result);
//     } else if (instruction.op == "+") {
//         execute_addition(instruction.arg1, instruction.arg2, instruction.result);
//     } else if (instruction.op == "-") {
//         execute_subtraction(instruction.arg1, instruction.arg2, instruction.result);
//     } else if (instruction.op == "*") {
//         execute_multiplication(instruction.arg1, instruction.arg2, instruction.result);
//     } else if (instruction.op == "/") {
//         execute_division(instruction.arg1, instruction.arg2, instruction.result);
//     } else if (instruction.op == "if") {
//         execute_conditional_jump(instruction.arg1, instruction.result, instruction.arg2, instruction.index);
//     } else if (instruction.op == "goto") {
//         execute_unconditional_jump(instruction.arg1);
//     } else if (instruction.op == "begin") {
//         execute_function_begin(instruction.arg1);
//     } else if (instruction.op == "end") {
//         execute_function_end();
//     } else if (instruction.op == "param") {
//         execute_parameter_passing(instruction.arg1);
//     } else if (instruction.op == "pushparam") {
//         execute_parameter_push(instruction.arg1);
//     } else if (instruction.op == "call") {
//         execute_function_call(instruction.arg1);
//     } else if (instruction.op == "return") {
//         execute_function_return();
//     } else if (instruction.op == "cast") {
//         execute_type_cast(instruction.arg1, instruction.arg2, instruction.result);
//     } else if (instruction.op == "string") {
//         execute_string_assignment(instruction.arg1, instruction.result);
//     } else {
//         throw runtime_error("Unsupported 3AC instruction: " + instruction.op);
//     }
// }






