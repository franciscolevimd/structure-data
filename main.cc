#include <cmath>
#include <iostream>
#include <string>

#include "expresion_tree.h"
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
  ExpresionTree *tree = new ExpresionTree();
  cout << "Ingrese una expresión: ";
  tree->set_trasversal_type(kPostOrder);
  cin >> *tree;
  cout << "Expresión postorden: " << *tree << endl;
  delete tree;
}
