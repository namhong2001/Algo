#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int v, m, n;
        cin >> v >> m >> n;
        vector<vector<int>> adj(v, vector<int>(v, INF));
        for (int i=0; i<v; ++i) adj[i][i] = 0;
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a][b] = adj[b][a] = min(adj[a][b], c);
        }
        for (int k=0; k<v; ++k) {
            for (int i=0; i<v; ++i) {
                for (int j=0; j<v; ++j) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        int cnt = 0;
        while (n--) {
            int a, b, c;
            cin >> a >> b >> c;
            if (adj[a][b] > c) {
                adj[a][b] = adj[b][a] = c;
                for (int i=0; i<v; ++i) {
                    for (int j=0; j<v; ++j) {
                        adj[i][j] = adj[j][i] = min({adj[i][j], adj[i][a] + c + adj[b][j], adj[i][b] + c + adj[a][j]});
                    }
                }
            } else {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
