#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b > a) return gcd(b, a);
  return a % b == 0 ? b : gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    int l =  a * b / g;
    cout << l << ' ' << g << '\n';
  }
  return 0;
}