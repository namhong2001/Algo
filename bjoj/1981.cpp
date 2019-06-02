#include <iostream>
#include <vector>

using namespace std; 


const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0}; 

vector<vector<int>> board;
vector<vector<bool>> visited;
int n;

bool dfs(int x, int y, int mn, int mx) {
	if (x<0 || x>=n || y<0 || y>=n) return false; 
	if (board[x][y] < mn || board[x][y] > mx) return false;
	if (visited[x][y]) return false; 
	if (x == n-1 && y == n-1) return true;
	visited[x][y] = true; 
	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (dfs(nx, ny, mn, mx)) return true;
	}
	return false;
} 

int main() {
	cin >> n;
	board.assign(n, vector<int>(n));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> board[i][j];
		}
	} 
	int mx = max(board[0][0], board[n-1][n-1]);
	int mn = min(board[0][0], board[n-1][n-1]);
	int ans = 200;
	for (int i=0; i<201; ++i) { 
		int l = 0, r = 201;
		while (l < r) {
			int mid = (l+r)/2;
			visited.assign(n, vector<bool>(n, false)); 
			if (!dfs(0, 0, mn-mid, mx+i)) {
				l = mid + 1;
			} else {
				r = mid;
			}
		} 
		if (l == 201) continue;
		ans = min(ans, mx+i - (mn-l)); 
	} 
	cout << ans << endl;
	return 0;
} 
