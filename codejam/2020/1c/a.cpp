#include <iostream>

using namespace std;

bool canGo(int x, int y, int walk) {
  return abs(x) + abs(y) <= walk;
}

string solve(int x, int y, string m) {
  for (int i = 0; i < m.size(); ++i) {
    char d = m[i];
    if (canGo(x, y, i)) return to_string(i);
    if (d == 'S') y--;
    else if (d == 'N') y++;
    else if (d == 'W') x--;
    else if (d == 'E') x++;
  }
  if (canGo(x, y, m.size())) return to_string(m.size());
  return "IMPOSSIBLE";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    int x, y;
    string m;
    cin >> x >> y >> m;
    cout << "Case #" << t << ": " << solve(x, y, m) << '\n';
  }
  return 0;
}