#include <iostream>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <limits>
#include <iomanip>

using namespace std;

const double INF = numeric_limits<double>::max()/2;

vector<vector<double>> adj;

double sx, sy, dx, dy;
int n;
double dijkstra() {
    priority_queue<pair<double, int>> pq;
    vector<double> d(n+2, INF);
    pq.push({0, 0});
    d[0] = 0;
    while (!pq.empty()) {
        int here = pq.top().second;
        double cost = -pq.top().first;
        pq.pop();
        if (d[here] < cost) continue;
        for (int there=0; there<n+2; ++there) {
            double nc = cost + adj[here][there];
            if (nc < d[there]) {
                d[there] = nc;
                pq.push({-nc, there});
            }
        }
    }
    return d[n+1];
}


double getdist(pair<double,double> &a, pair<double,double> &b) {
    return sqrt(pow(a.first-b.first, 2)+pow(a.second-b.second, 2));
}

int main() {
    cin >> sx >> sy >> dx >> dy;
    cin >> n;
    vector<pair<double,double>> p(n+2);
    p[0] = {sx, sy};
    p[n+1] = {dx, dy};

    for (int i=1; i<=n; ++i) {
        double x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    adj = vector<vector<double>>(n+2, vector<double>(n+2));
    for (int i=0; i<n+2; ++i) {
        for (int j=0; j<n+2; ++j) {
            double dist = getdist(p[i], p[j]);
            double time = dist/5;
            if (i != 0 && i != n+1) {
                double cannontime = 2;
                double cannondist = abs(dist - 50);
                cannontime += cannondist/5;
                time = min(time, cannontime);
            }
            adj[i][j] = time;
        }
    }
    cout << fixed << setprecision(10) << dijkstra() << endl;
    return 0;
}
