/* Your code here! */
#include <string>
using namespace std;

string age = "20";
string name = "zixuan";
std::string hello() {
  return std::string("Hello world! My name is ") + name + " and I am " + age + " years old.";
}
