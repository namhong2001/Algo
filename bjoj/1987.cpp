#include <iostream>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

string board[20]; 
int R, C;

int solve(int x, int y, int state) { 
	int ret = 0;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i]; 
		if (nx<0 || nx>=R || ny<0 || ny>=C || state & 1<<(board[nx][ny]-'A')) continue;
		ret = max(ret, solve(nx, ny, state | 1<<(board[nx][ny]-'A')));
	}
	ret += 1;
	return ret;
} 

int main() {
	cin >> R >> C;
	for (int i=0; i<R; ++i) {
		cin >> board[i];
	}
	cout << solve(0, 0, 1<<(board[0][0]-'A'));
	return 0;
} 
