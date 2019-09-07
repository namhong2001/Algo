#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll d_comb[101][101]; 
ll comb(int n, int m) {
	if (n <= 1) return 1;
	if (m == 0) return 1;
	if (n == m) return 1;
	ll &ret = d_comb[n][m];
	if (ret != -1) return ret;
	ret = comb(n-1, m-1) + comb(n-1, m);
	ret %= MOD;
	return ret;
} 


ll d[101][101]; // d[N][int_cnt] 
ll d_fact[101]; 

ll factorial(int N) {
	if (N == 0) return 1;
	ll &ret = d_fact[N];
	if (ret != -1) return ret;
	return ret = factorial(N-1) * N % MOD;
}

ll solve(int N, int inc) { // always N >= inc, inc > 0
	if (inc == 0) {
		if (N == 0) return 1;
		else return 0;
	}
	if (inc == N) return 1;
	if (inc == 1) return factorial(N-1);
	ll &ret = d[N][inc];
	if (ret != -1) return ret;
	ret = 0;
	for (int i=inc-1; i<N; ++i) {
		ll cases = solve(i, inc-1) * factorial(N-1-i) % MOD;
		cases = cases * comb(N-1, i) % MOD;
		ret += cases;
		ret %= MOD;
	}
	return ret;
} 

int main() {
	memset(d, -1, sizeof(d));
	memset(d_comb, -1, sizeof(d_comb));
	memset(d_fact, -1, sizeof(d_fact));
	int N, L, R;
	cin >> N >> L >> R;
	ll ans = 0;
	for (int n=L-1; n<=N-R; ++n) {
		ll cases = solve(n, L-1)*solve(N-n-1, R-1) % MOD;
		cases = cases * comb(N-1, n) % MOD;
		ans += cases;
		ans %= MOD;
	}
	cout << ans; 
	return 0;
} 
