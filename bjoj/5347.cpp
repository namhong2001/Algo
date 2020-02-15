#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  if (b > a) return gcd(b, a);
  return gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    cout << a * b / g << '\n';
  }
  return 0;
}