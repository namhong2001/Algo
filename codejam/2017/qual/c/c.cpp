#include <iostream>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;

pair<ll,ll> solve(ll n, ll k) {
  map<ll,ll,greater<ll>> mp;
  mp.insert({n, 1});
  for (ll i=0; ; ++i) {
    ll cnt = pow(2, i);
    if (k - cnt > 0) {
      k -= cnt;
      map<ll,ll,greater<ll>> nmp;
      for (auto &item : mp) {
        if (item.first % 2 == 0) {
          nmp[item.first / 2] += item.second;
          nmp[item.first / 2 - 1] += item.second;
        } else {
          nmp[item.first / 2] += item.second;
          nmp[item.first / 2] += item.second;
        }
      }
      mp = nmp;
    } else {
      while (k) {
        auto target = mp.begin();
        ll key = target->first;
        ll val = target->second;
        if (val >= k) {
          if (key % 2 == 0) {
            return {key / 2, key / 2 - 1};
          } else {
            return {key / 2, key / 2};
          }
        } else {
          k -= val;
          mp.erase(target);
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    ll n, k;
    cin >> n >> k;
    auto ans = solve(n, k);
    cout << "Case #" << t << ": " << ans.first << ' ' << ans.second << '\n';
  }
  return 0;
}