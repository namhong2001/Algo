#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};



int H, W;
vector<string> board;
vector<pii> spoints; 
vector<bool> haskey(26); 
int ans;
bool has_moved;

bool in_range(int x, int y) {
	return 0<=x && x<H && 0<=y && y<W;
} 

void dfs(int x, int y, vector<pii> &next) {
	if (board[x][y] == '*') return;
	if ('A' <= board[x][y] && board[x][y] <= 'Z' && !haskey[board[x][y]-'A']) {
		next.emplace_back(x, y);
		return;
	}
	if ('a' <= board[x][y] && board[x][y] <= 'z') {
		haskey[board[x][y]-'a'] = true;
	}
	if (board[x][y] == '$') ans++; 
	board[x][y] = '*';
	has_moved = true;
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (in_range(nx, ny)) dfs(nx, ny, next);
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) { 
		cin >> H >> W; 
		board.resize(H);
		spoints.clear();
		haskey.assign(26, false);
		for (int i=0; i<H; ++i) {
			cin >> board[i];
			if (i==0 || i==H-1) {
				for (int j=0; j<W; ++j) {
					if (board[i][j] != '*') spoints.push_back({i, j});
				}
			} else {
				if (board[i][0] != '*') spoints.push_back({i, 0});
				if (board[i][W-1] != '*') spoints.push_back({i, W-1});
			}
		}
		string keys; 
		cin >> keys;
		if (keys[0] != '0') {
			for (char key : keys) {
				haskey[key-'a'] = true;
			} 
		}
		ans = 0; 
		has_moved = false;
		while (true) { 
			vector<pii> next;
			has_moved = false;
			for (auto p : spoints) {
				dfs(p.first, p.second, next);
			} 
			if (!has_moved) break;
			swap(spoints, next); 
		}
		cout << ans << '\n';
	}
	return 0;
} 
