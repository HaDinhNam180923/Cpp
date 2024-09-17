//C++ 
#include <bits/stdc++.h> 
using namespace std;

// Hàm ð?m s? l?n ð?o ngý?c trong m?ng con
int count_inversions(vector<int>& arr, int left, int right) {
  // Trý?ng h?p cõ s?
  if (left >= right) {
    return 0;
  }

  // Chia m?ng thành hai n?a
  int mid = (left + right) / 2;
  int inversions_left = count_inversions(arr, left, mid);
  int inversions_right = count_inversions(arr, mid + 1, right);

  // Ð?m s? l?n ð?o ngý?c khi h?p nh?t hai n?a
  int inversions_merge = 0;
  int i = left;
  int j = mid + 1;
  while (i <= mid && j <= right) {
    if (arr[i] > arr[j]) {
      inversions_merge += (mid - i);
    }
    i++;
    j++;
  }

  // Tr? v? t?ng s? l?n ð?o ngý?c
  return inversions_left + inversions_right + inversions_merge;
}

// Hàm chính
int main() {
  // Nh?p s? ph?n t? c?a m?ng
  int n;
  cin >> n;

  // Kh?i t?o m?ng
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Ð?m s? l?n ð?o ngý?c
  int inversions = count_inversions(arr, 0, n - 1);

  // In k?t qu?
  cout << inversions % 1000000007 << endl;

  return 0;
}

