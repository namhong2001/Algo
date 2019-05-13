#include <iostream>
#include <iomanip>
#include <queue>
#include <limits>
#include <utility>
#include <vector>

using namespace std;

const double INF = numeric_limits<double>::max();

vector<vector<pair<int,double>>> adj;

int n, m;

double dijkstra() {
    priority_queue<pair<double,int>> pq;
    vector<double> dist(n, INF);
    pq.push({-1,0});
    dist[0] = 1;
    while (!pq.empty()) {
        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i=0; i<adj[here].size(); ++i) {
            int there = adj[here][i].first;
            double n_dist = dist[here] * adj[here][i].second;
            if (n_dist < dist[there]) {
                dist[there] = n_dist;
                pq.push({-n_dist, there});
            }
        }
    }
    return dist[n-1];
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        adj.clear();
        adj.resize(n);
        for (int i=0; i<m; ++i) {
            int a, b;
            double c;
            cin >> a >> b >> c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        cout << fixed << setprecision(10) << dijkstra() << endl;
    }

    return 0;
}
