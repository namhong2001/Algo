#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
	int N, M;
	cin >> N >> M;
	int profit[N+1][M+1] = {};
	for (int i=1; i<=N; ++i) {
		for (int j=0; j<=M; ++j) {
			cin >> profit[i][j];
		}
	} 
	int foot[M+1][N+1] = {};
	int d[N+1] = {};
	for (int i=1; i<=M; ++i) {
		for (int j=N; j>0; --j) {
			for (int k=0; k<=j; ++k) {
				if (d[j-k] + profit[k][i] > d[j]) {
					d[j] = d[j-k] + profit[k][i];
					foot[i][j] = k;
				}
			}
		}
	} 
	cout << d[N] << '\n';
	int W = N;
	vector<int> footprint;
	for (int i=M; i>0; --i) {
		footprint.push_back(foot[i][W]); 
		W -= foot[i][W];
	}
	reverse(footprint.begin(), footprint.end());
	for (int f : footprint) {
		cout << f << ' ';
	}
	return 0;
}

