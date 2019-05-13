#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> E;
    vector<vector<int>> origin(n, vector<int>(n));
    vector<vector<int>> adj(n, vector<int>(n, INF));
    for (int i=0; i<n; ++i) adj[i][i] = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> origin[i][j];
            if (i > j) {
                E.push_back({origin[i][j], i, j});
            }
        }
    }
    sort(E.begin(), E.end());
    int ans = 0;
    for (vector<int> &e : E) {
        int c=e[0], u=e[1], v=e[2];
        if (adj[u][v] < c) {
            cout << -1 << endl;
            return 0;
        }
        else if (adj[u][v] == c) continue;
        else {
            ans += c;
            adj[u][v] = adj[v][u] = c;
            for (int i=0; i<n; ++i) {
                for (int j=0; j<n; ++j) {
                    adj[j][i] = adj[i][j] = min({adj[i][j], adj[i][u] + c + adj[v][j], adj[i][v] + c + adj[u][j]});
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
