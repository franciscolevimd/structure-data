#ifndef EXPRESION_TREE_H_
#define EXPRESION_TREE_H_

#include "binary_tree.h"
#include "node.h"

class ExpresionTree : public BinaryTree {
  friend std::istream& operator>>(std::istream& in, ExpresionTree& tree);

 public:
  ExpresionTree(Node* root = nullptr);
  virtual ~ExpresionTree();
  void clean(Node* node);

 private:
  static Node* read_expression(std::istream& in);
  static Node*read_expression(std::string& expression);
};

#endif  // EXPRESION_TREE_H_