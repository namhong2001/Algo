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
  vector<int> arr(N);
  for (int i=0; i<N; ++i) cin >> arr[i];
  sort(arr.begin(), arr.end());
  int ans = 0;
  for (int i=0; i<N; ++i) {
    ans += arr[i] * (N-i);
  }
  cout << ans;
  return 0;
}