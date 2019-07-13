#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int N;
vector<ll> arr;

ll func(ll x) {
	ll dist = 0;
	for (int i=0; i<(int)arr.size(); ++i) {
		dist += abs(i*x - arr[i]);
	}
	return dist;
}

int main() {
	cin >> N;
	arr.resize(N);
	for (int i=0; i<N; ++i) {
		cin >> arr[i];
	} 
	ll l = 0, r = arr[N-1];
	while (l+2<r) {
		ll a = (2*l+r)/3;
		ll b = (l+2*r)/3;
		if (func(a) > func(b)) {
			l = a;
		} else {
			r = b;
		}
	} 
	cout << func((l+r)/2) << endl;
	return 0;
} 
