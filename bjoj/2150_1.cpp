#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


int v, e;
vector<vector<int>> adj;
vector<vector<int>> adj_r;

stack<int> topol;
void dfs_1(int here, vector<bool> &visited) {
    visited[here] = true;
    for (int there : adj[here]) {
        if (!visited[there]) {
            dfs_1(there, visited);
        }
    }
    topol.push(here);
}

void dfs_2(int here, vector<bool> &visited, vector<int> &ans) {
    visited[here] = true;
    for (int there : adj_r[here]) {
        if (!visited[there]) {
            dfs_2(there, visited, ans);
        }
    }
    ans.push_back(here);
}


vector<vector<int>> solve() {
    vector<vector<int>> scc;

    vector<bool> visited(v, false);
    for (int i=0; i<v; ++i) {
        if (!visited[i]) {
            dfs_1(i, visited);
        }
    }
    visited.assign(v, false);
    while (!topol.empty()) {
        int here = topol.top();
        topol.pop();
        if (visited[here]) continue;
        vector<int> scc_vertices;
        dfs_2(here, visited, scc_vertices);
        scc.push_back(scc_vertices);
    }
    return scc;
}



int main() {
    cin >> v >> e;
    adj = vector<vector<int>>(v);
    adj_r = vector<vector<int>>(v);
    for (int i=0; i<e; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj_r[b].push_back(a);
    }
    vector<vector<int>> ans = solve();
    for (vector<int> &arr : ans) {
        sort(arr.begin(), arr.end());
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto arr : ans) {
        for (int item : arr) {
            cout << item+1 << ' ';
        }
        cout << "-1" << '\n';
    }
    return 0;
}
