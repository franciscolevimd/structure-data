#include "node.h"

#include <iostream>

using namespace std;

Node::~Node() {
  left = nullptr;
  right = nullptr;
}

void clean(Node *node) {
  if (node == nullptr) {
    return;
  }
  clean(node->left);
  clean(node->right);
  if (node->left != nullptr) {
    cout << "delete left: " << node->left->data << endl;
    delete node->left;
  }
  if (node->right != nullptr) {
    cout << "delete right: " << node->right->data << endl;
    delete node->right;
  }
}

Node::Node(char data, Node *left, Node *right)
    : data(data), left(left), right(right) {}
