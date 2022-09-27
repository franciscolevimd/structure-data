#include "expresion_tree.h"
#include "node.h"
#include "utils.h"

#include <iostream>
#include <sstream>

using namespace std;

std::istream& operator>>(std::istream& in, ExpresionTree& tree) {
  tree.root_ = ExpresionTree::read_expression(in);
  return in;
}

ExpresionTree::ExpresionTree(Node* root) : BinaryTree(root) {}

ExpresionTree::~ExpresionTree() {
  expression_->clear();
  if (root_ != nullptr) {
    clean(root_);
    cout << "delete root: " << root_->data << endl;
    delete root_;
  }
}

Node* ExpresionTree::read_expression(istream& in) {
  char data;
  string next_line;  
  stack<char> operators_stack = stack<char>();
  stack<Node*> nodes_stack = stack<Node*>();
  getline(in, next_line);
  istringstream in_stream(next_line);
  for (int i = 0; i < next_line.size(); i++) {
    in_stream >> data;
    if (is_operator(data)) {
      ExpresionTree::build_tree(data, operators_stack, nodes_stack);
    } else {
      nodes_stack.push(new Node(data));
    }
  }
  while (operators_stack.size() > 0) {
    ExpresionTree::build_tree(operators_stack, nodes_stack);
  }
  if (nodes_stack.size() == 1) {
    return nodes_stack.top();
  }
  ExpresionTree::clean_nodes_stack(nodes_stack);
  return nullptr;
}

void ExpresionTree::build_tree(stack<char>& operators_stack,
                               stack<Node*>& nodes_stack) {
  Node* node_left = nullptr;
  Node* node_right = nullptr;
  if (nodes_stack.size() > 1) {
    node_right = nodes_stack.top();
    nodes_stack.pop();
    node_left = nodes_stack.top();
    nodes_stack.pop();
    nodes_stack.push(new Node(operators_stack.top(), node_left, node_right));
    operators_stack.pop();
  } else {
    ExpresionTree::clean_operators_stack(operators_stack);
  }
}

void ExpresionTree::build_tree(char& data, std::stack<char>& operators_stack,
                               std::stack<Node*>& nodes_stack) {
  cout << data;
  if (operators_stack.size() > 0) {
    if (is_greater_than(operators_stack.top(), data)) {
      cout << " is less than " << operators_stack.top() << endl;
      ExpresionTree::build_tree(operators_stack, nodes_stack);
      operators_stack.push(data);
      ExpresionTree::build_tree(operators_stack, nodes_stack);
      return;
    }
  }
  operators_stack.push(data);
  cout << endl;
}

void ExpresionTree::clean_operators_stack(stack<char>& operators_stack) {
  while (operators_stack.size() > 0) {
    cout << "pop: " << operators_stack.top() << " ";
    operators_stack.pop();
  }
  cout << endl;
}

void ExpresionTree::clean_nodes_stack(std::stack<Node*>& nodes_stack) {
  while (nodes_stack.size() > 0) {
    cout << "pop: " << nodes_stack.top()->data << " ";
    nodes_stack.pop();
  }
  cout << endl;
}
