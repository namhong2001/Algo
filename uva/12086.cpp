#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> bit;
int sum(int r) {
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
    while (idx <= N) {
        bit[idx] += delta;
        idx += idx & -idx;
    }
}
void update(int idx, int val) {
    add(idx, val - sum(idx, idx));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int t=1; ; t++) {
        cin >> N;
        if (N == 0) break;
        if (t > 1) cout << '\n';
        cout << "Case " << t << ":" << '\n';
        bit.assign(N+1, 0);
        for (int i=1; i<=N; ++i) {
            int val;
            cin >> val;
            update(i, val);
        }
        while (true) {
            string s;
            cin >> s;
            if (s == "END") break;
            if (s == "S") {
                int idx, val;
                cin >> idx >> val;
                update(idx, val);
            } else if (s == "M") {
                int l, r;
                cin >> l >> r;
                cout << sum(l, r) << '\n';
            }
        }
    }
    return 0;
}