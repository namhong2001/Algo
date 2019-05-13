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

void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}


int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        edges.clear();
        r.resize(n);
        for (int i=0; i<n; ++i) r[i] = i;
        int total = 0;
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            total += c;
            edges.push_back({c, a, b});
        }
        sort(edges.begin(), edges.end());
        int required = 0;
        int u_cnt = 0;
        for (E &e : edges) {
            int c = e[0];
            int a = e[1];
            int b = e[2];
            if (f(a) != f(b)) {
                u(a, b);
                required += c;
                u_cnt++;
                if (u_cnt == n-1) break;
            }
        }
        cout << total - required << endl;
    }
    return 0;
}
