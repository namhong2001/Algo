#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct Shark {
	int a, b, c;
	bool operator <= (const Shark &rhs) const {
		return a <= rhs.a && b <= rhs.b && c <= rhs.c;
	}
	bool operator == (const Shark &rhs) const {
		return tie(a, b, c) == tie(rhs.a, rhs.b, rhs.c);
	}
};

vector<vector<int>> adj;
vector<int> amatch, bmatch;
vector<Shark> in;

bool is_cycle(int here, int target) {
	int p = here/2;
	while (in[p] == in[target]) {
		if (p == target) return true;
		if (bmatch[p] == -1) break;
		p = bmatch[p]/2;
	}
	return false;
} 

bool dfs(int here, vector<bool> &visited) {
	if (visited[here]) return false;
	visited[here] = true;
	for (int there : adj[here]) {
//		if (is_cycle(here, there)) continue;
		if (bmatch[there] == -1 || dfs(bmatch[there], visited)) {
			amatch[here] = there;
			bmatch[there] = here;
			return true;
		}
	} 
	return false;
}

int bipmatch(int asize, int bsize) {
	int cnt = 0;
	amatch.assign(asize, -1);
	bmatch.assign(bsize, -1);
	for (int i=0; i<asize; ++i) {
		vector<bool> visited(asize, false);
		cnt += dfs(i, visited);
	}
	return cnt;
}

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		in.push_back({a, b, c});
	}
	adj.clear();
	adj.resize(2*n);
	for (int i=0; i<in.size(); ++i) {
		for (int j=0; j<in.size(); ++j) {
			if (i == j) continue;
			if (in[i] <= in[j]) {
				adj[2*j].push_back(i);
				adj[2*j+1].push_back(i);
			}
		}
	}
	cout << n-bipmatch(2*n, n) << endl;
	return 0;
} 
