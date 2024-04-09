#ifndef runt_env
#define runt_env

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
#include "parser.cpp"
using namespace std;


class ActivationRecord {
public:
    vector<void*> &parameters;
    ActivationRecord* accessLink;
    ActivationRecord* controlLink;
    unordered_map<string, MAPVAL>* localdecs;
    unordered_map<string, MAPVAL*>* freevars;
    unordered_map<string, MAPVAL*> tempo;
    void *returnAddress;

    ActivationRecord(vector<void*>& params,
                    ActivationRecord* access,
                    ActivationRecord* control,
                    unordered_map<string, MAPVAL>* locals,
                    unordered_map<string, MAPVAL*>* nonLocals,
                    void *retAddr)
    : parameters(params), accessLink(access),
       controlLink(control), localdecs(locals),
      returnAddress(retAddr), freevars(nonLocals){}
};

stack<ActivationRecord*> Display;
ActivationRecord* accessing;
SYMTAB* g_symtab=gt;


void execute_function_body(string name,ActivationRecord* ar) {

}
 
void execute_function_call(string name,vector<void*>& p, void* r) {
    SYMTAB* func = g_symtab->findmytab(name, g_symtab);
    unordered_map<string, MAPVAL>* locals = &(func->childs[name]->SYMVAL);
    unordered_map<string, MAPVAL*> *nonLocals = &(func->childs[name]->freepointers);
    ActivationRecord* new_ar = new ActivationRecord(p, accessing, Display.top(), locals, nonLocals, r);
    Display.push(new_ar);
    execute_function_body(name, Display.top());
    Display.pop();
}
