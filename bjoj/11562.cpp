#include <iostream>
#include <vector>

using namespace std;


const int INF = 987654321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    for (int i=0; i<n; ++i) adj[i][i] = 0;
    while (m--) {
        int u, v, b;
        cin >> u >> v >> b;
        u--, v--;
        adj[u][v] = 0;
        adj[v][u] = b == 0 ? 1 : 0;
    }
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        cout << adj[s][e] << '\n';
    }


    return 0;
}
