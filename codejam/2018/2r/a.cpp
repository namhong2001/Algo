#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    int C;
    cin >> C;
    vector<string> arr(C, string(C, '.'));
    vector<int> inputs;
    int row = 0;
    for (int remain=0, i=0; i<C; ++i) {
      int c;
      cin >> c;
      inputs.push_back(c);
      remain++;
      remain -= c;
      if (remain > 0) {
        for (int j=0; j<remain; ++j) {
          arr[j][i] = '\\';
        }
      } else if (remain < 0) {
        for (int j=0; j<abs(remain); ++j) {
          arr[j][i+1] = '/';
        }
      }
      row = max(row, abs(remain) + 1);
    }
    if (inputs[0] == 0 || inputs.back() == 0) {
      cout << "Case #" << t << ": " << "IMPOSSIBLE" << '\n';
    } else {
      cout << "Case #" << t << ": " << row << '\n';
      for (int i=0; i<row; ++i) {
        cout << arr[i] << '\n';
      }
    }
  }
  return 0;
}