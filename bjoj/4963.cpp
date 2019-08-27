#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int W, H;

void dfs(int h, int w, vector<vector<bool>> &visited) {
	visited[h][w] = true;
	for (int dh=-1; dh<=1; ++dh) {
		for (int dw=-1; dw<=1; ++dw) { 
			if (dh == 0 && dw == 0) continue;
			int nh = h + dh;
			int nw = w + dw; 
			if (0 <= nh && nh < H && 0 <= nw && nw < W && board[nh][nw] == 1 && !visited[nh][nw]) {
				dfs(nh, nw, visited);
			}
		}
	}
} 

int solve() {
	int ret = 0;
	vector<vector<bool>> visited(H, vector<bool>(W, false)); 
	for (int i=0; i<H; ++i) {
		for (int j=0; j<W; ++j) {
			if (board[i][j] == 1 && !visited[i][j]) {
				dfs(i, j, visited);
				ret++;
			}
		}
	}
	return ret;
} 

int main() {
	while (cin >> W >> H) {
		if (W == 0 && H == 0) break; 
		board.assign(H, vector<int>(W));
		for (int i=0; i<H; ++i) {
			for (int j=0; j<W; ++j) {
				cin >> board[i][j];
			}
		}
		cout << solve() << '\n';
	} 
	return 0;
}

