#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int dd[2][2] = {{1, -1}, {1, 1}}; 

vector<vector<int>> adj;
vector<int> bmatch;

bool dfs(int here, vector<bool> &visited) {
	if (visited[here]) return false;
	visited[here] = true;
	for (int there : adj[here]) {
		if (bmatch[there] == -1 || dfs(bmatch[there], visited)) {
			bmatch[there] = here;
			return true;
		}
	}
	return false;
}

int bimatch(int asize, int bsize) {
	bmatch.assign(bsize, -1);
	int cnt = 0;
	for (int i=0; i<asize; ++i) {
		vector<bool> visited(asize, false);
		cnt += dfs(i, visited);
	}
	return cnt;
} 

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> board(n, vector<bool>(n, true));
	for (int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		board[a][b] = false;
	}
	int cnt[2] = {0, 0};
	int id[2][n][n];
	memset(id, -1, sizeof(id));
	for (int dir=0; dir<2; ++dir) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (board[i][j] && id[dir][i][j] == -1) {
					int ni = i, nj = j;
					while (0 <= ni && ni < n &&
							0 <= nj && nj < n &&
							board[ni][nj]) {
						id[dir][ni][nj] = cnt[dir];
						ni += dd[dir][0];
						nj += dd[dir][1];
					}
					cnt[dir]++;
				}
			}
		}
	}
	adj.resize(cnt[0]); 
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (board[i][j]) {
				int a = id[0][i][j];
				int b = id[1][i][j];
				adj[a].push_back(b);
			}
		}
	}
	cout << bimatch(cnt[0], cnt[1]) << endl;
	return 0;
} 
