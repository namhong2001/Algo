#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> xore(N+1, 0);
  vector<int> ans(N+1, 0);
  for (int i=1; i<=M; ++i) {
      int l, r, val;
      cin >> l >> r >> val;
      if (i == 1) {
          xore[i] = val;
          ans[i] = val;
      }
      else {
          xore[i] = xore[l-1] ^ val;
          ans[i] = xore[i] ^ xore[i-1];
      }
  }
  for (int i=1; i<=N; ++i) {
      cout << ans[i] << ' ';
  }
  return 0;
}