#include "potd.h"

// Your code here!
double sum(vector<double>::iterator start, vector<double>::iterator end) {
  double summ = 0.0;
  for (auto ptr = start; ptr < end; ptr++) {
    summ += *ptr;
  }
  return summ;
}

vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end) {
  vector<double>::iterator max = start;
  for (auto ptr = start; ptr < end; ptr++) {
    if (*ptr > *max) {
      max = ptr;
    }
  }
  return max;
}

void sort_vector(vector<double>::iterator start, vector<double>::iterator end) {
  vector<double>::iterator iter = start;
  vector<double>::iterator max;
  while (iter < end) {
    max = max_iter(iter, end);
    double tmp = *iter;
    *iter = *max;
    *max = tmp;
    iter++;
  }
}
