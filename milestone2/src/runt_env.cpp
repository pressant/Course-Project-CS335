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
    unordered_map<string, MAPVAL*>& tempo;
    void *returnAddress;

   ActivationRecord(vector<Param*>& params,
                 unordered_map<string, MAPVAL*>& locals,
                 void *retAddr,
                 ActivationRecord* access,
                 ActivationRecord* control,
                 unordered_map<string, MAPVAL*>& nonLocals)
    : parameters(params), localdecs(locals),
      returnAddress(retAddr), accessLink(access),
      controlLink(control), freevars(nonLocals) {}
};

SYMTAB* g_symtab;
ActivationRecord* curr_ar;

void execute_assignment(string src, string dst) {
    MAPVAL* d=NULL;
    MAPVAL* s=NULL;

    if (curr_ar->localdecs.find(src) != curr_ar->localdecs.end()){
        s=curr_ar->localdecs[src];
    } else if (curr_ar->freevars.find(src) != curr_ar->freevars.end()) {
        s=curr_ar->localdecs[src];
    } else if (curr_ar->tempo.find(src) != curr_ar->tempo.end()){
        s=curr_ar->tempo[src];
    }

    if (curr_ar->localdecs.find(dst) != curr_ar->localdecs.end()){
        d=curr_ar->localdecs[dst];
    } else if (curr_ar->freevars.find(dst) != curr_ar->freevars.end()) {
        d=curr_ar->localdecs[dst];
    } else if (curr_ar->tempo.find(src) != curr_ar->tempo.end()){
        d=curr_ar->tempo[dst];
    }
    else {
        d=(MAPVAL*)malloc(sizeof(MAPVAL));
        d->
        curr_ar->tempo[dst]
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


    

    void execute_addition(string op1, string op2, string result) {
        int value1 = get_variable_value(op1);
        int value2 = get_variable_value(op2);
        set_variable_value(result, value1 + value2);
    }



    int get_variable_value(string var_name) {
        if (current_activation_record->localdecs.find(var_name) != current_activation_record->localdecs.end()) {
            return stoi(current_activation_record->localdecs[var_name].value.val);
        } else {
            return stoi(current_activation_record->freevar_Offsets[var_name]->val);
        }
    }

    void set_variable_value(string var_name, int value) {
        if (current_activation_record->localdecs.find(var_name) != current_activation_record->localdecs.end()) {
            current_activation_record->localdecs[var_name].value.val = to_string(value);
        } else {
            current_activation_record->freevar_Offsets[var_name]->val = to_string(value);
        }
    }

void execute_3ac(quadruple& instruction) {
    if (instruction.op == "=") {
        execute_assignment(instruction.arg1, instruction.result);
    } else if (instruction.op == "+") {
        execute_addition(instruction.arg1, instruction.arg2, instruction.result);
    } else if (instruction.op == "-") {
        execute_subtraction(instruction.arg1, instruction.arg2, instruction.result);
    } else if (instruction.op == "*") {
        execute_multiplication(instruction.arg1, instruction.arg2, instruction.result);
    } else if (instruction.op == "/") {
        execute_division(instruction.arg1, instruction.arg2, instruction.result);
    } else if (instruction.op == "if") {
        execute_conditional_jump(instruction.arg1, instruction.result, instruction.arg2, instruction.index);
    } else if (instruction.op == "goto") {
        execute_unconditional_jump(instruction.arg1);
    } else if (instruction.op == "begin") {
        execute_function_begin(instruction.arg1);
    } else if (instruction.op == "end") {
        execute_function_end();
    } else if (instruction.op == "param") {
        execute_parameter_passing(instruction.arg1);
    } else if (instruction.op == "pushparam") {
        execute_parameter_push(instruction.arg1);
    } else if (instruction.op == "call") {
        execute_function_call(instruction.arg1);
    } else if (instruction.op == "return") {
        execute_function_return();
    } else if (instruction.op == "cast") {
        execute_type_cast(instruction.arg1, instruction.arg2, instruction.result);
    } else if (instruction.op == "string") {
        execute_string_assignment(instruction.arg1, instruction.result);
    } else {
        throw runtime_error("Unsupported 3AC instruction: " + instruction.op);
    }
}






