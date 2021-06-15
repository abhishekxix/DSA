#include <bits/stdc++.h>

using namespace std;

void max_heapify(vector<int> &a, int heap_size, int idx) {
  while (true) {
    int big = idx;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;

    if (left < heap_size and a[left] > a[big]) big = left;
    if (right < heap_size and a[right] > a[big]) big = right;

    if (big != idx) {
      swap(a[big], a[idx]);
      idx = big;
    } else {
      return;
    }
  }
}

void build_max_heap(vector<int> &a) {
  for (int i = a.size() / 2; i >= 0; i--) {
    max_heapify(a, a.size(), i);
  }
}

void heapsort(vector<int> &a) {
  int heap_size = a.size();
  build_max_heap(a);

  while (heap_size >= 2) {
    swap(a[0], a[heap_size - 1]);
    heap_size--;
    max_heapify(a, heap_size, 0);
  }
}

int main() {
  vector<int> a{1, 2, 3, 4, 5};
  heapsort(a);
  return 0;
}