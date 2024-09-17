#include<bits/stdc++.h>
using namespace std;

// set: phan tu trong set deu khac nhau
// insert
// size
// count : tim kiem
// find : khong tim thay tra ve end
// s.begin() tro den dau mang
// s.end() tro den cuoi mang
//s.erase(gia_tri muon xoa) : xoa
// getline(cin, str); : doc du lieu
// multiset co the giong nhau nhung van sap xep, count in ra so lan xuat hien cua phan tu do trong tap hop
int main() {
    set<int> s;
    s.insert(100);
    s.insert(200);
    s.insert(300);
    s.insert(100);
    s.insert(200);
    s.insert(300);
    cout << s.size() << endl; // Ket qua la 3 vi khong luu duoc phan tu giong nhau
    if (s.count(150) != 0) cout << "Found!" << endl;
    else cout << "Not found!" << endl;
    if (s.find(100) != s.end()) cout << "Found!" << endl;
    else cout << "Not found!" << endl;
    cout << *s.begin() << endl;
    cout << *s.rbegin() << endl;
    for (int x : s){ // auto
        cout << x << endl;
    }
    return 0;
}