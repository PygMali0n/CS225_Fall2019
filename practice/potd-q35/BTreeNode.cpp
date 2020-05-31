#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
  if (root == NULL) {
    return NULL;
  }
  for (unsigned i = 0; i < root->elements_.size(); i++) {
    if (root->elements_[i] == key) {
      return root;
    }
  }
  if (root->children_.size() == 0) {
    return NULL;
  }
  for (unsigned j = 0; j < root->children_.size(); j++) {
    if (find(root->children_[j], key) != NULL) {
      return find(root->children_[j], key);
    }
  }
  return NULL;
}
