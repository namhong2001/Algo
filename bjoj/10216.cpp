#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Node {
    int x;
    int y;
    int r;
    Node(int x, int y, int r): x(x), y(y), r(r) {};
};

bool adj[3000][3000];

bool is_connected(const Node& A, const Node& B) {
    return (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y) <= (A.r + B.r)*(A.r + B.r);
}

void dfs(int here, bool visited[3000], int n) {
    visited[here] = true;
    for (int there=0; there<n; ++there) {
        if (adj[here][there] && !visited[there]) {
            dfs(there, visited, n);
        }
    }
}

int dfs_all(int n) {
    int ret = 0;
    bool visited[3000];
    memset(visited, false, sizeof(visited));
    for (int i=0; i<n; ++i) {
        if (!visited[i]) {
            dfs(i, visited, n);
            ++ret;
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(adj, false, sizeof(adj));
        vector<Node> nodes;
        for (int i=0; i<n; ++i) {
            int x, y, r;
            cin >> x >> y >> r;
            nodes.push_back(Node(x, y, r));
            for (int j=0; j<i; ++j) {
                if (is_connected(nodes[i], nodes[j])) {
                    adj[i][j] = adj[j][i] = true;
                }
            }
        }
        cout << dfs_all(n) << endl;
    }

    return 0;
}
