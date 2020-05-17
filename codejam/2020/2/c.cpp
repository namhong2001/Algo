#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> Hole;
typedef vector<int> vi;
typedef vector<vi> vvi;

int gcd(int a, int b) {
  if (b > a) return gcd(b, a);
  if (a % b) return b;
  return gcd(b, a%b);
}

int N;

int test(vector<Hole> &holes, int remain, vvi &conn, vi &checked, int start, int dx, int dy) {

}

int check(vector<Hole> &holes, int remain, vvi &conn, vi &checked) {
  if (remain < 2) {
    int ret = 0;
    for (int i=0; i<N; ++i) {
      for (int j=0; j<N; ++j) {
        if (i == j) continue;
        int dx = holes[i].first - holes[j].first;
        int dy = holes[i].second - holes[j].second;
        int g = gcd(abs(dx), abs(dy));
        dx /= g;
        dy /= g;
        ret = max(ret, test(holes, remain, conn, checked, i, dx, dy));
      }
    }
    return ret;
  }
  int ret = 0;
  for (int i=0; i<N ; ++i) {
    if (checked[i]) continue;
    checked[i] = true;
    int u = i;
    for (int j=0; j<N ; ++j) {
      if (checked[j]) continue;
      checked[j] = true;
      int v = j;
      conn[u].push_back(v);
      conn[v].push_back(u);
      ret = max(ret, check(holes, remain - 2, conn, checked));
      conn[u].pop_back();
      conn[v].pop_back();
      checked[j] = false;
    }
    checked[i] = false;
  }
  return ret;
}

int solve(vector<Hole> &holes) {
  vvi conn(N);
  vi checked(N);
  return check(holes, N, conn, checked);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    cin >> N;
    vector<Hole> holes;
    for (int i=0; i<N; ++i) {
      int x, y;
      cin >> x >> y;
      holes.push_back({x, y});
    }
    cout << "Case #" << t << ": " << solve(holes) << '\n';
  }
  return 0;
}