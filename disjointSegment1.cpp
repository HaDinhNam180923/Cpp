#include <bits/stdc++.h> 
#define max 10005
using namespace std;

int n;
pair<int,int> a[max];//phan tu mang a co dang int, int

bool cmp (pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

void input(){
	cin >> n;
	int i;
	for(i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}
}

void solve(){
	int i, res = 0;
	int last = -1; // a[i].second
	sort(a+1, a+n+1, cmp);
	for(i=1; i<=n; i++){
		if(a[i].first > last){
			res ++;
			last = a[i].second;	
		}
	}
	cout << res << endl;
}
int main() 
{ 
	input();
	solve();
	return 0;
}
