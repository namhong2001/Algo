#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

const int dd[2][2] = {{0, 1}, {1, 0}};


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

int bipmatch(int asize, int bsize) {
	bmatch.assign(bsize, -1);
	int cnt = 0;
	for (int i=0; i<asize; ++i) {
		vector<bool> visited(asize, false);
		cnt += dfs(i, visited);
	}
	return cnt;
} 

int main() {
	int n;
	cin >> n;
	vector<string> board(n);
	for (int i=0; i<n; ++i) {
		cin >> board[i];
	}
	int cnt[2] = {0, 0};
	int id[2][n][n];
	memset(id, -1, sizeof(id));
	for (int dir=0; dir<2; ++dir) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (board[i][j] == 'X') continue;
				if (id[dir][i][j] != -1) continue;
				int ni = i;
				int nj = j;
				while (ni < n && nj < n && board[ni][nj] == '.') {
					id[dir][ni][nj] = cnt[dir];
					ni += dd[dir][0];
					nj += dd[dir][1];
				}
				cnt[dir]++;
			}
		}
	}
	adj.resize(cnt[0]);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (board[i][j] == '.') {
				int a = id[0][i][j];
				int b = id[1][i][j];
				adj[a].push_back(b);
			}
		}
	}
	cout << bipmatch(cnt[0], cnt[1]);
	return 0;
} 
