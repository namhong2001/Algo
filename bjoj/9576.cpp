#include <iostream>
#include <vector>

using namespace std;


vector<pair<int,int>> adj;
vector<int> amatch, bmatch;
int n, m;

bool dfs(int here, vector<bool> &visited) {
	visited[here] = true;
	for (int there = adj[here].first; there <= adj[here].second; ++there) {
		if (bmatch[there] == -1) {
			amatch[here] = there;
			bmatch[there] = here;
			return true;
		}
	}
	for (int there = adj[here].first; there <= adj[here].second; ++there) {
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
	amatch.assign(m, -1);
	bmatch.assign(n, -1);
	int cnt = 0;
	for (int i=0; i<m; ++i) {
		vector<bool> visited(m, false);
		cnt += dfs(i, visited);
	}
	return cnt;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		adj.resize(m);
		for (int i=0; i<m; ++i) {
			int a, b;
			cin >> a >> b;
			adj[i] = {a-1, b-1};
		}
		cout << bimatch() << endl;
	}
	return 0;
}	
