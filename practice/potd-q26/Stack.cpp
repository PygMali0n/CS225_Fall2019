#include "Stack.h"

// `int size()` - returns the number of elements in the stack (0 if empty)
int Stack::size() const {
  return s.size();
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
  return s.empty();
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
  s.push(value);
}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
  int a = s.top();
  s.pop();
  return a;
}
