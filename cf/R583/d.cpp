#include <iostream>
#include <vector>

using namespace std;


vector<string> board;
int N, M;


vector<vector<bool>> visited;
bool dfs(int r, int c) { 
	if (r >= N || c >= M) return false;
	if (visited[r][c] || board[r][c] == '#') return false;
	if (r == N-1 && c == M-1) return true; 
	visited[r][c] = true;
	if (dfs(r+1, c) || dfs(r, c+1)) {
		if (!(r == 0 && c == 0)) board[r][c] = '#';
		return true;
	}
	return false;
}

int solve() {
	int ret = 0;
	for (int i=0; i<2; ++i) { 
		visited = vector<vector<bool>>(N, vector<bool>(M, false));
		if (dfs(0, 0)) ret++;
		else break;
	}
	return ret;
} 

int main() {
	cin >> N >> M;
	board.resize(N); 
	for (int i=0; i<N; ++i) cin >> board[i];
	cout << solve(); 
	return 0;
}

