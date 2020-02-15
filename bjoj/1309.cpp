#include <iostream>
#include <vector>

using namespace std;

const int MOD = 9901;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  int a=0, b=0, c=1; // lion is on left, right, empty.
  while (N--) {
    int na = b+c;
    int nb = a+c;
    int nc = a+b+c;
    a = na % MOD;
    b = nb % MOD;
    c = nc % MOD;
  }
  cout << (a+b+c) % MOD;
  return 0;
}