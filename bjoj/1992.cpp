#include <iostream>
#include <cmath>

using namespace std;

const int N_MAX = 64;
char square[N_MAX][N_MAX] = {};

int cnt_m1 = 0;
int cnt_0 = 0;
int cnt_1 = 0;

bool is_one (int x, int y, int n) {
    char a = square[x][y];
    for (int i=x; i<x+n; ++i) {
        for (int j=y; j<y+n; ++j) {
            if (square[i][j] != a) return false;
        }
    }
    return true;
}

string solve(int x, int y, int n) {
    if (is_one(x, y, n)) {
        return string(1, square[x][y]);
    } else {
        string ret = "(";
        for (int i=x; i<x+n; i+=n/2) {
            for (int j=y; j<y+n; j+=n/2) {
                ret += solve(i, j, n/2);
            }
        }
        ret += ")";
        return ret;
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
    cout << solve(0, 0, n);

    return 0;
}
