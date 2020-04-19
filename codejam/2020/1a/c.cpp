#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef map<int,int> mii;
typedef vector<mii> vmii;
typedef pair<int,int> pii;

typedef long long ll;

int R, C;

ll compete(vmii &row, vmii &col) {
  ll ret = 0;
  for (int i=0; i<R; ++i) {
    for (auto r : row[i]) {
      ret += r.second;
    }
  }
  vector<pii> removes;

  for (int i=0; i<R; ++i) {
    for (auto it = row[i].begin(); it!=row[i].end(); ++it) {
      int j = it->first;
      int me = 0;
      int compass = 0;
      if (it != row[i].begin()) {
        me += it->second;
        compass += prev(it)->second;
      }
      if (it != prev(row[i].end())) {
        me += it->second;
        compass += next(it)->second;
      }
      auto colIt = col[j].find(i);
      if (colIt != col[j].begin()) {
        me += colIt->second;
        compass += prev(colIt)->second;
      }
      if (colIt != prev(col[j].end())) {
        me += colIt->second;
        compass += next(colIt)->second;
      }
      if (me < compass) {
        removes.push_back({i, j});
      }
    }
  }
  for (auto &remove : removes) {
    int i = remove.first;
    int j = remove.second;
    row[i].erase(j);
    col[j].erase(i);
  }
  if (!removes.empty()) return ret + compete(row, col);
  else return ret;
}

ll solve() {
  vmii row(R); // j, val
  vmii col(C); // i, val
  for (int i=0; i<R; ++i) for (int j=0; j<C; ++j) {
    int val;
    cin >> val;
    row[i][j] = val;
    col[j][i] = val;
  }
  return compete(row, col);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    cin >> R >> C;
    ll ans = solve();
    cout << "Case #" << t << ": " << ans << '\n';
  }

  return 0;
}