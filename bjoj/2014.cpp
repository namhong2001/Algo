#include <iostream>
#include <vector>
#include <queue>
#include <set>

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
	set<ll> has;
	ll pq_max = 0;
	ll ans = 0; 
	for (int i=0; i<K; ++i) {
		cin >> primes[i];
		pq.push(primes[i]); 
		has.insert(primes[i]); 
		pq_max = max(pq_max, primes[i]);
	} 
	while (N) {
		ans = pq.top();
		pq.pop();
		N--;
		for (auto p : primes) {
			ll next = ans * p; 
			if (next > LIMIT) break;
			if ((ll)pq.size() > N && next > pq_max) break; 
			if (has.find(next) != has.end()) continue;
			pq.push(next);
			has.insert(next);
			pq_max = max(pq_max, next);
		}
	}
	cout << ans << endl;
	return 0;
} 

