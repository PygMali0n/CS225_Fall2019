#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {
    // your code here!
    if (head == NULL) {
      return "Empty list";
    }
    Node *current = head;
    string msg = "Node 0: " + to_string(current->data_);
    for (int i = 1;; i++) {
      if (current->next_ == NULL) {
        return msg;
      }
      current = current->next_;
      msg += " -> Node " + to_string(i) + ": " + to_string(current->data_);
    }
}
