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
  string temp_var;
  vector<string> parameters;
  int i_number;
};

// void print_node(Node *n, std::string, int);
void printNode(std::ostream& out, Node* node);

void printDot(Node* root, const std::string& filename);
Node *create_node(std::string label);
Node *create_node(std::string label, std::string val);
void simplify(Node* node);