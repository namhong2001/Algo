#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

ll LIMIT = 1ll<<31; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K, N;
	cin >> K >> N;
	vector<ll> primes(K); 
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i=0; i<K; ++i) {
		cin >> primes[i];
		pq.push(primes[i]); 
	} 
	ll ans = 0;
	
	while (N) {
		ll cand = pq.top();
		pq.pop();
		if (ans == cand) continue;
		ans = cand; 
		N--;
		for (auto p : primes) {
			ll next = ans * p;
			if (next >= LIMIT) continue; 
			pq.push(next);
		}
	}
	cout << ans << endl;
	return 0;
} 
