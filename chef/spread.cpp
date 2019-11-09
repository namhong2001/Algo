#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll N;
vector<ll> bit;
ll sum(ll r) {
    ll ret = 0;
    while (r > 0) {
        ret += bit[r];
        r -= r & -r;
    }
    return ret;
}
void add(ll idx, ll delta) {
    while (idx <= N) {
        bit[idx] += delta;
        idx += idx & -idx;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll M, C; 
    cin >> N >> M >> C;
    bit.assign(N+2, 0);
    add(1, C);
    add(N+1, -C);
    N++;
    while (M--) {
        string s;
        cin >> s;
        if (s == "S") {
            ll u, v, k;
            cin >> u >> v >> k;
            add(u, k);
            add(v+1, -k);
        } else if (s == "Q") {
            ll p;
            cin >> p;
            cout << sum(p) << '\n'; 
        }
    }
    return 0;
}