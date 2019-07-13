#include <iostream>
#include <queue>
#include <functional>
#include <set>
#include <iterator>

using namespace std;

typedef pair<int,int> Coord;


const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int board[300][300]; 
int rate[300][300];
set<Coord> ice; 

int main() {
	int N, M;
	cin >> N >> M; 
	auto in_range = [&](int x, int y) {
		return 0<=x && x<N && 0<=y && y<M;
	};
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) { 
			cin >> board[i][j];
			if (board[i][j] > 0) {
				ice.emplace(i, j);
			} else {
				for (int k=0; k<4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (in_range(nx, ny)) {
						rate[nx][ny]++;
					}
				}
			} 
		}
	} 

	auto check_departed = [&](int sx, int sy) {
		bool visited[300][300] = {};
		function<int(int,int)> dfs = [&](int x, int y) {
			visited[x][y] = true;
			int ret = 1;
			for (int i=0; i<4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (board[nx][ny] > 0 && !visited[nx][ny]) ret += dfs(nx, ny);
			}
			return ret;
		};
		return (int)ice.size() != dfs(sx, sy);
	};
	
	int time = 0;
	bool has_answer = false;
	while (!ice.empty()) {
		/*
		for (int i=0; i<N; ++i) {
			for (int j=0; j<M; ++j) {
				cerr << board[i][j] << ' ';
			}
			cerr << endl;
		}
		cerr << endl;
		*/
		if (check_departed(ice.begin()->first, ice.begin()->second)) { 
			has_answer = true;
			break;
		}
		for (auto &p : ice) {
			int x, y;
			tie(x,y) = p;
			board[x][y] -= rate[x][y];
			if (board[x][y] < 0) board[x][y] = 0; 
		}
		
		for (auto it = ice.begin(); it != ice.end(); ) {
			int x, y;
			tie(x,y) = *it;
			if (board[x][y] == 0) {
				for (int k=0; k<4; ++k) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					rate[nx][ny]++;
				} 
				it = ice.erase(it);
			} else {
				it++;
			}
		}
		time++;
	} 
	if (has_answer) {
		cout << time << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
} 
