#include<bits/stdc++.h>
using namespace std;
// pair<dttype1, dttype2> v;
int main() {
    pair<int, int> v = make_pair(100, 200);
    // pair<int, int> v = {100, 200};
    cout << v.first << " " << v.second << endl;

    tuple<int, int, int> t{1, 2, 3};
    cout << get<0>(t) << endl;
    return 0;
}