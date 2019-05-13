#include <iostream>
#include <vector>


using namespace std;

const int INF = 987654321;

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v, vector<int>(v, INF));
    for (int i=0; i<v; ++i) adj[i][i] = 0;
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a][b] = min(adj[a][b], c);
    }
    for (int k=0; k<v; ++k) {
        for (int i=0; i<v; ++i) {
            for (int j=0; j<v; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    int ans = INF;
    for (int i=0; i<v; ++i) {
        for (int j=i+1; j<v; ++j) {
            ans = min(ans, adj[i][j] + adj[j][i]);
        }
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
