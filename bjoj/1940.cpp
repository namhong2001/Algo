#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  cin >> N >> M;
  multiset<int> in;
  int ans = 0;
  for (int i=0; i<N; ++i) {
    int a;
    cin >> a;
    auto matcher = in.find(M-a);
    if (matcher != in.end()) {
      in.erase(matcher);
      ans++;
    } else {
      in.insert(a);
    }
  }
  cout << ans;
  return 0;
} 