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

ll ask(int x) {
    cout << x << "\n";
    cout.flush();
    ll y;
    cin >> y;
    return y;
}

void answer(ll *a) {
    cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] << "\n";
    cout.flush();
    int r;
    cin >> r;
    assert(r == 1);
}

void solve() {
    ll a[6];

    ll y = ask(56);
    a[0] = y >> 56;
    a[1] = (y >> 28) & 127;

    ll z = ask(170);
    a[2] = z >> 56;
    a[3] = (z >> 42) & 127;

    ll c11 = 4, c12 = 1;
    ll b1 = (y - (a[0] << 56) - (a[1] << 28) - (a[2] << 18) - (a[3] << 14)) >> 9;
    ll c21 = 1 << 6, c22 = 1;
    ll b2 = (z - (a[2] << 56) - (a[3] << 42)) >> 28;
    
    ll det = c11*c22 - c12*c21;
    a[4] = (b1*c22 - b2*c12) / det;
    a[5] = (b2*c11 - b1*c21) / det;

    answer(a);
}

int main() {
    ios::sync_with_stdio(false);

    int t, w;
    cin >> t >> w;
    for (int i = 1; i <= t; ++i) {
        solve();
    }

    return 0;
}
