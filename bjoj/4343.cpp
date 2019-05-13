#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef tuple<double, int, int> E;

vector<E> edges;
vector<pair<int,int>> points;

double dist (int a, int b) {
    int x1 = points[a].first;
    int y1 = points[a].second;
    int x2 = points[b].first;
    int y2 = points[b].second;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

vector<int> r;
int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}



int main() {
    int T;
    cin >> T;
    while (T--) {

        int s, p;
        cin >> s >> p;

        points.clear();
        edges.clear();
        r.resize(p);
        for (int i=0; i<p; ++i) r[i] = i;
        for (int i=0; i<p; ++i) {
            int x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }
        for (int i=0; i<p; ++i) {
            for (int j=i+1; j<p; ++j) {
                edges.push_back(E {dist(i,j), i, j});
            }
        }
        sort(edges.begin(), edges.end());
        vector<E> mst;
        for (E &e : edges) {
            double d;
            int a, b;
            tie(d, a, b) = e;
            if (f(a) != f(b)) {
                u(a, b);
                mst.push_back(e);
            }
        }
        double ans = 0;
        if (mst.size()-s >= 0) ans = get<0>(mst[mst.size()-s]);
        cout << fixed << setprecision(2) << ans << '\n';
    }
    return 0;
}
