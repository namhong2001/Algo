#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<ll> arr(10, 1);
    while (--N) {
      for (int i=9; i>=0; --i) {
        for (int j=i-1; j>=0; --j) {
          arr[i] += arr[j];
        }
      }
    }
    cout << accumulate(arr.begin(), arr.end(), 0ll) << '\n';
  }
  return 0;
}