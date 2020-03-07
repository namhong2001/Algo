#include <iostream>
#include <vector>

using namespace std;

struct Score {
  int g, s, b;
  bool operator > (const Score &rhs) {
    if (g == rhs.g) {
      if (s == rhs.s) return b > rhs.b;
      else return s > rhs.s;
    } else return g > rhs.g;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<Score> arr(N);
  Score target;
  for (int i=0; i<N; ++i) {
    int idx;
    cin >> idx >> arr[i].g >> arr[i].s >> arr[i].b;
    if (idx == K) target = arr[i];
  }
  int rank = 1;
  for (int i=0; i<N; ++i) {
    if (arr[i] > target) rank++;
  }
  cout << rank;
  return 0;
}