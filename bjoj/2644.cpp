#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N_MAX = 100;

vector<int> edges[N_MAX+1];

int n, u, v, m;
int ans = -1;

bool dfs(int me, int parent, int cost) {
    if (me == v) {
        ans = cost;
        return true;
    }
    for (int child : edges[me]) {
        if (child == parent) continue;
        if (dfs(child, me, cost+1)) return true;
    }
    return false;
}

void bfs(int root) {
    int costs[N_MAX+1];
    memset(costs, 0, sizeof(costs));
    queue<int> que;
    que.push(root);
    while (!que.empty()) {
        int me = que.front();
        que.pop();
        int cost = costs[me];
        if (me == v) {
            ans = cost;
            return;
        }
        for (int child : edges[me]) {
            if (costs[child] != 0) continue;
            que.push(child);
            costs[child] = cost+1;
        }
    }
}

int main() {
    cin >> n >> u >> v >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
//    dfs(u, u, 0);
    bfs(u);
    cout << ans;
    return 0;
}
