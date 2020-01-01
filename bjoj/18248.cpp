#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<set<int>> hear(N);
  for (int i=0; i<N; ++i) {
    for (int j=0; j<M; ++j) {
      int a;
      cin >> a;
      if (a) hear[i].insert(j);
    }
  }
  sort(hear.begin(), hear.end(), [](const set<int> &A, const set<int> &B){return A.size() < B.size();});
  set<int> ss;
  for (int i=0; i<N; ++i) {
    set<int> &tt = hear[i];
    for (int s : ss) {
      if (tt.find(s) == tt.end()) {
        cout << "NO";
        return 0;
      }
    }
    for (int t : tt) {
      ss.insert(t);
    }
  }
  cout << "YES";
  return 0;
}