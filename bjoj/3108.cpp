#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

struct Square {
  int x1, y1, x2, y2;
  bool operator < (const Square &rhs) const {
    if (x1 != rhs.x1) return x1 < rhs.x1;
    if (y1 != rhs.y1) return y1 < rhs.y1;
    if (x2 != rhs.x2) return x2 < rhs.x2;
    if (y2 != rhs.y2) return y2 < rhs.y2;
    return false;
  }
  bool intersect (const Square &rhs) const {
    if (rhs < *this) rhs.intersect(*this);
    if (x2 < rhs.x1) return false;
    if (rhs.y2 < y1) return false;
    if (rhs.y1 > y2) return false;
    if (x1 < rhs.x1 && x2 > rhs.x2 && y2 > rhs.y2 && y1 < rhs.y1) return false;
    return true;
  }
};

int N;
vector<int> r;
int f(int a) {
  return r[a] == a ? a : f(r[a]);
}

void u(int a, int b) {
  a = f(a);
  b = f(b);
  r[a] = b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N;

  r.resize(N);
  iota(r.begin(), r.end(), 0);

  vector<Square> arr(N);
  bool startWithSquare = false;
  for (int i=0; i<N; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    arr[i] = {x1, y1, x2, y2};
    if (x1 == 0  || x2 == 0) {
      if (y1 <= 0 && y2 >= 0) startWithSquare = true;
    }
    if (y1 == 0  || y2 == 0) {
      if (x1 <= 0 && x2 >= 0) startWithSquare = true;
    }
  }
  sort(arr.begin(), arr.end());
  for (int i=0; i<N; ++i) for (int j=i+1; j<N; ++j) {
    if (f(i) != f(j) && arr[i].intersect(arr[j])) {
      u(i, j);
    }
  }
  set<int> components;
  for (int i=0; i<N; ++i) {
    components.insert(f(i));
  }
  int ans = components.size();
  if (startWithSquare) ans--;
  cout << ans;
  return 0;
}