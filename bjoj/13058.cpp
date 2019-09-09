#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll max(const ll &a, const ll &b) {
	return a > b ? a : b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	int N, K;
	cin >> N >> K;
	vector<ll> S(N+1);
	vector<ll> V(N+1);
	for (int i=1; i<=N; ++i) {
		cin >> S[i] >> V[i];
	}
	vector<ll> d(K+1);
	for (int i=1; i<=N; ++i) {
		ll s = S[i];
		ll v = V[i];
		for (int j=K; j>=s; --j) {
			d[j] = max(d[j], d[j-s] + v);
		}
	}
	for (int i=1; i<=K; ++i) cout << d[i] << ' '; 
	return 0;
}

