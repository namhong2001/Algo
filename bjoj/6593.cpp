#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> P;

char b[31][31][31];
int step[31][31][31];


int l, r, c;
int sx, sy, sz;

bool valid(P &a) {
    return a[0]>=0 && a[0]<l && a[1]>=0 && a[1]<r && a[2]>=0 && a[2]<c;
}

int bfs() {
    memset(step, -1, sizeof(step));
    queue<P> q;
    q.push({sx, sy, sz});
    step[sx][sy][sz] = 0;
    while (!q.empty()) {
        P here = q.front();
        q.pop();
        int x = here[0], y = here[1], z = here[2];
        if (b[x][y][z] == 'E') return step[x][y][z];
        for (int i=0; i<3; ++i) {
            P next = here;
            int &nx = next[0];
            int &ny = next[1];
            int &nz = next[2];
            next[i]++;
            if (valid(next) && b[nx][ny][nz] != '#' && step[nx][ny][nz] == -1) {
                step[nx][ny][nz] = step[x][y][z]+1;
                q.push(next);
            }
            next[i]-=2;
            if (valid(next) && b[nx][ny][nz] != '#' && step[nx][ny][nz] == -1) {
                step[nx][ny][nz] = step[x][y][z]+1;
                q.push(next);
            }
        }
    }
    return -1;
}


int main() {
    while (true) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) break;
        for (int i=0; i<l; ++i) {
            for (int j=0; j<r; ++j) {
                cin >> b[i][j];
                for (int k=0; k<c; ++k) {
                    if (b[i][j][k] == 'S') {
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                }
            }
        }
        int ans = bfs();
        if (ans == -1) cout << "Trapped!" << endl;
        else cout << "Escaped in " << ans << " minute(s)." << endl;
    }

    return 0;
}
