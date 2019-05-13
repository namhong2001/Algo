#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[32001];
bool visited[32001];

void dfs(int here, vector<int> &ans) {
    visited[here] = true;
    for (int there : adj[here]) {
        if (!visited[there]) {
            dfs(there, ans);
        }
    }
    ans.push_back(here);
}

vector<int> topological_sort() {
    vector<int> ans;
    for (int i=1; i<=n; ++i) {
        if (!visited[i]) {
            dfs(i, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> ans = topological_sort();
    for (int here : ans) {
        cout << here << ' ';
    }
    return 0;
}
