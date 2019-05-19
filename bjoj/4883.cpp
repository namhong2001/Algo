#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std; 

typedef pair<int,int> pii;

const int INF = 987654321;

vector<int> cost;
vector<vector<int>> adj(300000);

int n;
int dijkstra(int src, int dest) {
	vector<int> d(3*n, INF);
	priority_queue<pii> pq;
	pq.push({-cost[src], src});
	d[src] = cost[src];
	while (!pq.empty()) {
		pii cur = pq.top();
		pq.pop();
		int c = -cur.first;
		int here = cur.second;
		if (c > d[here]) continue;
		if (here == dest) break;
		for (int there : adj[here]) {
			if (c + cost[there] < d[there]) {
				d[there] = c + cost[there];
				pq.push({-d[there], there});
			}
		}
	}
	return d[dest];
} 

int bellman(int src, int dest) {
	vector<int> d(3*n, INF);
	d[src] = cost[src];
	for (int i=0; i<3*n; ++i) {
		for (int here=0; here<3*n; ++here) { 
			if (d[here] == INF) continue;
			for (int there : adj[here]) {
				if (d[here] + cost[there] < d[there]) {
					d[there] = d[here] + cost[there];
				}
			}
		}
	}
	return d[dest];
} 


vector<int> d;
int dynamic(int here) {
	if (here == 0) return INF;
	if (here == 1) return cost[here];
	if (here == 2) return cost[here-1] + cost[here];
	int &ret = d[here];
	if (ret != -1) return ret;
	ret = cost[here];
	if (here%3 == 0) {
		return ret += min({dynamic(here-3), dynamic(here-2)});
	} else if (here%3 == 1) {
		return ret += min({dynamic(here-4), dynamic(here-3), dynamic(here-2), dynamic(here-1)});
	} else if (here%3 == 2) {
		return ret += min({dynamic(here-4), dynamic(here-3), dynamic(here-1)});
	}
	return ret;
} 

int kruskal(int src, int dest) {
	struct Edge {
		int u, v, cost;
		bool operator < (const Edge &A) const { 
			return cost < A.cost;
		}
	};
	vector<Edge> edges;
	for (int i=0; i<3*n; ++i) {
		for (int there : adj[i]) {
			edges.push_back({i, there, cost[there]});
		}
	}
	sort(edges.begin(), edges.end());
	vector<int> r(3*n);
	for (int i=0; i<3*n; ++i) r[i] = i;
	function<int(int)> f = [&](int a) {
		return r[a] = a == r[a] ? a : f(r[a]);
	};
	auto u = [&](int a, int b) {
		a = f(a), b = f(b);
		r[a] = b;
	};
	vector<vector<int>> n_adj(3*n);
	for (Edge &e : edges) {
		u(e.u, e.v);
		n_adj[e.u].push_back(e.v);
		if (f(src) == f(dest)) break;
	}

	function<int(int,int)> dfs = [&](int here, int c) {
		if (here == dest) return c;
		for (int there : n_adj[here]) {
			int ans = dfs(there, c+cost[there]);
			if (ans != -INF) return ans;
		}
		return -INF;
	};
	return dfs(src, cost[src]);
} 

int main() { 
	for (int i=0; i<(300000-3); ++i) {
		if (i%3 == 0) {
			adj[i].push_back(i+1);
			adj[i].push_back(i+3);
			adj[i].push_back(i+4);
		} else if (i%3 == 1) {
			adj[i].push_back(i+1);
			adj[i].push_back(i+2);
			adj[i].push_back(i+3);
			adj[i].push_back(i+4);
		} else if (i%3 == 2) {
			adj[i].push_back(i+2);
			adj[i].push_back(i+3);
		}
	}
	adj[299997].push_back(299998);
	adj[299998].push_back(299999);
			
	for (int t=1; ;t++) {
		cin >> n; 
		if (n == 0) return 0; 
		cost.assign(3*n, 0);
		
		for (int i=0; i<3*n; ++i) {
			cin >> cost[i];
		}
		d.assign(3*n, -1);
		//cout << t << ". " << dijkstra(1, 3*n-2) << endl;
		//cout << t << ". " << bellman(1, 3*n-2) << endl;
		cout << t << ". " << dynamic(3*n-2) << endl;
		//cout << t << ". " << kruskal(1, 3*n-2) << endl;
	}
	return 0;
} 
