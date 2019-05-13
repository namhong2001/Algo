#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> gems;

ll get_cnt(ll limit) {
	ll cnt = 0;
	for (ll gem : gems) { 
		cnt += gem/limit;
		if (gem%limit) cnt++;
	}
	return cnt;
} 

int main() { 
	int n, m;
	cin >> n >> m;
	gems.resize(m); 
	for (int i=0; i<m; ++i) {
		cin >> gems[i];
	}
	ll l = 0, r = 1e9+1;
	while (l < r) {
		ll mid = (l+r)/2;
		if (get_cnt(mid) > n) {
			l = mid+1;
		} else {
			r = mid;
		}
	}
	cout << l << endl;
	return 0;
} 
