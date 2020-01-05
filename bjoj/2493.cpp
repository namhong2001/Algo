#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int i=0; i<N; ++i) cin >> arr[i];
  vector<pii> lefts;
  vector<int> ans(N, 0);
  for (int i=0; i<N; ++i) {
    auto upper = upper_bound(
      lefts.begin(), 
      lefts.end(), 
      pii {arr[i], -1},
      [](const pii &A, const pii &B) { return A.first > B.first; });

    if (upper != lefts.begin()) {
      ans[i] = prev(upper)->second;
    }
    while (!lefts.empty() && lefts.back().first <= arr[i]) lefts.pop_back();
    lefts.emplace_back(arr[i], i+1);
  }
  for (int i=0; i<N; ++i) {
    cout << ans[i] << ' ';
  }

  return 0;
}