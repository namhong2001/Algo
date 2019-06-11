#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

typedef tuple<int,int,int> tiii;

int board[9][9];
int row_cand[9];
int col_cand[9];
int box_cand[9]; 

int box_id(int x, int y) {
	return x/3*3 + y/3;
}

int get_cand(int x, int y) {
	return row_cand[x] & col_cand[y] & box_cand[box_id(x, y)];
}

vector<tiii> order;

bool solve(int ith) {
	if (ith == (int)order.size()) return true;
	int cnt, x, y;
	tie(cnt, x, y) = order[ith];
	int cand = get_cand(x, y); 
	for (int i=0; i<9; ++i) {
		if (cand & 1<<i) {
			row_cand[x] &= ~(1<<i);
			col_cand[y] &= ~(1<<i);
			box_cand[box_id(x, y)] &= ~(1<<i); 

			board[x][y] = i;
			if (solve(ith+1)) return true;
			board[x][y] = -1; 

			row_cand[x] |= 1<<i;
			col_cand[y] |= 1<<i;
			box_cand[box_id(x, y)] |= 1<<i; 
		}
	}
	return false;
} 

int main() {
	for (int i=0; i<9; ++i) {
		for (int j=0; j<9; ++j) {
			cin >> board[i][j];
			--board[i][j];
		}
	}
	for (int i=0; i<9; ++i) {
		row_cand[i] = (1<<9)-1;
		col_cand[i] = (1<<9)-1;
		box_cand[i] = (1<<9)-1;
	} 
	for (int i=0; i<9; ++i) {
		for (int j=0; j<9; ++j) {
			if (board[i][j] == -1) continue;
			row_cand[i] &= ~(1<<board[i][j]);
			col_cand[j] &= ~(1<<board[i][j]); 
			box_cand[box_id(i, j)] &= ~(1<<board[i][j]); 
		}
	}
	for (int i=0; i<9; ++i) {
		for (int j=0; j<9; ++j) {
			if (board[i][j] != -1) continue;
			order.push_back({__builtin_popcount(get_cand(i,j)), i, j}); 
		}
	}
	sort(order.begin(), order.end());
	solve(0);
	for (int i=0; i<9; ++i) {
		for (int j=0; j<9; ++j) {
			cout << board[i][j]+1 << ' ';
		}
		cout << '\n';
	}
	return 0;
} 
