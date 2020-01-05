#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  int sz = s.size();
  for (int i=0; i<sz/2; ++i) {
    if (s[i] != s[sz-1-i]) {
      cout << 0;
      return 0;
    }
  }
  cout << 1;
  return 0;
}