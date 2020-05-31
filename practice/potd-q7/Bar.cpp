// your code here
#include "Bar.h"
#include "Foo.h"

potd::Bar::Bar(string name) {
  f_ = new Foo(name);
}

potd::Bar::Bar(const Bar & other) {
  f_ = new Foo(*other.f_);
}

potd::Bar::~Bar() {
  f_->~Foo();
}

string potd::Bar::get_name() {
  return f_->get_name();
}

potd::Bar & potd::Bar::operator=(const Bar & other) {
  delete this;
  Bar * temp = new Bar(other);
  return *this;
}
