#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
  if (input.size() == 0) {
    return true;
  }
  stack<char> s;
  for (unsigned i = 0; i < input.size(); i++) {
    char x = input[i];
    if (x == '[' || x == '{' || x == '(') {
      s.push(x);
    }

    if (x == ']') {
      if (s.empty()) {
        return false;
      }
      char y = s.top();
      if (y == '{' || y == '(') {
        return false;
      }
      s.pop();
    }
    if (x == '}') {
      if (s.empty()) {
        return false;
      }
      char y = s.top();
      if (y == '[' || y == '(') {
        return false;
      }
      s.pop();
    }
    if (x == ')') {
      if (s.empty()) {
        return false;
      }
      char y = s.top();
      if (y == '{' || y == '[') {
        return false;
      }
      s.pop();
    }
  }
  return (s.empty());
}
