#include "binary_tree.h"

using namespace std;

BinaryTree::BinaryTree(Node* root)
    : root_(root), trasversal_type_(kInOrder), expression_(new string("")) {}

BinaryTree::~BinaryTree() {
  delete expression_;
  root_ = nullptr;
}

void BinaryTree::set_trasversal_type(TraversalType trasversal_type) {
  trasversal_type_ = trasversal_type;
}

void BinaryTree::inorder_traversal(Node* node) const {
  if (node->left == nullptr) {
    expression_->push_back(node->data);
    return;
  }
  inorder_traversal(node->left);
  expression_->push_back(node->data);
  inorder_traversal(node->right);
}

void BinaryTree::preorder_traversal(Node* node) const {
  if (node->left == nullptr) {
    expression_->push_back(node->data);
    return;
  }
  preorder_traversal(node->left);
  preorder_traversal(node->right);
  expression_->push_back(node->data);
}

std::ostream& operator<<(std::ostream& os, const BinaryTree& tree) {
  tree.expression_->clear();
  if (tree.trasversal_type_ == kInOrder) {
    tree.inorder_traversal(tree.root_);
  } else if (tree.trasversal_type_ == kPostOrder) {
    tree.preorder_traversal(tree.root_);
  }
  os << *tree.expression_;
  return os;
}
