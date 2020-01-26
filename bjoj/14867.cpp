#include <iostream>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int,int> pii;
typedef tuple<int,int,int> ti;

int A, B, C, D;
int bfs() {
  set<pii> memo;
  queue<ti> q;
  q.emplace(0, 0, 0);
  while (!q.empty()) {
    int a, b, t;
    tie(a, b, t) = q.front();
    q.pop();
    if (memo.find({a, b}) != memo.end()) continue;
    if (a == C && b == D) return t;
    memo.emplace(a, b);
    q.emplace(A, b, t+1);
    q.emplace(a, B, t+1);
    q.emplace(0, b, t+1);
    q.emplace(a, 0, t+1);
    if (A - a > 0) {
      int da = min(A-a, b);
      q.emplace(a + da, b - da, t+1);
    }
    if (B - b > 0) {
      int db = min(B-b, a);
      q.emplace(a - db, b + db, t+1);
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> A >> B >> C >> D;
  cout << bfs();
  return 0;
}