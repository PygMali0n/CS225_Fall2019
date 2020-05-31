#include "Base.h"
#include <string>

using std::string;

string Base::foo() {
  return "Sam I Am";
}

string Base::bar() {
  return "Green Eggs";
}

Base::~Base() { }
