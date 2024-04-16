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

#define NORMIE 0
#define ARRAY 1
#define FUNC 2
#define CLS 3

struct Value {
    string val;
};

struct Param {
    string par_type;
    string par_name;
    Value par_val;
};

struct MAPVAL {

    int identity;
    int scope;
    int line_no;
    string type;
    string name;
    int size;
    string temp_var;
    // register stuff
    int g_index;
    int reg_name;

    // id
    Value val;

    // array stuff
    vector<Value*> vals;

    // function arguments
    vector<Param*> params;

};

class SYMTAB {
public:
    unordered_map<string, MAPVAL> SYMVAL;
    int SYMSCOPE;
    // vector<SYMTAB*> childs;
    unordered_map<string,SYMTAB*> childs;
    SYMTAB* parent;
    int tab_type;

    // Constructor
    SYMTAB() {
        SYMSCOPE = 0;
        parent = nullptr;
    }
    SYMTAB* findmytab(string target, SYMTAB* tab) {
        SYMTAB* temp = tab;
        if(!temp || (temp->SYMVAL.find(target) != temp->SYMVAL.end())){
            return temp;
        }
           for(auto&it:temp->childs){
            SYMTAB* s=findmytab(target,it.second);
            if(s) return s;
           }
           return NULL;
        }
    void PrintSYMTAB() {
        printf("SYMBOL TABLE\n");
        printf("Scope : %d\n", SYMSCOPE);
        if(parent!=nullptr) cout<<"scope of parent"<<parent->SYMSCOPE;
        cout<< "Entries in table :"<<SYMVAL.size() << endl;
    for (auto it = SYMVAL.begin(); it != SYMVAL.end(); ++it) {
        cout << "Label : "<<it->first << ", Type :"<<it->second.type <<endl;
        if(it->second.identity == FUNC)
        {
            // cout<<"Parameters"<<endl;
            for(int i = 0; i< it->second.params.size();i++)
            {
                cout<< it->second.params[i]->par_type<<" "<<it->second.params[i]->par_name<<endl;
            }
        }

    }
    cout<<endl;
    for (auto& ti : childs) {
        cout<< ti.first<<" ";
        ti.second->PrintSYMTAB();
    }
}
     void WriteSYMTABToCSV(ofstream& file, SYMTAB* symtab) {
    if(symtab->parent!=nullptr) file<<"Parent's SCOPE "<<symtab->parent->SYMSCOPE<<endl;
    else file<<"Global SCOPE"<<endl;
    file<<"My SCOPE = "<<symtab->SYMSCOPE<<endl;
    
    file << "Name,identity,scope,Line Number,Type,Size\n";

    for (const auto& entry : symtab->SYMVAL) {
        int x=entry.second.identity==FUNC;
        file << entry.first << "," << x << "," << symtab->SYMSCOPE << "," << entry.second.line_no << "," << entry.second.type << "," << entry.second.size<<endl;
    }
    file<<endl;
    for (const auto& child : symtab->childs) {
        file<< child.first <<" Table : ";
        WriteSYMTABToCSV(file, child.second);
    }
    }

    void WriteAllSYMTABsToCSV(const string& filename, SYMTAB* rootSymtab) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    WriteSYMTABToCSV(file, rootSymtab);

    file.close();
    }

};








