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
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    for1(ttt, T) {
        int n, q;
        cin >> n >> q;
        vi dx(q + 1), dy(q + 1);
        forn(i, n) {
            int x, y;
            char c;
            cin >> x >> y >> c;
            if (c == 'N') ++dy[y + 1];
            if (c == 'S') ++dy[0], --dy[y];
            if (c == 'E') ++dx[x + 1];
            if (c == 'W') ++dx[0], --dx[x];
        }
        forn(i, q) dx[i + 1] += dx[i];
        forn(i, q) dy[i + 1] += dy[i];
        cout << "Case #" << ttt << ": " << max_element(all(dx)) - dx.begin() << ' ' << max_element(all(dy)) - dy.begin() << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
