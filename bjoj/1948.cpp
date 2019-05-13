#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int n, m;
vector<vector<pair<int,int>>> adj;
vector<int> indegree;
vector<int> cost;
vector<vector<int>> parent;

void solve(int s) {
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (pair<int,int> cur : adj[here]) {
            int there = cur.first;
            int weight = cur.second;
            int here_cost = cost[here];
            int there_cost = cost[there];

            if (here_cost + weight > there_cost) {
                cost[there] = here_cost + weight;
                parent[there].clear();
                parent[there].push_back(here);
            } else if (here_cost + weight == there_cost) {
                parent[there].push_back(here);
            }
            if (--indegree[there] == 0) {
                q.push(there);
            }
        }
    }
}

int count_roads(int e) {
    vector<bool> visited(n+1, false);
    int ret = 0;
    queue<int> q;
    q.push(e);
    visited[e] = true;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (int p : parent[here]) {
            ++ret;
            if (!visited[p]) {
                q.push(p);
                visited[p] = true;
            }
        }
    }
    return ret;
}


int main() {
    cin >> n >> m;
    adj = vector<vector<pair<int,int>>>(n+1);
    indegree = vector<int>(n+1, 0);
    cost = vector<int>(n+1, 0);
    parent = vector<vector<int>>(n+1);

    for (int i=0; i<m; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        adj[s].push_back({e, w});
        indegree[e]++;
    }
    int s, e;
    cin >> s >> e;
    solve(s);
    cout << cost[e] << '\n' << count_roads(e) << endl;

    return 0;
}
