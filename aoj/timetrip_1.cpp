#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;


int v, w;

int floyd(vector<vector<int>> &adj) {
    vector<vector<int>> dist = adj;
    vector<vector<int>> via(v, vector<int>(v, -1));
    for (int k=0; k<v; ++k) {
        for (int i=0; i<v; ++i) {
            for (int j=0; j<v; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    via[i][j] = k;
                }
            }
        }
    }
    for (int i=0; i<v; ++i) {
        if (dist[i][i] < 0 && dist[0][i] < INF/2 && dist[i][1] < INF/2) {
            return -INF;
        }
    }
    return dist[0][1];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> v >> w;
        vector<vector<int>> min_adj(v, vector<int>(v, INF));
        vector<vector<int>> max_adj(v, vector<int>(v, INF));
        for (int i=0; i<v; ++i) min_adj[i][i] = max_adj[i][i] = 0;
        while (w--) {
            int a, b, c;
            cin >> a >> b >> c;
            if (c < min_adj[a][b]) {
                min_adj[a][b] = c;
            }
            if (-c < max_adj[a][b]) {
                max_adj[a][b] = -c;
            }
        }
        int ans = floyd(min_adj);
        if (ans > INF/2) {
            cout << "UNREACHABLE" << endl;
            continue;
        }
        if (ans == -INF) cout << "INFINITY" << ' ';
        else cout << ans << ' ';
        ans = floyd(max_adj);
        if (ans == -INF) cout << "INFINITY" << ' ';
        else cout << -ans << ' ';
        cout << endl;
    }


}
