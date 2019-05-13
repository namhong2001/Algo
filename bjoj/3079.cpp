#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;


vector<ll> ptimes;
ll pass_cnt(ll limit) {
	ll cnt = 0;
	for (ll ptime : ptimes) {
		cnt += limit/ptime;
	}
	return cnt;
} 

int main() {
	int n, m;
	cin >> n >> m;
	ptimes.resize(n);
	for (int i=0; i<n; ++i) {
		cin >> ptimes[i];
	}
	ll l = 0, r = 1e18+1;
	while (l < r) {
		ll mid = (l+r)/2;
		if (pass_cnt(mid) < m) {
			l = mid+1;
		} else {
			r = mid;
		}
	}
	cout << l;
	return 0;
} 
