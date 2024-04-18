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
#include <cstring>
using namespace std;


map<string, string> register_mapping; // Map for variables and stored registers
map<string, string> temp_reg; // Map for checking whether a register is empty or being used
map<string, string> initialized_registers; // Map for registers and their initialized values
vector<vector<string>> code_lines; // Tokens for every line
vector<string> current_function; // Stores information about the current function being processed


int get_variable_size(ifstream& input_file) {
    vector<string> type_column;
    string line;
    while (getline(input_file, line)) {
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
    int variable_size = 0;
    auto element = type_column.begin();
    ++element;
    for (; element != type_column.end(); ++element) {
        if (*element == "int" || *element == "float") {
            variable_size += 4;
        } else if (*element == "char") {
            variable_size += 2;
        } else if (*element == "bool") {
            variable_size += 1;
        } else if (*element == "long" || *element == "double") {
            variable_size += 8;
        } else {
            variable_size += 8; // Default size for unknown types
        }
    }
    return variable_size;
}


int get_variable(const string& variable_name, ifstream& input_file) {
    vector<string> token_row;
    string line;
    string type;
    while (getline(input_file, line)) {
        stringstream ss(line);
        string cell;
        int column = 0;
        while (getline(ss, cell, ',')) {
            if (column == 0 && cell == variable_name) {
                getline(ss, type, ',');
            }
            column++;
        }
    }

    int variable_size = 0;
    if (type == "int" || type == "float") {
        variable_size = 4;
    } else if (type == "char") {
        variable_size = 2;
    } else if (type == "bool") {
        variable_size = 1;
    } else if (type == "long" || type == "double") {
        variable_size = 8;
    } else {
        variable_size = 8; // Default size for unknown types
    }
    return variable_size;
}

void print_function(string op_code, string operand1, string operand2) {
    if (operand2 != "") {
        output_file << "\t" << op_code << " "  << operand1 << ", " << operand2 << endl;
    } else {
        output_file << "\t" << op_code << " "  << operand1 << endl;
    }
}

string get_register(string temporary_variable) {
    if (temp_reg.empty()) {
        string register_name = "%rdi";
        temp_reg.insert({temporary_variable, register_name});
        return register_name;
    } else {
        string register_name = "%r" + to_string(register_mapping.size() + 7);
        temp_reg.insert({temporary_variable, register_name});
        return register_name;
    }
}

ifstream input_file;
ofstream output_file;

int main(int argc, char**argv){
    //string input,output;
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " " << endl;
        return 1;
    }
    char *input_filename = argv[1], *output_filename = argv[2];
    int input =0;
    int output=0;
    for (int i = 1; i < argc; ++i)     
    {
        if (std::strcmp(argv[i], "-input") == 0 && i + 1 < argc) {
            input =1;
            input_filename = argv[i + 1];
            if(output==0){
                output_filename = argv[i + 2];
            }
            i++;
        }
        else if (strcmp(argv[i], "-output") == 0 && i + 1 < argc) {
            output =1;
            output_filename = argv[i + 1];
            if(input==0){
                input_filename = argv[i + 2];
            }
            i++;
        } 
        else if(  strcmp(argv[i],"-help")==0 ){
            cout<<"To create the executable parse run the command make in the directory and make sure you have flex bison and g++ installed "<<endl;
            cout<<"To execute the file use ./parse followed by optional input tag(-input) to specify input and optional outptut tag(-output) to specify output, If you want to turn on the verbose mode do -verbose,Note:input and output file need to mentioned"<<endl;
            cout<<"To make pdf from .dot file generated use the command dot - Tpdf graph . dot -o graph . pdf"<<endl;
            exit(0);
        }
    }
        if(input_filename==NULL){input_filename=argv[1];}
        if(output_filename==NULL){output_filename=argv[1];}
    
string str;
while(getline(input_file,str)){
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
    if(tokens.size())code_lines.push_back(tokens);
}  output_file<<"\t.text"<<endl;
output_file<<"\t.section .rodata"<<endl<<".LC0:"<<endl<<"\t.string \"\%ld\\n\"\n\t.text"<<endl;
int k = 0;
int local_variable = 0;
for(int i=0;i<code_lines.size();i++){
    string reg1,reg2;
    if(code_lines[i][0] == "BeginFunc"){
        current_function.push_back(code_lines[i][1]);
        output_file<<"\t.globl "<<code_lines[i][1]<<endl;
        output_file<<"\t.type "<<code_lines[i][1]<<"@function"<<endl;
        output_file << code_lines[i][1]<<":"<<endl;   
        print_function("pushq","%rbp","");
        print_function("movq","%rsp","%rbp");

        string filename = code_lines[i][1] + ".csv";
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return 1;
        }
        int local_var_size = get_variable_size(file);
        file.close();
        output_file <<"\t" <<"subq " << "$" << local_var_size << ", %rsp" << endl;
    }   
      else if(code_lines[i][0] == "EndFunc"){
        cout << "endfunc1" << endl;
        for(auto it = temp_reg.begin(); it != temp_reg.end(); it++){
            cout << it->first << " " << it->second << endl;
            output_file << "\tpop\t" << it->second << endl;
        }
        //printfunc("movq","%rbp","%rsp");
        //f_out << "\tpopq\t"<<"%rbp"<<endl;
        output_file << "\tleave" << endl;
        output_file << "\tret" << endl;
        output_file << "\n" << "\n" << endl;
        temp_reg.clear();
        register_mapping.clear();
        initialized_registers.clear();

    }
     else if(code_lines[i][0].substr(0,2) == ".ifloop" || code_lines[i][0].substr(0,3)=="end"){
        output_file << "   " << code_lines[i][0] <<":" << endl;
    }
    else if(code_lines[i][0] == "print"){
       string temp=code_lines[i][1];
       cout<<"print"<<endl;
       if(register_mapping.find(temp)==register_mapping.end()){cout<<"hi"<<endl;print_function("movq",initialized_registers[temp],"%rsi");cout<<"bye"<<endl;}
       else{
        print_function("movq",register_mapping[temp],"%rsi");
    
        register_mapping.erase(temp);
       }
        print_function("leaq",".LC0(%rip)","%rdi");
        print_function("movq","$0","%rax");
        print_function("call","printf@PLT","");
    }
   
    // else if(lines[i][3]=="array" && lines[i].size()==4){
    //     printfunc("pushq",t[lines[i][2]],"");
    //     k-=8;
    //     s[lines[i][1]]=""

    // }
   else if(code_lines[i][0] == "goto") {
        output_file <<"\t" <<"jmp " << code_lines[i][1] << endl;
    }
    else if(code_lines[i][2] == "popparam"){
        reg1 = get_register(code_lines[i][0]);
        register_mapping.insert({code_lines[i][0],reg1});
    }
   
    else if(code_lines[i][2]=="pushparam"){cout<<"ooo"<<endl;continue;}
    else if(code_lines[i][0].substr(0,2)!="t_" && code_lines[i][2].substr(0,2) == "t_" && code_lines[i].size() == 3 && code_lines[i-1][2] == "pushparam"){
        cout<<"pushed"<<endl;
       if(register_mapping.find(code_lines[i][0])==register_mapping.end()){
             reg1=get_register(code_lines[i][0]);
             string s4 = initialized_registers[code_lines[i][2]];
             print_function("movq",register_mapping[code_lines[i][2]],reg1);
             cout<<"pushed1"<<endl;
       }
       else reg1=register_mapping[code_lines[i][0]];
       register_mapping.erase(code_lines[i][0]);
       print_function("pushq",reg1,"");
       temp_reg.erase(code_lines[i][0]);
       cout<<"pushed2"<<endl;
    }
   
    else if(code_lines[i][0].substr(0,2) == "t_" && code_lines[i].size() == 3 && code_lines[i][2][0] != 't'){
        // f_out<<"imm1"<<endl;
        initialized_registers.insert({code_lines[i][0],code_lines[i][2]});
        cout<<"lines[0][2]"<<code_lines[i][2]<<endl;
        // f_out<<"imm2"<<endl;
    }
    else if(code_lines[i][2].substr(0,2) == "t_" && code_lines[i].size() == 3) {
        string filename = current_function[current_function.size()-1] + ".csv";
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return 1;
        }
        int local_var_size = get_variable(code_lines[i][0], file);
        
        file.close();
        if(local_var_size < 8){
        k = k - local_var_size;
        string s1 = to_string(k) + "(%rsp)";
        register_mapping.insert({code_lines[i][2],s1});
        output_file << "\tmovq " << "$" << initialized_registers[code_lines[i][2]] <<", " << s1 << endl;
        // curr_func[curr_func.size()-1];
        // lines[i][0] 
        }
    }
   
     else if(code_lines[i][0].substr(0, 4) == "call") {
        output_file <<"\t" <<"call " << code_lines[i][0].substr(4) << endl;
       
    }  else if(code_lines[i][0] == "if") {
        string reg_l, reg_r;
        if(code_lines[i].size() == 6) {
            if(register_mapping.find(code_lines[i][1])!=register_mapping.end()){
            reg_l = register_mapping[code_lines[i][1]];
        }
        else if(initialized_registers.find(code_lines[i][1])!=initialized_registers.end()){
            reg_l="$" + initialized_registers[code_lines[i][1]]; 
        }
        if(register_mapping.find(code_lines[i][3])!=register_mapping.end()){
            reg_r = register_mapping[code_lines[i][3]];
        }
        else if(initialized_registers.find(code_lines[i][3])!=initialized_registers.end()){
            reg_r="$" + initialized_registers[code_lines[i][3]]; 
        } 
        if(code_lines[i].size() == 6) {
            
            print_function("cmpq", reg_r, reg_l);
            if(code_lines[i][2] == "<") print_function("jl",code_lines[i][5],"");
            if(code_lines[i][2] == ">") print_function("jg",code_lines[i][5],"");
            if(code_lines[i][2] == ">=") print_function("jge",code_lines[i][5],"");
            if(code_lines[i][2] == "<=") print_function("jle",code_lines[i][5],"");
            if(code_lines[i][2] == "==") print_function("je",code_lines[i][5],"");
            if(code_lines[i][2] == "!=") print_function("jne",code_lines[i][5],"");
        } else if(code_lines[i].size() == 4) {
            if(code_lines[i][1][0] == '!') {
                string reg_str = code_lines[i][1].substr(1,code_lines[i][1].size());
                output_file<<"\t"<<reg_str<<endl;
                reg_l = register_mapping[str];
                print_function("cmpq", reg_l, "$0");
                print_function("jz", code_lines[i][3], "");
            } else if (code_lines[i][1][0] != '!') {
                reg_l = register_mapping[code_lines[i][1]];
                print_function("cmpq", reg_l, "$0");
                print_function("jnz", code_lines[i][3], "");
            }
        }

    } else if(code_lines[i].size() == 5){
        cout<<"entered size 5 "<<endl;
        if(register_mapping.find(code_lines[i][0])==register_mapping.end()){
            reg2=get_register(code_lines[i][0]);
            register_mapping.insert({code_lines[i][0],reg2});
        }
        else {
            reg2 = register_mapping[code_lines[i][0]];
        }
        if(register_mapping.find(code_lines[i][2])!=register_mapping.end() && code_lines[i][0] != code_lines[i][2]){
            reg1 = register_mapping[code_lines[i][2]];
            print_function("movq",reg1,reg2);
        }else if(initialized_registers.find(code_lines[i][2]) != initialized_registers.end()){
           reg1 = "$" + initialized_registers[code_lines[i][2]];
           print_function("movq",reg1,reg2);
        }
        
        if(register_mapping.find(code_lines[i][4])!=register_mapping.end()){
            reg1 = register_mapping[code_lines[i][4]];
            
        }else if(initialized_registers.find(code_lines[i][4]) != initialized_registers.end()){
           reg1 = "$" + initialized_registers[code_lines[i][4]];
        }
        else if(code_lines[i][4] == "1"){
            reg1 = "$1";
        }
        register_mapping.erase(code_lines[i][4]);
            if(code_lines[i][3]=="+")print_function("addq",reg1,reg2);
            else if(code_lines[i][3]=="-")print_function("subq",reg1,reg2);
            else if(code_lines[i][3]=="*")print_function("imulq",reg1,reg2);
            else if(code_lines[i][3]=="/"|| code_lines[i][3]=="%"){
                print_function("movq",reg1,"rax");//doubt
            }else if(code_lines[i][3]=="&")print_function("andq",reg1,reg2);
            else if(code_lines[i][3]=="|")print_function("orq",reg1,reg2);
            else if(code_lines[i][3]=="^")print_function("xorq",reg1,reg2);
            
          

    }
    
cout<<"i:"<<i<<endl; 
}
}
}
//sub13 ,rbp

// rbp local varibles 
// parameters rsi rdi rax rbx rcx rdx r8 r9... r15