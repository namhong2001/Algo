#include <iostream>
#include <vector>

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
	amatch.assign(n, -1);
	bmatch.assign(m, -1);
	int cnt = 0;
	for (int i=0; i<n; ++i) {
		vector<bool> visited(n, false);
		cnt += dfs(i, visited);
	}
	return cnt;
} 
int main() {
	cin >> n >> m;
	adj.resize(n);
	for (int i=0; i<n; ++i) {
		int t;
		cin >> t;
		while (t--) {
			int a;
			cin >> a;
			adj[i].push_back(a-1);
		}
	}
	cout << bimatch() << endl;
	return 0;
} 
