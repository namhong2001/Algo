#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct E {
    double d;
    int a, b;
};
bool operator < (const E &a, const E &b) {
    return a.d < b.d;
}

struct P {
    int x, y, r;
};

vector<P> points;
vector<E> edges;

vector<int> r;
int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}


double dist(int a, int b) {
    P &p1 = points[a];
    P &p2 = points[b];
    double d = sqrt(1ll*(p1.x-p2.x)*(p1.x-p2.x) + 1ll*(p1.y-p2.y)*(p1.y-p2.y));
    double ret = d-p1.r-p2.r;
    if (ret < 0 ) ret = 0;
    return ret;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int w, n;
        cin >> w >> n;
        points.clear();
        edges.clear();
        r.resize(n+2);
        for (int i=0; i<n+2; ++i) r[i] = i;
        for (int i=0; i<n; ++i) {
            int x, y, r;
            cin >> x >> y >> r;
            points.push_back({x, y, r});
        }
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                edges.push_back(E {dist(i, j), i, j});
            }
        }
        for (int i=0; i<n; ++i) {
            P &p = points[i];
            double d1 = w-p.x-p.r;
            double d2 = p.x-p.r;
            d1 = max(d1, 0.0);
            d2 = max(d2, 0.0);
            edges.push_back(E {d1, n, i});
            edges.push_back(E {d2, n+1, i});
        }
        edges.push_back(E {(double)w, n, n+1});
        sort(edges.begin(), edges.end());
        double ans;
        double total = 0;
        for (E &e : edges) {
            int a = e.a;
            int b = e.b;
            double d = e.d;
            if (f(a) == f(b)) continue;

            u(a, b);
            total += d;
//            if (f(n) == f(n+1)) {
//                ans = d;
//                break;
//            }
        }
        cout << total << endl;
//        cout << fixed << setprecision(10) << ans/2 << '\n';
    }

    return 0;
}
