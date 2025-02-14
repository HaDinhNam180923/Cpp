#include <iostream>
#include <cstring>
using namespace std;
const int N = 20;
int n;
int INF = 1e9;
int C[N][N], mem[N][1 << N];
int dp(int i, int S){
	if (S == (1 << n) - 1)
	return mem[i][S] = C[i][0];
	
	if (mem[i][S] != -1) return mem[i][S];
	
	int res = INF, j;
	for (j = 1; j <= n; j++){
		if(S & (1 << j)) continue;
		res = min(res, C[i][j] +
			dp(j, S | (1 << j)));
	}
	return mem[i][S] = res;
} 
void input(){
	cin >> n;
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> C[i][j];
}

void trace(int i, int S){
	cout << i << " -> ";
	if (S == (1 << n) - 1)
		cout << 0 << endl;
	
	int j;
	for (j = 1; j <= n; j++){
		if (S & (1 << j)) continue;
		if (mem[i][S] == C[i][j]+
		mem[j][S | (1 << j)]) trace(j, S | (1 << j));
		break;
	}

}
void iter_trace(){
	int k, j, i = 0, S = 1;
	cout << 0 << " -> ";
	for(k = 1; k < n; k++){
		cout << i << " -> ";
		for (j = 1; j < n; j++){
			if (S & (1 << j)) continue;
			if (mem[i][S] == C[i][j]+
			mem[j][S | 1 << j]) {
				i = j;
				S |= (1 << j);
				break;
			}
		}
		cout << i << " -> ";
	}
	cout << 0 << endl;
}
int main(){
	freopen("data.txt","r",stdin);
	memset (mem, -1, sizeof(mem));
	input();
	cout << dp(0, 1<<0) << endl;
	trace(0, 1<<0);
	//iter_trace();
	return 0;
}
