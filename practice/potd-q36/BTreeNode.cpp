#include <vector>
#include "BTreeNode.h"


std::vector<int> traverse(BTreeNode* root) {
    // your code here
    std::vector<int> v;
    help(root, v);
    return v;
}

void help(BTreeNode* node, std::vector<int> & tra) {
  if (node == NULL) {
    return;
  }
  if (node->is_leaf_) {
    for (auto it = node->elements_.begin(); it != node->elements_.end(); ++it) {
      tra.push_back(*it);
    }
  } else {
    help(node->children_[0], tra);
    if (node->children_.size() == 2) {
      for (unsigned i = 0; i < node->elements_.size(); i++) {
        tra.push_back(node->elements_[i]);
      }
      help(node->children_[1], tra);
    } else if (node->children_.size() > 2) {
      for (unsigned i = 0; i < node->elements_.size()/2; i++) {
        tra.push_back(node->elements_[i]);
      }
      for (unsigned i = 1; i < node->children_.size()-1; i++) {
        help(node->children_[i], tra);
      }
      for (unsigned i = node->elements_.size()/2; i < node->elements_.size(); i++) {
        tra.push_back(node->elements_[i]);
      }
      help(node->children_[node->children_.size()-1], tra);
    }
  }
}
