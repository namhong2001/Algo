#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int INF = 987654321;

vector<pair<int,int>> edges;

int dijkstra() {
    vector<int> dist(400, INF);
    priority_queue<pair<int,int>> pq;
    for (auto e : edges) {
        pq.push({-e.first, e.second+200});
        dist[e.second+200] = e.first;
    }
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[here] < cost) continue;
        if (here == 200) return cost;
        for (auto e : edges) {
            int there = here + e.second;
            if (there < 0 || there >= 400) continue;
            int nd = cost + e.first;
            if (nd < dist[there]) {
                dist[there] = nd;
                pq.push({-nd, there});
            }
        }
    }
    return -1;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int m;
        cin >> m;
        edges.clear();
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            edges.push_back({a, a-b});
        }
        int ans = dijkstra();
        if (ans == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
