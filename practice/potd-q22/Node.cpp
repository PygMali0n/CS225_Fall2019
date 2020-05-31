#include "Node.h"

using namespace std;

Node *listIntersection(Node *first, Node *second) {
  // your code here
  if (first == NULL || second == NULL) {
    return NULL;
  }
  Node * newlist = NULL;
  Node * tail;
  for (Node * tmp1 = first; tmp1 != NULL; tmp1 = tmp1->next_) {
    for (Node * tmp2 = second; tmp2 != NULL; tmp2 = tmp2->next_) {
      if (tmp1->data_ == tmp2->data_) {
        if (newlist == NULL) {
          newlist = new Node();
          newlist->data_ = tmp1->data_;
          newlist->next_ = NULL;
          tail = newlist;
        }
        for (Node * tmp3 = newlist; tmp3 != NULL; tmp3 = tmp3->next_) {
          if (tmp3->data_ == tmp1->data_) {
            break;
          }
          if (tmp3->next_ == NULL) {
            tail->next_ = new Node();
            tail = tail->next_;
            tail->next_ = NULL;
            tail->data_ = tmp1->data_;
          }
        }
      }
    }
  }
  return newlist;
}


Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
