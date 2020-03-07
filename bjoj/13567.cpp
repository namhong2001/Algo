#include <iostream>

using namespace std;

struct Pos {
  int x, y, d;
};

const int dx[4] = {1, 0, -1, 0}; // right, down, left, up
const int dy[4] = {0, -1, 0, 1};

bool isValid(int x, int y, int M) {
  return 0 <= x && x <= M && 0 <= y && y <= M;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int M, N;
  cin >> M >> N;
  Pos pos = {0, 0, 0};
  while (N--) {
    string s;
    int n;
    cin >> s >> n;
    if (s == "MOVE") {
      pos.x += dx[pos.d] * n;
      pos.y += dy[pos.d] * n;
    } else if (s == "TURN") {
      pos.d = (pos.d + (n == 1 ? 1 : -1) + 4) % 4;
    }
    if (!isValid(pos.x, pos.y, M)) {
      cout << -1;
      return 0;
    }
  }
  cout << pos.x << ' ' << pos.y;
  return 0;
}