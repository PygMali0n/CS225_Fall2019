// Pet.h
#include <string>
#include "Animal.h"

using std::string;

class Pet : public Animal {
  public:
    Pet();
    Pet(string type, string food, string name, string ownername);

    void setType(string type);
    void setFood(string food);
    void setName(string name);
    void setOwnerName(string ownername);
    string getType();
    string getFood();
    string getName();
    string getOwnerName();
    string print();
  private:
    string type_;
    string food_;
    string name_;
    string owner_name_;
};
