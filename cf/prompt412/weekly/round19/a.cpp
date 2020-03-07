#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> arr(M);
  for (int i=0; i<M; ++i) cin >> arr[i];
  int me;
  cin >> me;
  int ans = 0;
  for (int i=0; i<M; ++i) {
    if (__builtin_popcount(arr[i] ^ me) <= K) ans++;
  }
  cout << ans;
  return 0;
}