#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<int> minus;
  vector<int> plus;
  int zeroCnt = 0;
  for (int i=0; i<N; ++i) {
    int a;
    cin >> a;
    if (a > 0) plus.push_back(a);
    else if (a < 0) minus.push_back(a);
    else zeroCnt++;
  }
  sort(plus.begin(), plus.end(), greater<int>());
  sort(minus.begin(), minus.end());
  int ans = 0;
  for (int i=0; i<plus.size(); i++) {
    if (i+1 < plus.size() && plus[i+1] > 1) {
      ans += plus[i] * plus[i+1];
      i++;
    } else {
      ans += plus[i];
    }
  }
  for (int i=0; i<minus.size(); i++) {
    if (i+1 < minus.size()) {
      ans += minus[i] * minus[i+1];
      i++;
    } else {
      if (zeroCnt == 0) ans += minus[i];
    }
  }
  cout << ans;
  return 0;
}