#include <iostream>
#include <cmath>

using namespace std;

const int N_MAX = pow(3, 7);
int square[N_MAX][N_MAX] = {};

int cnt_m1 = 0;
int cnt_0 = 0;
int cnt_1 = 0;


bool is_one (int x, int y, int n) {
    int a = square[x][y];
    for (int i=x; i<x+n; ++i) {
        for (int j=y; j<y+n; ++j) {
            if (square[i][j] != a) return false;
        }
    }
    return true;
}

void solve(int x, int y, int n) {
    if (is_one(x, y, n)) {
        if (square[x][y] == -1) cnt_m1++;
        else if (square[x][y] == 0) cnt_0++;
        else if (square[x][y] == 1) cnt_1++;
    } else {
        for (int i=x; i<x+n; i+=n/3) {
            for (int j=y; j<y+n; j+=n/3) {
                solve(i, j, n/3);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> square[i][j];
        }
    }
    solve(0, 0, n);
    cout << cnt_m1 << endl;
    cout << cnt_0 << endl;
    cout << cnt_1 << endl;


    return 0;
}
