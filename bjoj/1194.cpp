#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 987654321;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

vector<string> board; 

struct q_item {
	int x, y, step, status;
}; 

int main() {
	int n, m;
	cin >> n >> m;
	board.resize(n);
	pair<int,int> start;
	for (int i=0; i<n; ++i) {
		cin >> board[i];
		for (int j=0; j<m; ++j) {
			if(board[i][j] == '0') {
				start = {i,j};
			}
		}
	}
	int d[n][m][1<<6];
	memset(d, -1, sizeof(d)); 

	auto can_go = [&](int x, int y, int status) {
		if (x<0 || x>=n || y<0 || y>=m) return false;
		if (board[x][y] == '#') return false;
		int keynum = board[x][y]-'A';
		if (keynum < 0 || keynum > 5) return true; // no requred key
		return (bool)(status & 1<<keynum);
	};

	auto get_new_status = [&](int x, int y, int status) {
		int keynum = board[x][y]-'a';
		if (keynum < 0 || keynum > 5) return status; // no aquired key
		return status | 1<<keynum;
	};

	queue<q_item> q;
	q.push({start.first, start.second, 0, 0}); 
	int ans = -1;
	while (!q.empty()) {
		q_item here = q.front();
		q.pop();
		int x = here.x;
		int y = here.y; 
		int step = here.step;
		int status = here.status;
		if (board[x][y] == '1') {
			ans = step;
			break;
		}
		for (int i=0; i<4; ++i) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (can_go(nx, ny, status)) { 
				int n_status = get_new_status(nx, ny, status); 
				int n_step = step+1;
				if (d[nx][ny][n_status] == -1) {
					d[nx][ny][n_status] = n_step;
					q.push({nx, ny, n_step, n_status});
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
