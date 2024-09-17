//C++ 
#include <bits/stdc++.h> 
using namespace std;

// H�m �?m s? l?n �?o ng�?c trong m?ng con
int count_inversions(vector<int>& arr, int left, int right) {
  // Tr�?ng h?p c� s?
  if (left >= right) {
    return 0;
  }

  // Chia m?ng th�nh hai n?a
  int mid = (left + right) / 2;
  int inversions_left = count_inversions(arr, left, mid);
  int inversions_right = count_inversions(arr, mid + 1, right);

  // �?m s? l?n �?o ng�?c khi h?p nh?t hai n?a
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

  // Tr? v? t?ng s? l?n �?o ng�?c
  return inversions_left + inversions_right + inversions_merge;
}

// H�m ch�nh
int main() {
  // Nh?p s? ph?n t? c?a m?ng
  int n;
  cin >> n;

  // Kh?i t?o m?ng
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // �?m s? l?n �?o ng�?c
  int inversions = count_inversions(arr, 0, n - 1);

  // In k?t qu?
  cout << inversions % 1000000007 << endl;

  return 0;
}

