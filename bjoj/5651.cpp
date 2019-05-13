#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>


using namespace std;

const int INF = 987654321;

vector<vector<int>> capacity, flow;
vector<unordered_set<int>> adj;
vector<vector<int>> edge_cnt;


int n, m;
void network_flow(int s, int t) {
    while (true) {
        queue<int> q;
        vector<int> parent(n, -1);
        q.push(s);
        parent[s] = s;
        while (!q.empty() && parent[t] == -1) {
            int here = q.front(); q.pop();
            for (int there : adj[here]) {
                if (capacity[here][there] - flow[here][there] > 0 &&
                    parent[there] == -1) {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if (parent[t] == -1) break;
        int path_min = INF;
        for (int p=t; p!=s; p=parent[p]) {
            path_min = min(path_min, capacity[parent[p]][p]-flow[parent[p]][p]);
        }
        for (int p=t; p!=s; p=parent[p]) {
            flow[parent[p]][p] += path_min;
            flow[p][parent[p]] -= path_min;
        }
    }
}


vector<int> r;
const int SET_S = 1;
const int SET_T = 2;

void dfs(int here, int sink, vector<pair<int,int>> &cut) {
    if (r[here] == SET_S) return;
    r[here] = SET_S;
    if (here == sink) return;
    for (int there : adj[here]) {
        if (r[there] == SET_T) {
            if (capacity[here][there] - flow[here][there] > 0) {
                dfs(there, sink, cut);
            } else if (capacity[here][there] > 0) {
                cut.push_back({here, there});
            }
        }
    }
}

int count_crucial_edge(int s, int t) {
    int ret = 0;
    r.assign(n, SET_T);
    vector<pair<int,int>> cut = {{s, s}};
    while (!cut.empty()) {
        vector<pair<int,int>> candi_cut;
        for (pair<int,int> &p : cut) {
            dfs(p.second, t, candi_cut);
        }
        vector<pair<int,int>> next_cut;
        for (pair<int,int> &p : candi_cut) {
            if (r[p.first] == SET_S && r[p.second] == SET_T) {
                ret += edge_cnt[p.first][p.second];
                if (p.second != t) {
                    next_cut.push_back(p);
                }
            }
        }
        swap(cut, next_cut);
    }
    return ret;
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
            capacity[u][v] += w;
            edge_cnt[u][v]++;
            adj[u].insert(v);
            adj[v].insert(u);

        }
        network_flow(0, n-1);
        cout << count_crucial_edge(0, n-1) << '\n';
    }
    return 0;
}
