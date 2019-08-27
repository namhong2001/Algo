#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> adj;
int V, E;

bool dfs(int here, int cur_group, int group[]) {
	if (group[here] != -1) {
		if (group[here] != cur_group) return false;
		else return true;
	}
	group[here] = cur_group;
	for (int next : adj[here]) {
		if (!dfs(next, cur_group^1, group)) return false;
	}
	return true;
}
	
bool solve() {
	int group[V];
	memset(group, -1, sizeof(group));
	for (int i=0; i<V; ++i) {
		if (group[i] == -1 && !dfs(i, 0, group)) return false;
	}
	return true; 
}


int main() {
	int K;
	cin >> K;
	while (K--) {
		cin >> V >> E;
		adj.clear();
		adj.resize(V);
		for (int i=0; i<E; ++i) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		cout << (solve() ? "YES" : "NO") << '\n';
	} 
	return 0;
}

