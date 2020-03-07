#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int diff = INF;
vector<int> ans;

void solve(int m, int p) {
  int nd = abs(m + p);
  if (nd < diff) {
    ans.clear();
    ans.push_back(m);
    ans.push_back(p);
    diff = nd;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<int> minus;
  vector<int> plus;
  while (N--) {
    int a;
    cin >> a;
    if (a < 0) minus.push_back(a);
    else plus.push_back(a);
  }
  sort(minus.begin(), minus.end(), greater<int>());
  sort(plus.begin(), plus.end());
  if (plus.size() >= 2) {
    solve(plus[0], plus[1]);
  }
  if (minus.size() >= 2) {
    solve(minus[0], minus[1]);
  }
  for (int i=0, j=0; i<minus.size() && j < plus.size(); ) {
    solve(minus[i], plus[j]);
    if (minus[i] + plus[j] > 0) i++;
    else j++;
  }
  sort(ans.begin(), ans.end());
  cout << ans[0] << ' ' << ans[1];
  return 0;
}
