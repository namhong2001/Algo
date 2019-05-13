#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef vector<int> P;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

queue<P> i_w;
char b[51][51];
bool w[51][51];
int step[51][51];

int r, c;
int s1, s2;

bool in_range(int x, int y) {
    return x>=0 && x<r && y>=0 && y<c;
}

int bfs() {
    memset(step, -1, sizeof(step));
    queue<P> q = i_w;
    q.push({s1, s2, 0});
    step[s1][s2] = 0;
    while (!q.empty()) {
        P here = q.front();
        q.pop();
        int x=here[0], y=here[1], is_w=here[2];
        if (b[x][y] == 'D') return step[x][y];
        for (int i=0; i<4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (!in_range(nx, ny)) continue;
            if (is_w) {
                if (b[nx][ny] != 'D' && b[nx][ny] != 'X' && !w[nx][ny]) {
                    w[nx][ny] = true;
                    q.push({nx, ny, 1});
                }
            } else if (b[nx][ny] != 'X' && !w[nx][ny] && step[nx][ny] == -1) {
                q.push({nx, ny, 0});
                step[nx][ny] = step[x][y]+1;
            }
        }
    }
    return -1;
}




int main() {
    memset(w, false, sizeof(w));
    cin >> r >> c;
    for (int i=0; i<r; ++i) {
        cin >> b[i];
        for (int j=0; j<c; ++j) {
            if (b[i][j] == 'S') {
                s1 = i, s2 = j;
            } else if (b[i][j] == '*') {
                i_w.push({i, j, 1});
                w[i][j] = true;
            }
        }
    }
    int ans = bfs();

    if (ans == -1) cout << "KAKTUS" << endl;
    else cout << ans << endl;

    return 0;
}
