#include <cmath>
#include <iostream>
#include <string>

#include "binary_tree.h"
#include "node.h"
#include "utils.h"

using namespace std;

int evaluate(char operator_v, int value_l, int value_r) {
  switch (operator_v) {
    case '^':
      return pow(value_l, value_r);
    case '*':
      return value_l * value_r;
    case '/':
      return value_l / value_r;
    case '+':
      return value_l + value_r;
    case '-':
      return value_l - value_r;
  }
  return 0;
}

int evaluate(Node *node) {
  int value_l;
  int value_r;
  int result = 0;
  if (node->left == nullptr) {
    return is_operator(node->data) ? node->data : node->data - '0';
  }
  value_l = evaluate(node->left);
  value_r = evaluate(node->right);
  if (is_operator(node->data)) {
    return evaluate(node->data, value_l, value_r);
  }
  return is_operator(node->data) ? node->data : node->data - '0';
}

int main(int, char **) {
  Node *root = new Node('+');
  root->left = new Node('+');
  root->left->left = new Node('3');
  root->left->right = new Node('^');
  root->left->right->left = new Node('8');
  root->left->right->right = new Node('4');
  root->right = new Node('/');
  root->right->left = new Node('5');
  root->right->right = new Node('5');

  BinaryTree *tree = new BinaryTree(root);
  cout << "In order tree: " << *tree << endl;
  tree->set_trasversal_type(kPostOrder);
  cout << "Post order tree: " << *tree << endl;

  delete tree;
  delete root->left->right->left;
  delete root->left->right->right;
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;
}
