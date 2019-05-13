#include <iostream>
#include <vector>

using namespace std;

const int direction[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void dfs(vector<vector<bool>> &arr, vector<vector<bool>> &visited, int x, int y) {
	visited[x][y] = true;
	for (int i=0; i<4; ++i) {
		int n_x = x + direction[i][0];
		int n_y = y + direction[i][1];
		if (n_x < 0 || n_y < 0 || n_x >= arr.size() || n_y >= arr[0].size()) continue;
		
		if (arr[n_x][n_y] && !visited[n_x][n_y]) {
			dfs(arr, visited, n_x, n_y);
		}
	}
}

	

int solve(vector<vector<bool>> &arr, vector<vector<bool>> &visited) {
	int ret = 0;
	for (int i=0; i<arr.size(); ++i) {
		for (int j=0; j<arr[0].size(); ++j) {
			if (arr[i][j] && !visited[i][j]) {
				dfs(arr, visited, i, j);
				++ret;
			}
		}
	}
	return ret;
}
	



int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, k;
		cin >> m >> n >> k;
		vector<vector<bool>> arr(m, vector<bool>(n, false));
		vector<vector<bool>> visited(m, vector<bool>(n, false));

		for (int i=0; i<k; ++i) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = true;
		}
		cout << solve(arr, visited) << '\n';
	}

	return 0;
}
