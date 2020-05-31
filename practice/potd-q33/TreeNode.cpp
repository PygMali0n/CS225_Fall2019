#include "TreeNode.h"
#include <algorithm>


void rightRotate(TreeNode* root) {

    // Your code here
    TreeNode* parent = root->parent_;
    TreeNode* pivot = root->left_;
    TreeNode* child = pivot->right_;
    root->left_ = child;
    if (child != NULL) {
      child->parent_ = root;
    }
    pivot->right_ = root;
    root->parent_ = pivot;
    pivot->parent_ = parent;
}


void leftRotate(TreeNode* root) {

    // your code here
    TreeNode* parent = root->parent_;
    TreeNode* pivot = root->right_;
    TreeNode* child = pivot->left_;
    root->right_ = child;
    if (child != NULL) {
      child->parent_ = root;
    }
    pivot->left_ = root;
    root->parent_ = pivot;
    pivot->parent_ = parent;
}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
