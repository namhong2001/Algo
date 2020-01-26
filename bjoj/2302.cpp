#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<bool> sit(N+1, false);
  sit[0] = true;
  vector<int> ans(N+1, 0);
  ans[0] = 1;
  for (int i=0; i<M; ++i) {
    int a;
    cin >> a;
    sit[a] = true;
  }
  for (int i=1; i<=N; ++i) {
    if (sit[i] || sit[i-1]) ans[i] = ans[i-1];
    else ans[i] = ans[i-2] + ans[i-1];
  }
  cout << ans[N];
  return 0;
}