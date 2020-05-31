#pragma once
#include <vector>
#include <iostream>
#include <cstddef>
#include <algorithm>
using namespace std;
class Exam {
public:
  Exam(vector<int> elems_) : elems(elems_), elemCount(0) {};
  void heapifyUp(size_t currentIdx);
  void buildHeap();
  void heapifyDown(size_t currentIdx);
  vector<int> returnN(int n);
  void unionBySize(int a, int b);
  int find(int currentIdx);
  void insertLP(int toInsert);
  void insertDH(int toInsert);
  void removeLP(int toRemove);
  void removeDH(int toRemove);
  vector<int> elems;
  int elemCount;
};
  const size_t primes[]
      = {17ul,         23ul, 29ul,         37ul,        53ul,        67ul,
         79ul,         97ul,         131ul,       193ul,       257ul,
         389ul,        521ul,        769ul,       1031ul,      1543ul,
         2053ul,       3079ul,       6151ul,      12289ul,     24593ul,
         49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
         1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
         50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
         1610612741ul, 3221225473ul, 4294967291ul};

  size_t findPrime(size_t num)
  {
      size_t len = sizeof(primes) / sizeof(size_t);
      const size_t* first = primes;
      const size_t* last = primes + len;
      const size_t* prime = upper_bound(first, last, num);
      if (prime == last)
          --prime;
      return *prime;
  }
