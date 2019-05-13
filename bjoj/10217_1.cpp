#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef vector<int> vi;

const int INF = 987654321;

vector<vector<vi>> adj;  // v, c, d;

int n, m, k;

int dijkstra() {
    int d[n][m+1];
    memset(d, -1, sizeof(d));
    priority_queue<vi> pq; // d, c, here
    d[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        int time = -pq.top()[0];
        int cost = pq.top()[1];
        int here = pq.top()[2];
        pq.pop();
        if (d[here][cost] < time) continue;
        if (here == n-1) return time;

        for (vi &t : adj[here]) {
            int there = t[0];
            int nc = t[1] + cost;
            int nt = t[2] + time;
            if (nc > m) continue;
            if (d[there][nc] == -1 || nt < d[there][nc]) {
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
