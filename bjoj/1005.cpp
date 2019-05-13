#include <iostream>
#include <vector>

using namespace std;
const int N_MAX = 1000;

int total_cost(int n, vector<int> pre_build[], int cost[], vector<int> &dp) {
    if (dp[n]>=0) return dp[n];
    else {
        int sub_cost = 0;
        int max_pre = 0;
        for (auto i : pre_build[n]) {
            int pre_cost = total_cost(i, pre_build, cost, dp);
            if (pre_cost > max_pre) max_pre = pre_cost;
        }
        dp[n] = max_pre + cost[n];
        return dp[n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<int> dp(N_MAX+1, -1);
        int cost[N_MAX+1] = {0};
        vector<int> pre_build[N_MAX+1];
        int n, k;
        cin >> n >> k;
        for (int i=1; i<=n; ++i) {
            int c;
            cin >> c;
            cost[i] = c;
        }
        for (int i=0; i<k; ++i) {
            int a, b;
            cin >> a >> b;
            pre_build[b].push_back(a);
        }
        int w;
        cin >> w;
        cout << total_cost(w, pre_build, cost, dp) << '\n';
    }

    return 0;
}
