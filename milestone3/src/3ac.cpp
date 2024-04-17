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
            tac_file<<i<<":  "<<code[i].arg1<<endl;
        }
        else if(code[i].op == "cast"){
            tac_file<<i<<":  "<<code[i].result<<" = cast_to_"<<code[i].arg2<<" "<<code[i].arg1<<endl;
        }
        else if(code[i].op == "begin"){
            tac_file<<i<<":  BeginFunc "<<code[i].arg1<<endl;
        }
        else if(code[i].op == "end"){
            tac_file<<i<<":  EndFunc"<<endl<<endl;
        }
        else if(code[i].op == "if"){
            tac_file<<i<<":  if "<<code[i].arg1<<" "<<code[i].result<<" "<<code[i].arg2<<" goto" << code[i].index<<"\n";
        }
        else if(code[i].result=="goto"){
            tac_file<<i<<":  goto "<<code[i].arg1<<endl;
        }
        else if(code[i].op==""){
            tac_file<<i<<":  "<<code[i].result<<" = "<<code[i].arg1<<endl;
        }
        else if(code[i].arg1=="call"){
            if(code[i+1].result !="")
            tac_file<<i<<":  "<<code[i+1].result<<" = "<<code[i].arg1<<" "<<code[i].arg2<<endl;
            else {
                tac_file<<i<<":  "<<code[i].arg1<<" "<<code[i].arg2<<endl;
            }
            i++;
        }
        else {
            tac_file <<i<<":  "<<code[i].result<<" = "<<code[i].arg1<<" "<<code[i].op<<" "<<code[i].arg2<<"\n";
        }
    }
}

string new_temporary(){
    string temp_var="t_"+to_string(var_num);
    var_num++;
    return temp_var;
}

