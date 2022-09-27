#ifndef EXPRESION_TREE_H_
#define EXPRESION_TREE_H_

#include <stack>

#include "binary_tree.h"
#include "node.h"

class ExpresionTree : public BinaryTree {
  friend std::istream& operator>>(std::istream& in, ExpresionTree& tree);

 public:
  ExpresionTree(Node* root = nullptr);
  virtual ~ExpresionTree();

 private:
  static Node* read_expression(std::istream& in);
  static void build_tree(std::stack<char>& operators_stack,
                         std::stack<Node*>& nodes_stack);
  static void build_tree(char& data, std::stack<char>& operators_stack,
                         std::stack<Node*>& nodes_stack);
  static void clean_operators_stack(std::stack<char>& operators_stack);
  static void clean_nodes_stack(std::stack<Node*>& nodes_stack);
};

#endif  // EXPRESION_TREE_H_