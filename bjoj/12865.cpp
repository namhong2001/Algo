#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	int N, K;
	cin >> N >> K;
	int d[K+1] = {};
	for (int i=1; i<=N; ++i) {
		int w, v;
		cin >> w >> v;
		for (int j=K; j>=w; --j) d[j] = max(d[j], d[j-w] + v);
	}
	cout << d[K]; 
	return 0;
}

