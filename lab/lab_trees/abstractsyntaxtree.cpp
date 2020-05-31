#include "abstractsyntaxtree.h"

/**
 * Calculates the value from an AST (Abstract Syntax Tree). To parse numbers from strings, please use std::stod
 * @return A double representing the calculated value from the expression transformed into an AST
 */
double AbstractSyntaxTree::eval() const {
    // @TODO Your code goes here...
    return evaluating(this->getRoot());
}

double AbstractSyntaxTree::evaluating(typename BinaryTree<std::string>::Node* node) const {
  if (node == NULL) {
    return 0;
  }
  if (node->left == NULL && node->right == NULL) {
    return std::stod(node->elem);
  } else {
    if (node->elem == "+") {
      return evaluating(node->left) + evaluating(node->right);
    }
    if (node->elem == "-") {
      return evaluating(node->left) - evaluating(node->right);
    }
    if (node->elem == "*") {
      return evaluating(node->left) * evaluating(node->right);
    }
    if (node->elem == "/") {
      return evaluating(node->left) / evaluating(node->right);
    }
  }
  return 0;
}
