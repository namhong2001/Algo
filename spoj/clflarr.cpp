#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> r;
int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

void u(int a, int b) { 
    a = f(a), b = f(b);
    if (a > b) u(b, a);
    r[a] = b;
}

struct Query {
    int l, r, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    r.resize(N+2);
    iota(r.begin(), r.end(), 0);
    vector<Query> q;
    for (int i=0; i<Q; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        q.push_back({l, r, c});
    }
    reverse(q.begin(), q.end());
    vector<int> ans(N+1);
    for (int i=0; i<Q; ++i) {
        int l = q[i].l;
        int r = q[i].r;
        int c = q[i].c;
        for (int v = f(l); v <= r; v = f(v)) {
            ans[v] = c;
            u(v, v+1);
        }
    }
    for (int i=1; i<=N; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}