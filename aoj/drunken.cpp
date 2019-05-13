#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int INF = 987654321;

int v, e;
vector<int> drunk_cost;
vector<vector<int>> adj;
vector<vector<int>> dist;
vector<vector<int>> ans;


void floyd() {
    worst = vector<vector<int>>(v, vector<int>(v, 0));
    ans = dist = adj;
    vector<pair<int,int>> order;
    for (int i=0; i<v; ++i) {
        order.push_back({drunk_cost[i], i});
    }
    sort(order.begin(), order.end());
    for (int k=0; k<v; ++k) {
        int w = order[k].second;
        for (int i=0; i<v; ++i) {
            for (int j=0; j<v; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][w] + dist[w][j]);
                ans[i][j] = min(ans[i][j], dist[i][w] + drunk_cost[w] + dist[w][j]);
            }
        }
    }
}

int main() {
    cin >> v >> e;
    drunk_cost = vector<int>(v);
    adj = vector<vector<int>>(v, vector<int>(v, INF));
    for (int i=0; i<v; ++i) cin >> drunk_cost[i];
    for (int i=0; i<v; ++i) adj[i][i] = 0;
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a][b] = adj[b][a] = c;
    }
    floyd();
    int T;
    cin >> T;
    while (T--) {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        cout << ans[s][t]<< endl;
    }
    return 0;
}
