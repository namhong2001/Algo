#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (a<b) return gcd(b, a);
	return a%b == 0 ? b : gcd(b, a%b);
}

ll comb3(ll a) {
	if (a < 3) return 0;
	if (a == 3) return 1; 
	return a*(a-1)*(a-2)/3/2;
} 

ll odds(ll a) {
	if (a < 3) return 0;
	if (a == 3) return 1;
	ll half = a/2; 
	return a * half - half*(half+1);
} 

ll hyp(ll N, ll M) { 
	ll ret = 0;
	for (ll i=2; i<N; ++i) {
		for (ll j=2; j<M; ++j) { 
			ll g = gcd(i, j);
			ll dots = g - 1;
			if (dots <= 0) continue;
			ret += (N-i)*(M-j)*dots; 
		}
	} 
	return ret*2;
} 

int main() {
	ll N, M;
	cin >> N >> M;
	N++, M++;
	cout << comb3(N*M) - comb3(N)*M - comb3(M)*N - hyp(N, M) << endl; 
	return 0;
}

