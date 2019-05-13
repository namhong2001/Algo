#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
stack<int> topological;

int n, m;

void dfs(int here) {
    visited[here] = true;
    for (int there : adj[here]) {
        if (!visited[there]) dfs(there);
    }
    topological.push(here);
}

int solve() {
    visited = vector<bool>(n, false);
    topological = stack<int>();

    for (int i=0; i<n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    fill(visited.begin(), visited.end(), false);
    int cnt = 0;
    while (!topological.empty()) {
        int here = topological.top();
        topological.pop();
        if (!visited[here]) {
            dfs(here);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        adj = vector<vector<int>>(n);
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
        }
        cout << solve() << endl;
    }
    return 0;
}
