#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  int sz = s.size();
  bool isMinus = false;
  string nstr = "";
  int ans = 0;
  for (int i=0; i<sz ; ++i) {
    if (s[i] >= '0' && s[i] <= '9') nstr += s[i];
    else {
      int n = stoi(nstr);
      if (isMinus) ans -= n;
      else ans += n;
      nstr = "";
      if (s[i] == '-') isMinus = true;
    }
  }
  if (nstr.size() > 0) {
    int n = stoi(nstr);
    if (isMinus) ans -= n;
    else ans += n;
  }
  cout << ans;
  return 0;
}