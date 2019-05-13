#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 8;
int arr[N_MAX][N_MAX];
int n, m;
vector<pair<int, int>> virus_poses;

void spread_virus(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    arr[x][y] = 2;
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    for (int i=0; i<4; ++i) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (arr[next_x][next_y] == 0) {

            spread_virus(next_x, next_y);
        }
    }
}

void mark_virus() {
    for (auto virus : virus_poses) {
        spread_virus(virus.first, virus.second);
    }
}
void clear_virus() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (arr[i][j] == 2) arr[i][j] = 0;
        }
    }
    for (auto virus : virus_poses) {
        arr[virus.first][virus.second] = 2;
    }
}

int cal_safe_zone(int wall) {
    int cnt = 0;
    if (wall == 0) {
        mark_virus();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (arr[i][j] == 0) cnt++;
            }
        }
        clear_virus();
    } else {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (arr[i][j] == 0) {
                    arr[i][j] = 1;
                    cnt = max(cnt, cal_safe_zone(wall-1));
                    arr[i][j] = 0;
                }
            }
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) virus_poses.push_back({i, j});
        }
    }
    cout << cal_safe_zone(3);
    return 0;
}
