#include "MinHeap.h"
#include <cmath>

vector<int> lastLevel(MinHeap & heap)
{
        // Your code here
        int logm;
        int m;
        vector<int> v;
        m = heap.elements.size();
        if (m<2) {
          return v;
        }
        if (m==2) {
          v.push_back(heap.elements[1]);
          return v;
        }
        logm = log2(m-1);
        for (int i = pow(2, logm); i < m; i++) {
          v.push_back(heap.elements[i]);
        }
        return v;
}
