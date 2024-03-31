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
    vector<SYMTAB*> childs;
    SYMTAB* parent;

    // Constructor
    SYMTAB() {
        SYMSCOPE = 0;
        parent = nullptr;
    }

    void PrintSYMTAB() {
        printf("SYMBOL TABLE\n");
        printf("%d\n", SYMSCOPE);
        cout<< SYMVAL.size() << endl;
    for (auto it = SYMVAL.begin(); it != SYMVAL.end(); ++it) {
        cout << it->first << "," << it->second.identity << "," << SYMSCOPE << endl;
    }
    for (auto& ti : childs) {
        ti->PrintSYMTAB();
    }
}

};







