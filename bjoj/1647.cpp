#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> E;
vector<E> edges;
vector<int> r;

int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

int u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    r.resize(n);
    for (int i=0; i<n; ++i) r[i] = i;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges.push_back({c, a, b});
    }
    sort(edges.begin(), edges.end());
    int u_cnt = 0;
    int ans = 0;
    for (E &e : edges) {
        int c = e[0];
        int a = e[1];
        int b = e[2];
        if (f(a) != f(b)) {
            u(a, b);
            u_cnt++;
            ans += c;
            if (u_cnt == n-2) break;
        }
    }
    cout << ans << '\n';
    return 0;
}
