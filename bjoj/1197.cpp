#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge { 
	int a, b, c;
	bool operator < (const Edge &A) const {
		return c < A.c;
	}
};


vector<int> r;
int f(int a) {
	return r[a] = a == r[a] ? a : f(r[a]);
}

void u(int a, int b) {
	a = f(a), b = f(b);
	r[a] = b;
}

int main() {
	int v, e;
	cin >> v >> e;
	vector<Edge> edges;
	r.resize(v);
	for (int i=0; i<v; ++i) r[i] = i;
	for (int i=0; i<e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edges.push_back({a, b, c});
	}
	sort(edges.begin(), edges.end());
	int cost = 0;
	int cnt = 0;
	for (Edge &e : edges) {
		int a = e.a;
		int b = e.b;
		int c = e.c;
		if (f(a) == f(b)) continue;
		u(a, b);
		cnt++;
		cost += c; 
		if (cnt == v-1) break;
	}
	cout << cost << endl;
	return 0;
} 
