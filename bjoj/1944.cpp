#include <iostream>
#include <vector>
#include <queue>


using namespace std;

const int INF = 987654321;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
vector<vector<int>> board;
vector<pair<int,int>> vertices;

vector<int> bfs(pair<int,int> &s) {
    queue<pair<int,int>> q;
    vector<vector<int>> b = board;
    q.push({s});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0; i<4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (b[nx][ny] == 0) {
                b[nx][ny] = b[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    vector<int> ret;
    for (pair<int,int> &v : vertices) {
        int x = v.first;
        int y = v.second;
        int c = b[x][y];
        if (c == 0) c = INF;
        ret.push_back(c);
    }

    return ret;
}

int prim(vector<vector<int>> &adj) {
    int s = adj.size();
    vector<bool> visited(s, false);
    vector<int> d(s, INF);
    d[0] = 0;
    int ret = 0;
    int u_cnt = 0;
    for (int i=0; i<s; ++i) {
        int u = -1;
        int c = INF;
        for (int j=0; j<s; ++j) {
            if (!visited[j] && d[j] < c) {
                u = j;
                c = d[j];
            }
        }
        if (u == -1) break;
        visited[u] = true;
        ret += c;
        u_cnt++;
        for (int j=0; j<s; ++j) {
            d[j] = min(d[j], adj[u][j]);
        }
    }
    if (u_cnt < s) return -1;
    return ret;
}



int main() {
    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(n));
    for (int i=0; i<n; ++i) {
        string s;
        cin >> s;
        for (int j=0; j<n; ++j) {
            if (s[j] == '1') {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
            if (s[j] == 'S' || s[j] == 'K') {
                vertices.push_back({i, j});
            }
        }
    }
    vector<vector<int>> adj;
    for (pair<int,int> &v : vertices) {
        adj.push_back(bfs(v));
    }
    cout << prim(adj) << endl;

    return 0;
}
