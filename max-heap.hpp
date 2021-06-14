#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
 private:
  vector<int> heap;
  int heap_size;

  int left(int idx) {
    return 2 * idx + 1;
  }

  int right(int idx) {
    return 2 * idx + 2;
  }

 public:
  MaxHeap() : heap_size(0), heap(vector<int>()) {}

  int size() {
    return heap_size;
  }

  int top() {
    return heap.at(0);
  }

  int pop() {
  }

  int push() {
  }

  void max_heapify(int idx) {
    while (true) {
      int l = left(idx);
      int r = right(idx);
      int big = idx;

      if (l < heap_size and heap[l] > heap[big]) {
        big = l;
      }

      if (r < heap_size and heap[r] > heap[big]) {
        big = r;
      }

      if (idx != big) {
        swap(heap[idx], heap[big]);
        idx = big;
      } else {
        return;
      }
    }
  }
};