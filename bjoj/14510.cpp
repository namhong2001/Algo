#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>

using namespace std;

typedef long long ll;

struct Edge {
	int a, b, c;
	int addition;
	bool is_special;
};	

vector<int> rt;
int f(int a) {
	return rt[a] = rt[a] == a ? a : f(rt[a]);
}
void u(int a, int b) {
	a = f(a), b = f(b);
	rt[a] = b;
}

pair<int,ll> kruskal(int addition, vector<Edge> &edges, int n) {
	//cerr << "addition : " << addition << endl;
	//for (Edge &e : edges) {
	//	cerr << (e.is_special ? 0 : 1) << ' ';
	//}
	//cerr << endl;

	for(int i=0; i<n; ++i) rt[i] = i;
	int cnt = 0;
	int s_cnt = 0;
	ll t_cost = 0;
	for (Edge &e : edges) {
		int a = e.a;
		int b = e.b;
		int c = e.c;
		int addition = e.addition;
		bool is_special = e.is_special;
		if (f(a) == f(b)) continue;
		u(a, b);
		cnt++;
		if (is_special) s_cnt++;
		t_cost += c + addition;
		if (cnt == n-1) break;
	}
	if (cnt != n-1) return {-1, -1};
	return {s_cnt, t_cost};
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k, w;
	cin >> n >> m >> k >> w; 
	rt.resize(n);
	vector<bool> s_places(n);
	for (int i=0; i<k; ++i) {
		int s;
		cin >> s;
		s--;
		s_places[s] = true;
	}
	vector<Edge> edges;
	for (int i=0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		bool is_special = false;
		if ((s_places[a] && !s_places[b]) || (!s_places[a] && s_places[b])) {
			is_special = true;
		}
		edges.push_back({a, b, c, 0, is_special});
	}

	auto comp1 = [&](const Edge &A, const Edge &B) { 
		int Acost = A.c + A.addition;
		int Bcost = B.c + B.addition;
		if (Acost == Bcost) return A.is_special && !B.is_special; 
		return Acost < Bcost;
	};
	auto comp2 = [&](const Edge &A, const Edge &B) { 
		int Acost = A.c + A.addition;
		int Bcost = B.c + B.addition;
		if (Acost == Bcost) return B.is_special && !A.is_special;
		return Acost < Bcost;
	};
	int l = 0, r = 2e5+1;
	ll ans = -1; 
	while (l <= r) {
		int mid = (l+r)/2;
		int addition = mid-1e5;
		for (Edge &e : edges) {
			if (e.is_special) e.addition = addition;
		}
		sort(edges.begin(), edges.end(), comp1);
		pair<int,ll> result1 = kruskal(mid-1e5, edges, n);
	//	cerr << l << ' ' << r << ' ' << mid-1e5 << ' ' << 
	//		'{' << result1.first << ',' << result1.second << '}' << ' ' <<
	//		'{' << result2.first << ',' << result2.second << '}' << endl;
		
		if (result1.first == -1) break; 
		else if (result1.first < w) {
			r = mid-1;
		} else {
			sort(edges.begin(), edges.end(), comp2);
			pair<int,ll> result2 = kruskal(mid-1e5, edges, n); 
			if (result2.first > w) {
				l = mid+1;
			} else { 
				ans = result1.second - (mid-1e5)*w;
				break;
			}
		} 
	}
	cout << ans << endl;
	
	//cerr << l-1e5 << ' ' << result.first << ' ' << result.second << endl;
	//cerr << l << endl;
	return 0;
} 
