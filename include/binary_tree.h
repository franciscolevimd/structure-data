#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <istream>
#include <string>

#include "node.h"

enum TraversalType {
  kInOrder = 0,
  kPostOrder,
  kPreOrder,
};

class BinaryTree {
  friend std::ostream& operator<<(std::ostream& os, const BinaryTree& tree);

 public:
  BinaryTree(Node* root = nullptr);
  virtual ~BinaryTree();
  void set_trasversal_type(TraversalType trasversal_type);

 protected:
  void inorder_traversal(Node* node) const;
  void preorder_traversal(Node *node) const;
  std::string* expression_;  
  TraversalType trasversal_type_;
  Node* root_;
};
#endif  // BINARY_TREE_H_