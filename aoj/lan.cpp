#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>

using namespace std;

typedef tuple<double,int,int> E;

vector<int> xpos;
vector<int> ypos;
vector<int> r;

int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

void u(int a, int b) {
    a = f(a), b = f(b);
    r[a] = b;
}

double dist(int a, int b) {
    return sqrt((xpos[a]-xpos[b])*(xpos[a]-xpos[b]) + (ypos[a]-ypos[b])*(ypos[a]-ypos[b]));
}

vector<E> edges; // dist, a, b

double kruskal() {
    double ret = 0;
    for (E &t : edges) {
        double dist;
        int a, b;
        tie(dist, a, b) = t;
        if (f(a) == f(b)) continue;
        u(a, b);
        ret += dist;
    }
    return ret;
}



int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        xpos.clear();
        ypos.clear();
        r.clear();
        r.resize(n);
        edges.clear();

        for (int i=0; i<n; ++i) r[i] = i;
        for (int i=0; i<n; ++i) {
            int x;
            cin >> x;
            xpos.push_back(x);
        }
        for (int i=0; i<n; ++i) {
            int y;
            cin >> y;
            ypos.push_back(y);
        }
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            u(a, b);
        }
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (f(i) != f(j)) {
                    edges.push_back(E {dist(i, j), i, j});
                }
            }
        }
        sort(edges.begin(), edges.end());
        cout << fixed << setprecision(10) << kruskal() << endl;
    }


    return 0;
}
