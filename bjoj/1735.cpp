#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b > a) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int f = b * d;
  int e = a*d + b*c;
  int g = gcd(e, f);
  cout << e/g << ' ' << f/g;
  return 0;
}