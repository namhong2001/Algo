#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 110000, LOG = 20;

int a[2][maxn];
pii sp[2][LOG + 1][maxn];
int k2[maxn];

int n, k;

void build_sparse(int t) {
    forn(i, n) sp[t][0][i] = mp(a[t][i], i);
    forn(j, LOG) forn(i, n) {
        sp[t][j + 1][i] = sp[t][j][i];
        if (i + (1 << j) < n) uax(sp[t][j + 1][i], sp[t][j][i + (1 << j)]);
    }
}

pii query(int t, int l, int r) {
    int j = k2[r - l];
    return max(sp[t][j][l], sp[t][j][r - (1 << j)]);
}

int at_mostr(int l, int x) {
    int L = l, R = n + 1;
    while (R - L > 1) {
        int M = (L + R) / 2;
        (query(1, l, M).fi <= x ? L : R) = M;
    }
//    cerr << "R " << l << ' ' << x << ' ' << L << '\n';
    return L;
}

int at_mostl(int r, int x) {
    int L = -1, R = r;
    while (R - L > 1) {
        int M = (L + R) / 2;
        (query(1, M, r).fi <= x ? R : L) = M;
    }
//    cerr << "L " << r << ' ' << x << ' ' << R << '\n';
    return R;
}

i64 dnc(int l, int r) {
    if (l == r) return 0;
    auto w = query(0, l, r);
    int x = w.fi, m = w.se;
    i64 ans = 0;
    if (m - l <= r - m) fore(i, l, m) ans += max(0, min(r, at_mostr(i, x + k)) - m) - max(0, min(r, at_mostr(i, x - k - 1)) - m);
    else fore(i, m + 1, r) ans += max(0, m + 1 - max(l, at_mostl(i, x + k))) - max(0, m + 1 - max(l, at_mostl(i, x - k - 1)));
    return ans + dnc(l, m) + dnc(m + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    {
        int k = 0;
        for1(i, maxn - 1) {
            while ((2 << k) <= i) ++k;
            k2[i] = k;
        }
    }

    int T;
    cin >> T;
    for1(ttt, T) {
        cin >> n >> k;
        forn(t, 2) forn(i, n) cin >> a[t][i];
        forn(t, 2) build_sparse(t);
        cout << "Case #" << ttt << ": " << dnc(0, n) << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
