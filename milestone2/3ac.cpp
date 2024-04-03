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
#include "3ac.h"

vector <quadruple> code;
vector <quadruple> current;

extern string out_file_name;
long long int variable_number=0;
long long int label_number=0;
int inst_num;

using namespace std;


void emitt(string op,string arg1, string arg2, string result, int idx){
    quadruple entry;
    entry.op=op;
    entry.arg1=arg1;
    entry.arg2=arg2;
    entry.result=result;
    entry.index=idx;
    code.push_back(entry);
    inst_num++;
}

string array_access(string name, vector<int> a, vector<int> b){
    string t = new_temporary();
    for(int i=0;i<a.size();i++){
        if(i==0) emitt("*","#t_"+to_string(a[i]),"#t_"+to_string(b[i]),t,-1);
        else{
            string s = new_temporary();
            emitt("*","#t_"+to_string(a[i]),"#t_"+to_string(b[i]),s,-1);
            emitt("+",t,s,t,-1);
        }
    }
    return "*("+name+" + "+t+")";
}

string new_temporary(){
    string temp_var="#t_"+to_string(variable_number);
    variable_number++;
    return temp_var;
}

int reduce(string name){
    return stoi(name.substr(3,name.size()-1));
}

void print3AC_code(){
    ofstream tac_file;
    string file_name = out_file_name+"3ac.txt";
    tac_file.open(file_name);
    for(int i=0;i<code.size();i++){
        if(code[i].op == "array"){
            emitt("string","push_param "+code[i].arg1,"","",-1);
            emitt("string","stack_pointer +8","","",-1);
            emitt("string","call alloc 1","","",-1);
            emitt("string","stack_pointer -8","","",-1);
            emitt("","pop 4","",code[i].result,-1);
            emitt("string","pop 4","","",-1);
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
            tac_file<<i<<":    if "<<code[i].arg1<<" "<<code[i].result<<" "<<code[i].index<<"\n";
        }
        else if(code[i].result=="goto"){
            tac_file<<i<<":    goto "<<code[i].index<<endl;
        }
        else if(code[i].op==""){
            tac_file<<i<<":    "<<code[i].result<<" = "<<code[i].arg1<<endl;
        }
        else {
            tac_file <<i<<":    "<<code[i].result<<" = "<<code[i].arg1<<" "<<code[i].op<<" "<<code[i].arg2<<"\n";
        }
    }
}

void backpatch(vector <int>&instructions, int target){
    for (int i=0;i<instructions.size();i++){
        code[instructions[i]].index=target;
        //cout<<instructions[i]<<" ";
    }
    //cout<<endl;

}

vector<int> merge(vector <int>& list1, vector <int>& list2){
    for(int i=0;i<list2.size();i++){
        list1.push_back(list2[i]);
    }
    return list1;
}

void array_func(string name, vector<int>&dim, string type){
    string size;
    if(type.substr(0,3)=="int" || type.substr(0,5)=="float") size="4";
    else if(type.substr(0,4)=="char" || type.substr(0,4)=="short") size="2";
    else if(type.substr(0,4)=="byte") size = "1";
    else if(type.substr(0,4)=="long" || type.substr(0,6)=="double") size = "8";
    else {
        cout<<"Unexpected Error Occurred. Pls give diff input"<<endl;
        exit(1);
    }
    string t = new_temporary();
    emitt("",size,"",t,-1);
    for(int i=dim.size()-1;i>=0;i--){
        string k = new_temporary();
        emitt("*","#t_"+to_string(dim[i]),t,k,-1);
        dim[i]=reduce(t);
        t=k;
    }
    emitt("array",t,"",name,-1);
}