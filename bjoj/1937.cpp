#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> d;
int N;

bool in_range(int x, int y) {
	return x>=0 && x<N && y>=0 && y<N;
} 

int solve(int x, int y) {
	int &ret = d[x][y];
	if (ret != -1) return ret;
	ret = 1;
	const int dx[4] = {0, 0, -1, 1};
	const int dy[4] = {-1, 1, 0, 0};
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in_range(nx, ny) && board[nx][ny] > board[x][y]) {
			ret = max(ret, 1 + solve(nx, ny));
		}
	}
	return ret;
} 

int main() {
	cin >> N;
	board.assign(N, vector<int>(N));
	d.assign(N, vector<int>(N, -1));
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			cin >> board[i][j];
		}
	}
	int ans = 0;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			ans = max(ans, solve(i, j));
		}
	}
	cout << ans; 
    return 0;
}

