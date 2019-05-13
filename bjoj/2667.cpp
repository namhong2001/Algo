#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int N_MAX = 25;

int n;
char arr[N_MAX][N_MAX+1];
bool visited[N_MAX][N_MAX];

int dfs(int x, int y) {
	visited[x][y] = true;
	int ret = 1;
	for (int i=0; i<4; ++i) {
		int next_x = x + direction[i][0];
		int next_y = y + direction[i][1];
		if (next_x < 0 ||  next_x >= n || next_y < 0 || next_y >= n) {
			continue;
		}
		if (arr[next_x][next_y] == '1' && !visited[next_x][next_y]) {
			ret += dfs(next_x, next_y);
		}
	}
	return ret;
}


vector<int> solve() {
	vector<int> ans;
	memset(visited, false, sizeof(visited));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (arr[i][j] == '1' && !visited[i][j]) {
				int count = dfs(i, j);
				ans.push_back(count);
			}
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> arr[i];
	}

	vector<int> ans = solve();
	cout << ans.size() << '\n';
	for (int count : ans) {
		cout << count << '\n';
	}

	return 0;
}
