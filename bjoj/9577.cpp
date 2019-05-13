#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> amatch, bmatch;
vector<vector<int>> adj;

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

int bimatch(int total) {
	int cnt = 0;
	amatch.assign(101, -1);
	bmatch.assign(101, -1);
	for (int i=0; i<100; ++i) {
		vector<bool> visited(100, false);
		cnt += dfs(i, visited);
		if (cnt == total) return i+1;
	}
	return -1;
} 

int main() {
	int T;
	cin >> T;
	while (T--) {
		adj.clear();
		adj.resize(100);
		int n, m;
		cin >> n >> m;
		for (int i=0; i<m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			vector<int> parts;
			for (int i=0; i<c; ++i) {
				int p;
				cin >> p;
				parts.push_back(p);
			}
			for (int t=a; t<b; ++t) {
				for (int p : parts) {
					adj[t].push_back(p);
				}
			}
		}
		cout << bimatch(n) << endl;
	}
	return 0;
} 
