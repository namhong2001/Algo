#include <iostream>
#include <vector>
#include <cmath>
#include <map> 

using namespace std;

typedef long long ll;

const int LIMIT = 1e6+1;

ll gcd(ll a, ll b) {
	if (a<b) return gcd(b, a);
	return a%b == 0 ? b : gcd(b, a%b);
}

vector<int> primes;
vector<bool> isprime;
void eratos(int limit) {
    primes.clear();
    isprime.assign(limit, true);
    isprime[0] = isprime[1] = false;
    for (int i=2; i<=sqrt(limit); ++i) {
        if (!isprime[i]) continue;
        for (int j=i+i; j<limit; j+=i) {
            isprime[j] = false;
        }
    }
    for (int i=2; i<limit; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
	eratos(LIMIT);
	int N;
	cin >> N; 
	ll g;
	for (int i=0; i<N; ++i) { 
		ll a;
		cin >> a;
		if (i == 0) g = a;
		else g = gcd(g, a);
	}
	map<ll,ll> cnt;
	for (ll p : primes) {
		while (g % p == 0) {
			g /= p;
			cnt[p]++;
		}
	}
	if (g > 1) {
		cnt[g]++;
	} 
	ll ret = 1;
	for (auto c : cnt) {
		ret *= c.second+1;
	} 
	cout << ret << endl;
	return 0;
}
