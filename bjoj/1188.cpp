#include <iostream>

using namespace std;

int func(int a, int b) {
  while (a >= b) a -= b;
  if (a == 0) return 0;
  return a + func(a, b-a);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  cin >> N >> M;
  cout << func(N, M);
  return 0;
}