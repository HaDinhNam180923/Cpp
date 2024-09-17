#include<bits/stdc++.h>
using namespace std;

//push
//pop
//top
//size
//empty

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl << st.size() << endl ;

    return 0;
}