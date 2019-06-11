#include <iostream>

using namespace std;

const int INF = 9876543;
int weight[10][10];
int d[1<<10][10];
int n;

int solve(int state, int here) {
	int &ret = d[state][here];
	if (ret != 0) return ret;
	if (state == (1<<n)-1) return ret = weight[here][0];
	ret = INF;
	for (int i=0; i<n; ++i) {
		if (state & 1<<i) continue;
		ret = min(ret, weight[here][i] + solve(state|1<<i, i));
	}
	return ret;
} 

int main() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> weight[i][j];
			if (weight[i][j] == 0) weight[i][j] = INF;
		}
	}
	cout << solve(1, 0);
	return 0;
}

