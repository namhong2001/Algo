#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9+7;
const int NMAX = 3e5+2;

int N;
int A[NMAX];
int S[NMAX];
int E[NMAX];
int d[NMAX];
int dpsum[NMAX]; 

int solve() {
	for (int i=1; i<=N; ++i) {
		d[i] = A[i];
		int s = S[i];
		int e = E[i];
		int bonus = dpsum[e] - dpsum[s-1];
		if (bonus < 0) bonus += MOD;
		d[i] += bonus;
		d[i] %= MOD;
		dpsum[i] = dpsum[i-1] + d[i];
		dpsum[i] %= MOD;
	}
	int ret = 0;
	for (int i=1; i<=N; ++i) {
		ret += d[i];
		ret %= MOD;
	}
	return ret;
} 

int main() {
	cin >> N;
	for (int i=1; i<=N; ++i) {
		cin >> A[i];
	}
	for (int i=1; i<=N; ++i) {
		cin >> S[i] >> E[i];
	} 
	cout << solve(); 
    return 0;
}

