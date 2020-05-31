#include "TreeNode.h"
#include <iostream>

void removeTreenode(TreeNode*& node, int key) {
  if (node == NULL) {
    return;
  }
  if (node->val_ == key) {
    if (node->left_ == NULL && node->right_ == NULL) {
      node = NULL;
      return;
    }
    if (node->left_ != NULL && node->right_ != NULL) {
      TreeNode*prev = nullptr;
      TreeNode*tmp = node->right_;
      while (tmp->left_ != NULL) {
        prev = tmp;
        tmp = tmp->left_;
      }
      if (prev != NULL) {
        prev->left_ = NULL;
      }
      if (tmp == node->right_) {
        tmp->left_ = node->left_;
        node = tmp;
        return;
      }
      tmp->left_ = node->left_;
      tmp->right_ = node->right_;
      node = tmp;
      return;
    }
    if (node->left_ != NULL) {
      node = node->left_;
      return;
    }
    if (node->right_ != NULL) {
      node = node->right_;
      return;
    }
  } else {
    removeTreenode(node->left_, key);
    removeTreenode(node->right_, key);
  }
}


TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
  removeTreenode(root, key);
  return root;
}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
