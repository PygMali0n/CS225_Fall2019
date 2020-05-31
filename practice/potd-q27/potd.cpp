// Your code here
#include <vector>
#include "potd.h"

string getFortune(const string &s) {
  std::vector<string> v;
  v.push_back("asd");
  v.push_back("sew");
  v.push_back("dfe");
  v.push_back("sefs");
  v.push_back("sdgs");
  return v[s.length()-1];
}
