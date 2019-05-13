#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

vector<vector<int>> adj;
vector<int> bmatch;
vector<vector<int>> dist;

bool dfs(int here, vector<bool> &visited, int limit) {
	if (visited[here]) return false;
	visited[here] = true;
	for (int there : adj[here]) {
		if (dist[here][there] > limit) continue;
		if (bmatch[there] == -1 || dfs(bmatch[there], visited, limit)) {
			bmatch[there] = here;
			return true;
		}
	}
	return false;
}

int R, C;
int CCNT, PCNT;

int bipmatch(int limit) {
	bmatch.assign(PCNT, -1);
	int cnt = 0;
	for (int i=0; i<CCNT; ++i) {
		vector<bool> visited(CCNT, false);
		cnt += dfs(i, visited, limit);
	}
	return cnt;
}

vector<vector<int>> cal_d(vector<string> &board, pii &c) {
	const int dx[4] = {0, 0, 1, -1};
	const int dy[4] = {1, -1, 0, 0};

	auto inrange = [&](int x, int y) {
		return 0<=x && x<R && 0<=y && y<C;
	};

	vector<vector<int>> ret(R, vector<int>(C, -1));
	ret[c.first][c.second] = 0;
	queue<pii> q;
	q.push(c);
	while (!q.empty()) {
		pii here = q.front();
		q.pop();
		int x = here.first;
		int y = here.second;
		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inrange(nx, ny) && board[nx][ny] != 'X' && ret[nx][ny] == -1) {
				ret[nx][ny] = ret[x][y]+1;
				q.push({nx, ny});
			}
		}
	}
	return ret;
} 

int main() {
	cin >> R >> C;
	vector<string> board(R);
	vector<pii> cars;
	vector<pii> parks;
	for (int i=0; i<R; ++i) {
		cin >> board[i];
		for (int j=0; j<C; ++j) {
			if (board[i][j] == 'C') cars.push_back({i, j});
			else if (board[i][j] == 'P') parks.push_back({i, j});
		}
	}
	CCNT = cars.size();
	PCNT = parks.size();
	//cerr << CCNT << ' ' << PCNT << endl;
	adj.clear();
	adj.resize(CCNT);
	dist.assign(CCNT, vector<int>(PCNT, -1));
	for (int i=0; i<CCNT; ++i) {
		const vector<vector<int>> &d = cal_d(board, cars[i]);	
		for (int j=0; j<PCNT; ++j) {
			pii &park = parks[j];
			if (d[park.first][park.second] > 0) {
				adj[i].push_back(j);
				dist[i][j] = d[park.first][park.second];
				//cerr << i << ' ' << j << ' ' << dist[i][j] << endl;
			}
		}
	}
	vector<int> time(2500);
	for (int i=0; i<2500; ++i) time[i] = i;
	auto it = lower_bound(time.begin(), time.end(), CCNT, [](int limit, int ccnt) {
			return bipmatch(limit) < ccnt;});
	if (it == time.end()) cout << -1 << endl;
	else cout << *it << endl;
	return 0;
} 
