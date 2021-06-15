#include "./max-heap.hpp"

using namespace std;

int main() {
  MaxHeap heap;
  for (int i = 0; i < 10; i++) {
    heap.insert(i);
  }

  while (!heap.empty()) {
    cout << heap.extract_max() << " ";
  }

  for (int i = 0; i < 10; i++) {
    heap.insert(i);
  }

  while (!heap.empty()) {
    cout << heap.extract_max() << " ";
  }
  return 0;
}