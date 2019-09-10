#include <iostream>

using namespace std;

int main() {
	int N, T;
	cin >> N >> T;
	int d[T+1] = {};
	for (int i=1; i<=N; ++i) {
		int k, s;
		cin >> k >> s;
		for (int j=T; j>=k; --j) {
			d[j] = max(d[j], d[j-k] + s);
		} 
	}
	cout << d[T]; 
	return 0;
}

