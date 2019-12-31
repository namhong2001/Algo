#include <iostream>
#include <vector>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> arr(N+2, vector<int>(N+2, -1));
  for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j) arr[i][j] = 0;

  int x=1, y=1;
  int val = N*N;
  int dir = 0;
  while (val) {
    arr[x][y] = val--;
    if (arr[x+dx[dir]][y+dy[dir]] != 0) dir = (dir+1) % 4;
    x += dx[dir];
    y += dy[dir];
  }
  for (int j=1; j<=N; ++j) {
    for (int i=1; i<=N; ++i) {
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
  int K;
  cin >> K;
  for (int j=1; j<=N; ++j) {
    for (int i=1; i<=N; ++i) {
      if (arr[i][j] == K) cout << j << ' ' << i;
    }
  }
  
  return 0;
}