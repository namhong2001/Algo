#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i=0; i<n; ++i) adj[i][i] = 1;
    while (m--) {
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
    int cnt = 0;
    for (int i=0; i<n; ++i) {
        cnt++;
        for (int j=0; j<n; ++j) {
            if ((adj[i][j] | adj[j][i]) ^ 1) {
                cnt--;
                break;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
