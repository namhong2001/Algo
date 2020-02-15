#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> dp(M+2, -INF);
  dp[1] = 0;
  while (N--) {
    vector<int> arr(M+2);
    for (int i=1; i<=M; ++i) cin >> arr[i];
    vector<int> fromLeft(M+2, -INF), fromRight(M+2, -INF);
    for (int i=1; i<=M; ++i) {
      fromLeft[i] = max(dp[i], fromLeft[i-1]) + arr[i];
    }
    for (int i=M; i>=1; --i) {
      fromRight[i] = max(dp[i], fromRight[i+1]) + arr[i];
    }
    for (int i=1; i<=M; ++i) {
      dp[i] = max({dp[i], fromLeft[i-1], fromRight[i+1]}) + arr[i];
    }
  }
  cout << dp[M];
  return 0;
}