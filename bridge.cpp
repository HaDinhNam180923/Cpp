#include<iostream>
#include<vector>
using namespace std;

const int N = 1e4 + 5;
int n, m;
vector<int> adj[N];
vector<int> low(N), num(N, -1);
vector< pair<int, int> > res;
int curNum = 0;
void dfs(int u, int p){
	low[u] = num[u] = ++curNum;
	for(const int &v : adj[u]){
		if(v == p) continue;
		if (num[v] == -1){
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], num[v]);
		}
		if (low[v] > num[u]) res.push_back(make_pair(u, v));
	}
}

int main(){
	freopen("bridge.txt", "r", stdin);
	input();
	for(int u; u<=n; u++){
		if(num[u]==-1) dfs(u, -1);
	}
	for (const auto &e : res){
		cout << e.first
	}
}