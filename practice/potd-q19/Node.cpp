#include "Node.h"

/** Create a new node and add it to the list, while keeping the list sorted.
*/
Node *insertSorted(Node *first, int data) {
    // your code here
    Node *newnode = new Node;
    newnode->data_ = data;
    newnode->next_ = NULL;
    if (first == NULL) {
      newnode->next_ = first;
      first = newnode;
      return first;
      delete newnode;
    }
    if (first->data_ == data) {
      return first;
      delete newnode;
    }
    if (first->data_ > data) {
      newnode->next_ = first;
      first = newnode;
      return first;
      delete newnode;
    } else {
      Node *current = first;
      while (current->next_ != NULL) {
        if (current->data_ == data) {
          return first;
          delete newnode;
        }
        if (current->next_->data_ > data) {
          newnode->next_ = current->next_;
          current->next_ = newnode;
          return first;
          delete newnode;
        }
        current = current->next_;
      }
      if (current->data_ == data) {
        return first;
        delete newnode;
      }
      current->next_ = newnode;
    }
    return first;

    delete newnode;
}

/** Creates a new list (containing new nodes, allocated on the heap)
	that contains the set union of the values in both lists.
*/
Node *listUnion(Node *first, Node *second) {
    Node *out = NULL;

    while (first != NULL) {
        // your code here
        // hint: call insertSorted and update l1
        out = insertSorted(out, first->data_);
        first = first->next_;
    }

    while (second != NULL) {
        // your code here
        out = insertSorted(out, second->data_);
        second = second->next_;
      }
    return out;
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
