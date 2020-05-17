#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

typedef vector<pii> vp;
typedef vector<vp> vvp;

vvp conn;

struct order {
  int id, others;
  bool operator < (const order &rhs) {
    return this->others < rhs.others;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    int C, D;
    cin >> C >> D;
    conn = vvp(C);
    vector<order> orders;
    for (int i=1; i<C; ++i) {
      int x;
      cin >> x;
      orders.push_back({i, -x});
    }
    sort(orders.begin(), orders.end());
    for (int i=0; i<D; ++i) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      conn[u].push_back({v, i});
      conn[v].push_back({u, i});
    }
    int ptime = 0;
    vector<int> time(C);
    vector<bool> checked(C);
    vector<int> targets;
    vector<int> ans(D);
    int others = 0;
    checked[0] = true;
    time[0] = 0;
    for (int i=0; i<C-1; ++i) {
      order &o = orders[i];
      if (o.others != others) {
        ptime++;
        others = o.others;
      }
      time[o.id] = ptime;
    }
    
    for (int u=0; u<C; ++u) {
      for (auto &co : conn[u]) {
        int v = co.first;
        int ith = co.second;
        ans[ith] = abs(time[u] - time[v]);
        if (ans[ith] == 0) ans[ith] = 1;
      }
    }
    cout << "Case #" << t << ": ";
    for (auto a : ans) {
      cout << a << ' ';
    }
    cout << '\n';
  }
  return 0;
}