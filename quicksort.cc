#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int l, int r) {
  int x = a[r];
  int i = l - 1;
  int j = l;

  while (j < r) {
    if (a[j] <= x) {
      i++;
      swap(a[j], a[i]);
    }
    j++;
  }
  i++;

  swap(a[i], a[r]);

  return i;
}

int randomized_partition(vector<int> &a, int l, int r) {
  int i = (random() % (r - l + 1)) + l;
  swap(a.at(i), a.at(r));
  return partition(a, l, r);
}

void randomized_quicksort(vector<int> &a, int l, int r) {
  if (l < r) {
    int pivot = randomized_partition(a, l, r);
    randomized_quicksort(a, l, pivot - 1);
    randomized_quicksort(a, pivot + 1, r);
  }
}

void quicksort(vector<int> &a, int l, int r) {
  if (l < r) {
    int pivot = partition(a, l, r);
    quicksort(a, l, pivot - 1);
    quicksort(a, pivot + 1, r);
  }
}

int main() {
  srand(time(nullptr));
  vector<int> a{5, 4, 3, 2, 1};
  randomized_quicksort(a, 0, a.size() - 1);

  return 0;
}