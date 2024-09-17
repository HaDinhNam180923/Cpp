#include<bits/stdc++.h>
using namespace std;
// front phan tu dau tien
// push
//pop
int main(){
    queue<int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    cout << qu.front() << endl;
    qu.pop();
    cout << qu.front() << endl << qu.size() << endl ;
    cout << qu.empty() << endl;// trong thi tra ve 1
    return 0;
}