#include "TreeNode.h"

// Your function here
void helper(TreeNode* node, int max, int number) {
  if (max == number) {
    return;
  }
  node->left_ = new TreeNode(++number, nullptr, nullptr);
  if (max == number) {
    return;
  }
  node->right_ = new TreeNode(++number, nullptr, nullptr);
  helper(node->right_, max, number);
}

TreeNode *makeFullRight(int n) {
  if (n <= 0) {
    return NULL;
  }
  TreeNode* root = new TreeNode(1, nullptr, nullptr);
  helper(root, n, 1);
  return root;
}

// Methods and functions we provide following.
// You should not need to edit this code.

TreeNode::TreeNode(int data, TreeNode *left, TreeNode *right) :
    data_(data), left_(left), right_(right) {}

TreeNode::~TreeNode() {
    if (left_ != NULL)
        delete left_;
    if (right_ != NULL)
        delete right_;
}

bool equal(TreeNode *n1, TreeNode *n2) {
    if (n1 == NULL)
        return n2 == NULL;

    if (n2==NULL)
        return false;

    return (n1->getData() == n2->getData() &&
            equal(n1->getLeft(),n2->getLeft()) &&
            equal(n1->getRight(),n2->getRight()));
}

int TreeNode::getData() const {
    return data_;
}

TreeNode *TreeNode::getLeft() const {
    return left_;
}

TreeNode *TreeNode::getRight() const {
    return right_;
}
