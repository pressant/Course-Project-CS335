#include<bits/stdc++.h>
using namespace std;
ifstream f_in;
ofstream f_out;
map<string,string> reg_map; // t map for variables and stored registers
map<string,string> temp_reg; // r whether a register is empty or being used
map<string,string> init_reg; // s reg and initialised value is stored
vector<vector<string> >lines;//tokens for every line
vector<string> curr_func;

void printfunc(string a, string b, string c){
     try {
        int value = std::stoi(b);
        if (value >= 0 && value <= 9) {
            b = '$' + b;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    if(c != "") {
        f_out << "\t" << a << " "  << b << ", " << c << endl;
    }
    else f_out << "\t" << a << " "  << b << endl;
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

string getreg(string temp_var){
     if(temp_reg.size() == 0){
        string reg = "%rdi";
        temp_reg.insert({temp_var,reg});
        return reg;
    } else {
        string reg = "%r" + to_string(reg_map.size() + 7);
        temp_reg.insert({temp_var,reg});
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
}  f_out<<"\t.text"<<endl;
f_out<<"\t.section .rodata"<<endl<<".LC0:"<<endl<<"\t.string \"\%ld\\n\"\n\t.text"<<endl;
int k = 0;
int local_variable = 0;
for(int i=0;i<lines.size();i++){
    string reg1,reg2;
    if(lines[i][0] == "BeginFunc"){
        curr_func.push_back(lines[i][1]);
        f_out<<"\t.globl "<<lines[i][1]<<endl;
        f_out<<"\t.type "<<lines[i][1]<<"@function"<<endl;
        f_out << lines[i][1]<<":"<<endl;   
        printfunc("pushq","%rbp","");
        printfunc("movq","%rsp","%rbp");

        string filename = lines[i][1] + ".csv";
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file." << endl;
            return 1;
        }
        int local_var_size = get_size(file);
        file.close();
        f_out <<"\t" <<"subq " << "$" << local_var_size << ", %rsp" << endl;
    }   
      else if(lines[i][0] == "EndFunc"){
        cout << "endfunc1" << endl;
        for(auto it = temp_reg.begin(); it != temp_reg.end(); it++){
            cout << it->first << " " << it->second << endl;
            f_out << "\tpop\t" << it->second << endl;
        }
        //printfunc("movq","%rbp","%rsp");
        //f_out << "\tpopq\t"<<"%rbp"<<endl;
        f_out << "\tleave" << endl;
        f_out << "\tret" << endl;
        f_out << "\n" << "\n" << endl;
        temp_reg.clear();
        reg_map.clear();
        init_reg.clear();

    }
     else if(lines[i][0].substr(0,2) == ".L" || lines[i][0].substr(0,3)=="end"){
        f_out << "   " << lines[i][0] <<":" << endl;
    }
    else if(lines[i][0] == "print"){
       string temp=lines[i][1];
       cout<<"print"<<endl;
       if(reg_map.find(temp)==reg_map.end()){cout<<"hi"<<endl;printfunc("movq",init_reg[temp],"%rsi");cout<<"bye"<<endl;}
       else{
        printfunc("movq",reg_map[temp],"%rsi");
    
        reg_map.erase(temp);
       }
        printfunc("leaq",".LC0(%rip)","%rdi");
        printfunc("movq","$0","%rax");
        printfunc("call","printf@PLT","");
    }
   
    // else if(lines[i][3]=="array" && lines[i].size()==4){
    //     printfunc("pushq",t[lines[i][2]],"");
    //     k-=8;
    //     s[lines[i][1]]=""

    // }
   else if(lines[i][0] == "goto") {
        f_out <<"\t" <<"jmp " << lines[i][1] << endl;
    }
    else if(lines[i][2] == "popparam"){
        reg1 = getreg(lines[i][0]);
        reg_map.insert({lines[i][0],reg1});
    }
   
    else if(lines[i][2]=="pushparam"){cout<<"ooo"<<endl;continue;}
    else if(lines[i][0].substr(0,2)!="t_" && lines[i][2].substr(0,2) == "t_" && lines[i].size() == 3 && lines[i-1][2] == "pushparam"){
        cout<<"pushed"<<endl;
       if(reg_map.find(lines[i][0])==reg_map.end()){
             reg1=getreg(lines[i][0]);
             string s4 = init_reg[lines[i][2]];
             printfunc("movq",reg_map[lines[i][2]],reg1);
             cout<<"pushed1"<<endl;
       }
       else reg1=reg_map[lines[i][0]];
       reg_map.erase(lines[i][0]);
       printfunc("pushq",reg1,"");
       temp_reg.erase(lines[i][0]);
       cout<<"pushed2"<<endl;
    }
   
    else if(lines[i][0].substr(0,2) == "t_" && lines[i].size() == 3 && lines[i][2][0] != 't'){
        // f_out<<"imm1"<<endl;
        init_reg.insert({lines[i][0],lines[i][2]});
        cout<<"lines[0][2]"<<lines[i][2]<<endl;
        // f_out<<"imm2"<<endl;
    }
    else if(lines[i][2].substr(0,2) == "t_" && lines[i].size() == 3) {
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
        reg_map.insert({lines[i][2],s1});
        f_out << "\tmovq " << "$" << init_reg[lines[i][2]] <<", " << s1 << endl;
        // curr_func[curr_func.size()-1];
        // lines[i][0] 
        }
    }
   
     else if(lines[i][0].substr(0, 4) == "call") {
        f_out <<"\t" <<"call " << lines[i][0].substr(4) << endl;
       
    }  else if(lines[i][0] == "if") {
        string reg_l, reg_r;
        if(lines[i].size() == 6) {
            if(reg_map.find(lines[i][1])!=reg_map.end()){
            reg_l = reg_map[lines[i][1]];
        }
        else if(init_reg.find(lines[i][1])!=init_reg.end()){
            reg_l="$" + init_reg[lines[i][1]]; 
        }
        if(reg_map.find(lines[i][3])!=reg_map.end()){
            reg_r = reg_map[lines[i][3]];
        }
        else if(init_reg.find(lines[i][3])!=init_reg.end()){
            reg_r="$" + init_reg[lines[i][3]]; 
        } 
        if(lines[i].size() == 6) {
            
            printfunc("cmpq", reg_r, reg_l);
            if(lines[i][2] == "<") printfunc("jl",lines[i][5],"");
            if(lines[i][2] == ">") printfunc("jg",lines[i][5],"");
            if(lines[i][2] == ">=") printfunc("jge",lines[i][5],"");
            if(lines[i][2] == "<=") printfunc("jle",lines[i][5],"");
            if(lines[i][2] == "==") printfunc("je",lines[i][5],"");
            if(lines[i][2] == "!=") printfunc("jne",lines[i][5],"");
        } else if(lines[i].size() == 4) {
            if(lines[i][1][0] == '!') {
                string reg_str = lines[i][1].substr(1,lines[i][1].size());
                f_out<<"\t"<<reg_str<<endl;
                reg_l = reg_map[str];
                printfunc("cmpq", reg_l, "$0");
                printfunc("jz", lines[i][3], "");
            } else if (lines[i][1][0] != '!') {
                reg_l = reg_map[lines[i][1]];
                printfunc("cmpq", reg_l, "$0");
                printfunc("jnz", lines[i][3], "");
            }
        }

    } else if(lines[i].size() == 5){
        cout<<"entered size 5 "<<endl;
        if(reg_map.find(lines[i][0])==reg_map.end()){
            reg2=getreg(lines[i][0]);
            reg_map.insert({lines[i][0],reg2});
        }
        else {
            reg2 = reg_map[lines[i][0]];
        }
        if(reg_map.find(lines[i][2])!=reg_map.end() && lines[i][0] != lines[i][2]){
            reg1 = reg_map[lines[i][2]];
            printfunc("movq",reg1,reg2);
        }else if(init_reg.find(lines[i][2]) != init_reg.end()){
           reg1 = "$" + init_reg[lines[i][2]];
           printfunc("movq",reg1,reg2);
        }
        
        if(reg_map.find(lines[i][4])!=reg_map.end()){
            reg1 = reg_map[lines[i][4]];
            
        }else if(init_reg.find(lines[i][4]) != init_reg.end()){
           reg1 = "$" + init_reg[lines[i][4]];
        }
        else if(lines[i][4] == "1"){
            reg1 = "$1";
        }
        reg_map.erase(lines[i][4]);
            if(lines[i][3]=="+")printfunc("addq",reg1,reg2);
            else if(lines[i][3]=="-")printfunc("subq",reg1,reg2);
            else if(lines[i][3]=="*")printfunc("imulq",reg1,reg2);
            else if(lines[i][3]=="/"|| lines[i][3]=="%"){
                printfunc("movq",reg1,"rax");//doubt
            }else if(lines[i][3]=="&")printfunc("andq",reg1,reg2);
            else if(lines[i][3]=="|")printfunc("orq",reg1,reg2);
            else if(lines[i][3]=="^")printfunc("xorq",reg1,reg2);
            
            cout<<"exit 5"<<endl;

    }
    
cout<<"i:"<<i<<endl; 
}
}
}
//sub13 ,rbp

// rbp local varibles 
// parameters rsi rdi rax rbx rcx rdx r8 r9... r15