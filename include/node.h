#ifndef NODE_H_
#define NODE_H_

#include <cstddef>

struct Node {
  Node(char data, Node *left = nullptr, Node *right = nullptr);
  virtual ~Node();
  char data;
  Node *left;
  Node *right;
};

#endif  // NODE_H_