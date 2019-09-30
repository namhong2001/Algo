#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	if (K > (N-1)/2) {
		cout << -1;
		return 0;
	}
	cout << N*K << '\n';
	for (int i=0; i<N; ++i) {
		for (int j=1; j<=K; ++j) {
			cout << i+1 << ' ' << (i+j)%N+1 << '\n';
		}
	} 
	return 0;
}

