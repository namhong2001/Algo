#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  vector<ll> arr(N);
  for (int i=0; i<N; ++i) cin >> arr[i];
  ll B, C;
  cin >> B >> C;
  ll ans = 0;
  for (int i=0; i<N; ++i) {
    arr[i] -= B;
    ans++;
    if (arr[i] > 0) ans += arr[i]/C + (arr[i]%C ? 1 : 0);
  }
  cout << ans;
  return 0;
}