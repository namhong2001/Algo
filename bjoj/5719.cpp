#include <iostream>
#include <vector>
#include <queue>


using namespace std;

const int INF = 987654321;



int n, m;
vector<int> d;
vector<vector<int>> p;
int dijkstra(int src, int dst, vector<vector<int>> adj) {
    priority_queue<pair<int,int>> pq;
    d = vector<int>(n, INF);
    p = vector<vector<int>>(n);
    d[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (d[here] < cost) continue;
        for (int there=0; there<n; ++there) {
            if (here == there) continue;
            int nc = adj[here][there] + cost;
            if (nc < d[there]) {
                p[there].clear();
                p[there].push_back(here);
                d[there] = nc;
                pq.push({-nc, there});
            } else if (nc == d[there]) {
                p[there].push_back(here);
            }
        }
    }
    return d[dst];
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        int s, d;
        cin >> s >> d;

        vector<vector<int>> adj(n, vector<int>(n, INF));
        for (int i=0; i<n; ++i) adj[i][i] = 0;
        while (m--) {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u][v] = p;
        }
        dijkstra(s, d, adj);
        vector<bool> visited(n, false);
        queue<int> q;
        for (int a : p[d]) {
            adj[a][d] = INF;
            q.push(a);
            visited[a] = true;
        }
        while (!q.empty()) {
            int here = q.front();
            q.pop();
            for (int a : p[here]) {
                adj[a][here] = INF;
                if (!visited[a]) q.push(a);
                visited[a] = true;
            }
        }
        int ans = dijkstra(s, d, adj);
        if (ans == INF) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}
