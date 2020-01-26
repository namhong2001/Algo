#include <iostream>
#include <vector>

using namespace std;

struct shark {
  int r = 0, c = 0, s = 0, d = 0, z = 0;
  bool isNull() {return d == 0;};
};

typedef vector<vector<shark>> vvs;
typedef vector<shark> vs;

int R, C, M;

int opd(int d) {
  if (d == 1) return 2;
  if (d == 2) return 1;
  if (d == 3) return 4;
  if (d == 4) return 3;
}

shark move(shark ss) {
  int r = ss.r;
  int c = ss.c;
  int s = ss.s;
  int d = ss.d;
  int z = ss.z;
  if (d == 1 || d == 2) {
    s %= (R-1) * 2;
    while (s > 0) {
      if (d == 1) {
        int x = min(s, r-1);
        s -= x;
        r -= x;
        if (r == 1) d = 2;
      } else {
        int x = min(s, R - r);
        s -= x;
        r += x;
        if (r == R) d = 1;
      }
    }
  } else {
    s %= (C-1) * 2;
    while (s > 0) {
      if (d == 4) {
        int x = min(s, c-1);
        s -= x;
        c -= x;
        if (c == 1) d = 3;
      } else {
        int x = min(s, C - c);
        s -= x;
        c += x;
        if (c == C) d = 4;
      }
    }
  }
  return {r, c, ss.s, d, z};
}

vvs turn(vvs &board) {
  vvs ret = vvs(R+1, vs(C+1));
  for (int i=1; i<=R; ++i) for (int j=1; j<=C; ++j) {
    if (board[i][j].isNull()) continue;
    shark ns = move(board[i][j]);
    if (ret[ns.r][ns.c].isNull() || ret[ns.r][ns.c].z < ns.z) {
      ret[ns.r][ns.c] = ns;
    }
  }
  for (int i=1; i<=R; ++i) for (int j=1; j<=C; ++j) {
    if (ret[i][j].isNull()) continue;
    // cerr << i << ' ' << j << ' ' << ret[i][j].d  << ' ' << ret[i][j].z << endl;
  }
  // cerr << endl;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> R >> C >> M;
  vvs board = vvs(R+1, vs(C+1));
  for (int i=0; i<M; ++i) {
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    board[r][c] = {r, c, s, d, z};
  }
  int ans = 0;
  for (int j=1; j<=C; ++j) {
    for (int i=1; i<=R; ++i) {
      if (!board[i][j].isNull()) {
        // cerr << i << ' ' << j << ' ' << board[i][j].z << endl;
        ans += board[i][j].z;
        board[i][j] = {};
        break;
      }
    }
    board = turn(board);
  }
  cout << ans;
  return 0;
}