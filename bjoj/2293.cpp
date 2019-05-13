#include <iostream>
#include <vector>

using namespace std;
const int N_MAX = 100;
const int K_MAX = 10000;

int *dp = new int[N_MAX*(K_MAX+1)];
//vector<vector<int>> dp(N_MAX)(K_MAX+1);
vector<int> value;

int cases(int money, int start) {
    if (money < 0) return 0;
    if (money == 0) return 1;
    if (dp[start*N_MAX + money] > 0) return dp[start*N_MAX + money];

    int ret = 0;
    for (int i=start; i<value.size(); ++i) {
        int coin = value[i];
        ret += cases(money-coin, i);
    }
    dp[start*N_MAX + money] = ret;
    return ret;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        int v;
        cin >> v;
        value.push_back(v);
    }
    cout << cases(k, 0);

    return 0;
}
