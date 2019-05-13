#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
    int n, s, e, m;
    cin >> n >> s >> e >> m;
    vector<vector<int>> adj(n, vector<int>(n, -INF));
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = max(adj[a][b], -c);
    }
    vector<int> earn(n);
    for (int i=0; i<n; ++i) {
        cin >> earn[i];
        for (int j=0; j<n; ++j) {
            if (adj[j][i] != -INF) {
                adj[j][i] += earn[i];
            }
        }
    }
    for (int i=0; i<n; ++i) adj[i][i] = max(adj[i][i], 0);
    bool cycle = false;
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            if (i == k) continue;
            for (int j=0; j<n; ++j) {
                if (j == k) continue;
                adj[i][j] = max(adj[i][j], adj[i][k]+adj[k][j]);
                if (i == j && adj[i][i] > 0 && adj[s][i] > -INF/2 && adj[i][e] > -INF/2) {
                    cycle = true;
                    break;
                }
            }
            if (cycle) break;
        }
        if (cycle) break;
    }
    if (cycle) {
        cout << "Gee" << endl;
        return 0;
    }
    if (adj[s][e] < -INF/2) {
        cout << "gg" << endl;
        return 0;
    }
    cout << adj[s][e] + earn[s] << endl;
    return 0;
}
