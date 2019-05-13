#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

typedef tuple<double, int, int> E;

vector<E> edges;
vector<pair<double, double>> points;

double get_dist(int a, int b) {
    double x1 = points[a].first;
    double y1 = points[a].second;
    double x2 = points[b].first;
    double y2 = points[b].second;
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
    int n;
    cin >> n;
    edges.clear();
    points.clear();
    r.resize(n);
    for (int i=0; i<n; ++i) r[i] = i;
    for (int i=0; i<n; ++i) {
        double x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            edges.push_back(E {get_dist(i, j), i, j});
        }
    }
    sort(edges.begin(), edges.end());
    double ans = 0;
    for (E &e : edges) {
        double d;
        int a, b;
        tie(d, a, b) = e;
        if (f(a) != f(b)) {
            u(a, b);
            ans += d;
        }
    }
    cout << fixed << setprecision(5) << ans << '\n';

    return 0;
}
