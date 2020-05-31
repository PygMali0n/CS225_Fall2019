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

TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
  if (root == NULL) {
    return NULL;
  }
  TreeNode* left = findLastUnbalanced(root->left_);
  TreeNode* right = findLastUnbalanced(root->right_);
  if (left == NULL && right == NULL) {
    if (fabs(getHeight(root->left_) - getHeight(root->right_)) > 1) {
      return root;
    } else {
      return NULL;
    }
  }
  if (left == NULL && right != NULL) {
    return right;
  }
  if (left != NULL && right == NULL) {
    return left;
  }
  if (getHeight(left) > getHeight(right)) {
    return left;
  } else {
    return right;
  }
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
