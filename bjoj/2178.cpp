#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int way[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

char board[100][101];
int ans[100][100];

int n, m;

int solve() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    memset(ans, 0, sizeof(ans));
    ans[0][0] = 1;
    while (!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();
        int x = here.first;
        int y = here.second;
        for (int i=0; i<4; ++i) {
            int nx = x + way[i][0];
            int ny = y + way[i][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == '0' || ans[nx][ny] != 0) continue;

            if (nx == n-1 && ny == m-1) return ans[x][y] + 1;

            ans[nx][ny] = ans[x][y] + 1;
            q.push({nx, ny});
        }
    }
    // should not reach here
    return 0;
}


int main() {
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        cin >> board[i];
    }
    cout << solve() << endl;

    return 0;
}
