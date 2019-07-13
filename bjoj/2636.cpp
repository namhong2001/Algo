#include <iostream>
#include <vector>
#include <functional>

using namespace std;

vector<vector<bool>> pre, cur;

int R, C;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

bool melt() {
	cur = pre;
	vector<vector<bool>> visited(R, vector<bool>(C, false)); 
	
	auto inrange = [&](const int x, const int y) {
		return 0<=x && x<R && 0<=y && y<C;
	};
	function<bool(int, int)> dfs = [&](int x, int y) { 
		if (visited[x][y]) return false; 

		visited[x][y] = true;
		if (cur[x][y]) {
			cur[x][y] = false;
			return true;
		}
		bool ret = false;
		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!inrange(nx, ny)) continue;
			ret = dfs(x+dx[i], y+dy[i]) || ret;
		} 
		return ret;
	};

	bool ret = false;
	for (int i=0; i<R; ++i) {
		if (i == 0 || i == R-1) {
			for (int j=0; j<C; ++j) {
				ret = dfs(i, j) || ret;
			}
		} else {
			ret = dfs(i, 0) || ret;
			ret = dfs(i, C-1) || ret;
		}
	}
	return ret;
} 

int cheese_cnt(vector<vector<bool>> &arr) {
	int cnt = 0;
	for (int i=0; i<R; ++i) {
		for (int j=0; j<C; ++j) {
			cnt += arr[i][j];
		}
	}
	return cnt;
} 

int main() {
	cin >> R >> C;
	pre = cur = vector<vector<bool>>(R, vector<bool>(C));
	for (int i=0; i<R; ++i) {
		for (int j=0; j<C; ++j) {
			int a;
			cin >> a;
			pre[i][j] = (bool)a;
		}
	}
	int melt_cnt = 0;
	int cheese = 0; 
	while (melt()) {
		melt_cnt++;
		cheese = cheese_cnt(pre);
		swap(pre, cur); 
	}
	cout << melt_cnt << '\n' << cheese << '\n';
	return 0;
} 
