#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int coins[N+1] = {};
		for (int i=1; i<=N; ++i) { 
			cin >> coins[i];
		} 
		int M;
		cin >> M;
		int d[M+1] = {};
		d[0] = 1;
		for (int i=1; i<=N; ++i) {
			int c = coins[i];
			for (int j=M; j>=0; --j) {
				for (int k=1; k*c<=j; ++k) {
					d[j] += d[j-k*c];
				}
			}
		}
		cout << d[M] << '\n';
	} 
	return 0;
}

