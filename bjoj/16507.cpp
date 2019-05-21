#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int r, c, q;
	cin >> r >> c >> q;
	vector<vector<int>> board(r+1, vector<int>(c+1, 0));
	for (int i=1; i<=r; ++i) {
		for (int j=1; j<=c; ++j) {
			cin >> board[i][j];
		}
	}
	vector<vector<int>> psum(r+1, vector<int>(c+1, 0));
	for (int i=1; i<=r; ++i) {
		for (int j=1; j<=c; ++j) {
			psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + board[i][j];
		}
	}
	for (int i=0; i<q; ++i) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		cout << (psum[r2][c2] - psum[r1-1][c2] - psum[r2][c1-1] + psum[r1-1][c1-1]) / ((r2-r1+1)*(c2-c1+1)) << '\n';
	}
	return 0;
} 
