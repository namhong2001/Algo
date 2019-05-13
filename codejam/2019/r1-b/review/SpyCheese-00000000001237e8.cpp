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

void solve() {
    int n, s;
    cin >> n >> s;
    ++s;
    vector<int> s1(s, 0), s2(s, 0), s3(s, 0), s4(s, 0);
    for (int i = 0; i < n; ++i) {
        int x, y;
        string t;
        cin >> x >> y >> t;
        if (t == "E") ++s1[x + 1];
        if (t == "N") ++s2[y + 1];
        if (t == "W") ++s3[x - 1];
        if (t == "S") ++s4[y - 1];
    }
    for (int i = 0; i < s - 1; ++i)
        s1[i + 1] += s1[i];
    for (int i = 0; i < s - 1; ++i)
        s2[i + 1] += s2[i];
    for (int i = s - 1; i > 0; --i)
        s3[i - 1] += s3[i];
    for (int i = s - 1; i > 0; --i)
        s4[i - 1] += s4[i];

    int bx = 0;
    for (int i = 1; i < s; ++i)
        if (s1[i] + s3[i] > s1[bx] + s3[bx])
            bx = i;
    int by = 0;
    for (int i = 1; i < s; ++i)
        if (s2[i] + s4[i] > s2[by] + s4[by])
            by = i;
    cout << bx << " " << by << "\n";
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
