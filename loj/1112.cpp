#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

const int NMAX = 100005;
int N, Q;
int bit[NMAX];
int sum(int r) {
    assert(r >= 0);
    int ret = 0;
    while (r > 0) {
        ret += bit[r];
        r -= r & -r;
    }
    return ret;
}
int sum(int l, int r) {
    return sum(r) - sum(l-1);
}
void add(int idx, int delta) {
    assert(idx >= 0);
    while (idx <= N) {
        assert(idx >= 0);
        bit[idx] += delta;
        idx += idx & -idx;
    }
}
void update(int idx, int val) {
    add(idx, val - sum(idx, idx));
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cin >> N >> Q;
        memset(bit, 0, sizeof(bit));
        // bit.assign(NMAX, 0);
        for (int i=1; i<=N; ++i) {
            int val;
            cin >> val;
            add(i, val);
        }
        cout << "Case " << t << ":" << '\n';
        for (int i=1; i<=Q; ++i) {
            int a;
            cin >> a;
            if (a == 1) {
                int idx;
                cin >> idx;
                idx++;
                cout << sum(idx, idx) << '\n';
                update(idx, 0);
            } else if (a == 2) {
                int idx, val;
                cin >> idx >> val;
                idx++;
                add(idx, val);
            } else if (a == 3) {
                int l, r;
                cin >> l >> r;
                l++, r++;
                cout << sum(l, r) << '\n';
            }
        }
    }
    return 0;
}