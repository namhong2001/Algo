#include <iostream>
#include <numeric>

using namespace std;

int main() {
	int C, D, M;
	cin >> C >> D >> M;
	int price[C+1][D+1] = {};
	for (int i=1; i<=C; ++i) {
		for (int j=1; j<=D; ++j) {
			cin >> price[i][j];
		}
	}
	for (int day=1; day<D; ++day) {
		int v[C+1] = {};
		int p[C+1] = {};
		int d[M+1] = {}; 
		iota(d, d+M+1, 0);
		for (int i=1; i<=C; ++i) v[i] = price[i][day+1]; 
		for (int i=1; i<=C; ++i) p[i] = price[i][day]; 
		for (int m=0; m<=M; ++m) {
			for (int i=1; i<=C; ++i) {
				int next = m+p[i];
				if (next <= M) d[next] = max(d[next], d[m]+v[i]);
			}
		}
		M = d[M];
	}
	cout << M; 
	return 0;
}

