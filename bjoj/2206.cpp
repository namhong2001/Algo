#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

typedef vector<int> P;

int step[1001][1001][2];
char b[1001][1001];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m;


int bfs() {
    memset(step, -1, sizeof(step));
    queue<P> q;
    q.push({0, 0, 0});
    step[0][0][0] = 1;
    while (!q.empty()) {
        P here = q.front();
        q.pop();
        int x=here[0], y=here[1], is_s=here[2];
        if (x == n-1 && y == m-1) return step[x][y][is_s];
        for (int i=0; i<4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx<0 || nx>=n || ny<0 || ny >=m) continue;
            if (b[nx][ny] == '1') {
                if (!is_s && step[nx][ny][1] == -1) {
                    q.push({nx, ny, 1});
                    step[nx][ny][1] = step[x][y][is_s] + 1;
                }
            } else if (step[nx][ny][is_s] == -1) {
                q.push({nx, ny, is_s});
                step[nx][ny][is_s] = step[x][y][is_s] + 1;
            }
        }
    }
    return -1;
}


int main() {
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        cin >> b[i];
    }
    cout << bfs() << endl;
}
