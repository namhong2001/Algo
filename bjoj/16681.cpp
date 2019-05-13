#include <iostream>
#include <vector>
#include <queue>


using namespace std;
typedef long long ll;

const ll INF = 987654321987654321;

vector<vector<pair<int,int>>> adj;
vector<int> h;

int N, M, D, E;
vector<ll> dijkstra(int src) {
    priority_queue<pair<ll,int>> pq;
    vector<ll> d(N, INF);
    d[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int here = pq.top().second;
        ll cost = -pq.top().first;
        pq.pop();
        if (d[here] < cost) continue;
        for (pair<int,int> t : adj[here]) {
            int there = t.first;
            ll nc = t.second + cost;
            if (h[there] > h[here] && nc < d[there]) {
                d[there] = nc;
                pq.push({-nc, there});
            }
        }
    }
    return d;
}


int main() {
    cin >> N >> M >> D >> E;

    h = vector<int>(N);
    for (int i=0; i<N; ++i) {
        cin >> h[i];
    }
    adj = vector<vector<pair<int,int>>>(N);
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<ll> d1 = dijkstra(0);
    vector<ll> d2 = dijkstra(N-1);
    ll ans = -INF;
    for (int i=1; i<N-1; ++i) {
        if (d1[i] != INF && d2[i] != INF) {
            ans = max(ans, h[i]*E-(d1[i]+d2[i])*D);
        }
    }
    if (ans == -INF) cout << "Impossible" << endl;
    else cout << ans << endl;

    return 0;
}
