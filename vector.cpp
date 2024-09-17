#include <bits/stdc++.h>
using namespace std;

int main() {
    int* dynamicArray;
    int size;

    cout << "Nhap kich thuoc cua mang: " << endl;
    cin >> size;

    dynamicArray = new int[size];

    cout << "Nhap cac phan tu cua mang: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "Phan tu " << i + 1 << ": ";
        cin >> dynamicArray[i];
    }

    cout << "Cac phan tu cua mang la: " << endl;
    for(int i = 0; i < size; i++){
        cout << dynamicArray[i] << " ";
    }

    delete[] dynamicArray;

    return 0;
}