#include <iostream>

using namespace std;

const int MOD = 10007; 
int d[1001];

int solve(int N) {
	if (d[N]) return d[N];
	int &ret = d[N];
	if (N == 1) return 1;
	if (N == 2) return 2; 
	return ret = (solve(N-1)+solve(N-2)) % MOD;
	return 0;
}

int main() {
	int N;
	cin >> N;
	cout << solve(N); 
	return 0;
}

