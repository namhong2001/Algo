#include <iostream>
#include <algorithm>

using namespace std;
const int N_MAX = 15;
int arr[N_MAX][2];
int dp[N_MAX+1];

int max_profit(int start, int n) {
    if (dp[start] > 0) return dp[start];

    int profit = 0;
    int end = min(start + arr[start][0], n);
    for (int i=start; i<end; ++i) {
        if (arr[i][0] + i <= n) {
            profit = max(profit, arr[i][1] + max_profit(i+arr[i][0], n));
        }
    }
    dp[start] = profit;
    return profit;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    cout << max_profit(0, n);
    return 0;
}
