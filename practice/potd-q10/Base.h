#pragma once

#include <string>
using std::string;

class Base {
  public:
    string foo();
    virtual string bar();
    virtual ~Base();
};
