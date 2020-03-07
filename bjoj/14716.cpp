#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int M, N;
vii arr;

vii checked;

const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

void oneChar(int x, int y) {
  if (x < 0 || x >= M || y < 0 || y >= N || !arr[x][y] || checked[x][y]) return;
  checked[x][y] = true;
  for (int i=0; i<8; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    oneChar(nx, ny);
  }
}

int solve() {
  checked.assign(M, vi(N, 0));
  int ret = 0;
  for (int i=0; i<M; ++i) for (int j=0; j<N; ++j) {
    if (!checked[i][j] && arr[i][j]) {
      ret++;
      oneChar(i, j);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> M >> N;
  arr.assign(M, vi(N));
  for (int i=0; i<M; ++i) for (int j=0; j<N; ++j) cin >> arr[i][j];
  cout << solve();
  return 0;
}