#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

/*** START OF TEMPLATE CODE ***/

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

template<class T>
vector<T> splitstr(const string &s)
{
    istringstream in(s);
    vector<T> out;
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
    return out;
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void solve_case(int cas);

int main(int argc, char * const *argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    struct rlimit stack_limit;
    getrlimit(RLIMIT_STACK, &stack_limit);
    stack_limit.rlim_cur = 1024 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &stack_limit);

    if (argc >= 2)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }
    if (argc >= 3)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }
    cin.exceptions(ios::failbit | ios::badbit);

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; cas++)
        solve_case(cas);
    return 0;
}

/*** END OF TEMPLATE CODE ***/

struct person
{
    int xy[2];
    char d;
};

static const char dirs[2][2] = {{'W', 'E'}, {'S', 'N'}};

static void solve_case(int cas)
{
    int P, Q;
    cin >> P >> Q;
    vector<person> peop(P);
    for (int i = 0; i < P; i++)
    {
        cin >> peop[i].xy[0] >> peop[i].xy[1] >> peop[i].d;
    }

    int ans[2];
    for (int axis = 0; axis < 2; axis++)
    {
        set<int> cand;
        cand.insert(0);
        for (const person &p : peop)
        {
            if (p.xy[axis] > 0)
                cand.insert(p.xy[axis] - 1);
            cand.insert(p.xy[axis]);
            if (p.xy[axis] < Q)
                cand.insert(p.xy[axis] + 1);
        }
        int best = 0;
        int bests = -1;
        for (int x : cand)
        {
            int score = 0;
            for (const person &p : peop)
            {
                if (p.d == dirs[axis][0])
                    score += x < p.xy[axis];
                else if (p.d == dirs[axis][1])
                    score += x > p.xy[axis];
            }
            if (score > bests)
            {
                bests = score;
                best = x;
            }
        }
        ans[axis] = best;
    }
    cout << "Case #" << cas << ": " << ans[0] << ' ' << ans[1] << "\n";
}
