#include <iostream>
#include <queue>

using namespace std;

int board[1000][1000];
int way[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int main() {
    int m, n;
    cin >> m >> n;

    queue<pair<int, int>> q;
    int rare_cnt = 0;
    int min_days = 0;

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                q.push({i, j});
            } else if (board[i][j] == 0) {
                ++rare_cnt;
            }
        }
    }

    if (rare_cnt == 0) {
        cout << 0 << endl;
        return 0;
    }

    int change_cnt = 0;
    while (!q.empty()) {
        pair<int, int> here = q.front();
        int x = here.first;
        int y = here.second;
        q.pop();
        for (int i=0; i<4; ++i) {
            int n_x = x + way[i][0];
            int n_y = y + way[i][1];
            if (n_x < 0 || n_y < 0 || n_x >= n || n_y >= m || board[n_x][n_y] != 0) continue;

            board[n_x][n_y] = board[x][y] + 1;
            change_cnt++;
            if (board[n_x][n_y] > min_days) {
                min_days = board[n_x][n_y];
            }

            q.push({n_x, n_y});
        }
    }
    if (rare_cnt != change_cnt) {
        cout << -1 << endl;
    } else {
        cout << (min_days - 1) << endl;
    }

    return 0;
}
