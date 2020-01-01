#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 200000;
const int MOD = 1e9 + 7;

vector<int> dp(NMAX, -1);

int fibo(int ith) {
  if (ith == 0 || ith == 1) return 1;
  int &ret = dp[ith];
  if (ret != -1) return ret;
  return ret = (fibo(ith-1) + fibo(ith-2)) % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    cout << fibo(N) << '\n';
  }
  return 0;
}