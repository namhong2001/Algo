#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<ll> vll; // cost, k, here
const ll INF = 987654321987654321;

vector<vector<pair<int,int>>> adj;

int N, M, K;
ll dijkstra() {
    vector<vector<ll>> d(N, vector<ll>(K, INF));
    priority_queue<vll> pq;
    pq.push({0, 0, 0});
    d[0][0] = 0;
    while (!pq.empty()) {
        ll cost = -pq.top()[0];
        int k = pq.top()[1];
        int here = pq.top()[2];
        pq.pop();
        if (d[here][k] < cost) continue;
        for (pair<int,int> t : adj[here]) {
            int there = t.first;
            ll nc = t.second + cost;
            if (d[there][k] > nc) {
                d[there][k] = nc;
                pq.push({-nc, k, there});
            }
            if (k < K-1 && d[there][k+1] > cost) {
                d[there][k+1] = cost;
                pq.push({-cost, k+1, there});
            }
        }
    }
    ll ans = INF;
    for (int i=0; i<K; ++i) {
        ans = min(ans, d[N-1][i]);
    }
    return ans;
}

int main() {
    cin >> N >> M >> K;
    K++;
    adj.resize(N);
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cout << dijkstra() << endl;
}

