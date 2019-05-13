#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i=0; i<n; ++i) adj[i][i] = 1;
    while (k--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = 1;
    }
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                adj[i][j] |= adj[i][k] & adj[k][j];
            }
        }
    }
    int s;
    cin >> s;
    while (s--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (adj[a][b]) cout << -1 << '\n';
        else if (adj[b][a]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}
