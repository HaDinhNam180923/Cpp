#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e4 + 5, MOD = 1e9 + 7;
int n, k1, k2;
int mem[N][2];

int dp(int i, int work){
	if(i == 0) return mem[i][work] = 1;
	if(mem[i][work]) return mem[i][work];
	int res = 0;
	if(work == 0) {
		res = dp(i-1, 1)%MOD;
	} else {
		for (int j = i - k2; j <= i - k1; j++)
			if( j >= 0) res = (res + dp (j, 0))%MOD;
	}
	return mem[i][work] = res;
}
int main(){
	memset (mem, 0, sizeof(mem));
	cin >> n >> k1 >> k2;
	cout << dp(0, 1<<0) << endl;
}
