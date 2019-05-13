#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

// ========================================================================= //

const int N = 1 << 17;

struct SegTree {
    int m1[N*2-1], m2[N*2-1];

    void build(int *a, int c = 0, int cl = 0, int cr = N - 1) {
        if (cl == cr)
            m1[c] = m2[c] = a[cl];
        else {
            build(a, c*2+1, cl, (cl+cr) / 2);
            build(a, c*2+2, (cl+cr) / 2 + 1, cr);
            m1[c] = min(m1[c*2+1], m1[c*2+2]);
            m2[c] = max(m2[c*2+1], m2[c*2+2]);
        }
    }

    int nextGE(int p, int v, int c = 0, int cl = 0, int cr = N - 1) {
        if (cr < p)
            return N;
        if (m2[c] < v)
            return N;
        if (cl == cr)
            return cl;
        int res = nextGE(p, v, c*2+1, cl, (cl+cr) / 2);
        if (res != N)
            return res;
        return nextGE(p, v, c*2+2, (cl+cr) / 2 + 1, cr);
    }
    int prevGE(int p, int v, int c = 0, int cl = 0, int cr = N - 1) {
        if (cl > p)
            return -1;
        if (m2[c] < v)
            return -1;
        if (cl == cr)
            return cl;
        int res = prevGE(p, v, c*2+2, (cl+cr) / 2 + 1, cr);
        if (res != -1)
            return res;
        return prevGE(p, v, c*2+1, cl, (cl+cr) / 2);
    }
};

void solve() {
    int n, k;
    static int a[N], b[N];
    static SegTree sa, sb;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    sa.build(a);
    sb.build(b);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int ml = sa.prevGE(i - 1, a[i]);
        int mr = min(sa.nextGE(i + 1, a[i] + 1), n);

        ml = max(ml, sb.prevGE(i, a[i] + k + 1));
        mr = min(mr, sb.nextGE(i, a[i] + k + 1));
        if (ml >= i || mr <= i)
            continue;

        int wl = sb.prevGE(i, a[i] - k);
        int wr = sb.nextGE(i, a[i] - k);

        wl = max(wl, ml);
        wr = min(wr, mr);

        ans += 1LL * (i - ml) * (mr - i) - 1LL * (i - wl) * (wr - i);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
