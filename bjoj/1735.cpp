#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 987654321;

int main() {
    int V, E, s;
    cin >> V >> E >> s;
    s--;
    vector<vector<pair<int,int>>> adj(V);
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }
    priority_queue<pair<int,int>> pq;
    vector<int> d(V, INF);
    pq.push({0, s});
    d[s] = 0;
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (d[here] < cost) continue;
        for (pair<int,int> t : adj[here]) {
            int there = t.first;
            int weight = t.second;
            int n_cost = d[here] + weight;
            if (d[there] > n_cost) {
                pq.push({-n_cost, there});
                d[there] = n_cost;
            }
        }
    }
    for (int i=0; i<V; ++i) {
        if (i == s) cout << 0 << '\n';
        else if (d[i] == INF) cout << "INF" << '\n';
        else cout << d[i] << '\n';
    }

    return 0;
}
