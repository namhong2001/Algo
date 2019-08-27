#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

typedef pair<int,int> pii;
vector<vector<int>> cost;
vector<vector<int>> board; 
int N; 
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int id) {
	board[x][y] = id;
	for (int i=0; i<4; ++i) { 
		int nx = x+dx[i];
		int ny = y+dy[i];
		if (0<=nx && nx<N && 0<=ny && ny<N && board[nx][ny] == 1) dfs(nx, ny, id); 
	}
} 

void make_comp() {
	int order = 2;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			if (board[i][j] == 1) dfs(i, j, order++);
		}
	}
}

bool check_connect(int x, int y) {
	for (int i=0; i<4; ++i) { 
		int nx = x+dx[i];
		int ny = y+dy[i];
		if (0<=nx && nx<N && 0<=ny && ny<N && board[nx][ny] && board[nx][ny] != board[x][y]) return true;
	}
	return false;
}
	

int solve() {
	make_comp();
	queue<pii> q;
	int ret = INF;
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			if (board[i][j] == 0) {
				for (int k=0; k<4; ++k) { 
					int nx = i+dx[k];
					int ny = j+dy[k]; 
					if (0<=nx && nx<N && 0<=ny && ny<N && board[nx][ny] && cost[nx][ny] == 0) {
						cost[i][j] = 1;
						board[i][j] = board[nx][ny];
						q.emplace(i, j);
					} 
				}
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i=0; i<4; ++i) { 
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (0<=nx && nx<N && 0<=ny && ny<N && board[nx][ny] == 0) {
				board[nx][ny] = board[x][y];
				cost[nx][ny] = cost[x][y]+1;
				q.emplace(nx, ny);
			}
		}
	}
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			for (int k=0; k<4; ++k) {
				int nx = i+dx[k];
				int ny = j+dy[k]; 
				if (0<=nx && nx<N && 0<=ny && ny<N && board[nx][ny] != board[i][j]) {
					ret = min(ret, cost[nx][ny]+cost[i][j]); 
				} 
			}
		}
	}
	return ret;
} 

int main() {
	cin >> N;
	board.assign(N, vector<int>(N));
	cost.assign(N, vector<int>(N, 0));
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			cin >> board[i][j];
		}
	} 
	cout << solve(); 
	return 0;
}

