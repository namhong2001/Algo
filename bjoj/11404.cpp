#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

const int INF = 987654321;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    for (int i=0; i<n; ++i) adj[i][i] = 0;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a][b] = min(adj[a][b], c);
    }
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (adj[i][j] > INF/2) cout << 0 << ' ';
            else cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
