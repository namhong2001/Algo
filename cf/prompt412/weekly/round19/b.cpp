#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  int M;
  cin >> M;
  for (int i=0; i<M; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    l--, r--;
    int len = r-l+1;
    string ns = s;
    for (int i=0; i<len; ++i) {
      int p = (i + k) % len;
      ns[l+p] = s[l+i];
    }
    s = ns;
  }
  cout << s;
  return 0;
}