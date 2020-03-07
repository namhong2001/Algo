#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, M;
  cin >> N >> M;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i=0; i<N; ++i) {
    ll a;
    cin >> a;
    pq.push(a);
  }
  while (M--) {
    ll a = pq.top();
    pq.pop();
    ll b = pq.top();
    pq.pop();
    ll c = a + b;
    pq.push(c);
    pq.push(c);
  }
  ll ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
  return 0;
}