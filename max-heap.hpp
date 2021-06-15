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

  int parent(int idx) {
    return ((idx % 2 == 0) ? idx / 2 - 1 : idx / 2);
  }

  int increase_key(int idx, int key) {
    if (heap.at(idx) > key) return heap.at(idx);
    heap.at(idx) = key;

    while (idx > 0 and heap.at(parent(idx)) < heap.at(idx)) {
      swap(heap.at(idx), heap.at(parent(idx)));
      idx = parent(idx);
    }
    return key;
  }

 public:
  MaxHeap() : heap_size(0), heap(vector<int>()) {}

  int size() {
    return heap_size;
  }

  int max() {
    return heap.at(0);
  }

  int extract_max() {
    int max_value = this->max();
    swap(heap.at(0), heap.at(heap_size - 1));
    heap_size--;
    max_heapify(0);
    return max_value;
  }

  int insert(int key) {
    if (heap_size == heap.size()) {
      heap.push_back(INT_MIN);
    } else {
      heap.at(heap_size) = INT_MIN;
    }
    heap_size++;

    increase_key(heap_size - 1, key);
    return key;
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

  bool empty() {
    return heap_size == 0;
  }
};