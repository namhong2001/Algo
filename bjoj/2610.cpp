#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

vector<int> r;
int f(int a) {
    return r[a] = r[a] == a ? a : f(r[a]);
}

void u(int a, int b) {
    a = f(a);
    b = f(b);
    r[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;
    r.resize(n);
    for (int i=0; i<n; ++i) r[i] = i;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    for (int i=0; i<n; ++i) adj[i][i] = 0;
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = 1;
        u(a, b);
    }
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    vector<vector<pair<int,int>>> candi(n);
    for (int i=0; i<n; ++i) {
        int l_max = 0;
        for (int j=0; j<n; ++j) {
            if (adj[i][j] == INF) continue;
            l_max = max(l_max, adj[i][j]);
        }
        candi[f(i)].push_back({l_max, i});
    }

    int cnt=0;
    for (int i=0; i<n; ++i) {
        if (!candi[i].empty()) {
            sort(candi[i].begin(), candi[i].end());
            cnt++;
        }
    }
    cout << cnt << endl;
    vector<int> ans;
    for (int i=0; i<n; ++i) {
        if (!candi[i].empty()) {
            ans.push_back(candi[i][0].second+1);
        }
    }
    sort(ans.begin(), ans.end());
    for (int a : ans) {
        cout << a << endl;
    }


    return 0;
}
