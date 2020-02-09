#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

vii board;
viii dp;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int dxx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dyy[8] = {-1, 1, -2, 2, 2, -2, 1, -1};

int K, W, H;
struct item {
  int x, y, k, cnt;
};

bool canGo(int x, int y, int k, int cnt) {
  if (x < 0 || x >= H || y < 0 || y >= W ||
       k > K || board[x][y] == 1 || dp[x][y][k] == 1) return false;
  return true;
}

int solve() {
  if (W == 1 && H == 1) return 0;
  queue<item> q;
  q.push({0, 0, 0, 0});
  while (!q.empty()) {
    item cur = q.front();
    q.pop();
    int x = cur.x;
    int y = cur.y;
    int k = cur.k;
    int cnt = cur.cnt;
    for (int i=0; i<8; ++i) {
      int nx = x+dxx[i];
      int ny = y+dyy[i];
      if (canGo(nx, ny, k+1, cnt+1)) {
        if (nx == H-1 && ny == W-1) return cnt+1;
        dp[nx][ny][k+1] = 1;
        q.push({nx, ny, k+1, cnt+1});
      }
    }
    for (int i=0; i<4; ++i) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (canGo(nx, ny, k, cnt+1)) {
        if (nx == H-1 && ny == W-1) return cnt+1;
        dp[nx][ny][k] = 1;
        q.push({nx, ny, k, cnt+1});
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> K >> W >> H;
  dp.assign(H, vii(W, vi(K+1, 0)));
  board.resize(H, vi(W));
  for (int i=0; i<H; ++i) {
    for (int j=0; j<W; ++j) {
      cin >> board[i][j];
    }
  }
  cout << solve();
  return 0;
}