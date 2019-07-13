#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e6+1;
const int d[3] = {-1, 0, 1};

typedef pair<int,int> pii;
set<pii> targets;

int N; 
int board[50][50];

bool inrange(int x, int y) {
	return 0<=x && x<N && 0<=y && y<N; 
};

bool validate(int x, int y, int mmin, int mmax) {
	return inrange(x, y) && mmin <= board[x][y] && board[x][y] <= mmax;
}; 

int dfs(int x, int y, bool visited[50][50], int mmin, int mmax) {
	visited[x][y] = true; 
	int ret = 0;
	if (targets.find({x, y}) != targets.end()) ret++;
	for (int i=0; i<3; ++i) {
		int nx = x + d[i];
		for (int j=0; j<3; ++j) { 
			int ny = y + d[j]; 
			if (validate(nx, ny, mmin, mmax) && !visited[nx][ny]) {
				ret += dfs(nx, ny, visited, mmin, mmax);
			}
		}
	}
	return ret;
};

bool decision(int mmin, int mmax) {
	int sx = targets.begin()->first;
	int sy = targets.begin()->second;
	if (board[sx][sy] < mmin || board[sx][sy] > mmax) return false; 
	bool visited[50][50] = {};
	return dfs(sx, sy, visited, mmin, mmax) == (int)targets.size();
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	vector<int> heights;
	for (int i=0; i<N; ++i) {
		string s;
		cin >> s; 
		for (int j=0; j<N; ++j) {
			if (s[j] == 'K' || s[j] == 'P') targets.emplace(i, j);
		}
	}
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			cin >> board[i][j];
			heights.push_back(board[i][j]);
		} 
	} 
	sort(heights.begin(), heights.end());
	int l = 0, r = 0;
	int ans = INF;
	while (!decision(heights[l], heights[r])) {
		r++;
	} 
	while (r < (int)heights.size()) {
		while (l <= r && decision(heights[l], heights[r])) {
			l++;
		}
		l--;
		ans = min(ans, heights[r]-heights[l]);
		r++;
	} 
	cout << ans << endl;
	return 0;
} 
