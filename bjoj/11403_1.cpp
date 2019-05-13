#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> adj[i][j];
        }
    }
    for (int k=0; k<n; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                adj[i][j] |= adj[i][k] & adj[k][j];
            }
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
