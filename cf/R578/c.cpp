#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b>a) return gcd(b, a);
	return a%b == 0 ? b : gcd(b, a%b);
}

int main() {
	ll N, M, Q;
	cin >> N >> M >> Q;
	ll G = gcd(N, M);
	for (ll i=0; i<Q; ++i) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		y1--;
		y2--;
		ll a, b;
		if (x1 == 1) {
			a = y1/(N/G);
		} else {
			a = y1/(M/G);
		}

		if (x2 == 1) { 
			b = y2/(N/G);
		} else {
			b = y2/(M/G);
		}
		if (a == b) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		} 
	} 
	return 0;
}

