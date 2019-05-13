#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100005], b[100005];
int ma[100005][20], mb[100005][20];

long long cal(void) {
    for (int i = 1; i <= n; ++i) ma[i][0] = a[i], mb[i][0] = b[i];
    for (int j = 1; j < 17; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            ma[i][j] = max(ma[i][j-1], ma[i+(1<<j-1)][j-1]);
            mb[i][j] = max(mb[i][j-1], mb[i+(1<<j-1)][j-1]);
        }
    }
    long long ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= b[i]) continue;
        int l = i, r = i;
        for (int j = 16; j >= 0; --j) {
            if (r + (1 << j) <= n && mb[r+1][j] <= b[i] && ma[r+1][j] < b[i])
                r += 1 << j;
        }
        for (int j = 16; j >= 0; --j) {
            if (l - (1 << j) > 0 && mb[l-(1<<j)][j] < b[i] && ma[l-(1<<j)][j] < b[i])
                l -= 1 << j;
        }
        ret += 1LL * (i - l + 1) * (r - i + 1);
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int ntest;
    cin >> ntest;
    for (int itest = 1; itest <= ntest; ++itest) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        long long all = 1ll * n * (n + 1) / 2;
        for (int i = 1; i <= n; ++i) a[i] += k;
        all -= cal();
        for (int i = 1; i <= n; ++i) {
            a[i] -= k;
            b[i] += k;
            swap(a[i], b[i]);
        }
        all -= cal();
        cout << "Case #" << itest << ": " << all << '\n';
    }
    return 0;
}
