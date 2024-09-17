#include <bits/stdc++.h> 
using namespace std;

const int maxN = 1111;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, r, c;
int maze[maxN][maxN], dist[maxN][maxN];

int shortestPath() {
    queue< pair<int, int> > q;
    q.push({r, c}); // push 
    dist[r][c] = 0;
	maze[r][c] = 1;
    while (!q.empty()) {
        pair<int, int> curr = q.front(); // pop 
        q.pop(); // bo phan tu dau 

        for (int i = 0; i < 4; i++) {
        	
		// toa do hien tai 
        	int x = curr.first;  // pair<first, second> 
        	int y = curr.second;
            int newX = x + dx[i];
            int newY = y + dy[i];
			
			if (newX < 1 || newX > n || newY < 1 || newY > m) return dist[x][y] + 1; 
            if (maze[newX][newY] != 1) {
                dist[newX][newY] = dist[x][y] + 1;
                q.push(pair<int, int> (newX, newY));
                maze[newX][newY] = 1; // duyet qua gan bang 1
            }
        }
    }

    // tim diem thoat cua me cung 


    return -1; // Khong tim thay duong thoat
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
        }
    }

    int result = shortestPath();
    cout << result << endl;

    return 0;
}

