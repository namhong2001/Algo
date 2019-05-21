#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n+1, vector<int>(n+1, 0));
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			cin >> board[i][j];
		}
	}
	vector<vector<int>> psum(n+1, vector<int>(n+1, 0));
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + board[i][j];
		}
	}
	for (int i=0; i<m; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << psum[x2][y2] - psum[x2][y1-1] - psum[x1-1][y2] + psum[x1-1][y1-1] << '\n';
	}
	return 0;
} 
