#include <vector>
#include "potd.h"
#include "functions.h"

std::vector<int> evaluate() {
    std::vector<int> ret(7);
    ret[0] = -1; // change to 0 or 1
    ret[1] = -1; // change to 0 or 1
    ret[2] = -1; // change to 0 or 1
    ret[3] = -1; // change to 0 or 1
    ret[4] = -1; // change to 0 or 1
    ret[5] = -1; // change to 0 or 1
    ret[6] = -1; // change to 0 or 1
    std::string first = "abc1";
    std::string second = "abc";
    std::string third = "ab1";
    std::string four = "ab";
    std::string five = "abcde123";
    if (validUsername(first) == true && validUsername(second) == false &&
    validUsername(third) == false && validUsername(four)==false && validUsername(five) == true) {
      ret[0] = 1;
    } else {
      ret[0] = 0;
    }
    bool arr[15];
    ret[1] = 1;
    for (int i = 0; i < 15; i++) {
      if (arrayIndex(i) != arr[i]) {
        ret[1] = 0;
      }
    }
    if (countPrimes(2) == 1 && countPrimes(4) == 2 && countPrimes(100) == 25 && countPrimes(10) == 4) {
      ret[2] = 1;
    } else {
      ret[2] = 0;
    }
    if (factorial(12) == 479001600 && factorial(0) == 1 && factorial(1) == 1) {
      ret[3] = 1;
    } else {
      ret[3] = 0;
    }
    if (samesies(1, 1) && samesies(0, 5) == false && samesies(-100,-100) && samesies(-50,50) == false) {
      ret[4] = 1;
    } else {
      ret[4] = 0;
    }
    if (absolutely(1) == 1 && absolutely(-100) == 100 && absolutely(0) == 0 && absolutely(50) == 50) {
      ret[5] = 1;
    } else {
      ret[5] = 0;
    }
    if (magnaCalca(0, 1) == 1 && magnaCalca(100,100) == 0 && magnaCalca(50, -50) == 100 && magnaCalca(-100,100) == 200) {
      ret[6] = 1;
    } else {
      ret[6] = 0;
    }
    return ret;
}
