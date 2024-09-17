#include <bits/stdc++.h>
using namespace std;

//vector<kieu_du_lieu> ten_vector;
//push_back(gia_tri) : push vao cuoi mang
//v.size() : kich thuoc vector
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
//    cout << v.size() << endl;
//    cout << "Phan tu dau tien trong vector: " << v[0] << endl;
//    cout << "Phan tu cuoi cung trong vector: " << v.back() << endl;
//    cout << "Phan tu cuoi cung trong vector: " << v[v.size()-1] << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    for (int x : v){
        cout << endl << x;
    }
    return 0;
}
