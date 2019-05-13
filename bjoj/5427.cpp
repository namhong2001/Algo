#include <iostream>
#include <queue>
#include <utility>
#include <cstring>


using namespace std;

typedef vector<int> P;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int w, h;
int sx, sy;
queue<P> i_f;
char b[1010][1010];
bool f[1010][1010];
int step[1010][1010];

int bfs() {
    memset(step, -1, sizeof(step));
    queue<P> q = i_f;
    q.push({sx, sy, 0});
    step[sx][sy] = 0;
    while (!q.empty()) {
        P here = q.front();
        q.pop();
        int x = here[0], y = here[1], is_f = here[2];
        if (!is_f && (x == 0 || x == h-1 || y == 0 || y == w-1)) return step[x][y]+1;

        for (int i=0; i<4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (is_f) {
                if (nx>=0 && nx<h && ny>=0 && ny<w && b[nx][ny] != '#' && !f[nx][ny]) {
                    f[nx][ny] = true;
                    q.push({nx, ny, 1});
                }
            } else if (b[nx][ny] == '.' && step[nx][ny] == -1 && !f[nx][ny]) {
                step[nx][ny] = step[x][y]+1;
                q.push({nx, ny, 0});
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(f, false, sizeof(f));
        i_f = queue<P>();
        cin >> w >> h;
        for (int i=0; i<h; ++i) {
            cin >> b[i];
            for (int j=0; j<w; ++j) {
                if (b[i][j] == '*') {
                    f[i][j] = true;
                    i_f.push({i, j, 1});
                } else if (b[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
            }
        }
        int ans = bfs();
        if (ans == -1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }


    return 0;
}
