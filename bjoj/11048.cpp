#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> candy;

vector<vector<int>> d;
int solve(int x, int y) {
	if (x < 0 || y < 0) return 0;
	int &ret = d[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret = max({ret, solve(x-1, y), solve(x, y-1), solve(x-1, y-1)}) + candy[x][y];
	return ret;
} 

int main() {
	int N, M;
	cin >> N >> M;
	candy.assign(N, vector<int>(M, 0));
	d.assign(N, vector<int>(M, -1));
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			cin >> candy[i][j];
		}
	}
	cout << solve(N-1, M-1); 
	return 0;
}

