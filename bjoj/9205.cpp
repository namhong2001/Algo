#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int manhtan(pair<int,int> &a, pair<int,int> &b) {
    return abs(a.first - b.first) + abs(a.second -b.second);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int,int>> p(n+2);
        for (int i=0; i<n+2; ++i) {
            int x, y;
            cin >> x >> y;
            p[i] = {x, y};
        }
        vector<vector<int>> adj(n+2, vector<int>(n+2, 0));
        for (int i=0; i<n+2; ++i) {
            adj[i][i] = 1;
            for (int j=i+1; j<n+2; ++j) {
                if (manhtan(p[i], p[j]) <= 1000) {
                    adj[i][j] = adj[j][i] = 1;
                }
            }
        }
        for (int k=0; k<n+2; ++k) {
            for (int i=0; i<n+2; ++i) {
                for (int j=0; j<n+2; ++j) {
                    adj[i][j] |= adj[i][k] & adj[k][j];
                }
            }
        }
        if (adj[0][n+1]) cout << "happy" << endl;
        else cout << "sad" << endl;
    }

    return 0;
}
