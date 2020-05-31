#include <string>
#include "Base.h"

using std::string;

class Derived : public Base {
  public:
    string foo();
    string bar();
    virtual ~Derived();
};
