#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<bool> eratos(N+1);
  for (int i=2; i<=N; ++i) {
    if (eratos[i]) continue;
    eratos[i] = true;
    K--;
    if (!K) {
      cout << i;
      return 0;
    }
    for (int j=i*i; j<=N; j+=i) {
      if (eratos[j]) continue;
      eratos[j] = true;
      K--;
      if (!K) {
        cout << j;
        return 0;
      }
    }
  }
  return 0;
}