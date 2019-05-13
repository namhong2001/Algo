#include <iostream>
#include <vector>
#include <utility>
#include <queue>


using namespace std;

const int INF = 987654321;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
    }
    int s, e;
    cin >> s >> e;
    s--, e--;
    priority_queue<pair<int,int>> pq;
    vector<int> d(n, INF);
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (d[here] < cost) continue;
        for (pair<int,int> t : adj[here]) {
            int there = t.first;
            int weight = t.second;
            int n_cost = d[here] + weight;
            if (n_cost < d[there]) {
                d[there] = n_cost;
                pq.push({-n_cost, there});
            }
        }
    }
    cout << d[e] << endl;

    return 0;
}
