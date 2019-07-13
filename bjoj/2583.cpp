#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int main() {
	int R, C, K;
	cin >> R >> C >> K;
	int board[100][100] = {};
	for (int i=0; i<K; ++i) { 
		int sx, sy, ex, ey; 
		cin >> sy >> sx >> ey >> ex;
		for (int x=sx; x<ex; ++x) {
			for (int y=sy; y<ey; ++y) {
				board[x][y] = true;
			}
		}
	}
	auto inrange = [&](const int x, const int y) {
		return 0<=x && x<R && 0<=y && y<C;
	};
	function<int(int,int)> dfs = [&](int x, int y) {
		if (board[x][y]) return 0;
		int ret = 0;
		board[x][y] = true;
		ret++;
		
		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inrange(nx, ny)) ret += dfs(nx, ny);
		}
		return ret;
	};
	vector<int> ans;
	for (int i=0; i<R; ++i) {
		for (int j=0; j<C; ++j) {
			if (!board[i][j]) {
				ans.push_back(dfs(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int a : ans) {
		cout << a << ' ';
	}
	return 0; 
} 
