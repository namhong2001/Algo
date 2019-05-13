#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, k;

ll get_cnt(ll num) {
	ll ret = 0;
	for (int i=1; i<=n; ++i) {
		ret += min(num/i, n);
	}
	return ret;
}

int main() {
	cin >> n >> k;
	ll l = 1;
	ll r = n*n;
	while (l < r) {
		ll mid = (l+r)/2;
		if (get_cnt(mid) < k) {
			l = mid+1;
		} else {
			r = mid;
		}
	}
	cout << l << endl;
	return 0;
} 
