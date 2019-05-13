#include <iostream>
#include <algorithm>

using namespace std;
const int N_MAX = 300;

int dp[N_MAX][2] = {0};
int step[N_MAX] = {0};

int max_score(int n, bool one_step) {
    if (n < 0) return 0;
    if (n == 0) return step[0];
    if (one_step) {
        if (dp[n][1] > 0) return dp[n][1];
        else {
            dp[n][1] = max_score(n-2, false) + step[n];
            return dp[n][1];
        }
    } else {
        if (dp[n][0] > 0) return dp[n][0];
        else {
            dp[n][0] = max(max_score(n-2, false), max_score(n-1, true)) + step[n];
            return dp[n][0];
        }
    }
}
int main() {

    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;
        step[i] = a;
    }
    cout << max_score(n-1, false);
    return 0;
}
