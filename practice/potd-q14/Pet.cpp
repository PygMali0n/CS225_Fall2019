// Pet.cpp
#include <string>
#include "Pet.h"

using std::string;

Pet::Pet() {
  type_ = "cat";
  food_ = "fish";
  name_ = "Fluffy";
  owner_name_ = "Cinda";
}

Pet::Pet(string type, string food, string name, string ownername) {
  type_ = type;
  food_ = food;
  name_ = name;
  owner_name_ = ownername;
}

void Pet::setType(string type) {
  type_ = type;
}
void Pet::setFood(string food) {
  food_ = food;
}
void Pet::setName(string name) {
  name_ = name;
}
void Pet::setOwnerName(string ownername) {
  owner_name_ = ownername;
}
string Pet::getType() {
  return type_;
}
string Pet::getFood() {
  return food_;
}
string Pet::getName() {
  return name_;
}
string Pet::getOwnerName() {
  return owner_name_;
}
string Pet::print() {
  return "My name is " + name_;
}
