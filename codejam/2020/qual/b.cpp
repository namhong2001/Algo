#include <iostream>

using namespace std;

string solve(string &in) {
  int N = in.size();
  int paren = 0;
  string ret = "";
  for (int i=0; i<N; ++i) {
    int digit = in[i] - '0';
    while (paren < digit) {
      ret += '(';
      paren++;
    }
    while (paren > digit) {
      ret += ')';
      paren--;
    }
    ret += in[i];
  }
  while (paren > 0) {
    ret += ')';
    paren--;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    string s;
    cin >> s;
    cout << "Case #" << t << ": " << solve(s) << '\n';
  }
  return 0;
}