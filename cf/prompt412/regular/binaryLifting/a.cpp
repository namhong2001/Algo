#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> st(N+1, vector<int>(17));
  for (int i=1; i<=N; ++i) cin >> st[i][0];
  for (int j=1; j<17; ++j) for (int i=1; i<=N; ++i) {
    st[i][j] = st[st[i][j-1]][j-1];
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    for (int i=0; i<17; ++i) {
      if ((1 << i) & b) a = st[a][i];
    }
    cout << a << '\n';
  }
  return 0;
}