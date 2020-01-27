#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int pre = 0;
  int cur = 0;
  for (int i=0; i<10; ++i) {
    int a;
    cin >> a;
    cur += a;
    if (cur >= 100) {
      if (cur - 100 <= 100 - pre) cout << cur;
      else cout << pre;
      return 0;
    }
    pre = cur;
  }
  cout << cur;
  return 0;
}