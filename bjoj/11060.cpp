#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int i=0; i<N; ++i) cin >> arr[i];
  vector<int> dp(N+102, -1);
  dp[0] = 0;
  int cur = 1;
  for (int i=0; i<N; ++i) {
    if (dp[i] == -1) break;
    while (i+arr[i] >= cur) {
      dp[cur++] = dp[i] + 1;
    }
  }
  cout << dp[N-1];
  return 0;
}