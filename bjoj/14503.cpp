#include <iostream>

using namespace std;

const int N_MAX = 50;
int arr[N_MAX][N_MAX];
int n, m;
int ans = 0;

const int directions[4][2] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}
};
void sweep(int x, int y, int d) {

    if (arr[x][y] == 0) {
        arr[x][y] = -1;
        ans++;
    }

    int i;
    for (i=1; i<=4; ++i) {
        int next_d = (d+i)%4;
        int next_x = x+directions[next_d][0];
        int next_y = y+directions[next_d][1];
        if (arr[next_x][next_y] == 0) {
            sweep(next_x, next_y, next_d);
            break;
        }
    }
    if (i == 5) {
        int temp_d = (d+2)%4;
        int next_x = x+directions[temp_d][0];
        int next_y = y+directions[temp_d][1];
        if (arr[next_x][next_y] != 1) {
            sweep(next_x, next_y, d);
        }
    }
}

int main() {
    cin >> n >> m;
    int x, y, d;
    cin >> x >> y >> d;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> arr[i][j];
        }
    }
    if (d == 1) d = 3;
    else if (d == 3) d = 1;
    sweep(x, y, d);
    cout << ans;
    return 0;
}
