#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    string s;
    cin >> s;
    int sz = s.size();
    for (int i=sz-1; i>0; --i) {
      if (s[i-1] > s[i]) {
        s[i-1]--;
        for (int j=i; j<sz; ++j) {
          s[j] = '9';
        }
      }
    }
    cout << "Case #" << t << ": ";
    if (s[0] == '0') {
      for (int i=1; i<sz; ++i) cout << s[i];
    } else {
      for (int i=0; i<sz; ++i) cout << s[i];
    }
    cout << '\n';
  }
  return 0;
}