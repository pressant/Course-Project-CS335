#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include "symtab.cpp"

struct Node {
  
  int count;
  SYMTAB* mytab;
  vector<Param*> p_f;
  std::string label;
  std::string category;
  std::vector<Node*> children;
  std::string type;
  int line_number;
  vector<string> parameters;
  string temp_var;
  string temp_op;
  int i_number;
  vector<int>true_list;
    vector<int>false_list;
    vector<int>next_list;
    vector<int>end_list;
    vector<int>dimension;
};

// void print_node(Node *n, std::string, int);
void printNode(std::ostream& out, Node* node);

void printDot(Node* root, const std::string& filename);
Node *create_node(std::string label);
Node *create_node(std::string label, std::string val);
void simplify(Node* node);