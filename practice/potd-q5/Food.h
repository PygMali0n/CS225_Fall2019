// Your code here
#pragma once

#include <string>
using std::string;

class Food {
  private:
    string name_;
    int quantity_;
  public:
    Food();
    void set_name(string name);
    string get_name();
    void set_quantity(int quantity);
    int get_quantity();
};
