#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int INF = 987654321;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    for (int i=0; i<n; ++i) adj[i][i] = 0;
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = 1;
    }
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    vector<pair<int,int>> sum;
    for (int i=0; i<n; ++i) {
        int s = 0;
        for (int j=0; j<n; ++j) {
            s += adj[i][j];
        }
        sum.push_back({s, i});
    }
    sort(sum.begin(), sum.end());
    cout << sum[0].second + 1 << endl;
    return 0;
}
