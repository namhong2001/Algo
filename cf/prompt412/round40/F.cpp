#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

struct Edge() {
	int u, v, w;
	bool operator < (const &Edge e) {
		return w < e.w;
	}
} 

vector<int> r;
int f(int a) {
	return r[a] = a == r[a] ? a : f(r[a]);
}
void u(int a, int b) {
	a = f(a), b = f(b);
	r[a] = b;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<bool> special(N);
	for (int i=0; i<K; ++i) {
		int a;
		cin >> a;
		a--;
		special[a] = true;
	}
	vector<Edge> edges;
	for (int i=0; i<M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		edges.push_back({u, v, w});
	}
	sort(edges.begin(), edges.end());
	r.resize(N);
	for (int i=0; i<N; ++i) r[i] = i;
	vector<int> ans(N, INF);
	bool has_prev = false;
	for (Edge &e : edges) { 
		if (special[e.u] && has_prev) {
			ans[e.u] = min(ans[e.u], e.w);
		}
		
		if (f(e.u) == f(e.v)) continue;
		u(e.u, e.v);
		if (
		


		
	return 0;
}

