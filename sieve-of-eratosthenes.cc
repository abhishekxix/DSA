#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 1) return 0;
    n++;
    vector<bool> isprime(n, true);
    isprime[0] = isprime[1] = false;
    int count = 0;

    int i = 2;
    int j = 2;
    while (i < n) {
      if (isprime[i]) {
        j = 2;
        count++;
        while (j * i < n) {
          isprime[j * i] = false;
          j++;
        }
      }
      i++;
    }
    return count;
  }
};

long reverse(int x) {
  long res = 0;

  while (x) {
    res = res * 10 + x % 10;
    x /= 10;
  }
  return res;
}

int main() {
  Solution sol;
  cout << reverse(1534236469);
  return 0;
}