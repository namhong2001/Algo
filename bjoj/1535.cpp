#include <iostream>
#include <cstring>


using namespace std;

const int INF = 987654321;

int joy[21];
int hp[21];
int d[21][101];
int solve(int ith, int W) {
	if (W < 0) return -INF;
	if (ith == 0) return 0; 
	int &ret = d[ith][W];
	if (ret != -1) return ret;
	return ret = max(solve(ith-1, W), solve(ith-1, W-hp[ith]) + joy[ith]);
}

int main() {
	memset(d, -1, sizeof(d));
	int N;
	cin >> N;
	for (int i=1; i<=N; ++i) {
		cin >> hp[i];
	}
	for (int i=1; i<=N; ++i) {
		cin >> joy[i];
	}
	cout << solve(N, 99); 
	return 0;
}

