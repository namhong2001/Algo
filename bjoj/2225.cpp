#include <iostream>

using namespace std;

const int MOD = 1e9;

int N, K; 
int d[201][201];
int solve(int sum, int remain) { 
	if (remain == 0) {
		if (sum == 0) return 1;
		else return 0;
	} 
	if (d[sum][remain]) return d[sum][remain];
	int &ret = d[sum][remain];
	for (int i=0; i<=sum; ++i) {
		ret += solve(sum-i, remain-1);
		ret %= MOD;
	}
	return ret;
} 

int main() {
	cin >> N >> K;
	cout << solve(N, K) << endl; 
	return 0;
}

