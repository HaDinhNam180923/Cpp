#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inversion_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversion_count += mid - i + 1;
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversion_count;
}

long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inversion_count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;
        inversion_count += mergeSort(arr, temp, left, mid);
        inversion_count += mergeSort(arr, temp, mid + 1, right);
        inversion_count += merge(arr, temp, left, mid, right);
    }

    return inversion_count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> temp(n);
    long long inversions = mergeSort(arr, temp, 0, n - 1);

    cout << inversions % MOD << endl;

    return 0;
}

