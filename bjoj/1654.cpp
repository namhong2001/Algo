#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll get_cnt(ll sz, vector<ll> &arr) {
	ll cnt = 0;
	for (ll a : arr) {
		cnt += a/sz;
	}
	return cnt;
}



int main() {
	int k, n;
	cin >> k >> n;
	vector<ll> len(k);
	for (int i=0; i<k; ++i) {
		cin >> len[i];
	}
	ll l=0, r=(1ll<<31);
	while (l+1<r) {
		ll mid = (l+r)/2;
		if (get_cnt(mid, len) >= n) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << endl;
	return 0;
}
