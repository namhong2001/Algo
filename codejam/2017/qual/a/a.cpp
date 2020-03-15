#include <iostream>

using namespace std;

bool isOk(string &s) {
  for (int i=0; i<s.size(); ++i) {
    if (s[i] == '-') return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    string s;
    int k;
    cin >> s >> k;
    int sz = s.size();
    int ans = 0;
    for (int i=0; i<sz-k+1; ++i) {
      if (s[i] == '-') {
        for (int j=0; j<k; ++j) {
          if (s[i+j] == '-') s[i+j] = '+';
          else if (s[i+j] == '+') s[i+j] = '-';
        }
        ans++;
      }
    }
    if (isOk(s)) {
      cout << "Case #" << t << ": " << ans << '\n';
    } else {
      cout << "Case #" << t << ": " << "IMPOSSIBLE" << '\n';
    }
  }
  return 0;
}