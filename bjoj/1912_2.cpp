#include <iostream>
#include <algorithm>

using namespace std;

const int N_MAX = 1e5;
int dp[N_MAX];

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int num;
        cin >> num;
        if (i > 0 && dp[i-1] + num > num ) {
            dp[i] = dp[i-1] + num;
        } else {
            dp[i] = num;
        }
    }
    int ret = -987654321;
    for (int i=0; i<n; ++i) ret = max(ret, dp[i]);
    cout << ret;
}
