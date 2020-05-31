// your code here!
#include <array>
#include <cmath>
#include "potd.h"
using namespace std;
using namespace potd;

int * potd::raise(int *arr) {
  int *newarr = new int[5];
  for (unsigned int i = 0;; i++) {
    if (arr[i] < 0) {
      newarr[i] = arr[i];
      break;
    } else if (arr[i + 1] < 0) {
      newarr[i] = arr[i];
    } else {
      newarr[i] = pow(arr[i], arr[i + 1]);
    }
  }
  return newarr;
}
