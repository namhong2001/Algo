#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    int st[N+1][26];
    for (int i=1; i<=N; ++i) cin >> st[i][0];
    for (int j=1; j<26; ++j) {
        for (int i=1; i+(1<<j) <= N+1; ++i) {
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    int ans = 0;
    while (M--) {
        int a, b;
        cin >> a >> b;
        int h = st[a][0];
        int h_max = h;
        int r = b-a;
        for (int j=0; j<26; ++j) {
            if (r & (1<<j)) {
                h_max = max(h_max, st[a][j]);
                a += 1<<j;
            }
        }
        if (h_max <= h) ans++;
    }
    cout << ans;
    return 0;
}