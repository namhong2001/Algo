#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

const int N_MAX = 10000;

int dp[N_MAX][2];
vector<int> amount;

int get_total(int n, int step) {
    if (n < 0) return 0;
    if (dp[n][step] >= 0 ) return dp[n][step];
    if (step == 1) {
        dp[n][step] = max(get_total(n-1, step-1), get_total(n-2, step)) + amount[n];
    } else {
        dp[n][step] = max(get_total(n-2, 1), get_total(n-3, 1)) + amount[n];
    }
    return dp[n][step];
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<N_MAX; ++i) {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }

    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;
        amount.push_back(a);
    }
    cout << max(get_total(n-1, 1), get_total(n-2, 1));
}
