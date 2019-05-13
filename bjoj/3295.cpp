#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> amatch, bmatch;

bool dfs(int here, vector<bool> &visited) {
	visited[here] = true;
	for (int there : adj[here]) {
		if (bmatch[there] == -1) {
			amatch[here] = there;
			bmatch[there] = here;
			return true;
		}
	}
	for (int there : adj[here]) {
		int p = bmatch[there];
		if (visited[p]) continue;
		if (dfs(p, visited)) {
			amatch[here] = there;
			bmatch[there] = here;
			return true;
		}
	}
	return false;
}

int bimatch(int n) {
	int cnt = 0;
	amatch.assign(n, -1);
	bmatch.assign(n, -1);
	for (int i=0; i<n; ++i) {
		vector<bool> visited(n, false);
		cnt += dfs(i, visited);
	}
	return cnt;
}



int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		adj.clear();
		adj.resize(n);
		for (int i=0; i<m; ++i) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}
		cout << bimatch(n) << endl;
	}
	return 0;
} 
