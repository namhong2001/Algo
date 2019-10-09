#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

int solve(ll A, ll B, int N, ll K) {
	if (N == 1) return A;
	if (N == 2) return B;
	for (int i=0; i<N-2; ++i) {
		ll next = B + K * A;
		next %= MOD;
		swap(A, B);
		B = next;
	}
	return B;
}


int main() {
	int N, A, B, K;
	cin >> N >> A >> B >> K;
	cout << solve(A, B, N, K); 
    return 0;
}

