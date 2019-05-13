#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> r;

int f(int me) {
    return r[me] = r[me] == me ? me : f(r[me]);
}

void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}

int n, m;

int main() {
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m;
        r.resize(2*n);
        for (int i=0; i<2*n; ++i) r[i] = i;
        int contradiction_idx = -1;

        for (int i=0; i<m; ++i) {
            string s;
            int a, b;
            cin >> s >> a >> b;
            a *=2, b *= 2;
            int not_a = a+1, not_b = b+1;

            if (s == "ACK") {
                u(a, b);
                u(not_a, not_b);
            } else if (s == "DIS") {
                u(a, not_b);
                u(b, not_a);
            }
            if (f(a) == f(not_a) || f(b) == f(not_b)) {
                if (contradiction_idx == -1) {
                    contradiction_idx = i+1;
                }
            }
        }
        if (contradiction_idx != -1) {
            cout << "CONTRADICTION AT " << contradiction_idx  << '\n';
        } else {
            vector<int> p_cnt(2*n);
            vector<int> m_cnt(2*n);
            int ans = 0;

            for (int i=0; i<2*n; ++i) {
                if (i%2) m_cnt[f(i)]++;
                else p_cnt[f(i)]++;
            }
            for (int i=0; i<2*n; ++i) {
                if (i == f(i)) ans += max(p_cnt[i], m_cnt[i]);
            }
            ans /= 2;
            cout << "MAX PARTY SIZE IS " << ans << '\n';
        }
    }
    return 0;
}
