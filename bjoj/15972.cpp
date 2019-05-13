#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int VAR_MAX = 1010;

int heights[VAR_MAX][VAR_MAX];
int holes[VAR_MAX][VAR_MAX][4]; // top, bottom, left, right
int N, M, H;
bool visited[VAR_MAX][VAR_MAX];

int getK(int x, int y, int parentX, int parentY) {
    if (x-1 == parentX && y == parentY) return 0; // top
    if (x+1 == parentX && y == parentY) return 1; // bottom
    if (x == parentX && y-1 == parentY) return 2; // left
    if (x == parentX && y+1 == parentY) return 3; // right

    return -1; //should not be reach here
}

int solve(int x, int y, int parentX, int parentY) {
    if (visited[x][y]) return;

    if (parentX != -1) {
        int cand = max(heights[parentX][parentY], holes[x][y][getK(x, y, parentX, parentY)];

    }





}


int main() {
    cin >> N >> M >> H;

    memset(holes, -1, sizeof(holes));
    memset(heights, 0, sizeof(heights));
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            heights[i][j] = H;
        }
    }

    for(int i=1; i<=N+1; ++i) {
        for (int j=1; j<=M; ++j) {
            int hole;
            cin >> hole;
            holes[i][j][0] = hole;
            holes[i-1][j][1] = hole;
        }
    }

    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M+1; ++j) {
            int hole;
            cin >> hole;
            holes[i][j][2] = hole;
            holes[i][j-1][3] = hole;
        }
    }

    for (int i=0; i<=N+1; ++i) {
        if (i==0 || i==N+1) {
            for (int j=0; j<=M+1; ++j) {
                for (int k=0; k<4; ++k) {
                    if (holes[i][j][k] != -1) {
                        solve(i, j, -1, -1);
                        break;
                    }
                }
            }
        } else {
            for (int k=0; k<4; ++k) {
                if (holes[i][0][k] != -1) {
                    solve(i, 0, -1, -1);
                    break;
                }
            }
            for (int k=0; k<4; ++k) {
                if (holes[i][M+1][k] != -1) {
                    solve(i, M+1, -1, -1);
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            ans += heights[i][j];
        }
    }
    cout << ans;

    return 0;
}
