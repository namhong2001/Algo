#include <iostream>

using namespace std;
const int N_MAX = 100;

int A[N_MAX][N_MAX];
int B[N_MAX][N_MAX];
int ANS[N_MAX][N_MAX];

void solve(int n, int m, int p) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<p; ++j) {
            for (int k=0; k<m; ++k) {
                ANS[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> A[i][j];
        }
    }
    int m_temp, k;
    cin >> m_temp >> k;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<k; ++j) {
            cin >> B[i][j];
        }
    }
    solve(n, m, k);

    for (int i=0; i<n; ++i) {
        for (int j=0; j<k; ++j) {
            cout << ANS[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}
