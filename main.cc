#include <iostream>

#include "expresion_tree.h"

using namespace std;

int main(int, char **) {
  ExpresionTree *tree = new ExpresionTree();
  cout << "Ingrese una expresión: ";
  tree->set_trasversal_type(kPostOrder);
  cin >> *tree;
  cout << "Expresión postorden: " << *tree << endl;
  cout << "Expresión evaluada: " << tree->evaluate() << endl;
  delete tree;
}
