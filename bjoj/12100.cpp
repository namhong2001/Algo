#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> State; 

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1}; 
int N; 

State move(State &state, int type) {
	vector<vector<bool>> merged(N, vector<bool>(N, false));
	int s, e, inc;
	if (type == 0 || type == 1) {
		s = N-1;
		e = -1;
		inc = -1;
	} else {
		s = 0;
		e = N;
		inc = 1;
	} 
	auto in_range = [](int x, int y) {
		return 0<=x && x<N && 0<=y && y<N;
	};
	State ret = state;
	for (int i=s; i!=e; i+=inc) {
		for (int j=s; j!=e; j+=inc) {
			if (ret[i][j] == 0) continue;
			int x = i;
			int y = j;
			while (true) {
				int nx = x+dx[type];
				int ny = y+dy[type];
				if (!in_range(nx, ny)) break;
				if (ret[nx][ny] == 0) {
					ret[nx][ny] = ret[x][y];
					ret[x][y] = 0;
					x = nx;
					y = ny;
				} else if (ret[nx][ny] == ret[x][y] && !merged[nx][ny]) {
					ret[nx][ny] += ret[x][y];
					merged[nx][ny] = true;
					ret[x][y] = 0;
					break;
				} else {
					break;
				}
			}
		}
	}
	return ret;
} 

int ans = 0;

void solve(State here, int cnt) { 
	if (cnt == 5) {
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				ans = max(ans, here[i][j]);
			}
		}
		return;
	} 
	for (int type=0; type<4; ++type) {
		solve(move(here, type), cnt+1);
	}
} 

int main() {
	cin >> N; 
	State is;
	is.assign(N, vector<int>(N));
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			cin >> is[i][j];
		}
	}
	solve(is, 0); 
	cout << ans;
	return 0;
} 
