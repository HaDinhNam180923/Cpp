#include<bits/stdc++.h>
#define max_n 100005
using namespace std;

int t;
int n, c, a[max_n];

bool check(int dis){
	int sl = 1;//dem so luong phan tu trong tap con
	int i = 1;
	int j = 2;
	while (i<n) {
		while (j<=n && a[j]-a[i] < dis) j++;
		if (j<=n) sl++;
		if (sl>=c) return true;
		i = j;
		j++;
	}
	return false;
}
