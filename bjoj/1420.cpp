#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int,int> pii;

const int INF = 10;

vector<string> board;
vector<vector<int>> adj;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0}; 

map<pii, int> capacity, flow;


int dfs(int here, int end, vector<bool> &visited, int cur_f) {
	if (here == end) return cur_f;
	visited[here] = true;
	for (int there : adj[here]) {
		if (visited[there]) continue;
		int residue = capacity[{here, there}] - flow[{here, there}];
		if (residue > 0) { 
			int f = dfs(there, end, visited, min(cur_f, residue));
			if (f > 0) {
				flow[{here, there}] += f;
				flow[{there, here}] -= f;
				return f;
			}
		}
	}
	return 0;
} 

int maxflow(int start, int end, int N) {
	int total = 0;
	while (true) { 
		vector<bool> visited(N, false);
		int f = dfs(start, end, visited, INF);
		if (f == 0) break;
		total += f;
	}
	if (total > 4) return -1;
	return total;
} 
	
int main() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		board.push_back(s);		
	}
	int N = n*m*2;
	adj.resize(N);
	auto inrange = [&](int x, int y) {
		return 0<=x && x<n && 0<=y && y<m;
	};
	auto out_id = [&](int x, int y) {
		return (x*m+y)*2+1;
	};
	auto in_id = [&](int x, int y) {
		return (x*m+y)*2;
	};
	int sx, sy, ex, ey;
	for (int x=0; x<n; ++x) {
		for (int y=0; y<m; ++y) {
			if (board[x][y] == '#') continue;
			if (board[x][y] == 'K') sx = x, sy = y;
			else if (board[x][y] == 'H') ex = x, ey = y;

			int hereout = out_id(x, y);	

			for (int k=0; k<4; ++k) { 
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (inrange(nx, ny) && board[nx][ny] != '#') {
					int therein = in_id(nx, ny);
					adj[hereout].push_back(therein);
					adj[therein].push_back(hereout);
					capacity[{hereout, therein}] = INF;
					capacity[{therein, hereout}] = 0;
					flow[{hereout, therein}] = 0;
					flow[{therein, hereout}] = 0;
				}
			}
		}
	}
	for (int x=0; x<n; ++x) {
		for (int y=0; y<m; ++y) {
			int in = in_id(x, y);
			int out = out_id(x, y);
			adj[in].push_back(out);
			adj[out].push_back(in);
			capacity[{in, out}] = 1;
			capacity[{out, in}] = 0;
			flow[{in, out}] = 0;
			flow[{out, in}] = 0;
		}
	}
	cout << maxflow(out_id(sx, sy), in_id(ex, ey), N) << endl;
	return 0;
} 
