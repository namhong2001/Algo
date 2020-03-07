#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int R, C;
vector<vector<bool>> checked;
vector<string> arr;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

pii getCnt(int x, int y) {
  if (x < 0 || x >= R || y < 0 || y >= C || checked[x][y] || arr[x][y] == '#') return {0, 0};
  checked[x][y] = true;
  pii ret = {0, 0};
  if (arr[x][y] == 'o') ret.first++;
  else if (arr[x][y] == 'v') ret.second++;
  for (int i=0; i<4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    pii c = getCnt(nx, ny);
    ret.first += c.first;
    ret.second += c.second;
  }
  return ret;
}

pii solve() {
  checked.assign(R, vector<bool>(C, false));
  pii ret = {0, 0};
  for (int i=0; i<R; ++i) for (int j=0; j<C; ++j) {
    if (!checked[i][j] && arr[i][j] != '#') {
      pii cnt = getCnt(i, j);
      // cerr << i << ' ' << j << ' ' << cnt.first << ' ' << cnt.second << endl;
      if (cnt.first > cnt.second) {
        ret.first += cnt.first;
      } else {
        ret.second += cnt.second;
      }
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> R >> C;
  arr.resize(R);
  for (int i=0; i<R; ++i) cin >> arr[i];
  pii ans = solve();
  cout << ans.first << ' ' << ans.second;
  return 0;
}