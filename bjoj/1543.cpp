#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string H, N;
  getline(cin, H);
  getline(cin, N);
  // cin >> H >> N;
  int ans = 0;
  string::size_type p = 0;
  while (true) {
    p = H.find(N, p);
    if (p != string::npos) {
      ans++;
      p += N.size();
    }
    else break;
  }
  cout << ans;
  return 0;
}