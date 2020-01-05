#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    if (N < 'L' - 'A' + 1 || M < 4) cout << -1;
    else cout << ('L'-'A') * M + 4;
    cout << '\n';
  }
  return 0;
}