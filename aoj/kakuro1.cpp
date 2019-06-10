#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int,int,int> tiii; 

vector<tiii> find_horizontal_hint(vector<vector<int>> &board) {
	int n = board.size(); 
	vector<tiii> ret;
	for (int i=0; i<n; ++i) {
		int sum = 0;
		for (int j=n-1; j>=0; --j) {
			if (board[i][j] == 0) {
				if (sum == 0) continue;
				ret.emplace_back(i+1, j+1, sum);
				sum = 0;
			} else {
				sum += board[i][j];
			}
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

vector<tiii> find_vertical_hint(vector<vector<int>> &board) {
	int n = board.size(); 
	vector<tiii> ret;
	for (int i=0; i<n; ++i) {
		int sum = 0; 
		for (int j=n-1; j>=0; --j) {
			if (board[j][i] == 0) {
				if (sum == 0) continue;
				ret.emplace_back(j+1, i+1, sum);
				sum = 0;
			} else {
				sum += board[j][i];
			}
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
} 

int main() {
	int T;
	cin >> T;
	cout << T << endl;
	while (T--) {
		int n;
		cin >> n;
		cout << n << endl;
		vector<vector<int>> board(n, vector<int>(n));
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				cin >> board[i][j];
				cout << (board[i][j] ? 1: 0) << ' ';
			}
			cout << endl;
		}
		vector<tiii> horizontal_hint = find_horizontal_hint(board);
		vector<tiii> vertical_hint = find_vertical_hint(board);
		int cnt = horizontal_hint.size() + vertical_hint.size();
		cout << cnt << endl;
		for (tiii &hh : horizontal_hint) {
			int y, x, sum;
			tie(y, x, sum) = hh;
			cout << y << ' ' << x << ' ' << '0' << ' ' << sum << endl;
		}
		for (tiii &vh : vertical_hint) {
			int y, x, sum;
			tie(y, x, sum) = vh;
			cout << y << ' ' << x << ' ' << '1' << ' ' << sum << endl;
		}
	}
	return 0;
} 
