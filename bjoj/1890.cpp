#include <iostream>
#include <cstring>

using namespace std;

int board[100][100];
long long dp[100][100];

long long solve(int x, int y, int n) {
    if (x >= n || y >= n) return 0;
    if (x == n-1 && y == n-1) return 1;
    if (board[x][y] == 0) return 0;

    long long &ret = dp[x][y];
    if (ret != -1) return ret;

    int jump = board[x][y];

    ret = solve(x + jump, y, n) + solve(x, y + jump, n);

    return ret;
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> board[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, n) << endl;

    return 0;
}
