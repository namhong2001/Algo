#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
      vector<int> arr(5);
      for (int i=0; i<5; ++i) cin >> arr[i];
      sort(arr.begin(), arr.end());
      arr.pop_back();
      arr.erase(arr.begin());
      const int sum = accumulate(arr.begin(), arr.end(), 0);
      if (arr.back() - arr.front() >= 4) cout << "KIN" << '\n';
      else cout << sum << '\n';
  }

  return 0;
}