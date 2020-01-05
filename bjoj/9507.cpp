#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> dp(100, -1);

ll koong(int n) {
  if (n < 2) return 1;
  if (n == 2) return 2;
  if (n == 3) return 4;

  ll &ret = dp[n];
  if (ret != -1) return ret;
  return ret = koong(n-1) + koong(n-2) + koong(n-3) + koong(n-4);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << koong(n) << '\n';
  }
  return 0;
}