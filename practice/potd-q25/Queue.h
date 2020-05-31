#pragma once

#include <cstddef>
#include <vector>
class Queue {
    public:
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
        ~Queue();
        Queue();
    private:
      std::vector<int> v;
};
