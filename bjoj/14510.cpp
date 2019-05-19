#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <tuple>

using namespace std;

typedef long long ll;

struct Edge {
	int a, b, c;
	int addition;
	bool is_special;
	bool operator < (const Edge &A) const {
		if (c+addition < A.c + A.addition) return A.is_special;
		return c+addition < A.c + A.addition;
	}
};	

bool contains(unordered_set<int> &s, int target) {
	return s.find(target) != s.end();
}


vector<int> rt;
int f(int a) {
	return rt[a] = rt[a] == a ? a : f(rt[a]);
}
void u(int a, int b) {
	a = f(a), b = f(b);
	rt[a] = b;
}

pair<int,ll> kruskal(int addition, vector<Edge> &edges, int n) {
	for (Edge &e : edges) {
		if (e.is_special) e.addition = addition;
	}
	sort(edges.begin(), edges.end());
	for(int i=0; i<n; ++i) rt[i] = i;
	int cnt = 0;
	int s_cnt = 0;
	ll t_cost = 0;
	for (Edge &e : edges) {
		int a = e.a;
		int b = e.b;
		int c = e.c;
		bool is_special = e.is_special;
		if (f(a) == f(b)) continue;
		u(a, b);
		cnt++;
		if (is_special) s_cnt++;
		t_cost += c;
		if (cnt == n-1) break;
	}
	if (cnt != n-1) return {-1, -1};
	return {s_cnt, t_cost};
} 

int main() {
	int n, m, k, w;
	cin >> n >> m >> k >> w; 
	rt.resize(n);
	unordered_set<int> s_places; 
	for (int i=0; i<k; ++i) {
		int s;
		cin >> s;
		s--;
		s_places.insert(s);
	}
	vector<Edge> edges;
	for (int i=0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		bool is_special = false;
		if ((contains(s_places, a) && !contains(s_places, b)) ||
				(!contains(s_places, a) && contains(s_places, b))) {
			is_special = true;
		}
		edges.push_back({a, b, c, 0, is_special});
	}
	int l = 0, r = 2e5+1;
	pair<int,ll> ans = {-1, -1};
	while (l < r) {
		int mid = (l+r)/2;
		pair<int,ll> result = kruskal(mid-1e5, edges, n);
		//cerr << l << ' ' << r << ' ' << mid-1e5 << ' ' << result.first << ' ' << result.second << endl;
		if (result.first > w) {
			l = mid+1;
		} else {
			r = mid;
		}
	}
	
	//cerr << l-1e5 << ' ' << result.first << ' ' << result.second << endl;
	//cerr << l << endl;
	if (ans.first == -1) {
		cout << -1 << endl;
	} else {
		cout << ans.second << endl;
	}
	return 0;
} 
