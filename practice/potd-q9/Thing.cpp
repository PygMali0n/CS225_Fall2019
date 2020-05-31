// Your code here!
#include "Thing.h"
using namespace potd;

Thing::Thing(int size) {
  props_ct_ = 0;
  props_max_ = size;
  properties_ = new std::string[size];
  values_ = new std::string[size];
}

Thing::Thing(const Thing & other) {
  props_ct_ = other.props_ct_;
  props_max_ = other.props_max_;
  properties_ = new std::string[props_max_];
  values_ = new std::string[props_max_];
  for (int i = 0; i < props_ct_; i++) {
    properties_[i] = other.properties_[i];
    values_[i] = other.values_[i];
  }
}

Thing::~Thing() {
  _destroy();
}

Thing & Thing::operator=(const Thing & other) {
  if (this == &other) {
    return *this;
  }
  _destroy();
  _copy(other);
  return *this;
}

void Thing::_copy(const Thing & other) {
  props_ct_ = other.props_ct_;
  props_max_ = other.props_max_;
  properties_ = new std::string[props_max_];
  values_ = new std::string[props_max_];
  for (int i = 0; i < props_ct_; i++) {
    properties_[i] = other.properties_[i];
    values_[i] = other.values_[i];
  }
}

void Thing::_destroy() {
  delete[] properties_;
  delete[] values_;
}

int Thing::set_property(std::string name, std::string value) {
  if (props_ct_ == 0 && props_max_ > 0) {
    values_[0] = value;
    properties_[0] = name;
    props_ct_++;
    return 0;
  }
  for (int i = 0; i < props_ct_; i++) {
    if (name.compare(properties_[i]) == 0) {
      values_[i] = value;
      return i;
    }
  }
  if (props_max_ == props_ct_) {
    return -1;
  }
  values_[props_ct_] = value;
  properties_[props_ct_] = name;
  props_ct_++;
  return props_ct_ - 1;
}

std::string Thing::get_property(std::string name) {
  for (int i = 0; i < props_ct_; i++) {
    if (name.compare(properties_[i]) == 0) {
      return values_[i];
    }
  }
  return "";
}
