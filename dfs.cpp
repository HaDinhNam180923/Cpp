#include<iostream>
#include<vector>
using namespace std;

const int N = 1e4+5;
vector<int> adj[N];
vector<bool> visited(N, false);
int m, n;

void input (){
	cin >> n >> m;
	int u, v, i; 
	for(i = 0; i<m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
	}
}
void dfs(int u){
	cout << u << ' ';
	visited[u] = true;
	for(const int &v : adj[u] ){
		if(!visited[v]) dfs(v);
	}
}

int main(){
	freopen("nam.txt", "r", stdin);
	input();
	for(int u = 1; u<=n; u++){
		if(!visited[u]) dfs(u);
	}
}
