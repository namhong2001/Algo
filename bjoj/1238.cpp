#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;


int n;
vector<vector<pair<int,int>>> oadj;
vector<vector<pair<int,int>>> radj;


vector<int> dijkstra(int src, bool rev) {
    vector<vector<pair<int,int>>> &adj = rev ? radj : oadj;
    priority_queue<pair<int,int>> pq;
    vector<int> d(n, INF);
    d[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (cost > d[here]) continue;
        for (pair<int,int> t : adj[here]) {
            int there = t.first;
            int nc = t.second + cost;
            if (nc < d[there]) {
                d[there] = nc;
                pq.push({-nc, there});
            }
        }
    }
    return d;
}


int main() {
    int m, x;
    cin >> n >> m >> x;
    x--;
    oadj = vector<vector<pair<int,int>>>(n);
    radj = vector<vector<pair<int,int>>>(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        oadj[a].push_back({b, c});
        radj[b].push_back({a, c});
    }
    vector<int> d1 = dijkstra(x, false);
    vector<int> d2 = dijkstra(x, true);
    int ans = 0;
    for (int i=0; i<n; ++i) {
        ans = max(ans, d1[i] + d2[i]);
    }

    cout << ans << endl;

    return 0;
}
