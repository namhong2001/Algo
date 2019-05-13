#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int N_MAX = 1001;
const int M_MAX = 1001;
const double p = 0.75;

double cache[N_MAX][M_MAX];

double solve(int n, int m) {
    if (n < 1) return 1;
    if (m < 1) return 0;

    if (n > 2*m) return 0;
    if (n <= m) return 1;

    double &ret = cache[n][m];
    if (ret != 0) return ret;

    ret = solve(n-2, m-1)*p + solve(n-1, m-1)*(1-p);
    return ret;
}

int main () {
    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        cout << fixed << setprecision(10) << solve(n, m) << endl;
    }

    return 0;
}
