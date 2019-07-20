#include <iostream> 
#include <cmath>
#include <map>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

const int LIMIT = (int)sqrt(1e9)+1;

bool isprime[LIMIT];
vector<int> primes;
void eratos() {
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i=2; i<=sqrt(LIMIT); ++i) {
		if (isprime[i]) {
			for (int j=i*i; j<LIMIT; j+=i) {
				isprime[j] = false;
			}
		}
	}
	for (int i=2; i<LIMIT; ++i) {
		if (isprime[i]) primes.push_back(i);
	}
} 

int gcd(int a, int b) {
	if (b > a) return gcd(b, a);
	return a%b == 0 ? b : gcd(b, a%b);
}

int main() { 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, K;
	eratos();
	while (cin >> N) {
		cin >> K;
		map<int,int> cnt;
		for (int p : primes) {
			if (K == 1) break;
			while (K%p == 0) {
				K/=p;
				cnt[p]++;
			}
		}
		cnt[K]++;
		int g = 1;
		for (auto item : cnt) {
			int p, c;
			tie(p, c) = item; 
			for (int i=p; i<=N; i+=p) { 
				int t = i;
				while (t%p == 0) {
					g *= p;
					t /= p;
					c--; 
					if (c == 0) break;
				}
				if (c == 0) break;
			}
		}
		cout << g << '\n';
	}
	return 0;
} 
