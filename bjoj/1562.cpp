#include <iostream>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 1e9;
const int N_MAX = 100;
int cache[2][10];
int n;

int stepNum(int start, int end) {
    int* prev = cache[0];
    int* next = cache[1];
    fill(prev, prev+10, 1);
    if (start == 0) prev[0] = 0;
    for (int i=1; i<n; ++i) {
        memset(next, 0, sizeof(int)*10);
        for (int j=start; j<=end; ++j) {
            if (j-1 >= start) {
                next[j-1] = (next[j-1] + prev[j]) % MOD;
            }
            if (j+1 <= end) {
                next[j+1] = (next[j+1] + prev[j]) % MOD;
            }
        }
        swap(prev, next);
    }
    int ret = 0;
    for (int i=start; i<=end; ++i) {
        ret += prev[i];
        ret %= MOD;
    }
    return ret;
}

int main() {
    cin >> n;
    int ans = stepNum(0, 9);
    ans = (ans - stepNum(1, 9) + MOD) % MOD;
    ans = (ans - stepNum(0, 8) + MOD) % MOD;
    ans = (ans + stepNum(1, 8)) % MOD;
    cout << ans;
    return 0;
}
