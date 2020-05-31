#include <vector>
#include <string>
#include <set>
#include "Hash.h"

using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
   int sum = 0;
   for (const char& c : s) {
     sum+=(int) c;
   }
   return sum % M;
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	// Your Code Here
  std::set<int> s;
  for (auto it = inputs.begin(); it != inputs.end(); ++it) {
    if (s.find(hashFunction(*it, M)) != s.end()) {
      collisions++;
    } else {
      s.insert(hashFunction(*it, M));
    }
  }
	return collisions;
}
