#include <iostream>
#include <queue>

using namespace std;

int board[100][100][100];
int way[6][3] = {{0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0}, {0,0,1}, {0,0,-1}};

struct Pos {
    int x;
    int y;
    int z;
    Pos(int x, int y, int z): x(x), y(y), z(z) {};
};

int main() {
    int m, n, h;
    cin >> m >> n >> h;

    queue<Pos> q;
    int rare_cnt = 0;
    int min_days = 0;

    for (int k=0; k<h; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> board[k][i][j];
                if (board[k][i][j] == 1) {
                    q.push(Pos(i, j, k));
                } else if (board[k][i][j] == 0) {
                    ++rare_cnt;
                }
            }
        }
    }

    if (rare_cnt == 0) {
        cout << 0 << endl;
        return 0;
    }

    int change_cnt = 0;
    while (!q.empty()) {
        Pos here = q.front();
        int x = here.x;
        int y = here.y;
        int z = here.z;
        q.pop();
        for (int i=0; i<6; ++i) {
            int n_x = x + way[i][0];
            int n_y = y + way[i][1];
            int n_z = z + way[i][2];
            if (n_x < 0 || n_y < 0 || n_z < 0 || n_x >= n || n_y >= m || n_z >= h || board[n_z][n_x][n_y] != 0) continue;

            board[n_z][n_x][n_y] = board[z][x][y] + 1;
            change_cnt++;
            if (board[n_z][n_x][n_y] > min_days) {
                min_days = board[n_z][n_x][n_y];
            }

            q.push(Pos(n_x, n_y, n_z));
        }
    }
    if (rare_cnt != change_cnt) {
        cout << -1 << endl;
    } else {
        cout << (min_days - 1) << endl;
    }

    return 0;
}
