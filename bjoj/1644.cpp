#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

vector<int> gen_primes(int n) {
	bool is_prime[n+1]; 
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i=2; i<=sqrt(n); ++i) {
		if (!is_prime[i]) continue;
		for (int j=i+i; j<=n; j+=i) {
			is_prime[j] = false;
		}
	}
	vector<int> primes;
	for (int i=2; i<=n; ++i) {
		if (is_prime[i]) primes.push_back(i);
	}
	return primes;
} 

int main() {
	int n;
	cin >> n;
	vector<int> primes = gen_primes(n);
	int sum = 0;
	int left = 0;
	int ans = 0;
	for (int i=0; i<(int)primes.size(); ++i) {
		sum += primes[i];
		while (sum > n && left <= i) {
			sum -= primes[left++];
		}
		if (sum == n) ans++;
	}
	cout << ans;
	return 0;
} 
