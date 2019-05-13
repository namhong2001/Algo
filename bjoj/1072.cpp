#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int get_percent(ll a, ll b) {
	return a*100/b;
} 

int main() {
	int x, y;
	cin >> x >> y;
	int p = get_percent(y, x);
	const ll R = 1e11;
	ll l = 0, r = R;
	// get upper_bound
	while (l<r) {
		ll mid = (l+r)/2;
		if (get_percent(y+mid, x+mid) <= p) {
			l = mid+1;
		} else {
			r = mid;
		}
	}
	if (l == R) cout << -1 << endl;
	else cout << l << endl;
	return 0;
} 
