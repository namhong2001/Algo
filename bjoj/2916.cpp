#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, K;
  cin >> N >> K;
  set<int> angle;
  for (int i=0; i<N; ++i) {
    int a;
    cin >> a;
    angle.insert(a);
  }
  int sz = angle.size();
  do {
    set<int> na = angle;
    sz = angle.size();
    for (int a : angle) {
      for (int b : angle) {
        na.insert((a+b) % 360);
        na.insert(abs(a-b) % 360);
      }
    }
    angle = na;
  } while (angle.size() > sz);
  while (K--) {
    int a;
    cin >> a;
    if (angle.find(a) != angle.end()) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}