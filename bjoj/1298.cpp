#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> amatch, bmatch;
vector<vector<int>> adj;
int n, m;

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

int bimatch() {
	amatch.assign(n+1, -1);
	bmatch.assign(n+1, -1);
	int cnt = 0;
	for (int i=1; i<=n; ++i) {
		vector<bool> visited(n+1, false);
		cnt += dfs(i, visited);
	}
	return cnt;
}
	

int main() {
	cin >> n >> m;
	adj.clear();
	adj.resize(n+1);
	for (int i=0; i<m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	cout << bimatch() << endl;
	return 0;
} 
