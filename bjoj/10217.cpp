#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pqitem {
    int d, c, here;
};
bool operator< (const pqitem &a, const pqitem &b) {
    return a.d < b.d;
}

struct adjitem {
    int v, c, d;
};


const int INF = 987654321;

vector<vector<adjitem>> adj;  // v, c, d;

int n, m, k;

int dijkstra() {
    vector<vector<int>> d(n, vector<int>(m+1, INF));
    priority_queue<pqitem> pq; // d, c, here
    d[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        int time = -pq.top().d;
        int cost = pq.top().c;
        int here = pq.top().here;
        pq.pop();
        if (d[here][cost] < time) continue;
        if (here == n-1) return time;

        for (adjitem &t : adj[here]) {
            int there = t.v;
            int nc = t.c + cost;
            int nt = t.d + time;
            if (nc > m) continue;
            if (nt < d[there][nc]) {
                for (int i=nc+1; i<m; ++i) {
                    if (d[there][i] <= nt) break;
                    d[there][i] = nt;
                }
                d[there][nc] = nt;
                pq.push({-nt, nc, there});
            }
        }
    }
    return INF;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        adj.clear();
        adj.resize(n);
        while (k--) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            u--, v--;
            adj[u].push_back({v, c, d});
        }
        int ans = dijkstra();
        if (ans == INF) cout << "Poor KCM" << '\n';
        else cout << ans << '\n';
    }

    return 0;
}
