#include <iostream>
#include <vector>

#define ll long long

using namespace std;

struct Fenwick {
    vector<ll> tree;
    Fenwick(ll n): tree(n+1) {}
    ll sum(ll pos) {
        ll ret = 0;
        while (pos > 0) {
            ret += tree[pos];
            pos &= (pos-1);
        }
        return ret;
    }
    void add(ll pos, ll val) {
        while (pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }

    void change(ll pos, ll val) {
        add(pos, val - sum(pos) + sum(pos-1));
    }
};


int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    Fenwick fenwick(n);
    for (ll i=1; i<=n; ++i) {
        ll num;
        cin >> num;
        fenwick.add(i, num);
    }
    for (ll i=0; i<m+k; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            fenwick.change(b, c);
        } else if (a == 2) {
            cout << fenwick.sum(c) - fenwick.sum(b-1) << endl;
        }
    }

    return 0;
}
