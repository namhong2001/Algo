#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;

typedef pair<int,int> pii; 
vector<vector<pii>> adj; 

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	adj.resize(n);
	vector<int> gem(n, -1);
	vector<vector<bool>> d(n, vector<bool>(1<<k, false)); 
	int gem_cnt = 0;
	for (int i=0; i<k; ++i) {
		int a;
		cin >> a;
		a--;
		gem[a] = gem_cnt++; 
	}
	for (int i=0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	int ans = 0;
	function<void(int, int)> dfs = [&](int here, int status) { 
		if (gem[here] != -1 && (status | 1<<gem[here]) != status) dfs(here, status | 1<<gem[here]);
		if (d[here][status]) return; 
		d[here][status] = true;
		int gem_cnt = __builtin_popcount(status);
		if (here == 0) ans = max(ans, gem_cnt);
		//cerr << here << ' ' << status << ' ' << gem_cnt << endl;
		for (pii &t : adj[here]) {
			int there = t.first;
			int c = t.second;
			if (gem_cnt > c) continue;
			dfs(there, status);
		}
	};
	dfs(0, 0); 
	cout << ans << endl;
	return 0;
} 
