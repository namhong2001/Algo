#include <iostream>
#include <vector>

using namespace std;

const int INF = 100;

vector<string> board(8); 

int steps(int x, int y, int row) { 
	int i = x, j = y;
	int add = row < i ? -1 : 1;
	while (i != row) {
		i += add;
		if (board[i][j] != '.') return INF;
	}
	return abs(row-x);
}

int min_steps(char pawn, int row) {
	int ret = INF;
	for (int i=0; i<8; ++i) {
		for (int j=0; j<8; ++j) {
			if (board[i][j] == pawn) {
				ret = min(ret, steps(i, j, row));
			}
		}
	}
	return ret;
} 

int main() {
	for (int i=0; i<8; ++i) cin >> board[i];
	int w_min = INF;
	int b_min = INF;
	for (int i=0; i<8; ++i) {
		for (int j=0; j<8; ++j) {
			if (board[i][j] == 'B') b_min = min(b_min, min_steps('B', 7));
			else if (board[i][j] == 'W') w_min = min(w_min, min_steps('W', 0));
		}
	}
	if (w_min <= b_min) cout << "A";
	else cout << "B"; 
	return 0;
}

