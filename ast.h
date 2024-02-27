#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
struct Node {
  string val;
  string label;
  string category;
  vector<Node*> children;
};

void print_node(Node *n, string, int);
Node *create_node(string label);
Node *create_node(string label, string val);