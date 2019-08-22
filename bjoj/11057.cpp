#include <iostream>

using namespace std; 

const int MOD = 10007;

int d[10][1001];
int solve(int prev, int remain) {
	if (remain == 0) return 1;
	if (d[prev][remain]) return d[prev][remain];
	int &ret = d[prev][remain];
	for (int i=prev; i<=9; ++i) {
		ret += solve(i, remain-1);
		ret %= MOD;
	}
	return ret;
}
	
int main() {
	int N;
	cin >> N;
	cout << solve(0, N) << endl; 
	return 0;
}

