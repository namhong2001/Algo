#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b > a) return gcd(b, a);
	return a%b == 0 ? b : gcd(b, a%b);
}

int main() {
	int N, M; 
	cin >> N >> M; 
	if (N == 1) { 
		ll a;
		cin >> a;
		cout << "YES" << endl;
		cout << a << ' ' << 1 << endl;
		return 0;
	} 
	ll start;
	ll prev = -1;
	ll interval = -1; 
	for (int i=0; i<N; ++i) {
		ll a;
		cin >> a;
		if (i == 0) start = a;
		if (prev != -1) {
			ll gap = a - prev;
			if (interval == -1) {
				interval = gap;
			} else {
				interval = gcd(interval, gap);
			} 
		}
		prev = a;
	}
	for (int i=0; i<M; ++i) {
		ll p;
		cin >> p;
		if (interval % p == 0) {
			cout << "YES" << endl;
			cout << start << ' ' << i+1 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
