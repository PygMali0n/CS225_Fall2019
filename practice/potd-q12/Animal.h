// Animal.h
#include <string>

using std::string;

class Animal {
  public:
    Animal();
    Animal(string type, string food);
    void setType(string);
    virtual void setFood(string);
    string getType();
    virtual string getFood();
    virtual string print();
  private:
    string type_;
    string food_;
};
