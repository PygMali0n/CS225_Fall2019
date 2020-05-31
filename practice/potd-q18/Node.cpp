#include "Node.h"

void mergeList(Node *first, Node *second) {
  // your code here!
  if (first == NULL || second == NULL) {
    return;
  }
  if (first->next_ == NULL && second->next_ != NULL) {
    first->next_ = second;
    return;
  }
  if (first->next_ != NULL && second->next_ == NULL) {
    Node* tmp = first->next_;
    first->next_ = second;
    second->next_ = tmp;
    return;
  }
  if (first->next_ == NULL && second->next_ == NULL) {
    first->next_ = second;
    return;
  }
  Node *temp1 = first->next_;
  Node *temp2 = second->next_;
  first->next_ = second;
  second->next_ = temp1;
  mergeList(second->next_, temp2);
}

Node::Node() {
    numNodes++;
}

Node::Node(const Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
