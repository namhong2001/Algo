#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int i=0; i<N; ++i) cin >> arr[i];
  ll sum = accumulate(arr.begin(), arr.end(), 0);
  ll ans = 0;
  for (int i=0; i<N; ++i) {
    sum -= arr[i];
    ans += sum * arr[i];
  }
  cout << ans;
  return 0;
}