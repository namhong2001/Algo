#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int,int> pii;
typedef tuple<int,int,int> item;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int N;
int board[50][50];
bool visited[50][50]; 
queue<item> q;

bool inrange(int x, int y) { 
	return 0<=x && x<N && 0<=y && y<N;
}

void dfs(int x, int y, int num) {
	visited[x][y] = true;
	board[x][y] = num;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inrange(nx, ny) && !visited[nx][ny]) {
			if (board[nx][ny] == -1) {
				q.emplace(nx, ny, num+1);
			} else if (board[nx][ny] == 0) {
				dfs(nx, ny, num);
			}
		}
	}
}

int solve() {
	q.emplace(0, 0, 0);
	while (!q.empty()) {
		item here = q.front();
		q.pop();
		int x, y, num;
		tie(x, y, num) = here;
		if (!visited[x][y]) {
			dfs(x, y, num);
		}
	}
	return board[N-1][N-1];
} 

int main() {
	cin >> N;
	for (int i=0; i<N; ++i) {
		string s;
		cin >> s; 
		for (int j=0; j<N; ++j) {
			board[i][j] = s[j] - '0' - 1;
		}
	}
	cout << solve() << endl;
	return 0;
} 
