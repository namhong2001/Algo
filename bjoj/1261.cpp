#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi; // cost, x, y

const int INF = 987654321;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int n, m;
vector<vector<int>> board;

int dijkstra() {
    priority_queue<vi> pq;
    vector<vector<int>> d(n, vector<int>(m, INF));
    d[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        int cost = -pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();
        if (d[x][y] < cost) continue;
        for (int i=0; i<4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            int nc = cost + board[nx][ny];
            if (d[nx][ny] > nc) {
                d[nx][ny] = nc;
                pq.push({-nc, nx, ny});
            }
        }
    }
    return d[n-1][m-1];
}


int main() {
    cin >> m >> n;
    board = vector<vector<int>>(n, vector<int>(m));
    for (int i=0; i<n; ++i) {
        string s;
        cin >> s;
        for (int j=0; j<m; ++j) {
            board[i][j] = s[j] -'0';
        }
    }
    cout << dijkstra() << endl;

    return 0;
}
