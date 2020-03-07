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
  vector<int> ans(N);
  vector<int> nge;
  for (int i=N-1; i>=0; --i) {
    auto target = upper_bound(nge.rbegin(), nge.rend(), arr[i]);
    if (target == nge.rend()) ans[i] = -1;
    else ans[i] = *target;
    while (!nge.empty() && nge.back() <= arr[i]) nge.pop_back();
    nge.push_back(arr[i]);
  }
  for (int i=0; i<N; ++i) {
    cout << ans[i] << ' ';
  }
  return 0;
}