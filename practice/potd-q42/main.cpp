#include <iostream>
#include "potd.cpp"

using namespace std;

int main() {
    unordered_map<string, int> mapA({
                                    {"common", 13},
                                    {"unique_a", 13}
                                    });
    unordered_map<string, int> mapB({
                                    {"common", 17},
                                    {"unique_b", 17}
                                    });

    unordered_map<string, int> common = common_elems(mapA, mapB);

    // check your outputs here
    for (auto pair : common) {
      std::cout << pair.first << ":" << pair.second << std::endl;
    }
    for (auto pair : mapA) {
      std::cout << pair.first << ":" << pair.second << std::endl;
    }
    for (auto pair : mapB) {
      std::cout << pair.first << ":" << pair.second << std::endl;
    }
}
