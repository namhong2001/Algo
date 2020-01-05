#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  cin >> N;
  int ans = 0;
  for (int i=0; i<N; ++i) {
      int a;
      cin >> a;
      ans += a;
  }
  if (ans > N/2) cout << "Junhee is cute!";
  else cout << "Junhee is not cute!";
  return 0;
}