#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int C, R, K;
  cin >> C >> R >> K;
  if (K > C*R) {
    cout << 0;
    return 0;
  }
  vector<vector<bool>> board(C, vector<bool>(R, false)); 
  int x=0, y=0, dir=0;
  for (int i=0; i<K-1; ++i) {
    board[x][y] = true;
    while (true) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= C || ny < 0 || ny >= R || board[nx][ny]) {
        dir = (dir+1) % 4;
      } else {
        x = nx;
        y = ny;
        break;
      }
    }
  }
  cout << x+1 << ' ' << y+1;
  return 0;
}