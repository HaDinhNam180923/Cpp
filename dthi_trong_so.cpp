#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 +5;
int n, m;
struct edge{
	int u, v, w;
	edge(int _u, int _v, int _w) :
	u(_u), v(_v), w(_w) {}
};
vector<edge> edge;
struct UnionFind{
	vector<int> parent;
	UnionFind(int n){
		parent = vector<int>(n);
		for (int i = 1; i <= n; i++) parent[i] = i;
	}
	int Find(int x){
		if (parent[x] == x) return x;
		return parent[x] = Find(parent[x]);
	}
	void Unite(int x, int y){
		parent[Find(x)] = Find(y);
	}
};

bool edgeCmp(const edge &a, const edge &b){
	return a.w < b.w;
}

vector <edge> kruskal(int n, vector<edge> edges) {
	sort(edge.begin(), edge.end(), edgeCmp);
	UnionFind uf(n);
	vector<edge> res;
	for (const auto &e : edges){
		int u = e.u, v = e.v, w = e.w;
		if (uf.Find(u) != uf.Find(v)) {
			res.push_back(e);
			uf.Unite(u, v);
		}
	}
	return res;
}
void input(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> w;
		edges.push_back(edge(u, v, w));
	}
}

int main() {
	freopen("data.inp", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	vector<edge> res = kruskal(n, edges);
	int ans = 0;
	for (const edge &e : res){
		ans += e.w;
		cout << e.u << ' ' << e.v << ' ' << e.w << endl;
	};
	cout << "MST: " << ans << endl;
	return 0;
}