#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
int N;

bool dfs(int x, int y, vector<string> &arr, vector<vector<bool>> &checked, char C) {
  if (x < 0 || x >= N || y < 0 || y >= N) return false;
  if (checked[x][y]) return false;
  if (arr[x][y] != C) return false;

  checked[x][y] = true;
  for (int i=0; i<4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    dfs(nx, ny, arr, checked, C);
  }
  return true;
}

int components(vector<string> &arr) {
  vector<vector<bool>> checked(N, vector<bool>(N, false));
  int ret = 0;
  for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
    ret += dfs(i, j, arr, checked, arr[i][j]);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> N;

  vector<string> arr(N);
  for (int i=0; i<N; ++i) cin >> arr[i];
  vector<string> arr2 = arr;
  for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
    if (arr2[i][j] == 'G') arr2[i][j] = 'R';
  }
  cout << components(arr) << ' ' << components(arr2);
  return 0;
}