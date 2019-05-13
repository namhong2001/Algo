#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int N_MAX = 512;


int n;
int pos[N_MAX][2];
double cache[N_MAX][N_MAX];

double dist(int pos_a, int pos_b) {
    int x_diff = pos[pos_a][0] - pos[pos_b][0];
    int y_diff = pos[pos_a][1] - pos[pos_b][1];
    return sqrt((double)x_diff*x_diff + y_diff*y_diff);
}

double solve(int pos_a, int pos_b) {
    if (pos_a == n-1) return dist(pos_b, n-1);
    else if (pos_b == n-1) return dist(pos_a, n-1);

    double &ret = cache[pos_a][pos_b];
    if (ret != 0.0) return ret;

    int next_pos = max(pos_a, pos_b) + 1;
    ret = min(solve(next_pos, pos_b) + dist(pos_a, next_pos), solve(pos_a, next_pos) + dist(pos_b, next_pos));
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> pos[i][0] >> pos[i][1];
        }
        memset(cache, 0, sizeof(cache));
        cout << solve(0, 0) << endl;
    }


    return 0;
}
