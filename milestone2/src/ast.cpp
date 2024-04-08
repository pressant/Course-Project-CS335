#ifndef ast
#define ast

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include "ast.h"

// create node from statement, assign it a label
Node *create_node(std::string label)
{

  Node *result = new Node;
  result->label = label;
  result->count=0;
  result->category = "";
  return result;
}
std::string escapeQuotes(const std::string& input) {
    std::string escapedString;
    for (char c : input) {
        if (c == '"') {
            escapedString += "\\\"";
        } else if (c == '\'') {
            escapedString += "\\\'";
        } else {
            escapedString += c;
        }
    }
    return escapedString;
}


void printNode(std::ostream& out, Node* node) {
    if(node->category=="STRING"){
      std::string escapedLabel = escapeQuotes(node->label);
      out << '"' << node << "\" [label=\""<<node->category <<"\n" << escapedLabel << "\"];\n";
    }
    else if(node->category != "")
        out << '"' << node << "\" [label=\""<<node->category <<"\n" << node->label << "\"];\n";
    else
        out << '"' << node << "\" [label=\"" << node->label << "\"];\n";
    for (auto child : node->children) {
        out << '"' << node << "\" -> \"" << child << "\";\n";
        printNode(out, child);
    }
}

void printDot(Node* root, const std::string& filename) {
    std::ofstream file(filename);
    file << "digraph parse_tree {\n";
    printNode(file, root);
    file << "}\n";
    file.close();
}

void simplify(Node* node) {
    if (node->children.size() == 1) {
        Node* child = node->children[0];
        node->label = child->label;
        node->category = child->category;
        node->children = child->children;
        delete child;
    }
    for (auto child : node->children) {
        simplify(child);
    }
}

#endif