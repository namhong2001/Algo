#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  vector<string> board(8);
  for (int i=0; i<8; ++i) cin >> board[i];
  int ans = 0;
  for (int i=0; i<8; ++i) for (int j=0; j<8; ++j) {
    if (board[i][j] == 'F' && (i + j) % 2 == 0) ans++;
  }
  cout << ans;
  return 0;
}