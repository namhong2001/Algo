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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int T, W;
    cin >> T >> W;
    while (T--) {
        vi64 ans(7);
        int k1 = 4 * 56;
        cout << k1 << endl;
        i64 x;
        cin >> x;
        fore(i, 4, 6) ans[i] = (x >> (k1 / i)) & 127;

        int k2 = 56;
        cout << k2 << endl;
        cin >> x;
        fore(i, 4, 6) x -= ans[i] << (k2 / i);
        for1(i, 3) ans[i] = (x >> (k2 / i)) & 127;
        for1(i, 6) {
            if (i > 1) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
        int verd;
        cin >> verd;
        assert(verd == 1);
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
