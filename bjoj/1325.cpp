#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> adj;

//int dp[10001];

int solve(int node, bool visited[10001]) {
    if (visited[node]) return 0;

    visited[node] = true;

//    int &ret = dp[node];

//    if (ret != -1) return ret;

    int ret = 1;
    for (int i=0; i<adj[node].size(); ++i) {
        int there = adj[node][i];
        ret += solve(there, visited);
    }
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
//    memset(dp, -1, sizeof(dp));
    for (int i=0; i<m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[y].push_back(x);
    }

    int max_cnt = 0;
    vector<int> ans;
    bool visited[10001];
    for (int i=1; i<=n; ++i) {
        memset(visited, false, sizeof(visited));
        int cnt = solve(i, visited);
        if (cnt == max_cnt) {
            ans.push_back(i);
        } else if (cnt > max_cnt) {
            max_cnt = cnt;
            ans.clear();
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    for (int node : ans) {
        cout << node << ' ';
    }
    return 0;
}
