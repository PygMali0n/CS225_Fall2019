#include <unordered_map>

using namespace std;

unordered_map<string, int> common_elems(unordered_map<string, int> &mapA,
                                        unordered_map<string, int> &mapB) {

    // your code here
    unordered_map<string, int> toreturn = unordered_map<string, int>();
    for (auto it = mapA.begin(); it != mapA.end(); ++it) {
      auto so = mapB.find(it->first);
      if (so != mapB.end()) {
        toreturn.insert({it->first, it->second+so->second});
      }
    }

    for (auto it = toreturn.begin(); it != toreturn.end(); ++it) {
      auto a = mapA.find(it->first);
      auto b = mapB.find(it->first);
      if (a != mapA.end()) {
        mapA.erase(it->first);
      }
      if (b != mapB.end()) {
        mapB.erase(it->first);
      }
    }

    return toreturn;
}
