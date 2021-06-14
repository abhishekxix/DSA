#include <bits/stdc++.h>

using namespace std;

vector<int> compute_lps(string pattern) {
  vector<int> lps(pattern.length());
  int i = 0;
  int j = 1;

  while (j < pattern.length()) {
    if (pattern[i] == pattern[j]) {
      i++;
      lps[j] = i;
      j++;
    } else if (i != 0) {
      i = lps[i - 1];
    } else {
      lps[j] = 0;
      j++;
    }
  }

  return lps;
}

int kmp(string text, string pattern) {
  int m = text.length();
  int n = pattern.length();
  int i = 0;
  int j = 0;

  vector<int> lps = compute_lps(pattern);

  while (i < m and j < n) {
    if (pattern[j] == text[i]) {
      i++;
      j++;
    } else if (j != 0) {
      j = lps[j - 1];
    } else {
      i++;
    }
  }

  if (j == n) return i - n;

  return -1;
}

int main() {
  string text;
  string pattern;
  cin >> text >> pattern;

  cout << kmp(text, pattern);
  return 0;
}