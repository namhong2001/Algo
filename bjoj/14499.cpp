#include <iostream>
#include <vector>

using namespace std;

struct Dice {
  int u=0, d=0, l=0, r=0, f=0, b=0;
  void move(int dir) {
    if (dir == 1) {
      int tmp = u;
      u = l;
      l = d;
      d = r;
      r = tmp;
    } else if (dir == 2) {
      int tmp = u;
      u = r;
      r = d;
      d = l;
      l = tmp;
    } else if (dir == 3) {
      int tmp = u;
      u = b;
      b = d;
      d = f;
      f = tmp;
    } else {
      int tmp = u;
      u = f;
      f = d;
      d = b;
      b = tmp;
    }
  }
};

const int dx[5] = {0, 0, 0, -1, 1};
const int dy[5] = {0, 1, -1, 0, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M, x, y, K;
  cin >> N >> M >> x >> y >> K;
  vector<vector<int>> board(N, vector<int>(M));
  Dice dice;
  for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) cin >> board[i][j];
  for (int i=0; i<K; ++i) {
    int d;
    cin >> d;
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
    x = nx;
    y = ny;
    dice.move(d);
    if (board[x][y] == 0) board[x][y] = dice.d;
    else {
      dice.d = board[x][y];
      board[x][y] = 0;
    }
    cout << dice.u << '\n';
  }
  return 0;
}