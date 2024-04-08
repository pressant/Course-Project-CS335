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
using namespace std;

// quadruple* curri;
// ActivationRecord* curr_ar=Display.top();

// MAPVAL* myval(string s){
//    if (curr_ar->localdecs.find(s) != curr_ar->localdecs.end()){
//         return curr_ar->localdecs[s];
//     } else if (curr_ar->freevars.find(s) != curr_ar->freevars.end()) {
//         return curr_ar->localdecs[s];
//     } else if (curr_ar->tempo.find(s) != curr_ar->tempo.end()){
//         return curr_ar->tempo[s];
//     } 
//     return NULL;
// }
// void ThreeAC_to_x86_64(quadruple& i){

//     string arg1=i.arg1;
//     string arg2=i.arg2;
//     string result=i.result;
//     string op=i.op;

//     string type;

//     MAPVAL* a1=myval(arg1);
//     MAPVAL* a2=myval(arg2);
//     MAPVAL* r=myval(result);

//     if(a1) type=a1->type;
//     else if(a2) type=a2->type;
//     else if(r)  type=r->type;
//     else throw runtime_error("vague instruct");

//     if(!r){
//         r=(MAPVAL*)malloc(sizeof(MAPVAL));
//         r->name=result;
//         r->type=type;
//         curr_ar->tempo[result]=r;
//     }

//     if(type=="int"){
//         int val1,val2;
//         if(a1) val1=stoi(a1->val.val);
//         else val1=stoi(arg1);
//         if(a2) val2=stoi(a2->val.val);
//         else val2=stoi(arg2);
        

//         if(op=="+"){r->val.val=to_string(val1+val2);}
//         else if(op=="-"){r->val.val=to_string(val1-val2);}
//         else if(op=="*"){r->val.val=to_string(val1*val2);}
//         else if(op=="/"){r->val.val=to_string(val1/val2);}
//         else if(op=="="){r->val.val=to_string(val1);}
//     }
//     else if(type=="float"){
//         float val1,val2;
//         if(a1) val1=stof(a1->val.val);
//         else val1=stof(arg1);
//         if(a2) val2=stof(a2->val.val);
//         else val2=stof(arg2);

//         if(op=="+"){r->val.val=to_string(val1+val2);}
//         else if(op=="-"){r->val.val=to_string(val1-val2);}
//         else if(op=="*"){r->val.val=to_string(val1*val2);}
//         else if(op=="/"){r->val.val=to_string(val1/val2);}
//         else if(op=="="){r->val.val=to_string(val1);}
//     }    
// }
