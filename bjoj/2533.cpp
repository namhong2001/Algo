#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> bmatch;
int n;

bool dfs(int here, vector<bool> &visited) {
	if (visited[here]) return false;
	visited[here] = true;
	for (int there : adj[here]) {
		if (bmatch[there] == -1) {
			bmatch[there] = here;
			return true;
		}
	}
	for (int there : adj[here]) {
		if (dfs(bmatch[there], visited)) {
			bmatch[there] = here;
			return true;
		}
	}
	return false;
} 

int bipartite(vector<int> &aset) {
	bmatch.assign(n, -1);
	int ret = 0;
	for (int here : aset) {
		vector<bool> visited(n, false);
		ret += dfs(here, visited);
	}
	return ret;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	adj.resize(n);
	for (int i=0; i<n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> aset;
	queue<int> q;
	q.push(0);
	vector<bool> visited(n, false);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		visited[here] = true;
		aset.push_back(here);
		vector<int> children;
		for (int neighbor : adj[here]) {
			if (visited[neighbor]) continue;
			children.push_back(neighbor);
		}
		for (int child : children) {
			visited[child] = true;
			for (int decen : adj[child]) {
				if (decen == here) continue;
				q.push(decen);
			}
		}
	}
	cout << bipartite(aset) << endl;
	return 0;
}

