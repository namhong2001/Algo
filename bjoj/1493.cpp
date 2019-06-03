#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std; 

typedef long long ll; 

vector<ll> need_cnt(21, 0);
vector<ll> cube_cnt(21, 0);

void cal_need(int l, int w, int h) {
	if (l == 0 || w == 0 || h == 0) return;
	int m = min({l, w, h});
	int ith = log2(m);
	int cube = pow(2, ith);
	ll cnt = 1ll * (l/cube) * (w/cube) * (h/cube);
	need_cnt[ith] += cnt;

	cal_need(l%cube, w, h);
	cal_need(l-l%cube, w%cube, h);
	cal_need(l-l%cube, w-w%cube, h%cube);
}


int solve() {
	ll ret = 0;
	for (int i=20; i>=0; --i) {
		ret += min(need_cnt[i], cube_cnt[i]);
		ll remain = need_cnt[i] - cube_cnt[i]; 
		if (remain > 0) {
			if (i == 0) return -1;
			else need_cnt[i-1] += 8*remain;
		}
	}
	return ret; 
} 

int main() {
	int l, w, h, n;
	cin >> l >> w >> h >> n; 
	for (int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		cube_cnt[a] += b;
	}
	cal_need(l, w, h);
	cout << solve() << endl;
	return 0;
} 
