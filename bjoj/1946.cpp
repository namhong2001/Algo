#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<pii> arr(N);
    for (int i=0; i<N; ++i) {
      cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    int tmin = arr[0].second;
    int ans = 1;
    for (int i=1; i<N; ++i) {
      if (arr[i].second < tmin) ans++;
      tmin = min(tmin, arr[i].second);
    }
    cout << ans << '\n';
  }
  return 0;
}