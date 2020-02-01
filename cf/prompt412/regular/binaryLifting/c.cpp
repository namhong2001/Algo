#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<int> job(N);
  for (int i=0; i<N; ++i) cin >> job[i];
  set<int> checker;
  vector<vector<ll>> st(N, vector<ll>(17));
  int s=0, e=0;
  while (s<N) {
    if (checker.find(job[e]) != checker.end()) {
      st[s][0] = checker.size();
      checker.erase(job[s]);
      s++;
    } else {
      checker.insert(job[e]);
      e++;
      e %= N;
    }
  }
  for (int j=1; j<17; ++j) for (int i=0; i<N; ++i) {
    st[i][j] = st[i][j-1] + st[(i + st[i][j-1]) % N][j-1];
  }
  int ans = N;
  for (int i=0; i<N; ++i) {
    int a = i;
    int remain = N;
    int team = 0;
    for (int j=16; j>=0; --j) {
      if (st[a][j] <= remain) {
        remain -= st[a][j];
        a = (a + st[a][j]) % N;
        team += 1<<j;
      }
    }
    if (remain) team++;
    ans = min(ans, team);
  }
  cout << ans;
  return 0;
}