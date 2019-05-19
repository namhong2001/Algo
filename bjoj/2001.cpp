#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

typedef tuple<int,int,int> ti;

vector<int> r;
int f(int a) {
	return r[a] = a == r[a] ? a : f(r[a]);
}
void u(int a, int b) {
	a = f(a), b = f(b);
	r[a] = b;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> gem(n, 0);
	r.resize(n);
	for (int i=0; i<n; ++i) r[i] = i;
	for (int i=0; i<k; ++i) {
		int a;
		cin >> a;
		a--;
		gem[a] = 1;
	}
	vector<ti> edges;
	for (int i=0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edges.push_back({-c, a, b});
	}
	sort(edges.begin(), edges.end());
	int ans = max(0, gem[0]);
	for (ti &e: edges) {
		int a, b, c;
		tie(c, a, b) = e;
		c = -c;
		u(a, b); 
		int gem_cnt = 0;
		for (int i=0; i<n; ++i) { 
			if (f(i) == f(0)) gem_cnt += gem[i];
		}
		ans = max(ans, min(gem_cnt, c));
	}
	cout << ans << endl;
	return 0;
}


			




	


	


