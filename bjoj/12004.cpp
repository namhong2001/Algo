#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
int N, M;

vector<bool> checked;
vector<bool> closed;
void dfs(int here) {
	if (closed[here] || checked[here]) return;
	checked[here] = true;
	for (int there : adj[here]) {
		dfs(there);
	}
}
	
bool check() {
	checked.assign(N, false);
	for (int i=0; i<N; ++i) {
		if (!closed[i]) {
			dfs(i);
			break;
		} 
	}
	for (int i=0; i<N; ++i) {
		if (!closed[i] && !checked[i]) return false;
	}
	return true;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	adj.resize(N);
	closed.assign(N, false);
	for (int i=0; i<M; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<N; ++i) {
		cout << (check() ? "YES" : "NO") << '\n';
		int a;
		cin >> a;
		a--;
		closed[a] = true;
	}
	return 0;
}
		
	
	

