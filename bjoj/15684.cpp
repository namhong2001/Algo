#include <iostream>

using namespace std;

const int N_MAX = 10;
const int H_MAX = 30;
int ladder[H_MAX][N_MAX] = {};

bool check_ladder(int h, int n) {
    for (int i=0; i<n; ++i) {
        int pos = i;
        for (int j=0; j<h; ++j) {
            if (ladder[j][pos] == 1) {
                pos++;
            } else if (ladder[j][pos] == 2) {
                pos--;
            }
        }
        if (pos != i) return false;
    }
    return true;
}

bool add_ladder_and_check(int h, int n, int h_start, int n_start, int ladder_cnt) {
    if (n_start == n) {
        n_start = 0;
        h_start++;
    }
    if (h_start == h) return false;

    for (int i=h_start; i<h; ++i) {
        for (int j=n_start; j<n-1; ++j) {
            if (ladder[i][j] == 0 && ladder[i][j+1] == 0) {
                ladder[i][j] = 1;
                ladder[i][j+1] = 2;
                if (ladder_cnt > 1) {
                    if (add_ladder_and_check(h, n, i, j+1, ladder_cnt-1)) return true;
                } else {
                    if (check_ladder(h, n)) return true;
                }
                ladder[i][j] = ladder[i][j+1] = 0;
            }
        }
        n_start = 0;
    }
    return false;
}


int main() {
    int n, m, h;
    cin >> n >> m >> h;
    for (int i=0; i<m; ++i) {
        int a;
        int b;
        cin >> a >> b;
        ladder[a-1][b-1] = 1; // right
        ladder[a-1][b] = 2; // left
    }
    if (check_ladder(h, n)) cout << 0;
    else if (add_ladder_and_check(h, n, 0, 0, 1)) cout << 1;
    else if (add_ladder_and_check(h, n, 0, 0, 2)) cout << 2;
    else if (add_ladder_and_check(h, n, 0, 0, 3)) cout << 3;
    else cout << -1;
    return 0;
}
