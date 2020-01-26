#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> ans(N, vector<int>(M, 0));
  for (int k=0; k<2; ++k) for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) {
    int a;
    cin >> a;
    ans[i][j] += a;
  }
  for (int i=0; i<N; ++i) {
    for (int j=0; j<M; ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}