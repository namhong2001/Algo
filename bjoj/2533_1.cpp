#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj; 
vector<vector<int>> d;

int dynamic(int here, int parent, int isearly) {
	int &ret = d[here][isearly];
	if (ret != -1) return ret;
	ret = isearly;
	for (int child : adj[here]) {
		if (child == parent) continue;
		if (isearly) {
			ret += min(dynamic(child, here, 0), dynamic(child, here, 1));
		} else {
			ret += dynamic(child, here, 1);
		}
	}
	return ret;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	adj.resize(n);
	d.assign(n, vector<int>(2, -1));
	for (int i=0; i<n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << min(dynamic(0, 0, 0), dynamic(0, 0, 1)) << endl;
	return 0;
} 
	
