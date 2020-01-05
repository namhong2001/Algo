#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int A, B;
    cin >> A >> B;
    int ans = 1;
    for (int i=0; i<B; ++i) {
      ans = ans * A % 10;
    }
    if (ans == 0) cout << 10 << '\n';
    else cout << ans << '\n';
  }

  return 0;
}