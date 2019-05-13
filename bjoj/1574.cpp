#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> adj;
vector<int> bmatch;

int r, c, n;
bool dfs(int here, vector<bool> &visited) {
	if (visited[here]) return false;
	visited[here] = true;
	for (int there=0; there<c; ++there) {
		if (!adj[here][there]) continue;
		if (bmatch[there] == -1 || dfs(bmatch[there], visited)) {
			bmatch[there] = here;
			return true;
		}
	}
	return false;
}

int bipmatch() {
	bmatch.assign(c, -1);
	int cnt = 0;
	for (int i=0; i<r; ++i) {
		vector<bool> visited(r, false);
		cnt += dfs(i, visited);
	}
	return cnt;
}

int main() {
	cin >> r >> c >> n;
	adj.assign(r, vector<bool>(c, true));
	for (int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a][b] = false;
	}
	cout << bipmatch() << endl;
	return 0;
} 
