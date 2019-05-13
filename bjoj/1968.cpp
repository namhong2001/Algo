#include <iostream>
#include <vector>

using namespace std;
vector<vector<bool>> adj;
vector<int> degree;

int n, m;

void dfs(int here, vector<int> &ans) {
    for (int there=1; there<=n; ++there) {
        if (adj[here][there]) {
            adj[here][there] = adj[there][here] = false;
            dfs(there, ans);
        }
    }
    ans.push_back(here);
}

vector<int> euler() {
    vector<int> ans;
    for (int i=1; i<=n; ++i) {
        if (degree[i] % 2 == 1) {
            dfs(i, ans);
            return ans;
        }
    }
    dfs(1, ans);
    return ans;
}

int main() {
    cin >> n >> m;
    adj = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
    degree = vector<int>(n+1, 0);
    for (int i=0; i<m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = adj[b][a] = true;
        degree[a]++;
        degree[b]++;
    }
    vector<int> ans = euler();
    for (int town : ans) {
        cout << town << '\n';
    }
    cout << -1;
    return 0;
}
