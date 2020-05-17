#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ll;

ll ssum(ll a, ll d, ll n) {
  return n * (2*a + (n-1) * d) / 2;
}

ll bsearch(ll sum, ll a, ll d) {
  ll l = 0; // true
  ll r = 2e9+1; // false
  while (l+1 < r) { 
    ll mid = (l+r)/2;
    if (ssum(a, d, mid) <= sum) l = mid;
    else r = mid;
  }
  return l;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    ll L, R;
    cin >> L >> R;
    ll n = 0;
    if (L > R) {
      ll nn = bsearch(L-R, 1, 1);
      ll sum = ssum(1, 1, nn);
      L -= sum;
      n += nn;
    } else if (R > L) {
      ll nn = bsearch(R-L, 1, 1);
      ll sum = ssum(1, 1, nn);
      R -= sum;
      n += nn;
      if (R > L && R >= (n+1)) {
        R -= ++n;
      }
    }
    ll ln = bsearch(L, n+1, 2);
    ll rn = bsearch(R, n+2, 2);
    L -= ssum(n+1, 2, ln);
    R -= ssum(n+2, 2, rn);
    n += ln + rn;
    cout << "Case #" << t << ": " << n << ' ' << L << ' ' << R << '\n';
  }
  return 0;
}