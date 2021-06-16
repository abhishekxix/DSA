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

void quicksort(vector<int> &a, int l, int r) {
  if (l < r) {
    int pivot = partition(a, l, r);
    quicksort(a, l, pivot - 1);
    quicksort(a, pivot + 1, r);
  }
}

int main() {
  vector<int> a{5, 4, 3, 2, 1};
  quicksort(a, 0, a.size() - 1);

  return 0;
}