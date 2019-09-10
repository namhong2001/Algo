#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 987654321; 
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct Cell {
	int x, y, d;
};

int R, C;
bool inrange(int x, int y) {
	return 0<=x && x<R && 0<=y && y<C;
}

string board[51];
bool visited[51][51]; 
Cell bfs(int sx, int sy) {
	queue<Cell> q;
	q.push({sx, sy, 0}); 
	visited[sx][sy] = true;
	while (!q.empty()) {
		Cell here = q.front();
		q.pop();
		int x = here.x;
		int y = here.y;
		int d = here.d;
		for (int i=0; i<4; ++i) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (!inrange(nx, ny) || visited[nx][ny] || board[nx][ny] == 'W') continue;
			q.push({nx, ny, d+1});
			visited[nx][ny] = true;
		}
		if (q.empty()) return here;
	}
	return {-1, -1, -1}; // error;
}
			
int main() {
	cin >> R >> C;
	for (int i=0; i<R; ++i) cin >> board[i];
	int ans = 0;
	for (int i=0; i<R; ++i) {
		for (int j=0; j<C; ++j) {
			if (board[i][j] == 'L') {
				memset(visited, false, sizeof(visited));
				Cell leaf = bfs(i, j);
				ans = max(ans, leaf.d);
			}
		}
	}
	cout << ans; 
    return 0;
}

