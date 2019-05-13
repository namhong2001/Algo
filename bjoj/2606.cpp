#include <iostream>

using namespace std;

int n, m;
bool adj[101][101];
bool visited[101];

int dfs(int here) {
    visited[here] = true;

    int ret = 1;
    for (int there=1; there<=n; ++there) {
        if (adj[here][there] && !visited[there]) {
            ret += dfs(there);
        }
    }
    return ret;
}

int main() {

    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = true;
    }
    cout << (dfs(1)-1) << endl;

    return 0;
}
