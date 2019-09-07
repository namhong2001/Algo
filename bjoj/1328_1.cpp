#include <iostream>
#include <cstring>


using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll d[101][101][101];
ll solve(int N, int L, int R) {
	if (L == 0 || R == 0 || N < L+R-1 || N < L || N < R) return 0;
	if (min(L, R) == 1 && max(L, R) == N) return 1;
	ll &ret = d[N][L][R];
	if (ret != -1) return ret;
	ret = solve(N-1, L-1, R) + solve(N-1, L, R-1) + solve(N-1, L, R) * (N-2);
	ret %= MOD;
	return ret;
} 

int main() {
	int N, L, R;
	memset(d, -1, sizeof(d));
	cin >> N >> L >> R;
	cout << solve(N, L, R); 
	return 0;
}

