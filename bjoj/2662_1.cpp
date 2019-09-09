#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std; 

const int INF = 987654321;

int N, M;
int d[21][301];
int profit[21][301];
int step[21][301];
int solve(int ith, int W) {
	if (W < 0) return -INF;
	if (ith == 0) return 0;
	int &ret = d[ith][W];
	if (ret != -1) return ret;
	for (int v=0; v<=N; ++v) { 
		int cur = profit[ith][v] + solve(ith-1, W-v);
		if (cur > ret) {
			ret = cur;
			step[ith][W] = v;
		}
	} 
	return ret;
}

void make_path(int ith, int W, vector<int> &path) {
	if (ith == 0) return;
	path.push_back(step[ith][W]);
	make_path(ith-1, W-step[ith][W], path);
}

int main() {
	memset(d, -1, sizeof(d));
	cin >> N >> M;
	for (int i=1; i<=N; ++i) {
		for (int j=0; j<=M; ++j) {
			cin >> profit[j][i];
		}
	} 
	cout << solve(M, N) << '\n';
	vector<int> path;
	make_path(M, N, path);
	reverse(path.begin(), path.end());
	for (int p : path) {
		cout << p << ' ';
	}
	return 0;
}

