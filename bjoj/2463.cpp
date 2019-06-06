#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std; 

typedef tuple<int,int,int> tiii;
typedef long long ll;
const ll MOD = 1e9;

vector<int> r;
vector<int> r_cnt;
int f(int a) {
	return r[a] = a == r[a] ? a : f(r[a]);
}

void u(int a, int b) {
	a = f(a), b = f(b);
	r[a] = b;
	r_cnt[b] += r_cnt[a];
	r_cnt[a] = 0;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<tiii> edges;
	r.resize(n+1);
	r_cnt.assign(n+1, 1);
	for (int i=0; i<n+1; ++i) r[i] = i; 
	ll w_sum = 0;
	for (int i=0; i<m; ++i) {
		int x, y, w;
		cin >> x >> y >> w; 
		edges.push_back({w, x, y}); 
		w_sum += w;
	}
	sort(edges.begin(), edges.end(), greater<tiii>());
	ll ans = 0; 
	ll cur_sum = 0;
	for (tiii &edge : edges) {
		int x, y, w;
		tie(w, x, y) = edge;
		if (f(x) != f(y)) {
			ans += (w_sum - cur_sum) * r_cnt[f(x)] * r_cnt[f(y)];
			ans %= MOD; 
			u(x, y);
		}
		cur_sum += w; 
	}
	cout << ans << endl;
	return 0;
}

