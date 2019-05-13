#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi; // cost, x, y

const int INF = 987654321;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

vector<vector<int>> board;

int n;
int dijkstra() {
    priority_queue<vi> pq;
    pq.push({-board[0][0], 0, 0});
    vector<vector<int>> d(n, vector<int>(n, INF));
    d[0][0] = board[0][0];
    while (!pq.empty()) {
        int cost = -pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();
        if (cost > d[x][y]) continue;

        for (int i=0; i<4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            int nc = cost + board[nx][ny];
            if (d[nx][ny] > nc) {
                d[nx][ny] = nc;
                pq.push({-nc, nx, ny});
            }
        }
    }
    return d[n-1][n-1];
}

int main() {
    int t=1;
    while (true) {;
        cin >> n;
        if (n == 0) return 0;
        board = vector<vector<int>> (n, vector<int>(n));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cin >> board[i][j];
            }
        }
        cout << "Problem " << t << ": " << dijkstra() << '\n';
        t++;
    }
    return 0;
}
