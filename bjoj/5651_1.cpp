#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>


using namespace std;

const int INF = 987654321;

vector<vector<int>> capacity, flow;
vector<unordered_set<int>> adj;
vector<vector<int>> edge_cnt;


vector<int> visited;
int dfs(int here, int sink, int path_min, bool for_check) {
    visited[here] = true;
    if (here == sink) return path_min;
    for (int there : adj[here]) {
        int residual = capacity[here][there] - flow[here][there];
        int new_min = min(path_min, residual);
        if (!visited[there] && residual > 0) {
            int f = dfs(there, sink, new_min, for_check);
            if (f > 0) {
                if (!for_check) {
                    flow[here][there] += f;
                    flow[there][here] -= f;
                }
                return f;
            }
        }
    }
    return 0;
}


int n, m;
void network_flow(int s, int t) {
    while (true) {
        visited.assign(n, false);
        if (dfs(s, t, INF, false) == 0) break;
    }
}

int count_crucial_edge() {
    int cnt = 0;
    for (int here=0; here<n; ++here) {
        for (int there : adj[here]) {
            if (capacity[here][there] > 0 && capacity[here][there] == flow[here][there]) {
                visited.assign(n, false);
                if (dfs(here, there, INF, true) == 0) {
                    cnt += edge_cnt[here][there];
                }
            }
        }
    }
    return cnt;
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        cin >> n >> m;
        capacity = vector<vector<int>>(n, vector<int>(n, 0));
        flow = vector<vector<int>>(n, vector<int>(n, 0));
        edge_cnt = vector<vector<int>>(n, vector<int>(n, 0));
        adj.clear();
        adj.resize(n);
        for (int i=0; i<m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u].insert(v);
            adj[v].insert(u);
            capacity[u][v] += w;
            edge_cnt[u][v]++;
        }
        network_flow(0, n-1);
        cout << count_crucial_edge() << '\n';
    }
    return 0;
}
