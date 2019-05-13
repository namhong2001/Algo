#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, w;
        cin >> n >> m >> w;
        vector<vector<pair<int,int>>> adj(n);
        while (m--) {
            int s, e, t;
            cin >> s >> e >> t;
            s--, e--;
            adj[s].push_back({e, t});
            adj[e].push_back({s, t});
        }
        while (w--) {
            int s, e, t;
            cin >> s >> e >> t;
            s--, e--;
            adj[s].push_back({e, -t});
        }
        vector<int> dist(n, INF);
        dist[0] = 0;
        for (int iter=0; iter<n-1; ++iter) {
            for (int here=0; here<n; ++here) {
                for (pair<int,int> t : adj[here]) {
                    int there = t.first;
                    int weight = t.second;
                    dist[there] = min(dist[there], dist[here] + weight);
                }
            }
        }
        string ans = "NO";
        for (int here=0; here<n; ++here) {
            for (pair<int,int> t : adj[here]) {
                int there = t.first;
                int weight = t.second;
                if (dist[there] > dist[here] + weight) {
                    ans = "YES";
                    break;
                }
            }
            if (ans == "YES") break;
        }
        cout << ans << '\n';
    }

    return 0;
}
