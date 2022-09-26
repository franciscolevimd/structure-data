#include "node.h"

Node::~Node() {
  left = nullptr;
  right = nullptr;
}

Node::Node(char data, Node *left, Node *right)
    : data(data), left(left), right(right) {}
