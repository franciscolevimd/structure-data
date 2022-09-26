#include "expresion_tree.h"

#include <iostream>
#include <stack>

using namespace std;

std::istream& operator>>(std::istream& in, ExpresionTree& tree) {
  tree.root_ = ExpresionTree::read_expression(in);
  return in;
}

ExpresionTree::ExpresionTree(Node* root) : BinaryTree(root) {}

ExpresionTree::~ExpresionTree() {
  expression_->clear();
  clean(root_);
}

void ExpresionTree::clean(Node* node) {
  if (node == nullptr) {
    return;
  }
  clean(node->left);
  clean(node->right);
  if (node->left != nullptr) {
    cout << "delete left: " << node->data << endl;
    delete node->left;
  }
  if (node->right != nullptr) {
    cout << "delete right: " << node->data << endl;
    delete node->right;
  }
}

Node* ExpresionTree::read_expression(std::istream& in) {
  string next_line;
  getline(in, next_line);
  return ExpresionTree::read_expression(next_line);
}

Node* ExpresionTree::read_expression(std::string& expression) {
  stack<Node*> tree_stack = stack<Node*>();
  return tree_stack.size() > 0 ? tree_stack.top() : nullptr;
}









// #####





// #include "tree.h"

// #include <sstream>
// #include <stack>
// #include <string>

// #include "node.h"
// #include "utils.h"

// using namespace std;

// std::istream& operator>>(std::istream& in, Tree& tree) {
//   //tree = Tree::read_expression(in);
//   return in;
// }

// Tree::Tree(Node* root) : root_(root) {}

// Tree::~Tree() {}

// Tree& Tree::operator=(const Tree& other) {
//   if (this != &other) {
//     this->root_ = other.root_;
//   }
//   return *this;
// }

// /*Tree Tree::read_expression(std::istream& in) {
//   string next_line;
//   getline(in, next_line);
//   //stack<Tree> tree_stack = Tree::read_expression(next_line);
//   return tree_stack.size() > 0 ? tree_stack.top() : Tree();
// }*/
// /*
// stack<Tree> Tree::read_expression(std::string& expression) {
//   char data;
//   stack<Tree> result;
//   stack<char> operators_stack;
//   istringstream in_stream(expression);
//   for (int i = 0; i < expression.size(); i++) {
//     in_stream >> data;
//     if (is_operator(data)) {
//       operators_stack.push(data);
//     } else {
//       Node node(data);
//       result.push(Tree(&node));
//     }
//   }
//   while(operators_stack.size() > 0) {
//     //
//   }
// }
// */








// #ifndef BINARY_TREE_H_
// #define BINARY_TREE_H_

// #include "node.h"

// #include <istream>
// #include <string>

// class BinaryTree {
//   friend std::istream& operator>>(std::istream& in, BinaryTree& tree);

//  public:
//   BinaryTree(Node *root = nullptr);
//   virtual ~BinaryTree();  
//   inline Node& root() const { return *root_; }

//  private:
//   //static Tree read_expression(std::istream& in);
//   //static stack<Tree> read_expression(std::string& expression);
//   Node* root_;
// };
// #endif // BINARY_TREE_H_





// friend std::ostream& operator<<(std::ostream& os, const BinaryTree& tree);
//   friend std::istream& operator>>(std::istream& in, BinaryTree& tree);