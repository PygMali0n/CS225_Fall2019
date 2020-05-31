#include "TreeNode.h"

double getHeight(TreeNode* root) {
  if (root == NULL) {
    return -1;
  }
  if (root->left_== NULL && root->right_ == NULL) {
    return 0;
  }
  if (root->left_ == NULL) {
    return 1 + getHeight(root->right_);
  }
  if (root->right_ == NULL) {
    return 1 + getHeight(root->left_);
  }
  return 1 + fmax(getHeight(root->left_), getHeight(root->right_));
}
bool isHeightBalanced(TreeNode* root) {
  // your code here
  if (root == NULL) {
    return true;
  }
  if (root->left_ == NULL && root->right_ == NULL) {
    return true;
  }
  if (fabs(getHeight(root->left_) - getHeight(root->right_)) > 1) {
    return false;
  }
  return isHeightBalanced(root->left_) && isHeightBalanced(root->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
