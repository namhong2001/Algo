#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N_MAX = 100;

int field[N_MAX][N_MAX];
int cache[N_MAX][N_MAX];

int getSum(int r, int c) {
    if (r < 0 || c < 0) return 0;
    int &ret = cache[r][c];
    if (ret == -1) {
        ret = max(getSum(r-1, c), getSum(r-1, c-1)) + field[r][c];
    }
    return ret;
}

int getMaxSum(int n) {
    int ans = 0;
    for (int i=0; i<n; ++i) {
        ans = max(ans, getSum(n-1, i));
    }
    return ans;
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        int n;
        cin >> n;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i+1; ++j) {
                cin >> field[i][j];
            }
        }
        memset(cache, -1, sizeof(cache));
        cout << getMaxSum(n) << endl;
    }

    return 0;
}
