#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int K;
  cin >> K;
  for (int i=0; i<K; ++i) cout << 1;
  for (int i=0; i<K-1; ++i) cout << 0;
  return 0;
}