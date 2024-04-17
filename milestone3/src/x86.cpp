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
using namespace std;
ifstream f_in;
ofstream f_out;
map<string,string> t; //map for variables and stored registers
map<string,string> r; //whether a register is empty or being used
map<string,string> s;
vector<vector<string> >lines;//tokens for every line
vector<string> curr_func;

void printfunc(string a, string b, string c){
    f_out << "\t" << a << " "  << b << " " << c << endl;
    // if(b=="")f_out<<endl;
    // else{
    //     if(b.size()>3 && b.substr(0,3)=="rbp"){
    //         string p = b.substr(4,b.size()-5);
    //         f_out<<"\t"<<p<<"(%rbp)";
    //     }else if(b[0]=='r') f_out<<"\t\%"<<b;
    //     else f_out<<"\t"<<b;
    //     if(c=="") f_out<<endl;
    //     else{
    //         if(c.size()>3 && c.substr(0,3)=="rbp"){
    //             string p = c.substr(4,c.size()-5);
    //             f_out<<", "<<p<<"(%rbp)"<<endl;
    //         }else if(c[0]=='r') f_out<<", \%"<<c<<endl;
    //         else f_out<<", "<<c<<endl;
    //     }
    // }
}

int get_size(ifstream& file){
    vector<string> type_column;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        int column = 0;
        while (getline(ss, cell, ',')) {
            if (column == 1) {
                type_column.push_back(cell);
            }
            column++;
        }
    }
    int lVar_size = 0;
    auto element = type_column.begin();
    ++element;
    for (; element != type_column.end(); ++element) {
        if(*element =="int" || *element =="float") lVar_size += 4;
        else if(*element =="char" ) lVar_size += 2;
        else if(*element =="bool") lVar_size += 1;
        else if(*element =="long" || *element =="double") lVar_size += 8;
        else lVar_size += 8;
    }
    return lVar_size;
}

int var_size(string str, ifstream& file) {
    vector<string> token_row;
    string line;
    string type;
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        int column = 0;
        while (getline(ss, cell, ',')) {
            if (column == 0 && cell == str) {
                getline(ss, type, ',');
            }
            column++;
        }
    }

    int lVar_size = 0;
    if(type =="int" || type =="float") lVar_size = 4;
    else if(type =="char" ) lVar_size = 2;
    else if(type =="bool") lVar_size = 1;
    else if(type =="long" || type =="double") lVar_size = 8;
    else lVar_size = 8;
    return lVar_size;
}

// string get_empty_reg(string reg = ""){
//     if(r.empty()) return "r8";
//     for(int l=8;l<16;l++){
//         if(r.find("r"+to_string(l))==r.end()) return "r"+to_string(l);
//     }
//     if(reg != "r8") reg = "r8";
//     else reg = "r9";
//     print("pushq",reg,"");
//     k-=8;
//     t.erase(r[reg]);
//     s[r[reg]] = "rbp["+to_string(k)+"]";
//     r.erase(reg);
//     return reg;
// }


string getreg(string temp_var){
    if(r.size() == 0){ 
        string reg = "rsi" ;
        r.insert({temp_var,reg});
        return reg;
    } else if(r.size() == 1){
        string reg = "rdi";
        r.insert({temp_var,reg});
        return reg;
    } else {
        string reg = "r" + to_string(r.size() + 6);
        r.insert({temp_var,reg});
        return reg;
    }
}


