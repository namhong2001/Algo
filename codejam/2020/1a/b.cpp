#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int DP_SIZE = 1000;
ll dp[DP_SIZE][DP_SIZE];

void initDp() {
  for (int i=0; i<DP_SIZE; ++i) for (int j=0; j<DP_SIZE; ++j) dp[i][j] = -1;
}

ll pascal(int r, int k) {
  if (r == 1 || k == 1 || r == k) return 1;
  ll &ret = dp[r][k];
  if (ret != -1) return ret;
  return ret = pascal(r-1, k-1) + pascal(r-1, k);
}

bool dfs(int r, int k, ll remain, set<pii> &foot, vector<pii> &trace, int depth) {
  if (r < 1 || k < 1 || k > r) return false;
  if (foot.find({r, k}) != foot.end()) return false;
  if (depth > 500) return false;

  ll val = pascal(r, k);
  if (remain - val < 0) return false;

  remain -= val;
  foot.insert({r, k});
  trace.push_back({r, k});
  
  if (remain == 0) return true;
  vector<pii> temps = {{r-1, k-1}, {r-1, k}, {r, k-1}, {r, k+1}, {r+1, k}, {r+1, k+1}};
  vector<pii> candidates;
  for (auto &temp : temps) {
    if (temp.first < 1 || temp.second < 1 || temp.second > temp.first) continue;
    if (foot.find(temp) != foot.end()) continue;
    if (pascal(temp.first, temp.second) > remain) continue;
    candidates.push_back(temp);
  }
  sort(candidates.begin(), candidates.end(), [](pii &A, pii &B){return pascal(A.first, A.second) > pascal(B.first, B.second);});
  for (auto &candi : candidates) {
    if (dfs(candi.first, candi.second, remain, foot, trace, depth+1)) return true;
  }
  foot.erase({r, k});
  trace.pop_back();
  return false;
}

vector<pii> solve(ll N) {
  set<pii> foot;
  vector<pii> trace;
  if (dfs(1, 1, N, foot, trace, 1)) return trace;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  initDp();
  for (int t=1; t<=T; ++t) {
    ll N;
    cin >> N;
    vector<pii> trace = solve(N);
    cout << "Case #" << t << ": " << '\n';
    for (auto &a : trace) {
      cout << a.first << ' ' << a.second << '\n';
    }
  }
  return 0;
}