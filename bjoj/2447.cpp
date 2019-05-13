#include <iostream>
#include <cmath>

using namespace std;

const int N_MAX = pow(3, 8);
char field[N_MAX][N_MAX];

int n;

void make_blank(int x, int y, int n) {
    for (int i=x; i<x+n; ++i) {
        for (int j=y; j<y+n; ++j) {
            field[i][j] = ' ';
        }
    }
}

void solve(int nth) {
    if (nth > n/3) return;

    for (int i=nth; i<n; i+=nth*3) {
        for (int j=nth; j<n; j+=nth*3) {
            make_blank(i, j, nth);
        }
    }

    solve(nth*3);
}

int main() {
    cin >> n;
    solve(1);


    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (field[i][j] != ' ') cout << '*';
            else cout << ' ';
        }
        cout << endl;
    }


    return 0;
}
