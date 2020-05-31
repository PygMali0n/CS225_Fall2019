// Your code here
#include <string>
#include "Food.h"
using std::string;

Food::Food() {
  name_ = "name";
  quantity_ = 0;
}

void Food::set_name(string name) {
  name_ = name;
}

string Food::get_name() {
  return name_;
}

void Food::set_quantity(int quantity) {
  quantity_ = quantity;
}

int Food::get_quantity() {
  return quantity_;
}
