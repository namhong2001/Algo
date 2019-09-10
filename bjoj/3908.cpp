#include <iostream>

using namespace std;

bool is_prime(int num) {
	for (int i=2; i<num; ++i) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	int d[1121][15] = {};
	d[0][0] = 1;
	for (int i=2; i<=1120; ++i) {
		if (!is_prime(i)) continue;
		for (int k=14; k>=1; --k) { 
			for (int n=1120; n>=i; --n) {
				d[n][k] += d[n-i][k-1];
			}
		}
	}
	while (T--) {
		int N, K; 
		cin >> N >> K;
		cout << d[N][K] << '\n';
	} 
	return 0;
}

