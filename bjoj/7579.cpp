#include <iostream>

using namespace std;

const int C = 10000; 

int main() {
	int N, M;
	cin >> N >> M;
	int m[N+1];
	int c[N+1];
	for (int i=1; i<=N; ++i) cin >> m[i];
	for (int i=1; i<=N; ++i) cin >> c[i];
	int d[C+1] = {};
	for (int i=1; i<=N; ++i) {
		int mm = m[i];
		int cc = c[i]; 
		for (int j=C; j>=cc; --j) {
			d[j] = max(d[j], d[j-cc] + mm);
		}
	}
	for (int i=0; i<=C; ++i) {
		if (d[i] >= M) {
			cout << i;
			return 0;
		}
	} 
	return 0;
}

