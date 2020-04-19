#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 987654321987654321;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    int N;
    cin >> N;
    vector<ll> dp(1000, INF);
    dp[0] = 0;
    int last = 0;
    for (int i=0; i<N; ++i) {
      ll w;
      cin >> w;
      for (int j=last; j>=0; --j) {
        if (dp[j] > w*6) continue;
        dp[j+1] = min(dp[j+1], dp[j] + w);
      }
      if (dp[last+1] != INF) last++;
    }
    cout << "Case #" << t << ": " << last << '\n';
  }
  return 0;
}
