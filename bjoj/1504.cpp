#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 87654321;

int n, e;
vector<vector<pair<int,int>>> adj;
int dijkstra(int src, int dst) {
    priority_queue<pair<int,int>> pq;
    vector<int> d(n, INF);
    pq.push({0, src});
    d[src] = 0;
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (d[here] < cost) continue;
        for (pair<int,int> t : adj[here]) {
            int there = t.first;
            int n_cost = cost + t.second;
            if (d[there] > n_cost) {
                d[there] = n_cost;
                pq.push({-n_cost, there});
            }
        }
    }
    return d[dst];
}

int main() {
    cin >> n >> e;
    adj.resize(n);
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int v, u;
    cin >> v >> u;
    v--, u--;
    int dvu = dijkstra(v, u);
    int dsv = dijkstra(0, v);
    int dsu = dijkstra(0, u);
    int deu = dijkstra(n-1, u);
    int dev = dijkstra(n-1, v);

    int ans = min(dsu + dvu + dev, dsv + dvu + deu);
    cout << (ans > INF ? -1 : ans) << endl;
    return 0;
}
