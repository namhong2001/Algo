#include <iostream>
#include <vector>

using namespace std;

int N;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

bool dfs(int x, int y, vector<vector<bool>> &arr) {
  if (x < 0 || x >= N || y < 0 || y >= N) return false;
  if (arr[x][y]) return false;
  
  arr[x][y] = true;
  for (int i=0; i<4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    dfs(nx, ny, arr);
  }
  return true;
}

int safeZone(vector<vector<int>> &arr, int limit) {
  vector<vector<bool>> checked(N, vector<bool>(N, false));
  for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
    if (arr[i][j] <= limit) checked[i][j] = true;
  }
  int ans = 0;
  for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
    ans += dfs(i, j, checked);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> N;
  vector<vector<int>> arr(N, vector<int>(N));
  for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) cin >> arr[i][j];
  
  int ans = 0;
  for (int i=0; i<=100; ++i) {
    ans = max(ans, safeZone(arr, i));
  }
  cout << ans;
  return 0;
}