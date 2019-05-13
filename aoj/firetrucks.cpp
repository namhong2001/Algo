#include <iostream>
#include <queue>
#include <limits>
#include <vector>
#include <utility>

using namespace std;

const int INF = numeric_limits<int>::max();


int v, e, n, m;

vector<vector<pair<int,int>>> adj;


int dijkstra(vector<int> &starts, vector<int> &ends) {
    priority_queue<pair<int,int>> pq;
    vector<int> dist(v, INF);
    for (int s : starts) {
        dist[s] = 0;
        pq.push({0, s});
    }
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[here] < cost) continue;
        for (auto t : adj[here]) {
            int there = t.first;
            int weight = t.second;
            int n_d = cost + weight;
            if (n_d < dist[there]) {
                dist[there] = n_d;
                pq.push({-n_d, there});
            }
        }
    }
    int ans = 0;
    for (int e : ends) {
        ans += dist[e];
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> v >> e >> n >> m;
        adj.clear();
        adj.resize(v);
        for (int i=0; i<e; ++i) {
            int a, b, t;
            cin >> a >> b >> t;
            a--, b--;
            adj[a].push_back({b, t});
            adj[b].push_back({a, t});
        }
        vector<int> starts;
        vector<int> ends;
        for (int i=0; i<n; ++i) {
            int a;
            cin >> a;
            a--;
            ends.push_back(a);
        }
        for (int i=0; i<m; ++i) {
            int a;
            cin >> a;
            a--;
            starts.push_back(a);
        }
        cout << dijkstra(starts, ends) << endl;
    }


    return 0;
}
