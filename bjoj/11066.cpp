#include <iostream>
#include <vector>

using namespace std;

const int K_MAX = 500;
const int FILE_SIZE_MAX = 10000;
int dp[K_MAX+1][K_MAX+1];
int sub_total[K_MAX+1][K_MAX+1];

int min_cost_sum(int start, int end, vector<int> &cost) {
    if (start == end) return 0;
    if (dp[start][end] != -1) return dp[start][end];
    int min = 987654321;
    for (int i=start; i<end; ++i) {
        int temp = min_cost_sum(start, i, cost) + min_cost_sum(i+1, end, cost);
        if (temp < min) min = temp;
    }
    min += sub_total[start][end];
    dp[start][end] = min;
    return min;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        vector<int> cost;
        for (int i=0; i<K_MAX+1; ++i) {
            for (int j=0; j<K_MAX+1; ++j) {
                dp[i][j] = -1;
                sub_total[i][j] = -1;
            }
        }
        for (int i=0; i<k; ++i) {
            int a;
            cin >> a;
            cost.push_back(a);
        }

        for (int i=1; i<=k; ++i) {
            sub_total[i][i] = cost[i-1];
            for (int j=i+1; j<=k; ++j) {
                sub_total[i][j] = sub_total[i][j-1] + cost[j-1];
            }
        }
        cout << min_cost_sum(1, k, cost) << '\n';
    }
    return 0;
}
