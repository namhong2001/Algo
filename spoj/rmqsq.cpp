#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int st[N][26];
    for (int i=0; i<N; ++i) cin >> st[i][0];
    for (int j=1; j<26; ++j) {
        for (int i=0; i+(1<<j)<=N; ++i) {
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int s, e;
        cin >> s >> e;
        int r = e-s+1;
        int ans = st[s][0];
        for (int j=0; j<26; ++j) {
            if (r & (1<<j)) {
                ans = min(ans, st[s][j]);
                s += 1<<j;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}