#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 987654321;

vector<vector<int>> capacity(52, vector<int>(52, 0));
vector<vector<int>> flow(52, vector<int>(52, 0));
vector<vector<int>> adj(52);

int get_id(string &s) {
    char c = s[0];
    if ('A' <= c && c <= 'Z') return c-'A';
    if ('a' <= c && c <= 'z') return c-'a'+26;
    return -1;
}

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


int network_flow(int s, int t) {
    int total = 0;
    while (true) {
        visited.assign(52, false);
        int f = dfs(s, t, INF, false);
        total += f;
        if (f == 0) break;
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        string a, b;
        int c;
        cin >> a >> b >> c;
        int aid = get_id(a);
        int bid = get_id(b);
        capacity[aid][bid] += c;
        capacity[bid][aid] += c;
        adj[aid].push_back(bid);
        adj[bid].push_back(aid);
    }
    cout << network_flow(0, 25);
    return 0;
}

