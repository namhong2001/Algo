#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> amatch, bmatch;
vector<vector<bool>> adj;
vector<int> visited;

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;
    for (int b=0; b<m; ++b) {
        if (adj[a][b]) {
            if (bmatch[b] == -1 || dfs(bmatch[b])) {
                amatch[a] = b;
                bmatch[b] = a;
                return true;
            }
        }
    }
    return false;
}

int bipartitematch() {
    int total = 0;
    amatch.assign(n, -1);
    bmatch.assign(m, -1);
    for (int i=0; i<n; ++i) {
        visited.assign(n, false);
        if(dfs(i)) ++total;
    }
    return total;
}

int main() {
    cin >> n >> m;
    adj = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int a=0; a<n; ++a) {
        int si;
        cin >> si;
        while (si--) {
            int b;
            cin >> b;
            b--;
            adj[a][b] = true;
        }
    }
    cout << bipartitematch() << endl;
    return 0;
}
