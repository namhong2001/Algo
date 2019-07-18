#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

const int LIMIT = 1e6;

bool isprime[LIMIT];
vector<ll> primes;
void eratos() {
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i=2; i<=sqrt(LIMIT); ++i) {
		if (isprime[i]) {
			for (int j=i+i; j<LIMIT; j+=i) {
				isprime[j] = false;
			}
		}
	} 
	for (int i=2; i<LIMIT; ++i) {
		if (isprime[i]) {
			primes.push_back(i);
		}
	}
}


int main() {
	eratos();
	ll mmin, mmax;
	cin >> mmin >> mmax;
	bool isans[LIMIT+1];
	memset(isans, true, sizeof(isans)); 
	for (ll p : primes) {
		ll pp = p*p; 
		if (pp > mmax) break;
		ll s = mmin/pp*pp;
		if (s < mmin) s+=pp;
		while (s <= mmax) {
			isans[s-mmin] = false;
			//cerr << pp << ' ' << s << endl;
			s+=pp;
		}
	}
	int cnt = 0;
	for (int i=0; i<=mmax-mmin; ++i) {
		if (isans[i]) cnt++;
	}
	cout << cnt << endl;
	return 0;
} 
