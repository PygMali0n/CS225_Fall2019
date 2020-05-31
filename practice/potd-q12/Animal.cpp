// Animal.cpp
#include <string>
#include "Animal.h"

using std::string;

Animal::Animal() {
  type_ = "cat";
  food_ = "fish";
}
Animal::Animal(string type, string food) {
  type_ = type;
  food_ = food;
}
void Animal::setType(string type) {
  type_ = type;
}
void Animal::setFood(string food) {
  food_ = food;
}
string Animal::getType() {
  return type_;
}
string Animal::getFood() {
  return food_;
}
string Animal::print() {
  return "I am a " + getType() + ".";
}
