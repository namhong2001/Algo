#include <iostream>
#include <vector>

using namespace std;

vector<int> amatch, bmatch;
vector<vector<int>> adj;
int n, m, k;

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
	amatch.assign(2*n, -1);
	bmatch.assign(m, -1);
	int cnt = 0;
	for (int i=0; i<n; ++i) {
		vector<bool> visited(2*n, false);
		cnt += dfs(2*i, visited);
	}
	for (int i=0; i<n; ++i) {
		if (k==0) break;
		vector<bool> visited(2*n, false);
		if (dfs(2*i+1, visited)) {
			k--;
			cnt++;
		}
	}
	return cnt;
} 
int main() {
	cin >> n >> m >> k;
	adj.resize(2*n);
	for (int i=0; i<n; ++i) {
		int t;
		cin >> t;
		while (t--) {
			int a;
			cin >> a;
			adj[2*i].push_back(a-1);
			adj[2*i+1].push_back(a-1);
		}
	}
	cout << bimatch() << endl;
	return 0;
} 
