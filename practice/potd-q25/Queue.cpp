#include "Queue.h"
#include <vector>

Queue::Queue() { }

// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
  return v.size();
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
  return v.empty();
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
  v.push_back(value);
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
  int e = v.front();
  v.erase(v.begin());
  return e;
}

Queue::~Queue() {
  while (!v.empty()) {
    v.pop_back();
  }
}
