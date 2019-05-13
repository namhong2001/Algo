#include <bits/stdc++.h>

using namespace std;

int n, q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int ntest;
    cin >> ntest;
    for (int itest = 1; itest <= ntest; ++itest) {
        map <int, int> hor, ver;
        cin >> n >> q;
        for (int i = 0; i < n; ++i) {
            int x, y; char c;
            cin >> x >> y >> c;
            if (c == 'N') ++ver[y+1];
            if (c == 'S') --ver[y];
            if (c == 'E') ++hor[x+1];
            if (c == 'W') --hor[x];
        }
        int bestx = 0, cur = 0, mx = 0;
        for (auto k: hor) {
            cur += k.second;
            if (cur > mx) mx = cur, bestx = k.first;
        }
        int besty = 0; cur = 0, mx = 0;
        for (auto k: ver) {
            cur += k.second;
            if (cur > mx) mx = cur, besty = k.first;
        }
        cout << "Case #" << itest << ": " << bestx << ' ' << besty << '\n';
    }
    return 0;
}