int main(int argc, char**argv){
    string input,output;
    if(argc<2){
        cout<<"No Actions Provided"<<endl;
        exit(1);
    }
    bool k_1;
    for(int i=1;i<argc;i++){
        string k = argv[i];
        if(k.size()<6){
            cout<<k<<" is not a valid option."<<endl;
            exit(1);
        }
        if(k=="--help"){
            cout<<"Available Options:"<<endl<<endl;
            cout<<"--help     :  Opens this menu"<<endl;
            cout<<"--input    :  To enter input file destination from the build folder"<<endl;
            cout<<"--output   :  To enter output file destination from the build folder"<<endl;
            exit(1);
        }
        else if(k.size()<8){
            cout<<k<<" is not a valid option."<<endl;
            exit(1);
        }
        else if(k.substr(0,8)=="--input=") input = k.substr(8,k.size()-8);
        else if(k.size()<9){
            cout<<k<<" is not a valid option."<<endl;
            exit(1);
        }
        else if(k.size()<9){
            cout<<k<<" is not a valid option."<<endl;
            exit(1);
        }
        else if(k.substr(0,9)=="--output=") output = k.substr(9,k.size()-9);
        else{
            cout<<k<<" is not a valid option."<<endl;
            exit(1);
        }
    }
    if(input.size()==0){
        cout<<"No input file provided"<<endl;
        exit(1);
    }
    if(output.size()==0){
        output = input.substr(0,input.size()-3)+"s";
    }
f_in.open(input);
f_out.open(output);
string str;
while(getline(f_in,str)){
    vector<string>tokens;
    string token;int p=0;//not in brac
    for(int i=0;i<str.size();i++){
     if(str[i]=='(')p++;
     else if(str[i]==')')p--;
     if(str[i]==' '&& p==0){
        if(token.size()!=0)tokens.push_back(token);
        token.clear();
     }else token.push_back(str[i]);
    }
    if(token.size()!=0)tokens.push_back(token);
    if(tokens.size())lines.push_back(tokens);
}  f_out<<"\t.section .data"<<endl;
//<<".LC0:"<<endl<<"\t.string \"\%ld\\n\"\n\t.text"<<endl;
/*
if(lines[0][0]!=".globl"){
    cout<<"main function not called"<<endl;
    exit(1);
}
*/
int k = 0;
for(int i=0;i<lines.size();i++){
    string reg1,reg2;
    if(lines[i][0] == "BeginFunc"){
        curr_func.push_back(lines[i][1]);
        f_out<<"\t.globl "<<lines[i][1]<<endl;
        f_out<<"\t.type "<<lines[i][1]<<"@function"<<endl;
        f_out << lines[i][1]<<":"<<endl;   
        printfunc("pushq","rbp","");
        printfunc("movq","rsp","rbp");

        string filename = lines[i][1] + ".csv";
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return 1;
        }
        int local_var_size = get_size(file);
        file.close();
        f_out <<"\t" <<"sub " << "$" << local_var_size << " %rsp" << endl;
    }   
    else if(lines[i][0].substr(0,2) == ".L"){
        f_out << "   " << lines[i][0] <<":" << endl;
    }
    else if(lines[i][2] == "popparam"){
        reg1 = getreg(lines[i][0]);
        t.insert({lines[i][0],reg1});
    }
    else if(lines[i][0].substr(0,2) == "t_" && lines[i].size() == 3){
        s.insert({lines[i][0],lines[i][2]});
    }
    else if(lines[i][2][0] == 't' && lines[i].size() == 3) {
        string filename = curr_func[curr_func.size()-1] + ".csv";
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return 1;
        }
        int local_var_size = var_size(lines[i][0], file);
        
        file.close();
        if(local_var_size < 8){
        k = k - local_var_size;
        string s1 = to_string(k) + "(%rsp)";
        t.insert({lines[i][2],s1});
        f_out << "\tmovq " << "$" << s[lines[i][2]] <<" " << s1 << endl;
        // curr_func[curr_func.size()-1];
        // lines[i][0] 
        }
    }
   
    else if(lines[i][0] == "goto") {
        f_out <<"\t" <<"jmp " << lines[i][1] << endl;
    } else if(lines[i][0].substr(0, 4) == "call") {
        f_out <<"\t" <<"call " << lines[i][0].substr(4) << endl;
    } else if(lines[i][0].size()>=5 && lines[i][0].substr(0,5)=="print"){
       string temp=lines[i][1];
       if(t.find(temp)==t.end())printfunc("movq",t[temp],"rsi");
       else{
        printfunc("movq",t[temp],"rsi");
        r.erase(t[temp]);
        t.erase(temp);
       }
        printfunc("leaq",".LC0(%rip)","rdi");
        printfunc("movq","$0","rax");
        printfunc("call","printf@PLT","");
    } else if(lines[i][0] == "if") {
        string reg_l, reg_r;
        if(lines[i].size() == 6) {
            reg_l = t[lines[i][1]];
            reg_r = t[lines[i][3]];
            printfunc("cmpq", reg_l, reg_r);
            if(lines[i][2] == "<") printfunc("jl",lines[i][5],"");
            if(lines[i][2] == ">") printfunc("jg",lines[i][5],"");
            if(lines[i][2] == ">=") printfunc("jge",lines[i][5],"");
            if(lines[i][2] == "<=") printfunc("jle",lines[i][5],"");
            if(lines[i][2] == "==") printfunc("je",lines[i][5],"");
            if(lines[i][2] == "!=") printfunc("jne",lines[i][5],"");
        } else if(lines[i].size() == 4) {
            if(lines[i][1][0] == '!') {
                string reg_str = lines[i][0].substr(1);
                reg_l = t[str];
                printfunc("cmpq", reg_l, "$0");
                printfunc("jz", lines[i][3], "");
            } else if (lines[i][1][0] != '!') {
                reg_l = t[lines[i][1]];
                printfunc("cmpq", reg_l, "$0");
                printfunc("jnz", lines[i][3], "");
            }
        }
    } else{

        if(t.find(lines[i][2])==t.end()){
            reg1=getreg(lines[i][0]);
            printfunc("movq",lines[i][2],reg1);
            t[lines[i][2]] = reg1;
        }else{
            reg1=t[lines[i][2]];
        }
        t.erase(lines[i][2]);
        if(s.find(lines[i][4])==s.end()){
            reg2=getreg(lines[i][4]);
            printfunc("movq",lines[i][4],reg2);
            s[lines[i][2]] = reg1;
        } 
        else{
            reg2="$" + s[lines[i][4]];
        }
        t.erase(lines[i][4]);
            if(lines[i][3]=="+")printfunc("addq",reg2,reg1);
            else if(lines[i][3]=="-")printfunc("subq",reg2,reg1);
            else if(lines[i][3]=="*")printfunc("imulq",reg2,reg1);
            else if(lines[i][3]=="/"|| lines[i][3]=="%"){
                printfunc("movq",reg1,"rax");//doubt
            }else if(lines[i][3]=="&")printfunc("andq",reg2,reg1);
            else if(lines[i][3]=="|")printfunc("orq",reg2,reg1);
            else if(lines[i][3]=="^")printfunc("xorq",reg2,reg1);
            r[reg1]=lines[i][0];
            r.erase(reg2);
            t[lines[i][0]]=reg1;//reg1=reg1+reg2

    }
    
}
  
}
//sub13 ,rbp

// rbp local varibles 
// parameters rsi rdi rax rbx rcx rdx r8 r9... r15
