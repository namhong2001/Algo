#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int N_MAX = 25;


int dfs(vector<vector<char>> &arr, vector<vector<bool>> &visited, int x, int y) {
	int n = arr.size();
	visited[x][y] = true;
	int ret = 1;
	for (int i=0; i<4; ++i) {
		int next_x = x + direction[i][0];
		int next_y = y + direction[i][1];
		if (next_x < 0 ||  next_x >= n || next_y < 0 || next_y >= n) {
			continue;
		}
		if (arr[next_x][next_y] == '1' && !visited[next_x][next_y]) {
			ret += dfs(arr, visited, next_x, next_y);
		}
	}
	return ret;
}


vector<int> solve(vector<vector<char>> &arr, vector<vector<bool>> &visited) {
	int n = arr.size();
	vector<int> ans;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (arr[i][j] == '1' && !visited[i][j]) {
				int count = dfs(arr, visited, i, j);
				ans.push_back(count);
			}
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<vector<char>> arr(n, vector<char>(n));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		arr[i] = vector<char>(s.begin(), s.end());
	}

	vector<int> ans = solve(arr, visited);
	cout << ans.size() << '\n';
	for (int count : ans) {
		cout << count << '\n';
	}

	return 0;
}
