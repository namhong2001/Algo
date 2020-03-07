#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
      int a, b;
      cin >> a >> b; 
    }
    cout << N-1 << '\n';
  }

  return 0;
}