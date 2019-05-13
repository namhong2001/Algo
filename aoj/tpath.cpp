#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

const int INF = 987654321;
typedef vector<int> vi;

vector<vi> edges;

vector<int> r;
int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}


int cnt = 0;
int n, m;
int kruskal(int lo) {
    r.clear();
    r.resize(n);
    for (int i=0; i<n; ++i) r[i] = i;

    for (int i=lo; i<m; ++i) {
        cnt++;
        vi &e = edges[i];
        int w = e[0];
        int a = e[1];
        int b = e[2];
        u(a, b);
        if (f(0) == f(n-1)) {
            return w - edges[lo][0];
        }
    }

    return INF;
}

int main() {
    clock_t BE, EN;
    BE = clock();
    int T;
    cin >> T;
    while (T--) {
        edges.clear();
        cin >> n >> m;
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        for (int i=0; i<m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            edges.push_back({c, a, b});
        }

        sort(edges.begin(), edges.end());

        int ans = INF;
        for (int i=0; i<m; ++i) {
            int t = kruskal(i);
            if (t == INF) break;
            ans = min(ans, t);
        }
        cout << "cnt : " << cnt << endl;
        cout << ans << endl;
    }
    EN = clock();
    cout << "time : " << 1000.0 * (EN-BE)/CLOCKS_PER_SEC << "ms" << endl;


    return 0;
}
